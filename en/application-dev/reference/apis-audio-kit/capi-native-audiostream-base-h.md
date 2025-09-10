# native_audiostream_base.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the basic data structure of OHAudio.

**File to include**: <ohaudio/native_audiostream_base.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioStreamInfo](capi-ohaudio-oh-audiostreaminfo.md) | OH_AudioStreamInfo | Describes the audio stream information, which is used to describe the basic audio format.|
| [OH_AudioRenderer_Callbacks_Struct](capi-ohaudio-oh-audiorenderer-callbacks-struct.md) | OH_AudioRenderer_Callbacks | Describes a pointer to the callbacks related to an audio renderer.|
| [OH_AudioCapturer_Callbacks_Struct](capi-ohaudio-oh-audiocapturer-callbacks-struct.md) | OH_AudioCapturer_Callbacks | Describes a pointer to the callbacks related to an audio capturer.<br> To avoid unexpected behavior, ensure that every member variable of the struct is initialized by a custom callback method or a null pointer when setting the audio callback functions.|
| [OH_AudioStreamBuilderStruct](capi-ohaudio-oh-audiostreambuilderstruct.md) | OH_AudioStreamBuilder | Defines a struct for an audio stream builder. An audio stream builder instance is often used to create an audio stream and set its attributes.|
| [OH_AudioRendererStruct](capi-ohaudio-oh-audiorendererstruct.md) | OH_AudioRenderer | Describes an audio renderer, which is used to render audio data.|
| [OH_AudioCapturerStruct](capi-ohaudio-oh-audiocapturerstruct.md) | OH_AudioCapturer | Describes an audio capturer, which is used to capture audio data.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioStream_Result](#oh_audiostream_result) | OH_AudioStream_Result | Enumerates the audio operation results.|
| [OH_AudioStream_Type](#oh_audiostream_type) | OH_AudioStream_Type | Enumerates the audio stream types.|
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) | OH_AudioStream_SampleFormat | Enumerates the sampling formats of audio streams.|
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) | OH_AudioStream_EncodingType | Enumerates the encoding types of audio streams.|
| [OH_AudioStream_Usage](#oh_audiostream_usage) | OH_AudioStream_Usage | Enumerates the usage scenarios of an audio renderer,<br> that is, usage scenarios of audio output streams.|
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) | OH_AudioStream_LatencyMode | Enumerates the latency modes of audio streams.|
| [OH_AudioStream_DirectPlaybackMode](#oh_audiostream_directplaybackmode) | OH_AudioStream_DirectPlaybackMode | Enumerates the direct playback modes of audio streams.|
| [OH_AudioStream_VolumeMode](#oh_audiostream_volumemode) | OH_AudioStream_VolumeMode | Enumerates the volume modes of audio streams.|
| [OH_AudioStream_State](#oh_audiostream_state) | OH_AudioStream_State | Enumerates the audio stream states.|
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) | OH_AudioStream_SourceType | Enumerates the usage scenarios of an audio capturer,<br> that is, usage scenarios of audio input streams.|
| [OH_AudioStream_Event](#oh_audiostream_event) | OH_AudioStream_Event | Enumerates the audio stream events.|
| [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) | OH_AudioInterrupt_ForceType | Enumerates the types of force that causes audio interruption.<br> The force type is obtained when an audio interruption event is received.<br> This type specifies whether the audio interruption operation is forcibly performed by the system. The operation information (such as audio pause or stop) can be obtained through [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint).|
| [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) | OH_AudioInterrupt_Hint | Enumerates the hints provided along with audio interruption.<br> The hint is obtained when an audio interruption event is received.<br> The hint specifies the operation (such as audio pause or volume adjustment) to be performed on audio streams based on the focus strategy.<br> You can determine whether the operation is forcibly performed by the system based on [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype).|
| [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) | OH_AudioInterrupt_Mode | Enumerates the audio interruption modes.|
| [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) | OH_AudioStream_AudioEffectMode | Enumerates the audio effect modes.|
| [OH_AudioStream_FastStatus](#oh_audiostream_faststatus) | OH_AudioStream_FastStatus | Enumerates the low-latency statuses.|
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) | OH_AudioStream_DeviceChangeReason | Enumerates the reasons for audio stream device changes.|
| [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) | OH_AudioStream_PrivacyType | Enumerates the privacy types of an audio stream. The privacy type specifies whether the audio stream can be recorded by other applications.|
| [OH_AudioData_Callback_Result](#oh_audiodata_callback_result) | OH_AudioData_Callback_Result | Enumerates the audio data callback results.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AudioRenderer_OutputDeviceChangeCallback)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_DeviceChangeReason reason)](#oh_audiorenderer_outputdevicechangecallback) | OH_AudioRenderer_OutputDeviceChangeCallback | Defines a pointer to the callback invoked when the audio capturer device changes.|
| [typedef void (\*OH_AudioRenderer_OnMarkReachedCallback)(OH_AudioRenderer* renderer, uint32_t samplePos, void* userData)](#oh_audiorenderer_onmarkreachedcallback) | OH_AudioRenderer_OnMarkReachedCallback | Defines a pointer to the callback invoked when the mark position is reached.|
| [typedef int32_t (\*OH_AudioRenderer_WriteDataWithMetadataCallback)(OH_AudioRenderer* renderer, void* userData, void* audioData, int32_t audioDataSize, void* metadata, int32_t metadataSize)](#oh_audiorenderer_writedatawithmetadatacallback) | OH_AudioRenderer_WriteDataWithMetadataCallback | Defines a function pointer to the callback used to write audio data and metadata.|
| [typedef OH_AudioData_Callback_Result (\*OH_AudioRenderer_OnWriteDataCallback)(OH_AudioRenderer* renderer, void* userData, void* audioData, int32_t audioDataSize)](#oh_audiorenderer_onwritedatacallback) | OH_AudioRenderer_OnWriteDataCallback | Defines a function pointer to the callback used to write audio data.<br> The callback is used only to write audio data. Do not call AudioRenderer APIs in it.<br> The return result indicates whether the data filled in the buffer is valid. If the data is invalid, the data entered by the user will not be played. Once the callback finishes its execution, the audio service queues the data pointed to by **audioData** for playback. Therefore, do not change the data outside the callback. It is crucial to fill **audioData** with the exact length (specified by **audioDataSize**) of data designated for playback; otherwise, noises may occur during playback.|
| [typedef int32_t (\*OH_AudioRenderer_OnWriteDataCallbackAdvanced)(OH_AudioRenderer* renderer, void* userData, void* audioData, int32_t audioDataSize)](#oh_audiorenderer_onwritedatacallbackadvanced) | OH_AudioRenderer_OnWriteDataCallbackAdvanced | Defines a function pointer to the callback used to write audio data. Unlike **OH_AudioRenderer_OnWriteDataCallback**, this function allows the application to fill data of the length ranging [0, audioDataSize].<br> Here, **audioDataSize** refers to the length of the callback buffer. The caller notifies the system of the length of the data written through the return value.<br> If the return value is 0, the callback thread sleeps for a period of time.<br> Otherwise, the system may immediately initiates the next callback.|

## Enum Description

### OH_AudioStream_Result

```
enum OH_AudioStream_Result
```

**Description**

Enumerates the audio operation results.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_SUCCESS = 0 | Operation successful.|
| AUDIOSTREAM_ERROR_INVALID_PARAM = 1 | Invalid input parameter.|
| AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2 | Invalid state.|
| AUDIOSTREAM_ERROR_SYSTEM = 3 | System error.|
| AUDIOSTREAM_ERROR_UNSUPPORTED_FORMAT = 4 | Unsupported audio format, such as unsupported encoding type or sampling format.<br>**Since**: 19|

### OH_AudioStream_Type

```
enum OH_AudioStream_Type
```

**Description**

Enumerates the audio stream types.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_TYPE_RENDERER = 1 | The audio stream is an output stream.|
| AUDIOSTREAM_TYPE_CAPTURER = 2 | The audio stream is an input stream.|

### OH_AudioStream_SampleFormat

```
enum OH_AudioStream_SampleFormat
```

**Description**

Enumerates the sampling formats of audio streams.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_SAMPLE_U8 = 0 | Unsigned 8-bit.|
| AUDIOSTREAM_SAMPLE_S16LE = 1 | Short 16-bit little-endian.|
| AUDIOSTREAM_SAMPLE_S24LE = 2 | Short 24-bit little-endian.|
| AUDIOSTREAM_SAMPLE_S32LE = 3 | Short 32-bit little-endian.|
| AUDIOSTREAM_SAMPLE_F32LE = 4 | Float 32-bit little-endian.<br>**Since**: 17|

### OH_AudioStream_EncodingType

```
enum OH_AudioStream_EncodingType
```

**Description**

Enumerates the encoding types of audio streams.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_ENCODING_TYPE_RAW = 0 | PCM encoding.|
| AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1 | Audio Vivid encoding.<br>**Since**: 12|
| AUDIOSTREAM_ENCODING_TYPE_E_AC3 = 2 | E_AC3 encoding.<br>**Since**: 19|

### OH_AudioStream_Usage

```
enum OH_AudioStream_Usage
```

**Description**

Enumerates the usage scenarios of an audio renderer, that is, usage scenarios of audio output streams.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_USAGE_UNKNOWN = 0 | Unknown content.|
| AUDIOSTREAM_USAGE_MUSIC = 1 | Music.|
| AUDIOSTREAM_USAGE_VOICE_COMMUNICATION = 2 | VoIP voice call.|
| AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3 | Voice assistant.|
| AUDIOSTREAM_USAGE_ALARM = 4 | Alarming.|
| AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5 | Voice message.|
| AUDIOSTREAM_USAGE_RINGTONE = 6 | Ringtone.|
| AUDIOSTREAM_USAGE_NOTIFICATION = 7 | Notification.|
| AUDIOSTREAM_USAGE_ACCESSIBILITY = 8 | Accessibility.|
| AUDIOSTREAM_USAGE_MOVIE = 10 | Movie or video.|
| AUDIOSTREAM_USAGE_GAME = 11 | Gaming.|
| AUDIOSTREAM_USAGE_AUDIOBOOK = 12 | Audiobooks (including crosstalks and storytelling), news radio, and podcasts.|
| AUDIOSTREAM_USAGE_NAVIGATION = 13 | Navigation.|
| AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION = 17 | VoIP video call.<br>**Since**: 12|

### OH_AudioStream_LatencyMode

```
enum OH_AudioStream_LatencyMode
```

**Description**

Enumerates the latency modes of audio streams.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_LATENCY_MODE_NORMAL = 0 | Normal latency mode.|
| AUDIOSTREAM_LATENCY_MODE_FAST = 1 | Low latency mode.|

### OH_AudioStream_DirectPlaybackMode

```
enum OH_AudioStream_DirectPlaybackMode
```

**Description**

Enumerates the direct playback modes of audio streams.

**Since**: 19

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_DIRECT_PLAYBACK_NOT_SUPPORTED = 0 | Direct playback is not supported.|
| AUDIOSTREAM_DIRECT_PLAYBACK_BITSTREAM_SUPPORTED = 1 | Direct playback of bit streams (without decoding) is supported.|
| AUDIOSTREAM_DIRECT_PLAYBACK_PCM_SUPPORTED = 2 | Direct playback of PCM-encoded audio is supported.|

### OH_AudioStream_VolumeMode

```
enum OH_AudioStream_VolumeMode
```

**Description**

Enumerates the volume modes of audio streams.

**Since**: 19

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_VOLUMEMODE_SYSTEM_GLOBAL = 0 | System-level volume (default mode).|
| AUDIOSTREAM_VOLUMEMODE_APP_INDIVIDUAL = 1 | Application-level volume.<br> In this mode, you can set and query the application volume through the provided functions.|

### OH_AudioStream_State

```
enum OH_AudioStream_State
```

**Description**

Enumerates the audio stream states.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_STATE_INVALID = -1 | Invalid state.|
| AUDIOSTREAM_STATE_NEW = 0 | Newly created.|
| AUDIOSTREAM_STATE_PREPARED = 1 | Prepared.|
| AUDIOSTREAM_STATE_RUNNING = 2 | Running.|
| AUDIOSTREAM_STATE_STOPPED = 3 | Stopped.|
| AUDIOSTREAM_STATE_RELEASED = 4 | Released.|
| AUDIOSTREAM_STATE_PAUSED = 5 | Paused.|

### OH_AudioStream_SourceType

```
enum OH_AudioStream_SourceType
```

**Description**

Enumerates the usage scenarios of an audio capturer, that is, usage scenarios of audio input streams.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_SOURCE_TYPE_INVALID = -1 | Invalid state.|
| AUDIOSTREAM_SOURCE_TYPE_MIC = 0 | Audio recording.|
| AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1 | Voice recognition.|
| AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2 | Audio playback.|
| AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7 | Voice communication.|
| AUDIOSTREAM_SOURCE_TYPE_VOICE_MESSAGE = 10 | Voice message.<br>**Since**: 12|
| AUDIOSTREAM_SOURCE_TYPE_CAMCORDER = 13 | Video recording.<br>**Since**: 13|
| AUDIOSTREAM_SOURCE_TYPE_UNPROCESSED = 14 | Raw microphone recording, where the system does not perform any algorithm processing.<br>**Since**: 14|
| AUDIOSTREAM_SOURCE_TYPE_LIVE = 17 | Live.<br>**Since**: 20|

### OH_AudioStream_Event

```
enum OH_AudioStream_Event
```

**Description**

Enumerates the audio stream events.

**Since**: 10

**Deprecated from**: 20

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0 | The audio route has been changed.<br>**Since**: 10<br>**Deprecated from**: 20<br>**Substitute**: [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback)|

### OH_AudioInterrupt_ForceType

```
enum OH_AudioInterrupt_ForceType
```

**Description**

Enumerates the types of force that causes audio interruption.

The force type is obtained when an audio interruption event is received.

This type specifies whether the audio interruption operation is forcibly performed by the system. The operation information (such as audio pause or stop) can be obtained through [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint).

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_INTERRUPT_FORCE = 0 | The operation is forcibly performed by the system.|
| AUDIOSTREAM_INTERRUPT_SHARE = 1 | The operation will not be performed by the system. [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) is used to provide recommended operations for the application, and the application can determine the next processing mode.|

### OH_AudioInterrupt_Hint

```
enum OH_AudioInterrupt_Hint
```

**Description**

Enumerates the hints provided along with audio interruption.

The hint is obtained when an audio interruption event is received.

The hint specifies the operation (such as audio pause or volume adjustment) to be performed on audio streams based on the focus strategy.

You can determine whether the operation is forcibly performed by the system based on [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype).

**Since**: 10

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_INTERRUPT_HINT_NONE = 0 | None.|
| AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1 | A hint is displayed, indicating that the audio stream is restored. The application can proactively trigger operations related to rendering or recording.<br> This operation cannot be forcibly performed by the system, and the corresponding [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) must be **AUDIOSTREAM_INTERRUPT_SHARE**.|
| AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2 | A hint is displayed, indicating that the audio stream is paused and the audio focus is lost temporarily.<br> The **AUDIOSTREAM_INTERRUPT_HINT_RESUME** event will be triggered when the focus is gained.|
| AUDIOSTREAM_INTERRUPT_HINT_STOP = 3 | A hint is displayed, indicating that the audio stream stops and the audio focus is lost.|
| AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4 | A hint is displayed, indicating that audio ducking starts and the audio is played at a lower volume.|
| AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5 | A hint is displayed, indicating that audio ducking ends and the audio is played at the normal volume.|
| AUDIOSTREAM_INTERRUPT_HINT_MUTE = 6 | A hint is displayed, indicating that the audio is muted.<br>**Since**: 20|
| AUDIOSTREAM_INTERRUPT_HINT_UNMUTE = 7 | A hint is displayed, indicating that the audio is unmuted.<br>**Since**: 20|

### OH_AudioInterrupt_Mode

```
enum OH_AudioInterrupt_Mode
```

**Description**

Enumerates the audio interruption modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0 | Shared mode.|
| AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 | Independent mode.|

### OH_AudioStream_AudioEffectMode

```
enum OH_AudioStream_AudioEffectMode
```

**Description**

Enumerates the audio effect modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| EFFECT_NONE = 0 | No audio effect used.|
| EFFECT_DEFAULT = 1 | Default audio effect mode.|

### OH_AudioStream_FastStatus

```
enum OH_AudioStream_FastStatus
```

**Description**

Enumerates the low-latency statuses.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| AUDIOSTREAM_FASTSTATUS_NORMAL = 0 | Normal audio stream status.|
| AUDIOSTREAM_FASTSTATUS_FAST = 1 | Low-latency audio stream status.|

### OH_AudioStream_DeviceChangeReason

```
enum OH_AudioStream_DeviceChangeReason
```

**Description**

Enumerates the reasons for audio stream device changes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| REASON_UNKNOWN = 0 | Unknown reason.|
| REASON_NEW_DEVICE_AVAILABLE = 1 | A new device is available.|
| REASON_OLD_DEVICE_UNAVAILABLE = 2 | The old device is unavailable. When this reason is reported, the application should consider pausing audio playback.|
| REASON_OVERRODE = 3 | The user or system forcibly changes the device.|
| REASON_SESSION_ACTIVATED = 4 | The audio session has been activated.<br>**Since**: 20|
| REASON_STREAM_PRIORITY_CHANGED = 5 | An audio stream with higher priority appears.<br>**Since**: 20|

### OH_AudioStream_PrivacyType

```
enum OH_AudioStream_PrivacyType
```

**Description**

Enumerates the privacy types of an audio stream. The privacy type specifies whether the audio stream can be recorded by other applications.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| AUDIO_STREAM_PRIVACY_TYPE_PUBLIC = 0 | The audio stream can be recorded by other applications.|
| AUDIO_STREAM_PRIVACY_TYPE_PRIVATE = 1 | The audio stream cannot be recorded by other applications.|

### OH_AudioData_Callback_Result

```
enum OH_AudioData_Callback_Result
```

**Description**

Enumerates the audio data callback results.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| AUDIO_DATA_CALLBACK_RESULT_INVALID = -1 | The audio data callback result is invalid, and the audio data will not be played.|
| AUDIO_DATA_CALLBACK_RESULT_VALID = 0 | The audio data callback result is valid, and the audio data will be played.|


## Function Description

### OH_AudioRenderer_OutputDeviceChangeCallback()

```
typedef void (*OH_AudioRenderer_OutputDeviceChangeCallback)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_DeviceChangeReason reason)
```

**Description**

Defines a pointer to the callback invoked when the audio capturer device changes.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
|  void* userData | Pointer to the application data passed through the callback.|
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) reason | Reason for the audio stream device change.|

### OH_AudioRenderer_OnMarkReachedCallback()

```
typedef void (*OH_AudioRenderer_OnMarkReachedCallback)(OH_AudioRenderer* renderer, uint32_t samplePos, void* userData)
```

**Description**

Defines a pointer to the callback invoked when the mark position is reached.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
|  uint32_t samplePos | Mark position.|
|  void* userData | Pointer to the application data passed through the callback.|

### OH_AudioRenderer_WriteDataWithMetadataCallback()

```
typedef int32_t (*OH_AudioRenderer_WriteDataWithMetadataCallback)(OH_AudioRenderer* renderer, void* userData, void* audioData, int32_t audioDataSize, void* metadata, int32_t metadataSize)
```

**Description**

Defines a function pointer to the callback used to write audio data and metadata.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
|  void* userData | Pointer to the application data passed through the callback.|
|  void* audioData | Pointer to the audio data written by the user.|
|  int32_t audioDataSize | Length of the audio data, in bytes.|
|  void* metadata | Pointer to the metadata written by the user.|
|  int32_t metadataSize | Length of the metadata, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Error code of the callback.|

### OH_AudioRenderer_OnWriteDataCallback()

```
typedef OH_AudioData_Callback_Result (*OH_AudioRenderer_OnWriteDataCallback)(OH_AudioRenderer* renderer, void* userData, void* audioData, int32_t audioDataSize)
```

**Description**

Defines a function pointer to the callback used to write audio data.

The callback is used only to write audio data. Do not call AudioRenderer APIs in it.

The return result indicates whether the data filled in the buffer is valid. If the data is invalid, the data entered by the user will not be played. Once the callback finishes its execution, the audio service queues the data pointed to by **audioData** for playback. Therefore, do not change the data outside the callback. It is crucial to fill **audioData** with the exact length (specified by **audioDataSize**) of data designated for playback; otherwise, noises may occur during playback.

The **audioDataSize** parameter can be set by calling [OH_AudioStreamBuilder_SetFrameSizeInCallback](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setframesizeincallback).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
|  void* userData | Pointer to the application data passed through the callback.|
|  void* audioData | Pointer to the audio data written by the user.|
|  int32_t audioDataSize | Length of the audio data, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioData_Callback_Result](#oh_audiodata_callback_result) | **AUDIO_DATA_CALLBACK_RESULT_INVALID**: The audio data callback result is invalid, and the audio data will not be played.<br>         **AUDIO_DATA_CALLBACK_RESULT_VALID**: The audio data callback result is valid, and the audio data will be played.|

### OH_AudioRenderer_OnWriteDataCallbackAdvanced()

```
typedef int32_t (*OH_AudioRenderer_OnWriteDataCallbackAdvanced)(OH_AudioRenderer* renderer, void* userData, void* audioData, int32_t audioDataSize)
```

**Description**

Defines a function pointer to the callback used to write audio data. Unlike **OH_AudioRenderer_OnWriteDataCallback**, this function allows the application to fill data of the length ranging [0, audioDataSize].

Here, **audioDataSize** refers to the length of the callback buffer. The caller notifies the system of the length of the data written through the return value.

If the return value is 0, the callback thread sleeps for a period of time.

Otherwise, the system may immediately initiates the next callback.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to the instance for which the callback occurs.|
|  void* userData | Pointer to the application data passed through the callback.|
|  void* audioData | Pointer to the audio data to be filled by the application.|
|  int32_t audioDataSize | Length of the audio data, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Actual length of valid audio data filled by the application. The return value must be in the range of [0, audioDataSize].<br>If the return value is less than 0, the system adjusts it to 0. If the return value is greater than **audioDataSize**, the system adjusts it to **audioDataSize**.<br>Note that the return value must be an integer multiple of the size of a single sampling point.<br>For example, for audio data in stereo s16 format, it must be an integer multiple of 4 (216/8).<br>Failure to do so may result in playback noise.|
