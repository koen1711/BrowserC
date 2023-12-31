// Copyright 2014 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/compiler/pipeline-statistics.h"

#include <memory>

#include "src/codegen/optimized-compilation-info.h"
#include "src/compiler/turboshaft/phase.h"
#include "src/compiler/zone-stats.h"
#include "src/objects/shared-function-info.h"

namespace v8 {
namespace internal {
namespace compiler {

constexpr char PipelineStatistics::kTraceCategory[];

void PipelineStatistics::CommonStats::Begin(
    PipelineStatistics* pipeline_stats) {
  DCHECK(!scope_);
  scope_.reset(new ZoneStats::StatsScope(pipeline_stats->zone_stats_));
  outer_zone_initial_size_ = pipeline_stats->OuterZoneSize();
  allocated_bytes_at_start_ =
      outer_zone_initial_size_ -
      pipeline_stats->total_stats_.outer_zone_initial_size_ +
      pipeline_stats->zone_stats_->GetCurrentAllocatedBytes();
  if (turboshaft::PipelineData::HasScope()) {
    graph_size_at_start_ =
        turboshaft::PipelineData::Get().graph().number_of_operations();
  }
  timer_.Start();
}


void PipelineStatistics::CommonStats::End(
    PipelineStatistics* pipeline_stats,
    CompilationStatistics::BasicStats* diff) {
  DCHECK(scope_);
  diff->function_name_ = pipeline_stats->function_name_;
  diff->delta_ = timer_.Elapsed();
  size_t outer_zone_diff =
      pipeline_stats->OuterZoneSize() - outer_zone_initial_size_;
  diff->max_allocated_bytes_ = outer_zone_diff + scope_->GetMaxAllocatedBytes();
  diff->absolute_max_allocated_bytes_ =
      diff->max_allocated_bytes_ + allocated_bytes_at_start_;
  diff->total_allocated_bytes_ =
      outer_zone_diff + scope_->GetTotalAllocatedBytes();
  diff->input_graph_size_ = graph_size_at_start_;
  if (turboshaft::PipelineData::HasScope()) {
    diff->output_graph_size_ =
        turboshaft::PipelineData::Get().graph().number_of_operations();
  }
  scope_.reset();
  timer_.Stop();
}

PipelineStatistics::PipelineStatistics(
    OptimizedCompilationInfo* info,
    std::shared_ptr<CompilationStatistics> compilation_stats,
    ZoneStats* zone_stats)
    : outer_zone_(info->zone()),
      zone_stats_(zone_stats),
      compilation_stats_(compilation_stats),
      code_kind_(info->code_kind()),
      phase_kind_name_(nullptr),
      phase_name_(nullptr) {
  if (info->has_shared_info()) {
    function_name_.assign(info->shared_info()->DebugNameCStr().get());
  }
  total_stats_.Begin(this);
}

PipelineStatistics::~PipelineStatistics() {
  if (InPhaseKind()) EndPhaseKind();
  CompilationStatistics::BasicStats diff;
  total_stats_.End(this, &diff);
  compilation_stats_->RecordTotalStats(diff);
}


void PipelineStatistics::BeginPhaseKind(const char* phase_kind_name) {
  DCHECK(!InPhase());
  if (InPhaseKind()) EndPhaseKind();
  TRACE_EVENT_BEGIN1(kTraceCategory, phase_kind_name, "kind",
                     CodeKindToString(code_kind_));
  phase_kind_name_ = phase_kind_name;
  phase_kind_stats_.Begin(this);
}

void PipelineStatistics::EndPhaseKind() {
  DCHECK(!InPhase());
  CompilationStatistics::BasicStats diff;
  phase_kind_stats_.End(this, &diff);
  compilation_stats_->RecordPhaseKindStats(phase_kind_name_, diff);
  TRACE_EVENT_END2(kTraceCategory, phase_kind_name_, "kind",
                   CodeKindToString(code_kind_), "stats",
                   TRACE_STR_COPY(diff.AsJSON().c_str()));
}

void PipelineStatistics::BeginPhase(const char* phase_name) {
  TRACE_EVENT_BEGIN1(kTraceCategory, phase_name, "kind",
                     CodeKindToString(code_kind_));
  DCHECK(InPhaseKind());
  phase_name_ = phase_name;
  phase_stats_.Begin(this);
}

void PipelineStatistics::EndPhase() {
  DCHECK(InPhaseKind());
  CompilationStatistics::BasicStats diff;
  phase_stats_.End(this, &diff);
  compilation_stats_->RecordPhaseStats(phase_kind_name_, phase_name_, diff);
  TRACE_EVENT_END2(kTraceCategory, phase_name_, "kind",
                   CodeKindToString(code_kind_), "stats",
                   TRACE_STR_COPY(diff.AsJSON().c_str()));
}

}  // namespace compiler
}  // namespace internal
}  // namespace v8
