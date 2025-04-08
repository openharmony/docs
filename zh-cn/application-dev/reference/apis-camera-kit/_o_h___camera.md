# OH_Camera


## 概述

为相机模块提供C接口的定义。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [相机管理](../../media/camera/native-camera-device-management.md)
- [设备输入](../../media/camera/native-camera-device-input.md)
- [会话管理](../../media/camera/native-camera-session-management.md)
- [预览](../../media/camera/native-camera-preview.md)
- [预览流二次处理](../../media/camera/native-camera-preview-imageReceiver.md)
- [拍照](../../media/camera/native-camera-shooting.md)
- [分段式拍照](../../media/camera/native-camera-deferred-capture.md)
- [录像](../../media/camera/native-camera-recording.md)
- [元数据](../../media/camera/native-camera-metadata.md)
- [手电筒使用](../../media/camera/native-camera-torch-use.md)
<!--RP1--><!--RP1End-->

**系统能力：** SystemCapability.Multimedia.Camera.Core

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [camera.h](camera_8h.md) | 声明相机的基本概念。 | 
| [camera_device.h](camera__device_8h.md) | 声明相机的基本概念。 | 
| [camera_input.h](camera__input_8h.md) | 声明相机输入概念。 | 
| [camera_manager.h](camera__manager_8h.md) | 声明相机管理器的概念。 | 
| [capture_session.h](capture__session_8h.md) | 声明捕获会话概念。 | 
| [metadata_output.h](metadata__output_8h.md) | 声明元数据输出概念。 | 
| [photo_native.h](photo__native_8h.md) | 声明相机照片概念。 | 
| [photo_output.h](photo__output_8h.md) | 声明拍照输出概念。 | 
| [preview_output.h](preview__output_8h.md) | 声明预览输出概念。 | 
| [video_output.h](video__output_8h.md) | 声明录像输出概念。 | 


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
| struct  [CameraInput_Callbacks](_camera_input___callbacks.md) | 相机输入错误事件的回调。 | 
| struct  [CameraManager_Callbacks](_camera_manager___callbacks.md) | 相机设备状态的回调。 | 
| struct  [CaptureSession_Callbacks](_capture_session___callbacks.md) | 捕获会话的回调。 | 
| struct  [MetadataOutput_Callbacks](_metadata_output___callbacks.md) | 元数据输出的回调。 | 
| struct  [PhotoOutput_Callbacks](_photo_output___callbacks.md) | 拍照输出的回调。 | 
| struct  [PreviewOutput_Callbacks](_preview_output___callbacks.md) | 用于预览输出的回调。 | 
| struct  [VideoOutput_Callbacks](_video_output___callbacks.md) | 用于录像输出的回调。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Camera_Manager](#camera_manager) [Camera_Manager](#camera_manager) | 相机管理器对象。 | 
| typedef enum [Camera_ErrorCode](#camera_errorcode) [Camera_ErrorCode](#camera_errorcode) | 相机错误代码的枚举。 | 
| typedef enum [Camera_Status](#camera_status) [Camera_Status](#camera_status) | 相机状态的枚举。 | 
| typedef enum [Camera_SceneMode](#camera_scenemode) [Camera_SceneMode](#camera_scenemode) | 相机模式的枚举。 | 
| typedef enum [Camera_Position](#camera_position) [Camera_Position](#camera_position) | 相机位置的枚举。 | 
| typedef enum [Camera_Type](#camera_type) [Camera_Type](#camera_type) | 相机类型的枚举。 | 
| typedef enum [Camera_Connection](#camera_connection) [Camera_Connection](#camera_connection) | 相机连接类型的枚举。 | 
| typedef enum [Camera_Format](#camera_format) [Camera_Format](#camera_format) | 相机格式类型的枚举。 | 
| typedef enum [Camera_FlashMode](#camera_flashmode) [Camera_FlashMode](#camera_flashmode) | 闪光模式的枚举。 | 
| typedef enum [Camera_ExposureMode](#camera_exposuremode) [Camera_ExposureMode](#camera_exposuremode) | 曝光模式的枚举。 | 
| typedef enum [Camera_FocusMode](#camera_focusmode) [Camera_FocusMode](#camera_focusmode) | 聚焦模式的枚举。 | 
| typedef enum [Camera_FocusState](#camera_focusstate) [Camera_FocusState](#camera_focusstate) | 焦点状态的枚举。 | 
| typedef enum [Camera_VideoStabilizationMode](#camera_videostabilizationmode) [Camera_VideoStabilizationMode](#camera_videostabilizationmode) | 录像防抖模式的枚举。 | 
| typedef enum [Camera_ImageRotation](#camera_imagerotation) [Camera_ImageRotation](#camera_imagerotation) | 图像旋转角度的枚举。 | 
| typedef enum [Camera_QualityLevel](#camera_qualitylevel) [Camera_QualityLevel](#camera_qualitylevel) | 图像质量等级的枚举。 | 
| typedef enum [Camera_QualityPrioritization](#camera_qualityprioritization) [Camera_QualityPrioritization](#camera_qualitylevel) | 录像质量优先级的枚举。 | 
| typedef enum [Camera_MetadataObjectType](#camera_metadataobjecttype) [Camera_MetadataObjectType](#camera_metadataobjecttype) | 元数据对象类型的枚举。 | 
| typedef enum [Camera_TorchMode](#camera_torchmode) [Camera_TorchMode](#camera_torchmode) | 手电筒模式的枚举。 | 
| typedef enum [Camera_SmoothZoomMode](#camera_smoothzoommode) [Camera_SmoothZoomMode](#camera_smoothzoommode) | 平滑变焦模式的枚举。 | 
| typedef enum [Camera_PreconfigType](#camera_preconfigtype) [Camera_PreconfigType](#camera_preconfigtype) | 预配置照片分辨率的枚举 | 
| typedef enum [Camera_PreconfigRatio](#camera_preconfigratio) [Camera_PreconfigRatio](#camera_preconfigratio) | 预配置照片比例的枚举。 | 
| typedef enum [Camera_HostDeviceType](#camera_hostdevicetype) [Camera_HostDeviceType](#camera_hostdevicetype) | 远程设备类型枚举。 | 
| typedef struct [Camera_Size](_camera___size.md) [Camera_Size](#camera_size) | 大小参数。 | 
| typedef struct [Camera_Profile](_camera___profile.md) [Camera_Profile](#camera_profile) | 相机流的配置文件。 | 
| typedef struct [Camera_FrameRateRange](_camera___frame_rate_range.md) [Camera_FrameRateRange](#camera_frameraterange) | 帧速率范围。 | 
| typedef struct [Camera_VideoProfile](_camera___video_profile.md) [Camera_VideoProfile](#camera_videoprofile) | 录像配置文件。 | 
| typedef struct [Camera_OutputCapability](_camera___output_capability.md) [Camera_OutputCapability](#camera_outputcapability) | 相机输出能力。 | 
| typedef struct [Camera_Device](_camera___device.md) [Camera_Device](#camera_device) | 相机设备对象。 | 
| typedef struct [Camera_StatusInfo](_camera___status_info.md) [Camera_StatusInfo](#camera_statusinfo) | 相机状态信息。 | 
| typedef struct [Camera_Point](_camera___point.md) [Camera_Point](#camera_point) | 点参数。 | 
| typedef struct [Camera_Location](_camera___location.md) [Camera_Location](#camera_location) | 拍照位置。 | 
| typedef struct [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) [Camera_PhotoCaptureSetting](#camera_photocapturesetting) | 要设置的拍照捕获选项。 | 
| typedef struct [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) [Camera_FrameShutterInfo](#camera_frameshutterinfo) | 帧快门回调信息。 | 
| typedef struct [Camera_CaptureEndInfo](_camera___capture_end_info.md) [Camera_CaptureEndInfo](#camera_captureendinfo) | 捕获结束信息。 | 
| typedef struct [Camera_Rect](_camera___rect.md) [Camera_Rect](#camera_rect) | 矩形定义。 | 
| typedef struct [Camera_MetadataObject](_camera___metadata_object.md) [Camera_MetadataObject](#camera_metadataobject) | 元数据对象基础。 | 
| typedef struct [Camera_TorchStatusInfo](_camera___torch_status_info.md) [Camera_TorchStatusInfo](#camera_torchstatusinfo) | 手电筒状态信息。 | 
| typedef struct [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) [Camera_SmoothZoomInfo](#camera_smoothzoominfo) | 平滑变焦参数信息。 | 
| typedef struct [Camera_CaptureStartInfo](_camera___capture_start_info.md) [Camera_CaptureStartInfo](#camera_capturestartinfo) | 拍照开始信息。 | 
| typedef struct [Camera_FrameShutterEndInfo](_camera___frame_shutter_end_info.md) [Camera_FrameShutterEndInfo](#camera_frameshutterendinfo) | 拍照曝光结束信息。 | 
| typedef struct [Camera_Input](#camera_input) [Camera_Input](#camera_input) | 相机输入对象。 | 
| typedef void(\* [OH_CameraInput_OnError](#oh_camerainput_onerror)) (const [Camera_Input](#camera_input) \*cameraInput, [Camera_ErrorCode](#camera_errorcode) errorCode) | 在[CameraInput_Callbacks](_camera_input___callbacks.md)中被调用的相机输入错误回调。 | 
| typedef struct [CameraInput_Callbacks](_camera_input___callbacks.md) [CameraInput_Callbacks](#camerainput_callbacks) | 相机输入错误事件的回调。 | 
| typedef void(\* [OH_CameraManager_StatusCallback](#oh_cameramanager_statuscallback)) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_StatusInfo](_camera___status_info.md) \*status) | 在[CameraManager_Callbacks](_camera_manager___callbacks.md)中被调用的相机管理器状态回调。 | 
| typedef void(\* [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback)) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_TorchStatusInfo](_camera___torch_status_info.md) \*status) | 手电筒状态变化回调。 | 
| typedef struct [CameraManager_Callbacks](_camera_manager___callbacks.md) [CameraManager_Callbacks](#cameramanager_callbacks) | 相机设备状态的回调。 | 
| typedef struct [Camera_CaptureSession](#camera_capturesession) [Camera_CaptureSession](#camera_capturesession) | 捕获会话对象。 | 
| typedef void(\* [OH_CaptureSession_OnFocusStateChange](#oh_capturesession_onfocusstatechange)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusState](#camera_focusstate) focusState) | 在[CaptureSession_Callbacks](_capture_session___callbacks.md)中被调用的捕获会话焦点状态回调。 | 
| typedef void(\* [OH_CaptureSession_OnError](#oh_capturesession_onerror)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ErrorCode](#camera_errorcode) errorCode) | 在[CaptureSession_Callbacks](_capture_session___callbacks.md)中被调用的捕获会话错误回调。 | 
| typedef void(\* [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) \*smoothZoomInfo) | 拍照会话平滑变焦信息回调，触发平滑变焦后该回调会返回。 | 
| typedef struct [CaptureSession_Callbacks](_capture_session___callbacks.md) [CaptureSession_Callbacks](#capturesession_callbacks) | 捕获会话的回调。 | 
| typedef struct [Camera_MetadataOutput](#camera_metadataoutput) [Camera_MetadataOutput](#camera_metadataoutput) | 元数据输出对象。 | 
| typedef void(\* [OH_MetadataOutput_OnMetadataObjectAvailable](#oh_metadataoutput_onmetadataobjectavailable)) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [Camera_MetadataObject](_camera___metadata_object.md) \*metadataObject, uint32_t size) | 在[MetadataOutput_Callbacks](_metadata_output___callbacks.md)中被调用的元数据输出元数据对象可用回调。 | 
| typedef void(\* [OH_MetadataOutput_OnError](#oh_metadataoutput_onerror)) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | 在[MetadataOutput_Callbacks](_metadata_output___callbacks.md)中被调用的元数据输出错误回调。 | 
| typedef struct [MetadataOutput_Callbacks](_metadata_output___callbacks.md) [MetadataOutput_Callbacks](#metadataoutput_callbacks) | 元数据输出的回调。 | 
| typedef struct [OH_PhotoNative](#oh_photonative) [OH_PhotoNative](#oh_photonative) | 相机照片对象。 | 
| typedef struct [Camera_PhotoOutput](#camera_photooutput) [Camera_PhotoOutput](#camera_photooutput) | 拍照输出对象。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameStart](#oh_photooutput_onframestart)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧启动回调。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameShutter](#oh_photooutput_onframeshutter)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*info) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧快门回调。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameEnd](#oh_photooutput_onframeend)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, int32_t frameCount) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧结束回调。 | 
| typedef void(\* [OH_PhotoOutput_OnError](#oh_photooutput_onerror)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | 在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出错误回调。 | 
| typedef void(\* [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, int32_t frameCount) | 拍照结束回调。 | 
| typedef void(\* [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_CaptureStartInfo](_camera___capture_start_info.md) \*Info) | 拍照开始回调。 | 
| typedef void(\* [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*Info) | 拍照曝光结束回调。 | 
| typedef void(\* [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | 拍照准备就绪回调。收到回调后，可以继续进行下一次拍照。 | 
| typedef void(\* [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, int64_t duration) | 预计拍照时间回调。 | 
| typedef void(\* [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoNative](#oh_photonative) \*photo) | 照片输出可用高分辨率图像回调。 | 
| typedef void(\* [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, OH_MediaAsset \*photoAsset) | 输出照片资源可用回调。 | 
| typedef struct [PhotoOutput_Callbacks](_photo_output___callbacks.md) [PhotoOutput_Callbacks](#photooutput_callbacks) | 拍照输出的回调。 | 
| typedef struct [Camera_PreviewOutput](#camera_previewoutput) [Camera_PreviewOutput](#camera_previewoutput) | 预览输出对象。 | 
| typedef void(\* [OH_PreviewOutput_OnFrameStart](#oh_previewoutput_onframestart)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | 在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧开始回调。 | 
| typedef void(\* [OH_PreviewOutput_OnFrameEnd](#oh_previewoutput_onframeend)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, int32_t frameCount) | 在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧结束回调。 | 
| typedef void(\* [OH_PreviewOutput_OnError](#oh_previewoutput_onerror)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | 在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧错误回调。 | 
| typedef struct [PreviewOutput_Callbacks](_preview_output___callbacks.md) [PreviewOutput_Callbacks](#previewoutput_callbacks) | 用于预览输出的回调。 | 
| typedef struct [Camera_VideoOutput](#camera_videooutput) [Camera_VideoOutput](#camera_videooutput) | 录像输出对象。 | 
| typedef void(\* [OH_VideoOutput_OnFrameStart](#oh_videooutput_onframestart)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧开始回调。 | 
| typedef void(\* [OH_VideoOutput_OnFrameEnd](#oh_videooutput_onframeend)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, int32_t frameCount) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧结束回调。 | 
| typedef void(\* [OH_VideoOutput_OnError](#oh_videooutput_onerror)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | 在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出错误回调。 | 
| typedef struct [VideoOutput_Callbacks](_video_output___callbacks.md) [VideoOutput_Callbacks](#videooutput_callbacks) | 用于录像输出的回调。 | 
| typedef struct [Camera_QualityPrioritization ](#camera_qualityprioritization) [Camera_QualityPrioritization](#camera_qualityprioritization) | 录像质量优先级。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](#camera_errorcode) {<br/>CAMERA_OK = 0,<br/>CAMERA_INVALID_ARGUMENT = 7400101,<br/>CAMERA_OPERATION_NOT_ALLOWED = 7400102,<br/>CAMERA_SESSION_NOT_CONFIG = 7400103,<br/>CAMERA_SESSION_NOT_RUNNING = 7400104,<br/>CAMERA_SESSION_CONFIG_LOCKED = 7400105,<br/>CAMERA_DEVICE_SETTING_LOCKED = 7400106,<br/>CAMERA_CONFLICT_CAMERA = 7400107,<br/>CAMERA_DEVICE_DISABLED = 7400108,<br/>CAMERA_DEVICE_PREEMPTED = 7400109,<br/>CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS = 7400110,<br/>CAMERA_SERVICE_FATAL_ERROR = 7400201} | 相机错误代码的枚举。 | 
| [Camera_Status](#camera_status) {<br/>CAMERA_STATUS_APPEAR = 0,<br/>CAMERA_STATUS_DISAPPEAR = 1,<br/>CAMERA_STATUS_AVAILABLE = 2,<br/>CAMERA_STATUS_UNAVAILABLE = 3 } | 相机状态的枚举。 | 
| [Camera_SceneMode](#camera_scenemode) {<br/>NORMAL_PHOTO = 1,<br/>NORMAL_VIDEO = 2,<br/>SECURE_PHOTO = 12 } | 相机模式的枚举。 | 
| [Camera_Position](#camera_position) {<br/>CAMERA_POSITION_UNSPECIFIED = 0,<br/>CAMERA_POSITION_BACK = 1,<br/>CAMERA_POSITION_FRONT = 2 } | 相机位置的枚举。 | 
| [Camera_Type](#camera_type) {<br/>CAMERA_TYPE_DEFAULT = 0,<br/>CAMERA_TYPE_WIDE_ANGLE = 1,<br/>CAMERA_TYPE_ULTRA_WIDE = 2,<br/>CAMERA_TYPE_TELEPHOTO = 3,<br/>CAMERA_TYPE_TRUE_DEPTH = 4<br/>} | 相机类型的枚举。 | 
| [Camera_Connection](#camera_connection) {<br/>CAMERA_CONNECTION_BUILT_IN = 0,<br/>CAMERA_CONNECTION_USB_PLUGIN = 1,<br/>CAMERA_CONNECTION_REMOTE = 2 } | 相机连接类型的枚举。 | 
| [Camera_Format](#camera_format) {<br/>CAMERA_FORMAT_RGBA_8888 = 3,<br/>CAMERA_FORMAT_YUV_420_SP = 1003,<br/>CAMERA_FORMAT_JPEG = 2000,<br/>CAMERA_FORMAT_YCBCR_P010 = 2001,<br/>CAMERA_FORMAT_YCRCB_P010 = 2002<br/>} | 相机格式类型的枚举。 | 
| [Camera_FlashMode](#camera_flashmode) {<br/>FLASH_MODE_CLOSE = 0,<br/>FLASH_MODE_OPEN = 1,<br/>FLASH_MODE_AUTO = 2,<br/>FLASH_MODE_ALWAYS_OPEN = 3 } | 闪光模式的枚举。 | 
| [Camera_ExposureMode](#camera_exposuremode) {<br/>EXPOSURE_MODE_LOCKED = 0,<br/>EXPOSURE_MODE_AUTO = 1,<br/>EXPOSURE_MODE_CONTINUOUS_AUTO = 2 } | 曝光模式的枚举。 | 
| [Camera_FocusMode](#camera_focusmode) {<br/>FOCUS_MODE_MANUAL = 0,<br/>FOCUS_MODE_CONTINUOUS_AUTO = 1,<br/>FOCUS_MODE_AUTO = 2,<br/>FOCUS_MODE_LOCKED = 3 } | 聚焦模式的枚举。 | 
| [Camera_FocusState](#camera_focusstate) {<br/>FOCUS_STATE_SCAN = 0,<br/>FOCUS_STATE_FOCUSED = 1,<br/>FOCUS_STATE_UNFOCUSED = 2 } | 焦点状态的枚举。 | 
| [Camera_VideoStabilizationMode](#camera_videostabilizationmode) {<br/>STABILIZATION_MODE_OFF = 0,<br/>STABILIZATION_MODE_LOW = 1,<br/>STABILIZATION_MODE_MIDDLE = 2,<br/>STABILIZATION_MODE_HIGH = 3,<br/>STABILIZATION_MODE_AUTO = 4<br/>} | 录像防抖模式的枚举。 | 
| [Camera_ImageRotation](#camera_imagerotation) {<br/>IAMGE_ROTATION_0 = 0,<br/>IAMGE_ROTATION_90 = 90,<br/>IAMGE_ROTATION_180 = 180,<br/>IAMGE_ROTATION_270 = 270 } | 图像旋转角度的枚举。 | 
| [Camera_QualityLevel](#camera_qualitylevel) {<br/>QUALITY_LEVEL_HIGH = 0,<br/>QUALITY_LEVEL_MEDIUM = 1,<br/>QUALITY_LEVEL_LOW = 2 } | 图像质量等级的枚举。 | 
| [Camera_HostDeviceType](#camera_hostdevicetype) {<br/>HOST_DEVICE_TYPE_UNKNOWN_TYPE = 0,<br/>HOST_DEVICE_TYPE_PHONE = 0x0E,<br/>HOST_DEVICE_TYPE_TABLET = 0x11 } | 远程设备类型枚举。 | 
| [Camera_QualityPrioritization](#camera_qualityprioritization) {<br/>HIGH_QUALITY  = 0,<br/>POWER_BALANCE  = 1} | 录像质量优先级的枚举。 | 
| [Camera_MetadataObjectType](#camera_metadataobjecttype) { FACE_DETECTION = 0 } | 元数据对象类型的枚举。 | 
| [Camera_TorchMode](#camera_torchmode) { OFF = 0, ON = 1, AUTO = 2 } | 手电筒模式的枚举。 | 
| [Camera_SmoothZoomMode](#camera_smoothzoommode) { NORMAL = 0 } | 平滑变焦模式的枚举。 | 
| [Camera_PreconfigType](#camera_preconfigtype) {<br/>PRECONFIG_720P = 0,<br/>PRECONFIG_1080P = 1,<br/>PRECONFIG_4K = 2,<br/>PRECONFIG_HIGH_QUALITY = 3 } | 预配置照片分辨率的枚举 | 
| [Camera_PreconfigRatio](#camera_preconfigratio) {<br/>PRECONFIG_RATIO_1_1 = 0,<br/>PRECONFIG_RATIO_4_3 = 1,<br/>PRECONFIG_RATIO_16_9 = 2 } | 预配置照片比例的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Camera_ErrorCode](#camera_errorcode) [OH_Camera_GetCameraManager](#oh_camera_getcameramanager) ([Camera_Manager](#camera_manager) \*\*cameraManager) | 创建CameraManager实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_Camera_DeleteCameraManager](#oh_camera_deletecameramanager) ([Camera_Manager](#camera_manager) \*cameraManager) | 删除CameraManager实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraDevice_GetCameraOrientation](#oh_cameradevice_getcameraorientation) ([Camera_Device](_camera___device.md) \*camera, uint32_t \*orientation) | 获取相机设备的传感器方向属性。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_RegisterCallback](#oh_camerainput_registercallback) ([Camera_Input](#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | 注册相机输入更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_UnregisterCallback](#oh_camerainput_unregistercallback) ([Camera_Input](#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | 注销相机输入更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Open](#oh_camerainput_open) ([Camera_Input](#camera_input) \*cameraInput) | 打开相机。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_OpenSecureCamera](#oh_camerainput_opensecurecamera) ([Camera_Input](#camera_input) \*cameraInput, uint64_t \*secureSeqId) | 打开安全相机。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Close](#oh_camerainput_close) ([Camera_Input](#camera_input) \*cameraInput) | 关闭相机。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Release](#oh_camerainput_release) ([Camera_Input](#camera_input) \*cameraInput) | 和[OH_CameraInput_Close](#oh_camerainput_close)只需要调用其中一个，调用之后无须再调用[OH_CameraInput_Close](#oh_camerainput_close)。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_RegisterCallback](#oh_cameramanager_registercallback) ([Camera_Manager](#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | 注册相机状态更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_UnregisterCallback](#oh_cameramanager_unregistercallback) ([Camera_Manager](#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | 注销相机状态更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_RegisterTorchStatusCallback](#oh_cameramanager_registertorchstatuscallback) ([Camera_Manager](#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback) torchStatusCallback) | 注册手电筒状态变更事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_UnregisterTorchStatusCallback](#oh_cameramanager_unregistertorchstatuscallback) ([Camera_Manager](#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback) torchStatusCallback) | 注销手电筒状态变更事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameras](#oh_cameramanager_getsupportedcameras) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*\*cameras, uint32_t \*size) | 获取支持相机的描述。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSupportedCameras](#oh_cameramanager_deletesupportedcameras) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*cameras, uint32_t size) | 删除支持的相机。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapability](#oh_cameramanager_getsupportedcameraoutputcapability) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | 查询指定相机在指定模式下支持的输出能力。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode](#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](#camera_scenemode) sceneMode, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | 查询指定相机在指定模式下支持的输出能力。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSupportedCameraOutputCapability](#oh_cameramanager_deletesupportedcameraoutputcapability) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_OutputCapability](_camera___output_capability.md) \*cameraOutputCapability) | 删除支持的输出功能。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_IsCameraMuted](#oh_cameramanager_iscameramuted) ([Camera_Manager](#camera_manager) \*cameraManager, bool \*isCameraMuted) | 确定相机是否静音。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCaptureSession](#oh_cameramanager_createcapturesession) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_CaptureSession](#camera_capturesession) \*\*captureSession) | 创建捕获会话实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCameraInput](#oh_cameramanager_createcamerainput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_Input](#camera_input) \*\*cameraInput) | 创建相机输入实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCameraInput_WithPositionAndType](#oh_cameramanager_createcamerainput_withpositionandtype) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Position](#camera_position) position, [Camera_Type](#camera_type) type, [Camera_Input](#camera_input) \*\*cameraInput) | 创建具有位置和类型的相机输入实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePreviewOutput](#oh_cameramanager_createpreviewoutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PreviewOutput](#camera_previewoutput) \*\*previewOutput) | 创建预览输出实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePreviewOutputUsedInPreconfig](#oh_cameramanager_createpreviewoutputusedinpreconfig) ([Camera_Manager](#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PreviewOutput](#camera_previewoutput) \*\*previewOutput) | 创建在预配置流中使用的预览输出实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePhotoOutput](#oh_cameramanager_createphotooutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PhotoOutput](#camera_photooutput) \*\*photoOutput) | 创建一个拍照输出实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePhotoOutputUsedInPreconfig](#oh_cameramanager_createphotooutputusedinpreconfig) ([Camera_Manager](#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PhotoOutput](#camera_photooutput) \*\*photoOutput) | 创建在预配置流中使用的照片输出实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePhotoOutputWithoutSurface](#oh_cameramanager_createphotooutputwithoutsurface) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, [Camera_PhotoOutput](#camera_photooutput) \*\*photoOutput) | 创建照片输出实例，调用此函数不需要surfaceId。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateVideoOutput](#oh_cameramanager_createvideooutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_VideoProfile](_camera___video_profile.md) \*profile, const char \*surfaceId, [Camera_VideoOutput](#camera_videooutput) \*\*videoOutput) | 创建一个录像输出实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateVideoOutputUsedInPreconfig](#oh_cameramanager_createvideooutputusedinpreconfig) ([Camera_Manager](#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_VideoOutput](#camera_videooutput) \*\*videoOutput) | 创建在预配置流中使用的视频输出实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateMetadataOutput](#oh_cameramanager_createmetadataoutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_MetadataObjectType](#camera_metadataobjecttype) \*profile, [Camera_MetadataOutput](#camera_metadataoutput) \*\*metadataOutput) | 创建元数据输出实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedSceneModes](#oh_cameramanager_getsupportedscenemodes) ([Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](#camera_scenemode) \*\*sceneModes, uint32_t \*size) | 获取特定相机支持的场景模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSceneModes](#oh_cameramanager_deletescenemodes) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_SceneMode](#camera_scenemode) \*sceneModes) | 删除场景模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_IsTorchSupported](#oh_cameramanager_istorchsupported) ([Camera_Manager](#camera_manager) \*cameraManager, bool \*isTorchSupported) | 检查设备是否支持手电筒。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_IsTorchSupportedByTorchMode](#oh_cameramanager_istorchsupportedbytorchmode) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_TorchMode](#camera_torchmode) torchMode, bool \*isTorchSupported) | 检查设备是否支持指定的手电筒模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_SetTorchMode](#oh_cameramanager_settorchmode) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_TorchMode](#camera_torchmode) torchMode) | 设置相机手电筒模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RegisterCallback](#oh_capturesession_registercallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | 注册捕获会话事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_UnregisterCallback](#oh_capturesession_unregistercallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | 注销捕获会话事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RegisterSmoothZoomInfoCallback](#oh_capturesession_registersmoothzoominfocallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback) | 注册平滑变焦信息事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_UnregisterSmoothZoomInfoCallback](#oh_capturesession_unregistersmoothzoominfocallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback) | 注销平滑变焦信息事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetSessionMode](#oh_capturesession_setsessionmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_SceneMode](#camera_scenemode) sceneMode) | 设置会话模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddSecureOutput](#oh_capturesession_addsecureoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | 把其中一条PreviewOutput标记成安全输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_BeginConfig](#oh_capturesession_beginconfig) ([Camera_CaptureSession](#camera_capturesession) \*session) | 开始捕获会话配置。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CommitConfig](#oh_capturesession_commitconfig) ([Camera_CaptureSession](#camera_capturesession) \*session) | 提交捕获会话配置。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddInput](#oh_capturesession_addinput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Input](#camera_input) \*cameraInput) | 添加相机输入。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemoveInput](#oh_capturesession_removeinput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Input](#camera_input) \*cameraInput) | 删除相机输入。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddPreviewOutput](#oh_capturesession_addpreviewoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | 添加预览输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemovePreviewOutput](#oh_capturesession_removepreviewoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | 删除预览输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddPhotoOutput](#oh_capturesession_addphotooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | 添加拍照输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemovePhotoOutput](#oh_capturesession_removephotooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | 删除拍照输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddVideoOutput](#oh_capturesession_addvideooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoOutput](#camera_videooutput) \*videoOutput) | 添加录像输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemoveVideoOutput](#oh_capturesession_removevideooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoOutput](#camera_videooutput) \*videoOutput) | 删除录像输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddMetadataOutput](#oh_capturesession_addmetadataoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | 添加元数据输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemoveMetadataOutput](#oh_capturesession_removemetadataoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | 删除元数据输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Start](#oh_capturesession_start) ([Camera_CaptureSession](#camera_capturesession) \*session) | 启动捕获会话。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Stop](#oh_capturesession_stop) ([Camera_CaptureSession](#camera_capturesession) \*session) | 停止捕获会话。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Release](#oh_capturesession_release) ([Camera_CaptureSession](#camera_capturesession) \*session) | 释放捕获会话。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_HasFlash](#oh_capturesession_hasflash) ([Camera_CaptureSession](#camera_capturesession) \*session, bool \*hasFlash) | 检查设备是否有闪光灯。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsFlashModeSupported](#oh_capturesession_isflashmodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FlashMode](#camera_flashmode) flashMode, bool \*isSupported) | 检查是否支持指定的闪光灯模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFlashMode](#oh_capturesession_getflashmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FlashMode](#camera_flashmode) \*flashMode) | 获取当前闪光灯模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetFlashMode](#oh_capturesession_setflashmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FlashMode](#camera_flashmode) flashMode) | 设置闪光灯模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsExposureModeSupported](#oh_capturesession_isexposuremodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ExposureMode](#camera_exposuremode) exposureMode, bool \*isSupported) | 检查是否支持指定的曝光模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureMode](#oh_capturesession_getexposuremode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ExposureMode](#camera_exposuremode) \*exposureMode) | 获取当前曝光模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetExposureMode](#oh_capturesession_setexposuremode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ExposureMode](#camera_exposuremode) exposureMode) | 设置曝光模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetMeteringPoint](#oh_capturesession_getmeteringpoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) \*point) | 获取当前测量点。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetMeteringPoint](#oh_capturesession_setmeteringpoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) point) | 设置计量区域的中心点。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureBiasRange](#oh_capturesession_getexposurebiasrange) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*minExposureBias, float \*maxExposureBias, float \*step) | 查询曝光补偿范围。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetExposureBias](#oh_capturesession_setexposurebias) ([Camera_CaptureSession](#camera_capturesession) \*session, float exposureBias) | 设置曝光补偿。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureBias](#oh_capturesession_getexposurebias) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*exposureBias) | 获取当前曝光补偿。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsFocusModeSupported](#oh_capturesession_isfocusmodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusMode](#camera_focusmode) focusMode, bool \*isSupported) | 检查是否支持指定的聚焦模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFocusMode](#oh_capturesession_getfocusmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusMode](#camera_focusmode) \*focusMode) | 获取当前聚焦模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetFocusMode](#oh_capturesession_setfocusmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusMode](#camera_focusmode) focusMode) | 设置聚焦模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFocusPoint](#oh_capturesession_getfocuspoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) \*focusPoint) | 获取当前焦点。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetFocusPoint](#oh_capturesession_setfocuspoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) focusPoint) | 设置焦点。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetZoomRatioRange](#oh_capturesession_getzoomratiorange) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*minZoom, float \*maxZoom) | 获取所有支持的缩放比例范围。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetZoomRatio](#oh_capturesession_getzoomratio) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*zoom) | 获取当前缩放比例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetZoomRatio](#oh_capturesession_setzoomratio) ([Camera_CaptureSession](#camera_capturesession) \*session, float zoom) | 设置缩放比例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsVideoStabilizationModeSupported](#oh_capturesession_isvideostabilizationmodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoStabilizationMode](#camera_videostabilizationmode) mode, bool \*isSupported) | 检查是否支持指定的录像防抖模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetVideoStabilizationMode](#oh_capturesession_getvideostabilizationmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoStabilizationMode](#camera_videostabilizationmode) \*mode) | 获取当前录像防抖模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetVideoStabilizationMode](#oh_capturesession_setvideostabilizationmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoStabilizationMode](#camera_videostabilizationmode) mode) | 设置录像防抖模式。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddInput](#oh_capturesession_canaddinput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Input](#camera_input) \*cameraInput, bool \*isSuccessful) | 确定是否可以将相机输入添加到会话中。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddPreviewOutput](#oh_capturesession_canaddpreviewoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*cameraOutput, bool \*isSuccessful) | 确定是否可以将相机预览输出添加到会话中。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddPhotoOutput](#oh_capturesession_canaddphotooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PhotoOutput](#camera_photooutput) \*cameraOutput, bool \*isSuccessful) | 确定是否可以将相机照片输出添加到会话中。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddVideoOutput](#oh_capturesession_canaddvideooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoOutput](#camera_videooutput) \*cameraOutput, bool \*isSuccessful) | 确定是否可以将相机视频输出添加到会话中。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanPreconfig](#oh_capturesession_canpreconfig) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType, bool \*canPreconfig) | 检查是否支持指定的预配置类型。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanPreconfigWithRatio](#oh_capturesession_canpreconfigwithratio) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType, [Camera_PreconfigRatio](#camera_preconfigratio) preconfigRatio, bool \*canPreconfig) | 检查是否支持带比例的预配置类型。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Preconfig](#oh_capturesession_preconfig) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType) | 设置预配置类型。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_PreconfigWithRatio](#oh_capturesession_preconfigwithratio) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType, [Camera_PreconfigRatio](#camera_preconfigratio) preconfigRatio) | 设置带有比例的预配置类型。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureValue](#oh_capturesession_getexposurevalue) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*exposureValue) | 查询曝光值。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFocalLength](#oh_capturesession_getfocallength) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*focalLength) | 获取当前焦距值。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetSmoothZoom](#oh_capturesession_setsmoothzoom) ([Camera_CaptureSession](#camera_capturesession) \*session, float targetZoom, [Camera_SmoothZoomMode](#camera_smoothzoommode) smoothZoomMode) | 触发平滑变焦。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetSupportedColorSpaces](#oh_capturesession_getsupportedcolorspaces) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*\*colorSpace, uint32_t \*size) | 获取支持的色彩空间列表。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_DeleteColorSpaces](#oh_capturesession_deletecolorspaces) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*colorSpace) | 删除色彩空间列表。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetActiveColorSpace](#oh_capturesession_getactivecolorspace) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*colorSpace) | 获取当前色彩空间。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetActiveColorSpace](#oh_capturesession_setactivecolorspace) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace colorSpace) | 设置当前色彩空间。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_RegisterCallback](#oh_metadataoutput_registercallback) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | 注册元数据输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_UnregisterCallback](#oh_metadataoutput_unregistercallback) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | 注销元数据输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Start](#oh_metadataoutput_start) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | 启动元数据输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Stop](#oh_metadataoutput_stop) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | 停止元数据输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Release](#oh_metadataoutput_release) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | 释放元数据输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoNative_GetMainImage](#oh_photonative_getmainimage) ([OH_PhotoNative](#oh_photonative) \*photo, OH_ImageNative \*\*mainImage) | 获取全质量图。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoNative_Release](#oh_photonative_release) ([OH_PhotoNative](#oh_photonative) \*photo) | 释放全质量图实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCallback](#oh_photooutput_registercallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | 注册拍照输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCallback](#oh_photooutput_unregistercallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | 注销拍照输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCaptureStartWithInfoCallback](#oh_photooutput_registercapturestartwithinfocallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo) callback) | 注册拍照开始事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback](#oh_photooutput_unregistercapturestartwithinfocallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo) callback) | 注销拍照开始事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCaptureEndCallback](#oh_photooutput_registercaptureendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend) callback) | 注册拍照结束事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureEndCallback](#oh_photooutput_unregistercaptureendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend) callback) | 注销拍照结束事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterFrameShutterEndCallback](#oh_photooutput_registerframeshutterendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend) callback) | 注册拍照曝光结束事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterFrameShutterEndCallback](#oh_photooutput_unregisterframeshutterendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend) callback) | 注销拍照曝光结束事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCaptureReadyCallback](#oh_photooutput_registercapturereadycallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready) callback) | 注册拍照就绪事件回调。收到回调后，可以继续进行下一次拍照。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureReadyCallback](#oh_photooutput_unregistercapturereadycallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready) callback) | 注销拍照就绪事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback](#oh_photooutput_registerestimatedcapturedurationcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration) callback) | 注册预计拍照时间事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback](#oh_photooutput_unregisterestimatedcapturedurationcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration) callback) | 注销预计拍照时间事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAvailableCallback](#oh_photooutput_registerphotoavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable) callback) | 注册输出照片可用回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAvailableCallback](#oh_photooutput_unregisterphotoavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable) callback) | 注销输出照片可用回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAssetAvailableCallback](#oh_photooutput_registerphotoassetavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable) callback) | 注册输出照片资源可用回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback](#oh_photooutput_unregisterphotoassetavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable) callback) | 注销输出照片资源可用回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Capture](#oh_photooutput_capture) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | 拍摄照片。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Capture_WithCaptureSetting](#oh_photooutput_capture_withcapturesetting) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) setting) | 使用捕获设置捕获拍照。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Release](#oh_photooutput_release) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | 释放拍照输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_IsMirrorSupported](#oh_photooutput_ismirrorsupported) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool \*isSupported) | 检查是否支持镜像拍照。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_EnableMirror](#oh_photooutput_enablemirror) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool enabled) | 是否启用动态照片镜像拍照。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_GetActiveProfile](#oh_photooutput_getactiveprofile) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_Profile](_camera___profile.md) \*\*profile) | 获取当前照片输出配置文件。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_DeleteProfile](#oh_photooutput_deleteprofile) ([Camera_Profile](_camera___profile.md) \*profile) | 删除照片配置文件实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_IsMovingPhotoSupported](#oh_photooutput_ismovingphotosupported) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool \*isSupported) | 检查是否支持动态照片。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_EnableMovingPhoto](#oh_photooutput_enablemovingphoto) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool enabled) | 是否启用动态照片。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_RegisterCallback](#oh_previewoutput_registercallback) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | 注册预览输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_UnregisterCallback](#oh_previewoutput_unregistercallback) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | 注销预览输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Start](#oh_previewoutput_start) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | 开始预览输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Stop](#oh_previewoutput_stop) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | 停止预览输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Release](#oh_previewoutput_release) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | 释放预览输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_GetActiveProfile](#oh_previewoutput_getactiveprofile) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_Profile](_camera___profile.md) \*\*profile) | 获取当前预览输出配置文件。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_DeleteProfile](#oh_previewoutput_deleteprofile) ([Camera_Profile](_camera___profile.md) \*profile) | 删除预览配置文件实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_GetSupportedFrameRates](#oh_previewoutput_getsupportedframerates) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*\*frameRateRange, uint32_t \*size) | 获取支持的预览输出帧率列表。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_DeleteFrameRates](#oh_previewoutput_deleteframerates) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | 删除帧率列表。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_SetFrameRate](#oh_previewoutput_setframerate) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, int32_t minFps, int32_t maxFps) | 设置预览输出帧率。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_GetActiveFrameRate](#oh_previewoutput_getactiveframerate) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | 获取当前预览输出帧率。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_RegisterCallback](#oh_videooutput_registercallback) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | 注册录像输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_UnregisterCallback](#oh_videooutput_unregistercallback) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | 注销录像输出更改事件回调。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Start](#oh_videooutput_start) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | 开始录像输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Stop](#oh_videooutput_stop) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | 停止录像输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Release](#oh_videooutput_release) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | 释放录像输出。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_GetActiveProfile](#oh_videooutput_getactiveprofile) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_VideoProfile](_camera___video_profile.md) \*\*profile) | 获取当前视频输出配置文件。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_DeleteProfile](#oh_videooutput_deleteprofile) ([Camera_VideoProfile](_camera___video_profile.md) \*profile) | 删除视频配置文件实例。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_GetSupportedFrameRates](#oh_videooutput_getsupportedframerates) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*\*frameRateRange, uint32_t \*size) | 获取支持的视频输出帧率列表。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_DeleteFrameRates](#oh_videooutput_deleteframerates) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | 删除帧率列表。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_SetFrameRate](#oh_videooutput_setframerate) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, int32_t minFps, int32_t maxFps) | 设置视频输出帧率。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_GetActiveFrameRate](#oh_videooutput_getactiveframerate) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | 获取当前视频输出帧率。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetQualityPrioritization](#oh_capturesession_setqualityprioritization) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_QualityPrioritization](#camera_qualityprioritization) qualityPrioritization) | 设置当前录像质量优先级。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraDevice_GetHostDeviceName](#oh_cameradevice_gethostdevicename) ([Camera_Device](_camera___device.md) \*camera, char \*\*hostDeviceName) | 获取远程设备名称。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraDevice_GetHostDeviceType](#oh_cameradevice_gethostdevicetype) ([Camera_Device](_camera___device.md) \*camera, [Camera_HostDeviceType](#camera_hostdevicetype) \*hostDeviceType) | 获取远程设备类型。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_IsMirrorSupported](#oh_videooutput_ismirrorsupported) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, bool \*isSupported) | 判断当前视频输出是否支持镜像。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_EnableMirror](#oh_videooutput_enablemirror) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, bool mirrorMode) | 打开/关闭当前视频输出镜像功能。 | 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_GetVideoRotation](#oh_videooutput_getvideorotation) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, int deviceDegree, [Camera_ImageRotation](#camera_imagerotation) \*imageRotation) | 获取当前视频输出应当设置的旋转角度。 | 

## 类型定义说明


### Camera_CaptureEndInfo

```
typedef struct Camera_CaptureEndInfo Camera_CaptureEndInfo
```

**描述**

捕获结束信息。

**起始版本：** 11


### Camera_CaptureSession

```
typedef struct Camera_CaptureSession Camera_CaptureSession
```

**描述**

捕获会话对象。

可以使用[OH_CameraManager_CreateCaptureSession](#oh_cameramanager_createcapturesession)方法创建指针。

**起始版本：** 11


### Camera_CaptureStartInfo

```
typedef struct Camera_CaptureStartInfo Camera_CaptureStartInfo
```

**描述**

拍照开始信息。

**起始版本：** 12


### Camera_Connection

```
typedef enum Camera_Connection Camera_Connection
```

**描述**

相机连接类型的枚举。

**起始版本：** 11


### Camera_Device

```
typedef struct Camera_Device Camera_Device
```

**描述**

相机设备对象。

**起始版本：** 11


### Camera_ErrorCode

```
typedef enum Camera_ErrorCode Camera_ErrorCode
```

**描述**

相机错误代码的枚举。

**起始版本：** 11


### Camera_ExposureMode

```
typedef enum Camera_ExposureMode Camera_ExposureMode
```

**描述**

曝光模式的枚举。

**起始版本：** 11


### Camera_FlashMode

```
typedef enum Camera_FlashMode Camera_FlashMode
```

**描述**

闪光模式的枚举。

**起始版本：** 11


### Camera_FocusMode

```
typedef enum Camera_FocusMode Camera_FocusMode
```

**描述**

聚焦模式的枚举。

**起始版本：** 11


### Camera_FocusState

```
typedef enum Camera_FocusState Camera_FocusState
```

**描述**

焦点状态的枚举。

**起始版本：** 11


### Camera_Format

```
typedef enum Camera_Format Camera_Format
```

**描述**

相机格式类型的枚举。

**起始版本：** 11


### Camera_FrameRateRange

```
typedef struct Camera_FrameRateRange Camera_FrameRateRange
```

**描述**

帧速率范围。

**起始版本：** 11


### Camera_FrameShutterEndInfo

```
typedef struct Camera_FrameShutterEndInfo Camera_FrameShutterEndInfo
```

**描述**

拍照曝光结束信息。

**起始版本：** 12


### Camera_FrameShutterInfo

```
typedef struct Camera_FrameShutterInfo Camera_FrameShutterInfo
```

**描述**

帧快门回调信息。

**起始版本：** 11


### Camera_HostDeviceType

```
typedef enum Camera_HostDeviceTypeCamera_HostDeviceType
```

**描述**

远程设备类型枚举。

**起始版本：** 15


### Camera_ImageRotation

```
typedef enum Camera_ImageRotation Camera_ImageRotation
```

**描述**

图像旋转角度的枚举。

**起始版本：** 11


### Camera_Input

```
typedef struct Camera_Input Camera_Input
```

**描述**

相机输入对象。

可以使用[OH_CameraManager_CreateCameraInput](#oh_cameramanager_createcamerainput)方法创建指针。

**起始版本：** 11


### Camera_Location

```
typedef struct Camera_Location Camera_Location
```

**描述**

拍照位置。

**起始版本：** 11


### Camera_Manager

```
typedef struct Camera_Manager Camera_Manager
```

**描述**

相机管理器对象。

可以使用[OH_Camera_GetCameraManager](#oh_camera_getcameramanager)方法创建指针。

**起始版本：** 11


### Camera_MetadataObject

```
typedef struct Camera_MetadataObject Camera_MetadataObject
```

**描述**

元数据对象基础。

**起始版本：** 11


### Camera_MetadataObjectType

```
typedef enum Camera_MetadataObjectType Camera_MetadataObjectType
```

**描述**

元数据对象类型的枚举。

**起始版本：** 11


### Camera_MetadataOutput

```
typedef struct Camera_MetadataOutput Camera_MetadataOutput
```

**描述**

元数据输出对象。

可以使用[OH_CameraManager_CreateMetadataOutput](#oh_cameramanager_createmetadataoutput)方法创建指针。

**起始版本：** 11


### Camera_OutputCapability

```
typedef struct Camera_OutputCapability Camera_OutputCapability
```

**描述**

相机输出能力。

**起始版本：** 11


### Camera_PhotoCaptureSetting

```
typedef struct Camera_PhotoCaptureSetting Camera_PhotoCaptureSetting
```

**描述**

要设置的拍照捕获选项。

**起始版本：** 11


### Camera_PhotoOutput

```
typedef struct Camera_PhotoOutput Camera_PhotoOutput
```

**描述**

拍照输出对象。

可以使用[OH_CameraManager_CreatePhotoOutput](#oh_cameramanager_createphotooutput)方法创建指针。

**起始版本：** 11


### Camera_Point

```
typedef struct Camera_Point Camera_Point
```

**描述**

点参数。

**起始版本：** 11


### Camera_Position

```
typedef enum Camera_Position Camera_Position
```

**描述**

相机位置的枚举。

**起始版本：** 11


### Camera_PreconfigRatio

```
typedef enum Camera_PreconfigRatio Camera_PreconfigRatio
```

**描述**

预配置照片比例的枚举。

**起始版本：** 12


### Camera_PreconfigType

```
typedef enum Camera_PreconfigType Camera_PreconfigType
```

**描述**

预配置照片分辨率的枚举。

**起始版本：** 12


### Camera_PreviewOutput

```
typedef struct Camera_PreviewOutput Camera_PreviewOutput
```

**描述**

预览输出对象。

可以使用[OH_CameraManager_CreatePreviewOutput](#oh_cameramanager_createpreviewoutput)方法创建指针。

**起始版本：** 11


### Camera_Profile

```
typedef struct Camera_Profile Camera_Profile
```

**描述**

相机流的配置文件。

**起始版本：** 11


### Camera_QualityLevel

```
typedef enum Camera_QualityLevel Camera_QualityLevel
```

**描述**

图像质量等级的枚举。

**起始版本：** 11


### Camera_QualityPrioritization

```
typedef enum Camera_QualityPrioritization Camera_QualityPrioritization
```

**描述**

录像质量优先级的枚举。

**起始版本：** 14


### Camera_Rect

```
typedef struct Camera_Rect Camera_Rect
```

**描述**

矩形定义。

**起始版本：** 11


### Camera_SceneMode

```
typedef enum Camera_SceneMode Camera_SceneMode
```

**描述**

相机模式的枚举。

**起始版本：** 12


### Camera_Size

```
typedef struct Camera_Size Camera_Size
```

**描述**

大小参数。

**起始版本：** 11


### Camera_SmoothZoomInfo

```
typedef struct Camera_SmoothZoomInfo Camera_SmoothZoomInfo
```

**描述**

平滑变焦参数信息。

**起始版本：** 12


### Camera_SmoothZoomMode

```
typedef enum Camera_SmoothZoomMode Camera_SmoothZoomMode
```

**描述**

平滑变焦模式的枚举。

**起始版本：** 12


### Camera_Status

```
typedef enum Camera_Status Camera_Status
```

**描述**

相机状态的枚举。

**起始版本：** 11


### Camera_StatusInfo

```
typedef struct Camera_StatusInfo Camera_StatusInfo
```

**描述**

相机状态信息。

**起始版本：** 11


### Camera_TorchMode

```
typedef enum Camera_TorchMode Camera_TorchMode
```

**描述**

手电筒模式的枚举。

**起始版本：** 12


### Camera_TorchStatusInfo

```
typedef struct Camera_TorchStatusInfo Camera_TorchStatusInfo
```

**描述**

手电筒状态信息。

**起始版本：** 12


### Camera_Type

```
typedef enum Camera_Type Camera_Type
```

**描述**

相机类型的枚举。

**起始版本：** 11


### Camera_VideoOutput

```
typedef struct Camera_VideoOutput Camera_VideoOutput
```

**描述**

录像输出对象。

可以使用[OH_CameraManager_CreateVideoOutput](#oh_cameramanager_createvideooutput)方法创建指针。

**起始版本：** 11


### Camera_VideoProfile

```
typedef struct Camera_VideoProfile Camera_VideoProfile
```

**描述**

录像配置文件。

**起始版本：** 11


### Camera_VideoStabilizationMode

```
typedef enum Camera_VideoStabilizationMode Camera_VideoStabilizationMode
```

**描述**

录像防抖模式的枚举。

**起始版本：** 11


### CameraInput_Callbacks

```
typedef struct CameraInput_Callbacks CameraInput_Callbacks
```

**描述**

相机输入错误事件的回调。

**起始版本：** 11

**参见：**

[OH_CameraInput_RegisterCallback](#oh_camerainput_registercallback)


### CameraManager_Callbacks

```
typedef struct CameraManager_Callbacks CameraManager_Callbacks
```

**描述**

相机设备状态的回调。

**起始版本：** 11

**参见：**

[OH_CameraManager_RegisterCallback](#oh_cameramanager_registercallback)


### CaptureSession_Callbacks

```
typedef struct CaptureSession_Callbacks CaptureSession_Callbacks
```

**描述**

捕获会话的回调。

**起始版本：** 11

**参见：**

[OH_CaptureSession_RegisterCallback](#oh_capturesession_registercallback)


### MetadataOutput_Callbacks

```
typedef struct MetadataOutput_Callbacks MetadataOutput_Callbacks
```

**描述**

元数据输出的回调。

**起始版本：** 11

**参见：**

[OH_MetadataOutput_RegisterCallback](#oh_metadataoutput_registercallback)


### OH_CameraInput_OnError

```
typedef void (*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)
```

**描述**

在[CameraInput_Callbacks](_camera_input___callbacks.md)中被调用的相机输入错误回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraInput | 传递回调的[Camera_Input](#camera_input)。 | 
| errorCode | 相机输入的[Camera_ErrorCode](#camera_errorcode-1)。 | 

**参见：**

[Camera_ErrorCode](#camera_errorcode-1)中的：

- CAMERA_CONFLICT_CAMERA

- CAMERA_DEVICE_DISABLED

- CAMERA_DEVICE_PREEMPTED

- CAMERA_SERVICE_FATAL_ERROR


### OH_CameraManager_StatusCallback

```
typedef void (*OH_CameraManager_StatusCallback)(Camera_Manager* cameraManager, Camera_StatusInfo* status)
```

**描述**

在[CameraManager_Callbacks](_camera_manager___callbacks.md)中被调用的相机管理器状态回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 传递回调的[Camera_Manager](#camera_manager)。 | 
| status | 每个相机设备的[Camera_StatusInfo](_camera___status_info.md)。 | 


### OH_CameraManager_TorchStatusCallback

```
typedef void (*OH_CameraManager_TorchStatusCallback)(Camera_Manager* cameraManager, Camera_TorchStatusInfo* status)
```

**描述**

手电筒状态变化回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 传递回调的[Camera_Manager](#camera_manager)。 | 
| status | 手电筒的状态[Camera_TorchStatusInfo](_camera___torch_status_info.md)。 | 


### OH_CaptureSession_OnError

```
typedef void (*OH_CaptureSession_OnError)(Camera_CaptureSession* session, Camera_ErrorCode errorCode)
```

**描述**

在[CaptureSession_Callbacks](_capture_session___callbacks.md)中被调用的捕获会话错误回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | 传递回调的[Camera_CaptureSession](#camera_capturesession)。 | 
| errorCode | 捕获会话的[Camera_ErrorCode](#camera_errorcode-1)。 | 

**参见：**

[Camera_ErrorCode](#camera_errorcode-1)中的CAMERA_SERVICE_FATAL_ERROR。


### OH_CaptureSession_OnFocusStateChange

```
typedef void (*OH_CaptureSession_OnFocusStateChange)(Camera_CaptureSession* session, Camera_FocusState focusState)
```

**描述**

在[CaptureSession_Callbacks](_capture_session___callbacks.md)中被调用的捕获会话焦点状态回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | 传递回调的[Camera_CaptureSession](#camera_capturesession)。 | 
| focusState | 回调传递的[Camera_FocusState](#camera_focusstate)。 | 


### OH_CaptureSession_OnSmoothZoomInfo

```
typedef void (*OH_CaptureSession_OnSmoothZoomInfo)(Camera_CaptureSession* session, Camera_SmoothZoomInfo* smoothZoomInfo)
```

**描述**

拍照会话平滑变焦信息回调，触发平滑变焦后该回调会返回。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | 传递回调的[Camera_CaptureSession](#camera_capturesession)。 | 
| smoothZoomInfo | 回调传递的[Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md)。 | 


### OH_MetadataOutput_OnError

```
typedef void (*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)
```

**描述**

在[MetadataOutput_Callbacks](_metadata_output___callbacks.md)中被调用的元数据输出错误回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataOutput | 传递回调的[Camera_MetadataOutput](#camera_metadataoutput)。 | 
| errorCode | 元数据输出的[Camera_ErrorCode](#camera_errorcode-1)。 | 

**参见：**

[Camera_ErrorCode](#camera_errorcode-1)中的CAMERA_SERVICE_FATAL_ERROR。


### OH_MetadataOutput_OnMetadataObjectAvailable

```
typedef void (*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput, Camera_MetadataObject* metadataObject, uint32_t size)
```

**描述**

在[MetadataOutput_Callbacks](_metadata_output___callbacks.md)中被调用的元数据输出元数据对象可用回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataOutput | 传递回调的[Camera_MetadataOutput](#camera_metadataoutput)。 | 
| metadataObject | [Camera_MetadataObject](_camera___metadata_object.md)将由回调传递。 | 
| size | 元数据对象的大小。 | 


### OH_PhotoNative

```
typedef struct OH_PhotoNative OH_PhotoNative
```

**描述**

相机照片对象。

全质量图对象。

**起始版本：** 12


### OH_PhotoOutput_CaptureEnd

```
typedef void (*OH_PhotoOutput_CaptureEnd) (Camera_PhotoOutput* photoOutput, int32_t frameCount)
```

**描述**

拍照结束回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| frameCount | 回调传递的帧数。 | 


### OH_PhotoOutput_CaptureReady

```
typedef void (*OH_PhotoOutput_CaptureReady) (Camera_PhotoOutput* photoOutput)
```

**描述**

拍照准备就绪回调。收到回调后，可以继续进行下一次拍照。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 


### OH_PhotoOutput_CaptureStartWithInfo

```
typedef void (*OH_PhotoOutput_CaptureStartWithInfo) (Camera_PhotoOutput* photoOutput, Camera_CaptureStartInfo* Info)
```

**描述**

拍照开始回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| Info | 回调传递的[Camera_CaptureStartInfo](_camera___capture_start_info.md)。 | 


### OH_PhotoOutput_EstimatedCaptureDuration

```
typedef void (*OH_PhotoOutput_EstimatedCaptureDuration) (Camera_PhotoOutput* photoOutput, int64_t duration)
```

**描述**

预计拍照时间回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| duration | 回调传递的预计拍照时间。 | 


### OH_PhotoOutput_OnError

```
typedef void (*OH_PhotoOutput_OnError)(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
```

**描述**

在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出错误回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| errorCode | 拍照输出的[Camera_ErrorCode](#camera_errorcode-1)。 | 

**参见：**

[Camera_ErrorCode](#camera_errorcode-1)中的CAMERA_SERVICE_FATAL_ERROR。


### OH_PhotoOutput_OnFrameEnd

```
typedef void (*OH_PhotoOutput_OnFrameEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount)
```

**描述**

在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧结束回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| frameCount | 回调传递的帧计数。 | 


### OH_PhotoOutput_OnFrameShutter

```
typedef void (*OH_PhotoOutput_OnFrameShutter)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info)
```

**描述**

在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧快门回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| info | 回调传递的[Camera_FrameShutterInfo](_camera___frame_shutter_info.md)。 | 


### OH_PhotoOutput_OnFrameShutterEnd

```
typedef void (*OH_PhotoOutput_OnFrameShutterEnd) (Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* Info)
```

**描述**

拍照曝光结束回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| Info | 回调传递的[Camera_FrameShutterInfo](_camera___frame_shutter_info.md)。 | 


### OH_PhotoOutput_OnFrameStart

```
typedef void(* OH_PhotoOutput_OnFrameStart) (Camera_PhotoOutput *photoOutput)
```

**描述**

在[PhotoOutput_Callbacks](_photo_output___callbacks.md)中被调用的拍照输出帧启动回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 


### OH_PhotoOutput_PhotoAssetAvailable

```
typedef void (*OH_PhotoOutput_PhotoAssetAvailable)(Camera_PhotoOutput* photoOutput, OH_MediaAsset* photoAsset)
```

**描述**

输出照片资源可用回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| photoAsset | 回调传递的[OH_MediaAsset](../apis-media-library-kit/_media_asset_manager.md#oh_mediaasset)。 | 


### OH_PhotoOutput_PhotoAvailable

```
typedef void (*OH_PhotoOutput_PhotoAvailable)(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo)
```

**描述**

照片输出可用高分辨率图像回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递回调的[Camera_PhotoOutput](#camera_photooutput)。 | 
| photo | 回调传递的[OH_PhotoNative](#oh_photonative)。 | 


### OH_PreviewOutput_OnError

```
typedef void (*OH_PreviewOutput_OnError)(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
```

**描述**

在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧错误回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 传递回调的[Camera_PreviewOutput](#camera_previewoutput)。 | 
| errorCode | 预览输出的[Camera_ErrorCode](#camera_errorcode-1)。 | 

**参见：**

[Camera_ErrorCode](#camera_errorcode-1)中的CAMERA_SERVICE_FATAL_ERROR


### OH_PreviewOutput_OnFrameEnd

```
typedef void (*OH_PreviewOutput_OnFrameEnd)(Camera_PreviewOutput* previewOutput, int32_t frameCount)
```

**描述**

在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧结束回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 传递回调的[Camera_PreviewOutput](#camera_previewoutput)。 | 
| frameCount | 回调传递的帧计数。 | 


### OH_PreviewOutput_OnFrameStart

```
typedef void (*OH_PreviewOutput_OnFrameStart)(Camera_PreviewOutput* previewOutput)
```

**描述**

在[PreviewOutput_Callbacks](_preview_output___callbacks.md)中被调用的预览输出帧开始回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 传递回调的[Camera_PreviewOutput](#camera_previewoutput)。 | 


### OH_VideoOutput_OnError

```
typedef void (*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
```

**描述**

在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出错误回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递回调的[Camera_VideoOutput](#camera_videooutput)。 | 
| errorCode | 录像输出的[Camera_ErrorCode](#camera_errorcode-1)。 | 

**参见：**

[Camera_ErrorCode](#camera_errorcode-1)中的CAMERA_SERVICE_FATAL_ERROR


### OH_VideoOutput_OnFrameEnd

```
typedef void (*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount)
```

**描述**

在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧结束回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递回调的[Camera_VideoOutput](#camera_videooutput)。 | 
| frameCount | 回调传递的帧计数。 | 


### OH_VideoOutput_OnFrameStart

```
typedef void (*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput)
```

**描述**

在[VideoOutput_Callbacks](_video_output___callbacks.md)中被调用的录像输出帧开始回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递回调的[Camera_VideoOutput](#camera_videooutput)。 | 


### PhotoOutput_Callbacks

```
typedef struct PhotoOutput_Callbacks PhotoOutput_Callbacks
```

**描述**

拍照输出的回调。

**起始版本：** 11

**参见：**

[OH_PhotoOutput_RegisterCallback](#oh_photooutput_registercallback)


### PreviewOutput_Callbacks

```
typedef struct PreviewOutput_Callbacks PreviewOutput_Callbacks
```

**描述**

用于预览输出的回调。

**起始版本：** 11

**参见：**

[OH_PreviewOutput_RegisterCallback](#oh_previewoutput_registercallback)


### VideoOutput_Callbacks

```
typedef struct VideoOutput_Callbacks VideoOutput_Callbacks
```

**描述**

用于录像输出的回调。

**起始版本：** 11

**参见：**

[OH_VideoOutput_RegisterCallback](#oh_videooutput_registercallback)


## 枚举类型说明


### Camera_Connection

```
enum Camera_Connection
```

**描述**

相机连接类型的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CAMERA_CONNECTION_BUILT_IN | 内置摄像头。 | 
| CAMERA_CONNECTION_USB_PLUGIN | 使用USB连接的摄像头。 | 
| CAMERA_CONNECTION_REMOTE | 远程摄像头。 | 


### Camera_ErrorCode

```
enum Camera_ErrorCode
```

**描述**

相机错误代码的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CAMERA_OK | 相机结果正常。 | 
| CAMERA_INVALID_ARGUMENT | 参数丢失或参数类型不正确。 | 
| CAMERA_OPERATION_NOT_ALLOWED | 不允许操作。 | 
| CAMERA_SESSION_NOT_CONFIG | 会话未配置。 | 
| CAMERA_SESSION_NOT_RUNNING | 会话未运行。 | 
| CAMERA_SESSION_CONFIG_LOCKED | 会话配置已锁定。 | 
| CAMERA_DEVICE_SETTING_LOCKED | 设备设置已锁定。 | 
| CAMERA_CONFLICT_CAMERA | 因冲突而无法使用相机。 | 
| CAMERA_DEVICE_DISABLED | 由于安全原因，相机已禁用。 | 
| CAMERA_DEVICE_PREEMPTED | 因被抢占而无法使用相机。 | 
| CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS | 与当前配置存在冲突。<br/>**起始版本：** 12 | 
| CAMERA_SERVICE_FATAL_ERROR | 相机服务致命错误。比如没有相机权限、相机服务重启、跨进程调用异常等。| 


### Camera_ExposureMode

```
enum Camera_ExposureMode
```

**描述**

曝光模式的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| EXPOSURE_MODE_LOCKED | 锁定曝光模式。 | 
| EXPOSURE_MODE_AUTO | 自动曝光模式。 | 
| EXPOSURE_MODE_CONTINUOUS_AUTO | 连续自动曝光。 | 


### Camera_FlashMode

```
enum Camera_FlashMode
```

**描述**

闪光模式的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| FLASH_MODE_CLOSE | 关闭模式。 | 
| FLASH_MODE_OPEN | 打开模式。 | 
| FLASH_MODE_AUTO | 自动模式。 | 
| FLASH_MODE_ALWAYS_OPEN | 始终打开模式。 | 


### Camera_FocusMode

```
enum Camera_FocusMode
```

**描述**

聚焦模式的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| FOCUS_MODE_MANUAL | 手动模式。 | 
| FOCUS_MODE_CONTINUOUS_AUTO | 连续自动模式。 | 
| FOCUS_MODE_AUTO | 自动模式。 | 
| FOCUS_MODE_LOCKED | 锁定模式。 | 


### Camera_FocusState

```
enum Camera_FocusState
```

**描述**

焦点状态的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| FOCUS_STATE_SCAN | 扫描状态。 | 
| FOCUS_STATE_FOCUSED | 聚焦状态。 | 
| FOCUS_STATE_UNFOCUSED | 非聚焦状态。 | 


### Camera_Format

```
enum Camera_Format
```

**描述**

相机格式类型的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CAMERA_FORMAT_RGBA_8888 | RGBA 8888格式。 | 
| CAMERA_FORMAT_YUV_420_SP | YUV 420格式。 | 
| CAMERA_FORMAT_JPEG | JPEG格式。 | 
| CAMERA_FORMAT_YCBCR_P010 | YCBCR P010 格式。<br/>**起始版本：** 12 | 
| CAMERA_FORMAT_YCRCB_P010 | YCRCB P010 格式。<br/>**起始版本：** 12 | 


### Camera_HostDeviceType

```
enum Camera_HostDeviceType
```

**描述**

远程设备类型枚举。

**起始版本：** 15

| 枚举值 | 描述 | 
| -------- | -------- |
| HOST_DEVICE_TYPE_UNKNOWN_TYPE | 未知设备类型。 | 
| HOST_DEVICE_TYPE_PHONE | 手机设备。 | 
| HOST_DEVICE_TYPE_TABLET | 平板设备。 | 


### Camera_ImageRotation

```
enum Camera_ImageRotation
```

**描述**

图像旋转角度的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| IAMGE_ROTATION_0 | 捕获图像旋转0度。 | 
| IAMGE_ROTATION_90 | 捕获图像旋转90度。 | 
| IAMGE_ROTATION_180 | 捕获图像旋转180度。 | 
| IAMGE_ROTATION_270 | 捕获图像旋转270度。 | 


### Camera_MetadataObjectType

```
enum Camera_MetadataObjectType
```

**描述**

元数据对象类型的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| FACE_DETECTION | 人脸检测。 | 


### Camera_Position

```
enum Camera_Position
```

**描述**

相机位置的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CAMERA_POSITION_UNSPECIFIED | 相对于设备屏幕没有固定的朝向的相机。 | 
| CAMERA_POSITION_BACK | 后置。 | 
| CAMERA_POSITION_FRONT | 前置。 | 


### Camera_PreconfigRatio

```
enum Camera_PreconfigRatio
```

**描述**

预配置照片比例的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PRECONFIG_RATIO_1_1 | 预配置照片比例为1:1。 | 
| PRECONFIG_RATIO_4_3 | 预配置照片比例为4:3。 | 
| PRECONFIG_RATIO_16_9 | 预配置照片比例为16:9。 | 


### Camera_PreconfigType

```
enum Camera_PreconfigType
```

**描述**

预配置照片分辨率的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PRECONFIG_720P | 预配置照片分辨率为720P。 | 
| PRECONFIG_1080P | 预配置照片分辨率为1080P。 | 
| PRECONFIG_4K | 预配置照片分辨率为4K。 | 
| PRECONFIG_HIGH_QUALITY | 预配置照片为高质量。 | 


### Camera_QualityLevel

```
enum Camera_QualityLevel
```

**描述**

图像质量等级的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| QUALITY_LEVEL_HIGH | 高图像质量。 | 
| QUALITY_LEVEL_MEDIUM | 中等图像质量。 | 
| QUALITY_LEVEL_LOW | 低图像质量。 | 

### Camera_QualityPrioritization

```
enum Camera_QualityPrioritization
```

**描述**

录像质量优先级的枚举。

**起始版本：** 14

| 枚举值        | 描述                 |
| ------------- | -------------------- |
| HIGH_QUALITY  | 高录像质量。         |
| POWER_BALANCE | 功耗平衡的录像质量。 |

### Camera_SceneMode

```
enum Camera_SceneMode
```

**描述**

相机模式的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL_PHOTO | 普通拍照模式。 | 
| NORMAL_VIDEO | 普通视频模式。 | 
| SECURE_PHOTO | 安全相机模式。 | 


### Camera_SmoothZoomMode

```
enum Camera_SmoothZoomMode
```

**描述**

平滑变焦模式的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NORMAL | 贝塞尔曲线模式。 | 


### Camera_Status

```
enum Camera_Status
```

**描述**

相机状态的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CAMERA_STATUS_APPEAR | 显示状态。 | 
| CAMERA_STATUS_DISAPPEAR | 消失状态。 | 
| CAMERA_STATUS_AVAILABLE | 可用状态。 | 
| CAMERA_STATUS_UNAVAILABLE | 不可用状态。 | 


### Camera_TorchMode

```
enum Camera_TorchMode
```

**描述**

手电筒模式的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OFF | 设备手电筒常关。 | 
| ON | 设备手电筒常开。 | 
| AUTO | 设备手电筒自动模式，将根据环境光照水平打开手电筒。 | 


### Camera_Type

```
enum Camera_Type
```

**描述**

相机类型的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CAMERA_TYPE_DEFAULT | 默认相机类型。 | 
| CAMERA_TYPE_WIDE_ANGLE | 广角相机。 | 
| CAMERA_TYPE_ULTRA_WIDE | 超广角相机。 | 
| CAMERA_TYPE_TELEPHOTO | 长焦相机。 | 
| CAMERA_TYPE_TRUE_DEPTH | 景深相机。 | 


### Camera_VideoStabilizationMode

```
enum Camera_VideoStabilizationMode
```

**描述**

录像防抖模式的枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| STABILIZATION_MODE_OFF | 关闭录像防抖。 | 
| STABILIZATION_MODE_LOW | LOW模式提供基本的防抖效果。 | 
| STABILIZATION_MODE_MIDDLE | MIDDLE模式意味着通过算法可以获得比LOW模式更好的效果。 | 
| STABILIZATION_MODE_HIGH | HIGH模式意味着通过算法可以获得比MIDDLE模式更好的效果。 | 
| STABILIZATION_MODE_AUTO | 自动选择模式，HDF相机可用。 | 


## 函数说明


### OH_Camera_DeleteCameraManager()

```
Camera_ErrorCode OH_Camera_DeleteCameraManager(Camera_Manager* cameraManager)
```

**描述**

删除CameraManager实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 要删除的[Camera_Manager](#camera_manager)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_Camera_GetCameraManager()

```
Camera_ErrorCode OH_Camera_GetCameraManager(Camera_Manager** cameraManager)
```

**描述**

创建CameraManager实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 如果方法调用成功，将创建输出[Camera_Manager](#camera_manager)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraDevice_GetCameraOrientation()

```
Camera_ErrorCode OH_CameraDevice_GetCameraOrientation(Camera_Device* camera, uint32_t* orientation)
```

**描述**

获取相机设备的传感器方向属性。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| camera | [Camera_Device](_camera___device.md) 用来获取属性。 | 
| orientation | 返回相机sensor角度属性。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：如果方法调用成功，则返回传感器方向属性。

- CAMERA_INVALID_ARGUMENT：参数丢失或者参数不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CameraInput_Close()

```
Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput)
```

**描述**

关闭相机。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraInput | 要关闭的[Camera_Input](#camera_input)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraInput_Open()

```
Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput)
```

**描述**

打开相机。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraInput | 要打开的[Camera_Input](#camera_input)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_CONFLICT_CAMERA：因冲突而无法使用相机。

- CAMERA_DEVICE_DISABLED：由于安全原因禁用了摄像头。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraInput_OpenSecureCamera()

```
Camera_ErrorCode OH_CameraInput_OpenSecureCamera(Camera_Input* cameraInput, uint64_t* secureSeqId)
```

**描述**

打开相机。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraInput | 要打开的[Camera_Input](#camera_input)实例。 | 
| secureSeqId | 表示安全摄像头的序列值。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_CONFLICT_CAMERA：因冲突而无法使用相机。

- CAMERA_DEVICE_DISABLED：由于安全原因禁用了摄像头。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraInput_RegisterCallback()

```
Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**描述**

注册相机输入更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraInput | [Camera_Input](#camera_input)实例。 | 
| callback | 要注册的[CameraInput_Callbacks](_camera_input___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraInput_Release()

```
Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput)
```

**描述**

释放相机输入实例。

和[OH_CameraInput_Close](#oh_camerainput_close)只需要调用其中一个，调用之后无须再调用[OH_CameraInput_Close](#oh_camerainput_close)。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraInput | 要释放的[Camera_Input](#camera_input)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraInput_UnregisterCallback()

```
Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**描述**

注销相机输入更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraInput | [Camera_Input](#camera_input)实例。 | 
| callback | 要注销的[CameraInput_Callbacks](_camera_input___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_CreateCameraInput()

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_Input** cameraInput)
```

**描述**

创建相机输入实例。

**起始版本：** 11

**需要权限：** ohos.permission.CAMERA

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| camera | 用于创建[Camera_Input](#camera_input)的[Camera_Device](_camera___device.md)。 | 
| cameraInput | 如果方法调用成功，将创建[Camera_Input](#camera_input)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreateCameraInput_WithPositionAndType()

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput_WithPositionAndType(Camera_Manager* cameraManager, Camera_Position position, Camera_Type type, Camera_Input** cameraInput)
```

**描述**

创建具有位置和类型的相机输入实例。

**起始版本：** 11

**需要权限：** ohos.permission.CAMERA

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| position | 用于创建[Camera_Input](#camera_input)的[Camera_Position](#camera_position)。 | 
| type | 用于创建[Camera_Input](#camera_input)的[Camera_Type](#camera_type)。 | 
| cameraInput | 如果方法调用成功，将创建[Camera_Input](#camera_input)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreateCaptureSession()

```
Camera_ErrorCode OH_CameraManager_CreateCaptureSession(Camera_Manager* cameraManager,
 Camera_CaptureSession** captureSession)
```

**描述**

创建捕获会话实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| captureSession | 如果方法调用成功，则将创建[Camera_CaptureSession](#camera_capturesession)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreateMetadataOutput()

```
Camera_ErrorCode OH_CameraManager_CreateMetadataOutput(Camera_Manager* cameraManager, const Camera_MetadataObjectType* profile, Camera_MetadataOutput** metadataOutput)
```

**描述**

创建元数据输出实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| profile | 用于创建[Camera_MetadataOutput](#camera_metadataoutput)的[Camera_MetadataObjectType](#camera_metadataobjecttype). | 
| metadataOutput | 如果方法调用成功，将创建[Camera_MetadataOutput](#camera_metadataoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreatePhotoOutput()

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PhotoOutput** photoOutput)
```

**描述**

创建一个拍照输出实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| profile | 用于创建[Camera_PhotoOutput](#camera_photooutput)的[Camera_Profile](_camera___profile.md)。 | 
| surfaceId | 用于创建[Camera_PhotoOutput](#camera_photooutput)的surfaceId。 | 
| photoOutput | 如果方法调用成功，将创建[Camera_PhotoOutput](#camera_photooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreatePhotoOutputUsedInPreconfig()

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PhotoOutput** photoOutput)
```

**描述**

创建在预配置流中使用的照片输出实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| surfaceId | 用于创建[Camera_PhotoOutput](#camera_photooutput)的surfaceId。 | 
| photoOutput | 如果方法调用成功，将创建[Camera_PhotoOutput](#camera_photooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreatePhotoOutputWithoutSurface()

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputWithoutSurface(Camera_Manager *cameraManager, const Camera_Profile *profile, Camera_PhotoOutput **photoOutput)
```

**描述**

创建照片输出实例，调用此函数不需要surfaceId。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| profile | 用于创建[Camera_PhotoOutput](#camera_photooutput)的[Camera_Profile](_camera___profile.md)。 | 
| photoOutput | 如果方法调用成功，将创建[Camera_PhotoOutput](#camera_photooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreatePreviewOutput()

```
Camera_ErrorCode OH_CameraManager_CreatePreviewOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PreviewOutput** previewOutput)
```

**描述**

创建预览输出实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| profile | 用于创建[Camera_PreviewOutput](#camera_previewoutput)的[Camera_Profile](_camera___profile.md)。 | 
| surfaceId | 用于创建[Camera_PreviewOutput](#camera_previewoutput)的surfaceId。 | 
| previewOutput | 如果方法调用成功，将创建[Camera_PreviewOutput](#camera_previewoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreatePreviewOutputUsedInPreconfig()

```
Camera_ErrorCode OH_CameraManager_CreatePreviewOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PreviewOutput** previewOutput)
```

**描述**

创建在预配置流中使用的预览输出实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| surfaceId | 用于创建[Camera_PreviewOutput](#camera_previewoutput)的surfaceId。 | 
| previewOutput | 如果方法调用成功，将创建[Camera_PreviewOutput](#camera_previewoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreateVideoOutput()

```
Camera_ErrorCode OH_CameraManager_CreateVideoOutput(Camera_Manager* cameraManager, const Camera_VideoProfile* profile, const char* surfaceId, Camera_VideoOutput** videoOutput)
```

**描述**

创建一个录像输出实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| profile | 用于创建[Camera_VideoOutput](#camera_videooutput)的[Camera_VideoProfile](_camera___video_profile.md)。 | 
| surfaceId | 用于创建[Camera_VideoOutput](#camera_videooutput)的surfaceId。 | 
| videoOutput | 如果方法调用成功，将创建[Camera_VideoOutput](#camera_videooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_CreateVideoOutputUsedInPreconfig()

```
Camera_ErrorCode OH_CameraManager_CreateVideoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_VideoOutput** videoOutput)
```

**描述**

创建在预配置流中使用的视频输出实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| surfaceId | 用于创建[Camera_VideoOutput](#camera_videooutput)的surfaceId。 | 
| videoOutput | 如果方法调用成功，将创建[Camera_VideoOutput](#camera_videooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_DeleteSceneModes()

```
Camera_ErrorCode OH_CameraManager_DeleteSceneModes(Camera_Manager* cameraManager, Camera_SceneMode* sceneModes)
```

**描述**

删除场景模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| sceneModes | 要删除的[Camera_SceneMode](#camera_scenemode)列表。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_DeleteSupportedCameraOutputCapability()

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameraOutputCapability(Camera_Manager* cameraManager, Camera_OutputCapability* cameraOutputCapability)
```

**描述**

删除支持的输出功能。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| cameraOutputCapability | 要删除的[Camera_OutputCapability](_camera___output_capability.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_DeleteSupportedCameras()

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameras(Camera_Manager* cameraManager, Camera_Device* cameras, uint32_t size)
```

**描述**

删除支持的相机。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| cameras | 要删除的[Camera_Device](_camera___device.md)列表。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_GetSupportedCameraOutputCapability()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapability(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_OutputCapability** cameraOutputCapability)
```

**描述**

查询指定相机在指定模式下支持的输出能力。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| cameras | 要查询的[Camera_Device](_camera___device.md)。 | 
| cameraOutputCapability | 如果方法调用成功，则将记录支持的[Camera_OutputCapability](_camera___output_capability.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_SceneMode sceneMode, Camera_OutputCapability** cameraOutputCapability)
```

**描述**

查询指定相机在指定模式下支持的输出能力。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| camera | 被查询的[Camera_Device](_camera___device.md)。 | 
| sceneMode | 指定相机模式[Camera_SceneMode](#camera_scenemode)。 | 
| cameraOutputCapability | 如果方法调用成功，则将记录支持的[Camera_OutputCapability](_camera___output_capability.md)列表。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_GetSupportedCameras()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameras(Camera_Manager* cameraManager, Camera_Device** cameras, uint32_t* size)
```

**描述**

获取支持相机的描述。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| cameras | 如果方法调用成功，则将记录支持的[Camera_Device](_camera___device.md)列表。 | 
| size | 如果方法调用成功，则将记录支持的[Camera_Device](_camera___device.md)列表的大小。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_GetSupportedSceneModes()

```
Camera_ErrorCode OH_CameraManager_GetSupportedSceneModes(Camera_Device* camera, Camera_SceneMode** sceneModes, uint32_t* size)
```

**描述**

获取特定相机支持的场景模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| camera | 要查询的[Camera_Device](_camera___device.md)。 | 
| sceneModes | 如果方法调用成功，则将记录支持的[Camera_SceneMode](#camera_scenemode)列表。 | 
| size | 如果方法调用成功，则将记录支持的[Camera_SceneMode](#camera_scenemode)的列表大小。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_IsCameraMuted()

```
Camera_ErrorCode OH_CameraManager_IsCameraMuted(Camera_Manager* cameraManager, bool* isCameraMuted)
```

**描述**

确定相机是否静音。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| isCameraMuted | 如果方法调用成功，将判断相机是否静音。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_IsTorchSupported()

```
Camera_ErrorCode OH_CameraManager_IsTorchSupported(Camera_Manager* cameraManager, bool* isTorchSupported)
```

**描述**

检查设备是否支持手电筒。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| isTorchSupported | 设备是否支持手电筒。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_IsTorchSupportedByTorchMode()

```
Camera_ErrorCode OH_CameraManager_IsTorchSupportedByTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode, bool* isTorchSupported)
```

**描述**

检查设备是否支持指定的手电筒模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| torchMode | 要检查的[Camera_TorchMode](#camera_torchmode-1)。 | 
| isTorchSupported | 设备是否支持指定的手电筒模式。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_RegisterCallback()

```
Camera_ErrorCode OH_CameraManager_RegisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)
```

**描述**

注册相机状态更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| callback | 要注册的[CameraManager_Callbacks](_camera_manager___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_RegisterTorchStatusCallback()

```
Camera_ErrorCode OH_CameraManager_RegisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)
```

**描述**

注册手电筒状态变更事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| torchStatusCallback | 要注册的[OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_SetTorchMode()

```
Camera_ErrorCode OH_CameraManager_SetTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode)
```

**描述**

设置相机手电筒模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| torchMode | 要设置的[Camera_TorchMode](#camera_torchmode)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：如果相机服务出现致命错误。


### OH_CameraManager_UnregisterCallback()

```
Camera_ErrorCode OH_CameraManager_UnregisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)
```

**描述**

注销摄像机状态更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| callback | 要注销的[CameraManager_Callbacks](_camera_manager___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraManager_UnregisterTorchStatusCallback()

```
Camera_ErrorCode OH_CameraManager_UnregisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)
```

**描述**

注销手电筒状态变更事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cameraManager | 相机管理器实例[Camera_Manager](#camera_manager)。 | 
| torchStatusCallback | 要注销的[OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。



### OH_CaptureSession_AddInput()

```
Camera_ErrorCode OH_CaptureSession_AddInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**描述**

添加相机输入。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| cameraInput | 要添加的目标[Camera_Input](#camera_input)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_AddMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_AddMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)
```

**描述**

添加元数据输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| metadataOutput | 要添加的目标[Camera_MetadataOutput](#camera_metadataoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_AddPhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**描述**

添加拍照输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| photoOutput | 要添加的目标[Camera_PhotoOutput](#camera_photooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_AddPreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**描述**

添加预览输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| previewOutput | 要添加的目标[Camera_PreviewOutput](#camera_previewoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_AddSecureOutput()

```
Camera_ErrorCode OH_CaptureSession_AddSecureOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**描述**

把其中一条PreviewOutput标记成安全输出。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| previewOutput | 要标记为安全输出的[Camera_PreviewOutput](#camera_previewoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。

- CAMERA_SESSION_CONFIG_LOCKED：会话配置已锁定。


### OH_CaptureSession_AddVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**描述**

添加录像输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| videoOutput | 要添加的目标[Camera_VideoOutput](#camera_videooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_BeginConfig()

```
Camera_ErrorCode OH_CaptureSession_BeginConfig(Camera_CaptureSession* session)
```

**描述**

开始捕获会话配置。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_CanAddInput()

```
Camera_ErrorCode OH_CaptureSession_CanAddInput(Camera_CaptureSession* session, Camera_Input* cameraInput, bool* isSuccessful)
```

**描述**

确定是否可以将相机输入添加到会话中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| cameraInput | 要设置的[Camera_Input](#camera_input)。 | 
| isSuccessful | 是否可以将相机输入添加到会话中的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_CanAddPhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* cameraOutput, bool* isSuccessful)
```

**描述**

确定是否可以将相机照片输出添加到会话中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| cameraOutput | 要设置的[Camera_PhotoOutput](#camera_photooutput)。 | 
| isSuccessful | 相机照片输出是否可以添加到会话中的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_CanAddPreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* cameraOutput, bool* isSuccessful)
```

**描述**

确定是否可以将相机预览输出添加到会话中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| cameraOutput | 要设置的[Camera_PreviewOutput](#camera_previewoutput)。 | 
| isSuccessful | 是否可以将相机预览输出添加到会话中的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_CanAddVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* cameraOutput, bool* isSuccessful)
```

**描述**

确定是否可以将相机视频输出添加到会话中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| cameraOutput | 要添加的[Camera_VideoOutput](#camera_videooutput)。 | 
| isSuccessful | 相机视频输出是否可以添加到会话中的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_CanPreconfig()

```
Camera_ErrorCode OH_CaptureSession_CanPreconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, bool* canPreconfig)
```

**描述**

检查是否支持指定的预配置类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| preconfigType | 要检查的预配置类型[Camera_PreconfigType](#camera_preconfigtype)。 | 
| canPreconfig | 是否支持预配置的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_CanPreconfigWithRatio()

```
Camera_ErrorCode OH_CaptureSession_CanPreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio, bool* canPreconfig)
```

**描述**

检查是否支持带比例的预配置类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| preconfigType | 要检查支持的类型[Camera_PreconfigType](#camera_preconfigtype)。 | 
| preconfigRatio | 要检查支持的比例[Camera_PreconfigRatio](#camera_preconfigratio)。 | 
| canPreconfig | 是否支持预配置的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_CommitConfig()

```
Camera_ErrorCode OH_CaptureSession_CommitConfig(Camera_CaptureSession* session)
```

**描述**

提交捕获会话配置。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CaptureSession_DeleteColorSpaces()

```
Camera_ErrorCode OH_CaptureSession_DeleteColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)
```

**描述**

删除色彩空间列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| colorSpace | 如果方法调用成功，将删除的目前[OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1)列表。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_GetActiveColorSpace()

```
Camera_ErrorCode OH_CaptureSession_GetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)
```

**描述**

获取当前色彩空间。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| colorSpace | 当前的[OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBias(Camera_CaptureSession* session, float* exposureBias)
```

**描述**

获取当前曝光补偿。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| exposureBias | 当前的曝光补偿。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetExposureBiasRange()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange(Camera_CaptureSession* session, float* minExposureBias, float* maxExposureBias, float* step)
```

**描述**

查询曝光补偿范围。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| minExposureBias | 曝光补偿的最小值。 | 
| maxExposureBias | 曝光补偿的最大值。 | 
| step | 每个级别之间的曝光补偿阶梯。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_GetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode* exposureMode)
```

**描述**

获取当前曝光模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| exposureMode | 当前的[Camera_ExposureMode](#camera_exposuremode)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetExposureValue()

```
Camera_ErrorCode OH_CaptureSession_GetExposureValue(Camera_CaptureSession* session, float* exposureValue)
```

**描述**

查询曝光值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| exposureValue | 当前的曝光值。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CaptureSession_GetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_GetFlashMode(Camera_CaptureSession* session, Camera_FlashMode* flashMode)
```

**描述**

获取当前闪光灯模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| flashMode | 当前[Camera_FlashMode](#camera_flashmode)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetFocalLength()

```
Camera_ErrorCode OH_CaptureSession_GetFocalLength(Camera_CaptureSession* session, float* focalLength)
```

**描述**

获取当前焦距值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| focalLength | 当前焦距值。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_GetFocusMode(Camera_CaptureSession* session, Camera_FocusMode* focusMode)
```

**描述**

获取当前聚焦模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| exposureBias | 当前[Camera_FocusMode](#camera_focusmode)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_GetFocusPoint(Camera_CaptureSession* session, Camera_Point* focusPoint)
```

**描述**

获取当前焦点。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| focusPoint | 当前[Camera_Point](_camera___point.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_GetMeteringPoint(Camera_CaptureSession* session, Camera_Point* point)
```

**描述**

获取当前测量点。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| point | 当前[Camera_Point](_camera___point.md)测量点。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetSupportedColorSpaces()

```
Camera_ErrorCode OH_CaptureSession_GetSupportedColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace** colorSpace, uint32_t* size)
```

**描述**

获取支持的色彩空间列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| colorSpace | 如果方法调用成功，则将记录支持的[OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1)列表。 | 
| size | 如果方法调用成功，则将记录支持的[OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1)列表的大小。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode* mode)
```

**描述**

获取当前录像防抖模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| mode | 当前[Camera_VideoStabilizationMode](#camera_videostabilizationmode)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatio(Camera_CaptureSession* session, float* zoom)
```

**描述**

获取当前缩放比例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| zoom | 当前缩放比例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_GetZoomRatioRange()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange(Camera_CaptureSession* session, float* minZoom, float* maxZoom)
```

**描述**

获取所有支持的缩放比例范围。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| minZoom | 缩放比范围的最小值。 | 
| maxZoom | 缩放比例范围的最大值。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_HasFlash()

```
Camera_ErrorCode OH_CaptureSession_HasFlash(Camera_CaptureSession* session, bool* hasFlash)
```

**描述**

检查设备是否有闪光灯。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| hasFlash | 是否支持闪光灯的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_IsExposureModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported(Camera_CaptureSession* session, Camera_ExposureMode exposureMode, bool* isSupported)
```

**描述**

检查是否支持指定的曝光模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| exposureMode | 要检查的[Camera_ExposureMode](#camera_exposuremode)。 | 
| isSupported | 是否支持曝光模式的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_IsFlashModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported(Camera_CaptureSession* session, Camera_FlashMode flashMode, bool* isSupported)
```

**描述**

检查是否支持指定的闪光灯模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| flashMode | 要检查的[Camera_FlashMode](#camera_flashmode)。 | 
| isSupported | 是否支持闪光灯模式的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_IsFocusModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported(Camera_CaptureSession* session, Camera_FocusMode focusMode, bool* isSupported)
```

**描述**

检查是否支持指定的聚焦模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| focusMode | 要检查的[Camera_FocusMode](#camera_focusmode-1)。 | 
| isSupported | 是否支持聚焦模式的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_IsVideoStabilizationModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode, bool* isSupported)
```

**描述**

检查是否支持指定的录像防抖模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| mode | 要检查的[Camera_VideoStabilizationMode](#camera_videostabilizationmode-1)。 | 
| isSupported | 是否支持录像防抖模式的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_Preconfig()

```
Camera_ErrorCode OH_CaptureSession_Preconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType)
```

**描述**

设置预配置类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| preconfigType | 要检查支持的类型[Camera_PreconfigType](#camera_preconfigtype-1)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CaptureSession_PreconfigWithRatio()

```
Camera_ErrorCode OH_CaptureSession_PreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio)
```

**描述**

设置带有比例的预配置类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| preconfigType | 要检查支持的类型[Camera_PreconfigType](#camera_preconfigtype-1)。 | 
| preconfigRatio | 要检查支持的比例[Camera_PreconfigRatio](#camera_preconfigratio-1)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CaptureSession_RegisterCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)
```

**描述**

注册捕获会话事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| callback | 要注册的[CaptureSession_Callbacks](_capture_session___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_RegisterSmoothZoomInfoCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**描述**

注册平滑变焦信息事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| smoothZoomInfoCallback | 要注册的[OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_Release()

```
Camera_ErrorCode OH_CaptureSession_Release(Camera_CaptureSession* session)
```

**描述**

释放捕获会话。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | 要释放的[Camera_CaptureSession](#camera_capturesession)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CaptureSession_RemoveInput()

```
Camera_ErrorCode OH_CaptureSession_RemoveInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**描述**

删除相机输入。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| cameraInput | 要删除的目标[Camera_Input](#camera_input)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_RemoveMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)
```

**描述**

删除元数据输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| metadataOutput | 要删除的目标[Camera_MetadataOutput](#camera_metadataoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_RemovePhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**描述**

删除拍照输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| photoOutput | 要删除的目标[Camera_PhotoOutput](#camera_photooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_RemovePreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**描述**

删除预览输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| previewOutput | 要删除的目标[Camera_PreviewOutput](#camera_previewoutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_RemoveVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**描述**

删除录像输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| videoOutput | 要删除的目标[Camera_VideoOutput](#camera_videooutput)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。


### OH_CaptureSession_SetActiveColorSpace()

```
Camera_ErrorCode OH_CaptureSession_SetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace colorSpace)
```

**描述**

设置当前色彩空间。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| colorSpace | 要设置的目标[OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_SetExposureBias(Camera_CaptureSession* session, float exposureBias)
```

**描述**

设置曝光补偿。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| exposureBias | 要设置的目标曝光补偿。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_SetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode exposureMode)
```

**描述**

设置曝光模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| exposureMode | 要设置的目标[Camera_ExposureMode](#camera_exposuremode-1)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_SetFlashMode(Camera_CaptureSession* session, Camera_FlashMode flashMode)
```

**描述**

设置闪光灯模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| flashMode | 要设置的目标[Camera_FlashMode](#camera_flashmode-1)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_SetFocusMode(Camera_CaptureSession* session, Camera_FocusMode focusMode)
```

**描述**

设置聚焦模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| focusMode | 要设置的目标[Camera_FocusMode](#camera_focusmode-1)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_SetFocusPoint(Camera_CaptureSession* session, Camera_Point focusPoint)
```

**描述**

设置焦点。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| focusPoint | 要设置的目标[Camera_Point](_camera___point.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_SetMeteringPoint(Camera_CaptureSession* session, Camera_Point point)
```

**描述**

设置计量区域的中心点。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| point | 要设置的目标[Camera_Point](_camera___point.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetQualityPrioritization()

```
Camera_ErrorCode OH_CaptureSession_SetQualityPrioritization(Camera_CaptureSession* session, Camera_QualityPrioritization qualityPrioritization)
```

**描述**

设置录像质量优先级。

> **说明：**
> 默认为高质量，设置为功耗平衡将降低录像质量以减少功耗。实际功耗收益因平台而异。

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| qualityPrioritization | 要设置的质量优先级[Camera_QualityPrioritization ](#camera_qualityprioritization)（默认为高质量）。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetSessionMode()

```
Camera_ErrorCode OH_CaptureSession_SetSessionMode(Camera_CaptureSession* session, Camera_SceneMode sceneMode)
```

**描述**

设置会话模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| sceneMode | [Camera_SceneMode](#camera_scenemode-1)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。

- CAMERA_OPERATION_NOT_ALLOWED：不允许操作。

- CAMERA_SESSION_CONFIG_LOCKED：会话配置已锁定。


### OH_CaptureSession_SetSmoothZoom()

```
Camera_ErrorCode OH_CaptureSession_SetSmoothZoom(Camera_CaptureSession* session, float targetZoom, Camera_SmoothZoomMode smoothZoomMode)
```

**描述**

触发平滑变焦。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| targetZoom | 要设置的目标变焦比。 | 
| smoothZoomMode | [Camera_SmoothZoomMode](#camera_smoothzoommode)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode)
```

**描述**

设置录像防抖模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| mode | 要设置的目标[Camera_VideoStabilizationMode](#camera_videostabilizationmode)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_SetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_SetZoomRatio(Camera_CaptureSession* session, float zoom)
```

**描述**

设置缩放比例。

**起始版本：** 11

**参数:**

| 名称 | 描述                                                        | 
| -------- |-----------------------------------------------------------|
| session | [Camera_CaptureSession](#camera_capturesession)实例。        | 
| zoom | 要设置的目标缩放比。<br>设置可变焦距比到底层生效需要一定时间，获取正确设置的可变焦距比需要等待1~2帧的时间。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。


### OH_CaptureSession_Start()

```
Camera_ErrorCode OH_CaptureSession_Start(Camera_CaptureSession* session)
```

**描述**

启动捕获会话。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | 要启动的[Camera_CaptureSession](#camera_capturesession)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CaptureSession_Stop()

```
Camera_ErrorCode OH_CaptureSession_Stop(Camera_CaptureSession* session)
```

**描述**

停止捕获会话。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | 要停止的[Camera_CaptureSession](#camera_capturesession)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CaptureSession_UnregisterCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)
```

**描述**

注销捕获会话事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| callback | 要注销的[CaptureSession_Callbacks](_capture_session___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CaptureSession_UnregisterSmoothZoomInfoCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**描述**

注销平滑变焦信息事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| session | [Camera_CaptureSession](#camera_capturesession)实例。 | 
| smoothZoomInfoCallback | 要注销的[OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_MetadataOutput_RegisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
```

**描述**

注册元数据输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataOutput | [Camera_MetadataOutput](#camera_metadataoutput)实例。 | 
| callback | 要注册的[MetadataOutput_Callbacks](_metadata_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_MetadataOutput_Release()

```
Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput)
```

**描述**

释放元数据输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataOutput | 要释放的[Camera_MetadataOutput](#camera_metadataoutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_MetadataOutput_Start()

```
Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput)
```

**描述**

启动元数据输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataOutput | 要启动的[Camera_MetadataOutput](#camera_metadataoutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_MetadataOutput_Stop()

```
Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput)
```

**描述**

停止元数据输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataOutput | 要停止的[Camera_MetadataOutput](#camera_metadataoutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_MetadataOutput_UnregisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
```

**描述**

注销元数据输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataOutput | [Camera_MetadataOutput](#camera_metadataoutput)实例。 | 
| callback | 要注销的[MetadataOutput_Callbacks](_metadata_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoNative_GetMainImage()

```
Camera_ErrorCode OH_PhotoNative_GetMainImage(OH_PhotoNative* photo, OH_ImageNative** mainImage)
```

**描述**

获取全质量图。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photo | [OH_PhotoNative](#oh_photonative)实例。 | 
| mainImage | 用于获取全质量图的[OH_ImageNative](../apis-image-kit/_image___native_module.md#oh_imagenative)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoNative_Release()

```
Camera_ErrorCode OH_PhotoNative_Release(OH_PhotoNative* photo)
```

**描述**

释放全质量图实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photo | 要被释放的[OH_PhotoNative](#oh_photonative)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_Capture()

```
Camera_ErrorCode OH_PhotoOutput_Capture(Camera_PhotoOutput* photoOutput)
```

**描述**

拍摄照片。

OH_PhotoOutput_Capture()必须在OH_PreviewOutput_Release()之前调用，否则会导致无法拍照。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 用于捕获拍照的[Camera_PhotoOutput](#camera_photooutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_RUNNING：捕获会话未运行。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_Capture_WithCaptureSetting()

```
Camera_ErrorCode OH_PhotoOutput_Capture_WithCaptureSetting(Camera_PhotoOutput* photoOutput, Camera_PhotoCaptureSetting setting)
```

**描述**

使用捕获设置捕获拍照。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 用于捕获拍照的[Camera_PhotoOutput](#camera_photooutput)实例。 | 
| setting | 用于捕获拍照的[Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_RUNNING：捕获会话未运行。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_DeleteProfile()

```
Camera_ErrorCode OH_PhotoOutput_DeleteProfile(Camera_Profile* profile)
```

**描述**

删除照片配置文件实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| profile | 要被删除的[Camera_Profile](_camera___profile.md)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_EnableMovingPhoto()

```
Camera_ErrorCode OH_PhotoOutput_EnableMovingPhoto(Camera_PhotoOutput* photoOutput, bool enabled)
```

**描述**

是否启用动态照片。

**起始版本：** 12

**需要权限：** ohos.permission.MICROPHONE

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 用来启用或禁用动态照片的[Camera_PhotoOutput](#camera_photooutput)实例。 | 
| enabled | 是否启用动态照片。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_GetActiveProfile()

```
Camera_ErrorCode OH_PhotoOutput_GetActiveProfile(Camera_PhotoOutput* photoOutput, Camera_Profile** profile)
```

**描述**

获取当前照片输出配置文件。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 传递当前配置文件的[Camera_PhotoOutput](#camera_photooutput)实例。 | 
| profile | 如果方法调用成功，则将记录[Camera_Profile](_camera___profile.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_IsMirrorSupported()

```
Camera_ErrorCode OH_PhotoOutput_IsMirrorSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)
```

**描述**

检查是否支持镜像拍照。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例，用于检查是否支持镜像。 | 
| isSupported | 是否支持镜像的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_EnableMirror()

```
Camera_ErrorCode OH_PhotoOutput_EnableMirror(Camera_PhotoOutput* photoOutput, bool enabled)
```

**描述**

是否启用动态照片镜像拍照。

**起始版本：** 13

**参数:**

| 名称          | 描述                                                      | 
|-------------|---------------------------------------------------------|
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例，用于是否启用镜像拍照。 | 
| enabled     | 是否启用动态照片镜像拍照的结果，true为开启动态照片镜像拍照，false为关闭动态照片镜像拍照。        | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_IsMovingPhotoSupported()

```
Camera_ErrorCode OH_PhotoOutput_IsMovingPhotoSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)
```

**描述**

检查是否支持动态照片。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 用来检查是否支持动态照片的[Camera_PhotoOutput](#camera_photooutput)实例。 | 
| isSupported | 是否支持动态照片的结果。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_RegisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)
```

**描述**

注册拍照输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[PhotoOutput_Callbacks](_photo_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_RegisterCaptureEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureEnd callback)
```

**描述**

注册拍照结束事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_RegisterCaptureReadyCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureReady callback)
```

**描述**

注册拍照就绪事件回调。收到回调后，可以继续进行下一次拍照。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_RegisterCaptureStartWithInfoCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureStartWithInfo callback)
```

**描述**

注册拍照开始事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_EstimatedCaptureDuration callback)
```

**描述**

注册预计拍照时间事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_RegisterFrameShutterEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_OnFrameShutterEnd callback)
```

**描述**

注册拍照曝光结束事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_RegisterPhotoAssetAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAssetAvailable callback)
```

**描述**

注册输出照片资源可用回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_RegisterPhotoAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAvailable callback)
```

**描述**

注册输出照片可用回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注册的[OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_Release()

```
Camera_ErrorCode OH_PhotoOutput_Release(Camera_PhotoOutput* photoOutput)
```

**描述**

释放拍照输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | 要释放的[Camera_PhotoOutput](#camera_photooutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PhotoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)
```

**描述**

注销拍照输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[PhotoOutput_Callbacks](_photo_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_UnregisterCaptureEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureEnd callback)
```

**描述**

注销拍照结束事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_UnregisterCaptureReadyCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureReady callback)
```

**描述**

注销拍照就绪事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。



### OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureStartWithInfo callback)
```

**描述**

注销拍照开始事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_EstimatedCaptureDuration callback)
```

**描述**

注销预计拍照时间事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_UnregisterFrameShutterEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_OnFrameShutterEnd callback)
```

**描述**

注销拍照曝光结束事件回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAssetAvailable callback)
```

**描述**

注销输出照片资源可用回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PhotoOutput_UnregisterPhotoAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAvailable callback)
```

**描述**

注销输出照片可用回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| photoOutput | [Camera_PhotoOutput](#camera_photooutput)实例。 | 
| callback | 要注销的[PhotoOutput_Callbacks](_photo_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PreviewOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)
```

**描述**

删除帧率列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | [Camera_PreviewOutput](#camera_previewoutput)实例。 | 
| frameRateRange | 要删除的[Camera_FrameRateRange](_camera___frame_rate_range.md)列表。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PreviewOutput_DeleteProfile()

```
Camera_ErrorCode OH_PreviewOutput_DeleteProfile(Camera_Profile* profile)
```

**描述**

删除预览配置文件实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| profile | 要被删除的[Camera_Profile](_camera___profile.md)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PreviewOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)
```

**描述**

获取当前预览输出帧率。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 传递当前预览输出帧率的[Camera_PreviewOutput](#camera_previewoutput)实例。 | 
| frameRateRange | 如果方法调用成功，则将记录当前的[Camera_FrameRateRange](_camera___frame_rate_range.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PreviewOutput_GetActiveProfile()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveProfile(Camera_PreviewOutput* previewOutput, Camera_Profile** profile)
```

**描述**

获取当前预览输出配置文件。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 提供当前预览输出配置文件的[Camera_PreviewOutput](#camera_previewoutput)实例。 | 
| profile | 如果方法调用成功，则将记录当前的[Camera_Profile](_camera___profile.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PreviewOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**描述**

获取支持的预览输出帧率列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 传递支持的帧率列表的[Camera_PreviewOutput](#camera_previewoutput)实例。 | 
| frameRateRange | 如果方法调用成功，则将记录支持的[Camera_FrameRateRange](_camera___frame_rate_range.md)列表。 | 
| size | 如果方法调用成功，则将记录支持的[Camera_FrameRateRange](_camera___frame_rate_range.md)列表大小。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PreviewOutput_RegisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)
```

**描述**

注册预览输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | [Camera_PreviewOutput](#camera_previewoutput)实例。 | 
| callback | 要注册的[PreviewOutput_Callbacks](_preview_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PreviewOutput_Release()

```
Camera_ErrorCode OH_PreviewOutput_Release(Camera_PreviewOutput* previewOutput)
```

**描述**

释放预览输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 要释放的[Camera_PreviewOutput](#camera_previewoutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PreviewOutput_SetFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput, int32_t minFps, int32_t maxFps)
```

**描述**

设置预览输出帧率。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 要设置帧率的[Camera_PreviewOutput](#camera_previewoutput)实例。 | 
| minFps | 要设置的最小值。 | 
| maxFps | 要设置的最大值。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_PreviewOutput_Start()

```
Camera_ErrorCode OH_PreviewOutput_Start(Camera_PreviewOutput* previewOutput)
```

**描述**

开始预览输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 要启动的[Camera_PreviewOutput](#camera_previewoutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PreviewOutput_Stop()

```
Camera_ErrorCode OH_PreviewOutput_Stop(Camera_PreviewOutput* previewOutput)
```

**描述**

停止预览输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | 要停止的[Camera_PreviewOutput](#camera_previewoutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_PreviewOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)
```

**描述**

注销预览输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| previewOutput | [Camera_PreviewOutput](#camera_previewoutput)实例。 | 
| callback | 要注销的[PreviewOutput_Callbacks](_preview_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_VideoOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_VideoOutput_DeleteFrameRates(Camera_VideoOutput* videoOutput, Camera_FrameRateRange* frameRateRange)
```

**描述**

删除帧率列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | [Camera_VideoOutput](#camera_videooutput)实例。 | 
| frameRateRange | 要删除的[Camera_FrameRateRange](_camera___frame_rate_range.md)列表。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_VideoOutput_DeleteProfile()

```
Camera_ErrorCode OH_VideoOutput_DeleteProfile(Camera_VideoProfile* profile)
```

**描述**

删除视频配置文件实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| profile | 要删除的[Camera_VideoProfile](_camera___video_profile.md)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_VideoOutput_EnableMirror()

```
Camera_ErrorCode OH_VideoOutput_EnableMirror(Camera_VideoOutput* videoOutput, bool mirrorMode)
```

**描述**

打开/关闭当前视频输出镜像功能。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递当前视频输出的[Camera_VideoOutput](#camera_videooutput)实例。 | 
| mirrorMode | TRUE表示打开镜像功能, FALSE表示关闭镜像功能。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。
- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。
- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_VideoOutput_GetActiveFrameRate(Camera_VideoOutput* videoOutput, Camera_FrameRateRange* frameRateRange)
```

**描述**

获取当前视频输出帧率。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递当前视频输出帧率的[Camera_VideoOutput](#camera_videooutput)实例。 | 
| frameRateRange | 如果方法调用成功，则将记录当前的[Camera_FrameRateRange](_camera___frame_rate_range.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_GetActiveProfile()

```
Camera_ErrorCode OH_VideoOutput_GetActiveProfile(Camera_VideoOutput* videoOutput, Camera_VideoProfile** profile)
```

**描述**

获取当前视频输出配置文件。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递当前视频输出配置文件的[Camera_VideoOutput](#camera_videooutput)实例。 | 
| profile | 如果方法调用成功，则将记录当前的[Camera_VideoProfile](_camera___video_profile.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_VideoOutput_GetSupportedFrameRates(Camera_VideoOutput* videoOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**描述**

获取支持的视频输出帧率列表。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递支持的视频输出帧率列表的[Camera_VideoOutput](#camera_videooutput)实例。 | 
| frameRateRange | 如果方法调用成功，则将记录支持的[Camera_FrameRateRange](_camera___frame_rate_range.md)列表。 | 
| size | 如果方法调用成功，则将记录支持的[Camera_FrameRateRange](_camera___frame_rate_range.md)列表大小。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_GetVideoRotation()

```
Camera_ErrorCode  OH_VideoOutput_GetVideoRotation(Camera_VideoOutput* videoOutput, int deviceDegree, Camera_ImageRotation* imageRotation)
```

**描述**

获取当前视频输出应当设置的旋转角度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递当前视频输出的[Camera_VideoOutput](#camera_videooutput)实例。 | 
| deviceDegree | 设备目前相对于自然方向（充电口朝下）顺时针的旋转角度。 | 
| imageRotation | 当前视频输出应当设置的旋转角度。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。 
- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。
- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_IsMirrorSupported()

```
Camera_ErrorCode OH_VideoOutput_IsMirrorSupported(Camera_VideoOutput* videoOutput, bool* isSupported)
```

**描述**

判断当前视频输出是否支持镜像。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 传递当前视频输出的[Camera_VideoOutput](#camera_videooutput)实例。 | 
| isSupported | 当前视频输出是否支持镜像。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。 
- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。
- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_RegisterCallback()

```
Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**描述**

注册录像输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | [Camera_VideoOutput](#camera_videooutput)实例。 | 
| callback | 要注册的[VideoOutput_Callbacks](_video_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_VideoOutput_Release()

```
Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput)
```

**描述**

释放录像输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 要释放的[Camera_VideoOutput](#camera_videooutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_SetFrameRate()

```
Camera_ErrorCode OH_VideoOutput_SetFrameRate(Camera_VideoOutput* videoOutput, int32_t minFps, int32_t maxFps)
```

**描述**

设置视频输出帧率。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 要设置帧率的[Camera_VideoOutput](#camera_videooutput)实例。 | 
| minFps      | 设置的最小帧率。                                |
| maxFps      | 设置的最大帧率。                                |

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_VideoOutput_Start()

```
Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput)
```

**描述**

开始录像输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 要启动的[Camera_VideoOutput](#camera_videooutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SESSION_NOT_CONFIG：捕获会话未配置。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_Stop()

```
Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput)
```

**描述**

停止录像输出。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | 要停止的[Camera_VideoOutput](#camera_videooutput)实例。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_VideoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**描述**

注销录像输出更改事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| videoOutput | [Camera_VideoOutput](#camera_videooutput)实例。 | 
| callback | 要注销的[VideoOutput_Callbacks](_video_output___callbacks.md)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功。

- CAMERA_INVALID_ARGUMENT：参数丢失或参数类型不正确。


### OH_CameraDevice_GetHostDeviceName()

```
Camera_ErrorCode OH_CameraDevice_GetHostDeviceName(Camera_Device* camera, char** hostDeviceName)
```

**描述**

获取远程设备名称。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| camera | 用来获取属性的[Camera_Device](_camera___device.md)。 | 
| hostDeviceName | 返回远程设备名称属性。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功，将返回远程设备名称属性。 

- CAMERA_INVALID_ARGUMENT：参数丢失或者参数不正确。 

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。


### OH_CameraDevice_GetHostDeviceType()

```
Camera_ErrorCode OH_CameraDevice_GetHostDeviceType(Camera_Device* camera, Camera_HostDeviceType* hostDeviceType)
```

**描述**

获取远程设备类型。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| camera | 用来获取属性的[Camera_Device](_camera___device.md)。 | 
| hostDeviceType | 返回远程设备类型属性[Camera_HostDeviceType](#camera_hostdevicetype)。 | 

**返回：**

错误码[Camera_ErrorCode](#camera_errorcode-1)：

- CAMERA_OK：方法调用成功，将返回远程设备名称属性。 

- CAMERA_INVALID_ARGUMENT：参数丢失或者参数不正确。 

- CAMERA_SERVICE_FATAL_ERROR：相机服务出现致命错误。