# modular_object_dispatcher.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

声明ModularObject分发器接口，提供基于类型库元数据的跨进程延迟绑定调用能力。

开发者可以通过本模块从远端Proxy对象创建主服务或子实例分发器，查询远端服务的类型库元数据（接口/方法/枚举/结构体），并通过成员ID（MemberID）动态调用远端方法，创建与操作容器类型（Array/Vector/Set/Map）和结构体。

**引用文件：** <AbilityKit/ability_runtime/modular_object_dispatcher.h>

**库：** libability_runtime.so

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 26.0.0

**相关模块：** [AbilityRuntime](capi-abilityruntime.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md) | OH_AbilityRuntime_ModObjDispatcher_TypeInfo | 定义参数或返回值的类型信息。<br>使用带标签的联合体[u](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md#成员变量)描述类型信息，通过[vt](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md#成员变量)字段决定联合体中哪个成员有效。<br>对于映射（MAP）类型，使用u.mapType.keyType描述键类型，u.mapType.pValueType描述值类型；<br>对于数组（ARRAY）类型，使用u.arrayType.pElementType描述元素类型，u.arrayType.size描述数组长度；<br>对于向量（VECTOR）或集合（SET）类型，使用u.pElementType描述元素类型；<br>对于结构体（STRUCT）、远端通信对象（IPC_REMOTE_PROXY、IPC_REMOTE_STUB）、枚举（ENUM）类型，使用u.idlType描述[IDL类型名称](../../application-models/modular-object-extension-ability-taihe.md#ohidl文件编写规范)。<br>使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放内部持有的堆资源。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md) | OH_AbilityRuntime_ModObjDispatcher_Variant | 定义使用联合体加类型标签的变体结构，通过类型标签区分实际数据类型，用于在参数传递和返回值接收中安全传递多种类型的值。<br>变体值由[vt](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md#成员变量)字段决定实际存储的数据类型和联合体中有效的成员。<br>当变体持有堆分配资源（如字符串、容器句柄）时，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [OH_AbilityRuntime_ModObjDispatcher_InputParams](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md) | OH_AbilityRuntime_ModObjDispatcher_InputParams | 定义方法调用的参数结构。[rgvarg](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md#成员变量)指向参数变体数组，数组长度由[cArgs](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md#成员变量)指定。参数顺序应与方法定义中的参数顺序一致。 |
| [OH_AbilityRuntime_ModularObjectDispatcher_TypeDescriptor*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) | OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle | 定义ModularObject分发器的类型描述符句柄。<br>该句柄指向类型库元数据的访问接口，可用于查询远端服务定义的接口、方法、枚举和结构体等信息。<br>可通过[OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor)获取，使用完毕后需通过[OH_AbilityRuntime_TypeDescriptor_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_release)释放。 |
| [OH_AbilityRuntime_ModularObjectDispatcher*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) | OH_AbilityRuntime_ModObjDispatcherHandle | ModularObject分发器的句柄。<br>该句柄指向一个ModularObject分发器实例，可通过[OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createmainserviceinstance)或[OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createsubinstance)创建，使用完毕后需通过[OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release)释放。 |
| [OH_AbilityRuntime_ModularObjectDispatcher_Array*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) | OH_AbilityRuntime_ModObjDispatcher_ArrayHandle | 数组句柄。<br>该句柄指向一个固定大小的有序元素集合，所有元素类型相同，支持按索引设置获取元素和查询数组大小。<br>可通过[OH_AbilityRuntime_ModObjDispatcher_ArrayCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arraycreate)创建，使用完毕后需通过[OH_AbilityRuntime_ModObjDispatcher_ArrayRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arrayrelease)释放。 |
| [OH_AbilityRuntime_ModularObjectDispatcher_Vector*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) | OH_AbilityRuntime_ModObjDispatcher_VectorHandle | 向量句柄。<br>该句柄指向一个动态大小的有序元素集合，所有元素类型相同，支持添加元素、按索引获取元素、查询向量大小和清空操作。<br>可通过[OH_AbilityRuntime_ModObjDispatcher_VectorCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorcreate)创建，使用完毕后需通过[OH_AbilityRuntime_ModObjDispatcher_VectorRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorrelease)释放。 |
| [OH_AbilityRuntime_ModularObjectDispatcher_Set*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) | OH_AbilityRuntime_ModObjDispatcher_SetHandle | 集合句柄。<br>该句柄指向一个不重复元素的无序集合，所有元素类型相同，支持添加元素、删除元素、查询指定元素是否存在、按索引获取元素、查询集合大小和清空操作。<br>可通过[OH_AbilityRuntime_ModObjDispatcher_SetCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setcreate)创建，使用完毕后需通过[OH_AbilityRuntime_ModObjDispatcher_SetRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setrelease)释放。 |
| [OH_AbilityRuntime_ModularObjectDispatcher_Map*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) | OH_AbilityRuntime_ModObjDispatcher_MapHandle | 映射句柄。<br>该句柄指向一个键值对的有序集合，键和值类型在创建时指定，支持添加或更新键值对、按键获取值、删除键值对、查询指定键是否存在、按索引获取键或值、查询映射大小和清空操作。<br>键仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM）。<br>可通过[OH_AbilityRuntime_ModObjDispatcher_MapCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapcreate)创建，使用完毕后需通过[OH_AbilityRuntime_ModObjDispatcher_MapRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_maprelease)释放。 |
| [OH_AbilityRuntime_ModularObjectDispatcher_Struct*](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) | OH_AbilityRuntime_ModObjDispatcher_StructHandle | 结构体句柄。<br>该句柄指向一个具名字段的结构体实例，字段类型通过类型库元数据定义。<br>可通过[OH_AbilityRuntime_ModObjDispatcher_StructCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_structcreate)创建，使用完毕后需通过[OH_AbilityRuntime_ModObjDispatcher_StructRelease](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_structrelease)释放。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) | OH_AbilityRuntime_ModObjDispatcher_ValueType | 定义变体类型枚举，用于标识变体值的数据类型。<br>变体（Variant）是一种能够存储多种不同类型值的通用数据容器，类似于C语言的联合体（union）。每个变体在同一时刻只持有一种类型的值，通过本枚举值标识其实际存储的数据类型。<br>在本模块中，变体用于方法调用的参数传递和返回值接收，使得同一套接口能够处理布尔、整数、浮点数、字符串、数组、向量、集合、映射、结构体、远端通信对象等多种数据类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [void OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pTypeInfo)](#oh_abilityruntime_modobjdispatcher_typeinfoclear) | 清理TypeInfo结构体持有的堆资源。<br>递归释放TypeInfo持有的堆资源。清理后，所有内部指针被置为NULL，vt被重置为VT_EMPTY，但TypeInfo结构体本身不会被释放（通常由调用方在栈上分配）。<br>各类型持有的堆资源：<br>- 映射（MAP）类型：递归释放并删除由new分配的子TypeInfo节点（u.mapType.pValueType）。<br>- 数组（ARRAY）类型：递归释放并删除由new分配的子TypeInfo节点（u.arrayType.pElementType）。<br>- 向量（VECTOR）或集合（SET）类型：递归释放并删除由new分配的子TypeInfo节点（u.pElementType）。<br>- 结构体（STRUCT）、枚举（ENUM）、远端通信对象（IPC_REMOTE_PROXY、IPC_REMOTE_STUB）类型：释放u.idlType字符串（由strdup分配）。 |
| [void OH_AbilityRuntime_ModObjDispatcher_VariantClear(OH_AbilityRuntime_ModObjDispatcher_Variant* pVariant)](#oh_abilityruntime_modobjdispatcher_variantclear) | 清理变体持有的资源。释放变体持有的资源（字符串、容器句柄等），清理后变体被重置为VT_EMPTY，所有字段归零。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance(OHIPCRemoteProxy* remoteProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)](#oh_abilityruntime_modobjdispatcher_createmainserviceinstance) | 从远端Proxy对象为主服务接口创建ModularObject分发器实例。<br>类型库元数据将在首次需要时从远端服务延迟加载（如调用[OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor)、[OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_hastypedescriptor)、[OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames)或[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)时触发）。<br>调用方需在不再使用时调用[OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release)释放分发器实例，避免内存泄漏。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance(OH_AbilityRuntime_ModObjDispatcherHandle mainServiceDispatcher, OHIPCRemoteProxy* subProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)](#oh_abilityruntime_modobjdispatcher_createsubinstance) | 创建绑定到主服务分发器的子实例分发器。<br>子实例共享主服务分发器的类型库元数据，但使用独立的IPC代理发送请求。适用于需要调用同一类型库中非主服务接口的场景。<br>当在子实例上调用[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)时，方法签名从主服务分发器的类型库元数据中解析，IPC请求通过subProxy发送到远端服务。<br>调用方需在不再使用时调用[OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release)释放子实例，避免内存泄漏。 |
| [void OH_AbilityRuntime_ModObjDispatcher_Release(OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)](#oh_abilityruntime_modobjdispatcher_release) | 释放ModularObject分发器实例。释放后指针将被置为NULL。如果ppModObjDispatcher或*ppModObjDispatcher为NULL，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t* pctinfo)](#oh_abilityruntime_modobjdispatcher_hastypedescriptor) | 检查远端服务是否支持类型库元数据。调用此接口将触发类型库元数据的延迟加载。如果元数据加载成功，*pctinfo 为 1；否则为 0。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* ppTypeDescriptor)](#oh_abilityruntime_modobjdispatcher_gettypedescriptor) | 获取类型描述符句柄，用于查询接口元数据信息。<br>类型描述符提供对远端服务类型库元数据的访问能力，包括接口、方法、枚举和结构体的定义信息。调用此接口将触发类型库元数据的延迟加载。<br>使用完毕后需调用[OH_AbilityRuntime_TypeDescriptor_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_release)释放句柄。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, const char** rgszNames, uint32_t cNames, uint32_t* pMemID)](#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames) | 根据方法名称查询主服务接口中对应的方法成员ID（MemberID）。返回的成员ID可作为[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)的memID参数使用。调用此接口将触发类型库元数据的延迟加载。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CallMethod(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t memID, OH_AbilityRuntime_ModObjDispatcher_InputParams* pInputParams, OH_AbilityRuntime_ModObjDispatcher_Variant* pResult, int32_t* pMethodErrCode)](#oh_abilityruntime_modobjdispatcher_callmethod) | 通过成员ID（MemberID）调用远端方法。<br>调用流程：通过memID从元数据管理器获取方法元数据（方法名、参数类型、返回类型、IPC码等），将参数序列化到MessageParcel，通过IPC发送请求到远端服务，最后反序列化返回结果。<br>本接口采用双层错误处理机制：<br>- 框架级错误：IPC通信、元数据加载、参数验证等框架层面的问题，通过方法返回值返回。<br>- 方法级错误：远端方法执行返回的业务错误，通过pMethodErrCode输出参数返回。 |
| [void OH_AbilityRuntime_TypeDescriptor_Release(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* pTypeDescriptor)](#oh_abilityruntime_typedescriptor_release) | 释放类型描述符实例。释放后句柄将被置为NULL。如果pTypeDescriptor或*pTypeDescriptor为NULL，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetVersion(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrVersion, uint32_t cMaxVersion)](#oh_abilityruntime_typedescriptor_getversion) | 获取类型库版本号。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcInterfaces)](#oh_abilityruntime_typedescriptor_getinterfacecount) | 获取类型库中定义的接口总数。返回的数量可用于确定遍历接口时的索引上限。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getinterfacename) | 根据索引获取接口名称。接口索引的有效范围为[0, interfaceCount - 1]，其中interfaceCount可通过[OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getinterfacecount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceIsCallback(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrName, bool* pIsCallback)](#oh_abilityruntime_typedescriptor_getinterfaceiscallback) | 检查指定接口是否为回调类型。回调接口表示该接口需要客户端实现并提供给服务端调用。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMainServiceInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getmainserviceinterfacename) | 获取主服务接口名称。<br>主服务接口是远端ModularObjectExtensionAbility对外暴露的默认接口，即通过[OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createmainserviceinstance)创建分发器时所绑定Proxy对象对应的接口。<br>该接口由远端服务在类型库元数据中声明，可通过本接口获取其名称。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t* pcMethods)](#oh_abilityruntime_typedescriptor_getmethodcount) | 获取指定接口中定义的方法总数。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getmethodname) | 根据索引获取接口中的方法名称。方法索引的有效范围为[0, methodCount - 1]，其中methodCount可通过[OH_AbilityRuntime_TypeDescriptor_GetMethodCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodcount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pMemID)](#oh_abilityruntime_typedescriptor_getmethodmemberid) | 根据方法名称获取方法的成员ID（MemberID）。返回的成员ID可作为[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)的memID参数使用。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pReturnType)](#oh_abilityruntime_typedescriptor_getmethodreturntype) | 获取方法的返回类型。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pcParams)](#oh_abilityruntime_typedescriptor_getmethodparamcount) | 获取方法的参数数量。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pParamType)](#oh_abilityruntime_typedescriptor_getmethodparamtype) | 根据索引获取方法参数的类型。参数索引的有效范围为[0, paramCount - 1]，其中paramCount可通过[OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getmethodparamname) | 根据索引获取方法参数的名称。参数索引的有效范围为[0, paramCount - 1]，其中paramCount可通过[OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcEnums)](#oh_abilityruntime_typedescriptor_getenumcount) | 获取类型库中定义的枚举总数。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getenumname) | 根据索引获取枚举名称。枚举索引的有效范围为[0, enumCount - 1]，其中enumCount可通过[OH_AbilityRuntime_TypeDescriptor_GetEnumCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumcount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t* pcValues)](#oh_abilityruntime_typedescriptor_getenumvaluecount) | 获取指定枚举中定义的枚举值数量。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t iValueIndex, char* pbstrValueName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getenumvaluename) | 根据索引获取枚举值的名称。枚举值索引的有效范围为[0, valueCount - 1]，其中valueCount可通过[OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumvaluecount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValue(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, const char* pbstrValueName, int32_t* pValue)](#oh_abilityruntime_typedescriptor_getenumvalue) | 根据枚举值名称获取枚举值。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcStructs)](#oh_abilityruntime_typedescriptor_getstructcount) | 获取类型库中定义的结构体总数。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getstructname) | 根据索引获取结构体名称。结构体索引的有效范围为[0, structCount - 1]，其中structCount可通过[OH_AbilityRuntime_TypeDescriptor_GetStructCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructcount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t* pcFields)](#oh_abilityruntime_typedescriptor_getstructfieldcount) | 获取指定结构体中定义的字段数量。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t iFieldIndex, char* pbstrFieldName, uint32_t cMaxName)](#oh_abilityruntime_typedescriptor_getstructfieldname) | 根据索引获取结构体字段的名称。结构体字段索引的有效范围为[0, fieldCount - 1]，其中fieldCount可通过[OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructfieldcount)获取。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, const char* pbstrFieldName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pFieldType)](#oh_abilityruntime_typedescriptor_getstructfieldtype) | 根据字段名称获取结构体字段的类型。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, uint32_t size, OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)](#oh_abilityruntime_modobjdispatcher_arraycreate) | 创建指定元素类型和大小的数组实例。数组为固定大小，创建后不可改变长度。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)](#oh_abilityruntime_modobjdispatcher_arraygetelementtype) | 获取数组的元素类型。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArraySet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_arrayset) | 设置数组中指定索引位置的元素值。函数会执行深拷贝，调用方保留原始变体的所有权。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_arrayget) | 获取数组中指定索引位置的元素值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetSize(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_arraygetsize) | 获取数组的大小。 |
| [void OH_AbilityRuntime_ModObjDispatcher_ArrayRelease(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)](#oh_abilityruntime_modobjdispatcher_arrayrelease) | 释放数组实例。释放后句柄将被置为NULL。如果ppArray或*ppArray为NULL，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)](#oh_abilityruntime_modobjdispatcher_vectorcreate) | 创建指定元素类型的向量实例。向量为动态大小的有序集合，所有元素类型相同，支持添加元素、按索引获取元素、查询大小和清空。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)](#oh_abilityruntime_modobjdispatcher_vectorgetelementtype) | 获取向量的元素类型。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorAdd(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_vectoradd) | 向向量末尾添加一个元素。函数会执行深拷贝，调用方保留原始变体的所有权。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGet(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_vectorget) | 获取向量中指定索引位置的元素值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetSize(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_vectorgetsize) | 获取向量中的元素数量。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorClear(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector)](#oh_abilityruntime_modobjdispatcher_vectorclear) | 清空向量中的所有元素。 |
| [void OH_AbilityRuntime_ModObjDispatcher_VectorRelease(OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)](#oh_abilityruntime_modobjdispatcher_vectorrelease) | 释放向量实例。释放后句柄将被置为NULL。如果ppVector或*ppVector为NULL，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)](#oh_abilityruntime_modobjdispatcher_setcreate) | 创建指定元素类型的集合实例。集合为不重复元素的无序集合，所有元素类型相同，支持添加、删除、查询指定元素是否存在、按索引获取元素和清空。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetElementType(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)](#oh_abilityruntime_modobjdispatcher_setgetelementtype) | 获取集合的元素类型。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetAdd(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_setadd) | 向集合中添加一个元素。如果元素已存在，则不会重复添加。函数会执行深拷贝，调用方保留原始变体的所有权。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetRemove(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_setremove) | 从集合中移除指定元素。如果元素不存在，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetContains(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue, bool* pExists)](#oh_abilityruntime_modobjdispatcher_setcontains) | 检查集合中是否存在指定元素。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetSize(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_setgetsize) | 获取集合中的元素数量。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetAt(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_setgetat) | 根据索引获取集合中的元素值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetClear(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet)](#oh_abilityruntime_modobjdispatcher_setclear) | 清空集合中的所有元素。 |
| [void OH_AbilityRuntime_ModObjDispatcher_SetRelease(OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)](#oh_abilityruntime_modobjdispatcher_setrelease) | 释放集合实例。释放后句柄将被置为NULL。如果ppSet或*ppSet为NULL，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapCreate(OH_AbilityRuntime_ModObjDispatcher_ValueType keyType, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* valueType, OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)](#oh_abilityruntime_modobjdispatcher_mapcreate) | 创建指定键类型和值类型的映射实例。<br>键仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM），不支持容器类型（ARRAY、VECTOR、SET、MAP）和复杂类型（STRUCT、IPC_REMOTE_PROXY、IPC_REMOTE_STUB）。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_ValueType* pKeyType)](#oh_abilityruntime_modobjdispatcher_mapgetkeytype) | 获取映射的键类型。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pValueType)](#oh_abilityruntime_modobjdispatcher_mapgetvaluetype) | 获取映射的值类型。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapPut(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_mapput) | 向映射中添加或更新键值对。如果键已存在，则更新对应的值。函数会执行深拷贝，调用方保留原始变体的所有权。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGet(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_mapget) | 根据键获取映射中对应的值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapRemove(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)](#oh_abilityruntime_modobjdispatcher_mapremove) | 根据键从映射中移除键值对。如果键不存在，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapContainsKey(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, bool* pExists)](#oh_abilityruntime_modobjdispatcher_mapcontainskey) | 检查映射中是否存在指定的键。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetSize(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t* pSize)](#oh_abilityruntime_modobjdispatcher_mapgetsize) | 获取映射中的键值对数量。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)](#oh_abilityruntime_modobjdispatcher_mapgetkeyat) | 根据索引获取映射中的键。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_mapgetvalueat) | 根据索引获取映射中的值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapClear(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap)](#oh_abilityruntime_modobjdispatcher_mapclear) | 清空映射中的所有键值对。 |
| [void OH_AbilityRuntime_ModObjDispatcher_MapRelease(OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)](#oh_abilityruntime_modobjdispatcher_maprelease) | 释放映射实例。释放后句柄将被置为NULL。如果ppMap或*ppMap为NULL，则不执行任何操作。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructCreate(const char* structName, OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)](#oh_abilityruntime_modobjdispatcher_structcreate) | 根据类型库元数据中的结构体名称创建结构体实例。structName必须与类型库中定义的结构体名称一致，可通过[OH_AbilityRuntime_TypeDescriptor_GetStructName](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructname)获取可用结构体名称。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetName(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, char* pbstrName, uint32_t cMaxName)](#oh_abilityruntime_modobjdispatcher_structgetname) | 获取结构体的类型名称。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructSetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_structsetfield) | 设置结构体中指定字段的值。函数会执行深拷贝，调用方保留原始变体的所有权。 |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)](#oh_abilityruntime_modobjdispatcher_structgetfield) | 获取结构体中指定字段的值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| [void OH_AbilityRuntime_ModObjDispatcher_StructRelease(OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)](#oh_abilityruntime_modobjdispatcher_structrelease) | 释放结构体实例。释放后句柄将被置为NULL。如果ppStruct或*ppStruct为NULL，则不执行任何操作。 |

## 枚举类型说明
### OH_AbilityRuntime_ModObjDispatcher_ValueType

```c
enum OH_AbilityRuntime_ModObjDispatcher_ValueType
```

**描述**

定义变体类型枚举，用于标识变体值的数据类型。

变体（Variant）是一种能够存储多种不同类型值的通用数据容器，类似于C语言的联合体（union）。每个变体在同一时刻只持有一种类型的值，通过本枚举值标识其实际存储的数据类型。

在本模块中，变体用于方法调用的参数传递和返回值接收，使得同一套接口能够处理布尔、整数、浮点数、字符串、数组、向量、集合、映射、结构体、远端通信对象等多种数据类型。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_EMPTY = 0 | 空值。表示未初始化或无效的变体值。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_VOID = 1 | void类型。用于方法不返回任何值。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_BOOL = 2 | 布尔值。取值为true或false，true表示真，false表示假。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I8 = 3 | 8位有符号整数。取值范围：[-128, 127]。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I16 = 4 | 16位有符号整数。取值范围：[-32768, 32767]。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I32 = 5 | 32位有符号整数。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_I64 = 6 | 64位有符号整数。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U8 = 7 | 8位无符号整数。取值范围：[0, 255]。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U16 = 8 | 16位无符号整数。取值范围：[0, 65535]。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U32 = 9 | 32位无符号整数。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_U64 = 10 | 64位无符号整数。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_F32 = 11 | 32位浮点数（单精度）。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_F64 = 12 | 64位浮点数（双精度）。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_STRING = 13 | UTF-8字符串。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_ARRAY = 14 | 数组。固定大小的有序元素集合，所有元素类型相同，支持按索引设置获取元素和查询数组大小。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_VECTOR = 15 | 向量。动态大小的有序元素集合，所有元素类型相同，支持添加元素、按索引获取元素、查询向量大小和清空操作。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_SET = 16 | 集合。不重复元素的无序集合，所有元素类型相同，支持添加元素、删除元素、查询指定元素是否存在、按索引获取元素、查询集合大小和清空操作。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_MAP = 17 | 映射。键值对的有序集合，键和值类型在创建时指定，支持添加或更新键值对、按键获取值、删除键值对、查询指定键是否存在、按索引获取键或值、查询映射大小和清空操作。键仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM），不支持容器类型和复杂类型。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_STRUCT = 18 | 结构体。具名字段的集合，字段类型通过类型库元数据定义。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_IPC_REMOTE_PROXY = 19 | 用于跨进程通信的远端Proxy对象。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_IPC_REMOTE_STUB = 20 | 用于跨进程通信的远端Stub对象。 |
| OH_ABILITY_RUNTIME_MOD_OBJ_DISPATCHER_VT_ENUM = 21 | 枚举值。以int32_t形式存储，枚举定义可通过类型描述符查询。 |

## 函数说明

### OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear()

```c
void OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pTypeInfo)
```

**描述**

清理TypeInfo结构体持有的堆资源。

递归释放TypeInfo持有的堆资源。清理后，所有内部指针被置为NULL，vt被重置为VT_EMPTY，但TypeInfo结构体本身不会被释放（通常由调用方在栈上分配）。

各类型持有的堆资源：  
- 映射（MAP）类型：递归释放并删除由new分配的子TypeInfo节点（u.mapType.pValueType）。  
- 数组（ARRAY）类型：递归释放并删除由new分配的子TypeInfo节点（u.arrayType.pElementType）。  
- 向量（VECTOR）或集合（SET）类型：递归释放并删除由new分配的子TypeInfo节点（u.pElementType）。  
- 结构体（STRUCT）、枚举（ENUM）、远端通信对象（IPC_REMOTE_PROXY、IPC_REMOTE_STUB）类型：释放u.idlType字符串（由strdup分配）。

释放规则：
- 当TypeInfo从函数返回（如[OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodreturntype)、[OH_AbilityRuntime_TypeDescriptor_GetMethodParamType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamtype)、[OH_AbilityRuntime_TypeDescriptor_GetStructFieldType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructfieldtype)、[OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arraygetelementtype)、[OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorgetelementtype)、[OH_AbilityRuntime_ModObjDispatcher_SetGetElementType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setgetelementtype)、[OH_AbilityRuntime_ModObjDispatcher_MapGetValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapgetvaluetype)）时，函数执行深拷贝，调用方获得返回TypeInfo的所有权，必须调用此接口释放资源。
- 当TypeInfo被传入函数（如[OH_AbilityRuntime_ModObjDispatcher_ArrayCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arraycreate)、[OH_AbilityRuntime_ModObjDispatcher_VectorCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_vectorcreate)、[OH_AbilityRuntime_ModObjDispatcher_SetCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_setcreate)、[OH_AbilityRuntime_ModObjDispatcher_MapCreate](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapcreate)）时，函数执行深拷贝，调用方保留原始TypeInfo的所有权，需自行调用此接口释放原始TypeInfo持有的资源。
- 简单类型（布尔、整数、浮点数、空值等）不持有堆资源，无需调用此接口释放。
- 禁止对TypeInfo的浅拷贝调用此接口。如果执行了 TypeInfo t2 = t1，只能对原始实例或拷贝实例中的一个调用此接口。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pTypeInfo | 指向待清理的TypeInfo的指针。 |

### OH_AbilityRuntime_ModObjDispatcher_VariantClear()

```c
void OH_AbilityRuntime_ModObjDispatcher_VariantClear(OH_AbilityRuntime_ModObjDispatcher_Variant* pVariant)
```

**描述**

清理变体持有的资源。

释放变体持有的资源（字符串、容器句柄等），清理后变体被重置为VT_EMPTY，所有字段归零。

释放规则：
- 当变体被传入函数（如[OH_AbilityRuntime_ModObjDispatcher_ArraySet](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arrayset)、[OH_AbilityRuntime_ModObjDispatcher_MapPut](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapput)）时，函数执行深拷贝，调用方保留原始变体的所有权，需自行释放原始变体持有的资源（如字符串需调用free(bstrVal)、容器句柄需调用对应的Release接口）。  
- 当变体从函数返回（如[OH_AbilityRuntime_ModObjDispatcher_ArrayGet](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_arrayget)、[OH_AbilityRuntime_ModObjDispatcher_MapGet](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_mapget)、[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)）时，函数执行深拷贝，调用方获得返回变体的所有权，必须调用此接口释放资源。  
- 简单类型（布尔、整数、浮点数等）不持有堆资源，无需调用此接口释放。  
- 禁止对变体的浅拷贝调用此接口。如果执行了 Variant v2 = v1，只能清理其中一个。  

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pVariant | 指向待清理的变体的指针。 |

### OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance(OHIPCRemoteProxy* remoteProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)
```

**描述**

从远端Proxy对象为主服务接口创建ModularObject分发器实例。

类型库元数据将在首次需要时从远端服务延迟加载（如调用[OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor)、[OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_hastypedescriptor)、[OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames)或[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)时触发）。

调用方需在不再使用时调用[OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release)释放分发器实例，避免内存泄漏。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHIPCRemoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md)* remoteProxy | 远端Proxy对象句柄，通过连接ModularObjectExtensionAbility获取。 |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md)* ppModObjDispatcher | 指向接收ModularObject分发器句柄的指针，不能为NULL，且*ppModObjDispatcher必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) remoteProxy或ppModObjDispatcher为NULL，或*ppModObjDispatcher不为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误，如内存分配失败。请检查系统内存是否充足，必要时释放资源后重试。 |

### OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CreateSubInstance(OH_AbilityRuntime_ModObjDispatcherHandle mainServiceDispatcher, OHIPCRemoteProxy* subProxy, OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)
```

**描述**

创建绑定到主服务分发器的子实例分发器。

子实例共享主服务分发器的类型库元数据，但使用独立的IPC代理发送请求。适用于需要调用同一类型库中非主服务接口的场景。

当在子实例上调用[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)时，方法签名从主服务分发器的类型库元数据中解析，IPC请求通过subProxy发送到远端服务。

调用方需在不再使用时调用[OH_AbilityRuntime_ModObjDispatcher_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_release)释放子实例，避免内存泄漏。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) mainServiceDispatcher | 主服务分发器句柄。 |
| [OHIPCRemoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md)* subProxy | 非主服务接口的远端Proxy对象句柄。 |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md)* ppModObjDispatcher | 指向接收创建的子实例分发器句柄的指针，不能为NULL，且*ppModObjDispatcher必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) mainServiceDispatcher、subProxy或ppModObjDispatcher为NULL，或*ppModObjDispatcher不为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误，如内存分配失败。请检查系统内存是否充足，必要时释放资源后重试。 |

### OH_AbilityRuntime_ModObjDispatcher_Release()

```c
void OH_AbilityRuntime_ModObjDispatcher_Release(OH_AbilityRuntime_ModObjDispatcherHandle* ppModObjDispatcher)
```

**描述**

释放ModularObject分发器实例。释放后指针将被置为NULL。如果ppModObjDispatcher或*ppModObjDispatcher为NULL，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md)* ppModObjDispatcher | 指向待释放的ModularObject分发器句柄的指针。释放后该指针将被置为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_HasTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t* pctinfo)
```

**描述**

检查远端服务是否支持类型库元数据。调用此接口将触发类型库元数据的延迟加载。如果元数据加载成功，*pctinfo 为 1；否则为 0。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) pModObjDispatcher | ModularObject分发器句柄。 |
| uint32_t* pctinfo | 指向接收支持类型库元数据状态的指针。1表示支持，0表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pModObjDispatcher或pctinfo为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) IPC请求发送失败。请检查远端服务是否正常运行。<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 类型库元数据无效。请检查远端服务的类型库定义是否正确。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。请检查系统状态，必要时释放资源后重试。 |

### OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* ppTypeDescriptor)
```

**描述**

获取类型描述符句柄，用于查询接口元数据信息。

类型描述符提供对远端服务类型库元数据的访问能力，包括接口、方法、枚举和结构体的定义信息。调用此接口将触发类型库元数据的延迟加载。

使用完毕后需调用[OH_AbilityRuntime_TypeDescriptor_Release](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_release)释放句柄。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) pModObjDispatcher | ModularObject分发器句柄。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md)* ppTypeDescriptor | 指向接收类型描述符句柄的指针，不能为NULL，且*ppTypeDescriptor必须为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pModObjDispatcher或ppTypeDescriptor为NULL，或*ppTypeDescriptor不为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) IPC请求发送失败。请检查远端服务是否正常运行。<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 类型库元数据无效。请检查远端服务的类型库定义是否正确。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。请检查系统状态，必要时释放资源后重试。 |

### OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, const char** rgszNames, uint32_t cNames, uint32_t* pMemID)
```

**描述**

根据方法名称查询主服务接口中对应的方法成员ID（MemberID）。返回的成员ID可作为[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)的memID参数使用。调用此接口将触发类型库元数据的延迟加载。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) pModObjDispatcher | ModularObject分发器句柄。 |
| const char** rgszNames | 方法名称数组。 |
| uint32_t cNames | 方法名称数量。 |
| uint32_t* pMemID | 指向接收成员ID数组的指针。数组长度与cNames相同，每个名称对应一个成员ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pModObjDispatcher、rgszNames或pMemID为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) IPC请求发送失败。请检查远端服务是否正常运行。<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 类型库元数据无效。请检查远端服务的类型库定义是否正确。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 方法名称未找到。请检查方法名称是否与类型库中定义一致。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。请检查系统状态，必要时释放资源后重试。 |

### OH_AbilityRuntime_ModObjDispatcher_CallMethod()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_CallMethod(OH_AbilityRuntime_ModObjDispatcherHandle pModObjDispatcher, uint32_t memID, OH_AbilityRuntime_ModObjDispatcher_InputParams* pInputParams, OH_AbilityRuntime_ModObjDispatcher_Variant* pResult, int32_t* pMethodErrCode)
```

