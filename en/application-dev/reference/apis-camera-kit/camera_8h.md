# camera.h


## Overview

The **camera.h** file declares the basic concepts of the camera.

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [Camera_Size](_camera___size.md) | Defines the parameters that describe the size.| 
| [Camera_Profile](_camera___profile.md) | Defines the profile of the camera stream.| 
| [Camera_FrameRateRange](_camera___frame_rate_range.md) | Defines the frame rate range.| 
| [Camera_VideoProfile](_camera___video_profile.md) | Defines the video profile.| 
| [Camera_OutputCapability](_camera___output_capability.md) | Defines the camera output capability.| 
| [Camera_Device](_camera___device.md) | Defines the camera device.| 
| [Camera_StatusInfo](_camera___status_info.md) | Defines the camera status information.| 
| [Camera_Point](_camera___point.md) | Defines the parameters that describe a point.| 
| [Camera_Location](_camera___location.md) | Defines the location where the photo is taken.| 
| [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) | Defines the photographing parameters.| 
| [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) | Defines the frame shutter callback.| 
| [Camera_CaptureEndInfo](_camera___capture_end_info.md) | Defines the capture end information.| 
| [Camera_Rect](_camera___rect.md) | Defines the rectangle.| 
| [Camera_MetadataObject](_camera___metadata_object.md) | Defines the camera metadata.| 


### Types

