# Camera_TorchStatusInfo
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

## Overview

The struct describes the flashlight status information.

**Since**: 12

**Related module**: [OH_Camera](capi-oh-camera.md)

**Header file**: [camera.h](capi-camera-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| bool isTorchAvailable | Whether the flashlight is available. **true** if available, **false** otherwise.|
| bool isTorchActive | Whether the flashlight is activated. **true** if activated, **false** otherwise.|
| float torchLevel | Flashlight level. The value range is [0, 1]. A larger value indicates a greater luminance.|