**描述**

通过成员ID（MemberID）调用远端方法。

调用流程：通过memID从元数据管理器获取方法元数据（方法名、参数类型、返回类型、IPC码等），将参数序列化到MessageParcel，通过IPC发送请求到远端服务，最后反序列化返回结果。

本接口采用双层错误处理机制：
- 框架级错误：IPC通信、元数据加载、参数验证等框架层面的问题，通过方法返回值返回。  
- 方法级错误：远端方法执行返回的业务错误，通过pMethodErrCode输出参数返回。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcherHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher8h.md) pModObjDispatcher | ModularObject分发器句柄。 |
| uint32_t memID | 方法成员ID（MemberID），可通过[OH_AbilityRuntime_ModObjDispatcher_QueryMainServiceInterfaceMemIDsOfNames](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_querymainserviceinterfacememidsofnames)或[OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodmemberid)获取。 |
| [OH_AbilityRuntime_ModObjDispatcher_InputParams](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-inputparams.md)* pInputParams | 指向包含调用参数的结构体。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pResult | 指向接收返回结果变体的指针。返回的变体是深拷贝，调用方需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。 |
| int32_t* pMethodErrCode | 指向接收方法级错误码的指针。0表示方法执行成功，非零表示方法返回错误，该错误码独立于框架级返回值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pModObjDispatcher、pInputParams或pResult为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 方法未找到。请检查memID是否正确。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 参数类型与元数据定义不匹配。请检查输入参数类型是否与方法定义一致。<br>[ABILITY_RUNTIME_ERROR_CODE_SEND_REQUEST_FAILED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) IPC请求发送失败。请检查远端服务是否正常运行。<br>[ABILITY_RUNTIME_ERROR_CODE_METADATA_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 类型库元数据无效。请检查远端服务的类型库定义是否正确。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。请检查系统状态，必要时释放资源后重试。 |

### OH_AbilityRuntime_TypeDescriptor_Release()

```c
void OH_AbilityRuntime_TypeDescriptor_Release(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle* pTypeDescriptor)
```

**描述**

释放类型描述符实例。释放后句柄将被置为NULL。如果pTypeDescriptor或*pTypeDescriptor为NULL，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md)* pTypeDescriptor | 指向待释放的类型描述符句柄的指针。释放后该指针将被置为NULL。 |

