# OH_AbilityRuntime_ModObjDispatcher_TypeInfo

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:15:11.224Z pushedAt=2026-08-14T01:50:28.119Z -->

```c
typedef struct OH_AbilityRuntime_ModObjDispatcher_TypeInfo {...} OH_AbilityRuntime_ModObjDispatcher_TypeInfo
```

## Overview

Defines the type information of a parameter or return value.

Uses the tagged union u to describe the type information, and uses the vt field to determine which member of the union is valid.

- For the map (MAP) type, use u.mapType.keyType to describe the key type and u.mapType.pValueType to describe the value type.

- For the array (ARRAY) type, use u.arrayType.pElementType to describe the element type and u.arrayType.size to describe the fixed size of the array.

- For the vector (VECTOR) or set (SET) type, use u.pElementType to describe the element type.  

- For the struct (STRUCT), remote communication object (IPC_REMOTE_PROXY, IPC_REMOTE_STUB), and enum (ENUM) types, use u.idlType to describe the [IDL type name](../../application-models/modular-object-extension-ability-taihe.md#ohidl-file-writing-specifications).  

After use, call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release the heap resources held internally.

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

**File to include:** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) vt | Type tag that determines which member of the union is valid.<br>**Since:** 26.0.0 |
| union {<br>struct {<br>[OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) keyType;<br>[OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pValueType;<br>} mapType;<br>struct {<br>[OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType;<br>uint32_t size;<br>} arrayType;<br>[OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType;<br>char* idlType;<br>} u | Union of type-specific metadata. The valid member is determined by vt.<br>mapType: metadata of the map type, used when vt is MAP.<br>mapType.keyType: key type of the map. Only basic types (BOOL, signed integer, unsigned integer, floating-point number, STRING, ENUM) are supported. Container types (ARRAY, VECTOR, SET, MAP) and complex types (STRUCT, IPC_REMOTE_PROXY, IPC_REMOTE_STUB) are not supported.<br>mapType.pValueType: handle to the value type descriptor, which must be released by calling [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear).<br>arrayType: metadata of the array type, used when vt is ARRAY.<br>arrayType.pElementType: handle to the element type descriptor, which must be released by calling [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear).<br>arrayType.size: fixed size of the array.<br>pElementType: handle to the element type descriptor, used when vt is VECTOR or SET, which must be released by calling [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear).<br>idlType: string of the [IDL type name](../../application-models/modular-object-extension-ability-taihe.md#ohidl-file-writing-specifications), used when vt is STRUCT, IPC_REMOTE_PROXY, IPC_REMOTE_STUB, or ENUM, which must be released by calling [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear).<br>**Since:** 26.0.0 |