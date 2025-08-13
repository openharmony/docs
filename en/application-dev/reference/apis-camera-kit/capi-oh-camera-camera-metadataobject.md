# Camera_MetadataObject
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

## Overview

The struct describes the camera metadata.

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

**Header file**: [camera.h](capi-camera-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype) type | Type of the metadata object.|
| int64_t timestamp | Timestamp of the metadata object, in milliseconds.|
| [Camera_Rect](capi-oh-camera-camera-rect.md)* boundingBox | Pointer to the axis aligned bounding box of the metadata object.|
