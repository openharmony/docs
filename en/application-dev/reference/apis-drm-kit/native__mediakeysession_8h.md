# native_mediakeysession.h


## Overview

The **native_mediakeysession.h** file declares the **MediaKeySession** API. The APIs can be used to generate media key requests, process responses to media key requests, listen for events, obtain content protection levels, check media key status, and delete media keys.

**Library**: libnative_drm.so

**File to include**: &lt;multimedia/drm_framework/native_mediakeysession.h&gt;

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [MediaKeySession_Callback](_media_key_session___callback.md) | Describes the callback used to listen for events such as media key expiry or change, without returning media key session instances. It applies to the scenario where a single media key session needs to be decrypted. | 
| struct  [OH_MediaKeySession_Callback](_o_h___media_key_session___callback.md) | Describes the callback used to listen for events such as media key expiry or change, with media key session instances returned. It applies to the scenario where multiple media key sessions need to be decrypted. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySession_EventCallback](_drm.md#mediakeysession_eventcallback)) ([DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | Defines the callback that is invoked when a media key session event is triggered. | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [MediaKeySession_KeyChangeCallback](_drm.md#mediakeysession_keychangecallback)) ([DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | Defines the callback that is invoked when the key is changed. | 
| typedef struct [MediaKeySession_Callback](_media_key_session___callback.md) [MediaKeySession_Callback](_drm.md#mediakeysession_callback) | Defines the callback used to listen for events such as media key expiry or change, without returning media key session instances. It applies to the scenario where a single media key session needs to be decrypted. | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [OH_MediaKeySession_EventCallback](_drm.md#oh_mediakeysession_eventcallback)) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [DRM_EventType](_drm.md#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | Defines the callback that is invoked when a DRM event is triggered. | 
| typedef [Drm_ErrCode](_drm.md#drm_errcode)(\* [OH_MediaKeySession_KeyChangeCallback](_drm.md#oh_mediakeysession_keychangecallback)) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | Defines the callback that is invoked when the key is changed. | 
| typedef struct [OH_MediaKeySession_Callback](_o_h___media_key_session___callback.md) [OH_MediaKeySession_Callback](_drm.md#oh_mediakeysession_callback) | Defines the callback used to listen for events such as media key expiry or change, with media key session instances returned. It applies to the scenario where multiple media key sessions need to be decrypted. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_GenerateMediaKeyRequest](_drm.md#oh_mediakeysession_generatemediakeyrequest) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) \*info, [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) \*mediaKeyRequest) | Generates a media key request. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_ProcessMediaKeyResponse](_drm.md#oh_mediakeysession_processmediakeyresponse) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, uint8_t \*response, int32_t responseLen, uint8_t \*offlineMediaKeyId, int32_t \*offlineMediaKeyIdLen) | Processes a response to the media key request. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_CheckMediaKeyStatus](_drm.md#oh_mediakeysession_checkmediakeystatus) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) \*mediaKeyStatus) | Checks the status of media keys. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_ClearMediaKeys](_drm.md#oh_mediakeysession_clearmediakeys) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession) | Clears media keys. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_GenerateOfflineReleaseRequest](_drm.md#oh_mediakeysession_generateofflinereleaserequest) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseRequest, int32_t \*releaseRequestLen) | Generates a request to release offline media keys. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_ProcessOfflineReleaseResponse](_drm.md#oh_mediakeysession_processofflinereleaseresponse) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseReponse, int32_t releaseReponseLen) | Processes a response to a request for releasing offline media keys. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_RestoreOfflineMediaKeys](_drm.md#oh_mediakeysession_restoreofflinemediakeys) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | Restores offline media keys. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_GetContentProtectionLevel](_drm.md#oh_mediakeysession_getcontentprotectionlevel) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) \*contentProtectionLevel) | Obtains the content protection level of a media key session. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_RequireSecureDecoderModule](_drm.md#oh_mediakeysession_requiresecuredecodermodule) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, const char \*mimeType, bool \*status) | Checks whether secure decoding is required. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_SetMediaKeySessionCallback](_drm.md#oh_mediakeysession_setmediakeysessioncallback) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [MediaKeySession_Callback](_media_key_session___callback.md) \*callback) | Sets a media key session event callback. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_SetCallback](_drm.md#oh_mediakeysession_setcallback) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession, [OH_MediaKeySession_Callback](_o_h___media_key_session___callback.md) \*callback) | Sets a media key session event callback. | 
| [Drm_ErrCode](_drm.md#drm_errcode) [OH_MediaKeySession_Destroy](_drm.md#oh_mediakeysession_destroy) ([MediaKeySession](_drm.md#mediakeysession) \*mediaKeySession) | Destroys a **MediaKeySession** instance. | 
