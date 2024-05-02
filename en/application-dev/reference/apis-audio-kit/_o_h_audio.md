# OHAudio


## Overview

The **OHAudio** module provides C APIs of the audio module.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_audiocapturer.h](native__audiocapturer_8h.md) | Declares the functions related to an audio capturer.<br>**File to include**: &lt;ohaudio/native_audiocapturer.h&gt;<br>**Library**: libohaudio.so| 
| [native_audiorenderer.h](native__audiorenderer_8h.md) | Declares the functions related to an audio renderer.<br>**File to include**: &lt;ohaudio/native_audiorenderer.h&gt;<br>**Library**: libohaudio.so| 
| [native_audiostream_base.h](native__audiostream__base_8h.md) | Declares the basic data structure of **OHAudio**.<br>**File to include**: &lt;ohaudio/native_audiostream_base.h&gt;<br>**Library**: libohaudio.so| 
| [native_audiostreambuilder.h](native__audiostreambuilder_8h.md) | Declares the functions related to an audio stream builder.<br>**File to include**: &lt;ohaudio/native_audiostreambuilder.h&gt;<br>**Library**: libohaudio.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio renderer.| 
| struct  [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio capturer.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct OH_AudioStreamBuilderStruct [OH_AudioStreamBuilder](#oh_audiostreambuilder)                                                                  | Defines an audio stream builder.| 
| typedef struct OH_AudioRendererStruct [OH_AudioRenderer](#oh_audiorenderer)                                                                                 | Defines an audio renderer.| 
| typedef struct OH_AudioCapturerStruct [OH_AudioCapturer](#oh_audiocapturer)                                                                                 | Defines an audio capturer.| 
| typedef struct [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) | Defines a pointer to the callback functions related to an audio renderer.| 
| typedef struct [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) | Defines a pointer to the callback functions related to an audio capturer.| 
| typedef void(\* [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback)) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) reason) | Defines a pointer to the callback invoked when the audio stream device changes.| 
| typedef void(\* [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback)) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, void \*userData) | Defines a pointer to the callback invoked when the mark position is reached. | 
| typedef int32_t(\* [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback)) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize, void \*metadata, int32_t metadataSize) | Defines a function pointer to the callback function used to write audio data and metadata. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AudioStream_Result](#oh_audiostream_result) {<br>AUDIOSTREAM_SUCCESS = 0,<br>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br>AUDIOSTREAM_ERROR_SYSTEM = 3<br>} | Enumerates the audio stream operation results.| 
| [OH_AudioStream_Type](#oh_audiostream_type) {<br>AUDIOSTREAM_TYPE_RERNDERER = 1,<br>AUDIOSTREAM_TYPE_CAPTURER = 2<br>} | Enumerates the audio stream types.| 
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) {<br>AUDIOSTREAM_SAMPLE_U8 = 0,<br>AUDIOSTREAM_SAMPLE_S16LE = 1,<br>AUDIOSTREAM_SAMPLE_S24LE = 2,<br>AUDIOSTREAM_SAMPLE_S32LE = 3<br>} | Enumerates the sampling formats of audio streams.| 
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) { <br>AUDIOSTREAM_ENCODING_TYPE_RAW = 0, <br>AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1 <br>} | Enumerates the encoding types of audio streams. | 
| [OH_AudioStream_Usage](#oh_audiostream_usage) {<br>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br>AUDIOSTREAM_USAGE_MUSIC = 1,<br>AUDIOSTREAM_USAGE_COMMUNICATION = 2,<br>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br>AUDIOSTREAM_USAGE_ALARM = 4,<br>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br>AUDIOSTREAM_USAGE_RINGTONE = 6,<br>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br>AUDIOSTREAM_USAGE_MOVIE = 10,<br>AUDIOSTREAM_USAGE_GAME = 11,<br>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br>AUDIOSTREAM_USAGE_NAVIGATION = 13<br>} | Enumerates the usage scenarios of audio streams.| 
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) {<br>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br>} | Enumerates the latency modes of audio streams.| 
| [OH_AudioStream_State](#oh_audiostream_state) {<br>AUDIOSTREAM_STATE_INVALID = -1,<br>AUDIOSTREAM_STATE_NEW = 0,<br>AUDIOSTREAM_STATE_PREPARED = 1,<br>AUDIOSTREAM_STATE_RUNNING = 2,<br>AUDIOSTREAM_STATE_STOPPED = 3,<br>AUDIOSTREAM_STATE_RELEASED = 4,<br>AUDIOSTREAM_STATE_PAUSED = 5<br>} | Enumerates the audio stream states.| 
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) {<br>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7<br>} | Enumerates the usage scenarios of audio streams.| 
| [OH_AudioStream_Event](#oh_audiostream_event) {<br>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br>} | Enumerates the audio stream events.| 
| [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) {<br>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br>AUDIOSTREAM_INTERRUPT_SHARE = 1<br>} | Enumerates the types of force that causes audio interruption.| 
| [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) {<br>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br>} | Enumerates the hints provided along with audio interruption.| 
| [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) {<br> AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0, <br>AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 <br>} | Enumerates the audio interrupt modes. | 
| [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) { <br>EFFECT_NONE = 0, <br>EFFECT_DEFAULT = 1 <br>} | Enumerates the audio effect modes. | 
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) {<br>REASON_UNKNOWN = 0,<br>REASON_NEW_DEVICE_AVAILABLE = 1,<br>REASON_OLD_DEVICE_UNAVAILABLE = 2,<br>REASON_OVERRODE = 3<br>} | Enumerates the reasons for audio stream device changes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Release](#oh_audiocapturer_release)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                           | Releases an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Start](#oh_audiocapturer_start)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                               | Starts an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Pause](#oh_audiocapturer_pause)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                               | Pauses an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Stop](#oh_audiocapturer_stop)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                                 | Stops an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_Flush](#oh_audiocapturer_flush)([OH_AudioCapturer](#oh_audiocapturer) \*capturer)                                                                                               | Flushes obtained audio data.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCurrentState](#oh_audiocapturer_getcurrentstate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_State](#oh_audiostream_state) \*state)                    | Obtains the state of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetLatencyMode](#oh_audiocapturer_getlatencymode)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode)    | Obtains the latency mode of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetStreamId](#oh_audiocapturer_getstreamid)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*streamId)                                                              | Obtains the stream ID of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSamplingRate](#oh_audiocapturer_getsamplingrate)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*rate)                                                           | Obtains the sampling rate of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetChannelCount](#oh_audiocapturer_getchannelcount)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*channelCount)                                                   | Obtains the number of channels for an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetSampleFormat](#oh_audiocapturer_getsampleformat)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetEncodingType](#oh_audiocapturer_getencodingtype)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetCapturerInfo](#oh_audiocapturer_getcapturerinfo)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) \*sourceType)     | Obtains the usage scenario of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFrameSizeInCallback](#oh_audiocapturer_getframesizeincallback)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int32_t \*frameSize)                                        | Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetTimestamp](#oh_audiocapturer_gettimestamp)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp)                | Obtains the timestamp and position information of an audio input stream.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetFramesRead](#oh_audiocapturer_getframesread)([OH_AudioCapturer](#oh_audiocapturer) \*capturer, int64_t \*frames)                                                             | Obtains the number of frames that have been read since the stream was created.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioCapturer_GetOverflowCount](#oh_audiocapturer_getoverflowcount) ([OH_AudioCapturer](#oh_audiocapturer) \*capturer, uint32_t \*count) | Obtains the number of overloaded audio streams of an audio capturer. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Release](#oh_audiorenderer_release)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                           | Releases an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Start](#oh_audiorenderer_start)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                               | Starts an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Pause](#oh_audiorenderer_pause)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                               | Pauses an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Stop](#oh_audiorenderer_stop)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                                 | Stops an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_Flush](#oh_audiorenderer_flush)([OH_AudioRenderer](#oh_audiorenderer) \*renderer)                                                                                               | Flushes written audio data.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetCurrentState](#oh_audiorenderer_getcurrentstate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_State](#oh_audiostream_state) \*state)                    | Obtains the state of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSamplingRate](#oh_audiorenderer_getsamplingrate)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*rate)                                                           | Obtains the sampling rate of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetStreamId](#oh_audiorenderer_getstreamid)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*streamId)                                                              | Obtains the stream ID of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelCount](#oh_audiorenderer_getchannelcount)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*channelCount)                                                   | Obtains the number of channels for an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSampleFormat](#oh_audiorenderer_getsampleformat)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetLatencyMode](#oh_audiorenderer_getlatencymode)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) \*latencyMode)    | Obtains the latency mode of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetRendererInfo](#oh_audiorenderer_getrendererinfo)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](#oh_audiostream_usage) \*usage)                    | Obtains the usage scenario of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEncodingType](#oh_audiorenderer_getencodingtype)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFramesWritten](#oh_audiorenderer_getframeswritten)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int64_t \*frames)                                                       | Obtains the number of frames that have been written since the stream was created.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetTimestamp](#oh_audiorenderer_gettimestamp)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp)                | Obtains the timestamp and position information of an audio output stream.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetFrameSizeInCallback](#oh_audiorenderer_getframesizeincallback)([OH_AudioRenderer](#oh_audiorenderer) \*renderer, int32_t \*frameSize)                                        | Obtains the frame size in the callback.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetSpeed](#oh_audiorenderer_getspeed) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*speed) | Obtains the audio renderer rate.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetSpeed](#oh_audiorenderer_setspeed) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float speed) | Sets the audio renderer rate.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t samplePos, [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback) callback, void \*userData) | Sets the mark position for an audio renderer. When this function is called, the mark position that has been set will be overwritten. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_CancelMark](#oh_audiorenderer_cancelmark) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer) | Cancels the mark set by [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition). | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolume](#oh_audiorenderer_setvolume) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume) | Sets the volume for an audio stream. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetVolumeWithRamp](#oh_audiorenderer_setvolumewithramp) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float volume, int32_t durationMs) | Sets the volume with a ramp within the specified duration for an audio stream. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetVolume](#oh_audiorenderer_getvolume) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, float \*volume) | Obtains the volume of an audio stream. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetUnderflowCount](#oh_audiorenderer_getunderflowcount) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, uint32_t \*count) | Obtains the number of underloaded audio streams of an audio capturer. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetChannelLayout](#oh_audiorenderer_getchannellayout) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, OH_AudioChannelLayout \*channelLayout) | Obtains the channel layout of an audio stream. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_GetEffectMode](#oh_audiorenderer_geteffectmode) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) \*effectMode) | Obtains the effect mode of an audio stream. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioRenderer_SetEffectMode](#oh_audiorenderer_seteffectmode) ([OH_AudioRenderer](#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) effectMode) | Sets the effect mode for an audio stream. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](#oh_audiostream_type) type)                        | Creates an audio stream builder, which can be an audio renderer or capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder)                                                                        | Destroys an audio stream builder.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSamplingRate](#oh_audiostreambuilder_setsamplingrate)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t rate)                                          | Sets the sampling rate of an audio stream.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelCount](#oh_audiostreambuilder_setchannelcount)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t channelCount)                                  | Sets the number of channels for an audio stream.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetSampleFormat](#oh_audiostreambuilder_setsampleformat)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) format) | Sets the sampling format of an audio stream.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetEncodingType](#oh_audiostreambuilder_setencodingtype)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) encodingType) | Sets the encoding type of an audio stream.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetLatencyMode](#oh_audiostreambuilder_setlatencymode)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) latencyMode) | Sets the latency mode of an audio stream.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetChannelLayout](#oh_audiostreambuilder_setchannellayout) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, OH_AudioChannelLayout channelLayout) | Sets the channel layout for an audio stream. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInfo](#oh_audiostreambuilder_setrendererinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](#oh_audiostream_usage) usage)   | Sets the usage scenario of an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerInfo](#oh_audiostreambuilder_setcapturerinfo)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) sourceType) | Sets the usage scenario of an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](#oh_audiorenderer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio renderer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback](#oh_audiostreambuilder_setrendereroutputdevicechangecallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback) callback, void \*userData) | Sets the callback invoked when the audio stream device changes.|
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](#oh_audiocapturer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio capturer.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback](#oh_audiostreambuilder_setwritedatawithmetadatacallback) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_WriteDataWithMetadataCallback](#oh_audiorenderer_writedatawithmetadatacallback) callback, void \*userData) | Sets the callback invoked to write both audio data and metadata. | 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](#oh_audiorenderer) \*\*audioRenderer) | Creates an audio renderer instance.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](#oh_audiocapturer) \*\*audioCapturer) | Creates an audio capturer instance.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetFrameSizeInCallback](#oh_audiostreambuilder_setframesizeincallback)([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, int32_t frameSize) | Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity.| 
| [OH_AudioStream_Result](#oh_audiostream_result) [OH_AudioStreamBuilder_SetRendererInterruptMode](#oh_audiostreambuilder_setrendererinterruptmode) ([OH_AudioStreamBuilder](#oh_audiostreambuilder) \*builder, [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) mode) | Sets the interrupt mode of the stream client. | 


## Type Description


### OH_AudioCapturer

```
typedef struct OH_AudioCapturerStruct OH_AudioCapturer
```

**Description**

Defines an audio capturer.

An audio capturer instance is used to capture audio data.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioCapturer_Callbacks

```
typedef struct OH_AudioCapturer_Callbacks_Struct OH_AudioCapturer_Callbacks
```

**Description**

Defines a pointer to the callback functions related to an audio capturer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioRenderer

```
typedef struct OH_AudioRendererStruct OH_AudioRenderer
```

**Description**

Defines an audio renderer.

An audio renderer instance is used to render audio data.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioRenderer_Callbacks

```
typedef struct OH_AudioRenderer_Callbacks_Struct OH_AudioRenderer_Callbacks
```

**Description**

Defines a pointer to the callback functions related to an audio renderer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


### OH_AudioRenderer_OnMarkReachedCallback

```
typedef void(* OH_AudioRenderer_OnMarkReachedCallback) (OH_AudioRenderer *renderer, uint32_t samplePos, void *userData)
```
**Description**

Defines a pointer to the callback invoked when the mark position is reached.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| samplePos | Mark position. | 
| userData | Pointer to the application data passed through the callback functions. | 


### OH_AudioRenderer_OutputDeviceChangeCallback

```
typedef void(* OH_AudioRenderer_OutputDeviceChangeCallback) (OH_AudioRenderer *renderer, void *userData, OH_AudioStream_DeviceChangeReason reason)
```

**Description**

Defines a pointer to the callback invoked when the audio stream device changes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| userData | Pointer to the application data passed through the callback functions.| 
| reason | Enumerates the reasons for audio stream device changes.| 


### OH_AudioRenderer_WriteDataWithMetadataCallback

```
typedef int32_t(* OH_AudioRenderer_WriteDataWithMetadataCallback) (OH_AudioRenderer *renderer, void *userData, void *audioData, int32_t audioDataSize, void *metadata, int32_t metadataSize)
```
**Description**

Defines a function pointer to the callback function used to write audio data and metadata.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| userData | Pointer to the application data passed through the callback functions. | 
| audioData | Pointer to the audio data written by the user. | 
| audioDataSize | Length of the audio data, in bytes. | 
| metadata | Pointer to the metadata written by the user. | 
| metadataSize | Length of the metadata, in bytes. | 

**Returns**

Error code of the callback function.


### OH_AudioStreamBuilder

```
typedef struct OH_AudioStreamBuilderStruct OH_AudioStreamBuilder
```

**Description**

Defines an audio stream builder.

An audio stream builder instance is often used to create an audio stream and set its attributes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10


## Enum Description


### OH_AudioInterrupt_ForceType

```
enum OH_AudioInterrupt_ForceType
```

**Description**

Enumerates the types of force that causes audio interruption.

This enum is used to describe audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_FORCE | The system changes the audio status.| 
| AUDIOSTREAM_INTERRUPT_SHARE | The application changes the audio status.| 


### OH_AudioInterrupt_Hint

```
enum OH_AudioInterrupt_Hint
```

**Description**

Enumerates the types of force that causes audio interruption.

This enum is used to describe audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_HINT_NONE | None.| 
| AUDIOSTREAM_INTERRUPT_HINT_RESUME | Resume the playback.| 
| AUDIOSTREAM_INTERRUPT_HINT_PAUSE | Paused/Pause the playback.| 
| AUDIOSTREAM_INTERRUPT_HINT_STOP | Stopped/Stop the playback.| 
| AUDIOSTREAM_INTERRUPT_HINT_DUCK | Ducked the playback.| 
| AUDIOSTREAM_INTERRUPT_HINT_UNDUCK | Unducked the playback.| 


### OH_AudioInterrupt_Mode

```
enum OH_AudioInterrupt_Mode
```
**Description**

Enumerates the audio interrupt modes.

This enum is used to describe the audio interrupt mode.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_INTERRUPT_MODE_SHARE  | Sharing mode.| 
| AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT  | Independent mode.| 


### OH_AudioStream_AudioEffectMode

```
enum OH_AudioStream_AudioEffectMode
```
**Description**

Enumerates the audio effect modes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| EFFECT_NONE  | No audio effect used.  | 
| EFFECT_DEFAULT  | Default audio effect mode.  | 


### OH_AudioStream_DeviceChangeReason

```
enum OH_AudioStream_DeviceChangeReason
```

**Description**

Enumerates the reasons for audio stream device changes.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| REASON_UNKNOWN | Unknown reason.| 
| REASON_NEW_DEVICE_AVAILABLE | A new device is available.| 
| REASON_OLD_DEVICE_UNAVAILABLE | The old device is unavailable. When this reason is reported, the application should consider pausing audio playback.| 
| REASON_OVERRODE | The user or system forcibly changes the device.| 


### OH_AudioStream_EncodingType

```
enum OH_AudioStream_EncodingType
```

**Description**

Enumerates the encoding types of audio streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_ENCODING_TYPE_RAW | PCM encoding.| 
| AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID  | AudioVivid encoding.<br>**Since**: 12| 


### OH_AudioStream_Event

```
enum OH_AudioStream_Event
```

**Description**

Enumerates the audio stream events.

This enum is used to describe audio events.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_EVENT_ROUTING_CHANGED | The audio route has been changed.| 


### OH_AudioStream_LatencyMode

```
enum OH_AudioStream_LatencyMode
```

**Description**

Enumerates the latency modes of audio streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_LATENCY_MODE_NORMAL | Normal latency mode.| 
| AUDIOSTREAM_LATENCY_MODE_FAST | Low latency mode.| 


### OH_AudioStream_Result

```
enum OH_AudioStream_Result
```

**Description**

Enumerates the audio stream operation results.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_SUCCESS | The operation is successful.| 
| AUDIOSTREAM_ERROR_INVALID_PARAM | Invalid input parameter.| 
| AUDIOSTREAM_ERROR_ILLEGAL_STATE | Invalid state.| 
| AUDIOSTREAM_ERROR_SYSTEM | System error.| 


### OH_AudioStream_SampleFormat

```
enum OH_AudioStream_SampleFormat
```

**Description**

Enumerates the sampling formats of audio streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

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

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_SOURCE_TYPE_INVALID | Invalid state.| 
| AUDIOSTREAM_SOURCE_TYPE_MIC | Audio recording.| 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION | Voice recognition.| 
| AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE | Audio playback.| 
| AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION | Voice communication.| 


### OH_AudioStream_State

```
enum OH_AudioStream_State
```

**Description**

Enumerates the audio stream states.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_STATE_INVALID | Invalid state.| 
| AUDIOSTREAM_STATE_NEW | Newly created.| 
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

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_TYPE_RERNDERER | The audio stream is an output stream.| 
| AUDIOSTREAM_TYPE_CAPTURER | The audio stream is an input stream.| 


### OH_AudioStream_Usage

```
enum OH_AudioStream_Usage
```

**Description**

Enumerates the usage scenarios of an audio renderer, that is, the usage scenarios of audio output streams.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

| Value| Description| 
| -------- | -------- |
| AUDIOSTREAM_USAGE_UNKNOWN | Undefined.| 
| AUDIOSTREAM_USAGE_MUSIC | Music.| 
| AUDIOSTREAM_USAGE_COMMUNICATION | Voice communication.| 
| AUDIOSTREAM_USAGE_VOICE_ASSISTANT | Voice assistant.| 
| AUDIOSTREAM_USAGE_ALARM | Alarming.| 
| AUDIOSTREAM_USAGE_VOICE_MESSAGE | Voice message.| 
| AUDIOSTREAM_USAGE_RINGTONE | Ringtone.| 
| AUDIOSTREAM_USAGE_NOTIFICATION | Notification.| 
| AUDIOSTREAM_USAGE_ACCESSIBILITY | Accessibility.| 
| AUDIOSTREAM_USAGE_MOVIE | Video.| 
| AUDIOSTREAM_USAGE_GAME | Gaming.| 
| AUDIOSTREAM_USAGE_AUDIOBOOK | Audiobook.| 
| AUDIOSTREAM_USAGE_NAVIGATION | Navigation.| 


## Function Description


### OH_AudioCapturer_Flush()

```
OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer *capturer)
```

**Description**

Flushes obtained audio data.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetCapturerInfo()

```
OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer *capturer, OH_AudioStream_SourceType *sourceType)
```

**Description**

Obtains the usage scenario of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| sourceType | Pointer to a variable used to receive the usage scenario.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer *capturer, int32_t *channelCount)
```

**Description**

Obtains the number of channels for an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| channelCount | Pointer to a variable used to receive the number of channels.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer *capturer, OH_AudioStream_State *state)
```

**Description**

Obtains the state of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| state | Pointer to a variable used to receive the state.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer *capturer, OH_AudioStream_EncodingType *encodingType)
```

**Description**

Obtains the encoding type of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| encodingType | Pointer to a variable used to receive the encoding type.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer *capturer, int32_t *frameSize)
```

