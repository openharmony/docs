# native_audiorenderer.h


## 概述

声明输出类型的音频流相关接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioRenderer_Release](_o_h_audio.md#oh_audiorenderer_release) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | 释放输出音频流。 | 
| [OH_AudioRenderer_Start](_o_h_audio.md#oh_audiorenderer_start) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | 开始输出音频数据。 | 
| [OH_AudioRenderer_Pause](_o_h_audio.md#oh_audiorenderer_pause) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | 暂停输出音频流。 | 
| [OH_AudioRenderer_Stop](_o_h_audio.md#oh_audiorenderer_stop) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | 停止输出音频流。 | 
| [OH_AudioRenderer_Flush](_o_h_audio.md#oh_audiorenderer_flush) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | 丢弃已经写入的音频数据。 | 
| [OH_AudioRenderer_GetCurrentState](_o_h_audio.md#oh_audiorenderer_getcurrentstate) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) \*state) | 查询当前输出音频流状态。 | 
| [OH_AudioRenderer_GetSamplingRate](_o_h_audio.md#oh_audiorenderer_getsamplingrate) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*rate) | 查询当前输出音频流采样率。 | 
| [OH_AudioRenderer_GetStreamId](_o_h_audio.md#oh_audiorenderer_getstreamid) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, uint32_t \*streamId) | 查询当前输出音频流ID。 | 
| [OH_AudioRenderer_GetChannelCount](_o_h_audio.md#oh_audiorenderer_getchannelcount) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*channelCount) | 查询当前输出音频流通道数。 | 
| [OH_AudioRenderer_GetSampleFormat](_o_h_audio.md#oh_audiorenderer_getsampleformat) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) \*sampleFormat) | 查询当前输出音频流采样格式。 | 
| [OH_AudioRenderer_GetLatencyMode](_o_h_audio.md#oh_audiorenderer_getlatencymode) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) \*latencyMode) | 查询当前输出音频流时延模式。 | 
| [OH_AudioRenderer_GetRendererInfo](_o_h_audio.md#oh_audiorenderer_getrendererinfo) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) \*usage) | 查询当前输出音频流工作场景类型。 | 
| [OH_AudioRenderer_GetEncodingType](_o_h_audio.md#oh_audiorenderer_getencodingtype) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) \*encodingType) | 查询当前输出音频流编码类型。 | 
| [OH_AudioRenderer_GetFramesWritten](_o_h_audio.md#oh_audiorenderer_getframeswritten) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int64_t \*frames) | 查询自创建流以来已写入的帧数。 | 
| [OH_AudioRenderer_GetTimestamp](_o_h_audio.md#oh_audiorenderer_gettimestamp) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | 获取输出音频流时间戳和位置信息。 | 
| [OH_AudioRenderer_GetFrameSizeInCallback](_o_h_audio.md#oh_audiorenderer_getframesizeincallback) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*frameSize) | 在回调中查询帧大小。 | 
