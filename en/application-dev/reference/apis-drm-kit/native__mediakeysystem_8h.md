# native_mediakeysystem.h


## Overview

The **native_mediakeysystem.h** file declares the **MediaKeySystem** API. The APIs can be used to check whether a specific DRM scheme is supported, create a media key session, obtain and set DRM configurations, obtain device-specific DRM statistics information, obtain the content protection level, generate provision requests, process responses to these requests, listen for events, and manage offline media keys.

**Library**: libnative_drm.so

**File to include**: &lt;multimedia/drm_framework/native_mediakeysystem.h&gt;

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback)) ([DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | Defines the callback that is invoked when a DRM event is triggered. It does not return media key system instances and applies to the scenario where a single media key system is used. | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [OH_MediaKeySystem_Callback](_drm.md#oh_mediakeysystem_callback)) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | Defines the callback that is invoked when a DRM event is triggered. It returns media key system instances and applies to the scenario with where media key systems are used. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetCallback](_drm.md#oh_mediakeysystem_setcallback) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [OH_MediaKeySystem_Callback](_drm.md#oh_mediakeysystem_callback) callback) | Sets a media key system event callback. | 
| bool [OH_MediaKeySystem_IsSupported](_drm.md#oh_mediakeysystem_issupported) (const char \*name) | Checks whether the device supports the specified DRM scheme. | 
| bool [OH_MediaKeySystem_IsSupported2](_drm.md#oh_mediakeysystem_issupported2) (const char \*name, const char \*mimeType) | Checks whether the device supports the combination of the DRM scheme and MIME type. | 
| bool [OH_MediaKeySystem_IsSupported3](_drm.md#oh_mediakeysystem_issupported3) (const char \*name, const char \*mimeType, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) contentProtectionLevel) | Checks whether the device supports the combination of the DRM scheme, MIME type, and content protection level. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetMediaKeySystems](_drm.md#oh_mediakeysystem_getmediakeysystems) ([DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) \*infos, uint32_t \*count) | Obtains the names and UUIDs of the DRM schemes supported by the device. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_Create](_drm.md#oh_mediakeysystem_create) (const char \*name, [MediaKeySystem](_drm.md#mediakeysystem) \*\*mediaKeySystem) | Creates a **MediaKeySystem** instance based on the DRM scheme name. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetConfigurationString](_drm.md#oh_mediakeysystem_setconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, const char \*value) | Sets a configuration item in the form of a string. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetConfigurationString](_drm.md#oh_mediakeysystem_getconfigurationstring) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, char \*value, int32_t valueLen) | Obtains the value of a configuration item in the form of a string. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetConfigurationByteArray](_drm.md#oh_mediakeysystem_setconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t valueLen) | Sets a configuration item in the form of an array. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetConfigurationByteArray](_drm.md#oh_mediakeysystem_getconfigurationbytearray) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t \*valueLen) | Obtains the value of a configuration item in the form of an array. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetStatistics](_drm.md#oh_mediakeysystem_getstatistics) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_Statistics](_d_r_m___statistics.md) \*statistics) | Obtains the statistics information about a media key system. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetMaxContentProtectionLevel](_drm.md#oh_mediakeysystem_getmaxcontentprotectionlevel) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*contentProtectionLevel) | Obtains the maximum content protection level supported by the current DRM scheme. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_SetMediaKeySystemCallback](_drm.md#oh_mediakeysystem_setmediakeysystemcallback) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [MediaKeySystem_Callback](_drm.md#mediakeysystem_callback) callback) | Sets a media key system event callback. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_CreateMediaKeySession](_drm.md#oh_mediakeysystem_createmediakeysession) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*level, [MediaKeySession](_drm.md#mediakeysession) \*\*mediaKeySession) | Creates a **MediaKeySession** instance. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GenerateKeySystemRequest](_drm.md#oh_mediakeysystem_generatekeysystemrequest) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*request, int32_t \*requestLen, char \*defaultUrl, int32_t defaultUrlLen) | Generates a provision request. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_ProcessKeySystemResponse](_drm.md#oh_mediakeysystem_processkeysystemresponse) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*response, int32_t responseLen) | Processes a provision response. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyIds](_drm.md#oh_mediakeysystem_getofflinemediakeyids) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) \*offlineMediaKeyIds) | Obtains the IDs of offline media keys. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyStatus](_drm.md#oh_mediakeysystem_getofflinemediakeystatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus) \*status) | Obtains the status of an offline media key. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_ClearOfflineMediaKeys](_drm.md#oh_mediakeysystem_clearofflinemediakeys) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | Clears offline media keys. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_GetCertificateStatus](_drm.md#oh_mediakeysystem_getcertificatestatus) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem, [DRM_CertificateStatus](_drm.md#drm_certificatestatus) \*certStatus) | Obtains the status of a DRM certificate. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySystem_Destroy](_drm.md#oh_mediakeysystem_destroy) ([MediaKeySystem](_drm.md#mediakeysystem) \*mediaKeySystem) | Destroys a **MediaKeySystem** instance. | 
