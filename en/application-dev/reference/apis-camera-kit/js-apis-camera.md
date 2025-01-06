# @ohos.multimedia.camera (Camera Management)

The camera module provides a set of camera service APIs for you to easily develop a camera application. The application can access and operate the camera hardware to implement basic operations, such as preview, taking photos, and recording videos. It can also perform more operations, for example, controlling the flash and exposure time, and focusing or adjusting the focus.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## camera.getCameraManager

getCameraManager(context: Context): CameraManager

Obtains a **CameraManager** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)      | Yes  | Application context.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraManager](#cameramanager)           | **CameraManager** instance obtained.                  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function getCameraManager(context: common.BaseContext): camera.CameraManager | undefined {
  let cameraManager: camera.CameraManager | undefined = undefined;
  try {
    cameraManager = camera.getCameraManager(context);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getCameraManager call failed. error code: ${err.code}`);
  }
  return cameraManager;
}
```

## CameraDevice

Defines the camera device information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type                              | Read-only| Optional| Description       |
| -------------- | --------------------------------- | ---- | ---- |---------- |
| cameraId       | string                            | Yes  | No  | Camera ID.|
| cameraPosition | [CameraPosition](#cameraposition) | Yes  | No  | Camera position.   |
| cameraType     | [CameraType](#cameratype)         | Yes  | No  | Camera type.   |
| connectionType | [ConnectionType](#connectiontype) | Yes  | No  | Camera connection type.|
| cameraOrientation<sup>12+</sup> | number | Yes  | No  | Installation angle of the lens, which does not change as the screen rotates. The value ranges from 0° to 360°.|

## CameraPosition

Enumerates the camera positions.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Value  | Description                                                             |
| --------------------------- | ---- |-----------------------------------------------------------------|
| CAMERA_POSITION_UNSPECIFIED | 0    | Unspecified position.                                                       |
| CAMERA_POSITION_BACK        | 1    | Rear camera.                                                          |
| CAMERA_POSITION_FRONT       | 2    | Front camera.                                                          |
| CAMERA_POSITION_FOLD_INNER<sup>(deprecated)</sup>  | 3    | Folded camera.<br>This API is supported since API version 11 and deprecated since API version 12.|

## CameraType

Enumerates the camera types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value  | Description           |
| ----------------------- | ---- | -------------- |
| CAMERA_TYPE_DEFAULT     | 0    | Unspecified camera type. |
| CAMERA_TYPE_WIDE_ANGLE  | 1    | Wide camera.      |
| CAMERA_TYPE_ULTRA_WIDE  | 2    | Ultra wide camera.    |
| CAMERA_TYPE_TELEPHOTO   | 3    | Telephoto camera.      |
| CAMERA_TYPE_TRUE_DEPTH  | 4    | Camera with depth of field information.|

## ConnectionType

Enumerates the camera connection types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value  | Description          |
| ---------------------------- | ---- | ------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0    | Built-in camera.     |
| CAMERA_CONNECTION_USB_PLUGIN | 1    | Camera connected using USB.|
| CAMERA_CONNECTION_REMOTE     | 2    | Remote camera.|

## CameraStatus

Enumerates the camera statuses.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | A camera appears.  |
| CAMERA_STATUS_DISAPPEAR   | 1    | The camera disappears.    |
| CAMERA_STATUS_AVAILABLE   | 2    | The camera is available.      |
| CAMERA_STATUS_UNAVAILABLE | 3    | The camera is unavailable.    |

## FoldStatus<sup>12+</sup>

Enumerates the folding statuses available for a fordable device.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| NON_FOLDABLE      | 0    | The device is not foldable.  |
| EXPANDED   | 1    | The device is fully unfolded.|
| FOLDED   | 2    | The device is folded.      |

## CameraStatusInfo

Defines the camera status information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                          |    Read-only  |     Optional    | Description      |
| ------ | ----------------------------- | --------- |------------ | ---------- |
| camera | [CameraDevice](#cameradevice) |     No   |       No    | Camera device.|
| status | [CameraStatus](#camerastatus) |     No   |       No    | Camera status.|

## FoldStatusInfo<sup>12+</sup>

Describes the folding status information about a foldable device.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                          |    Read-only  |     Optional    | Description      |
| ------ | ----------------------------- | --------- |------------ | ---------- |
| supportedCameras | [Array<CameraDevice\>](#cameradevice) |     No   |       No    | List of cameras supported in the current folding status.|
| foldStatus | [FoldStatus](#foldstatus12) |     No   |       No    | Folding status.|

## Profile

Defines the camera profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description        |
| -------- | ----------------------------- |---- | ---- | ------------- |
| format   | [CameraFormat](#cameraformat) | Yes |  No | Output format.     |
| size     | [Size](#size)                 | Yes |  No | Resolution.<br>The width and height of the camera resolution is set, not the actual width and height of an output image. |

## FrameRateRange

Defines the frame rate range.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description           |
| -------- | ----------------------------- |----- |---| -------------- |
| min      | number                        |  Yes | No| Minimum frame rate.     |
| max      | number                        |  Yes | No| Maximum frame rate.     |

## VideoProfile

Defines the video configuration information. It inherits from [Profile](#profile).

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Read-only| Optional| Description       |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| frameRateRange            | [FrameRateRange](#frameraterange)         | Yes |  No | Frame rate range, in units of frames per second (FPS).|

## CameraOutputCapability

Defines the camera output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Type                                               | Read-only| Optional| Description               |
| ----------------------------- | --------------------------------------------------- | ---- | ---- |-------------------|
| previewProfiles               | Array\<[Profile](#profile)\>                        |  Yes | No| Supported preview profiles.     |
| photoProfiles                 | Array\<[Profile](#profile)\>                        |  Yes | No| Supported photo profiles.       |
| videoProfiles                 | Array\<[VideoProfile](#videoprofile)\>              |  Yes | No| Supported video profiles.       |
| supportedMetadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  |  Yes | No| Supported metadata object types.|

## SceneMode<sup>11+</sup>

Enumerates the camera scene modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Value      | Description                                         |
|----------------------------|---------|---------------------------------------------|
| NORMAL_PHOTO               | 1       | Normal photo mode. For details, see [PhotoSession](#photosession11).  |
| NORMAL_VIDEO               | 2       | Normal record mode. For details, see [VideoSession](#videosession11).  |
| SECURE_PHOTO<sup>12+</sup> | 12      | Secure mode. For details, see [SecureSession](#securesession12).|

## CameraErrorCode

Enumerates the camera error codes,

which are returned when an API call is incorrect or the **on()** API is used to listen for the error status.

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

## CameraManager

Implements camera management. Before calling any API in **CameraManager**, you must use [getCameraManager](#cameragetcameramanager) to obtain a **CameraManager** instance.

### getSupportedCameras

getSupportedCameras(): Array\<CameraDevice\>

Obtains the supported camera devices. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[CameraDevice](#cameradevice)>            | Array of camera devices supported.                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getSupportedCameras(cameraManager: camera.CameraManager): Array<camera.CameraDevice> {
  let cameras: Array<camera.CameraDevice> = [];
  try {
    cameras = cameraManager.getSupportedCameras();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getSupportedCameras call failed. error code: ${err.code}`);
  }
  return cameras;
}
```

### getSupportedSceneModes<sup>11+</sup>

getSupportedSceneModes(camera: CameraDevice): Array\<SceneMode\>

Obtains the scene modes supported by a camera device. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| camera | [CameraDevice](#cameradevice)                              | Yes| **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras). An error code is returned if the input parameter is invalid.      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[SceneMode](#scenemode11)>            | Array of scene modes supported.                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getSupportedSceneModes(cameraManager: camera.CameraManager, camera: camera.CameraDevice): Array<camera.SceneMode> {
  let modes: Array<camera.SceneMode> = [];
  try {
    modes = cameraManager.getSupportedSceneModes(camera);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getSupportedSceneModes call failed. error code: ${err.code}`);
  }
  return modes;
}
```

### getSupportedOutputCapability<sup>(deprecated)</sup>

getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability

Obtains the output capability supported by a camera device. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getSupportedOutputCapability](#getsupportedoutputcapability11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| camera | [CameraDevice](#cameradevice)                              | Yes| **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras). An error code is returned if the input parameter is invalid.     |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```ts
function getSupportedOutputCapability(camera: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(camera);
  return cameraOutputCapability;
}
```

### getSupportedOutputCapability<sup>11+</sup>

getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability

Obtains the output capability supported by a camera device in a given scene mode. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| camera | [CameraDevice](#cameradevice)                              | Yes| **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras).      |
| mode | [SceneMode](#scenemode11)                              | Yes| Scene mode, which is obtained through [getSupportedSceneModes](#getsupportedscenemodes11).      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```ts
function getSupportedOutputCapability(camera: camera.CameraDevice, cameraManager: camera.CameraManager, sceneMode: camera.SceneMode): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(camera, sceneMode);
  return cameraOutputCapability;
}
```

### isCameraMuted

isCameraMuted(): boolean

Checks whether the camera device is muted.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                                        |
| ---------- | -------------------------------------------- |
| boolean    | **true**: The camera device is muted.<br>**false**: The camera device is not muted.|

**Example**

```ts
function isCameraMuted(cameraManager: camera.CameraManager): boolean {
  let isMuted: boolean = cameraManager.isCameraMuted();
  return isMuted;
}
```

### createCameraInput

createCameraInput(camera: CameraDevice): CameraInput

Creates a **CameraInput** instance with the specified **CameraDevice** instance. This API returns the result synchronously.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                              |
| -------- | ------------------------------------------- | ---- |--------------------------------------------------|
| camera  | [CameraDevice](#cameradevice)         | Yes  | **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | **CameraInput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400102                |  Operation not allowed.               |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createCameraInput(camera: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput | undefined {
  let cameraInput: camera.CameraInput | undefined = undefined;
  try {
    cameraInput = cameraManager.createCameraInput(camera);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createCameraInput call failed. error code: ${err.code}`);
  }
  return cameraInput;
}
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType): CameraInput

Creates a **CameraInput** instance with the specified camera position and type. This API returns the result synchronously.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| position | [CameraPosition](#cameraposition)           | Yes  | Camera position. You can call [getSupportedCameras](#getsupportedcameras) to obtain a **CameraDevice** instance, which contains the camera position information. |
| type     | [CameraType](#cameratype)                   | Yes  | Camera type. You can call [getSupportedCameras](#getsupportedcameras) to obtain a **CameraDevice** instance, which contains the camera type information.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | **CameraInput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400102                |  Operation not allowed.               |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createCameraInput(camera: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput | undefined {
  let position: camera.CameraPosition = camera.cameraPosition;
  let type: camera.CameraType = camera.cameraType;
  let cameraInput: camera.CameraInput | undefined = undefined;
  try {
    cameraInput = cameraManager.createCameraInput(position, type);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createCameraInput call failed. error code: ${err.code}`);
  }
  return cameraInput;
}
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput

Creates a **PreviewOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                             |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](#profile)                             | Yes  | Supported preview profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string | Yes  | Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) or [ImageReceiver](../apis-image-kit/js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PreviewOutput](#previewoutput)    | **PreviewOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPreviewOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.PreviewOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.previewProfiles[0];
  let previewOutput: camera.PreviewOutput | undefined = undefined;
  try {
    previewOutput = cameraManager.createPreviewOutput(profile, surfaceId);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createPreviewOutput call failed. error code: ${err.code}`);
  }
  return previewOutput;
}
```

### createPreviewOutput<sup>12+</sup>

createPreviewOutput(surfaceId: string): PreviewOutput

Creates a **PreviewOutput** instance without configuration. This API returns the result synchronously. It must be used together with [preconfig](#preconfig12).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                             |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| surfaceId| string | Yes  | Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) or [ImageReceiver](../apis-image-kit/js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PreviewOutput](#previewoutput)    | **PreviewOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                          |
|---------|------------------------------------------------|
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400201 | Camera service fatal error.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPreviewOutput(cameraManager: camera.CameraManager, surfaceId: string): camera.PreviewOutput | undefined {
  let previewOutput: camera.PreviewOutput | undefined = undefined;
  try {
    previewOutput = cameraManager.createPreviewOutput(surfaceId);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createPreviewOutput call failed. error code: ${err.code}`);
  }
  return previewOutput;
}
```

### createPhotoOutput<sup>(deprecated)</sup>

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

Creates a **PhotoOutput** instance. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [createPhotoOutput](#createphotooutput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | Yes  | Supported photo profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string            | Yes  | Surface ID, which is obtained from [ImageReceiver](../apis-image-kit/js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | **PhotoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPhotoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.PhotoOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.photoProfiles[0];
  let photoOutput: camera.PhotoOutput | undefined = undefined;
  try {
    photoOutput = cameraManager.createPhotoOutput(profile, surfaceId);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createPhotoOutput call failed. error code: ${err.code}`);
  }
  return photoOutput;
}
```

### createPhotoOutput<sup>11+</sup>

createPhotoOutput(profile?: Profile): PhotoOutput

Creates a **PhotoOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- |----| ----------------------------------- |
| profile  | [Profile](#profile)                         | No | Supported photo profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).<br>In API version 11, this parameter is mandatory. Since API version 12, it will overwrite the preconfigured parameters passed in through **preconfig**.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | **PhotoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID   | Error Message                                          |
|----------|------------------------------------------------|
| 7400101  | Parameter missing or parameter type incorrect. |
| 7400201  | Camera service fatal error.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createPhotoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager): camera.PhotoOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.photoProfiles[0];
  let photoOutput: camera.PhotoOutput | undefined = undefined;
  try {
    photoOutput = cameraManager.createPhotoOutput(profile);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createPhotoOutput call failed. error code: ${err.code}`);
  }
  return photoOutput;
}
```

### createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput

Creates a **VideoOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                             |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| profile  | [VideoProfile](#videoprofile)               | Yes  | Supported video profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string          | Yes  | Surface ID, which is obtained from [AVRecorder](../apis-media-kit/js-apis-media.md#avrecorder9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoOutput](#videooutput)   | **VideoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createVideoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.VideoOutput | undefined {
  let profile: camera.VideoProfile = cameraOutputCapability.videoProfiles[0];
  let videoOutput: camera.VideoOutput | undefined = undefined;
  try {
    videoOutput = cameraManager.createVideoOutput(profile, surfaceId);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createVideoOutput call failed. error code: ${err.code}`);
  }
  return videoOutput;
}
```

### createVideoOutput<sup>12+</sup>

createVideoOutput(surfaceId: string): VideoOutput

Creates a **VideoOutput** instance without configuration. This API returns the result synchronously. It must be used together with [preconfig](#preconfig12-1).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type    | Mandatory   | Description                                                                        |
|-----------|--------|-------|----------------------------------------------------------------------------|
| surfaceId | string | Yes    | Surface ID, which is obtained from [AVRecorder](../apis-media-kit/js-apis-media.md#avrecorder9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoOutput](#videooutput)   | **VideoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID   | Error Message                                          |
|----------|------------------------------------------------|
| 7400101  | Parameter missing or parameter type incorrect. |
| 7400201  | Camera service fatal error.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createVideoOutput(cameraManager: camera.CameraManager, surfaceId: string): camera.VideoOutput | undefined {
  let videoOutput: camera.VideoOutput | undefined = undefined;
  try {
    videoOutput = cameraManager.createVideoOutput(surfaceId);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createVideoOutput call failed. error code: ${err.code}`);
  }
  return videoOutput;
}
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes: Array\<MetadataObjectType\>): MetadataOutput

Creates a **MetadataOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Metadata object types, which are obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [MetadataOutput](#metadataoutput)   | **MetadataOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createMetadataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): void {
  let metadataObjectTypes: Array<camera.MetadataObjectType> = cameraOutputCapability.supportedMetadataObjectTypes;
  let metadataOutput: camera.MetadataOutput | undefined = undefined;
  try {
    metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`createMetadataOutput error. error code: ${err.code}`);
  }
}
```

### createCaptureSession<sup>(deprecated)</sup>

createCaptureSession(): CaptureSession

Creates a **CaptureSession** instance. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [createSession](#createsession11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CaptureSession](#capturesessiondeprecated)   | **CaptureSession** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createCaptureSession(cameraManager: camera.CameraManager): camera.CaptureSession | undefined {
  let captureSession: camera.CaptureSession | undefined = undefined;
  try {
    captureSession = cameraManager.createCaptureSession();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`createCaptureSession error. error code: ${err.code}`);
  }
  return captureSession;
}
```

### createSession<sup>11+</sup>

createSession\<T extends Session\>(mode: SceneMode): T

Creates a **Session** instance with a given scene mode. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type             | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| mode     | [SceneMode](#scenemode11)     | Yes  | Scene mode. The API does not take effect if the input parameter is invalid (for example, the value is out of range, null, or undefined).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [T extends Session](#session11)   | **Session** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message                                                                                                                                          |
| --------------- |------------------------------------------------------------------------------------------------------------------------------------------------|
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3.Parameter verification failed. |  
| 7400201                | Camera service fatal error.                                                                                                                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createSession(cameraManager: camera.CameraManager, mode: camera.SceneMode): camera.Session | undefined {
  let photoSession: camera.PhotoSession | undefined = undefined;
  try {
    photoSession = cameraManager.createSession(mode) as camera.PhotoSession;
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`createCaptureSession error. error code: ${err.code}`);
  }
  return photoSession;
}
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo\>): void

Subscribes to camera status events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'cameraStatus'**. The event can be listened for when a **CameraManager** instance is obtained. This event is triggered and the corresponding information is returned only when the camera device is enabled or disabled.|
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | Yes  | Callback used to return the camera status change.|                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error('cameraStatus with errorCode = ' + err.code);
    return;
  }
  console.info(`camera : ${cameraStatusInfo.camera.cameraId}`);
  console.info(`status: ${cameraStatusInfo.status}`);
}

function registerCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraStatus', callback);
}
```

### off('cameraStatus')

off(type: 'cameraStatus', callback?: AsyncCallback\<CameraStatusInfo\>): void

Unsubscribes from camera status events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'cameraStatus'**. The event can be listened for when a **CameraManager** instance is obtained.|
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.off('cameraStatus');
}
```

### on('foldStatusChange')<sup>12+</sup>

on(type: 'foldStatusChange', callback: AsyncCallback\<FoldStatusInfo\>): void

Subscribes to folding status change events of the foldable device. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'foldStatusChange'**. The event is triggered when the folding status of the foldable device changes.|
| callback | AsyncCallback\<[FoldStatusInfo](#foldstatusinfo12)\> | Yes  | Callback used to return the folding status information about the foldable device.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, foldStatusInfo: camera.FoldStatusInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error('foldStatusChange with errorCode = ' + err.code);
    return;
  }
  console.info(`camera length: ${foldStatusInfo.supportedCameras.length}`);
  console.info(`foldStatus: ${foldStatusInfo.foldStatus}`);
}

function registerFoldStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.on('foldStatusChange', callback);
}
```

### off('foldStatusChange')<sup>12+</sup>

off(type: 'foldStatusChange', callback?: AsyncCallback\<FoldStatusInfo\>): void

Unsubscribes from folding status change events of the foldable device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'foldStatusChange'**. The event is triggered when the folding status of the foldable device changes.|
| callback | AsyncCallback\<[FoldStatusInfo](#foldstatusinfo12)\> | No  | Callback used to return the folding status information about the foldable device. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFoldStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.off('foldStatusChange');
}
```

### isTorchSupported<sup>11+</sup>

isTorchSupported(): boolean

Checks whether the camera device supports the flashlight.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The camera device supports the flashlight.<br>**false**: The camera device does not support the flashlight.|

**Example**

```ts
function isTorchSupported(cameraManager: camera.CameraManager): boolean {
  let isSupported = cameraManager.isTorchSupported();
  return isSupported;
}
```

### isTorchModeSupported<sup>11+</sup>

isTorchModeSupported(mode: TorchMode): boolean

Checks whether a flashlight mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| mode | [TorchMode](#torchmode11) | Yes| Flashlight mode. If the input parameter is null or undefined, it is treated as 0 and the flashlight is turned off.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The flashlight mode is supported.<br>**false**: The flashlight mode is not supported.|

**Example**

```ts
function isTorchModeSupported(cameraManager: camera.CameraManager, torchMode: camera.TorchMode): boolean {
  let isSupported = cameraManager.isTorchModeSupported(torchMode);
  return isSupported;
}
```

### getTorchMode<sup>11+</sup>

getTorchMode(): TorchMode

Obtains the flashlight mode of this camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [TorchMode](#torchmode11)    | Flashlight mode.|

**Example**

```ts
function getTorchMode(cameraManager: camera.CameraManager): camera.TorchMode | undefined {
  let torchMode: camera.TorchMode | undefined = undefined;
  torchMode = cameraManager.getTorchMode();
  return torchMode;
}
```

### setTorchMode<sup>11+</sup>

setTorchMode(mode: TorchMode): void

Sets the flashlight mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| mode | [TorchMode](#torchmode11) | Yes| Flashlight mode. If the input parameter is null or undefined, it is treated as 0 and the flashlight is turned off.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed. |
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setTorchMode(cameraManager: camera.CameraManager, torchMode: camera.TorchMode): void {
  try {
    cameraManager.setTorchMode(torchMode);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setTorchMode call failed. error code: ${err.code}`);
  }
}
```

### on('torchStatusChange')<sup>11+</sup>

on(type: 'torchStatusChange', callback: AsyncCallback\<TorchStatusInfo\>): void

Subscribes to flashlight status change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'torchStatusChange'**. The event can be listened for when a **CameraManager** instance is obtained. Currently, this event is triggered only in the following scenarios: The flashlight is turned on or turned off, or becomes unavailable or available.|
| callback | AsyncCallback\<TorchStatusInfo> | Yes  | Callback used to return the flashlight status.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, torchStatusInfo: camera.TorchStatusInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`onTorchStatusChange, isTorchAvailable: ${torchStatusInfo.isTorchAvailable}, isTorchActive: ${torchStatusInfo.isTorchActive}, level: ${torchStatusInfo.torchLevel}`);
}

function registerTorchStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.on('torchStatusChange', callback);
}
```

### off('torchStatusChange')<sup>11+</sup>

off(type: 'torchStatusChange', callback?: AsyncCallback\<TorchStatusInfo\>): void

Unsubscribes from flashlight status change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'torchStatusChange'**. The event can be listened for when a **CameraManager** instance is obtained.|
| callback | AsyncCallback\<TorchStatusInfo> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterTorchStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.off('torchStatusChange');
}
```

## TorchMode<sup>11+</sup>

Enumerates the flashlight modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value  | Description          |
| ---------------------------- | ---- | ------------- |
| OFF    | 0    | The flashlight is off.     |
| ON  | 1    | The flashlight is on.|
| AUTO      | 2    | The flashlight mode is auto.|

## TorchStatusInfo<sup>11+</sup>

Defines the flashlight status information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name             | Type      | Read-only| Optional| Description       |
| ---------------- | ---------- | ---- | ---- | ----------- |
| isTorchAvailable | boolean    | Yes  | No  | Whether the flashlight is available.|
| isTorchActive    | boolean    | Yes  | No  | Whether the flashlight is activated.   |
| torchLevel       | number     | Yes  | No  | Flashlight level. The value range is [0, 1]. A larger value indicates a greater luminance.   |

## Size

Defines the output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type   | Read-only| Optional | Description        |
| ------ | ------ | ---- |-----| ------------ |
| height | number | No  | No  | Image height, in pixels.|
| width  | number | No  | No  | Image width, in pixels.|

## Point

Defines the point coordinates, which are used for focus and exposure configuration.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name   | Type  | Read-only  | Optional  | Description        |
| ------ | ------ | ------ | ------ | ------------ |
| x      | number | No    | No    | X coordinate of a point.  |
| y      | number | No    | No    | Y coordinate of a point.  |

## CameraFormat

Enumerates the camera output formats.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGBA_888 image.       |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV_420_SP image.     |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG image.           |
| CAMERA_FORMAT_YCBCR_P010<sup>11+</sup> |   2001    | YCBCR_P010 image.     |
| CAMERA_FORMAT_YCRCB_P010<sup>11+</sup> |   2002    | YCRCB_P010 image.     |
| CAMERA_FORMAT_HEIC<sup>13+</sup>       |   2003    | HEIF image.           |

## VideoCodecType<sup>13+</sup>

Enumerates the video codec types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Value   | Description         |
|------|------|-------------|
| AVC  | 0    | AVC. |
| HEVC | 1 | HEVC.|

## CameraInput

Defines the camera input object.

Provides camera device information used in [Session](#session11).

### open

open(callback: AsyncCallback\<void\>): void

Opens this camera device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open((err: BusinessError) => {
    if (err) {
      console.error(`Failed to open the camera, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with camera opened.');
  });
}
```

### open

open(): Promise\<void\>

Opens this camera device. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                     |
|---------|-------------------------------------------|
| 7400102 | Operation not allowed.                    |
| 7400107 | Can not use camera cause of conflict.     |
| 7400108 | Camera disabled cause of security reason. |
| 7400201 | Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open().then(() => {
    console.info('Promise returned with camera opened.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to open the camera, error code: ${error.code}.`);
  });
}
```

### open<sup>12+</sup>

open(isSecureEnabled: boolean): Promise\<bigint\>

Opens this camera device and obtains the handle to the camera in secure mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                                                                     |
| -------- | -------------------- | ---- |-------------------------------------------------------------------------|
| isSecureEnabled | boolean | Yes  | Whether the camera can be enabled in secure mode. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise\<bigint\> | Promise used to return the handle to the camera.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open(true).then(() => {
    console.info('Promise returned with camera opened.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to open the camera, error code: ${error.code}.`);
  });
}
```

### close

close(callback: AsyncCallback\<void\>\): void

Closes this camera device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function closeCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.close((err: BusinessError) => {
    if (err) {
      console.error(`Failed to close the cameras, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with camera closed.');
  });
}
```

### close

close(): Promise\<void\>

Closes this camera device. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function closeCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.close().then(() => {
    console.info('Promise returned with camera closed.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to close the cameras, error code: ${error.code}.`);
  });
}
```

### on('error')

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void

Subscribes to **CameraInput** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **CameraInput** instance is created. This event is triggered and the result is returned when an error occurs on the camera device. For example, if the camera device is unavailable or a conflict occurs, the error information is returned.|
| camera   | [CameraDevice](#cameradevice)    | Yes  | Camera device.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Camera input error code: ${err.code}`);
}

function registerCameraInputError(cameraInput: camera.CameraInput, camera: camera.CameraDevice): void {
  cameraInput.on('error', camera, callback);
}
```

### off('error')

off(type: 'error', camera: CameraDevice, callback?: ErrorCallback): void

Unsubscribes from **CameraInput** error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **CameraInput** instance is created. This event is triggered and the result is returned when an error occurs on the camera device. For example, if the camera device is unavailable or a conflict occurs, the error information is returned.|
| camera   | [CameraDevice](#cameradevice)    | Yes  | Camera device.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterCameraInputError(cameraInput: camera.CameraInput, camera: camera.CameraDevice): void {
  cameraInput.off('error', camera);
}
```

## CameraOutput

Implements output information used in [Session](#session11). It is the base class of **output**.

### release

release(callback: AsyncCallback\<void\>): void

Releases output resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releasePreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the Preview output instance ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate that the preview output instance is released successfully.');
  });
}

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the video output instance ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate that the video output instance is released successfully.');
  });
}
```

### release

release(): Promise\<void\>

Releases output resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releasePreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.release().then(() => {
    console.info('Promise returned to indicate that the preview output instance is released successfully.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to preview output release, error code: ${error.code}`);
  });
}

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release().then(() => {
    console.info('Promise returned to indicate that the video output instance is released successfully.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to video output release, error code: ${error.code}`);
  });
}
```

## PreviewOutput

Implements preview output. It inherits from [CameraOutput](#cameraoutput).

### start<sup>(deprecated)</sup>

start(callback: AsyncCallback\<void\>): void

Starts to output preview streams. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](#start11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the preview output, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with preview output started.');
  });
}
```

### start<sup>(deprecated)</sup>

start(): Promise\<void\>

Starts to output preview streams. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](#start11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description               |
| -------------- |-------------------|
| Promise\<void\> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.start().then(() => {
    console.info('Promise returned with preview output started.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to preview output start, error code: ${error.code}.`);
  });
}
```

### stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void\>): void

Stops outputting preview streams. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](#stop11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the preview output, error code: ${err.code}.`);
      return;
    }
    console.info('Returned with preview output stopped.');
  })
}
```

### stop<sup>(deprecated)</sup>

stop(): Promise\<void\>

Stops outputting preview streams. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](#stop11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.stop().then(() => {
    console.info('Callback returned with preview output stopped.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to preview output stop, error code: ${error.code}.`);
  });
}
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

Subscribes to preview frame start events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                    |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and returned when the bottom layer starts exposure for the first time.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. The preview starts as long as this event is returned.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info('Preview frame started');
}

function registerPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('frameStart', callback);
}
```

### off('frameStart')

off(type: 'frameStart', callback?: AsyncCallback\<void\>): void

Unsubscribes from preview frame start events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                    |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **previewOutput** instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameStart');
}
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback\<void\>): void

Subscribes to preview frame end events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and returned when the last frame of preview ends.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. The preview ends as long as this event is returned.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info('Preview frame ended');
}

function registerPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('frameEnd', callback);
}
```

### off('frameEnd')

off(type: 'frameEnd', callback?: AsyncCallback\<void\>): void

