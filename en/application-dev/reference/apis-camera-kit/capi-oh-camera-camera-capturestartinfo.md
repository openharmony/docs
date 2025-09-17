# Camera_CaptureStartInfo
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the capture start information.

**Since**: 12

**Related module**: [OH_Camera](capi-oh-camera.md)

**Header file**: [camera.h](capi-camera-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t captureId | Capture ID.|
| int64_t time | Estimated duration when the sensor captures frames at the bottom layer in a single capture. If **–1** is reported, there is no estimated duration.|
