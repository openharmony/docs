# Interfaces (Others)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-11T02:00:32.060Z pushedAt=2026-08-11T10:58:37.303Z -->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CameraDevice

Describes the camera device information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                             | Type                                 | Read-only| Optional| Description       |
|---------------------------------|-------------------------------------| ---- |----|---------- |
| cameraId                        | string                              | Yes  | No | Camera ID.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| cameraPosition                  | [CameraPosition](arkts-apis-camera-e.md#cameraposition)   | Yes  | No | Camera position.<br>**Atomic service API**: This API can be used in atomic services since API version 19.   |
| cameraType                      | [CameraType](arkts-apis-camera-e.md#cameratype)           | Yes  | No | Camera type.<br>**Atomic service API**: This API can be used in atomic services since API version 19.   |
| connectionType                  | [ConnectionType](arkts-apis-camera-e.md#connectiontype)   | Yes  | No | Camera connection type.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| cameraOrientation<sup>12+</sup> | number                              | Yes  | No | Camera installation angle, which does not change as the screen rotates. The value range is [0, 360], in degrees.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| hostDeviceName<sup>15+</sup>    | string                              | Yes  | No | Remote device name. If no remote device is available, an empty value is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| hostDeviceType<sup>15+</sup>    | [HostDeviceType](arkts-apis-camera-e.md#hostdevicetype15) | Yes  | No | Remote device type.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| lensEquivalentFocalLength<sup>24+</sup> | Array\<number\> | Yes| Yes| Equivalent focal length of the camera lens.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| isLogicalCamera<sup>24+</sup> | boolean | Yes| Yes| Whether a camera is a logical camera (consisting of multiple physical cameras). **true** if the camera is a logical camera, **false** otherwise.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| constituentCameraDevices<sup>24+</sup> | Array\<[CameraDevice](arkts-apis-camera-i.md#cameradevice)\> | Yes| Yes| List of physical cameras that form the logical camera.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| lensFocalLength<sup>24+</sup> | number | Yes| Yes| Actual focal length of the lens.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| minimumFocusDistance<sup>24+</sup> | number | Yes| Yes| Minimum focus distance of the camera.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| lensDistortion<sup>24+</sup> | Array\<number\> | Yes| Yes| Array of lens distortion parameters.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| lensIntrinsicCalibration<sup>24+</sup> | Array\<number\> | Yes| Yes| Array of lens intrinsic calibration parameters.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| sensorPhysicalSize<sup>24+</sup> | Array\<number\> | Yes| Yes| Physical dimensions (width and height) of the sensor.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| sensorPixelArraySize<sup>24+</sup> | Array\<number\> | Yes| Yes| Pixel array dimensions (width and height, in pixels) of the sensor.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| sensorColorFilterArrangement<sup>24+</sup> | [SensorColorFilterArrangement](arkts-apis-camera-e.md#sensorcolorfilterarrangement24) | Yes| Yes| Arrangement mode of the sensor color filter.<br>**Model constraint**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 24.|
| automotiveCameraPosition | [AutomotiveCameraPosition](arkts-apis-camera-e.md#automotivecameraposition) | Yes | Yes | Camera position on a car.<br>**Since:** 26.0.0<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0. |

## CameraStatusInfo

Describes the camera status information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                          |    Read-only  |     Optional    | Description      |
| ------ | ----------------------------- | --------- |------------ | ---------- |
| camera | [CameraDevice](arkts-apis-camera-i.md#cameradevice) |     No   |       No    | Camera device.|
| status | [CameraStatus](arkts-apis-camera-e.md#camerastatus) |     No   |       No    | Camera status.|

## FoldStatusInfo<sup>12+</sup>

Describes the fold state information about a foldable device.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                          |    Read-only  |     Optional    | Description      |
| ------ | ----------------------------- | --------- |------------ | ---------- |
| supportedCameras | [Array<CameraDevice\>](arkts-apis-camera-i.md#cameradevice) |     Yes   |       No    | List of cameras supported in the current fold state.|
| foldStatus | [FoldStatus](arkts-apis-camera-e.md#foldstatus12) |     Yes   |       No    | Fold state.|

## Profile

Describes the camera profile.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description        |
| -------- | ----------------------------- |---- | ---- | ------------- |
| format   | [CameraFormat](arkts-apis-camera-e.md#cameraformat) | Yes |  No | Output format.     |
| size     | [Size](#size)                 | Yes |  No | Resolution.<br>The size setting corresponds to the camera's resolution width and height, rather than the actual dimensions of the output image. |

## FrameRateRange

Describes the frame rate range.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description           |
| -------- | ----------------------------- |----- |---| -------------- |
| min      | number                        |  Yes | No| Minimum frame rate. Unit: FPS     |
| max      | number                        |  Yes | No| Maximum frame rate. Unit: FPS     |

## VideoProfile

Describes the video configuration information. It inherits from [Profile](#profile).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Read-only| Optional| Description       |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| frameRateRange            | [FrameRateRange](arkts-apis-camera-i.md#frameraterange)         | Yes |  No | Describes the frame rate range. Unit: FPS|

## CameraOutputCapability

Describes the camera output capability.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Type                                               | Read-only| Optional| Description               |
| ----------------------------- | --------------------------------------------------- | ---- | ---- |-------------------|
| previewProfiles               | Array\<[Profile](#profile)\>                        |  Yes | No| Supported preview profiles.     |
| photoProfiles                 | Array\<[Profile](#profile)\>                        |  Yes | No| Supported photo profiles.       |
| videoProfiles                 | Array\<[VideoProfile](#videoprofile)\>              |  Yes | No| Supported video profiles.       |
| supportedMetadataObjectTypes  | Array\<[MetadataObjectType](arkts-apis-camera-e.md#metadataobjecttype)\>  |  Yes | No| Supported metadata object types.|

## TorchStatusInfo<sup>11+</sup>

Describes the flashlight status information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name             | Type      | Read-only| Optional| Description       |
| ---------------- | ---------- | ---- | ---- | ----------- |
| isTorchAvailable | boolean    | Yes  | No  | Whether the flashlight is available. **true** if available, **false** otherwise.|
| isTorchActive    | boolean    | Yes  | No  | Whether the flashlight is activated. **true** if activated, **false** otherwise.|
| torchLevel       | number     | Yes  | No  | Flashlight brightness level. The value range is [0, 1]. A larger value indicates a greater luminance. |

## Size

Describes the image dimensions.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type   | Read-only| Optional | Description        |
| ------ | ------ | ---- |-----| ------------ |
| height | number | No  | No  | Image height, in pixels.|
| width  | number | No  | No  | Image width, in pixels.|

## Point

Describes the point coordinates, which are used for focus and exposure configuration.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name   | Type  | Read-only  | Optional  | Description        |
| ------ | ------ | ------ | ------ | ------------ |
| x      | number | No    | No    | X coordinate of a point.  |
| y      | number | No    | No    | Y coordinate of a point.  |

## CameraConcurrentInfo<sup>18+</sup>

Describes the camera's concurrency information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type   | Read-only| Optional | Description        |
| ------ | ------ |----|-----| ------------ |
| device              | [CameraDevice](arkts-apis-camera-i.md#cameradevice)   | Yes | No  | Concurrent camera device.|
| type                | [CameraConcurrentType](arkts-apis-camera-e.md#cameraconcurrenttype18)  | Yes | No  | Concurrency type.|
| modes               | Array\<[SceneMode](arkts-apis-camera-e.md#scenemode11) \>              | Yes | No  | Scene mode.|
| outputCapabilities  | Array\<[CameraOutputCapability](#cameraoutputcapability) \> | Yes | No  | Output capabilities of the camera.|

## Location

Describes the geolocation information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Type  | Read-only| Optional |Description        |
| ------------ | ------ | ---- |-----|------------ |
| latitude     | number |  No | No  |Latitude, in degrees, within the range [–90, 90].   |
| longitude    | number |  No | No  |Longitude, in degrees, within the range [–180, 180].   |
| altitude     | number |  No | No  |Altitude, in meters.   |

## PhotoCaptureSetting

Describes the settings for taking an image.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type                            | Read-Only | Optional | Description                                                                   |
| -------- | ------------------------------- | ---- | ---- |----------------------------------------------------------------------|
| quality  | [QualityLevel](arkts-apis-camera-e.md#qualitylevel)   | No   | Yes   | Image quality.<br>If **quality** is not specified, the value of **compressionQuality** is used for image quality by default. If both **quality** and **compressionQuality** are specified, the value of **compressionQuality** is used for image quality. If neither **quality** nor **compressionQuality** is specified, the image quality is high by default.                                                           |
| rotation | [ImageRotation](arkts-apis-camera-e.md#imagerotation) | No   | Yes   | Rotation angle of the image. The default value is **0**, indicating clockwise rotation.                                                  |
| location | [Location](#location)           | No   | Yes   | Geolocation information of the image (depending on the device hardware information by default).                                               |
| mirror   | boolean                         | No   | Yes   | Whether mirror photography is enabled (disabled by default). Before using this enumerated value, call [isMirrorSupported](arkts-apis-camera-PhotoOutput.md#ismirrorsupported) to check whether mirror photography is supported. The value **true** indicates mirror photography is enabled, and the value **false** indicates it is disabled. |
| compressionQuality   | number                         | No   | Yes   |  Compression quality of the image. The value range is (1, 100).<br>If **compressionQuality** is not specified, the value of **quality** is used for the compression quality of the image. If both **quality** and **compressionQuality** are specified, the value of **compressionQuality** is used for the compression quality. If neither **quality** nor **compressionQuality** is specified, the compression quality is high by default.<br> **Since:** 26.0.0<br> **Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.   |

## FrameShutterInfo

Describes the frame shutter information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type  | Read-only| Optional| Description       |
| --------- | ------ | ---- | ---- | ---------- |
| captureId | number | No  | No  | ID of this capture action.|
| timestamp | number | No  | No  | Timestamp when the frame shutter event is triggered, in milliseconds.|

## FrameShutterEndInfo<sup>12+</sup>

Describes the frame shutter end information during capture.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  | Read-only| Optional| Description      |
| --------- | ------ | ---- | ---- | ---------- |
| captureId | number | No  | No  | ID of this capture action.|

## CaptureStartInfo<sup>11+</sup>

Describes the capture start information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type   | Read-only| Optional| Description      |
| ---------- | ------ | ---- | ---- | --------- |
| captureId  | number | No  | No  | ID of this capture action.|
| time       | number | No  | No  | Estimated duration when the sensor captures frames at the bottom layer in a single capture. If **-1** is reported, there is no estimated duration.   |

## CaptureEndInfo

Describes the capture end information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type   | Read-only| Optional| Description      |
| ---------- | ------ | ---- | ---- | ---------|
| captureId  | number | No  | No  | ID of this capture action.|
| frameCount | number | No  | No  | Number of frames captured.|

## AutoDeviceSwitchStatus<sup>13+</sup>

Describes the information about the automatic camera switch status.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type     | Read-only| Optional| Description                     |
| ---------- |---------| ---- | ---- |-------------------------|
| isDeviceSwitched  | boolean | Yes  | No  | Whether the camera is automatically switched. **true** if auto-switched, **false** otherwise.      |
| isDeviceCapabilityChanged | boolean  | Yes  | No  | Whether the camera capability is changed after the camera is automatically switched. **true** if changed, **false** otherwise.|

## Rect

Defines a camera rectangle. This method is used to draw rectangles for various detection objects. The coordinate system for the returned detection points is based on the landscape device orientation, with the charging port on the right. In this coordinate system, the top-left corner is (0, 0), and the bottom-right corner is (1, 1). Here, **topLeftX** and **topLeftY** represent the coordinates of the top-left corner of the rectangle, whereas **width** and **height** represent the width and height of the rectangle, respectively. When cropping or selecting a face region based on specific requirements, the x and y coordinates of the rectangle must be multiplied by the width and height of the actual camera preview output stream to obtain the cropped face region.

The width and height of the actual preview stream refer to the resolution of the camera output stream. For details, see **size** in [profile](arkts-apis-camera-i.md#profile).

For details about how to obtain the preview stream data, see [Dual-Channel Preview (ArkTS)](../../media/camera/camera-dual-channel-preview.md).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  |  Read-only | Optional |           Description        |
| -------- | ------ | ------ |-----| --------------------- |
| topLeftX | number |   No  | No  | X coordinate of the top-left corner of the rectangle, in the range of [0, 1].  |
| topLeftY | number |   No  | No  | Y coordinate of the top-left corner of the rectangle, in the range of [0, 1].  |
| width    | number |   No  | No  | Width of the rectangle, in the range of [0, 1]. |
| height   | number |   No  | No  | Height of the rectangle, in the range of [0, 1]. |

## MetadataObject

Describes the camera metadata, which is the data source of [CameraInput](arkts-apis-camera-CameraInput.md). The metadata is obtained through **metadataOutput.on('metadataObjectsAvailable')**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Type                                       | Read-only| Optional|Description               |
| ----------- | ------------------------------------------- | ---- | ---- | ----------------- |
| type        | [MetadataObjectType](arkts-apis-camera-e.md#metadataobjecttype)   |  Yes |  No | Metadata object type.   |
| timestamp   | number                                      |  Yes |  No | Timestamp, in ns.|
| boundingBox | [Rect](#rect)                               |  Yes |  No | Metadata rectangle. |
| isLockFocusTracked | boolean                              |  Yes  |  Yes  | Whether focus tracking is locked. The value **true** indicates that it is locked, and the value **false** indicates that it is not locked.<br>**Since:** 26.0.0<br> **Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.  |

## MetadataBasicFaceObject

Basic face metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Type                             | Read-only| Optional|Description               |
| ---------------------- | --------------------------------- | ---- | ---- | --------------------- |
| leftEyeBoundingBox     | [Rect](#rect)                             |  Yes |  Yes | Left eye area.|
| rightEyeBoundingBox    | [Rect](#rect)                            |  Yes |  Yes | Right eye area.|
| pitchAngle             | number                            |  Yes |  Yes | Pitch angle. The value range is [-90, 90], with the positive direction being downwards.|
| yawAngle               | number                            |  Yes |  Yes | Yaw angle. The value range is [-90, 90], with the positive direction being rightwards.|
| rollAngle              | number                            |  Yes |  Yes | Roll angle. The value range is [-180, 180], with the positive direction being clockwise.|

## MetadataFaceObject

Face metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Type                             | Read-only| Optional|Description               |
| ---------------------- | --------------------------------- | ---- | ---- | --------------------- |
| leftEyeBoundingBox     | [Rect](#rect)                             |  Yes |  No | Left eye area.|
| rightEyeBoundingBox    | [Rect](#rect)                            |  Yes |  No | Right eye area.|
| emotion                | [Emotion](arkts-apis-camera-e.md#emotion)             |  Yes |  No | Detected emotion.|
| emotionConfidence      | number                            |  Yes |  No | Emotion detection confidence. The value range is [0, 1].|
| pitchAngle             | number                            |  Yes |  No | Pitch angle. The value range is [-90, 90], with the positive direction being downwards.|
| yawAngle               | number                            |  Yes |  No | Yaw angle. The value range is [-90, 90], with the positive direction being rightwards.|
| rollAngle              | number                            |  Yes |  No | Roll angle. The value range is [-180, 180], with the positive direction being clockwise.|

## MetadataHumanBodyObject

Human body metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

## MetadataCatFaceObject

Cat face metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Type                             | Read-only| Optional|Description               |
| ---------------------- | --------------------------------- | ---- | ---- | --------------------- |
| leftEyeBoundingBox     | [Rect](#rect)                              |  Yes |  No | Left eye area.|
| rightEyeBoundingBox    | [Rect](#rect)                              |  Yes |  No | Right eye area.|

## MetadataCatBodyObject

Cat body metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

## MetadataDogFaceObject

Dog face metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Type                             | Read-only| Optional|Description               |
| ---------------------- | --------------------------------- | ---- | ---- | --------------------- |
| leftEyeBoundingBox     | [Rect](#rect)                              |  Yes |  No | Left eye area.|
| rightEyeBoundingBox    | [Rect](#rect)                              |  Yes |  No | Right eye area.|

## MetadataDogBodyObject

Dog body metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

## MetadataSalientDetectionObject

Salient subject metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

## MetadataBarcodeObject

Barcode metadata detected by the camera, which is extended from [MetadataObject](#metadataobject). It serves as the data source of the camera information in [CameraInput](arkts-apis-camera-CameraInput.md). It is obtained by calling metadataOutput.[on('metadataObjectsAvailable')](arkts-apis-camera-MetadataOutput.md#onmetadataobjectsavailable).

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

## SmoothZoomInfo<sup>11+</sup>

Describes the smooth zoom information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  |   Optional  | Description      |
| -------- | ---------- | -------- | -------- | ---------- |
| duration |   number   |   No    |    No   | Total duration of smooth zoom, in milliseconds.|

## ControlCenterStatusInfo<sup>20+</sup>

Describes the effect status information of a camera controller.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  |   Optional  | Description      |
| -------- | ---------- | -------- | -------- | ---------- |
| effectType | [ControlCenterEffectType](arkts-apis-camera-e.md#controlcentereffecttype20) |   Yes   |    No   | Effect type of the camera controller.|
| isActive | boolean | Yes| No| Whether the camera controller is activated. **true** if activated, **false** otherwise.|

## IsoInfo<sup>22+</sup>

Describes the information about the sensitivity (ISO) settings.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type   | Read-only| Optional| Description          |
| ---- | ------- | ---- |--| -------------- |
| iso  | number  | Yes  | Yes| ISO.       |

## CameraOcclusionDetectionResult<sup>23+</sup>

Describes the instance returned by the occlusion status callback, which indicates whether the camera lens is blocked or dirty.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                | Type      | Read-only| Optional| Description                               |
|--------------------| ---------- | ---- | ---- |-----------------------------------|
| isCameraOccluded   | boolean    | Yes  | No  | Whether the camera lens is blocked. **true** if blocked, **false** otherwise.|
| isCameraLensDirty  | boolean    | Yes  | No  | Whether the camera lens is dirty. **true** if dirty, false otherwise.|

## ZoomRange<sup>24+</sup>

Describes the zoom range.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description           |
| -------- | ----------------------------- |----- |---| --------------|
| min      | number                        |  Yes | No| Minimum zoom value.     |
| max      | number                        |  Yes | No| Maximum zoom value.     |

## PhysicalAperture<sup>24+</sup>

Describes the physical aperture object.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Read-only| Optional| Description       |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| zoomRange            | [ZoomRange](#zoomrange24)         | No |  No | Zoom range of a given physical aperture.|
| apertures                 | Array\<number\>              | No |  No | Supported physical aperture.       |

## ExposureInfo<sup>24+</sup>

Describes the exposure information object.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description           |
| -------- | ----------------------------- |----- |---| --------------|
| exposureTime      | number                        |  Yes | Yes| Exposure time, in microseconds.     |

## ZoomPointInfo

Describes the equivalent focal length information.

**Since:** 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  | Optional | Description      |
| -------- | ---------- | -------- |-----| ---------- |
| zoomRatio |   number   |   Yes    | No  | Zoom ratio.|
| equivalentFocalLength |   number   |   Yes    | No  | Equivalent focal length corresponding to the current focal length ratio.|