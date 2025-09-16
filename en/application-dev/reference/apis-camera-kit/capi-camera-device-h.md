# camera_device.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the basic concepts of the camera device.

**File to include**: <ohcamera/camera_device.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 12

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [Camera_ErrorCode OH_CameraDevice_GetCameraOrientation(Camera_Device* camera, uint32_t* orientation)](#oh_cameradevice_getcameraorientation) | Obtains the sensor direction of a camera device.|
| [Camera_ErrorCode OH_CameraDevice_GetHostDeviceName(Camera_Device* camera, char** hostDeviceName)](#oh_cameradevice_gethostdevicename) | Obtains the name of a remote device.|
| [Camera_ErrorCode OH_CameraDevice_GetHostDeviceType(Camera_Device* camera, Camera_HostDeviceType* hostDeviceType)](#oh_cameradevice_gethostdevicetype) | Obtains the type of a remote device.|

## Function Description

### OH_CameraDevice_GetCameraOrientation()

```
Camera_ErrorCode OH_CameraDevice_GetCameraOrientation(Camera_Device* camera, uint32_t* orientation)
```

**Description**

Obtains the sensor direction of a camera device.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| uint32_t* orientation | Pointer to the sensor direction obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_CameraDevice_GetHostDeviceName()

```
Camera_ErrorCode OH_CameraDevice_GetHostDeviceName(Camera_Device* camera, char** hostDeviceName)
```

**Description**

Obtains the name of a remote device.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| char** hostDeviceName | Double pointer to the name of the remote device.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful, and the remote device name is returned.<br>         **CAMERA_CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_CameraDevice_GetHostDeviceType()

```
Camera_ErrorCode OH_CameraDevice_GetHostDeviceType(Camera_Device* camera, Camera_HostDeviceType* hostDeviceType)
```

**Description**

Obtains the type of a remote device.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| [Camera_HostDeviceType](capi-camera-h.md#camera_hostdevicetype)* hostDeviceType | Pointer to the type of the remote device.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful, and the remote device name is returned.<br>         **CAMERA_CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|
