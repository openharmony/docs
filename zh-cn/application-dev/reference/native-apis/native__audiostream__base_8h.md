# native_audiostream_base.h


## 概述

声明OHAudio基础的数据结构。

\@syscap SystemCapability.Multimedia.Audio.Core

**起始版本：**

10

**相关模块：**

[OHAudio](_o_h_audio.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioRenderer_Callbacks_Struct](_o_h___audio_renderer___callbacks___struct.md) | 声明输出音频流的回调函数指针。 | 
| [OH_AudioCapturer_Callbacks_Struct](_o_h___audio_capturer___callbacks___struct.md) | 声明输入音频流的回调函数指针。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) | 声明音频流的构造器。 | 
| [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) | 声明输出音频流。 | 
| [OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) | 声明输入音频流。 | 
| [OH_AudioRenderer_Callbacks](_o_h_audio.md#oh_audiorenderer_callbacks) | 声明输出音频流的回调函数指针。 | 
| [OH_AudioCapturer_Callbacks](_o_h_audio.md#oh_audiocapturer_callbacks) | 声明输入音频流的回调函数指针。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) { [AUDIOSTREAM_SUCCESS](_o_h_audio.md), [AUDIOSTREAM_ERROR_INVALID_PARAM](_o_h_audio.md), [AUDIOSTREAM_ERROR_ILLEGAL_STATE](_o_h_audio.md), [AUDIOSTREAM_ERROR_SYSTEM](_o_h_audio.md) } | 音频错误码。 | 
| [OH_AudioStream_Type](_o_h_audio.md#oh_audiostream_type) { [AUDIOSTREAM_TYPE_RENDERER](_o_h_audio.md) = 1, [AUDIOSTREAM_TYPE_CAPTURER](_o_h_audio.md) = 2 } | 音频流类型。 | 
| [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) { [AUDIOSTREAM_SAMPLE_U8](_o_h_audio.md) = 0, [AUDIOSTREAM_SAMPLE_S16LE](_o_h_audio.md) = 1, [AUDIOSTREAM_SAMPLE_S24LE](_o_h_audio.md) = 2, [AUDIOSTREAM_SAMPLE_S32LE](_o_h_audio.md) = 3 } | 定义音频流采样格式。 | 
| [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) { **AUDIOSTREAM_ENCODING_TYPE_RAW** = 0 } | 定义音频流编码类型。 | 
| [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) { **AUDIOSTREAM_USAGE_UNKNOWN** = 0, **AUDIOSTREAM_USAGE_MUSIC** = 1, **AUDIOSTREAM_USAGE_COMMUNICATION** = 2, **AUDIOSTREAM_USAGE_GAME** = 11 } | 定义音频流使用场景。 | 
| [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) { [AUDIOSTREAM_LATENCY_MODE_NORMAL](_o_h_audio.md) } | 定义音频时延模式。 | 
| [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) {<br/>[AUDIOSTREAM_STATE_INVALID](_o_h_audio.md) = -1, [AUDIOSTREAM_STATE_PREPARED](_o_h_audio.md) = 1, [AUDIOSTREAM_STATE_RUNNING](_o_h_audio.md) = 2, [AUDIOSTREAM_STATE_STOPPED](_o_h_audio.md) = 3,<br/>[AUDIOSTREAM_STATE_RELEASED](_o_h_audio.md) = 4, [AUDIOSTREAM_STATE_PAUSED](_o_h_audio.md) = 5<br/>} | 定义音频流的状态。 | 
| [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) { **AUDIOSTREAM_SOURCE_TYPE_INVALID** = -1, **AUDIOSTREAM_SOURCE_TYPE_MIC**, **AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION** = 1, **AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION** = 7 } | 定义音频流使用场景。 | 
