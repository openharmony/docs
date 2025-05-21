# native_interface_bundle.h


## 概述

提供查询应用信息等相关功能。

**起始版本：**

9

**相关模块：**

[bundle](_bundle.md)


## 汇总


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OH_NativeBundle_ApplicationInfo](_o_h___native_bundle_application_info.md) | 提供应用相关信息。 |
| [OH_NativeBundle_ElementName](_o_h___native_bundle_element_name.md) | 提供应用入口的信息。 |
| [OH_NativeBundle_Metadata](native_interface_bundle_metadata.md) | 提供元数据信息。 |
| [OH_NativeBundle_ModuleMetadata](native_interface_bundle_module_metadata.md) | 提供模块元数据的信息。 |

### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](_bundle.md#oh_nativebundle_getcurrentapplicationinfo)| 获取当前应用的信息。 |
| [OH_NativeBundle_GetAppId](_bundle.md#oh_nativebundle_getappid) | 获取当前应用的appId信息。 |
| [OH_NativeBundle_GetAppIdentifier](_bundle.md#oh_nativebundle_getappidentifier) | 获取当前应用的appIdentifier信息。 |
| [OH_NativeBundle_GetMainElementName](_bundle.md#oh_nativebundle_getmainelementname) | 获取当前应用的入口信息。 |
| [OH_NativeBundle_GetCompatibleDeviceType](_bundle.md#oh_nativebundle_getcompatibledevicetype) | 获取当前应用适用的设备类型。 |
| [OH_NativeBundle_IsDebugMode](_bundle.md#oh_nativebundle_isdebugmode) | 获取当前应用是否处于调试模式。|
| [OH_NativeBundle_GetModuleMetadata](_bundle.md#oh_nativebundle_getmodulemetadata) | 获取当前应用的元数据信息。 |