**Description**

Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| frameSize | Pointer to the variable that holds the frame size.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetFramesRead()

```
OH_AudioStream_Result OH_AudioCapturer_GetFramesRead (OH_AudioCapturer *capturer, int64_t *frames)
```

**Description**

Obtains the number of frames that have been read since the stream was created.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| frames | Pointer to the variable that holds the frame count.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer *capturer, OH_AudioStream_LatencyMode *latencyMode)
```

**Description**

Obtains the latency mode of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| latencyMode | Pointer to a variable used to receive the latency mode.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetOverflowCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount (OH_AudioCapturer *capturer, uint32_t *count)
```
**Description**

Obtains the number of overloaded audio streams of an audio capturer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer). | 
| count | Pointer to a variable used to receive the number of overloaded audio streams. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer *capturer, OH_AudioStream_SampleFormat *sampleFormat)
```

**Description**

Obtains the sampling format of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| sampleFormat | Pointer to a variable used to receive the sampling format.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer *capturer, int32_t *rate)
```

**Description**

Obtains the sampling rate of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| rate | Pointer to a variable used to receive the sampling rate.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetStreamId()

```
OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer *capturer, uint32_t *streamId)
```

**Description**

Obtains the stream ID of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| streamId | Pointer to a variable used to receive the stream ID.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer *capturer, clockid_t clockId, int64_t *framePosition, int64_t *timestamp)
```

**Description**

Obtains the timestamp and position information of an audio input stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 
| clockId | Clock identifier. Use **CLOCK_MONOTONIC**.| 
| framePosition | Pointer to the variable that holds the position information.| 
| timestamp | Pointer to the variable that holds the timestamp.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_Pause()

```
OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer *capturer)
```

**Description**

Pauses an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_Release()

```
OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer *capturer)
```

**Description**

Releases an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_Start()

```
OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer *capturer)
```

**Description**

Starts an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioCapturer_Stop()

```
OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer *capturer)
```

**Description**

Stops an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance created by [OH_AudioStreamBuilder_GenerateCapturer](#oh_audiostreambuilder_generatecapturer).| 

**Required permissions**

ohos.permission.MICROPHONE

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_CancelMark()

```
OH_AudioStream_Result OH_AudioRenderer_CancelMark (OH_AudioRenderer *renderer)
```
**Description**

Cancels the mark set by [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition).

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_Flush()

```
OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer *renderer)
```

**Description**

Flushes written audio data.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer *renderer, int32_t *channelCount)
```

