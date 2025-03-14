# native_audiostreambuilder.h


## 概述

声明音频流构造器相关接口。

包含构造和销毁构造器，设置音频流属性，回调等相关接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：** OHAudio

## section测试1

### subsection测试11

**系统能力：** SystemCapability.Multimedia.Audio.Core

### subsection测试12

|名称|描述|
|---|---|
|name1|Desc1<br>**系统能力：** SystemCapability.ArkUI.ArkUI.Full|
|name2|Desc2<br>**系统能力：** SystemCapability.DistributedDataManager.DataShare.Core|
|name3|Desc3<br>**系统能力：** SystemCapability.Multimedia.Audio.Volume|

### subsection测试13

无系统能力打标关键字

## section测试2

### subsection测试21

无系统能力打标关键字

### subsection测试22

无系统能力打标关键字

### subsection测试23

无系统能力打标关键字


## section测试3

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

### subsection测试31

无系统能力打标关键字

## section测试4

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

### subsection测试41

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

## 汇总

### 函数

**系统能力：** SystemCapability.Multimedia.Audio.Core

|名称|描述|
|---|---|
| OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder \*\*builder, OH_AudioStream_Type type)                                              | 创建一个输入或者输出类型的音频流构造器。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder \*builder)                                                                                                           | 销毁一个音频流构造器。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate(OH_AudioStreamBuilder \*builder, int32_t rate)                                                                             | 设置音频流的采样率属性。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount(OH_AudioStreamBuilder \*builder, int32_t channelCount)                                                                     | 设置音频流的通道数属性。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder \*builder, OH_AudioStream_SampleFormat format)          | 设置音频流的采样格式属性。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder \*builder, OH_AudioStream_EncodingType encodingType)    | 设置音频流的编码类型属性。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder \*builder, OH_AudioStream_LatencyMode latencyMode)         | 设置音频流的时延模式。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder \*builder, OH_AudioStream_Usageusage)                         | 设置输出音频流的工作场景。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder \*builder, OH_AudioStream_SourceType sourceType)          | 设置输入音频流的工作场景。  | 
| OH_AudioStream_ResultOH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder \*builder, OH_AudioRenderer_Callbacks callbacks, void \*userData) | 设置输出音频流的回调。  | 
| OH_AudioStream_ResultOH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback (OH_AudioStreamBuilder \*builder, OH_AudioRenderer_OutputDeviceChangeCallback callback, void \*userData) | 设置输出音频流设备变更的回调。  |
| OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder \*builder, OH_AudioCapturer_Callbacks callbacks, void \*userData) | 设置输入音频流的回调。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder \*builder, OH_AudioRenderer \*\*audioRenderer)                     | 创建输出音频流实例。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder \*builder, OH_AudioCapturer\*\*audioCapturer)                     | 创建输入音频流实例。  | 
| OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder \*builder, int32_t frameSize) | 设置每次回调的帧长，帧长至少为音频硬件一次处理的数据大小，并且小于内部缓冲容量的一半。  | 


### 测试

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core