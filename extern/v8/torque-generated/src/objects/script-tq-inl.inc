// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=20&c=3
template<class D, class P>
PrimitiveHeapObject TorqueGeneratedScript<D, P>::source() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=20&c=3
template<class D, class P>
PrimitiveHeapObject TorqueGeneratedScript<D, P>::source(PtrComprCageBase cage_base) const {
  PrimitiveHeapObject value;
  value = TaggedField<PrimitiveHeapObject>::load(cage_base, *this, kSourceOffset);
  DCHECK(value.IsUndefined() || value.IsString());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source(PrimitiveHeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsUndefined() || value.IsString());
  WRITE_FIELD(*this, kSourceOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=23&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=23&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::name(PtrComprCageBase cage_base) const {
  Object value;
  value = TaggedField<Object>::load(cage_base, *this, kNameOffset);
  DCHECK(value.IsHeapObject() || value.IsSmi());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=23&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_name(Object value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsHeapObject() || value.IsSmi());
  WRITE_FIELD(*this, kNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=26&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::line_offset() const {
  int value;
  value = TaggedField<Smi>::load(*this, kLineOffsetOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=26&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_line_offset(int value) {
  WRITE_FIELD(*this, kLineOffsetOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=30&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::column_offset() const {
  int value;
  value = TaggedField<Smi>::load(*this, kColumnOffsetOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=30&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_column_offset(int value) {
  WRITE_FIELD(*this, kColumnOffsetOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=33&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::context_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::context_data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=33&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::context_data(PtrComprCageBase cage_base) const {
  Object value;
  value = TaggedField<Object>::load(cage_base, *this, kContextDataOffset);
  DCHECK(value.IsUndefined() || value.IsSymbol() || value.IsSmi());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=33&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_context_data(Object value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsUndefined() || value.IsSymbol() || value.IsSmi());
  WRITE_FIELD(*this, kContextDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kContextDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=35&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::script_type() const {
  int value;
  value = TaggedField<Smi>::load(*this, kScriptTypeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=35&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_script_type(int value) {
  WRITE_FIELD(*this, kScriptTypeOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=38&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::line_ends() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::line_ends(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=38&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::line_ends(PtrComprCageBase cage_base) const {
  Object value;
  value = TaggedField<Object>::load(cage_base, *this, kLineEndsOffset);
  DCHECK(value.IsSmi() || value.IsFixedArray());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=38&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_line_ends(Object value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsSmi() || value.IsFixedArray());
  WRITE_FIELD(*this, kLineEndsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLineEndsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=41&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::id() const {
  int value;
  value = TaggedField<Smi>::load(*this, kIdOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=41&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_id(int value) {
  WRITE_FIELD(*this, kIdOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=46&c=3
template<class D, class P>
HeapObject TorqueGeneratedScript<D, P>::eval_from_shared_or_wrapped_arguments() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::eval_from_shared_or_wrapped_arguments(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=46&c=3
template<class D, class P>
HeapObject TorqueGeneratedScript<D, P>::eval_from_shared_or_wrapped_arguments(PtrComprCageBase cage_base) const {
  HeapObject value;
  value = TaggedField<HeapObject>::load(cage_base, *this, kEvalFromSharedOrWrappedArgumentsOffset);
  DCHECK(value.IsUndefined() || value.IsFixedArray() || value.IsSharedFunctionInfo());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=46&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_eval_from_shared_or_wrapped_arguments(HeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsUndefined() || value.IsFixedArray() || value.IsSharedFunctionInfo());
  WRITE_FIELD(*this, kEvalFromSharedOrWrappedArgumentsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEvalFromSharedOrWrappedArgumentsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=48&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::eval_from_position() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::eval_from_position(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=48&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::eval_from_position(PtrComprCageBase cage_base) const {
  Object value;
  value = TaggedField<Object>::load(cage_base, *this, kEvalFromPositionOffset);
  DCHECK(value.IsSmi() || value.IsForeign());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=48&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_eval_from_position(Object value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsSmi() || value.IsForeign());
  WRITE_FIELD(*this, kEvalFromPositionOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEvalFromPositionOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
template<class D, class P>
HeapObject TorqueGeneratedScript<D, P>::shared_function_infos() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::shared_function_infos(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
template<class D, class P>
HeapObject TorqueGeneratedScript<D, P>::shared_function_infos(PtrComprCageBase cage_base) const {
  HeapObject value;
  value = TaggedField<HeapObject>::load(cage_base, *this, kSharedFunctionInfosOffset);
  DCHECK(value.IsWeakFixedArray() || value.IsWeakArrayList());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_shared_function_infos(HeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsWeakFixedArray() || value.IsWeakArrayList());
  WRITE_FIELD(*this, kSharedFunctionInfosOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSharedFunctionInfosOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=53&c=3
template<class D, class P>
HeapObject TorqueGeneratedScript<D, P>::compiled_lazy_function_positions() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::compiled_lazy_function_positions(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=53&c=3
template<class D, class P>
HeapObject TorqueGeneratedScript<D, P>::compiled_lazy_function_positions(PtrComprCageBase cage_base) const {
  HeapObject value;
  value = TaggedField<HeapObject>::load(cage_base, *this, kCompiledLazyFunctionPositionsOffset);
  DCHECK(value.IsUndefined() || value.IsArrayList());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=53&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_compiled_lazy_function_positions(HeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsUndefined() || value.IsArrayList());
  WRITE_FIELD(*this, kCompiledLazyFunctionPositionsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCompiledLazyFunctionPositionsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=56&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::flags() const {
  int value;
  value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=56&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=59&c=3
template<class D, class P>
PrimitiveHeapObject TorqueGeneratedScript<D, P>::source_url() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source_url(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=59&c=3
template<class D, class P>
PrimitiveHeapObject TorqueGeneratedScript<D, P>::source_url(PtrComprCageBase cage_base) const {
  PrimitiveHeapObject value;
  value = TaggedField<PrimitiveHeapObject>::load(cage_base, *this, kSourceUrlOffset);
  DCHECK(value.IsUndefined() || value.IsString());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=59&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source_url(PrimitiveHeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsUndefined() || value.IsString());
  WRITE_FIELD(*this, kSourceUrlOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceUrlOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=62&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::source_mapping_url() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source_mapping_url(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=62&c=3
template<class D, class P>
Object TorqueGeneratedScript<D, P>::source_mapping_url(PtrComprCageBase cage_base) const {
  Object value;
  value = TaggedField<Object>::load(cage_base, *this, kSourceMappingUrlOffset);
  DCHECK(value.IsHeapObject() || value.IsSmi());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=62&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source_mapping_url(Object value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsHeapObject() || value.IsSmi());
  WRITE_FIELD(*this, kSourceMappingUrlOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceMappingUrlOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=65&c=3
template<class D, class P>
FixedArray TorqueGeneratedScript<D, P>::host_defined_options() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::host_defined_options(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=65&c=3
template<class D, class P>
FixedArray TorqueGeneratedScript<D, P>::host_defined_options(PtrComprCageBase cage_base) const {
  FixedArray value;
  value = TaggedField<FixedArray>::load(cage_base, *this, kHostDefinedOptionsOffset);
  DCHECK(value.IsFixedArray());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=65&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_host_defined_options(FixedArray value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsFixedArray());
  WRITE_FIELD(*this, kHostDefinedOptionsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kHostDefinedOptionsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=74&c=3
template<class D, class P>
PrimitiveHeapObject TorqueGeneratedScript<D, P>::source_hash() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source_hash(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=74&c=3
template<class D, class P>
PrimitiveHeapObject TorqueGeneratedScript<D, P>::source_hash(PtrComprCageBase cage_base) const {
  PrimitiveHeapObject value;
  value = TaggedField<PrimitiveHeapObject>::load(cage_base, *this, kSourceHashOffset);
  DCHECK(value.IsUndefined() || value.IsString());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=74&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source_hash(PrimitiveHeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsUndefined() || value.IsString());
  WRITE_FIELD(*this, kSourceHashOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceHashOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
template<class D, class P>
D TorqueGeneratedScript<D, P>::cast(Object object) {
    return D(object.ptr());
}

template<class D, class P>
inline TorqueGeneratedScript<D, P>::TorqueGeneratedScript(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsScript_NonInline(*this));
}
