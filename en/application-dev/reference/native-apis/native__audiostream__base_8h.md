# native_audiostream_base.h


## Overview

The **native_audiostream_base.h** file declares the basic data structure of **OHAudio**.

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
| typedef struct [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md)[OH_AudioRenderer_Callbacks](_o_h_audio.md#oh_audiorenderer_callbacks) | Defines a pointer to the callback functions related to an audio renderer. | 
| typedef struct [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md)[OH_AudioCapturer_Callbacks](_o_h_audio.md#oh_audiocapturer_callbacks) | Defines a pointer to the callback functions related to an audio capturer. | 


### Enum

| Name| Description| 
| -------- | -------- |
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) {<br>AUDIOSTREAM_SUCCESS = 0,<br>AUDIOSTREAM_ERROR_INVALID_PARAM = 1,<br>AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2,<br>AUDIOSTREAM_ERROR_SYSTEM = 3<br>} | Enumerates the audio stream operation results.| 
| [OH_AudioStream_Type](_o_h_audio.md#oh_audiostream_type) {<br>AUDIOSTREAM_TYPE_RERNDERER = 1,<br>AUDIOSTREAM_TYPE_CAPTURER = 2<br>} | Enumerates the audio stream types.| 
| [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) {<br>AUDIOSTREAM_SAMPLE_U8 = 0,<br>AUDIOSTREAM_SAMPLE_S16LE = 1,<br>AUDIOSTREAM_SAMPLE_S24LE = 2,<br>AUDIOSTREAM_SAMPLE_S32LE = 3<br>} | Enumerates the sampling formats of audio streams.| 
| [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) {<br>AUDIOSTREAM_ENCODING_TYPE_RAW = 0<br>} | Enumerates the encoding types of audio streams.| 
| [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) {<br>AUDIOSTREAM_USAGE_UNKNOWN = 0,<br>AUDIOSTREAM_USAGE_MUSIC = 1,<br>AUDIOSTREAM_USAGE_COMMUNICATION = 2,<br>AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3,<br>AUDIOSTREAM_USAGE_ALARM = 4,<br>AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5,<br>AUDIOSTREAM_USAGE_RINGTONE = 6,<br>AUDIOSTREAM_USAGE_NOTIFICATION = 7,<br>AUDIOSTREAM_USAGE_ACCESSIBILITY = 8,<br>AUDIOSTREAM_USAGE_MOVIE = 10,<br>AUDIOSTREAM_USAGE_GAME = 11,<br>AUDIOSTREAM_USAGE_AUDIOBOOK = 12,<br>AUDIOSTREAM_USAGE_NAVIGATION = 13<br>} | Enumerates the usage scenarios of audio streams.| 
| [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) {<br>AUDIOSTREAM_LATENCY_MODE_NORMAL = 0,<br>AUDIOSTREAM_LATENCY_MODE_FAST = 1<br>} | Enumerates the latency modes of audio streams.| 
| [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) {<br>AUDIOSTREAM_STATE_INVALID = -1,<br>AUDIOSTREAM_STATE_NEW = 0,<br>AUDIOSTREAM_STATE_PREPARED = 1,<br>AUDIOSTREAM_STATE_RUNNING = 2,<br>AUDIOSTREAM_STATE_STOPPED = 3,<br>AUDIOSTREAM_STATE_RELEASED = 4,<br>AUDIOSTREAM_STATE_PAUSED = 5<br>} | Enumerates the audio stream states.| 
| [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) {<br>AUDIOSTREAM_SOURCE_TYPE_INVALID = -1,<br>AUDIOSTREAM_SOURCE_TYPE_MIC = 0,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1,<br>AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2,<br>AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7<br>} | Enumerates the usage scenarios of audio streams.| 
| [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) {<br>AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0<br>} | Enumerates the audio stream events.| 
| [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) {<br>AUDIOSTREAM_INTERRUPT_FORCE = 0,<br>AUDIOSTREAM_INTERRUPT_SHAR = 1<br>} | Enumerates the types of force that causes audio interruption.| 
| [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) {<br>AUDIOSTREAM_INTERRUPT_HINT_NONE = 0,<br>AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1,<br>AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2,<br>AUDIOSTREAM_INTERRUPT_HINT_STOP = 3,<br>AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4,<br>AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5<br>} | Enumerates the hints provided along with audio interruption.| 
