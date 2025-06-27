# photo_output.h

## 概述

声明拍照输出概念。

**引用文件：** <ohcamera/photo_output.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md) | PhotoOutput_Callbacks | 拍照输出的回调。 |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md) | Camera_PhotoOutput | 拍照输出对象。<br> 可以使用[OH_CameraManager_CreatePhotoOutput](capi-camera-manager-h.md#oh_cameramanager_createphotooutput)方法创建指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_PhotoOutput_OnFrameStart)(Camera_PhotoOutput* photoOutput)](#oh_photooutput_onframestart) | OH_PhotoOutput_OnFrameStart | 在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出帧启动回调。 |
| [typedef void (\*OH_PhotoOutput_OnFrameShutter)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info)](#oh_photooutput_onframeshutter) | OH_PhotoOutput_OnFrameShutter | 在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出帧快门回调。 |
| [typedef void (\*OH_PhotoOutput_OnFrameEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount)](#oh_photooutput_onframeend) | OH_PhotoOutput_OnFrameEnd | 在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出帧结束回调。 |
| [typedef void (\*OH_PhotoOutput_OnError)(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)](#oh_photooutput_onerror) | OH_PhotoOutput_OnError | 在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出错误回调。 |
| [typedef void (\*OH_PhotoOutput_CaptureEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount)](#oh_photooutput_captureend) | OH_PhotoOutput_CaptureEnd | 拍照结束回调。 |
| [typedef void (\*OH_PhotoOutput_CaptureStartWithInfo)(Camera_PhotoOutput* photoOutput, Camera_CaptureStartInfo* Info)](#oh_photooutput_capturestartwithinfo) | OH_PhotoOutput_CaptureStartWithInfo | 拍照开始回调。 |
| [typedef void (\*OH_PhotoOutput_OnFrameShutterEnd)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* Info)](#oh_photooutput_onframeshutterend) | OH_PhotoOutput_OnFrameShutterEnd | 拍照曝光结束回调。 |
| [typedef void (\*OH_PhotoOutput_CaptureReady)(Camera_PhotoOutput* photoOutput)](#oh_photooutput_captureready) | OH_PhotoOutput_CaptureReady | 拍照准备就绪回调。收到回调后，可以继续进行下一次拍照。 |
| [typedef void (\*OH_PhotoOutput_EstimatedCaptureDuration)(Camera_PhotoOutput* photoOutput, int64_t duration)](#oh_photooutput_estimatedcaptureduration) | OH_PhotoOutput_EstimatedCaptureDuration | 预计拍照时间回调。 |
| [typedef void (\*OH_PhotoOutput_PhotoAvailable)(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo)](#oh_photooutput_photoavailable) | OH_PhotoOutput_PhotoAvailable | 照片输出可用高分辨率图像回调。 |
| [typedef void (\*OH_PhotoOutput_PhotoAssetAvailable)(Camera_PhotoOutput* photoOutput, OH_MediaAsset* photoAsset)](#oh_photooutput_photoassetavailable) | OH_PhotoOutput_PhotoAssetAvailable | 输出照片资源可用回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)](#oh_photooutput_registercallback) | - | 注册拍照输出更改事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)](#oh_photooutput_unregistercallback) | - | 注销拍照输出更改事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureStartWithInfo callback)](#oh_photooutput_registercapturestartwithinfocallback) | - | 注册拍照开始事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_GetPhotoRotation(Camera_PhotoOutput* photoOutput, int deviceDegree,Camera_ImageRotation* imageRotation)](#oh_photooutput_getphotorotation) | - | 获取照片旋转角度。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureStartWithInfo callback)](#oh_photooutput_unregistercapturestartwithinfocallback) | - | 注销拍照开始事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterCaptureEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureEnd callback)](#oh_photooutput_registercaptureendcallback) | - | 注册拍照结束事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureEnd callback)](#oh_photooutput_unregistercaptureendcallback) | - | 注销拍照结束事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_OnFrameShutterEnd callback)](#oh_photooutput_registerframeshutterendcallback) | - | 注册拍照曝光结束事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_OnFrameShutterEnd callback)](#oh_photooutput_unregisterframeshutterendcallback) | - | 注销拍照曝光结束事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureReady callback)](#oh_photooutput_registercapturereadycallback) | - | 注册拍照就绪事件回调。收到回调后，可以继续进行下一次拍照。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureReady callback)](#oh_photooutput_unregistercapturereadycallback) | - | 注销拍照就绪事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_EstimatedCaptureDuration callback)](#oh_photooutput_registerestimatedcapturedurationcallback) | - | 注册预计拍照时间事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_EstimatedCaptureDuration callback)](#oh_photooutput_unregisterestimatedcapturedurationcallback) | - | 注销预计拍照时间事件回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAvailable callback)](#oh_photooutput_registerphotoavailablecallback) | - | 注册输出照片可用回调。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAvailable callback)](#oh_photooutput_unregisterphotoavailablecallback) | - | 注销输出照片可用回调。 |
| [Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAssetAvailable callback)](#oh_photooutput_registerphotoassetavailablecallback) | - | 注册输出照片资源可用回调。 |
| [Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAssetAvailable callback)](#oh_photooutput_unregisterphotoassetavailablecallback) | - | 注销输出照片资源可用回调。 |
| [Camera_ErrorCode OH_PhotoOutput_Capture(Camera_PhotoOutput* photoOutput)](#oh_photooutput_capture) | - | 拍摄照片。<br> 必须在[OH_PreviewOutput_Release](capi-preview-output-h.md#oh_previewoutput_release)之前调用，否则会导致无法拍照。 |
| [Camera_ErrorCode OH_PhotoOutput_Capture_WithCaptureSetting(Camera_PhotoOutput* photoOutput,Camera_PhotoCaptureSetting setting)](#oh_photooutput_capture_withcapturesetting) | - | 使用捕获设置捕获拍照。 |
| [Camera_ErrorCode OH_PhotoOutput_Release(Camera_PhotoOutput* photoOutput)](#oh_photooutput_release) | - | 释放拍照输出。 |
| [Camera_ErrorCode OH_PhotoOutput_IsMirrorSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)](#oh_photooutput_ismirrorsupported) | - | 检查是否支持镜像拍照。 |
| [Camera_ErrorCode OH_PhotoOutput_EnableMirror(Camera_PhotoOutput* photoOutput, bool enabled)](#oh_photooutput_enablemirror) | - | 是否启用动态照片镜像拍照。 |
| [Camera_ErrorCode OH_PhotoOutput_GetActiveProfile(Camera_PhotoOutput* photoOutput, Camera_Profile** profile)](#oh_photooutput_getactiveprofile) | - | 获取当前照片输出配置文件。 |
| [Camera_ErrorCode OH_PhotoOutput_DeleteProfile(Camera_Profile* profile)](#oh_photooutput_deleteprofile) | - | 删除照片配置文件实例。 |
| [Camera_ErrorCode OH_PhotoOutput_IsMovingPhotoSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)](#oh_photooutput_ismovingphotosupported) | - | 检查是否支持动态照片。 |
| [Camera_ErrorCode OH_PhotoOutput_EnableMovingPhoto(Camera_PhotoOutput* photoOutput, bool enabled)](#oh_photooutput_enablemovingphoto) | - | 是否启用动态照片。 |

## 函数说明

### OH_PhotoOutput_OnFrameStart()

```
typedef void (*OH_PhotoOutput_OnFrameStart)(Camera_PhotoOutput* photoOutput)
```

**描述**

在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出帧启动回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |

### OH_PhotoOutput_OnFrameShutter()

```
typedef void (*OH_PhotoOutput_OnFrameShutter)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info)
```

**描述**

在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出帧快门回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
| [Camera_FrameShutterInfo](capi-oh-camera-camera-frameshutterinfo.md)* info | 回调传递的帧快门回调信息。 |

### OH_PhotoOutput_OnFrameEnd()

```
typedef void (*OH_PhotoOutput_OnFrameEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount)
```

**描述**

在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出帧结束回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
|  int32_t frameCount | 回调传递的帧计数。 |

### OH_PhotoOutput_OnError()

```
typedef void (*OH_PhotoOutput_OnError)(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
```

**描述**

在[PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)中被调用的拍照输出错误回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
|  [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | 拍照输出的错误码。 |

**参考：**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)

### OH_PhotoOutput_CaptureEnd()

```
typedef void (*OH_PhotoOutput_CaptureEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount)
```

**描述**

拍照结束回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
|  int32_t frameCount | 回调传递的帧数。 |

### OH_PhotoOutput_CaptureStartWithInfo()

```
typedef void (*OH_PhotoOutput_CaptureStartWithInfo)(Camera_PhotoOutput* photoOutput, Camera_CaptureStartInfo* Info)
```

**描述**

拍照开始回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
|  [Camera_CaptureStartInfo](capi-oh-camera-camera-capturestartinfo.md)* Info | 回调传递的拍照开始信息。 |

### OH_PhotoOutput_OnFrameShutterEnd()

```
typedef void (*OH_PhotoOutput_OnFrameShutterEnd)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* Info)
```

**描述**

拍照曝光结束回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
| [Camera_FrameShutterInfo](capi-oh-camera-camera-frameshutterinfo.md)* info | 回调传递的帧快门回调信息。 |

### OH_PhotoOutput_CaptureReady()

```
typedef void (*OH_PhotoOutput_CaptureReady)(Camera_PhotoOutput* photoOutput)
```

**描述**

拍照准备就绪回调。收到回调后，可以继续进行下一次拍照。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |

### OH_PhotoOutput_EstimatedCaptureDuration()

```
typedef void (*OH_PhotoOutput_EstimatedCaptureDuration)(Camera_PhotoOutput* photoOutput, int64_t duration)
```

**描述**

预计拍照时间回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
|  int64_t duration | 回调传递的预计拍照时间。 |

### OH_PhotoOutput_PhotoAvailable()

```
typedef void (*OH_PhotoOutput_PhotoAvailable)(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo)
```

**描述**

照片输出可用高分辨率图像回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
|  [OH_PhotoNative](capi-oh-camera-oh-photonative.md)* photo | 回调传递的OH_PhotoNative。 |

### OH_PhotoOutput_PhotoAssetAvailable()

```
typedef void (*OH_PhotoOutput_PhotoAssetAvailable)(Camera_PhotoOutput* photoOutput, OH_MediaAsset* photoAsset)
```

**描述**

输出照片资源可用回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递回调的拍照输出实例。 |
|  [OH_MediaAsset](../apis-media-library-kit/capi-mediaassetmanager-oh-mediaasset.md)* photoAsset | 回调传递的媒体资源。 |

### OH_PhotoOutput_RegisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)
```

**描述**

注册拍照输出更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)* callback | 要注册的拍照输出更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)
```

**描述**

注销拍照输出更改事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [PhotoOutput_Callbacks](capi-oh-camera-photooutput-callbacks.md)* callback | 要注销的拍照输出更改事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_RegisterCaptureStartWithInfoCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureStartWithInfo callback)
```

**描述**

注册拍照开始事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo) callback | 要注册的拍照开始事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_GetPhotoRotation()

```
Camera_ErrorCode OH_PhotoOutput_GetPhotoRotation(Camera_PhotoOutput* photoOutput, int deviceDegree,Camera_ImageRotation* imageRotation)
```

**描述**

获取照片旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 用于获取照片旋转角度的拍照输出实例。 |
| int deviceDegree | 当前设备旋转角度。 |
| [Camera_ImageRotation](capi-camera-h.md#camera_imagerotation)* imageRotation | 照片旋转角度的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureStartWithInfo callback)
```

**描述**

注销拍照开始事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo) callback | 要注销的拍照开始事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_RegisterCaptureEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureEnd callback)
```

**描述**

注册拍照结束事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend) callback | 要注册的拍照结束事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_UnregisterCaptureEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureEnd callback)
```

**描述**

注销拍照结束事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend) callback | 要注销的拍照结束事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_RegisterFrameShutterEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_OnFrameShutterEnd callback)
```

**描述**

注册拍照曝光结束事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend) callback | 要注册的拍照曝光结束事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_UnregisterFrameShutterEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_OnFrameShutterEnd callback)
```

**描述**

注销拍照曝光结束事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend) callback | 要注销的拍照曝光结束事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_RegisterCaptureReadyCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureReady callback)
```

**描述**

注册拍照就绪事件回调。收到回调后，可以继续进行下一次拍照。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready) callback | 要注册的拍照就绪事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_UnregisterCaptureReadyCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_CaptureReady callback)
```

**描述**

注销拍照就绪事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready) callback | 要注销的拍照就绪事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_EstimatedCaptureDuration callback)
```

**描述**

注册预计拍照时间事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration) callback | 要注册的预计拍照时间事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_EstimatedCaptureDuration callback)
```

**描述**

注销预计拍照时间事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration) callback | 要注销的预计拍照时间事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_RegisterPhotoAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAvailable callback)
```

**描述**

注册输出照片可用回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable) callback | 要注册的输出照片可用回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_UnregisterPhotoAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAvailable callback)
```

**描述**

注销输出照片可用回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable) callback | 要注销的输出照片可用回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_RegisterPhotoAssetAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAssetAvailable callback)
```

**描述**

注册输出照片资源可用回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable) callback | 要注册的输出照片资源可用回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput,OH_PhotoOutput_PhotoAssetAvailable callback)
```

**描述**

注销输出照片资源可用回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例。 |
| [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable) callback | 要注销的输出照片资源可用回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_Capture()

```
Camera_ErrorCode OH_PhotoOutput_Capture(Camera_PhotoOutput* photoOutput)
```

**描述**

拍摄照片。<br> 必须在[OH_PreviewOutput_Release](capi-preview-output-h.md#oh_previewoutput_release)之前调用，否则会导致无法拍照。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 用于捕获拍照的拍照输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_RUNNING：捕获会话未运行。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_Capture_WithCaptureSetting()

```
Camera_ErrorCode OH_PhotoOutput_Capture_WithCaptureSetting(Camera_PhotoOutput* photoOutput,Camera_PhotoCaptureSetting setting)
```

**描述**

使用捕获设置捕获拍照。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 用于捕获拍照的拍照输出实例。 |
| [Camera_PhotoCaptureSetting](capi-oh-camera-camera-photocapturesetting.md) setting | 用于捕获拍照的[Camera_PhotoCaptureSetting](capi-oh-camera-camera-photocapturesetting.md)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_RUNNING：捕获会话未运行。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_Release()

```
Camera_ErrorCode OH_PhotoOutput_Release(Camera_PhotoOutput* photoOutput)
```

**描述**

释放拍照输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 要释放的拍照输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_IsMirrorSupported()

```
Camera_ErrorCode OH_PhotoOutput_IsMirrorSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)
```

**描述**

检查是否支持镜像拍照。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例，用于检查是否支持镜像。 |
| bool* isSupported | 是否支持镜像的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_EnableMirror()

```
Camera_ErrorCode OH_PhotoOutput_EnableMirror(Camera_PhotoOutput* photoOutput, bool enabled)
```

**描述**

是否启用动态照片镜像拍照。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 拍照输出实例，用于确认是否启用镜像拍照。 |
| bool enabled | 是否启用动态照片镜像拍照的结果，true为开启动态照片镜像拍照，false为关闭动态照片镜像拍照。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_GetActiveProfile()

```
Camera_ErrorCode OH_PhotoOutput_GetActiveProfile(Camera_PhotoOutput* photoOutput, Camera_Profile** profile)
```

**描述**

获取当前照片输出配置文件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 传递当前配置文件的拍照输出实例。 |
| [Camera_Profile](capi-oh-camera-camera-profile.md)** profile | 如果方法调用成功，将记录照片输出配置文件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_DeleteProfile()

```
Camera_ErrorCode OH_PhotoOutput_DeleteProfile(Camera_Profile* profile)
```

**描述**

删除照片配置文件实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_Profile](capi-oh-camera-camera-profile.md)* profile | 要被删除的照片配置文件实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_PhotoOutput_IsMovingPhotoSupported()

```
Camera_ErrorCode OH_PhotoOutput_IsMovingPhotoSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)
```

**描述**

检查是否支持动态照片。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 用于检查是否支持动态照片的拍照输出实例。 |
| bool* isSupported | 是否支持动态照片的结果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_PhotoOutput_EnableMovingPhoto()

```
Camera_ErrorCode OH_PhotoOutput_EnableMovingPhoto(Camera_PhotoOutput* photoOutput, bool enabled)
```

**描述**

是否启用动态照片。

**需要权限：** ohos.permission.MICROPHONE

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 用于启用或禁用动态照片的拍照输出实例。 |
| bool enabled | 是否启用动态照片。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |


