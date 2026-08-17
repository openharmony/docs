# modular_object_dispatcher.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:21:39.759Z pushedAt=2026-08-14T06:49:10.274Z -->

## Overview

Declares the ModularObject dispatcher APIs, providing cross-process deferred binding invocation capabilities based on type library metadata.

Through this module, developers can create a main service or sub-instance dispatcher from a remote Proxy object, query the type library metadata (interface/method/enum/struct) of the remote service, dynamically invoke remote methods by member ID (MemberID), and create and operate container types (Array/Vector/Set/Map) and structs.

**File to include:** <AbilityKit/ability_runtime/modular_object_dispatcher.h>

**Library:** libability_runtime.so

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Since**: 26.0.0

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md) | OH_AbilityRuntime_ModObjDispatcher_TypeInfo | Defines the type information of a parameter or return value.<br>Uses a tagged union [u](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md#member-variable) to describe the type information, and the [vt](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md#member-variable) field determines which member of the union is valid.<br>For the map (MAP) type, u.mapType.keyType describes the key type and u.mapType.pValueType describes the value type.<br>For the array (ARRAY) type, u.arrayType.pElementType describes the element type and u.arrayType.size describes the array length.<br>For the vector (VECTOR) or set (SET) type, u.pElementType describes the element type.<br>For the struct (STRUCT), remote communication object (IPC_REMOTE_PROXY, IPC_REMOTE_STUB), and enum (ENUM) types, u.idlType describes the [IDL type name](../../application-models/modular-object-extension-ability-taihe.md#ohidl-file-writing-specifications).<br>After use, call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release the internally held heap resources. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md) | OH_AbilityRuntime_ModObjDispatcher_Variant | Defines a variant structure that uses a union plus a type tag. The type tag distinguishes the actual data type, and is used to safely pass values of multiple types during parameter passing and return value receiving.<br>The variant value is determined by the [vt](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md#member-variable) field, which specifies the actual stored data type and the valid member of the union.<br>When the variant holds heap-allocated resources (such as strings and container handles), call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release them. |
| [OH_AbilityRuntime_ModObjDispatcher_InputParams](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md) | OH_AbilityRuntime_ModObjDispatcher_InputParams | Defines the parameter structure of a method invocation. [rgvarg](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md#member-variable) points to the array of parameter variants, and the array length is specified by [cArgs](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md#member-variable). The parameter order must be consistent with the parameter order in the method definition. |
| [OH_AbilityRuntime_ModularObjectDispatcher_TypeDescriptor*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) | OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle | Defines the type descriptor handle of the ModularObject dispatcher.<br>This handle points to the access interface of the type library metadata, and can be used to query information such as interfaces, methods, enums, and structs defined by the remote service.<br>It can be obtained through [OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor), and must be released through [OH_AbilityRuntime_TypeDescriptor_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_release) after use. |
| [OH_AbilityRuntime_ModularObjectDispatcher*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) | OH_AbilityRuntime_ModObjDispatcherHandle | Handle of the ModularObject dispatcher.<br>This handle points to a ModularObject dispatcher instance. It can be created through [OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createmainserviceinstance) or [OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createsubinstance), and must be released through [OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release) after use. |
| [OH_AbilityRuntime_ModularObjectDispatcher_Array*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) | OH_AbilityRuntime_ModObjDispatcher_ArrayHandle | Array handle.<br>This handle points to a fixed-size ordered collection of elements, where all elements are of the same type. It supports setting and obtaining elements by index and querying the array size.<br>It can be created through [OH_AbilityRuntime_ModObjDispatcher_ArrayCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arraycreate), and must be released through [OH_AbilityRuntime_ModObjDispatcher_ArrayRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arrayrelease) after use. |
| [OH_AbilityRuntime_ModularObjectDispatcher_Vector*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) | OH_AbilityRuntime_ModObjDispatcher_VectorHandle | Vector handle.<br>This handle points to a dynamically sized ordered collection of elements, where all elements are of the same type. It supports adding elements, obtaining elements by index, querying the vector size, and clearing operations.<br>It can be created through [OH_AbilityRuntime_ModObjDispatcher_VectorCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorcreate), and must be released through [OH_AbilityRuntime_ModObjDispatcher_VectorRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorrelease) after use. |
| [OH_AbilityRuntime_ModularObjectDispatcher_Set*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) | OH_AbilityRuntime_ModObjDispatcher_SetHandle | Set handle.<br>This handle points to an unordered set of non-duplicate elements, where all elements are of the same type. It supports adding elements, deleting elements, querying whether a specified element exists, obtaining elements by index, querying the set size, and clearing operations.<br>It can be created through [OH_AbilityRuntime_ModObjDispatcher_SetCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setcreate), and must be released through [OH_AbilityRuntime_ModObjDispatcher_SetRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setrelease) after use. |
| [OH_AbilityRuntime_ModularObjectDispatcher_Map*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) | OH_AbilityRuntime_ModObjDispatcher_MapHandle | Map handle.<br>This handle points to an ordered collection of key-value pairs. The key and value types are specified at creation. It supports adding or updating key-value pairs, obtaining values by key, deleting key-value pairs, querying whether a specified key exists, obtaining keys or values by index, querying the map size, and clearing operations.<br>Keys support only primitive types (BOOL, signed integer, unsigned integer, floating-point number, STRING, ENUM).<br>It can be created through [OH_AbilityRuntime_ModObjDispatcher_MapCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapcreate), and must be released through [OH_AbilityRuntime_ModObjDispatcher_MapRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_maprelease) after use. |
| [OH_AbilityRuntime_ModularObjectDispatcher_Struct*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) | OH_AbilityRuntime_ModObjDispatcher_StructHandle | Struct handle.<br>This handle points to a struct instance with named fields, where the field types are defined by the type library metadata.<br>It can be created through [OH_AbilityRuntime_ModObjDispatcher_StructCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_structcreate), and must be released through [OH_AbilityRuntime_ModObjDispatcher_StructRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_structrelease) after use. |

### Enums

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) | OH_AbilityRuntime_ModObjDispatcher_ValueType | Enumerates the variant types, used to identify the data type of a variant value.<br>A variant is a general-purpose data container that can store values of multiple different types, similar to a union in the C language. Each variant holds only one type of value at a time, and this enum value identifies the data type actually stored.<br>In this module, variants are used for parameter passing and return value receiving in method calls, so that the same set of APIs can handle multiple data types such as boolean, integer, floating-point number, string, array, vector, set, map, struct, and remote communication object. |

### Functions

| Name | Description |
| -- | -- |
| [void OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pTypeInfo)](#oh_abilityruntime_modobjdispatcher_typeinfoclear) | Clears the heap resources held by the TypeInfo struct.<br>Recursively releases the heap resources held by TypeInfo. After clearing, all internal pointers are set to NULL, vt is reset to VT_EMPTY, but the TypeInfo struct itself is not released (it is usually allocated on the stack by the caller).<br>Heap resources held by each type:<br>- Map (MAP) type: recursively releases and deletes the child TypeInfo node allocated by new (u.mapType.pValueType).<br>- Array (ARRAY) type: recursively releases and deletes the child TypeInfo node allocated by new (u.arrayType.pElementType).<br>- Vector (VECTOR) or set (SET) type: recursively releases and deletes the child TypeInfo node allocated by new (u.pElementType).<br>- Struct (STRUCT), enum (ENUM), and remote communication object (IPC_REMOTE_PROXY, IPC_REMOTE_STUB) types: releases the u.idlType string (allocated by strdup). |
| [void OH_AbilityRuntime_ModObjDispatcher_VariantClear(OH_AbilityRuntime_ModObjDispatcher_Variant* pVariant)](#oh_abilityruntime_modobjdispatcher_variantclear) | Clears the resources held by the variant. Releases the resources held by the variant (strings, container handles, etc.). After clearing, the variant is reset to VT_EMPTY and all fields are zeroed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance(OHIPCRemoteProxy* remoteProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)](#oh_abilityruntime_modobjdispatcher_createmainserviceinstance) | Creates a ModularObject dispatcher instance for the main service interface from a remote Proxy object.<br>The type library metadata is lazily loaded from the remote service when first needed (for example, when [OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor), [OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_hastypedescriptor), [OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames), or [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod) is called).<br>The caller must call [OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release) to release the dispatcher instance when it is no longer used, to avoid memory leaks. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance(OH_AbilityRuntime_ModObjDispatcherHandle mainServiceDispatcher, OHIPCRemoteProxy* subProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)](#oh_abilityruntime_modobjdispatcher_createsubinstance) | Creates a sub-instance dispatcher bound to the main service dispatcher.<br>The sub-instance shares the type library metadata of the main service dispatcher but uses an independent IPC proxy to send requests. It is suitable for scenarios where non-main-service interfaces in the same type library need to be called.<br>When [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod) is called on the sub-instance, the method signature is resolved from the type library metadata of the main service dispatcher, and the IPC request is sent to the remote service through subProxy.<br>The caller must call [OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release) to release the sub-instance when it is no longer used, to avoid memory leaks. |
| [void OH_AbilityRuntime_ModObjDispatcher_Release(OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)](#oh_abilityruntime_modobjdispatcher_release) | Releases the ModularObject dispatcher instance. After release, the pointer is set to NULL. If ppModObjDispatcher or *ppModObjDispatcher is NULL, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t* pctinfo)](#oh_abilityruntime_modobjdispatcher_hastypedescriptor) | Checks whether the remote service supports type library metadata. Calling this API triggers the lazy loading of the type library metadata. If the metadata is loaded successfully, *pctinfo is 1; otherwise, it is 0. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* ppTypeDescriptor)](#oh_abilityruntime_modobjdispatcher_gettypedescriptor) | Obtains the type descriptor handle for querying interface metadata information.<br>The type descriptor provides access to the type library metadata of the remote service, including the definition information of interfaces, methods, enums, and structs. Calling this API triggers the lazy loading of the type library metadata.<br>After use, call [OH_AbilityRuntime_TypeDescriptor_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_release) to release the handle. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, const char** rgszNames, uint32_t cNames, uint32_t* pMemID)](#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames) | Queries the method member IDs (MemberID) corresponding to the method names in the main service interface. The returned member IDs can be used as the memID parameter of [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod). Calling this API triggers the lazy loading of the type library metadata. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CallMethod(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t memID, OH_AbilityRuntime_ModObjDispatcher_InputParams* pInputParams, OH_AbilityRuntime_ModObjDispatcher_Variant* pResult, int32_t* pMethodErrCode)](#oh_abilityruntime_modobjdispatcher_callmethod) | Calls a remote method by member ID (MemberID).<br>Calling process: obtains the method metadata (method name, parameter types, return type, IPC code, etc.) from the metadata manager through memID, serializes the parameters into a MessageParcel, sends the request to the remote service through IPC, and finally deserializes the returned result.<br>This API uses a two-layer error handling mechanism:<br>- Framework-level errors: issues at the framework level such as IPC communication, metadata loading, and parameter validation are returned through the method return value.<br>- Method-level errors: business errors returned by the execution of the remote method are returned through the pMethodErrCode output parameter. |
| [void OH_AbilityRuntime_TypeDescriptor_Release(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* pTypeDescriptor)](#oh_abilityruntime_typedescriptor_release) | Releases the type descriptor instance. After release, the handle is set to NULL. If pTypeDescriptor or *pTypeDescriptor is NULL, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetVersion(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrVersion, uint32_t cMaxVersion)](#oh_abilityruntime_typedescriptor_getversion) | Obtains the version number of the type library. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcInterfaces)](#oh_abilityruntime_typedescriptor_getinterfacecount) | Obtains the total number of interfaces defined in the type library. The returned count can be used to determine the upper limit of the index when traversing interfaces. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getinterfacename) | Obtains the interface name by index. The valid range of the interface index is [0, interfaceCount - 1], where interfaceCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getinterfacecount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceIsCallback(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrName, bool* pIsCallback)](#oh_abilityruntime_typedescriptor_getinterfaceiscallback) | Checks whether the specified interface is a callback type. A callback interface indicates that the interface needs to be implemented by the client and provided to the server for invocation. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMainServiceInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getmainserviceinterfacename) | Obtains the name of the main service interface.<br>The main service interface is the default interface exposed by the remote ModularObjectExtensionAbility, that is, the interface corresponding to the Proxy object bound when the dispatcher is created through [OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createmainserviceinstance).<br>This interface is declared by the remote service in the type library metadata, and its name can be obtained through this API. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t* pcMethods)](#oh_abilityruntime_typedescriptor_getmethodcount) | Obtains the total number of methods defined in the specified interface. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getmethodname) | Obtains the method name in the interface by index. The valid range of the method index is [0, methodCount - 1], where methodCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetMethodCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodcount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pMemID)](#oh_abilityruntime_typedescriptor_getmethodmemberid) | Obtains the member ID (MemberID) of a method by method name. The returned member ID can be used as the memID parameter of [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pReturnType)](#oh_abilityruntime_typedescriptor_getmethodreturntype) | Obtains the return type of a method. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pcParams)](#oh_abilityruntime_typedescriptor_getmethodparamcount) | Obtains the number of parameters of a method. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pParamType)](#oh_abilityruntime_typedescriptor_getmethodparamtype) | Obtains the type of a method parameter by index. The valid range of the parameter index is [0, paramCount - 1], where paramCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getmethodparamname) | Obtains the name of a method parameter by index. The valid range of the parameter index is [0, paramCount - 1], where paramCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcEnums)](#oh_abilityruntime_typedescriptor_getenumcount) | Obtains the total number of enums defined in the type library. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getenumname) | Obtains the enum name by index. The valid range of the enum index is [0, enumCount - 1], where enumCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetEnumCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumcount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t* pcValues)](#oh_abilityruntime_typedescriptor_getenumvaluecount) | Obtains the number of enum values defined in the specified enum. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t iValueIndex, char* pbstrValueName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getenumvaluename) | Obtains the name of an enum value by index. The valid range of the enum value index is [0, valueCount - 1], where valueCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumvaluecount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValue(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, const char* pbstrValueName, int32_t* pValue)](#oh_abilityruntime_typedescriptor_getenumvalue) | Obtains the enum value by enum value name. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcStructs)](#oh_abilityruntime_typedescriptor_getstructcount) | Obtains the total number of structs defined in the type library. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getstructname) | Obtains the struct name by index. The valid range of the struct index is [0, structCount - 1], where structCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetStructCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructcount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t* pcFields)](#oh_abilityruntime_typedescriptor_getstructfieldcount) | Obtains the number of fields defined in the specified struct. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t iFieldIndex, char* pbstrFieldName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getstructfieldname) | Obtains the name of a struct field by index. The valid range of the struct field index is [0, fieldCount - 1], where fieldCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructfieldcount). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, const char* pbstrFieldName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pFieldType)](#oh_abilityruntime_typedescriptor_getstructfieldtype) | Obtains the type of a struct field by field name. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, uint32_t size, OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)](#oh_abilityruntime_modobjdispatcher_arraycreate) | Creates an array instance with the specified element type and size. The array has a fixed size and its length cannot be changed after creation. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)](#oh_abilityruntime_modobjdispatcher_arraygetelementtype) | Obtains the element type of the array. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArraySet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_arrayset) | Sets the element value at the specified index in the array. The function performs a deep copy, and the caller retains ownership of the original variant. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_arrayget) | Obtains the element value at the specified index in the array. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetSize(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_arraygetsize) | Obtains the size of the array. |
| [void OH_AbilityRuntime_ModObjDispatcher_ArrayRelease(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)](#oh_abilityruntime_modobjdispatcher_arrayrelease) | Releases the array instance. After release, the handle is set to NULL. If ppArray or *ppArray is NULL, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)](#oh_abilityruntime_modobjdispatcher_vectorcreate) | Creates a vector instance with the specified element type. The vector is an ordered collection of dynamic size. All elements have the same type. It supports adding elements, obtaining elements by index, querying the size, and clearing. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)](#oh_abilityruntime_modobjdispatcher_vectorgetelementtype) | Obtains the element type of the vector. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorAdd(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_vectoradd) | Adds an element to the end of the vector. The function performs a deep copy, and the caller retains ownership of the original variant. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGet(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_vectorget) | Obtains the element value at the specified index in the vector. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetSize(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_vectorgetsize) | Obtains the number of elements in the vector. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorClear(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector)](#oh_abilityruntime_modobjdispatcher_vectorclear) | Clears all elements in the vector. |
| [void OH_AbilityRuntime_ModObjDispatcher_VectorRelease(OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)](#oh_abilityruntime_modobjdispatcher_vectorrelease) | Releases the vector instance. After release, the handle is set to NULL. If ppVector or *ppVector is NULL, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)](#oh_abilityruntime_modobjdispatcher_setcreate) | Creates a set instance with the specified element type. The set is an unordered set of non-duplicate elements. All elements have the same type. It supports adding, removing, checking whether a specified element exists, obtaining elements by index, and clearing. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetElementType(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)](#oh_abilityruntime_modobjdispatcher_setgetelementtype) | Obtains the element type of the set. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetAdd(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_setadd) | Adds an element to the set. If the element already exists, it is not added again. The function performs a deep copy, and the caller retains ownership of the original variant. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetRemove(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_setremove) | Removes the specified element from the set. If the element does not exist, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetContains(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue, bool* pExists)](#oh_abilityruntime_modobjdispatcher_setcontains) | Checks whether the specified element exists in the set. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetSize(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_setgetsize) | Obtains the number of elements in the set. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetAt(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_setgetat) | Obtains the element value in the set by index. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetClear(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet)](#oh_abilityruntime_modobjdispatcher_setclear) | Clears all elements in the set. |
| [void OH_AbilityRuntime_ModObjDispatcher_SetRelease(OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)](#oh_abilityruntime_modobjdispatcher_setrelease) | Releases the set instance. After release, the handle is set to NULL. If ppSet or *ppSet is NULL, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapCreate(OH_AbilityRuntime_ModObjDispatcher_ValueType keyType, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* valueType, OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)](#oh_abilityruntime_modobjdispatcher_mapcreate) | Creates a map instance with the specified key type and value type.<br>The key supports only primitive types (BOOL, signed integer, unsigned integer, floating point, STRING, ENUM), and does not support container types (ARRAY, VECTOR, SET, MAP) or complex types (STRUCT, IPC_REMOTE_PROXY, IPC_REMOTE_STUB). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_ValueType* pKeyType)](#oh_abilityruntime_modobjdispatcher_mapgetkeytype) | Obtains the key type of the map. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pValueType)](#oh_abilityruntime_modobjdispatcher_mapgetvaluetype) | Obtains the value type of the map. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapPut(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_mapput) | Adds or updates a key-value pair in the map. If the key already exists, the corresponding value is updated. The function performs a deep copy, and the caller retains ownership of the original variants. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGet(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_mapget) | Obtains the value corresponding to the key in the map. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapRemove(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)](#oh_abilityruntime_modobjdispatcher_mapremove) | Removes the key-value pair from the map by key. If the key does not exist, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapContainsKey(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, bool* pExists)](#oh_abilityruntime_modobjdispatcher_mapcontainskey) | Checks whether the specified key exists in the map. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetSize(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_mapgetsize) | Obtains the number of key-value pairs in the map. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)](#oh_abilityruntime_modobjdispatcher_mapgetkeyat) | Obtains the key in the map by index. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_mapgetvalueat) | Obtains the value in the map by index. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapClear(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap)](#oh_abilityruntime_modobjdispatcher_mapclear) | Clears all key-value pairs in the map. |
| [void OH_AbilityRuntime_ModObjDispatcher_MapRelease(OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)](#oh_abilityruntime_modobjdispatcher_maprelease) | Releases the map instance. After release, the handle is set to NULL. If ppMap or *ppMap is NULL, no operation is performed. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructCreate(const char* structName, OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)](#oh_abilityruntime_modobjdispatcher_structcreate) | Creates a struct instance based on the struct name in the type library metadata. structName must be consistent with the struct name defined in the type library. Available struct names can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetStructName](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructname). |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetName(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_modobjdispatcher_structgetname) | Obtains the type name of the struct. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructSetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_structsetfield) | Sets the value of the specified field in the struct. The function performs a deep copy, and the caller retains ownership of the original variant. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_structgetfield) | Obtains the value of the specified field in the struct. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| [void OH_AbilityRuntime_ModObjDispatcher_StructRelease(OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)](#oh_abilityruntime_modobjdispatcher_structrelease) | Releases the struct instance. After release, the handle is set to NULL. If ppStruct or *ppStruct is NULL, no operation is performed. |

## Enum Description

### OH_AbilityRuntime_ModObjDispatcher_ValueType

```c
enum OH_AbilityRuntime_ModObjDispatcher_ValueType
```

**Description**

Defines the variant type enum, which is used to identify the data type of a variant value.

A variant is a general-purpose data container that can store values of multiple different types, similar to a union in the C language. Each variant holds a value of only one type at a time, and this enum identifies the data type actually stored.

In this module, variants are used for passing parameters and receiving return values in method calls, so that the same set of interfaces can handle multiple data types such as boolean, integer, floating-point number, string, array, vector, set, map, struct, and remote communication object.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_EMPTY = 0 | Empty value. Indicates an uninitialized or invalid variant value. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_VOID = 1 | Void type. Used when a method returns no value. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_BOOL = 2 | Boolean value. The value is true or false, where true indicates true and false indicates false. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I8 = 3 | 8-bit signed integer. Value range: [-128, 127]. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I16 = 4 | 16-bit signed integer. Value range: [-32768, 32767]. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I32 = 5 | 32-bit signed integer. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I64 = 6 | 64-bit signed integer. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U8 = 7 | 8-bit unsigned integer. Value range: [0, 255]. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U16 = 8 | 16-bit unsigned integer. Value range: [0, 65535]. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U32 = 9 | 32-bit unsigned integer. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U64 = 10 | 64-bit unsigned integer. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_F32 = 11 | 32-bit floating-point number (single precision). |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_F64 = 12 | 64-bit floating-point number (double precision). |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_STRING = 13 | UTF-8 string. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_ARRAY = 14 | Array. A fixed-size ordered collection of elements, all of the same type, supporting setting and obtaining elements by index and querying the array size. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_VECTOR = 15 | Vector. A dynamic-size ordered collection of elements, all of the same type, supporting adding elements, obtaining elements by index, querying the vector size, and clearing. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_SET = 16 | Set. An unordered set of non-duplicate elements, all of the same type, supporting adding elements, deleting elements, querying whether a specified element exists, obtaining elements by index, querying the set size, and clearing. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_MAP = 17 | Map. An ordered collection of key-value pairs, with the key and value types specified at creation, supporting adding or updating key-value pairs, obtaining values by key, deleting key-value pairs, querying whether a specified key exists, obtaining keys or values by index, querying the map size, and clearing. Keys support only primitive types (BOOL, signed integer, unsigned integer, floating-point number, STRING, ENUM), and do not support container types or complex types. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_STRUCT = 18 | Struct. A collection of named fields, with field types defined through type library metadata. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_IPC_REMOTE_PROXY = 19 | Remote Proxy object used for cross-process communication. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_IPC_REMOTE_STUB = 20 | Remote Stub object used for cross-process communication. |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_ENUM = 21 | Enum value. Stored as int32_t, and the enum definition can be queried through the type descriptor. |

## Function Description

### OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear()

```c
void OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pTypeInfo)
```

**Description**

Clears the heap resources held by a TypeInfo struct.

Recursively releases the heap resources held by the TypeInfo. After the cleanup, all internal pointers are set to NULL, and vt is reset to VT_EMPTY. However, the TypeInfo struct itself is not released (it is usually allocated on the stack by the caller).

Heap resources held by each type:  

- Map (MAP) type: recursively releases and deletes the child TypeInfo node allocated by new (u.mapType.pValueType).  

- Array (ARRAY) type: recursively releases and deletes the child TypeInfo node allocated by new (u.arrayType.pElementType).  

- Vector (VECTOR) or set (SET) type: recursively releases and deletes the child TypeInfo node allocated by new (u.pElementType).  

- Struct (STRUCT), enum (ENUM), and remote communication object (IPC_REMOTE_PROXY, IPC_REMOTE_STUB) types: releases the u.idlType string (allocated by strdup).

Release rules:

- When TypeInfo is returned from a function (such as [OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodreturntype), [OH_AbilityRuntime_TypeDescriptor_GetMethodParamType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamtype), [OH_AbilityRuntime_TypeDescriptor_GetStructFieldType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructfieldtype), [OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arraygetelementtype), [OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorgetelementtype), [OH_AbilityRuntime_ModObjDispatcher_SetGetElementType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setgetelementtype), [OH_AbilityRuntime_ModObjDispatcher_MapGetValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapgetvaluetype)), the function performs a deep copy, and the caller obtains ownership of the returned TypeInfo and must call this API to release the resource.

- When TypeInfo is passed into a function (such as [OH_AbilityRuntime_ModObjDispatcher_ArrayCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arraycreate), [OH_AbilityRuntime_ModObjDispatcher_VectorCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorcreate), [OH_AbilityRuntime_ModObjDispatcher_SetCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setcreate), or [OH_AbilityRuntime_ModObjDispatcher_MapCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapcreate)), the function performs a deep copy. The caller retains ownership of the original TypeInfo and must call this API to release the resources held by the original TypeInfo.

- Primitive types (boolean, integer, floating-point number, null, etc.) do not hold heap resources and do not require calling this API to release them.

- Do not call this API on a shallow copy of TypeInfo. If TypeInfo t2 = t1 is performed, call this API on only one of the original instance and the copied instance.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pTypeInfo | Pointer to the TypeInfo to be cleared. |

### OH_AbilityRuntime_ModObjDispatcher_VariantClear()

```c
void OH_AbilityRuntime_ModObjDispatcher_VariantClear(OH_AbilityRuntime_ModObjDispatcher_Variant* pVariant)
```

**Description**

Clears the resources held by a variant.

Releases the resources held by the variant (strings, container handles, and so on). After the cleanup, the variant is reset to VT_EMPTY and all fields are zeroed.

Release rules:

- When a variant is passed into a function (such as [OH_AbilityRuntime_ModObjDispatcher_ArraySet](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arrayset) and [OH_AbilityRuntime_ModObjDispatcher_MapPut](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapput)), the function performs a deep copy. The caller retains ownership of the original variant and must release the resources held by the original variant (for example, call free(bstrVal) for a string and call the corresponding Release API for a container handle).

- When a variant is returned from a function (for example, [OH_AbilityRuntime_ModObjDispatcher_ArrayGet](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arrayget), [OH_AbilityRuntime_ModObjDispatcher_MapGet](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapget), or [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)), the function performs a deep copy. The caller obtains the ownership of the returned variant and must call this API to release the resources.  

- Primitive types (boolean, integer, floating-point number, and so on) do not hold heap resources, so there is no need to call this API to release them.  

- Do not call this API on a shallow copy of a variant. If `Variant v2 = v1` is executed, only one of them can be cleared.  

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pVariant | Pointer to the variant to be cleared. |

### OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance(OHIPCRemoteProxy* remoteProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)
```

**Description**

Creates a ModularObject dispatcher instance for the main service interface from a remote Proxy object.

The type library metadata is lazily loaded from the remote service when first needed (for example, when [OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor), [OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_hastypedescriptor), [OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames), or [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod) is called).

The caller must call [OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release) to release the dispatcher instance when it is no longer needed, to avoid memory leaks.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OHIPCRemoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md)* remoteProxy | Handle to the remote Proxy object, obtained by connecting to the ModularObjectExtensionAbility. |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md)* ppModObjDispatcher | Pointer to the pointer that receives the ModularObject dispatcher handle. It cannot be NULL, and *ppModObjDispatcher must be NULL. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>Returns [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) if the API is called successfully.<br>Returns [ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) if remoteProxy or ppModObjDispatcher is NULL, or *ppModObjDispatcher is not NULL.<br>Returns [ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) if an internal error occurs, for example, memory allocation failure. Check whether the system memory is sufficient, and release resources and retry if necessary. |

### OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance(OH_AbilityRuntime_ModObjDispatcherHandle mainServiceDispatcher, OHIPCRemoteProxy* subProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)
```

**Description**

Creates a sub-instance dispatcher bound to the main service dispatcher.

The sub-instance shares the type library metadata of the main service dispatcher, but uses an independent IPC proxy to send requests. It is suitable for scenarios where non-main-service interfaces in the same type library need to be called.

When [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod) is called on the sub-instance, the method signature is resolved from the type library metadata of the main service dispatcher, and the IPC request is sent to the remote service through subProxy.

The caller must call [OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release) to release the sub-instance when it is no longer used, to avoid memory leaks.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) mainServiceDispatcher | Handle of the main service dispatcher. |
| [OHIPCRemoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md)* subProxy | Handle of the remote Proxy object of the non-main service interface. |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md)* ppModObjDispatcher | Pointer to the handle that receives the created sub-instance dispatcher. It cannot be NULL, and *ppModObjDispatcher must be NULL. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) mainServiceDispatcher, subProxy, or ppModObjDispatcher is NULL, or *ppModObjDispatcher is not NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error, for example, memory allocation failure. Check whether the system memory is sufficient, and release resources and retry if necessary. |

### OH_AbilityRuntime_ModObjDispatcher_Release()

```c
void OH_AbilityRuntime_ModObjDispatcher_Release(OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)
```

**Description**

Releases a ModularObject dispatcher instance. After the release, the pointer is set to NULL. If ppModObjDispatcher or *ppModObjDispatcher is NULL, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md)* ppModObjDispatcher | Pointer to the ModularObject dispatcher handle to release. After the release, this pointer is set to NULL. |

### OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t* pctinfo)
```

**Description**

Checks whether the remote service supports type library metadata. Calling this API triggers lazy loading of the type library metadata. If the metadata is loaded successfully, *pctinfo is 1; otherwise, it is 0.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) pModObjDispatcher | ModularObject dispatcher handle. |
| uint32_t* pctinfo | Pointer to the status indicating whether type library metadata is supported. 1 indicates supported, and 0 indicates not supported. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pModObjDispatcher or pctinfo is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Failed to send the IPC request. Check whether the remote service is running properly.<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The type library metadata is invalid. Check whether the type library definition of the remote service is correct.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. Check the system status and release resources if necessary before retrying. |

### OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* ppTypeDescriptor)
```

**Description**

Obtains a type descriptor handle for querying interface metadata.

The type descriptor provides access to the type library metadata of a remote service, including the definition information of interfaces, methods, enums, and structs. Calling this API triggers lazy loading of the type library metadata.

After use, call [OH_AbilityRuntime_TypeDescriptor_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_release) to release the handle.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) pModObjDispatcher | ModularObject dispatcher handle. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md)* ppTypeDescriptor | Pointer to the pointer that receives the type descriptor handle. It cannot be NULL, and *ppTypeDescriptor must be NULL. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_NO_ERROR if the API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID if pModObjDispatcher or ppTypeDescriptor is NULL, or *ppTypeDescriptor is not NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED if the IPC request fails to be sent. Check whether the remote service is running properly.<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID if the type library metadata is invalid. Check whether the type library definition of the remote service is correct.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_INTERNAL if an internal error occurs. Check the system status, and release resources and retry if necessary. |

### OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, const char** rgszNames, uint32_t cNames, uint32_t* pMemID)
```

**Description**

Queries the member IDs (MemberID) of the methods in the main service interface by method name. The returned member IDs can be used as the memID parameter of [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod). Calling this API triggers lazy loading of the type library metadata.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) pModObjDispatcher | Handle to the ModularObject dispatcher. |
| const char** rgszNames | Array of method names. |
| uint32_t cNames | Number of method names. |
| uint32_t* pMemID | Pointer to the array that receives the member IDs. The array length is the same as cNames, and each name corresponds to one member ID. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pModObjDispatcher, rgszNames, or pMemID is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Failed to send the IPC request. Check whether the remote service is running properly.<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The type library metadata is invalid. Check whether the type library definition of the remote service is correct.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The method name is not found. Check whether the method name is consistent with the definition in the type library.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. Check the system status and release resources if necessary before retrying. |

### OH_AbilityRuntime_ModObjDispatcher_CallMethod()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CallMethod(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t memID, OH_AbilityRuntime_ModObjDispatcher_InputParams* pInputParams, OH_AbilityRuntime_ModObjDispatcher_Variant* pResult, int32_t* pMethodErrCode)
```

**Description**

Calls a remote method by member ID (MemberID).

Calling process: obtains the method metadata (method name, parameter types, return type, IPC code, and so on) from the metadata manager by memID, serializes the parameters into a MessageParcel, sends the request to the remote service through IPC, and finally deserializes the return result.

This API uses a two-layer error handling mechanism:

- Framework-level errors: issues at the framework layer, such as IPC communication, metadata loading, and parameter validation, are returned through the method return value.  

- Method-level error: the business error returned by the remote method execution, returned through the pMethodErrCode output parameter.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modobjdispatcher8h.md) pModObjDispatcher | ModularObject dispatcher handle. |
| uint32_t memID | Method member ID (MemberID), which can be obtained through [OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames) or [OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodmemberid). |
| [OH_AbilityRuntime_ModObjDispatcher_InputParams](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md)* pInputParams | Pointer to the struct that contains the call parameters. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pResult | Pointer to the variant that receives the returned result. The returned variant is a deep copy, and the caller must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it. |
| int32_t* pMethodErrCode | Pointer to the method-level error code. 0 indicates that the method is executed successfully, and a non-zero value indicates that the method returns an error. This error code is independent of the framework-level return value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pModObjDispatcher, pInputParams, or pResult is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The method is not found. Check whether memID is correct.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The parameter type does not match the metadata definition. Check whether the input parameter type is consistent with the method definition.<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Failed to send the IPC request. Check whether the remote service is running properly.<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The type library metadata is invalid. Check whether the type library definition of the remote service is correct.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. Check the system status and retry after releasing resources if necessary. |

### OH_AbilityRuntime_TypeDescriptor_Release()

```c
void OH_AbilityRuntime_TypeDescriptor_Release(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* pTypeDescriptor)
```

**Description**

Releases a type descriptor instance. After the release, the handle is set to NULL. If pTypeDescriptor or *pTypeDescriptor is NULL, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md)* pTypeDescriptor | Pointer to the type descriptor handle to release. After the release, this pointer is set to NULL. |

**Reference**

[OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor)

### OH_AbilityRuntime_TypeDescriptor_GetVersion()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetVersion(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrVersion, uint32_t cMaxVersion)
```

**Description**

Obtains the version number of the type library.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| char* pbstrVersion | Pointer to the buffer that receives the version string. |
| uint32_t cMaxVersion | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor or pbstrVersion is NULL, or cMaxVersion is 0.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcInterfaces)
```

**Description**

Obtains the total number of interfaces defined in the type library. The returned count can be used to determine the upper index limit when traversing the interfaces.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| uint32_t* pcInterfaces | Pointer to the variable that receives the total number of interfaces. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor or pcInterfaces is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetInterfaceName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**Description**

Obtains the interface name by index. The valid range of the interface index is [0, interfaceCount - 1], where interfaceCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getinterfacecount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| uint32_t index | Interface index. |
| char* pbstrName | Pointer to the buffer that receives the interface name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor or pbstrName is NULL, or cMaxName is 0, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetInterfaceIsCallback()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceIsCallback(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrName, bool* pIsCallback)
```

**Description**

Checks whether a specified interface is a callback type. A callback interface indicates that the interface needs to be implemented by the client and provided to the server for invocation.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrName | Interface name. |
| bool* pIsCallback | Pointer to the callback flag. The value **true** indicates that it is a callback interface, and **false** indicates that it is not. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the API call is successful.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pTypeDescriptor, pbstrName, or pIsCallback is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the interface is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if an internal error occurs. |

### OH_AbilityRuntime_TypeDescriptor_GetMainServiceInterfaceName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMainServiceInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrName, uint32_t cMaxName)
```

