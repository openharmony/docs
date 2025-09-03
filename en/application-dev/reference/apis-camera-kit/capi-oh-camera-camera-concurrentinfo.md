# Camera_ConcurrentInfo
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

## Overview

The struct describes the camera's concurrency information.

**Since**: 18

**Related module**: [OH_Camera](capi-oh-camera.md)

**Header file**: [camera.h](capi-camera-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md) camera | Camera instance.|
| [Camera_ConcurrentType](capi-camera-h.md#camera_concurrenttype) type | Concurrency type of the camera.|
| [Camera_SceneMode](capi-camera-h.md#camera_scenemode)* sceneModes | Scene modes supported by the camera.|
| [Camera_OutputCapability](capi-oh-camera-camera-outputcapability.md)* outputCapabilities | Output capabilities of the camera.|
| uint32_t modeAndCapabilitySize | Output capability size of the camera.|
