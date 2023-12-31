// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=5&c=1
template<class D, class P>
D TorqueGeneratedMicrotask<D, P>::cast(Object object) {
    return D(object.ptr());
}

template<class D, class P>
inline TorqueGeneratedMicrotask<D, P>::TorqueGeneratedMicrotask(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsMicrotask_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=10&c=3
template<class D, class P>
Foreign TorqueGeneratedCallbackTask<D, P>::callback() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallbackTask::callback(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=10&c=3
template<class D, class P>
Foreign TorqueGeneratedCallbackTask<D, P>::callback(PtrComprCageBase cage_base) const {
  Foreign value;
  value = TaggedField<Foreign>::load(cage_base, *this, kCallbackOffset);
  DCHECK(value.IsForeign());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedCallbackTask<D, P>::set_callback(Foreign value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsForeign());
  WRITE_FIELD(*this, kCallbackOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallbackOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=3
template<class D, class P>
Foreign TorqueGeneratedCallbackTask<D, P>::data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallbackTask::data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=3
template<class D, class P>
Foreign TorqueGeneratedCallbackTask<D, P>::data(PtrComprCageBase cage_base) const {
  Foreign value;
  value = TaggedField<Foreign>::load(cage_base, *this, kDataOffset);
  DCHECK(value.IsForeign());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=3
template<class D, class P>
void TorqueGeneratedCallbackTask<D, P>::set_data(Foreign value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsForeign());
  WRITE_FIELD(*this, kDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=9&c=1
template<class D, class P>
D TorqueGeneratedCallbackTask<D, P>::cast(Object object) {
    return D(object.ptr());
}

template<class D, class P>
inline TorqueGeneratedCallbackTask<D, P>::TorqueGeneratedCallbackTask(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsCallbackTask_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=15&c=3
template<class D, class P>
JSReceiver TorqueGeneratedCallableTask<D, P>::callable() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallableTask::callable(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=15&c=3
template<class D, class P>
JSReceiver TorqueGeneratedCallableTask<D, P>::callable(PtrComprCageBase cage_base) const {
  JSReceiver value;
  value = TaggedField<JSReceiver>::load(cage_base, *this, kCallableOffset);
  DCHECK(value.IsJSReceiver());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedCallableTask<D, P>::set_callable(JSReceiver value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsJSReceiver());
  WRITE_FIELD(*this, kCallableOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallableOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=3
template<class D, class P>
Context TorqueGeneratedCallableTask<D, P>::context() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallableTask::context(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=3
template<class D, class P>
Context TorqueGeneratedCallableTask<D, P>::context(PtrComprCageBase cage_base) const {
  Context value;
  value = TaggedField<Context>::load(cage_base, *this, kContextOffset);
  DCHECK(value.IsContext());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=3
template<class D, class P>
void TorqueGeneratedCallableTask<D, P>::set_context(Context value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsContext());
  WRITE_FIELD(*this, kContextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kContextOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=14&c=1
template<class D, class P>
D TorqueGeneratedCallableTask<D, P>::cast(Object object) {
    return D(object.ptr());
}

template<class D, class P>
inline TorqueGeneratedCallableTask<D, P>::TorqueGeneratedCallableTask(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsCallableTask_NonInline(*this));
}
