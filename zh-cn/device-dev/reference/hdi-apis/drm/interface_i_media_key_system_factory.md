# IMediaKeySystemFactory


## 概述

DRM实例工厂方法接口，判断是否支持特定DRM方案，创建DRM实例。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [IsMediaKeySystemSupported](#ismediakeysystemsupported) ([in] String name, [in] String mimeType, [in] enum [ContentProtectionLevel](_hdi_drm.md#contentprotectionlevel) level, [out] boolean isSupported) | 判断是否支持特定DRM方案。  | 
| [CreateMediaKeySystem](#createmediakeysystem) ([out] [IMediaKeySystem](interface_i_media_key_system.md) mediaKeySystem) | 创建DRM实例。  | 


## 成员函数说明


### CreateMediaKeySystem()

```
IMediaKeySystemFactory::CreateMediaKeySystem ([out] IMediaKeySystem mediaKeySystem)
```
**描述**

创建DRM实例。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | DRM实例。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### IsMediaKeySystemSupported()

```
IMediaKeySystemFactory::IsMediaKeySystemSupported ([in] String name, [in] String mimeType, [in] enum ContentProtectionLevel level, [out] boolean isSupported )
```
**描述**

判断是否支持特定DRM方案。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | DRM方案名。  | 
| mimeType | 数字内容的MIME类型。  | 
| level | 内容保护等级。  | 
| isSupported | 是否支持特定DRM方案，true表示支持，false表示失败。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。
