# native_audio_stream_manager.h

## Overview

The file declares the functions related to an audio stream manager.

You can call the functions to create an audio stream manager and set and manage audio streams.


**Library**: libohaudio.so

**File to include**: <ohaudio/native_audio_stream_manager.h>

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 19

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioStreamManager](capi-oh-audiostreammanager.md) | OH_AudioStreamManager | Describes an audio stream manager, which is used to manage audio streams.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AudioCommon_Result OH_AudioManager_GetAudioStreamManager(OH_AudioStreamManager **streamManager)](#oh_audiomanager_getaudiostreammanager) | Obtains the handle to the audio stream manager.|
| [OH_AudioCommon_Result OH_AudioStreamManager_GetDirectPlaybackSupport(OH_AudioStreamManager *audioStreamManager, OH_AudioStreamInfo *streamInfo,OH_AudioStream_Usage usage, OH_AudioStream_DirectPlaybackMode *directPlaybackMode)](#oh_audiostreammanager_getdirectplaybacksupport) | Obtains the direct playback mode supported by an audio stream.|

## Function Description

### OH_AudioManager_GetAudioStreamManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioStreamManager(OH_AudioStreamManager **streamManager)
```

**Description**

Obtains the handle to the audio stream manager.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamManager](capi-oh-audiostreammanager.md) **streamManager | Double pointer to the audio stream manager.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS = 0**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301**: The system status is incorrect.|

### OH_AudioStreamManager_GetDirectPlaybackSupport()

```
OH_AudioCommon_Result OH_AudioStreamManager_GetDirectPlaybackSupport(OH_AudioStreamManager *audioStreamManager, OH_AudioStreamInfo *streamInfo,OH_AudioStream_Usage usage, OH_AudioStream_DirectPlaybackMode *directPlaybackMode)
```

**Description**

Obtains the direct playback mode supported by an audio stream.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamManager](capi-oh-audiostreammanager.md) *audioStreamManager | Handle to the audio stream manager. The handle is obtained by calling [OH_AudioManager_GetAudioStreamManager](capi-native-audio-stream-manager-h.md#oh_audiomanager_getaudiostreammanager).|
| [OH_AudioStreamInfo](capi-oh-audiostreaminfo.md) *streamInfo | Pointer to the audio stream information.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage scenario of the audio stream.|
| [OH_AudioStream_DirectPlaybackMode](capi-native-audiostream-base-h.md#oh_audiostream_directplaybackmode) *directPlaybackMode | Pointer to [OH_AudioStream_DirectPlaybackMode](capi-native-audiostream-base-h.md#oh_audiostream_directplaybackmode), which is used to receive the direct playback mode supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result):<br>**AUDIOCOMMON_RESULT_SUCCESS = 0**: The function is executed successfully.<br>**AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101**:<br>1. The **audioStreamManager** parameter is nullptr.<br>2. The **streamInfo** parameter is nullptr.<br>3. The **usage** parameter is invalid.<br>4. The **directPlaybackMode** parameter is nullptr. |


