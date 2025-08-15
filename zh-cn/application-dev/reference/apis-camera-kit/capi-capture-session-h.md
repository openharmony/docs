# capture_session.h
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

声明捕获会话概念。

**引用文件：** <ohcamera/capture_session.h>

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：** [OH_Camera](capi-oh-camera.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md) | CaptureSession_Callbacks | 捕获会话的回调。 |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md) | Camera_CaptureSession | 捕获会话对象。<br> 可以使用[OH_CameraManager_CreateCaptureSession](capi-camera-manager-h.md#oh_cameramanager_createcapturesession)方法创建指针。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_CaptureSession_OnFocusStateChange)(Camera_CaptureSession* session, Camera_FocusState focusState)](#oh_capturesession_onfocusstatechange) | OH_CaptureSession_OnFocusStateChange | 在[CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)中被调用的捕获会话焦点状态回调。 |
| [typedef void (\*OH_CaptureSession_OnError)(Camera_CaptureSession* session, Camera_ErrorCode errorCode)](#oh_capturesession_onerror) | OH_CaptureSession_OnError | 在[CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)中被调用的捕获会话错误回调。 |
| [typedef void (\*OH_CaptureSession_OnSmoothZoomInfo)(Camera_CaptureSession* session,Camera_SmoothZoomInfo* smoothZoomInfo)](#oh_capturesession_onsmoothzoominfo) | OH_CaptureSession_OnSmoothZoomInfo | 拍照会话平滑变焦信息回调，触发平滑变焦后该回调会返回。 |
| [typedef void (\*OH_CaptureSession_OnAutoDeviceSwitchStatusChange)(Camera_CaptureSession* session,Camera_AutoDeviceSwitchStatusInfo* autoDeviceSwitchStatusInfo)](#oh_capturesession_onautodeviceswitchstatuschange) | OH_CaptureSession_OnAutoDeviceSwitchStatusChange | 捕获会话设备切换状态回调。 |
| [typedef void (\*OH_CaptureSession_OnSystemPressureLevelChange)(Camera_CaptureSession* session,Camera_SystemPressureLevel systemPressureLevel)](#oh_capturesession_onsystempressurelevelchange) | OH_CaptureSession_OnSystemPressureLevelChange | 捕获系统压力状态变化回调。 |
| [typedef void (\*OH_CaptureSession_OnControlCenterEffectStatusChange)(Camera_CaptureSession* session,Camera_ControlCenterStatusInfo* controlCenterStatusInfo)](#oh_capturesession_oncontrolcentereffectstatuschange) | OH_CaptureSession_OnControlCenterEffectStatusChange | 相机控制器效果激活状态变化回调。 |
| [Camera_ErrorCode OH_CaptureSession_RegisterCallback(Camera_CaptureSession* session,CaptureSession_Callbacks* callback)](#oh_capturesession_registercallback) | - | 注册捕获会话事件回调。 |
| [Camera_ErrorCode OH_CaptureSession_UnregisterCallback(Camera_CaptureSession* session,CaptureSession_Callbacks* callback)](#oh_capturesession_unregistercallback) | - | 注销捕获会话事件回调。 |
| [Camera_ErrorCode OH_CaptureSession_RegisterSmoothZoomInfoCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)](#oh_capturesession_registersmoothzoominfocallback) | - | 注册平滑变焦信息事件回调。 |
| [Camera_ErrorCode OH_CaptureSession_UnregisterSmoothZoomInfoCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)](#oh_capturesession_unregistersmoothzoominfocallback) | - | 注销平滑变焦信息事件回调。 |
| [Camera_ErrorCode OH_CaptureSession_SetSessionMode(Camera_CaptureSession* session, Camera_SceneMode sceneMode)](#oh_capturesession_setsessionmode) | - | 设置会话模式。<br> 此接口不能在[OH_CaptureSession_BeginConfig](#oh_capturesession_beginconfig)之后使用。<br> 建议在使用[OH_CameraManager_CreateCaptureSession](capi-camera-manager-h.md#oh_cameramanager_createcapturesession)后立即使用此接口。 |
| [Camera_ErrorCode OH_CaptureSession_AddSecureOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)](#oh_capturesession_addsecureoutput) | - | 把其中一条PreviewOutput标记成安全输出。 |
| [Camera_ErrorCode OH_CaptureSession_BeginConfig(Camera_CaptureSession* session)](#oh_capturesession_beginconfig) | - | 开始捕获会话配置。 |
| [Camera_ErrorCode OH_CaptureSession_CommitConfig(Camera_CaptureSession* session)](#oh_capturesession_commitconfig) | - | 提交捕获会话配置。 |
| [Camera_ErrorCode OH_CaptureSession_AddInput(Camera_CaptureSession* session, Camera_Input* cameraInput)](#oh_capturesession_addinput) | - | 添加相机输入。 |
| [Camera_ErrorCode OH_CaptureSession_RemoveInput(Camera_CaptureSession* session, Camera_Input* cameraInput)](#oh_capturesession_removeinput) | - | 删除相机输入。 |
| [Camera_ErrorCode OH_CaptureSession_AddPreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* previewOutput)](#oh_capturesession_addpreviewoutput) | - | 添加预览输出。 |
| [Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* previewOutput)](#oh_capturesession_removepreviewoutput) | - | 删除预览输出。 |
| [Camera_ErrorCode OH_CaptureSession_AddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)](#oh_capturesession_addphotooutput) | - | 添加拍照输出。 |
| [Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)](#oh_capturesession_removephotooutput) | - | 删除拍照输出。 |
| [Camera_ErrorCode OH_CaptureSession_AddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)](#oh_capturesession_addvideooutput) | - | 添加录像输出。 |
| [Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)](#oh_capturesession_removevideooutput) | - | 删除录像输出。 |
| [Camera_ErrorCode OH_CaptureSession_AddMetadataOutput(Camera_CaptureSession* session,Camera_MetadataOutput* metadataOutput)](#oh_capturesession_addmetadataoutput) | - | 添加元数据输出。 |
| [Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput(Camera_CaptureSession* session,Camera_MetadataOutput* metadataOutput)](#oh_capturesession_removemetadataoutput) | - | 删除元数据输出。 |
| [Camera_ErrorCode OH_CaptureSession_Start(Camera_CaptureSession* session)](#oh_capturesession_start) | - | 启动捕获会话。 |
| [Camera_ErrorCode OH_CaptureSession_Stop(Camera_CaptureSession* session)](#oh_capturesession_stop) | - | 停止捕获会话。 |
| [Camera_ErrorCode OH_CaptureSession_Release(Camera_CaptureSession* session)](#oh_capturesession_release) | - | 释放捕获会话。 |
| [Camera_ErrorCode OH_CaptureSession_HasFlash(Camera_CaptureSession* session, bool* hasFlash)](#oh_capturesession_hasflash) | - | 检查设备是否有闪光灯。 |
| [Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported(Camera_CaptureSession* session,Camera_FlashMode flashMode, bool* isSupported)](#oh_capturesession_isflashmodesupported) | - | 检查是否支持指定的闪光灯模式。 |
| [Camera_ErrorCode OH_CaptureSession_GetFlashMode(Camera_CaptureSession* session, Camera_FlashMode* flashMode)](#oh_capturesession_getflashmode) | - | 获取当前闪光灯模式。 |
| [Camera_ErrorCode OH_CaptureSession_SetFlashMode(Camera_CaptureSession* session, Camera_FlashMode flashMode)](#oh_capturesession_setflashmode) | - | 设置闪光灯模式。 |
| [Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported(Camera_CaptureSession* session,Camera_ExposureMode exposureMode, bool* isSupported)](#oh_capturesession_isexposuremodesupported) | - | 检查是否支持指定的曝光模式。 |
| [Camera_ErrorCode OH_CaptureSession_GetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode* exposureMode)](#oh_capturesession_getexposuremode) | - | 获取当前曝光模式。 |
| [Camera_ErrorCode OH_CaptureSession_SetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode exposureMode)](#oh_capturesession_setexposuremode) | - | 设置曝光模式。 |
| [Camera_ErrorCode OH_CaptureSession_GetMeteringPoint(Camera_CaptureSession* session, Camera_Point* point)](#oh_capturesession_getmeteringpoint) | - | 获取当前测量点。 |
| [Camera_ErrorCode OH_CaptureSession_SetMeteringPoint(Camera_CaptureSession* session, Camera_Point point)](#oh_capturesession_setmeteringpoint) | - | 设置计量区域的中心点。 |
| [Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange(Camera_CaptureSession* session, float* minExposureBias,float* maxExposureBias, float* step)](#oh_capturesession_getexposurebiasrange) | - | 查询曝光补偿范围。 |
| [Camera_ErrorCode OH_CaptureSession_SetExposureBias(Camera_CaptureSession* session, float exposureBias)](#oh_capturesession_setexposurebias) | - | 设置曝光补偿。 |
| [Camera_ErrorCode OH_CaptureSession_GetExposureBias(Camera_CaptureSession* session, float* exposureBias)](#oh_capturesession_getexposurebias) | - | 获取当前曝光补偿。 |
| [Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported(Camera_CaptureSession* session,Camera_FocusMode focusMode, bool* isSupported)](#oh_capturesession_isfocusmodesupported) | - | 检查是否支持指定的聚焦模式。 |
| [Camera_ErrorCode OH_CaptureSession_GetFocusMode(Camera_CaptureSession* session, Camera_FocusMode* focusMode)](#oh_capturesession_getfocusmode) | - | 获取当前聚焦模式。 |
| [Camera_ErrorCode OH_CaptureSession_SetFocusMode(Camera_CaptureSession* session, Camera_FocusMode focusMode)](#oh_capturesession_setfocusmode) | - | 设置聚焦模式。 |
| [Camera_ErrorCode OH_CaptureSession_GetFocusPoint(Camera_CaptureSession* session, Camera_Point* focusPoint)](#oh_capturesession_getfocuspoint) | - | 获取当前焦点。 |
| [Camera_ErrorCode OH_CaptureSession_SetFocusPoint(Camera_CaptureSession* session, Camera_Point focusPoint)](#oh_capturesession_setfocuspoint) | - | 设置焦点。 |
| [Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange(Camera_CaptureSession* session, float* minZoom, float* maxZoom)](#oh_capturesession_getzoomratiorange) | - | 获取所有支持的缩放比例范围。 |
| [Camera_ErrorCode OH_CaptureSession_GetZoomRatio(Camera_CaptureSession* session, float* zoom)](#oh_capturesession_getzoomratio) | - | 获取当前缩放比例。 |
| [Camera_ErrorCode OH_CaptureSession_SetZoomRatio(Camera_CaptureSession* session, float zoom)](#oh_capturesession_setzoomratio) | - | 设置缩放比例。 |
| [Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported(Camera_CaptureSession* session,Camera_VideoStabilizationMode mode, bool* isSupported)](#oh_capturesession_isvideostabilizationmodesupported) | - | 检查是否支持指定的录像防抖模式。 |
| [Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode(Camera_CaptureSession* session,Camera_VideoStabilizationMode* mode)](#oh_capturesession_getvideostabilizationmode) | - | 获取当前录像防抖模式。 |
| [Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode(Camera_CaptureSession* session,Camera_VideoStabilizationMode mode)](#oh_capturesession_setvideostabilizationmode) | - | 设置录像防抖模式。 |
| [Camera_ErrorCode OH_CaptureSession_CanAddInput(Camera_CaptureSession* session,Camera_Input* cameraInput, bool* isSuccessful)](#oh_capturesession_canaddinput) | - | 确定是否可以将相机输入添加到会话中。 |
| [Camera_ErrorCode OH_CaptureSession_CanAddPreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* cameraOutput, bool* isSuccessful)](#oh_capturesession_canaddpreviewoutput) | - | 确定是否可以将相机预览输出添加到会话中。 |
| [Camera_ErrorCode OH_CaptureSession_CanAddPhotoOutput(Camera_CaptureSession* session,Camera_PhotoOutput* cameraOutput, bool* isSuccessful)](#oh_capturesession_canaddphotooutput) | - | 确定是否可以将拍照输出添加到会话中。 |
| [Camera_ErrorCode OH_CaptureSession_CanAddVideoOutput(Camera_CaptureSession* session,Camera_VideoOutput* cameraOutput, bool* isSuccessful)](#oh_capturesession_canaddvideooutput) | - | 确定是否可以将录像输出添加到会话中。 |
| [Camera_ErrorCode OH_CaptureSession_CanPreconfig(Camera_CaptureSession* session,Camera_PreconfigType preconfigType, bool* canPreconfig)](#oh_capturesession_canpreconfig) | - | 检查是否支持指定的预配置类型。 |
| [Camera_ErrorCode OH_CaptureSession_CanPreconfigWithRatio(Camera_CaptureSession* session,Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio, bool* canPreconfig)](#oh_capturesession_canpreconfigwithratio) | - | 检查是否支持带比例的预配置类型。 |
| [Camera_ErrorCode OH_CaptureSession_Preconfig(Camera_CaptureSession* session,Camera_PreconfigType preconfigType)](#oh_capturesession_preconfig) | - | 设置预配置类型。 |
| [Camera_ErrorCode OH_CaptureSession_PreconfigWithRatio(Camera_CaptureSession* session,Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio)](#oh_capturesession_preconfigwithratio) | - | 设置带有比例的预配置类型。 |
| [Camera_ErrorCode OH_CaptureSession_GetExposureValue(Camera_CaptureSession* session, float* exposureValue)](#oh_capturesession_getexposurevalue) | - | 查询曝光值。 |
| [Camera_ErrorCode OH_CaptureSession_GetFocalLength(Camera_CaptureSession* session, float* focalLength)](#oh_capturesession_getfocallength) | - | 获取当前焦距值。 |
| [Camera_ErrorCode OH_CaptureSession_SetSmoothZoom(Camera_CaptureSession* session,float targetZoom, Camera_SmoothZoomMode smoothZoomMode)](#oh_capturesession_setsmoothzoom) | - | 触发平滑变焦。 |
| [Camera_ErrorCode OH_CaptureSession_GetSupportedColorSpaces(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace** colorSpace, uint32_t* size)](#oh_capturesession_getsupportedcolorspaces) | - | 获取支持的色彩空间列表。 |
| [Camera_ErrorCode OH_CaptureSession_DeleteColorSpaces(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace* colorSpace)](#oh_capturesession_deletecolorspaces) | - | 删除色彩空间列表。 |
| [Camera_ErrorCode OH_CaptureSession_GetActiveColorSpace(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace* colorSpace)](#oh_capturesession_getactivecolorspace) | - | 获取当前色彩空间。 |
| [Camera_ErrorCode OH_CaptureSession_SetActiveColorSpace(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace colorSpace)](#oh_capturesession_setactivecolorspace) | - | 设置当前色彩空间。 |
| [Camera_ErrorCode OH_CaptureSession_RegisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session,OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)](#oh_capturesession_registerautodeviceswitchstatuscallback) | - | 注册设备切换事件回调。 |
| [Camera_ErrorCode OH_CaptureSession_UnregisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session,OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)](#oh_capturesession_unregisterautodeviceswitchstatuscallback) | - | 注销设备切换事件回调。 |
| [Camera_ErrorCode OH_CaptureSession_IsAutoDeviceSwitchSupported(Camera_CaptureSession* session, bool* isSupported)](#oh_capturesession_isautodeviceswitchsupported) | - | 检查是否支持自动设备切换。 |
| [Camera_ErrorCode OH_CaptureSession_EnableAutoDeviceSwitch(Camera_CaptureSession* session, bool enabled)](#oh_capturesession_enableautodeviceswitch) | - | 是否启用相机设备的自动切换。 |
| [Camera_ErrorCode OH_CaptureSession_RegisterSystemPressureLevelChangeCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)](#oh_capturesession_registersystempressurelevelchangecallback) | - | 注册系统压力状态变化回调。 |
| [Camera_ErrorCode OH_CaptureSession_UnregisterSystemPressureLevelCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)](#oh_capturesession_unregistersystempressurelevelcallback) | - | 注销系统压力状态变化回调。 |
| [Camera_ErrorCode OH_CaptureSession_SetQualityPrioritization(Camera_CaptureSession* session, Camera_QualityPrioritization qualityPrioritization)](#oh_capturesession_setqualityprioritization) | - | 设置录像质量优先级。<br> 默认为高质量，设置为功耗平衡将降低录像质量以减少功耗。实际功耗收益因平台而异。 |
| [Camera_ErrorCode OH_CaptureSession_IsMacroSupported(Camera_CaptureSession* session, bool* isSupported)](#oh_capturesession_ismacrosupported) | - | 检查是否支持微距能力。 |
| [Camera_ErrorCode OH_CaptureSession_EnableMacro(Camera_CaptureSession* session, bool enabled)](#oh_capturesession_enablemacro) | - | 是否启用相机设备的微距能力。 |
| [Camera_ErrorCode OH_CaptureSession_SetWhiteBalance(Camera_CaptureSession* session, int32_t colorTemperature)](#oh_capturesession_setwhitebalance) | - | 设置白平衡的色温。<br> 设置前，建议通过[OH_CaptureSession_GetWhiteBalanceRange](#oh_capturesession_getwhitebalancerange)获取支持配置的白平衡色温范围。 |
| [Camera_ErrorCode OH_CaptureSession_GetWhiteBalance(Camera_CaptureSession* session, int32_t *colorTemperature)](#oh_capturesession_getwhitebalance) | - | 获取当前白平衡色温值。 |
| [Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode* whiteBalanceMode)](#oh_capturesession_getwhitebalancemode) | - | 获取当前的白平衡模式。 |
| [Camera_ErrorCode OH_CaptureSession_IsWhiteBalanceModeSupported(Camera_CaptureSession* session,Camera_WhiteBalanceMode whiteBalanceMode, bool* isSupported)](#oh_capturesession_iswhitebalancemodesupported) | - | 检查是否支持指定的白平衡模式。 |
| [Camera_ErrorCode OH_CaptureSession_SetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode whiteBalanceMode)](#oh_capturesession_setwhitebalancemode) | - | 设置白平衡模式。 |
| [Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceRange(Camera_CaptureSession* session, int32_t *minColorTemperature, int32_t *maxColorTemperature)](#oh_capturesession_getwhitebalancerange) | - | 获取支持配置的白平衡色温范围。 |
| [Camera_ErrorCode OH_CaptureSession_IsControlCenterSupported(Camera_CaptureSession* session, bool* isSupported)](#oh_capturesession_iscontrolcentersupported) | - | 检查是否支持相机控制器。 |
| [Camera_ErrorCode OH_CaptureSession_GetSupportedEffectType(Camera_CaptureSession* session,Camera_ControlCenterEffectType** types, uint32_t* size)](#oh_capturesession_getsupportedeffecttype) | - | 获取相机控制器支持的效果类型。 |
| [Camera_ErrorCode OH_CaptureSession_DeleteSupportedEffectType(Camera_CaptureSession* session,Camera_ControlCenterEffectType* types, uint32_t size)](#oh_capturesession_deletesupportedeffecttype) | - | 删除相机控制器效果类型列表。 |
| [Camera_ErrorCode OH_CaptureSession_EnableControlCenter(Camera_CaptureSession* session, bool enabled)](#oh_capturesession_enablecontrolcenter) | - | 是否启用相机控制器。 |
| [Camera_ErrorCode OH_CaptureSession_RegisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session,OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)](#oh_capturesession_registercontrolcentereffectstatuschangecallback) | - | 注册相机控制器效果激活状态变化回调。 |
| [Camera_ErrorCode OH_CaptureSession_UnregisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session,OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)](#oh_capturesession_unregistercontrolcentereffectstatuschangecallback) | - | 注销相机控制器效果激活状态变化回调。 |

## 函数说明

### OH_CaptureSession_OnFocusStateChange()

```
typedef void (*OH_CaptureSession_OnFocusStateChange)(Camera_CaptureSession* session, Camera_FocusState focusState)
```

**描述**

在[CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)中被调用的捕获会话焦点状态回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [Camera_FocusState](capi-camera-h.md#camera_focusstate) focusState | 回调传递的会话焦点状态。 |

### OH_CaptureSession_OnError()

```
typedef void (*OH_CaptureSession_OnError)(Camera_CaptureSession* session, Camera_ErrorCode errorCode)
```

**描述**

在[CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)中被调用的捕获会话错误回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) errorCode | 捕获会话的错误码。 |

**参考：**

[CAMERA_SERVICE_FATAL_ERROR](capi-camera-h.md#camera_errorcode)


### OH_CaptureSession_OnSmoothZoomInfo()

```
typedef void (*OH_CaptureSession_OnSmoothZoomInfo)(Camera_CaptureSession* session,Camera_SmoothZoomInfo* smoothZoomInfo)
```

**描述**

拍照会话平滑变焦信息回调，触发平滑变焦后该回调会返回。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [Camera_SmoothZoomInfo](capi-oh-camera-camera-smoothzoominfo.md)* smoothZoomInfo | 回调传递的平滑变焦参数信息。 |

### OH_CaptureSession_OnAutoDeviceSwitchStatusChange()

```
typedef void (*OH_CaptureSession_OnAutoDeviceSwitchStatusChange)(Camera_CaptureSession* session,Camera_AutoDeviceSwitchStatusInfo* autoDeviceSwitchStatusInfo)
```

**描述**

捕获会话设备切换状态回调。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [Camera_AutoDeviceSwitchStatusInfo](capi-oh-camera-camera-autodeviceswitchstatusinfo.md)* autoDeviceSwitchStatusInfo | 回调传递的设备切换状态信息。 |

### OH_CaptureSession_OnSystemPressureLevelChange()

```
typedef void (*OH_CaptureSession_OnSystemPressureLevelChange)(Camera_CaptureSession* session,Camera_SystemPressureLevel systemPressureLevel)
```

**描述**

捕获系统压力状态变化回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [Camera_SystemPressureLevel](capi-camera-h.md#camera_systempressurelevel) systemPressureLevel | 回调传递的系统压力等级。 |

### OH_CaptureSession_OnControlCenterEffectStatusChange()

```
typedef void (*OH_CaptureSession_OnControlCenterEffectStatusChange)(Camera_CaptureSession* session,Camera_ControlCenterStatusInfo* controlCenterStatusInfo)
```

**描述**

相机控制器效果激活状态变化回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [Camera_ControlCenterStatusInfo](capi-oh-camera-camera-controlcenterstatusinfo.md)* controlCenterStatusInfo | 回调传递的相机控制器效果激活状态。 |

### OH_CaptureSession_RegisterCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterCallback(Camera_CaptureSession* session,CaptureSession_Callbacks* callback)
```

**描述**

注册捕获会话事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)* callback | 要注册的捕获会话事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_UnregisterCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterCallback(Camera_CaptureSession* session,CaptureSession_Callbacks* callback)
```

**描述**

注销捕获会话事件回调。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [CaptureSession_Callbacks](capi-oh-camera-capturesession-callbacks.md)* callback | 要注销的捕获会话事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_RegisterSmoothZoomInfoCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterSmoothZoomInfoCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**描述**

注册平滑变焦信息事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback | 要注册的平滑变焦信息事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_UnregisterSmoothZoomInfoCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterSmoothZoomInfoCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**描述**

注销平滑变焦信息事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback | 要注销的平滑变焦信息事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_SetSessionMode()

```
Camera_ErrorCode OH_CaptureSession_SetSessionMode(Camera_CaptureSession* session, Camera_SceneMode sceneMode)
```

**描述**

设置会话模式。<br> 此接口不能在[OH_CaptureSession_BeginConfig](#oh_capturesession_beginconfig)之后使用。<br> 建议在使用[OH_CameraManager_CreateCaptureSession](capi-camera-manager-h.md#oh_cameramanager_createcapturesession)后立即使用此接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_SceneMode](capi-camera-h.md#camera_scenemode) sceneMode | 相机模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。<br>         CAMERA_SESSION_CONFIG_LOCKED：会话配置已锁定。 |

### OH_CaptureSession_AddSecureOutput()

```
Camera_ErrorCode OH_CaptureSession_AddSecureOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**描述**

把其中一条PreviewOutput标记成安全输出。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | 要标记为安全输出的Camera_PreviewOutput。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。<br>         CAMERA_SESSION_CONFIG_LOCKED：会话配置已锁定。 |

### OH_CaptureSession_BeginConfig()

```
Camera_ErrorCode OH_CaptureSession_BeginConfig(Camera_CaptureSession* session)
```

**描述**

开始捕获会话配置。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_CONFIG_LOCKED：会话配置已锁定。 |

### OH_CaptureSession_CommitConfig()

```
Camera_ErrorCode OH_CaptureSession_CommitConfig(Camera_CaptureSession* session)
```

**描述**

提交捕获会话配置。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_AddInput()

```
Camera_ErrorCode OH_CaptureSession_AddInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**描述**

添加相机输入。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要添加的相机输入实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_RemoveInput()

```
Camera_ErrorCode OH_CaptureSession_RemoveInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**描述**

删除相机输入。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要删除的相机输入实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_AddPreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* previewOutput)
```

**描述**

添加预览输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | 要添加的预览输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_RemovePreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* previewOutput)
```

**描述**

删除预览输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* previewOutput | 要删除的预览输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_AddPhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**描述**

添加拍照输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 要添加的拍照输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_RemovePhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**描述**

删除拍照输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* photoOutput | 要删除的拍照输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_AddVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**描述**

添加录像输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 要添加的录像输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_RemoveVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**描述**

删除录像输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* videoOutput | 要删除的录像输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_AddMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_AddMetadataOutput(Camera_CaptureSession* session,Camera_MetadataOutput* metadataOutput)
```

**描述**

添加元数据输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 要添加的元数据输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_RemoveMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput(Camera_CaptureSession* session,Camera_MetadataOutput* metadataOutput)
```

**描述**

删除元数据输出。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_MetadataOutput](capi-oh-camera-camera-metadataoutput.md)* metadataOutput | 要删除的元数据输出实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_OPERATION_NOT_ALLOWED：操作不允许。 |

### OH_CaptureSession_Start()

```
Camera_ErrorCode OH_CaptureSession_Start(Camera_CaptureSession* session)
```

**描述**

启动捕获会话。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 要启动的Camera_CaptureSession实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_Stop()

```
Camera_ErrorCode OH_CaptureSession_Stop(Camera_CaptureSession* session)
```

**描述**

停止捕获会话。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 要停止的Camera_CaptureSession实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_Release()

```
Camera_ErrorCode OH_CaptureSession_Release(Camera_CaptureSession* session)
```

**描述**

释放捕获会话。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 要释放的Camera_CaptureSession实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_HasFlash()

```
Camera_ErrorCode OH_CaptureSession_HasFlash(Camera_CaptureSession* session, bool* hasFlash)
```

**描述**

检查设备是否有闪光灯。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| bool* hasFlash | 是否支持闪光灯的结果。返回true表示支持闪光灯，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_IsFlashModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported(Camera_CaptureSession* session,Camera_FlashMode flashMode, bool* isSupported)
```

**描述**

检查是否支持指定的闪光灯模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_FlashMode](capi-camera-h.md#camera_flashmode) flashMode | 要检查的闪光灯模式。 |
| bool* isSupported | 是否支持闪光灯模式的结果。返回true表示支持闪光灯模式，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_GetFlashMode(Camera_CaptureSession* session, Camera_FlashMode* flashMode)
```

**描述**

获取当前闪光灯模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_FlashMode](capi-camera-h.md#camera_flashmode)* flashMode | 当前闪光灯模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_SetFlashMode(Camera_CaptureSession* session, Camera_FlashMode flashMode)
```

**描述**

设置闪光灯模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_FlashMode](capi-camera-h.md#camera_flashmode) flashMode | 要设置的闪光灯模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_IsExposureModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported(Camera_CaptureSession* session,Camera_ExposureMode exposureMode, bool* isSupported)
```

**描述**

检查是否支持指定的曝光模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_ExposureMode](capi-camera-h.md#camera_exposuremode) exposureMode | 要检查的曝光模式。 |
| bool* isSupported | 是否支持曝光模式的结果。返回true表示支持曝光模式，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_GetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode* exposureMode)
```

**描述**

获取当前曝光模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_ExposureMode](capi-camera-h.md#camera_exposuremode)* exposureMode | 当前的曝光模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_SetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode exposureMode)
```

**描述**

设置曝光模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_ExposureMode](capi-camera-h.md#camera_exposuremode) exposureMode | 要设置的曝光模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_GetMeteringPoint(Camera_CaptureSession* session, Camera_Point* point)
```

**描述**

获取当前测量点。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_Point](capi-oh-camera-camera-point.md)* point | 当前测量点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_SetMeteringPoint(Camera_CaptureSession* session, Camera_Point point)
```

**描述**

设置计量区域的中心点。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_Point](capi-oh-camera-camera-point.md) point | 要设置的测量点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetExposureBiasRange()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange(Camera_CaptureSession* session, float* minExposureBias,float* maxExposureBias, float* step)
```

**描述**

查询曝光补偿范围。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float* minExposureBias | 曝光补偿的最小值。 |
| float* maxExposureBias | 曝光补偿的最大值。 |
| float* step | 每个级别之间的曝光补偿阶梯。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_SetExposureBias(Camera_CaptureSession* session, float exposureBias)
```

**描述**

设置曝光补偿。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float exposureBias | 要设置的曝光补偿。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBias(Camera_CaptureSession* session, float* exposureBias)
```

**描述**

获取当前曝光补偿。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float* exposureBias | 当前的曝光补偿。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_IsFocusModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported(Camera_CaptureSession* session,Camera_FocusMode focusMode, bool* isSupported)
```

**描述**

检查是否支持指定的聚焦模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_FocusMode](capi-camera-h.md#camera_focusmode) focusMode | 要检查的聚焦模式。 |
| bool* isSupported | 是否支持聚焦模式的结果。返回true表示支持聚焦模式，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_GetFocusMode(Camera_CaptureSession* session, Camera_FocusMode* focusMode)
```

**描述**

获取当前聚焦模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_FocusMode](capi-camera-h.md#camera_focusmode)* focusMode | 当前聚焦模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_SetFocusMode(Camera_CaptureSession* session, Camera_FocusMode focusMode)
```

**描述**

设置聚焦模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_FocusMode](capi-camera-h.md#camera_focusmode) focusMode | 要设置的聚焦模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_GetFocusPoint(Camera_CaptureSession* session, Camera_Point* focusPoint)
```

**描述**

获取当前焦点。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_Point](capi-oh-camera-camera-point.md)* focusPoint | 当前焦点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_SetFocusPoint(Camera_CaptureSession* session, Camera_Point focusPoint)
```

**描述**

设置焦点。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_Point](capi-oh-camera-camera-point.md) focusPoint | 要设置的目标点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetZoomRatioRange()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange(Camera_CaptureSession* session, float* minZoom, float* maxZoom)
```

**描述**

获取所有支持的缩放比例范围。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float* minZoom | 缩放比范围的最小值。 |
| float* maxZoom | 缩放比例范围的最大值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatio(Camera_CaptureSession* session, float* zoom)
```

**描述**

获取当前缩放比例。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float* zoom | 当前缩放比例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_SetZoomRatio(Camera_CaptureSession* session, float zoom)
```

**描述**

设置缩放比例。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float zoom | 要设置的目标缩放比。<br> 设置可变焦距比到底层生效需要一定时间，获取正确设置的可变焦距比需要等待1~2帧的时间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_IsVideoStabilizationModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported(Camera_CaptureSession* session,Camera_VideoStabilizationMode mode, bool* isSupported)
```

**描述**

检查是否支持指定的录像防抖模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_VideoStabilizationMode](capi-camera-h.md#camera_videostabilizationmode) mode | 要检查的录像防抖模式。 |
| bool* isSupported | 是否支持录像防抖模式的结果。返回true表示支持录像防抖模式，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode(Camera_CaptureSession* session,Camera_VideoStabilizationMode* mode)
```

**描述**

获取当前录像防抖模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_VideoStabilizationMode](capi-camera-h.md#camera_videostabilizationmode)* mode | 当前录像防抖模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode(Camera_CaptureSession* session,Camera_VideoStabilizationMode mode)
```

**描述**

设置录像防抖模式。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_VideoStabilizationMode](capi-camera-h.md#camera_videostabilizationmode) mode | 要设置的录像防抖模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_CanAddInput()

```
Camera_ErrorCode OH_CaptureSession_CanAddInput(Camera_CaptureSession* session,Camera_Input* cameraInput, bool* isSuccessful)
```

**描述**

确定是否可以将相机输入添加到会话中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_Input](capi-oh-camera-camera-input.md)* cameraInput | 要设置的相机输入实例。 |
| bool* isSuccessful | 是否可以将相机输入添加到会话中的结果。返回true表示可以将相机输入添加到会话中，返回false表示不可以。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_CanAddPreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddPreviewOutput(Camera_CaptureSession* session,Camera_PreviewOutput* cameraOutput, bool* isSuccessful)
```

**描述**

确定是否可以将相机预览输出添加到会话中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreviewOutput](capi-oh-camera-camera-previewoutput.md)* cameraOutput | 要设置的预览输出实例。 |
| bool* isSuccessful | 是否可以将相机预览输出添加到会话中的结果。返回true表示可以将相机预览输出添加到会话中，返回false表示不可以。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_CanAddPhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddPhotoOutput(Camera_CaptureSession* session,Camera_PhotoOutput* cameraOutput, bool* isSuccessful)
```

**描述**

确定是否可以将拍照输出添加到会话中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PhotoOutput](capi-oh-camera-camera-photooutput.md)* cameraOutput | 要设置的拍照输出实例。 |
| bool* isSuccessful | 拍照输出是否可以添加到会话中的结果。返回true表示拍照输出可以添加到会话中，返回false表示不可以。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_CanAddVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddVideoOutput(Camera_CaptureSession* session,Camera_VideoOutput* cameraOutput, bool* isSuccessful)
```

**描述**

确定是否可以将录像输出添加到会话中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_VideoOutput](capi-oh-camera-camera-videooutput.md)* cameraOutput | 要添加的录像输出实例。 |
| bool* isSuccessful | 录像输出是否可以添加到会话中的结果。返回true表示录像输出可以添加到会话中，返回false表示不可以。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_CanPreconfig()

```
Camera_ErrorCode OH_CaptureSession_CanPreconfig(Camera_CaptureSession* session,Camera_PreconfigType preconfigType, bool* canPreconfig)
```

**描述**

检查是否支持指定的预配置类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | 要检查的预配置类型。 |
| bool* canPreconfig | 是否支持预配置的结果。返回true表示支持预配置，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_CanPreconfigWithRatio()

```
Camera_ErrorCode OH_CaptureSession_CanPreconfigWithRatio(Camera_CaptureSession* session,Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio, bool* canPreconfig)
```

**描述**

检查是否支持带比例的预配置类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | 要检查的预配置类型。 |
| [Camera_PreconfigRatio](capi-camera-h.md#camera_preconfigratio) preconfigRatio | 要检查的预配置比例。 |
| bool* canPreconfig | 是否支持预配置的结果。返回ture表示支持预配置，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_Preconfig()

```
Camera_ErrorCode OH_CaptureSession_Preconfig(Camera_CaptureSession* session,Camera_PreconfigType preconfigType)
```

**描述**

设置预配置类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | 指定的预配置类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_PreconfigWithRatio()

```
Camera_ErrorCode OH_CaptureSession_PreconfigWithRatio(Camera_CaptureSession* session,Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio)
```

**描述**

设置带有比例的预配置类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_PreconfigType](capi-camera-h.md#camera_preconfigtype) preconfigType | 指定的预配置类型。 |
| [Camera_PreconfigRatio](capi-camera-h.md#camera_preconfigratio) preconfigRatio | 指定的预配置比例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_GetExposureValue()

```
Camera_ErrorCode OH_CaptureSession_GetExposureValue(Camera_CaptureSession* session, float* exposureValue)
```

**描述**

查询曝光值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float* exposureValue | 当前的曝光值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_GetFocalLength()

```
Camera_ErrorCode OH_CaptureSession_GetFocalLength(Camera_CaptureSession* session, float* focalLength)
```

**描述**

获取当前焦距值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float* focalLength | 当前焦距值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetSmoothZoom()

```
Camera_ErrorCode OH_CaptureSession_SetSmoothZoom(Camera_CaptureSession* session,float targetZoom, Camera_SmoothZoomMode smoothZoomMode)
```

**描述**

触发平滑变焦。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| float targetZoom | 要设置的目标变焦比。 |
| [Camera_SmoothZoomMode](capi-camera-h.md#camera_smoothzoommode) smoothZoomMode | 平滑变焦模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetSupportedColorSpaces()

```
Camera_ErrorCode OH_CaptureSession_GetSupportedColorSpaces(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace** colorSpace, uint32_t* size)
```

**描述**

获取支持的色彩空间列表。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| OH_NativeBuffer_ColorSpace** colorSpace | 如果方法调用成功，将记录支持的OH_NativeBuffer_ColorSpace列表。 |
| uint32_t* size | 如果方法调用成功，将记录支持的OH_NativeBuffer_ColorSpace列表的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_DeleteColorSpaces()

```
Camera_ErrorCode OH_CaptureSession_DeleteColorSpaces(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace* colorSpace)
```

**描述**

删除色彩空间列表。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace)* colorSpace | 如果方法调用成功，将删除的OH_NativeBuffer_ColorSpace列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_GetActiveColorSpace()

```
Camera_ErrorCode OH_CaptureSession_GetActiveColorSpace(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace* colorSpace)
```

**描述**

获取当前色彩空间。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace)* colorSpace | 当前的OH_NativeBuffer_ColorSpace。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_SetActiveColorSpace()

```
Camera_ErrorCode OH_CaptureSession_SetActiveColorSpace(Camera_CaptureSession* session,OH_NativeBuffer_ColorSpace colorSpace)
```

**描述**

设置当前色彩空间。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace) colorSpace | 要设置的目标OH_NativeBuffer_ColorSpace。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_RegisterAutoDeviceSwitchStatusCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session,OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)
```

**描述**

注册设备切换事件回调。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnAutoDeviceSwitchStatusChange](#oh_capturesession_onautodeviceswitchstatuschange) autoDeviceSwitchStatusChange | 要注册的设备切换事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_UnregisterAutoDeviceSwitchStatusCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterAutoDeviceSwitchStatusCallback(Camera_CaptureSession* session,OH_CaptureSession_OnAutoDeviceSwitchStatusChange autoDeviceSwitchStatusChange)
```

**描述**

注销设备切换事件回调。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnAutoDeviceSwitchStatusChange](#oh_capturesession_onautodeviceswitchstatuschange) autoDeviceSwitchStatusChange | 要注销的设备切换事件回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_IsAutoDeviceSwitchSupported()

```
Camera_ErrorCode OH_CaptureSession_IsAutoDeviceSwitchSupported(Camera_CaptureSession* session, bool* isSupported)
```

**描述**

检查是否支持自动设备切换。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| bool* isSupported | 是否支持自动设备切换的结果。返回true表示支持自动设备切换，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_EnableAutoDeviceSwitch()

```
Camera_ErrorCode OH_CaptureSession_EnableAutoDeviceSwitch(Camera_CaptureSession* session, bool enabled)
```

**描述**

是否启用相机设备的自动切换。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| bool enabled | 是否启用自动切换的标志。返回true表示启用自动切换，返回false表示不启用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_RegisterSystemPressureLevelChangeCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterSystemPressureLevelChangeCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)
```

**描述**

注册系统压力状态变化回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnSystemPressureLevelChange](#oh_capturesession_onsystempressurelevelchange) systemPressureLevelChange | 要注册的系统压力状态变化OH_CaptureSession_OnSystemPressureLevelChange回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_UnregisterSystemPressureLevelCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterSystemPressureLevelCallback(Camera_CaptureSession* session,OH_CaptureSession_OnSystemPressureLevelChange systemPressureLevelChange)
```

**描述**

注销系统压力状态变化回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnSystemPressureLevelChange](#oh_capturesession_onsystempressurelevelchange) systemPressureLevelChange | 要注销的系统压力状态变化OH_CaptureSession_OnSystemPressureLevelChange回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_SetQualityPrioritization()

```
Camera_ErrorCode OH_CaptureSession_SetQualityPrioritization(Camera_CaptureSession* session, Camera_QualityPrioritization qualityPrioritization)
```

**描述**

设置录像质量优先级。<br> 默认为高质量，设置为功耗平衡将降低录像质量以减少功耗。实际功耗收益因平台而异。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_QualityPrioritization](capi-camera-h.md#camera_qualityprioritization) qualityPrioritization | 要设置的录像质量优先级，默认为高质量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_IsMacroSupported()

```
Camera_ErrorCode OH_CaptureSession_IsMacroSupported(Camera_CaptureSession* session, bool* isSupported)
```

**描述**

检查是否支持微距能力。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| bool* isSupported | 是否支持微距能力的结果。返回ture表示支持微距能力，返回false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | <br>         CAMERA_OK = 0：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_EnableMacro()

```
Camera_ErrorCode OH_CaptureSession_EnableMacro(Camera_CaptureSession* session, bool enabled)
```

**描述**

是否启用相机设备的微距能力。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| bool enabled | 是否启用微距能力的标志。返回ture表示启用微距能力，返回false表示不启用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | <br>         CAMERA_OK = 0：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_OPERATION_NOT_ALLOWED：不允许操作。 |

### OH_CaptureSession_SetWhiteBalance()

```
Camera_ErrorCode OH_CaptureSession_SetWhiteBalance(Camera_CaptureSession* session, int32_t colorTemperature)
```

**描述**

设置白平衡的色温。<br> 设置前，建议通过[OH_CaptureSession_GetWhiteBalanceRange](#oh_capturesession_getwhitebalancerange)获取支持配置的白平衡色温范围。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| int32_t colorTemperature | 色温值，单位为K。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：设置成功。<br> CAMERA_INVALID_ARGUMENT：参数缺失或者参数类型不正确。<br> CAMERA_SESSION_NOT_CONFIG：相机会话未配置。 |

### OH_CaptureSession_GetWhiteBalance()

```
Camera_ErrorCode OH_CaptureSession_GetWhiteBalance(Camera_CaptureSession* session, int32_t *colorTemperature)
```

**描述**

获取当前白平衡色温值。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| int32_t *colorTemperature | 色温值，单位为K。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：函数调用成功。<br> CAMERA_INVALID_ARGUMENT：参数缺失或者参数类型不正确。<br> CAMERA_SESSION_NOT_CONFIG：相机会话未配置。 |

### OH_CaptureSession_GetWhiteBalanceMode()

```
Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode* whiteBalanceMode)
```

**描述**

获取当前的白平衡模式。


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_WhiteBalanceMode](capi-camera-h.md#camera_whitebalancemode)* whiteBalanceMode | 白平衡模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：函数调用成功。<br> CAMERA_INVALID_ARGUMENT：参数缺失或者参数类型不正确。<br> CAMERA_SESSION_NOT_CONFIG：相机会话未配置。 |

### OH_CaptureSession_IsWhiteBalanceModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsWhiteBalanceModeSupported(Camera_CaptureSession* session,Camera_WhiteBalanceMode whiteBalanceMode, bool* isSupported)
```

**描述**

检查是否支持指定的白平衡模式。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_WhiteBalanceMode](capi-camera-h.md#camera_whitebalancemode) whiteBalanceMode | 指定的白平衡模式。 |
| bool* isSupported | 用于返回是否支持指定的白平衡模式，支持返回true，否则返回false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：函数调用成功。<br> CAMERA_INVALID_ARGUMENT：参数缺失或者参数类型不正确。<br> CAMERA_SESSION_NOT_CONFIG：相机会话未配置。 |

### OH_CaptureSession_SetWhiteBalanceMode()

```
Camera_ErrorCode OH_CaptureSession_SetWhiteBalanceMode(Camera_CaptureSession* session, Camera_WhiteBalanceMode whiteBalanceMode)
```

**描述**

设置白平衡模式。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_WhiteBalanceMode](capi-camera-h.md#camera_whitebalancemode) whiteBalanceMode | 白平衡模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：设置成功。<br> CAMERA_INVALID_ARGUMENT：参数缺失或者参数类型不正确。<br> CAMERA_SESSION_NOT_CONFIG：相机会话未配置。 |

### OH_CaptureSession_GetWhiteBalanceRange()

```
Camera_ErrorCode OH_CaptureSession_GetWhiteBalanceRange(Camera_CaptureSession* session, int32_t *minColorTemperature, int32_t *maxColorTemperature)
```

**描述**

获取支持配置的白平衡色温范围。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| int32_t *minColorTemperature | 支持的最小色温值，单位为K。 |
| int32_t *maxColorTemperature | 支持的最大色温值，单位为K。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：函数调用成功。<br> CAMERA_INVALID_ARGUMENT：参数缺失或者参数类型不正确。<br> CAMERA_SESSION_NOT_CONFIG：相机会话未配置。 |

### OH_CaptureSession_IsControlCenterSupported()

```
Camera_ErrorCode OH_CaptureSession_IsControlCenterSupported(Camera_CaptureSession* session, bool* isSupported)
```

**描述**

检查是否支持相机控制器。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| bool* isSupported | 是否支持相机控制器的结果。true表示支持，false表示不支持。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK = 0：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_GetSupportedEffectType()

```
Camera_ErrorCode OH_CaptureSession_GetSupportedEffectType(Camera_CaptureSession* session,Camera_ControlCenterEffectType** types, uint32_t* size)
```

**描述**

获取相机控制器支持的效果类型。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_ControlCenterEffectType](capi-camera-h.md#camera_controlcentereffecttype)** types | 如果方法调用成功，将记录支持的Camera_ControlCenterEffectType列表。 |
| uint32_t* size | 如果方法调用成功，将记录支持的Camera_ControlCenterEffectType列表的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。 |

### OH_CaptureSession_DeleteSupportedEffectType()

```
Camera_ErrorCode OH_CaptureSession_DeleteSupportedEffectType(Camera_CaptureSession* session,Camera_ControlCenterEffectType* types, uint32_t size)
```

**描述**

删除相机控制器效果类型列表。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| [Camera_ControlCenterEffectType](capi-camera-h.md#camera_controlcentereffecttype)* types | 如果方法调用成功，要删除的Camera_ControlCenterEffectType列表。 |
| uint32_t size | 要删除的Camera_ControlCenterEffectType列表的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_EnableControlCenter()

```
Camera_ErrorCode OH_CaptureSession_EnableControlCenter(Camera_CaptureSession* session, bool enabled)
```

**描述**

是否启用相机控制器。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | Camera_CaptureSession实例。 |
| bool enabled | 是否启用相机控制器的标志。true表示启用，false表示禁用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK = 0：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。<br>         CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。<br>         CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。 |

### OH_CaptureSession_RegisterControlCenterEffectStatusChangeCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session,OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)
```

**描述**

注册相机控制器效果激活状态变化回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnControlCenterEffectStatusChange](#oh_capturesession_oncontrolcentereffectstatuschange) controlCenterEffectStatusChange | 要注册的相机控制器效果激活状态变化OH_CaptureSession_OnControlCenterEffectStatusChange回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |

### OH_CaptureSession_UnregisterControlCenterEffectStatusChangeCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterControlCenterEffectStatusChangeCallback(Camera_CaptureSession* session,OH_CaptureSession_OnControlCenterEffectStatusChange controlCenterEffectStatusChange)
```

**描述**

注销相机控制器效果激活状态变化回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Camera_CaptureSession](capi-oh-camera-camera-capturesession.md)* session | 传递回调的Camera_CaptureSession实例。 |
| [OH_CaptureSession_OnControlCenterEffectStatusChange](#oh_capturesession_oncontrolcentereffectstatuschange) controlCenterEffectStatusChange | 要注销的相机控制器效果激活状态变化OH_CaptureSession_OnControlCenterEffectStatusChange回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | CAMERA_OK：方法调用成功。<br>         CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。 |


