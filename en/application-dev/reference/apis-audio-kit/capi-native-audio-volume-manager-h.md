# native_audio_volume_manager.h

## Overview

The file declares the functions related to an audio volume manager. You can call the functions to create an audio volume manager.

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 20

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) | OH_AudioVolumeManager | Describes an audio volume manager, which provides various functions for obtaining system volume information.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AudioVolumeManager_OnStreamVolumeChangeCallback)(void *userData,OH_AudioStream_Usage usage,int32_t volumeLevel,bool updateUi)](#oh_audiovolumemanager_onstreamvolumechangecallback) | OH_AudioVolumeManager_OnStreamVolumeChangeCallback | Defines the prototype of the volume change callback function, which is passed in [OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_registerstreamvolumechangecallback).|
| [typedef void (\*OH_AudioVolumeManager_OnRingerModeChangeCallback)(void *userData,OH_AudioRingerMode ringerMode)](#oh_audiovolumemanager_onringermodechangecallback) | OH_AudioVolumeManager_OnRingerModeChangeCallback | Defines the prototype of the ringer mode change callback function, which is passed in [OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_registerstreamvolumechangecallback).|
| [OH_AudioCommon_Result OH_AudioManager_GetAudioVolumeManager(OH_AudioVolumeManager **volumeManager)](#oh_audiomanager_getaudiovolumemanager) | - | Obtains an OH_AudioVolumeManager instance.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_GetMaxVolumeByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, int32_t *maxVolumeLevel)](#oh_audiovolumemanager_getmaxvolumebyusage) | - | Obtains the maximum volume level of an audio stream of a specified usage type.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_GetMinVolumeByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, int32_t *minVolumeLevel)](#oh_audiovolumemanager_getminvolumebyusage) | - | Obtains the minimum volume level of an audio stream of a specified usage type.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_GetVolumeByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, int32_t *volumeLevel)](#oh_audiovolumemanager_getvolumebyusage) | - | Obtains the system volume level of an audio stream of a specified usage type.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_IsMuteByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, bool *muted)](#oh_audiovolumemanager_ismutebyusage) | - | Checks whether an audio stream of a specified usage type is muted.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback(OH_AudioVolumeManager *volumeManager, OH_AudioStream_Usage usage,OH_AudioVolumeManager_OnStreamVolumeChangeCallback callback, void *userData)](#oh_audiovolumemanager_registerstreamvolumechangecallback) | - | Registers the volume change callback function.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_UnregisterStreamVolumeChangeCallback(OH_AudioVolumeManager *volumeManager,OH_AudioVolumeManager_OnStreamVolumeChangeCallback callback)](#oh_audiovolumemanager_unregisterstreamvolumechangecallback) | - | Unregisters the volume change callback function.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_GetRingerMode(OH_AudioVolumeManager *volumeManager,OH_AudioRingerMode *ringerMode)](#oh_audiovolumemanager_getringermode) | - | Obtains the ringer mode in use.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_RegisterRingerModeChangeCallback(OH_AudioVolumeManager *volumeManager,OH_AudioVolumeManager_OnRingerModeChangeCallback callback, void *userData)](#oh_audiovolumemanager_registerringermodechangecallback) | - | Registers the ringer mode change callback function.|
| [OH_AudioCommon_Result OH_AudioVolumeManager_UnregisterRingerModeChangeCallback(OH_AudioVolumeManager *volumeManager,OH_AudioVolumeManager_OnRingerModeChangeCallback callback)](#oh_audiovolumemanager_unregisterringermodechangecallback) | - | Unregisters the ringer mode change callback function.|

## Function Description

### OH_AudioVolumeManager_OnStreamVolumeChangeCallback()

```
typedef void (*OH_AudioVolumeManager_OnStreamVolumeChangeCallback)(void *userData,OH_AudioStream_Usage usage,int32_t volumeLevel,bool updateUi)
```

**Description**

Defines the prototype of the volume change callback function, which is passed in [OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_registerstreamvolumechangecallback).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| void *userData | Pointer to user data.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage type of the audio stream for which the volume is changed.|
| int32_t volumeLevel | Volume level after change.|
| bool updateUi | Whether to update the UI accordingly.|

### OH_AudioVolumeManager_OnRingerModeChangeCallback()

```
typedef void (*OH_AudioVolumeManager_OnRingerModeChangeCallback)(void *userData,OH_AudioRingerMode ringerMode)
```

**Description**

Defines the prototype of the ringer mode change callback function, which is passed in [OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_registerstreamvolumechangecallback).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| void *userData | Pointer to user data.|
| [OH_AudioRingerMode](capi-native-audio-common-h.md#oh_audioringermode) ringerMode | Ringer mode after change.|

### OH_AudioManager_GetAudioVolumeManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioVolumeManager(OH_AudioVolumeManager **volumeManager)
```

**Description**

Obtains an OH_AudioVolumeManager instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) **volumeManager | Double pointer to an OH_AudioVolumeManager instance, which is used to receive the created audio volume manager instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** parameter is nullptr.|

### OH_AudioVolumeManager_GetMaxVolumeByUsage()

```
OH_AudioCommon_Result OH_AudioVolumeManager_GetMaxVolumeByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, int32_t *maxVolumeLevel)
```

**Description**

Obtains the maximum volume level of an audio stream of a specified usage type.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage type of the audio stream.|
| int32_t *maxVolumeLevel | Pointer to the maximum volume level.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **maxVolumeLevel** parameter is nullptr, or **usage** is invalid.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_GetMinVolumeByUsage()

```
OH_AudioCommon_Result OH_AudioVolumeManager_GetMinVolumeByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, int32_t *minVolumeLevel)
```

**Description**

Obtains the minimum volume level of an audio stream of a specified usage type.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage type of the audio stream.|
| int32_t *minVolumeLevel | Pointer to the minimum volume level.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **minVolumeLevel** parameter is nullptr, or **usage** is invalid.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_GetVolumeByUsage()

```
OH_AudioCommon_Result OH_AudioVolumeManager_GetVolumeByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, int32_t *volumeLevel)
```

**Description**

Obtains the system volume level of an audio stream of a specified usage type.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage type of the audio stream.|
| int32_t *volumeLevel | Pointer to the system volume level.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **volumeLevel** parameter is nullptr, or **usage** is invalid.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_IsMuteByUsage()

```
OH_AudioCommon_Result OH_AudioVolumeManager_IsMuteByUsage(OH_AudioVolumeManager *volumeManager,OH_AudioStream_Usage usage, bool *muted)
```

**Description**

Checks whether an audio stream of a specified usage type is muted.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage type of the audio stream.|
| bool *muted | Pointer to the check result.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **muted** parameter is nullptr, or **usage** is invalid.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback()

```
OH_AudioCommon_Result OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback(OH_AudioVolumeManager *volumeManager, OH_AudioStream_Usage usage,OH_AudioVolumeManager_OnStreamVolumeChangeCallback callback, void *userData)
```

**Description**

Registers the volume change callback function.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage type of the audio stream.|
| [OH_AudioVolumeManager_OnStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_onstreamvolumechangecallback) callback | [OH_AudioVolumeManager_OnStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_onstreamvolumechangecallback), which is called when the volume of the audio stream changes.|
| void *userData | Pointer to user data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager**, **usage**, or **callback** parameter is nullptr, or **usage** is invalid.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_UnregisterStreamVolumeChangeCallback()

```
OH_AudioCommon_Result OH_AudioVolumeManager_UnregisterStreamVolumeChangeCallback(OH_AudioVolumeManager *volumeManager,OH_AudioVolumeManager_OnStreamVolumeChangeCallback callback)
```

**Description**

Unregisters the volume change callback function.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioVolumeManager_OnStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_onstreamvolumechangecallback) callback | Pointer to the callback function passed by [OH_AudioVolumeManager_RegisterStreamVolumeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_registerstreamvolumechangecallback).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **callback** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_GetRingerMode()

```
OH_AudioCommon_Result OH_AudioVolumeManager_GetRingerMode(OH_AudioVolumeManager *volumeManager,OH_AudioRingerMode *ringerMode)
```

**Description**

Obtains the ringer mode in use.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioRingerMode](capi-native-audio-common-h.md#oh_audioringermode) *ringerMode | Pointer to the ringer mode.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **ringerMode** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_RegisterRingerModeChangeCallback()

```
OH_AudioCommon_Result OH_AudioVolumeManager_RegisterRingerModeChangeCallback(OH_AudioVolumeManager *volumeManager,OH_AudioVolumeManager_OnRingerModeChangeCallback callback, void *userData)
```

**Description**

Registers the ringer mode change callback function.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioVolumeManager_OnRingerModeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_onringermodechangecallback) callback | [OH_AudioVolumeManager_OnRingerModeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_onringermodechangecallback), which is called when the ringer mode changes.|
| void *userData | Pointer to user data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **callback** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|

### OH_AudioVolumeManager_UnregisterRingerModeChangeCallback()

```
OH_AudioCommon_Result OH_AudioVolumeManager_UnregisterRingerModeChangeCallback(OH_AudioVolumeManager *volumeManager,OH_AudioVolumeManager_OnRingerModeChangeCallback callback)
```

**Description**

Unregisters the ringer mode change callback function.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVolumeManager](capi-ohaudio-oh-audiovolumemanager.md) *volumeManager | Pointer to an OH_AudioVolumeManager instance.|
| [OH_AudioVolumeManager_OnRingerModeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_onringermodechangecallback) callback | Pointer to the callback function passed by [OH_AudioVolumeManager_RegisterRingerModeChangeCallback](capi-native-audio-volume-manager-h.md#oh_audiovolumemanager_registerringermodechangecallback).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **volumeManager** or **callback** parameter is nullptr.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM**: A system processing error occurs.|