**参考：**

[OH_AbilityRuntime_ModObjDispatcher_GetTypeDescriptor](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_gettypedescriptor)

### OH_AbilityRuntime_TypeDescriptor_GetVersion()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetVersion(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrVersion, uint32_t cMaxVersion)
```

**描述**

获取类型库版本号。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| char* pbstrVersion | 指向接收版本字符串的缓冲区。 |
| uint32_t cMaxVersion | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pbstrVersion为NULL，或cMaxVersion为0。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcInterfaces)
```

**描述**

获取类型库中定义的接口总数。返回的数量可用于确定遍历接口时的索引上限。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| uint32_t* pcInterfaces | 指向接收接口总数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pcInterfaces为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetInterfaceName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**描述**

根据索引获取接口名称。接口索引的有效范围为[0, interfaceCount - 1]，其中interfaceCount可通过[OH_AbilityRuntime_TypeDescriptor_GetInterfaceCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getinterfacecount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| uint32_t index | 接口索引。 |
| char* pbstrName | 指向接收接口名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pbstrName为NULL，或cMaxName为0，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetInterfaceIsCallback()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetInterfaceIsCallback(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrName, bool* pIsCallback)
```

**描述**

检查指定接口是否为回调类型。回调接口表示该接口需要客户端实现并提供给服务端调用。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrName | 接口名称。 |
| bool* pIsCallback | 指向接收回调标志的指针。true表示是回调接口，false表示不是。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrName或pIsCallback为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMainServiceInterfaceName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMainServiceInterfaceName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, char* pbstrName, uint32_t cMaxName)
```

**描述**

获取主服务接口名称。

主服务接口是远端ModularObjectExtensionAbility对外暴露的默认接口，即通过[OH_AbilityRuntime_ModObjDispatcher_CreateMainServiceInstance](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_createmainserviceinstance)创建分发器时所绑定Proxy对象对应的接口。

该接口由远端服务在类型库元数据中声明，可通过本接口获取其名称。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| char* pbstrName | 指向接收主服务接口名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pbstrName为NULL，或cMaxName为0。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMethodCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t* pcMethods)
```

**描述**

获取指定接口中定义的方法总数。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrInterfaceName | 接口名称。 |
| uint32_t* pcMethods | 指向接收方法总数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrInterfaceName或pcMethods为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMethodName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**描述**

根据索引获取接口中的方法名称。方法索引的有效范围为[0, methodCount - 1]，其中methodCount可通过[OH_AbilityRuntime_TypeDescriptor_GetMethodCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodcount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrInterfaceName | 接口名称。 |
| uint32_t index | 方法索引。 |
| char* pbstrName | 指向接收方法名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrInterfaceName或pbstrName为NULL，或cMaxName为0，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodMemberId(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pMemID)
```

