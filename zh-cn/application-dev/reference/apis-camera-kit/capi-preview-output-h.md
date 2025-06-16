# preview_output.h

## 概述

声明预览输出概念。

**引用文件：** <ohcamera/preview_output.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [PreviewOutput_Callbacks](capi-previewoutput-callbacks.md) | PreviewOutput_Callbacks | 用于预览输出的回调。 |
| [Camera_PreviewOutput](capi-camera-previewoutput.md) | Camera_PreviewOutput | 预览输出对象。<br> 可以使用[OH_CameraManager_CreatePreviewOutput](capi-camera-manager-h.md#oh_cameramanager_createpreviewoutput)方法创建指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_PreviewOutput_OnFrameStart)(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_onframestart) | OH_PreviewOutput_OnFrameStart | 在[PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)中被调用的预览输出帧开始回调。 |
| [typedef void (\*OH_PreviewOutput_OnFrameEnd)(Camera_PreviewOutput* previewOutput, int32_t frameCount)](#oh_previewoutput_onframeend) | OH_PreviewOutput_OnFrameEnd | 在[PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)中被调用的预览输出帧结束回调。 |
| [typedef void (\*OH_PreviewOutput_OnError)(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)](#oh_previewoutput_onerror) | OH_PreviewOutput_OnError | 在[PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)中被调用的预览输出帧错误回调。 |
| [Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput,PreviewOutput_Callbacks* callback)](#oh_previewoutput_registercallback) | - | 注册预览输出更改事件回调。 |
| [Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput,PreviewOutput_Callbacks* callback)](#oh_previewoutput_unregistercallback) | - | 注销预览输出更改事件回调。 |
| [Camera_ErrorCode OH_PreviewOutput_Start(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_start) | - | 开始预览输出。 |
| [Camera_ErrorCode OH_PreviewOutput_Stop(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_stop) | - | 停止预览输出。 |
| [Camera_ErrorCode OH_PreviewOutput_Release(Camera_PreviewOutput* previewOutput)](#oh_previewoutput_release) | - | 释放预览输出实例。 |
| [Camera_ErrorCode OH_PreviewOutput_GetActiveProfile(Camera_PreviewOutput* previewOutput, Camera_Profile** profile)](#oh_previewoutput_getactiveprofile) | - | 获取当前预览输出配置文件。 |
| [Camera_ErrorCode OH_PreviewOutput_DeleteProfile(Camera_Profile* profile)](#oh_previewoutput_deleteprofile) | - | 删除预览配置文件实例。 |
| [Camera_ErrorCode OH_PreviewOutput_GetPreviewRotation(Camera_PreviewOutput* previewOutput, int displayRotation,Camera_ImageRotation* imageRotation)](#oh_previewoutput_getpreviewrotation) | - | 获取相机预览旋转角度。 |
| [Camera_ErrorCode OH_PreviewOutput_SetPreviewRotation(Camera_PreviewOutput* previewOutput,Camera_ImageRotation previewRotation, bool isDisplayLocked)](#oh_previewoutput_setpreviewrotation) | - | 设置相机预览旋转角度。 |
| [Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange** frameRateRange, uint32_t* size)](#oh_previewoutput_getsupportedframerates) | - | 获取支持的预览输出帧率列表。 |
| [Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange* frameRateRange)](#oh_previewoutput_deleteframerates) | - | 删除帧率列表。 |
| [Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput,int32_t minFps, int32_t maxFps)](#oh_previewoutput_setframerate) | - | 设置预览输出帧率。 |
| [Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange* frameRateRange)](#oh_previewoutput_getactiveframerate) | - | 获取当前预览输出帧率。 |

## 函数说明

### OH_PreviewOutput_OnFrameStart()

```
typedef void (*OH_PreviewOutput_OnFrameStart)(Camera_PreviewOutput* previewOutput)
```

**描述**

在[PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)中被调用的预览输出帧开始回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 传递回调的预览输出实例。 |

### OH_PreviewOutput_OnFrameEnd()

```
typedef void (*OH_PreviewOutput_OnFrameEnd)(Camera_PreviewOutput* previewOutput, int32_t frameCount)
```

**描述**

在[PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)中被调用的预览输出帧结束回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 传递回调的预览输出实例。 |
|  int32_t frameCount | 回调传递的帧计数。 |

### OH_PreviewOutput_OnError()

```
typedef void (*OH_PreviewOutput_OnError)(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
```

**描述**

在[PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)中被调用的预览输出帧错误回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 传递回调的预览输出实例。 |
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | 预览输出的错误码。 |

**参考：**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_PreviewOutput_RegisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput,PreviewOutput_Callbacks* callback)
```

**描述**

注册预览输出更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 预览输出实例。 |
| [PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)* callback | 要注册的预览输出更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PreviewOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput,PreviewOutput_Callbacks* callback)
```

**描述**

注销预览输出更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 预览输出实例。 |
| [PreviewOutput_Callbacks](capi-previewoutput-callbacks.md)* callback | 要注销的预览输出更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PreviewOutput_Start()

```
Camera_ErrorCode OH_PreviewOutput_Start(Camera_PreviewOutput* previewOutput)
```

**描述**

开始预览输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 要启动的预览输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PreviewOutput_Stop()

```
Camera_ErrorCode OH_PreviewOutput_Stop(Camera_PreviewOutput* previewOutput)
```

**描述**

停止预览输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 要停止的预览输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PreviewOutput_Release()

```
Camera_ErrorCode OH_PreviewOutput_Release(Camera_PreviewOutput* previewOutput)
```

**描述**

释放预览输出实例。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 要释放的预览输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PreviewOutput_GetActiveProfile()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveProfile(Camera_PreviewOutput* previewOutput, Camera_Profile** profile)
```

**描述**

获取当前预览输出配置文件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 提供当前预览输出配置文件的预览输出实例。 |
| [Camera_Profile](capi-camera-profile.md)** profile | 如果方法调用成功，将记录当前的预览输出配置文件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PreviewOutput_DeleteProfile()

```
Camera_ErrorCode OH_PreviewOutput_DeleteProfile(Camera_Profile* profile)
```

**描述**

删除预览配置文件实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Profile](capi-camera-profile.md)* profile | 要被删除的预览配置文件实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PreviewOutput_GetPreviewRotation()

```
Camera_ErrorCode OH_PreviewOutput_GetPreviewRotation(Camera_PreviewOutput* previewOutput, int displayRotation,Camera_ImageRotation* imageRotation)
```

**描述**

获取相机预览旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 用于获取预览旋转角度的预览输出实例。 |
| int displayRotation | 当前显示的旋转角度。 |
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation)* imageRotation | 预览旋转角度结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PreviewOutput_SetPreviewRotation()

```
Camera_ErrorCode OH_PreviewOutput_SetPreviewRotation(Camera_PreviewOutput* previewOutput,Camera_ImageRotation previewRotation, bool isDisplayLocked)
```

**描述**

设置相机预览旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 用于设置预览旋转角度的预览输出实例。 |
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation) previewRotation | 预览的显示旋转角度。 |
| bool isDisplayLocked | 显示器状态，true表示显示器被锁定。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PreviewOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**描述**

获取支持的预览输出帧率列表。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 传递支持的帧率列表的预览输出实例。 |
| [Camera_FrameRateRange](capi-camera-frameraterange.md)** frameRateRange | 如果方法调用成功，将记录支持的预览输出帧率列表。 |
| uint32_t* size | 如果方法调用成功，将记录支持的预览输出帧率列表大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PreviewOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange* frameRateRange)
```

**描述**

删除帧率列表。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 预览输出实例。 |
| [Camera_FrameRateRange](capi-camera-frameraterange.md)* frameRateRange | 要删除的帧率列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PreviewOutput_SetFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput,int32_t minFps, int32_t maxFps)
```

**描述**

设置预览输出帧率。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 要设置帧率的预览输出实例。 |
| int32_t minFps | 要设置的最小值。 |
| int32_t maxFps | 要设置的最大值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PreviewOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput,Camera_FrameRateRange* frameRateRange)
```

**描述**

获取当前预览输出帧率。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PreviewOutput](capi-camera-previewoutput.md)* previewOutput | 传递当前预览输出帧率的预览输出实例。 |
| [Camera_FrameRateRange](capi-camera-frameraterange.md)* frameRateRange | 如果方法调用成功，则将记录当前的[Camera_FrameRateRange](capi-camera-frameraterange.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |


