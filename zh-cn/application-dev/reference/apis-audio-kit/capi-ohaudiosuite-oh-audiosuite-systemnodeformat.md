# OH_AudioSuite_SystemNodeFormat
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AudioSuite_SystemNodeFormat {...} OH_AudioSuite_SystemNodeFormat
```

## 概述

定义系统节点的基本音频格式。

**起始版本：** 26.0.0

**相关模块：** [OHAudioSuite](capi-ohaudiosuite.md)

**所在头文件：** [native_audio_suite_base.h](capi-native-audio-suite-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_Audio_SampleRate](capi-native-audio-suite-base-h.md#oh_audio_samplerate) samplingRate | 音频流采样率。 |
| OH_AudioChannelLayout channelLayout | 音频流声道布局。 |
| uint32_t channelCount | 音频流声道个数。 |
| int32_t encoding | 音频流编码类型。取值为1或者9，1表示PCM编码格式，9表示PCM与MetaData混合音频数据。 |
| [OH_Audio_SampleFormat](capi-native-audio-suite-base-h.md#oh_audio_sampleformat) sampleFormat | 音频流采样格式。 |


