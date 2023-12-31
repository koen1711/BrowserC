// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-raw-json.tq?l=7&c=1
template<class D, class P>
D TorqueGeneratedJSRawJson<D, P>::cast(Object object) {
    return D(object.ptr());
}

template<class D, class P>
inline TorqueGeneratedJSRawJson<D, P>::TorqueGeneratedJSRawJson(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSRawJson_NonInline(*this));
}
