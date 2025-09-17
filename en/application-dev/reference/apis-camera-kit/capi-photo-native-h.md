# photo_native.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the camera photo concepts.

**File to include**: <ohcamera/photo_native.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 12

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_PhotoNative](capi-oh-camera-oh-photonative.md) | OH_PhotoNative | Describes the photo object, which is a full-quality image object.|

### Functions

| Name| Description|
| -- | -- |
| [Camera_ErrorCode OH_PhotoNative_GetMainImage(OH_PhotoNative* photo, OH_ImageNative** mainImage)](#oh_photonative_getmainimage) | Obtains a full-quality image.|
| [Camera_ErrorCode OH_PhotoNative_Release(OH_PhotoNative* photo)](#oh_photonative_release) | Releases a full-quality image.|

## Function Description

### OH_PhotoNative_GetMainImage()

```
Camera_ErrorCode OH_PhotoNative_GetMainImage(OH_PhotoNative* photo, OH_ImageNative** mainImage)
```

**Description**

Obtains a full-quality image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PhotoNative](capi-oh-camera-oh-photonative.md)* photo | Pointer to an OH_PhotoNative instance.|
| [OH_ImageNative](../apis-image-kit/capi-image-imagenative-.md)** mainImage | Double pointer to the full-quality image, which is an OH_ImageNative instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_PhotoNative_Release()

```
Camera_ErrorCode OH_PhotoNative_Release(OH_PhotoNative* photo)
```

**Description**

Releases a full-quality image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PhotoNative](capi-oh-camera-oh-photonative.md)* photo | Pointer to the OH_PhotoNative instance to release.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|
