# video_output.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the video output concepts.

**File to include**: <ohcamera/video_output.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) | VideoOutput_Callbacks | Describes the callbacks related to video output.|
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md) | Camera_VideoOutput | Describes the video output object.<br> You can use [OH_CameraManager_CreateVideoOutput](capi-camera-manager-h.md#oh_cameramanager_createvideooutput) to create such an object.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput)](#oh_videooutput_onframestart) | OH_VideoOutput_OnFrameStart | Defines the callback defined in the [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) struct and used to report video output frame start events.|
| [typedef void (\*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount)](#oh_videooutput_onframeend) | OH_VideoOutput_OnFrameEnd | Defines the callback defined in the [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) struct and used to report video output frame end events.|
| [typedef void (\*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)](#oh_videooutput_onerror) | OH_VideoOutput_OnError | Defines the callback defined in the [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) struct and used to report video output errors.|
| [Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)](#oh_videooutput_registercallback) | - | Registers a callback to listen for video output events.|
| [Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)](#oh_videooutput_unregistercallback) | - | Unregisters the callback used to listen for video output events.|
| [Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput)](#oh_videooutput_start) | - | Starts video output.|
| [Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput)](#oh_videooutput_stop) | - | Stops video output.|
| [Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput)](#oh_videooutput_release) | - | Releases a VideoOutput instance.|
| [Camera_ErrorCode OH_VideoOutput_GetActiveProfile(Camera_VideoOutput* videoOutput, Camera_VideoProfile** profile)](#oh_videooutput_getactiveprofile) | - | Obtains the profile of a VideoOutput instance.|
| [Camera_ErrorCode OH_VideoOutput_DeleteProfile(Camera_VideoProfile* profile)](#oh_videooutput_deleteprofile) | - | Deletes the profile of a VideoOutput instance.|
| [ Camera_ErrorCode OH_VideoOutput_IsMirrorSupported(Camera_VideoOutput* videoOutput, bool* isSupported)](#oh_videooutput_ismirrorsupported) | - | Checks whether a video output supports mirror mode.|
| [ Camera_ErrorCode OH_VideoOutput_EnableMirror(Camera_VideoOutput* videoOutput, bool mirrorMode)](#oh_videooutput_enablemirror) | - | Enables or disables mirror mode for a video output.|
| [ Camera_ErrorCode  OH_VideoOutput_GetVideoRotation(Camera_VideoOutput* videoOutput, int deviceDegree, Camera_ImageRotation* imageRotation)](#oh_videooutput_getvideorotation) | - | Obtains the rotation angle of a video output.|
| [Camera_ErrorCode OH_VideoOutput_GetSupportedFrameRates(Camera_VideoOutput* videoOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)](#oh_videooutput_getsupportedframerates) | - | Obtains the list of frame rates supported by a VideoOutput instance.|
| [Camera_ErrorCode OH_VideoOutput_DeleteFrameRates(Camera_VideoOutput* videoOutput, Camera_FrameRateRange* frameRateRange)](#oh_videooutput_deleteframerates) | - | Deletes the frame rate list.|
| [Camera_ErrorCode OH_VideoOutput_SetFrameRate(Camera_VideoOutput* videoOutput,int32_t minFps, int32_t maxFps)](#oh_videooutput_setframerate) | - | Sets the frame rates for a VideoOutput instance.|
| [Camera_ErrorCode OH_VideoOutput_GetActiveFrameRate(Camera_VideoOutput* videoOutput, Camera_FrameRateRange* frameRateRange)](#oh_videooutput_getactiveframerate) | - | Obtains the active frame rates of a VideoOutput instance.|

## Function Description

### OH_VideoOutput_OnFrameStart()

```
typedef void (*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput)
```

**Description**

Defines the callback defined in the [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) struct and used to report video output frame start events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance that transfers the callback.|

### OH_VideoOutput_OnFrameEnd()

```
typedef void (*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount)
```

**Description**

Defines the callback defined in the [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) struct and used to report video output frame end events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance that transfers the callback.|
|  int32_t frameCount | Number of frames to be included in the callback.|

### OH_VideoOutput_OnError()

```
typedef void (*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) struct and used to report video output errors.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance that transfers the callback.|
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | Error code reported during video output.|

**See also**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_VideoOutput_RegisterCallback()

```
Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**Description**

Registers a callback to listen for video output events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_VideoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for video output events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_VideoOutput_Start()

```
Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput)
```

**Description**

Starts video output.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance to start.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_Stop()

```
Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput)
```

**Description**

Stops video output.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance to stop.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_Release()

```
Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput)
```

**Description**

Releases a VideoOutput instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance to release.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_GetActiveProfile()

```
Camera_ErrorCode OH_VideoOutput_GetActiveProfile(Camera_VideoOutput* videoOutput, Camera_VideoProfile** profile)
```

**Description**

Obtains the profile of a VideoOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance for which the profile is to be obtained.|
| [Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md)** profile | Double pointer to the video output profile obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_DeleteProfile()

```
Camera_ErrorCode OH_VideoOutput_DeleteProfile(Camera_VideoProfile* profile)
```

**Description**

Deletes the profile of a VideoOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md)* profile | Pointer to the profile to delete.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_VideoOutput_IsMirrorSupported()

```
 Camera_ErrorCode OH_VideoOutput_IsMirrorSupported(Camera_VideoOutput* videoOutput, bool* isSupported)
```

**Description**

Checks whether a video output supports mirror mode.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| bool* isSupported | Pointer to the check result for the support of mirror mode. **true** if supported, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_EnableMirror()

```
 Camera_ErrorCode OH_VideoOutput_EnableMirror(Camera_VideoOutput* videoOutput, bool mirrorMode)
```

**Description**

Enables or disables mirror mode for a video output.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| bool mirrorMode | Whether to enable or disable mirror mode. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>          **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>          **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_GetVideoRotation()

```
 Camera_ErrorCode  OH_VideoOutput_GetVideoRotation(Camera_VideoOutput* videoOutput, int deviceDegree,Camera_ImageRotation* imageRotation)
```

**Description**

Obtains the rotation angle of a video output.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| int deviceDegree | Clockwise rotation angle of the device relative to the natural direction (the charging port faces downward).|
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation)* imageRotation | Pointer to the rotation angle of the video output.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>          **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>          **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_VideoOutput_GetSupportedFrameRates(Camera_VideoOutput* videoOutput,Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**Description**

Obtains the list of frame rates supported by a VideoOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)** frameRateRange | Double pointer to the list of frame rates, if the function is successfully called.|
| uint32_t* size | Pointer to the size of the list of frame rates.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_VideoOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_VideoOutput_DeleteFrameRates(Camera_VideoOutput* videoOutput,Camera_FrameRateRange* frameRateRange)
```

**Description**

Deletes the frame rate list.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)* frameRateRange | Pointer to the list of frame rates to delete.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_VideoOutput_SetFrameRate()

```
Camera_ErrorCode OH_VideoOutput_SetFrameRate(Camera_VideoOutput* videoOutput,int32_t minFps, int32_t maxFps)
```

**Description**

Sets the frame rates for a VideoOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the VideoOutput instance for which the frame rates are to be set.|
| int32_t minFps | Minimum frame rate.|
| int32_t maxFps | Maximum frame rate.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_VideoOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_VideoOutput_GetActiveFrameRate(Camera_VideoOutput* videoOutput,Camera_FrameRateRange* frameRateRange)
```

**Description**

Obtains the active frame rates of a VideoOutput instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | Pointer to the target VideoOutput instance.|
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)* frameRateRange | Pointer to the frame rate range, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|
