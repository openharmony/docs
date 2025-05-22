# OH_AudioCaptureInfo


## 概述

音频采样信息。

当audioSampleRate和audioChannels同时为0时，忽略该类型音频相关参数，不录制该类型音频数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)

**所在头文件：**[native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [audioSampleRate](#audiosamplerate) | 音频采样率。  | 
| int32_t [audioChannels](#audiochannels) | 音频声道数。  | 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) [audioSource](#audiosource) | 音频源。  | 


## 结构体成员变量说明


### audioChannels

```
int32_t OH_AudioCaptureInfo::audioChannels
```
**描述**
音频声道数。


### audioSampleRate

```
int32_t OH_AudioCaptureInfo::audioSampleRate
```
**描述**
音频采样率，支持列表请查阅Audio Kit的[AudioSamplingRate](../apis-audio-kit/js-apis-audio.md#audiosamplingrate8)。


### audioSource

```
OH_AudioCaptureSourceType OH_AudioCaptureInfo::audioSource
```
**描述**
音频源。
