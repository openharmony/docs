# native_audiostreambuilder.h


## 概述

声明音频流构造器相关接口。

包含构造和销毁构造器，设置音频流属性，回调等相关接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：** [OHAudio](_o_h_audio.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioStreamBuilder_Create](_o_h_audio.md#oh_audiostreambuilder_create) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](_o_h_audio.md#oh_audiostream_type) type) | 创建一个输入或者输出类型的音频流构造器。 | 
| [OH_AudioStreamBuilder_Destroy](_o_h_audio.md#oh_audiostreambuilder_destroy) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder) | 销毁一个音频流构造器。 | 
| [OH_AudioStreamBuilder_SetSamplingRate](_o_h_audio.md#oh_audiostreambuilder_setsamplingrate) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, int32_t rate) | 设置音频流的采样率属性。 | 
| [OH_AudioStreamBuilder_SetChannelCount](_o_h_audio.md#oh_audiostreambuilder_setchannelcount) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, int32_t channelCount) | 设置音频流的通道数属性。 | 
| [OH_AudioStreamBuilder_SetSampleFormat](_o_h_audio.md#oh_audiostreambuilder_setsampleformat) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) format) | 设置音频流的采样格式属性。 | 
| [OH_AudioStreamBuilder_SetEncodingType](_o_h_audio.md#oh_audiostreambuilder_setencodingtype) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) encodingType) | 设置音频流的编码类型属性。 | 
| [OH_AudioStreamBuilder_SetLatencyMode](_o_h_audio.md#oh_audiostreambuilder_setlatencymode) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) latencyMode) | 设置音频流的时延模式。 | 
| [OH_AudioStreamBuilder_SetRendererInfo](_o_h_audio.md#oh_audiostreambuilder_setrendererinfo) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) usage) | 设置输出音频流的工作场景。 | 
| [OH_AudioStreamBuilder_SetCapturerInfo](_o_h_audio.md#oh_audiostreambuilder_setcapturerinfo) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) sourceType) | 设置输入音频流的工作场景。 | 
| [OH_AudioStreamBuilder_SetRendererCallback](_o_h_audio.md#oh_audiostreambuilder_setrenderercallback) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](_o_h_audio.md#oh_audiorenderer_callbacks) callbacks, void \*userData) | 设置输出音频流的回调。 | 
| [OH_AudioStreamBuilder_SetCapturerCallback](_o_h_audio.md#oh_audiostreambuilder_setcapturercallback) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](_o_h_audio.md#oh_audiocapturer_callbacks) callbacks, void \*userData) | 设置输入音频流的回调。 | 
| [OH_AudioStreamBuilder_GenerateRenderer](_o_h_audio.md#oh_audiostreambuilder_generaterenderer) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*\*audioRenderer) | 创建输出音频流实例。 | 
| [OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*\*audioCapturer) | 创建输入音频流实例。 | 