**Description**

Obtains the number of channels for an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| channelCount | Pointer to a variable used to receive the number of channels.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetChannelLayout()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout (OH_AudioRenderer *renderer, OH_AudioChannelLayout *channelLayout)
```
**Description**

Obtains the channel layout of an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| channelLayout | Pointer to a variable used to receive the channel layout. For details about the available options, see [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1). | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer *renderer, OH_AudioStream_State *state)
```

**Description**

Obtains the state of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| state | Pointer to a variable used to receive the state.| 
**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetEffectMode (OH_AudioRenderer *renderer, OH_AudioStream_AudioEffectMode *effectMode)
```
**Description**

Obtains the effect mode of an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| effectMode | Pointer to a variable used to receive the effect mode. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer *renderer, OH_AudioStream_EncodingType *encodingType)
```

**Description**

Obtains the encoding type of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| encodingType | Pointer to a variable used to receive the encoding type.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer *renderer, int32_t *frameSize)
```

**Description**

Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| frameSize | Pointer to the variable that holds the frame size.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetFramesWritten()

```
OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer *renderer, int64_t *frames)
```

**Description**

Obtains the number of frames that have been written since the stream was created.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| frames | Pointer to the variable that holds the frame count.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer *renderer, OH_AudioStream_LatencyMode *latencyMode)
```

