# bundle


## 概述

包管理（bundle）模块支持查询应用自身的相关信息。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**起始版本：** 9


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_interface_bundle.h](native__interface__bundle.md) | 提供应用信息数据结构和函数。<br/>**引用文件**：&lt;bundle/native_interface_bundle.h&gt;<br/>**库**：libbundle_ndk.z.so |


### 结构体定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBundle_ApplicationInfo](_o_h___native_bundle_application_info.md) | 表示应用信息。 |
| [OH_NativeBundle_ElementName](_o_h___native_bundle_element_name.md) | 表示应用入口的信息。 |



### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBundle_GetCurrentApplicationInfo](#oh_nativebundle_getcurrentapplicationinfo) | 获取当前应用的信息。 |
| [OH_NativeBundle_GetAppId](#oh_nativebundle_getappid) | 获取当前应用的appId信息。 |
| [OH_NativeBundle_GetAppIdentifier](#oh_nativebundle_getappidentifier) | 获取当前应用的appIdentifier信息。 |
| [OH_NativeBundle_GetMainElementName](#oh_nativebundle_getmainelementname) | 获取当前应用的入口信息。 |
| [OH_NativeBundle_GetCompatibleDeviceType](_bundle.md#oh_nativebundle_getcompatibledevicetype) | 获取当前应用适用的设备类型。 |


## 函数说明


### OH_NativeBundle_GetCurrentApplicationInfo()

```
OH_NativeBundle_ApplicationInfo OH_NativeBundle_GetCurrentApplicationInfo()
```

**描述**

获取自身应用的相关信息。

**起始版本：** 9

**返回：**

返回一个[OH_NativeBundle_ApplicationInfo](_o_h___native_bundle_application_info.md)结构体。

### OH_NativeBundle_GetAppId()

```
char* OH_NativeBundle_GetAppId()
```

**描述**

获取自身应用的appId信息。

**起始版本：** 11

**返回：**

返回一个字符串，包含该应用的appId信息。

### OH_NativeBundle_GetAppIdentifier()

```
char* OH_NativeBundle_GetAppIdentifier()
```

**描述**

获取自身应用的appIdentifier信息。appIdentifier指应用的唯一标识，是云端统一分配的随机字符串。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。

**起始版本：** 11

**返回：**

返回一个字符串，包含该应用的appIdentifier信息。

### OH_NativeBundle_GetMainElementName()

```
OH_NativeBundle_ElementName OH_NativeBundle_GetMainElementName()
```

**描述**

获取自身应用入口的信息。包含bundleName、moduleName和abilityName信息。

**起始版本：** 13

**返回：**

返回一个[OH_NativeBundle_ElementName](_o_h___native_bundle_element_name.md)结构体。

### OH_NativeBundle_GetCompatibleDeviceType()

```
char* OH_NativeBundle_GetCompatibleDeviceType()
```

**描述**

获取当前应用适用的设备类型。用于将手机应用分发到平板/2in1设备时，合理适配布局和字体大小。

**起始版本：** 14

**返回：**

返回一个字符串，表示该应用适用的设备类型。
