# Enums
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CameraPosition

Enumerates the camera positions.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Value  | Description                                                             |
| --------------------------- | ---- |-----------------------------------------------------------------|
| CAMERA_POSITION_UNSPECIFIED | 0    | A camera that does not have a fixed orientation relative to the device screen.                                                       |
| CAMERA_POSITION_BACK        | 1    | Rear camera.                                                          |
| CAMERA_POSITION_FRONT       | 2    | Front camera.                                                          |
| CAMERA_POSITION_FOLD_INNER<sup>(deprecated)</sup>  | 3    | Folded camera.<br> This API is supported since API version 11 and deprecated since API version 12.|

## CameraType

Enumerates the camera types.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value  | Description           |
| ----------------------- | ---- | -------------- |
| CAMERA_TYPE_DEFAULT     | 0    | Default camera type. |
| CAMERA_TYPE_WIDE_ANGLE  | 1    | Wide camera.      |
| CAMERA_TYPE_ULTRA_WIDE  | 2    | Ultra-wide camera.    |
| CAMERA_TYPE_TELEPHOTO   | 3    | Telephoto camera.      |
| CAMERA_TYPE_TRUE_DEPTH  | 4    | Camera with depth of field information.|

## ConnectionType

Enumerates the camera connection types.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value  | Description          |
| ---------------------------- | ---- | ------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0    | Built-in camera.     |
| CAMERA_CONNECTION_USB_PLUGIN | 1    | Camera connected using USB.|
| CAMERA_CONNECTION_REMOTE     | 2    | Remote camera.|

## HostDeviceType<sup>15+</sup>

Enumerates the remote camera types.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value      | Description     |
| ---------------------------- | ----     |---------|
| UNKNOWN_TYPE                 | 0        | Unknown type.|
| PHONE                        | 0x0E     | Mobile phone.  |
| TABLET                       | 0x11     | Tablet.  |

## CameraStatus

Enumerates the camera statuses.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | A camera appears.  |
| CAMERA_STATUS_DISAPPEAR   | 1    | The camera disappears.    |
| CAMERA_STATUS_AVAILABLE   | 2    | The camera is available.      |
| CAMERA_STATUS_UNAVAILABLE | 3    | The camera is unavailable.    |

## FoldStatus<sup>12+</sup>

Enumerates the fold states available for a fordable device.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| NON_FOLDABLE      | 0    | The device is not foldable.  |
| EXPANDED   | 1    | The device is fully unfolded.|
| FOLDED   | 2    | The device is folded.      |

## SceneMode<sup>11+</sup>

Enumerates the camera scene modes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Value      | Description                                         |
|----------------------------|---------|---------------------------------------------|
| NORMAL_PHOTO               | 1       | Normal photo mode. For details, see [PhotoSession](arkts-apis-camera-PhotoSession.md).  |
| NORMAL_VIDEO               | 2       | Normal record mode. For details, see [VideoSession](arkts-apis-camera-VideoSession.md).  |
| SECURE_PHOTO<sup>12+</sup> | 12      | Secure mode. For details, see [SecureSession](arkts-apis-camera-SecureSession.md).|

## CameraErrorCode

Enumerates the camera error codes,

which are returned when an API call is incorrect or the **on()** API is used to listen for the error status.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value         | Description           |
| -------------------------  | ----       | ------------    |
| INVALID_ARGUMENT           | 7400101    | A parameter is missing or the parameter type is incorrect.  |
| OPERATION_NOT_ALLOWED      | 7400102    | The operation is not allowed.    |
| SESSION_NOT_CONFIG         | 7400103    | The session is not configured.      |
| SESSION_NOT_RUNNING        | 7400104    | The session is not running.   |
| SESSION_CONFIG_LOCKED      | 7400105    | The session configuration is locked.    |
| DEVICE_SETTING_LOCKED      | 7400106    | The device setting is locked.    |
| CONFLICT_CAMERA            | 7400107    | The device is already started.    |
| DEVICE_DISABLED            | 7400108    | The camera is disabled for security reasons.    |
| DEVICE_PREEMPTED           | 7400109    | The camera is preempted.    |
| UNRESOLVED_CONFLICTS_WITH_CURRENT_CONFIGURATIONS<sup>12+</sup> | 7400110   | The configuration conflicts with the current configuration.    |
| SERVICE_FATAL_ERROR        | 7400201    | An error occurs in the camera service.    |

