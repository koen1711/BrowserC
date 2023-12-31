class Script;
// Alias for HeapObject::IsScript() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
V8_EXPORT_PRIVATE bool IsScript_NonInline(HeapObject o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
template <class D, class P>
class TorqueGeneratedScript : public P {
  static_assert(
      std::is_same<Script, D>::value,
      "Use this class as direct base for Script.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedScript.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedScript<D,P>;

  // Torque type: (Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=20&c=3
  inline PrimitiveHeapObject source() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=20&c=3
  inline PrimitiveHeapObject source(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=20&c=3
  inline void set_source(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=23&c=3
  inline Object name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=23&c=3
  inline Object name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=23&c=3
  inline void set_name(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=26&c=3
  inline int line_offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=26&c=3
  inline void set_line_offset(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=30&c=3
  inline int column_offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=30&c=3
  inline void set_column_offset(int value);

  // Torque type: (Undefined | class Symbol | Smi)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=33&c=3
  inline Object context_data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=33&c=3
  inline Object context_data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=33&c=3
  inline void set_context_data(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=35&c=3
  inline int script_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=35&c=3
  inline void set_script_type(int value);

  // Torque type: (Smi | class FixedArray)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=38&c=3
  inline Object line_ends() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=38&c=3
  inline Object line_ends(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=38&c=3
  inline void set_line_ends(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=41&c=3
  inline int id() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=41&c=3
  inline void set_id(int value);

  // Torque type: (Undefined | class FixedArray | class SharedFunctionInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=46&c=3
  inline HeapObject eval_from_shared_or_wrapped_arguments() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=46&c=3
  inline HeapObject eval_from_shared_or_wrapped_arguments(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=46&c=3
  inline void set_eval_from_shared_or_wrapped_arguments(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | class Foreign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=48&c=3
  inline Object eval_from_position() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=48&c=3
  inline Object eval_from_position(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=48&c=3
  inline void set_eval_from_position(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class WeakFixedArray | class WeakArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  inline HeapObject shared_function_infos() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  inline HeapObject shared_function_infos(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  inline void set_shared_function_infos(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | class ArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=53&c=3
  inline HeapObject compiled_lazy_function_positions() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=53&c=3
  inline HeapObject compiled_lazy_function_positions(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=53&c=3
  inline void set_compiled_lazy_function_positions(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=56&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=56&c=3
  inline void set_flags(int value);

  // Torque type: (Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=59&c=3
  inline PrimitiveHeapObject source_url() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=59&c=3
  inline PrimitiveHeapObject source_url(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=59&c=3
  inline void set_source_url(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=62&c=3
  inline Object source_mapping_url() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=62&c=3
  inline Object source_mapping_url(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=62&c=3
  inline void set_source_mapping_url(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=65&c=3
  inline FixedArray host_defined_options() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=65&c=3
  inline FixedArray host_defined_options(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=65&c=3
  inline void set_host_defined_options(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=74&c=3
  inline PrimitiveHeapObject source_hash() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=74&c=3
  inline PrimitiveHeapObject source_hash(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=74&c=3
  inline void set_source_hash(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
  V8_INLINE static D cast(Object object);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
  V8_INLINE static D unchecked_cast(Object object) {
    return base::bit_cast<D>(object);
  }

  DECL_PRINTER(Script)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
  V8_EXPORT_PRIVATE void ScriptVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=20&c=3
  static constexpr int kSourceOffset = P::kHeaderSize;
  static constexpr int kSourceOffsetEnd = kSourceOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=23&c=3
  static constexpr int kNameOffset = kSourceOffsetEnd + 1;
  static constexpr int kNameOffsetEnd = kNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=26&c=3
  static constexpr int kLineOffsetOffset = kNameOffsetEnd + 1;
  static constexpr int kLineOffsetOffsetEnd = kLineOffsetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=30&c=3
  static constexpr int kColumnOffsetOffset = kLineOffsetOffsetEnd + 1;
  static constexpr int kColumnOffsetOffsetEnd = kColumnOffsetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=33&c=3
  static constexpr int kContextDataOffset = kColumnOffsetOffsetEnd + 1;
  static constexpr int kContextDataOffsetEnd = kContextDataOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=35&c=3
  static constexpr int kScriptTypeOffset = kContextDataOffsetEnd + 1;
  static constexpr int kScriptTypeOffsetEnd = kScriptTypeOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=38&c=3
  static constexpr int kLineEndsOffset = kScriptTypeOffsetEnd + 1;
  static constexpr int kLineEndsOffsetEnd = kLineEndsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=41&c=3
  static constexpr int kIdOffset = kLineEndsOffsetEnd + 1;
  static constexpr int kIdOffsetEnd = kIdOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=46&c=3
  static constexpr int kEvalFromSharedOrWrappedArgumentsOffset = kIdOffsetEnd + 1;
  static constexpr int kEvalFromSharedOrWrappedArgumentsOffsetEnd = kEvalFromSharedOrWrappedArgumentsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=48&c=3
  static constexpr int kEvalFromPositionOffset = kEvalFromSharedOrWrappedArgumentsOffsetEnd + 1;
  static constexpr int kEvalFromPositionOffsetEnd = kEvalFromPositionOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  static constexpr int kSharedFunctionInfosOffset = kEvalFromPositionOffsetEnd + 1;
  static constexpr int kSharedFunctionInfosOffsetEnd = kSharedFunctionInfosOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=53&c=3
  static constexpr int kCompiledLazyFunctionPositionsOffset = kSharedFunctionInfosOffsetEnd + 1;
  static constexpr int kCompiledLazyFunctionPositionsOffsetEnd = kCompiledLazyFunctionPositionsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=56&c=3
  static constexpr int kFlagsOffset = kCompiledLazyFunctionPositionsOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=59&c=3
  static constexpr int kSourceUrlOffset = kFlagsOffsetEnd + 1;
  static constexpr int kSourceUrlOffsetEnd = kSourceUrlOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=62&c=3
  static constexpr int kSourceMappingUrlOffset = kSourceUrlOffsetEnd + 1;
  static constexpr int kSourceMappingUrlOffsetEnd = kSourceMappingUrlOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=65&c=3
  static constexpr int kHostDefinedOptionsOffset = kSourceMappingUrlOffsetEnd + 1;
  static constexpr int kHostDefinedOptionsOffsetEnd = kHostDefinedOptionsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=74&c=3
  static constexpr int kSourceHashOffset = kHostDefinedOptionsOffsetEnd + 1;
  static constexpr int kSourceHashOffsetEnd = kSourceHashOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSourceHashOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSourceHashOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSourceHashOffsetEnd + 1;
  static constexpr int kHeaderSize = kSourceHashOffsetEnd + 1;
  static constexpr int kSize = kSourceHashOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 144);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=18&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedScript() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedScript, DAlias>::value,
        "class TorqueGeneratedScript should be used as direct base for Script.");
  }

 protected:
  inline explicit TorqueGeneratedScript(Address ptr);
};

