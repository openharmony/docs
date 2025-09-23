# camera.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the basic concepts of the camera.

**File to include**: <ohcamera/camera.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Camera_Size](capi-oh-camera-camera-size.md) | Camera_Size | Describes the parameters related to the size.|
| [Camera_Profile](capi-oh-camera-camera-profile.md) | Camera_Profile | Describes the profile of a camera stream.|
| [Camera_FrameRateRange](capi-oh-camera-camera-frameraterange.md) | Camera_FrameRateRange | Describes the frame rate range.|
| [Camera_VideoProfile](capi-oh-camera-camera-videoprofile.md) | Camera_VideoProfile | Describes the video profile.|
| [Camera_OutputCapability](capi-oh-camera-camera-outputcapability.md) | Camera_OutputCapability | Describes the camera output capability.|
| [Camera_Device](capi-oh-camera-camera-device.md) | Camera_Device | Describes the camera device.|
| [Camera_StatusInfo](capi-oh-camera-camera-statusinfo.md) | Camera_StatusInfo | Describes the camera status information.|
| [Camera_Point](capi-oh-camera-camera-point.md) | Camera_Point | Describes the parameters related to a point.|
| [Camera_Location](capi-oh-camera-camera-location.md) | Camera_Location | Describes the location where the photo is taken.|
| [Camera_PhotoCaptureSetting](capi-oh-camera-camera-photocapturesetting.md) | Camera_PhotoCaptureSetting | Describes the parameters related to photo capture.|
| [Camera_FrameShutterInfo](capi-oh-camera-camera-frameshutterinfo.md) | Camera_FrameShutterInfo | Describes the frame shutter information.|
| [Camera_CaptureEndInfo](capi-oh-camera-camera-captureendinfo.md) | Camera_CaptureEndInfo | Describes the capture end information.|
| [Camera_Rect](capi-oh-camera-camera-rect.md) | Camera_Rect | Defines the rectangle.|
| [Camera_MetadataObject](capi-oh-camera-camera-metadataobject.md) | Camera_MetadataObject | Describes the camera metadata.|
| [Camera_TorchStatusInfo](capi-oh-camera-camera-torchstatusinfo.md) | Camera_TorchStatusInfo | Describes the flashlight status information.|
| [Camera_SmoothZoomInfo](capi-oh-camera-camera-smoothzoominfo.md) | Camera_SmoothZoomInfo | Describes the smooth zoom information.|
| [Camera_CaptureStartInfo](capi-oh-camera-camera-capturestartinfo.md) | Camera_CaptureStartInfo | Describes the capture start information.|
| [Camera_FrameShutterEndInfo](capi-oh-camera-camera-frameshutterendinfo.md) | Camera_FrameShutterEndInfo | Describes the frame shutter end information during capture.|
| [Camera_FoldStatusInfo](capi-oh-camera-camera-foldstatusinfo.md) | Camera_FoldStatusInfo | Describes the fold status information of the camera.|
| [Camera_AutoDeviceSwitchStatusInfo](capi-oh-camera-camera-autodeviceswitchstatusinfo.md) | Camera_AutoDeviceSwitchStatusInfo | Describes the automatic device switching status information.|
| [Camera_ConcurrentInfo](capi-oh-camera-camera-concurrentinfo.md) | Camera_ConcurrentInfo | Describes the camera's concurrency information.|
| [Camera_ControlCenterStatusInfo](capi-oh-camera-camera-controlcenterstatusinfo.md) | Camera_ControlCenterStatusInfo | Describes the effect status information of a camera controller.|
| [Camera_Manager](capi-oh-camera-camera-manager.md) | Camera_Manager | Describes the camera manager.<br> You can call [OH_Camera_GetCameraManager](#oh_camera_getcameramanager) to create such an object.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Camera_ErrorCode](#camera_errorcode) | Camera_ErrorCode | Enumerates the camera error codes.|
| [Camera_Status](#camera_status) | Camera_Status | Enumerates the camera statuses.|
| [Camera_SceneMode](#camera_scenemode) | Camera_SceneMode | Enumerates the camera scene modes.|
| [Camera_Position](#camera_position) | Camera_Position | Enumerates the camera positions.|
| [Camera_Type](#camera_type) | Camera_Type | Enumerates the camera types.|
| [Camera_Connection](#camera_connection) | Camera_Connection | Enumerates the camera connection types.|
| [Camera_Format](#camera_format) | Camera_Format | Enumerates the camera output formats.|
| [Camera_FlashMode](#camera_flashmode) | Camera_FlashMode | Enumerates the flash modes.|
| [Camera_ExposureMode](#camera_exposuremode) | Camera_ExposureMode | Enumerates the exposure modes.|
| [Camera_FocusMode](#camera_focusmode) | Camera_FocusMode | Enumerates the focus modes.|
| [Camera_FocusState](#camera_focusstate) | Camera_FocusState | Enumerates the focus states.|
| [Camera_VideoStabilizationMode](#camera_videostabilizationmode) | Camera_VideoStabilizationMode | Enumerates the video stabilization modes.|
| [Camera_ImageRotation](#camera_imagerotation) | Camera_ImageRotation | Enumerates the image rotation angles.|
| [Camera_QualityLevel](#camera_qualitylevel) | Camera_QualityLevel | Enumerates the image quality levels.|
| [Camera_MetadataObjectType](#camera_metadataobjecttype) | Camera_MetadataObjectType | Enumerates the metadata object types.|
| [Camera_TorchMode](#camera_torchmode) | Camera_TorchMode | Enumerates the flashlight modes.|
| [Camera_SmoothZoomMode](#camera_smoothzoommode) | Camera_SmoothZoomMode | Enumerates the smooth zoom modes.|
| [Camera_SystemPressureLevel](#camera_systempressurelevel) | Camera_SystemPressureLevel | Enumerates the system pressure levels.|
| [Camera_PreconfigType](#camera_preconfigtype) | Camera_PreconfigType | Enumerates the preconfigured photo resolution types.|
| [Camera_PreconfigRatio](#camera_preconfigratio) | Camera_PreconfigRatio | Enumerates the preconfigured photo aspect ratios.|
| [Camera_HostDeviceType](#camera_hostdevicetype) | Camera_HostDeviceType | Enumerates the remote device types.|
| [Camera_FoldStatus](#camera_foldstatus) | Camera_FoldStatus | Enumerates the fold statuses.|
| [Camera_QualityPrioritization](#camera_qualityprioritization) | Camera_QualityPrioritization | Enumerates the priority levels for video recording quality.|
| [Camera_ConcurrentType](#camera_concurrenttype) | Camera_ConcurrentType | Enumerates the camera's concurrency types.|
| [Camera_WhiteBalanceMode](#camera_whitebalancemode) | Camera_WhiteBalanceMode | Enumerates the white balance modes.|
| [Camera_ControlCenterEffectType](#camera_controlcentereffecttype) | Camera_ControlCenterEffectType | Enumerates the effect types of a camera controller.|
| [Camera_PhotoQualityPrioritization](#camera_photoqualityprioritization) | Camera_PhotoQualityPrioritization | Enumerates the photo quality prioritization strategies.|

### Functions

| Name| Description|
| -- | -- |
| [Camera_ErrorCode OH_Camera_GetCameraManager(Camera_Manager** cameraManager)](#oh_camera_getcameramanager) | Obtains a Camera_Manager instance.|
| [Camera_ErrorCode OH_Camera_DeleteCameraManager(Camera_Manager* cameraManager)](#oh_camera_deletecameramanager) | Deletes a Camera_Manager instance.|

## Enum Description

### Camera_ErrorCode

```
enum Camera_ErrorCode
```

**Description**

Enumerates the camera error codes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CAMERA_OK = 0 | The camera is normal.|
| CAMERA_INVALID_ARGUMENT = 7400101 | A parameter is missing or the parameter type is incorrect.|
| CAMERA_OPERATION_NOT_ALLOWED = 7400102 | The operation is not allowed.|
| CAMERA_SESSION_NOT_CONFIG = 7400103 | The session is not configured.|
| CAMERA_SESSION_NOT_RUNNING = 7400104 | The session is not running.|
| CAMERA_SESSION_CONFIG_LOCKED = 7400105 | The session configuration is locked.|
| CAMERA_DEVICE_SETTING_LOCKED = 7400106 | The device setting is locked.|
| CAMERA_CONFLICT_CAMERA = 7400107 | The device is already started.|
| CAMERA_DEVICE_DISABLED = 7400108 | The camera is disabled for security reasons.|
| CAMERA_DEVICE_PREEMPTED = 7400109 | The camera is preempted.|
| CAMERA_UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS = 7400110 | The configuration conflicts with the current configuration.<br>**Since**: 12|
| CAMERA_SERVICE_FATAL_ERROR = 7400201 | A fatal error occurs in the camera service, for example, no camera permission, camera service restart, or abnormal cross-process invocation.|

### Camera_Status

```
enum Camera_Status
```

**Description**

Enumerates the camera statuses.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CAMERA_STATUS_APPEAR = 0 | A camera appears.|
| CAMERA_STATUS_DISAPPEAR = 1 | The camera disappears.|
| CAMERA_STATUS_AVAILABLE = 2 | The camera is available.|
| CAMERA_STATUS_UNAVAILABLE = 3 | The camera is unavailable.|

### Camera_SceneMode

```
enum Camera_SceneMode
```

**Description**

Enumerates the camera scene modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| NORMAL_PHOTO = 1 | Normal photo mode.|
| NORMAL_VIDEO = 2 | Normal video mode.|
| SECURE_PHOTO = 12 | Secure mode.|

### Camera_Position

```
enum Camera_Position
```

**Description**

Enumerates the camera positions.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CAMERA_POSITION_UNSPECIFIED = 0 | A camera that does not have a fixed orientation relative to the device screen.|
| CAMERA_POSITION_BACK = 1 | Rear camera.|
| CAMERA_POSITION_FRONT = 2 | Front camera.|

### Camera_Type

```
enum Camera_Type
```

**Description**

Enumerates the camera types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CAMERA_TYPE_DEFAULT = 0 | Default camera type.|
| CAMERA_TYPE_WIDE_ANGLE = 1 | Wide camera.|
| CAMERA_TYPE_ULTRA_WIDE = 2 | Ultra-wide camera.|
| CAMERA_TYPE_TELEPHOTO = 3 | Telephoto camera.|
| CAMERA_TYPE_TRUE_DEPTH = 4 | Camera with depth of field information.|

### Camera_Connection

```
enum Camera_Connection
```

**Description**

Enumerates the camera connection types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CAMERA_CONNECTION_BUILT_IN = 0 | Built-in camera.|
| CAMERA_CONNECTION_USB_PLUGIN = 1 | Camera connected using USB.|
| CAMERA_CONNECTION_REMOTE = 2 | Remote camera.|

### Camera_Format

```
enum Camera_Format
```

**Description**

Enumerates the camera output formats.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CAMERA_FORMAT_RGBA_8888 = 3 | RGBA 8888.|
| CAMERA_FORMAT_YUV_420_SP = 1003 | YUV 420 SP.|
| CAMERA_FORMAT_JPEG = 2000 | JPEG.|
| CAMERA_FORMAT_YCBCR_P010 = 2001 | YCBCR P010.<br>**Since**: 12|
| CAMERA_FORMAT_YCRCB_P010 = 2002 | YCRCB P010.<br>**Since**: 12|

### Camera_FlashMode

```
enum Camera_FlashMode
```

**Description**

Enumerates the flash modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| FLASH_MODE_CLOSE = 0 | The flash is off.|
| FLASH_MODE_OPEN = 1 | The flash is on.|
| FLASH_MODE_AUTO = 2 | The flash mode is auto.|
| FLASH_MODE_ALWAYS_OPEN = 3 | The flash is steady on.|

### Camera_ExposureMode

```
enum Camera_ExposureMode
```

**Description**

Enumerates the exposure modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| EXPOSURE_MODE_LOCKED = 0 | Exposure locked.|
| EXPOSURE_MODE_AUTO = 1 | Auto exposure.|
| EXPOSURE_MODE_CONTINUOUS_AUTO = 2 | Continuous auto exposure.|

### Camera_FocusMode

```
enum Camera_FocusMode
```

**Description**

Enumerates the focus modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| FOCUS_MODE_MANUAL = 0 | Manual focus.|
| FOCUS_MODE_CONTINUOUS_AUTO = 1 | Continuous auto focus.|
| FOCUS_MODE_AUTO = 2 | Auto focus.|
| FOCUS_MODE_LOCKED = 3 | Focus locked.|

### Camera_FocusState

```
enum Camera_FocusState
```

**Description**

Enumerates the focus states.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| FOCUS_STATE_SCAN = 0 | Focusing.|
| FOCUS_STATE_FOCUSED = 1 | Focused.|
| FOCUS_STATE_UNFOCUSED = 2 | Unfocused.|

### Camera_VideoStabilizationMode

```
enum Camera_VideoStabilizationMode
```

**Description**

Enumerates the video stabilization modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| STABILIZATION_MODE_OFF = 0 | Video stabilization is disabled.|
| STABILIZATION_MODE_LOW = 1 | The basic video stabilization algorithm is used.|
| STABILIZATION_MODE_MIDDLE = 2 | A video stabilization algorithm with a stabilization effect better than that of the **LOW** type is used.|
| STABILIZATION_MODE_HIGH = 3 | A video stabilization algorithm with a stabilization effect better than that of the **MIDDLE** type is used.|
| STABILIZATION_MODE_AUTO = 4 | Automatic video stabilization is used. This value is available for HDF cameras.|

### Camera_ImageRotation

```
enum Camera_ImageRotation
```

**Description**

Enumerates the image rotation angles.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| IAMGE_ROTATION_0 = 0 | The image rotates 0 degrees.|
| IAMGE_ROTATION_90 = 90 | The image rotates 90 degrees.|
| IAMGE_ROTATION_180 = 180 | The image rotates 180 degrees.|
| IAMGE_ROTATION_270 = 270 | The image rotates 270 degrees.|

### Camera_QualityLevel

```
enum Camera_QualityLevel
```

**Description**

Enumerates the image quality levels.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| QUALITY_LEVEL_HIGH = 0 | High image quality.|
| QUALITY_LEVEL_MEDIUM = 1 | Medium image quality.|
| QUALITY_LEVEL_LOW = 2 | Low image quality.|

### Camera_MetadataObjectType

```
enum Camera_MetadataObjectType
```

**Description**

Enumerates the metadata object types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| FACE_DETECTION = 0 | Metadata object used for face detection.|

### Camera_TorchMode

```
enum Camera_TorchMode
```

**Description**

Enumerates the flashlight modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OFF = 0 | The flashlight is always off.|
| ON = 1 | The flashlight is always on.|
| AUTO = 2 | The flashlight will be turned on automatically based on the ambient lighting level.|

### Camera_SmoothZoomMode

```
enum Camera_SmoothZoomMode
```

**Description**

Enumerates the smooth zoom modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| NORMAL = 0 | Bessel curve mode.|

### Camera_SystemPressureLevel

```
enum Camera_SystemPressureLevel
```

**Description**

Enumerates the system pressure levels.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| SYSTEM_PRESSURE_NORMAL = 0 | The system pressure is normal.|
| SYSTEM_PRESSURE_MILD = 1 | The system pressure is elevated but not actively managed by the system.|
| SYSTEM_PRESSURE_SEVERE = 2 | The system pressure may affect the overall image quality and performance.|
| SYSTEM_PRESSURE_CRITICAL = 3 | The system pressure has a significant impact on the image quality and performance.|
| SYSTEM_PRESSURE_SHUTDOWN = 4 | The system pressure is too high, causing the system to shut down.|

### Camera_PreconfigType

```
enum Camera_PreconfigType
```

**Description**

Enumerates the preconfigured photo resolution types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| PRECONFIG_720P = 0 | 720p resolution.|
| PRECONFIG_1080P = 1 | 1080p resolution.|
| PRECONFIG_4K = 2 | 4K resolution.|
| PRECONFIG_HIGH_QUALITY = 3 | High-quality photos.|

### Camera_PreconfigRatio

```
enum Camera_PreconfigRatio
```

**Description**

Enumerates the preconfigured photo aspect ratios.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| PRECONFIG_RATIO_1_1 = 0 | 1:1 aspect ratio.|
| PRECONFIG_RATIO_4_3 = 1 | 4:3 aspect ratio.|
| PRECONFIG_RATIO_16_9 = 2 | 16:9 aspect ratio.|

### Camera_HostDeviceType

```
enum Camera_HostDeviceType
```

**Description**

Enumerates the remote device types.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| HOST_DEVICE_TYPE_UNKNOWN_TYPE = 0 | Unknown type.|
| HOST_DEVICE_TYPE_PHONE = 0x0E | Mobile phone.|
| HOST_DEVICE_TYPE_TABLET = 0x11 | Tablet.|

### Camera_FoldStatus

```
enum Camera_FoldStatus
```

**Description**

Enumerates the fold statuses.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| NON_FOLDABLE = 0 | Unfoldable.|
| EXPANDED = 1 | Unfolded.|
| FOLDED = 2 | Folded.|

### Camera_QualityPrioritization

```
enum Camera_QualityPrioritization
```

**Description**

Enumerates the priority levels for video recording quality.

**Since**: 14

| Enum Item| Description|
| -- | -- |
| HIGH_QUALITY = 0 | Prioritizes high-quality video recording.|
| POWER_BALANCE = 1 | Prioritizes video recording quality while balancing power consumption.|

### Camera_ConcurrentType

```
enum Camera_ConcurrentType
```

**Description**

Enumerates the camera's concurrency types.

**Since**: 18

| Enum Item| Description|
| -- | -- |
| CAMERA_CONCURRENT_TYPE_LIMITED_CAPABILITY  = 0 | Limited camera concurrency.|
| CAMERA_CONCURRENT_TYPE_FULL_CAPABILITY = 1 | Full camera concurrency.|

### Camera_WhiteBalanceMode

```
enum Camera_WhiteBalanceMode
```

**Description**

Enumerates the white balance modes.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CAMERA_WHITE_BALANCE_MODE_AUTO = 0 | Automatic.|
| CAMERA_WHITE_BALANCE_MODE_CLOUDY = 1 | Cloudy.|
| CAMERA_WHITE_BALANCE_MODE_INCANDESCENT = 2 | Incandescent light.|
| CAMERA_WHITE_BALANCE_MODE_FLUORESCENT = 3 | Fluorescence light.|
| CAMERA_WHITE_BALANCE_MODE_DAYLIGHT = 4 | Daylight.|
| CAMERA_WHITE_BALANCE_MODE_MANUAL = 5 | Manual.|
| CAMERA_WHITE_BALANCE_MODE_LOCKED = 6 | Locked.|

### Camera_ControlCenterEffectType

```
enum Camera_ControlCenterEffectType
```

**Description**

Enumerates the effect types of a camera controller.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CONTROL_CENTER_EFFECT_TYPE_BEAUTY = 0 | Beauty effect.|
| CONTROL_CENTER_EFFECT_TYPE_PORTRAIT = 1 | Portrait blur effect.|

### Camera_PhotoQualityPrioritization

```
enum Camera_PhotoQualityPrioritization
```

**Description**

Enumerates the photo quality prioritization strategies.

**Since**: 21

| Enum Item| Description|
| -- | -- |
| CAMERA_PHOTO_QUALITY_PRIORITIZATION_HIGH_QUALITY = 0 | Focuses on image quality, which may increase the time required for capturing photos to ensure high-quality output.|
| CAMERA_PHOTO_QUALITY_PRIORITIZATION_SPEED = 1 | Focuses on performance, trading off image quality for faster capture times.|


## Function Description

### OH_Camera_GetCameraManager()

```
Camera_ErrorCode OH_Camera_GetCameraManager(Camera_Manager** cameraManager)
```

**Description**

Obtains a Camera_Manager instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)** cameraManager | Double pointer to the Camera_Manager instance created, if the function is successfully called.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|

### OH_Camera_DeleteCameraManager()

```
Camera_ErrorCode OH_Camera_DeleteCameraManager(Camera_Manager* cameraManager)
```

**Description**

Deletes a Camera_Manager instance.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [Camera_Manager](capi-oh-camera-camera-manager.md)* cameraManager | Pointer to the target Camera_Manager instance.|

**Returns**

| Type| Description|
| -- | -- |
| [Camera_ErrorCode](#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: A fatal error occurs in the camera service.|