Unsubscribes from preview frame end events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a **previewOutput** instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PreviewOutput** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a preview-related API such as [Session.start](#start11-1) or [CameraOutput.release](#release-1).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(previewOutputError: BusinessError): void {
  console.error(`Preview output error code: ${previewOutputError.code}`);
}

function registerPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('error', callback)
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PreviewOutput** error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **previewOutput** instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('error');
}
```

### getSupportedFrameRates<sup>12+</sup>

 getSupportedFrameRates(): Array\<FrameRateRange\>

Obtains the supported frame rates.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**
|      Type     |     Description    |
| -------------  | ------------ |
| Array<[FrameRateRange](#frameraterange)> | Array of supported frame rates.|

**Example**

```ts
function getSupportedFrameRates(previewOutput: camera.PreviewOutput): Array<camera.FrameRateRange> {
  let supportedFrameRatesArray: Array<camera.FrameRateRange> = previewOutput.getSupportedFrameRates();
  return supportedFrameRatesArray;
}
```

### setFrameRate<sup>12+</sup>

setFrameRate(minFps: number, maxFps: number): void

Sets a frame rate range for preview streams. The range must be within the supported frame rate range, which can be obtained by calling [getSupportedFrameRates](#getsupportedframerates12).

> **NOTE**
>
> This API is valid only in [PhotoSession](#photosession11) or [VideoSession](#videosession11) mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| minFps   | number        | Yes  | Minimum frame rate.|
| maxFps   | number        | Yes  | Maximum frame rate. When the minimum value is greater than the maximum value, the API does not take effect.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID       | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400110                |  Unresolved conflicts with current configurations.     |

**Example**

```ts
function setFrameRateRange(previewOutput: camera.PreviewOutput, frameRateRange: Array<number>): void {
  previewOutput.setFrameRate(frameRateRange[0], frameRateRange[1]);
}
```

### getActiveFrameRate<sup>12+</sup>

getActiveFrameRate(): FrameRateRange

Obtains the configured frame rate range.

This API is valid only after [setFrameRate](#setframerate12) is called to set a frame rate range for preview streams.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     |     Description    |
| -------------  | ------------ |
| [FrameRateRange](#frameraterange) | Frame rate range.|

**Example**

```ts
function getActiveFrameRate(previewOutput: camera.PreviewOutput): camera.FrameRateRange {
  let activeFrameRate: camera.FrameRateRange = previewOutput.getActiveFrameRate();
  return activeFrameRate;
}
```

### getActiveProfile<sup>12+</sup>

getActiveProfile(): Profile

Obtains the profile that takes effect currently.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [Profile](#profile) | Profile obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400201 | Camera service fatal error.  |

**Example**

```ts
function testGetActiveProfile(previewOutput: camera.PreviewOutput): camera.Profile | undefined {
  let activeProfile: camera.Profile | undefined = undefined;
  try {
    activeProfile = previewOutput.getActiveProfile();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The previewOutput.getActiveProfile call failed. error code: ${err.code}`);
  }
  return activeProfile;
}
```

### getPreviewRotation<sup>12+</sup>

getPreviewRotation(displayRotation: number): ImageRotation

Obtains the preview rotation degree.

- Device' natural orientation: The default orientation of the device (phone) is in portrait mode, with the charging port facing downward.
- Camera lens angle: equivalent to the angle at which the camera is rotated clockwise to match the device's natural direction. The rear camera sensor of a phone is installed in landscape mode. Therefore, it needs to be rotated by 90 degrees clockwise to match the device's natural direction.
- Screen orientation: The upper left corner of the image displayed on the screen is the first pixel, which is the coordinate origin. In the case of lock screen, the direction is the same as the device's natural orientation.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| displayRotation | number  | Yes  | Screen rotation angle of the display. It is obtained by calling [display.getDefaultDisplaySync](../apis-arkui/js-apis-display.md#displaygetdefaultdisplaysync9).|

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [ImageRotation](#imagerotation) | Preview rotation degree.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.  |
| 7400201 | Camera service fatal error.  |

**Example**

```ts
function testGetPreviewRotation(previewOutput: camera.PreviewOutput, imageRotation : camera.ImageRotation): camera.ImageRotation {
  let previewRotation: camera.ImageRotation = camera.ImageRotation.ROTATION_0;
  try {
    previewRotation = previewOutput.getPreviewRotation(imageRotation);
    console.log(`Preview rotation is: ${previewRotation}`);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The previewOutput.getPreviewRotation call failed. error code: ${err.code}`);
  }
  return previewRotation;
}
```
### setPreviewRotation<sup>12+</sup>
setPreviewRotation(previewRotation: ImageRotation, isDisplayLocked?: boolean): void

Sets the preview rotation degree.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| previewRotation | [ImageRotation](#imagerotation)  | Yes  | Preview rotation angle.|
| isDisplayLocked | boolean  | No  | Whether the display is locked.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.  |
| 7400201 | Camera service fatal error.  |

**Example**

```ts
function testSetPreviewRotation(previewOutput: camera.PreviewOutput, previewRotation : camera.ImageRotation, isDisplayLocked: boolean): void {
  try {
    previewOutput.setPreviewRotation(previewRotation, isDisplayLocked);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The previewOutput.setPreviewRotation call failed. error code: ${err.code}`);
  }
  return;
}
```
## ImageRotation

Enumerates the image rotation angles.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Value  | Description          |
| ------------ | ---- | ------------- |
| ROTATION_0   | 0    | The image rotates 0 degrees.  |
| ROTATION_90  | 90   | The image rotates 90 degrees. |
| ROTATION_180 | 180  | The image rotates 180 degrees.|
| ROTATION_270 | 270  | The image rotates 270 degrees.|

## Location

Defines the geolocation information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Type  | Read-only| Optional |Description        |
| ------------ | ------ | ---- |-----|------------ |
| latitude     | number |  No | No  |Latitude, in degrees.   |
| longitude    | number |  No | No  |Longitude, in degrees.   |
| altitude     | number |  No | No  |Altitude, in meters.   |

## QualityLevel

Enumerates the image quality levels.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                 | Value  | Description        |
| -------------------- | ---- | ------------ |
| QUALITY_LEVEL_HIGH   | 0    | High image quality.  |
| QUALITY_LEVEL_MEDIUM | 1    | Medium image quality.|
| QUALITY_LEVEL_LOW    | 2    | Low image quality.  |


## PhotoCaptureSetting

Defines the settings for taking an image.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                           | Read-only| Optional| Description                                                                  |
| -------- | ------------------------------- | ---- | ---- |----------------------------------------------------------------------|
| quality  | [QualityLevel](#qualitylevel)   | No  | Yes  | Image quality (low by default).                                                          |
| rotation | [ImageRotation](#imagerotation) | No  | Yes  | Rotation angle of the image. The default value is **0**, indicating clockwise rotation.                                                 |
| location | [Location](#location)           | No  | Yes  | Geolocation information of the image (depending on the device hardware information by default).                                              |
| mirror   | boolean                         | No  | Yes  | Whether mirror photography is enabled (disabled by default). Before using this enumerated value, call [isMirrorSupported](#ismirrorsupported) to check whether mirror photography is supported.|

## Photo<sup>11+</sup>

Defines a higher-resolution image object.

### Attributes

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| main<sup>11+</sup> | [image.Image](../apis-image-kit/js-apis-image.md#image9) |        Yes      | Higher-resolution image.|

### release<sup>11+</sup>

release(): Promise\<void\>

Releases output resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Example**

```ts
async function releasePhoto(photo: camera.Photo): Promise<void> {
  await photo.release();
}
```

## PhotoOutput

Implements output information used in a photo session. It inherits from [CameraOutput](#cameraoutput).

### capture

capture(callback: AsyncCallback\<void\>): void

Captures a photo with the default photo capture parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function capture(photoOutput: camera.PhotoOutput): void {
  photoOutput.capture((err: BusinessError) => {
    if (err) {
      console.error(`Failed to capture the photo, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the photo capture request success.');
  });
}
```

### capture

capture(): Promise\<void\>

Captures a photo with the default photo capture parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function capture(photoOutput: camera.PhotoOutput): void {
  photoOutput.capture().then(() => {
    console.info('Promise returned to indicate that photo capture request success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to photo output capture, error code: ${error.code}.`);
  });
}
```

### capture

capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void\>): void

Captures a photo with the specified photo capture parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                        | Mandatory| Description                 |
| -------- | ------------------------------------------- | ---- | -------------------- |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | Yes  | Photo capture settings.            |
| callback | AsyncCallback\<void\>                        | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function capture(photoOutput: camera.PhotoOutput): void {
  let captureLocation: camera.Location = {
    latitude: 0,
    longitude: 0,
    altitude: 0
  }
  let settings: camera.PhotoCaptureSetting = {
    quality: camera.QualityLevel.QUALITY_LEVEL_LOW,
    rotation: camera.ImageRotation.ROTATION_0,
    location: captureLocation,
    mirror: false
  }
  photoOutput.capture(settings, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to capture the photo, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the photo capture request success.');
  });
}
```

### capture

capture(setting: PhotoCaptureSetting): Promise\<void\>

Captures a photo with the specified photo capture parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description     |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](#photocapturesetting) | Yes  | Photo capture parameters. The input of **undefined** is processed as if no parameters were passed.|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function capture(photoOutput: camera.PhotoOutput): void {
  let captureLocation: camera.Location = {
    latitude: 0,
    longitude: 0,
    altitude: 0
  }
  let settings: camera.PhotoCaptureSetting = {
    quality: camera.QualityLevel.QUALITY_LEVEL_LOW,
    rotation: camera.ImageRotation.ROTATION_0,
    location: captureLocation,
    mirror: false
  }
  photoOutput.capture(settings).then(() => {
    console.info('Promise returned to indicate that photo capture request success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to photo output capture, error code: ${error.code}.`);
  });
}
```

### on('photoAvailable')<sup>11+</sup>

on(type: 'photoAvailable', callback: AsyncCallback\<Photo\>): void

Subscribes to events indicating available high-resolution images. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'photoAvailable'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[Photo](#photo11)\> | Yes  | Callback used to return the high-resolution image.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

function callback(err: BusinessError, photo: camera.Photo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  let mainImage: image.Image = photo.main;
}

function registerPhotoOutputPhotoAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('photoAvailable', callback);
}
```

### off('photoAvailable')<sup>11+</sup>

off(type: 'photoAvailable', callback?: AsyncCallback\<Photo\>): void

Unsubscribes from events indicating available high-resolution images.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'photoAvailable'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[Photo](#photo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

function callback(err: BusinessError, photo: camera.Photo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  let mainImage: image.Image = photo.main;
}

function unRegisterPhotoOutputPhotoAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('photoAvailable', callback);
}
```

### on('captureStartWithInfo')<sup>11+</sup>

on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo\>): void

Subscribes to capture start events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'captureStartWithInfo'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[CaptureStartInfo](#capturestartinfo11)\> | Yes  | Callback used to return the capture ID.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, captureStartInfo: camera.CaptureStartInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`photo capture started, captureStartInfo : ${captureStartInfo}`);
}

function registerCaptureStartWithInfo(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureStartWithInfo', callback);
}
```

### off('captureStartWithInfo')<sup>11+</sup>

off(type: 'captureStartWithInfo', callback?: AsyncCallback\<CaptureStartInfo\>): void

Unsubscribes from capture start events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStartWithInfo'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[CaptureStartInfo](#capturestartinfo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function unRegisterCaptureStartWithInfo(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureStartWithInfo');
}
```

### isMovingPhotoSupported<sup>12+</sup>

isMovingPhotoSupported(): boolean

Checks whether taking moving photos is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | **true**: Taking moving photos is supported.<br>**false**: Taking moving photos is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID      | Error Message      |
| -------------- | --------------- |
| 7400201 |  Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isMovingPhotoSupported(photoOutput: camera.PhotoOutput): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = photoOutput.isMovingPhotoSupported();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isMovingPhotoSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### enableMovingPhoto<sup>12+</sup>

enableMovingPhoto(enabled: boolean): void

Enables or disables the feature of taking moving photos.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| enabled  | boolean                | Yes  | Whether to enable the feature of taking moving photos. The value **true** means to enable the feature, and **false** means the opposite.    |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID   | Error Message                                          |
| -------- |------------------------------------------------|
| 201      | permission denied.                             |
| 7400101  | Parameter missing or parameter type incorrect. |
| 7400201  | Camera service fatal error.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableMovingPhoto(photoOutput: camera.PhotoOutput): void {
  try {
    photoOutput.enableMovingPhoto(true);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The enableMovingPhoto call failed. error code: ${err.code}`);
  }
}
```

### on('photoAssetAvailable')<sup>12+</sup>

on(type: 'photoAssetAvailable', callback: AsyncCallback\<photoAccessHelper.PhotoAsset\>): void

Subscribes to photo asset available events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'photoAssetAvailable'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoasset)\> | Yes  | Callback used to return the photo asset.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

function photoAssetAvailableCallback(err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): void {
  if (err) {
    console.info(`photoAssetAvailable error: ${JSON.stringify(err)}.`);
    return;
  }
  console.info('photoOutPutCallBack photoAssetAvailable');
  // You can use photoAsset to obtain image information.
}

function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('photoAssetAvailable', photoAssetAvailableCallback);
}
```

### off('photoAssetAvailable')<sup>12+</sup>

off(type: 'photoAssetAvailable', callback?: AsyncCallback\<photoAccessHelper.PhotoAsset\>): void

Unsubscribes from photo asset available events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory | Description                                                                        |
| -------- | ---------- |-----|----------------------------------------------------------------------------|
| type     | string     | Yes  | Event type. The value is fixed at **'photoAssetAvailable'**. The event can be listened for when a **photoOutput** instance is created.                        |
| callback | AsyncCallback\<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoasset)\> | No  | Callback used for unsubscription. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function offPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('photoAssetAvailable');
}
```

### isMirrorSupported

isMirrorSupported(): boolean

Checks whether mirror photography is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | **true**: Mirror photography is supported.<br>**false**: Mirror photography is not supported.|

**Example**

```ts
function isMirrorSupported(photoOutput: camera.PhotoOutput): boolean {
  let isSupported: boolean = photoOutput.isMirrorSupported();
  return isSupported;
}
```

### enableMirror<sup>13+</sup>

enableMirror(enabled: boolean): void

Enables mirror photography.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                       |
|----------| ---------------------- | ---- |---------------------------|
| enabled | boolean                | Yes  | Whether to enable mirror photography. The value **true** means to enable it, and **false** means to diable it.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID   | Error Message                                          |
| -------- |------------------------------------------------|
| 7400101  | Parameter missing or parameter type incorrect. |
| 7400103  | Session not config.                    |
| 7400201  | Camera service fatal error.            |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableMirror(photoOutput: camera.PhotoOutput): void {
  try {
    photoOutput.enableMirror(true);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The enableMirror call failed. error code: ${err.code}`);
  }
}
```

### getSupportedMovingPhotoVideoCodecTypes<sup>13+</sup>

getSupportedMovingPhotoVideoCodecTypes(): Array\<VideoCodecType\>

Obtains the supported video codec types of moving photos.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description               |
| -------------- |-------------------|
| Array\<[VideoCodecType](#videocodectype13)\> | Array holding the supported video codec types.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID       | Error Message                     |
| --------------- | ---------------               |
| 7400201         |  Camera service fatal error.  |

**Example**

```ts
function getSupportedMovingPhotoVideoCodecType(photoOutput: camera.PhotoOutput): Array<camera.VideoCodecType> {
  let supportedVideoCodecTypesArray: Array<camera.VideoCodecType> = photoOutput.getSupportedMovingPhotoVideoCodecTypes();
  return supportedVideoCodecTypesArray;
}
```

### setMovingPhotoVideoCodecType<sup>13+</sup>

setMovingPhotoVideoCodecType(codecType: VideoCodecType): void

Sets a video codec type for moving photos.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                                 | Mandatory|  Description               |
| ------------- |-------------------------------------|-------| ------------        |
| codecType     | [VideoCodecType](#videocodectype13) |  Yes   |Video codec type. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID       | Error Message                     |
| --------------- | ---------------               |
| 7400201         |  Camera service fatal error.  |

**Example**

```ts
function setMovingPhotoVideoCodecTypes(photoOutput: camera.PhotoOutput, videoCodecType: camera.VideoCodecType): void {
   photoOutput.setMovingPhotoVideoCodecType(videoCodecType);
}
```

### on('captureStart')<sup>(deprecated)</sup>

on(type: 'captureStart', callback: AsyncCallback\<number\>): void

Subscribes to capture start events. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [on('captureStartWithInfo')](#oncapturestartwithinfo11) instead.
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and returned when the bottom layer starts exposure each time a photo is taken.|
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the capture ID.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, captureId: number): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`photo capture started, captureId : ${captureId}`);
}

function registerPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureStart', callback);
}
```

### off('captureStart')<sup>(deprecated)</sup>

off(type: 'captureStart', callback?: AsyncCallback\<number\>): void

Unsubscribes from capture start events.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [off('captureStartWithInfo')](#offcapturestartwithinfo11) instead.
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<number\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureStart');
}
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo\>): void

Subscribes to frame shutter events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'frameShutter'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[FrameShutterInfo](#frameshutterinfo)\> | Yes  | Callback used to return the result. A new photographing request can be delivered as long as this event is returned.            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, frameShutterInfo: camera.FrameShutterInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`CaptureId for frame : ${frameShutterInfo.captureId}`);
  console.info(`Timestamp for frame : ${frameShutterInfo.timestamp}`);
}

function registerPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('frameShutter', callback);
}
```

### off('frameShutter')

off(type: 'frameShutter', callback?: AsyncCallback\<FrameShutterInfo\>): void

Unsubscribes from frame shutter events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'frameShutter'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[FrameShutterInfo](#frameshutterinfo)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('frameShutter');
}
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo\>): void

Subscribes to capture end events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding information is returned when the photographing is complete.|
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | Yes  | Callback used to return the result.                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, captureEndInfo: camera.CaptureEndInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
  console.info(`frameCount : ${captureEndInfo.frameCount}`);
}

function registerPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureEnd', callback);
}
```

### off('captureEnd')

off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo\>): void

Unsubscribes from capture end events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureEnd');
}
```

### on('frameShutterEnd')<sup>12+</sup>

on(type: 'frameShutterEnd', callback: AsyncCallback\<FrameShutterEndInfo\>): void

Subscribes to frame shutter end events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'frameShutterEnd'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[FrameShutterEndInfo](#frameshutterendinfo12)\> | Yes  | Callback used to return the result. It is invoked when the frame shutter ends.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, frameShutterEndInfo: camera.FrameShutterEndInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`CaptureId for frame : ${frameShutterEndInfo.captureId}`);
}

function registerPhotoOutputFrameShutterEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('frameShutterEnd', callback);
}
```

