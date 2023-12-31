// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
template<class D, class P>
String TorqueGeneratedSyntheticModule<D, P>::name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSyntheticModule::name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
template<class D, class P>
String TorqueGeneratedSyntheticModule<D, P>::name(PtrComprCageBase cage_base) const {
  String value;
  value = TaggedField<String>::load(cage_base, *this, kNameOffset);
  DCHECK(value.IsString());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedSyntheticModule<D, P>::set_name(String value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsString());
  WRITE_FIELD(*this, kNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
template<class D, class P>
FixedArray TorqueGeneratedSyntheticModule<D, P>::export_names() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSyntheticModule::export_names(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
template<class D, class P>
FixedArray TorqueGeneratedSyntheticModule<D, P>::export_names(PtrComprCageBase cage_base) const {
  FixedArray value;
  value = TaggedField<FixedArray>::load(cage_base, *this, kExportNamesOffset);
  DCHECK(value.IsFixedArray());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
template<class D, class P>
void TorqueGeneratedSyntheticModule<D, P>::set_export_names(FixedArray value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsFixedArray());
  WRITE_FIELD(*this, kExportNamesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kExportNamesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
template<class D, class P>
Foreign TorqueGeneratedSyntheticModule<D, P>::evaluation_steps() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSyntheticModule::evaluation_steps(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
template<class D, class P>
Foreign TorqueGeneratedSyntheticModule<D, P>::evaluation_steps(PtrComprCageBase cage_base) const {
  Foreign value;
  value = TaggedField<Foreign>::load(cage_base, *this, kEvaluationStepsOffset);
  DCHECK(value.IsForeign());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedSyntheticModule<D, P>::set_evaluation_steps(Foreign value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsForeign());
  WRITE_FIELD(*this, kEvaluationStepsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEvaluationStepsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=5&c=1
template<class D, class P>
D TorqueGeneratedSyntheticModule<D, P>::cast(Object object) {
    return D(object.ptr());
}

template<class D, class P>
inline TorqueGeneratedSyntheticModule<D, P>::TorqueGeneratedSyntheticModule(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSyntheticModule_NonInline(*this));
}
