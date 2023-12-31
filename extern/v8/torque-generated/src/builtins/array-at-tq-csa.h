#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_AT_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_AT_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-at.tq?l=6&c=1
TNode<Number> ConvertRelativeIndex_0(compiler::CodeAssemblerState* state_, TNode<Number> p_index, TNode<Number> p_length, compiler::CodeAssemblerLabel* label_OutOfBoundsLow, compiler::CodeAssemblerLabel* label_OutOfBoundsHigh);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_AT_TQ_CSA_H_
