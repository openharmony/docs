# native_audiostream_base.h


## Overview

The **native_audiostream_base.h** file declares the basic data structure of **OHAudio**.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

**Related Modules**

[OHAudio](_o_h_audio.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio renderer.| 
| [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | Defines a pointer to the callback functions related to an audio capturer.| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) | Defines an audio stream builder.| 
| [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) | Defines an audio renderer.| 
| [OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) | Defines an audio capturer.| 
| [OH_AudioRenderer_Callbacks](_o_h_audio.md#oh_audiorenderer_callbacks) | Defines a pointer to the callback functions related to an audio renderer.| 
| [OH_AudioCapturer_Callbacks](_o_h_audio.md#oh_audiocapturer_callbacks) | Defines a pointer to the callback functions related to an audio capturer.| 


### Enum

| Name| Description| 
| -------- | -------- |
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) { [AUDIOSTREAM_SUCCESS](_o_h_audio.md), [AUDIOSTREAM_ERROR_INVALID_PARAM](_o_h_audio.md), [AUDIOSTREAM_ERROR_ILLEGAL_STATE](_o_h_audio.md), [AUDIOSTREAM_ERROR_SYSTEM](_o_h_audio.md) } | Enumerates the audio stream operation results.| 
| [OH_AudioStream_Type](_o_h_audio.md#oh_audiostream_type) { [AUDIOSTREAM_TYPE_RENDERER](_o_h_audio.md) = 1, [AUDIOSTREAM_TYPE_CAPTURER](_o_h_audio.md) = 2 } | Enumerates the audio stream types.| 
| [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) { [AUDIOSTREAM_SAMPLE_U8](_o_h_audio.md) = 0, [AUDIOSTREAM_SAMPLE_S16LE](_o_h_audio.md) = 1, [AUDIOSTREAM_SAMPLE_S24LE](_o_h_audio.md) = 2, [AUDIOSTREAM_SAMPLE_S32LE](_o_h_audio.md) = 3 } | Enumerates the sampling formats of audio streams.| 
| [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) { **AUDIOSTREAM_ENCODING_TYPE_RAW** = 0 } | Enumerates the encoding types of audio streams.| 
| [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) { **AUDIOSTREAM_USAGE_UNKNOWN** = 0, **AUDIOSTREAM_USAGE_MUSIC** = 1, **AUDIOSTREAM_USAGE_COMMUNICATION** = 2, **AUDIOSTREAM_USAGE_GAME** = 11 } | Enumerates the usage scenarios of audio output streams.| 
| [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) { [AUDIOSTREAM_LATENCY_MODE_NORMAL](_o_h_audio.md) = 0, [AUDIOSTREAM_LATENCY_MODE_FAST](_o_h_audio.md) = 1 } | Enumerates the latency modes of audio streams.| 
| [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) {<br>[AUDIOSTREAM_STATE_INVALID](_o_h_audio.md) = -1, [AUDIOSTREAM_STATE_PREPARED](_o_h_audio.md) = 1, [AUDIOSTREAM_STATE_RUNNING](_o_h_audio.md) = 2, [AUDIOSTREAM_STATE_STOPPED](_o_h_audio.md) = 3,<br>[AUDIOSTREAM_STATE_RELEASED](_o_h_audio.md) = 4, [AUDIOSTREAM_STATE_PAUSED](_o_h_audio.md) = 5<br>} | Enumerates the audio stream states.| 
| [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) { **AUDIOSTREAM_SOURCE_TYPE_INVALID** = -1, **AUDIOSTREAM_SOURCE_TYPE_MIC**, **AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION** = 1, **AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION** = 7 } | Enumerates the usage scenarios of audio input streams.| 