**Description**

Obtains the latency mode of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| latencyMode | Pointer to a variable used to receive the latency mode.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetRendererInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer *renderer, OH_AudioStream_Usage *usage)
```

**Description**

Obtains the usage scenario of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| usage | Pointer to a variable used to receive the usage scenario.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer *renderer, OH_AudioStream_SampleFormat *sampleFormat)
```

**Description**

Obtains the sampling format of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| sampleFormat | Pointer to a variable used to receive the sampling format.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer *renderer, int32_t *rate)
```

**Description**

Obtains the sampling rate of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| rate | Pointer to a variable used to receive the sampling rate.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_GetSpeed (OH_AudioRenderer * renderer, float * speed )
```

**Description**

Obtains the audio renderer rate.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| speed | Pointer to the variable that holds the renderer rate (used as the return value).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetStreamId()

```
OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer *renderer, uint32_t *streamId)
```

**Description**

Obtains the stream ID of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| streamId | Pointer to a variable used to receive the stream ID.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer *renderer, clockid_t clockId, int64_t *framePosition, int64_t *timestamp)
```

**Description**

Obtains the timestamp and position information of an audio output stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| clockId | Clock identifier. Use **CLOCK_MONOTONIC**.| 
| framePosition | Pointer to the variable that holds the position information.| 
| timestamp | Pointer to the variable that holds the timestamp.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetUnderflowCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount (OH_AudioRenderer *renderer, uint32_t *count)
```
**Description**

