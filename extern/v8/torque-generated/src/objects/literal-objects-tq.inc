class ArrayBoilerplateDescription;
class RegExpBoilerplateDescription;
// Alias for HeapObject::IsArrayBoilerplateDescription() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsArrayBoilerplateDescription_NonInline(HeapObject o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedArrayBoilerplateDescription : public P {
  static_assert(
      std::is_same<ArrayBoilerplateDescription, D>::value,
      "Use this class as direct base for ArrayBoilerplateDescription.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedArrayBoilerplateDescription.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedArrayBoilerplateDescription<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=6&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=6&c=3
  inline void set_flags(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=7&c=3
  inline FixedArrayBase constant_elements() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=7&c=3
  inline FixedArrayBase constant_elements(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=7&c=3
  inline void set_constant_elements(FixedArrayBase value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
  V8_INLINE static D cast(Object object);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
  V8_INLINE static D unchecked_cast(Object object) {
    return base::bit_cast<D>(object);
  }

  DECL_PRINTER(ArrayBoilerplateDescription)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
  V8_EXPORT_PRIVATE void ArrayBoilerplateDescriptionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=6&c=3
  static constexpr int kFlagsOffset = P::kHeaderSize;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=7&c=3
  static constexpr int kConstantElementsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kConstantElementsOffsetEnd = kConstantElementsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kHeaderSize = kConstantElementsOffsetEnd + 1;
  static constexpr int kSize = kConstantElementsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedArrayBoilerplateDescription() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedArrayBoilerplateDescription, DAlias>::value,
        "class TorqueGeneratedArrayBoilerplateDescription should be used as direct base for ArrayBoilerplateDescription.");
  }

 protected:
  inline explicit TorqueGeneratedArrayBoilerplateDescription(Address ptr);
};

// Alias for HeapObject::IsRegExpBoilerplateDescription() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=1
V8_EXPORT_PRIVATE bool IsRegExpBoilerplateDescription_NonInline(HeapObject o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=1
template <class D, class P>
class TorqueGeneratedRegExpBoilerplateDescription : public P {
  static_assert(
      std::is_same<RegExpBoilerplateDescription, D>::value,
      "Use this class as direct base for RegExpBoilerplateDescription.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedRegExpBoilerplateDescription.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedRegExpBoilerplateDescription<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=11&c=3
  inline FixedArray data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=11&c=3
  inline FixedArray data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=11&c=3
  inline void set_data(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=12&c=3
  inline String source() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=12&c=3
  inline String source(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=12&c=3
  inline void set_source(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=3
  inline void set_flags(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=1
  V8_INLINE static D cast(Object object);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=1
  V8_INLINE static D unchecked_cast(Object object) {
    return base::bit_cast<D>(object);
  }

  DECL_PRINTER(RegExpBoilerplateDescription)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=1
  V8_EXPORT_PRIVATE void RegExpBoilerplateDescriptionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=11&c=3
  static constexpr int kDataOffset = P::kHeaderSize;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=12&c=3
  static constexpr int kSourceOffset = kDataOffsetEnd + 1;
  static constexpr int kSourceOffsetEnd = kSourceOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=3
  static constexpr int kFlagsOffset = kSourceOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;
  static constexpr int kSize = kFlagsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 32);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedRegExpBoilerplateDescription() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedRegExpBoilerplateDescription, DAlias>::value,
        "class TorqueGeneratedRegExpBoilerplateDescription should be used as direct base for RegExpBoilerplateDescription.");
  }

 protected:
  inline explicit TorqueGeneratedRegExpBoilerplateDescription(Address ptr);
};

