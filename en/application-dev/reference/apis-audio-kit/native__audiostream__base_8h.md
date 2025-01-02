# native_audiostream_base.h


## Overview

The **native_audiostream_base.h** file declares the basic data structure of **OHAudio**.

**Library**: libohaudio.so

**File to include**: &lt;ohaudio/native_audiostream_base.h&gt;

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio renderer. | 
| struct&nbsp;&nbsp;[OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio capturer. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct OH_AudioStreamBuilderStruct [OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) | Defines an audio stream builder. | 
| typedef struct OH_AudioRendererStruct [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) | Defines an audio renderer. | 
| typedef struct OH_AudioCapturerStruct [OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) | Defines an audio capturer. | 
| typedef struct [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) [OH_AudioRenderer_Callbacks](_o_h_audio.md#oh_audiorenderer_callbacks) | Defines a pointer to the callback functions related to an audio renderer. | 
| typedef struct [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) [OH_AudioCapturer_Callbacks](_o_h_audio.md#oh_audiocapturer_callbacks) | Defines a pointer to the callback functions related to an audio capturer. | 
| typedef void(\* [OH_AudioRenderer_OutputDeviceChangeCallback](_o_h_audio.md#oh_audiorenderer_outputdevicechangecallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_DeviceChangeReason](_o_h_audio.md#oh_audiostream_devicechangereason) reason) | Defines a pointer to the callback invoked when the audio stream device changes. | 
| typedef void(\* [OH_AudioRenderer_OnMarkReachedCallback](_o_h_audio.md#oh_audiorenderer_onmarkreachedcallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, uint32_t samplePos, void \*userData) | Defines a pointer to the callback invoked when the mark position is reached. | 
| typedef int32_t(\* [OH_AudioRenderer_WriteDataWithMetadataCallback](_o_h_audio.md#oh_audiorenderer_writedatawithmetadatacallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize, void \*metadata, int32_t metadataSize) | Defines a function pointer to the callback function used to write audio data and metadata. | 
| typedef [OH_AudioData_Callback_Result](_o_h_audio.md#oh_audiodata_callback_result)(\* [OH_AudioRenderer_OnWriteDataCallback](_o_h_audio.md#oh_audiorenderer_onwritedatacallback))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*audioData, int32_t audioDataSize) | Defines a function pointer to the callback function used to write audio data. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) {<br>AUDIOSTREAM_SUCCESS = 0,<br>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br>AUDIOSTREAM_ERROR_SYSTEM = 3<br>} | Enumerates the audio stream operation results.| 
| [OH_AudioStream_Type](_o_h_audio.md#oh_audiostream_type) {<br>AUDIOSTREAM_TYPE_RENDERER = 1,<br>AUDIOSTREAM_TYPE_CAPTURER = 2<br>} | Enumerates the audio stream types.| 
| [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) {<br>AUDIOSTREAM_SAMPLE_U8 = 0,<br>AUDIOSTREAM_SAMPLE_S16LE = 1,<br>AUDIOSTREAM_SAMPLE_S24LE = 2,<br>AUDIOSTREAM_SAMPLE_S32LE = 3<br>} | Enumerates the sampling formats of audio streams.| 
| [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) { <br>AUDIOSTREAM_ENCODING_TYPE_RAW = 0, <br>AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1<br>} | Enumerates the encoding types of audio streams. | 
| [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) {<br>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br>AUDIOSTREAM_USAGE_MUSIC = 1,<br>AUDIOSTREAM_USAGE_VOICE_COMMUNICATION = 2,<br>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br>AUDIOSTREAM_USAGE_ALARM = 4,<br>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br>AUDIOSTREAM_USAGE_RINGTONE = 6,<br>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br>AUDIOSTREAM_USAGE_MOVIE = 10,<br>AUDIOSTREAM_USAGE_GAME = 11,<br>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br>AUDIOSTREAM_USAGE_NAVIGATION = 13,<br>AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION = 17<br>} | Enumerates the usage scenarios of audio streams.| 
| [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) {<br>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br>} | Enumerates the latency modes of audio streams.| 
| [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) {<br>AUDIOSTREAM_STATE_INVALID = -1,<br>AUDIOSTREAM_STATE_NEW = 0,<br>AUDIOSTREAM_STATE_PREPARED = 1,<br>AUDIOSTREAM_STATE_RUNNING = 2,<br>AUDIOSTREAM_STATE_STOPPED = 3,<br>AUDIOSTREAM_STATE_RELEASED = 4,<br>AUDIOSTREAM_STATE_PAUSED = 5<br>} | Enumerates the audio stream states.| 
| [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) {<br>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7,<br>AUDIOSTREAM_SOURCE_TYPE_CAMCORDER = 13<br>} | Enumerates the usage scenarios of audio streams.| 
| [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) {<br>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br>} | Enumerates the audio stream events.| 
| [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) {<br>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br>AUDIOSTREAM_INTERRUPT_SHARE = 1<br>} | Enumerates the types of force that causes audio interruption.| 
| [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) {<br>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br>} | Enumerates the hints provided along with audio interruption.| 
| [OH_AudioInterrupt_Mode](_o_h_audio.md#oh_audiointerrupt_mode) {<br> AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0, <br> AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 <br>} | Enumerates the audio interrupt modes. | 
| [OH_AudioStream_AudioEffectMode](_o_h_audio.md#oh_audiostream_audioeffectmode) {<br>  EFFECT_NONE = 0, <br> EFFECT_DEFAULT = 1 <br> } | Enumerates the audio effect modes. | 
| [OH_AudioStream_DeviceChangeReason](_o_h_audio.md#oh_audiostream_devicechangereason) {<br>REASON_UNKNOWN = 0,<br>REASON_NEW_DEVICE_AVAILABLE = 1,<br>REASON_OLD_DEVICE_UNAVAILABLE = 2,<br>REASON_OVERRODE = 3<br>} | Enumerates the reasons for audio stream device changes.| 
| [OH_AudioStream_PrivacyType](_o_h_audio.md#oh_audiostream_privacytype) { <br>AUDIO_STREAM_PRIVACY_TYPE_PUBLIC = 0, <br>AUDIO_STREAM_PRIVACY_TYPE_PRIVATE = 1 <br>} | Enumerates the privacy types of an audio stream. The privacy type specifies whether the audio stream can be recorded by other applications. | 
| [OH_AudioData_Callback_Result](_o_h_audio.md#oh_audiodata_callback_result) { <br>AUDIO_DATA_CALLBACK_RESULT_INVALID = -1, <br>AUDIO_DATA_CALLBACK_RESULT_VALID = 0 <br>} | Enumerates the audio data callback results. | 
