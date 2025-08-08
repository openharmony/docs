# Interfaces (Others)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CameraDevice

Describes the camera device information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                             | Type                                 | Read-only| Optional| Description       |
|---------------------------------|-------------------------------------| ---- |----|---------- |
| cameraId                        | string                              | Yes  | No | Camera ID.|
| cameraPosition                  | [CameraPosition](arkts-apis-camera-e.md#cameraposition)   | Yes  | No | Camera position.   |
| cameraType                      | [CameraType](arkts-apis-camera-e.md#cameratype)           | Yes  | No | Camera type.   |
| connectionType                  | [ConnectionType](arkts-apis-camera-e.md#connectiontype)   | Yes  | No | Camera connection type.|
| cameraOrientation<sup>12+</sup> | number                              | Yes  | No | Camera installation angle, which does not change as the screen rotates. The value ranges from 0° to 360°, measured in degrees.|
| hostDeviceName<sup>15+</sup>    | string                              | Yes  | No | Remote device name.|
| hostDeviceType<sup>15+</sup>    | [HostDeviceType](arkts-apis-camera-e.md#hostdevicetype15) | Yes  | No | Remote device type.|

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
| min      | number                        |  Yes | No| Minimum frame rate.     |
| max      | number                        |  Yes | No| Maximum frame rate.     |

## VideoProfile

Describes the video configuration information. It inherits from [Profile](#profile).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Read-only| Optional| Description       |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| frameRateRange            | [FrameRateRange](arkts-apis-camera-i.md#frameraterange)         | Yes |  No | Frame rate range, in units of frames per second (FPS).|

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

Describes the output capability.

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
| ------ | ------ | ---- |-----| ------------ |
| device              | [CameraDevice](arkts-apis-camera-i.md#cameradevice)   | No  | No  | Concurrent camera device.|
| type                | [CameraConcurrentType](arkts-apis-camera-e.md#cameraconcurrenttype18)  | No  | No  | Concurrency type.|
| modes               | Array\<[SceneMode](arkts-apis-camera-e.md#scenemode11) \>              | No  | No  | Scene mode.|
| outputCapabilities  | Array\<[CameraOutputCapability](#cameraoutputcapability) \> | No  | No  | Output capabilities of the camera.|

## Location

Describes the geolocation information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Type  | Read-only| Optional |Description        |
| ------------ | ------ | ---- |-----|------------ |
| latitude     | number |  No | No  |Latitude, in degrees.   |
| longitude    | number |  No | No  |Longitude, in degrees.   |
| altitude     | number |  No | No  |Altitude, in meters.   |

## PhotoCaptureSetting

Describes the settings for taking an image.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                           | Read-only| Optional| Description                                                                  |
| -------- | ------------------------------- | ---- | ---- |----------------------------------------------------------------------|
| quality  | [QualityLevel](arkts-apis-camera-e.md#qualitylevel)   | No  | Yes  | Image quality (low by default).                                                          |
| rotation | [ImageRotation](arkts-apis-camera-e.md#imagerotation) | No  | Yes  | Rotation angle of the image. The default value is **0**, indicating clockwise rotation.                                                 |
| location | [Location](#location)           | No  | Yes  | Geolocation information of the image (depending on the device hardware information by default).                                              |
| mirror   | boolean                         | No  | Yes  | Whether mirror photography is enabled (disabled by default). Before using this enumerated value, call [isMirrorSupported](arkts-apis-camera-PhotoOutput.md#ismirrorsupported) to check whether mirror photography is supported.|

## FrameShutterInfo

Describes the frame shutter information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type  | Read-only| Optional| Description       |
| --------- | ------ | ---- | ---- | ---------- |
| captureId | number | No  | No  | ID of this capture action.|
| timestamp | number | No  | No  | Timestamp when the frame shutter event is triggered.|

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
| time       | number | No  | No  | Estimated duration when the sensor captures frames at the bottom layer in a single capture. If **–1** is reported, there is no estimated duration.   |

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

Describes a rectangle.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  |  Read-only | Optional |           Description        |
| -------- | ------ | ------ |-----| --------------------- |
| topLeftX | number |   No  | No  | X-axis coordinate of the upper left corner of the rectangle.  |
| topLeftY | number |   No  | No  | Y-axis coordinate of the upper left corner of the rectangle.  |
| width    | number |   No  | No  | Width of the rectangle, which is a relative value. The value range is [0, 1]. |
| height   | number |   No  | No  | Height of the rectangle, which is a relative value. The value range is [0, 1]. |

## MetadataObject

Describes the camera metadata, which is the data source of [CameraInput](arkts-apis-camera-CameraInput.md). The metadata is obtained through metadataOutput.on('metadataObjectsAvailable').

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Type                                       | Read-only| Optional|Description               |
| ----------- | ------------------------------------------- | ---- | ---- | ----------------- |
| type        | [MetadataObjectType](arkts-apis-camera-e.md#metadataobjecttype)   |  Yes |  No | Metadata object type.   |
| timestamp   | number                                      |  Yes |  No | Current timestamp, in milliseconds.|
| boundingBox | [Rect](#rect)                               |  Yes |  No | Metadata rectangle. |

## SmoothZoomInfo<sup>11+</sup>

Describes the smooth zoom information.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  |   Optional  | Description      |
| -------- | ---------- | -------- | -------- | ---------- |
| duration |   number   |   No    |    No   | Total duration of smooth zoom, in ms.|

## ControlCenterStatusInfo<sup>20+</sup>

Describes the effect status information of a camera controller.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  |   Optional  | Description      |
| -------- | ---------- | -------- | -------- | ---------- |
| effectType | [ControlCenterEffectType](arkts-apis-camera-e.md#controlcentereffecttype20) |   Yes   |    No   | Effect type of the camera controller.|
| isActive | boolean | Yes| No| Whether the camera controller is activated. **true** if activated, **false** otherwise.|
