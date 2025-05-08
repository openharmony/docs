# camera.h


## 概述

声明相机的基本概念。

**库：** libohcamera.so

**引用文件：**&lt;ohcamera/camera.h&gt;

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Camera_Size](_camera___size.md) | 大小参数。 | 
| struct  [Camera_Profile](_camera___profile.md) | 相机流的配置文件。 | 
| struct  [Camera_FrameRateRange](_camera___frame_rate_range.md) | 帧速率范围。 | 
| struct  [Camera_VideoProfile](_camera___video_profile.md) | 录像配置文件。 | 
| struct  [Camera_OutputCapability](_camera___output_capability.md) | 相机输出能力。 | 
| struct  [Camera_Device](_camera___device.md) | 相机设备对象。 | 
| struct  [Camera_StatusInfo](_camera___status_info.md) | 相机状态信息。 | 
| struct  [Camera_Point](_camera___point.md) | 点参数。 | 
| struct  [Camera_Location](_camera___location.md) | 拍照位置。 | 
| struct  [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) | 要设置的拍照捕获选项。 | 
| struct  [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) | 帧快门回调信息。 | 
| struct  [Camera_CaptureEndInfo](_camera___capture_end_info.md) | 捕获结束信息。 | 
| struct  [Camera_Rect](_camera___rect.md) | 矩形定义。 | 
| struct  [Camera_MetadataObject](_camera___metadata_object.md) | 元数据对象基础。 | 
| struct  [Camera_TorchStatusInfo](_camera___torch_status_info.md) | 手电筒状态信息。 | 
| struct  [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) | 平滑变焦参数信息。 | 
| struct  [Camera_CaptureStartInfo](_camera___capture_start_info.md) | 拍照开始信息。 | 
| struct  [Camera_FrameShutterEndInfo](_camera___frame_shutter_end_info.md) | 拍照曝光结束信息。 | 
| struct  [Camera_ConcurrentInfo](_camera___concurrent_info.md) | 相机并发能力信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_Manager](_o_h___camera.md#camera_manager) [Camera_Manager](_o_h___camera.md#camera_manager) | 相机管理器对象。 | 
| typedef enum [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) | 相机错误代码的枚举。 | 
| typedef enum [Camera_Status](_o_h___camera.md#camera_status) [Camera_Status](_o_h___camera.md#camera_status) | 相机状态的枚举。 | 
| typedef enum [Camera_SceneMode](_o_h___camera.md#camera_scenemode) [Camera_SceneMode](_o_h___camera.md#camera_scenemode) | 相机模式的枚举。 | 
| typedef enum [Camera_Position](_o_h___camera.md#camera_position) [Camera_Position](_o_h___camera.md#camera_position) | 相机位置的枚举。 | 
| typedef enum [Camera_Type](_o_h___camera.md#camera_type) [Camera_Type](_o_h___camera.md#camera_type) | 相机类型的枚举。 | 
| typedef enum [Camera_Connection](_o_h___camera.md#camera_connection) [Camera_Connection](_o_h___camera.md#camera_connection) | 相机连接类型的枚举。 | 
| typedef enum [Camera_Format](_o_h___camera.md#camera_format) [Camera_Format](_o_h___camera.md#camera_format) | 相机格式类型的枚举。 | 
| typedef enum [Camera_FlashMode](_o_h___camera.md#camera_flashmode) [Camera_FlashMode](_o_h___camera.md#camera_flashmode) | 闪光模式的枚举。 | 
| typedef enum [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) | 曝光模式的枚举。 | 
| typedef enum [Camera_FocusMode](_o_h___camera.md#camera_focusmode) [Camera_FocusMode](_o_h___camera.md#camera_focusmode) | 聚焦模式的枚举。 | 
| typedef enum [Camera_FocusState](_o_h___camera.md#camera_focusstate) [Camera_FocusState](_o_h___camera.md#camera_focusstate) | 焦点状态的枚举。 | 
| typedef enum [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) | 录像防抖模式的枚举。 | 
| typedef enum [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) | 图像旋转角度的枚举。 | 
| typedef enum [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) | 图像质量等级的枚举。 | 
| typedef enum [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) | 元数据对象类型的枚举。 | 
| typedef enum [Camera_TorchMode](_o_h___camera.md#camera_torchmode) [Camera_TorchMode](_o_h___camera.md#camera_torchmode) | 手电筒模式的枚举。 | 
| typedef enum [Camera_SmoothZoomMode](_o_h___camera.md#camera_smoothzoommode) [Camera_SmoothZoomMode](_o_h___camera.md#camera_smoothzoommode) | 平滑变焦模式的枚举。 | 
| typedef enum [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) | 预配置照片分辨率的枚举 | 
| typedef enum [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio) [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio) | 预配置照片比例的枚举。 | 
| typedef enum [Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype) [Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype) | 远程设备类型枚举。 | 
| typedef struct [Camera_Size](_camera___size.md) [Camera_Size](_o_h___camera.md#camera_size) | 大小参数。 | 
| typedef struct [Camera_Profile](_camera___profile.md) [Camera_Profile](_o_h___camera.md#camera_profile) | 相机流的配置文件。 | 
| typedef struct [Camera_FrameRateRange](_camera___frame_rate_range.md) [Camera_FrameRateRange](_o_h___camera.md#camera_frameraterange) | 帧速率范围。 | 
| typedef struct [Camera_VideoProfile](_camera___video_profile.md) [Camera_VideoProfile](_o_h___camera.md#camera_videoprofile) | 录像配置文件。 | 
| typedef struct [Camera_OutputCapability](_camera___output_capability.md) [Camera_OutputCapability](_o_h___camera.md#camera_outputcapability) | 相机输出能力。 | 
| typedef struct [Camera_Device](_camera___device.md) [Camera_Device](_o_h___camera.md#camera_device) | 相机设备对象。 | 
| typedef struct [Camera_StatusInfo](_camera___status_info.md) [Camera_StatusInfo](_o_h___camera.md#camera_statusinfo) | 相机状态信息。 | 
| typedef struct [Camera_Point](_camera___point.md) [Camera_Point](_o_h___camera.md#camera_point) | 点参数。 | 
| typedef struct [Camera_Location](_camera___location.md) [Camera_Location](_o_h___camera.md#camera_location) | 拍照位置。 | 
| typedef struct [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) [Camera_PhotoCaptureSetting](_o_h___camera.md#camera_photocapturesetting) | 要设置的拍照捕获选项。 | 
| typedef struct [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) [Camera_FrameShutterInfo](_o_h___camera.md#camera_frameshutterinfo) | 帧快门回调信息。 | 
| typedef struct [Camera_CaptureEndInfo](_camera___capture_end_info.md) [Camera_CaptureEndInfo](_o_h___camera.md#camera_captureendinfo) | 捕获结束信息。 | 
| typedef struct [Camera_Rect](_camera___rect.md) [Camera_Rect](_o_h___camera.md#camera_rect) | 矩形定义。 | 
| typedef struct [Camera_MetadataObject](_camera___metadata_object.md) [Camera_MetadataObject](_o_h___camera.md#camera_metadataobject) | 元数据对象基础。 | 
| typedef struct [Camera_TorchStatusInfo](_camera___torch_status_info.md) [Camera_TorchStatusInfo](_o_h___camera.md#camera_torchstatusinfo) | 手电筒状态信息。 | 
| typedef struct [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) [Camera_SmoothZoomInfo](_o_h___camera.md#camera_smoothzoominfo) | 平滑变焦参数信息。 | 
| typedef struct [Camera_CaptureStartInfo](_camera___capture_start_info.md) [Camera_CaptureStartInfo](_o_h___camera.md#camera_capturestartinfo) | 拍照开始信息。 | 
| typedef struct [Camera_FrameShutterEndInfo](_camera___frame_shutter_end_info.md) [Camera_FrameShutterEndInfo](_o_h___camera.md#camera_frameshutterendinfo) | 拍照曝光结束信息。 | 
| typedef enum [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype-1) [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype) | 相机并发状态的枚举。 | 
| typedef struct [Camera_ConcurrentInfo](_camera___concurrent_info.md) [Camera_ConcurrentInfo](_o_h___camera.md#camera_concurrentinfo) | 相机并发能力信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode-1) {<br/>CAMERA_OK = 0,<br/>CAMERA_INVALID_ARGUMENT = 7400101,<br/>CAMERA_OPERATION_NOT_ALLOWED = 7400102,<br/>CAMERA_SESSION_NOT_CONFIG = 7400103,<br/>CAMERA_SESSION_NOT_RUNNING = 7400104,<br/>CAMERA_SESSION_CONFIG_LOCKED = 7400105,<br/>CAMERA_DEVICE_SETTING_LOCKED = 7400106,<br/>CAMERA_CONFLICT_CAMERA = 7400107,<br/>CAMERA_DEVICE_DISABLED = 7400108,<br/>CAMERA_DEVICE_PREEMPTED = 7400109,<br/>CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS = 7400110,<br/>CAMERA_SERVICE_FATAL_ERROR = 7400201} | 相机错误代码的枚举。 | 
| [Camera_Status](_o_h___camera.md#camera_status-1) {<br/>CAMERA_STATUS_APPEAR = 0,<br/>CAMERA_STATUS_DISAPPEAR = 1,<br/>CAMERA_STATUS_AVAILABLE = 2,<br/>CAMERA_STATUS_UNAVAILABLE = 3 } | 相机状态的枚举。 | 
| [Camera_SceneMode](_o_h___camera.md#camera_scenemode-1) {<br/>NORMAL_PHOTO = 1,<br/>NORMAL_VIDEO = 2,<br/>SECURE_PHOTO = 12 } | 相机模式的枚举。 | 
| [Camera_Position](_o_h___camera.md#camera_position-1) {<br/>CAMERA_POSITION_UNSPECIFIED = 0,<br/>CAMERA_POSITION_BACK = 1,<br/>CAMERA_POSITION_FRONT = 2 } | 相机位置的枚举。 | 
| [Camera_Type](_o_h___camera.md#camera_type-1) {<br/>CAMERA_TYPE_DEFAULT = 0,<br/>CAMERA_TYPE_WIDE_ANGLE = 1,<br/>CAMERA_TYPE_ULTRA_WIDE = 2,<br/>CAMERA_TYPE_TELEPHOTO = 3,<br/>CAMERA_TYPE_TRUE_DEPTH = 4<br/>} | 相机类型的枚举。 | 
| [Camera_Connection](_o_h___camera.md#camera_connection-1) {<br/>CAMERA_CONNECTION_BUILT_IN = 0,<br/>CAMERA_CONNECTION_USB_PLUGIN = 1,<br/>CAMERA_CONNECTION_REMOTE = 2 } | 相机连接类型的枚举。 | 
| [Camera_Format](_o_h___camera.md#camera_format-1) {<br/>CAMERA_FORMAT_RGBA_8888 = 3,<br/>CAMERA_FORMAT_YUV_420_SP = 1003,<br/>CAMERA_FORMAT_JPEG = 2000,<br/>CAMERA_FORMAT_YCBCR_P010 = 2001,<br/>CAMERA_FORMAT_YCRCB_P010 = 2002<br/>} | 相机格式类型的枚举。 | 
| [Camera_FlashMode](_o_h___camera.md#camera_flashmode-1) {<br/>FLASH_MODE_CLOSE = 0,<br/>FLASH_MODE_OPEN = 1,<br/>FLASH_MODE_AUTO = 2,<br/>FLASH_MODE_ALWAYS_OPEN = 3 } | 闪光模式的枚举。 | 
| [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode-1) {<br/>EXPOSURE_MODE_LOCKED = 0,<br/>EXPOSURE_MODE_AUTO = 1,<br/>EXPOSURE_MODE_CONTINUOUS_AUTO = 2 } | 曝光模式的枚举。 | 
| [Camera_FocusMode](_o_h___camera.md#camera_focusmode-1) {<br/>FOCUS_MODE_MANUAL = 0,<br/>FOCUS_MODE_CONTINUOUS_AUTO = 1,<br/>FOCUS_MODE_AUTO = 2,<br/>FOCUS_MODE_LOCKED = 3 } | 聚焦模式的枚举。 | 
| [Camera_FocusState](_o_h___camera.md#camera_focusstate-1) {<br/>FOCUS_STATE_SCAN = 0,<br/>FOCUS_STATE_FOCUSED = 1,<br/>FOCUS_STATE_UNFOCUSED = 2 } | 焦点状态的枚举。 | 
| [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode-1) {<br/>STABILIZATION_MODE_OFF = 0,<br/>STABILIZATION_MODE_LOW = 1,<br/>STABILIZATION_MODE_MIDDLE = 2,<br/>STABILIZATION_MODE_HIGH = 3,<br/>STABILIZATION_MODE_AUTO = 4<br/>} | 录像防抖模式的枚举。 | 
| [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation-1) {<br/>IAMGE_ROTATION_0 = 0,<br/>IAMGE_ROTATION_90 = 90,<br/>IAMGE_ROTATION_180 = 180,<br/>IAMGE_ROTATION_270 = 270 } | 图像旋转角度的枚举。 | 
| [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel-1) {<br/>QUALITY_LEVEL_HIGH = 0,<br/>QUALITY_LEVEL_MEDIUM = 1,<br/>QUALITY_LEVEL_LOW = 2 } | 图像质量等级的枚举。 | 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype-1) { FACE_DETECTION = 0 } | 元数据对象类型的枚举。 | 
| [Camera_TorchMode](_o_h___camera.md#camera_torchmode-1) { OFF = 0, ON = 1, AUTO = 2 } | 手电筒模式的枚举。 | 
| [Camera_SmoothZoomMode](_o_h___camera.md#camera_smoothzoommode-1) { NORMAL = 0 } | 平滑变焦模式的枚举。 | 
| [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype-1) {<br/>PRECONFIG_720P = 0,<br/>PRECONFIG_1080P = 1,<br/>PRECONFIG_4K = 2,<br/>PRECONFIG_HIGH_QUALITY = 3 } | 预配置照片分辨率的枚举。 | 
| [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio-1) {<br/>PRECONFIG_RATIO_1_1 = 0,<br/>PRECONFIG_RATIO_4_3 = 1,<br/>PRECONFIG_RATIO_16_9 = 2 } | 预配置照片比例的枚举。 | 
| [Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype) {<br/>HOST_DEVICE_TYPE_UNKNOWN_TYPE = 0,<br/>HOST_DEVICE_TYPE_PHONE = 0x0E,<br/>HOST_DEVICE_TYPE_TABLET = 0x11 } | 远程设备类型枚举。 | 
| [Camera_QualityPrioritization](_o_h___camera.md#camera_qualityprioritization) { [HIGH_QUALITY](_o_h___camera.md) = 0, [POWER_BALANCE](_o_h___camera.md) = 1 } | 录像质量优先级的枚举。 | 
| [Camera_ConcurrentType](_o_h___camera.md#camera_concurrenttype-1) {<br/>CAMERA_CONCURRENT_TYPE_LIMITED_CAPABILITY = 0,<br/>CAMERA_CONCURRENT_TYPE_FULL_CAPABILITY = 1 } | 相机并发状态的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_Camera_GetCameraManager](_o_h___camera.md#oh_camera_getcameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*\*cameraManager) | 创建CameraManager实例。 | 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_Camera_DeleteCameraManager](_o_h___camera.md#oh_camera_deletecameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager) | 删除CameraManager实例。 | 
