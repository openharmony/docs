# OH_AudioCaptureInfo


## 概述

音频采样信息。

当audioSampleRate和audioChannels同时为0时，忽略该类型音频相关参数，不录制该类型音频数据。

**系统能力**：SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块:**

[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [audioSampleRate](#audiosamplerate) | int32_t<br/>音频采样率，支持列表参考**OH_AudioCapturer_GetSamplingRate**。 | 
| [audioChannels](#audiochannels) | int32_t<br/>音频声道数。 | 
| [audioSource](#audiosource) | [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype)<br/>音频源。 | 


## 结构体成员变量说明


### audioChannels

```
int32_t OH_AudioCaptureInfo::audioChannels
```

**描述:**

音频声道数。


### audioSampleRate

```
int32_t OH_AudioCaptureInfo::audioSampleRate
```

**描述:**

音频采样率，支持列表参考**OH_AudioCapturer_GetSamplingRate**。


### audioSource

```
OH_AudioCaptureSourceType OH_AudioCaptureInfo::audioSource
```

**描述:**

音频源。