### off('frameShutterEnd')<sup>12+</sup>

off(type: 'frameShutterEnd', callback?: AsyncCallback\<FrameShutterEndInfo\>): void

Unsubscribes from frame shutter end events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'frameShutterEnd'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[FrameShutterEndInfo](#frameshutterendinfo12)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputFrameShutterEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('frameShutterEnd');
}
```

### on('captureReady')<sup>12+</sup>

on(type: 'captureReady', callback: AsyncCallback\<void\>): void

Subscribes to capture ready events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| type     | string                | Yes  | Event type. The value is fixed at **'captureReady'**. The event can be listened for when a **photoOutput** instance is created. The event is triggered and the corresponding information is returned when it is ready to take the next photo.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`photo capture ready`);
}

function registerPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureReady', callback);
}
```

### off('captureReady')<sup>12+</sup>

off(type: 'captureReady', callback?: AsyncCallback\<void\>): void

Unsubscribes from capture ready events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                               | Yes  | Event type. The value is fixed at **'captureReady'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[CaptureReadyInfo](#captureendinfo)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureReady');
}
```

### on('estimatedCaptureDuration')<sup>12+</sup>

on(type: 'estimatedCaptureDuration', callback: AsyncCallback\<number\>): void

Subscribes to estimated capture duration events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'estimatedCaptureDuration'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding information is returned when the photographing is complete.|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the estimated duration when the sensor captures frames at the bottom layer in a single capture. If **–1** is reported, there is no estimated duration.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, duration: number): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`photo estimated capture duration : ${duration}`);
}

function registerPhotoOutputEstimatedCaptureDuration(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('estimatedCaptureDuration', callback);
}
```

### off('estimatedCaptureDuration')<sup>12+</sup>

off(type: 'estimatedCaptureDuration', callback?: AsyncCallback\<number\>): void

Unsubscribes from estimated capture duration events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'estimatedCaptureDuration'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<number\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputEstimatedCaptureDuration(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('estimatedCaptureDuration');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PhotoOutput** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a photo-related API.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Photo output error code: ${err.code}`);
}

function registerPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('error', callback);
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PhotoOutput** error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('error');
}
```

### getActiveProfile<sup>12+</sup>

getActiveProfile(): Profile

Obtains the profile that takes effect currently.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [Profile](#profile) | Profile obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400201 | Camera service fatal error.  |

**Example**

```ts
function testGetActiveProfile(photoOutput: camera.PhotoOutput): camera.Profile | undefined {
  let activeProfile: camera.Profile | undefined = undefined;
  try {
    activeProfile = photoOutput.getActiveProfile();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The photoOutput.getActiveProfile call failed. error code: ${err.code}`);
  }
  return activeProfile;
}
```
### getPhotoRotation<sup>12+</sup>

getPhotoRotation(deviceDegree: number): ImageRotation

Obtains the photo rotation degree.

- Device' natural orientation: The default orientation of the device (phone) is in portrait mode, with the charging port facing downward.
- Camera lens angle: equivalent to the angle at which the camera is rotated clockwise to match the device's natural direction. The rear camera sensor of a phone is installed in landscape mode. Therefore, it needs to be rotated by 90 degrees clockwise to match the device's natural direction.
- Screen orientation: The upper left corner of the image displayed on the screen is the first pixel, which is the coordinate origin. In the case of lock screen, the direction is the same as the device's natural orientation.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| deviceDegree | number | Yes  | Rotation angle.|

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [ImageRotation](#imagerotation) | Photo rotation degree.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.  |
| 7400201 | Camera service fatal error.  |

**Example**

```ts
function testGetPhotoRotation(photoOutput: camera.PhotoOutput, deviceDegree : number): camera.ImageRotation {
  let photoRotation: camera.ImageRotation = camera.ImageRotation.ROTATION_0;
  try {
    photoRotation = photoOutput.getPhotoRotation(deviceDegree);
    console.log(`Photo rotation is: ${photoRotation}`);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The photoOutput.getPhotoRotation call failed. error code: ${err.code}`);
  }
  return photoRotation;
}
```

## FrameShutterInfo

Defines the frame shutter information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type  | Read-only| Optional| Description       |
| --------- | ------ | ---- | ---- | ---------- |
| captureId | number | No  | No  | ID of this capture action. |
| timestamp | number | No  | No  | Timestamp when the frame shutter event is triggered.|

## FrameShutterEndInfo<sup>12+</sup>

Describes the frame shutter end information during capture.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  | Read-only| Optional| Description      |
| --------- | ------ | ---- | ---- | ---------- |
| captureId | number | No  | No  | ID of this capture action.|

## CaptureStartInfo<sup>11+</sup>

Defines the capture start information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type   | Read-only| Optional| Description      |
| ---------- | ------ | ---- | ---- | --------- |
| captureId  | number | No  | No  | ID of this capture action.|
| time       | number | No  | No  | Estimated duration when the sensor captures frames at the bottom layer in a single capture. If **–1** is reported, there is no estimated duration.   |

## CaptureEndInfo

Defines the capture end information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type   | Read-only| Optional| Description      |
| ---------- | ------ | ---- | ---- | ---------|
| captureId  | number | No  | No  | ID of this capture action.|
| frameCount | number | No  | No  | Number of frames captured.   |

## AutoDeviceSwitchStatus<sup>13+</sup>

Describes the information about the automatic camera switch status.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type     | Read-only| Optional| Description                     |
| ---------- |---------| ---- | ---- |-------------------------|
| isDeviceSwitched  | boolean | No  | No  | Whether the camera is automatically switched.            |
| isDeviceCapabilityChanged | boolean  | No  | No  | Whether the camera capability is changed after the camera is automatically switched.|

## VideoOutput

Implements output information used in a video session. It inherits from [CameraOutput](#cameraoutput).

### start

start(callback: AsyncCallback\<void\>): void

Starts video recording. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the video output, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the video output start success.');
  });
}
```

### start

start(): Promise\<void\>

Starts video recording. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.start().then(() => {
    console.info('Promise returned to indicate that start method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to video output start, error code: ${error.code}.`);
  });
}
```

### stop

stop(callback: AsyncCallback\<void\>): void

Stops video recording. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the video output, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the video output stop success.');
  });
}
```

### stop

stop(): Promise\<void\>

Stops video recording. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.stop().then(() => {
    console.info('Promise returned to indicate that stop method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to video output stop, error code: ${error.code}.`);
  });
}
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

Subscribes to video recording start events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **videoOutput** instance is created. The event is triggered and the corresponding information is returned when the bottom layer starts exposure for the first time.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  The recording starts as long as this event is returned.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info('Video frame started');
}

function registerVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameStart', callback);
}
```

### off('frameStart')

off(type: 'frameStart', callback?: AsyncCallback\<void\>): void

Unsubscribes from video recording start events.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **videoOutput** instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.off('frameStart');
}

```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback\<void\>): void

Subscribes to video recording stop events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a **videoOutput** instance is created. This event is triggered and returned when the last frame of recording is complete.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. The recording ends as long as this event is returned.                     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info('Video frame ended');
}

function registerVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameEnd', callback);
}
```

### off('frameEnd')

off(type: 'frameEnd', callback?: AsyncCallback\<void\>): void

Unsubscribes from video recording stop events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a **videoOutput** instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.off('frameEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **VideoOutput** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type      | Mandatory| Description                                   |
| -------- | ----------- | ---- | -------------------------------------- |
| type     | string      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **videoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a recording-related API such as [start](#start-1) or [CameraOutput.release](#release-1).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Video output error code: ${err.code}`);
}

function registerVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.on('error', callback);
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **VideoOutput** error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.off('error');
}
```

### getSupportedFrameRates<sup>12+</sup>

getSupportedFrameRates(): Array\<FrameRateRange\>

Obtains the supported frame rates.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     |     Description    |
| -------------  | ------------ |
| Array<[FrameRateRange](#frameraterange)> | Array of supported frame rates.|

**Example**

```ts
function getSupportedFrameRates(videoOutput: camera.VideoOutput): Array<camera.FrameRateRange> {
  let supportedFrameRatesArray: Array<camera.FrameRateRange> = videoOutput.getSupportedFrameRates();
  return supportedFrameRatesArray;
}
```

### setFrameRate<sup>12+</sup>

setFrameRate(minFps: number, maxFps: number): void

Sets a frame rate range for video streams. The range must be within the supported frame rate range, which can be obtained by calling [getSupportedFrameRates](#getsupportedframerates12-1).

> **NOTE**
>
> This API is valid only in [PhotoSession](#photosession11) or [VideoSession](#videosession11) mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| minFps   | number        | Yes  | Minimum frame rate.|
| maxFps   | number        | Yes  | Maximum frame rate. When the minimum value is greater than the maximum value, the API does not take effect.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID       | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400110                |  Unresolved conflicts with current configurations.     |

**Example**

```ts
function setFrameRateRange(videoOutput: camera.VideoOutput, frameRateRange: Array<number>): void {
  videoOutput.setFrameRate(frameRateRange[0], frameRateRange[1]);
}
```

### getActiveFrameRate<sup>12+</sup>

getActiveFrameRate(): FrameRateRange

Obtains the configured frame rate range.

This API is valid only after [setFrameRate](#setframerate12-1) is called to set a frame rate range for video streams.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     |     Description    |
| -------------  | ------------ |
| [FrameRateRange](#frameraterange) | Frame rate range.|

**Example**

```ts
function getActiveFrameRate(videoOutput: camera.VideoOutput): camera.FrameRateRange {
  let activeFrameRate: camera.FrameRateRange = videoOutput.getActiveFrameRate();
  return activeFrameRate;
}
```

### getActiveProfile<sup>12+</sup>

getActiveProfile(): VideoProfile

Obtains the profile that takes effect currently.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [VideoProfile](#videoprofile) | Profile obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400201 | Camera service fatal error.  |

**Example**

```ts
function testGetActiveProfile(videoOutput: camera.VideoOutput): camera.Profile | undefined {
  let activeProfile: camera.VideoProfile | undefined = undefined;
  try {
    activeProfile = videoOutput.getActiveProfile();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The videoOutput.getActiveProfile call failed. error code: ${err.code}`);
  }
  return activeProfile;
}
```

### getVideoRotation<sup>12+</sup>

getVideoRotation(deviceDegree: number): ImageRotation

Obtains the video rotation degree.

- Device' natural orientation: The default orientation of the device (phone) is in portrait mode, with the charging port facing downward.
- Camera lens angle: equivalent to the angle at which the camera is rotated clockwise to match the device's natural direction. The rear camera sensor of a phone is installed in landscape mode. Therefore, it needs to be rotated by 90 degrees clockwise to match the device's natural direction.
- Screen orientation: The upper left corner of the image displayed on the screen is the first pixel, which is the coordinate origin. In the case of lock screen, the direction is the same as the device's natural orientation.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| deviceDegree | number | Yes  | Rotation angle.|

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [ImageRotation](#imagerotation) | Video rotation degree.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.  |
| 7400201 | Camera service fatal error.  |

**Example**

```ts
function testGetVideoRotation(videoOutput: camera.VideoOutput, deviceDegree : number): camera.ImageRotation {
  let videoRotation: camera.ImageRotation = camera.ImageRotation.ROTATION_0;
  try {
    videoRotation = videoOutput.getVideoRotation(deviceDegree);
    console.log(`Video rotation is: ${videoRotation}`);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The videoOutput.getVideoRotation call failed. error code: ${err.code}`);
  }
  return videoRotation;
}
```

## MetadataOutput

Implements metadata streams. It inherits from [CameraOutput](#cameraoutput).

### start

start(callback: AsyncCallback\<void\>): void

Starts to output metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\>       | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start metadata output, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with metadata output started.');
  });
}
```

