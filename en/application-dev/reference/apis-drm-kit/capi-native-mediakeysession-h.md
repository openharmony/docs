# native_mediakeysession.h

## Overview

The file declares the MediaKeySession APIs.

The APIs can be used to generate media key requests, process responses to media key requests, listen for events, obtain content protection levels, check media key status, and delete media keys.

**File to include**: <multimedia/drm_framework/native_mediakeysession.h>

**Library**: libnative_drm.z.so

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](capi-drm.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [MediaKeySession_Callback](capi-drm-mediakeysession-callback.md) | MediaKeySession_Callback | Describes the callback used to listen for events such as media key expiry or change, without returning media key session instances. It applies to the scenario where a single media key session needs to be decrypted.|
| [OH_MediaKeySession_Callback](capi-drm-oh-mediakeysession-callback.md) | OH_MediaKeySession_Callback | Describes the callback used to listen for events such as media key expiry or change, with media key session instances returned. It applies to the scenario where multiple media key sessions need to be decrypted.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef  Drm_ErrCode (\*MediaKeySession_EventCallback)(DRM_EventType eventType, uint8_t *info,int32_t infoLen, char *extra)](#mediakeysession_eventcallback) | MediaKeySession_EventCallback | Defines the callback used to listen for media key session events, for example, a key expiration event.|
| [typedef  Drm_ErrCode (\*MediaKeySession_KeyChangeCallback)(DRM_KeysInfo *keysInfo, bool newKeysAvailable)](#mediakeysession_keychangecallback) | MediaKeySession_KeyChangeCallback | Defines the callback that is invoked when the key is changed.|
| [typedef Drm_ErrCode (\*OH_MediaKeySession_EventCallback)(MediaKeySession *mediaKeySession, DRM_EventType eventType,uint8_t *info, int32_t infoLen, char *extra)](#oh_mediakeysession_eventcallback) | OH_MediaKeySession_EventCallback | Defines the callback that is invoked when a media key session event is triggered.|
| [typedef Drm_ErrCode (\*OH_MediaKeySession_KeyChangeCallback)(MediaKeySession *mediaKeySession, DRM_KeysInfo *keysInfo,bool newKeysAvailable)](#oh_mediakeysession_keychangecallback) | OH_MediaKeySession_KeyChangeCallback | Defines the callback that is invoked when the key is changed.|
| [Drm_ErrCode OH_MediaKeySession_GenerateMediaKeyRequest(MediaKeySession *mediaKeySession,DRM_MediaKeyRequestInfo *info, DRM_MediaKeyRequest *mediaKeyRequest)](#oh_mediakeysession_generatemediakeyrequest) | - | Generates a media key request.|
| [Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse(MediaKeySession *mediaKeySession,uint8_t *response, int32_t responseLen, uint8_t *offlineMediaKeyId, int32_t *offlineMediaKeyIdLen)](#oh_mediakeysession_processmediakeyresponse) | - | Processes a media key response.|
| [Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus(MediaKeySession *mediaKeySession,DRM_MediaKeyStatus *mediaKeyStatus)](#oh_mediakeysession_checkmediakeystatus) | - | Checks the status of media keys.|
| [Drm_ErrCode OH_MediaKeySession_ClearMediaKeys(MediaKeySession *mediaKeySession)](#oh_mediakeysession_clearmediakeys) | - | Clears media keys.|
| [Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseRequest,int32_t *releaseRequestLen)](#oh_mediakeysession_generateofflinereleaserequest) | - | Generates a request to release offline media keys.|
| [Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseReponse,int32_t releaseReponseLen)](#oh_mediakeysession_processofflinereleaseresponse) | - | Processes a response to a request for releasing offline media keys.|
| [Drm_ErrCode OH_MediaKeySession_RestoreOfflineMediaKeys(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen)](#oh_mediakeysession_restoreofflinemediakeys) | - | Restores offline media keys.|
| [Drm_ErrCode OH_MediaKeySession_GetContentProtectionLevel(MediaKeySession *mediaKeySession,DRM_ContentProtectionLevel *contentProtectionLevel)](#oh_mediakeysession_getcontentprotectionlevel) | - | Obtains the content protection level of a media key session.|
| [Drm_ErrCode OH_MediaKeySession_RequireSecureDecoderModule(MediaKeySession *mediaKeySession,const char *mimeType, bool *status)](#oh_mediakeysession_requiresecuredecodermodule) | - | Checks whether secure decoding is required.|
| [Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback(MediaKeySession *mediaKeySession,MediaKeySession_Callback *callback)](#oh_mediakeysession_setmediakeysessioncallback) | - | Sets a media key session event callback.|
| [Drm_ErrCode OH_MediaKeySession_SetCallback(MediaKeySession *mediaKeySession,OH_MediaKeySession_Callback *callback)](#oh_mediakeysession_setcallback) | - | Sets a media key session event callback.|
| [Drm_ErrCode OH_MediaKeySession_Destroy(MediaKeySession *mediaKeySession)](#oh_mediakeysession_destroy) | - | Destroys a MediaKeySession instance.|

## Function Description

### MediaKeySession_EventCallback()

```
typedef  Drm_ErrCode (*MediaKeySession_EventCallback)(DRM_EventType eventType, uint8_t *info,int32_t infoLen, char *extra)
```

**Description**

Defines the callback used to listen for media key session events, for example, a key expiration event.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [DRM_EventType](capi-native-drm-common-h.md#drm_eventtype) eventType | Event type.|
|  uint8_t *info | Pointer to the event information obtained from the media key session.|
| int32_t infoLen | Length of the event information.|
|  char *extra | Pointer to the additional information obtained from the media key session.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | Error code.|

### MediaKeySession_KeyChangeCallback()

```
typedef  Drm_ErrCode (*MediaKeySession_KeyChangeCallback)(DRM_KeysInfo *keysInfo, bool newKeysAvailable)
```

**Description**

Defines the callback that is invoked when the key is changed.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [DRM_KeysInfo](capi-drm-drm-keysinfo.md) *keysInfo | Pointer to the media key information.|
|  bool newKeysAvailable | Whether the new key is available.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: Parameter check fails.|

### OH_MediaKeySession_EventCallback()

```
typedef Drm_ErrCode (*OH_MediaKeySession_EventCallback)(MediaKeySession *mediaKeySession, DRM_EventType eventType,uint8_t *info, int32_t infoLen, char *extra)
```

**Description**

Defines the callback that is invoked when a media key session event is triggered.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| [DRM_EventType](capi-native-drm-common-h.md#drm_eventtype) eventType | Event type.|
| uint8_t *info | Pointer to the event information.|
|  int32_t infoLen | Length of the event information.|
|  char *extra | Pointer to extended event information.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | Error code.|

### OH_MediaKeySession_KeyChangeCallback()

```
typedef Drm_ErrCode (*OH_MediaKeySession_KeyChangeCallback)(MediaKeySession *mediaKeySession, DRM_KeysInfo *keysInfo,bool newKeysAvailable)
```

**Description**

Defines the callback that is invoked when the key is changed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| [DRM_KeysInfo](capi-drm-drm-keysinfo.md) *keysInfo | Pointer to the media key information.|
| bool newKeysAvailable | Whether the new keys are available. **true** if available, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: Parameter check fails.|

### OH_MediaKeySession_GenerateMediaKeyRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateMediaKeyRequest(MediaKeySession *mediaKeySession,DRM_MediaKeyRequestInfo *info, DRM_MediaKeyRequest *mediaKeyRequest)
```

**Description**

Generates a media key request.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| [DRM_MediaKeyRequestInfo](capi-drm-drm-mediakeyrequestinfo.md) *info | Pointer to the information about the media key request.|
| [DRM_MediaKeyRequest](capi-drm-drm-mediakeyrequest.md) *mediaKeyRequest | Pointer to the media key request.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **info** or **mediaKeyRequest** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_ProcessMediaKeyResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse(MediaKeySession *mediaKeySession,uint8_t *response, int32_t responseLen, uint8_t *offlineMediaKeyId, int32_t *offlineMediaKeyIdLen)
```

**Description**

Processes a media key response.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| uint8_t *response | Pointer to a media key response.|
| int32_t responseLen | Pointer to the length of the media key response.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t *offlineMediaKeyIdLen | Length of the offline media key ID.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_CheckMediaKeyStatus()

```
Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus(MediaKeySession *mediaKeySession,DRM_MediaKeyStatus *mediaKeyStatus)
```

**Description**

Checks the status of media keys.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| [DRM_MediaKeyStatus](capi-drm-drm-mediakeystatus.md) *mediaKeyStatus | Pointer to the media key status obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **mediaKeyStatus** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_ClearMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_ClearMediaKeys(MediaKeySession *mediaKeySession)
```

**Description**

Clears media keys.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_GenerateOfflineReleaseRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseRequest,int32_t *releaseRequestLen)
```

**Description**

Generates a request to release offline media keys.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t *releaseRequestLen | Length of the offline media key ID.|
| uint8_t *releaseRequest | Pointer to a request to release offline media keys.|
| int32_t *releaseRequestLen | Length of the request to release offline media keys.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs or the DRM solution on the device does not support offline media key release. Check the log details.|

### OH_MediaKeySession_ProcessOfflineReleaseResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseReponse,int32_t releaseReponseLen)
```

**Description**

Processes a response to a request for releasing offline media keys.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t offlineMediaKeyIdLen | Length of the offline media key ID.|
| uint8_t *releaseReponse | Pointer to the response.|
| int32_t releaseReponseLen | Length of the response.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs or the DRM solution on the device does not support offline media key release. Check the log details.|

### OH_MediaKeySession_RestoreOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_RestoreOfflineMediaKeys(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen)
```

**Description**

Restores offline media keys.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t offlineMediaKeyIdLen | Length of the offline media key ID.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_GetContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySession_GetContentProtectionLevel(MediaKeySession *mediaKeySession,DRM_ContentProtectionLevel *contentProtectionLevel)
```

**Description**

Obtains the content protection level of a media key session.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| [DRM_ContentProtectionLevel](capi-native-drm-common-h.md#drm_contentprotectionlevel) *contentProtectionLevel | Pointer to the content protection level.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **contentProtectionLevel** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_RequireSecureDecoderModule()

```
Drm_ErrCode OH_MediaKeySession_RequireSecureDecoderModule(MediaKeySession *mediaKeySession,const char *mimeType, bool *status)
```

**Description**

Checks whether secure decoding is required.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| const char *mimeType | Pointer to the MIME type. The supported MIME types depend on the DRM solution. Example types are video/avc and video/hev.|
| bool *status | Pointer to the result indicating whether secure decoding is required.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_SetMediaKeySessionCallback()

```
Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback(MediaKeySession *mediaKeySession,MediaKeySession_Callback *callback)
```

**Description**

Sets a media key session event callback.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| [MediaKeySession_Callback](capi-drm-mediakeysession-callback.md) *callback | Pointer to the callback for the media key session event.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **callback** is nullptr.|

### OH_MediaKeySession_SetCallback()

```
Drm_ErrCode OH_MediaKeySession_SetCallback(MediaKeySession *mediaKeySession,OH_MediaKeySession_Callback *callback)
```

**Description**

Sets a media key session event callback.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| [OH_MediaKeySession_Callback](capi-drm-oh-mediakeysession-callback.md) *callback | Pointer to the callback for the media key session event.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **callback** is nullptr.|

### OH_MediaKeySession_Destroy()

```
Drm_ErrCode OH_MediaKeySession_Destroy(MediaKeySession *mediaKeySession)
```

**Description**

Destroys a MediaKeySession instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|
