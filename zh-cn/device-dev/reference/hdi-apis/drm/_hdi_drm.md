# HdiDrm


## 概述

DRM模块接口定义。 DRM是数字版权管理，用于对多媒体内容加密，以便保护价值内容不被非法获取，DRM模块接口定义了DRM实例管理、DRM会话管理、DRM内容解密的接口。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IMediaDecryptModule.idl](_i_media_decrypt_module_8idl.md) | 定义了DRM内容解密接口、解密模块实例释放接口。 | 
| [IMediaKeySession.idl](_i_media_key_session_8idl.md) | 定义了DRM会话功能接口。 | 
| [IMediaKeySessionCallback.idl](_i_media_key_session_callback_8idl.md) | 定义了DRM会话的事件通知接口。 | 
| [IMediaKeySystem.idl](_i_media_key_system_8idl.md) | 定义了DRM实例的功能接口。 | 
| [IMediaKeySystemCallback.idl](_i_media_key_system_callback_8idl.md) | 定义了DRM实例的事件通知接口。 | 
| [IMediaKeySystemFactory.idl](_i_media_key_system_factory_8idl.md) | 定义了DRM实例的工厂方法。 | 
| [IOemCertificate.idl](_i_oem_certificate_8idl.md) | 定义了不同厂商证书下载的接口。 | 
| [MediaKeySystemTypes.idl](_media_key_system_types_8idl.md) | 定义了HdiDrm使用的类型及结构。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IMediaDecryptModule](interface_i_media_decrypt_module.md) | 定义内容解密、解密模块实例释放函数。用于解密加密的内容。 | 
| interface&nbsp;&nbsp;[IMediaKeySession](interface_i_media_key_session.md) | DRM会话功能接口，获取/设置许可证、查询当前会话许可证状态、删除当前会话许可证、释放许可证、恢复离线许可证、 判断是否需要安全内存中解密、获取解密模块实例、设置会话消息通知接口、销毁会话。 | 
| interface&nbsp;&nbsp;[IMediaKeySessionCallback](interface_i_media_key_session_callback.md) | 定义DRM会话的事件通知函数，用于DRM驱动通知DRM框架事件。 | 
| interface&nbsp;&nbsp;[IMediaKeySystem](interface_i_media_key_system.md) | DRM实例功能接口，判断是否支持特定DRM方案，创建DRM实例。 | 
| interface&nbsp;&nbsp;[IMediaKeySystemCallback](interface_i_media_key_system_callback.md) | 定义DRM实例的事件通知函数。 | 
| interface&nbsp;&nbsp;[IMediaKeySystemFactory](interface_i_media_key_system_factory.md) | DRM实例工厂方法接口，判断是否支持特定DRM方案，创建DRM实例。 | 
| interface&nbsp;&nbsp;[IOemCertificate](interface_i_oem_certificate.md) | 厂商证书下载接口。 产生证书下载请求，处理下载的证书。 | 
| struct&nbsp;&nbsp;[MediaKeyRequestInfo](_media_key_request_info.md) | 定义MediaKeyRequestInfo，该信息由[IMediaKeySession::GenerateMediaKeyRequest](interface_i_media_key_session.md#generatemediakeyrequest)使用。 | 
| struct&nbsp;&nbsp;[MediaKeyRequest](_media_key_request.md) | 定义MediaKeyRequest，该信息由[IMediaKeySession::GenerateMediaKeyRequest](interface_i_media_key_session.md#generatemediakeyrequest)使用。 | 
| struct&nbsp;&nbsp;[Pattern](_pattern.md) | 定义Pattern，该信息由CryptoInfo使用。 | 
| struct&nbsp;&nbsp;[SubSample](_sub_sample.md) | 定义SubSample，该信息由CryptoInfo使用。 | 
| struct&nbsp;&nbsp;[CryptoInfo](_crypto_info.md) | 定义CryptoInfo，该信息由[IMediaDecryptModule::DecryptMediaData](interface_i_media_decrypt_module.md#decryptmediadata)使用。 | 
| struct&nbsp;&nbsp;[DrmBuffer](_drm_buffer.md) | 定义DrmBuffer，该信息由[IMediaDecryptModule::DecryptMediaData](interface_i_media_decrypt_module.md#decryptmediadata)使用。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ContentProtectionLevel](#contentprotectionlevel) {<br/>SECURE_UNKNOWN = 0 , SW_SECURE_CRYPTO , HW_SECURE_CRYPTO , HW_ENHANCED_SECURE_CRYPTO , HW_SECURE_MAX<br/>} | 内容保护等级。 | 
| [MediaKeyRequestType](#mediakeyrequesttype) {<br/>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0 , MEDIA_KEY_REQUEST_TYPE_INITIAL , MEDIA_KEY_REQUEST_TYPE_RENEWAL , MEDIA_KEY_REQUEST_TYPE_RELEASE , MEDIA_KEY_REQUEST_TYPE_NONE , MEDIA_KEY_REQUEST_TYPE_UPDATE<br/>} | 许可证请求类型。 | 
| [EventType](#eventtype) {<br/>EVENTTYPE_PROVISIONREQUIRED = 0 , EVENTTYPE_KEYREQUIRED , EVENTTYPE_KEYEXPIRED , EVENTTYPE_VENDOR_DEFINED , EVENTTYPE_EXPIRATIONUPDATE , EVENTTYPE_KEYCHANGE<br/>} | DRM插件监听事件类型。 | 
| [CryptoAlgorithmType](#cryptoalgorithmtype) {<br/>ALGTYPE_UNENCRYPTED = 0 , ALGTYPE_AES_CTR , ALGTYPE_AES_WV , ALGTYPE_AES_CBC , ALGTYPE_SM4_CBC , ALGTYPE_SM4_CTR<br/>} | 加密算法类型。 | 
| [OfflineMediaKeyStatus](#offlinemediakeystatus) { OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0 , OFFLINE_MEDIA_KEY_STATUS_USABLE , OFFLINE_MEDIA_KEY_STATUS_INACTIVE } | 离线许可证状态。 | 
| [MediaKeyType](#mediakeytype) { MEDIA_KEY_TYPE_OFFLINE = 0 , MEDIA_KEY_TYPE_ONLINE } | 许可证类型。 | 
| [CertificateStatus](#certificatestatus) {<br/>CERT_STATUS_PROVISIONED = 0 , CERT_STATUS_NOT_PROVISIONED , CERT_STATUS_EXPIRED , CERT_STATUS_INVALID , CERT_STATUS_UNAVAILABLE<br/>} | 证书状态。 | 
| [MediaKeySessionKeyStatus](#mediakeysessionkeystatus) {<br/>MEDIA_KEY_SESSION_KEY_STATUS_USABLE = 0 , MEDIA_KEY_SESSION_KEY_STATUS_EXPIRED , MEDIA_KEY_SESSION_KEY_STATUS_OUTPUT_NOT_ALLOWED , MEDIA_KEY_SESSION_KEY_STATUS_PENDING , MEDIA_KEY_SESSION_KEY_STATUS_INTERNAL_ERROR , MEDIA_KEY_SESSION_KEY_STATUS_USABLE_IN_FUTURE<br/>} | 会话许可证状态。 | 


## 枚举类型说明


### CertificateStatus

```
enum CertificateStatus
```

**描述**


证书状态。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CERT_STATUS_PROVISIONED | 证书已设置。 | 
| CERT_STATUS_NOT_PROVISIONED | 证书未设置。 | 
| CERT_STATUS_EXPIRED | 证书过期。 | 
| CERT_STATUS_INVALID | 证书无效。 | 
| CERT_STATUS_UNAVAILABLE | 获取证书状态失败。 | 


### ContentProtectionLevel

```
enum ContentProtectionLevel
```

**描述**


内容保护等级。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| SECURE_UNKNOWN | 未知等级。 | 
| SW_SECURE_CRYPTO | 软件安全等级。 | 
| HW_SECURE_CRYPTO | 硬件安全等级。 | 
| HW_ENHANCED_SECURE_CRYPTO | 增强硬件安全等级。 | 
| HW_SECURE_MAX | 安全等级最大值，用于判断非法安全等级。 | 


### CryptoAlgorithmType

```
enum CryptoAlgorithmType
```

**描述**


加密算法类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| ALGTYPE_UNENCRYPTED | 未加密。 | 
| ALGTYPE_AES_CTR | aes_ctr加密。 | 
| ALGTYPE_AES_WV | aes_wv加密。 | 
| ALGTYPE_AES_CBC | aes_cbc加密。 | 
| ALGTYPE_SM4_CBC | sm4_cbc加密。 | 
| ALGTYPE_SM4_CTR | sm4_ctr加密。 | 


### EventType

```
enum EventType
```

**描述**


DRM插件监听事件类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| EVENTTYPE_PROVISIONREQUIRED | 证书下载。 | 
| EVENTTYPE_KEYREQUIRED | 许可证获取。 | 
| EVENTTYPE_KEYEXPIRED | 许可证过期。 | 
| EVENTTYPE_VENDOR_DEFINED | 厂商自定义事件。 | 
| EVENTTYPE_EXPIRATIONUPDATE | 许可证有效期更新。 | 
| EVENTTYPE_KEYCHANGE | 许可证变更。 | 


### MediaKeyRequestType

```
enum MediaKeyRequestType
```

**描述**


许可证请求类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN | 未知类型。 | 
| MEDIA_KEY_REQUEST_TYPE_INITIAL | 初次请求。 | 
| MEDIA_KEY_REQUEST_TYPE_RENEWAL | 再次许可证请求。 | 
| MEDIA_KEY_REQUEST_TYPE_RELEASE | 释放许可证请求。 | 
| MEDIA_KEY_REQUEST_TYPE_NONE | 无类型。 | 
| MEDIA_KEY_REQUEST_TYPE_UPDATE | 许可证更新请求。 | 


### MediaKeySessionKeyStatus

```
enum MediaKeySessionKeyStatus
```

**描述**


会话许可证状态。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_KEY_SESSION_KEY_STATUS_USABLE | 许可证可用。 | 
| MEDIA_KEY_SESSION_KEY_STATUS_EXPIRED | 许可证过期。 | 
| MEDIA_KEY_SESSION_KEY_STATUS_OUTPUT_NOT_ALLOWED | 该许可证不允许输出。 | 
| MEDIA_KEY_SESSION_KEY_STATUS_PENDING | 暂时不可用许可证。 | 
| MEDIA_KEY_SESSION_KEY_STATUS_INTERNAL_ERROR | 许可证内部状态错误。 | 
| MEDIA_KEY_SESSION_KEY_STATUS_USABLE_IN_FUTURE | 许可证待生效。 | 


### MediaKeyType

```
enum MediaKeyType
```

**描述**


许可证类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_KEY_TYPE_OFFLINE | 离线许可证。 | 
| MEDIA_KEY_TYPE_ONLINE | 在线许可证。 | 


### OfflineMediaKeyStatus

```
enum OfflineMediaKeyStatus
```

**描述**


离线许可证状态。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN | 未知状态。 | 
| OFFLINE_MEDIA_KEY_STATUS_USABLE | 许可证可用。 | 
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE | 许可证不可用（未在生效时间段内、已过期等）。 | 
