# native_mediakeysystem.h


## 概述

定义Drm MediaKeySystem API。提供以下功能： 查询是否支持特定的drm，创建媒体密钥会话，获取和设置配置， 获取统计信息，获取内容保护级别，生成提供请求，处理提供响应， 事件监听，获取内容防护级别，管理离线媒体密钥等。

**库：** libnative_drm.z.so

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback)) ([DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | 事件触发时将调用的回调。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| bool [OH_MediaKeySystem_IsSupported](_drm.md#oh_mediakeysystem_issupported) (const char \*name) | 查询是否支持媒体密钥系统。  | 
| bool [OH_MediaKeySystem_IsSupported2](_drm.md#oh_mediakeysystem_issupported2) (const char \*name, const char \*mimeType) | 查询是否支持媒体密钥系统。  | 
| bool [OH_MediaKeySystem_IsSupported3](_drm.md#oh_mediakeysystem_issupported3) (const char \*name, const char \*mimeType, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) contentProtectionLevel) | 查询是否支持媒体密钥系统。  | 
| Drm_ErrCode [OH_MediaKeySystem_GetMediaKeySystems](_drm.md#oh_mediakeysystem_getmediakeysystems) ([DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) \*infos, uint32_t \*count) | 获取支持的媒体密钥系统的名称和uuid。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_Create](_drm.md#oh_mediakeysystem_create) (const char \*name, [MediaKeySystem](_drm.md#mediakeysystem) \*\*mediaKeySystem) | 根据名称创建媒体密钥系统实例。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetConfigurationString](_drm.md#oh_mediakeysystem_setconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, const char \*value) | 按名称设置媒体密钥系统配置值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetConfigurationString](_drm.md#oh_mediakeysystem_getconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, char \*value, int32_t valueLen) | 按名称获取媒体密钥系统配置值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetConfigurationByteArray](_drm.md#oh_mediakeysystem_setconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t valueLen) | 通过配置名设置MediaKeySystem的配置值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetConfigurationByteArray](_drm.md#oh_mediakeysystem_getconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t \*valueLen) | 按名称获取媒体密钥系统配置值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetStatistics](_drm.md#oh_mediakeysystem_getstatistics) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_Statistics](_d_r_m___statistics.md) \*statistics) | 获取媒体密钥系统度量信息。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetMaxContentProtectionLevel](_drm.md#oh_mediakeysystem_getmaxcontentprotectionlevel) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取支持的最高内容保护级别的媒体密钥系统。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetMediaKeySystemCallback](_drm.md#oh_mediakeysystem_setmediakeysystemcallback) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback) callback) | 设置媒体密钥系统事件回调。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_CreateMediaKeySession](_drm.md#oh_mediakeysystem_createmediakeysession) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*level, [MediaKeySession](_drm.md#mediakeysession) \*\*mediaKeySession) | 创建媒体密钥会话实例。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GenerateKeySystemRequest](_drm.md#oh_mediakeysystem_generatekeysystemrequest) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*request, int32_t \*requestLen, char \*defaultUrl, int32_t defaultUrlLen) | 生成媒体密钥系统提供请求。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_ProcessKeySystemResponse](_drm.md#oh_mediakeysystem_processkeysystemresponse) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*response, int32_t responseLen) | 处理媒体密钥系统提供响应。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyIds](_drm.md#oh_mediakeysystem_getofflinemediakeyids) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) \*offlineMediaKeyIds) | 获取离线媒体密钥ID。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyStatus](_drm.md#oh_mediakeysystem_getofflinemediakeystatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus) \*status) | 获取离线密钥状态。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_ClearOfflineMediaKeys](_drm.md#oh_mediakeysystem_clearofflinemediakeys) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | 按id清除离线媒体密钥。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetCertificateStatus](_drm.md#oh_mediakeysystem_getcertificatestatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_CertificateStatus](_drm.md#drm_certificatestatus) \*certStatus) | 获取媒体密钥系统的证书状态。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_Destroy](_drm.md#oh_mediakeysystem_destroy) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem) | Destroy a 媒体密钥系统实例。  | 
