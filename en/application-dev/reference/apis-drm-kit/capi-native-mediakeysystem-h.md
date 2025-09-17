# native_mediakeysystem.h

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the MediaKeySystem APIs.

The APIs can be used to check whether a specific DRM is supported, create a media key session, obtain and set configurations, obtain statistics information, obtain the content protection level, generate media key system requests, process responses to media key system requests, listen for events, and manage offline media keys.

**File to include**: <multimedia/drm_framework/native_mediakeysystem.h>

**Library**: libnative_drm.z.so

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](capi-drm.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef  Drm_ErrCode (\*MediaKeySystem_Callback)(DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)](#mediakeysystem_callback) | MediaKeySystem_Callback | Defines the callback used to listen for media key system events. No MediaKeySystem instance is returned. This callback applies to the scenario where a single MediaKeySystem instance is used.|
| [typedef Drm_ErrCode (\*OH_MediaKeySystem_Callback)(MediaKeySystem *mediaKeySystem, DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)](#oh_mediakeysystem_callback) | OH_MediaKeySystem_Callback | Defines the callback used to listen for media key system events. A MediaKeySystem instance is returned. This callback applies to the scenario where multiple MediaKeySystem instances are used.|
| [Drm_ErrCode OH_MediaKeySystem_SetCallback(MediaKeySystem *mediaKeySystem, OH_MediaKeySystem_Callback callback)](#oh_mediakeysystem_setcallback) | - | Sets a media key system event callback.|
| [Drm_ErrCode OH_MediaKeySystem_GetMediaKeySystems(DRM_MediaKeySystemDescription *infos, uint32_t *count)](#oh_mediakeysystem_getmediakeysystems) | - | Obtains the name and ID list of the DRM solutions supported by the device.|
| [bool OH_MediaKeySystem_IsSupported(const char *name)](#oh_mediakeysystem_issupported) | - | Checks whether the device supports the specified DRM solution.|
| [bool OH_MediaKeySystem_IsSupported2(const char *name, const char *mimeType)](#oh_mediakeysystem_issupported2) | - | Checks whether the device supports the combination of the DRM solution and MIME type.|
| [bool OH_MediaKeySystem_IsSupported3(const char *name, const char *mimeType, DRM_ContentProtectionLevel contentProtectionLevel)](#oh_mediakeysystem_issupported3) | - | Checks whether the device supports the combination of the DRM solution, MIME type, and content protection level.|
| [Drm_ErrCode OH_MediaKeySystem_Create(const char *name, MediaKeySystem **mediaKeySystem)](#oh_mediakeysystem_create) | - | Creates a MediaKeySystem instance.|
| [Drm_ErrCode OH_MediaKeySystem_SetConfigurationString(MediaKeySystem *mediaKeySystem, const char *configName, const char *value)](#oh_mediakeysystem_setconfigurationstring) | - | Sets a configuration item in the form of a string.|
| [Drm_ErrCode OH_MediaKeySystem_GetConfigurationString(MediaKeySystem *mediaKeySystem, const char *configName, char *value, int32_t valueLen)](#oh_mediakeysystem_getconfigurationstring) | - | Obtains the value of a configuration item in the form of a string.|
| [Drm_ErrCode OH_MediaKeySystem_SetConfigurationByteArray(MediaKeySystem *mediaKeySystem, const char *configName, uint8_t *value, int32_t valueLen)](#oh_mediakeysystem_setconfigurationbytearray) | - | Sets a configuration item in the form of an array.|
| [Drm_ErrCode OH_MediaKeySystem_GetConfigurationByteArray(MediaKeySystem *mediaKeySystem, const char *configName, uint8_t *value, int32_t *valueLen)](#oh_mediakeysystem_getconfigurationbytearray) | - | Obtains the value of a configuration item in the form of an array.|
| [Drm_ErrCode OH_MediaKeySystem_GetStatistics(MediaKeySystem *mediaKeySystem, DRM_Statistics *statistics)](#oh_mediakeysystem_getstatistics) | - | Obtains the statistics information about a media key system.|
| [Drm_ErrCode OH_MediaKeySystem_GetMaxContentProtectionLevel(MediaKeySystem *mediaKeySystem, DRM_ContentProtectionLevel *contentProtectionLevel)](#oh_mediakeysystem_getmaxcontentprotectionlevel) | - | Obtains the maximum content protection level supported by the device.|
| [Drm_ErrCode OH_MediaKeySystem_SetMediaKeySystemCallback(MediaKeySystem *mediaKeySystem, MediaKeySystem_Callback callback)](#oh_mediakeysystem_setmediakeysystemcallback) | - | Sets a media key system event callback.|
| [Drm_ErrCode OH_MediaKeySystem_CreateMediaKeySession(MediaKeySystem *mediaKeySystem, DRM_ContentProtectionLevel *level, MediaKeySession **mediaKeySession)](#oh_mediakeysystem_createmediakeysession) | - | Creates a MediaKeySession instance.|
| [Drm_ErrCode OH_MediaKeySystem_GenerateKeySystemRequest(MediaKeySystem *mediaKeySystem, uint8_t *request, int32_t *requestLen, char *defaultUrl, int32_t defaultUrlLen)](#oh_mediakeysystem_generatekeysystemrequest) | - | Generates a provision request.|
| [Drm_ErrCode OH_MediaKeySystem_ProcessKeySystemResponse(MediaKeySystem *mediaKeySystem, uint8_t *response, int32_t responseLen)](#oh_mediakeysystem_processkeysystemresponse) | - | Processes a provision response.|
| [Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyIds(MediaKeySystem *mediaKeySystem, DRM_OfflineMediakeyIdArray *offlineMediaKeyIds)](#oh_mediakeysystem_getofflinemediakeyids) | - | Obtains the list of offline media key IDs, which are used to manage offline media keys.|
| [Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyStatus(MediaKeySystem *mediaKeySystem, uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, DRM_OfflineMediaKeyStatus *status)](#oh_mediakeysystem_getofflinemediakeystatus) | - | Obtains the status of an offline media key.|
| [Drm_ErrCode OH_MediaKeySystem_ClearOfflineMediaKeys(MediaKeySystem *mediaKeySystem, uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen)](#oh_mediakeysystem_clearofflinemediakeys) | - | Clears offline media keys by ID.|
| [Drm_ErrCode OH_MediaKeySystem_GetCertificateStatus(MediaKeySystem *mediaKeySystem, DRM_CertificateStatus *certStatus)](#oh_mediakeysystem_getcertificatestatus) | - | Obtains the status of a DRM certificate.|
| [Drm_ErrCode OH_MediaKeySystem_Destroy(MediaKeySystem *mediaKeySystem)](#oh_mediakeysystem_destroy) | - | Destroys a MediaKeySystem instance.|

## Function Description

### MediaKeySystem_Callback()

```
typedef  Drm_ErrCode (*MediaKeySystem_Callback)(DRM_EventType eventType, uint8_t *info,int32_t infoLen, char *extra)
```

**Description**

Defines the callback used to listen for media key system events. No MediaKeySystem instance is returned. This callback applies to the scenario where a single MediaKeySystem instance is used.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [DRM_EventType](capi-native-drm-common-h.md#drm_eventtype) eventType | Event type.|
|  uint8_t *info | Pointer to the event information.|
| int32_t infoLen | Length of the event information.|
|  char *extra | Pointer to extended event information.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: An input parameter is invalid.|

### OH_MediaKeySystem_Callback()

```
typedef Drm_ErrCode (*OH_MediaKeySystem_Callback)(MediaKeySystem *mediaKeySystem, DRM_EventType eventType,uint8_t *info, int32_t infoLen, char *extra)
```

**Description**

Defines the callback used to listen for media key system events. A MediaKeySystem instance is returned. This callback applies to the scenario where multiple MediaKeySystem instances are used.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [DRM_EventType](capi-native-drm-common-h.md#drm_eventtype) eventType | Event type.|
| uint8_t *info | Pointer to the event information.|
|  int32_t infoLen | Length of the event information.|
|  char *extra | Pointer to extended event information.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: An input parameter is invalid.|

### OH_MediaKeySystem_SetCallback()

```
Drm_ErrCode OH_MediaKeySystem_SetCallback(MediaKeySystem *mediaKeySystem, OH_MediaKeySystem_Callback callback)
```

**Description**

Sets a media key system event callback.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [OH_MediaKeySystem_Callback](#oh_mediakeysystem_callback) callback | Callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid.|

### OH_MediaKeySystem_GetMediaKeySystems()

```
Drm_ErrCode OH_MediaKeySystem_GetMediaKeySystems(DRM_MediaKeySystemDescription *infos, uint32_t *count)
```

**Description**

Obtains the name and ID list of the DRM solutions supported by the device.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [DRM_MediaKeySystemDescription](capi-drm-drm-mediakeysystemdescription.md) *infos | Pointer to the list of the names and UUIDs of DRM solutions.|
| uint32_t *count | Pointer to the length of the list.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: Possible causes:<br>                            1. The input parameter **infos** or **count** is nullptr.<br>                            2. The length of the input parameter **infos** is insufficient.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_IsSupported()

```
bool OH_MediaKeySystem_IsSupported(const char *name)
```

**Description**

Checks whether the device supports the specified DRM solution.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to the DRM solution name.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of the specified DRM solution.|

### OH_MediaKeySystem_IsSupported2()

```
bool OH_MediaKeySystem_IsSupported2(const char *name, const char *mimeType)
```

**Description**

Checks whether the device supports the combination of the DRM solution and MIME type.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to the DRM solution name.|
| const char *mimeType | Pointer to the MIME type. The supported MIME types depend on the DRM solution. Example types are video/avc and video/hev.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of the combination.|

### OH_MediaKeySystem_IsSupported3()

```
bool OH_MediaKeySystem_IsSupported3(const char *name, const char *mimeType,DRM_ContentProtectionLevel contentProtectionLevel)
```

**Description**

Checks whether the device supports the combination of the DRM solution, MIME type, and content protection level.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to the DRM solution name.|
| const char *mimeType | Pointer to the MIME type. The supported MIME types depend on the DRM solution. Example types are video/avc and video/hev.|
| [DRM_ContentProtectionLevel](capi-native-drm-common-h.md#drm_contentprotectionlevel) contentProtectionLevel | Content protection level.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of the combination.|

### OH_MediaKeySystem_Create()

```
Drm_ErrCode OH_MediaKeySystem_Create(const char *name, MediaKeySystem **mediaKeySystem)
```

**Description**

Creates a MediaKeySystem instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Pointer to the DRM solution name.|
| [MediaKeySystem](capi-drm-mediakeysystem.md) **mediaKeySystem | Pointer to the MediaKeySystem instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: Possible causes:<br>                            1. The input parameter **name** is nullptr or its length is 0.<br>                            2. The input parameter **mediaKeySystem** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.<br>**DRM_ERR_SERVICE_DIED**: The service is dead.<br>DRM_ERR_MAX_SYSTEM_NUM_REACHED: The number of created MediaKeySystem instances has reached the upper limit (64).|

### OH_MediaKeySystem_SetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationString(MediaKeySystem *mediaKeySystem,const char *configName, const char *value)
```

**Description**

Sets a configuration item in the form of a string.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| const char *configName | Pointer to the name of the configuration item in the form of a string. It is determined by the DRM solution on the device and cannot be empty.|
| const char *value | Pointer to the value of the configuration item in the form of a string. It is determined by the DRM solution on the device and cannot be empty.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **configName** or **value** is nullptr.|

### OH_MediaKeySystem_GetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationString(MediaKeySystem *mediaKeySystem,const char *configName, char *value, int32_t valueLen)
```

**Description**

Obtains the value of a configuration item in the form of a string.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| const char *configName | Pointer to the name of the configuration item.|
| char *value | Pointer to the value of the configuration item.|
| int32_t valueLen | Length of the value.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **configName** or **value** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_SetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationByteArray(MediaKeySystem *mediaKeySystem,const char *configName, uint8_t *value, int32_t valueLen)
```

**Description**

Sets a configuration item in the form of an array.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| const char *configName | Pointer to the name of the configuration item in the form of a character array. It is determined by the DRM solution on the device and cannot be empty.|
| uint8_t *value | Pointer to the value of the configuration item in the form of a character array. It is determined by the DRM solution on the device and cannot be empty.|
| int32_t valueLen | Length of the value.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **configName** or **value** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_GetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationByteArray(MediaKeySystem *mediaKeySystem,const char *configName, uint8_t *value, int32_t *valueLen)
```

**Description**

Obtains the value of a configuration item in the form of an array.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| const char *configName | Pointer to the name of the configuration item in the form of a character array. It is determined by the DRM solution on the device and cannot be empty.|
| uint8_t *value | Pointer to the value of the configuration item.|
| int32_t *valueLen | Pointer to the length of the value.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **configName**, **value**, or **valueLen** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_GetStatistics()

```
Drm_ErrCode OH_MediaKeySystem_GetStatistics(MediaKeySystem *mediaKeySystem, DRM_Statistics *statistics)
```

**Description**

Obtains the statistics information about a media key system.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [DRM_Statistics](capi-drm-drm-statistics.md) *statistics | Pointer to the statistical information.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **statistics** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_GetMaxContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySystem_GetMaxContentProtectionLevel(MediaKeySystem *mediaKeySystem,DRM_ContentProtectionLevel *contentProtectionLevel)
```

**Description**

Obtains the maximum content protection level supported by the device.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [DRM_ContentProtectionLevel](capi-native-drm-common-h.md#drm_contentprotectionlevel) *contentProtectionLevel | Pointer to the content protection level.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **contentProtectionLevel** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_SetMediaKeySystemCallback()

```
Drm_ErrCode OH_MediaKeySystem_SetMediaKeySystemCallback(MediaKeySystem *mediaKeySystem,MediaKeySystem_Callback callback)
```

**Description**

Sets a media key system event callback.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [MediaKeySystem_Callback](#mediakeysystem_callback) callback | Callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid.|

### OH_MediaKeySystem_CreateMediaKeySession()

```
Drm_ErrCode OH_MediaKeySystem_CreateMediaKeySession(MediaKeySystem *mediaKeySystem,DRM_ContentProtectionLevel *level, MediaKeySession **mediaKeySession)
```

**Description**

Creates a MediaKeySession instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [DRM_ContentProtectionLevel](capi-native-drm-common-h.md#drm_contentprotectionlevel) *level | Pointer to the content protection level.|
| [MediaKeySession](capi-drm-mediakeysession.md) **mediaKeySession | Double pointer to the MediaKeySession instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, **level** is out of range, or **mediaKeySession** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.<br>**DRM_ERR_SERVICE_DIED**: The service is dead.<br>**DRM_ERR_MAX_SESSION_NUM_REACHED**: The number of MediaKeySession instances created by the MediaKeySystem instance reaches the upper limit (64).|

### OH_MediaKeySystem_GenerateKeySystemRequest()

```
Drm_ErrCode OH_MediaKeySystem_GenerateKeySystemRequest(MediaKeySystem *mediaKeySystem, uint8_t *request,int32_t *requestLen, char *defaultUrl, int32_t defaultUrlLen)
```

**Description**

Generates a provision request.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| uint8_t *request | Pointer to the provision request, which is used to request a DRM certificate from a provisioning server.|
| int32_t *requestLen | Pointer to the length of the provision request.|
| char *defaultUrl | Pointer to the URL of the provisioning server.|
| int32_t defaultUrlLen | Length of the URL of the provisioning server.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_ProcessKeySystemResponse()

```
Drm_ErrCode OH_MediaKeySystem_ProcessKeySystemResponse(MediaKeySystem *mediaKeySystem,uint8_t *response, int32_t responseLen)
```

**Description**

Processes a provision response.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| uint8_t *response | Pointer to the provision response.|
| int32_t responseLen | Length of the provision response.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **response** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_GetOfflineMediaKeyIds()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyIds(MediaKeySystem *mediaKeySystem,DRM_OfflineMediakeyIdArray *offlineMediaKeyIds)
```

**Description**

Obtains the list of offline media key IDs, which are used to manage offline media keys.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [DRM_OfflineMediakeyIdArray](capi-drm-drm-offlinemediakeyidarray.md) *offlineMediaKeyIds | Pointer to the IDs of offline media keys.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_NO_MEMORY**: The memory fails to be allocated due to insufficient memory.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **offlineMediaKeyIds** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_GetOfflineMediaKeyStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyStatus(MediaKeySystem *mediaKeySystem,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen, DRM_OfflineMediaKeyStatus *status)
```

**Description**

Obtains the status of an offline media key.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t offlineMediaKeyIdLen | Length of the offline media key ID.|
| [DRM_OfflineMediaKeyStatus](capi-native-drm-common-h.md#drm_offlinemediakeystatus) *status | Pointer to the media key status obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or another parameter of the pointer type is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_ClearOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySystem_ClearOfflineMediaKeys(MediaKeySystem *mediaKeySystem,uint8_t *offlineMediaKeyId, int32_t offlineMediaKeyIdLen)
```

**Description**

Clears offline media keys by ID.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| uint8_t *offlineMediaKeyId | Pointer to the ID of an offline media key.|
| int32_t offlineMediaKeyIdLen | Length of the offline media key ID.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **offlineMediaKeyId** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_GetCertificateStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetCertificateStatus(MediaKeySystem *mediaKeySystem,DRM_CertificateStatus *certStatus)
```

**Description**

Obtains the status of a DRM certificate.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|
| [DRM_CertificateStatus](capi-native-drm-common-h.md#drm_certificatestatus) *certStatus | Pointer to the DRM certificate status.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid, or **certStatus** is nullptr.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|

### OH_MediaKeySystem_Destroy()

```
Drm_ErrCode OH_MediaKeySystem_Destroy(MediaKeySystem *mediaKeySystem)
```

**Description**

Destroys a MediaKeySystem instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [MediaKeySystem](capi-drm-mediakeysystem.md) *mediaKeySystem | Pointer to the MediaKeySystem instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Drm_ErrCode](capi-native-drm-err-h.md#drm_errcode) | **DRM_ERR_OK**: The operation is successful.<br>**DRM_ERR_INVALID_VAL**: The input parameter **mediaKeySystem** is nullptr or invalid.<br>**DRM_ERR_UNKNOWN**: An internal error occurs. Check the log details.|