**Description**

Obtains the name of the main service interface.

The main service interface is the default interface exposed by the remote ModularObjectExtensionAbility, that is, the interface corresponding to the Proxy object bound when the dispatcher is created through [OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createmainserviceinstance).

This interface is declared by the remote service in the type library metadata, and its name can be obtained through this API.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| char* pbstrName | Pointer to the buffer that receives the name of the main service interface. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_NO_ERROR if the API call is successful.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID if pTypeDescriptor or pbstrName is NULL, or cMaxName is 0.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns ABILITY_RUNTIME_ERROR_CODE_INTERNAL if an internal error occurs. |

### OH_AbilityRuntime_TypeDescriptor_GetMethodCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t* pcMethods)
```

**Description**

Obtains the total number of methods defined in a specified interface.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrInterfaceName | Interface name. |
| uint32_t* pcMethods | Pointer to the variable that receives the total number of methods. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pTypeDescriptor, pbstrInterfaceName, or pcMethods is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the interface is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if an internal error occurs. |

### OH_AbilityRuntime_TypeDescriptor_GetMethodName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**Description**

Obtains the method name in an interface by index. The valid range of the method index is [0, methodCount - 1], where methodCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetMethodCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodcount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrInterfaceName | Interface name. |
| uint32_t index | Method index. |
| char* pbstrName | Pointer to the buffer that receives the method name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrInterfaceName, or pbstrName is NULL, or cMaxName is 0, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The interface is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pMemID)
```