### start

start(): Promise\<void\>

Starts to output metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                    | Description                    |
| ----------------------  | ------------------------ |
| Promise\<void\>          | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.start().then(() => {
    console.info('Callback returned with metadata output started.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to metadata output stop, error code: ${error.code}`);
  });
}
```

### stop

stop(callback: AsyncCallback\<void\>): void

Stops outputting metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                        | Mandatory| Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\>       | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the metadata output, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with metadata output stopped.');
  })
}
```

### stop

stop(): Promise\<void\>

Stops outputting metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                   | Description                       |
| ----------------------  | --------------------------- |
| Promise\<void\>         | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.stop().then(() => {
    console.info('Callback returned with metadata output stopped.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to metadata output stop, error code: ${error.code}`);
  });
}
```

### on('metadataObjectsAvailable')

on(type: 'metadataObjectsAvailable', callback: AsyncCallback\<Array\<MetadataObject\>\>): void

Subscribes to events indicating available metadata objects. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type        | Mandatory| Description                                 |
| -------- | -------------- | ---- | ------------------------------------ |
| type     | string         | Yes  | Event type. The value is fixed at **'metadataObjectsAvailable'**. The event can be listened for when a **metadataOutput** instance is created. This event is triggered and the corresponding metadata is returned when valid metadata is detected.|
| callback | AsyncCallback\<Array\<[MetadataObject](#metadataobject)\>\> | Yes  | Callback used to return the metadata.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info('metadata output metadataObjectsAvailable');
}

function registerMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.on('metadataObjectsAvailable', callback);
}
```

### off('metadataObjectsAvailable')

off(type: 'metadataObjectsAvailable', callback?: AsyncCallback\<Array\<MetadataObject\>\>): void

Unsubscribes from events indicating available metadata objects.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type        | Mandatory| Description                                 |
| -------- | -------------- | ---- | ------------------------------------ |
| type     | string         | Yes  | Event type. The value is fixed at **'metadataObjectsAvailable'**. The event can be listened for when a **metadataOutput** instance is created.|
| callback | AsyncCallback\<Array\<[MetadataObject](#metadataobject)\>\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.off('metadataObjectsAvailable');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to metadata error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                    |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **metadataOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a metadata-related API such as [start](#start-3) or [CameraOutput.release](#release-1).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(metadataOutputError: BusinessError): void {
  console.error(`Metadata output error code: ${metadataOutputError.code}`);
}

function registerMetadataOutputError(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.on('error', callback);
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from metadata error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                    |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **metadataOutput** instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterMetadataOutputError(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.off('error');
}
```

## MetadataObjectType

Enumerates the metadata object types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description             |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | Metadata object used for face detection.<br> The detection point must be in the coordinate system (0-1), where the upper left corner is (0, 0) and the lower right corner is (1, 1).<br> The coordinate system is based on the horizontal device direction with the device's charging port on the right.<br>If the layout of a preview screen of an application is based on the vertical direction with the charging port on the lower side,<br>the layout width and height are (w, h) and the return point is (x, y), then the coordinate point after conversion is (1-y, x).|

## Rect

Defines a rectangle.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  |  Read-only | Optional |           Description        |
| -------- | ------ | ------ |-----| --------------------- |
| topLeftX | number |   No  | No  | X-axis coordinate of the upper left corner of the rectangle.  |
| topLeftY | number |   No  | No  | Y-axis coordinate of the upper left corner of the rectangle.  |
| width    | number |   No  | No  | Width of the rectangle, which is a relative value. The value range is [0, 1]. |
| height   | number |   No  | No  | Height of the rectangle, which is a relative value. The value range is [0, 1]. |

## MetadataObject

Implements camera metadata, which is the data source of [CameraInput](#camerainput). The metadata is obtained through metadataOutput.on('metadataObjectsAvailable').

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Type                                       | Read-only| Optional|Description               |
| ----------- | ------------------------------------------- | ---- | ---- | ----------------- |
| type        | [MetadataObjectType](#metadataobjecttype)   |  Yes |  No | Metadata object type.   |
| timestamp   | number                                      |  Yes |  No | Current timestamp, in milliseconds.|
| boundingBox | [Rect](#rect)                               |  Yes |  No | Metadata rectangle. |

## FlashMode

Enumerates the flash modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Value  | Description       |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | The flash is off.|
| FLASH_MODE_OPEN        | 1    | The flash is on.|
| FLASH_MODE_AUTO        | 2    | The flash mode is auto, indicating that the flash fires automatically depending on the photo capture conditions.|
| FLASH_MODE_ALWAYS_OPEN | 3    | The flash is steady on.|

## ExposureMode

Enumerates the exposure modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_LOCKED          | 0    | Exposure locked. The metering point cannot be set.|
| EXPOSURE_MODE_AUTO            | 1    | Auto exposure. The metering point can be set by calling [AutoExposure.setMeteringPoint](#setmeteringpoint11).|
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | Continuous auto exposure. The metering point cannot be set.|

## FocusMode

Enumerates the focus modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                       | Value  | Description         |
| -------------------------- | ---- | ------------ |
| FOCUS_MODE_MANUAL          | 0    | Manual focus. The focal length of the camera can be manually set to change the focus position. However, the focal point cannot be set.    |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | Continuous auto focus. The focal point cannot be set.|
| FOCUS_MODE_AUTO            | 2    | Auto focus. The focal point can be set by calling [Focus.setFocusPoint](#setfocuspoint11), and auto focus is performed once based on the focal point.   |
| FOCUS_MODE_LOCKED          | 3    | Focus locked. The focal point cannot be set.    |

## FocusState

Enumerates the focus states.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Value  | Description      |
| --------------------- | ---- | --------- |
| FOCUS_STATE_SCAN      | 0    | Focusing. |
| FOCUS_STATE_FOCUSED   | 1    | Focused. |
| FOCUS_STATE_UNFOCUSED | 2    | Unfocused.|

## VideoStabilizationMode

Enumerates the video stabilization modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Value  | Description        |
| --------- | ---- | ------------ |
| OFF       | 0    | Video stabilization is disabled.  |
| LOW       | 1    | The basic video stabilization algorithm is used.  |
| MIDDLE    | 2    | A video stabilization algorithm with a stabilization effect better than that of the **LOW** type is used.  |
| HIGH      | 3    | A video stabilization algorithm with a stabilization effect better than that of the **MIDDLE** type is used.  |
| AUTO      | 4    | Automatic video stabilization is used.  |

## Session<sup>11+</sup>

Implements a session, which saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera and requests the camera to take a photo or record a video.

### beginConfig<sup>11+</sup>

beginConfig(): void

Starts configuration for the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400105                |  Session config locked.               |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function beginConfig(session: camera.Session): void {
  try {
    session.beginConfig();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The beginConfig call failed. error code: ${err.code}`);
  }
}
```

### commitConfig<sup>11+</sup>

commitConfig(callback: AsyncCallback\<void\>): void

Commits the configuration for this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function commitConfig(session: camera.Session): void {
  session.commitConfig((err: BusinessError) => {
    if (err) {
      console.error(`The commitConfig call failed. error code: ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate the commit config success.');
  });
}
```

### commitConfig<sup>11+</sup>

commitConfig(): Promise\<void\>

Commits the configuration for this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function commitConfig(session: camera.Session): void {
  session.commitConfig().then(() => {
    console.info('Promise returned to indicate the commit config success.');
  }).catch((error: BusinessError) => {
    // If the operation fails, error.code is returned and processed.
    console.error(`The commitConfig call failed. error code: ${error.code}`);
  });
}
```

### canAddInput<sup>11+</sup>

canAddInput(cameraInput: CameraInput): boolean

Determines whether a **CameraInput** instance can be added to this session. This API must be called after [beginConfig](#beginconfig11) and before [commitConfig](#commitconfig11-1).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add. The API does not take effect if the input parameter is invalid (for example, the value is out of range, null, or undefined).|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| boolean | **true**: The **CameraInput** instance can be added.<br>**false**: The **CameraInput** instance cannot be added.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function canAddInput(session: camera.Session, cameraInput: camera.CameraInput): void {
  let canAdd: boolean = session.canAddInput(cameraInput);
  console.info(`The input canAddInput: ${canAdd}`);
}
```

### addInput<sup>11+</sup>

addInput(cameraInput: CameraInput): void

Adds a [CameraInput](#camerainput) instance to this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addInput(session: camera.Session, cameraInput: camera.CameraInput): void {
  try {
    session.addInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The addInput call failed. error code: ${err.code}`);
  }
}
```

### removeInput<sup>11+</sup>

removeInput(cameraInput: CameraInput): void

Removes a [CameraInput](#camerainput) instance from this session. This API must be called after [beginConfig](#beginconfig11) and before [commitConfig](#commitconfig11-1).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeInput(session: camera.Session, cameraInput: camera.CameraInput): void {
  try {
    session.removeInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The removeInput call failed. error code: ${err.code}`);
  }
}
```

### canAddOutput<sup>11+</sup>

canAddOutput(cameraOutput: CameraOutput): boolean

Determines whether a **CameraOutput** instance can be added to this session. This API must be called after [addInput](#addinput11) and before [commitConfig](#commitconfig11-1).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraOutput | [CameraOutput](#cameraoutput) | Yes  | **CameraOutput** instance to add. The API does not take effect if the input parameter is invalid (for example, the value is out of range, null, or undefined).|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| boolean | **true**: The **CameraOutput** instance can be added.<br>**false**: The **CameraOutput** instance cannot be added.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function canAddOutput(session: camera.Session, cameraOutput: camera.CameraOutput): void {
  let canAdd: boolean = session.canAddOutput(cameraOutput);
  console.info(`This addOutput can add: ${canAdd}`);
}
```

### addOutput<sup>11+</sup>

addOutput(cameraOutput: CameraOutput): void

Adds a [CameraOutput](#cameraoutput) instance to this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addOutput(session: camera.Session, cameraOutput: camera.CameraOutput): void {
  try {
    session.addOutput(cameraOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The addOutput call failed. error code: ${err.code}`);
  }
}
```

### removeOutput<sup>11+</sup>

removeOutput(cameraOutput: CameraOutput): void

Removes a [CameraOutput](#cameraoutput) instance from this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeOutput(session: camera.Session, previewOutput: camera.PreviewOutput): void {
  try {
    session.removeOutput(previewOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The removeOutput call failed. error code: ${err.code}`);
  }
}
```

### start<sup>11+</sup>

start(callback: AsyncCallback\<void\>): void

Starts this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startCaptureSession(session: camera.Session): void {
  session.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session start success.');
  });
}
```

### start<sup>11+</sup>

start(): Promise\<void\>

Starts this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startCaptureSession(session: camera.Session): void {
  session.start().then(() => {
    console.info('Promise returned to indicate the session start success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to start the session, error code: ${error.code}.`);
  });
}
```

### stop<sup>11+</sup>

stop(callback: AsyncCallback\<void\>): void

Stops this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopCaptureSession(session: camera.Session): void {
  session.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session stop success.');
  });
}
```

### stop<sup>11+</sup>

stop(): Promise\<void\>

Stops this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description               |
| -------------- |-------------------|
| Promise\<void\> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopCaptureSession(session: camera.Session): void {
  session.stop().then(() => {
    console.info('Promise returned to indicate the session stop success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to stop the session, error code: ${error.code}.`);
  });
}
```

### release<sup>11+</sup>

release(callback: AsyncCallback\<void\>): void

Releases this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releaseCaptureSession(session: camera.Session): void {
  session.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the session instance, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate that the session instance is released successfully.');
  });
}
```

### release<sup>11+</sup>

release(): Promise\<void\>

Releases this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releaseCaptureSession(session: camera.Session): void {
  session.release().then(() => {
    console.info('Promise returned to indicate that the session instance is released successfully.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to release the session instance, error code: ${error.code}.`);
  });
}
```

## Flash<sup>11+</sup>

Flash extends [FlashQuery](#flashquery12)

Provides APIs related to the flash.

### setFlashMode<sup>11+</sup>

setFlashMode(flashMode: FlashMode): void

Sets a flash mode.

Before the setting, do the following checks:

1. Use [hasFlash](#hasflash11) to check whether the camera device has flash.
2. Use [isFlashModeSupported](#isflashmodesupported11) to check whether the camera device supports the flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                 |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode. If the input parameter is null or undefined, it is treated as 0 and the flash is turned off.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFlashMode(photoSession: camera.PhotoSession): void {
  try {
    photoSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFlashMode call failed. error code: ${err.code}`);
  }
}
```

### getFlashMode<sup>11+</sup>

getFlashMode(): FlashMode

Obtains the flash mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FlashMode](#flashmode)    | Flash mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFlashMode(photoSession: camera.PhotoSession): camera.FlashMode | undefined {
  let flashMode: camera.FlashMode | undefined = undefined;
  try {
    flashMode = photoSession.getFlashMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFlashMode call failed.error code: ${err.code}`);
  }
  return flashMode;
}
```

## FlashQuery<sup>12+</sup>

Provides APIs to query the flash status and mode of a camera device.

### hasFlash<sup>11+</sup>

hasFlash(): boolean

Checks whether the camera device has flash. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The camera device has flash.<br>**false**: The camera device does not have flash. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function hasFlash(photoSession: camera.PhotoSession): boolean {
  let status: boolean = false;
  try {
    status = photoSession.hasFlash();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The hasFlash call failed. error code: ${err.code}`);
  }
  return status;
}
```

### isFlashModeSupported<sup>11+</sup>

isFlashModeSupported(flashMode: FlashMode): boolean

Checks whether a flash mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                              |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode. If the input parameter is null or undefined, it is treated as 0 and the flash is turned off.            |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The flash mode is supported.<br>**false**: The flash mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFlashModeSupported(photoSession: camera.PhotoSession): boolean {
  let status: boolean = false;
  try {
    status = photoSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFlashModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## AutoExposure<sup>11+</sup>

AutoExposure extends [AutoExposureQuery](#autoexposurequery12)

Provides APIs related to auto exposure.

### getExposureMode<sup>11+</sup>

getExposureMode(): ExposureMode

Obtains the exposure mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [ExposureMode](#exposuremode)    | Exposure mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMode(photoSession: camera.PhotoSession): camera.ExposureMode | undefined {
  let exposureMode: camera.ExposureMode | undefined = undefined;
  try {
    exposureMode = photoSession.getExposureMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureMode call failed. error code: ${err.code}`);
  }
  return exposureMode;
}
```

### setExposureMode<sup>11+</sup>

setExposureMode(aeMode: ExposureMode): void

Sets an exposure mode. Before the setting, call [isExposureModeSupported](#isexposuremodesupported11) to check whether the target exposure mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode. If the input parameter is null or undefined, it is treated as 0 and exposure is locked.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMode(photoSession: camera.PhotoSession): void {
  try {
    photoSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setExposureMode call failed. error code: ${err.code}`);
  }
}
```

### getMeteringPoint<sup>11+</sup>

getMeteringPoint(): Point

Obtains the metering point of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Metering point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMeteringPoint(photoSession: camera.PhotoSession): camera.Point | undefined {
  let exposurePoint: camera.Point | undefined = undefined;
  try {
    exposurePoint = photoSession.getMeteringPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);
  }
  return exposurePoint;
}
```

