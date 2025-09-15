# Camera_OutputCapability
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the camera output capability.

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

**Header file**: [camera.h](capi-camera-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [Camera_Profile](capi-oh-camera-camera-profile.md)** previewProfiles | Double pointer to the list of preview profiles.|
| uint32_t previewProfilesSize | Size of the preview profiles.|
| [Camera_Profile](capi-oh-camera-camera-profile.md)** photoProfiles | Double pointer to the list of photo profiles.<br> In the configuration file, **size** is set to the width and height of the camera resolution, not the actual width and height of an output image.|
| uint32_t photoProfilesSize | Size of the photo profiles.|
| [Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md)** videoProfiles | Double pointer to the list of video profiles.|
| uint32_t videoProfilesSize | Size of the video profiles.|
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)** supportedMetadataObjectTypes | Double pointer to the list of the metadata object types supported.|
| uint32_t metadataProfilesSize | Size of the metadata profiles.|
