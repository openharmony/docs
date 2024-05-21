# OH_Camera


## Overview

The **OH_Camera** module provides C APIs for the camera service.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [camera.h](camera_8h.md) | Declares the basic concepts of the camera.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/camera.h&gt; | 
| [camera_input.h](camera__input_8h.md) | Declares the camera input concepts.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/camera_input.h&gt;| 
| [camera_manager.h](camera__manager_8h.md) | Declares the camera manager concepts.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/camera_manager.h&gt; |
| [capture_session.h](capture__session_8h.md) | Declares the session capture concepts.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/capture_session.h&gt; |
| [metadata_output.h](metadata__output_8h.md) | Declares the metadata output concepts.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/metadata_output.h&gt; | 
| [photo_output.h](photo__output_8h.md) | Declares the photo output concepts.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/photo_output.h&gt; | 
| [preview_output.h](preview__output_8h.md) | Declares the preview output concepts.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/preview_output.h&gt; | 
| [video_output.h](video__output_8h.md) | Declares the video output concepts.<br>**Library**: libohcamera.so<br>**File to include**: &lt;ohcamera/video_output.h&gt; | 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[Camera_Size](_camera___size.md) | Defines the parameters that describe the size.| 
| struct&nbsp;&nbsp;[Camera_Profile](_camera___profile.md) | Defines the profile of the camera stream.| 
| struct&nbsp;&nbsp;[Camera_FrameRateRange](_camera___frame_rate_range.md) | Defines the frame rate range.| 
| struct&nbsp;&nbsp;[Camera_VideoProfile](_camera___video_profile.md) | Defines the video profile.| 
| struct&nbsp;&nbsp;[Camera_OutputCapability](_camera___output_capability.md) | Defines the camera output capability.| 
| struct&nbsp;&nbsp;[Camera_Device](_camera___device.md) | Defines the camera device.| 
| struct&nbsp;&nbsp;[Camera_StatusInfo](_camera___status_info.md) | Defines the camera status information.| 
| struct&nbsp;&nbsp;[Camera_Point](_camera___point.md) | Defines the parameters that describe a point.| 
| struct&nbsp;&nbsp;[Camera_Location](_camera___location.md) | Defines the location where the photo is taken.| 
| struct&nbsp;&nbsp;[Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) | Defines the photographing parameters.| 
| struct&nbsp;&nbsp;[Camera_FrameShutterInfo](_camera___frame_shutter_info.md) | Defines the frame shutter callback.| 
| struct&nbsp;&nbsp;[Camera_CaptureEndInfo](_camera___capture_end_info.md) | Defines the capture end information.| 
| struct&nbsp;&nbsp;[Camera_Rect](_camera___rect.md) | Defines the rectangle.| 
| struct&nbsp;&nbsp;[Camera_MetadataObject](_camera___metadata_object.md) | Defines the camera metadata.| 
| struct&nbsp;&nbsp;[CameraInput_Callbacks](_camera_input___callbacks.md) | Defines the callbacks used to listen for camera input errors.| 
| struct&nbsp;&nbsp;[CameraManager_Callbacks](_camera_manager___callbacks.md) | Defines the callbacks used to listen for camera status changes.| 
| struct&nbsp;&nbsp;[CaptureSession_Callbacks](_capture_session___callbacks.md) | Defines the callbacks used for session capture.| 
| struct&nbsp;&nbsp;[MetadataOutput_Callbacks](_metadata_output___callbacks.md) | Defines the callback functions of metadata output.| 
| struct&nbsp;&nbsp;[PhotoOutput_Callbacks](_photo_output___callbacks.md) | Defines the callbacks used for photo output.| 
| struct&nbsp;&nbsp;[PreviewOutput_Callbacks](_preview_output___callbacks.md) | Defines the callbacks used for preview output.| 
| struct&nbsp;&nbsp;[VideoOutput_Callbacks](_video_output___callbacks.md) | Defines the callbacks used for video output.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Camera_Manager](#camera_manager) [Camera_Manager](#camera_manager) | Defines the camera manager.| 
| typedef enum [Camera_ErrorCode](#camera_errorcode) [Camera_ErrorCode](#camera_errorcode) | Defines an enum for camera error codes.| 
| typedef enum [Camera_Status](#camera_status) [Camera_Status](#camera_status) | Defines an enum for camera statuses.| 
| typedef enum [Camera_Position](#camera_position) [Camera_Position](#camera_position) | Defines an enum for camera positions.| 
| typedef enum [Camera_Type](#camera_type) [Camera_Type](#camera_type) | Defines an enum for camera types.| 
| typedef enum [Camera_Connection](#camera_connection) [Camera_Connection](#camera_connection) | Defines an enum for camera connection types.| 
| typedef enum [Camera_Format](#camera_format) [Camera_Format](#camera_format) | Defines an enum for camera output formats.| 
| typedef enum [Camera_FlashMode](#camera_flashmode) [Camera_FlashMode](#camera_flashmode) | Defines an enum for flash modes.| 
| typedef enum [Camera_ExposureMode](#camera_exposuremode) [Camera_ExposureMode](#camera_exposuremode) | Defines an enum for exposure modes.| 
| typedef enum [Camera_FocusMode](#camera_focusmode) [Camera_FocusMode](#camera_focusmode) | Defines an enum for focus modes.| 
| typedef enum [Camera_FocusState](#camera_focusstate) [Camera_FocusState](#camera_focusstate) | Defines an enum for focus states.| 
| typedef enum [Camera_VideoStabilizationMode](#camera_videostabilizationmode) [Camera_VideoStabilizationMode](#camera_videostabilizationmode) | Defines an enum for video stabilization modes.| 
| typedef enum [Camera_ImageRotation](#camera_imagerotation) [Camera_ImageRotation](#camera_imagerotation) | Defines an enum for image rotation angles.| 
| typedef enum [Camera_QualityLevel](#camera_qualitylevel) [Camera_QualityLevel](#camera_qualitylevel) | Defines an enum for image quality levels.| 
| typedef enum [Camera_MetadataObjectType](#camera_metadataobjecttype) [Camera_MetadataObjectType](#camera_metadataobjecttype) | Defines an enum for metadata object types.| 
| typedef struct [Camera_Size](_camera___size.md) [Camera_Size](#camera_size) | Defines the parameters that describe the size.| 
| typedef struct [Camera_Profile](_camera___profile.md) [Camera_Profile](#camera_profile) | Defines the profile of the camera stream.| 
| typedef struct [Camera_FrameRateRange](_camera___frame_rate_range.md) [Camera_FrameRateRange](#camera_frameraterange) | Defines the frame rate range.| 
| typedef struct [Camera_VideoProfile](_camera___video_profile.md) [Camera_VideoProfile](#camera_videoprofile) | Defines the video profile.| 
| typedef struct [Camera_OutputCapability](_camera___output_capability.md) [Camera_OutputCapability](#camera_outputcapability) | Defines the camera output capability.| 
| typedef struct [Camera_Device](_camera___device.md) [Camera_Device](#camera_device) | Defines the camera device.| 
| typedef struct [Camera_StatusInfo](_camera___status_info.md) [Camera_StatusInfo](#camera_statusinfo) | Defines the camera status information.| 
| typedef struct [Camera_Point](_camera___point.md) [Camera_Point](#camera_point) | Defines the parameters that describe a point.| 
| typedef struct [Camera_Location](_camera___location.md) [Camera_Location](#camera_location) | Defines the location where the photo is taken.| 
| typedef struct [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) [Camera_PhotoCaptureSetting](#camera_photocapturesetting) | Defines the photographing parameters.| 
| typedef struct [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) [Camera_FrameShutterInfo](#camera_frameshutterinfo) | Defines the frame shutter callback.| 
| typedef struct [Camera_CaptureEndInfo](_camera___capture_end_info.md) [Camera_CaptureEndInfo](#camera_captureendinfo) | Defines the capture end information.| 
| typedef struct [Camera_Rect](_camera___rect.md) [Camera_Rect](#camera_rect) | Defines the rectangle.| 
| typedef struct [Camera_MetadataObject](_camera___metadata_object.md) [Camera_MetadataObject](#camera_metadataobject) | Defines the camera metadata.| 
| typedef struct [Camera_Input](#camera_input) [Camera_Input](#camera_input) | Defines the camera input object.| 
| typedef void(\* [OH_CameraInput_OnError](#oh_camerainput_onerror)) (const [Camera_Input](#camera_input) \*cameraInput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct and used to report camera input errors.| 
| typedef struct [CameraInput_Callbacks](_camera_input___callbacks.md) [CameraInput_Callbacks](#camerainput_callbacks) | Defines the callbacks used to listen for camera input errors.| 
| typedef void(\* [OH_CameraManager_StatusCallback](#oh_cameramanager_statuscallback)) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_StatusInfo](_camera___status_info.md) \*status) | Defines the pointer to the callback defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct and used to report the camera manager status.| 
| typedef struct [CameraManager_Callbacks](_camera_manager___callbacks.md) [CameraManager_Callbacks](#cameramanager_callbacks) | Defines the callbacks used to listen for camera status changes.| 
| typedef struct [Camera_CaptureSession](#camera_capturesession) [Camera_CaptureSession](#camera_capturesession) | Defines the session capture object.| 
| typedef void(\* [OH_CaptureSession_OnFocusStateChange](#oh_capturesession_onfocusstatechange)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_FocusState](#camera_focusstate) focusState) | Defines the pointer to the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report session capture focus status changes.| 
| typedef void(\* [OH_CaptureSession_OnError](#oh_capturesession_onerror)) ([Camera_CaptureSession](#camera_capturesession) \*session, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report capture session errors.| 
| typedef struct [CaptureSession_Callbacks](_capture_session___callbacks.md) [CaptureSession_Callbacks](#capturesession_callbacks) | Defines the callbacks used for session capture.| 
| typedef struct [Camera_MetadataOutput](#camera_metadataoutput) [Camera_MetadataOutput](#camera_metadataoutput) | Defines the metadata output object.| 
| typedef void(\* [OH_MetadataOutput_OnMetadataObjectAvailable](#oh_metadataoutput_onmetadataobjectavailable)) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [Camera_MetadataObject](_camera___metadata_object.md) \*metadataObject, uint32_t size) | Defines the pointer to the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output data.| 
| typedef void(\* [OH_MetadataOutput_OnError](#oh_metadataoutput_onerror)) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output errors.| 
| typedef struct [MetadataOutput_Callbacks](_metadata_output___callbacks.md) [MetadataOutput_Callbacks](#metadataoutput_callbacks) | Defines the callback functions of metadata output.| 
| typedef struct [Camera_PhotoOutput](#camera_photooutput) [Camera_PhotoOutput](#camera_photooutput) | Defines the photo output object.| 
| typedef void(\* [OH_PhotoOutput_OnFrameStart](#oh_photooutput_onframestart)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame start events.| 
| typedef void(\* [OH_PhotoOutput_OnFrameShutter](#oh_photooutput_onframeshutter)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) \*info) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report frame shutter events.| 
| typedef void(\* [OH_PhotoOutput_OnFrameEnd](#oh_photooutput_onframeend)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, int32_t frameCount) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame end events.| 
| typedef void(\* [OH_PhotoOutput_OnError](#oh_photooutput_onerror)) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output errors.| 
| typedef struct [PhotoOutput_Callbacks](_photo_output___callbacks.md) [PhotoOutput_Callbacks](#photooutput_callbacks) | Defines the callbacks used for photo output.| 
| typedef struct [Camera_PreviewOutput](#camera_previewoutput) [Camera_PreviewOutput](#camera_previewoutput) | Defines the preview output object.| 
| typedef void(\* [OH_PreviewOutput_OnFrameStart](#oh_previewoutput_onframestart)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame start events.| 
| typedef void(\* [OH_PreviewOutput_OnFrameEnd](#oh_previewoutput_onframeend)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, int32_t frameCount) | Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame end events.| 
| typedef void(\* [OH_PreviewOutput_OnError](#oh_previewoutput_onerror)) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output errors.| 
| typedef struct [PreviewOutput_Callbacks](_preview_output___callbacks.md) [PreviewOutput_Callbacks](#previewoutput_callbacks) | Defines the callbacks used for preview output.| 
| typedef struct [Camera_VideoOutput](#camera_videooutput) [Camera_VideoOutput](#camera_videooutput) | Defines the video output object.| 
| typedef void(\* [OH_VideoOutput_OnFrameStart](#oh_videooutput_onframestart)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame start events.| 
| typedef void(\* [OH_VideoOutput_OnFrameEnd](#oh_videooutput_onframeend)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, int32_t frameCount) | Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame end events.| 
| typedef void(\* [OH_VideoOutput_OnError](#oh_videooutput_onerror)) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [Camera_ErrorCode](#camera_errorcode) errorCode) | Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output errors.| 
| typedef struct [VideoOutput_Callbacks](_video_output___callbacks.md) [VideoOutput_Callbacks](#videooutput_callbacks) | Defines the callbacks used for video output.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](#camera_errorcode) {<br>CAMERA_OK = 0,<br>CAMERA_INVALID_ARGUMENT = 7400101,<br>CAMERA_OPERATION_NOT_ALLOWED = 7400102,<br>CAMERA_SESSION_NOT_CONFIG = 7400103,<br>CAMERA_SESSION_NOT_RUNNING = 7400104,<br>CAMERA_SESSION_CONFIG_LOCKED = 7400105,<br>CAMERA_DEVICE_SETTING_LOCKED = 7400106,<br>CAMERA_CONFLICT_CAMERA = 7400107,<br>CAMERA_DEVICE_DISABLED = 7400108,<br>CAMERA_DEVICE_PREEMPTED = 7400109,<br>CAMERA_SERVICE_FATAL_ERROR = 7400201<br>} | Enumerates the camera error codes.| 
| [Camera_Status](#camera_status) {<br>CAMERA_STATUS_APPEAR = 0,<br>CAMERA_STATUS_DISAPPEAR = 1,<br>CAMERA_STATUS_AVAILABLE = 2,<br>CAMERA_STATUS_UNAVAILABLE = 3<br>} | Enumerates the camera statuses.| 
| [Camera_Position](#camera_position) {<br>CAMERA_POSITION_UNSPECIFIED = 0,<br>CAMERA_POSITION_BACK = 1,<br>CAMERA_POSITION_FRONT = 2<br>} | Enumerates the camera positions.| 
| [Camera_Type](#camera_type) {<br>CAMERA_TYPE_DEFAULT = 0,<br>CAMERA_TYPE_WIDE_ANGLE = 1,<br>CAMERA_TYPE_ULTRA_WIDE = 2,<br>CAMERA_TYPE_TELEPHOTO = 3,<br>CAMERA_TYPE_TRUE_DEPTH = 4<br>} | Enumerates the camera types.| 
| [Camera_Connection](#camera_connection) {<br>CAMERA_CONNECTION_BUILT_IN = 0,<br>CAMERA_CONNECTION_USB_PLUGIN = 1,<br>CAMERA_CONNECTION_REMOTE = 2<br>} | Enumerates the camera connection types.| 
| [Camera_Format](#camera_format) {<br>CAMERA_FORMAT_RGBA_8888 = 3,<br>CAMERA_FORMAT_YUV_420_SP = 1003,<br>CAMERA_FORMAT_JPEG = 2000<br>} | Enumerates the camera output formats.| 
| [Camera_FlashMode](#camera_flashmode) {<br>FLASH_MODE_CLOSE = 0,<br>FLASH_MODE_OPEN = 1,<br>FLASH_MODE_AUTO = 2,<br>FLASH_MODE_ALWAYS_OPEN = 3<br>} | Enumerates the flash modes.| 
| [Camera_ExposureMode](#camera_exposuremode) {<br>EXPOSURE_MODE_LOCKED = 0,<br>EXPOSURE_MODE_AUTO = 1,<br>EXPOSURE_MODE_CONTINUOUS_AUTO = 2<br>} | Enumerates the exposure modes.| 
| [Camera_FocusMode](#camera_focusmode) {<br>FOCUS_MODE_MANUAL = 0,<br>FOCUS_MODE_CONTINUOUS_AUTO = 1,<br>FOCUS_MODE_AUTO = 2,<br>FOCUS_MODE_LOCKED = 3<br>} | Enumerates the focus modes.| 
| [Camera_FocusState](#camera_focusstate) {<br>FOCUS_STATE_SCAN = 0,<br>FOCUS_STATE_FOCUSED = 1,<br>FOCUS_STATE_UNFOCUSED = 2<br>} | Enumerates the focus states.| 
| [Camera_VideoStabilizationMode](#camera_videostabilizationmode) {<br>STABILIZATION_MODE_OFF = 0,<br>STABILIZATION_MODE_LOW = 1,<br>STABILIZATION_MODE_MIDDLE = 2,<br>STABILIZATION_MODE_HIGH = 3,<br>STABILIZATION_MODE_AUTO = 4<br>} | Enumerates the video stabilization modes.| 
| [Camera_ImageRotation](#camera_imagerotation) {<br>IAMGE_ROTATION_0 = 0,<br>IAMGE_ROTATION_90 = 90,<br>IAMGE_ROTATION_180 = 180,<br>IAMGE_ROTATION_270 = 270<br>} | Enumerates the image rotation angles.| 
| [Camera_QualityLevel](#camera_qualitylevel) {<br>QUALITY_LEVEL_HIGH = 0,<br>QUALITY_LEVEL_MEDIUM = 1,<br>QUALITY_LEVEL_LOW = 2<br>} | Enumerates the image quality levels.| 
| [Camera_MetadataObjectType](#camera_metadataobjecttype) {<br>FACE_DETECTION = 0<br>} | Enumerates the metadata object types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Camera_ErrorCode](#camera_errorcode) [OH_Camera_GetCameraManager](#oh_camera_getcameramanager) ([Camera_Manager](#camera_manager) \*\*cameraManager) | Obtains a **CameraManager** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_Camera_DeleteCameraManager](#oh_camera_deletecameramanager) ([Camera_Manager](#camera_manager) \*cameraManager) | Deletes a **CameraManager** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_RegisterCallback](#oh_camerainput_registercallback) ([Camera_Input](#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Registers a callback to listen for camera input changes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_UnregisterCallback](#oh_camerainput_unregistercallback) ([Camera_Input](#camera_input) \*cameraInput, [CameraInput_Callbacks](_camera_input___callbacks.md) \*callback) | Unregisters the callback used to listen for camera input events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Open](#oh_camerainput_open) ([Camera_Input](#camera_input) \*cameraInput) | Opens a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Close](#oh_camerainput_close) ([Camera_Input](#camera_input) \*cameraInput) | Closes a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraInput_Release](#oh_camerainput_release) ([Camera_Input](#camera_input) \*cameraInput) | Releases a **CameraInput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_RegisterCallback](#oh_cameramanager_registercallback) ([Camera_Manager](#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Registers a callback to listen for camera status changes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_UnregisterCallback](#oh_cameramanager_unregistercallback) ([Camera_Manager](#camera_manager) \*cameraManager, [CameraManager_Callbacks](_camera_manager___callbacks.md) \*callback) | Unregisters the callback used to listen for camera status changes.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameras](#oh_cameramanager_getsupportedcameras) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*\*cameras, uint32_t \*size) | Obtains supported cameras.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSupportedCameras](#oh_cameramanager_deletesupportedcameras) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Device](_camera___device.md) \*cameras, uint32_t size) | Deletes supported cameras.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_GetSupportedCameraOutputCapability](#oh_cameramanager_getsupportedcameraoutputcapability) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_OutputCapability](_camera___output_capability.md) \*\*cameraOutputCapability) | Obtains the output capability supported by a camera in the specified mode.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_DeleteSupportedCameraOutputCapability](#oh_cameramanager_deletesupportedcameraoutputcapability) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_OutputCapability](_camera___output_capability.md) \*cameraOutputCapability) | Deletes the output capability supported by a camera.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_IsCameraMuted](#oh_cameramanager_iscameramuted) ([Camera_Manager](#camera_manager) \*cameraManager, bool \*isCameraMuted) | Checks whether a camera is muted.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCaptureSession](#oh_cameramanager_createcapturesession) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_CaptureSession](#camera_capturesession) \*\*captureSession) | Creates a **CaptureSession** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCameraInput](#oh_cameramanager_createcamerainput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Device](_camera___device.md) \*camera, [Camera_Input](#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateCameraInput_WithPositionAndType](#oh_cameramanager_createcamerainput_withpositionandtype) ([Camera_Manager](#camera_manager) \*cameraManager, [Camera_Position](#camera_position) position, [Camera_Type](#camera_type) type, [Camera_Input](#camera_input) \*\*cameraInput) | Creates a **CameraInput** instance with the specified location and type.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePreviewOutput](#oh_cameramanager_createpreviewoutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PreviewOutput](#camera_previewoutput) \*\*previewOutput) | Creates a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreatePhotoOutput](#oh_cameramanager_createphotooutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_Profile](_camera___profile.md) \*profile, const char \*surfaceId, [Camera_PhotoOutput](#camera_photooutput) \*\*photoOutput) | Creates a **PhotoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateVideoOutput](#oh_cameramanager_createvideooutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_VideoProfile](_camera___video_profile.md) \*profile, const char \*surfaceId, [Camera_VideoOutput](#camera_videooutput) \*\*videoOutput) | Creates a **VideoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CameraManager_CreateMetadataOutput](#oh_cameramanager_createmetadataoutput) ([Camera_Manager](#camera_manager) \*cameraManager, const [Camera_MetadataObjectType](#camera_metadataobjecttype) \*profile, [Camera_MetadataOutput](#camera_metadataoutput) \*\*metadataOutput) | Creates a **MetadataOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_RegisterCallback](#oh_capturesession_registercallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | Registers a callback to listen for session capture events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_UnregisterCallback](#oh_capturesession_unregistercallback) ([Camera_CaptureSession](#camera_capturesession) \*session, [CaptureSession_Callbacks](_capture_session___callbacks.md) \*callback) | Unregisters the callback used to listen for session capture events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_BeginConfig](#oh_capturesession_beginconfig) ([Camera_CaptureSession](#camera_capturesession) \*session) | Starts the configuration for session capture.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_CommitConfig](#oh_capturesession_commitconfig) ([Camera_CaptureSession](#camera_capturesession) \*session) | Commits the configuration for session capture.| 
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
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Start](#oh_capturesession_start) ([Camera_CaptureSession](#camera_capturesession) \*session) | Starts session capture.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_CaptureSession_Stop](#oh_capturesession_stop) ([Camera_CaptureSession](#camera_capturesession) \*session) | Stops session capture.| 
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
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_RegisterCallback](#oh_metadataoutput_registercallback) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | Registers a callback to listen for metadata output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_UnregisterCallback](#oh_metadataoutput_unregistercallback) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput, [MetadataOutput_Callbacks](_metadata_output___callbacks.md) \*callback) | Unregisters the callback used to listen for metadata output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Start](#oh_metadataoutput_start) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Starts metadata output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Stop](#oh_metadataoutput_stop) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Stops metadata output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_MetadataOutput_Release](#oh_metadataoutput_release) ([Camera_MetadataOutput](#camera_metadataoutput) \*metadataOutput) | Releases a **MetadataOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_RegisterCallback](#oh_photooutput_registercallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Registers a callback to listen for photo output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_UnregisterCallback](#oh_photooutput_unregistercallback) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [PhotoOutput_Callbacks](_photo_output___callbacks.md) \*callback) | Unregisters the callback used to listen for photo output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Capture](#oh_photooutput_capture) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Captures a photo.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Capture_WithCaptureSetting](#oh_photooutput_capture_withcapturesetting) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) setting) | Captures a photo with the photographing parameters.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_Release](#oh_photooutput_release) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput) | Releases a **PhotoOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PhotoOutput_IsMirrorSupported](#oh_photooutput_ismirrorsupported) ([Camera_PhotoOutput](#camera_photooutput) \*photoOutput, bool \*isSupported) | Checks whether mirroring is supported.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_RegisterCallback](#oh_previewoutput_registercallback) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Registers a callback to listen for preview output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_UnregisterCallback](#oh_previewoutput_unregistercallback) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput, [PreviewOutput_Callbacks](_preview_output___callbacks.md) \*callback) | Unregisters the callback used to listen for preview output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Start](#oh_previewoutput_start) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Starts preview output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Stop](#oh_previewoutput_stop) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Stops preview output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_PreviewOutput_Release](#oh_previewoutput_release) ([Camera_PreviewOutput](#camera_previewoutput) \*previewOutput) | Releases a **PreviewOutput** instance.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_RegisterCallback](#oh_videooutput_registercallback) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Registers a callback to listen for video output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_UnregisterCallback](#oh_videooutput_unregistercallback) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput, [VideoOutput_Callbacks](_video_output___callbacks.md) \*callback) | Unregisters the callback used to listen for video output events.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Start](#oh_videooutput_start) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Starts video output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Stop](#oh_videooutput_stop) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Stops video output.| 
| [Camera_ErrorCode](#camera_errorcode) [OH_VideoOutput_Release](#oh_videooutput_release) ([Camera_VideoOutput](#camera_videooutput) \*videoOutput) | Releases a **VideoOutput** instance.| 


## Type Description


### Camera_CaptureEndInfo

```
typedef struct Camera_CaptureEndInfo Camera_CaptureEndInfo
```

**Description**

Defines the capture end information.

**Since**: 11


### Camera_CaptureSession

```
typedef struct Camera_CaptureSession Camera_CaptureSession
```

**Description**

Defines the session capture object.

You can call [OH_CameraManager_CreateCaptureSession](#oh_cameramanager_createcapturesession) to create such an object.

**Since**: 11


### Camera_Connection

```
typedef enum Camera_Connection Camera_Connection
```

**Description**

Defines an enum for camera connection types.

**Since**: 11


### Camera_Device

```
typedef struct Camera_Device Camera_Device
```

**Description**

Defines the camera device.

**Since**: 11


### Camera_ErrorCode

```
typedef enum Camera_ErrorCode Camera_ErrorCode
```

**Description**

Defines an enum for camera error codes.

**Since**: 11


### Camera_ExposureMode

```
typedef enum Camera_ExposureMode Camera_ExposureMode
```

**Description**

Defines an enum for exposure modes.

**Since**: 11


### Camera_FlashMode

```
typedef enum Camera_FlashMode Camera_FlashMode
```

**Description**

Defines an enum forflash modes.

**Since**: 11


### Camera_FocusMode

```
typedef enum Camera_FocusMode Camera_FocusMode
```

**Description**

Defines an enum for focus modes.

**Since**: 11


### Camera_FocusState

```
typedef enum Camera_FocusState Camera_FocusState
```

**Description**

Defines an enum for focus states.

**Since**: 11


### Camera_Format

```
typedef enum Camera_Format Camera_Format
```

**Description**

Defines an enum for camera output formats.

**Since**: 11


### Camera_FrameRateRange

```
typedef struct Camera_FrameRateRange Camera_FrameRateRange
```

**Description**

Defines the frame rate range.

**Since**: 11


### Camera_FrameShutterInfo

```
typedef struct Camera_FrameShutterInfo Camera_FrameShutterInfo
```

**Description**

Defines the frame shutter callback.

**Since**: 11


### Camera_ImageRotation

```
typedef enum Camera_ImageRotation Camera_ImageRotation
```

**Description**

Defines an enum for image rotation angles.

**Since**: 11


### Camera_Input

```
typedef struct Camera_Input Camera_Input
```

**Description**

Defines the camera input object.

You can call [OH_CameraManager_CreateCameraInput](#oh_cameramanager_createcamerainput) to create such an object.

**Since**: 11


### Camera_Location

```
typedef struct Camera_Location Camera_Location
```

**Description**

Defines the location where the photo is taken.

**Since**: 11


### Camera_Manager

```
typedef struct Camera_Manager Camera_Manager
```

**Description**

Defines the camera manager.

You can call [OH_Camera_GetCameraManager](#oh_camera_getcameramanager) to create such an object.

**Since**: 11


### Camera_MetadataObject

```
typedef struct Camera_MetadataObject Camera_MetadataObject
```

**Description**

Defines the camera metadata.

**Since**: 11


### Camera_MetadataObjectType

```
typedef enum Camera_MetadataObjectType Camera_MetadataObjectType
```

**Description**

Defines an enum for metadata object types.

**Since**: 11


### Camera_MetadataOutput

```
typedef struct Camera_MetadataOutput Camera_MetadataOutput
```

**Description**

Defines the metadata output object.

You can call [OH_CameraManager_CreateMetadataOutput](#oh_cameramanager_createmetadataoutput) to create such an object.

**Since**: 11


### Camera_OutputCapability

```
typedef struct Camera_OutputCapability Camera_OutputCapability
```

**Description**

Defines the camera output capability.

**Since**: 11


### Camera_PhotoCaptureSetting

```
typedef struct Camera_PhotoCaptureSetting Camera_PhotoCaptureSetting
```

**Description**

Defines the photographing parameters.

**Since**: 11


### Camera_PhotoOutput

```
typedef struct Camera_PhotoOutput Camera_PhotoOutput
```

**Description**

Defines the photo output object.

You can call [OH_CameraManager_CreatePhotoOutput](#oh_cameramanager_createphotooutput) to create such an object.

**Since**: 11


### Camera_Point

```
typedef struct Camera_Point Camera_Point
```

**Description**

Defines the parameters that describe a point.

**Since**: 11


### Camera_Position

```
typedef enum Camera_Position Camera_Position
```

**Description**

Defines an enum for camera positions.

**Since**: 11


### Camera_PreviewOutput

```
typedef struct Camera_PreviewOutput Camera_PreviewOutput
```

**Description**

Defines the preview output object.

You can call [OH_CameraManager_CreatePreviewOutput](#oh_cameramanager_createpreviewoutput) to create such an object.

**Since**: 11


### Camera_Profile

```
typedef struct Camera_Profile Camera_Profile
```

**Description**

Defines the profile of the camera stream.

**Since**: 11


### Camera_QualityLevel

```
typedef enum Camera_QualityLevel Camera_QualityLevel
```

**Description**

Defines an enum for image quality levels.

**Since**: 11


### Camera_Rect

```
typedef struct Camera_Rect Camera_Rect
```

**Description**

Defines the rectangle.

**Since**: 11


### Camera_Size

```
typedef struct Camera_Size Camera_Size
```

**Description**

Defines the parameters that describe the size.

**Since**: 11


### Camera_Status

```
typedef enum Camera_Status Camera_Status
```

**Description**

Defines an enum for camera statuses.

**Since**: 11


### Camera_StatusInfo

```
typedef struct Camera_StatusInfo Camera_StatusInfo
```

**Description**

Defines the camera status information.

**Since**: 11


### Camera_Type

```
typedef enum Camera_Type Camera_Type
```

**Description**

Defines an enum for camera types.

**Since**: 11


### Camera_VideoOutput

```
typedef struct Camera_VideoOutput Camera_VideoOutput
```

**Description**

Defines the video output object.

You can call [OH_CameraManager_CreateVideoOutput](#oh_cameramanager_createvideooutput) to create such an object.

**Since**: 11


### Camera_VideoProfile

```
typedef struct Camera_VideoProfile Camera_VideoProfile
```

**Description**

Defines the video profile.

**Since**: 11


### Camera_VideoStabilizationMode

```
typedef enum Camera_VideoStabilizationMode Camera_VideoStabilizationMode
```

**Description**

Defines an enum for video stabilization modes.

**Since**: 11


### CameraInput_Callbacks

```
typedef struct CameraInput_Callbacks CameraInput_Callbacks
```

**Description**

Defines the callbacks used to listen for camera input errors.

**Since**: 11

**See**

[OH_CameraInput_RegisterCallback](#oh_camerainput_registercallback)


### CameraManager_Callbacks

```
typedef struct CameraManager_Callbacks CameraManager_Callbacks
```

**Description**

Defines the callbacks used to listen for camera status changes.

**Since**: 11

**See**

[OH_CameraManager_RegisterCallback](#oh_cameramanager_registercallback)


### CaptureSession_Callbacks

```
typedef struct CaptureSession_Callbacks CaptureSession_Callbacks
```

**Description**

Defines the callbacks used for session capture.

**Since**: 11

**See**

[OH_CaptureSession_RegisterCallback](#oh_capturesession_registercallback)


### MetadataOutput_Callbacks

```
typedef struct MetadataOutput_Callbacks MetadataOutput_Callbacks
```

**Description**

Defines the callback functions of metadata output.

**Since**: 11

**See**

[OH_MetadataOutput_RegisterCallback](#oh_metadataoutput_registercallback)


### OH_CameraInput_OnError

```
typedef void(* OH_CameraInput_OnError) (const Camera_Input *cameraInput, Camera_ErrorCode errorCode)
```

**Description**

Defines the pointer to the callback defined in the [CameraInput_Callbacks](_camera_input___callbacks.md) struct and used to report camera input errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the [Camera_Input](#camera_input) instance that transfers the callback.| 
| errorCode | Error code reported during camera input and defined in [Camera_ErrorCode](#camera_errorcode).| 

**See**

In [Camera_ErrorCode](#camera_errorcode):

CAMERA_CONFLICT_CAMERA

CAMERA_DEVICE_DISABLED

CAMERA_DEVICE_PREEMPTED

CAMERA_SERVICE_FATAL_ERROR


### OH_CameraManager_StatusCallback

```
typedef void(* OH_CameraManager_StatusCallback) (Camera_Manager *cameraManager, Camera_StatusInfo *status)
```

**Description**

Defines the pointer to the callback defined in the [CameraManager_Callbacks](_camera_manager___callbacks.md) struct and used to report the camera manager status.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to the [Camera_Manager](#camera_manager) instance that transfers the callback.| 
| status | Pointer to the camera manager status, which is defined in the [Camera_StatusInfo](_camera___status_info.md) struct.| 


### OH_CaptureSession_OnError

```
typedef void(* OH_CaptureSession_OnError) (Camera_CaptureSession *session, Camera_ErrorCode errorCode)
```

**Description**

Defines the pointer to the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report capture session errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the [Camera_CaptureSession](#camera_capturesession) instance that transfers the callback.| 
| errorCode | Error code reported during session capture and defined in [Camera_ErrorCode](#camera_errorcode).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode)


### OH_CaptureSession_OnFocusStateChange

```
typedef void(* OH_CaptureSession_OnFocusStateChange) (Camera_CaptureSession *session, Camera_FocusState focusState)
```

**Description**

Defines the pointer to the callback defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct and used to report session capture focus status changes.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the [Camera_CaptureSession](#camera_capturesession) instance that transfers the callback.| 
| focusState | Focus state, which is defined in [Camera_FocusState](#camera_focusstate).| 


### OH_MetadataOutput_OnError

```
typedef void(* OH_MetadataOutput_OnError) (Camera_MetadataOutput *metadataOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the pointer to the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the [Camera_MetadataOutput](#camera_metadataoutput) instance that transfers the callback.| 
| errorCode | Error code reported during metadata output and defined in [Camera_ErrorCode](#camera_errorcode).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode)


### OH_MetadataOutput_OnMetadataObjectAvailable

```
typedef void(* OH_MetadataOutput_OnMetadataObjectAvailable) (Camera_MetadataOutput *metadataOutput, Camera_MetadataObject *metadataObject, uint32_t size)
```

**Description**

Defines the pointer to the callback defined in the [MetadataOutput_Callbacks](_metadata_output___callbacks.md) struct and used to report metadata output data.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the [Camera_MetadataOutput](#camera_metadataoutput) instance that transfers the callback.| 
| metadataObject | Pointer to the metadata output data, which is defined in the [Camera_MetadataObject](_camera___metadata_object.md) struct.| 
| size | Size of the metadata object.| 


### OH_PhotoOutput_OnError

```
typedef void(* OH_PhotoOutput_OnError) (Camera_PhotoOutput *photoOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| errorCode | Error code reported during photo output and defined in [Camera_ErrorCode](#camera_errorcode).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode)


### OH_PhotoOutput_OnFrameEnd

```
typedef void(* OH_PhotoOutput_OnFrameEnd) (Camera_PhotoOutput *photoOutput, int32_t frameCount)
```

**Description**

Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame end events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| frameCount | Number of frames to be included in the callback.| 


### OH_PhotoOutput_OnFrameShutter

```
typedef void(* OH_PhotoOutput_OnFrameShutter) (Camera_PhotoOutput *photoOutput, Camera_FrameShutterInfo *info)
```

**Description**

Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report frame shutter events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 
| info | Pointer to the frame shutter information, which is defined in the [Camera_FrameShutterInfo](_camera___frame_shutter_info.md) struct.| 


### OH_PhotoOutput_OnFrameStart

```
typedef void(* OH_PhotoOutput_OnFrameStart) (Camera_PhotoOutput *photoOutput)
```

**Description**

Defines the pointer to the callback defined in the [PhotoOutput_Callbacks](_photo_output___callbacks.md) struct and used to report photo output frame start events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the [Camera_PhotoOutput](#camera_photooutput) instance that transfers the callback.| 


### OH_PreviewOutput_OnError

```
typedef void(* OH_PreviewOutput_OnError) (Camera_PreviewOutput *previewOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance that transfers the callback.| 
| errorCode | Error code reported during preview output and defined in [Camera_ErrorCode](#camera_errorcode).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode)


### OH_PreviewOutput_OnFrameEnd

```
typedef void(* OH_PreviewOutput_OnFrameEnd) (Camera_PreviewOutput *previewOutput, int32_t frameCount)
```

**Description**

Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used report preview output frame end events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance that transfers the callback.| 
| frameCount | Number of frames to be included in the callback.| 


### OH_PreviewOutput_OnFrameStart

```
typedef void(* OH_PreviewOutput_OnFrameStart) (Camera_PreviewOutput *previewOutput)
```

**Description**

Defines the pointer to the callback defined in the [PreviewOutput_Callbacks](_preview_output___callbacks.md) struct and used to report preview output frame start events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance that transfers the callback.| 


### OH_VideoOutput_OnError

```
typedef void(* OH_VideoOutput_OnError) (Camera_VideoOutput *videoOutput, Camera_ErrorCode errorCode)
```

**Description**

Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output errors.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance that transfers the callback.| 
| errorCode | Error code reported during video output and defined in [Camera_ErrorCode](#camera_errorcode).| 

**See**

**CAMERA_SERVICE_FATAL_ERROR** in [Camera_ErrorCode](#camera_errorcode)


### OH_VideoOutput_OnFrameEnd

```
typedef void(* OH_VideoOutput_OnFrameEnd) (Camera_VideoOutput *videoOutput, int32_t frameCount)
```

**Description**

Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame end events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance that transfers the callback.| 
| frameCount | Number of frames to be included in the callback.| 


### OH_VideoOutput_OnFrameStart

```
typedef void(* OH_VideoOutput_OnFrameStart) (Camera_VideoOutput *videoOutput)
```

**Description**

Defines the pointer to the callback defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct and used to report video output frame start events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the [Camera_VideoOutput](#camera_videooutput) instance that transfers the callback.| 


### PhotoOutput_Callbacks

```
typedef struct PhotoOutput_CallbacksPhotoOutput_Callbacks
```

**Description**

Defines the callbacks used for photo output.

**Since**: 11

**See**

[OH_PhotoOutput_RegisterCallback](#oh_photooutput_registercallback)


### PreviewOutput_Callbacks

```
typedef struct PreviewOutput_CallbacksPreviewOutput_Callbacks
```

**Description**

Defines the callbacks used for preview output.

**Since**: 11

**See**

[OH_PreviewOutput_RegisterCallback](#oh_previewoutput_registercallback)


### VideoOutput_Callbacks

```
typedef struct VideoOutput_CallbacksVideoOutput_Callbacks
```

**Description**

Defines the callbacks used for video output.

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
Camera_ErrorCode OH_Camera_DeleteCameraManager (Camera_Manager * cameraManager)
```

**Description**

Deletes a **CameraManager** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to the target [Camera_Manager](#camera_manager) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_Camera_GetCameraManager()

```
Camera_ErrorCode OH_Camera_GetCameraManager (Camera_Manager ** cameraManager)
```

**Description**

Obtains a **CameraManager** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Double pointer to the [Camera_Manager](#camera_manager) instance if the function is successfully called.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraInput_Close()

```
Camera_ErrorCode OH_CameraInput_Close (Camera_Input * cameraInput)
```

**Description**

Closes a camera.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraInput_Open()

```
Camera_ErrorCode OH_CameraInput_Open (Camera_Input * cameraInput)
```

**Description**

Opens a camera.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_CONFLICT_CAMERA** if the camera device is already started; returns **CAMERA_DEVICE_DISABLED** if the camera is disabled for security reasons; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraInput_RegisterCallback()

```
Camera_ErrorCode OH_CameraInput_RegisterCallback (Camera_Input * cameraInput, CameraInput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraInput_Release()

```
Camera_ErrorCode OH_CameraInput_Release (Camera_Input * cameraInput)
```

**Description**

Releases a **CameraInput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraInput | Pointer to the target [Camera_Input](#camera_input) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraInput_UnregisterCallback()

```
Camera_ErrorCode OH_CameraInput_UnregisterCallback (Camera_Input * cameraInput, CameraInput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_CreateCameraInput()

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput (Camera_Manager * cameraManager, const Camera_Device * camera, Camera_Input ** cameraInput )
```

**Description**

Creates a **CameraInput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| camera | Pointer to the target camera, which is defined in the [Camera_Device](_camera___device.md) struct.| 
| cameraInput | Double pointer to the [Camera_Input](#camera_input) instance if the function is successfully called.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).

**Required Permissions**

ohos.permission.CAMERA


### OH_CameraManager_CreateCameraInput_WithPositionAndType()

```
Camera_ErrorCode OH_CameraManager_CreateCameraInput_WithPositionAndType (Camera_Manager * cameraManager, Camera_Position position, Camera_Type type, Camera_Input ** cameraInput )
```

**Description**

Creates a **CameraInput** instance with the specified location and type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| position | Camera position, which is defined in the [Camera_Position](#camera_position) struct.| 
| type | Camera type, which is defined in the [Camera_Type](#camera_type) struct.| 
| cameraInput | Double pointer to the [Camera_Input](#camera_input) instance if the function is successfully called.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).

**Required Permissions**

ohos.permission.CAMERA


### OH_CameraManager_CreateCaptureSession()

```
Camera_ErrorCode OH_CameraManager_CreateCaptureSession (Camera_Manager * cameraManager, Camera_CaptureSession ** captureSession )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_CreateMetadataOutput()

```
Camera_ErrorCode OH_CameraManager_CreateMetadataOutput (Camera_Manager * cameraManager, const Camera_MetadataObjectType * profile, Camera_MetadataOutput ** metadataOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_CreatePhotoOutput()

```
Camera_ErrorCode OH_CameraManager_CreatePhotoOutput (Camera_Manager * cameraManager, const Camera_Profile * profile, const char * surfaceId, Camera_PhotoOutput ** photoOutput )
```

**Description**

Creates a **PhotoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| profile | Pointer to the profile, which is defined in the [Camera_Profile](_camera___profile.md) struct.| 
| surfaceId | Pointer to the surface ID.| 
| photoOutput | Double pointer to the [Camera_PhotoOutput](#camera_photooutput) instance if the function is successfully called.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_CreatePreviewOutput()

```
Camera_ErrorCode OH_CameraManager_CreatePreviewOutput (Camera_Manager * cameraManager, const Camera_Profile * profile, const char * surfaceId, Camera_PreviewOutput ** previewOutput )
```

**Description**

Creates a **PreviewOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| profile | Pointer to the profile, which is defined in the [Camera_Profile](_camera___profile.md) struct.| 
| surfaceId | Pointer to the surface ID.| 
| previewOutput | Double pointer to the [Camera_PreviewOutput](#camera_previewoutput) instance if the function is successfully called.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_CreateVideoOutput()

```
Camera_ErrorCode OH_CameraManager_CreateVideoOutput (Camera_Manager * cameraManager, const Camera_VideoProfile * profile, const char * surfaceId, Camera_VideoOutput ** videoOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_DeleteSupportedCameraOutputCapability()

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameraOutputCapability (Camera_Manager * cameraManager, Camera_OutputCapability * cameraOutputCapability )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_DeleteSupportedCameras()

```
Camera_ErrorCode OH_CameraManager_DeleteSupportedCameras (Camera_Manager * cameraManager, Camera_Device * cameras, uint32_t size )
```

**Description**

Deletes supported cameras.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| cameras | Pointer to the list of cameras, which is defined in the [Camera_Device](_camera___device.md) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_GetSupportedCameraOutputCapability()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameraOutputCapability (Camera_Manager * cameraManager, const Camera_Device * camera, Camera_OutputCapability ** cameraOutputCapability )
```

**Description**

Obtains the output capability supported by a camera in the specified mode.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| cameras | Pointer to the list of cameras, which is defined in the [Camera_Device](_camera___device.md) struct.| 
| cameraOutputCapability | Double pointer to the [Camera_OutputCapability](_camera___output_capability.md) struct if the function is successfully called.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_GetSupportedCameras()

```
Camera_ErrorCode OH_CameraManager_GetSupportedCameras (Camera_Manager * cameraManager, Camera_Device ** cameras, uint32_t * size )
```

**Description**

Obtains supported cameras.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cameraManager | Pointer to a [Camera_Manager](#camera_manager) instance.| 
| cameras | Double pointer to the list of cameras, which is defined in the [Camera_Device](_camera___device.md) struct, if the function is successfully called.| 
| size | Pointer to the size of the list of cameras.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_IsCameraMuted()

```
Camera_ErrorCode OH_CameraManager_IsCameraMuted (Camera_Manager * cameraManager, bool * isCameraMuted )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_RegisterCallback()

```
Camera_ErrorCode OH_CameraManager_RegisterCallback (Camera_Manager * cameraManager, CameraManager_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CameraManager_UnregisterCallback()

```
Camera_ErrorCode OH_CameraManager_UnregisterCallback (Camera_Manager * cameraManager, CameraManager_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_AddInput()

```
Camera_ErrorCode OH_CaptureSession_AddInput (Camera_CaptureSession * session, Camera_Input * cameraInput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_AddMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_AddMetadataOutput (Camera_CaptureSession * session, Camera_MetadataOutput * metadataOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_AddPhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPhotoOutput (Camera_CaptureSession * session, Camera_PhotoOutput * photoOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_AddPreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_AddPreviewOutput (Camera_CaptureSession * session, Camera_PreviewOutput * previewOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_AddVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_AddVideoOutput (Camera_CaptureSession * session, Camera_VideoOutput * videoOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_BeginConfig()

```
Camera_ErrorCode OH_CaptureSession_BeginConfig (Camera_CaptureSession * session)
```

**Description**

Starts the configuration for session capture.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_CONFIG_LOCKED** if the session configuration is locked. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_CommitConfig()

```
Camera_ErrorCode OH_CaptureSession_CommitConfig (Camera_CaptureSession * session)
```

**Description**

Commits the configuration for session capture.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBias (Camera_CaptureSession * session, float * exposureBias )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetExposureBiasRange()

```
Camera_ErrorCode OH_CaptureSession_GetExposureBiasRange (Camera_CaptureSession * session, float * minExposureBias, float * maxExposureBias, float * step )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_GetExposureMode (Camera_CaptureSession * session, Camera_ExposureMode * exposureMode )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_GetFlashMode (Camera_CaptureSession * session, Camera_FlashMode * flashMode )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_GetFocusMode (Camera_CaptureSession * session, Camera_FocusMode * focusMode )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_GetFocusPoint (Camera_CaptureSession * session, Camera_Point * focusPoint )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_GetMeteringPoint (Camera_CaptureSession * session, Camera_Point * point )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_GetVideoStabilizationMode (Camera_CaptureSession * session, Camera_VideoStabilizationMode * mode )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatio (Camera_CaptureSession * session, float * zoom )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_GetZoomRatioRange()

```
Camera_ErrorCode OH_CaptureSession_GetZoomRatioRange (Camera_CaptureSession * session, float * minZoom, float * maxZoom )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_HasFlash()

```
Camera_ErrorCode OH_CaptureSession_HasFlash (Camera_CaptureSession * session, bool * hasFlash )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_IsExposureModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsExposureModeSupported (Camera_CaptureSession * session, Camera_ExposureMode exposureMode, bool * isSupported )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_IsFlashModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFlashModeSupported (Camera_CaptureSession * session, Camera_FlashMode flashMode, bool * isSupported )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_IsFocusModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsFocusModeSupported (Camera_CaptureSession * session, Camera_FocusMode focusMode, bool * isSupported )
```

**Description**

Checks whether a focus mode is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| focusMode | Target focus mode, which is defined in the [Camera_FocusMode](#camera_focusmode) struct.| 
| isSupported | Pointer to the result that specifies whether the focus mode is supported.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_IsVideoStabilizationModeSupported()

```
Camera_ErrorCode OH_CaptureSession_IsVideoStabilizationModeSupported (Camera_CaptureSession * session, Camera_VideoStabilizationMode mode, bool * isSupported )
```

**Description**

Checks whether a video stabilization mode is supported. 

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| mode | Target video stabilization mode, which is defined in the [Camera_VideoStabilizationMode](#camera_videostabilizationmode) struct.| 
| isSupported | Pointer to the result that specifies whether the video stabilization mode is supported.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_RegisterCallback()

```
Camera_ErrorCode OH_CaptureSession_RegisterCallback (Camera_CaptureSession * session, CaptureSession_Callbacks * callback )
```

**Description**

Registers a callback to listen for session capture events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| callback | Pointer to the target callback, which is defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_Release()

```
Camera_ErrorCode OH_CaptureSession_Release (Camera_CaptureSession * session)
```

**Description**

Releases a **CaptureSession** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_RemoveInput()

```
Camera_ErrorCode OH_CaptureSession_RemoveInput (Camera_CaptureSession * session, Camera_Input * cameraInput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_RemoveMetadataOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveMetadataOutput (Camera_CaptureSession * session, Camera_MetadataOutput * metadataOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_RemovePhotoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePhotoOutput (Camera_CaptureSession * session, Camera_PhotoOutput * photoOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_RemovePreviewOutput()

```
Camera_ErrorCode OH_CaptureSession_RemovePreviewOutput (Camera_CaptureSession * session, Camera_PreviewOutput * previewOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_RemoveVideoOutput()

```
Camera_ErrorCode OH_CaptureSession_RemoveVideoOutput (Camera_CaptureSession * session, Camera_VideoOutput * videoOutput )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_OPERATION_NOT_ALLOWED** if the operation is not allowed. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetExposureBias()

```
Camera_ErrorCode OH_CaptureSession_SetExposureBias (Camera_CaptureSession * session, float exposureBias )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetExposureMode()

```
Camera_ErrorCode OH_CaptureSession_SetExposureMode (Camera_CaptureSession * session, Camera_ExposureMode exposureMode )
```

**Description**

Sets an [Camera_VideoOutput](#camera_videooutput) for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| exposureMode | Target exposure mode, which is defined in the [Camera_ExposureMode](#camera_exposuremode) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetFlashMode()

```
Camera_ErrorCode OH_CaptureSession_SetFlashMode (Camera_CaptureSession * session, Camera_FlashMode flashMode )
```

**Description**

Sets a flash mode for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| flashMode | Target flash mode, which is defined in the [Camera_FlashMode](#camera_flashmode) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetFocusMode()

```
Camera_ErrorCode OH_CaptureSession_SetFocusMode (Camera_CaptureSession * session, Camera_FocusMode focusMode )
```

**Description**

Sets a focus mode for the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| focusMode | Target focus mode, which is defined in the [Camera_FocusMode](#camera_focusmode) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetFocusPoint()

```
Camera_ErrorCode OH_CaptureSession_SetFocusPoint (Camera_CaptureSession * session, Camera_Point focusPoint )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetMeteringPoint()

```
Camera_ErrorCode OH_CaptureSession_SetMeteringPoint (Camera_CaptureSession * session, Camera_Point point )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetVideoStabilizationMode()

```
Camera_ErrorCode OH_CaptureSession_SetVideoStabilizationMode (Camera_CaptureSession * session, Camera_VideoStabilizationMode mode )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_SetZoomRatio()

```
Camera_ErrorCode OH_CaptureSession_SetZoomRatio (Camera_CaptureSession * session, float zoom )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_Start()

```
Camera_ErrorCode OH_CaptureSession_Start (Camera_CaptureSession * session)
```

**Description**

Starts session capture.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_Stop()

```
Camera_ErrorCode OH_CaptureSession_Stop (Camera_CaptureSession * session)
```

**Description**

Stops session capture.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_CaptureSession_UnregisterCallback()

```
Camera_ErrorCode OH_CaptureSession_UnregisterCallback (Camera_CaptureSession * session, CaptureSession_Callbacks * callback )
```

**Description**

Unregisters the callback used to listen for session capture events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| session | Pointer to the target [Camera_CaptureSession](#camera_capturesession) instance.| 
| callback | Pointer to the target callback, which is defined in the [CaptureSession_Callbacks](_capture_session___callbacks.md) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_MetadataOutput_RegisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_RegisterCallback (Camera_MetadataOutput * metadataOutput, MetadataOutput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_MetadataOutput_Release()

```
Camera_ErrorCode OH_MetadataOutput_Release (Camera_MetadataOutput * metadataOutput)
```

**Description**

Releases a **MetadataOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_MetadataOutput_Start()

```
Camera_ErrorCode OH_MetadataOutput_Start (Camera_MetadataOutput * metadataOutput)
```

**Description**

Starts metadata output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_MetadataOutput_Stop()

```
Camera_ErrorCode OH_MetadataOutput_Stop (Camera_MetadataOutput * metadataOutput)
```

**Description**

Stops metadata output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| metadataOutput | Pointer to the target [Camera_MetadataOutput](#camera_metadataoutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_MetadataOutput_UnregisterCallback()

```
Camera_ErrorCode OH_MetadataOutput_UnregisterCallback (Camera_MetadataOutput * metadataOutput, MetadataOutput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PhotoOutput_Capture()

```
Camera_ErrorCode OH_PhotoOutput_Capture (Camera_PhotoOutput * photoOutput)
```

**Description**

Captures a photo.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PhotoOutput_Capture_WithCaptureSetting()

```
Camera_ErrorCode OH_PhotoOutput_Capture_WithCaptureSetting (Camera_PhotoOutput * photoOutput, Camera_PhotoCaptureSetting setting )
```

**Description**

Captures a photo with the photographing parameters.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 
| setting | Photographing parameters, which are defined in the [Camera_PhotoCaptureSetting](_camera___photo_capture_setting.md) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PhotoOutput_IsMirrorSupported()

```
Camera_ErrorCode OH_PhotoOutput_IsMirrorSupported (Camera_PhotoOutput * photoOutput, bool * isSupported )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PhotoOutput_RegisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_RegisterCallback (Camera_PhotoOutput * photoOutput, PhotoOutput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PhotoOutput_Release()

```
Camera_ErrorCode OH_PhotoOutput_Release (Camera_PhotoOutput * photoOutput)
```

**Description**

Releases a **PhotoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| photoOutput | Pointer to the target [Camera_PhotoOutput](#camera_photooutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PhotoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PhotoOutput_UnregisterCallback (Camera_PhotoOutput * photoOutput, PhotoOutput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PreviewOutput_RegisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_RegisterCallback (Camera_PreviewOutput * previewOutput, PreviewOutput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PreviewOutput_Release()

```
Camera_ErrorCode OH_PreviewOutput_Release (Camera_PreviewOutput * previewOutput)
```

**Description**

Releases a **PreviewOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PreviewOutput_Start()

```
Camera_ErrorCode OH_PreviewOutput_Start (Camera_PreviewOutput * previewOutput)
```

**Description**

Starts preview output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PreviewOutput_Stop()

```
Camera_ErrorCode OH_PreviewOutput_Stop (Camera_PreviewOutput * previewOutput)
```

**Description**

Stops preview output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| previewOutput | Pointer to the target [Camera_PreviewOutput](#camera_previewoutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_PreviewOutput_UnregisterCallback()

```
Camera_ErrorCode OH_PreviewOutput_UnregisterCallback (Camera_PreviewOutput * previewOutput, PreviewOutput_Callbacks * callback )
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

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_VideoOutput_RegisterCallback()

```
Camera_ErrorCode OH_VideoOutput_RegisterCallback (Camera_VideoOutput * videoOutput, VideoOutput_Callbacks * callback )
```

**Description**

Registers a callback to listen for video output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to a [Camera_VideoOutput](#camera_videooutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_VideoOutput_Release()

```
Camera_ErrorCode OH_VideoOutput_Release (Camera_VideoOutput * videoOutput)
```

**Description**

Releases a **VideoOutput** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_VideoOutput_Start()

```
Camera_ErrorCode OH_VideoOutput_Start (Camera_VideoOutput * videoOutput)
```

**Description**

Starts video output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SESSION_NOT_CONFIG** if the session is not configured; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_VideoOutput_Stop()

```
Camera_ErrorCode OH_VideoOutput_Stop (Camera_VideoOutput * videoOutput)
```

**Description**

Stops video output.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to the target [Camera_VideoOutput](#camera_videooutput) instance.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect; returns **CAMERA_SERVICE_FATAL_ERROR** if a fatal error occurs in the camera service. For details, see [Camera_ErrorCode](#camera_errorcode).


### OH_VideoOutput_UnregisterCallback()

```
Camera_ErrorCode OH_VideoOutput_UnregisterCallback (Camera_VideoOutput * videoOutput, VideoOutput_Callbacks * callback )
```

**Description**

Unregisters the callback used to listen for video output events.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| videoOutput | Pointer to a [Camera_VideoOutput](#camera_videooutput) instance.| 
| callback | Pointer to the target callback, which is defined in the [VideoOutput_Callbacks](_video_output___callbacks.md) struct.| 

**Returns**

Returns **CAMERA_OK** if the function is successfully called; returns **INVALID_ARGUMENT** if a parameter is missing or the parameter type is incorrect. For details, see [Camera_ErrorCode](#camera_errorcode).