## TorchMode<sup>11+</sup>

Enumerates the flashlight modes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value  | Description          |
| ---------------------------- | ---- | ------------- |
| OFF    | 0    | The flashlight is off.     |
| ON  | 1    | The flashlight is on.|
| AUTO      | 2    | The system automatically adjusts the flashlight brightness according to the environment.|

## CameraFormat

Enumerates the camera output formats.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGBA_8888 image.       |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV_420_SP image, which corresponds to the NV21 image.     |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG image.           |
| CAMERA_FORMAT_YCBCR_P010<sup>11+</sup> |   2001    | YCBCR_P010 image.     |
| CAMERA_FORMAT_YCRCB_P010<sup>11+</sup> |   2002    | YCRCB_P010 image.     |
| CAMERA_FORMAT_HEIC<sup>13+</sup>       |   2003    | HEIF image.           |

## VideoCodecType<sup>13+</sup>

Enumerates the video codec types.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Value   | Description         |
|------|------|-------------|
| AVC  | 0    | AVC.|
| HEVC | 1 | HEVC.|

## CameraConcurrentType<sup>18+</sup>

Enumerates the camera concurrency types.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Value   | Description         |
|------|------|-------------|
| CAMERA_LIMITED_CAPABILITY  | 0 | Limited camera concurrency. |
| CAMERA_FULL_CAPABILITY     | 1 | Full camera concurrency.|

## ImageRotation

Enumerates the image rotation angles.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Value  | Description          |
| ------------ | ---- | ------------- |
| ROTATION_0   | 0    | The image rotates 0 degrees.  |
| ROTATION_90  | 90   | The image rotates 90 degrees. |
| ROTATION_180 | 180  | The image rotates 180 degrees.|
| ROTATION_270 | 270  | The image rotates 270 degrees.|

## QualityLevel

Enumerates the image quality levels.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                 | Value  | Description        |
| -------------------- | ---- | ------------ |
| QUALITY_LEVEL_HIGH   | 0    | High image quality.  |
| QUALITY_LEVEL_MEDIUM | 1    | Medium image quality.|
| QUALITY_LEVEL_LOW    | 2    | Low image quality.  |

## MetadataObjectType

Enumerates the metadata object types.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description             |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | Metadata object used for face detection.|

## FlashMode

Enumerates the flash modes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Value  | Description       |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | The flash is off.|
| FLASH_MODE_OPEN        | 1    | The flash is on.|
| FLASH_MODE_AUTO        | 2    | The flash mode is auto, indicating that the flash fires automatically depending on the photo capture conditions.|
| FLASH_MODE_ALWAYS_OPEN | 3    | The flash is steady on.|

## ExposureMode

