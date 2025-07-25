# native_audio_resource_manager.h

## Overview

The file declares the functions related to an audio resource manager.

**File to include**: <ohaudio/native_audio_resource_manager.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 20

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioResourceManager](capi-ohaudio-oh-audioresourcemanager.md) | OH_AudioResourceManager | Describes an audio resource manager, which is used to manage audio resources.|
| [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md) | OH_AudioWorkgroup | Describes an audio group, which is used to group and manage key audio threads.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AudioCommon_Result OH_AudioManager_GetAudioResourceManager(OH_AudioResourceManager **resourceManager)](#oh_audiomanager_getaudioresourcemanager) | Obtains an audio resource manager.<br>Before using the features related to the audio resource manager, you must obtain an audio resource manager instance.|
| [OH_AudioCommon_Result OH_AudioResourceManager_CreateWorkgroup(OH_AudioResourceManager *resourceManager,const char *name, OH_AudioWorkgroup **group)](#oh_audioresourcemanager_createworkgroup) | Creates an audio workgroup.|
| [OH_AudioCommon_Result OH_AudioResourceManager_ReleaseWorkgroup(OH_AudioResourceManager *resourceManager,OH_AudioWorkgroup *group)](#oh_audioresourcemanager_releaseworkgroup) | Releases an audio workgroup.|
| [OH_AudioCommon_Result OH_AudioWorkgroup_AddCurrentThread(OH_AudioWorkgroup *group, int32_t *tokenId)](#oh_audioworkgroup_addcurrentthread) | Adds a thread to an audio workgroup.|
| [OH_AudioCommon_Result OH_AudioWorkgroup_RemoveThread(OH_AudioWorkgroup *group, int32_t tokenId)](#oh_audioworkgroup_removethread) | Removes a thread from an audio workgroup.|
| [OH_AudioCommon_Result OH_AudioWorkgroup_Start(OH_AudioWorkgroup *group, uint64_t startTime, uint64_t deadlineTime)](#oh_audioworkgroup_start) | Notifies the system that an audio workgroup starts working and provides the expected end time of the workgroup.|
| [OH_AudioCommon_Result OH_AudioWorkgroup_Stop(OH_AudioWorkgroup *group)](#oh_audioworkgroup_stop) | Notifies the system that an audio workgroup finishes working.|

## Function Description

### OH_AudioManager_GetAudioResourceManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioResourceManager(OH_AudioResourceManager **resourceManager)
```

**Description**

Obtains an audio resource manager.

Before using the features related to the audio resource manager, you must obtain an audio resource manager instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioResourceManager](capi-ohaudio-oh-audioresourcemanager.md) **resourceManager | Double pointer to an OH_AudioResourceManager instance, which is used to receive the created audio resource manager instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |  **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **resourceManager** parameter is nullptr.|

### OH_AudioResourceManager_CreateWorkgroup()

```
OH_AudioCommon_Result OH_AudioResourceManager_CreateWorkgroup(OH_AudioResourceManager *resourceManager,const char *name, OH_AudioWorkgroup **group)
```

**Description**

Creates an audio workgroup.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioResourceManager](capi-ohaudio-oh-audioresourcemanager.md) *resourceManager | Pointer to an OH_AudioResourceManager instance, which is created by calling [OH_AudioManager_GetAudioResourceManager](capi-native-audio-resource-manager-h.md#oh_audiomanager_getaudioresourcemanager).|
| const char *name | Pointer to the name of the audio workgroup.|
| [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md) **group | Double pointer to an OH_AudioWorkgroup instance, which is used to receive the created audio workgroup instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>1. The **resourceManager** parameter is nullptr.<br>2. The **name** parameter is nullptr.<br>3. The **group** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The workgroup fails to be created, and the returned workgroup is nullptr. |

### OH_AudioResourceManager_ReleaseWorkgroup()

```
OH_AudioCommon_Result OH_AudioResourceManager_ReleaseWorkgroup(OH_AudioResourceManager *resourceManager,OH_AudioWorkgroup *group)
```

**Description**

Releases an audio workgroup.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioResourceManager](capi-ohaudio-oh-audioresourcemanager.md) *resourceManager | Pointer to an OH_AudioResourceManager instance, which is created by calling [OH_AudioManager_GetAudioResourceManager](capi-native-audio-resource-manager-h.md#oh_audiomanager_getaudioresourcemanager).|
| [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md) *group | Pointer to an OH_AudioWorkgroup instance, which is created by calling [OH_AudioResourceManager_CreateWorkgroup](capi-native-audio-resource-manager-h.md#oh_audioresourcemanager_createworkgroup).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>1. The **resourceManager** parameter is nullptr.<br>2. The **group** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The workgroup fails to be released. |

### OH_AudioWorkgroup_AddCurrentThread()

```
OH_AudioCommon_Result OH_AudioWorkgroup_AddCurrentThread(OH_AudioWorkgroup *group, int32_t *tokenId)
```

**Description**

Adds a thread to an audio workgroup.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md) *group | Pointer to an OH_AudioWorkgroup instance, which is created by calling [OH_AudioResourceManager_CreateWorkgroup](capi-native-audio-resource-manager-h.md#oh_audioresourcemanager_createworkgroup).|
| int32_t *tokenId | Pointer to the ID of the thread to be added to the audio workgroup.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |  **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **group** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The thread fails to be added to the workgroup.|

### OH_AudioWorkgroup_RemoveThread()

```
OH_AudioCommon_Result OH_AudioWorkgroup_RemoveThread(OH_AudioWorkgroup *group, int32_t tokenId)
```

**Description**

Removes a thread from an audio workgroup.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md) *group | Pointer to an OH_AudioWorkgroup instance, which is created by calling [OH_AudioResourceManager_CreateWorkgroup](capi-native-audio-resource-manager-h.md#oh_audioresourcemanager_createworkgroup).|
| int32_t tokenId | ID of the thread to be removed from the audio workgroup.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |  **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **group** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The thread fails to be removed from the workgroup.|

### OH_AudioWorkgroup_Start()

```
OH_AudioCommon_Result OH_AudioWorkgroup_Start(OH_AudioWorkgroup *group, uint64_t startTime, uint64_t deadlineTime)
```

**Description**

Notifies the system that an audio workgroup starts working and provides the expected end time of the workgroup.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md) *group | Pointer to an OH_AudioWorkgroup instance, which is created by calling [OH_AudioResourceManager_CreateWorkgroup](capi-native-audio-resource-manager-h.md#oh_audioresourcemanager_createworkgroup).|
| uint64_t startTime | Time when the audio workgroup starts working.|
| uint64_t deadlineTime | Expected end time of the audio workgroup.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |  **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **group** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The workgroup fails to notify the system of the start.|

### OH_AudioWorkgroup_Stop()

```
OH_AudioCommon_Result OH_AudioWorkgroup_Stop(OH_AudioWorkgroup *group)
```

**Description**

Notifies the system that an audio workgroup finishes working.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioWorkgroup](capi-ohaudio-oh-audioworkgroup.md) *group | Pointer to an OH_AudioWorkgroup instance, which is created by calling [OH_AudioResourceManager_CreateWorkgroup](capi-native-audio-resource-manager-h.md#oh_audioresourcemanager_createworkgroup).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **group** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE**: The workgroup fails to notify the system of the end.|
