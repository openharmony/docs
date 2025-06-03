# OH_VideoCaptureInfo

## Overview

The OH_VideoCaptureInfo struct describes the video capture information.

When **videoFrameWidth** and **videoFrameHeight** are both **0**, video-related parameters are ignored and screen data is not recorded.

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

**Header file**: [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint64_t displayId | ID of the physical screen to capture. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_SCREEN**.|
| int32_t* missionIDs | Mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.|
| int32_t missionIDsLen | Length of the mission ID list. This member variable is valid when **capturemode** is set to **CAPTURE_SPECIFIED_WINDOW**.|
| int32_t videoFrameWidth | Width of the video to capture, in px.|
| int32_t videoFrameHeight | Height of the video to capture, in px.|
| [OH_VideoSourceType](capi-native-avscreen-capture-base-h.md#oh_videosourcetype) videoSource | Video source type. Currently, only RGBA is supported.|
