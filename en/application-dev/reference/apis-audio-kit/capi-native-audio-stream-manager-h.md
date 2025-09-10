# native_audio_stream_manager.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the functions related to an audio stream manager.

You can call the functions to create an audio stream manager and set and manage audio streams.

**File to include**: <ohaudio/native_audio_stream_manager.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 19

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioStreamManager](capi-ohaudio-oh-audiostreammanager.md) | OH_AudioStreamManager | Describes an audio stream manager, which is used to manage audio streams.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AudioCommon_Result OH_AudioManager_GetAudioStreamManager(OH_AudioStreamManager **streamManager)](#oh_audiomanager_getaudiostreammanager) | Obtains the handle to the audio stream manager.|
| [OH_AudioCommon_Result OH_AudioStreamManager_GetDirectPlaybackSupport(OH_AudioStreamManager *audioStreamManager, OH_AudioStreamInfo *streamInfo, OH_AudioStream_Usage usage, OH_AudioStream_DirectPlaybackMode *directPlaybackMode)](#oh_audiostreammanager_getdirectplaybacksupport) | Obtains the direct playback mode supported by an audio stream.|
| [OH_AudioCommon_Result OH_AudioStreamManager_IsAcousticEchoCancelerSupported(OH_AudioStreamManager *streamManager, OH_AudioStream_SourceType sourceType, bool *supported)](#oh_audiostreammanager_isacousticechocancelersupported) | Checks whether the audio stream of the specified source type supports acoustic echo cancellation.|
| [bool OH_AudioStreamManager_IsFastPlaybackSupported(OH_AudioStreamManager *streamManager, OH_AudioStreamInfo *streamInfo, OH_AudioStream_Usage usage)](#oh_audiostreammanager_isfastplaybacksupported) | Checks whether the current device supports low-latency playback for the specified audio stream information and usage scenario.|
| [bool OH_AudioStreamManager_IsFastRecordingSupported(OH_AudioStreamManager *streamManager, OH_AudioStreamInfo *streamInfo, OH_AudioStream_SourceType source)](#oh_audiostreammanager_isfastrecordingsupported) | Checks whether the current device supports low-latency recording for the specified audio stream information and usage scenario.|

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
| [OH_AudioStreamManager](capi-ohaudio-oh-audiostreammanager.md) **streamManager | Double pointer to the audio stream manager.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS = 0**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301**: The system status is incorrect.|

### OH_AudioStreamManager_GetDirectPlaybackSupport()

```
OH_AudioCommon_Result OH_AudioStreamManager_GetDirectPlaybackSupport(OH_AudioStreamManager *audioStreamManager, OH_AudioStreamInfo *streamInfo, OH_AudioStream_Usage usage, OH_AudioStream_DirectPlaybackMode *directPlaybackMode)
```

**Description**

Obtains the direct playback mode supported by an audio stream.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamManager](capi-ohaudio-oh-audiostreammanager.md) *audioStreamManager | Handle to the audio stream manager. The handle is obtained by calling [OH_AudioManager_GetAudioStreamManager](capi-native-audio-stream-manager-h.md#oh_audiomanager_getaudiostreammanager).|
| [OH_AudioStreamInfo](capi-ohaudio-oh-audiostreaminfo.md) *streamInfo | Pointer to the audio stream information.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage scenario of the audio stream.|
| [OH_AudioStream_DirectPlaybackMode](capi-native-audiostream-base-h.md#oh_audiostream_directplaybackmode) *directPlaybackMode | Pointer to [OH_AudioStream_DirectPlaybackMode](capi-native-audiostream-base-h.md#oh_audiostream_directplaybackmode), which is used to receive the direct playback mode supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS = 0**: The function is executed successfully.<br>         **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101**:<br>                                                        1. The **audioStreamManager** parameter is nullptr.<br>                                                        2. The **streamInfo** parameter is nullptr.<br>                                                        3. The **usage** parameter is invalid.<br>                                                        4. The **directPlaybackMode** parameter is nullptr.|

### OH_AudioStreamManager_IsAcousticEchoCancelerSupported()

```
OH_AudioCommon_Result OH_AudioStreamManager_IsAcousticEchoCancelerSupported(OH_AudioStreamManager *streamManager, OH_AudioStream_SourceType sourceType, bool *supported)
```

**Description**

Checks whether the audio stream of the specified source type supports acoustic echo cancellation.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamManager](capi-ohaudio-oh-audiostreammanager.md) *streamManager | Handle to the audio stream manager. The handle is obtained by calling [OH_AudioManager_GetAudioStreamManager](capi-native-audio-stream-manager-h.md#oh_audiomanager_getaudiostreammanager).|
| [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) sourceType | Usage scenario ([OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype)) of the audio input stream.|
| bool *supported | Pointer to the result for the support of acoustic echo cancellation. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | **AUDIOCOMMON_RESULT_SUCCESS = 0**: The function is executed successfully.<br>          **AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101**:<br>                                                    1. The **audioStreamManager** parameter is nullptr.<br>                                                    2. The **sourceType** parameter is invalid.<br>                                                    3. The **supported** parameter is nullptr.|

### OH_AudioStreamManager_IsFastPlaybackSupported()

```
bool OH_AudioStreamManager_IsFastPlaybackSupported(OH_AudioStreamManager *streamManager, OH_AudioStreamInfo *streamInfo, OH_AudioStream_Usage usage)
```

**Description**

Checks whether the current device supports low-latency playback for the specified audio stream information and usage scenario.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamManager](capi-ohaudio-oh-audiostreammanager.md) *streamManager | Handle to the audio stream manager. The handle is obtained by calling [OH_AudioManager_GetAudioStreamManager](capi-native-audio-stream-manager-h.md#oh_audiomanager_getaudiostreammanager).|
| [OH_AudioStreamInfo](capi-ohaudio-oh-audiostreaminfo.md) *streamInfo | Pointer to the audio stream information.|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage scenario of the audio stream.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of low-latency playback. **true** if supported, **false** otherwise.|

### OH_AudioStreamManager_IsFastRecordingSupported()

```
bool OH_AudioStreamManager_IsFastRecordingSupported(OH_AudioStreamManager *streamManager, OH_AudioStreamInfo *streamInfo, OH_AudioStream_SourceType source)
```

**Description**

Checks whether the current device supports low-latency recording for the specified audio stream information and usage scenario.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamManager](capi-ohaudio-oh-audiostreammanager.md) *streamManager | Handle to the audio stream manager. The handle is obtained by calling [OH_AudioManager_GetAudioStreamManager](capi-native-audio-stream-manager-h.md#oh_audiomanager_getaudiostreammanager).|
| [OH_AudioStreamInfo](capi-ohaudio-oh-audiostreaminfo.md) *streamInfo | Pointer to the audio stream information.|
| [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) source | Usage scenario of the audio stream.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result for the support of low-latency recording. **true** if supported, **false** otherwise.|
