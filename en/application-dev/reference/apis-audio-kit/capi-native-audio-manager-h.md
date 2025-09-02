# native_audio_manager.h

## Overview

The file declares the functions related to an audio manager.

**Library**: libohaudio.so

**File to include**: <ohaudio/native_audio_manager.h>

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioManager](capi-oh-audiomanager.md) | OH_AudioManager | Describes an audio manager, which is used for audio management.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioCommon_Result OH_GetAudioManager(OH_AudioManager **audioManager)](#oh_getaudiomanager) | - | Obtains an OH_AudioManager instance.<br>Before using the features related to the audio manager, you must obtain an OH_AudioManager instance. |
| [OH_AudioCommon_Result OH_GetAudioScene(OH_AudioManager* manager, OH_AudioScene *scene)](#oh_getaudioscene) | - | Obtains the audio scene.|

## Function Description

### OH_GetAudioManager()

```
OH_AudioCommon_Result OH_GetAudioManager(OH_AudioManager **audioManager)
```

**Description**

Obtains an OH_AudioManager instance.<br> Before using the features related to the audio manager, you must obtain an OH_AudioManager instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioManager](capi-oh-audiomanager.md) **audioManager | Double pointer to an [OH_AudioManager](capi-oh-audiomanager.md), which is used to receive the audio manager instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**: The **audioManager** parameter is nullptr. |

### OH_GetAudioScene()

```
OH_AudioCommon_Result OH_GetAudioScene(OH_AudioManager* manager, OH_AudioScene *scene)
```

**Description**

Obtains the audio scene.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioManager](capi-oh-audiomanager.md)* manager | Pointer to an [OH_AudioManager](capi-oh-audiomanager.md) instance, which is created by calling [OH_GetAudioManager](capi-native-audio-manager-h.md#oh_getaudiomanager).|
| [OH_AudioScene](capi-native-audio-common-h.md#oh_audioscene) *scene | Pointer to an [OH_AudioScene](capi-native-audio-common-h.md#oh_audioscene), which is used to receive the audio scene.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM**:<br>1. The **audioManager** parameter is nullptr.<br>2. The **scene** parameter is nullptr. |