**Description**

Obtains the member ID of a method by the method name. The returned member ID can be used as the memID parameter of [OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrInterfaceName | Interface name. |
| const char* pbstrMethodName | Method name. |
| uint32_t* pMemID | Pointer to the variable that receives the method member ID. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrInterfaceName, pbstrMethodName, or pMemID is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The interface or method is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pReturnType)
```

**Description**

Obtains the return type of a method.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrInterfaceName | Interface name. |
| const char* pbstrMethodName | Method name. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pReturnType | Pointer to the TypeInfo that receives the return type. Call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release it after use. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrInterfaceName, pbstrMethodName, or pReturnType is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The interface or method is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pcParams)
```

**Description**

Obtains the number of parameters of a method.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrInterfaceName | Interface name. |
| const char* pbstrMethodName | Method name. |
| uint32_t* pcParams | Pointer to the parameter that receives the number of parameters. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The interface call succeeds.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrInterfaceName, pbstrMethodName, or pcParams is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The interface or method is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetMethodParamType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pParamType)
```

**Description**

Obtains the type of a method parameter by index. The valid range of the parameter index is [0, paramCount - 1], where paramCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrInterfaceName | Interface name. |
| const char* pbstrMethodName | Method name. |
| uint32_t iParamIndex | Parameter index. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pParamType | Pointer to the TypeInfo that receives the parameter type. After use, call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release it. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrInterfaceName, pbstrMethodName, or pParamType is NULL, or iParamIndex is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The interface or method is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetMethodParamName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, char* pbstrName, uint32_t cMaxName)
```

