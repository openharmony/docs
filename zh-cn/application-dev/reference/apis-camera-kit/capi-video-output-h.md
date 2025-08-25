# video_output.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

声明录像输出概念。

**引用文件：** <ohcamera/video_output.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md) | VideoOutput_Callbacks | 用于录像输出的回调。 |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md) | Camera_VideoOutput | 录像输出对象。<br> 可以使用[OH_CameraManager_CreateVideoOutput](capi-camera-manager-h.md#oh_cameramanager_createvideooutput)方法创建指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput)](#oh_videooutput_onframestart) | OH_VideoOutput_OnFrameStart | 在[VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)中被调用的录像输出帧开始回调。 |
| [typedef void (\*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount)](#oh_videooutput_onframeend) | OH_VideoOutput_OnFrameEnd | 在[VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)中被调用的录像输出帧结束回调。 |
| [typedef void (\*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)](#oh_videooutput_onerror) | OH_VideoOutput_OnError | 在[VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)中被调用的录像输出错误回调。 |
| [Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)](#oh_videooutput_registercallback) | - | 注册录像输出更改事件回调。 |
| [Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)](#oh_videooutput_unregistercallback) | - | 注销录像输出更改事件回调。 |
| [Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput)](#oh_videooutput_start) | - | 开始录像输出。 |
| [Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput)](#oh_videooutput_stop) | - | 停止录像输出。 |
| [Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput)](#oh_videooutput_release) | - | 释放录像输出实例。 |
| [Camera_ErrorCode OH_VideoOutput_GetActiveProfile(Camera_VideoOutput* videoOutput, Camera_VideoProfile** profile)](#oh_videooutput_getactiveprofile) | - | 获取当前视频输出配置文件。 |
| [Camera_ErrorCode OH_VideoOutput_DeleteProfile(Camera_VideoProfile* profile)](#oh_videooutput_deleteprofile) | - | 删除视频配置文件实例。 |
| [ Camera_ErrorCode OH_VideoOutput_IsMirrorSupported(Camera_VideoOutput* videoOutput, bool* isSupported)](#oh_videooutput_ismirrorsupported) | - | 判断当前视频输出是否支持镜像。 |
| [ Camera_ErrorCode OH_VideoOutput_EnableMirror(Camera_VideoOutput* videoOutput, bool mirrorMode)](#oh_videooutput_enablemirror) | - | 打开/关闭当前视频输出镜像功能。 |
| [ Camera_ErrorCode  OH_VideoOutput_GetVideoRotation(Camera_VideoOutput* videoOutput, int deviceDegree,Camera_ImageRotation* imageRotation)](#oh_videooutput_getvideorotation) | - | 获取当前视频输出应当设置的旋转角度。 |
| [Camera_ErrorCode OH_VideoOutput_GetSupportedFrameRates(Camera_VideoOutput* videoOutput,Camera_FrameRateRange** frameRateRange, uint32_t* size)](#oh_videooutput_getsupportedframerates) | - | 获取支持的视频输出帧率列表。 |
| [Camera_ErrorCode OH_VideoOutput_DeleteFrameRates(Camera_VideoOutput* videoOutput,Camera_FrameRateRange* frameRateRange)](#oh_videooutput_deleteframerates) | - | 删除帧率列表。 |
| [Camera_ErrorCode OH_VideoOutput_SetFrameRate(Camera_VideoOutput* videoOutput,int32_t minFps, int32_t maxFps)](#oh_videooutput_setframerate) | - | 设置视频输出帧率。 |
| [Camera_ErrorCode OH_VideoOutput_GetActiveFrameRate(Camera_VideoOutput* videoOutput,Camera_FrameRateRange* frameRateRange)](#oh_videooutput_getactiveframerate) | - | 获取当前视频输出帧率。 |

## 函数说明

### OH_VideoOutput_OnFrameStart()

```
typedef void (*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput)
```

**描述**

在[VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)中被调用的录像输出帧开始回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递回调的录像输出实例。 |

### OH_VideoOutput_OnFrameEnd()

```
typedef void (*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount)
```

**描述**

在[VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)中被调用的录像输出帧结束回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递回调的录像输出实例。 |
|  int32_t frameCount | 回调传递的帧计数。 |

### OH_VideoOutput_OnError()

```
typedef void (*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
```

**描述**

在[VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)中被调用的录像输出错误回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递回调的录像输出实例。 |
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | 录像输出的错误码。 |

**参考：**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_VideoOutput_RegisterCallback()

```
Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**描述**

注册录像输出更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 录像输出实例。 |
| [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)* callback | 要注册的录像输出更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_VideoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**描述**

注销录像输出更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 录像输出实例。 |
| [VideoOutput_Callbacks](capi-oh-camera-videooutput-callbacks.md)* callback | 要注销的录像输出更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_VideoOutput_Start()

```
Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput)
```

**描述**

开始录像输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 要启动的录像输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_Stop()

```
Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput)
```

**描述**

停止录像输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 要停止的录像输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_Release()

```
Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput)
```

**描述**

释放录像输出实例。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 要释放的录像输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_GetActiveProfile()

```
Camera_ErrorCode OH_VideoOutput_GetActiveProfile(Camera_VideoOutput* videoOutput, Camera_VideoProfile** profile)
```

**描述**

获取当前视频输出配置文件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递当前视频输出配置文件的录像输出实例。 |
| [Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md)** profile | 如果方法调用成功，将记录当前的视频输出配置文件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_DeleteProfile()

```
Camera_ErrorCode OH_VideoOutput_DeleteProfile(Camera_VideoProfile* profile)
```

**描述**

删除视频配置文件实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md)* profile | 要删除的视频配置文件实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_VideoOutput_IsMirrorSupported()

```
 Camera_ErrorCode OH_VideoOutput_IsMirrorSupported(Camera_VideoOutput* videoOutput, bool* isSupported)
```

**描述**

判断当前视频输出是否支持镜像。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递当前视频输出的录像输出实例。 |
| bool* isSupported | 当前视频输出是否支持镜像。true表示当前视频输出支持镜像，false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_EnableMirror()

```
 Camera_ErrorCode OH_VideoOutput_EnableMirror(Camera_VideoOutput* videoOutput, bool mirrorMode)
```

**描述**

打开/关闭当前视频输出镜像功能。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递当前视频输出的录像输出实例。 |
| bool mirrorMode | 设备是否开启镜像功能。true表示打开镜像功能，false表示关闭镜像功能。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>          CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>          CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_GetVideoRotation()

```
 Camera_ErrorCode  OH_VideoOutput_GetVideoRotation(Camera_VideoOutput* videoOutput, int deviceDegree,Camera_ImageRotation* imageRotation)
```

**描述**

获取当前视频输出应当设置的旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递当前视频输出的录像输出实例。 |
| int deviceDegree | 设备目前相对于自然方向（充电口朝下）顺时针的旋转角度。 |
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation)* imageRotation | 当前视频输出应当设置的旋转角度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>          CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>          CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_VideoOutput_GetSupportedFrameRates(Camera_VideoOutput* videoOutput,Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**描述**

获取支持的视频输出帧率列表。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递支持的视频输出帧率列表的录像输出实例。 |
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)** frameRateRange | 如果方法调用成功，将记录支持的视频输出帧率列表。 |
| uint32_t* size | 如果方法调用成功，将记录支持的视频输出帧率列表大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_VideoOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_VideoOutput_DeleteFrameRates(Camera_VideoOutput* videoOutput,Camera_FrameRateRange* frameRateRange)
```

**描述**

删除帧率列表。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 录像输出实例。 |
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)* frameRateRange | 要删除的帧率列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_VideoOutput_SetFrameRate()

```
Camera_ErrorCode OH_VideoOutput_SetFrameRate(Camera_VideoOutput* videoOutput,int32_t minFps, int32_t maxFps)
```

**描述**

设置视频输出帧率。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 要设置帧率的录像输出实例。 |
| int32_t minFps | 设置的最小帧率。 |
| int32_t maxFps | 设置的最大帧率。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_VideoOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_VideoOutput_GetActiveFrameRate(Camera_VideoOutput* videoOutput,Camera_FrameRateRange* frameRateRange)
```

**描述**

获取当前视频输出帧率。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 传递当前视频输出帧率的录像输出实例。 |
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md)* frameRateRange | 如果方法调用成功，将记录当前的视频输出帧率。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |


