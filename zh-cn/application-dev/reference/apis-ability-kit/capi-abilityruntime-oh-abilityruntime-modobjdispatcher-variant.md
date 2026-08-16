# OH_AbilityRuntime_ModObjDispatcher_Variant

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

```c
typedef struct {...} OH_AbilityRuntime_ModObjDispatcher_Variant
```

## 概述

定义使用联合体加类型标签的变体结构，通过类型标签区分实际数据类型，用于在参数传递和返回值接收中安全传递多种类型的值。

变体值由vt字段决定实际存储的数据类型和联合体中有效的成员。

当变体持有堆分配资源（如字符串、容器句柄）时，需调用[OH_AbilityRuntime_ModObjDispatcher_VariantClear](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_variantclear)释放。

简单类型（布尔、整数、浮点数）不持有堆资源，无需调用OH_AbilityRuntime_ModObjDispatcher_VariantClear释放。

> **说明：**
>
> 禁止对变体的浅拷贝调用OH_AbilityRuntime_ModObjDispatcher_VariantClear。如果执行了 Variant v2 = v1，只能清理其中一个。

**起始版本：** 26.0.0

**相关模块：** [AbilityRuntime](capi-abilityruntime.md)

**所在头文件：** [modular_object_dispatcher.h](capi-modular-object-dispatcher-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_AbilityRuntime_ModObjDispatcher_ValueType](capi-modular-object-dispatcher-h.md#oh_abilityruntime_modobjdispatcher_valuetype) vt | 变体类型标签，决定联合体中有效的成员。<br>**起始版本：** 26.0.0 |
| uint64_t reserved1 | 保留字段1。预留空间供后续版本扩展使用，调用方应将其初始化为0，且不应读取或修改。<br>**起始版本：** 26.0.0 |
| uint64_t reserved2 | 保留字段2。预留空间供后续版本扩展使用，调用方应将其初始化为0，且不应读取或修改。<br>**起始版本：** 26.0.0 |
| uint64_t reserved3 | 保留字段3。预留空间供后续版本扩展使用，调用方应将其初始化为0，且不应读取或修改。<br>**起始版本：** 26.0.0 |
| union {<br>void* pvoidVal;<br>bool boolVal;<br>int8_t i8Val;<br>int16_t i16Val;<br>int32_t i32Val;<br>int64_t i64Val;<br>uint8_t u8Val;<br>uint16_t u16Val;<br>uint32_t u32Val;<br>uint64_t u64Val;<br>float f32Val;<br>double f64Val;<br>int32_t enumVal;<br>char* bstrVal;<br>[OH_AbilityRuntime_ModObjDispatcher_ArrayHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-array8h.md) parrayVal;<br>[OH_AbilityRuntime_ModObjDispatcher_VectorHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-vector8h.md) pvectorVal;<br>[OH_AbilityRuntime_ModObjDispatcher_SetHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-set8h.md) psetVal;<br>[OH_AbilityRuntime_ModObjDispatcher_MapHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-map8h.md) pmapVal;<br>[OH_AbilityRuntime_ModObjDispatcher_StructHandle](capi-abilityruntime-oh-abilityruntime-modularobjectdispatcher-struct8h.md) pstructVal;<br>[OHIPCRemoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md)* premoteProxyVal;<br>[OHIPCRemoteStub](../apis-ipc-kit/capi-ohipcparcel-ohipcremotestub.md)* premoteStubVal;<br>} u | 变体值数据联合体。有效的成员由vt决定。<br>pvoidVal：void指针。<br>boolVal：布尔值。<br>i8Val：8位有符号整数。<br>i16Val：16位有符号整数。<br>i32Val：32位有符号整数。<br>i64Val：64位有符号整数。<br>u8Val：8位无符号整数。<br>u16Val：16位无符号整数。<br>u32Val：32位无符号整数。<br>u64Val：64位无符号整数。<br>f32Val：32位浮点数（单精度）。<br>f64Val：64位浮点数（双精度）。<br>enumVal：枚举值，以int32_t形式存储。<br>bstrVal：UTF-8字符串句柄，指向堆分配的字符串。<br>parrayVal：数组句柄。<br>pvectorVal：向量句柄。<br>psetVal：集合句柄。<br>pmapVal：映射句柄。<br>pstructVal：结构体句柄。<br>premoteProxyVal：远端Proxy对象句柄。<br>premoteStubVal：远端Stub对象句柄。<br>**起始版本：** 26.0.0 |


