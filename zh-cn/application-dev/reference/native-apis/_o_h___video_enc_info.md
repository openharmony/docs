# OH_VideoEncInfo


## 概述

视频编码参数。

> **说明：** 
> 
> 预留接口，将在后续版本提供。

**系统能力**：SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块:**

[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [videoCodec](#videocodec) | [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat)<br/>视频采集编码格式。 | 
| [videoBitrate](#videobitrate) | int32_t<br/>视频采集比特率。 | 
| [videoFrameRate](#videoframerate) | int32_t<br/>视频采集帧率。 | 


## 结构体成员变量说明


### videoBitrate

```
int32_t OH_VideoEncInfo::videoBitrate
```

**描述:**

视频采集比特率。


### videoCodec

```
OH_VideoCodecFormat OH_VideoEncInfo::videoCodec
```

**描述:**

视频采集编码格式。


### videoFrameRate

```
int32_t OH_VideoEncInfo::videoFrameRate
```

**描述:**

视频采集帧率。