Obtains the number of underloaded audio streams of an audio capturer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| count | Pointer to a variable used to receive the number of underloaded audio streams. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_GetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_GetVolume (OH_AudioRenderer *renderer, float *volume)
```
**Description**

Obtains the volume of an audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| volume | Pointer to the audio volume. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_Pause()

```
OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer *renderer)
```

**Description**

Pauses an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_Release()

```
OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer *renderer)
```

**Description**

Releases an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_SetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_SetEffectMode (OH_AudioRenderer *renderer, OH_AudioStream_AudioEffectMode effectMode)
```
**Description**

Sets the effect mode for an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| effectMode | Effect mode to set. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_SetMarkPosition()

```
OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition (OH_AudioRenderer *renderer, uint32_t samplePos, OH_AudioRenderer_OnMarkReachedCallback callback, void *userData)
```
**Description**

Sets the mark position for an audio renderer. When this function is called, the mark position that has been set will be overwritten.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| samplePos | Mark position. | 
| callback | When the target mark position is reached, [OH_AudioRenderer_OnMarkReachedCallback](#oh_audiorenderer_onmarkreachedcallback) is invoked. | 
| userData | Pointer to the application data passed through the callback functions. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_SetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_SetSpeed (OH_AudioRenderer * renderer, float speed )
```

**Description**

Sets the audio renderer rate.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 
| speed | Playback speed, which ranges from 0.25 to 4.0.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_SetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolume (OH_AudioRenderer *renderer, float volume)
```
**Description**

Sets the volume for an audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| volume | Target volume, in the range of [0.0, 1.0]. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_SetVolumeWithRamp()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp (OH_AudioRenderer *renderer, float volume, int32_t durationMs)
```
**Description**

Sets the volume with a ramp within the specified duration for an audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer). | 
| volume | Target volume, in the range of [0.0, 1.0]. | 
| durationMs | Duration, in milliseconds. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_Start()

```
OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer *renderer)
```

**Description**

Starts an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioRenderer_Stop()

```
OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer *renderer)
```

**Description**

Stops an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance created by [OH_AudioStreamBuilder_GenerateRenderer](#oh_audiostreambuilder_generaterenderer).| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_Create()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder **builder, OH_AudioStream_Type type)
```

