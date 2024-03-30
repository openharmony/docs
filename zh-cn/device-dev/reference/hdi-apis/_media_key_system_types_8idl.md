# MediaKeySystemTypes.idl


## 概述

定义了HdiDrm使用的类型及结构。

模块包路径：ohos.hdi.drm.v1_0

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[MediaKeyRequestInfo](_media_key_request_info.md) | 定义MediaKeyRequestInfo，该信息由[IMediaKeySession::GenerateMediaKeyRequest](interface_i_media_key_session.md#generatemediakeyrequest)使用。 | 
| struct&nbsp;&nbsp;[MediaKeyRequest](_media_key_request.md) | 定义MediaKeyRequest，该信息由[IMediaKeySession::GenerateMediaKeyRequest](interface_i_media_key_session.md#generatemediakeyrequest)使用。 | 
| struct&nbsp;&nbsp;[Pattern](_pattern.md) | 定义Pattern，该信息由CryptoInfo使用。 | 
| struct&nbsp;&nbsp;[SubSample](_sub_sample.md) | 定义SubSample，该信息由CryptoInfo使用。 | 
| struct&nbsp;&nbsp;[CryptoInfo](_crypto_info.md) | 定义CryptoInfo，该信息由[IMediaDecryptModule::DecryptMediaData](interface_i_media_decrypt_module.md#decryptmediadata)使用。 | 
| struct&nbsp;&nbsp;[DrmBuffer](_drm_buffer.md) | 定义DrmBuffer，该信息由[IMediaDecryptModule::DecryptMediaData](interface_i_media_decrypt_module.md#decryptmediadata)使用。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ContentProtectionLevel](_hdi_drm.md#contentprotectionlevel) {<br/>SECURE_UNKNOWN = 0 , SW_SECURE_CRYPTO , HW_SECURE_CRYPTO , HW_ENHANCED_SECURE_CRYPTO , HW_SECURE_MAX<br/>} | 内容保护等级。 | 
| [MediaKeyRequestType](_hdi_drm.md#mediakeyrequesttype) {<br/>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0 , MEDIA_KEY_REQUEST_TYPE_INITIAL , MEDIA_KEY_REQUEST_TYPE_RENEWAL , MEDIA_KEY_REQUEST_TYPE_RELEASE , MEDIA_KEY_REQUEST_TYPE_NONE , MEDIA_KEY_REQUEST_TYPE_UPDATE<br/>} | 许可证请求类型。 | 
| [EventType](_hdi_drm.md#eventtype) {<br/>EVENTTYPE_PROVISIONREQUIRED = 0 , EVENTTYPE_KEYREQUIRED , EVENTTYPE_KEYEXPIRED , EVENTTYPE_VENDOR_DEFINED , EVENTTYPE_EXPIRATIONUPDATE , EVENTTYPE_KEYCHANGE<br/>} | DRM插件监听事件类型。 | 
| [CryptoAlgorithmType](_hdi_drm.md#cryptoalgorithmtype) {<br/>ALGTYPE_UNENCRYPTED = 0 , ALGTYPE_AES_CTR , ALGTYPE_AES_WV , ALGTYPE_AES_CBC , ALGTYPE_SM4_CBC , ALGTYPE_SM4_CTR<br/>} | 加密算法类型。 | 
| [OfflineMediaKeyStatus](_hdi_drm.md#offlinemediakeystatus) { OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0 , OFFLINE_MEDIA_KEY_STATUS_USABLE , OFFLINE_MEDIA_KEY_STATUS_INACTIVE } | 离线许可证状态。 | 
| [MediaKeyType](_hdi_drm.md#mediakeytype) { MEDIA_KEY_TYPE_OFFLINE = 0 , MEDIA_KEY_TYPE_ONLINE } | 许可证类型。 | 
| [CertificateStatus](_hdi_drm.md#certificatestatus) {<br/>CERT_STATUS_PROVISIONED = 0 , CERT_STATUS_NOT_PROVISIONED , CERT_STATUS_EXPIRED , CERT_STATUS_INVALID , CERT_STATUS_UNAVAILABLE<br/>} | 证书状态。 | 
| [MediaKeySessionKeyStatus](_hdi_drm.md#mediakeysessionkeystatus) {<br/>MEDIA_KEY_SESSION_KEY_STATUS_USABLE = 0 , MEDIA_KEY_SESSION_KEY_STATUS_EXPIRED , MEDIA_KEY_SESSION_KEY_STATUS_OUTPUT_NOT_ALLOWED , MEDIA_KEY_SESSION_KEY_STATUS_PENDING , MEDIA_KEY_SESSION_KEY_STATUS_INTERNAL_ERROR , MEDIA_KEY_SESSION_KEY_STATUS_USABLE_IN_FUTURE<br/>} | 会话许可证状态。 | 