**描述**

根据方法名称获取方法的成员ID（MemberID）。返回的成员ID可作为[OH_AbilityRuntime_ModObjDispatcher_CallMethod](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_callmethod)的memID参数使用。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrInterfaceName | 接口名称。 |
| const char* pbstrMethodName | 方法名称。 |
| uint32_t* pMemID | 指向接收方法成员ID的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrInterfaceName、pbstrMethodName或pMemID为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口或方法未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodReturnType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pReturnType)
```

**描述**

获取方法的返回类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrInterfaceName | 接口名称。 |
| const char* pbstrMethodName | 方法名称。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pReturnType | 指向接收返回类型的TypeInfo的指针。使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrInterfaceName、pbstrMethodName或pReturnType为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口或方法未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t* pcParams)
```

**描述**

获取方法的参数数量。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrInterfaceName | 接口名称。 |
| const char* pbstrMethodName | 方法名称。 |
| uint32_t* pcParams | 指向接收参数数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrInterfaceName、pbstrMethodName或pcParams为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口或方法未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMethodParamType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pParamType)
```

**描述**

根据索引获取方法参数的类型。参数索引的有效范围为[0, paramCount - 1]，其中paramCount可通过[OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrInterfaceName | 接口名称。 |
| const char* pbstrMethodName | 方法名称。 |
| uint32_t iParamIndex | 参数索引。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pParamType | 指向接收参数类型的TypeInfo的指针。使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrInterfaceName、pbstrMethodName或pParamType为NULL，或iParamIndex超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口或方法未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetMethodParamName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetMethodParamName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrInterfaceName, const char* pbstrMethodName, uint32_t iParamIndex, char* pbstrName, uint32_t cMaxName)
```

