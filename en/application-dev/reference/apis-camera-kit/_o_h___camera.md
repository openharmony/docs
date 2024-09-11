# OH_Camera


## Overview

The **OH_Camera** module provides C APIs for the camera service.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [camera.h](camera_8h.md) | Declares the basic concepts of the camera.| 
| [camera_device.h](camera__device_8h.md) | Declares the basic concepts of the camera device.| 
| [camera_input.h](camera__input_8h.md) | Declares the camera input concepts.| 
| [camera_manager.h](camera__manager_8h.md) | Declares the camera manager concepts.| 
| [capture_session.h](capture__session_8h.md) | Declares the capture session concepts.| 
| [metadata_output.h](metadata__output_8h.md) | Declares the metadata output concepts.| 
| [photo_native.h](photo__native_8h.md) | Declares the camera photo concepts.| 
| [photo_output.h](photo__output_8h.md) | Declares the photo output concepts.| 
| [preview_output.h](preview__output_8h.md) | Declares the preview output concepts.| 
| [video_output.h](video__output_8h.md) | Declares the video output concepts.| 


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
| struct  [Camera_Rect](_camera___rect.md) | Describes the rectangle.| 
| struct  [Camera_MetadataObject](_camera___metadata_object.md) | Describes the camera metadata.| 
| struct  [Camera_TorchStatusInfo](_camera___torch_status_info.md) | Describes the flashlight status information.| 
| struct  [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) | Describes the smooth zoom information.| 
| struct  [Camera_CaptureStartInfo](_camera___capture_start_info.md) | Describes the capture start information.| 
| struct  [Camera_FrameShutterEndInfo](_camera___frame_shutter_end_info.md) | Describes the frame shutter end information during capture.| 
| struct  [CameraInput_Callbacks](_camera_input___callbacks.md) | Describes the callbacks used to listen for camera input errors.| 
| struct  [CameraManager_Callbacks](_camera_manager___callbacks.md) | Describes the callbacks used to listen for camera status changes.| 
| struct  [CaptureSession_Callbacks](_capture_session___callbacks.md) | Describes the callbacks used for a capture session.| 
| struct  [MetadataOutput_Callbacks](_metadata_output___callbacks.md) | Describes the callbacks related to metadata output.| 
| struct  [PhotoOutput_Callbacks](_photo_output___callbacks.md) | Describes the callbacks related to photo output.| 
| struct  [PreviewOutput_Callbacks](_preview_output___callbacks.md) | Describes the callbacks related to preview output.| 
| struct  [VideoOutput_Callbacks](_video_output___callbacks.md) | Describes the callbacks related to video output.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_Manager](#camera_manager) [Camera_Manager](#camera_manager) | Defines a struct for the camera manager.| 
| typedef enum [Camera_ErrorCode](#camera_errorcode) [Camera_ErrorCode](#camera_errorcode) | Defines an enum for the camera error codes.| 
| typedef enum [Camera_Status](#camera_status) [Camera_Status](#camera_status) | Defines an enum for the camera statuses.| 
| typedef enum [Camera_SceneMode](#camera_scenemode) [Camera_SceneMode](#camera_scenemode) | Defines an enum for the camera scene modes.| 
| typedef enum [Camera_Position](#camera_position) [Camera_Position](#camera_position) | Defines an enum for the camera positions.| 
| typedef enum [Camera_Type](#camera_type) [Camera_Type](#camera_type) | Defines an enum for the camera types.| 
| typedef enum [Camera_Connection](#camera_connection) [Camera_Connection](#camera_connection) | Defines an enum for the camera connection types.| 
| typedef enum [Camera_Format](#camera_format) [Camera_Format](#camera_format) | Defines an enum for the camera output formats.| 
| typedef enum [Camera_FlashMode](#camera_flashmode) [Camera_FlashMode](#camera_flashmode) | Defines an enum for the flash modes.| 
| typedef enum [Camera_ExposureMode](#camera_exposuremode) [Camera_ExposureMode](#camera_exposuremode) | Defines an enum for the exposure modes.| 
| typedef enum [Camera_FocusMode](#camera_focusmode) [Camera_FocusMode](#camera_focusmode) | Defines an enum for the focus modes.| 
| typedef enum [Camera_FocusState](#camera_focusstate) [Camera_FocusState](#camera_focusstate) | Defines an enum for the focus states.| 
| typedef enum [Camera_VideoStabilizationMode](#camera_videostabilizationmode) [Camera_VideoStabilizationMode](#camera_videostabilizationmode) | Defines an enum for the video stabilization modes.| 
| typedef enum [Camera_ImageRotation](#camera_imagerotation) [Camera_ImageRotation](#camera_imagerotation) | Defines an enum for the image rotation angles.| 
| typedef enum [Camera_QualityLevel](#camera_qualitylevel) [Camera_QualityLevel](#camera_qualitylevel) | Defines an enum for the image quality levels.| 
| typedef enum [Camera_MetadataObjectType](#camera_metadataobjecttype) [Camera_MetadataObjectType](#camera_metadataobjecttype) | Defines an enum for the metadata object types.| 
| typedef enum [Camera_TorchMode](#camera_torchmode) [Camera_TorchMode](#camera_torchmode) | Defines an enum for the flashlight modes.| 
| typedef enum [Camera_SmoothZoomMode](#camera_smoothzoommode) [Camera_SmoothZoomMode](#camera_smoothzoommode) | Defines an enum for the smooth zoom modes.| 
| typedef enum [Camera_PreconfigType](#camera_preconfigtype) [Camera_PreconfigType](#camera_preconfigtype) | Defines an enum for the preconfigured resolution types.| 
| typedef enum [Camera_PreconfigRatio](#camera_preconfigratio) [Camera_PreconfigRatio](#camera_preconfigratio) | Defines an enum for the preconfigured aspect ratios.| 
| typedef struct [Camera_Size](_camera___size.md) [Camera_Size](#camera_size) | Defines a struct for the parameters related to the size.| 
| typedef struct [Camera_Profile](_camera___profile.md) [Camera_Profile](#camera_profile) | Defines a struct for the profile of a camera stream.| 
| typedef struct [Camera_FrameRateRange](_camera___frame_rate_range.md) [Camera_FrameRateRange](#camera_frameraterange) | Defines a struct for the frame rate range.| 
| typedef struct [Camera_VideoProfile](_camera___video_profile.md) [Camera_VideoProfile](#camera_videoprofile) | Defines a struct for the video profile.| 
| typedef struct [Camera_OutputCapability](_camera___output_capability.md) [Camera_OutputCapability](#camera_outputcapability) | Defines a struct for the camera output capability.| 
| typedef struct [Camera_Device](_camera___device.md) [Camera_Device](#camera_device) | Defines a struct for the camera device.| 
| typedef struct [Camera_StatusInfo](_camera___status_info.md) [Camera_StatusInfo](#camera_statusinfo) | Defines a struct for the camera status information.| 
| typedef struct [Camera_Point](_camera___point.md) [Camera_Point](#camera_point) | Defines a struct for the parameters related to a point.| 
| typedef struct [Camera_Location](_camera___location.md) [Camera_Location](#camera_location) | Defines a struct for the location where the photo is taken.| 
| typedef struct [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) [Camera_PhotoCaptureSetting](#camera_photocapturesetting) | Defines a struct for the parameters related to photo capture.| 
| typedef struct [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) [Camera_FrameShutterInfo](#camera_frameshutterinfo) | Defines a struct for the frame shutter information.| 
| typedef struct [Camera_CaptureEndInfo](_camera___capture_end_info.md) [Camera_CaptureEndInfo](#camera_captureendinfo) | Defines a struct for the capture end information.| 
| typedef struct [Camera_Rect](_camera___rect.md) [Camera_Rect](#camera_rect) | Defines a struct for the rectangle.| 
| typedef struct [Camera_MetadataObject](_camera___metadata_object.md) [Camera_MetadataObject](#camera_metadataobject) | Defines a struct for the camera metadata.| 
| typedef struct [Camera_TorchStatusInfo](_camera___torch_status_info.md) [Camera_TorchStatusInfo](#camera_torchstatusinfo) | Defines a struct for the flashlight status information.| 
| typedef struct [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) [Camera_SmoothZoomInfo](#camera_smoothzoominfo) | Defines a struct for the smooth zoom information.| 
| typedef struct [Camera_CaptureStartInfo](_camera___capture_start_info.md) [Camera_CaptureStartInfo](#camera_capturestartinfo) | Defines a struct for the capture start information.| 
| typedef struct [Camera_FrameShutterEndInfo](_camera___frame_shutter_end_info.md) [Camera_FrameShutterEndInfo](#camera_frameshutterendinfo) | Defines a struct for the frame shutter end information during capture.| 
| typedef struct [Camera_Input](#camera_input) [Camera_Input](#camera_input) | Defines a struct for the camera input object.| 
| typedef void(\* [OH_CameraInput_OnError](#oh_camerainput_onerror)) (const [Camera_Input](#camera_input) \*cameraInput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the callback defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct and used to report camera input errors.| 
| typedef struct [CameraInput_Callbacks](_camera_input___callbacks.md) [CameraInput_Callbacks](#camerainput_callbacks) | Defines a struct for the callbacks used to listen for camera input errors.| 
| typedef void(\* [OH_CameraManager_StatusCallback](#oh_cameramanager_statuscallback)) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_StatusInfo](_camera___status_info.md) \*status) | Defines the callback defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct and used to report the camera manager status.| 
| typedef void(\* [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback)) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_TorchStatusInfo](_camera___torch_status_info.md) \*status) | Defines the callback invoked when the flashlight status changes.| 
| typedef struct [CameraManager_Callbacks](_camera_manager___callbacks.md) [CameraManager_Callbacks](#cameramanager_callbacks) | Defines a struct for the callbacks used to listen for camera status changes.| 
| typedef struct [Camera_CaptureSession](#camera_capturesession) [Camera_CaptureSession](#camera_capturesession) | Defines a struct for the capture session object.| 
| typedef void(\* [OH_CaptureSession_OnFocusStateChange](#oh_capturesession_onfocusstatechange)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusState](#camera_focusstate) focusState) | Defines the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report focus status changes of a capture session.| 
| typedef void(\* [OH_CaptureSession_OnError](#oh_capturesession_onerror)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report capture session errors.| 
| typedef void(\* [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) \*smoothZoomInfo) | Defines the callback invoked when smooth zoom is triggered for a capture session.| 
| typedef struct [CaptureSession_Callbacks](_capture_session___callbacks.md) [CaptureSession_Callbacks](#capturesession_callbacks) | Defines a struct for the callbacks used for a capture session.| 
| typedef struct [Camera_MetadataOutput](#camera_metadataoutput) [Camera_MetadataOutput](#camera_metadataoutput) | Defines a struct for the metadata output object.| 
| typedef void(\* [OH_MetadataOutput_OnMetadataObjectAvailable](#oh_metadataoutput_onmetadataobjectavailable)) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [Camera_MetadataObject](_camera___metadata_object.md) \*metadataObject, uint32_t size) | Defines the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output data.| 
| typedef void(\* [OH_MetadataOutput_OnError](#oh_metadataoutput_onerror)) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output errors.| 
| typedef struct [MetadataOutput_Callbacks](_metadata_output___callbacks.md) [MetadataOutput_Callbacks](#metadataoutput_callbacks) | Defines a struct for the callbacks related to metadata output.| 
| typedef struct [OH_PhotoNative](#oh_photonative) [OH_PhotoNative](#oh_photonative) | Defines a struct for a camera photo object.| 
| typedef struct [Camera_PhotoOutput](#camera_photooutput) [Camera_PhotoOutput](#camera_photooutput) | Defines a struct for the photo output object.| 
| typedef void(\* [OH_PhotoOutput_OnFrameStart](#oh_photooutput_onframestart)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame start events.| 
| typedef void(\* [OH_PhotoOutput_OnFrameShutter](#oh_photooutput_onframeshutter)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*info) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report frame shutter events.| 
| typedef void(\* [OH_PhotoOutput_OnFrameEnd](#oh_photooutput_onframeend)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, int32_t frameCount) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame end events.| 
| typedef void(\* [OH_PhotoOutput_OnError](#oh_photooutput_onerror)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output errors.| 
| typedef void(\* [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, int32_t frameCount) | Defines the callback invoked when the capture ends.| 
| typedef void(\* [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_CaptureStartInfo](_camera___capture_start_info.md) \*Info) | Defines the callback invoked when the capture starts.| 
| typedef void(\* [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*Info) | Defines the callback invoked when frame shutter ends.| 
| typedef void(\* [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Defines the callback invoked when the camera is ready to take photos. When the callback is received, the next capture can be performed.| 
| typedef void(\* [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, int64_t duration) | Defines the callback for the estimated capture duration.| 
| typedef void(\* [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoNative](#oh_photonative) \*photo) | Defines the callback invoked when a high-resolution photo is available.| 
| typedef void(\* [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, OH_MediaAsset \*photoAsset) | Defines the callback invoked when a photo asset is available.| 
| typedef struct [PhotoOutput_Callbacks](_photo_output___callbacks.md) [PhotoOutput_Callbacks](#photooutput_callbacks) | Defines a struct for the callbacks related to photo output.| 
| typedef struct [Camera_PreviewOutput](#camera_previewoutput) [Camera_PreviewOutput](#camera_previewoutput) | Defines a struct for the preview output object.| 
| typedef void(\* [OH_PreviewOutput_OnFrameStart](#oh_previewoutput_onframestart)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame start events.| 
| typedef void(\* [OH_PreviewOutput_OnFrameEnd](#oh_previewoutput_onframeend)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, int32_t frameCount) | Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame end events.| 
| typedef void(\* [OH_PreviewOutput_OnError](#oh_previewoutput_onerror)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output errors.| 
| typedef struct [PreviewOutput_Callbacks](_preview_output___callbacks.md) [PreviewOutput_Callbacks](#previewoutput_callbacks) | Defines a struct for the callbacks related to preview output.| 
| typedef struct [Camera_VideoOutput](#camera_videooutput) [Camera_VideoOutput](#camera_videooutput) | Defines a struct for the video output object.| 
| typedef void(\* [OH_VideoOutput_OnFrameStart](#oh_videooutput_onframestart)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame start events.| 
| typedef void(\* [OH_VideoOutput_OnFrameEnd](#oh_videooutput_onframeend)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, int32_t frameCount) | Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame end events.| 
| typedef void(\* [OH_VideoOutput_OnError](#oh_videooutput_onerror)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output errors.| 
| typedef struct [VideoOutput_Callbacks](_video_output___callbacks.md) [VideoOutput_Callbacks](#videooutput_callbacks) | Defines a struct for the callbacks related to video output.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](#camera_errorcode) {<br>CAMERA_OK = 0,<br>CAMERA_INVALID_ARGUMENT = 7400101,<br>CAMERA_OPERATION_NOT_ALLOWED = 7400102,<br>CAMERA_SESSION_NOT_CONFIG = 7400103,<br>CAMERA_SESSION_NOT_RUNNING = 7400104,<br>CAMERA_SESSION_CONFIG_LOCKED = 7400105,<br>CAMERA_DEVICE_SETTING_LOCKED = 7400106,<br>CAMERA_CONFLICT_CAMERA = 7400107,<br>CAMERA_DEVICE_DISABLED = 7400108,<br>CAMERA_DEVICE_PREEMPTED = 7400109,<br>CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS = 7400110,<br>CAMERA_SERVICE_FATAL_ERROR = 7400201} | Enumerates the camera error codes.| 
| [Camera_Status](#camera_status) {<br>CAMERA_STATUS_APPEAR = 0,<br>CAMERA_STATUS_DISAPPEAR = 1,<br>CAMERA_STATUS_AVAILABLE = 2,<br>CAMERA_STATUS_UNAVAILABLE = 3 } | Enumerates the camera statuses.| 
| [Camera_SceneMode](#camera_scenemode) {<br>NORMAL_PHOTO = 1,<br>NORMAL_VIDEO = 2,<br>SECURE_PHOTO = 12 } | Enumerates the camera scene modes.| 
| [Camera_Position](#camera_position) {<br>CAMERA_POSITION_UNSPECIFIED = 0,<br>CAMERA_POSITION_BACK = 1,<br>CAMERA_POSITION_FRONT = 2 } | Enumerates the camera positions.| 
| [Camera_Type](#camera_type) {<br>CAMERA_TYPE_DEFAULT = 0,<br>CAMERA_TYPE_WIDE_ANGLE = 1,<br>CAMERA_TYPE_ULTRA_WIDE = 2,<br>CAMERA_TYPE_TELEPHOTO = 3,<br>CAMERA_TYPE_TRUE_DEPTH = 4<br>} | Enumerates the camera types.| 
| [Camera_Connection](#camera_connection) {<br>CAMERA_CONNECTION_BUILT_IN = 0,<br>CAMERA_CONNECTION_USB_PLUGIN = 1,<br>CAMERA_CONNECTION_REMOTE = 2 } | Enumerates the camera connection types.| 
| [Camera_Format](#camera_format) {<br>CAMERA_FORMAT_RGBA_8888 = 3,<br>CAMERA_FORMAT_YUV_420_SP = 1003,<br>CAMERA_FORMAT_JPEG = 2000,<br>CAMERA_FORMAT_YCBCR_P010 = 2001,<br>CAMERA_FORMAT_YCRCB_P010 = 2002<br>} | Enumerates the camera output formats.| 
| [Camera_FlashMode](#camera_flashmode) {<br>FLASH_MODE_CLOSE = 0,<br>FLASH_MODE_OPEN = 1,<br>FLASH_MODE_AUTO = 2,<br>FLASH_MODE_ALWAYS_OPEN = 3 } | Enumerates the flash modes.| 
| [Camera_ExposureMode](#camera_exposuremode) {<br>EXPOSURE_MODE_LOCKED = 0,<br>EXPOSURE_MODE_AUTO = 1,<br>EXPOSURE_MODE_CONTINUOUS_AUTO = 2 } | Enumerates the exposure modes.| 
| [Camera_FocusMode](#camera_focusmode) {<br>FOCUS_MODE_MANUAL = 0,<br>FOCUS_MODE_CONTINUOUS_AUTO = 1,<br>FOCUS_MODE_AUTO = 2,<br>FOCUS_MODE_LOCKED = 3 } | Enumerates the focus modes.| 
| [Camera_FocusState](#camera_focusstate) {<br>FOCUS_STATE_SCAN = 0,<br>FOCUS_STATE_FOCUSED = 1,<br>FOCUS_STATE_UNFOCUSED = 2 } | Enumerates the focus states.| 
| [Camera_VideoStabilizationMode](#camera_videostabilizationmode) {<br>STABILIZATION_MODE_OFF = 0,<br>STABILIZATION_MODE_LOW = 1,<br>STABILIZATION_MODE_MIDDLE = 2,<br>STABILIZATION_MODE_HIGH = 3,<br>STABILIZATION_MODE_AUTO = 4<br>} | Enumerates the video stabilization modes.| 
| [Camera_ImageRotation](#camera_imagerotation) {<br>IAMGE_ROTATION_0 = 0,<br>IAMGE_ROTATION_90 = 90,<br>IAMGE_ROTATION_180 = 180,<br>IAMGE_ROTATION_270 = 270 } | Enumerates the image rotation angles.| 
| [Camera_QualityLevel](#camera_qualitylevel) {<br>QUALITY_LEVEL_HIGH = 0,<br>QUALITY_LEVEL_MEDIUM = 1,<br>QUALITY_LEVEL_LOW = 2 } | Enumerates the image quality levels.| 
| [Camera_MetadataObjectType](#camera_metadataobjecttype) { FACE_DETECTION = 0 } | Enumerates the metadata object types.| 
| [Camera_TorchMode](#camera_torchmode) { OFF = 0, ON = 1, AUTO = 2 } | Enumerates the flashlight modes.| 
| [Camera_SmoothZoomMode](#camera_smoothzoommode) { NORMAL = 0 } | Enumerates the smooth zoom modes.| 
| [Camera_PreconfigType](#camera_preconfigtype) {<br>PRECONFIG_720P = 0,<br>PRECONFIG_1080P = 1,<br>PRECONFIG_4K = 2,<br>PRECONFIG_HIGH_QUALITY = 3 } | Enumerates the preconfigured resolution types.| 
| [Camera_PreconfigRatio](#camera_preconfigratio) {<br>PRECONFIG_RATIO_1_1 = 0,<br>PRECONFIG_RATIO_4_3 = 1,<br>PRECONFIG_RATIO_16_9 = 2 } | Enumerates the preconfigured aspect ratios.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](#camera_errorcode) [OH_Camera_GetCameraManager](#oh_camera_getcameramanager) ([Camera_Manager](#camera_manager) \*\*cameraManager) | Obtains a **CameraManager** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_Camera_DeleteCameraManager](#oh_camera_deletecameramanager) ([Camera_Manager](#camera_manager) \*cameraManager) | Deletes a **CameraManager** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraDevice_GetCameraOrientation](#oh_cameradevice_getcameraorientation) ([Camera_Device](_camera___device.md) \*camera, uint32_t \*orientation) | Obtains the sensor direction of a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_RegisterCallback](#oh_camerainput_registercallback) ([Camera_Input](#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Registers a callback to listen for camera input events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_UnregisterCallback](#oh_camerainput_unregistercallback) ([Camera_Input](#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Unregisters the callback used to listen for camera input events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Open](#oh_camerainput_open) ([Camera_Input](#camera_input) \*cameraInput) | Opens a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_OpenSecureCamera](#oh_camerainput_opensecurecamera) ([Camera_Input](#camera_input) \*cameraInput, uint64_t \*secureSeqId) | Opens a camera in secure mode.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Close](#oh_camerainput_close) ([Camera_Input](#camera_input) \*cameraInput) | Closes a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Release](#oh_camerainput_release) ([Camera_Input](#camera_input) \*cameraInput) | Releases a **CameraInput** instance. Either this function or [OH_CameraInput_Close](#oh_camerainput_close) needs to be called.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_RegisterCallback](#oh_cameramanager_registercallback) ([Camera_Manager](#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Registers a callback to listen for camera status changes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_UnregisterCallback](#oh_cameramanager_unregistercallback) ([Camera_Manager](#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Unregisters the callback used to listen for camera status changes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_RegisterTorchStatusCallback](#oh_cameramanager_registertorchstatuscallback) ([Camera_Manager](#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback) torchStatusCallback) | Registers a callback to listen for flashlight status changes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_UnregisterTorchStatusCallback](#oh_cameramanager_unregistertorchstatuscallback) ([Camera_Manager](#camera_manager) \*cameraManager, [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback) torchStatusCallback) | Unregisters the callback used to listen for flashlight status changes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameras](#oh_cameramanager_getsupportedcameras) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*\*cameras, uint32_t \*size) | Obtains supported cameras.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSupportedCameras](#oh_cameramanager_deletesupportedcameras) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*cameras, uint32_t size) | Deletes supported cameras.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapability](#oh_cameramanager_getsupportedcameraoutputcapability) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | Obtains the output capability supported by a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode](#oh_cameramanager_getsupportedcameraoutputcapabilitywithscenemode) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](#camera_scenemode) sceneMode, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | Obtains the output capability supported by a camera in the specified mode.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSupportedCameraOutputCapability](#oh_cameramanager_deletesupportedcameraoutputcapability) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_OutputCapability](_camera___output_capability.md) \*cameraOutputCapability) | Deletes the output capability supported by a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_IsCameraMuted](#oh_cameramanager_iscameramuted) ([Camera_Manager](#camera_manager) \*cameraManager, bool \*isCameraMuted) | Checks whether a camera is muted.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCaptureSession](#oh_cameramanager_createcapturesession) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_CaptureSession](#camera_capturesession) \*\*captureSession) | Creates a **CaptureSession** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCameraInput](#oh_cameramanager_createcamerainput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_Input](#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCameraInput_WithPositionAndType](#oh_cameramanager_createcamerainput_withpositionandtype) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Position](#camera_position) position, [Camera_Type](#camera_type) type, [Camera_Input](#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance with the specified location and type.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePreviewOutput](#oh_cameramanager_createpreviewoutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PreviewOutput](#camera_previewoutput) \*\*previewOutput) | Creates a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePreviewOutputUsedInPreconfig](#oh_cameramanager_createpreviewoutputusedinpreconfig) ([Camera_Manager](#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PreviewOutput](#camera_previewoutput) \*\*previewOutput) | Creates a **PreviewOutput** instance to be used in a preconfiguration stream.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePhotoOutput](#oh_cameramanager_createphotooutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PhotoOutput](#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePhotoOutputUsedInPreconfig](#oh_cameramanager_createphotooutputusedinpreconfig) ([Camera_Manager](#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_PhotoOutput](#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance to be used in a preconfiguration stream.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePhotoOutputWithoutSurface](#oh_cameramanager_createphotooutputwithoutsurface) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, [Camera_PhotoOutput](#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance. **surfaceId** is not required in this function.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateVideoOutput](#oh_cameramanager_createvideooutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_VideoProfile](_camera___video_profile.md) \*profile, const char \*surfaceId, [Camera_VideoOutput](#camera_videooutput) \*\*videoOutput) | Creates a **VideoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateVideoOutputUsedInPreconfig](#oh_cameramanager_createvideooutputusedinpreconfig) ([Camera_Manager](#camera_manager) \*cameraManager, const char \*surfaceId, [Camera_VideoOutput](#camera_videooutput) \*\*videoOutput) | Creates a **VideoOutput** instance to be used in a preconfiguration stream.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateMetadataOutput](#oh_cameramanager_createmetadataoutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_MetadataObjectType](#camera_metadataobjecttype) \*profile, [Camera_MetadataOutput](#camera_metadataoutput) \*\*metadataOutput) | Creates a **MetadataOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedSceneModes](#oh_cameramanager_getsupportedscenemodes) ([Camera_Device](_camera___device.md) \*camera, [Camera_SceneMode](#camera_scenemode) \*\*sceneModes, uint32_t \*size) | Obtains the scene modes supported by a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSceneModes](#oh_cameramanager_deletescenemodes) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_SceneMode](#camera_scenemode) \*sceneModes) | Deletes scene modes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_IsTorchSupported](#oh_cameramanager_istorchsupported) ([Camera_Manager](#camera_manager) \*cameraManager, bool \*isTorchSupported) | Checks whether the device supports the flashlight.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_IsTorchSupportedByTorchMode](#oh_cameramanager_istorchsupportedbytorchmode) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_TorchMode](#camera_torchmode) torchMode, bool \*isTorchSupported) | Checks whether the device supports the specified flashlight mode.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_SetTorchMode](#oh_cameramanager_settorchmode) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_TorchMode](#camera_torchmode) torchMode) | Sets a flashlight mode.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RegisterCallback](#oh_capturesession_registercallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | Registers a callback to listen for capture session events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_UnregisterCallback](#oh_capturesession_unregistercallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | Unregisters the callback used to listen for capture session events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RegisterSmoothZoomInfoCallback](#oh_capturesession_registersmoothzoominfocallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback) | Registers a callback to listen for smooth zoom events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_UnregisterSmoothZoomInfoCallback](#oh_capturesession_unregistersmoothzoominfocallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo) smoothZoomInfoCallback) | Unregisters the callback used to listen for smooth zoom events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetSessionMode](#oh_capturesession_setsessionmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_SceneMode](#camera_scenemode) sceneMode) | Sets a session mode.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddSecureOutput](#oh_capturesession_addsecureoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Marks a preview output stream as secure output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_BeginConfig](#oh_capturesession_beginconfig) ([Camera_CaptureSession](#camera_capturesession) \*session) | Starts the configuration for a capture session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CommitConfig](#oh_capturesession_commitconfig) ([Camera_CaptureSession](#camera_capturesession) \*session) | Commits the configuration for a capture session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddInput](#oh_capturesession_addinput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Input](#camera_input) \*cameraInput) | Adds a **CameraInput** instance to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemoveInput](#oh_capturesession_removeinput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Input](#camera_input) \*cameraInput) | Removes a **CameraInput** instance from a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddPreviewOutput](#oh_capturesession_addpreviewoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Adds a **PreviewOutput** instance to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemovePreviewOutput](#oh_capturesession_removepreviewoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Removes a **PreviewOutput** instance from a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddPhotoOutput](#oh_capturesession_addphotooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Adds a **PhotoOutput** instance to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemovePhotoOutput](#oh_capturesession_removephotooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Removes a **PhotoOutput** instance from a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddVideoOutput](#oh_capturesession_addvideooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Adds a **VideoOutput** instance to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemoveVideoOutput](#oh_capturesession_removevideooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Removes a **VideoOutput** instance from a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_AddMetadataOutput](#oh_capturesession_addmetadataoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Adds a **MetadataOutput** instance to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RemoveMetadataOutput](#oh_capturesession_removemetadataoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Removes a **MetadataOutput** instance from a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Start](#oh_capturesession_start) ([Camera_CaptureSession](#camera_capturesession) \*session) | Starts a capture session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Stop](#oh_capturesession_stop) ([Camera_CaptureSession](#camera_capturesession) \*session) | Stops a capture session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Release](#oh_capturesession_release) ([Camera_CaptureSession](#camera_capturesession) \*session) | Releases a **CaptureSession** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_HasFlash](#oh_capturesession_hasflash) ([Camera_CaptureSession](#camera_capturesession) \*session, bool \*hasFlash) | Checks whether the device has flash.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsFlashModeSupported](#oh_capturesession_isflashmodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FlashMode](#camera_flashmode) flashMode, bool \*isSupported) | Checks whether a flash mode is supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFlashMode](#oh_capturesession_getflashmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FlashMode](#camera_flashmode) \*flashMode) | Obtains the flash mode in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetFlashMode](#oh_capturesession_setflashmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FlashMode](#camera_flashmode) flashMode) | Sets a flash mode for the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsExposureModeSupported](#oh_capturesession_isexposuremodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ExposureMode](#camera_exposuremode) exposureMode, bool \*isSupported) | Checks whether an exposure mode is supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureMode](#oh_capturesession_getexposuremode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ExposureMode](#camera_exposuremode) \*exposureMode) | Obtains the exposure mode in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetExposureMode](#oh_capturesession_setexposuremode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ExposureMode](#camera_exposuremode) exposureMode) | Sets an exposure mode for the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetMeteringPoint](#oh_capturesession_getmeteringpoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) \*point) | Obtains the metering point in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetMeteringPoint](#oh_capturesession_setmeteringpoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) point) | Sets the metering point, which is the center point of the metering rectangle.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureBiasRange](#oh_capturesession_getexposurebiasrange) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*minExposureBias, float \*maxExposureBias, float \*step) | Obtains the exposure compensation values of the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetExposureBias](#oh_capturesession_setexposurebias) ([Camera_CaptureSession](#camera_capturesession) \*session, float exposureBias) | Sets an exposure compensation value for the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureBias](#oh_capturesession_getexposurebias) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*exposureBias) | Obtains the exposure compensation value in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsFocusModeSupported](#oh_capturesession_isfocusmodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusMode](#camera_focusmode) focusMode, bool \*isSupported) | Checks whether a focus mode is supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFocusMode](#oh_capturesession_getfocusmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusMode](#camera_focusmode) \*focusMode) | Obtains the focus mode in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetFocusMode](#oh_capturesession_setfocusmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusMode](#camera_focusmode) focusMode) | Sets a focus mode for the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFocusPoint](#oh_capturesession_getfocuspoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) \*focusPoint) | Obtains the focal point in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetFocusPoint](#oh_capturesession_setfocuspoint) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Point](_camera___point.md) focusPoint) | Sets a focal point for the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetZoomRatioRange](#oh_capturesession_getzoomratiorange) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*minZoom, float \*maxZoom) | Obtains the supported zoom ratio range.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetZoomRatio](#oh_capturesession_getzoomratio) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*zoom) | Obtains the zoom ratio in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetZoomRatio](#oh_capturesession_setzoomratio) ([Camera_CaptureSession](#camera_capturesession) \*session, float zoom) | Sets a zoom ratio for the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_IsVideoStabilizationModeSupported](#oh_capturesession_isvideostabilizationmodesupported) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoStabilizationMode](#camera_videostabilizationmode) mode, bool \*isSupported) | Checks whether a video stabilization mode is supported. | 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetVideoStabilizationMode](#oh_capturesession_getvideostabilizationmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoStabilizationMode](#camera_videostabilizationmode) \*mode) | Obtains the video stabilization mode in use.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetVideoStabilizationMode](#oh_capturesession_setvideostabilizationmode) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoStabilizationMode](#camera_videostabilizationmode) mode) | Sets a video stabilization mode for the device.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddInput](#oh_capturesession_canaddinput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_Input](#camera_input) \*cameraInput, bool \*isSuccessful) | Checks whether a **CameraInput** instance can be added to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddPreviewOutput](#oh_capturesession_canaddpreviewoutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreviewOutput](#camera_previewoutput) \*cameraOutput, bool \*isSuccessful) | Checks whether a **PreviewOutput** instance can be added to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddPhotoOutput](#oh_capturesession_canaddphotooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PhotoOutput](#camera_photooutput) \*cameraOutput, bool \*isSuccessful) | Checks whether a **PhotoOutput** instance can be added to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanAddVideoOutput](#oh_capturesession_canaddvideooutput) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_VideoOutput](#camera_videooutput) \*cameraOutput, bool \*isSuccessful) | Checks whether a **VideoOutput** instance can be added to a session.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanPreconfig](#oh_capturesession_canpreconfig) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType, bool \*canPreconfig) | Checks whether a preconfigured resolution type is supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CanPreconfigWithRatio](#oh_capturesession_canpreconfigwithratio) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType, [Camera_PreconfigRatio](#camera_preconfigratio) preconfigRatio, bool \*canPreconfig) | Checks whether a preconfigured resolution type with an aspect ratio is supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Preconfig](#oh_capturesession_preconfig) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType) | Sets a preconfigured resolution type.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_PreconfigWithRatio](#oh_capturesession_preconfigwithratio) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_PreconfigType](#camera_preconfigtype) preconfigType, [Camera_PreconfigRatio](#camera_preconfigratio) preconfigRatio) | Sets a preconfigured resolution type with an aspect ratio.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetExposureValue](#oh_capturesession_getexposurevalue) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*exposureValue) | Obtains the exposure value.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetFocalLength](#oh_capturesession_getfocallength) ([Camera_CaptureSession](#camera_capturesession) \*session, float \*focalLength) | Obtains the current focal length.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetSmoothZoom](#oh_capturesession_setsmoothzoom) ([Camera_CaptureSession](#camera_capturesession) \*session, float targetZoom, [Camera_SmoothZoomMode](#camera_smoothzoommode) smoothZoomMode) | Sets smooth zoom.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetSupportedColorSpaces](#oh_capturesession_getsupportedcolorspaces) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*\*colorSpace, uint32_t \*size) | Obtains the supported color spaces.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_DeleteColorSpaces](#oh_capturesession_deletecolorspaces) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*colorSpace) | Deletes color spaces.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_GetActiveColorSpace](#oh_capturesession_getactivecolorspace) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace \*colorSpace) | Obtains the active color space.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_SetActiveColorSpace](#oh_capturesession_setactivecolorspace) ([Camera_CaptureSession](#camera_capturesession) \*session, OH_NativeBuffer_ColorSpace colorSpace) | Sets the active color space.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_RegisterCallback](#oh_metadataoutput_registercallback) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | Registers a callback to listen for metadata output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_UnregisterCallback](#oh_metadataoutput_unregistercallback) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | Unregisters the callback used to listen for metadata output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Start](#oh_metadataoutput_start) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Starts metadata output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Stop](#oh_metadataoutput_stop) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Stops metadata output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Release](#oh_metadataoutput_release) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Releases a **MetadataOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoNative_GetMainImage](#oh_photonative_getmainimage) ([OH_PhotoNative](#oh_photonative) \*photo, OH_ImageNative \*\*mainImage) | Obtains a full quality photo.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoNative_Release](#oh_photonative_release) ([OH_PhotoNative](#oh_photonative) \*photo) | Releases a full quality photo.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCallback](#oh_photooutput_registercallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Registers a callback to listen for photo output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCallback](#oh_photooutput_unregistercallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Unregisters the callback used to listen for photo output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCaptureStartWithInfoCallback](#oh_photooutput_registercapturestartwithinfocallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo) callback) | Registers a callback to listen for capture start events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback](#oh_photooutput_unregistercapturestartwithinfocallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo) callback) | Unregisters the callback used to listen for capture start events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCaptureEndCallback](#oh_photooutput_registercaptureendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend) callback) | Registers a callback to listen for capture end events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureEndCallback](#oh_photooutput_unregistercaptureendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend) callback) | Unregisters the callback used to listen for capture end events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterFrameShutterEndCallback](#oh_photooutput_registerframeshutterendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend) callback) | Registers a callback to listen for frame shutter end events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterFrameShutterEndCallback](#oh_photooutput_unregisterframeshutterendcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend) callback) | Unregisters the callback used to listen for frame shutter end events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCaptureReadyCallback](#oh_photooutput_registercapturereadycallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready) callback) | Registers a callback to listen for camera ready events. When the callback is received, the next capture can be performed.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCaptureReadyCallback](#oh_photooutput_unregistercapturereadycallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready) callback) | Unregisters the callback used to listen for camera ready events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback](#oh_photooutput_registerestimatedcapturedurationcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration) callback) | Registers a callback to listen for estimated capture duration events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback](#oh_photooutput_unregisterestimatedcapturedurationcallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration) callback) | Unregisters the callback used to listen for estimated capture duration events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAvailableCallback](#oh_photooutput_registerphotoavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable) callback) | Registers a callback to listen for photo availability events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAvailableCallback](#oh_photooutput_unregisterphotoavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable) callback) | Unregisters the callback used to listen for photo availability events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterPhotoAssetAvailableCallback](#oh_photooutput_registerphotoassetavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable) callback) | Registers a callback to listen for photo asset availability events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback](#oh_photooutput_unregisterphotoassetavailablecallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable) callback) | Unregisters the callback used to listen for photo asset availability events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Capture](#oh_photooutput_capture) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Captures a photo.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Capture_WithCaptureSetting](#oh_photooutput_capture_withcapturesetting) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) setting) | Captures a photo with photographing parameters.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Release](#oh_photooutput_release) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Releases a **PhotoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_IsMirrorSupported](#oh_photooutput_ismirrorsupported) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool \*isSupported) | Checks whether mirroring is supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_GetActiveProfile](#oh_photooutput_getactiveprofile) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_Profile](_camera___profile.md) \*\*profile) | Obtains the profile of a **PhotoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_DeleteProfile](#oh_photooutput_deleteprofile) ([Camera_Profile](_camera___profile.md) \*profile) | Deletes the profile of this **PhotoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_IsMovingPhotoSupported](#oh_photooutput_ismovingphotosupported) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool \*isSupported) | Checks whether moving photos are supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_EnableMovingPhoto](#oh_photooutput_enablemovingphoto) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool enabled) | Enables moving photos.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_RegisterCallback](#oh_previewoutput_registercallback) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Registers a callback to listen for preview output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_UnregisterCallback](#oh_previewoutput_unregistercallback) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Unregisters the callback used to listen for preview output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Start](#oh_previewoutput_start) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Starts preview output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Stop](#oh_previewoutput_stop) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Stops preview output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Release](#oh_previewoutput_release) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Releases a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_GetActiveProfile](#oh_previewoutput_getactiveprofile) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_Profile](_camera___profile.md) \*\*profile) | Obtains the profile of a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_DeleteProfile](#oh_previewoutput_deleteprofile) ([Camera_Profile](_camera___profile.md) \*profile) | Deletes the profile of this **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_GetSupportedFrameRates](#oh_previewoutput_getsupportedframerates) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*\*frameRateRange, uint32_t \*size) | Obtains the list of frame rates supported by a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_DeleteFrameRates](#oh_previewoutput_deleteframerates) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Deletes the frame rate list.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_SetFrameRate](#oh_previewoutput_setframerate) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, int32_t minFps, int32_t maxFps) | Sets the frame rates for a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_GetActiveFrameRate](#oh_previewoutput_getactiveframerate) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Obtains the active frame rates of a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_RegisterCallback](#oh_videooutput_registercallback) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Registers a callback to listen for video output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_UnregisterCallback](#oh_videooutput_unregistercallback) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Unregisters the callback used to listen for video output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Start](#oh_videooutput_start) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Starts video output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Stop](#oh_videooutput_stop) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Stops video output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Release](#oh_videooutput_release) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Releases a **VideoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_GetActiveProfile](#oh_videooutput_getactiveprofile) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_VideoProfile](_camera___video_profile.md) \*\*profile) | Obtains the profile of a **VideoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_DeleteProfile](#oh_videooutput_deleteprofile) ([Camera_VideoProfile](_camera___video_profile.md) \*profile) | Deletes the profile of this **VideoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_GetSupportedFrameRates](#oh_videooutput_getsupportedframerates) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*\*frameRateRange, uint32_t \*size) | Obtains the list of frame rates supported by a **VideoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_DeleteFrameRates](#oh_videooutput_deleteframerates) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Deletes the frame rate list.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_SetFrameRate](#oh_videooutput_setframerate) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, int32_t minFps, int32_t maxFps) | Sets the frame rates for a **VideoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_GetActiveFrameRate](#oh_videooutput_getactiveframerate) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_FrameRateRange](_camera___frame_rate_range.md) \*frameRateRange) | Obtains the active frame rates of a **VideoOutput** instance.| 


## Type Description


### Camera_CaptureEndInfo

```
typedef struct Camera_CaptureEndInfo Camera_CaptureEndInfo
```

**Description**

Defines a struct for the capture end information.

**Since**: 11


### Camera_CaptureSession

```
typedef struct Camera_CaptureSession Camera_CaptureSession
```

**Description**

Defines a struct for the capture session object.

You can call [OH_CameraManager_CreateCaptureSession](#oh_cameramanager_createcapturesession) to create such an object.

**Since**: 11


### Camera_CaptureStartInfo

```
typedef struct Camera_CaptureStartInfo Camera_CaptureStartInfo
```

**Description**

Defines a struct for the capture start information.

**Since**: 12


### Camera_Connection

```
typedef enum Camera_Connection Camera_Connection
```

**Description**

Defines an enum for the camera connection types.

**Since**: 11


### Camera_Device

```
typedef struct Camera_Device Camera_Device
```

**Description**

Defines a struct for the camera device.

**Since**: 11


### Camera_ErrorCode

```
typedef enum Camera_ErrorCode Camera_ErrorCode
```

**Description**

Defines an enum for the camera error codes.

**Since**: 11


### Camera_ExposureMode

```
typedef enum Camera_ExposureMode Camera_ExposureMode
```

**Description**

Defines an enum for the exposure modes.

**Since**: 11


### Camera_FlashMode

```
typedef enum Camera_FlashMode Camera_FlashMode
```

**Description**

Defines an enum for the flash modes.

**Since**: 11


### Camera_FocusMode

```
typedef enum Camera_FocusMode Camera_FocusMode
```

**Description**

Defines an enum for the focus modes.

**Since**: 11


### Camera_FocusState

```
typedef enum Camera_FocusState Camera_FocusState
```

**Description**

Defines an enum for the focus states.

**Since**: 11


### Camera_Format

```
typedef enum Camera_FormatCamera_Format
```

**Description**

Defines an enum for the camera output formats.

**Since**: 11


### Camera_FrameRateRange

```
typedef struct Camera_FrameRateRange Camera_FrameRateRange
```

**Description**

Defines a struct for the frame rate range.

**Since**: 11


### Camera_FrameShutterEndInfo

```
typedef struct Camera_FrameShutterEndInfo Camera_FrameShutterEndInfo
```

**Description**

Defines a struct for the frame shutter end information during capture.

**Since**: 12


### Camera_FrameShutterInfo

```
typedef struct Camera_FrameShutterInfo Camera_FrameShutterInfo
```

**Description**

Defines a struct for the frame shutter information.

**Since**: 11


### Camera_ImageRotation

```
typedef enum Camera_ImageRotation Camera_ImageRotation
```

**Description**

Defines an enum for the image rotation angles.

**Since**: 11


### Camera_Input

```
typedef struct Camera_Input Camera_Input
```

**Description**

Defines a struct for the camera input object.

You can call [OH_CameraManager_CreateCameraInput](#oh_cameramanager_createcamerainput) to create such an object.

**Since**: 11


### Camera_Location

```
typedef struct Camera_Location Camera_Location
```

**Description**

Defines a struct for the location where the photo is taken.

**Since**: 11


### Camera_Manager

```
typedef struct Camera_Manager Camera_Manager
```

**Description**

Defines a struct for the camera manager.

You can call [OH_Camera_GetCameraManager](#oh_camera_getcameramanager) to create such an object.

**Since**: 11


### Camera_MetadataObject

```
typedef struct Camera_MetadataObject Camera_MetadataObject
```

**Description**

Defines a struct for the camera metadata.

**Since**: 11


### Camera_MetadataObjectType

```
typedef enum Camera_MetadataObjectType Camera_MetadataObjectType
```

**Description**

Defines an enum for the metadata object types.

**Since**: 11


### Camera_MetadataOutput

```
typedef struct Camera_MetadataOutput Camera_MetadataOutput
```

**Description**

Defines a struct for the metadata output object.

You can call [OH_CameraManager_CreateMetadataOutput](#oh_cameramanager_createmetadataoutput) to create such an object.

**Since**: 11


### Camera_OutputCapability

```
typedef struct Camera_OutputCapability Camera_OutputCapability
```

**Description**

Defines a struct for the camera output capability.

**Since**: 11


### Camera_PhotoCaptureSetting

```
typedef struct Camera_PhotoCaptureSetting Camera_PhotoCaptureSetting
```

**Description**

Defines a struct for the parameters related to photo capture.

**Since**: 11


### Camera_PhotoOutput

```
typedef struct Camera_PhotoOutput Camera_PhotoOutput
```

**Description**

Defines a struct for the photo output object.

You can call [OH_CameraManager_CreatePhotoOutput](#oh_cameramanager_createphotooutput) to create such an object.

**Since**: 11


### Camera_Point

```
typedef struct Camera_Point Camera_Point
```

**Description**

Defines a struct for the parameters related to a point.

**Since**: 11


### Camera_Position

```
typedef enum Camera_Position Camera_Position
```

**Description**

Defines an enum for the camera positions.

**Since**: 11


### Camera_PreconfigRatio

```
typedef enum Camera_PreconfigRatio Camera_PreconfigRatio
```

**Description**

Defines an enum for the preconfigured aspect ratios.

**Since**: 12


### Camera_PreconfigType

```
typedef enum Camera_PreconfigType Camera_PreconfigType
```

**Description**

Defines an enum for the preconfigured resolution types.

**Since**: 12


### Camera_PreviewOutput

```
typedef struct Camera_PreviewOutput Camera_PreviewOutput
```

**Description**

Defines a struct for the preview output object.

You can call [OH_CameraManager_CreatePreviewOutput](#oh_cameramanager_createpreviewoutput) to create such an object.

**Since**: 11


### Camera_Profile

```
typedef struct Camera_Profile Camera_Profile
```

**Description**

Defines a struct for the profile of a camera stream.

**Since**: 11


### Camera_QualityLevel

```
typedef enum Camera_QualityLevel Camera_QualityLevel
```

**Description**

Defines an enum for the image quality levels.

**Since**: 11


### Camera_Rect

```
typedef struct Camera_Rect Camera_Rect
```

**Description**

Defines a struct for the rectangle.

**Since**: 11


### Camera_SceneMode

```
typedef enum Camera_SceneMode Camera_SceneMode
```

**Description**

Defines an enum for the camera scene modes.

**Since**: 12


### Camera_Size

```
typedef struct Camera_Size Camera_Size
```

**Description**

Defines a struct for the parameters related to the size.

**Since**: 11


### Camera_SmoothZoomInfo

```
typedef struct Camera_SmoothZoomInfo Camera_SmoothZoomInfo
```

**Description**

Defines a struct for the smooth zoom information.

**Since**: 12


### Camera_SmoothZoomMode

```
typedef enum Camera_SmoothZoomMode Camera_SmoothZoomMode
```

**Description**

Defines an enum for the smooth zoom modes.

**Since**: 12


### Camera_Status

```
typedef enum Camera_Status Camera_Status
```

**Description**

Defines an enum for the camera statuses.

**Since**: 11


### Camera_StatusInfo

```
typedef struct Camera_StatusInfo Camera_StatusInfo
```

**Description**

Defines a struct for the camera status information.

**Since**: 11


### Camera_TorchMode

```
typedef enum Camera_TorchMode Camera_TorchMode
```

**Description**

Defines an enum for the flashlight modes.

**Since**: 12


### Camera_TorchStatusInfo

```
typedef struct Camera_TorchStatusInfo Camera_TorchStatusInfo
```

**Description**

Defines a struct for the flashlight status information.

**Since**: 12


### Camera_Type

```
typedef enum Camera_Type Camera_Type
```

**Description**

Defines an enum for the camera types.

**Since**: 11


### Camera_VideoOutput

```
typedef struct Camera_VideoOutput Camera_VideoOutput
```

**Description**

Defines a struct for the video output object.

You can call [OH_CameraManager_CreateVideoOutput](#oh_cameramanager_createvideooutput) to create such an object.

**Since**: 11


### Camera_VideoProfile

```
typedef struct Camera_VideoProfile Camera_VideoProfile
```

**Description**

Defines a struct for the video profile.

**Since**: 11


### Camera_VideoStabilizationMode

```
typedef enum Camera_VideoStabilizationMode Camera_VideoStabilizationMode
```

**Description**

Defines an enum for the video stabilization modes.

**Since**: 11


### CameraInput_Callbacks

```
typedef struct CameraInput_Callbacks CameraInput_Callbacks
```

**Description**

Defines a struct for the callbacks used to listen for camera input errors.

**Since**: 11

**See**

[OH_CameraInput_RegisterCallback](#oh_camerainput_registercallback)


### CameraManager_Callbacks

```
typedef struct CameraManager_Callbacks CameraManager_Callbacks
```

**Description**

Defines a struct for the callbacks used to listen for camera status changes.

**Since**: 11

**See**

[OH_CameraManager_RegisterCallback](#oh_cameramanager_registercallback)


### CaptureSession_Callbacks

```
typedef struct CaptureSession_Callbacks CaptureSession_Callbacks
```

**Description**

Defines a struct for the callbacks used for a capture session.

**Since**: 11

**See**

[OH_CaptureSession_RegisterCallback](#oh_capturesession_registercallback)


### MetadataOutput_Callbacks

```
typedef struct MetadataOutput_Callbacks MetadataOutput_Callbacks
```

**Description**

Defines a struct for the callbacks related to metadata output.

**Since**: 11

**See**

[OH_MetadataOutput_RegisterCallback](#oh_metadataoutput_registercallback)


### OH_CameraInput_OnError

```
typedef void (*OH_CameraInput_OnError)(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct and used to report camera input errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the [Camera_Input](#camera_input) instance that transfers the callback.| 
| errorCode | Error code reported during camera input and defined in [Camera_ErrorCode](#camera_errorcode-1).| 

**See**

In [Camera_ErrorCode](#camera_errorcode-1):

- CAMERA_CONFLICT_CAMERA

- CAMERA_DEVICE_DISABLED

- CAMERA_DEVICE_PREEMPTED

- CAMERA_SERVICE_FATAL_ERROR


### OH_CameraManager_StatusCallback

```
typedef void (*OH_CameraManager_StatusCallback)(Camera_Manager* cameraManager, Camera_StatusInfo* status)
```

**Description**

Defines the callback defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct and used to report the camera manager status.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to the [Camera_Manager](#camera_manager) instance that transfers the callback.| 
| status | Pointer to the camera manager status, which is defined in the [Camera_StatusInfo](_camera___status_info.md) struct.| 


### OH_CameraManager_TorchStatusCallback

```
typedef void (*OH_CameraManager_TorchStatusCallback)(Camera_Manager* cameraManager, Camera_TorchStatusInfo* status)
```

**Description**

Defines the callback invoked when the flashlight status changes.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to the [Camera_Manager](#camera_manager) instance that transfers the callback.| 
| status | Pointer to the flashlight status, which is defined in the [Camera_TorchStatusInfo](_camera___torch_status_info.md) struct.| 


### OH_CaptureSession_OnError

```
typedef void (*OH_CaptureSession_OnError)(Camera_CaptureSession* session, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report capture session errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the [Camera_CaptureSession](#camera_capturesession) instance that transfers the callback.| 
| errorCode | Error code reported in a capture session and defined in [Camera_ErrorCode](#camera_errorcode-1).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode-1).


### OH_CaptureSession_OnFocusStateChange

```
typedef void (*OH_CaptureSession_OnFocusStateChange)(Camera_CaptureSession* session, Camera_FocusState focusState)
```

**Description**

Defines the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report focus status changes of a capture session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the [Camera_CaptureSession](#camera_capturesession) instance that transfers the callback.| 
| focusState | Focus state, which is defined in [Camera_FocusState](#camera_focusstate).| 


### OH_CaptureSession_OnSmoothZoomInfo

```
typedef void (*OH_CaptureSession_OnSmoothZoomInfo)(Camera_CaptureSession* session, Camera_SmoothZoomInfo* smoothZoomInfo)
```

**Description**

Defines the callback invoked when smooth zoom is triggered for a capture session.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the [Camera_CaptureSession](#camera_capturesession) instance that transfers the callback.| 
| smoothZoomInfo | Pointer to [Camera_SmoothZoomInfo](_camera___smooth_zoom_info.md) passed by the callback.| 


### OH_MetadataOutput_OnError

```
typedef void (*OH_MetadataOutput_OnError)(Camera_MetadataOutput* metadataOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the [Camera_MetadataOutput](#camera_metadataoutput) instance that transfers the callback.| 
| errorCode | Error code reported during metadata output and defined in [Camera_ErrorCode](#camera_errorcode-1).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode-1).


### OH_MetadataOutput_OnMetadataObjectAvailable

```
typedef void (*OH_MetadataOutput_OnMetadataObjectAvailable)(Camera_MetadataOutput* metadataOutput, Camera_MetadataObject* metadataObject, uint32_t size)
```

**Description**

Defines the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output data.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the [Camera_MetadataOutput](#camera_metadataoutput) instance that transfers the callback.| 
| metadataObject | Pointer to the metadata output data, which is defined in the [Camera_MetadataObject](_camera___metadata_object.md) struct.| 
| size | Size of the metadata object.| 


### OH_PhotoNative

```
typedef struct OH_PhotoNative OH_PhotoNative
```

**Description**

Defines a struct for a camera photo object.

Defines a high-resolution image object.

**Since**: 12


### OH_PhotoOutput_CaptureEnd

```
typedef void (*OH_PhotoOutput_CaptureEnd) (Camera_PhotoOutput* photoOutput, int32_t frameCount)
```

**Description**

Defines the callback invoked when the capture ends.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| frameCount | Number of frames to be included in the callback.| 


### OH_PhotoOutput_CaptureReady

```
typedef void (*OH_PhotoOutput_CaptureReady) (Camera_PhotoOutput* photoOutput)
```

**Description**

Defines the callback invoked when the camera is ready to take photos. When the callback is received, the next capture can be performed.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 


### OH_PhotoOutput_CaptureStartWithInfo

```
typedef void (*OH_PhotoOutput_CaptureStartWithInfo) (Camera_PhotoOutput* photoOutput, Camera_CaptureStartInfo* Info)
```

**Description**

Defines the callback invoked when the capture starts.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| Info | Pointer to [Camera_CaptureStartInfo](_camera___capture_start_info.md) passed by the callback.| 


### OH_PhotoOutput_EstimatedCaptureDuration

```
typedef void (*OH_PhotoOutput_EstimatedCaptureDuration) (Camera_PhotoOutput* photoOutput, int64_t duration)
```

**Description**

Defines the callback for the estimated capture duration.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| duration | Estimated capture duration passed by the callback.| 


### OH_PhotoOutput_OnError

```
typedef void (*OH_PhotoOutput_OnError)(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| errorCode | Error code reported during photo output and defined in [Camera_ErrorCode](#camera_errorcode-1).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode-1).


### OH_PhotoOutput_OnFrameEnd

```
typedef void (*OH_PhotoOutput_OnFrameEnd)(Camera_PhotoOutput* photoOutput, int32_t frameCount)
```

**Description**

Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame end events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| frameCount | Number of frames to be included in the callback.| 


### OH_PhotoOutput_OnFrameShutter

```
typedef void (*OH_PhotoOutput_OnFrameShutter)(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info)
```

**Description**

Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report frame shutter events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| info | Pointer to the frame shutter information, which is defined in the [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) struct.| 


### OH_PhotoOutput_OnFrameShutterEnd

```
typedef void (*OH_PhotoOutput_OnFrameShutterEnd) (Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* Info)
```

**Description**

Defines the callback invoked when frame shutter ends.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| Info | Pointer to [Camera_CaptureStartInfo](_camera___capture_start_info.md) passed by the callback.| 


### OH_PhotoOutput_OnFrameStart

```
typedef void(* OH_PhotoOutput_OnFrameStart) (Camera_PhotoOutput *photoOutput)
```

**Description**

Defines the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame start events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 


### OH_PhotoOutput_PhotoAssetAvailable

```
typedef void (*OH_PhotoOutput_PhotoAssetAvailable)(Camera_PhotoOutput* photoOutput, OH_MediaAsset* photoAsset)
```

**Description**

Defines the callback invoked when a photo asset is available.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| photoAsset | Pointer to [OH_MediaAsset](../apis-media-library-kit/_media_asset_manager.md#oh_mediaasset) passed by the callback.| 


### OH_PhotoOutput_PhotoAvailable

```
typedef void (*OH_PhotoOutput_PhotoAvailable)(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo)
```

**Description**

Defines the callback invoked when a high-resolution photo is available.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| photo | Pointer to [OH_PhotoNative](#oh_photonative) passed by the callback.| 


### OH_PreviewOutput_OnError

```
typedef void (*OH_PreviewOutput_OnError)(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance that transfers the callback.| 
| errorCode | Error code reported during preview output and defined in [Camera_ErrorCode](#camera_errorcode-1).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode-1).


### OH_PreviewOutput_OnFrameEnd

```
typedef void (*OH_PreviewOutput_OnFrameEnd)(Camera_PreviewOutput* previewOutput, int32_t frameCount)
```

**Description**

Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used report preview output frame end events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance that transfers the callback.| 
| frameCount | Number of frames to be included in the callback.| 


### OH_PreviewOutput_OnFrameStart

```
typedef void (*OH_PreviewOutput_OnFrameStart)(Camera_PreviewOutput* previewOutput)
```

**Description**

Defines the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame start events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance that transfers the callback.| 


### OH_VideoOutput_OnError

```
typedef void (*OH_VideoOutput_OnError)(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance that transfers the callback.| 
| errorCode | Error code reported during video output and defined in [Camera_ErrorCode](#camera_errorcode-1).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode-1).


### OH_VideoOutput_OnFrameEnd

```
typedef void (*OH_VideoOutput_OnFrameEnd)(Camera_VideoOutput* videoOutput, int32_t frameCount)
```

**Description**

Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame end events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance that transfers the callback.| 
| frameCount | Number of frames to be included in the callback.| 


### OH_VideoOutput_OnFrameStart

```
typedef void (*OH_VideoOutput_OnFrameStart)(Camera_VideoOutput* videoOutput)
```

**Description**

Defines the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame start events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance that transfers the callback.| 


### PhotoOutput_Callbacks

```
typedef struct PhotoOutput_Callbacks PhotoOutput_Callbacks
```

**Description**

Defines a struct for the callbacks related to photo output.

**Since**: 11

**See**

[OH_PhotoOutput_RegisterCallback](#oh_photooutput_registercallback)


### PreviewOutput_Callbacks

```
typedef struct PreviewOutput_Callbacks PreviewOutput_Callbacks
```

**Description**

Defines a struct for the callbacks related to preview output.

**Since**: 11

**See**

[OH_PreviewOutput_RegisterCallback](#oh_previewoutput_registercallback)


### VideoOutput_Callbacks

```
typedef struct VideoOutput_Callbacks VideoOutput_Callbacks
```

**Description**

Defines a struct for the callbacks related to video output.

**Since**: 11

**See**

[OH_VideoOutput_RegisterCallback](#oh_videooutput_registercallback)


## Enum Description


### Camera_Connection

```
enum Camera_Connection
```

**Description**

Enumerates the camera connection types.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CAMERA_CONNECTION_BUILT_IN | Built-in camera.| 
| CAMERA_CONNECTION_USB_PLUGIN | Camera connected using USB.| 
| CAMERA_CONNECTION_REMOTE | Remote camera.| 


### Camera_ErrorCode

```
enum Camera_ErrorCode
```

**Description**

Enumerates the camera error codes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CAMERA_OK | The camera is normal.| 
| CAMERA_INVALID_ARGUMENT | A parameter is missing or the parameter type is incorrect.| 
| CAMERA_OPERATION_NOT_ALLOWED | The operation is not allowed.| 
| CAMERA_SESSION_NOT_CONFIG | The session is not configured.| 
| CAMERA_SESSION_NOT_RUNNING | The session is not running.| 
| CAMERA_SESSION_CONFIG_LOCKED | The session configuration is locked.| 
| CAMERA_DEVICE_SETTING_LOCKED | The device setting is locked.| 
| CAMERA_CONFLICT_CAMERA | The device is already started.| 
| CAMERA_DEVICE_DISABLED | The camera is disabled for security reasons.| 
| CAMERA_DEVICE_PREEMPTED | The camera is preempted.| 
| CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS | The configuration conflicts with the current configuration.<br>**Since**: 12| 
| CAMERA_SERVICE_FATAL_ERROR | A fatal error occurs in the camera service.| 


### Camera_ExposureMode

```
enum Camera_ExposureMode
```

**Description**

Enumerates the exposure modes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| EXPOSURE_MODE_LOCKED | Exposure locked.| 
| EXPOSURE_MODE_AUTO | Auto exposure.| 
| EXPOSURE_MODE_CONTINUOUS_AUTO | Continuous auto exposure.| 


### Camera_FlashMode

```
enum Camera_FlashMode
```

**Description**

Enumerates the flash modes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| FLASH_MODE_CLOSE | The flash is off.| 
| FLASH_MODE_OPEN | The flash is on.| 
| FLASH_MODE_AUTO | The flash mode is auto.| 
| FLASH_MODE_ALWAYS_OPEN | The flash is steady on.| 


### Camera_FocusMode

```
enum Camera_FocusMode
```

**Description**

Enumerates the focus modes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| FOCUS_MODE_MANUAL | Manual focus.| 
| FOCUS_MODE_CONTINUOUS_AUTO | Continuous auto focus.| 
| FOCUS_MODE_AUTO | Auto focus.| 
| FOCUS_MODE_LOCKED | Focus locked.| 


### Camera_FocusState

```
enum Camera_FocusState
```

**Description**

Enumerates the focus states.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| FOCUS_STATE_SCAN | Focusing.| 
| FOCUS_STATE_FOCUSED | Focused.| 
| FOCUS_STATE_UNFOCUSED | Unfocused.| 


### Camera_Format

```
enum Camera_Format
```

**Description**

Enumerates the camera output formats.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CAMERA_FORMAT_RGBA_8888 | RGBA 8888.| 
| CAMERA_FORMAT_YUV_420_SP | YUV 420 SP.| 
| CAMERA_FORMAT_JPEG | JPEG.| 
| CAMERA_FORMAT_YCBCR_P010 | YCBCR P010.<br>**Since**: 12| 
| CAMERA_FORMAT_YCRCB_P010 | YCRCB P010.<br>**Since**: 12| 


### Camera_ImageRotation

```
enum Camera_ImageRotation
```

**Description**

Enumerates the image rotation angles.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| IAMGE_ROTATION_0 | The image rotates 0 degrees.| 
| IAMGE_ROTATION_90 | The image rotates 90 degrees.| 
| IAMGE_ROTATION_180 | The image rotates 180 degrees.| 
| IAMGE_ROTATION_270 | The image rotates 270 degrees.| 


### Camera_MetadataObjectType

```
enum Camera_MetadataObjectType
```

**Description**

Enumerates the metadata object types.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| FACE_DETECTION | Face detection.| 


### Camera_Position

```
enum Camera_Position
```

**Description**

Enumerates the camera positions.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CAMERA_POSITION_UNSPECIFIED | Unspecified position.| 
| CAMERA_POSITION_BACK | Rear camera.| 
| CAMERA_POSITION_FRONT | Front camera.| 


### Camera_PreconfigRatio

```
enum Camera_PreconfigRatio
```

**Description**

Enumerates the preconfigured aspect ratios.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| PRECONFIG_RATIO_1_1 | 1:1 aspect ratio.| 
| PRECONFIG_RATIO_4_3 | 4:3 aspect ratio.| 
| PRECONFIG_RATIO_16_9 | 16:9 aspect ratio.| 


### Camera_PreconfigType

```
enum Camera_PreconfigType
```

**Description**

Enumerates the preconfigured resolution types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| PRECONFIG_720P | 720p resolution.| 
| PRECONFIG_1080P | 1080p resolution.| 
| PRECONFIG_4K | 4K resolution.| 
| PRECONFIG_HIGH_QUALITY | High-quality photos.| 


### Camera_QualityLevel

```
enum Camera_QualityLevel
```

**Description**

Enumerates the image quality levels.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| QUALITY_LEVEL_HIGH | High image quality.| 
| QUALITY_LEVEL_MEDIUM | Medium image quality.| 
| QUALITY_LEVEL_LOW | Low image quality.| 


### Camera_SceneMode

```
enum Camera_SceneMode
```

**Description**

Enumerates the camera scene modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NORMAL_PHOTO | Normal photo mode.| 
| NORMAL_VIDEO | Normal video mode.| 
| SECURE_PHOTO | Secure mode.| 


### Camera_SmoothZoomMode

```
enum Camera_SmoothZoomMode
```

**Description**

Enumerates the smooth zoom modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NORMAL | Bessel curve mode.| 


### Camera_Status

```
enum Camera_Status
```

**Description**

Enumerates the camera statuses.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CAMERA_STATUS_APPEAR | A camera appears.| 
| CAMERA_STATUS_DISAPPEAR | The camera disappears.| 
| CAMERA_STATUS_AVAILABLE | The camera is available.| 
| CAMERA_STATUS_UNAVAILABLE | The camera is unavailable.| 


### Camera_TorchMode

```
enum Camera_TorchMode
```

**Description**

Enumerates the flashlight modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OFF | The flashlight is always off.| 
| ON | The flashlight is always on.| 
| AUTO | The flashlight will be turned on automatically based on the ambient lighting level.| 


### Camera_Type

```
enum Camera_Type
```

**Description**

Enumerates the camera types.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CAMERA_TYPE_DEFAULT | Default camera type.| 
| CAMERA_TYPE_WIDE_ANGLE | Wide camera.| 
| CAMERA_TYPE_ULTRA_WIDE | Ultra wide camera.| 
| CAMERA_TYPE_TELEPHOTO | Telephone camera.| 
| CAMERA_TYPE_TRUE_DEPTH | Camera with depth of field information.| 


### Camera_VideoStabilizationMode

```
enum Camera_VideoStabilizationMode
```

**Description**

Enumerates the video stabilization modes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| STABILIZATION_MODE_OFF | Video stabilization is disabled.| 
| STABILIZATION_MODE_LOW | The basic video stabilization algorithm is used.| 
| STABILIZATION_MODE_MIDDLE | A video stabilization algorithm with a stabilization effect better than that of the **LOW** type is used.| 
| STABILIZATION_MODE_HIGH | A video stabilization algorithm with a stabilization effect better than that of the **MIDDLE** type is used.| 
| STABILIZATION_MODE_AUTO | Automatic video stabilization is used. This value is available for HDF cameras.| 


## Function Description


### OH_Camera_DeleteCameraManager()

```
Camera_ErrorCode OH_Camera_DeleteCameraManager(Camera_Manager* cameraManager)
```

**Description**

Deletes a **CameraManager** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to the target [Camera_Manager](#camera_manager) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_Camera_GetCameraManager()

```
Camera_ErrorCode OH_Camera_GetCameraManager(Camera_Manager** cameraManager)
```

**Description**

Obtains a **CameraManager** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Double pointer to the [Camera_Manager](#camera_manager) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraDevice_GetCameraOrientation()

```
Camera_ErrorCode OH_CameraDevice_GetCameraOrientation(Camera_Device* camera, uint32_t* orientation)
```

**Description**

Obtains the sensor direction of a camera device.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| camera | Pointer to the target [Camera_Device](_camera___device.md) instance.| 
| orientation | Pointer to the sensor direction obtained.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraInput_Close()

```
Camera_ErrorCode OH_CameraInput_Close(Camera_Input* cameraInput)
```

**Description**

Closes a camera.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraInput_Open()

```
Camera_ErrorCode OH_CameraInput_Open(Camera_Input* cameraInput)
```

**Description**

Opens a camera.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_CONFLICT_CAMERA**: The camera cannot be used due to a conflict.

- **CAMERA_DEVICE_DISABLED**: The camera is disabled due to security reasons.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraInput_OpenSecureCamera()

```
Camera_ErrorCode OH_CameraInput_OpenSecureCamera(Camera_Input* cameraInput, uint64_t* secureSeqId)
```

**Description**

Opens a camera in secure mode.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 
| secureSeqId | Pointer to the sequence ID of the camera.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_CONFLICT_CAMERA**: The camera cannot be used due to a conflict.

- **CAMERA_DEVICE_DISABLED**: The camera is disabled due to security reasons.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraInput_RegisterCallback()

```
Camera_ErrorCode OH_CameraInput_RegisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**Description**

Registers a callback to listen for camera input events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to a [Camera_Input](#camera_input) instance.| 
| callback | Pointer to the target callback, which is defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraInput_Release()

```
Camera_ErrorCode OH_CameraInput_Release(Camera_Input* cameraInput)
```

**Description**

Releases a **CameraInput** instance.

Either this function or [OH_CameraInput_Close](#oh_camerainput_close) needs to be called.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraInput_UnregisterCallback()

```
Camera_ErrorCode OH_CameraInput_UnregisterCallback(Camera_Input* cameraInput, CameraInput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for camera input events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to a [Camera_Input](#camera_input) instance.| 
| callback | Pointer to the target callback, which is defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_CreateCameraInput()

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_Input** cameraInput)
```

**Description**

Creates a **CameraInput** instance.

**Since**: 11

**Required permissions**: ohos.permission.CAMERA

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| camera | Pointer to the target camera, which is defined in [Camera_Device](_camera___device.md).| 
| cameraInput | Double pointer to the [Camera_Input](#camera_input) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreateCameraInput_WithPositionAndType()

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput_WithPositionAndType(Camera_Manager* cameraManager, Camera_Position position, Camera_Type type, Camera_Input** cameraInput)
```

**Description**

Creates a **CameraInput** instance with the specified location and type.

**Since**: 11

**Required permissions**: ohos.permission.CAMERA

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| position | Camera position, which is defined in [Camera_Position](#camera_position).| 
| type | Camera type, which is defined in [Camera_Type](#camera_type).| 
| cameraInput | Double pointer to the [Camera_Input](#camera_input) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreateCaptureSession()

```
Camera_ErrorCode OH_CameraManager_CreateCaptureSession(Camera_Manager* cameraManager,
 Camera_CaptureSession** captureSession)
```

**Description**

Creates a **CaptureSession** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| captureSession | Double pointer to the [Camera_CaptureSession](#camera_capturesession) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreateMetadataOutput()

```
Camera_ErrorCode OH_CameraManager_CreateMetadataOutput(Camera_Manager* cameraManager, const Camera_MetadataObjectType* profile, Camera_MetadataOutput** metadataOutput)
```

**Description**

Creates a **MetadataOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| profile | Pointer to the profile, which is defined in [Camera_MetadataObjectType](#camera_metadataobjecttype).| 
| metadataOutput | Double pointer to the [Camera_MetadataOutput](#camera_metadataoutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreatePhotoOutput()

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PhotoOutput** photoOutput)
```

**Description**

Creates a **PhotoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| profile | Pointer to the profile, which is defined in [Camera_Profile](_camera___profile.md).| 
| surfaceId | Pointer to the surface ID.| 
| photoOutput | Double pointer to the [Camera_PhotoOutput](#camera_photooutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreatePhotoOutputUsedInPreconfig()

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PhotoOutput** photoOutput)
```

**Description**

Creates a **PhotoOutput** instance to be used in a preconfiguration stream.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| surfaceId | Pointer to the surface ID.| 
| photoOutput | Double pointer to the [Camera_PhotoOutput](#camera_photooutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreatePhotoOutputWithoutSurface()

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutputWithoutSurface(Camera_Manager *cameraManager, const Camera_Profile *profile, Camera_PhotoOutput **photoOutput)
```

**Description**

Creates a **PhotoOutput** instance. **surfaceId** is not required in this function.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| profile | Pointer to the profile, which is defined in [Camera_Profile](_camera___profile.md).| 
| photoOutput | Double pointer to the [Camera_PhotoOutput](#camera_photooutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreatePreviewOutput()

```
Camera_ErrorCode OH_CameraManager_CreatePreviewOutput(Camera_Manager* cameraManager, const Camera_Profile* profile, const char* surfaceId, Camera_PreviewOutput** previewOutput)
```

**Description**

Creates a **PreviewOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| profile | Pointer to the profile, which is defined in [Camera_Profile](_camera___profile.md).| 
| surfaceId | Pointer to the surface ID.| 
| previewOutput | Double pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreatePreviewOutputUsedInPreconfig()

```
Camera_ErrorCode OH_CameraManager_CreatePreviewOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_PreviewOutput** previewOutput)
```

**Description**

Creates a **PreviewOutput** instance to be used in a preconfiguration stream.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| surfaceId | Pointer to the surface ID.| 
| previewOutput | Double pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreateVideoOutput()

```
Camera_ErrorCode OH_CameraManager_CreateVideoOutput(Camera_Manager* cameraManager, const Camera_VideoProfile* profile, const char* surfaceId, Camera_VideoOutput** videoOutput)
```

**Description**

Creates a **VideoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| profile | Pointer to the profile, which is defined in the [Camera_VideoProfile](_camera___video_profile.md) struct.| 
| surfaceId | Pointer to the surface ID.| 
| videoOutput | Double pointer to the [Camera_VideoOutput](#camera_videooutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_CreateVideoOutputUsedInPreconfig()

```
Camera_ErrorCode OH_CameraManager_CreateVideoOutputUsedInPreconfig(Camera_Manager* cameraManager, const char* surfaceId, Camera_VideoOutput** videoOutput)
```

**Description**

Creates a **VideoOutput** instance to be used in a preconfiguration stream.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| surfaceId | Pointer to the surface ID.| 
| videoOutput | Double pointer to the [Camera_VideoOutput](#camera_videooutput) instance if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_DeleteSceneModes()

```
Camera_ErrorCode OH_CameraManager_DeleteSceneModes(Camera_Manager* cameraManager, Camera_SceneMode* sceneModes)
```

**Description**

Deletes scene modes.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| sceneModes | Target scene modes, which are defined in [Camera_SceneMode](#camera_scenemode).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_DeleteSupportedCameraOutputCapability()

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameraOutputCapability(Camera_Manager* cameraManager, Camera_OutputCapability* cameraOutputCapability)
```

**Description**

Deletes the output capability supported by a camera.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| cameraOutputCapability | Pointer to the output capability, which is defined in the [Camera_OutputCapability](_camera___output_capability.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_DeleteSupportedCameras()

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameras(Camera_Manager* cameraManager, Camera_Device* cameras, uint32_t size)
```

**Description**

Deletes supported cameras.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| cameras | Pointer to a list of cameras, which are defined in [Camera_Device](_camera___device.md).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_GetSupportedCameraOutputCapability()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapability(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_OutputCapability** cameraOutputCapability)
```

**Description**

Obtains the output capability supported by a camera.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| camera | Pointer to a camera, which is defined in [Camera_Device](_camera___device.md).| 
| cameraOutputCapability | Double pointer to the output capability, which is defined in [Camera_OutputCapability](_camera___output_capability.md), if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapabilityWithSceneMode(Camera_Manager* cameraManager, const Camera_Device* camera, Camera_SceneMode sceneMode, Camera_OutputCapability** cameraOutputCapability)
```

**Description**

Obtains the output capability supported by a camera in the specified mode.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| camera | Pointer to a camera, which is defined in [Camera_Device](_camera___device.md).| 
| sceneMode | Scene mode, which is defined in [Camera_SceneMode](#camera_scenemode).| 
| cameraOutputCapability | Double pointer to output capability, which is defined in [Camera_OutputCapability](_camera___output_capability.md), if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_GetSupportedCameras()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameras(Camera_Manager* cameraManager, Camera_Device** cameras, uint32_t* size)
```

**Description**

Obtains supported cameras.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| cameras | Double pointer to the list of cameras, which is defined in [Camera_Device](_camera___device.md), if the function is successfully called.| 
| size | Pointer to the size of the list of cameras.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_GetSupportedSceneModes()

```
Camera_ErrorCode OH_CameraManager_GetSupportedSceneModes(Camera_Device* camera, Camera_SceneMode** sceneModes, uint32_t* size)
```

**Description**

Obtains the scene modes supported by a camera.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| camera | Pointer to a camera, which is defined in [Camera_Device](_camera___device.md).| 
| sceneModes | Double pointer to the list of scene modes, which are defined in [Camera_SceneMode](#camera_scenemode), if the function is successfully called.| 
| size | Pointer to the size of the list of scene modes.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_IsCameraMuted()

```
Camera_ErrorCode OH_CameraManager_IsCameraMuted(Camera_Manager* cameraManager, bool* isCameraMuted)
```

**Description**

Checks whether a camera is muted.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| isCameraMuted | Pointer to the result that specifies whether the camera is muted if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_IsTorchSupported()

```
Camera_ErrorCode OH_CameraManager_IsTorchSupported(Camera_Manager* cameraManager, bool* isTorchSupported)
```

**Description**

Checks whether the device supports the flashlight.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| isTorchSupported | Pointer to the result indicating whether the device supports the flashlight.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_IsTorchSupportedByTorchMode()

```
Camera_ErrorCode OH_CameraManager_IsTorchSupportedByTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode, bool* isTorchSupported)
```

**Description**

Checks whether the device supports the specified flashlight mode.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| torchMode | Target flashlight mode, which is defined in [Camera_TorchMode](#camera_torchmode-1).| 
| isTorchSupported | Pointer to the result indicating whether the device supports the flashlight mode.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_RegisterCallback()

```
Camera_ErrorCode OH_CameraManager_RegisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)
```

**Description**

Registers a callback to listen for camera status changes.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| callback | Pointer to the target callback, which is defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_RegisterTorchStatusCallback()

```
Camera_ErrorCode OH_CameraManager_RegisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)
```

**Description**

Registers a callback to listen for flashlight status changes.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| torchStatusCallback | Target callback, which is defined in [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_SetTorchMode()

```
Camera_ErrorCode OH_CameraManager_SetTorchMode(Camera_Manager* cameraManager, Camera_TorchMode torchMode)
```

**Description**

Sets a flashlight mode.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| torchMode | Target flashlight mode, which is defined in [Camera_TorchMode](#camera_torchmode).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CameraManager_UnregisterCallback()

```
Camera_ErrorCode OH_CameraManager_UnregisterCallback(Camera_Manager* cameraManager, CameraManager_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for camera status changes.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| callback | Pointer to the target callback, which is defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CameraManager_UnregisterTorchStatusCallback()

```
Camera_ErrorCode OH_CameraManager_UnregisterTorchStatusCallback(Camera_Manager* cameraManager, OH_CameraManager_TorchStatusCallback torchStatusCallback)
```

**Description**

Unregisters the callback used to listen for flashlight status changes.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| torchStatusCallback | Target callback, which is defined in [OH_CameraManager_TorchStatusCallback](#oh_cameramanager_torchstatuscallback).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.



### OH_CaptureSession_AddInput()

```
Camera_ErrorCode OH_CaptureSession_AddInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**Description**

Adds a **CameraInput** instance to a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_AddMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_AddMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)
```

**Description**

Adds a **MetadataOutput** instance to a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_AddPhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**Description**

Adds a **PhotoOutput** instance to a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_AddPreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**Description**

Adds a **PreviewOutput** instance to a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_AddSecureOutput()

```
Camera_ErrorCode OH_CaptureSession_AddSecureOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**Description**

Marks a preview output stream as secure output.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.

- **CAMERA_SESSION_CONFIG_LOCKED**: The session configuration is locked.


### OH_CaptureSession_AddVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**Description**

Adds a **VideoOutput** instance to a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_BeginConfig()

```
Camera_ErrorCode OH_CaptureSession_BeginConfig(Camera_CaptureSession* session)
```

**Description**

Starts the configuration for a capture session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_CanAddInput()

```
Camera_ErrorCode OH_CaptureSession_CanAddInput(Camera_CaptureSession* session, Camera_Input* cameraInput, bool* isSuccessful)
```

**Description**

Checks whether a **CameraInput** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 
| isSuccessful | Pointer to the result indicating whether the **CameraInput** instance can be added to the session.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_CanAddPhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddPhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* cameraOutput, bool* isSuccessful)
```

**Description**

Checks whether a **PhotoOutput** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| cameraOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| isSuccessful | Pointer to the result indicating whether the **PhotoOutput** instance can be added to the session.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_CanAddPreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddPreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* cameraOutput, bool* isSuccessful)
```

**Description**

Checks whether a **PreviewOutput** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| cameraOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| isSuccessful | Pointer to the result indicating whether the **PreviewOutput** instance can be added to the session.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_CanAddVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_CanAddVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* cameraOutput, bool* isSuccessful)
```

**Description**

Checks whether a **VideoOutput** instance can be added to a session.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| cameraOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 
| isSuccessful | Pointer to the result indicating whether the **VideoOutput** instance can be added to the session.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_CanPreconfig()

```
Camera_ErrorCode OH_CaptureSession_CanPreconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, bool* canPreconfig)
```

**Description**

Checks whether a preconfigured resolution type is supported.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| preconfigType | Target resolution type, which is defined in [Camera_PreconfigType](#camera_preconfigtype).| 
| canPreconfig | Pointer to the result indicating whether the preconfigured resolution type is supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_CanPreconfigWithRatio()

```
Camera_ErrorCode OH_CaptureSession_CanPreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio, bool* canPreconfig)
```

**Description**

Checks whether a preconfigured resolution type with an aspect ratio is supported.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| preconfigType | Target resolution type, which is defined in [Camera_PreconfigType](#camera_preconfigtype).| 
| preconfigRatio | Target aspect ratio, which is defined in [Camera_PreconfigRatio](#camera_preconfigratio).| 
| canPreconfig | Pointer to the result indicating whether the preconfigured resolution type with the aspect ratio is supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_CommitConfig()

```
Camera_ErrorCode OH_CaptureSession_CommitConfig(Camera_CaptureSession* session)
```

**Description**

Commits the configuration for a capture session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CaptureSession_DeleteColorSpaces()

```
Camera_ErrorCode OH_CaptureSession_DeleteColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)
```

**Description**

Deletes color spaces.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| colorSpace | Pointer to the list of color spaces, which are defined in [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_GetActiveColorSpace()

```
Camera_ErrorCode OH_CaptureSession_GetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace* colorSpace)
```

**Description**

Obtains the active color space.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| colorSpace | Pointer to the active color space, which is defined in [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBias(Camera_CaptureSession* session, float* exposureBias)
```

**Description**

Obtains the exposure compensation value in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureBias | Pointer to the exposure compensation value.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetExposureBiasRange()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange(Camera_CaptureSession* session, float* minExposureBias, float* maxExposureBias, float* step)
```

**Description**

Obtains the exposure compensation values of the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| minExposureBias | Pointer to the minimum exposure compensation value.| 
| maxExposureBias | Pointer to the maximum exposure compensation value.| 
| step | Pointer to the exposure compensation step.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_GetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode* exposureMode)
```

**Description**

Obtains the exposure mode in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureMode | Pointer to the exposure mode, which is defined in the [Camera_ExposureMode](#camera_exposuremode) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetExposureValue()

```
Camera_ErrorCode OH_CaptureSession_GetExposureValue(Camera_CaptureSession* session, float* exposureValue)
```

**Description**

Obtains the exposure value.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureValue | Pointer to the exposure value.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CaptureSession_GetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_GetFlashMode(Camera_CaptureSession* session, Camera_FlashMode* flashMode)
```

**Description**

Obtains the flash mode in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| flashMode | Pointer to the flash mode, which is defined in the [Camera_FlashMode](#camera_flashmode) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetFocalLength()

```
Camera_ErrorCode OH_CaptureSession_GetFocalLength(Camera_CaptureSession* session, float* focalLength)
```

**Description**

Obtains the current focal length.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| focalLength | Pointer to the focal length.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_GetFocusMode(Camera_CaptureSession* session, Camera_FocusMode* focusMode)
```

**Description**

Obtains the focus mode in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureBias | Pointer to the focus mode, which is defined in the [Camera_FocusMode](#camera_focusmode) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_GetFocusPoint(Camera_CaptureSession* session, Camera_Point* focusPoint)
```

**Description**

Obtains the focal point in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| focusPoint | Pointer to the focal point, which is defined in the [Camera_Point](_camera___point.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_GetMeteringPoint(Camera_CaptureSession* session, Camera_Point* point)
```

**Description**

Obtains the metering point in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| point | Pointer to the metering point, which is defined in the [Camera_Point](_camera___point.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetSupportedColorSpaces()

```
Camera_ErrorCode OH_CaptureSession_GetSupportedColorSpaces(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace** colorSpace, uint32_t* size)
```

**Description**

Obtains the supported color spaces.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| colorSpace | Double pointer to the list of color spaces, which are defined in [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1), if the function is successfully called.| 
| size | Pointer to the size of the list of color spaces.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode* mode)
```

**Description**

Obtains the video stabilization mode in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| mode | Pointer to the video stabilization mode, which is defined in the [Camera_VideoStabilizationMode](#camera_videostabilizationmode) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatio(Camera_CaptureSession* session, float* zoom)
```

**Description**

Obtains the zoom ratio in use.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| zoom | Pointer to the zoom ratio.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_GetZoomRatioRange()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange(Camera_CaptureSession* session, float* minZoom, float* maxZoom)
```

**Description**

Obtains the supported zoom ratio range.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| minZoom | Pointer to the minimum zoom ratio.| 
| maxZoom | Pointer to the maximum zoom ratio.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_HasFlash()

```
Camera_ErrorCode OH_CaptureSession_HasFlash(Camera_CaptureSession* session, bool* hasFlash)
```

**Description**

Checks whether the device has flash.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| hasFlash | Pointer to the result that specifies whether the device has flash.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_IsExposureModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported(Camera_CaptureSession* session, Camera_ExposureMode exposureMode, bool* isSupported)
```

**Description**

Checks whether an exposure mode is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureMode | Target exposure mode, which is defined in the [Camera_ExposureMode](#camera_exposuremode) struct.| 
| isSupported | Pointer to the result that specifies whether the exposure mode is supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_IsFlashModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported(Camera_CaptureSession* session, Camera_FlashMode flashMode, bool* isSupported)
```

**Description**

Checks whether a flash mode is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| flashMode | Target flash mode, which is defined in the [Camera_FlashMode](#camera_flashmode) struct.| 
| isSupported | Pointer to the result that specifies whether the flash mode is supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_IsFocusModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported(Camera_CaptureSession* session, Camera_FocusMode focusMode, bool* isSupported)
```

**Description**

Checks whether a focus mode is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| focusMode | Target focus mode, which is defined in the [Camera_FocusMode](#camera_focusmode-1) struct.| 
| isSupported | Pointer to the result that specifies whether the focus mode is supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_IsVideoStabilizationModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode, bool* isSupported)
```

**Description**

Checks whether a video stabilization mode is supported. 

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| mode | Target video stabilization mode, which is defined in the [Camera_VideoStabilizationMode](#camera_videostabilizationmode-1) struct.| 
| isSupported | Pointer to the result that specifies whether the video stabilization mode is supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_Preconfig()

```
Camera_ErrorCode OH_CaptureSession_Preconfig(Camera_CaptureSession* session, Camera_PreconfigType preconfigType)
```

**Description**

Sets a preconfigured resolution type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| preconfigType | Target resolution type, which is defined in [Camera_PreconfigType](#camera_preconfigtype-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CaptureSession_PreconfigWithRatio()

```
Camera_ErrorCode OH_CaptureSession_PreconfigWithRatio(Camera_CaptureSession* session, Camera_PreconfigType preconfigType, Camera_PreconfigRatio preconfigRatio)
```

**Description**

Sets a preconfigured resolution type with an aspect ratio.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| preconfigType | Target resolution type, which is defined in [Camera_PreconfigType](#camera_preconfigtype-1).| 
| preconfigRatio | Target aspect ratio, which is defined in [Camera_PreconfigRatio](#camera_preconfigratio-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CaptureSession_RegisterCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)
```

**Description**

Registers a callback to listen for capture session events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| callback | Pointer to the target callback, which is defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_RegisterSmoothZoomInfoCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**Description**

Registers a callback to listen for smooth zoom events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| smoothZoomInfoCallback | Target callback, which is defined in [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_Release()

```
Camera_ErrorCode OH_CaptureSession_Release(Camera_CaptureSession* session)
```

**Description**

Releases a **CaptureSession** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CaptureSession_RemoveInput()

```
Camera_ErrorCode OH_CaptureSession_RemoveInput(Camera_CaptureSession* session, Camera_Input* cameraInput)
```

**Description**

Removes a **CameraInput** instance from a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_RemoveMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput(Camera_CaptureSession* session, Camera_MetadataOutput* metadataOutput)
```

**Description**

Removes a **MetadataOutput** instance from a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_RemovePhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput(Camera_CaptureSession* session, Camera_PhotoOutput* photoOutput)
```

**Description**

Removes a **PhotoOutput** instance from a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_RemovePreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput(Camera_CaptureSession* session, Camera_PreviewOutput* previewOutput)
```

**Description**

Removes a **PreviewOutput** instance from a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_RemoveVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput(Camera_CaptureSession* session, Camera_VideoOutput* videoOutput)
```

**Description**

Removes a **VideoOutput** instance from a session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.


### OH_CaptureSession_SetActiveColorSpace()

```
Camera_ErrorCode OH_CaptureSession_SetActiveColorSpace(Camera_CaptureSession* session, OH_NativeBuffer_ColorSpace colorSpace)
```

**Description**

Sets the active color space.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| colorSpace | Target color space, which is defined in [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_colorspace-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_SetExposureBias(Camera_CaptureSession* session, float exposureBias)
```

**Description**

Sets an exposure compensation value for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureBias | Target exposure compensation value.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_SetExposureMode(Camera_CaptureSession* session, Camera_ExposureMode exposureMode)
```

**Description**

Sets an exposure mode for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureMode | Target exposure mode, which is defined in [Camera_ExposureMode](#camera_exposuremode-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_SetFlashMode(Camera_CaptureSession* session, Camera_FlashMode flashMode)
```

**Description**

Sets a flash mode for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| flashMode | Target flash mode, which is defined in [Camera_FlashMode](#camera_flashmode-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_SetFocusMode(Camera_CaptureSession* session, Camera_FocusMode focusMode)
```

**Description**

Sets a focus mode for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| focusMode | Target focus mode, which is defined in [Camera_FocusMode](#camera_focusmode-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_SetFocusPoint(Camera_CaptureSession* session, Camera_Point focusPoint)
```

**Description**

Sets a focal point for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| focusPoint | Target focal point, which is defined in the [Camera_Point](_camera___point.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_SetMeteringPoint(Camera_CaptureSession* session, Camera_Point point)
```

**Description**

Sets the metering point, which is the center point of the metering rectangle.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| point | Target metering point, which is defined in the [Camera_Point](_camera___point.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetSessionMode()

```
Camera_ErrorCode OH_CaptureSession_SetSessionMode(Camera_CaptureSession* session, Camera_SceneMode sceneMode)
```

**Description**

Sets a session mode.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| sceneMode | Target scene mode, which is an enumerated value of [CaptureSession_SceneMode](#camera_scenemode-1).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.

- **CAMERA_OPERATION_NOT_ALLOWED**: The operation is not allowed.

- **CAMERA_SESSION_CONFIG_LOCKED**: The session configuration is locked.


### OH_CaptureSession_SetSmoothZoom()

```
Camera_ErrorCode OH_CaptureSession_SetSmoothZoom(Camera_CaptureSession* session, float targetZoom, Camera_SmoothZoomMode smoothZoomMode)
```

**Description**

Sets smooth zoom.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| targetZoom | Target zoom ratio.| 
| smoothZoomMode | [Camera_SmoothZoomMode](#camera_smoothzoommode) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode(Camera_CaptureSession* session, Camera_VideoStabilizationMode mode)
```

**Description**

Sets a video stabilization mode for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| mode | Target video stabilization mode, which is defined in the [Camera_VideoStabilizationMode](#camera_videostabilizationmode) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_SetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_SetZoomRatio(Camera_CaptureSession* session, float zoom)
```

**Description**

Sets a zoom ratio for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| zoom | Target zoom ratio.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.


### OH_CaptureSession_Start()

```
Camera_ErrorCode OH_CaptureSession_Start(Camera_CaptureSession* session)
```

**Description**

Starts a capture session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CaptureSession_Stop()

```
Camera_ErrorCode OH_CaptureSession_Stop(Camera_CaptureSession* session)
```

**Description**

Stops a capture session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_CaptureSession_UnregisterCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterCallback(Camera_CaptureSession* session, CaptureSession_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for capture session events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| callback | Pointer to the target callback, which is defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_CaptureSession_UnregisterSmoothZoomInfoCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterSmoothZoomInfoCallback(Camera_CaptureSession* session, OH_CaptureSession_OnSmoothZoomInfo smoothZoomInfoCallback)
```

**Description**

Unregisters the callback used to listen for smooth zoom events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| smoothZoomInfoCallback | Target callback, which is defined in [OH_CaptureSession_OnSmoothZoomInfo](#oh_capturesession_onsmoothzoominfo).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_MetadataOutput_RegisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_RegisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
```

**Description**

Registers a callback to listen for metadata output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_MetadataOutput_Release()

```
Camera_ErrorCode OH_MetadataOutput_Release(Camera_MetadataOutput* metadataOutput)
```

**Description**

Releases a **MetadataOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_MetadataOutput_Start()

```
Camera_ErrorCode OH_MetadataOutput_Start(Camera_MetadataOutput* metadataOutput)
```

**Description**

Starts metadata output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_MetadataOutput_Stop()

```
Camera_ErrorCode OH_MetadataOutput_Stop(Camera_MetadataOutput* metadataOutput)
```

**Description**

Stops metadata output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_MetadataOutput_UnregisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_UnregisterCallback(Camera_MetadataOutput* metadataOutput, MetadataOutput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for metadata output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoNative_GetMainImage()

```
Camera_ErrorCode OH_PhotoNative_GetMainImage(OH_PhotoNative* photo, OH_ImageNative** mainImage)
```

**Description**

Obtains a full quality photo.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photo | Pointer to an [OH_PhotoNative](#oh_photonative) instance.| 
| mainImage | Double pointer to the full quality photo, which is an [OH_ImageNative](../apis-image-kit/_image___native_module.md#oh_imagenative) object.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoNative_Release()

```
Camera_ErrorCode OH_PhotoNative_Release(OH_PhotoNative* photo)
```

**Description**

Releases a full quality photo.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photo | Pointer to an [OH_PhotoNative](#oh_photonative) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_Capture()

```
Camera_ErrorCode OH_PhotoOutput_Capture(Camera_PhotoOutput* photoOutput)
```

**Description**

Captures a photo.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_RUNNING**: The capture session is not running.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PhotoOutput_Capture_WithCaptureSetting()

```
Camera_ErrorCode OH_PhotoOutput_Capture_WithCaptureSetting(Camera_PhotoOutput* photoOutput, Camera_PhotoCaptureSetting setting)
```

**Description**

Captures a photo with photographing parameters.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| setting | Photographing parameters, which are defined in the [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_RUNNING**: The capture session is not running.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PhotoOutput_DeleteProfile()

```
Camera_ErrorCode OH_PhotoOutput_DeleteProfile(Camera_Profile* profile)
```

**Description**

Deletes the profile of this **PhotoOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| profile | Pointer to a [Camera_Profile](_camera___profile.md) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_EnableMovingPhoto()

```
Camera_ErrorCode OH_PhotoOutput_EnableMovingPhoto(Camera_PhotoOutput* photoOutput, bool enabled)
```

**Description**

Enables moving photos.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to a [Camera_PhotoOutput](#camera_photooutput) instance.| 
| enabled | Whether to enable moving photos.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PhotoOutput_GetActiveProfile()

```
Camera_ErrorCode OH_PhotoOutput_GetActiveProfile(Camera_PhotoOutput* photoOutput, Camera_Profile** profile)
```

**Description**

Obtains the profile of a **PhotoOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to a [Camera_PhotoOutput](#camera_photooutput) instance.| 
| profile | Double pointer to the profile, which is defined in [Camera_Profile](_camera___profile.md), if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PhotoOutput_IsMirrorSupported()

```
Camera_ErrorCode OH_PhotoOutput_IsMirrorSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)
```

**Description**

Checks whether mirroring is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance, which is used to check whether mirroring is supported.| 
| isSupported | Pointer to the result that specifies whether mirroring is supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PhotoOutput_IsMovingPhotoSupported()

```
Camera_ErrorCode OH_PhotoOutput_IsMovingPhotoSupported(Camera_PhotoOutput* photoOutput, bool* isSupported)
```

**Description**

Checks whether moving photos are supported.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to a [Camera_PhotoOutput](#camera_photooutput) instance.| 
| isSupported | Pointer to the result indicating whether moving photos are supported.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PhotoOutput_RegisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)
```

**Description**

Registers a callback to listen for photo output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_RegisterCaptureEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureEnd callback)
```

**Description**

Registers a callback to listen for capture end events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_RegisterCaptureReadyCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureReady callback)
```

**Description**

Registers a callback to listen for camera ready events. When the callback is received, the next capture can be performed.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_RegisterCaptureStartWithInfoCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureStartWithInfo callback)
```

**Description**

Registers a callback to listen for capture start events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_EstimatedCaptureDuration callback)
```

**Description**

Registers a callback to listen for estimated capture duration events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_RegisterFrameShutterEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_OnFrameShutterEnd callback)
```

**Description**

Registers a callback to listen for frame shutter end events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_RegisterPhotoAssetAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAssetAvailable callback)
```

**Description**

Registers a callback to listen for photo asset availability events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_RegisterPhotoAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAvailable callback)
```

**Description**

Registers a callback to listen for photo availability events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_PhotoAvailable](#oh_photooutput_photoavailable).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_Release()

```
Camera_ErrorCode OH_PhotoOutput_Release(Camera_PhotoOutput* photoOutput)
```

**Description**

Releases a **PhotoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PhotoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCallback(Camera_PhotoOutput* photoOutput, PhotoOutput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for photo output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_UnregisterCaptureEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureEnd callback)
```

**Description**

Unregisters the callback used to listen for capture end events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_CaptureEnd](#oh_photooutput_captureend).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_UnregisterCaptureReadyCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureReady callback)
```

**Description**

Unregisters the callback used to listen for camera ready events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_CaptureReady](#oh_photooutput_captureready).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.



### OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCaptureStartWithInfoCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_CaptureStartWithInfo callback)
```

**Description**

Unregisters the callback used to listen for capture start events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_CaptureStartWithInfo](#oh_photooutput_capturestartwithinfo).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterEstimatedCaptureDurationCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_EstimatedCaptureDuration callback)
```

**Description**

Unregisters the callback used to listen for estimated capture duration events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_EstimatedCaptureDuration](#oh_photooutput_estimatedcaptureduration).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_UnregisterFrameShutterEndCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterFrameShutterEndCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_OnFrameShutterEnd callback)
```

**Description**

Unregisters the callback used to listen for frame shutter end events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_OnFrameShutterEnd](#oh_photooutput_onframeshutterend).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAssetAvailable callback)
```

**Description**

Unregisters the callback used to listen for photo asset availability events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [OH_PhotoOutput_PhotoAssetAvailable](#oh_photooutput_photoassetavailable).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PhotoOutput_UnregisterPhotoAvailableCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput, OH_PhotoOutput_PhotoAvailable callback)
```

**Description**

Unregisters the callback used to listen for photo availability events.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| callback | Target callback, which is defined in [PhotoOutput_Callbacks](_photo_output___callbacks.md).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PreviewOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_DeleteFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)
```

**Description**

Deletes the frame rate list.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| frameRateRange | Pointer to the list of frame rates, which are defined in [Camera_FrameRateRange](_camera___frame_rate_range.md).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PreviewOutput_DeleteProfile()

```
Camera_ErrorCode OH_PreviewOutput_DeleteProfile(Camera_Profile* profile)
```

**Description**

Deletes the profile of this **PreviewOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| profile | Pointer to a [Camera_Profile](_camera___profile.md) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PreviewOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveFrameRate(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange* frameRateRange)
```

**Description**

Obtains the active frame rates of a **PreviewOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to a [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| frameRateRange | Double pointer to the frame rates, which are defined in [Camera_FrameRateRange](_camera___frame_rate_range.md), if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PreviewOutput_GetActiveProfile()

```
Camera_ErrorCode OH_PreviewOutput_GetActiveProfile(Camera_PreviewOutput* previewOutput, Camera_Profile** profile)
```

**Description**

Obtains the profile of a **PreviewOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to a [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| profile | Double pointer to the profile, which is defined in [Camera_Profile](_camera___profile.md), if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PreviewOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_PreviewOutput_GetSupportedFrameRates(Camera_PreviewOutput* previewOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**Description**

Obtains the list of frame rates supported by a **PreviewOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| frameRateRange | Double pointer to the list of frame rates, which are defined in [Camera_FrameRateRange](_camera___frame_rate_range.md), if the function is successfully called.| 
| size | Pointer to the size of the list of frame rates.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PreviewOutput_RegisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_RegisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)
```

**Description**

Registers a callback to listen for preview output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PreviewOutput_Release()

```
Camera_ErrorCode OH_PreviewOutput_Release(Camera_PreviewOutput* previewOutput)
```

**Description**

Releases a **PreviewOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PreviewOutput_SetFrameRate()

```
Camera_ErrorCode OH_PreviewOutput_SetFrameRate(Camera_PreviewOutput* previewOutput, int32_t minFps, int32_t maxFps)
```

**Description**

Sets the frame rates for a **PreviewOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| minFps | Minimum frame rate.| 
| maxFps | Maximum frame rate.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_PreviewOutput_Start()

```
Camera_ErrorCode OH_PreviewOutput_Start(Camera_PreviewOutput* previewOutput)
```

**Description**

Starts preview output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PreviewOutput_Stop()

```
Camera_ErrorCode OH_PreviewOutput_Stop(Camera_PreviewOutput* previewOutput)
```

**Description**

Stops preview output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_PreviewOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_UnregisterCallback(Camera_PreviewOutput* previewOutput, PreviewOutput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for preview output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_VideoOutput_DeleteFrameRates()

```
Camera_ErrorCode OH_VideoOutput_DeleteFrameRates(Camera_VideoOutput* videoOutput, Camera_FrameRateRange* frameRateRange)
```

**Description**

Deletes the frame rate list.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 
| frameRateRange | Pointer to the list of frame rates, which are defined in [Camera_FrameRateRange](_camera___frame_rate_range.md).| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_VideoOutput_DeleteProfile()

```
Camera_ErrorCode OH_VideoOutput_DeleteProfile(Camera_VideoProfile* profile)
```

**Description**

Deletes the profile of this **VideoOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| profile | Pointer to the [Camera_VideoProfile](_camera___video_profile.md) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_VideoOutput_GetActiveFrameRate()

```
Camera_ErrorCode OH_VideoOutput_GetActiveFrameRate(Camera_VideoOutput* videoOutput, Camera_FrameRateRange* frameRateRange)
```

**Description**

Obtains the active frame rates of a **VideoOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance.| 
| frameRateRange | Pointer to the frame rates, which are defined in [Camera_FrameRateRange](_camera___frame_rate_range.md), if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_VideoOutput_GetActiveProfile()

```
Camera_ErrorCode OH_VideoOutput_GetActiveProfile(Camera_VideoOutput* videoOutput, Camera_VideoProfile** profile)
```

**Description**

Obtains the profile of a **VideoOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance.| 
| profile | Double pointer to the profile, which is defined in [Camera_VideoProfile](_camera___video_profile.md), if the function is successfully called.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_VideoOutput_GetSupportedFrameRates()

```
Camera_ErrorCode OH_VideoOutput_GetSupportedFrameRates(Camera_VideoOutput* videoOutput, Camera_FrameRateRange** frameRateRange, uint32_t* size)
```

**Description**

Obtains the list of frame rates supported by a **VideoOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance.| 
| frameRateRange | Double pointer to the list of frame rates, which are defined in [Camera_FrameRateRange](_camera___frame_rate_range.md), if the function is successfully called.| 
| size | Pointer to the size of the list of frame rates.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_VideoOutput_RegisterCallback()

```
Camera_ErrorCode OH_VideoOutput_RegisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**Description**

Registers a callback to listen for video output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_VideoOutput_Release()

```
Camera_ErrorCode OH_VideoOutput_Release(Camera_VideoOutput* videoOutput)
```

**Description**

Releases a **VideoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_VideoOutput_SetFrameRate()

```
Camera_ErrorCode OH_VideoOutput_SetFrameRate(Camera_VideoOutput* videoOutput, int32_t minFps, int32_t maxFps)
```

**Description**

Sets the frame rates for a **VideoOutput** instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 
| minFps      | Minimum frame rate.                               |
| maxFps      | Maximum frame rate.                               |

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.


### OH_VideoOutput_Start()

```
Camera_ErrorCode OH_VideoOutput_Start(Camera_VideoOutput* videoOutput)
```

**Description**

Starts video output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SESSION_NOT_CONFIG**: The capture session is not configured.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_VideoOutput_Stop()

```
Camera_ErrorCode OH_VideoOutput_Stop(Camera_VideoOutput* videoOutput)
```

**Description**

Stops video output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.

- **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.


### OH_VideoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_VideoOutput_UnregisterCallback(Camera_VideoOutput* videoOutput, VideoOutput_Callbacks* callback)
```

**Description**

Unregisters the callback used to listen for video output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct.| 

**Returns**

In [Camera_ErrorCode] (#camera_errorcode-1):

- **CAMERA_OK**: The operation is successful.

- **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.
