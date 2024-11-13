# photo_native.h


## Overview

The **camera_input.h** file declares the camera photo concepts.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/photo_native.h&gt;

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 12

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_PhotoNative](_o_h___camera.md#oh_photonative) [OH_PhotoNative](_o_h___camera.md#oh_photonative) | Defines a struct for the camera photo object.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoNative_GetMainImage](_o_h___camera.md#oh_photonative_getmainimage) ([OH_PhotoNative](_o_h___camera.md#oh_photonative) \*photo, OH_ImageNative \*\*mainImage) | Obtains a full quality photo.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoNative_Release](_o_h___camera.md#oh_photonative_release) ([OH_PhotoNative](_o_h___camera.md#oh_photonative) \*photo) | Releases a full quality photo.| 