### setMeteringPoint<sup>11+</sup>

setMeteringPoint(point: Point): void

Sets the metering point, which is the center point of the metering rectangle.

The metering point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| point | [Point](#point)                | Yes  | Metering point. The value range of x and y must be within [0, 1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.            |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMeteringPoint(photoSession: camera.PhotoSession): void {
  const point: camera.Point = {x: 1, y: 1};
  try {
    photoSession.setMeteringPoint(point);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

### setExposureBias<sup>11+</sup>

setExposureBias(exposureBias: number): void

Sets an exposure compensation value (EV).

Before the setting, you are advised to use [getExposureBiasRange](#getexposurebiasrange11) to obtain the supported values.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                                                                                                                                                                           |
| -------- | -------------------------------| ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| exposureBias   | number                   | Yes  | EV. The supported EV range can be obtained by calling [getExposureBiasRange](#getexposurebiasrange11). If the value passed is not within the supported range, the nearest critical point is used.<br>There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0.<br>If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureBias(photoSession: camera.PhotoSession, biasRangeArray: Array<number>): void {
  if (biasRangeArray && biasRangeArray.length > 0) {
    let exposureBias = biasRangeArray[0];
    try {
      photoSession.setExposureBias(exposureBias);
    } catch (error) {
      // If the operation fails, error.code is returned and processed.
      let err = error as BusinessError;
      console.error(`The setExposureBias call failed. error code: ${err.code}`);
    }
  }
}
```

### getExposureValue<sup>11+</sup>

getExposureValue(): number

Obtains the exposure value in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Exposure value obtained. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0.<br>If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureValue(photoSession: camera.PhotoSession): number {
  const invalidValue: number = -1;
  let exposureValue: number = invalidValue;
  try {
    exposureValue = photoSession.getExposureValue();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureValue call failed. error code: ${err.code}`);
  }
  return exposureValue;
}
```

## AutoExposureQuery<sup>12+</sup>

Provides APIs to query the automatic exposure feature of a camera device.

### isExposureModeSupported<sup>11+</sup>

isExposureModeSupported(aeMode: ExposureMode): boolean

Checks whether an exposure mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode. If the input parameter is null or undefined, it is treated as 0 and exposure is locked.                |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The exposure mode is supported.<br>**false**: The exposure mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isExposureModeSupported(photoSession: camera.PhotoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = photoSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isExposureModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### getExposureBiasRange<sup>11+</sup>

getExposureBiasRange(): Array\<number\>

Obtains the exposure compensation values of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Array of compensation values. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureBiasRange(photoSession: camera.PhotoSession): Array<number> {
  let biasRangeArray: Array<number> = [];
  try {
    biasRangeArray = photoSession.getExposureBiasRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureBiasRange call failed. error code: ${err.code}`);
  }
  return biasRangeArray;
}
```

## Focus<sup>11+</sup>

Focus extends [FocusQuery](#focusquery12)

Provides APIs related to focus operations.

### setFocusMode<sup>11+</sup>

setFocusMode(afMode: FocusMode): void

Sets a focus mode.

Before the setting, call [isFocusModeSupported](#isfocusmodesupported11) to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode. If the input parameter is null or undefined, it is treated as 0 and manual focus is used.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusMode(photoSession: camera.PhotoSession): void {
  try {
    photoSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusMode call failed. error code: ${err.code}`);
  }
}
```

### getFocusMode<sup>11+</sup>

getFocusMode(): FocusMode

Obtains the focus mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FocusMode](#focusmode)   | Focus mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusMode(photoSession: camera.PhotoSession): camera.FocusMode | undefined {
  let afMode: camera.FocusMode | undefined = undefined;
  try {
    afMode = photoSession.getFocusMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusMode call failed. error code: ${err.code}`);
  }
  return afMode;
}
```

### setFocusPoint<sup>11+</sup>

setFocusPoint(point: Point): void

Sets the focal point. The focal point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](#point)         | Yes  | Focal point. The value range of x and y must be within [0, 1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusPoint(photoSession: camera.PhotoSession): void {
  const focusPoint: camera.Point = {x: 1, y: 1};
  try {
    photoSession.setFocusPoint(focusPoint);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);
  }
}
```

### getFocusPoint<sup>11+</sup>

getFocusPoint(): Point

Obtains the focal point of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Focal point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusPoint(photoSession: camera.PhotoSession): camera.Point | undefined {
  let point: camera.Point | undefined = undefined;
  try {
    point = photoSession.getFocusPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusPoint call failed. error code: ${err.code}`);
  }
  return point;
}
```

### getFocalLength<sup>11+</sup>

getFocalLength(): number

Obtains the focal length of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Focal length, in mm. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocalLength(photoSession: camera.PhotoSession): number {
  const invalidValue: number = -1;
  let focalLength: number = invalidValue;
  try {
    focalLength = photoSession.getFocalLength();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocalLength call failed. error code: ${err.code}`);
  }
  return focalLength;
}
```

## FocusQuery<sup>12+</sup>

Provides APIs to check whether a focus mode is supported.

### isFocusModeSupported<sup>11+</sup>

isFocusModeSupported(afMode: FocusMode): boolean

Checks whether a focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                             |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode. If the input parameter is null or undefined, it is treated as 0 and manual focus is used.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The focus mode is supported.<br>**false**: The focus mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusModeSupported(photoSession: camera.PhotoSession): boolean {
  let status: boolean = false;
  try {
    status = photoSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## SmoothZoomMode<sup>11+</sup>

Enumerates the smooth zoom modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Value  | Description           |
| ------------ | ---- | -------------- |
| NORMAL       | 0    | Bessel curve mode. |

## SmoothZoomInfo<sup>11+</sup>

Defines the smooth zoom information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  |   Optional  | Description      |
| -------- | ---------- | -------- | -------- | ---------- |
| duration |   number   |   No    |    No   | Total duration of smooth zoom, in ms.|

## Zoom<sup>11+</sup>

Zoom extends [ZoomQuery](#zoomquery12)

Provides APIs related to zoom operations.

### setZoomRatio<sup>11+</sup>

setZoomRatio(zoomRatio: number): void

Sets a zoom ratio, with a maximum precision of two decimal places.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                 | Mandatory| Description                                                                                                                             |
| --------- | -------------------- | ---- |---------------------------------------------------------------------------------------------------------------------------------|
| zoomRatio | number               | Yes  | Zoom ratio. The supported zoom ratio range can be obtained by calling [getZoomRatioRange](#getzoomratiorange11). If the value passed in is not within the supported range, the value within the precision range is retained.<br>It takes some time for the zoom ratio to take effect at the bottom layer. To obtain the correct zoom ratio, you need to wait for one to two frames.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setZoomRatio(photoSession: camera.PhotoSession, zoomRatioRange: Array<number>): void {
  if (zoomRatioRange === undefined || zoomRatioRange.length <= 0) {
    return;
  }
  let zoomRatio = zoomRatioRange[0];
  try {
    photoSession.setZoomRatio(zoomRatio);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setZoomRatio call failed. error code: ${err.code}`);
  }
}
```

### getZoomRatio<sup>11+</sup>

getZoomRatio(): number

Obtains the zoom ratio in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Zoom ratio obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatio(photoSession: camera.PhotoSession): number {
  const invalidValue: number = -1;
  let zoomRatio: number = invalidValue;
  try {
    zoomRatio = photoSession.getZoomRatio();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getZoomRatio call failed. error code: ${err.code}`);
  }
  return zoomRatio;
}
```

### setSmoothZoom<sup>11+</sup>

setSmoothZoom(targetRatio: number, mode?: SmoothZoomMode): void

Sets smooth zoom.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type           | Mandatory| Description              |
| ------------ | -------------- | ---- | ----------------- |
| targetRatio  | number         | Yes  | Target zoom ratio.     |
| mode         | [SmoothZoomMode](#smoothzoommode11) | No  | Smooth zoom mode.     |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setSmoothZoom(sessionExtendsZoom: camera.Zoom, targetZoomRatio: number, mode: camera.SmoothZoomMode): void {
  try {
    sessionExtendsZoom.setSmoothZoom(targetZoomRatio, mode);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setSmoothZoom call failed. error code: ${err.code}`);
  }
}
```

## ZoomQuery<sup>12+</sup>

Provides APIs to query the zoom feature of a device camera, including the API to obtain the supported zoom ratio range.

### getZoomRatioRange<sup>11+</sup>

getZoomRatioRange(): Array\<number\>

Obtains the supported zoom ratio range.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Array containing the minimum and maximum zoom ratios. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatioRange(photoSession: camera.PhotoSession): Array<number> {
  let zoomRatioRange: Array<number> = [];
  try {
    zoomRatioRange = photoSession.getZoomRatioRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getZoomRatioRange call failed. error code: ${err.code}`);
  }
  return zoomRatioRange;
}
```

## Stabilization<sup>11+</sup>

Stabilization extends [StabilizationQuery](#stabilizationquery12)

Provides APIs to set video stabilization.

 > **NOTE**
 >
 > You can set video stabilization only when a [VideoOutput](#videooutput) stream exists in the session.
 > The enumerated value **HIGH** of [VideoStabilizationMode](#videostabilizationmode) takes effect only when the resolution of [Profile](#profile) is 1920 x 1080.

### getActiveVideoStabilizationMode<sup>11+</sup>

getActiveVideoStabilizationMode(): VideoStabilizationMode

Obtains the video stabilization mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description         |
| ---------- |-------------|
| [VideoStabilizationMode](#videostabilizationmode)    | Video stabilization mode obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getActiveVideoStabilizationMode(videoSession: camera.VideoSession): camera.VideoStabilizationMode | undefined {
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;
  try {
    vsMode = videoSession.getActiveVideoStabilizationMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);
  }
  return vsMode;
}
```

### setVideoStabilizationMode<sup>11+</sup>

setVideoStabilizationMode(mode: VideoStabilizationMode): void

Sets a video stabilization mode. Before the setting, call [isVideoStabilizationModeSupported](#isvideostabilizationmodesupported11) to check whether the target video stabilization mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setVideoStabilizationMode(videoSession: camera.VideoSession): void {
  try {
    videoSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);
  }
}
```

## StabilizationQuery<sup>12+</sup>

Provides APIs to check the support for video stabilization.

### isVideoStabilizationModeSupported<sup>11+</sup>

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean

Checks whether a video stabilization mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                            |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The video stabilization mode is supported.<br>**false**: The video stabilization mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isVideoStabilizationModeSupported(videoSession: camera.VideoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = videoSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isVideoStabilizationModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## CaptureSession<sup>(deprecated)</sup>

Implements a capture session, which saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera and requests the camera to complete shooting or video recording.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [PhotoSession](#photosession11) and [VideoSession](#videosession11) instead.

### beginConfig<sup>(deprecated)</sup>

beginConfig(): void

Starts configuration for the session.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.beginConfig](#beginconfig11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400105         |  Session config locked.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function beginConfig(captureSession: camera.CaptureSession): void {
  try {
    captureSession.beginConfig();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The beginConfig call failed. error code: ${err.code}`);
  }
}
```

### commitConfig<sup>(deprecated)</sup>

commitConfig(callback: AsyncCallback\<void\>): void

Commits the configuration for this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.commitConfig](#commitconfig11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig((err: BusinessError) => {
    if (err) {
      console.error(`The commitConfig call failed. error code: ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate the commit config success.');
  });
}
```

### commitConfig<sup>(deprecated)</sup>

commitConfig(): Promise\<void\>

Commits the configuration for this session. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.commitConfig](#commitconfig11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description               |
| -------------- |-------------------|
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig().then(() => {
    console.info('Promise returned to indicate the commit config success.');
  }).catch((error: BusinessError) => {
    // If the operation fails, error.code is returned and processed.
    console.error(`The commitConfig call failed. error code: ${error.code}`);
  });
}
```

### addInput<sup>(deprecated)</sup>

addInput(cameraInput: CameraInput): void

Adds a [CameraInput](#camerainput) instance to this session.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.addInput](#addinput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                         |
|---------|-----------------------------------------------|
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.addInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The addInput call failed. error code: ${err.code}`);
  }
}
```

### removeInput<sup>(deprecated)</sup>

removeInput(cameraInput: CameraInput): void

Removes a [CameraInput](#camerainput) instance from this session.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.removeInput](#removeinput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.removeInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The removeInput call failed. error code: ${err.code}`);
  }
}
```

### addOutput<sup>(deprecated)</sup>

addOutput(cameraOutput: CameraOutput): void

Adds a [CameraOutput](#cameraoutput) instance to this session.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.addOutput](#addoutput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {
  try {
    captureSession.addOutput(cameraOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The addOutput call failed. error code: ${err.code}`);
  }
}
```

### removeOutput<sup>(deprecated)</sup>

removeOutput(cameraOutput: CameraOutput): void

Removes a [CameraOutput](#cameraoutput) instance from this session.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.removeOutput](#removeoutput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeOutput(captureSession: camera.CaptureSession, previewOutput: camera.PreviewOutput): void {
  try {
    captureSession.removeOutput(previewOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The removeOutput call failed. error code: ${err.code}`);
  }
}
```

### start<sup>(deprecated)</sup>

start(callback: AsyncCallback\<void\>): void

Starts this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](#start11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session start success.');
  });
}
```

### start<sup>(deprecated)</sup>

start(): Promise\<void\>

Starts this session. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](#start11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start().then(() => {
    console.info('Promise returned to indicate the session start success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start the session, error code: ${err.code}.`);
  });
}
```

### stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void\>): void

Stops this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](#stop11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session stop success.');
  });
}
```

### stop<sup>(deprecated)</sup>

stop(): Promise\<void\>

Stops this session. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](#stop11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop().then(() => {
    console.info('Promise returned to indicate the session stop success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to stop the session, error code: ${err.code}.`);
  });
}
```

### release<sup>(deprecated)</sup>

release(callback: AsyncCallback\<void\>): void

Releases this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.release](#release11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate that the CaptureSession instance is released successfully.');
  });
}
```

### release<sup>(deprecated)</sup>

release(): Promise\<void\>

Releases this session. This API uses a promise to return the result.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.release](#release11-2) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release().then(() => {
    console.info('Promise returned to indicate that the CaptureSession instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
  });
}
```

### hasFlash<sup>(deprecated)</sup>

hasFlash(): boolean

Checks whether the camera device has flash.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.hasFlash](#hasflash11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The camera device has flash.<br>**false**: The camera device does not have flash. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function hasFlash(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.hasFlash();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The hasFlash call failed. error code: ${err.code}`);
  }
  return status;
}
```

### isFlashModeSupported<sup>(deprecated)</sup>

isFlashModeSupported(flashMode: FlashMode): boolean

Checks whether a flash mode is supported.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.isFlashModeSupported](#isflashmodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                              |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.                    |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The flash mode is supported.<br>**false**: The flash mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFlashModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFlashModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### setFlashMode<sup>(deprecated)</sup>

setFlashMode(flashMode: FlashMode): void

Sets a flash mode.

Before the setting, do the following checks:

1. Use [hasFlash](#hasflashdeprecated) to check whether the camera device has flash.
2. Use [isFlashModeSupported](#isflashmodesupporteddeprecated) to check whether the camera device supports the flash mode.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.setFlashMode](#setflashmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                |
| --------- | ----------------------- | ---- | -------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFlashMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFlashMode call failed. error code: ${err.code}`);
  }
}
```

### getFlashMode<sup>(deprecated)</sup>

getFlashMode(): FlashMode

Obtains the flash mode in use.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.getFlashMode](#getflashmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FlashMode](#flashmode)    | Flash mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFlashMode(captureSession: camera.CaptureSession): camera.FlashMode | undefined {
  let flashMode: camera.FlashMode | undefined = undefined;
  try {
    flashMode = captureSession.getFlashMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFlashMode call failed.error code: ${err.code}`);
  }
  return flashMode;
}
```

### isExposureModeSupported<sup>(deprecated)</sup>

isExposureModeSupported(aeMode: ExposureMode): boolean

Checks whether an exposure mode is supported.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.isExposureModeSupported](#isexposuremodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.                     |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The exposure mode is supported.<br>**false**: The exposure mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isExposureModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isExposureModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### getExposureMode<sup>(deprecated)</sup>

getExposureMode(): ExposureMode

Obtains the exposure mode in use.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getExposureMode](#getexposuremode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [ExposureMode](#exposuremode)    | Exposure mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMode(captureSession: camera.CaptureSession): camera.ExposureMode | undefined {
  let exposureMode: camera.ExposureMode | undefined = undefined;
  try {
    exposureMode = captureSession.getExposureMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureMode call failed. error code: ${err.code}`);
  }
  return exposureMode;
}
```

### setExposureMode<sup>(deprecated)</sup>

setExposureMode(aeMode: ExposureMode): void

Sets an exposure mode. Before the setting, call [isExposureModeSupported](#isexposuremodesupporteddeprecated) to check whether the target exposure mode is supported.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.setExposureMode](#setexposuremode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setExposureMode call failed. error code: ${err.code}`);
  }
}
```

### getMeteringPoint<sup>(deprecated)</sup>

getMeteringPoint(): Point

Obtains the metering point of the camera device.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getMeteringPoint](#getmeteringpoint11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Metering point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMeteringPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let exposurePoint: camera.Point | undefined = undefined;
  try {
    exposurePoint = captureSession.getMeteringPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);
  }
  return exposurePoint;
}
```

