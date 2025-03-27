# camera.h


## Overview

The **camera.h** file declares the basic concepts of the camera.

**Library**: libohcamera.so

**File to include**: &lt;ohcamera/camera.h&gt; 

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [Camera_Size](_camera___size.md) | Describes the parameters related to the size.| 
| struct  [Camera_Profile](_camera___profile.md) | Describes the profile of a camera stream.| 
| struct  [Camera_FrameRateRange](_camera___frame_rate_range.md) | Describes the frame rate range.| 
| struct  [Camera_VideoProfile](_camera___video_profile.md) | Describes the video profile.| 
| struct  [Camera_OutputCapability](_camera___output_capability.md) | Describes the camera output capability.| 
| struct  [Camera_Device](_camera___device.md) | Describes the camera device.| 
| struct  [Camera_StatusInfo](_camera___status_info.md) | Describes the camera status information.| 
| struct  [Camera_Point](_camera___point.md) | Describes the parameters related to a point.| 
| struct  [Camera_Location](_camera___location.md) | Describes the location where the photo is taken.| 
| struct  [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) | Describes the parameters related to photo capture.| 
| struct  [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) | Describes the frame shutter information.| 
| struct  [Camera_CaptureEndInfo](_camera___capture_end_info.md) | Describes the capture end information.| 
| struct  [Camera_Rect](_camera___rect.md) | Defines the rectangle.| 
| struct  [Camera_MetadataObject](_camera___metadata_object.md) | Describes the camera metadata.| 
| struct  [Camera_TorchStatusInfo](_camera___torch_status_info.md) | Describes the flashlight status information.| 
| struct  [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) | Describes the smooth zoom information.| 
| struct  [Camera_CaptureStartInfo](_camera___capture_start_info.md) | Describes the capture start information.| 
| struct  [Camera_FrameShutterEndInfo](_camera___frame_shutter_end_info.md) | Describes the frame shutter end information during capture.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_Manager](_o_h___camera.md#camera_manager) [Camera_Manager](_o_h___camera.md#camera_manager) | Defines a struct for the camera manager.| 
| typedef enum [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) | Defines an enum for the camera error codes.| 
| typedef enum [Camera_Status](_o_h___camera.md#camera_status) [Camera_Status](_o_h___camera.md#camera_status) | Defines an enum for the camera statuses.| 
| typedef enum [Camera_SceneMode](_o_h___camera.md#camera_scenemode) [Camera_SceneMode](_o_h___camera.md#camera_scenemode) | Defines an enum for the camera scene modes.| 
| typedef enum [Camera_Position](_o_h___camera.md#camera_position) [Camera_Position](_o_h___camera.md#camera_position) | Defines an enum for the camera positions.| 
| typedef enum [Camera_Type](_o_h___camera.md#camera_type) [Camera_Type](_o_h___camera.md#camera_type) | Defines an enum for the camera types.| 
| typedef enum [Camera_Connection](_o_h___camera.md#camera_connection) [Camera_Connection](_o_h___camera.md#camera_connection) | Defines an enum for the camera connection types.| 
| typedef enum [Camera_Format](_o_h___camera.md#camera_format) [Camera_Format](_o_h___camera.md#camera_format) | Defines an enum for the camera output formats.| 
| typedef enum [Camera_FlashMode](_o_h___camera.md#camera_flashmode) [Camera_FlashMode](_o_h___camera.md#camera_flashmode) | Defines an enum for the flash modes.| 
| typedef enum [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) | Defines an enum for the exposure modes.| 
| typedef enum [Camera_FocusMode](_o_h___camera.md#camera_focusmode) [Camera_FocusMode](_o_h___camera.md#camera_focusmode) | Defines an enum for the focus modes.| 
| typedef enum [Camera_FocusState](_o_h___camera.md#camera_focusstate) [Camera_FocusState](_o_h___camera.md#camera_focusstate) | Defines an enum for the focus states.| 
| typedef enum [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) | Defines an enum for the video stabilization modes.| 
| typedef enum [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) | Defines an enum for the image rotation angles.| 
| typedef enum [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) | Defines an enum for the image quality levels.| 
| typedef enum [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) | Defines an enum for the metadata object types.| 
| typedef enum [Camera_TorchMode](_o_h___camera.md#camera_torchmode) [Camera_TorchMode](_o_h___camera.md#camera_torchmode) | Defines an enum for the flashlight modes.| 
| typedef enum [Camera_SmoothZoomMode](_o_h___camera.md#camera_smoothzoommode) [Camera_SmoothZoomMode](_o_h___camera.md#camera_smoothzoommode) | Defines an enum for the smooth zoom modes.| 
| typedef enum [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype) | Defines an enum for the preconfigured photo resolution types.| 
| typedef enum [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio) [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio) | Defines an enum for the preconfigured photo aspect ratios.| 
| typedef enum [Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype)[Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype) | Defines an enum for the remote device types.| 
| typedef struct [Camera_Size](_camera___size.md) [Camera_Size](_o_h___camera.md#camera_size) | Defines a struct for the parameters related to the size.| 
| typedef struct [Camera_Profile](_camera___profile.md) [Camera_Profile](_o_h___camera.md#camera_profile) | Defines a struct for the profile of the camera stream.| 
| typedef struct [Camera_FrameRateRange](_camera___frame_rate_range.md) [Camera_FrameRateRange](_o_h___camera.md#camera_frameraterange) | Defines a struct for the frame rate range.| 
| typedef struct [Camera_VideoProfile](_camera___video_profile.md) [Camera_VideoProfile](_o_h___camera.md#camera_videoprofile) | Defines a struct for the video profile.| 
| typedef struct [Camera_OutputCapability](_camera___output_capability.md) [Camera_OutputCapability](_o_h___camera.md#camera_outputcapability) | Defines a struct for the camera output capability.| 
| typedef struct [Camera_Device](_camera___device.md) [Camera_Device](_o_h___camera.md#camera_device) | Defines a struct for the camera device.| 
| typedef struct [Camera_StatusInfo](_camera___status_info.md) [Camera_StatusInfo](_o_h___camera.md#camera_statusinfo) | Defines a struct for the camera status information.| 
| typedef struct [Camera_Point](_camera___point.md) [Camera_Point](_o_h___camera.md#camera_point) | Defines a struct for the parameters related to a point.| 
| typedef struct [Camera_Location](_camera___location.md) [Camera_Location](_o_h___camera.md#camera_location) | Defines a struct for the location where the photo is taken.| 
| typedef struct [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) [Camera_PhotoCaptureSetting](_o_h___camera.md#camera_photocapturesetting) | Defines a struct for the parameters related to photo capture.| 
| typedef struct [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) [Camera_FrameShutterInfo](_o_h___camera.md#camera_frameshutterinfo) | Defines a struct for the frame shutter information.| 
| typedef struct [Camera_CaptureEndInfo](_camera___capture_end_info.md) [Camera_CaptureEndInfo](_o_h___camera.md#camera_captureendinfo) | Defines a struct for the capture end information.| 
| typedef struct [Camera_Rect](_camera___rect.md) [Camera_Rect](_o_h___camera.md#camera_rect) | Defines a struct for the rectangle.| 
| typedef struct [Camera_MetadataObject](_camera___metadata_object.md) [Camera_MetadataObject](_o_h___camera.md#camera_metadataobject) | Defines a struct for the camera metadata.| 
| typedef struct [Camera_TorchStatusInfo](_camera___torch_status_info.md) [Camera_TorchStatusInfo](_o_h___camera.md#camera_torchstatusinfo) | Defines a struct for the flashlight status information.| 
| typedef struct [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) [Camera_SmoothZoomInfo](_o_h___camera.md#camera_smoothzoominfo) | Defines a struct for the smooth zoom information.| 
| typedef struct [Camera_CaptureStartInfo](_camera___capture_start_info.md) [Camera_CaptureStartInfo](_o_h___camera.md#camera_capturestartinfo) | Defines a struct for the capture start information.| 
| typedef struct [Camera_FrameShutterEndInfo](_camera___frame_shutter_end_info.md) [Camera_FrameShutterEndInfo](_o_h___camera.md#camera_frameshutterendinfo) | Defines a struct for the frame shutter end information during capture.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode-1) {<br>CAMERA_OK = 0,<br>CAMERA_INVALID_ARGUMENT = 7400101,<br>CAMERA_OPERATION_NOT_ALLOWED = 7400102,<br>CAMERA_SESSION_NOT_CONFIG = 7400103,<br>CAMERA_SESSION_NOT_RUNNING = 7400104,<br>CAMERA_SESSION_CONFIG_LOCKED = 7400105,<br>CAMERA_DEVICE_SETTING_LOCKED = 7400106,<br>CAMERA_CONFLICT_CAMERA = 7400107,<br>CAMERA_DEVICE_DISABLED = 7400108,<br>CAMERA_DEVICE_PREEMPTED = 7400109,<br>CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS = 7400110,<br>CAMERA_SERVICE_FATAL_ERROR = 7400201} | Enumerates the camera error codes.| 
| [Camera_Status](_o_h___camera.md#camera_status-1) {<br>CAMERA_STATUS_APPEAR = 0,<br>CAMERA_STATUS_DISAPPEAR = 1,<br>CAMERA_STATUS_AVAILABLE = 2,<br>CAMERA_STATUS_UNAVAILABLE = 3 } | Enumerates the camera statuses.| 
| [Camera_SceneMode](_o_h___camera.md#camera_scenemode-1) {<br>NORMAL_PHOTO = 1,<br>NORMAL_VIDEO = 2,<br>SECURE_PHOTO = 12 } | Enumerates the camera scene modes.| 
| [Camera_Position](_o_h___camera.md#camera_position-1) {<br>CAMERA_POSITION_UNSPECIFIED = 0,<br>CAMERA_POSITION_BACK = 1,<br>CAMERA_POSITION_FRONT = 2 } | Enumerates the camera positions.| 
| [Camera_Type](_o_h___camera.md#camera_type-1) {<br>CAMERA_TYPE_DEFAULT = 0,<br>CAMERA_TYPE_WIDE_ANGLE = 1,<br>CAMERA_TYPE_ULTRA_WIDE = 2,<br>CAMERA_TYPE_TELEPHOTO = 3,<br>CAMERA_TYPE_TRUE_DEPTH = 4<br>} | Enumerates the camera types.| 
| [Camera_Connection](_o_h___camera.md#camera_connection-1) {<br>CAMERA_CONNECTION_BUILT_IN = 0,<br>CAMERA_CONNECTION_USB_PLUGIN = 1,<br>CAMERA_CONNECTION_REMOTE = 2 } | Enumerates the camera connection types.| 
| [Camera_Format](_o_h___camera.md#camera_format-1) {<br>CAMERA_FORMAT_RGBA_8888 = 3,<br>CAMERA_FORMAT_YUV_420_SP = 1003,<br>CAMERA_FORMAT_JPEG = 2000,<br>CAMERA_FORMAT_YCBCR_P010 = 2001,<br>CAMERA_FORMAT_YCRCB_P010 = 2002<br>} | Enumerates the camera output formats.| 
| [Camera_FlashMode](_o_h___camera.md#camera_flashmode-1) {<br>FLASH_MODE_CLOSE = 0,<br>FLASH_MODE_OPEN = 1,<br>FLASH_MODE_AUTO = 2,<br>FLASH_MODE_ALWAYS_OPEN = 3 } | Enumerates the flash modes.| 
| [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode-1) {<br>EXPOSURE_MODE_LOCKED = 0,<br>EXPOSURE_MODE_AUTO = 1,<br>EXPOSURE_MODE_CONTINUOUS_AUTO = 2 } | Enumerates the exposure modes.| 
| [Camera_FocusMode](_o_h___camera.md#camera_focusmode-1) {<br>FOCUS_MODE_MANUAL = 0,<br>FOCUS_MODE_CONTINUOUS_AUTO = 1,<br>FOCUS_MODE_AUTO = 2,<br>FOCUS_MODE_LOCKED = 3 } | Enumerates the focus modes.| 
| [Camera_FocusState](_o_h___camera.md#camera_focusstate-1) {<br>FOCUS_STATE_SCAN = 0,<br>FOCUS_STATE_FOCUSED = 1,<br>FOCUS_STATE_UNFOCUSED = 2 } | Enumerates the focus states.| 
| [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode-1) {<br>STABILIZATION_MODE_OFF = 0,<br>STABILIZATION_MODE_LOW = 1,<br>STABILIZATION_MODE_MIDDLE = 2,<br>STABILIZATION_MODE_HIGH = 3,<br>STABILIZATION_MODE_AUTO = 4<br>} | Enumerates the video stabilization modes.| 
| [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation-1) {<br>IAMGE_ROTATION_0 = 0,<br>IAMGE_ROTATION_90 = 90,<br>IAMGE_ROTATION_180 = 180,<br>IAMGE_ROTATION_270 = 270 } | Enumerates the image rotation angles.| 
| [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel-1) {<br>QUALITY_LEVEL_HIGH = 0,<br>QUALITY_LEVEL_MEDIUM = 1,<br>QUALITY_LEVEL_LOW = 2 } | Enumerates the image quality levels.| 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype-1) { FACE_DETECTION = 0 } | Enumerates the metadata object types.| 
| [Camera_TorchMode](_o_h___camera.md#camera_torchmode-1) { OFF = 0, ON = 1, AUTO = 2 } | Enumerates the flashlight modes.| 
| [Camera_SmoothZoomMode](_o_h___camera.md#camera_smoothzoommode-1) { NORMAL = 0 } | Enumerates the smooth zoom modes.| 
| [Camera_PreconfigType](_o_h___camera.md#camera_preconfigtype-1) {<br>PRECONFIG_720P = 0,<br>PRECONFIG_1080P = 1,<br>PRECONFIG_4K = 2,<br>PRECONFIG_HIGH_QUALITY = 3 } | Enumerates the preconfigured photo resolution types.| 
| [Camera_PreconfigRatio](_o_h___camera.md#camera_preconfigratio-1) {<br>PRECONFIG_RATIO_1_1 = 0,<br>PRECONFIG_RATIO_4_3 = 1,<br>PRECONFIG_RATIO_16_9 = 2 } | Enumerates the preconfigured photo aspect ratios.| 
| [Camera_HostDeviceType](_o_h___camera.md#camera_hostdevicetype) {<br>HOST_DEVICE_TYPE_UNKNOWN_TYPE = 0,<br>HOST_DEVICE_TYPE_PHONE = 0x0E,<br>HOST_DEVICE_TYPE_TABLET = 0x11 } | Enumerates the remote device types.| 
| [Camera_QualityPrioritization](_o_h___camera.md#camera_qualityprioritization) { [HIGH_QUALITY](_o_h___camera.md) = 0, [POWER_BALANCE](_o_h___camera.md) = 1 } | Enumerates the priority levels for video recording quality.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_Camera_GetCameraManager](_o_h___camera.md#oh_camera_getcameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*\*cameraManager) | Obtains a **CameraManager** instance.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) [OH_Camera_DeleteCameraManager](_o_h___camera.md#oh_camera_deletecameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager) | Deletes a **CameraManager** instance.| 
