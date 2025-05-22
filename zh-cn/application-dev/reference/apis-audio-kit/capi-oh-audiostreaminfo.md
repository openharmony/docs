# OH_AudioStreamInfo

## 概述

定义音频流信息，用于描述基本音频格式。

**起始版本：** 19

**相关模块：** [OHAudio](capi-ohaudio.md)

**所在头文件：** [native_audiostream_base.h](capi-native-audiostream-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t samplingRate | 音频流采样率。|
| [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) channelLayout | 音频流声道布局。|
| [OH_AudioStream_EncodingType](capi-native-audiostream-base-h.md#oh_audiostream_encodingtype) encodingType | 音频流编码类型。|
| [OH_AudioStream_SampleFormat](capi-native-audiostream-base-h.md#oh_audiostream_sampleformat) sampleFormat | 音频流采样格式。|


