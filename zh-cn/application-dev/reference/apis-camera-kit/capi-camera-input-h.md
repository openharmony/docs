# camera_input.h

## 概述

声明相机输入概念。

**引用文件：** <ohcamera/camera_input.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md) | CameraInput_Callbacks | 相机输入错误事件的回调。 |
| [Camera_Input](capi-oh-camera-camera-input.md) | Camera_Input | 相机输入对象。可以使用[OH_CameraManager_CreateCameraInput](capi-camera-manager-h.md#oh_cameramanager_createcamerainput)方法创建指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)](#oh_camerainput_onerror) | OH_CameraInput_OnError | 在[CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md)中被调用的相机输入错误回调。 |
| [Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)](#oh_camerainput_registercallback) | - | 注册相机输入更改事件回调。 |
| [Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)](#oh_camerainput_unregistercallback) | - | 注销相机输入更改事件回调。 |
| [Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput)](#oh_camerainput_open) | - | 打开相机。 |
| [Camera_ErrorCode OH_CameraInput_OpenSecureCamera(Camera_Input* cameraInput, uint64_t* secureSeqId)](#oh_camerainput_opensecurecamera) | - | 打开安全相机。 |
| [Camera_ErrorCode OH_CameraInput_OpenConcurrentCameras(Camera_Input* cameraInput, Camera_ConcurrentType type)](#oh_camerainput_openconcurrentcameras) | - | 根据指定并发类型打开相机。 |
| [Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput)](#oh_camerainput_close) | - | 关闭相机。 |
| [Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput)](#oh_camerainput_release) | - | 释放相机输入实例。<br> 和[OH_CameraInput_Close](capi-camera-input-h.md#oh_camerainput_close)只需要调用其中一个，调用之后无须再调用[OH_CameraInput_Close](capi-camera-input-h.md#oh_camerainput_close)。 |

## 函数说明

### OH_CameraInput_OnError()

```
typedef void (*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)
```

**描述**

在[CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md)中被调用的相机输入错误回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 传递回调的Camera_Input。 |
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | 相机输入的Camera_ErrorCode。 |

**参考：**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_CameraInput_RegisterCallback()

```
Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**描述**

注册相机输入更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Camera_Input实例。 |
| [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md)* callback | 要注册的相机输入更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CameraInput_UnregisterCallback()

```
Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**描述**

注销相机输入更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | Camera_Input实例。 |
| [CameraInput_Callbacks](capi-oh-camera-camerainput-callbacks.md)* callback | 要注销的相机输入更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CameraInput_Open()

```
Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput)
```

**描述**

打开相机。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要打开的Camera_Input实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_CONFLICT_CAMERA：因冲突而无法使用相机。<br>         CAMERA_DEVICE_DISABLED：由于安全原因禁用了相机。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CameraInput_OpenSecureCamera()

```
Camera_ErrorCode OH_CameraInput_OpenSecureCamera(Camera_Input* cameraInput, uint64_t* secureSeqId)
```

**描述**

打开安全相机。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要打开的Camera_Input实例。 |
| uint64_t* secureSeqId | 表示安全摄像头的序列值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_CONFLICT_CAMERA：因冲突而无法使用相机。<br>         CAMERA_DEVICE_DISABLED：由于安全原因禁用了相机。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CameraInput_OpenConcurrentCameras()

```
Camera_ErrorCode OH_CameraInput_OpenConcurrentCameras(Camera_Input* cameraInput, Camera_ConcurrentType type)
```

**描述**

根据指定并发类型打开相机。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要打开的Camera_Input实例。 |
| [Camera_ConcurrentType](capi-camera-h.md#camera_concurrenttype) type | 指定并发类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK: 方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_CONFLICT_CAMERA：因冲突而无法使用相机。<br>         CAMERA_DEVICE_DISABLED：由于安全原因禁用了相机。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CameraInput_Close()

```
Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput)
```

**描述**

关闭相机。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要关闭的Camera_Input实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CameraInput_Release()

```
Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput)
```

**描述**

释放相机输入实例。<br> 和[OH_CameraInput_Close](capi-camera-input-h.md#oh_camerainput_close)只需要调用其中一个，调用之后无须再调用[OH_CameraInput_Close](capi-camera-input-h.md#oh_camerainput_close)。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要释放的Camera_Input实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |


