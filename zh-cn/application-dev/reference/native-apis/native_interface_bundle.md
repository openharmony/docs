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
| [OH_NativeBundle_ApplicationInfo](_o_h___native_bundle_application_info.md) | 提供应用相关信息 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeBundle_GetCurrentApplicationInfo()](#oh_nativebundle_getcurrentapplicationinfo)| 获取应用自身相关包信息。 |


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