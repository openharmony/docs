# MediaKeyRequestInfo


## 概述

定义MediaKeyRequestInfo，该信息由[IMediaKeySession::GenerateMediaKeyRequest](interface_i_media_key_session.md#generatemediakeyrequest)使用。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [MediaKeyType](_hdi_drm.md#mediakeytype)[mediaKeyType](#mediakeytype) | 许可证类型。  | 
| String [mimeType](#mimetype) | 媒体类型。  | 
| unsigned char[] [initData](#initdata) | 初始信息，从MediaKeySystemInfo中获取。  | 
| Map&lt; String, String &gt; [optionalData](#optionaldata) | 应用自定义数据。  | 


## 类成员变量说明


### initData

```
unsigned char [] MediaKeyRequestInfo::initData
```
**描述**

初始信息，从MediaKeySystemInfo中获取。


### mediaKeyType

```
enum MediaKeyType MediaKeyRequestInfo::mediaKeyType
```
**描述**

许可证类型。


### mimeType

```
String MediaKeyRequestInfo::mimeType
```
**描述**

媒体类型。


### optionalData

```
Map<String, String> MediaKeyRequestInfo::optionalData
```
**描述**

应用自定义数据。
