# OH_AbilityRuntime_ModObjDispatcher_TypeInfo

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

```c
typedef struct OH_AbilityRuntime_ModObjDispatcher_TypeInfo {...} OH_AbilityRuntime_ModObjDispatcher_TypeInfo
```

## 概述

定义参数或返回值的类型信息。  
  
使用带标签的联合体u描述类型信息，通过vt字段决定联合体中哪个成员有效。  
  
- 对于映射（MAP）类型，使用u.mapType.keyType描述键类型，u.mapType.pValueType描述值类型；  
- 对于数组（ARRAY）类型，使用u.arrayType.pElementType描述元素类型，u.arrayType.size描述数组的固定大小；  
- 对于向量（VECTOR）或集合（SET）类型，使用u.pElementType描述元素类型；  
- 对于结构体（STRUCT）、远端通信对象（IPC_REMOTE_PROXY、IPC_REMOTE_STUB）、枚举（ENUM）类型，使用u.idlType描述[IDL类型名称](../../application-models/modular-object-extension-ability-taihe.md#ohidl文件编写规范)。  

使用完毕后需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放内部持有的堆资源。

**起始版本：** 26.0.0

**相关模块：** [AbilityRuntime](capi-abilityruntime.md)

**所在头文件：** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) vt | 类型标签，决定联合体中哪个成员有效。<br>**起始版本：** 26.0.0 |
| union {<br>struct {<br>[OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) keyType;<br>[OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pValueType;<br>} mapType;<br>struct {<br>[OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType;<br>uint32_t size;<br>} arrayType;<br>[OH_AbilityRuntime_ModObjDispatcher_TypeInfo](capi-abilityruntime-oh-abilityruntime-modobjdispatcher-typeinfo.md)* pElementType;<br>char* idlType;<br>} u | 类型特定的元数据联合体。有效的成员由vt决定。<br>mapType：映射类型元数据，当vt为MAP时使用。<br>mapType.keyType：映射的键类型，仅支持基本类型（BOOL、有符号整数、无符号整数、浮点数、STRING、ENUM），不支持容器类型（ARRAY、VECTOR、SET、MAP）和复杂类型（STRUCT、IPC_REMOTE_PROXY、IPC_REMOTE_STUB）。<br>mapType.pValueType：值类型描述符的句柄，需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。<br>arrayType：数组类型元数据，当vt为ARRAY时使用。<br>arrayType.pElementType：元素类型描述符的句柄，需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。<br>arrayType.size：数组的固定大小。<br>pElementType：元素类型描述符的句柄，当vt为VECTOR或SET时使用，需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。<br>idlType：[IDL类型名称](../../application-models/modular-object-extension-ability-taihe.md#ohidl文件编写规范)字符串，当vt为STRUCT、IPC_REMOTE_PROXY、IPC_REMOTE_STUB、ENUM时使用，需调用[OH_AbilityRuntime_ModObjDispatcher_TypeInfoClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_typeinfoclear)释放。<br>**起始版本：** 26.0.0 |


