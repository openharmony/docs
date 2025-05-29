# native_interface.h


## 概述

提供NativeModule接口的统一入口函数。

**库：** libace_ndk.z.so

**引用文件：** <arkui/native_interface.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ArkUI_GetModuleInterface](_ark_u_i___native_module.md#oh_arkui_getmoduleinterface)(nativeAPIVariantKind, structType, structPtr) | 基于结构体类型获取对应结构体指针的宏函数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_NativeAPIVariantKind](_ark_u_i___native_module.md#arkui_nativeapivariantkind) { ARKUI_NATIVE_NODE, ARKUI_NATIVE_DIALOG, ARKUI_NATIVE_GESTURE, ARKUI_NATIVE_ANIMATE } | 定义Native接口集合类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| void \* [OH_ArkUI_QueryModuleInterfaceByName](_ark_u_i___native_module.md#oh_arkui_querymoduleinterfacebyname) ([ArkUI_NativeAPIVariantKind](_ark_u_i___native_module.md#arkui_nativeapivariantkind) type, const char \*structName) | 获取指定类型的Native模块接口集合。  | 