**Description**

Creates an audio stream builder, which can be an audio renderer or capturer.

You need to call **OH_AudioStreamBuilder_Destroy()** to destroy the builder when it is no longer required.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Double pointer to the audio stream builder created.| 
| type | Type of the audio stream builder, which can be **AUDIOSTREAM_TYPE_RERNDERER** or **AUDIOSTREAM_TYPE_CAPTURER**.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_Destroy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder *builder)
```

**Description**

Destroys an audio stream builder when it is no longer required.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_GenerateCapturer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder *builder, OH_AudioCapturer **audioCapturer)
```

**Description**

Creates an audio capturer instance.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| audioCapturer | Double pointer to the audio capturer instance created.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_GenerateRenderer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder *builder, OH_AudioRenderer **audioRenderer)
```

**Description**

Creates an audio renderer instance.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| audioRenderer | Double pointer to the audio renderer instance created.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetCapturerCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder *builder, OH_AudioCapturer_Callbacks callbacks, void *userData)
```

**Description**

Sets callbacks for an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| callbacks | Callback functions that will be used to process events related to audio input streams.| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetCapturerInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder *builder, OH_AudioStream_SourceType sourceType)
```

**Description**

Sets the usage scenario of an audio capturer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| sourceType | Usage scenario of the audio capturer.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetChannelCount()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount(OH_AudioStreamBuilder *builder, int32_t channelCount)
```