**Description**

Obtains the name of a method parameter by index. The valid range of the parameter index is [0, paramCount - 1], where paramCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrInterfaceName | Interface name. |
| const char* pbstrMethodName | Method name. |
| uint32_t iParamIndex | Parameter index. |
| char* pbstrName | Pointer to the buffer that receives the parameter name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrInterfaceName, pbstrMethodName, or pbstrName is NULL, or iParamIndex is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The interface or method is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetEnumCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcEnums)
```

**Description**

Obtains the total number of enums defined in the type library.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| uint32_t* pcEnums | Pointer to the variable that receives the total number of enums. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pTypeDescriptor or pcEnums is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if an internal error occurs. |

### OH_AbilityRuntime_TypeDescriptor_GetEnumName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**Description**

Obtains the enum name by index. The valid range of the enum index is [0, enumCount - 1], where enumCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetEnumCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumcount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| uint32_t index | Enum index. |
| char* pbstrName | Pointer to the buffer that receives the enum name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor or pbstrName is NULL, or cMaxName is 0, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t* pcValues)
```

**Description**

Obtains the number of enum values defined in a specified enum.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrEnumName | Enum name. |
| uint32_t* pcValues | Pointer to the variable that receives the number of enum values. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrEnumName, or pcValues is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The enum is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetEnumValueName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t iValueIndex, char* pbstrValueName, uint32_t cMaxName)
```

**Description**

Obtains the name of an enum value by index. The valid range of the enum value index is [0, valueCount - 1], where valueCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumvaluecount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrEnumName | Enum name. |
| uint32_t iValueIndex | Enum value index. |
| char* pbstrValueName | Pointer to the buffer that receives the enum value name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrEnumName, or pbstrValueName is NULL, or iValueIndex is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The enum is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetEnumValue()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValue(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, const char* pbstrValueName, int32_t* pValue)
```

