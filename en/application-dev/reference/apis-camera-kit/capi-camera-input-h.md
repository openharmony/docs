# camera_input.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the camera input concepts.

**File to include**: <ohcamera/camera_input.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md) | CameraInput_Callbacks | Describes the callbacks used to listen for camera input errors.|
| [Camera_Input](capi-oh-camera-camera-input.md) | Camera_Input | Describes the camera input object. You can use [OH_CameraManager_CreateCameraInput](capi-camera-manager-h.md#oh_cameramanager_createcamerainput) to create such an object.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)](#oh_camerainput_onerror) | OH_CameraInput_OnError | Defines the callback defined in the [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md) struct and used to report camera input errors.|
| [Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)](#oh_camerainput_registercallback) | - | Registers a callback to listen for camera input events.|
| [Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)](#oh_camerainput_unregistercallback) | - | Unregisters the callback used to listen for camera input events.|
| [Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput)](#oh_camerainput_open) | - | Opens a camera.|
| [Camera_ErrorCode OH_CameraInput_OpenSecureCamera(Camera_Input* cameraInput, uint64_t* secureSeqId)](#oh_camerainput_opensecurecamera) | - | Opens a camera in secure mode.|
| [Camera_ErrorCode OH_CameraInput_OpenConcurrentCameras(Camera_Input* cameraInput, Camera_ConcurrentType type)](#oh_camerainput_openconcurrentcameras) | - | Opens the camera based on the specified concurrency type.|
| [Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput)](#oh_camerainput_close) | - | Closes a camera.|
| [Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput)](#oh_camerainput_release) | - | Releases a Camera_Input instance.<br> Either this function or [OH_CameraInput_Close](capi-camera-input-h.md#oh_camerainput_close) needs to be called.|
| [Camera_ErrorCode OH_CameraInput_IsPhysicalCameraOrientationVariable(Camera_Input* cameraInput, bool* isVariable)](#oh_camerainput_isphysicalcameraorientationvariable) | - | Checks whether the physical camera orientation is adjustable in different fold states.|
| [Camera_ErrorCode OH_CameraInput_GetPhysicalCameraOrientation(Camera_Input* cameraInput, uint32_t* orientation)](#oh_camerainput_getphysicalcameraorientation) | - | Obtains the physical camera orientation in the current fold state.|
| [Camera_ErrorCode OH_CameraInput_UsePhysicalCameraOrientation(Camera_Input* cameraInput, bool isUsed)](#oh_camerainput_usephysicalcameraorientation) | - | Enables or disables the use of the physical camera orientation.|

## Function Description

### OH_CameraInput_OnError()

```
typedef void (*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md) struct and used to report camera input errors.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | Error code reported during camera input and defined in the Camera_ErrorCode struct.|

**See also**

[CAMERA_CONFLICT_CAMERA](capi-camera-h.md#camera_errorcode)

[CAMERA_DEVICE_DISABLED](capi-camera-h.md#camera_errorcode)

[CAMERA_DEVICE_PREEMPTED](capi-camera-h.md#camera_errorcode)

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)


### OH_CameraInput_RegisterCallback()

```
Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**Description**

Registers a callback to listen for camera input events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraInput_UnregisterCallback()

```
Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for camera input events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md)* callback | Pointer to the target callback.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraInput_Open()

```
Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput)
```

**Description**

Opens a camera.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_CONFLICT_CAMERA**: The camera cannot be used due to a conflict.<br>         **CAMERA_DEVICE_DISABLED**: The camera is disabled due to security reasons.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_CameraInput_OpenSecureCamera()

```
Camera_ErrorCode OH_CameraInput_OpenSecureCamera(Camera_Input* cameraInput, uint64_t* secureSeqId)
```

**Description**

Opens a camera in secure mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| uint64_t* secureSeqId | Pointer to the sequence ID of the camera.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_CONFLICT_CAMERA**: The camera cannot be used due to a conflict.<br>         **CAMERA_DEVICE_DISABLED**: The camera is disabled due to security reasons.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_CameraInput_OpenConcurrentCameras()

```
Camera_ErrorCode OH_CameraInput_OpenConcurrentCameras(Camera_Input* cameraInput, Camera_ConcurrentType type)
```

**Description**

Opens the camera based on the specified concurrency type.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| [Camera_ConcurrentType](capi-camera-h.md#camera_concurrenttype) type | Concurrency type.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_CONFLICT_CAMERA**: The camera cannot be used due to a conflict.<br>         **CAMERA_DEVICE_DISABLED**: The camera is disabled due to security reasons.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_CameraInput_Close()

```
Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput)
```

**Description**

Closes a camera.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_CameraInput_Release()

```
Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput)
```

**Description**

Releases a Camera_Input instance.

Either this function or [OH_CameraInput_Close](capi-camera-input-h.md#oh_camerainput_close) needs to be called.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_CameraInput_IsPhysicalCameraOrientationVariable()

```
Camera_ErrorCode OH_CameraInput_IsPhysicalCameraOrientationVariable(Camera_Input* cameraInput, bool* isVariable)
```

**Description**

Checks whether the physical camera orientation is adjustable in different fold states.

**Since**: 21


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| bool* isVariable | Pointer to the check result for whether the physical camera orientation is adjustable. **true** if adjustable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraInput_GetPhysicalCameraOrientation()

```
Camera_ErrorCode OH_CameraInput_GetPhysicalCameraOrientation(Camera_Input* cameraInput, uint32_t* orientation)
```

**Description**

Obtains the physical camera orientation in the current fold state.

**Since**: 21


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| uint32_t* orientation | Pointer to the physical camera orientation if the operation is successful.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraInput_UsePhysicalCameraOrientation()

```
Camera_ErrorCode OH_CameraInput_UsePhysicalCameraOrientation(Camera_Input* cameraInput, bool isUsed)
```

**Description**

Enables or disables the use of the physical camera orientation.

**Since**: 21


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Pointer to the target Camera_Input instance.|
| bool isUsed | Whether to enable the use of the physical camera orientation. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|