**Description**

Sets the number of channels for an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| channelCount | Number of channels.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetChannelLayout()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout (OH_AudioStreamBuilder *builder, OH_AudioChannelLayout channelLayout)
```
**Description**

Sets the channel layout for an audio stream.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**. | 
| channelLayout | Channel layout. For details about the available options, see [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1). | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetEncodingType()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder *builder, OH_AudioStream_EncodingType encodingType)
```

**Description**

Sets the encoding type of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| encodingType | Encoding type.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder *builder, int32_t frameSize)
```

**Description**

Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity.

- In the case of low-latency playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 5 ms, 10 ms, 15 ms, or 20 ms.
- In the case of common playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 20 ms to 100 ms.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| frameSize | Frame size.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetLatencyMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder *builder, OH_AudioStream_LatencyMode latencyMode)
```

**Description**

Sets the latency mode of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| latencyMode | Latency mode.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetRendererCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder *builder, OH_AudioRenderer_Callbacks callbacks, void *userData)
```

**Description**

Sets callbacks for an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| callbacks | Callback functions that will be used to process events related to audio output streams.| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetRendererInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder *builder, OH_AudioStream_Usage usage)
```

**Description**

Sets the usage scenario of an audio renderer.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| usage | Usage scenario of the audio renderer.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetRendererInterruptMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptMode (OH_AudioStreamBuilder *builder, OH_AudioInterrupt_Mode mode)
```
**Description**

Sets the interrupt mode of the stream client.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**. | 
| mode | Audio interrupt mode. For details about the available options, see [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode). | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback (OH_AudioStreamBuilder * builder, OH_AudioRenderer_OutputDeviceChangeCallback callback, void * userData )
```

**Description**

Sets the callback invoked when the audio stream device changes.

**Since**: 11

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| callbacks | Callback that will be used to process events related to audio stream device changes.| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetSampleFormat()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder *builder, OH_AudioStream_SampleFormat format)
```

**Description**

Sets the sampling format of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| format | Sampling format.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetSamplingRate()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate(OH_AudioStreamBuilder *builder, int32_t rate)
```

**Description**

Sets the sampling rate of an audio stream.

**Since**: 10

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**.| 
| channelCount | Sampling rate.| 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.


### OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback (OH_AudioStreamBuilder *builder, OH_AudioRenderer_WriteDataWithMetadataCallback callback, void *userData)
```
**Description**

Sets the callback invoked to write both audio data and metadata.

**Since**: 12

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an audio stream builder instance created by **OH_AudioStreamBuilder_Create()**. | 
| callback | Callback used to write both audio data and metadata. | 
| userData | Pointer to the application data passed through the callback functions. | 

**Returns**

Returns **AUDIOSTREAM_SUCCESS** if the operation is successful; returns an error code otherwise.
