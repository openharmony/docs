# camera.h


## 概述

声明相机的基本概念。

**库：** libohcamera.so

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_Size](_camera___size.md) | 大小参数。 | 
| [Camera_Profile](_camera___profile.md) | 相机流的配置文件。 | 
| [Camera_FrameRateRange](_camera___frame_rate_range.md) | 帧速率范围。 | 
| [Camera_VideoProfile](_camera___video_profile.md) | 录像配置文件。 | 
| [Camera_OutputCapability](_camera___output_capability.md) | 相机输出能力。 | 
| [Camera_Device](_camera___device.md) | 相机设备对象。 | 
| [Camera_StatusInfo](_camera___status_info.md) | 相机状态信息。 | 
| [Camera_Point](_camera___point.md) | 点参数。 | 
| [Camera_Location](_camera___location.md) | 拍照位置。 | 
| [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) | 要设置的拍照捕获选项。 | 
| [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) | 帧快门回调信息。 | 
| [Camera_CaptureEndInfo](_camera___capture_end_info.md) | 捕获结束信息。 | 
| [Camera_Rect](_camera___rect.md) | 矩形定义。 | 
| [Camera_MetadataObject](_camera___metadata_object.md) | 元数据对象基础。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_Manager](_o_h___camera.md#camera_manager) | 相机管理器对象。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) | 相机错误代码的枚举。 | 
| [Camera_Status](_o_h___camera.md#camera_status) | 相机状态的枚举。 | 
| [Camera_Position](_o_h___camera.md#camera_position) | 相机位置的枚举。 | 
| [Camera_Type](_o_h___camera.md#camera_type) | 相机类型的枚举。 | 
| [Camera_Connection](_o_h___camera.md#camera_connection) | 相机连接类型的枚举。 | 
| [Camera_Format](_o_h___camera.md#camera_format) | 相机格式类型的枚举。 | 
| [Camera_FlashMode](_o_h___camera.md#camera_flashmode) | 闪光模式的枚举。 | 
| [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) | 曝光模式的枚举。 | 
| [Camera_FocusMode](_o_h___camera.md#camera_focusmode) | 聚焦模式的枚举。 | 
| [Camera_FocusState](_o_h___camera.md#camera_focusstate) | 焦点状态的枚举。 | 
| [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) | 录像防抖模式的枚举。 | 
| [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) | 图像旋转角度的枚举。 | 
| [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) | 图像质量等级的枚举。 | 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) | 元数据对象类型的枚举。 | 
| [Camera_Size](_o_h___camera.md#camera_size) | 大小参数。 | 
| [Camera_Profile](_o_h___camera.md#camera_profile) | 相机流的配置文件。 | 
| [Camera_FrameRateRange](_o_h___camera.md#camera_frameraterange) | 帧速率范围。 | 
| [Camera_VideoProfile](_o_h___camera.md#camera_videoprofile) | 录像配置文件。 | 
| [Camera_OutputCapability](_o_h___camera.md#camera_outputcapability) | 相机输出能力。 | 
| [Camera_Device](_o_h___camera.md#camera_device) | 相机设备对象。 | 
| [Camera_StatusInfo](_o_h___camera.md#camera_statusinfo) | 相机状态信息。 | 
| [Camera_Point](_o_h___camera.md#camera_point) | 点参数。 | 
| [Camera_Location](_o_h___camera.md#camera_location) | 拍照位置。 | 
| [Camera_PhotoCaptureSetting](_o_h___camera.md#camera_photocapturesetting) | 要设置的拍照捕获选项。 | 
| [Camera_FrameShutterInfo](_o_h___camera.md#camera_frameshutterinfo) | 帧快门回调信息。 | 
| [Camera_CaptureEndInfo](_o_h___camera.md#camera_captureendinfo) | 捕获结束信息。 | 
| [Camera_Rect](_o_h___camera.md#camera_rect) | 矩形定义。 | 
| [Camera_MetadataObject](_o_h___camera.md#camera_metadataobject) | 元数据对象基础。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) {<br/>[CAMERA_OK](_o_h___camera.md) = 0, [CAMERA_INVALID_ARGUMENT](_o_h___camera.md) = 7400101, [CAMERA_OPERATION_NOT_ALLOWED](_o_h___camera.md) = 7400102, [CAMERA_SESSION_NOT_CONFIG](_o_h___camera.md) = 7400103,<br/>[CAMERA_SESSION_NOT_RUNNING](_o_h___camera.md) = 7400104, [CAMERA_SESSION_CONFIG_LOCKED](_o_h___camera.md) = 7400105, [CAMERA_DEVICE_SETTING_LOCKED](_o_h___camera.md) = 7400106, [CAMERA_CONFLICT_CAMERA](_o_h___camera.md) = 7400107,<br/>[CAMERA_DEVICE_DISABLED](_o_h___camera.md) = 7400108, [CAMERA_DEVICE_PREEMPTED](_o_h___camera.md) = 7400109, [CAMERA_SERVICE_FATAL_ERROR](_o_h___camera.md) = 7400201<br/>} | 相机错误代码的枚举。 | 
| [Camera_Status](_o_h___camera.md#camera_status) { [CAMERA_STATUS_APPEAR](_o_h___camera.md) = 0, [CAMERA_STATUS_DISAPPEAR](_o_h___camera.md) = 1, [CAMERA_STATUS_AVAILABLE](_o_h___camera.md) = 2, [CAMERA_STATUS_UNAVAILABLE](_o_h___camera.md) = 3 } | 相机状态的枚举。 | 
| [Camera_Position](_o_h___camera.md#camera_position) { [CAMERA_POSITION_UNSPECIFIED](_o_h___camera.md) = 0, [CAMERA_POSITION_BACK](_o_h___camera.md) = 1, [CAMERA_POSITION_FRONT](_o_h___camera.md) = 2 } | 相机位置的枚举。 | 
| [Camera_Type](_o_h___camera.md#camera_type) {<br/>[CAMERA_TYPE_DEFAULT](_o_h___camera.md) = 0, [CAMERA_TYPE_WIDE_ANGLE](_o_h___camera.md) = 1, [CAMERA_TYPE_ULTRA_WIDE](_o_h___camera.md) = 2, [CAMERA_TYPE_TELEPHOTO](_o_h___camera.md) = 3,<br/>[CAMERA_TYPE_TRUE_DEPTH](_o_h___camera.md) = 4<br/>} | 相机类型的枚举。 | 
| [Camera_Connection](_o_h___camera.md#camera_connection) { [CAMERA_CONNECTION_BUILT_IN](_o_h___camera.md) = 0, [CAMERA_CONNECTION_USB_PLUGIN](_o_h___camera.md) = 1, [CAMERA_CONNECTION_REMOTE](_o_h___camera.md) = 2 } | 相机连接类型的枚举。 | 
| [Camera_Format](_o_h___camera.md#camera_format) { [CAMERA_FORMAT_RGBA_8888](_o_h___camera.md) = 3, [CAMERA_FORMAT_YUV_420_SP](_o_h___camera.md) = 1003, [CAMERA_FORMAT_JPEG](_o_h___camera.md) = 2000 } | 相机格式类型的枚举。 | 
| [Camera_FlashMode](_o_h___camera.md#camera_flashmode) { [FLASH_MODE_CLOSE](_o_h___camera.md) = 0, [FLASH_MODE_OPEN](_o_h___camera.md) = 1, [FLASH_MODE_AUTO](_o_h___camera.md) = 2, [FLASH_MODE_ALWAYS_OPEN](_o_h___camera.md) = 3 } | 闪光模式的枚举。 | 
| [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) { [EXPOSURE_MODE_LOCKED](_o_h___camera.md) = 0, [EXPOSURE_MODE_AUTO](_o_h___camera.md) = 1, [EXPOSURE_MODE_CONTINUOUS_AUTO](_o_h___camera.md) = 2 } | 曝光模式的枚举。 | 
| [Camera_FocusMode](_o_h___camera.md#camera_focusmode) { [FOCUS_MODE_MANUAL](_o_h___camera.md) = 0, [FOCUS_MODE_CONTINUOUS_AUTO](_o_h___camera.md) = 1, [FOCUS_MODE_AUTO](_o_h___camera.md) = 2, [FOCUS_MODE_LOCKED](_o_h___camera.md) = 3 } | 聚焦模式的枚举。 | 
| [Camera_FocusState](_o_h___camera.md#camera_focusstate) { [FOCUS_STATE_SCAN](_o_h___camera.md) = 0, [FOCUS_STATE_FOCUSED](_o_h___camera.md) = 1, [FOCUS_STATE_UNFOCUSED](_o_h___camera.md) = 2 } | 焦点状态的枚举。 | 
| [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) {<br/>[STABILIZATION_MODE_OFF](_o_h___camera.md) = 0, [STABILIZATION_MODE_LOW](_o_h___camera.md) = 1, [STABILIZATION_MODE_MIDDLE](_o_h___camera.md) = 2, [STABILIZATION_MODE_HIGH](_o_h___camera.md) = 3,<br/>[STABILIZATION_MODE_AUTO](_o_h___camera.md) = 4<br/>} | 录像防抖模式的枚举。 | 
| [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) { [IAMGE_ROTATION_0](_o_h___camera.md) = 0, [IAMGE_ROTATION_90](_o_h___camera.md) = 90, [IAMGE_ROTATION_180](_o_h___camera.md) = 180, [IAMGE_ROTATION_270](_o_h___camera.md) = 270 } | 图像旋转角度的枚举。 | 
| [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) { [QUALITY_LEVEL_HIGH](_o_h___camera.md) = 0, [QUALITY_LEVEL_MEDIUM](_o_h___camera.md) = 1, [QUALITY_LEVEL_LOW](_o_h___camera.md) = 2 } | 图像质量等级的枚举。 | 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) { [FACE_DETECTION](_o_h___camera.md) = 0 } | 元数据对象类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Camera_GetCameraManager](_o_h___camera.md#oh_camera_getcameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*\*cameraManager) | 创建CameraManager实例。 | 
| [OH_Camera_DeleteCameraManager](_o_h___camera.md#oh_camera_deletecameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager) | 删除CameraManager实例。 | 
