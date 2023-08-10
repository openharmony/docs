# OH_VideoCaptureInfo


## Overview

The **OH_VideoCaptureInfo** struct defines video capture information.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [displayId](#displayid) | uint64_t<br>Defines the ID of the physical screen to capture. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_SCREEN**.<br>**NOTE**: This member variable is reserved and will be provided in later versions.| 
| [missionIDs](#missionids) | int32_t \*<br>Defines the mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.<br>**NOTE**: This member variable is reserved and will be provided in later versions.| 
| [missionIDsLen](#missionidslen) | int32_t<br>Defines the length of the mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.<br>**NOTE**: This member variable is reserved and will be provided in later versions.| 
| [videoFrameWidth](#videoframewidth) | int32_t<br>Defines the width of the captured video.| 
| [videoFrameHeight](#videoframeheight) | int32_t<br>Defines the height of the captured video.| 
| [videoSource](#videosource) | [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype)<br>Defines the video source type. Currently, only RGBA is supported.| 


## Member Variable Description


### displayId

```
uint64_t OH_VideoCaptureInfo::displayId
```

**Description**

Defines the ID of the physical screen to capture. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_SCREEN**.

> **NOTE**
> 
> This member variable is reserved and will be provided in later versions.


### missionIDs

```
int32_t* OH_VideoCaptureInfo::missionIDs
```

**Description**

Defines the mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.

> **NOTE**
> 
> This member variable is reserved and will be provided in later versions.

### missionIDsLen

```
int32_t OH_VideoCaptureInfo::missionIDsLen
```

**Description**

Defines the length of the mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.

> **NOTE**
> 
> This member variable is reserved and will be provided in later versions.


### videoFrameHeight

```
int32_t OH_VideoCaptureInfo::videoFrameHeight
```

**Description**

Defines the height of the captured video.


### videoFrameWidth

```
int32_t OH_VideoCaptureInfo::videoFrameWidth
```

**Description**

Defines the width of the captured video.


### videoSource

```
OH_VideoSourceType OH_VideoCaptureInfo::videoSource
```

**Description**

Defines the video source type. Currently, only RGBA is supported.
