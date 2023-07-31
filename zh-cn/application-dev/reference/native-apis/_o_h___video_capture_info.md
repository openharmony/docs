# OH_VideoCaptureInfo


## 概述

视频采集信息。

**系统能力**：SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块:**

[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [displayId](#displayid) | uint64_t<br/>录制物理屏id，使用该参数需要在capturemode为CAPTURE_SPECIFIED_SCREEN模式下使用。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [missionIDs](#missionids) | int32_t \*<br/>指定窗口id列表，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。 <br>**说明：** 预留接口，将在后续版本提供。| 
| [missionIDsLen](#missionidslen) | int32_t<br/>指定窗口ID长度，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [videoFrameWidth](#videoframewidth) | int32_t<br/>采集视频的宽度设置。 | 
| [videoFrameHeight](#videoframeheight) | int32_t<br/>采集视频的高度设置。 | 
| [videoSource](#videosource) | [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype)<br/>视频采集格式设置，目前仅支持RGBA格式。 | 


## 结构体成员变量说明


### displayId

```
uint64_t OH_VideoCaptureInfo::displayId
```

**描述:**

录制物理屏id，使用该参数需要在capturemode为CAPTURE_SPECIFIED_SCREEN模式下使用。

> **说明：** 
> 
> 预留接口，将在后续版本提供。


### missionIDs

```
int32_t* OH_VideoCaptureInfo::missionIDs
```

**描述:**

指定窗口id列表，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。

> **说明：** 
> 
> 预留接口，将在后续版本提供。

### missionIDsLen

```
int32_t OH_VideoCaptureInfo::missionIDsLen
```

**描述:**

指定窗口ID长度，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。

> **说明：** 
> 
> 预留接口，将在后续版本提供。


### videoFrameHeight

```
int32_t OH_VideoCaptureInfo::videoFrameHeight
```

**描述:**

采集视频的高度设置。


### videoFrameWidth

```
int32_t OH_VideoCaptureInfo::videoFrameWidth
```

**描述:**

采集视频的宽度设置。


### videoSource

```
OH_VideoSourceType OH_VideoCaptureInfo::videoSource
```

**描述:**

视频采集格式设置，目前仅支持RGBA格式。
