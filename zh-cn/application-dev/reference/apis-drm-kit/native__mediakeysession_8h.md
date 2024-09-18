# native_mediakeysession.h


## 概述

定义Drm MediaKeySession API。提供以下功能：生成媒体密钥请求、处理媒体密钥响应、事件监听、获取内容保护级别、检查媒体密钥状态、删除媒体密钥等。

**库：** libnative_drm.so

**引用文件：** &lt;multimedia/drm_framework/native_mediakeysession.h&gt;

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [MediaKeySession_Callback](_media_key_session___callback.md) | MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件，不返回媒体密钥会话实例，适用于单媒体密钥会话解密场景。  | 
| struct  [OH_MediaKeySession_Callback](_o_h___media_key_session___callback.md) | OH_MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件，返回媒体密钥会话实例，适用多个媒体密钥会话解密场景。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySession_EventCallback](_drm.md#mediakeysession_eventcallback)) ([DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | MediaKeySession事件触发时将调用的回调。  | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySession_KeyChangeCallback](_drm.md#mediakeysession_keychangecallback)) ([DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | 密钥变换时将调用回调。  | 
| typedef struct [MediaKeySession_Callback](_media_key_session___callback.md) [MediaKeySession_Callback](_drm.md#mediakeysession_callback) | MediaKeySession_Callback结构体，用于监听密钥过期、密钥变换等事件，不返回媒体密钥会话实例，适用于单媒体密钥会话解密场景。  | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [OH_MediaKeySession_EventCallback](_drm.md#oh_mediakeysession_eventcallback)) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | 事件触发时将调用的回调。  | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [OH_MediaKeySession_KeyChangeCallback](_drm.md#oh_mediakeysession_keychangecallback)) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | 密钥变换时将调用的回调。  | 
| typedef struct [OH_MediaKeySession_Callback](_o_h___media_key_session___callback.md) [OH_MediaKeySession_Callback](_drm.md#oh_mediakeysession_callback) | OH_MediaKeySession_Callback结构体，用于监听密钥过期、密钥变换等事件，返回媒体密钥会话实例，适用多个媒体密钥会话解密场景。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_GenerateMediaKeyRequest](_drm.md#oh_mediakeysession_generatemediakeyrequest) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) \*info, [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) \*mediaKeyRequest) | 生成媒体密钥请求。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_ProcessMediaKeyResponse](_drm.md#oh_mediakeysession_processmediakeyresponse) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, uint8_t \*response, int32_t responseLen, uint8_t \*offlineMediaKeyId, int32_t \*offlineMediaKeyIdLen) | 处理媒体密钥请求响应。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_CheckMediaKeyStatus](_drm.md#oh_mediakeysession_checkmediakeystatus) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) \*mediaKeyStatus) | 检查媒体密钥状态。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_ClearMediaKeys](_drm.md#oh_mediakeysession_clearmediakeys) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin) | 清除当前会话的媒体密钥。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_GenerateOfflineReleaseRequest](_drm.md#oh_mediakeysession_generateofflinereleaserequest) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseRequest, int32_t \*releaseRequestLen) | 生成离线媒体密钥释放请求。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_ProcessOfflineReleaseResponse](_drm.md#oh_mediakeysession_processofflinereleaseresponse) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseReponse, int32_t releaseReponseLen) | 处理离线媒体密钥释放请求响应。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_RestoreOfflineMediaKeys](_drm.md#oh_mediakeysession_restoreofflinemediakeys) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | 恢复离线媒体密钥到当前会话。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_GetContentProtectionLevel](_drm.md#oh_mediakeysession_getcontentprotectionlevel) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取会话的内容保护级别。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_RequireSecureDecoderModule](_drm.md#oh_mediakeysession_requiresecuredecodermodule) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, const char \*mimeType, bool \*status) | 是否需要安全解码。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_SetMediaKeySessionCallback](_drm.md#oh_mediakeysession_setmediakeysessioncallback) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [MediaKeySession_Callback](_media_key_session___callback.md) \*callback) | 设置媒体密钥会话事件回调。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_SetCallback](_drm.md#oh_mediakeysession_setcallback) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin, [OH_MediaKeySession_Callback](_o_h___media_key_session___callback.md) \*callback) | 设置媒体密钥会话事件回调。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_Destroy](_drm.md#oh_mediakeysession_destroy) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySessoin) | 销毁MediaKeySession。  | 