**Description**

Obtains an enum value by its name.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrEnumName | Enum name. |
| const char* pbstrValueName | Enum value name. |
| int32_t* pValue | Pointer to the variable that receives the enum value. The enum value is returned as int32_t. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrEnumName, pbstrValueName, or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The enum value is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetStructCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcStructs)
```

**Description**

Obtains the total number of structs defined in the type library.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| uint32_t* pcStructs | Pointer to the variable that receives the total number of structs. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor or pcStructs is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetStructName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**Description**

Obtains the struct name by index. The valid range of the struct index is [0, structCount - 1], where structCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetStructCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructcount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| uint32_t index | Struct index. |
| char* pbstrName | Pointer to the buffer that receives the struct name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor or pbstrName is NULL, or cMaxName is 0, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t* pcFields)
```

**Description**

Obtains the number of fields defined in a specified struct.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrStructName | Struct name. |
| uint32_t* pcFields | Pointer to the variable that receives the number of fields. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrStructName, or pcFields is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The struct is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetStructFieldName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t iFieldIndex, char* pbstrFieldName, uint32_t cMaxName)
```

**Description**

Obtains the name of a struct field by index. The valid range of the struct field index is [0, fieldCount - 1], where fieldCount can be obtained through [OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructfieldcount).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrStructName | Struct name. |
| uint32_t iFieldIndex | Struct field index. |
| char* pbstrFieldName | Pointer to the buffer that receives the field name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrStructName, or pbstrFieldName is NULL, or iFieldIndex is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The struct is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_TypeDescriptor_GetStructFieldType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, const char* pbstrFieldName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pFieldType)
```

