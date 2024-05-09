# OH_AudioInfo


## 概述

音频信息。

同时采集音频麦克风和音频内录数据时，两路音频的audioSampleRate和audioChannels采样参数需要相同。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [micCapInfo](#miccapinfo) | 音频麦克风采样信息。 | 
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [innerCapInfo](#innercapinfo) | 音频内录采样信息 。 | 
| [OH_AudioEncInfo](_o_h___audio_enc_info.md) [audioEncInfo](#audioencinfo) | 音频编码信息，原始码流时不需要设置。 | 


## 结构体成员变量说明


### audioEncInfo

```
OH_AudioEncInfo OH_AudioInfo::audioEncInfo
```

**描述**

音频编码信息，原始码流时不需要设置。



### innerCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::innerCapInfo
```

**描述**

音频内录采样信息 。


### micCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::micCapInfo
```

**描述**

音频麦克风采样信息。
