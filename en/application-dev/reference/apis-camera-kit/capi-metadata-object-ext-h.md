# metadata_object_ext.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f0e09e3de648081eea4659387ebc6bc9008f04fc translatedAt=2026-08-11T02:02:06.030Z pushedAt=2026-08-12T03:21:22.184Z -->

## Overview

Declares the metadata object extension concepts.

**File to include:** <ohcamera/metadata_object_ext.h>

**Library:** libohcamera.so

**System capability:** SystemCapability.Multimedia.Camera.Core

**Since:** 26.0.0

**Related module:** [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md) | OH_Camera_MetadataObjectExt | Defines a struct for metadata object extensions.|

### Functions

| Name| Description|
| -- | -- |
| [Camera_ErrorCode OH_MetadataObjectExt_GetMetadataObjectType(const OH_Camera_MetadataObjectExt* metadataObjectExt, Camera_MetadataObjectType* type)](#oh_metadataobjectext_getmetadataobjecttype) | Obtains the metadata object type.|
| [Camera_ErrorCode OH_MetadataObjectExt_GetTimestamp(const OH_Camera_MetadataObjectExt* metadataObjectExt, int64_t* timestamp)](#oh_metadataobjectext_gettimestamp) | Obtains the timestamp of a metadata object.|
| [Camera_ErrorCode OH_MetadataObjectExt_GetBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)](#oh_metadataobjectext_getboundingbox) | Obtains the bounding box of a metadata object.|
| [Camera_ErrorCode OH_MetadataObjectExt_GetPitchAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* pitchAngle)](#oh_metadataobjectext_getpitchangle) | Obtains the pitch angle of a metadata object (such as a face). The value range is [-90, 90], with the positive direction being downwards.|
| [Camera_ErrorCode OH_MetadataObjectExt_GetYawAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* yawAngle)](#oh_metadataobjectext_getyawangle) | Obtains the yaw angle of a metadata object (such as a face). The value range is [-90, 90], with the positive direction being rightwards.|
| [Camera_ErrorCode OH_MetadataObjectExt_GetRollAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* rollAngle)](#oh_metadataobjectext_getrollangle) | Obtains the roll angle of a metadata object (such as a face). The value range is [-180, 180], with the positive direction being clockwise.|
| [Camera_ErrorCode OH_MetadataObjectExt_GetLeftEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)](#oh_metadataobjectext_getlefteyeboundingbox) | Obtains the left eye bounding box of a metadata object (such as a face).|
| [Camera_ErrorCode OH_MetadataObjectExt_GetRightEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)](#oh_metadataobjectext_getrighteyeboundingbox) | Obtains the right eye bounding box of a metadata object (such as a face).|
| [Camera_ErrorCode OH_MetadataObjectExt_GetEmotion(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_MetadataObjectEmotion* emotion)](#oh_metadataobjectext_getemotion) | Obtains the emotion of a metadata object (such as a face).|
| [void OH_MetadataObjectExt_Destroy(OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t objectCount)](#oh_metadataobjectext_destroy) | Destroys an **OH_Camera_MetadataObjectExt** instance array.|
| [bool OH_MetadataObjectExt_IsLockFocusTracked(const OH_Camera_MetadataObjectExt* metadataObjectExt)](#oh_metadataobjectext_islockfocustracked) | Checks whether the focus is locked for tracking. |

## Function Description

### OH_MetadataObjectExt_GetMetadataObjectType()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetMetadataObjectType(const OH_Camera_MetadataObjectExt* metadataObjectExt, Camera_MetadataObjectType* type)
```

**Description**

Obtains the metadata object type.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* type | Pointer to a **Camera_MetadataObjectType** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataObjectExt_GetTimestamp()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetTimestamp(const OH_Camera_MetadataObjectExt* metadataObjectExt, int64_t* timestamp)
```

**Description**

Obtains the timestamp of a metadata object.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| int64_t* timestamp | Pointer to the timestamp.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataObjectExt_GetBoundingBox()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)
```

**Description**

Obtains the bounding box of a metadata object.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| [OH_Camera_Rect_Ext](capi-oh-camera-oh-camera-rect-ext.md)* boundingBox | Pointer to an **OH_Camera_Rect_Ext** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_MetadataObjectExt_GetPitchAngle()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetPitchAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* pitchAngle)
```

**Description**

Obtains the pitch angle of a metadata object (such as a face). The value range is [-90, 90], with the positive direction being downwards.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| float* pitchAngle | Pointer to the pitch angle.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST**: The optional property does not exist.|

### OH_MetadataObjectExt_GetYawAngle()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetYawAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* yawAngle)
```

**Description**

Obtains the yaw angle of a metadata object (such as a face). The value range is [-90, 90], with the positive direction being rightwards.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| float* yawAngle | Pointer to the yaw angle.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST**: The optional property does not exist.|

### OH_MetadataObjectExt_GetRollAngle()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetRollAngle(const OH_Camera_MetadataObjectExt* metadataObjectExt, float* rollAngle)
```

**Description**

Obtains the roll angle of a metadata object (such as a face). The value range is [-180, 180], with the positive direction being clockwise.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| float* rollAngle | Pointer to the roll angle.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST**: The optional property does not exist.|

### OH_MetadataObjectExt_GetLeftEyeBoundingBox()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetLeftEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)
```

**Description**

Obtains the left eye bounding box of a metadata object (such as a face).

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| [OH_Camera_Rect_Ext](capi-oh-camera-oh-camera-rect-ext.md)* boundingBox | Pointer to an **OH_Camera_Rect_Ext** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST**: The optional property does not exist.|

### OH_MetadataObjectExt_GetRightEyeBoundingBox()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetRightEyeBoundingBox(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_Rect_Ext* boundingBox)
```

**Description**

Obtains the right eye bounding box of a metadata object (such as a face).

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| [OH_Camera_Rect_Ext](capi-oh-camera-oh-camera-rect-ext.md)* boundingBox | Pointer to an **OH_Camera_Rect_Ext** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST**: The optional property does not exist.|

### OH_MetadataObjectExt_GetEmotion()

```c
Camera_ErrorCode OH_MetadataObjectExt_GetEmotion(const OH_Camera_MetadataObjectExt* metadataObjectExt, OH_Camera_MetadataObjectEmotion* emotion)
```

**Description**

Obtains the emotion of a metadata object (such as a face).

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| [OH_Camera_MetadataObjectEmotion](capi-camera-h.md#oh_camera_metadataobjectemotion)* emotion | Pointer to an **OH_Camera_MetadataObjectEmotion** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST**: The optional property does not exist.|

### OH_MetadataObjectExt_Destroy()

```c
void OH_MetadataObjectExt_Destroy(OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t objectCount)
```

**Description**

Destroys an **OH_Camera_MetadataObjectExt** instance array.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)** metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance.|
| uint32_t objectCount | Number of metadata objects to destroy.|

### OH_MetadataObjectExt_IsLockFocusTracked()

```c
bool OH_MetadataObjectExt_IsLockFocusTracked(const OH_Camera_MetadataObjectExt* metadataObjectExt)
```

**Description**

Checks whether the focus is locked for tracking.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| const [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)* metadataObjectExt | Pointer to an **OH_Camera_MetadataObjectExt** instance. |

**Returns**

| Type | Description |
| -- | -- |
| bool | Whether the focus is locked for tracking. The value **true** means it is locked, and **false** means it is not locked. |