**描述**

根据索引获取方法参数的名称。参数索引的有效范围为[0, paramCount - 1]，其中paramCount可通过[OH_AbilityRuntime_TypeDescriptor_GetMethodParamCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getmethodparamcount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrInterfaceName | 接口名称。 |
| const char* pbstrMethodName | 方法名称。 |
| uint32_t iParamIndex | 参数索引。 |
| char* pbstrName | 指向接收参数名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrInterfaceName、pbstrMethodName或pbstrName为NULL，或iParamIndex超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口或方法未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetEnumCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcEnums)
```

**描述**

获取类型库中定义的枚举总数。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| uint32_t* pcEnums | 指向接收枚举总数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pcEnums为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetEnumName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**描述**

根据索引获取枚举名称。枚举索引的有效范围为[0, enumCount - 1]，其中enumCount可通过[OH_AbilityRuntime_TypeDescriptor_GetEnumCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumcount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| uint32_t index | 枚举索引。 |
| char* pbstrName | 指向接收枚举名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pbstrName为NULL，或cMaxName为0，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t* pcValues)
```

**描述**

获取指定枚举中定义的枚举值数量。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrEnumName | 枚举名称。 |
| uint32_t* pcValues | 指向接收枚举值数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrEnumName或pcValues为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 枚举未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetEnumValueName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValueName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, uint32_t iValueIndex, char* pbstrValueName, uint32_t cMaxName)
```

**描述**

根据索引获取枚举值的名称。枚举值索引的有效范围为[0, valueCount - 1]，其中valueCount可通过[OH_AbilityRuntime_TypeDescriptor_GetEnumValueCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getenumvaluecount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrEnumName | 枚举名称。 |
| uint32_t iValueIndex | 枚举值索引。 |
| char* pbstrValueName | 指向接收枚举值名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrEnumName或pbstrValueName为NULL，或iValueIndex超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 枚举未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetEnumValue()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetEnumValue(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrEnumName, const char* pbstrValueName, int32_t* pValue)
```

**描述**

根据枚举值名称获取枚举值。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrEnumName | 枚举名称。 |
| const char* pbstrValueName | 枚举值名称。 |
| int32_t* pValue | 指向接收枚举值的指针。枚举值以int32_t形式返回。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrEnumName、pbstrValueName或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 枚举值未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetStructCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t* pcStructs)
```

**描述**

获取类型库中定义的结构体总数。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| uint32_t* pcStructs | 指向接收结构体总数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pcStructs为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetStructName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, uint32_t index, char* pbstrName, uint32_t cMaxName)
```

**描述**

根据索引获取结构体名称。结构体索引的有效范围为[0, structCount - 1]，其中structCount可通过[OH_AbilityRuntime_TypeDescriptor_GetStructCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructcount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| uint32_t index | 结构体索引。 |
| char* pbstrName | 指向接收结构体名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor或pbstrName为NULL，或cMaxName为0，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t* pcFields)
```

**描述**

获取指定结构体中定义的字段数量。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrStructName | 结构体名称。 |
| uint32_t* pcFields | 指向接收字段数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrStructName或pcFields为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 结构体未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetStructFieldName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldName(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, uint32_t iFieldIndex, char* pbstrFieldName, uint32_t cMaxName)
```

