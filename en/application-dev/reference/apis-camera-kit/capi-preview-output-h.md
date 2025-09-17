# preview_output.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the preview output concepts.

**File to include**: <ohcamera/preview_output.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md) | PreviewOutput_Callbacks | Describes the callbacks related to preview output.|
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md) | Camera_PreviewOutput | Describes the preview output object.<br> You can use [OH_CameraManager_CreatePreviewOutput](capi-camera-manager-h.md#oh_cameramanager_createpreviewoutput) to create such an object.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_PreviewOutput_OnFrameStart)(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_onframestart) | OH_PreviewOutput_OnFrameStart | Defines the callback defined in the [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md) struct and used to report preview output frame start events.|
| [typedef void (\*OH_PreviewOutput_OnFrameEnd)(Camera_PreviewOutput* previewOutput, int32_t frameCount)](#oh_previewoutput_onframeend) | OH_PreviewOutput_OnFrameEnd | Defines the callback defined in the [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md) struct and used to report preview output frame end events.|
| [typedef void (\*OH_PreviewOutput_OnError)(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)](#oh_previewoutput_onerror) | OH_PreviewOutput_OnError | Defines the callback defined in the [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md) struct and used to report preview output errors.|
| [Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)](#oh_previewoutput_registercallback) | - | Registers a callback to listen for preview output events.|
| [Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)](#oh_previewoutput_unregistercallback) | - | Unregisters the callback used to listen for preview output events.|
| [Camera_ErrorCode OH_PreviewOutput_Start(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_start) | - | Starts preview output.|
| [Camera_ErrorCode OH_PreviewOutput_Stop(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_stop) | - | Stops preview output.|
| [Camera_ErrorCode OH_PreviewOutput_Release(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_release) | - | Releases a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_GetActiveProfile(Camera_PreviewOutput* previewOutput, Camera_Profile** profile)](#oh_previewoutput_getactiveprofile) | - | Obtains the profile of a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_DeleteProfile(Camera_Profile* profile)](#oh_previewoutput_deleteprofile) | - | Deletes the profile of a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_GetPreviewRotation(Camera_PreviewOutput* previewOutput, int displayRotation, Camera_ImageRotation* imageRotation)](#oh_previewoutput_getpreviewrotation) | - | Obtains the preview rotation angle.|
| [Camera_ErrorCode OH_PreviewOutput_SetPreviewRotation(Camera_PreviewOutput* previewOutput, Camera_ImageRotation previewRotation, bool isDisplayLocked)](#oh_previewoutput_setpreviewrotation) | - | Sets the preview rotation angle.|
| [Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)](#oh_previewoutput_getsupportedframerates) | - | Obtains the list of frame rates supported by a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)](#oh_previewoutput_deleteframerates) | - | Deletes the frame rate list.|
| [Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput, int32_t minFps, int32_t maxFps)](#oh_previewoutput_setframerate) | - | Sets the frame rates for a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)](#oh_previewoutput_getactiveframerate) | - | Obtains the active frame rates of a PreviewOutput instance.|

## Function Description

### OH_PreviewOutput_OnFrameStart()

```
typedef void (*OH_PreviewOutput_OnFrameStart)(Camera_PreviewOutput* previewOutput)
```

**Description**

Defines the callback defined in the [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md) struct and used to report preview output frame start events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance that transfers the callback.|

### OH_PreviewOutput_OnFrameEnd()

```
typedef void (*OH_PreviewOutput_OnFrameEnd)(Camera_PreviewOutput* previewOutput, int32_t frameCount)
```

**Description**

Defines the callback defined in the [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md) struct and used to report preview output frame end events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance that transfers the callback.|
|  int32_t frameCount | Number of frames to be included in the callback.|

### OH_PreviewOutput_OnError()

```
typedef void (*OH_PreviewOutput_OnError)(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md) struct and used to report preview output errors.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance that transfers the callback.|
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | Error code reported during preview output.|

**See also**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_PreviewOutput_RegisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput,PreviewOutput_Callbacks* callback)
```

**Description**

Registers a callback to listen for preview output events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the target PreviewOutput instance.|
| [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_PreviewOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput,PreviewOutput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for preview output events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the target PreviewOutput instance.|
| [PreviewOutput_Callbacks](capi-oh-camera-previewoutput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_PreviewOutput_Start()

```
Camera_ErrorCode OH_PreviewOutput_Start(Camera_PreviewOutput* previewOutput)
```

**Description**

Starts preview output.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance to start.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_PreviewOutput_Stop()

```
Camera_ErrorCode OH_PreviewOutput_Stop(Camera_PreviewOutput* previewOutput)
```

**Description**

Stops preview output.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance to stop.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_PreviewOutput_Release()

```
Camera_ErrorCode OH_PreviewOutput_Release(Camera_PreviewOutput* previewOutput)
```

**Description**

Releases a PreviewOutput instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance to release.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_PreviewOutput_GetActiveProfile()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveProfile(Camera_PreviewOutput* previewOutput, Camera_Profile** profile)
```

**Description**

Obtains the profile of a PreviewOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance for which the profile is to be obtained.|
| [Camera_Profile](capi-oh-camera-camera-profile.md)** profile | Double pointer to the preview output profile obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_PreviewOutput_DeleteProfile()

```
Camera_ErrorCode OH_PreviewOutput_DeleteProfile(Camera_Profile* profile)
```

**Description**

Deletes the profile of a PreviewOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Profile](capi-oh-camera-camera-profile.md)* profile | Pointer to the profile to delete.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_PreviewOutput_GetPreviewRotation()

```
Camera_ErrorCode OH_PreviewOutput_GetPreviewRotation(Camera_PreviewOutput* previewOutput, int displayRotation,Camera_ImageRotation* imageRotation)
```

**Description**

Obtains the preview rotation angle.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance used to obtain the rotation angle.|
| int displayRotation | Rotation angle of the display.|
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation)* imageRotation | Pointer to the preview rotation angle.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_PreviewOutput_SetPreviewRotation()

```
Camera_ErrorCode OH_PreviewOutput_SetPreviewRotation(Camera_PreviewOutput* previewOutput,Camera_ImageRotation previewRotation, bool isDisplayLocked)
```

**Description**

Sets the preview rotation angle.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance used to set the rotation angle.|
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation) previewRotation | Preview rotation angle.|
| bool isDisplayLocked | Whether the orientation of the surface is locked when the screen rotates. If this parameter is not set, the default value **false** is used, indicating that the orientation is not locked. **true** if locked, **false** otherwise. For details, see [SurfaceRotationOptions](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#surfacerotationoptions12).|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_PreviewOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**Description**

Obtains the list of frame rates supported by a PreviewOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance used to obtain the frame rates.|
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)** frameRateRange | Double pointer to the list of frame rates, if the function is successfully called.|
| uint32_t* size | Pointer to the size of the list of frame rates.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_PreviewOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange* frameRateRange)
```

**Description**

Deletes the frame rate list.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the target PreviewOutput instance.|
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)* frameRateRange | Pointer to the list of frame rates to delete.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_PreviewOutput_SetFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput,int32_t minFps, int32_t maxFps)
```

**Description**

Sets the frame rates for a PreviewOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance used to set the frame rates.|
| int32_t minFps | Minimum frame rate.|
| int32_t maxFps | Maximum frame rate.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_PreviewOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange* frameRateRange)
```

**Description**

Obtains the active frame rates of a PreviewOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance used to obtain the active frame rates.|
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)* frameRateRange | Pointer to the frame rate range, which is defined in the [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md) struct, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|
