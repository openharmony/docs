# camera_device.h


## Overview

The **camera.h** file declares the basic concepts of the camera device.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/camera_device.h&gt;

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 12

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraDevice_GetCameraOrientation](_o_h___camera.md#oh_cameradevice_getcameraorientation) ([Camera_Device](_camera___device.md) \*camera, uint32_t \*orientation) | Obtains the sensor direction of a camera device. | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode)  [OH_CameraDevice_GetHostDeviceName](_o_h___camera.md#oh_cameradevice_gethostdevicename) ([Camera_Device](_camera___device.md) \*camera, char \*\*hostDeviceName) | Obtains the name of a remote device.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode)  [OH_CameraDevice_GetHostDeviceType](_o_h___camera.md#oh_cameradevice_gethostdevicetype) ([Camera_Device](_camera___device.md) \*camera, [Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype) \*hostDeviceType) | Obtains the type of a remote device.| 
