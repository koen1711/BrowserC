// Copyright 2018 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/api/api-arguments.h"

#include "src/api/api-arguments-inl.h"

namespace v8 {
namespace internal {

PropertyCallbackArguments::PropertyCallbackArguments(
    Isolate* isolate, Object data, Object self, JSObject holder,
    Maybe<ShouldThrow> should_throw)
    : Super(isolate)
#ifdef DEBUG
      ,
      javascript_execution_counter_(isolate->javascript_execution_counter())
#endif  // DEBUG
{
  slot_at(T::kThisIndex).store(self);
  slot_at(T::kHolderIndex).store(holder);
  slot_at(T::kDataIndex).store(data);
  slot_at(T::kIsolateIndex).store(Object(reinterpret_cast<Address>(isolate)));
  int value = Internals::kInferShouldThrowMode;
  if (should_throw.IsJust()) {
    value = should_throw.FromJust();
  }
  slot_at(T::kShouldThrowOnErrorIndex).store(Smi::FromInt(value));
  // Here the hole is set as default value.
  // It cannot escape into js as it's removed in Call below.
  HeapObject the_hole_value = ReadOnlyRoots(isolate).the_hole_value();
  slot_at(T::kReturnValueIndex).store(the_hole_value);
  slot_at(T::kUnusedIndex).store(Smi::zero());
  DCHECK((*slot_at(T::kHolderIndex)).IsHeapObject());
  DCHECK((*slot_at(T::kIsolateIndex)).IsSmi());
}

FunctionCallbackArguments::FunctionCallbackArguments(
    internal::Isolate* isolate, internal::Object data, internal::Object holder,
    internal::HeapObject new_target, internal::Address* argv, int argc)
    : Super(isolate), argv_(argv), argc_(argc) {
  slot_at(T::kDataIndex).store(data);
  slot_at(T::kHolderIndex).store(holder);
  slot_at(T::kNewTargetIndex).store(new_target);
  slot_at(T::kIsolateIndex).store(Object(reinterpret_cast<Address>(isolate)));
  // Here the hole is set as default value. It's converted to and not
  // directly exposed to js.
  // TODO(cbruni): Remove and/or use custom sentinel value.
  HeapObject the_hole_value = ReadOnlyRoots(isolate).the_hole_value();
  slot_at(T::kReturnValueIndex).store(the_hole_value);
  slot_at(T::kUnusedIndex).store(Smi::zero());
  DCHECK((*slot_at(T::kHolderIndex)).IsHeapObject());
  DCHECK((*slot_at(T::kIsolateIndex)).IsSmi());
}

}  // namespace internal
}  // namespace v8
