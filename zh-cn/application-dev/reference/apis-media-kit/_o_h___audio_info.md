# OH_AudioInfo


## 概述

音频录制参数。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [micCapInfo](#miccapinfo) | 麦克风的音频参数。 | 
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [innerCapInfo](#innercapinfo) | 内录的音频参数。 | 
| [OH_AudioEncInfo](_o_h___audio_enc_info.md) [audioEncInfo](#audioencinfo) | 音频录制信息， 当dataType为OH_ORIGINAL_STREAM时不需要设置。 | 


## 结构体成员变量说明


### audioEncInfo

```
OH_AudioEncInfo OH_AudioInfo::audioEncInfo
```

**描述**

音频录制信息， 当dataType为OH_ORIGINAL_STREAM时不需要设置。



### innerCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::innerCapInfo
```

**描述**

内录的音频参数。


### micCapInfo

```
OH_AudioCaptureInfo OH_AudioInfo::micCapInfo
```

**描述**

麦克风的音频参数。
