# native_audiocapturer.h


## 概述

声明输入类型的音频流相关接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCapturer_Release](_o_h_audio.md#oh_audiocapturer_release) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer) | 释放输入音频流。 | 
| [OH_AudioCapturer_Start](_o_h_audio.md#oh_audiocapturer_start) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer) | 开始获取音频数据。 | 
| [OH_AudioCapturer_Pause](_o_h_audio.md#oh_audiocapturer_pause) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer) | 暂停输入音频流。 | 
| [OH_AudioCapturer_Stop](_o_h_audio.md#oh_audiocapturer_stop) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer) | 停止输入音频流。 | 
| [OH_AudioCapturer_Flush](_o_h_audio.md#oh_audiocapturer_flush) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer) | 丢弃获取的音频数据。 | 
| [OH_AudioCapturer_GetCurrentState](_o_h_audio.md#oh_audiocapturer_getcurrentstate) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) \*state) | 查询当前输入音频流状态。 | 
| [OH_AudioCapturer_GetLatencyMode](_o_h_audio.md#oh_audiocapturer_getlatencymode) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) \*latencyMode) | 查询当前输入音频流时延模式。 | 
| [OH_AudioCapturer_GetStreamId](_o_h_audio.md#oh_audiocapturer_getstreamid) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, uint32_t \*streamId) | 查询当前输入音频流ID。 | 
| [OH_AudioCapturer_GetSamplingRate](_o_h_audio.md#oh_audiocapturer_getsamplingrate) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, int32_t \*rate) | 查询当前输入音频流采样率。 | 
| [OH_AudioCapturer_GetChannelCount](_o_h_audio.md#oh_audiocapturer_getchannelcount) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, int32_t \*channelCount) | 查询当前输入音频流通道数。 | 
| [OH_AudioCapturer_GetSampleFormat](_o_h_audio.md#oh_audiocapturer_getsampleformat) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输入音频流采样格式。 | 
| [OH_AudioCapturer_GetEncodingType](_o_h_audio.md#oh_audiocapturer_getencodingtype) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) \*encodingType) | 查询当前输入音频流编码类型。 | 
| [OH_AudioCapturer_GetCapturerInfo](_o_h_audio.md#oh_audiocapturer_getcapturerinfo) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) \*sourceType) | 查询当前输入音频流工作场景类型。 | 
| [OH_AudioCapturer_GetFrameSizeInCallback](_o_h_audio.md#oh_audiocapturer_getframesizeincallback) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, int32_t \*frameSize) | 在回调中查询帧大小，它是每次回调返回的缓冲区的固定长度。 | 
| [OH_AudioCapturer_GetTimestamp](_o_h_audio.md#oh_audiocapturer_gettimestamp) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | 获取输入音频流时间戳和位置信息。 | 
| [OH_AudioCapturer_GetFramesRead](_o_h_audio.md#oh_audiocapturer_getframesread) ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, int64_t *frame) | 查询自创建流以来已读取的帧数。 |