| Name| Description| 
| -------- | -------- |
| [Camera_Manager](_o_h___camera.md#camera_manager) | Defines the camera manager.| 
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) | Defines an enum that enumerates the camera error codes.| 
| [Camera_Status](_o_h___camera.md#camera_status) | Defines an enum that enumerates the camera statuses.| 
| [Camera_Position](_o_h___camera.md#camera_position) | Defines an enum that enumerates the camera positions.| 
| [Camera_Type](_o_h___camera.md#camera_type) | Defines an enum that enumerates the camera types.| 
| [Camera_Connection](_o_h___camera.md#camera_connection) | Defines an enum that enumerates the camera connection types.| 
| [Camera_Format](_o_h___camera.md#camera_format) | Defines an enum that enumerates the camera output formats.| 
| [Camera_FlashMode](_o_h___camera.md#camera_flashmode) | Defines an enum that enumerates the flash modes.| 
| [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) | Defines an enum that enumerates the exposure modes.| 
| [Camera_FocusMode](_o_h___camera.md#camera_focusmode) | Defines an enum that enumerates the focus modes.| 
| [Camera_FocusState](_o_h___camera.md#camera_focusstate) | Defines an enum that enumerates the focus states.| 
| [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) | Defines an enum that enumerates the video stabilization modes.| 
| [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) | Defines an enum that enumerates the image rotation angles.| 
| [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) | Defines an enum that enumerates the image quality levels.| 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) | Defines an enum that enumerates the metadata object types.| 
| [Camera_Size](_o_h___camera.md#camera_size) | Defines the parameters that describe the size.| 
| [Camera_Profile](_o_h___camera.md#camera_profile) | Defines the profile of the camera stream.| 
| [Camera_FrameRateRange](_o_h___camera.md#camera_frameraterange) | Defines the frame rate range.| 
| [Camera_VideoProfile](_o_h___camera.md#camera_videoprofile) | Defines the video profile.| 
| [Camera_OutputCapability](_o_h___camera.md#camera_outputcapability) | Defines the camera output capability.| 
| [Camera_Device](_o_h___camera.md#camera_device) | Defines the camera device.| 
| [Camera_StatusInfo](_o_h___camera.md#camera_statusinfo) | Defines the camera status information.| 
| [Camera_Point](_o_h___camera.md#camera_point) | Defines the parameters that describe a point.| 
| [Camera_Location](_o_h___camera.md#camera_location) | Defines the location where the photo is taken.| 
| [Camera_PhotoCaptureSetting](_o_h___camera.md#camera_photocapturesetting) | Defines the photographing parameters.| 
| [Camera_FrameShutterInfo](_o_h___camera.md#camera_frameshutterinfo) | Defines the frame shutter callback.| 
| [Camera_CaptureEndInfo](_o_h___camera.md#camera_captureendinfo) | Defines the capture end information.| 
| [Camera_Rect](_o_h___camera.md#camera_rect) | Defines the rectangle.| 
| [Camera_MetadataObject](_o_h___camera.md#camera_metadataobject) | Defines the camera metadata.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](_o_h___camera.md#camera_errorcode) {<br>[CAMERA_OK](_o_h___camera.md) = 0, [CAMERA_INVALID_ARGUMENT](_o_h___camera.md) = 7400101, [CAMERA_OPERATION_NOT_ALLOWED](_o_h___camera.md) = 7400102, [CAMERA_SESSION_NOT_CONFIG](_o_h___camera.md) = 7400103,<br>[CAMERA_SESSION_NOT_RUNNING](_o_h___camera.md) = 7400104, [CAMERA_SESSION_CONFIG_LOCKED](_o_h___camera.md) = 7400105, [CAMERA_DEVICE_SETTING_LOCKED](_o_h___camera.md) = 7400106, [CAMERA_CONFLICT_CAMERA](_o_h___camera.md) = 7400107,<br>[CAMERA_DEVICE_DISABLED](_o_h___camera.md) = 7400108, [CAMERA_DEVICE_PREEMPTED](_o_h___camera.md) = 7400109, [CAMERA_SERVICE_FATAL_ERROR](_o_h___camera.md) = 7400201<br>} | Enumerates the camera error codes.| 
| [Camera_Status](_o_h___camera.md#camera_status) { [CAMERA_STATUS_APPEAR](_o_h___camera.md) = 0, [CAMERA_STATUS_DISAPPEAR](_o_h___camera.md) = 1, [CAMERA_STATUS_AVAILABLE](_o_h___camera.md) = 2, [CAMERA_STATUS_UNAVAILABLE](_o_h___camera.md) = 3 } | Enumerates the camera statuses.| 
| [Camera_Position](_o_h___camera.md#camera_position) { [CAMERA_POSITION_UNSPECIFIED](_o_h___camera.md) = 0, [CAMERA_POSITION_BACK](_o_h___camera.md) = 1, [CAMERA_POSITION_FRONT](_o_h___camera.md) = 2 } | Enumerates the camera positions.| 
| [Camera_Type](_o_h___camera.md#camera_type) {<br>[CAMERA_TYPE_DEFAULT](_o_h___camera.md) = 0, [CAMERA_TYPE_WIDE_ANGLE](_o_h___camera.md) = 1, [CAMERA_TYPE_ULTRA_WIDE](_o_h___camera.md) = 2, [CAMERA_TYPE_TELEPHOTO](_o_h___camera.md) = 3,<br>[CAMERA_TYPE_TRUE_DEPTH](_o_h___camera.md) = 4<br>} | Enumerates the camera types.| 
| [Camera_Connection](_o_h___camera.md#camera_connection) { [CAMERA_CONNECTION_BUILT_IN](_o_h___camera.md) = 0, [CAMERA_CONNECTION_USB_PLUGIN](_o_h___camera.md) = 1, [CAMERA_CONNECTION_REMOTE](_o_h___camera.md) = 2 } | Enumerates the camera connection types.| 
| [Camera_Format](_o_h___camera.md#camera_format) { [CAMERA_FORMAT_RGBA_8888](_o_h___camera.md) = 3, [CAMERA_FORMAT_YUV_420_SP](_o_h___camera.md) = 1003, [CAMERA_FORMAT_JPEG](_o_h___camera.md) = 2000 } | Enumerates the camera output formats.| 
| [Camera_FlashMode](_o_h___camera.md#camera_flashmode) { [FLASH_MODE_CLOSE](_o_h___camera.md) = 0, [FLASH_MODE_OPEN](_o_h___camera.md) = 1, [FLASH_MODE_AUTO](_o_h___camera.md) = 2, [FLASH_MODE_ALWAYS_OPEN](_o_h___camera.md) = 3 } | Enumerates the flash modes.| 
| [Camera_ExposureMode](_o_h___camera.md#camera_exposuremode) { [EXPOSURE_MODE_LOCKED](_o_h___camera.md) = 0, [EXPOSURE_MODE_AUTO](_o_h___camera.md) = 1, [EXPOSURE_MODE_CONTINUOUS_AUTO](_o_h___camera.md) = 2 } | Enumerates the exposure modes.| 
| [Camera_FocusMode](_o_h___camera.md#camera_focusmode) { [FOCUS_MODE_MANUAL](_o_h___camera.md) = 0, [FOCUS_MODE_CONTINUOUS_AUTO](_o_h___camera.md) = 1, [FOCUS_MODE_AUTO](_o_h___camera.md) = 2, [FOCUS_MODE_LOCKED](_o_h___camera.md) = 3 } | Enumerates the focus modes.| 
| [Camera_FocusState](_o_h___camera.md#camera_focusstate) { [FOCUS_STATE_SCAN](_o_h___camera.md) = 0, [FOCUS_STATE_FOCUSED](_o_h___camera.md) = 1, [FOCUS_STATE_UNFOCUSED](_o_h___camera.md) = 2 } | Enumerates the focus states.| 
| [Camera_VideoStabilizationMode](_o_h___camera.md#camera_videostabilizationmode) {<br>[STABILIZATION_MODE_OFF](_o_h___camera.md) = 0, [STABILIZATION_MODE_LOW](_o_h___camera.md) = 1, [STABILIZATION_MODE_MIDDLE](_o_h___camera.md) = 2, [STABILIZATION_MODE_HIGH](_o_h___camera.md) = 3,<br>[STABILIZATION_MODE_AUTO](_o_h___camera.md) = 4<br>} | Enumerates the video stabilization modes.| 
| [Camera_ImageRotation](_o_h___camera.md#camera_imagerotation) { [IAMGE_ROTATION_0](_o_h___camera.md) = 0, [IAMGE_ROTATION_90](_o_h___camera.md) = 90, [IAMGE_ROTATION_180](_o_h___camera.md) = 180, [IAMGE_ROTATION_270](_o_h___camera.md) = 270 } | Enumerates the image rotation angles.| 
| [Camera_QualityLevel](_o_h___camera.md#camera_qualitylevel) { [QUALITY_LEVEL_HIGH](_o_h___camera.md) = 0, [QUALITY_LEVEL_MEDIUM](_o_h___camera.md) = 1, [QUALITY_LEVEL_LOW](_o_h___camera.md) = 2 } | Enumerates the image quality levels.| 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) { [FACE_DETECTION](_o_h___camera.md) = 0 } | Enumerates the metadata object types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Camera_GetCameraManager](_o_h___camera.md#oh_camera_getcameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*\*cameraManager) | Obtains a **CameraManager** instance.| 
| [OH_Camera_DeleteCameraManager](_o_h___camera.md#oh_camera_deletecameramanager) ([Camera_Manager](_o_h___camera.md#camera_manager) \*cameraManager) | Deletes a **CameraManager** instance.| 
