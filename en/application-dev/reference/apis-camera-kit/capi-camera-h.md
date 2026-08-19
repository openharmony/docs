# camera.h

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9bee8cbce88e74e911451ede628deb5598986bb1 translatedAt=2026-08-11T02:02:50.204Z pushedAt=2026-08-12T02:21:34.200Z -->

## Overview

Defines the basic APIs of the camera.

**File to include**: <ohcamera/camera.h>

**Library**: libohcamera.so

**System capability**: SystemCapability.Multimedia.Camera.Core

**Since**: 11

**Related module**: [OH_Camera](capi-oh-camera.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Camera_DeviceQueryInfo](capi-oh-camera-camera-devicequeryinfo.md) | Camera_DeviceQueryInfo | Describes the camera device query information.|
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
| [Camera_Rect](capi-oh-camera-camera-rect.md) | Camera_Rect | Defines a camera rectangle. This method is used to draw rectangles for various detection objects.<br> The coordinate system for detection points is based on the landscape device orientation, with the charging port on the right.<br> The origin of the coordinate system is (0, 0) at the upper left corner, and the coordinates at the lower right corner are the resolution of the camera preview stream.<br> All parameters are integer pixel values. **topLeftX** and **topLeftY** indicate the coordinates of the upper left corner of the rectangle, and **width** and **height** indicate the width and height of the rectangle. |
| [Camera_MetadataObject](capi-oh-camera-camera-metadataobject.md) | Camera_MetadataObject | Describes the camera metadata.|
| [Camera_TorchStatusInfo](capi-oh-camera-camera-torchstatusinfo.md) | Camera_TorchStatusInfo | Describes the flashlight status information.|
| [Camera_SmoothZoomInfo](capi-oh-camera-camera-smoothzoominfo.md) | Camera_SmoothZoomInfo | Describes the smooth zoom information.|
| [Camera_CaptureStartInfo](capi-oh-camera-camera-capturestartinfo.md) | Camera_CaptureStartInfo | Describes the capture start information.|
| [Camera_FrameShutterEndInfo](capi-oh-camera-camera-frameshutterendinfo.md) | Camera_FrameShutterEndInfo | Describes the frame shutter end information during capture.|
| [Camera_FoldStatusInfo](capi-oh-camera-camera-foldstatusinfo.md) | Camera_FoldStatusInfo | Describes the fold status information of the camera.|
| [Camera_AutoDeviceSwitchStatusInfo](capi-oh-camera-camera-autodeviceswitchstatusinfo.md) | Camera_AutoDeviceSwitchStatusInfo | Describes the automatic device switching status information.|
| [Camera_ConcurrentInfo](capi-oh-camera-camera-concurrentinfo.md) | Camera_ConcurrentInfo | Describes the camera's concurrency information.|
| [Camera_ControlCenterStatusInfo](capi-oh-camera-camera-controlcenterstatusinfo.md) | Camera_ControlCenterStatusInfo | Describes the effect status information of a camera controller.|
| [Camera_OcclusionDetectionResult](capi-oh-camera-camera-occlusiondetectionresult.md) | Camera_OcclusionDetectionResult | Describes the check result for whether a camera lens is blocked or dirty.|
| [OH_Camera_ZoomRange](capi-oh-camera-oh-camera-zoomrange.md) | OH_Camera_ZoomRange | Describes the zoom range.|
| [OH_Camera_PhysicalAperture](capi-oh-camera-oh-camera-physicalaperture.md) | OH_Camera_PhysicalAperture | Describes the physical aperture configuration.|
| [OH_Camera_ZoomPointInfo](capi-oh-camera-oh-camera-zoompointinfo.md) | OH_Camera_ZoomPointInfo | Focus change information.|
| [OH_Camera_Rect_Ext](capi-oh-camera-oh-camera-rect-ext.md) | OH_Camera_Rect_Ext | Defines the rectangle.<br> The detection point must be in the coordinate system (0-1), where the top-left corner is (0, 0) and the bottom-right corner is (1, 1).<br> The coordinate system is based on the horizontal device direction with the device's charging port on the right.<br> If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the returned point is {x, y}, then the coordinate point after conversion is (1-y, x).|
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
| [OH_Camera_SensorColorFilterArrangement](#oh_camera_sensorcolorfilterarrangement) | OH_Camera_SensorColorFilterArrangement | Enumerates the arrangement modes of the color filter array of a sensor.|
| [Camera_Format](#camera_format) | Camera_Format | Enumerates the camera output formats.|
| [Camera_FlashMode](#camera_flashmode) | Camera_FlashMode | Enumerates the flash modes.|
| [OH_Camera_FlashState](#oh_camera_flashstate) | OH_Camera_FlashState | Enumerates the flash states.|
| [Camera_ExposureMode](#camera_exposuremode) | Camera_ExposureMode | Enumerates the exposure modes.|
| [OH_Camera_ExposureMeteringMode](#oh_camera_exposuremeteringmode) | OH_Camera_ExposureMeteringMode | Enumerates the exposure metering modes.|
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
| [OH_Camera_OISMode](#oh_camera_oismode) | OH_Camera_OISMode | Enumerates the optical image stabilization (OIS) modes.|
| [OH_Camera_OISAxes](#oh_camera_oisaxes) | OH_Camera_OISAxes | Enumerates the OIS axes.|
| [OH_Camera_ExposureState](#oh_camera_exposurestate) | OH_Camera_ExposureState | Enumerates the exposure states of the camera.|
| [OH_Camera_MetadataObjectEmotion](#oh_camera_metadataobjectemotion) | OH_Camera_MetadataObjectEmotion | Enumerates the metadata object emotion types.|

### Functions

| Name| Description|
| -- | -- |
| [Camera_ErrorCode OH_Camera_GetCameraManager(Camera_Manager** cameraManager)](#oh_camera_getcameramanager) | Obtains a Camera_Manager instance.|
| [Camera_ErrorCode OH_Camera_DeleteCameraManager(Camera_Manager* cameraManager)](#oh_camera_deletecameramanager) | Deletes a Camera_Manager instance.|

## Enum Description

### Camera_ErrorCode

```c
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
| CAMERA_ERROR_OPTIONAL_PROPERTY_NOT_EXIST = 7400113 | The optional attribute does not exist.<br>**Since:** 26.0.0 |
| CAMERA_SERVICE_FATAL_ERROR = 7400201 | The camera service is abnormal,<br> for example, no camera permission, camera service restart, or abnormal cross-process invocation.|
| CAMERA_ERROR_CAPABILITY_NOT_SUPPORTED = 7400114 | The device currently does not support this capability.<br>**Since:** 26.0.0 |

### Camera_Status

```c
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

```c
enum Camera_SceneMode
```

**Description**

Enumerates the camera scene modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| NORMAL_PHOTO = 1 | Normal photo mode.|
| NORMAL_VIDEO = 2 | Normal video mode.|
| SECURE_PHOTO = 12 | Secure mode, which is mainly provided for high-security applications like banking that require features such as biometric verification. The secure mode requires the encryption algorithm framework and trusted application services. For details, see [Device Certificate Kit](../../security/DeviceCertificateKit/device-certificate-kit-intro.md).|

### Camera_Position

```c
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

```c
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

```c
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

### OH_Camera_SensorColorFilterArrangement

```c
enum OH_Camera_SensorColorFilterArrangement
```

**Description**

Enumerates the arrangement modes of the color filter array of a sensor.

**Since**: 24

| Enum Item| Description|
| -- | -- |
| OH_CAMERA_SENSOR_CFA_BGGR = 0 | Blue-green-green-red (BGGR) color filter array arrangement.<br>**Since**: 24|
| OH_CAMERA_SENSOR_CFA_GBRG = 1 | Green-blue-red-green (GBRG) color filter array arrangement.<br>**Since**: 24|
| OH_CAMERA_SENSOR_CFA_GRBG = 2 | Green-red-blue-green (GRBG) color filter array arrangement.<br>**Since**: 24|
| OH_CAMERA_SENSOR_CFA_RGGB = 3 | Red-green-green-blue (RGGB) color filter array arrangement.<br>**Since**: 24|

### Camera_Format

```c
enum Camera_Format
```

**Description**

Enumerates the camera output formats.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CAMERA_FORMAT_RGBA_8888 = 3 | RGBA 8888.|
| CAMERA_FORMAT_DNG = 4 | DNG format.<br>**Since**: 24|
| CAMERA_FORMAT_DNG_XDRAW = 5 | Enhanced DNG format.<br>**Since**: 26.0.0|
| CAMERA_FORMAT_YUV_420_SP = 1003 | YUV 420 SP.|
| CAMERA_FORMAT_JPEG = 2000 | JPEG.|
| CAMERA_FORMAT_YCBCR_P010 = 2001 | YCBCR P010.<br>**Since**: 12|
| CAMERA_FORMAT_YCRCB_P010 = 2002 | YCRCB P010.<br>**Since**: 12|
| CAMERA_FORMAT_HEIC = 2003 | HEIC.<br>**Since:** 23 |

### Camera_FlashMode

```c
enum Camera_FlashMode
```

**Description**

Enumerates the flash modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| FLASH_MODE_CLOSE = 0 | The flash is off.|
| FLASH_MODE_OPEN = 1 | The flash is on.|
| FLASH_MODE_AUTO = 2 | Auto mode.|
| FLASH_MODE_ALWAYS_OPEN = 3 | The flash is steady on.|

### OH_Camera_FlashState

```c
enum OH_Camera_FlashState
```

**Description**

Enumerates the flash states.

**Since**: 24

| Enum Item| Description|
| -- | -- |
| OH_CAMERA_FLASH_STATE_UNAVAILABLE = 0 | The flash is unavailable. This is the default value.<br>**Since**: 24|
| OH_CAMERA_FLASH_STATE_READY = 1 | The flash is available.<br>**Since**: 24|
| OH_CAMERA_FLASH_STATE_FLASHING = 2 | The flash is turned on.<br>**Since**: 24|

### Camera_ExposureMode

```c
enum Camera_ExposureMode
```

**Description**

Enumerates the exposure modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| EXPOSURE_MODE_UNSPECIFIED = -1 | Unspecified exposure.<br>**Since**: 24|
| EXPOSURE_MODE_LOCKED = 0 | Exposure locked. The metering point cannot be set.<br>After this mode is used, the exposure will be locked by default for each photo capture.|
| EXPOSURE_MODE_AUTO = 1 | Auto exposure. The metering point can be set by calling [OH_CaptureSession_SetMeteringPoint](capi-capture-session-h.md#oh_capturesession_setmeteringpoint).<br>After this mode is used, it takes effect only for the first photo capture.|
| EXPOSURE_MODE_CONTINUOUS_AUTO = 2 | Continuous auto exposure.<br>After this mode is used, the camera system automatically adjusts the exposure based on the environment changes each time.|
| EXPOSURE_MODE_MANUAL = 3 | Manual exposure mode You can use the [OH_CaptureSession_SetExposureDuration](capi-capture-session-h.md#oh_capturesession_setexposureduration) API to set the exposure duration.<br>**Since**: 24|

### OH_Camera_ExposureMeteringMode

```c
enum OH_Camera_ExposureMeteringMode
```

**Description**

Enumerates the exposure metering modes.

**Since**: 24

| Enum Item| Description|
| -- | -- |
| OH_CAMERA_EXPOSURE_METERING_MODE_MATRIX = 0 | Matrix metering mode. Light is measured across the entire frame in this mode, which is ideal for shooting natural landscapes.<br>**Since**: 24|
| OH_CAMERA_EXPOSURE_METERING_MODE_CENTER = 1 | Center-weighted metering mode. The light near the center of the screen is concentrated on in this mode, which is ideal for shooting portraits.<br>**Since**: 24|
| OH_CAMERA_EXPOSURE_METERING_MODE_SPOT = 2 | Spot metering mode. The light in a specified small area is concentrated on in this mode, which is ideal for shooting details of the subject (such as eyes).<br>**Since**: 24|

### Camera_FocusMode

```c
enum Camera_FocusMode
```

**Description**

Enumerates the focus modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| FOCUS_MODE_MANUAL = 0 | Manual focus.|
| FOCUS_MODE_CONTINUOUS_AUTO = 1 | Continuous auto focus.|
| FOCUS_MODE_AUTO = 2 | Auto mode.|
| FOCUS_MODE_LOCKED = 3 | Focus locked.|

### Camera_FocusState

```c
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

```c
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

```c
enum Camera_ImageRotation
```

**Description**

Enumerates the image rotation angles.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| IAMGE_ROTATION_0 = 0 | The image rotates 0 degrees.<br> Since API version 23, you are advised to use the new enum value [CAMERA_IMAGE_ROTATION_0](capi-camera-h.md#camera_imagerotation) instead.|
| CAMERA_IMAGE_ROTATION_0 = 0 | The image rotates 0 degrees.<br>**Since**: 23|
| IAMGE_ROTATION_90 = 90 | The image rotates 90 degrees.<br> Since API version 23, you are advised to use the new enum value [CAMERA_IMAGE_ROTATION_90](capi-camera-h.md#camera_imagerotation) instead.|
| CAMERA_IMAGE_ROTATION_90 = 90 | The image rotates 90 degrees.<br>**Since**: 23|
| IAMGE_ROTATION_180 = 180 | The image rotates 180 degrees.<br> Since API version 23, you are advised to use the new enum value [CAMERA_IMAGE_ROTATION_180](capi-camera-h.md#camera_imagerotation) instead.|
| CAMERA_IMAGE_ROTATION_180 = 180 | The image rotates 180 degrees.<br>**Since**: 23|
| IAMGE_ROTATION_270 = 270 | The image rotates 270 degrees.<br> Since API version 23, you are advised to use the new enum value [CAMERA_IMAGE_ROTATION_270](capi-camera-h.md#camera_imagerotation) instead.|
| CAMERA_IMAGE_ROTATION_270 = 270 | The image rotates 270 degrees.<br>**Since**: 23|

### Camera_QualityLevel

```c
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

```c
enum Camera_MetadataObjectType
```

**Description**

Enumerates the metadata object types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| FACE_DETECTION = 0 | Metadata object used for face detection.<br> Since API version 23, you are advised to use the new enum value [CAMERA_METADATA_OBJECT_TYPE_FACE_DETECTION](capi-camera-h.md#camera_metadataobjecttype) instead.|
| CAMERA_METADATA_OBJECT_TYPE_FACE_DETECTION = 0 | Metadata object used for face detection.<br>**Since**: 23|
| CAMERA_METADATA_OBJECT_TYPE_HUMAN_BODY = 1 | Metadata object used for body detection.<br>**Since**: 23|
| CAMERA_METADATA_OBJECT_TYPE_CAT_FACE = 2 | Metadata object used for cat face detection.<br>**Since:** 26.0.0 |
| CAMERA_METADATA_OBJECT_TYPE_CAT_BODY = 3 | Metadata object used for cat body detection.<br>**Since:** 26.0.0 |
| CAMERA_METADATA_OBJECT_TYPE_DOG_FACE = 4 | Metadata object used for dog face detection.<br>**Since:** 26.0.0 |
| CAMERA_METADATA_OBJECT_TYPE_DOG_BODY = 5 | Metadata object used for dog body detection.<br>**Since:** 26.0.0 |
| CAMERA_METADATA_OBJECT_TYPE_SALIENT_DETECTION = 6 | Metadata object used for salient object detection.<br>**Since:** 26.0.0 |
| CAMERA_METADATA_OBJECT_TYPE_BAR_CODE_DETECTION = 7 | Metadata object used for QR code detection.<br>**Since:** 26.0.0 |
| CAMERA_METADATA_OBJECT_TYPE_BASIC_FACE_DETECTION = 8 | Metadata object used for basic face detection.<br>**Since:** 26.0.0 |

### Camera_TorchMode

```c
enum Camera_TorchMode
```

**Description**

Enumerates the flashlight modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OFF = 0 | The flashlight is always off.<br> Since API version 23, you are advised to use the new enum value [CAMERA_TORCH_MODE_OFF](capi-camera-h.md#camera_torchmode) instead.|
| CAMERA_TORCH_MODE_OFF = 0 | The flashlight is always off.<br>**Since**: 23|
| ON = 1 | The flashlight is always on.<br> Since API version 23, you are advised to use the new enum value [CAMERA_TORCH_MODE_ON](capi-camera-h.md#camera_torchmode) instead.|
| CAMERA_TORCH_MODE_ON = 1 | The flashlight is always on.<br>**Since**: 23|
| AUTO = 2 | The flashlight will be turned on automatically based on the ambient lighting level.<br> Since API version 23, you are advised to use the new enum value [CAMERA_TORCH_MODE_AUTO](capi-camera-h.md#camera_torchmode) instead.|
| CAMERA_TORCH_MODE_AUTO = 2 | The flashlight will be turned on automatically based on the ambient lighting level.<br>**Since**: 23|

### Camera_SmoothZoomMode

```c
enum Camera_SmoothZoomMode
```

**Description**

Enumerates the smooth zoom modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| NORMAL = 0 | Bessel curve mode.<br> Since API version 23, you are advised to use the new enum value [CAMERA_SMOOTH_ZOOM_MODE_NORMAL](capi-camera-h.md#camera_smoothzoommode) instead.|
| CAMERA_SMOOTH_ZOOM_MODE_NORMAL = 0 | Bessel curve mode.<br>**Since**: 23|

### Camera_SystemPressureLevel

```c
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

```c
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
| PRECONFIG_HIGH_QUALITY_PHOTOSESSION_BT2020 = 4 | Resolution that supports HDR preview and GIF photography.<br>**Since**: 23|

### Camera_PreconfigRatio

```c
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

```c
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

```c
enum Camera_FoldStatus
```

**Description**

Enumerates the fold statuses.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| NON_FOLDABLE = 0 | Unfoldable.<br> Since API version 23, you are advised to use the new enum value [CAMERA_FOLD_STATUS_NON_FOLDABLE](capi-camera-h.md#camera_foldstatus) instead.|
| CAMERA_FOLD_STATUS_NON_FOLDABLE = 0 | Unfoldable.<br>**Since**: 23|
| EXPANDED = 1 | Unfolded.<br> Since API version 23, you are advised to use the new enum value [CAMERA_FOLD_STATUS_EXPANDED](capi-camera-h.md#camera_foldstatus) instead.|
| CAMERA_FOLD_STATUS_EXPANDED = 1 | Unfolded.<br>**Since**: 23|
| FOLDED = 2 | Folded.<br> Since API version 23, you are advised to use the new enum value [CAMERA_FOLD_STATUS_FOLDED](capi-camera-h.md#camera_foldstatus) instead.|
| CAMERA_FOLD_STATUS_FOLDED = 2 | Folded.<br>**Since**: 23|

### Camera_QualityPrioritization

```c
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

```c
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

```c
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

```c
enum Camera_ControlCenterEffectType
```

**Description**

Enumerates the effect types of a camera controller.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| CONTROL_CENTER_EFFECT_TYPE_BEAUTY = 0 | Beauty effect.|
| CONTROL_CENTER_EFFECT_TYPE_PORTRAIT = 1 | Portrait blur effect.|
| CONTROL_CENTER_EFFECT_TYPE_AUTO_FRAMING = 2 | Auto focus effect.<br>**Since**: 24|
| CONTROL_CENTER_EFFECT_TYPE_COLOR_EFFECT = 3 | Effect types of a camera controller, which is the XMAGE style.<br>**Since**: 26.0.0|

### Camera_PhotoQualityPrioritization

```c
enum Camera_PhotoQualityPrioritization
```

**Description**

Enumerates the photo quality prioritization strategies.

**Since**: 21

| Enum Item| Description|
| -- | -- |
| CAMERA_PHOTO_QUALITY_PRIORITIZATION_HIGH_QUALITY = 0 | Focuses on image quality, which may increase the time required for capturing photos to ensure high-quality output.|
| CAMERA_PHOTO_QUALITY_PRIORITIZATION_SPEED = 1 | Focuses on performance, trading off image quality for faster capture times.|

### OH_Camera_OISMode

```c
enum OH_Camera_OISMode
```

**Description**

Enumerates the optical image stabilization (OIS) modes.

**Since**: 24

| Enum Item| Description|
| -- | -- |
| OH_CAMERA_OIS_MODE_OFF = 0 | OIS mode disabled.|
| OH_CAMERA_OIS_MODE_AUTO = 1 | Auto OIS mode.|
| OH_CAMERA_OIS_MODE_CUSTOM = 2 | Manual OIS mode.|

### OH_Camera_OISAxes

```c
enum OH_Camera_OISAxes
```

**Description**

Enumerates the OIS axes.

**Since**: 24

| Enum Item| Description|
| -- | -- |
| OH_CAMERA_OIS_AXES_PITCH = 0 | Pitch axis: controls the up-down rotation of the camera body, that is, the camera body rotates around the axis horizontal to the lens.|
| OH_CAMERA_OIS_AXES_YAW = 1 | Yaw axis: controls the left-right rotation of the camera body, that is, the camera body rotates around the axis perpendicular to the lens.|

### OH_Camera_ExposureState

```c
enum OH_Camera_ExposureState
```

**Description**

Enumerates the exposure states of the camera.

**Since**: 26.0.0

| Enum Item| Description|
| -- | -- |
| OH_CAMERA_EXPOSURE_STATE_SCAN = 0 | Focusing.<br>**Since**: 26.0.0|
| OH_CAMERA_EXPOSURE_STATE_CONVERGED = 1 | Exposure converged.<br>**Since**: 26.0.0|

### OH_Camera_MetadataObjectEmotion

```c
enum OH_Camera_MetadataObjectEmotion
```

**Description**

Enumerates the metadata object emotion types.

**Since**: 26.0.0

| Enum Item| Description|
| -- | -- |
| OH_CAMERA_METADATA_OBJECT_EMOTION_NEUTRAL = 0 | Neutral.<br>**Since**: 26.0.0|
| OH_CAMERA_METADATA_OBJECT_EMOTION_SADNESS = 1 | Sad.<br>**Since**: 26.0.0|
| OH_CAMERA_METADATA_OBJECT_EMOTION_SMILE = 2 | Smile.<br>**Since**: 26.0.0|
| OH_CAMERA_METADATA_OBJECT_EMOTION_SURPRISE = 3 | Surprise.<br>**Since**: 26.0.0|

### OH_Camera_AutomotiveCameraPosition

```c
enum OH_Camera_AutomotiveCameraPosition
```

**Description**

Enumerates the camera positions on a car.

**Since**: 26.0.0

| Value | Description |
| -- | -- |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_OTHER = 0 | Camera at another position outside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_FRONT = 1 | Front camera outside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_REAR = 2 | Rear camera outside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_LEFT = 3 | Left camera outside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_EXTERIOR_RIGHT = 4 | Right camera outside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_OTHER = 5 | Camera at another position inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_1_LEFT = 6 | Left camera in the first row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_1_CENTER = 7 | Central camera in the first row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_1_RIGHT = 8 | Right camera in the first row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_2_LEFT = 9 | Left camera in the second row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_2_CENTER = 10 | Central camera in the second row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_2_RIGHT = 11 | Right camera in the second row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_3_LEFT = 12 | Left camera in the third row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_3_CENTER = 13 | Central camera in the third row inside the car.<br>**Since:** 26.0.0 |
| OH_CAMERA_AUTOMOTIVE_CAMERA_POSITION_INTERIOR_ROW_3_RIGHT = 14 | Right camera in the third row inside the car.<br>**Since:** 26.0.0 |

## Function Description

### OH_Camera_GetCameraManager()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|

### OH_Camera_DeleteCameraManager()

```c
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
| [Camera_ErrorCode](capi-camera-h.md#camera_errorcode) | **CAMERA_OK**: The operation is successful.<br>         **CAMERA_INVALID_ARGUMENT**: A parameter is missing or the parameter type is incorrect.<br>         **CAMERA_SERVICE_FATAL_ERROR**: The camera service is abnormal.|