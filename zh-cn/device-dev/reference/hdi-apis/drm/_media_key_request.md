# MediaKeyRequest


## 概述

定义MediaKeyRequest，该信息由[IMediaKeySession::GenerateMediaKeyRequest](interface_i_media_key_session.md#generatemediakeyrequest)使用。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [MediaKeyRequestType](_hdi_drm.md#mediakeyrequesttype)[requestType](#requesttype) | 许可证请求的类型。  | 
| unsigned char[] [data](#data) | 许可证请求。  | 
| String [defaultUrl](#defaulturl) | 许可证服务器URL。  | 


## 类成员变量说明


### data

```
unsigned char [] MediaKeyRequest::data
```
**描述**

许可证请求。


### defaultUrl

```
String MediaKeyRequest::defaultUrl
```
**描述**

许可证服务器URL。


### requestType

```
enum MediaKeyRequestType MediaKeyRequest::requestType
```
**描述**

许可证请求的类型。
