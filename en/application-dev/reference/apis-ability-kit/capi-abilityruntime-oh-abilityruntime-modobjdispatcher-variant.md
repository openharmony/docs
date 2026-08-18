# OH_AbilityRuntime_ModObjDispatcher_Variant

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:15:11.847Z pushedAt=2026-08-14T02:52:21.101Z -->

```c
typedef struct {...} OH_AbilityRuntime_ModObjDispatcher_Variant
```

## Overview

Defines a variant struct that uses a union with a type tag to distinguish the actual data type, for safely passing values of multiple types during parameter passing and return value receiving.

The value of a variant is determined by the vt field, which specifies the actual stored data type and the valid member of the union.

When a variant holds heap-allocated resources (such as strings and container handles), call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release them.

Simple types (boolean, integer, and floating-point) do not hold heap resources and do not need to be released by calling OH_AbilityRuntime_ModObjDispatcher_VariantClear.

> **NOTE**
>
> Do not call OH_AbilityRuntime_ModObjDispatcher_VariantClear on a shallow copy of the variant. If Variant v2 = v1 is executed, only one of them can be cleared.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**File to include:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) vt | Type tag of the variant, which determines the valid member in the union.<br>**Since:** 26.0.0 |
| uint64_t reserved1 | Reserved field 1. Reserved for future version extension. The caller should initialize it to 0 and should not read or modify it.<br>**Since:** 26.0.0 |
| uint64_t reserved2 | Reserved field 2. Reserved for future version extension. The caller should initialize it to 0 and should not read or modify it.<br>**Since:** 26.0.0 |
| uint64_t reserved3 | Reserved field 3. Reserved for future version extension. The caller should initialize it to 0 and should not read or modify it.<br>**Since:** 26.0.0 |
| union {<br>void* pvoidVal;<br>bool boolVal;<br>int8_t i8Val;<br>int16_t i16Val;<br>int32_t i32Val;<br>int64_t i64Val;<br>uint8_t u8Val;<br>uint16_t u16Val;<br>uint32_t u32Val;<br>uint64_t u64Val;<br>float f32Val;<br>double f64Val;<br>int32_t enumVal;<br>char* bstrVal;<br>[OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) parrayVal;<br>[OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pvectorVal;<br>[OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) psetVal;<br>[OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pmapVal;<br>[OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pstructVal;<br>[OHIPCRemoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md)* premoteProxyVal;<br>[OHIPCRemoteStub](../apis-ipc-kit/capi-ohipcparcel-ohipcremotestub.md)* premoteStubVal;<br>} u | Union of the variant value data. The valid member is determined by vt.<br>pvoidVal: void pointer.<br>boolVal: boolean value.<br>i8Val: 8-bit signed integer.<br>i16Val: 16-bit signed integer.<br>i32Val: 32-bit signed integer.<br>i64Val: 64-bit signed integer.<br>u8Val: 8-bit unsigned integer.<br>u16Val: 16-bit unsigned integer.<br>u32Val: 32-bit unsigned integer.<br>u64Val: 64-bit unsigned integer.<br>f32Val: 32-bit floating-point number (single precision).<br>f64Val: 64-bit floating-point number (double precision).<br>enumVal: enum value, stored as int32_t.<br>bstrVal: UTF-8 string handle, pointing to a heap-allocated string.<br>parrayVal: array handle.<br>pvectorVal: vector handle.<br>psetVal: set handle.<br>pmapVal: map handle.<br>pstructVal: struct handle.<br>premoteProxyVal: remote Proxy object handle.<br>premoteStubVal: remote Stub object handle.<br>**Since:** 26.0.0 |