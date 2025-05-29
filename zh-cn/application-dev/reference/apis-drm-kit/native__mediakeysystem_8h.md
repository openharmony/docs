# native_mediakeysystem.h


## 概述

定义Drm MediaKeySystem API。提供以下功能：查询是否支持指定的DRM解决方案，创建媒体密钥会话，获取和设置DRM配置属性，获取设备DRM度量信息，查询内容保护级别，生成设备DRM证书请求，处理设备DRM证书请求响应，事件监听，管理离线媒体密钥等。

**库：** libnative_drm.so

**引用文件：** &lt;multimedia/drm_framework/native_mediakeysystem.h&gt;

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback)) ([DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | 事件触发时将调用的回调，不返回媒体密钥系统实例，适用于单个媒体密钥系统场景。  | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [OH_MediaKeySystem_Callback](_drm.md#oh_mediakeysystem_callback)) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | 事件触发时将调用的回调，返回媒体密钥系统实例，适用于多个媒体密钥系统场景。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetCallback](_drm.md#oh_mediakeysystem_setcallback) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [OH_MediaKeySystem_Callback](_drm.md#oh_mediakeysystem_callback) callback) | 设置MediaKeySystem事件回调。  | 
| bool [OH_MediaKeySystem_IsSupported](_drm.md#oh_mediakeysystem_issupported) (const char \*name) | 判断设备是否支持指定的DRM解决方案。  | 
| bool [OH_MediaKeySystem_IsSupported2](_drm.md#oh_mediakeysystem_issupported2) (const char \*name, const char \*mimeType) | 判断设备是否支持指定DRM解决方案及媒体类型。  | 
| bool [OH_MediaKeySystem_IsSupported3](_drm.md#oh_mediakeysystem_issupported3) (const char \*name, const char \*mimeType, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) contentProtectionLevel) | 判断设备是否支持指定DRM解决方案、媒体类型以及内容保护级别。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetMediaKeySystems](_drm.md#oh_mediakeysystem_getmediakeysystems) ([DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) \*infos, uint32_t \*count) | 获取设备支持的DRM解决方案的名称和唯一标识列表。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_Create](_drm.md#oh_mediakeysystem_create) (const char \*name, [MediaKeySystem](_drm.md#mediakeysystem) \*\*mediaKeySystem) | 根据DRM解决方案名称创建MediaKeySystem实例。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetConfigurationString](_drm.md#oh_mediakeysystem_setconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, const char \*value) | 设置字符串类型配置属性值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetConfigurationString](_drm.md#oh_mediakeysystem_getconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, char \*value, int32_t valueLen) | 获取字符串类型配置属性值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetConfigurationByteArray](_drm.md#oh_mediakeysystem_setconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t valueLen) | 设置字符数组类型配置属性值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetConfigurationByteArray](_drm.md#oh_mediakeysystem_getconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t \*valueLen) | 获取字符数组类型配置属性值。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetStatistics](_drm.md#oh_mediakeysystem_getstatistics) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_Statistics](_d_r_m___statistics.md) \*statistics) | 获取媒体密钥系统度量信息。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetMaxContentProtectionLevel](_drm.md#oh_mediakeysystem_getmaxcontentprotectionlevel) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取当前DRM解决方案支持的最大内容保护级别。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetMediaKeySystemCallback](_drm.md#oh_mediakeysystem_setmediakeysystemcallback) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback) callback) | 设置MediaKeySystem事件回调。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_CreateMediaKeySession](_drm.md#oh_mediakeysystem_createmediakeysession) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*level, [MediaKeySession](_drm.md#mediakeysession) \*\*mediaKeySession) | 创建MediaKeySession实例。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GenerateKeySystemRequest](_drm.md#oh_mediakeysystem_generatekeysystemrequest) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*request, int32_t \*requestLen, char \*defaultUrl, int32_t defaultUrlLen) | 生成设备DRM证书请求。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_ProcessKeySystemResponse](_drm.md#oh_mediakeysystem_processkeysystemresponse) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*response, int32_t responseLen) | 处理设备DRM证书请求响应。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyIds](_drm.md#oh_mediakeysystem_getofflinemediakeyids) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) \*offlineMediaKeyIds) | 获取离线媒体密钥标识。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyStatus](_drm.md#oh_mediakeysystem_getofflinemediakeystatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus) \*status) | 获取离线媒体密钥状态。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_ClearOfflineMediaKeys](_drm.md#oh_mediakeysystem_clearofflinemediakeys) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | 清除离线媒体密钥。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetCertificateStatus](_drm.md#oh_mediakeysystem_getcertificatestatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_CertificateStatus](_drm.md#drm_certificatestatus) \*certStatus) | 获取设备DRM证书状态。  | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_Destroy](_drm.md#oh_mediakeysystem_destroy) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem) | 销毁MediaKeySystem实例。  | 
