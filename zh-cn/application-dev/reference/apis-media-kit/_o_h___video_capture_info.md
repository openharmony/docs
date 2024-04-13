# OH_VideoCaptureInfo


## 概述

视频录制信息。

当videoFrameWidth和videoFrameHeight同时为0时，忽略视频相关参数不录制屏幕数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint64_t [displayId](#displayid) | 录制物理屏id，使用该参数需要在capturemode为CAPTURE_SPECIFIED_SCREEN模式下使用。 | 
| int32_t \* [missionIDs](#missionids) | 指定窗口id列表，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。 | 
| int32_t [missionIDsLen](#missionidslen) | 指定窗口ID长度，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。 | 
| int32_t [videoFrameWidth](#videoframewidth) | 采集视频的宽度设置，单位px。 | 
| int32_t [videoFrameHeight](#videoframeheight) | 采集视频的高度设置，单位px。 | 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) [videoSource](#videosource) | 视频采集格式设置，目前仅支持RGBA格式。 | 


## 结构体成员变量说明


### displayId

```
uint64_t OH_VideoCaptureInfo::displayId
```

**描述**

录制物理屏id，使用该参数需要在capturemode为CAPTURE_SPECIFIED_SCREEN模式下使用。


### missionIDs

```
int32_t* OH_VideoCaptureInfo::missionIDs
```

**描述**

指定窗口id列表，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。


### missionIDsLen

```
int32_t OH_VideoCaptureInfo::missionIDsLen
```

**描述**

指定窗口ID长度，使用该参数需要在capturemode为CAPTURE_SPECIFIED_WINDOW模式下使用。


### videoFrameHeight

```
int32_t OH_VideoCaptureInfo::videoFrameHeight
```

**描述**

采集视频的高度设置，单位px。


### videoFrameWidth

```
int32_t OH_VideoCaptureInfo::videoFrameWidth
```

**描述**

采集视频的宽度设置，单位px。


### videoSource

```
OH_VideoSourceType OH_VideoCaptureInfo::videoSource
```

**描述**

视频采集格式设置，目前仅支持RGBA格式。