**Description**

Obtains the type of a struct field by field name.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | Type descriptor handle. |
| const char* pbstrStructName | Struct name. |
| const char* pbstrFieldName | Field name. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pFieldType | Pointer to the TypeInfo that receives the field type. Call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release it after use. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor, pbstrStructName, pbstrFieldName, or pFieldType is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The struct or field is not found.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_ArrayCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, uint32_t size, OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)
```

**Description**

Creates an array instance with the specified element type and size. The array has a fixed size and its length cannot be changed after creation.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* elementType | Pointer to the element type descriptor. The function performs a deep copy. The caller retains ownership of the original TypeInfo and must call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release the heap resources held by the TypeInfo. |
| uint32_t size | Initial size of the array. |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md)* ppArray | Pointer to the pointer that receives the array handle. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) elementType or ppArray is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)
```

**Description**

Obtains the element type of an array.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | Array handle. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType | Pointer to the TypeInfo that receives the element type. After use, call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release it. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pArray or pElementType is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_ArraySet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArraySet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Sets the element value at the specified index in the array. The function performs a deep copy, and the caller retains ownership of the original variant.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | Array handle. |
| uint32_t index | Element index, ranging from [0, size - 1]. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the element value variant. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pArray or pValue is NULL, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the element type does not match the type defined by the array.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if an internal error occurs. |

### OH_AbilityRuntime_ModObjDispatcher_ArrayGet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Obtains the element value at the specified index in the array. The returned variant is a deep copy, and the caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | Array handle. |
| uint32_t index | Element index, ranging from 0 to size - 1. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant that receives the element value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pArray or pValue is NULL, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if an internal error occurs. |

### OH_AbilityRuntime_ModObjDispatcher_ArrayGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetSize(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t* pSize)
```

**Description**

Obtains the size of an array.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | Array handle. |
| uint32_t* pSize | Pointer to the size of the array. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pArray or pSize is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_ArrayRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_ArrayRelease(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)
```

**Description**

Releases an array instance. After the release, the handle is set to NULL. If ppArray or *ppArray is NULL, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md)* ppArray | Pointer to the array handle to release. After the release, this pointer is set to NULL. |

### OH_AbilityRuntime_ModObjDispatcher_VectorCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)
```

**Description**

Creates a vector instance of the specified element type. A vector is an ordered collection of dynamic size, in which all elements are of the same type. It supports adding elements, obtaining elements by index, querying the size, and clearing.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* elementType | Pointer to the element type descriptor. The function performs a deep copy. The caller retains ownership of the original TypeInfo and must call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release the heap resources held by the TypeInfo. |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md)* ppVector | Pointer to the vector handle to receive. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) elementType or ppVector is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)
```

**Description**

Obtains the element type of the vector.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | Vector handle. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType | Pointer to the TypeInfo that receives the element type. Call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release it after use. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector or pElementType is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_VectorAdd()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorAdd(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Adds an element to the end of a vector. The function performs a deep copy, and the caller retains ownership of the original variant.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | Vector handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant of the element value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns success if the API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pVector or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the element type does not match the type defined by the vector.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if an internal error occurs. |

### OH_AbilityRuntime_ModObjDispatcher_VectorGet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGet(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Obtains the element value at the specified index in a vector. The returned variant is a deep copy, and the caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | Vector handle. |
| uint32_t index | Element index, ranging from 0 to size - 1. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant that receives the element value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector or pValue is NULL, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_VectorGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetSize(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t* pSize)
```

**Description**

Obtains the number of elements in the vector.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | Vector handle. |
| uint32_t* pSize | Pointer to the variable that receives the number of elements. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector or pSize is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_VectorClear()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorClear(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector)
```

**Description**

Clears all elements in the vector.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | Vector handle. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_VectorRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_VectorRelease(OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)
```

**Description**

Releases a vector instance. After the release, the handle is set to NULL. If ppVector or *ppVector is NULL, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md)* ppVector | Pointer to the vector handle to release. After the release, this pointer is set to NULL. |

### OH_AbilityRuntime_ModObjDispatcher_SetCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)
```

**Description**

Creates a set instance with the specified element type. A set is an unordered set of non-duplicate elements. All elements are of the same type. It supports adding, deleting, and querying whether a specified element exists, obtaining an element by index, and clearing.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* elementType | Pointer to the element type descriptor. The function performs a deep copy. The caller retains the ownership of the original TypeInfo and must call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release the heap resources held by TypeInfo. |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md)* ppSet | Pointer to the pointer that receives the set handle. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) elementType or ppSet is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_SetGetElementType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetElementType(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)
```

**Description**

Obtains the element type of the set.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | Set handle. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType | Pointer to the TypeInfo that receives the element type. After use, call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release it. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet or pElementType is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_SetAdd()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetAdd(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Adds an element to a set. If the element already exists, it will not be added again. The function performs a deep copy, and the caller retains ownership of the original variant.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | Set handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant of the element value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The element type does not match the type defined by the set.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_SetRemove()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetRemove(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Removes a specified element from a set. If the element does not exist, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | Set handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant of the element value to remove. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The element type does not match the type defined by the set.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_SetContains()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetContains(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue, bool* pExists)
```

**Description**

Checks whether a specified element exists in the set.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | Set handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant of the element value to be found. |
| bool* pExists | Pointer to the parameter indicating whether the element exists. The value **true** indicates that the element exists, and **false** indicates that it does not. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet, pValue, or pExists is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The element type does not match the type defined by the set. |

### OH_AbilityRuntime_ModObjDispatcher_SetGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetSize(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t* pSize)
```

**Description**

Obtains the number of elements in the set.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | Set handle. |
| uint32_t* pSize | Pointer to the variable that receives the number of elements. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet or pSize is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_SetGetAt()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetAt(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Obtains the element value at the specified index in the set. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | Set handle. |
| uint32_t index | Element index, ranging from 0 to size - 1. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant that receives the element value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet or pValue is NULL, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_SetClear()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetClear(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet)
```

**Description**

