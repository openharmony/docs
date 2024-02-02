# native_mediakeysession.h


## 概述

定义Drm MediaKeySession API。提供以下功能： 生成媒体密钥请求、处理媒体密钥响应、事件侦听、获取内容保护级别、 检查媒体密钥状态、删除媒体密钥等。

**库：** libnative_drm.z.so

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[MediaKeySession_Callback](_media_key_session___callback.md) | MediaKeySession回调结构体, 用来监听密钥过期、密钥变化等事件。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySession_EventCallback](_drm.md#mediakeysession_eventcallback)) ([DRM_ListenerType](_drm.md#drm_listenertype) eventType, [DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md) \*eventInfo) | 事件触发时将调用的回调。 | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySession_KeyChangeCallback](_drm.md#mediakeysession_keychangecallback)) ([DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | 注册监听，监听密钥变化。 | 
| typedef struct [MediaKeySession_Callback](_media_key_session___callback.md)[MediaKeySession_Callback](_drm.md#mediakeysession_callback) | MediaKeySession回调结构体, 用来监听密钥过期、密钥变化等事件。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_GenerateMediaKeyRequest](_drm.md#oh_mediakeysession_generatemediakeyrequest) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) \*info, [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) \*\*mediaKeyRequest) | 生成许可证请求。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_ProcessMediaKeyResponse](_drm.md#oh_mediakeysession_processmediakeyresponse) ([MediaKeySession](_drm.md#mediakeysession) \*keySession, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*response, unsigned char \*\*mediaKeyId, int32_t \*mediaKeyIdLen) | 处理许可证响应。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_CheckMediaKeyStatus](_drm.md#oh_mediakeysession_checkmediakeystatus) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_MediaKeyDescription](_d_r_m___media_key_description.md) \*\*mediaKeyDescription) | 检查许可证状态. | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_ClearMediaKeys](_drm.md#oh_mediakeysession_clearmediakeys) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin) | 清除当前会话的许可证 . | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_GenerateOfflineReleaseRequest](_drm.md#oh_mediakeysession_generateofflinereleaserequest) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId, unsigned char \*\*releaseRequest, int32_t \*releaseRequestLen) | 生成离线许可证释放请求。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_ProcessOfflineReleaseResponse](_drm.md#oh_mediakeysession_processofflinereleaseresponse) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*releaseReponse) | 处理离线许可证释放响应。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_RestoreOfflineMediaKeys](_drm.md#oh_mediakeysession_restoreofflinemediakeys) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId) | 根据许可证ID恢复对应许可证状态。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_GetContentProtectionLevel](_drm.md#oh_mediakeysession_getcontentprotectionlevel) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取当前会话的内容保护级别。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_RequireSecureDecoderModule](_drm.md#oh_mediakeysession_requiresecuredecodermodule) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, const char \*mimeType, bool \*status) | 查询是否需要安全解码. | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_SetMediaKeySessionCallback](_drm.md#oh_mediakeysession_setmediakeysessioncallback) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [MediaKeySession_Callback](_media_key_session___callback.md) \*callback) | 设置MediaKeySession事件回调。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySession_Destroy](_drm.md#oh_mediakeysession_destroy) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin) | MediaKeySession资源销毁. | 
