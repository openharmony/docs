# native_interface.h


## 概述

提供NativeModule接口的统一入口函数。

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_AnyNativeAPI](_ark_u_i___any_native_a_p_i.md) | 定义任意版本的Native接口类型。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [ArkUI_NativeAPIVariantKind](_ark_u_i___native_module.md#arkui_nativeapivariantkind) { [ARKUI_NATIVE_NODE](_ark_u_i___native_module.md) } | 定义Native接口集合类型。  |
| [ArkUI_NativeNodeAPIVersion](_ark_u_i___native_module.md#arkui_nativenodeapiversion) { [ARKUI_NATIVE_NODE_VERSION_1](_ark_u_i___native_module.md) } | 定义ARKUI_NATIVE_NODE类型支持的版本号信息。  |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [ArkUI_AnyNativeAPI](_ark_u_i___any_native_a_p_i.md) \* [OH_ArkUI_GetNativeAPI](_ark_u_i___native_module.md#oh_arkui_getnativeapi) ([ArkUI_NativeAPIVariantKind](_ark_u_i___native_module.md#arkui_nativeapivariantkind) type, int32_t version) | 获取指定版本的Native接口集合。  |
| [ArkUI_AnyNativeAPI](_ark_u_i___any_native_a_p_i.md) \* [OH_ArkUI_QueryModuleInterface](_ark_u_i___native_module.md#oh_arkui_querymoduleinterface) ([ArkUI_NativeAPIVariantKind](_ark_u_i___native_module.md#arkui_nativeapivariantkind) type, int32_t version) | 获取指定版本的Native模块接口集合。  |
