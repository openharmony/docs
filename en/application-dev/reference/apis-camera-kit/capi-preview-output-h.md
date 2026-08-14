# preview_output.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=49098dc8bf8e2b87271445659fa4b6b57bf81d5e translatedAt=2026-08-11T02:03:52.519Z pushedAt=2026-08-12T07:52:34.000Z -->

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
| [Camera_ErrorCode OH_PreviewOutput_GetPreviewRotationWithoutDisplayRotation(Camera_PreviewOutput* previewOutput, Camera_ImageRotation* imageRotation)](#oh_previewoutput_getpreviewrotationwithoutdisplayrotation) | - | Obtains the preview rotation angle.|
| [Camera_ErrorCode OH_PreviewOutput_SetPreviewRotation(Camera_PreviewOutput* previewOutput, Camera_ImageRotation previewRotation, bool isDisplayLocked)](#oh_previewoutput_setpreviewrotation) | - | Sets the preview rotation angle.|
| [Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)](#oh_previewoutput_getsupportedframerates) | - | Obtains the list of frame rates supported by a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)](#oh_previewoutput_deleteframerates) | - | Deletes the frame rate list.|
| [Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput, int32_t minFps, int32_t maxFps)](#oh_previewoutput_setframerate) | - | Sets the frame rates for a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)](#oh_previewoutput_getactiveframerate) | - | Obtains the active frame rates of a PreviewOutput instance.|
| [Camera_ErrorCode OH_PreviewOutput_IsBandwidthCompressionSupported(Camera_PreviewOutput* previewOutput, bool* isSupported)](#oh_previewoutput_isbandwidthcompressionsupported) | - | Checks whether preview bandwidth compression is supported. This involves reducing data volume through encoding to minimize bandwidth usage during transmission.|
| [Camera_ErrorCode OH_PreviewOutput_EnableBandwidthCompression(Camera_PreviewOutput* previewOutput, bool enabled)](#oh_previewoutput_enablebandwidthcompression) | - | Enables preview bandwidth compression.<br>This function must be called prior to [OH_CaptureSession_CommitConfig()](capi-capture-session-h.md#oh_capturesession_commitconfig). Otherwise, the preview output stream format will be affected.|
| [Camera_ErrorCode OH_PreviewOutput_AddDeferredSurface(const Camera_PreviewOutput* previewOutput, const char* surfaceId)](#oh_previewoutput_adddeferredsurface) | - | Adds a surface for delayed preview.|
| [bool OH_PreviewOutput_IsLogViewAssistSupported(const Camera_PreviewOutput* previewOutput)](#oh_previewoutput_islogviewassistsupported) | - | Checks whether view assist is supported.|
| [Camera_ErrorCode OH_PreviewOutput_SetLogViewAssistEnable(Camera_PreviewOutput* previewOutput, bool enable)](#oh_previewoutput_setlogviewassistenable) | - | Enables view assist.<br>This API can be called only after [OH_CaptureSession_CommitConfig()](capi-capture-session-h.md#oh_capturesession_commitconfig) is called. |

## Function Description

### OH_PreviewOutput_OnFrameStart()

```c
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

```c
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

```c
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

```c
Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)
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

```c
Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)
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

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_Stop()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_Release()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_GetActiveProfile()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_DeleteProfile()

```c
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

```c
Camera_ErrorCode OH_PreviewOutput_GetPreviewRotation(Camera_PreviewOutput* previewOutput, int displayRotation, Camera_ImageRotation* imageRotation)
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_GetPreviewRotationWithoutDisplayRotation()

```c
Camera_ErrorCode OH_PreviewOutput_GetPreviewRotationWithoutDisplayRotation(Camera_PreviewOutput* previewOutput, Camera_ImageRotation* imageRotation)
```

**Description**

Obtains the preview rotation angle.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the PreviewOutput instance used to obtain the rotation angle.|
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation)* imageRotation | Pointer to the preview rotation angle.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_SetPreviewRotation()

```c
Camera_ErrorCode OH_PreviewOutput_SetPreviewRotation(Camera_PreviewOutput* previewOutput, Camera_ImageRotation previewRotation, bool isDisplayLocked)
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_GetSupportedFrameRates()

```c
Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_DeleteFrameRates()

```c
Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)
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

```c
Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput, int32_t minFps, int32_t maxFps)
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

```c
Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_IsBandwidthCompressionSupported()

```c
Camera_ErrorCode OH_PreviewOutput_IsBandwidthCompressionSupported(Camera_PreviewOutput* previewOutput, bool* isSupported)
```

**Description**

Checks whether preview bandwidth compression is supported. This involves reducing data volume through encoding to minimize bandwidth usage during transmission.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the target PreviewOutput instance.|
| bool* isSupported | Pointer to the check result for the support of bandwidth compression. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_EnableBandwidthCompression()

```c
Camera_ErrorCode OH_PreviewOutput_EnableBandwidthCompression(Camera_PreviewOutput* previewOutput, bool enabled)
```

**Description**

Enables preview bandwidth compression.<br> This function must be called prior to [OH_CaptureSession_CommitConfig()](capi-capture-session-h.md#oh_capturesession_commitconfig). Otherwise, the preview output stream format will be affected.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the target PreviewOutput instance.|
| bool enabled | Whether to enable preview bandwidth compression. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>     **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>    **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_PreviewOutput_AddDeferredSurface()

```c
Camera_ErrorCode OH_PreviewOutput_AddDeferredSurface(const Camera_PreviewOutput* previewOutput, const char* surfaceId)
```

**Description**

Adds a surface for delayed preview.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [const Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the **PreviewOutput** instance of the surface ID to add.|
| const char* surfaceId | Pointer to the surface ID used for creating the **Camera_PreviewOutput** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_PreviewOutput_IsLogViewAssistSupported()

```c
bool OH_PreviewOutput_IsLogViewAssistSupported(const Camera_PreviewOutput* previewOutput)
```

**Description**

Checks whether view assist is supported.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the target **PreviewOutput** instance. |

**Returns**

| Type | Description |
| -- | -- |
| bool | Whether view assist is supported. The value **true** indicates it is supported, and **false** indicates otherwise. |

### OH_PreviewOutput_SetLogViewAssistEnable()

```c
Camera_ErrorCode OH_PreviewOutput_SetLogViewAssistEnable(Camera_PreviewOutput* previewOutput, bool enable)
```

**Description**

Enables view assist.<br> This API can be called only after [OH_CaptureSession_CommitConfig()](capi-capture-session-h.md#oh_capturesession_commitconfig) is called.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | Pointer to the **previewOutput** instance for which view assist is to be enabled. |
| bool enable | Whether to enable view assist for preview. The value **true** indicates that view assist is enabled, and the value **false** indicates otherwise. |

**Returns**

| Type | Description |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br> **CAMERA_ERROR_CAPABILITY_NOT_SUPPORTED**: The device does not support this capability.<br> **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br> **CAMERA_SESSION_NOT_CONFIG**: The camera session is not configured.<br> **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal. |