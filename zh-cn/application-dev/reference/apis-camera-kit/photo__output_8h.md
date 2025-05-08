# photo_output.h


## 概述

声明拍照输出概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/photo_output.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [PhotoOutput_Callbacks](_photo_output___callbacks.md) | 拍照输出的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) | 拍照输出对象。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameStart](_o_h___camera.md#oh_photooutput_onframestart)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧启动回调。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameShutter](_o_h___camera.md#oh_photooutput_onframeshutter)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*info) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧快门回调。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameEnd](_o_h___camera.md#oh_photooutput_onframeend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int32_t frameCount) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧结束回调。 | 
| typedef void(\* [OH_PhotoOutput_OnError](_o_h___camera.md#oh_photooutput_onerror)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出错误回调。 | 
| typedef void(\* [OH_PhotoOutput_CaptureEnd](_o_h___camera.md#oh_photooutput_captureend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int32_t frameCount) | 拍照结束回调。 | 
| typedef void(\* [OH_PhotoOutput_CaptureStartWithInfo](_o_h___camera.md#oh_photooutput_capturestartwithinfo)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_CaptureStartInfo](_camera___capture_start_info.md) \*Info) | 拍照开始回调。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameShutterEnd](_o_h___camera.md#oh_photooutput_onframeshutterend)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*Info) | 拍照曝光结束回调。 | 
| typedef void(\* [OH_PhotoOutput_CaptureReady](_o_h___camera.md#oh_photooutput_captureready)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 拍照准备就绪回调。收到回调后，可以继续进行下一次拍照。 | 
| typedef void(\* [OH_PhotoOutput_EstimatedCaptureDuration](_o_h___camera.md#oh_photooutput_estimatedcaptureduration)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int64_t duration) | 预计拍照时间回调。 | 
| typedef void(\* [OH_PhotoOutput_PhotoAvailable](_o_h___camera.md#oh_photooutput_photoavailable)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoNative](_o_h___camera.md#oh_photonative) \*photo) | 照片输出可用高分辨率图像回调。 | 
| typedef void(\* [OH_PhotoOutput_PhotoAssetAvailable](_o_h___camera.md#oh_photooutput_photoassetavailable)) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, OH_MediaAsset \*photoAsset) | 输出照片资源可用回调。 | 
| typedef struct [PhotoOutput_Callbacks](_photo_output___callbacks.md) [PhotoOutput_Callbacks](_o_h___camera.md#photooutput_callbacks) | 拍照输出的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCallback](_o_h___camera.md#oh_photooutput_registercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | 注册拍照输出更改事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCallback](_o_h___camera.md#oh_photooutput_unregistercallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | 注销拍照输出更改事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCaptureStartWithInfoCallback](_o_h___camera.md#oh_photooutput_registercapturestartwithinfocallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](_o_h___camera.md#oh_photooutput_capturestartwithinfo) callback) | 注册拍照开始事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback](_o_h___camera.md#oh_photooutput_unregistercapturestartwithinfocallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](_o_h___camera.md#oh_photooutput_capturestartwithinfo) callback) | 注销拍照开始事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCaptureEndCallback](_o_h___camera.md#oh_photooutput_registercaptureendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](_o_h___camera.md#oh_photooutput_captureend) callback) | 注册拍照结束事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureEndCallback](_o_h___camera.md#oh_photooutput_unregistercaptureendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](_o_h___camera.md#oh_photooutput_captureend) callback) | 注销拍照结束事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterFrameShutterEndCallback](_o_h___camera.md#oh_photooutput_registerframeshutterendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](_o_h___camera.md#oh_photooutput_onframeshutterend) callback) | 注册拍照曝光结束事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterFrameShutterEndCallback](_o_h___camera.md#oh_photooutput_unregisterframeshutterendcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](_o_h___camera.md#oh_photooutput_onframeshutterend) callback) | 注销拍照曝光结束事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterCaptureReadyCallback](_o_h___camera.md#oh_photooutput_registercapturereadycallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](_o_h___camera.md#oh_photooutput_captureready) callback) | 注册拍照就绪事件回调。收到回调后，可以继续进行下一次拍照。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureReadyCallback](_o_h___camera.md#oh_photooutput_unregistercapturereadycallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](_o_h___camera.md#oh_photooutput_captureready) callback) | 注销拍照就绪事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback](_o_h___camera.md#oh_photooutput_registerestimatedcapturedurationcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](_o_h___camera.md#oh_photooutput_estimatedcaptureduration) callback) | 注册预计拍照时间事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback](_o_h___camera.md#oh_photooutput_unregisterestimatedcapturedurationcallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](_o_h___camera.md#oh_photooutput_estimatedcaptureduration) callback) | 注销预计拍照时间事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAvailableCallback](_o_h___camera.md#oh_photooutput_registerphotoavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](_o_h___camera.md#oh_photooutput_photoavailable) callback) | 注册输出照片可用回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAvailableCallback](_o_h___camera.md#oh_photooutput_unregisterphotoavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](_o_h___camera.md#oh_photooutput_photoavailable) callback) | 注销输出照片可用回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAssetAvailableCallback](_o_h___camera.md#oh_photooutput_registerphotoassetavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](_o_h___camera.md#oh_photooutput_photoassetavailable) callback) | 注册输出照片资源可用回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback](_o_h___camera.md#oh_photooutput_unregisterphotoassetavailablecallback) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](_o_h___camera.md#oh_photooutput_photoassetavailable) callback) | 注销输出照片资源可用回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture](_o_h___camera.md#oh_photooutput_capture) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 拍摄照片。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Capture_WithCaptureSetting](_o_h___camera.md#oh_photooutput_capture_withcapturesetting) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) setting) | 使用捕获设置捕获拍照。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_Release](_o_h___camera.md#oh_photooutput_release) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 释放拍照输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_IsMirrorSupported](_o_h___camera.md#oh_photooutput_ismirrorsupported) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool \*isSupported) | 检查是否支持镜像拍照。 |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_EnableMirror](_o_h___camera.md#oh_photooutput_enablemirror) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool enabled) | 是否启用动态照片镜像拍照。 |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_GetActiveProfile](_o_h___camera.md#oh_photooutput_getactiveprofile) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, [Camera_Profile](_camera___profile.md) \*\*profile) | 获取当前照片输出配置文件。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_DeleteProfile](_o_h___camera.md#oh_photooutput_deleteprofile) ([Camera_Profile](_camera___profile.md) \*profile) | 删除照片配置文件实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_IsMovingPhotoSupported](_o_h___camera.md#oh_photooutput_ismovingphotosupported) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool \*isSupported) | 检查是否支持动态照片。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_EnableMovingPhoto](_o_h___camera.md#oh_photooutput_enablemovingphoto) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, bool enabled) | 是否启用动态照片。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_PhotoOutput_GetPhotoRotation](_o_h___camera.md#oh_photooutput_getphotorotation) ([Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput, int devicedegree, [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) \*imageRotation) | 获得相机照片旋转角度。 | 
