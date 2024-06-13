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
| struct  [Camera_Size](_camera___size.md) | 大小参数。  | 
| struct  [Camera_Profile](_camera___profile.md) | 相机流的配置文件。  | 
| struct  [Camera_FrameRateRange](_camera___frame_rate_range.md) | 帧速率范围。  | 
| struct  [Camera_VideoProfile](_camera___video_profile.md) | 录像配置文件。  | 
| struct  [Camera_OutputCapability](_camera___output_capability.md) | 相机输出能力。  | 
| struct  [Camera_Device](_camera___device.md) | 相机设备对象。  | 
| struct  [Camera_StatusInfo](_camera___status_info.md) | 相机状态信息。  | 
| struct  [Camera_Point](_camera___point.md) | 点参数。  | 
| struct  [Camera_Location](_camera___location.md) | 拍照位置。  | 
| struct  [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) | 要设置的拍照捕获选项。  | 
| struct  [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) | 帧快门回调信息。  | 
| struct  [Camera_CaptureEndInfo](_camera___capture_end_info.md) | 捕获结束信息。  | 
| struct  [Camera_Rect](_camera___rect.md) | 矩形定义。  | 
| struct  [Camera_MetadataObject](_camera___metadata_object.md) | 元数据对象基础。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_Manager](_o_h___camera.md#camera_manager) [Camera_Manager](_o_h___camera.md#camera_manager) | 相机管理器对象。  | 
| typedef enum [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) | 相机错误代码的枚举。  | 
| typedef enum [Camera_Status](_o_h___camera.md#camera_status) [Camera_Status](_o_h___camera.md#camera_status) | 相机状态的枚举。  | 
| typedef enum [Camera_SceneMode](_o_h___camera.md#camera_scenemode) [Camera_SceneMode](_o_h___camera.md#camera_scenemode) | 相机模式的枚举。  | 
| typedef enum [Camera_Position](_o_h___camera.md#camera_position) [Camera_Position](_o_h___camera.md#camera_position) | 相机位置的枚举。  | 
| typedef enum [Camera_Type](_o_h___camera.md#camera_type) [Camera_Type](_o_h___camera.md#camera_type) | 相机类型的枚举。  | 
| typedef enum [Camera_Connection](_o_h___camera.md#camera_connection) [Camera_Connection](_o_h___camera.md#camera_connection) | 相机连接类型的枚举。  | 
| typedef enum [Camera_Format](_o_h___camera.md#camera_format) [Camera_Format](_o_h___camera.md#camera_format) | 相机格式类型的枚举。  | 
| typedef enum [Camera_FlashMode](_o_h___camera.md#camera_flashmode) [Camera_FlashMode](_o_h___camera.md#camera_flashmode) | 闪光模式的枚举。  | 
| typedef enum [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) | 曝光模式的枚举。  | 
| typedef enum [Camera_FocusMode](_o_h___camera.md#camera_focusmode) [Camera_FocusMode](_o_h___camera.md#camera_focusmode) | 聚焦模式的枚举。  | 
| typedef enum [Camera_FocusState](_o_h___camera.md#camera_focusstate) [Camera_FocusState](_o_h___camera.md#camera_focusstate) | 焦点状态的枚举。  | 
| typedef enum [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) | 录像防抖模式的枚举。  | 
| typedef enum [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) | 图像旋转角度的枚举。  | 
| typedef enum [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) | 图像质量等级的枚举。  | 
| typedef enum [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) | 元数据对象类型的枚举。  | 
| typedef struct [Camera_Size](_camera___size.md) [Camera_Size](_o_h___camera.md#camera_size) | 大小参数。  | 
| typedef struct [Camera_Profile](_camera___profile.md) [Camera_Profile](_o_h___camera.md#camera_profile) | 相机流的配置文件。  | 
| typedef struct [Camera_FrameRateRange](_camera___frame_rate_range.md) [Camera_FrameRateRange](_o_h___camera.md#camera_frameraterange) | 帧速率范围。  | 
| typedef struct [Camera_VideoProfile](_camera___video_profile.md) [Camera_VideoProfile](_o_h___camera.md#camera_videoprofile) | 录像配置文件。  | 
| typedef struct [Camera_OutputCapability](_camera___output_capability.md) [Camera_OutputCapability](_o_h___camera.md#camera_outputcapability) | 相机输出能力。  | 
| typedef struct [Camera_Device](_camera___device.md) [Camera_Device](_o_h___camera.md#camera_device) | 相机设备对象。  | 
| typedef struct [Camera_StatusInfo](_camera___status_info.md) [Camera_StatusInfo](_o_h___camera.md#camera_statusinfo) | 相机状态信息。  | 
| typedef struct [Camera_Point](_camera___point.md) [Camera_Point](_o_h___camera.md#camera_point) | 点参数。  | 
| typedef struct [Camera_Location](_camera___location.md) [Camera_Location](_o_h___camera.md#camera_location) | 拍照位置。  | 
| typedef struct [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) [Camera_PhotoCaptureSetting](_o_h___camera.md#camera_photocapturesetting) | 要设置的拍照捕获选项。  | 
| typedef struct [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) [Camera_FrameShutterInfo](_o_h___camera.md#camera_frameshutterinfo) | 帧快门回调信息。  | 
| typedef struct [Camera_CaptureEndInfo](_camera___capture_end_info.md) [Camera_CaptureEndInfo](_o_h___camera.md#camera_captureendinfo) | 捕获结束信息。  | 
| typedef struct [Camera_Rect](_camera___rect.md) [Camera_Rect](_o_h___camera.md#camera_rect) | 矩形定义。  | 
| typedef struct [Camera_MetadataObject](_camera___metadata_object.md) [Camera_MetadataObject](_o_h___camera.md#camera_metadataobject) | 元数据对象基础。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) {<br/>CAMERA_OK = 0,<br/>CAMERA_INVALID_ARGUMENT = 7400101,<br/>CAMERA_OPERATION_NOT_ALLOWED = 7400102,<br/>CAMERA_SESSION_NOT_CONFIG = 7400103,<br/>CAMERA_SESSION_NOT_RUNNING = 7400104,<br/>CAMERA_SESSION_CONFIG_LOCKED = 7400105,<br/>CAMERA_DEVICE_SETTING_LOCKED = 7400106,<br/>CAMERA_CONFLICT_CAMERA = 7400107,<br/>CAMERA_DEVICE_DISABLED = 7400108,<br/>CAMERA_DEVICE_PREEMPTED = 7400109,<br/>CAMERA_SERVICE_FATAL_ERROR = 7400201<br/>} | 相机错误代码的枚举。 | 
| [Camera_Status](_o_h___camera.md#camera_status) {<br/>CAMERA_STATUS_APPEAR = 0,<br/>CAMERA_STATUS_DISAPPEAR = 1,<br/>CAMERA_STATUS_AVAILABLE = 2,<br/>CAMERA_STATUS_UNAVAILABLE = 3<br/>} | 相机状态的枚举。 | 
| [Camera_SceneMode](_o_h___camera.md#camera_scenemode) { SECURE_PHOTO = 12 } | 相机模式的枚举。  | 
| [Camera_Position](_o_h___camera.md#camera_position) {<br/>CAMERA_POSITION_UNSPECIFIED = 0,<br/>CAMERA_POSITION_BACK = 1,<br/>CAMERA_POSITION_FRONT = 2<br/>} | 相机位置的枚举。 | 
| [Camera_Type](_o_h___camera.md#camera_type) {<br/>CAMERA_TYPE_DEFAULT = 0,<br/>CAMERA_TYPE_WIDE_ANGLE = 1,<br/>CAMERA_TYPE_ULTRA_WIDE = 2,<br/>CAMERA_TYPE_TELEPHOTO = 3,<br/>CAMERA_TYPE_TRUE_DEPTH = 4<br/>} | 相机类型的枚举。 | 
| [Camera_Connection](_o_h___camera.md#camera_connection) {<br/>CAMERA_CONNECTION_BUILT_IN = 0,<br/>CAMERA_CONNECTION_USB_PLUGIN = 1,<br/>CAMERA_CONNECTION_REMOTE = 2<br/>} | 相机连接类型的枚举。 | 
| [Camera_Format](_o_h___camera.md#camera_format) {<br/>CAMERA_FORMAT_RGBA_8888 = 3,<br/>CAMERA_FORMAT_YUV_420_SP = 1003,<br/>CAMERA_FORMAT_JPEG = 2000<br/>} | 相机格式类型的枚举。 | 
| [Camera_FlashMode](_o_h___camera.md#camera_flashmode) {<br/>FLASH_MODE_CLOSE = 0,<br/>FLASH_MODE_OPEN = 1,<br/>FLASH_MODE_AUTO = 2,<br/>FLASH_MODE_ALWAYS_OPEN = 3<br/>} | 闪光模式的枚举。 | 
| [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) {<br/>EXPOSURE_MODE_LOCKED = 0,<br/>EXPOSURE_MODE_AUTO = 1,<br/>EXPOSURE_MODE_CONTINUOUS_AUTO = 2<br/>} | 曝光模式的枚举。 | 
| [Camera_FocusMode](_o_h___camera.md#camera_focusmode) {<br/>FOCUS_MODE_MANUAL = 0,<br/>FOCUS_MODE_CONTINUOUS_AUTO = 1,<br/>FOCUS_MODE_AUTO = 2,<br/>FOCUS_MODE_LOCKED = 3<br/>} | 聚焦模式的枚举。 | 
| [Camera_FocusState](_o_h___camera.md#camera_focusstate) {<br/>FOCUS_STATE_SCAN = 0,<br/>FOCUS_STATE_FOCUSED = 1,<br/>FOCUS_STATE_UNFOCUSED = 2<br/>} | 焦点状态的枚举。 | 
| [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) {<br/>STABILIZATION_MODE_OFF = 0,<br/>STABILIZATION_MODE_LOW = 1,<br/>STABILIZATION_MODE_MIDDLE = 2,<br/>STABILIZATION_MODE_HIGH = 3,<br/>STABILIZATION_MODE_AUTO = 4<br/>} | 录像防抖模式的枚举。 | 
| [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) {<br/>IAMGE_ROTATION_0 = 0,<br/>IAMGE_ROTATION_90 = 90,<br/>IAMGE_ROTATION_180 = 180,<br/>IAMGE_ROTATION_270 = 270<br/>} | 图像旋转角度的枚举。 | 
| [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) {<br/>QUALITY_LEVEL_HIGH = 0,<br/>QUALITY_LEVEL_MEDIUM = 1,<br/>QUALITY_LEVEL_LOW = 2<br/>} | 图像质量等级的枚举。 | 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) {<br/>FACE_DETECTION = 0<br/>} | 元数据对象类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_Camera_GetCameraManager](_o_h___camera.md#oh_camera_getcameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*\*cameraManager) | 创建CameraManager实例。  | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_Camera_DeleteCameraManager](_o_h___camera.md#oh_camera_deletecameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager) | 删除CameraManager实例。  | 
