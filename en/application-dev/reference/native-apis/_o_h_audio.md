# OHAudio


## Overview

The **OHAudio** module provides native APIs of the audio module.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_audiocapturer.h](native__audiocapturer_8h.md) | Declares the functions related to an audio capturer.<br>**File to include**: &lt;ohaudio/native_audiocapturer.h&gt;<br>**Library**: libohaudio.so| 
| [native_audiorenderer.h](native__audiorenderer_8h.md) | Declares the functions related to an audio renderer.<br>**File to include**: &lt;ohaudio/native_audiorenderer.h&gt;<br>**Library**: libohaudio.so| 
| [native_audiostream_base.h](native__audiostream__base_8h.md) | Declares the basic data structure of **OHAudio**.<br>**File to include**: &lt;ohaudio/native_audiostream_base.h&gt;<br>**Library**: libohaudio.so| 
| [native_audiostreambuilder.h](native__audiostreambuilder_8h.md) | Declares the functions related to the audio stream builder.<br>**File to include**: &lt;ohaudio/native_audiostreambuilder.h&gt;<br>**Library**: libohaudio.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio renderer.| 
| [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio capturer.| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_AudioStreamBuilder](#oh_audiostreambuilder) | Defines an audio stream builder.| 
| [OH_AudioRenderer](#oh_audiorenderer) | Defines an audio renderer.| 
| [OH_AudioCapturer](#oh_audiocapturer) | Defines an audio capturer.| 
| [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) | Defines a pointer to the callback functions related to an audio renderer.| 
| [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) | Defines a pointer to the callback functions related to an audio capturer.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AudioStream_Result](#oh_audiostream_result) { AUDIOSTREAM_SUCCESS, AUDIOSTREAM_ERROR_INVALID_PARAM, AUDIOSTREAM_ERROR_ILLEGAL_STATE, AUDIOSTREAM_ERROR_SYSTEM } | Enumerates the audio stream result codes.| 
| [OH_AudioStream_Type](#oh_audiostream_type) { AUDIOSTREAM_TYPE_RENDERER = 1, AUDIOSTREAM_TYPE_CAPTURER = 2 } | Enumerates the audio stream types.| 
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) { AUDIOSTREAM_SAMPLE_U8 = 0, AUDIOSTREAM_SAMPLE_S16LE = 1, AUDIOSTREAM_SAMPLE_S24LE = 2, AUDIOSTREAM_SAMPLE_S32LE = 3 } | Enumerates the sampling formats of audio streams.| 
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) { **AUDIOSTREAM_ENCODING_TYPE_RAW** = 0 } | Enumerates the encoding types of audio streams.| 
| [OH_AudioStream_Usage](#oh_audiostream_usage) { **AUDIOSTREAM_USAGE_UNKNOWN** = 0, **AUDIOSTREAM_USAGE_MUSIC** = 1, **AUDIOSTREAM_USAGE_COMMUNICATION** = 2, **AUDIOSTREAM_USAGE_GAME** = 11 } | Enumerates the usage scenarios of audio output streams.| 
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) { AUDIOSTREAM_LATENCY_MODE_NORMAL = 0, AUDIOSTREAM_LATENCY_MODE_FAST = 1} | Enumerates the latency modes of audio streams.| 
| [OH_AudioStream_State](#oh_audiostream_state) {<br>AUDIOSTREAM_STATE_INVALID = -1, AUDIOSTREAM_STATE_PREPARED = 1, AUDIOSTREAM_STATE_RUNNING = 2, AUDIOSTREAM_STATE_STOPPED = 3,<br>AUDIOSTREAM_STATE_RELEASED = 4, AUDIOSTREAM_STATE_PAUSED = 5<br>} | Enumerates the audio stream states.| 
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) { **AUDIOSTREAM_SOURCE_TYPE_INVALID** = -1, **AUDIOSTREAM_SOURCE_TYPE_MIC**, **AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION** = 1, **AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION** = 7 } | Enumerates the usage scenarios of audio input streams.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioCapturer_Release](#oh_audiocapturer_release) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Releases an audio capturer.| 
| [OH_AudioCapturer_Start](#oh_audiocapturer_start) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Starts an audio capturer.| 
| [OH_AudioCapturer_Pause](#oh_audiocapturer_pause) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Pauses an audio capturer.| 
| [OH_AudioCapturer_Stop](#oh_audiocapturer_stop) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Stops an audio capturer.| 
| [OH_AudioCapturer_Flush](#oh_audiocapturer_flush) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer) | Flushes obtained audio data.| 
| [OH_AudioCapturer_GetCurrentState](#oh_audiocapturer_getcurrentstate) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | Obtains the state of an audio capturer.| 
| [OH_AudioCapturer_GetLatencyMode](#oh_audiocapturer_getlatencymode) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | Obtains the latency mode of an audio capturer.| 
| [OH_AudioCapturer_GetStreamId](#oh_audiocapturer_getstreamid) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*streamId) | Obtains the stream ID of an audio capturer.| 
| [OH_AudioCapturer_GetSamplingRate](#oh_audiocapturer_getsamplingrate) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*rate) | Obtains the sampling rate of an audio capturer.| 
| [OH_AudioCapturer_GetChannelCount](#oh_audiocapturer_getchannelcount) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*channelCount) | Obtains the number of channels for an audio capturer.| 
| [OH_AudioCapturer_GetSampleFormat](#oh_audiocapturer_getsampleformat) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio capturer.| 
| [OH_AudioCapturer_GetEncodingType](#oh_audiocapturer_getencodingtype) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio capturer.| 
| [OH_AudioCapturer_GetCapturerInfo](#oh_audiocapturer_getcapturerinfo) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) \*sourceType) | Obtains the usage scenario of an audio capturer.| 
| [OH_AudioRenderer_Release](#oh_audiorenderer_release) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Releases an audio renderer.| 
| [OH_AudioRenderer_Start](#oh_audiorenderer_start) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Starts an audio renderer.| 
| [OH_AudioRenderer_Pause](#oh_audiorenderer_pause) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Pauses an audio renderer.| 
| [OH_AudioRenderer_Stop](#oh_audiorenderer_stop) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Stops an audio renderer.| 
| [OH_AudioRenderer_Flush](#oh_audiorenderer_flush) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Flushes written audio data.| 
| [OH_AudioRenderer_GetCurrentState](#oh_audiorenderer_getcurrentstate) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_State](#oh_audiostream_state) \*state) | Obtains the state of an audio renderer.| 
| [OH_AudioRenderer_GetSamplingRate](#oh_audiorenderer_getsamplingrate) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*rate) | Obtains the sampling rate of an audio renderer.| 
| [OH_AudioRenderer_GetStreamId](#oh_audiorenderer_getstreamid) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*streamId) | Obtains the stream ID of an audio renderer.| 
| [OH_AudioRenderer_GetChannelCount](#oh_audiorenderer_getchannelcount) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*channelCount) | Obtains the number of channels for an audio renderer.| 
| [OH_AudioRenderer_GetSampleFormat](#oh_audiorenderer_getsampleformat) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio renderer.| 
| [OH_AudioRenderer_GetLatencyMode](#oh_audiorenderer_getlatencymode) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode) | Obtains the latency mode of an audio renderer.| 
| [OH_AudioRenderer_GetRendererInfo](#oh_audiorenderer_getrendererinfo) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](#oh_audiostream_usage) \*usage) | Obtains the usage scenario of an audio renderer.| 
| [OH_AudioRenderer_GetEncodingType](#oh_audiorenderer_getencodingtype) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio renderer.| 
| [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](#oh_audiostream_type) type) | Creates an audio stream builder, which can be an audio renderer or capturer.| 
| [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder) | Destroys an audio stream builder.| 
| [OH_AudioStreamBuilder_SetSamplingRate](#oh_audiostreambuilder_setsamplingrate) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t rate) | Sets the sampling rate of an audio stream.| 
| [OH_AudioStreamBuilder_SetChannelCount](#oh_audiostreambuilder_setchannelcount) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t channelCount) | Sets the number of channels for an audio stream.| 
| [OH_AudioStreamBuilder_SetSampleFormat](#oh_audiostreambuilder_setsampleformat) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) format) | Sets the sampling format of an audio stream.| 
| [OH_AudioStreamBuilder_SetEncodingType](#oh_audiostreambuilder_setencodingtype) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) encodingType) | Sets the encoding type of an audio stream.| 
| [OH_AudioStreamBuilder_SetLatencyMode](#oh_audiostreambuilder_setlatencymode) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) latencyMode) | Sets the latency mode of an audio stream.| 
| [OH_AudioStreamBuilder_SetRendererInfo](#oh_audiostreambuilder_setrendererinfo) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](#oh_audiostream_usage) usage) | Sets the usage scenario of an audio renderer.| 
| [OH_AudioStreamBuilder_SetCapturerInfo](#oh_audiostreambuilder_setcapturerinfo) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType) | Sets the usage scenario of an audio capturer.| 
| [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio renderer.| 
| [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio capturer.| 
| [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](#oh_audiorenderer) \*\*audioRenderer) | Creates an audio renderer instance.| 
| [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](#oh_audiocapturer) \*\*audioCapturer) | Creates an audio capturer instance.| 


### Variables

| Name| Description| 
| -------- | -------- |
| (\*[OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnWriteData](#oh_audiorenderer_onwritedata) )([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*buffer, int32_t lenth) | Defines a function pointer to the callback function used to write audio data.| 
| (\*[OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnReadData](#oh_audiocapturer_onreaddata) )([OH_AudioCapturer](#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t lenth) | Defines a function pointer to the callback function used to read audio data.| 


## Type Description


### OH_AudioCapturer

  
```
typedef struct OH_AudioCapturerStruct OH_AudioCapturer
```

**Description**

Defines an audio capturer.

An audio capturer instance is used to capture audio data.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10


### OH_AudioCapturer_Callbacks

  
```
typedef struct OH_AudioCapturer_Callbacks_Struct OH_AudioCapturer_Callbacks
```

**Description**

Defines a pointer to the callback functions related to an audio capturer.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10


### OH_AudioRenderer

  
```
typedef struct OH_AudioRendererStruct OH_AudioRenderer
```

**Description**

Defines an audio renderer.

An audio renderer instance is used to render audio data.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10


### OH_AudioRenderer_Callbacks

  
```
typedef struct OH_AudioRenderer_Callbacks_Struct OH_AudioRenderer_Callbacks
```

**Description**

Defines a pointer to the callback functions related to an audio renderer.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10


### OH_AudioStreamBuilder

  
```
typedef struct OH_AudioStreamBuilderStruct OH_AudioStreamBuilder
```

**Description**

Defines an audio stream builder.

An audio stream builder instance is often used to create an audio stream and set its attributes.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10


## Enum Description


### OH_AudioStream_EncodingType

  
```
enum OH_AudioStream_EncodingType
```

**Description**

Enumerates the encoding types of audio streams.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_ENCODING_TYPE_RAW | PCM encoding.| 


### OH_AudioStream_LatencyMode

  
```
enum OH_AudioStream_LatencyMode
```

**Description**

Enumerates the latency modes of audio streams.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_LATENCY_MODE_NORMAL | Normal latency mode.| 
| AUDIOSTREAM_LATENCY_MODE_FAST | Low latency mode.| 


### OH_AudioStream_Result

  
```
enum OH_AudioStream_Result
```

**Description**

Enumerates the audio stream result codes.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_SUCCESS | Operation successful.| 
| AUDIOSTREAM_ERROR_INVALID_PARAM | Invalid input parameter.| 
| AUDIOSTREAM_ERROR_ILLEGAL_STATE | Invalid state.| 
| AUDIOSTREAM_ERROR_SYSTEM | System error.| 


### OH_AudioStream_SampleFormat

  
```
enum OH_AudioStream_SampleFormat
```

**Description**

Enumerates the sampling formats of audio streams.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_SAMPLE_U8 | Unsigned 8-bit.| 
| AUDIOSTREAM_SAMPLE_S16LE | Short 16-bit little-endian.| 
| AUDIOSTREAM_SAMPLE_S24LE | Short 24-bit little-endian.| 
| AUDIOSTREAM_SAMPLE_S32LE | Short 32-bit little-endian.| 


### OH_AudioStream_SourceType

  
```
enum OH_AudioStream_SourceType
```

**Description**

Enumerates the usage scenarios of an audio capturer, that is, the usage scenarios of audio input streams.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_SOURCE_TYPE_INVALID | Invalid state.| 
| AUDIOSTREAM_SOURCE_TYPE_MIC | Audio recording.| 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION | Voice recognition.| 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION | Voice communication.| 


### OH_AudioStream_State

  
```
enum OH_AudioStream_State
```

**Description**

Enumerates the audio stream states.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_STATE_INVALID | Invalid state.| 
| AUDIOSTREAM_STATE_PREPARED | Prepared.| 
| AUDIOSTREAM_STATE_RUNNING | Running.| 
| AUDIOSTREAM_STATE_STOPPED | Stopped.| 
| AUDIOSTREAM_STATE_RELEASED | Released.| 
| AUDIOSTREAM_STATE_PAUSED | Paused.| 


### OH_AudioStream_Type

  
```
enum OH_AudioStream_Type
```

**Description**

Enumerates the audio stream types.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_TYPE_RENDERER | The audio stream is an output stream.| 
| AUDIOSTREAM_TYPE_CAPTURER | The audio stream is an input stream.| 


### OH_AudioStream_Usage

  
```
enum OH_AudioStream_Usage
```

**Description**

Enumerates the usage scenarios of an audio renderer, that is, the usage scenarios of audio output streams.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

  | Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_USAGE_UNKNOWN | Undefined.| 
| AUDIOSTREAM_USAGE_MUSIC | Music.| 
| AUDIOSTREAM_USAGE_COMMUNICATION | Voice communication.| 
| AUDIOSTREAM_USAGE_GAME | Gaming.| 


## Function Description


### OH_AudioCapturer_Flush()

  
```
OH_AudioStream_Result OH_AudioCapturer_Flush (OH_AudioCapturer * capturer)
```

**Description**

Flushes obtained audio data.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetCapturerInfo()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo (OH_AudioCapturer * capturer, OH_AudioStream_SourceType * sourceType )
```

**Description**

Obtains the usage scenario of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| sourceType | Pointer to a variable used to receive the usage scenario.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetChannelCount()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetChannelCount (OH_AudioCapturer * capturer, int32_t * channelCount )
```

**Description**

Obtains the number of channels for an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| channelCount | Pointer to a variable used to receive the number of channels.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetCurrentState()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetCurrentState (OH_AudioCapturer * capturer, OH_AudioStream_State * state )
```

**Description**

Obtains the state of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| state | Pointer to a variable used to receive the state.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetEncodingType()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetEncodingType (OH_AudioCapturer * capturer, OH_AudioStream_EncodingType * encodingType )
```

**Description**

Obtains the encoding type of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| encodingType | Pointer to a variable used to receive the encoding type.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetLatencyMode()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode (OH_AudioCapturer * capturer, OH_AudioStream_LatencyMode * latencyMode )
```

**Description**

Obtains the latency mode of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| latencyMode | Pointer to a variable used to receive the latency mode.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetSampleFormat()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat (OH_AudioCapturer * capturer, OH_AudioStream_SampleFormat * sampleFormat )
```

**Description**

Obtains the sampling format of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| sampleFormat | Pointer to a variable used to receive the sampling format.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetSamplingRate()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate (OH_AudioCapturer * capturer, int32_t * rate )
```

**Description**

Obtains the sampling rate of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| rate | Pointer to a variable used to receive the sampling rate.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_GetStreamId()

  
```
OH_AudioStream_Result OH_AudioCapturer_GetStreamId (OH_AudioCapturer * capturer, uint32_t * streamId )
```

**Description**

Obtains the stream ID of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| streamId | Pointer to a variable used to receive the stream ID.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_Pause()

  
```
OH_AudioStream_Result OH_AudioCapturer_Pause (OH_AudioCapturer * capturer)
```

**Description**

Pauses an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_Release()

  
```
OH_AudioStream_Result OH_AudioCapturer_Release (OH_AudioCapturer * capturer)
```

**Description**

Releases an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_Start()

  
```
OH_AudioStream_Result OH_AudioCapturer_Start (OH_AudioCapturer * capturer)
```

**Description**

Starts an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioCapturer_Stop()

  
```
OH_AudioStream_Result OH_AudioCapturer_Stop (OH_AudioCapturer * capturer)
```

**Description**

Stops an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_Flush()

  
```
OH_AudioStream_Result OH_AudioRenderer_Flush (OH_AudioRenderer * renderer)
```

**Description**

Flushes written audio data.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetChannelCount()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount (OH_AudioRenderer * renderer, int32_t * channelCount )
```

**Description**

Obtains the number of channels for an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| channelCount | Pointer to a variable used to receive the number of channels.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetCurrentState()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState (OH_AudioRenderer * renderer, OH_AudioStream_State * state )
```

**Description**

Obtains the state of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| state | Pointer to a variable used to receive the state.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetEncodingType()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType (OH_AudioRenderer * renderer, OH_AudioStream_EncodingType * encodingType )
```

**Description**

Obtains the encoding type of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| encodingType | Pointer to a variable used to receive the encoding type.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetLatencyMode()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode (OH_AudioRenderer * renderer, OH_AudioStream_LatencyMode * latencyMode )
```

**Description**

Obtains the latency mode of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| latencyMode | Pointer to a variable used to receive the latency mode.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetRendererInfo()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo (OH_AudioRenderer * renderer, OH_AudioStream_Usage * usage )
```

**Description**

Obtains the usage scenario of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| usage | Pointer to a variable used to receive the usage scenario.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetSampleFormat()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat (OH_AudioRenderer * renderer, OH_AudioStream_SampleFormat * sampleFormat )
```

**Description**

Obtains the sampling format of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| sampleFormat | Pointer to a variable used to receive the sampling format.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetSamplingRate()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate (OH_AudioRenderer * renderer, int32_t * rate )
```

**Description**

Obtains the sampling rate of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| rate | Pointer to a variable used to receive the sampling rate.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_GetStreamId()

  
```
OH_AudioStream_Result OH_AudioRenderer_GetStreamId (OH_AudioRenderer * renderer, uint32_t * streamId )
```

**Description**

Obtains the stream ID of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| streamId | Pointer to a variable used to receive the stream ID.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_Pause()

  
```
OH_AudioStream_Result OH_AudioRenderer_Pause (OH_AudioRenderer * renderer)
```

**Description**

Pauses an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_Release()

  
```
OH_AudioStream_Result OH_AudioRenderer_Release (OH_AudioRenderer * renderer)
```

**Description**

Releases an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_Start()

  
```
OH_AudioStream_Result OH_AudioRenderer_Start (OH_AudioRenderer * renderer)
```

**Description**

Starts an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioRenderer_Stop()

  
```
OH_AudioStream_Result OH_AudioRenderer_Stop (OH_AudioRenderer * renderer)
```

**Description**

Stops an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_Create()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_Create (OH_AudioStreamBuilder ** builder, OH_AudioStream_Type type )
```

**Description**

Creates an audio stream builder, which can be an audio renderer or capturer.

You need to call **OH_AudioStreamBuilder_Destroy()** to destroy the builder when it is no longer required.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Double pointer to the audio stream builder created.| 
| type | Type of the audio stream builder, which can be **AUDIOSTREAM_TYPE_RENDERER** or **AUDIOSTREAM_TYPE_CAPTURER**.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_Destroy()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy (OH_AudioStreamBuilder * builder)
```

**Description**

Destroys an audio stream builder when it is no longer required.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_GenerateCapturer()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer (OH_AudioStreamBuilder * builder, OH_AudioCapturer ** audioCapturer )
```

**Description**

Creates an audio capturer instance.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| audioCapturer | Double pointer to the audio capturer instance created.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_GenerateRenderer()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer (OH_AudioStreamBuilder * builder, OH_AudioRenderer ** audioRenderer )
```

**Description**

Creates an audio renderer instance.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| audioRenderer | Double pointer to the audio renderer instance created.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetCapturerCallback()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback (OH_AudioStreamBuilder * builder, OH_AudioCapturer_Callbacks callbacks, void * userData )
```

**Description**

Sets callbacks for an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| callbacks | Callback functions that will be used to process events related to input audio streams.| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetCapturerInfo()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo (OH_AudioStreamBuilder * builder, OH_AudioStream_SourceType sourceType )
```

**Description**

Sets the usage scenario of an audio capturer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| sourceType | Usage scenario of the audio capturer.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetChannelCount()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount (OH_AudioStreamBuilder * builder, int32_t channelCount )
```

**Description**

Sets the number of channels for an audio stream.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| channelCount | Number of channels.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetEncodingType()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType (OH_AudioStreamBuilder * builder, OH_AudioStream_EncodingType encodingType )
```

**Description**

Sets the encoding type of an audio stream.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| encodingType | Encoding type, which can be **AUDIOSTREAM_ENCODING_PCM**.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetLatencyMode()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode (OH_AudioStreamBuilder * builder, OH_AudioStream_LatencyMode latencyMode )
```

**Description**

Sets the latency mode of an audio stream.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| latencyMode | Latency mode.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetRendererCallback()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback (OH_AudioStreamBuilder * builder, OH_AudioRenderer_Callbacks callbacks, void * userData )
```

**Description**

Sets callbacks for an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| callbacks | Callback functions that will be used to process events related to output audio streams.| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetRendererInfo()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo (OH_AudioStreamBuilder * builder, OH_AudioStream_Usage usage )
```

**Description**

Sets the usage scenario of an audio renderer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| usage | Usage scenario of the audio renderer.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetSampleFormat()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat (OH_AudioStreamBuilder * builder, OH_AudioStream_SampleFormat format )
```

**Description**

Sets the sampling format of an audio stream.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| format | Sampling format.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


### OH_AudioStreamBuilder_SetSamplingRate()

  
```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate (OH_AudioStreamBuilder * builder, int32_t rate )
```

**Description**

Sets the sampling rate of an audio stream.

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| channelCount | Sampling rate.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

10


## Variable Description


### OH_AudioCapturer_OnReadData

  
```
int32_t(* OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnReadData) (OH_AudioCapturer *capturer, void *userData, void *buffer, int32_t lenth)
```

**Description**

Defines a function pointer to the callback function used to read audio data.

**Since**

10


### OH_AudioRenderer_OnWriteData

  
```
int32_t(* OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnWriteData) (OH_AudioRenderer *renderer, void *userData, void *buffer, int32_t lenth)
```

**Description**

Defines a function pointer to the callback function used to write audio data.

**Since**

10