### setMeteringPoint<sup>(deprecated)</sup>

setMeteringPoint(point: Point): void

Sets the metering point, which is the center point of the metering rectangle.

The metering point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.setMeteringPoint](#setmeteringpoint11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| point | [Point](#point)                | Yes  | Metering point. The value range of x and y must be within [0,1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.            |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMeteringPoint(captureSession: camera.CaptureSession): void {
  const point: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setMeteringPoint(point);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

### getExposureBiasRange<sup>(deprecated)</sup>

getExposureBiasRange(): Array\<number\>

Obtains the exposure compensation values of the camera device.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getExposureBiasRange](#getexposurebiasrange11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Array of compensation values. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureBiasRange(captureSession: camera.CaptureSession): Array<number> {
  let biasRangeArray: Array<number> = [];
  try {
    biasRangeArray = captureSession.getExposureBiasRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureBiasRange call failed. error code: ${err.code}`);
  }
  return biasRangeArray;
}
```

### setExposureBias<sup>(deprecated)</sup>

setExposureBias(exposureBias: number): void

Sets an exposure compensation value (EV).

Before the setting, you are advised to use [getExposureBiasRange](#getexposurebiasrangedeprecated) to obtain the supported values.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.setExposureBias](#setexposurebias11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory | Description                                                                                                                                                                                   |
| -------- | -------------------------------|-----|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| exposureBias   | number                   | Yes | EV. The supported EV range can be obtained by calling [getExposureBiasRange](#getexposurebiasrange11). If the value passed is not within the supported range, the nearest critical point is used. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned. If the input parameter is null or undefined, the EV is set to 0.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureBias(captureSession: camera.CaptureSession, biasRangeArray: Array<number>): void {
  if (biasRangeArray && biasRangeArray.length > 0) {
    let exposureBias = biasRangeArray[0];
    try {
      captureSession.setExposureBias(exposureBias);
    } catch (error) {
      // If the operation fails, error.code is returned and processed.
      let err = error as BusinessError;
      console.error(`The setExposureBias call failed. error code: ${err.code}`);
    }
  }
}
```

### getExposureValue<sup>(deprecated)</sup>

getExposureValue(): number

Obtains the exposure value in use.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getExposureValue](#getexposurevalue11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Exposure value obtained. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureValue(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let exposureValue: number = invalidValue;
  try {
    exposureValue = captureSession.getExposureValue();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureValue call failed. error code: ${err.code}`);
  }
  return exposureValue;
}
```

### isFocusModeSupported<sup>(deprecated)</sup>

isFocusModeSupported(afMode: FocusMode): boolean

Checks whether a focus mode is supported.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.isFocusModeSupported](#isfocusmodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                             |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The focus mode is supported.<br>**false**: The focus mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### setFocusMode<sup>(deprecated)</sup>

setFocusMode(afMode: FocusMode): void

Sets a focus mode.

Before the setting, call [isFocusModeSupported](#isfocusmodesupporteddeprecated) to check whether the focus mode is supported.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.setFocusMode](#setfocusmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusMode call failed. error code: ${err.code}`);
  }
}
```

### getFocusMode<sup>(deprecated)</sup>

getFocusMode(): FocusMode

Obtains the focus mode in use.

> **NOTE**
>
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.getFocusMode](#getfocusmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FocusMode](#focusmode)   | Focus mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusMode(captureSession: camera.CaptureSession): camera.FocusMode | undefined {
  let afMode: camera.FocusMode | undefined = undefined;
  try {
    afMode = captureSession.getFocusMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusMode call failed. error code: ${err.code}`);
  }
  return afMode;
}
```

### setFocusPoint<sup>(deprecated)</sup>

setFocusPoint(point: Point): void

Sets the focal point. The focal point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.setFocusPoint](#setfocuspoint11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                    | Mandatory | Description                |
|-------| ----------------------- |-----| ------------------- |
| point | [Point](#point)         | Yes | Focal point. The value range of x and y must be within [0,1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusPoint(captureSession: camera.CaptureSession): void {
  const focusPoint: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setFocusPoint(focusPoint);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);
  }
}
```

### getFocusPoint<sup>(deprecated)</sup>

getFocusPoint(): Point

Obtains the focal point of the camera device.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.getFocusPoint](#getfocuspoint11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Focal point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let point: camera.Point | undefined = undefined;
  try {
    point = captureSession.getFocusPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusPoint call failed. error code: ${err.code}`);
  }
  return point;
}
```

### getFocalLength<sup>(deprecated)</sup>

getFocalLength(): number

Obtains the focal length of the camera device.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.getFocalLength](#getfocallength11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Focal length obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocalLength(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let focalLength: number = invalidValue;
  try {
    focalLength = captureSession.getFocalLength();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocalLength call failed. error code: ${err.code}`);
  }
  return focalLength;
}
```

### getZoomRatioRange<sup>(deprecated)</sup>

getZoomRatioRange(): Array\<number\>

Obtains the supported zoom ratio range.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Zoom.getZoomRatioRange](#getzoomratiorange11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Array containing the minimum and maximum zoom ratios. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatioRange(captureSession: camera.CaptureSession): Array<number> {
  let zoomRatioRange: Array<number> = [];
  try {
    zoomRatioRange = captureSession.getZoomRatioRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getZoomRatioRange call failed. error code: ${err.code}`);
  }
  return zoomRatioRange;
}
```

### setZoomRatio<sup>(deprecated)</sup>

setZoomRatio(zoomRatio: number): void

Sets a zoom ratio, with a maximum precision of two decimal places.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Zoom.setZoomRatio](#setzoomratio11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                 | Mandatory | Description                |
| --------- | -------------------- |-----| ------------------- |
| zoomRatio | number               | Yes | Zoom ratio. The supported zoom ratio range can be obtained by calling [getZoomRatioRange](#getzoomratiorange11). If the value passed in is not within the supported range, the value within the precision range is retained. If the input parameter is null or undefined, it is treated as 0 and the minimum zoom ratio is used.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setZoomRatio(captureSession: camera.CaptureSession, zoomRatioRange: Array<number>): void {
  if (zoomRatioRange === undefined || zoomRatioRange.length <= 0) {
    return;
  }
  let zoomRatio = zoomRatioRange[0];
  try {
    captureSession.setZoomRatio(zoomRatio);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setZoomRatio call failed. error code: ${err.code}`);
  }
}
```

### getZoomRatio<sup>(deprecated)</sup>

getZoomRatio(): number

Obtains the zoom ratio in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Zoom.getZoomRatio](#getzoomratio11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Zoom ratio obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatio(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let zoomRatio: number = invalidValue;
  try {
    zoomRatio = captureSession.getZoomRatio();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getZoomRatio call failed. error code: ${err.code}`);
  }
  return zoomRatio;
}
```

### isVideoStabilizationModeSupported<sup>(deprecated)</sup>

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean

Checks whether a video stabilization mode is supported. 

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Stabilization.isVideoStabilizationModeSupported](#isvideostabilizationmodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                            |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode. If the input parameter is null or undefined, it is treated as 0 and video stabilization is disabled.             |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The video stabilization mode is supported.<br>**false**: The video stabilization mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isVideoStabilizationModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isVideoStabilizationModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### getActiveVideoStabilizationMode<sup>(deprecated)</sup>

getActiveVideoStabilizationMode(): VideoStabilizationMode

Obtains the video stabilization mode in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Stabilization.getActiveVideoStabilizationMode](#getactivevideostabilizationmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoStabilizationMode](#videostabilizationmode)    | Video stabilization mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getActiveVideoStabilizationMode(captureSession: camera.CaptureSession): camera.VideoStabilizationMode | undefined {
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;
  try {
    vsMode = captureSession.getActiveVideoStabilizationMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);
  }
  return vsMode;
}
```

### setVideoStabilizationMode<sup>(deprecated)</sup>

setVideoStabilizationMode(mode: VideoStabilizationMode): void

Sets a video stabilization mode. Before the setting, call [isVideoStabilizationModeSupported](#isvideostabilizationmodesupporteddeprecated) to check whether the target video stabilization mode is supported.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Stabilization.setVideoStabilizationMode](#setvideostabilizationmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode. If the input parameter is null or undefined, it is treated as 0 and video stabilization is disabled.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setVideoStabilizationMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);
  }
}
```

### on('focusStateChange')<sup>(deprecated)</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.on('focusStateChange')](#onfocusstatechange11-1) instead.
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function registerFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    if (err !== undefined && err.code !== 0) {
      console.error(`Callback Error, errorCode: ${err.code}`);
      return;
    }
    console.info(`Focus state: ${focusState}`);
  });
}
```

### off('focusStateChange')<sup>(deprecated)</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.off('focusStateChange')](#offfocusstatechange11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.off('focusStateChange');
}
```

### on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **CaptureSession** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.on('error')](#onerror11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                                      | Mandatory| Description                          |
| -------- |--------------------------------------------------------------------------| ---- | ------------------------------ |
| type     | string                                                                   | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfigdeprecated), [commitConfig](#commitconfigdeprecated-1), and [addInput](#addinputdeprecated).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function registerCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.on('error', (error: BusinessError) => {
    console.error(`Capture session error code: ${error.code}`);
  });
}
```

### off('error')<sup>(deprecated)</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **CaptureSession** error events. This API uses a callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.off('error')](#offerror11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.off('error');
}
```
## ColorManagementQuery<sup>12+</sup>

Provides the APIs for color space query.

### getSupportedColorSpaces<sup>12+</sup>

getSupportedColorSpaces(): Array\<colorSpaceManager.ColorSpace\>

