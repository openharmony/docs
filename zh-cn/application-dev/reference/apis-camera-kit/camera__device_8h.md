# camera_device.h


## 概述

声明相机的基本概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/camera_device.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 12

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CameraDevice_GetCameraOrientation](_o_h___camera.md#oh_cameradevice_getcameraorientation) ([Camera_Device](_camera___device.md) \*camera, uint32_t \*orientation) | 获取相机设备的传感器方向属性。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode)  [OH_CameraDevice_GetHostDeviceName](_o_h___camera.md#oh_cameradevice_gethostdevicename) ([Camera_Device](_camera___device.md) \*camera, char \*\*hostDeviceName) | 获取远程设备名称。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode)  [OH_CameraDevice_GetHostDeviceType](_o_h___camera.md#oh_cameradevice_gethostdevicetype) ([Camera_Device](_camera___device.md) \*camera, [Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype) \*hostDeviceType) | 获取远程设备类型。 | 
