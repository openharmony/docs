# capture_session.h


## 概述

声明捕获会话概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/capture_session.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [CaptureSession_Callbacks](_capture_session___callbacks.md) | 捕获会话的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_CaptureSession](_o_h___camera.md#camera_capturesession) [Camera_CaptureSession](_o_h___camera.md#camera_capturesession) | 捕获会话对象。 | 
| typedef void(\* [OH_CaptureSession_OnFocusStateChange](_o_h___camera.md#oh_capturesession_onfocusstatechange)) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_FocusState](_o_h___camera.md#camera_focusstate) focusState) | 在[CaptureSession_Callbacks](_capture_session___callbacks.md)中被调用的捕获会话焦点状态回调。 | 
| typedef void(\* [OH_CaptureSession_OnError](_o_h___camera.md#oh_capturesession_onerror)) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) errorCode) | 在[CaptureSession_Callbacks](_capture_session___callbacks.md)中被调用的捕获会话错误回调。 | 
| typedef void(\* [OH_CaptureSession_OnSmoothZoomInfo](_o_h___camera.md#oh_capturesession_onsmoothzoominfo)) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) \*smoothZoomInfo) | 拍照会话平滑变焦信息回调，触发平滑变焦后该回调会返回。 | 
| typedef struct [CaptureSession_Callbacks](_capture_session___callbacks.md) [CaptureSession_Callbacks](_o_h___camera.md#capturesession_callbacks) | 捕获会话的回调。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_RegisterCallback](_o_h___camera.md#oh_capturesession_registercallback) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | 注册捕获会话事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_UnregisterCallback](_o_h___camera.md#oh_capturesession_unregistercallback) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | 注销捕获会话事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_RegisterSmoothZoomInfoCallback](_o_h___camera.md#oh_capturesession_registersmoothzoominfocallback) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [OH_CaptureSession_OnSmoothZoomInfo](_o_h___camera.md#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback) | 注册平滑变焦信息事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_UnregisterSmoothZoomInfoCallback](_o_h___camera.md#oh_capturesession_unregistersmoothzoominfocallback) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [OH_CaptureSession_OnSmoothZoomInfo](_o_h___camera.md#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback) | 注销平滑变焦信息事件回调。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetSessionMode](_o_h___camera.md#oh_capturesession_setsessionmode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_SceneMode](_o_h___camera.md#camera_scenemode) sceneMode) | 指定具体的模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_AddSecureOutput](_o_h___camera.md#oh_capturesession_addsecureoutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | 把其中一条PreviewOutput标记成安全输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_BeginConfig](_o_h___camera.md#oh_capturesession_beginconfig) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session) | 开始捕获会话配置。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_CommitConfig](_o_h___camera.md#oh_capturesession_commitconfig) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session) | 提交捕获会话配置。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_AddInput](_o_h___camera.md#oh_capturesession_addinput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | 添加相机输入。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_RemoveInput](_o_h___camera.md#oh_capturesession_removeinput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_Input](_o_h___camera.md#camera_input) \*cameraInput) | 删除相机输入。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_AddPreviewOutput](_o_h___camera.md#oh_capturesession_addpreviewoutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | 添加预览输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_RemovePreviewOutput](_o_h___camera.md#oh_capturesession_removepreviewoutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*previewOutput) | 删除预览输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_AddPhotoOutput](_o_h___camera.md#oh_capturesession_addphotooutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 添加拍照输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_RemovePhotoOutput](_o_h___camera.md#oh_capturesession_removephotooutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*photoOutput) | 删除拍照输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_AddVideoOutput](_o_h___camera.md#oh_capturesession_addvideooutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 添加录像输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_RemoveVideoOutput](_o_h___camera.md#oh_capturesession_removevideooutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*videoOutput) | 删除录像输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_AddMetadataOutput](_o_h___camera.md#oh_capturesession_addmetadataoutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | 添加元数据输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_RemoveMetadataOutput](_o_h___camera.md#oh_capturesession_removemetadataoutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_MetadataOutput](_o_h___camera.md#camera_metadataoutput) \*metadataOutput) | 删除元数据输出。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_Start](_o_h___camera.md#oh_capturesession_start) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session) | 启动捕获会话。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_Stop](_o_h___camera.md#oh_capturesession_stop) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session) | 停止捕获会话。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_Release](_o_h___camera.md#oh_capturesession_release) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session) | 释放捕获会话。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_HasFlash](_o_h___camera.md#oh_capturesession_hasflash) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, bool \*hasFlash) | 检查设备是否有闪光灯。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_IsFlashModeSupported](_o_h___camera.md#oh_capturesession_isflashmodesupported) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_FlashMode](_o_h___camera.md#camera_flashmode) flashMode, bool \*isSupported) | 检查是否支持指定的闪光灯模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetFlashMode](_o_h___camera.md#oh_capturesession_getflashmode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_FlashMode](_o_h___camera.md#camera_flashmode) \*flashMode) | 获取当前闪光灯模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetFlashMode](_o_h___camera.md#oh_capturesession_setflashmode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_FlashMode](_o_h___camera.md#camera_flashmode) flashMode) | 设置闪光灯模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_IsExposureModeSupported](_o_h___camera.md#oh_capturesession_isexposuremodesupported) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) exposureMode, bool \*isSupported) | 检查是否支持指定的曝光模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetExposureMode](_o_h___camera.md#oh_capturesession_getexposuremode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) \*exposureMode) | 获取当前曝光模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetExposureMode](_o_h___camera.md#oh_capturesession_setexposuremode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) exposureMode) | 设置曝光模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetMeteringPoint](_o_h___camera.md#oh_capturesession_getmeteringpoint) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_Point](_camera___point.md) \*point) | 获取当前测量点。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetMeteringPoint](_o_h___camera.md#oh_capturesession_setmeteringpoint) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_Point](_camera___point.md) point) | 设置计量区域的中心点。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetExposureBiasRange](_o_h___camera.md#oh_capturesession_getexposurebiasrange) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float \*minExposureBias, float \*maxExposureBias, float \*step) | 查询曝光补偿范围。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetExposureBias](_o_h___camera.md#oh_capturesession_setexposurebias) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float exposureBias) | 设置曝光补偿。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetExposureBias](_o_h___camera.md#oh_capturesession_getexposurebias) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float \*exposureBias) | 获取当前曝光补偿。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_IsFocusModeSupported](_o_h___camera.md#oh_capturesession_isfocusmodesupported) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_FocusMode](_o_h___camera.md#camera_focusmode) focusMode, bool \*isSupported) | 检查是否支持指定的聚焦模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetFocusMode](_o_h___camera.md#oh_capturesession_getfocusmode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_FocusMode](_o_h___camera.md#camera_focusmode) \*focusMode) | 获取当前聚焦模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetFocusMode](_o_h___camera.md#oh_capturesession_setfocusmode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_FocusMode](_o_h___camera.md#camera_focusmode) focusMode) | 设置聚焦模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetFocusPoint](_o_h___camera.md#oh_capturesession_getfocuspoint) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_Point](_camera___point.md) \*focusPoint) | 获取当前焦点。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetFocusPoint](_o_h___camera.md#oh_capturesession_setfocuspoint) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_Point](_camera___point.md) focusPoint) | 设置焦点。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetZoomRatioRange](_o_h___camera.md#oh_capturesession_getzoomratiorange) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float \*minZoom, float \*maxZoom) | 获取所有支持的缩放比例范围。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetZoomRatio](_o_h___camera.md#oh_capturesession_getzoomratio) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float \*zoom) | 获取当前缩放比例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetZoomRatio](_o_h___camera.md#oh_capturesession_setzoomratio) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float zoom) | 设置缩放比例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_IsVideoStabilizationModeSupported](_o_h___camera.md#oh_capturesession_isvideostabilizationmodesupported) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) mode, bool \*isSupported) | 检查是否支持指定的录像防抖模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetVideoStabilizationMode](_o_h___camera.md#oh_capturesession_getvideostabilizationmode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) \*mode) | 获取当前录像防抖模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetVideoStabilizationMode](_o_h___camera.md#oh_capturesession_setvideostabilizationmode) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) mode) | 设置录像防抖模式。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_CanAddInput](_o_h___camera.md#oh_capturesession_canaddinput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_Input](_o_h___camera.md#camera_input) \*cameraInput, bool \*isSuccessful) | 确定是否可以将相机输入添加到会话中。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_CanAddPreviewOutput](_o_h___camera.md#oh_capturesession_canaddpreviewoutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreviewOutput](_o_h___camera.md#camera_previewoutput) \*cameraOutput, bool \*isSuccessful) | 确定是否可以将相机预览输出添加到会话中。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_CanAddPhotoOutput](_o_h___camera.md#oh_capturesession_canaddphotooutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PhotoOutput](_o_h___camera.md#camera_photooutput) \*cameraOutput, bool \*isSuccessful) | 确定是否可以将相机照片输出添加到会话中。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_CanAddVideoOutput](_o_h___camera.md#oh_capturesession_canaddvideooutput) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_VideoOutput](_o_h___camera.md#camera_videooutput) \*cameraOutput, bool \*isSuccessful) | 确定是否可以将相机视频输出添加到会话中。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_CanPreconfig](_o_h___camera.md#oh_capturesession_canpreconfig) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) preconfigType, bool \*canPreconfig) | 检查是否支持指定的预配置类型。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_CanPreconfigWithRatio](_o_h___camera.md#oh_capturesession_canpreconfigwithratio) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) preconfigType, [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio) preconfigRatio, bool \*canPreconfig) | 检查是否支持带比例的预配置类型。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_Preconfig](_o_h___camera.md#oh_capturesession_preconfig) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) preconfigType) | 设置预配置类型。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_PreconfigWithRatio](_o_h___camera.md#oh_capturesession_preconfigwithratio) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) preconfigType, [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio) preconfigRatio) | 设置带有比例的预配置类型。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetExposureValue](_o_h___camera.md#oh_capturesession_getexposurevalue) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float \*exposureValue) | 查询曝光值。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetFocalLength](_o_h___camera.md#oh_capturesession_getfocallength) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float \*focalLength) | 获取当前焦距值。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetSmoothZoom](_o_h___camera.md#oh_capturesession_setsmoothzoom) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, float targetZoom, [Camera_SmoothZoomMode](_o_h___camera.md#camera_smoothzoommode) smoothZoomMode) | 触发平滑变焦。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetSupportedColorSpaces](_o_h___camera.md#oh_capturesession_getsupportedcolorspaces) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*\*colorSpace, uint32_t \*size) | 获取支持的色彩空间列表。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_DeleteColorSpaces](_o_h___camera.md#oh_capturesession_deletecolorspaces) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*colorSpace) | 删除色彩空间列表。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_GetActiveColorSpace](_o_h___camera.md#oh_capturesession_getactivecolorspace) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*colorSpace) | 获取当前色彩空间。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetActiveColorSpace](_o_h___camera.md#oh_capturesession_setactivecolorspace) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace colorSpace) | 设置当前色彩空间。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_CaptureSession_SetQualityPrioritization](_o_h___camera.md#oh_capturesession_setqualityprioritization) ([Camera_CaptureSession](_o_h___camera.md#camera_capturesession) \*session, [Camera_QualityPrioritization](_o_h___camera.md#camera_qualityprioritization) qualityPrioritization) | 设置录像质量优先级。 | 
