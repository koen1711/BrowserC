// Copyright 2014 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_COMPILER_PIPELINE_STATISTICS_H_
#define V8_COMPILER_PIPELINE_STATISTICS_H_

#include <memory>
#include <string>

#include "src/base/platform/elapsed-timer.h"
#include "src/compiler/zone-stats.h"
#include "src/diagnostics/compilation-statistics.h"
#include "src/objects/code-kind.h"
#include "src/tracing/trace-event.h"

namespace v8 {
namespace internal {
namespace compiler {

class PhaseScope;

class PipelineStatistics : public Malloced {
 public:
  PipelineStatistics(OptimizedCompilationInfo* info,
                     std::shared_ptr<CompilationStatistics> turbo_stats,
                     ZoneStats* zone_stats);
  ~PipelineStatistics();
  PipelineStatistics(const PipelineStatistics&) = delete;
  PipelineStatistics& operator=(const PipelineStatistics&) = delete;

  void BeginPhaseKind(const char* phase_kind_name);
  void EndPhaseKind();

  // We log detailed phase information about the pipeline
  // in both the v8.turbofan and the v8.wasm.turbofan categories.
  static constexpr char kTraceCategory[] =
      TRACE_DISABLED_BY_DEFAULT("v8.turbofan") ","  // --
      TRACE_DISABLED_BY_DEFAULT("v8.wasm.turbofan");

 private:
  size_t OuterZoneSize() {
    return static_cast<size_t>(outer_zone_->allocation_size());
  }

  class CommonStats {
   public:
    CommonStats() : outer_zone_initial_size_(0) {}
    CommonStats(const CommonStats&) = delete;
    CommonStats& operator=(const CommonStats&) = delete;

    void Begin(PipelineStatistics* pipeline_stats);
    void End(PipelineStatistics* pipeline_stats,
             CompilationStatistics::BasicStats* diff);

    std::unique_ptr<ZoneStats::StatsScope> scope_;
    base::ElapsedTimer timer_;
    size_t outer_zone_initial_size_;
    size_t allocated_bytes_at_start_;
    size_t graph_size_at_start_ = 0;
  };

  bool InPhaseKind() { return !!phase_kind_stats_.scope_; }

  friend class PhaseScope;
  bool InPhase() { return !!phase_stats_.scope_; }
  void BeginPhase(const char* name);
  void EndPhase();

  Zone* outer_zone_;
  ZoneStats* zone_stats_;
  std::shared_ptr<CompilationStatistics> compilation_stats_;
  CodeKind code_kind_;
  std::string function_name_;

  // Stats for the entire compilation.
  CommonStats total_stats_;

  // Stats for phase kind.
  const char* phase_kind_name_;
  CommonStats phase_kind_stats_;

  // Stats for phase.
  const char* phase_name_;
  CommonStats phase_stats_;
};

class V8_NODISCARD PhaseScope {
 public:
  PhaseScope(PipelineStatistics* pipeline_stats, const char* name)
      : pipeline_stats_(pipeline_stats) {
    if (pipeline_stats_ != nullptr) pipeline_stats_->BeginPhase(name);
  }
  ~PhaseScope() {
    if (pipeline_stats_ != nullptr) pipeline_stats_->EndPhase();
  }
  PhaseScope(const PhaseScope&) = delete;
  PhaseScope& operator=(const PhaseScope&) = delete;

 private:
  PipelineStatistics* const pipeline_stats_;
};

}  // namespace compiler
}  // namespace internal
}  // namespace v8

#endif  // V8_COMPILER_PIPELINE_STATISTICS_H_