**描述**

根据索引获取结构体字段的名称。结构体字段索引的有效范围为[0, fieldCount - 1]，其中fieldCount可通过[OH_AbilityRuntime_TypeDescriptor_GetStructFieldCount](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructfieldcount)获取。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrStructName | 结构体名称。 |
| uint32_t iFieldIndex | 结构体字段索引。 |
| char* pbstrFieldName | 指向接收字段名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrStructName或pbstrFieldName为NULL，或iFieldIndex超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 结构体未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_TypeDescriptor_GetStructFieldType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_TypeDescriptor_GetStructFieldType(OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle pTypeDescriptor, const char* pbstrStructName, const char* pbstrFieldName, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pFieldType)
```

**描述**

根据字段名称获取结构体字段的类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeDescriptorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-typedescriptor8h.md) pTypeDescriptor | 类型描述符句柄。 |
| const char* pbstrStructName | 结构体名称。 |
| const char* pbstrFieldName | 字段名称。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pFieldType | 指向接收字段类型的TypeInfo的指针。使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pTypeDescriptor、pbstrStructName、pbstrFieldName或pFieldType为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 结构体或字段未找到。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_ArrayCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, uint32_t size, OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)
```

**描述**

创建指定元素类型和大小的数组实例。数组为固定大小，创建后不可改变长度。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* elementType | 指向元素类型描述符的指针。函数执行深拷贝，调用方保留原始TypeInfo的所有权，需自行调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放TypeInfo持有的堆资源。 |
| uint32_t size | 数组的初始大小。 |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md)* ppArray | 指向接收数组句柄的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) elementType或ppArray为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetElementType(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)
```

**描述**

获取数组的元素类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | 数组句柄。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType | 指向接收元素类型的TypeInfo的指针。使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pArray或pElementType为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_ArraySet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArraySet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

设置数组中指定索引位置的元素值。函数会执行深拷贝，调用方保留原始变体的所有权。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | 数组句柄。 |
| uint32_t index | 元素索引，范围为[0, size - 1]。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向元素值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pArray或pValue为NULL，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 元素类型与数组定义的类型不匹配。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_ArrayGet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGet(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

获取数组中指定索引位置的元素值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | 数组句柄。 |
| uint32_t index | 元素索引，范围为[0, size - 1]。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向接收元素值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pArray或pValue为NULL，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_ArrayGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_ArrayGetSize(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle pArray, uint32_t* pSize)
```

**描述**

获取数组的大小。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) pArray | 数组句柄。 |
| uint32_t* pSize | 指向接收数组大小的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pArray或pSize为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_ArrayRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_ArrayRelease(OH_AbilityRuntime_ModObjDispatcher_ArrayHandle* ppArray)
```

**描述**

释放数组实例。释放后句柄将被置为NULL。如果ppArray或*ppArray为NULL，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md)* ppArray | 指向待释放的数组句柄的指针。释放后该指针将被置为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_VectorCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)
```

**描述**

创建指定元素类型的向量实例。向量为动态大小的有序集合，所有元素类型相同，支持添加元素、按索引获取元素、查询大小和清空。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* elementType | 指向元素类型描述符的指针。函数执行深拷贝，调用方保留原始TypeInfo的所有权，需自行调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放TypeInfo持有的堆资源。 |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md)* ppVector | 指向接收向量句柄的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) elementType或ppVector为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetElementType(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)
```

**描述**

获取向量的元素类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | 向量句柄。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType | 指向接收元素类型的TypeInfo的指针。使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector或pElementType为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_VectorAdd()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorAdd(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

向向量末尾添加一个元素。函数会执行深拷贝，调用方保留原始变体的所有权。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | 向量句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向元素值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 元素类型与向量定义的类型不匹配。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_VectorGet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGet(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

获取向量中指定索引位置的元素值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | 向量句柄。 |
| uint32_t index | 元素索引，范围为[0, size - 1]。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向接收元素值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector或pValue为NULL，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_VectorGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorGetSize(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector, uint32_t* pSize)
```

**描述**

获取向量中的元素数量。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | 向量句柄。 |
| uint32_t* pSize | 指向接收元素数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector或pSize为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_VectorClear()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_VectorClear(OH_AbilityRuntime_ModObjDispatcher_VectorHandle pVector)
```

**描述**

清空向量中的所有元素。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pVector | 向量句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pVector为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_VectorRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_VectorRelease(OH_AbilityRuntime_ModObjDispatcher_VectorHandle* ppVector)
```

**描述**

释放向量实例。释放后句柄将被置为NULL。如果ppVector或*ppVector为NULL，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md)* ppVector | 指向待释放的向量句柄的指针。释放后该指针将被置为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_SetCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetCreate(OH_AbilityRuntime_ModObjDispatcher_TypeInfo* elementType, OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)
```

**描述**

创建指定元素类型的集合实例。集合为不重复元素的无序集合，所有元素类型相同，支持添加、删除、查询指定元素是否存在、按索引获取元素和清空。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* elementType | 指向元素类型描述符的指针。函数执行深拷贝，调用方保留原始TypeInfo的所有权，需自行调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放TypeInfo持有的堆资源。 |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md)* ppSet | 指向接收集合句柄的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) elementType或ppSet为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_SetGetElementType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetElementType(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pElementType)
```

**描述**