Obtains the supported color spaces.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)>| Array of color spaces supported.    |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config, only throw in session usage.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function getSupportedColorSpaces(session: camera.PhotoSession): Array<colorSpaceManager.ColorSpace> {
  let colorSpaces: Array<colorSpaceManager.ColorSpace> = [];
  try {
    colorSpaces = session.getSupportedColorSpaces();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getSupportedColorSpaces call failed. error code: ${err.code}`);
  }
  return colorSpaces;
}
```
## ColorManagement<sup>12+</sup>

ColorManagement extends [ColorManagementQuery](#colormanagementquery12)

Implements color space management. It inherits from [ColorManagementQuery](#colormanagementquery12).

### setColorSpace<sup>12+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpace): void

Sets a color space. Before the setting, call [getSupportedColorSpaces](#getsupportedcolorspaces12) to obtain the supported color spaces.

P3 and HDR Imaging  

An application can deliver different color space parameters to declare its support for P3 and HDR.

If an application does not proactively set the color space, HDR is used by default in photographing and video recording scenarios. 

In photo mode, P3 can be directly supported by setting the HDR effect.

For details about how to enable the HDR effect and set the color space in different modes, see the following table. 

**Recording Mode**

| SDR/HRD Photographing        | CameraFormat             | ColorSpace       |
|--------------------|--------------------------|------------------|
| SDR                | CAMERA_FORMAT_YUV_420_SP | BT709_LIMIT      |
| HDR_VIVID(Default) | CAMERA_FORMAT_YCRCB_P010 | BT2020_HLG_LIMIT |

**Photo Mode**

| SDR/HRD Photographing   | ColorSpace |
|--------------|------------|
| SDR          | SRGB       |
| HDR(Default) | DISPLAY_P3 |

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                | Mandatory| Description                     |
| ------------ |---------------------- | -- | -------------------------- |
| colorSpace | [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)  | Yes| Color space, which can be obtained through [getSupportedColorSpaces](#getsupportedcolorspaces12).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101         |  Parameter missing or parameter type incorrect.     |
| 7400102         |  The colorSpace does not match the format.     |
| 7400103         |  Session not config.                           |
| 7400201         |  Camera service fatal error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function setColorSpace(session: camera.PhotoSession, colorSpaces: Array<colorSpaceManager.ColorSpace>): void {
  if (colorSpaces === undefined || colorSpaces.length <= 0) {
    return;
  }
  try {
    session.setColorSpace(colorSpaces[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setColorSpace call failed, error code: ${err.code}`);
  }
}
```

### getActiveColorSpace<sup>12+</sup>

getActiveColorSpace(): colorSpaceManager.ColorSpace

Obtains the color space in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)               | Color space.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function getActiveColorSpace(session: camera.PhotoSession): colorSpaceManager.ColorSpace | undefined {
  let colorSpace: colorSpaceManager.ColorSpace | undefined = undefined;
  try {
    colorSpace = session.getActiveColorSpace();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getActiveColorSpace call failed. error code: ${err.code}`);
  }
  return colorSpace;
}
```

## AutoDeviceSwitchQuery<sup>13+</sup>

A class for checking whether a device supports automatic camera switch.

### isAutoDeviceSwitchSupported<sup>13+</sup>

isAutoDeviceSwitchSupported(): boolean

Checks whether the device supports automatic camera switch.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description         |
| ----------------------------------------------- |-------------|
| boolean               | Whether the device supports automatic camera switch.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message                                             |
| --------------- |---------------------------------------------------|
| 7400103         | Session not config, only throw in session usage.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isAutoDeviceSwitchSupported(session: camera.PhotoSession): boolean {
  let isSupported = false;
  try {
    isSupported = session.isAutoDeviceSwitchSupported();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The isAutoDeviceSwitchSupported call failed, error code: ${err.code}`);
  }
  return isSupported;
}
```

## AutoDeviceSwitch<sup>13+</sup>

AutoDeviceSwitch extends [AutoDeviceSwitchQuery](#autodeviceswitchquery13)

A class that is used to enable or disable automatic camera switch. This class inherits from [AutoDeviceSwitchQuery](#autodeviceswitchquery13).

It is recommended that the system completes input device switch, session configuration, and parameter connection during automatic camera switch. If the system detects that the zoom ranges of the two cameras are different, it notifies the application through the **isDeviceCapabilityChanged** field in [AutoDeviceSwitchStatus](#autodeviceswitchstatus13). The application needs to process the UX change by itself. For example, if the zoom range is different, the application needs to call [getZoomRatioRange](#getzoomratiorange11) to obtain data and update the UX. Therefore, this class is more applicable to a simplified UX exchange scenario.

### enableAutoDeviceSwitch<sup>13+</sup>

enableAutoDeviceSwitch(enabled: boolean): void

Enables or disables automatic camera switch. You can use [isAutoDeviceSwitchSupported](#isautodeviceswitchsupported13) to check whether the device supports automatic camera switch.

> **NOTE**
>
> This API is used only for foldable devices with multiple front cameras. In different folding states, the system can automatically switch to an available front camera. It does not enable automatic switching between front and rear cameras.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type | Mandatory| Description |
| ----------- |---------------------- |---| -------------------------- |
| enabled | boolean  | Yes| Whether to enable automatic camera switch.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                                                                                                                      |
|----------|------------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 7400102  | Operation not allowed.                                                                                                                         |
| 7400103  | Session not config.                                                                                                                            |
| 7400201  | Camera service fatal error.                                                                                                                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableAutoDeviceSwitch(session: camera.PhotoSession, isEnable: boolean): void {
  try {
    session.enableAutoDeviceSwitch(isEnable);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The enableAutoDeviceSwitch call failed, error code: ${err.code}`);
  }
}
```

## PreconfigType<sup>12+</sup>

Enumerates the preconfigured resolution types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                     | Value| Description        |
|-------------------------|---|------------|
| PRECONFIG_720P          | 0 | 720p resolution.  |
| PRECONFIG_1080P         | 1 | 1080p resolution. |
| PRECONFIG_4K            | 2 | 4K resolution.    |
| PRECONFIG_HIGH_QUALITY  | 3 | High-quality resolution.   |

## PreconfigRatio<sup>12+</sup>

Enumerates the preconfigured aspect ratios.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value| Description     |
|--------------------------|---|---------|
| PRECONFIG_RATIO_1_1      | 0 | 1:1 aspect ratio. |
| PRECONFIG_RATIO_4_3      | 1 | 4:3 aspect ratio. |
| PRECONFIG_RATIO_16_9     | 2 | 16:9 aspect ratio.|

## PhotoSession<sup>11+</sup>

PhotoSession extends [Session](#session11), [Flash](#flash11), [AutoExposure](#autoexposure11), [Focus](#focus11), [Zoom](#zoom11), [ColorManagement](#colormanagement12), [AutoDeviceSwitch](#autodeviceswitch13)

Implements a photo session, which provides operations on the flash, exposure, focus, zoom, and color space.

> **NOTE**
>
> This class is provided for the default photo mode. It is used to take standard photos. It supports multiple photo formats and resolutions, which are suitable for most daily photographing scenarios.

### canPreconfig<sup>12+</sup>

canPreconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): boolean

Checks whether this session supports a preconfigured resolution.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name           | Type                                 | Mandatory | Description             |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](#preconfigtype12)   | Yes  | Resolution type.     |
| preconfigRatio | [PreconfigRatio](#preconfigratio12) | No  | Aspect ratio. The default value is 4:3. |

**Return value**

| Type     | Description                                     |
|---------|-----------------------------------------|
| boolean | **true**: The preconfigured resolution is supported.<br>**false**: The preconfigured resolution is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
function testCanPreconfig(photoSession: camera.PhotoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    let result = photoSession.canPreconfig(preconfigType, preconfigRatio);
    console.info(`canPreconfig ${preconfigType} ${preconfigRatio} result is : ${result}`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The canPreconfig call failed. error code: ${err.code}`);
  }
}
```

### preconfig<sup>12+</sup>

preconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): void

Preconfigures this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name           | Type                                 | Mandatory | Description             |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](#preconfigtype12)   | Yes  | Resolution type.     |
| preconfigRatio | [PreconfigRatio](#preconfigratio12) | No  | Aspect ratio. The default value is 4:3. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
function testPreconfig(photoSession: camera.PhotoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    photoSession.preconfig(preconfigType, preconfigRatio);
    console.info(`preconfig ${preconfigType} ${preconfigRatio} success`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The preconfig call failed. error code: ${err.code}`);
  }
}
```

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PhotoSession** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig11), [commitConfig](#commitconfig11-1), and [addInput](#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Photo session error code: ${err.code}`);
}

function registerSessionError(photoSession: camera.PhotoSession): void {
  photoSession.on('error', callback);
}
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PhotoSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                          |
| -------- | -------------------------------- | ---- | ------------------------------ |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSessionError(photoSession: camera.PhotoSession): void {
  photoSession.off('error');
}
```

### on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('smoothZoomInfoAvailable');
}
```

### on('autoDeviceSwitchStatusChange')<sup>13+</sup>

on(type: 'autoDeviceSwitchStatusChange', callback: AsyncCallback\<AutoDeviceSwitchStatus\>): void

Subscribes to automatic camera switch status change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                                  | Mandatory| Description                                                    |
| -------- |----------------------------------------------------------------------| ---- |--------------------------------------------------------|
| type     | string                                                               | Yes  | Event type. The value is fixed at **'autoDeviceSwitchStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](#autodeviceswitchstatus13)\> | Yes  | Callback function, which is used to obtain the status of automatic camera switch.                                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, autoDeviceSwitchStatus: camera.AutoDeviceSwitchStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isDeviceSwitched: ${autoDeviceSwitchStatus.isDeviceSwitched}, isDeviceCapabilityChanged: ${autoDeviceSwitchStatus.isDeviceCapabilityChanged}`);
}

function registerAutoDeviceSwitchStatus(photoSession: camera.PhotoSession): void {
  photoSession.on('autoDeviceSwitchStatusChange', callback);
}
```

### off('autoDeviceSwitchStatusChange')<sup>13+</sup>

off(type: 'autoDeviceSwitchStatusChange', callback?: AsyncCallback\<AutoDeviceSwitchStatus\>): void

Unsubscribes from automatic camera switch status change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                          | Mandatory| Description                      |
| -------- |----------------------------------------------| ---- | ------------------------ |
| type     | string                                       | Yes  | Event type. The value is fixed at **'autoDeviceSwitchStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](#autodeviceswitchstatus13)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('autoDeviceSwitchStatusChange');
}
```

## VideoSession<sup>11+</sup>

VideoSession extends [Session](#session11), [Flash](#flash11), [AutoExposure](#autoexposure11), [Focus](#focus11), [Zoom](#zoom11), [Stabilization](#stabilization11), [ColorManagement](#colormanagement12), [AutoDeviceSwitch](#autodeviceswitch13)

Implements a video session, which provides operations on the flash, exposure, focus, zoom, video stabilization, and color space.

> **NOTE**
>
> This class is provided for the default video recording mode. It applies to common scenarios. It supports recording at various resolutions (such as 720p and 1080p) and frame rates (such as 30 fps and 60 fps).

### canPreconfig<sup>12+</sup>

canPreconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): boolean

Checks whether this session supports a preconfigured resolution.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name           | Type                                 | Mandatory | Description             |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](#preconfigtype12)   | Yes  | Resolution type.     |
| preconfigRatio | [PreconfigRatio](#preconfigratio12) | No  | Aspect ratio. The default value is 16:9.|

**Return value**

| Type     | Description                                     |
|---------|-----------------------------------------|
| boolean | **true**: The preconfigured resolution is supported.<br>**false**: The preconfigured resolution is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
function testCanPreconfig(videoSession: camera.VideoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    let result = videoSession.canPreconfig(preconfigType, preconfigRatio);
    console.info(`canPreconfig ${preconfigType} ${preconfigRatio} result is : ${result}`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The canPreconfig call failed. error code: ${err.code}`);
  }
}
```

### preconfig<sup>12+</sup>

preconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): void

Preconfigures this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name           | Type                                 | Mandatory | Description             |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](#preconfigtype12)   | Yes  | Resolution type.     |
| preconfigRatio | [PreconfigRatio](#preconfigratio12) | No  | Aspect ratio. The default value is 16:9.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                       |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**Example**

```ts
function testPreconfig(videoSession: camera.VideoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    videoSession.preconfig(preconfigType, preconfigRatio);
    console.info(`preconfig ${preconfigType} ${preconfigRatio} success`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The preconfig call failed. error code: ${err.code}`);
  }
}
```

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **VideoSession** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type             | Mandatory| Description                          |
| -------- | ------------------ | ---- | ------------------------------ |
| type     | string             | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig11), [commitConfig](#commitconfig11-1), and [addInput](#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)      | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Video session error code: ${err.code}`);
}

function registerSessionError(videoSession: camera.VideoSession): void {
  videoSession.on('error', callback);
}
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **VideoSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                         | Mandatory| Description                          |
| -------- | --------------------------- | ---- | ------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSessionError(videoSession: camera.VideoSession): void {
  videoSession.off('error');
}
```

### on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('smoothZoomInfoAvailable');
}
```

### on('autoDeviceSwitchStatusChange')<sup>13+</sup>

on(type: 'autoDeviceSwitchStatusChange', callback: AsyncCallback\<AutoDeviceSwitchStatus\>): void

Subscribes to automatic camera switch status change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                                  | Mandatory| Description                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------ |
| type     | string                                                               | Yes  | Event type. The value is fixed at **'autoDeviceSwitchStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](#autodeviceswitchstatus13)\> | Yes  | Callback function, which is used to obtain the status of automatic camera switch. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, autoDeviceSwitchStatus: camera.AutoDeviceSwitchStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isDeviceSwitched: ${autoDeviceSwitchStatus.isDeviceSwitched}, isDeviceCapabilityChanged: ${autoDeviceSwitchStatus.isDeviceCapabilityChanged}`);
}

function registerAutoDeviceSwitchStatus(videoSession: camera.VideoSession): void {
  videoSession.on('autoDeviceSwitchStatusChange', callback);
}
```

### off('autoDeviceSwitchStatusChange')<sup>13+</sup>

off(type: 'autoDeviceSwitchStatusChange', callback?: AsyncCallback\<AutoDeviceSwitchStatus\>): void

Unsubscribes from automatic camera switch status change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                          | Mandatory| Description                      |
| -------- |----------------------------------------------| ---- | ------------------------ |
| type     | string                                       | Yes  | Event type. The value is fixed at **'autoDeviceSwitchStatusChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](#autodeviceswitchstatus13)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('autoDeviceSwitchStatusChange');
}
```

## SecureSession<sup>12+</sup>

SecureSession extends [Session](#session11), [Flash](#flash11), [AutoExposure](#autoexposure11), [Focus](#focus11), [Zoom](#zoom11)

Implements a secure session, which provides operations on the flash, exposure, focus, and zoom.

> **NOTE**
>
> You can call [createSession](#createsession11) with [SceneMode](#scenemode11) set to **SECURE_PHOTO** to create a session in secure mode. This class is designed for applications with high security requirements, such as facial recognition systems and banking services. It must be used together with the <!--RP1-->security TA<!--RP1End--> to support service scenarios where both standard preview streams and security streams are generated.<!--RP2-->
> The security TA can verify the signature of data delivered by the server, sign images, parse and assemble TLV logic, and read, create, and operate keys. It applies to image processing.<!--RP2End-->

### addSecureOutput<sup>12+</sup>

addSecureOutput(previewOutput: PreviewOutput): void

Marks a [PreviewOutput](#previewoutput) stream as secure output.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description           |
| ------------- | ------------------------------- | ---- |---------------|
| previewOutput  | [PreviewOutput](#previewoutput)   | Yes  | Preview output stream. An error code is returned if the input parameter is invalid.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addSecureOutput(session: camera.SecureSession, previewOutput: camera.PreviewOutput): void {
  try {
    session.addSecureOutput(previewOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The addOutput call failed. error code: ${err.code}`);
  }
}
```
### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **SecureSession** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type             | Mandatory| Description                          |
| -------- | ------------------ | ---- | ------------------------------ |
| type     | string             | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig11), [commitConfig](#commitconfig11-1), and [addInput](#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)      | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Video session error code: ${err.code}`);
}

function registerSessionError(secureSession: camera.SecureSession): void {
  secureSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **SecureSession** error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                         | Mandatory| Description                          |
| -------- | --------------------------- | ---- | ------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterSessionError(secureSession: camera.SecureSession): void {
  secureSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(secureSession: camera.SecureSession): void {
  secureSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFocusStateChange(secureSession: camera.SecureSession): void {
  secureSession.off('focusStateChange');
}
```
