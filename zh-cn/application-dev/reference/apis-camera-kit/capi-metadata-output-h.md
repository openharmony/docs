# metadata_output.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明元数据输出概念。

**引用文件：** <ohcamera/metadata_output.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md) | MetadataOutput_Callbacks | 元数据输出的回调。 |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md) | Camera_MetadataOutput | 元数据输出对象。<br> 可以使用[OH_CameraManager_CreateMetadataOutput](capi-camera-manager-h.md#oh_cameramanager_createmetadataoutput)方法创建指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput, Camera_MetadataObject* metadataObject, uint32_t size)](#oh_metadataoutput_onmetadataobjectavailable) | OH_MetadataOutput_OnMetadataObjectAvailable | 在[MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)中被调用的元数据输出元数据对象可用回调。 |
| [typedef void (\*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)](#oh_metadataoutput_onerror) | OH_MetadataOutput_OnError | 在[MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)中被调用的元数据输出错误回调。 |
| [Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)](#oh_metadataoutput_registercallback) | - | 注册元数据输出更改事件回调。 |
| [Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)](#oh_metadataoutput_unregistercallback) | - | 注销元数据输出更改事件回调。 |
| [Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_start) | - | 启动元数据输出。 |
| [Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_stop) | - | 停止元数据输出。 |
| [Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_release) | - | 释放元数据输出实例。 |
| [Camera_ErrorCode OH_MetadataOutput_AddMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)](#oh_metadataoutput_addmetadataobjecttypes) | - | 添加元数据对象类型。 |
| [Camera_ErrorCode OH_MetadataOutput_RemoveMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)](#oh_metadataoutput_removemetadataobjecttypes) | - | 移除元数据对象类型。 |
| [typedef void (\*OH_MetadataOutput_OnMetadataObjectExtAvailable)(void* context, OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t size)](#oh_metadataoutput_onmetadataobjectextavailable) | OH_MetadataOutput_OnMetadataObjectExtAvailable | 用于监听元数据对象上报事件的回调。使用[OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_registermetadataobjectextavailablecallback)进行注册。 |
| [typedef void (\*OH_MetadataOutput_OnErrorExt)(void* context, Camera_ErrorCode errorCode)](#oh_metadataoutput_onerrorext) | OH_MetadataOutput_OnErrorExt | 在元数据输出期间，用于监听错误事件的回调。 |
| [Camera_ErrorCode OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)](#oh_metadataoutput_registermetadataobjectextavailablecallback) | - | 注册监听元数据对象上报事件的回调。该回调可通过[OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistermetadataobjectextavailablecallback)注销。 |
| [Camera_ErrorCode OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)](#oh_metadataoutput_unregistermetadataobjectextavailablecallback) | - | 注销监听元数据对象上报事件的回调。 |
| [Camera_ErrorCode OH_MetadataOutput_RegisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)](#oh_metadataoutput_registererrorextcallback) | - | 注册监听错误事件的回调。该回调可通过[OH_MetadataOutput_UnregisterErrorExtCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistererrorextcallback)注销。 |
| [Camera_ErrorCode OH_MetadataOutput_UnregisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)](#oh_metadataoutput_unregistererrorextcallback) | - | 注销监听错误事件的回调。 |
| [bool OH_MetadataOutput_IsLockMetadataObjectTrackingSupported(const Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_islockmetadataobjecttrackingsupported) | - | 检查设备是否支持锁定元数据对象（如猫脸、狗脸）追踪功能。 |
| [Camera_ErrorCode OH_MetadataOutput_LockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput, Camera_Point* pointOfInterest)](#oh_metadataoutput_lockmetadataobjecttracking) | - | 锁定对特定元数据对象（如猫脸、狗脸）的追踪。<br> 该功能以pointOfInterest所指向的点所在的对象为追踪对象，如果该点不存在追踪对象，则功能不生效。<br> 被锁定追踪的对象离开取景范围超过三秒或调用解锁追踪后，锁定追踪自动取消。 |
| [Camera_ErrorCode OH_MetadataOutput_UnlockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput)](#oh_metadataoutput_unlockmetadataobjecttracking) | - | 解锁元数据对象（如猫脸、狗脸）的追踪。 |

## 函数说明

### OH_MetadataOutput_OnMetadataObjectAvailable()

```c
typedef void (*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput, Camera_MetadataObject* metadataObject, uint32_t size)
```

**描述**

在[MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)中被调用的元数据输出元数据对象可用回调。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 传递回调的元数据输出实例。 |
| [Camera_MetadataObject](capi-oh-camera-camera-metadataobject.md)* metadataObject | 回调传递的元数据实例信息。 |
|  uint32_t size | 元数据对象的大小。 |

### OH_MetadataOutput_OnError()

```c
typedef void (*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)
```

**描述**

在[MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)中被调用的元数据输出错误回调。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 传递回调的元数据输出实例。 |
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | 元数据输出的错误码。 |

**参考：**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)


### OH_MetadataOutput_RegisterCallback()

```c
Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
```

**描述**

注册元数据输出更改事件回调。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例。 |
| [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)* callback | 要注册的元数据输出回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_MetadataOutput_UnregisterCallback()

```c
Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
```

**描述**

注销元数据输出更改事件回调。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例。 |
| [MetadataOutput_Callbacks](capi-oh-camera-metadataoutput-callbacks.md)* callback | 要注销的元数据输出回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_MetadataOutput_Start()

```c
Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput)
```

**描述**

启动元数据输出。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 要启动的元数据输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务异常。 |

### OH_MetadataOutput_Stop()

```c
Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput)
```

**描述**

停止元数据输出。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 要停止的元数据输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务异常。 |

### OH_MetadataOutput_Release()

```c
Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput)
```

**描述**

释放元数据输出实例。

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 要释放的元数据输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务异常。 |

### OH_MetadataOutput_AddMetadataObjectTypes()

```c
Camera_ErrorCode OH_MetadataOutput_AddMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)
```

**描述**

添加元数据对象类型。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例。 |
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* types | 用于添加到Camera_MetadataOutput实例的元数据对象类型数组。 |
| uint32_t size | 元数据对象类型数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务异常。 |

### OH_MetadataOutput_RemoveMetadataObjectTypes()

```c
Camera_ErrorCode OH_MetadataOutput_RemoveMetadataObjectTypes(Camera_MetadataOutput* metadataOutput, Camera_MetadataObjectType* types, uint32_t size)
```

**描述**

移除元数据对象类型。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例。 |
| [Camera_MetadataObjectType](capi-camera-h.md#camera_metadataobjecttype)* types | 从Camera_MetadataOutput实例移除的元数据对象类型数组。 |
| uint32_t size | 元数据对象类型数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务异常。 |

### OH_MetadataOutput_OnMetadataObjectExtAvailable()

```c
typedef void (*OH_MetadataOutput_OnMetadataObjectExtAvailable)(void* context, OH_Camera_MetadataObjectExt** metadataObjectExt, uint32_t size)
```

**描述**

用于监听元数据对象上报事件的回调。使用[OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_registermetadataobjectextavailablecallback)进行注册。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* context | 用户提供的上下文指针。 |
| [OH_Camera_MetadataObjectExt](capi-oh-camera-oh-camera-metadataobjectext.md)\*\* metadataObjectExt | 指向元数据对象的二级指针。 |
| uint32_t size | 元数据对象的数量。 |

### OH_MetadataOutput_OnErrorExt()

```c
typedef void (*OH_MetadataOutput_OnErrorExt)(void* context, Camera_ErrorCode errorCode)
```

**描述**

在元数据输出期间，用于监听错误事件的回调。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void\* context | 用户提供的上下文指针。 |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | 元数据输出期间报告的错误码。 |

### OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback()

```c
Camera_ErrorCode OH_MetadataOutput_RegisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)
```

**描述**

注册监听元数据对象上报事件的回调。该回调可通过[OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistermetadataobjectextavailablecallback)注销。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例的指针。 |
| void* context | 用户提供的上下文指针。 |
| [OH_MetadataOutput_OnMetadataObjectExtAvailable](capi-metadata-output-h.md#oh_metadataoutput_onmetadataobjectextavailable) callback | 监听元数据对象上报事件的回调的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。 |

### OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback()

```c
Camera_ErrorCode OH_MetadataOutput_UnregisterMetadataObjectExtAvailableCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnMetadataObjectExtAvailable callback)
```

**描述**

注销监听元数据对象上报事件的回调。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例的指针。 |
| void* context | 用户提供的上下文指针。 |
| [OH_MetadataOutput_OnMetadataObjectExtAvailable](capi-metadata-output-h.md#oh_metadataoutput_onmetadataobjectextavailable) callback | 监听元数据对象上报事件的回调的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。 |

### OH_MetadataOutput_RegisterErrorExtCallback()

```c
Camera_ErrorCode OH_MetadataOutput_RegisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)
```

**描述**

注册监听错误事件的回调。该回调可通过[OH_MetadataOutput_UnregisterErrorExtCallback](capi-metadata-output-h.md#oh_metadataoutput_unregistererrorextcallback)注销。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例的指针。 |
| void* context | 用户提供的上下文指针。 |
| [OH_MetadataOutput_OnErrorExt](capi-metadata-output-h.md#oh_metadataoutput_onerrorext) callback | 监听错误事件的回调的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。 |

### OH_MetadataOutput_UnregisterErrorExtCallback()

```c
Camera_ErrorCode OH_MetadataOutput_UnregisterErrorExtCallback(Camera_MetadataOutput* metadataOutput, void* context, OH_MetadataOutput_OnErrorExt callback)
```

**描述**

注销监听错误事件的回调。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例的指针。 |
| void* context | 用户提供的上下文指针。 |
| [OH_MetadataOutput_OnErrorExt](capi-metadata-output-h.md#oh_metadataoutput_onerrorext) callback | 监听错误事件的回调的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。 |

### OH_MetadataOutput_IsLockMetadataObjectTrackingSupported()

```c
bool OH_MetadataOutput_IsLockMetadataObjectTrackingSupported(const Camera_MetadataOutput* metadataOutput)
```

**描述**

检查设备是否支持锁定元数据对象（如猫脸、狗脸）追踪功能。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const[Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | MetadataOutput实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | true表示支持该功能。<br>         false表示不支持该功能。 |

### OH_MetadataOutput_LockMetadataObjectTracking()

```c
Camera_ErrorCode OH_MetadataOutput_LockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput, Camera_Point* pointOfInterest)
```

**描述**

锁定对特定元数据对象（如猫脸、狗脸）的追踪。<br> 该功能以pointOfInterest所指向的点所在的对象为追踪对象，如果该点不存在追踪对象，则功能不生效。<br> 被锁定追踪的对象离开取景范围超过三秒或调用解锁追踪后，锁定追踪自动取消。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例的指针。 |
| [Camera_Point](capi-oh-camera-camera-point.md)* pointOfInterest | 期望追踪对应位置对象的点的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务异常。 |

### OH_MetadataOutput_UnlockMetadataObjectTracking()

```c
Camera_ErrorCode OH_MetadataOutput_UnlockMetadataObjectTracking(Camera_MetadataOutput* metadataOutput)
```

**描述**

解锁元数据对象（如猫脸、狗脸）的追踪。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 元数据输出实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：操作成功。<br>         CAMERA_INVALID_ARGUMENT：参数缺失或参数类型错误。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务异常。 |


