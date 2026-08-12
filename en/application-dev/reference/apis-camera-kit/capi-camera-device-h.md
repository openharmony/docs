# camera_device.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=7b5b0cb39f94db799420f13dcf4f3f8b2658983b translatedAt=2026-08-11T02:00:52.461Z pushedAt=2026-08-12T01:29:52.999Z -->

## Overview

Defines the basic APIs of the camera device.

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
| [Camera_ErrorCode OH_CameraDevice_GetLensEquivalentFocalLengths(const Camera_Device* camera, uint32_t** equivalentFocalLengths, uint32_t* size)](#oh_cameradevice_getlensequivalentfocallengths) | Obtains the equivalent focal length of a camera.|
| [Camera_ErrorCode OH_CameraDevice_IsLogicalCamera(const Camera_Device* camera, bool* isLogicalCamera)](#oh_cameradevice_islogicalcamera) | Checks whether a camera is a logical camera (consisting of multiple physical cameras).|
| [Camera_ErrorCode OH_CameraDevice_GetLogicalCameraConstituentCameraDevices(const Camera_Device* logicalCamera, Camera_Device** constituentCameras, uint32_t* size)](#oh_cameradevice_getlogicalcameraconstituentcameradevices) | Obtains all physical cameras that constitute a logical camera by calling [OH_CameraDevice_DeleteConstituentCameraDevices](capi-camera-device-h.md#oh_cameradevice_deleteconstituentcameradevices).|
| [Camera_ErrorCode OH_CameraDevice_DeleteConstituentCameraDevices(const Camera_Device* logicalCamera, Camera_Device* constituentCameras, uint32_t size)](#oh_cameradevice_deleteconstituentcameradevices) | Deletes all physical cameras that constitute a logical camera.|
| [Camera_ErrorCode OH_CameraDevice_GetLensFocalLength(const Camera_Device* camera, float* lensFocalLength)](#oh_cameradevice_getlensfocallength) | Obtains the focal length of a camera.|
| [Camera_ErrorCode OH_CameraDevice_GetMinimumFocusDistance(const Camera_Device* camera, float* minimumFocusDistance)](#oh_cameradevice_getminimumfocusdistance) | Obtains the minimum focus distance of a camera.|
| [Camera_ErrorCode OH_CameraDevice_GetLensDistortion(const Camera_Device* camera, float** lens, uint32_t* size)](#oh_cameradevice_getlensdistortion) | Obtains the distortion parameters of a camera.|
| [Camera_ErrorCode OH_CameraDevice_GetIntrinsicCalibration(const Camera_Device* camera, float** intrinsicCalibration, uint32_t* size)](#oh_cameradevice_getintrinsiccalibration) | Obtains the intrinsic calibration parameters of a camera.|
| [Camera_ErrorCode OH_CameraDevice_GetSensorPhysicalSize(const Camera_Device* camera, float* width, float* height)](#oh_cameradevice_getsensorphysicalsize) | Obtains the physical dimensions of a camera sensor.|
| [Camera_ErrorCode OH_CameraDevice_GetSensorPixelArraySize(const Camera_Device* camera, uint32_t* width, uint32_t* height)](#oh_cameradevice_getsensorpixelarraysize) | Obtains the pixel array dimensions of a camera sensor.|
| [Camera_ErrorCode OH_CameraDevice_GetSensorColorFilterArrangement(const Camera_Device* camera, OH_Camera_SensorColorFilterArrangement* sensorCFA)](#oh_cameradevice_getsensorcolorfilterarrangement) | Obtains the color filter array arrangement of a camera sensor.|
| [Camera_ErrorCode OH_CameraDevice_GetAutomotiveCameraPosition(const Camera_Device* camera, OH_Camera_AutomotiveCameraPosition* automotiveCameraPosition)](#oh_cameradevice_getautomotivecameraposition) | Obtains the camera position on a car. |

## Function Description

### OH_CameraDevice_GetCameraOrientation()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetHostDeviceName()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful, and the remote device name is returned.<br>         **CAMERA_CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetHostDeviceType()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful, and the remote device name is returned.<br>         **CAMERA_CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetLensEquivalentFocalLengths()

```c
Camera_ErrorCode OH_CameraDevice_GetLensEquivalentFocalLengths(const Camera_Device* camera, uint32_t** equivalentFocalLengths, uint32_t* size)
```

**Description**

Obtains the equivalent focal length of a camera.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| uint32_t** equivalentFocalLengths | Array of equivalent focal lengths.|
| uint32_t* size | Array size.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_IsLogicalCamera()

```c
Camera_ErrorCode OH_CameraDevice_IsLogicalCamera(const Camera_Device* camera, bool* isLogicalCamera)
```

**Description**

Checks whether a camera is a logical camera (consisting of multiple physical cameras).

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| bool* isLogicalCamera | Boolean indicating whether the camera is a logical camera.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetLogicalCameraConstituentCameraDevices()

```c
Camera_ErrorCode OH_CameraDevice_GetLogicalCameraConstituentCameraDevices(const Camera_Device* logicalCamera, Camera_Device** constituentCameras, uint32_t* size)
```

**Description**

Obtains all physical cameras that constitute a logical camera by calling [OH_CameraDevice_DeleteConstituentCameraDevices](capi-camera-device-h.md#oh_cameradevice_deleteconstituentcameradevices).

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* logicalCamera | Pointer to the logical camera device.|
| [Camera_Device](capi-oh-camera-camera-device.md)** constituentCameras | Array of pointers to the physical cameras that constitute the logical camera.|
| uint32_t* size | Array size.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_DeleteConstituentCameraDevices()

```c
Camera_ErrorCode OH_CameraDevice_DeleteConstituentCameraDevices(const Camera_Device* logicalCamera, Camera_Device* constituentCameras, uint32_t size)
```

**Description**

Deletes all physical cameras that constitute a logical camera.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* logicalCamera | Pointer to the logical camera device.|
| [Camera_Device](capi-oh-camera-camera-device.md)* constituentCameras | Array of pointers to the physical cameras that constitute the logical camera.|
| uint32_t size | Array size.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.|

### OH_CameraDevice_GetLensFocalLength()

```c
Camera_ErrorCode OH_CameraDevice_GetLensFocalLength(const Camera_Device* camera, float* lensFocalLength)
```

**Description**

Obtains the focal length of a camera.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| float* lensFocalLength | Focal length.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetMinimumFocusDistance()

```c
Camera_ErrorCode OH_CameraDevice_GetMinimumFocusDistance(const Camera_Device* camera, float* minimumFocusDistance)
```

**Description**

Obtains the minimum focus distance of a camera.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| float* minimumFocusDistance | Minimum focus distance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetLensDistortion()

```c
Camera_ErrorCode OH_CameraDevice_GetLensDistortion(const Camera_Device* camera, float** lens, uint32_t* size)
```

**Description**

Obtains the distortion parameters of a camera.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| float** lens | Array of lens distortion parameters.|
| uint32_t* size | Array size.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetIntrinsicCalibration()

```c
Camera_ErrorCode OH_CameraDevice_GetIntrinsicCalibration(const Camera_Device* camera, float** intrinsicCalibration, uint32_t* size)
```

**Description**

Obtains the intrinsic calibration parameters of a camera.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| float** intrinsicCalibration | Array of intrinsic calibration parameters.|
| uint32_t* size | Array size.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetSensorPhysicalSize()

```c
Camera_ErrorCode OH_CameraDevice_GetSensorPhysicalSize(const Camera_Device* camera, float* width, float* height)
```

**Description**

Obtains the physical dimensions of a camera sensor.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| float* width | Sensor width, in millimeters.|
| float* height | Sensor height, in millimeters.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetSensorPixelArraySize()

```c
Camera_ErrorCode OH_CameraDevice_GetSensorPixelArraySize(const Camera_Device* camera, uint32_t* width, uint32_t* height)
```

**Description**

Obtains the pixel array dimensions of a camera sensor.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| uint32_t* width | Pixel array width, in pixels.|
| uint32_t* height | Pixel array height, in pixels.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetSensorColorFilterArrangement()

```c
Camera_ErrorCode OH_CameraDevice_GetSensorColorFilterArrangement(const Camera_Device* camera, OH_Camera_SensorColorFilterArrangement* sensorCFA)
```

**Description**

Obtains the color filter array arrangement of a camera sensor.

**Since:** 24

**Parameters**

| Name| Description|
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the camera device.|
| [OH_Camera_SensorColorFilterArrangement](capi-camera-h.md#oh_camera_sensorcolorfilterarrangement)* sensorCFA | Arrangement modes of the sensor color filter.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_CameraDevice_GetAutomotiveCameraPosition()

```c
Camera_ErrorCode OH_CameraDevice_GetAutomotiveCameraPosition(const Camera_Device* camera, OH_Camera_AutomotiveCameraPosition* automotiveCameraPosition)
```

**Description**

Obtains the camera position on a car.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| const [Camera_Device](capi-oh-camera-camera-device.md)* camera | Pointer to the **Camera_Device** instance used to retrieve the attribute. |
| [OH_Camera_AutomotiveCameraPosition](capi-camera-h.md#oh_camera_automotivecameraposition)* automotiveCameraPosition | Output parameter, which returns the enumerated values of the camera position on a car. |

**Returns**

| Type | Description |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal. |