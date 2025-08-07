# Camera_PhotoCaptureSetting
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

## Overview

The struct describes the parameters related to photo capture.

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

**Header file**: [camera.h](capi-camera-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [Camera_QualityLevel](capi-camera-h.md#camera_qualitylevel) quality | Quality of the photo.|
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation) rotation | Rotation angle.|
| [Camera_Location](capi-oh-camera-camera-location.md)* location | Pointer to the location where the photo is taken.|
| bool mirror | Whether mirroring is enabled.<br>**true** if enabled, **false** otherwise. The default value is **false**.|
