# native_mediakeysession.h

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29f3919446ee01733553b9b39493ee11224dad86 translatedAt=2026-07-31T02:14:18.113Z pushedAt=2026-07-31T06:23:14.008Z -->

## Overview

This file declares the DRM MediaKeySession API and provides the following features:<br> generating media key requests, processing media key responses, listening for events, obtaining content protection levels, checking media key status, and deleting media keys.

**File to include**: <multimedia/drm_framework/native_mediakeysession.h>

**Library**: libnative_drm.so

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](capi-drm.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [MediaKeySession_Callback](capi-drm-mediakeysession-callback.md) | MediaKeySession_Callback | Defines the callbacks for media key session events such as key expiration and key changes. It does not provide a MediaKeySession instance, making it suitable for single-session decryption scenarios.|
| [OH_MediaKeySession_Callback](capi-drm-oh-mediakeysession-callback.md) | OH_MediaKeySession_Callback | Defines the callbacks for media key session events such as key expiration and key changes. It provides a MediaKeySession instance, making it suitable for multi-session decryption scenarios.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef Drm_ErrCode (\*MediaKeySession_EventCallback)(DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)](#mediakeysession_eventcallback) | MediaKeySession_EventCallback | Defines the callback invoked when a MediaKeySession event is triggered, such as a key expiration event. |
| [typedef Drm_ErrCode (\*MediaKeySession_KeyChangeCallback)(DRM_KeysInfo *keysInfo, bool newKeysAvailable)](#mediakeysession_keychangecallback) | MediaKeySession_KeyChangeCallback | Defines the callback invoked when a key change occurs. |
| [typedef Drm_ErrCode (\*OH_MediaKeySession_EventCallback)(MediaKeySession *mediaKeySession, DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)](#oh_mediakeysession_eventcallback) | OH_MediaKeySession_EventCallback | Defines the callback invoked when an event is triggered. The event information originates from DRM events during media playback and is triggered through the MediaKeySession instance. |
| [typedef Drm_ErrCode (\*OH_MediaKeySession_KeyChangeCallback)(MediaKeySession *mediaKeySession, DRM_KeysInfo *keysInfo, bool newKeysAvailable)](#oh_mediakeysession_keychangecallback) | OH_MediaKeySession_KeyChangeCallback | Defines the callback invoked when a key change occurs. |
| [Drm_ErrCode OH_MediaKeySession_GenerateMediaKeyRequest(MediaKeySession *mediaKeySession, DRM_MediaKeyRequestInfo *info, DRM_MediaKeyRequest *mediaKeyRequest)](#oh_mediakeysession_generatemediakeyrequest) | - | Generates a media key request.|
| [Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse(MediaKeySession *mediaKeySession, uint8_t *response, int32_t responseLen, uint8_t *offlineMediaKeyId, int32_t *offlineMediaKeyIdLen)](#oh_mediakeysession_processmediakeyresponse) | - | Processes the response to a media key request.|
| [Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus(MediaKeySession *mediaKeySession, DRM_MediaKeyStatus *mediaKeyStatus)](#oh_mediakeysession_checkmediakeystatus) | - | Checks the status of a media key.|
| [Drm_ErrCode OH_MediaKeySession_ClearMediaKeys(MediaKeySession *mediaKeySession)](#oh_mediakeysession_clearmediakeys) | - | Clears media keys of the current session.|
| [Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest(MediaKeySession *mediaKeySession, uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseRequest,int32_t *releaseRequestLen)](#oh_mediakeysession_generateofflinereleaserequest) | - | Generates a request to release offline media keys.|
| [Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse(MediaKeySession *mediaKeySession, uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseResponse,int32_t releaseResponseLen)](#oh_mediakeysession_processofflinereleaseresponse) | - | Processes the response to a request for releasing offline media keys.|
| [Drm_ErrCode OH_MediaKeySession_RestoreOfflineMediaKeys(MediaKeySession *mediaKeySession, uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen)](#oh_mediakeysession_restoreofflinemediakeys) | - | Restores offline media keys to the current session.|
| [Drm_ErrCode OH_MediaKeySession_GetContentProtectionLevel(MediaKeySession *mediaKeySession, DRM_ContentProtectionLevel *contentProtectionLevel)](#oh_mediakeysession_getcontentprotectionlevel) | - | Obtains the content protection level of a media key session.|
| [Drm_ErrCode OH_MediaKeySession_RequireSecureDecoderModule(MediaKeySession *mediaKeySession, const char *mimeType, bool *status)](#oh_mediakeysession_requiresecuredecodermodule) | - | Checks whether secure decoding is required.|
| [Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback(MediaKeySession *mediaKeySession, MediaKeySession_Callback *callback)](#oh_mediakeysession_setmediakeysessioncallback) | - | Sets a media key session event callback. This callback does not return a MediaKeySession instance and applies to the scenario where a single MediaKeySession is used.|
| [Drm_ErrCode OH_MediaKeySession_SetCallback(MediaKeySession *mediaKeySession, OH_MediaKeySession_Callback *callback)](#oh_mediakeysession_setcallback) | - | Sets a media key session event callback. This callback returns a MediaKeySession instance, making it suitable for scenarios where multiple MediaKeySessions are used.|
| [Drm_ErrCode OH_MediaKeySession_Destroy(MediaKeySession *mediaKeySession)](#oh_mediakeysession_destroy) | - | Destroys a MediaKeySession instance.|

## Function Description

### MediaKeySession_EventCallback()

```c
typedef Drm_ErrCode (*MediaKeySession_EventCallback)(DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
```

**Description**

Defines the callback function called when a MediaKeySession event is triggered, such as a key expiration event.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [DRM_EventType](capi-native-drm-common-h.md#drm_eventtype) eventType | Event type. This is an input parameter.|
|  uint8_t *info | Pointer to the event information obtained from the media key session. This is an output parameter.|
| int32_t infoLen | Event information length. This is an output parameter.|
|  char *extra | Pointer to the extra information obtained from the media key session. This is an output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | Error code.|

### MediaKeySession_KeyChangeCallback()

```c
typedef  Drm_ErrCode (*MediaKeySession_KeyChangeCallback)(DRM_KeysInfo *keysInfo, bool newKeysAvailable)
```

**Description**

Defines the callback invoked when the key changes.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [DRM_KeysInfo](capi-drm-drm-keysinfo.md) *keysInfo | Pointer to the media key information.|
|  bool newKeysAvailable | Whether the new keys are available. **true** if available, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: Parameter check fails.|

### OH_MediaKeySession_EventCallback()

```c
typedef Drm_ErrCode (*OH_MediaKeySession_EventCallback)(MediaKeySession *mediaKeySession, DRM_EventType eventType,uint8_t *info, int32_t infoLen, char *extra)
```

**Description**

Defines the callback function called when an event occurs. The event originates from DRM events during media playback and is triggered through the MediaKeySession instance.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the session instance, which identifies the event source. This is an input parameter.|
| [DRM_EventType](capi-native-drm-common-h.md#drm_eventtype) eventType | Event type. This is an input parameter.|
| uint8_t *info | Pointer to the event information which originates from the DRM event. This is an output parameter.|
|  int32_t infoLen | Event information length. This is an output parameter.|
|  char *extra | Pointer to the extra information from the DRM event. This is an output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | Error code.|

### OH_MediaKeySession_KeyChangeCallback()

```c
typedef Drm_ErrCode (*OH_MediaKeySession_KeyChangeCallback)(MediaKeySession *mediaKeySession, DRM_KeysInfo *keysInfo,bool newKeysAvailable)
```

**Description**

Defines the callback function called for key change events.

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

```c
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
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: Memory allocation fails due to insufficient system memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **info** or **mediaKeyRequest** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_ProcessMediaKeyResponse()

```c
Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse(MediaKeySession *mediaKeySession,uint8_t *response, int32_t responseLen, uint8_t *offlineMediaKeyId, int32_t *offlineMediaKeyIdLen)
```

**Description**

Processes the response to a media key request.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| uint8_t *response | Pointer to the response to a media key request.|
| int32_t responseLen | Length of the response.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t *offlineMediaKeyIdLen | Pointer to the length of the offline media key ID.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: Memory allocation fails due to insufficient system memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_CheckMediaKeyStatus()

```c
Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus(MediaKeySession *mediaKeySession,DRM_MediaKeyStatus *mediaKeyStatus)
```

**Description**

Checks the status of a media key.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance. This is an input parameter which is mandatory.|
| [DRM_MediaKeyStatus](capi-drm-drm-mediakeystatus.md) *mediaKeyStatus | Pointer to the media key status. This is an output parameter which is mandatory.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: Memory allocation fails due to insufficient system memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **mediaKeyStatus** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_ClearMediaKeys()

```c
Drm_ErrCode OH_MediaKeySession_ClearMediaKeys(MediaKeySession *mediaKeySession)
```

**Description**

Clears media keys of the current session.

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

```c
Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseRequest,int32_t *releaseRequestLen)
```

**Description**

Generates a request to release offline media keys.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance. This is an input parameter.|
| uint8_t *offlineMediaKeyId | Pointer to the offline media key ID. This is an input parameter. The value range is [1, 64], and the unit is bytes.|
| int32_t offlineMediaKeyIdLen | Length of the offline media key ID. This is an input parameter. The value range is [1, 64].|
| uint8_t *releaseRequest | Pointer to the offline media key release request. This is an output parameter.|
| int32_t *releaseRequestLen | Pointer to the length of the offline media key release request. This is an output parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: Memory allocation fails due to insufficient system memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs or the DRM solution on the device does not support the release of offline media keys. Check the log details.|

### OH_MediaKeySession_ProcessOfflineReleaseResponse()

```c
Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse(MediaKeySession *mediaKeySession,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t *releaseResponse,int32_t releaseResponseLen)
```

**Description**

Processes the response to a request for releasing offline media keys.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t offlineMediaKeyIdLen | Length of the offline media key ID.|
| uint8_t *releaseResponse | Pointer to the response.|
| int32_t releaseResponseLen | Length of the response.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs or the DRM solution on the device does not support the release of offline media keys. Check the log details.|

### OH_MediaKeySession_RestoreOfflineMediaKeys()

```c
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

```c
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

```c
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
| bool *status | Pointer to the result indicating whether secure decoding is required. The value **true** means that secure decoding is required, and the value **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySession_SetMediaKeySessionCallback()

```c
Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback(MediaKeySession *mediaKeySession,MediaKeySession_Callback *callback)
```

**Description**

Sets a media key session event callback. This callback does not return a MediaKeySession instance and applies to the scenario where a single MediaKeySession is used.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance. This is an input parameter.|
| [MediaKeySession_Callback](capi-drm-mediakeysession-callback.md) *callback | Pointer to the callback structure of the MediaKeySession. This is an input parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **callback** is nullptr.|

### OH_MediaKeySession_SetCallback()

```c
Drm_ErrCode OH_MediaKeySession_SetCallback(MediaKeySession *mediaKeySession,OH_MediaKeySession_Callback *callback)
```

**Description**

Sets a media key session event callback. This callback returns a MediaKeySession instance, making it suitable for scenarios where multiple MediaKeySessions are used.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySession](capi-drm-mediakeysession.md) *mediaKeySession | Pointer to the MediaKeySession instance. This is an input parameter.|
| [OH_MediaKeySession_Callback](capi-drm-oh-mediakeysession-callback.md) *callback | Pointer to the callback structure of the MediaKeySession. This is an input parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySession** is nullptr or invalid, or **callback** is nullptr.|

### OH_MediaKeySession_Destroy()

```c
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