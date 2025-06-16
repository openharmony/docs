# OH_AudioCaptureInfo

## 概述

音频采样信息。

当audioSampleRate和audioChannels同时为0时，忽略该类型音频相关参数，不录制该类型音频数据。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t audioSampleRate | 音频采样率，支持列表请查阅Audio Kit的[AudioSamplingRate](../apis-audio-kit/arkts-apis-audio-e.md#audiosamplingrate8)。 |
| int32_t audioChannels | 音频声道数。 |
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) audioSource | 音频源。 |


