# camera_device.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

## 概述

声明相机的基本概念。

**引用文件：** <ohcamera/camera_device.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 12

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [Camera_ErrorCode OH_CameraDevice_GetCameraOrientation(Camera_Device* camera, uint32_t* orientation)](#oh_cameradevice_getcameraorientation) | 获取相机设备的传感器方向属性。 |
| [Camera_ErrorCode OH_CameraDevice_GetHostDeviceName(Camera_Device* camera, char** hostDeviceName)](#oh_cameradevice_gethostdevicename) | 获取远程设备名称。 |
| [Camera_ErrorCode OH_CameraDevice_GetHostDeviceType(Camera_Device* camera, Camera_HostDeviceType* hostDeviceType)](#oh_cameradevice_gethostdevicetype) | 获取远程设备类型。 |

## 函数说明

### OH_CameraDevice_GetCameraOrientation()

```
Camera_ErrorCode OH_CameraDevice_GetCameraOrientation(Camera_Device* camera, uint32_t* orientation)
```

**描述**

获取相机设备的传感器方向属性。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | 用于获取属性的Camera_Device。 |
| uint32_t* orientation | 返回相机sensor角度属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功，返回传感器方向属性。<br>         CAMERA_CAMERA_INVALID_ARGUMENT：参数丢失或者参数不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CameraDevice_GetHostDeviceName()

```
Camera_ErrorCode OH_CameraDevice_GetHostDeviceName(Camera_Device* camera, char** hostDeviceName)
```

**描述**

获取远程设备名称。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | 用于获取属性的Camera_Device。 |
| char** hostDeviceName | 返回远程设备名称属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功，将返回远程设备名称属性。<br>         CAMERA_CAMERA_INVALID_ARGUMENT：参数丢失或者参数不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CameraDevice_GetHostDeviceType()

```
Camera_ErrorCode OH_CameraDevice_GetHostDeviceType(Camera_Device* camera, Camera_HostDeviceType* hostDeviceType)
```

**描述**

获取远程设备类型。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Device](capi-oh-camera-camera-device.md)* camera | 用于获取属性的Camera_Device。 |
| [Camera_HostDeviceType](capi-camera-h.md#camera_hostdevicetype)* hostDeviceType | 远程设备类型属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功，将返回远程设备名称属性。<br>         CAMERA_CAMERA_INVALID_ARGUMENT：参数丢失或者参数不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |


