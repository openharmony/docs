# OH_AudioInfo


## 概述

音频录制参数。

**系统能力**：SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块:**

[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [micCapInfo](#miccapinfo) | [OH_AudioCaptureInfo](_o_h___audio_capture_info.md)<br/>麦克风的音频参数。 | 
| [innerCapInfo](#innercapinfo) | [OH_AudioCaptureInfo](_o_h___audio_capture_info.md)<br/>内录的音频参数。 | 
| [audioEncInfo](#audioencinfo) | [OH_AudioEncInfo](_o_h___audio_enc_info.md)<br/>音频录制信息， 当dataType为OH_ORIGINAL_STREAM时不需要设置。<br>**说明：** 预留接口，将在后续版本提供。 | 


## 结构体成员变量说明


### audioEncInfo

```
OH_AudioEncInfo OH_AudioInfo::audioEncInfo
```

**描述:**

音频录制信息， 当dataType为OH_ORIGINAL_STREAM时不需要设置。

> **说明：** 
> 
> 预留接口，将在后续版本提供。


### innerCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::innerCapInfo
```

**描述:**

内录的音频参数。


### micCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::micCapInfo
```

**描述:**

麦克风的音频参数。