Enumerates the exposure modes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_LOCKED          | 0    | Exposure locked. The metering point cannot be set.|
| EXPOSURE_MODE_AUTO            | 1    | Auto exposure. The metering point can be set by calling [AutoExposure.setMeteringPoint](arkts-apis-camera-AutoExposure.md#setmeteringpoint11).|
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | Continuous auto exposure. The metering point cannot be set.|

## FocusMode

Enumerates the focus modes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                       | Value  | Description         |
| -------------------------- | ---- | ------------ |
| FOCUS_MODE_MANUAL          | 0    | Manual focus. The focal length of the camera can be manually set to change the focus position. However, the focal point cannot be set.    |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | Continuous auto focus. The focal point cannot be set.|
| FOCUS_MODE_AUTO            | 2    | Auto focus. The focal point can be set by calling [Focus.setFocusPoint](arkts-apis-camera-Focus.md#setfocuspoint11), and auto focus is performed once based on the focal point.   |
| FOCUS_MODE_LOCKED          | 3    | Focus locked. The focal point cannot be set.    |

## FocusState

Enumerates the focus states.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Value  | Description      |
| --------------------- | ---- | --------- |
| FOCUS_STATE_SCAN      | 0    | Focusing. |
| FOCUS_STATE_FOCUSED   | 1    | Focused. |
| FOCUS_STATE_UNFOCUSED | 2    | Unfocused.|

## VideoStabilizationMode

Enumerates the video stabilization modes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Value  | Description        |
| --------- | ---- | ------------ |
| OFF       | 0    | Video stabilization is disabled.  |
| LOW       | 1    | The basic video stabilization algorithm is used.  |
| MIDDLE    | 2    | A video stabilization algorithm with a stabilization effect better than that of the **LOW** type is used.  |
| HIGH      | 3    | A video stabilization algorithm with a stabilization effect better than that of the **MIDDLE** type is used.  |
| AUTO      | 4    | The system automatically selects a video stabilization algorithm.  |

## SmoothZoomMode<sup>11+</sup>

Enumerates the smooth zoom modes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Value  | Description           |
| ------------ | ---- | -------------- |
| NORMAL       | 0    | Bessel curve mode. |

## PreconfigType<sup>12+</sup>

Enumerates the preconfigured resolution types.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                     | Value| Description        |
|-------------------------|---|------------|
| PRECONFIG_720P          | 0 | 720p resolution.  |
| PRECONFIG_1080P         | 1 | 1080p resolution. |
| PRECONFIG_4K            | 2 | 4K resolution.    |
| PRECONFIG_HIGH_QUALITY  | 3 | High-quality resolution.   |

## PreconfigRatio<sup>12+</sup>

Enumerates the preconfigured aspect ratios.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value| Description     |
|--------------------------|---|---------|
| PRECONFIG_RATIO_1_1      | 0 | 1:1 aspect ratio. |
| PRECONFIG_RATIO_4_3      | 1 | 4:3 aspect ratio. |
| PRECONFIG_RATIO_16_9     | 2 | 16:9 aspect ratio.|

## QualityPrioritization<sup>14+</sup>

Enumerates the priority levels for video recording quality.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Value | Description      |
| ------------- | --- | ---------- |
| HIGH_QUALITY  | 0   | Prioritizes high-quality video recording.  |
| POWER_BALANCE | 1   | Prioritizes video recording quality while balancing power consumption.|

## WhiteBalanceMode<sup>20+</sup>

Enumerates the white balance modes.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value| Description        |
|----------------|---| ----------- |
| AUTO           | 0 | Automatic.|
| CLOUDY         | 1 | Cloudy.|
| INCANDESCENT   | 2 | Incandescent light.|
| FLUORESCENT    | 3 | Fluorescence light.|
| DAYLIGHT       | 4 | Daylight.|
| MANUAL         | 5 | Manual.|
| LOCKED         | 6 | Locked. |

## SystemPressureLevel<sup>20+</sup>

Enumerates the system pressure levels.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value| Description      | 
|--------------------------|---|------------|
| SYSTEM_PRESSURE_NORMAL   | 0 | The system pressure is normal.|
| SYSTEM_PRESSURE_MILD     | 1 | The system pressure is elevated but not actively managed by the system.|
| SYSTEM_PRESSURE_SEVERE   | 2 | The system pressure may affect the overall image quality and performance.|
| SYSTEM_PRESSURE_CRITICAL | 3 | The system pressure has a significant impact on the image quality and performance.|
| SYSTEM_PRESSURE_SHUTDOWN | 4 | The system pressure is too high, causing the system to shut down.|

## ControlCenterEffectType<sup>20+</sup>

Enumerates the effect types supported by the camera controller.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Value| Description   |
|-----------|---|---------|
| BEAUTY    | 0 | Beauty effect.  |
| PORTRAIT  | 1 | Portrait blur effect.|

## PhotoQualityPrioritization<sup>21+</sup>

Enumerates the photo quality prioritization strategies.

**Atomic service API**: This API can be used in atomic services since API version 21.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Value    | Description   |
|--------------|-------|---------|
| HIGH_QUALITY | 0     | Focuses on image quality, which may increase the time required for capturing photos to ensure high-quality output.|
| SPEED        | 1     | Focuses on performance, trading off image quality for faster capture times.|
