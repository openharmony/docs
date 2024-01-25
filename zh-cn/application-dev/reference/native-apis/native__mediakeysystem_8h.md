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
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback)) ([DRM_ListenerType](_drm.md#drm_listenertype) eventType, [DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md) \*eventInfo) | 事件触发时将调用的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetMediaKeySystemName](_drm.md#oh_mediakeysystem_getmediakeysystemname) (const char \*uuid, unsigned char \*\*name, int32_t \*nameLen) | 通过MediaKeySystem方案唯一编号获取MediaKeySystem方案名。 | 
| bool [OH_MediaKeySystem_IsSupported](_drm.md#oh_mediakeysystem_issupported) (const char \*name) | 查询设备是否支持指定MediaKeySystem方案。 | 
| bool [OH_MediaKeySystem_IsSupported2](_drm.md#oh_mediakeysystem_issupported2) (const char \*name, const char \*mimeType) | 查询设备是否支持指定MediaKeySystem方案、指定媒体类型。 | 
| bool [OH_MediaKeySystem_IsSupported3](_drm.md#oh_mediakeysystem_issupported3) (const char \*name, const char \*mimeType, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) contentProtectionLevel) | 查询设备是否支持指定MediaKeySystem方案、指定媒体类型、指定内容保护级别。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_Create](_drm.md#oh_mediakeysystem_create) (const char \*name, [MediaKeySystem](_drm.md#mediakeysystem) \*\*mediaKeySystem) | 根据方案名创建一个MediaKeySystem实例。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_SetConfigurationString](_drm.md#oh_mediakeysystem_setconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, const char \*value) | 通过配置名设置MediaKeySystem的字符串类型配置值。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetConfigurationString](_drm.md#oh_mediakeysystem_getconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, char \*\*value, int32_t \*valueLen) | 通过配置名获取MediaKeySystem的字符串类型配置值。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_SetConfigurationByteArray](_drm.md#oh_mediakeysystem_setconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*value) | 通过配置名设置MediaKeySystem的字符数组类型配置值。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetConfigurationByteArray](_drm.md#oh_mediakeysystem_getconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, unsigned char \*\*value, int32_t \*valueLen) | 通过配置名获取MediaKeySystem的字符数组类型配置值。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetStatistics](_drm.md#oh_mediakeysystem_getstatistics) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_Statistics](_d_r_m___statistics.md) \*\*statistics) | 获取MediaKeySystem的度量统计信息。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetMaxContentProtectionLevel](_drm.md#oh_mediakeysystem_getmaxcontentprotectionlevel) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取MediaKeySystem支持的最大内容保护级别。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_SetMediaKeySystemCallback](_drm.md#oh_mediakeysystem_setmediakeysystemcallback) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback) callback) | 设置MediaKeySystem回调监听。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_CreateMediaKeySession](_drm.md#oh_mediakeysystem_createmediakeysession) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*level, [MediaKeySession](_drm.md#mediakeysession) \*\*mediaKeySession) | 创建一个MediaKeySession实例。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GenerateKeySystemRequest](_drm.md#oh_mediakeysystem_generatekeysystemrequest) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, unsigned char \*\*request, int32_t \*requestLen, char \*\*defaultUrl, int32_t \*defaultUrlLen) | 生成设备证书请求。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_ProcessKeySystemResponse](_drm.md#oh_mediakeysystem_processkeysystemresponse) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*response) | 处理设备证书响应。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetOfflineMediaKeyIds](_drm.md#oh_mediakeysystem_getofflinemediakeyids) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_MediakeyIdArray](_d_r_m___mediakey_id_array.md) \*\*mediaKeyIds) | 获取离线许可证状态。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetOfflineMediaKeyStatus](_drm.md#oh_mediakeysystem_getofflinemediakeystatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId, [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus) \*status) | 获取离线许可证状态。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_ClearOfflineMediaKeys](_drm.md#oh_mediakeysystem_clearofflinemediakeys) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId) | 根据许可证Id清理许可证。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_GetCertificateStatus](_drm.md#oh_mediakeysystem_getcertificatestatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_CertificateStatus](_drm.md#drm_certificatestatus) \*certStatus) | 获取设备证书状态。 | 
| [Drm_ErrCode](_drm.md#drm_errcode)[OH_MediaKeySystem_Destroy](_drm.md#oh_mediakeysystem_destroy) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem) | 销毁MediaKeySystem实例。 | 