Clears all elements in the set.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | Set handle. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_SetRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_SetRelease(OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)
```

**Description**

Releases a set instance. After the release, the handle is set to NULL. If ppSet or *ppSet is NULL, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md)* ppSet | Pointer to the set handle to release. After the release, this pointer is set to NULL. |

### OH_AbilityRuntime_ModObjDispatcher_MapCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapCreate(OH_AbilityRuntime_ModObjDispatcher_ValueType keyType, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* valueType, OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)
```

**Description**

Creates a map instance with the specified key type and value type. The key supports only primitive types (BOOL, signed integer, unsigned integer, floating point, STRING, and ENUM), and does not support container types (ARRAY, VECTOR, SET, and MAP) or complex types (STRUCT, IPC_REMOTE_PROXY, and IPC_REMOTE_STUB).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) keyType | Key type. Only primitive types (BOOL, signed integer, unsigned integer, floating point, STRING, and ENUM) are supported. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* valueType | Pointer to the value type descriptor. There is no special restriction on the value type. The function performs a deep copy. The caller retains ownership of the original TypeInfo and must call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release the heap resources held by TypeInfo. |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md)* ppMap | Pointer to the location that receives the map handle. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) valueType or ppMap is NULL, or keyType is an unsupported type.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_MapGetKeyType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_ValueType* pKeyType)
```

**Description**

Obtains the key type of a map.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype)* pKeyType | Pointer to the location that receives the key type. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap or pKeyType is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_MapGetValueType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pValueType)
```

**Description**

Obtains the value type of the map.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pValueType | Pointer to the TypeInfo that receives the value type. After use, call [OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear) to release it. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap or pValueType is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_MapPut()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapPut(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Adds or updates a key-value pair in a map. If the key already exists, the corresponding value is updated. The function performs a deep copy, and the caller retains ownership of the original variants.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | Pointer to the key variant. The key type must be consistent with the type specified when the map is created. Only primitive types (BOOL, signed integer, unsigned integer, floating point, STRING, ENUM) are supported. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the value variant. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap, pKey, or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The type of the key or value does not match the type defined for the map. Check whether the key and value types are consistent with the types specified when the map is created.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. Check the system status and release resources if necessary before retrying. |

### OH_AbilityRuntime_ModObjDispatcher_MapGet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGet(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Obtains the value corresponding to a key in the map. The returned variant is a deep copy, and the caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | Pointer to the key variant. The key type must be consistent with the type specified when the map is created. Only primitive types (BOOL, signed integer, unsigned integer, floating point, STRING, ENUM) are supported. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant that receives the value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap, pKey, or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The type of the key or value does not match the type defined for the map. Check whether the key and value types are consistent with the types specified when the map is created.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The key does not exist in the map. Check whether the key is correct.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. Check the system status and release resources if necessary before retrying. |

### OH_AbilityRuntime_ModObjDispatcher_MapRemove()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapRemove(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)
```

**Description**

Removes a key-value pair from the map by key. If the key does not exist, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | Pointer to the key variant. The key type must be consistent with the type specified when the map is created. Only primitive types (BOOL, signed integer, unsigned integer, floating-point number, STRING, ENUM) are supported. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap or pKey is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The type of the key or value does not match the type defined for the map.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_MapContainsKey()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapContainsKey(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, bool* pExists)
```

**Description**

Checks whether the specified key exists in the map.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | Pointer to the key variant. The key type must be consistent with the type specified when the map is created. Only primitive types (BOOL, signed integer, unsigned integer, floating point, STRING, and ENUM) are supported. |
| bool* pExists | Pointer to the flag that receives the existence status. The value **true** indicates that the key exists, and **false** indicates that it does not. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap, pKey, or pExists is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The type of the key or value does not match the type defined for the map. |

### OH_AbilityRuntime_ModObjDispatcher_MapGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetSize(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t* pSize)
```

**Description**

Obtains the number of key-value pairs in the map.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| uint32_t* pSize | Pointer to the number of key-value pairs. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap or pSize is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_MapGetKeyAt()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)
```

**Description**

Obtains the key in a map by index. The returned variant is a deep copy, and the caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| uint32_t index | Index of the key-value pair, in the range [0, size - 1]. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | Pointer to the variant that receives the key. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap or pKey is NULL, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_MapGetValueAt()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Obtains the value in the map by index. The returned variant is a deep copy. The caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |
| uint32_t index | Index of the key-value pair, ranging from [0, size - 1]. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant that receives the value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap or pValue is NULL, or index is out of range.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_MapClear()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapClear(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap)
```

**Description**

Clears all key-value pairs in the map.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | Map handle. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap is NULL. |

### OH_AbilityRuntime_ModObjDispatcher_MapRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_MapRelease(OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)
```

**Description**

Releases a map instance. After the release, the handle is set to NULL. If ppMap or *ppMap is NULL, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md)* ppMap | Pointer to the map handle to release. After the release, this pointer is set to NULL. |

### OH_AbilityRuntime_ModObjDispatcher_StructCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructCreate(const char* structName, OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)
```

**Description**

Creates a struct instance based on the struct name in the type library metadata. The value of structName must be consistent with the struct name defined in the type library. You can obtain the available struct names through [OH_AbilityRuntime_TypeDescriptor_GetStructName](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructname).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| const char* structName | Struct name, which comes from the type library metadata. |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md)* ppStruct | Pointer to the struct handle to receive. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) structName or ppStruct is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) structName does not exist in the struct names defined in the type library.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_StructGetName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetName(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, char* pbstrName, uint32_t cMaxName)
```

**Description**

Obtains the type name of a struct.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pStruct | Struct handle. |
| char* pbstrName | Pointer to the buffer that receives the struct name. |
| uint32_t cMaxName | Buffer size in bytes, including the null terminator. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if the API call is successful.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if pStruct or pbstrName is NULL, or cMaxName is 0.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Returns this code if an internal error occurs. |

### OH_AbilityRuntime_ModObjDispatcher_StructSetField()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructSetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Sets the value of a specified field in a struct. The function performs a deep copy, and the caller retains ownership of the original variant.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pStruct | Struct handle. |
| const char* szName | Field name. |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant of the field value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pStruct, szName, or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The field does not exist in the struct.<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The field type does not match the type defined in the metadata.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_StructGetField()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**Description**

Obtains the value of a specified field in a struct. The returned variant is a deep copy, and the caller owns the returned variant and must call [OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear) to release it.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pStruct | Struct handle. |
| const char* szName | Field name. |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | Pointer to the variant that receives the field value. |

**Returns**

| Type | Description |
| -- | -- |
| AbilityRuntime_ErrorCode | Result code.<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The API is called successfully.<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pStruct, szName, or pValue is NULL.<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) The field does not exist in the struct.<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) Internal error. |

### OH_AbilityRuntime_ModObjDispatcher_StructRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_StructRelease(OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)
```

**Description**

Releases a struct instance. After the release, the handle is set to NULL. If ppStruct or *ppStruct is NULL, no operation is performed.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md)* ppStruct | Pointer to the struct handle to release. After the release, this pointer is set to NULL. |