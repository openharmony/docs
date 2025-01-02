# OH_VideoCaptureInfo


## Overview

The **OH_VideoCaptureInfo** struct describes the video capture information.

When both **videoFrameWidth** and **videoFrameHeight** are **0**, video-related parameters are ignored and screen data is not recorded.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint64_t [displayId](#displayid) | ID of the physical screen to capture. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_SCREEN**.| 
| int32_t \* [missionIDs](#missionids) | Mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.| 
| int32_t [missionIDsLen](#missionidslen) | Length of the mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.| 
| int32_t [videoFrameWidth](#videoframewidth) | Width of the video to capture, in px.| 
| int32_t [videoFrameHeight](#videoframeheight) | Height of the video to capture, in px.| 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) [videoSource](#videosource) | Video source type. Currently, only RGBA is supported.| 


## Member Variable Description


### displayId

```
uint64_t OH_VideoCaptureInfo::displayId
```

**Description**

ID of the physical screen to capture. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_SCREEN**.


### missionIDs

```
int32_t* OH_VideoCaptureInfo::missionIDs
```

**Description**

Mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.


### missionIDsLen

```
int32_t OH_VideoCaptureInfo::missionIDsLen
```

**Description**

Length of the mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.


### videoFrameHeight

```
int32_t OH_VideoCaptureInfo::videoFrameHeight
```

**Description**

Height of the video to capture, in px.


### videoFrameWidth

```
int32_t OH_VideoCaptureInfo::videoFrameWidth
```

**Description**

Width of the video to capture, in px.


### videoSource

```
OH_VideoSourceType OH_VideoCaptureInfo::videoSource
```

**Description**

Video source type. Currently, only RGBA is supported.
