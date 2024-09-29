# IMediaKeySession


## 概述

DRM会话功能接口，获取/设置许可证、查询当前会话许可证状态、删除当前会话许可证、释放许可证、恢复离线许可证、 判断是否需要安全内存中解密、获取解密模块实例、设置会话消息通知接口、销毁会话。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GenerateMediaKeyRequest](#generatemediakeyrequest) ([in] struct [MediaKeyRequestInfo](_media_key_request_info.md) mediaKeyRequestInfo, [out] struct [MediaKeyRequest](_media_key_request.md) mediaKeyRequest) | 产生获取许可证请求。  | 
| [ProcessMediaKeyResponse](#processmediakeyresponse) ([in] unsigned char[] mediaKeyResponse, [out] unsigned char[] mediaKeyId) | 处理许可证响应。  | 
| [CheckMediaKeyStatus](#checkmediakeystatus) ([out] Map&lt; String, String &gt; mediaKeyStatus) | 查询许可证状态（包括策略等信息）。  | 
| [ClearMediaKeys](#clearmediakeys) () | 删除许可证。  | 
| [GetOfflineReleaseRequest](#getofflinereleaserequest) ([in] unsigned char[] mediaKeyId, [out] unsigned char[] releaseRequest) | 产生离线许可证释放请求。  | 
| [ProcessOfflineReleaseResponse](#processofflinereleaseresponse) ([in] unsigned char[] mediaKeyId, [in] unsigned char[] response) | 处理离线许可证释放响应。  | 
| [RestoreOfflineMediaKeys](#restoreofflinemediakeys) ([in] unsigned char[] mediaKeyId) | 恢复离线许可证至当前会话。  | 
| [GetContentProtectionLevel](#getcontentprotectionlevel) ([out] enum [ContentProtectionLevel](_hdi_drm.md#contentprotectionlevel) level) | 获取当前DRM会话的内容保护级别。  | 
| [RequiresSecureDecoderModule](#requiressecuredecodermodule) ([in] String mimeType, [out] boolean required) | 判断是否需要安全内存用于存放解密后的数据。  | 
| [SetCallback](#setcallback) ([in] [IMediaKeySessionCallback](interface_i_media_key_session_callback.md) sessionCallback) | 设置DRM会话事件通知接口。  | 
| [GetMediaDecryptModule](#getmediadecryptmodule) ([out] [IMediaDecryptModule](interface_i_media_decrypt_module.md) decryptModule) | 获取解密模块实例。  | 
| [Destroy](#destroy) () | 销毁DRM会话。  | 


## 成员函数说明


### CheckMediaKeyStatus()

```
IMediaKeySession::CheckMediaKeyStatus ([out] Map< String, String > mediaKeyStatus)
```
**描述**

查询许可证状态（包括策略等信息）。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyStatus | 许可证状态。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### ClearMediaKeys()

```
IMediaKeySession::ClearMediaKeys ()
```
**描述**

删除许可证。

**起始版本：** 4.1

**返回：**

0 表示执行成功。

其他值表示执行失败。


### Destroy()

```
IMediaKeySession::Destroy ()
```
**描述**

销毁DRM会话。

**起始版本：** 4.1

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GenerateMediaKeyRequest()

```
IMediaKeySession::GenerateMediaKeyRequest ([in] struct MediaKeyRequestInfo mediaKeyRequestInfo, [out] struct MediaKeyRequest mediaKeyRequest )
```
**描述**

产生获取许可证请求。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyRequestInfo | 用于产生许可证请求的初始信息。  | 
| mediaKeyRequest | 许可证请求。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetContentProtectionLevel()

```
IMediaKeySession::GetContentProtectionLevel ([out] enum ContentProtectionLevel level)
```
**描述**

获取当前DRM会话的内容保护级别。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 内容保护级别。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetMediaDecryptModule()

```
IMediaKeySession::GetMediaDecryptModule ([out] IMediaDecryptModule decryptModule)
```
**描述**

获取解密模块实例。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| decryptModule | 解密模块实例。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### GetOfflineReleaseRequest()

```
IMediaKeySession::GetOfflineReleaseRequest ([in] unsigned char[] mediaKeyId, [out] unsigned char[] releaseRequest )
```
**描述**

产生离线许可证释放请求。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyId | 离线许可证索引。  | 
| releaseRequest | 离线许可证释放请求。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### ProcessMediaKeyResponse()

```
IMediaKeySession::ProcessMediaKeyResponse ([in] unsigned char[] mediaKeyResponse, [out] unsigned char[] mediaKeyId )
```
**描述**

处理许可证响应。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyResponse | 待处理的许可证响应。  | 
| mediaKeyId | 对于离线许可证类型，表示索引；在线许可证类型下，值为空。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### ProcessOfflineReleaseResponse()

```
IMediaKeySession::ProcessOfflineReleaseResponse ([in] unsigned char[] mediaKeyId, [in] unsigned char[] response )
```
**描述**

处理离线许可证释放响应。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyId | 离线许可证索引。  | 
| response | 离线许可证释放响应。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### RequiresSecureDecoderModule()

```
IMediaKeySession::RequiresSecureDecoderModule ([in] String mimeType, [out] boolean required )
```
**描述**

判断是否需要安全内存用于存放解密后的数据。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mimeType | 待解密内容的MIME类型。  | 
| required | 布尔值表示是否需要安全内存，true表示需要安全内存存储解密后的视频帧， flase表示不需要安全内存存储解密后的视频帧。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### RestoreOfflineMediaKeys()

```
IMediaKeySession::RestoreOfflineMediaKeys ([in] unsigned char[] mediaKeyId)
```
**描述**

恢复离线许可证至当前会话。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeyId | 离线许可证索引。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。


### SetCallback()

```
IMediaKeySession::SetCallback ([in] IMediaKeySessionCallback sessionCallback)
```
**描述**

设置DRM会话事件通知接口。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sessionCallback | DRM实例事件通知接口。 | 

**返回：**

0 表示执行成功。

其他值表示执行失败。