获取集合的元素类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | 集合句柄。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType | 指向接收元素类型的TypeInfo的指针。使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet或pElementType为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_SetAdd()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetAdd(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

向集合中添加一个元素。如果元素已存在，则不会重复添加。函数会执行深拷贝，调用方保留原始变体的所有权。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | 集合句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向元素值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 元素类型与集合定义的类型不匹配。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_SetRemove()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetRemove(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

从集合中移除指定元素。如果元素不存在，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | 集合句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向待移除元素值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 元素类型与集合定义的类型不匹配。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_SetContains()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetContains(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue, bool* pExists)
```

**描述**

检查集合中是否存在指定元素。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | 集合句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向待查找元素值变体的指针。 |
| bool* pExists | 指向接收存在标志的指针。true表示元素存在，false表示不存在。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet、pValue或pExists为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 元素类型与集合定义的类型不匹配。 |

### OH_AbilityRuntime_ModObjDispatcher_SetGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetSize(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t* pSize)
```

**描述**

获取集合中的元素数量。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | 集合句柄。 |
| uint32_t* pSize | 指向接收元素数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet或pSize为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_SetGetAt()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetGetAt(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

根据索引获取集合中的元素值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | 集合句柄。 |
| uint32_t index | 元素索引，范围为[0, size - 1]。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向接收元素值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet或pValue为NULL，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_SetClear()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_SetClear(OH_AbilityRuntime_ModObjDispatcher_SetHandle pSet)
```

**描述**

清空集合中的所有元素。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) pSet | 集合句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pSet为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_SetRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_SetRelease(OH_AbilityRuntime_ModObjDispatcher_SetHandle* ppSet)
```

**描述**

释放集合实例。释放后句柄将被置为NULL。如果ppSet或*ppSet为NULL，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md)* ppSet | 指向待释放的集合句柄的指针。释放后该指针将被置为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_MapCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapCreate(OH_AbilityRuntime_ModObjDispatcher_ValueType keyType, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* valueType, OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)
```

**描述**

创建指定键类型和值类型的映射实例。键仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM），不支持容器类型（ARRAY、VECTOR、SET、MAP）和复杂类型（STRUCT、IPC_REMOTE_PROXY、IPC_REMOTE_STUB）。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) keyType | 键类型。仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM）。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* valueType | 指向值类型描述符的指针，值类型无特殊限制。函数执行深拷贝，调用方保留原始TypeInfo的所有权，需自行调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放TypeInfo持有的堆资源。 |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md)* ppMap | 指向接收映射句柄的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) valueType或ppMap为NULL，或keyType为不支持的类型。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_MapGetKeyType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_ValueType* pKeyType)
```

**描述**

获取映射的键类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype)* pKeyType | 指向接收键类型的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap或pKeyType为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_MapGetValueType()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueType(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, OH_AbilityRuntime_ModObjDispatcher_TypeInfo* pValueType)
```

**描述**

获取映射的值类型。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| [OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pValueType | 指向接收值类型的TypeInfo的指针。使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap或pValueType为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_MapPut()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapPut(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

向映射中添加或更新键值对。如果键已存在，则更新对应的值。函数会执行深拷贝，调用方保留原始变体的所有权。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | 指向键变体的指针。键类型必须与创建映射时指定的类型一致，仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM）。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap、pKey或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 键或值的类型与映射定义的类型不匹配。请检查键值类型是否与创建映射时指定的类型一致。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。请检查系统状态，必要时释放资源后重试。 |

### OH_AbilityRuntime_ModObjDispatcher_MapGet()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGet(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

根据键获取映射中对应的值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | 指向键变体的指针。键类型必须与创建映射时指定的类型一致，仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM）。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向接收值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap、pKey或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 键或值的类型与映射定义的类型不匹配。请检查键值类型是否与创建映射时指定的类型一致。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 键在映射中不存在。请检查键是否正确。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。请检查系统状态，必要时释放资源后重试。 |

### OH_AbilityRuntime_ModObjDispatcher_MapRemove()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapRemove(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)
```

**描述**

根据键从映射中移除键值对。如果键不存在，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | 指向键变体的指针。键类型必须与创建映射时指定的类型一致，仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap或pKey为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 键或值的类型与映射定义的类型不匹配。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_MapContainsKey()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapContainsKey(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, const OH_AbilityRuntime_ModObjDispatcher_Variant* pKey, bool* pExists)
```

**描述**

检查映射中是否存在指定的键。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | 指向键变体的指针。键类型必须与创建映射时指定的类型一致，仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM）。 |
| bool* pExists | 指向接收存在标志的指针。true表示键存在，false表示不存在。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap、pKey或pExists为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 键或值的类型与映射定义的类型不匹配。 |

### OH_AbilityRuntime_ModObjDispatcher_MapGetSize()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetSize(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t* pSize)
```

**描述**

获取映射中的键值对数量。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| uint32_t* pSize | 指向接收键值对数量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap或pSize为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_MapGetKeyAt()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetKeyAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pKey)
```

**描述**

根据索引获取映射中的键。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| uint32_t index | 键值对索引，范围为[0, size - 1]。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pKey | 指向接收键变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap或pKey为NULL，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_MapGetValueAt()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapGetValueAt(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap, uint32_t index, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

根据索引获取映射中的值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |
| uint32_t index | 键值对索引，范围为[0, size - 1]。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向接收值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap或pValue为NULL，或index超出范围。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_MapClear()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_MapClear(OH_AbilityRuntime_ModObjDispatcher_MapHandle pMap)
```

**描述**

清空映射中的所有键值对。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pMap | 映射句柄。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pMap为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_MapRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_MapRelease(OH_AbilityRuntime_ModObjDispatcher_MapHandle* ppMap)
```

**描述**

释放映射实例。释放后句柄将被置为NULL。如果ppMap或*ppMap为NULL，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md)* ppMap | 指向待释放的映射句柄的指针。释放后该指针将被置为NULL。 |

### OH_AbilityRuntime_ModObjDispatcher_StructCreate()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructCreate(const char* structName, OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)
```

**描述**

根据类型库元数据中的结构体名称创建结构体实例。structName必须与类型库中定义的结构体名称一致，可通过[OH_AbilityRuntime_TypeDescriptor_GetStructName](capi-modular-object-dispatcher-h.md#oh_abilityruntime_typedescriptor_getstructname)获取可用结构体名称。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* structName | 结构体名称，来源于类型库元数据。 |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md)* ppStruct | 指向接收结构体句柄的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) structName或ppStruct为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) structName在类型库定义的结构体名称中不存在。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_StructGetName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetName(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, char* pbstrName, uint32_t cMaxName)
```

**描述**

获取结构体的类型名称。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pStruct | 结构体句柄。 |
| char* pbstrName | 指向接收结构体名称的缓冲区。 |
| uint32_t cMaxName | 缓冲区大小（字节），包括空终止符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pStruct或pbstrName为NULL，或cMaxName为0。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_StructSetField()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructSetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, const OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

设置结构体中指定字段的值。函数会执行深拷贝，调用方保留原始变体的所有权。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pStruct | 结构体句柄。 |
| const char* szName | 字段名称。 |
| [const OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向字段值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pStruct、szName或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 字段在结构体中不存在。<br>[ABILITY_RUNTIME_ERROR_CODE_TYPE_MISMATCH](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 字段类型与元数据定义的类型不匹配。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_StructGetField()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_ModObjDispatcher_StructGetField(OH_AbilityRuntime_ModObjDispatcher_StructHandle pStruct, const char* szName, OH_AbilityRuntime_ModObjDispatcher_Variant* pValue)
```

**描述**

获取结构体中指定字段的值。返回的变体是深拷贝，调用方拥有返回变体的所有权，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pStruct | 结构体句柄。 |
| const char* szName | 字段名称。 |
| [OH_AbilityRuntime_ModObjDispatcher_Variant](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-variant.md)* pValue | 指向接收字段值变体的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| AbilityRuntime_ErrorCode | 返回特定的错误码。<br>[ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 接口调用成功。<br>[ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID](capi-ability-runtime-common-h.md#abilityruntime_errorcode) pStruct、szName或pValue为NULL。<br>[ABILITY_RUNTIME_ERROR_CODE_PROPERTY_NOT_FOUND](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 字段在结构体中不存在。<br>[ABILITY_RUNTIME_ERROR_CODE_INTERNAL](capi-ability-runtime-common-h.md#abilityruntime_errorcode) 内部错误。 |

### OH_AbilityRuntime_ModObjDispatcher_StructRelease()

```c
void OH_AbilityRuntime_ModObjDispatcher_StructRelease(OH_AbilityRuntime_ModObjDispatcher_StructHandle* ppStruct)
```

**描述**

释放结构体实例。释放后句柄将被置为NULL。如果ppStruct或*ppStruct为NULL，则不执行任何操作。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md)* ppStruct | 指向待释放的结构体句柄的指针。释放后该指针将被置为NULL。 |


