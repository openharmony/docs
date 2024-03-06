# @ohos.multimedia.camera (Camera Management)

The camera module provides a set of camera service APIs for you to easily develop a camera application. The application can access and operate the camera hardware to implement basic operations, such as preview, taking photos, and recording videos. It can also perform more operations, for example, controlling the flash and exposure time, and focusing or adjusting the focus.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import camera from '@ohos.multimedia.camera';
```

## camera.getCameraManager

getCameraManager(context: Context): CameraManager

Obtains a **CameraManager** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](js-apis-inner-application-baseContext.md)      | Yes  | Application context.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraManager](#cameramanager)           | **CameraManager** instance obtained.                  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

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

| Name          | Type                               | Mandatory| Read-only| Description       |
| -------------- | --------------------------------- | ---- | ---- |---------- |
| cameraId       | string                            | Yes  | Yes  | Camera ID.|
| cameraPosition | [CameraPosition](#cameraposition) | Yes  | Yes  | Camera position.   |
| cameraType     | [CameraType](#cameratype)         | Yes  | Yes  | Camera type.   |
| connectionType | [ConnectionType](#connectiontype) | Yes  | Yes  | Camera connection type.|
| hostDeviceName | string                            | Yes  | Yes  | Name of the remote device. **System API**: This is a system API.|
| hostDeviceType | [HostDeviceType](#hostdevicetype) | Yes  | Yes  | Type of the remote device. **System API**: This is a system API.|

## CameraPosition

Enumerates the camera positions.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Value  | Description           |
| --------------------------- | ---- | -------------- |
| CAMERA_POSITION_UNSPECIFIED | 0    | Unspecified position. |
| CAMERA_POSITION_BACK        | 1    | Rear camera.      |
| CAMERA_POSITION_FRONT       | 2    | Front camera.      |
| CAMERA_POSITION_FOLD_INNER<sup>11+</sup>  | 3    | Folded camera.    |

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

## HostDeviceType

Enumerates the remote camera types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value      | Description          |
| ---------------------------- | ----     | ------------- |
| UNKNOWN_TYPE                 | 0        | Unknown type.     |
| PHONE                        | 0x0E     | Phone camera.|
| TABLET                       | 0x11     | Tablet camera.|

## CameraStatus

Enumerates the camera statuses.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | A camera appears.  |
| CAMERA_STATUS_DISAPPEAR   | 1    | The camera disappears.    |
| CAMERA_STATUS_AVAILABLE   | 2    | The camera is available.      |
| CAMERA_STATUS_UNAVAILABLE | 3    | The camera is unavailable.    |

## CameraStatusInfo

Defines the camera status information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| camera | [CameraDevice](#cameradevice) |        Yes      | Camera device.|
| status | [CameraStatus](#camerastatus) |        Yes       | Camera status.|

## Profile

Defines the camera profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Mandatory| Read-only| Description        |
| -------- | ----------------------------- |---- | ---- | ------------- |
| format   | [CameraFormat](#cameraformat) | Yes |  Yes | Output format.     |
| size     | [Size](#size)                 | Yes |  Yes | Resolution.      |

## FrameRateRange

Defines the frame rate range.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Mandatory| Read-only| Description        |
| -------- | ----------------------------- |---- | ---- | ------------- |
| min      | number                        | Yes |  Yes | Minimum frame rate.     |
| max      | number                        | Yes |  Yes | Maximum frame rate.     |

## VideoProfile

Defines the video configuration information. It inherits from [Profile](#profile).

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Mandatory| Read-only| Description       |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| frameRateRange            | [FrameRateRange](#frameraterange)         | Yes |  Yes | Frame rate range, in units of frames per second (FPS).|

## CameraOutputCapability

Defines the camera output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Type                                              | Mandatory| Read-only| Description               |
| ----------------------------- | -------------------------------------------------- | --- | ---- | ------------------- |
| previewProfiles               | Array\<[Profile](#profile)\>                        | Yes |  Yes | Supported preview profiles.   |
| photoProfiles                 | Array\<[Profile](#profile)\>                        | Yes |  Yes | Supported photo profiles.   |
| videoProfiles                 | Array\<[VideoProfile](#videoprofile)\>              | Yes |  Yes | Supported video profiles.   |
| supportedMetadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | Yes |  Yes | Supported metadata object types.|

## SceneMode<sup>11+</sup>

Enumerates the camera scene modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| NORMAL_PHOTO  | 1         | Normal photo mode.            |
| NORMAL_VIDEO | 2      | Normal record mode.     |
| PORTRAIT_PHOTO       | 3      | Portrait photo mode. **System API**: This is a system API.           |
| NIGHT_PHOTO        | 4      | Night photo mode. **System API**: This is a system API.            |

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
import { BusinessError } from '@ohos.base';

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
| cameraDevice | [CameraDevice](#cameradevice)                              | Yes| **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras).      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[SceneMode](#scenemode11)>            | Array of scene modes supported.                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function getSupportedSceneModes(cameraManager: camera.CameraManager): Array<camera.SceneMode> {
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
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getSupportedOutputCapability<sup>11+</sup>](#getsupportedoutputcapability11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | Yes| **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras).      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```ts
function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice);
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
| cameraDevice | [CameraDevice](#cameradevice)                              | Yes| **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras).      |
| mode | [SceneMode](#scenemode11)                              | Yes| Scene mode, which is obtained through [getSupportedSceneModes](#getsupportedscenemodes11).      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```ts
function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager, sceneMode: camera.SceneMode): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice, sceneMode);
  return cameraOutputCapability;
}
```

### isCameraMuted

isCameraMuted(): boolean

Checks whether the camera device is muted.

Before calling the API, ensure that the camera device can be muted. You can use [isCameraMuteSupported](#iscameramutesupported) to check whether the camera device can be muted.

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

### isCameraMuteSupported

isCameraMuteSupported(): boolean

Checks whether the camera device can be muted.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The camera device can be muted.<br>**false**: The camera device cannot be muted.|

**Example**

```ts
function isCameraMuteSupported(cameraManager: camera.CameraManager): boolean {
  let isMuteSupported: boolean = cameraManager.isCameraMuteSupported();
  return isMuteSupported;
}
```

### muteCamera

muteCamera(mute: boolean): void

Mutes or unmutes the camera device.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                             | Mandatory | Description       |
| -------- | --------------------------------- | ---- | ---------- |
| mute     | boolean                           |  Yes |  Whether to mute the camera device. The value **true** means to mute the camera device, and **false** means the opposite. |

**Example**

```ts
function muteCamera(cameraManager: camera.CameraManager): void {
  let mute: boolean = true;
  cameraManager.muteCamera(mute);
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
| cameraDevice   | [CameraDevice](#cameradevice)         | Yes  | **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | **CameraInput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function createCameraInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput | undefined {
  let cameraInput: camera.CameraInput | undefined = undefined;
  try {
    cameraInput = cameraManager.createCameraInput(cameraDevice);
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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function createCameraInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput | undefined {
  let position: camera.CameraPosition = cameraDevice.cameraPosition;
  let type: camera.CameraType = cameraDevice.cameraType;
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
| profile  | [Profile](#profile)                             | Yes  | Supported preview profiles, which are obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string | Yes  | Surface ID, which is obtained from [XComponent](../arkui-ts/ts-basic-components-xcomponent.md) or [ImageReceiver](js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PreviewOutput](#previewoutput)    | **PreviewOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### createPhotoOutput<sup>(deprecated)</sup>

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

Creates a **PhotoOutput** instance. This API returns the result synchronously.

> **NOTE**
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [createPhotoOutput<sup>11+</sup>](#createphotooutput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | Yes  | Supported photo profiles, which are obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string            | Yes  | Surface ID, which is obtained from [ImageReceiver](js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | **PhotoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

```ts
import { BusinessError } from '@ohos.base';

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

createPhotoOutput(profile: Profile): PhotoOutput

Creates a **PhotoOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | Yes  | Supported photo profiles, which are obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | **PhotoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| profile  | [VideoProfile](#videoprofile)               | Yes  | Supported video profiles, which are obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string          | Yes  | Surface ID, which is obtained from [AVRecorder](js-apis-media.md#avrecorder9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoOutput](#videooutput)   | **VideoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [createSession](#createsession11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CaptureSession](#capturesession)   | **CaptureSession** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| mode     | SceneMode        | Yes  | Scene mode.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [T extends Session](#session)   | **Session** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function createSession(cameraManager: camera.CameraManager, mode: camera.SceneMode): camera.Session | undefined {
  let photoSession: camera.PhotoSession | undefined = undefined;
  try {
    photoSession = cameraManager.createSession(mode.NORMAL_PHOTO);
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

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'cameraStatus'**. The event can be listened for when a **CameraManager** instance is obtained. This event is triggered and the corresponding information is returned only when the camera device is enabled or disabled.|
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | Yes  | Callback used to return the camera status change.|                 |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo): void {
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
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.off('cameraStatus');
}
```

### on('cameraMute')

on(type: 'cameraMute', callback: AsyncCallback\<boolean\>): void

Subscribes to camera mute status events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'cameraMute'**, indicating the camera mute status. The event can be listened for when a **CameraManager** instance is obtained. This event is triggered and the status is returned when the camera device is muted or unmuted.|
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the mute status. The value **true** means that the camera is enabled, and **false** means that the camera is disabled.              |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, curMuetd: boolean): void {
  let isMuted: boolean = curMuetd;
  console.info(`cameraMute status: ${isMuted}`);
}

function registerCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraMute', callback);
}
```

### off('cameraMute')

off(type: 'cameraMute', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from camera mute status events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description                                                     |
| -------- | --------------- | ---- |---------------------------------------------------------|
| type     | string          | Yes  | Event type. The value is fixed at **'cameraMute'**, indicating the camera mute status. The event can be listened for when a **CameraManager** instance is obtained.|
| callback | AsyncCallback\<boolean> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)                 |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, curMuetd: boolean): void {
  let isMuted: boolean = curMuetd;
}

function unregisterCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraMute', callback);
  cameraManager.off('cameraMute', callback);
}
```

### isPrelaunchSupported

isPrelaunchSupported(camera: CameraDevice): boolean

Checks whether a camera device supports prelaunch.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| camera | [CameraDevice](#cameradevice) | Yes| Camera device.|

**Return value**

| Type| Description|
| -------- | --------------- |
| boolean | **true**: The camera device supports prelaunch.<br>**false**: The camera device does not support prelaunch.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**Example**

```ts
import common from '@ohos.app.ability.common';

function isPreLaunchSupported(context: common.BaseContext): boolean {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  let isSupported: boolean = false;
  if (cameras && cameras.length >= 1) {
    isSupported = cameraManager.isPrelaunchSupported(cameras[0]);
    console.info(`PreLaunch supported states: ${isSupported}`);
    return isSupported;
  }
  return isSupported;
}
```

### setPrelaunchConfig

setPrelaunchConfig(prelaunchConfig: PrelaunchConfig): void

Sets prelaunch configuration.

Before the setting, use [isPrelaunchSupported](#isprelaunchsupported) to check whether the camera device supports prelaunch.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| prelaunchConfig | [PrelaunchConfig](#prelaunchconfig) | Yes| Prelaunch configuration.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allow. |

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

function setPrelaunchConfig(context: common.BaseContext): void {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  if (cameras && cameras.length >= 1) {
    let cameraDevice: camera.CameraDevice = cameras[0];
    if(cameraManager.isPrelaunchSupported(cameraDevice)) {
      try {
        cameraManager.setPrelaunchConfig({cameraDevice: cameraDevice});
      } catch (error) {
        let err = error as BusinessError;
        console.error(`setPrelaunchConfig error. Code: ${err.code}, message: ${err.message}`);
      }
    }
  }
}
```

### prelaunch

prelaunch(): void

Prelaunches the camera device. This API is called when a user clicks the system camera icon to start the camera application.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

function preLaunch(context: common.BaseContext): void {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  try {
    cameraManager.prelaunch();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`prelaunch error. Code: ${err.code}, message: ${err.message}`);
  }
}
```

### createDeferredPreviewOutput

createDeferredPreviewOutput(profile: Profile): PreviewOutput

Creates a deferred **PreviewOutput** instance and adds it, instead of a common **PreviewOutput** instance, to the data stream during stream configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| profile | [Profile](#profile) | Yes| Configuration file of the camera preview stream.|

**Return value**

| Type| Description|
| -------- | --------------- |
| [PreviewOutput](#previewoutput) | **PreviewOutput** instance obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**Example**

```ts
import common from '@ohos.app.ability.common';

function getDeferredPreviewOutput(context: common.BaseContext, previewProfile: camera.Profile): camera.PreviewOutput {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const output: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);
  return output;
}
```

### preSwitchCamera<sup>11+</sup>

preSwitchCamera(cameraId: string): void

Pre-switches a camera device to speed up its startup.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| cameraId | string | Yes| Camera device.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

function preSwitch(cameraDevice: camera.CameraDevice, context: common.BaseContext): void {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  try {
    cameraManager.preSwitchCamera(cameraDevice.cameraId);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`prelaunch error. Code: ${err.code}, message: ${err.message}`);
  }
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
| mode | [TorchMode](#torchmode) | Yes| Flashlight mode.|

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
| [TorchMode](#torchmode)    | Flashlight mode.|

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
| mode | [TorchMode](#torchmode) | Yes| Flashlight mode.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'torchStatusChange'**. The event can be listened for when a **CameraManager** instance is obtained. Currently, this event is triggered only in the following scenarios: The flashlight is turned on or turned off, or becomes unavailable or available.|
| callback | AsyncCallback\<TorchStatusInfo> | Yes  | Callback used to return the flashlight status.              |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, torchStatusInfo: camera.TorchStatusInfo): void {
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
| callback | AsyncCallback\<TorchStatusInfo> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)              |

**Example**

```ts
function unregisterTorchStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.off('torchStatusChange');
}
```

## PrelaunchConfig

Defines the camera prelaunch configuration.

Currently, the configuration is used for sensor-level prelaunch. It will be used for stream-level prelaunch in a later version.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| cameraDevice | [CameraDevice](#cameradevice) |        Yes      | Camera device.|
| restoreParamType<sup>11+</sup> | [RestoreParamType](#restoreparamtype11) |        No      | Type of the parameter used for prelaunch.|
| activeTime<sup>11+</sup> | number |        No      | Activation time, in minutes.|
| settingParam<sup>11+</sup> | [SettingParam](#settingparam11) |        No      | Setting parameter.|

## RestoreParamType<sup>11+</sup>

Enumerates the types of the parameters used for prelaunch.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value   | Description    |
| ----------------| ----  | ---------|
| NO_NEED_RESTORE_PARAM           | 0      | The parameter used for prelaunch is not required.    |
| PRESISTENT_DEFAULT_PARAM    | 1      | Persistent parameter type. This parameter is used to restore stream information with the specified time point.    |
| TRANSIENT_ACTIVE_PARAM   | 2      | Temporary parameter type. This parameter is used to restore stream information only within a period of time after the camera application is closed. Its priority is higher than that of the persistent parameter.    |

## SettingParam<sup>11+</sup>

Defines the effect parameters used to preheat an image.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| skinSmoothLevel | number |        Yes      | Skin smoothing level, which is obtained through [getSupportedBeautyRange](#getsupportedbeautyrange). For example, the value **1** indicates level-1 smoothing.|
| faceSlender | number |        Yes       | Face slimming level, which is obtained through [getSupportedBeautyRange](#getsupportedbeautyrange). For example, the value **1** indicates level-1 slimming.|
| skinTone | number |        Yes       | Skin tone perfection level, which is obtained through [getSupportedBeautyRange](#getsupportedbeautyrange). For example, the value **0xBF986C** indicates a specific color.|

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

| Name          | Type                               | Read-only| Description       |
| -------------- | --------------------------------- | ---- | ---------- |
| isTorchAvailable       | boolean   | Yes  | Whether the flashlight is available.|
| isTorchActive | boolean | Yes  | Whether the flashlight is activated.   |
| torchLevel     | number  | Yes  | Flashlight level. The value range is [0, 1]. A larger value indicates a greater luminance.   |

## Size

Defines the output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type  | Readable| Writable| Description        |
| ------ | ------ | ---- | ---- | ------------ |
| height | number | Yes  | Yes  | Image height, in pixels.|
| width  | number | Yes  | Yes  | Image width, in pixels.|

## Point

Defines the point coordinates, which are used for focus and exposure configuration.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type  | Mandatory  | Description        |
| ------ | ------ | ---- | ------------ |
| x      | number | Yes   | X coordinate of a point.  |
| y      | number | Yes   | Y coordinate of a point.  |

## CameraFormat

Enumerates the camera output formats.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGB image.            |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV 420 SP image.     |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG image.           |
| CAMERA_FORMAT_YCBCR_P010<sup>11+</sup> |   2001    | YCBCR_P010 image.     |
| CAMERA_FORMAT_YCRCB_P010<sup>11+</sup> |   2002    | YCRCB_P010 image.           |

## CameraInput

Defines the camera input object.

Provides camera device information used in [CaptureSession](#capturesession).

### open

open(callback: AsyncCallback\<void\>): void

Opens this camera device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open().then(() => {
    console.info('Promise returned with camera opened.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to open the camera, error code: ${err.code}.`);
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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function closeCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.close().then(() => {
    console.info('Promise returned with camera closed.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to close the cameras, error code: ${err.code}.`);
  });
}
```

### on('error')

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void

Subscribes to **CameraInput** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **CameraInput** instance is created. This event is triggered and the result is returned when an error occurs on the camera device. For example, if the camera device is unavailable or a conflict occurs, the error information is returned.|
| cameraDevice   | [CameraDevice](#cameradevice)    | Yes  | Camera device.|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode). |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError): void {
  console.error(`Camera input error code: ${err.code}`);
}

function registerCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {
  cameraInput.on('error', cameraDevice, callback);
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
| cameraDevice   | [CameraDevice](#cameradevice)    | Yes  | Camera device.|
| callback | ErrorCallback | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)  |

**Example**

```ts
function unregisterCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {
  cameraInput.off('error', cameraDevice);
}
```

## CameraOutput

Implements output information used in [CaptureSession](#capturesession). It is the base class of **output**.

### release

release(callback: AsyncCallback\<void\>): void

Releases output resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function releasePreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the PreviewOutput instance ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate that the previewOutput instance is released successfully.');
  });
}

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the VideoOutput instance ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate that the videoOutput instance is released successfully.');
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
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function releasePreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.release().then(() => {
    console.info('Promise returned to indicate that the PreviewOutput instance is released successfully.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to previewOutput release, error code: ${err.code}`);
  });
}

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release().then(() => {
    console.info('Promise returned to indicate that the VideoOutput instance is released successfully.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to videoOutput release, error code: ${err.code}`);
  });
}
```

## PreviewOutput

Implements preview output. It inherits from [CameraOutput](#cameraoutput).

### start<sup>(deprecated)</sup>

start(callback: AsyncCallback\<void\>): void

Starts to output preview streams. This API uses an asynchronous callback to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](#start-4) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function startPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the previewOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with previewOutput started.');
  });
}
```

### start<sup>(deprecated)</sup>

start(): Promise\<void\>

Starts to output preview streams. This API uses a promise to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](#start-5) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function startPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.start().then(() => {
    console.info('Promise returned with previewOutput started.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to previewOutput start, error code: ${err.code}.`);
  });
}
```

### stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void\>): void

Stops outputting preview streams. This API uses an asynchronous callback to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](#stop-4) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the previewOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Returned with previewOutput stopped.');
  })
}
```

### stop<sup>(deprecated)</sup>

stop(): Promise\<void\>

Stops outputting preview streams. This API uses a promise to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](#stop-5) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.stop().then(() => {
    console.info('Callback returned with previewOutput stopped.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to previewOutput stop, error code: ${err.code}.`);
  });
}
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

Subscribes to preview frame start events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                    |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and returned when the bottom layer starts exposure for the first time.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. The preview starts as long as this event is returned.                   |

**Example**

```ts
function callback(): void {
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
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)                    |

**Example**

```ts
function unregisterPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameStart');
}
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback\<void\>): void

Subscribes to preview frame end events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and returned when the last frame of preview ends.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. The preview ends as long as this event is returned.               |

**Example**

```ts
function callback(): void {
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
| callback | AsyncCallback\<void\> | No  |  Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)               |

**Example**

```ts
function unregisterPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PreviewOutput** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a preview-related API such as [Session.start](#start-5) or [CameraOutput.release](#release-1).|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode). |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| callback | ErrorCallback | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)   |

**Example**

```ts
function unregisterPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('error');
}
```

### addDeferredSurface

addDeferredSurface(surfaceId: string): void

Adds a surface for delayed preview. This API can run after [commitConfig](#commitconfig) or [Session.start](#start-4) is called.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| surfaceId | string | Yes| Surface ID, which is obtained from [XComponent](../arkui-ts/ts-basic-components-xcomponent.md).|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |

**Example**

```ts
import common from '@ohos.app.ability.common';

async function preview(context: common.BaseContext, cameraInfo: camera.CameraDevice, previewProfile: camera.Profile, photoProfile: camera.Profile, photoSurfaceId: string, previewSurfaceId: string): Promise<void> {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameraInfo)
  const previewOutput: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);
  const photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, photoSurfaceId);
  const session: camera.CaptureSession  = cameraManager.createCaptureSession();
  session.beginConfig();
  session.addInput(cameraInput);
  session.addOutput(previewOutput);
  session.addOutput(photoOutput);
  await session.commitConfig();
  await session.start();
  previewOutput.addDeferredSurface(previewSurfaceId);
}
```

### isSketchSupported<sup>11+</sup>

isSketchSupported(): boolean

Checks whether Picture-in-Picture (PiP) preview is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | **true**: PiP preview is supported.<br>**false**: PiP preview is not supported.|

**Example**

```ts
function isSketchSupported(previewOutput: camera.PreviewOutput): boolean {
  let isSupported: boolean = previewOutput.isSketchSupported();
  return isSupported;
}
```

### getSketchRatio<sup>11+</sup>

getSketchRatio(): number

Obtains the zoom ratio when PiP preview is enabled.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| number | Zoom ratio obtained. If PiP preview is not supported, the value **-1** is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
function getSketchRatio(previewOutput: camera.PreviewOutput): number {
  let sketchRatio: number = previewOutput.getSketchRatio();
  return sketchRatio;
}
```

### enableSketch<sup>11+</sup>

enableSketch(enabled: boolean): void

Enables or disables PiP preview.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| enabled | boolean | Yes| Whether to enable PiP preview. The value **true** means to enable PiP preview, and **false** means to disable it.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function enableSketch(previewOutput: camera.PreviewOutput, captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.beginConfig();
    captureSession.addInput(cameraInput);
    captureSession.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    captureSession.commitConfig();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The enableSketch call failed. error code: ${err.code}`);
  }
}
```

### attachSketchSurface<sup>11+</sup>

attachSketchSurface(surfaceId: string): void

Attaches a surface for PiP preview.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| surfaceId | string | Yes| Surface ID, which is obtained from [XComponent](../arkui-ts/ts-basic-components-xcomponent.md).|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function attachSketchSurface(previewOutput: camera.PreviewOutput, captureSession: camera.CaptureSession, cameraInput: camera.CameraInput, sketchSurfaceId: string): void {
  try {
    captureSession.beginConfig();
    captureSession.addInput(cameraInput);
    captureSession.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    captureSession.commitConfig();
    previewOutput.attachSketchSurface(sketchSurfaceId);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The attachSketchSurface call failed. error code: ${err.code}`);
  }
}
```

### on('sketchStatusChanged')<sup>11+</sup>

on(type: 'sketchStatusChanged', callback: AsyncCallback\<SketchStatusData\>): void

Subscribes to PiP status change events. This API uses an asynchronous callback to return the PiP status data.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'sketchStatusChanged'**. The event can be listened for when a PiP preview stream is created. This event is triggered when PiP preview is enabled or disabled or the zoom ratio changes while PiP preview is enabled.|
| callback | AsyncCallback\<SketchStatusData\> | Yes  | Callback used to return the PiP status data.           |

**Example**

```ts
function callback(errorCode: number, data: camera.SketchStatusData): void {
  console.info(`sketch errorCode is ${errorCode}, data is ${JSON.stringify(data)}`);
}

function registerSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('sketchStatusChanged', callback);
}
```

### off('sketchStatusChanged')<sup>11+</sup>

off(type: 'sketchStatusChanged', callback?: AsyncCallback\<SketchStatusData\>): void

Unsubscribes from PiP status change events. This API uses an asynchronous callback to return the PiP status data.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'sketchStatusChanged'**. The event can be listened for when a PiP preview stream is created.|
| callback | AsyncCallback\<SketchStatusData\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)          |

**Example**

```ts
function unregisterSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('sketchStatusChanged');
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

| Name         | Type  | Mandatory|Description        |
| ------------ | ------ | --- |------------ |
| latitude     | number | Yes |Latitude, in degrees.   |
| longitude    | number | Yes |Longitude, in degrees.   |
| altitude     | number | Yes |Altitude, in meters.   |

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

| Name     | Type                           | Mandatory | Description                                                                  |
| -------- | ------------------------------- | ---- |----------------------------------------------------------------------|
| quality  | [QualityLevel](#qualitylevel)   | No  | Image quality (low by default).                                                          |
| rotation | [ImageRotation](#imagerotation) | No  | Rotation angle of the image. The default value is **0**, indicating clockwise rotation.                                                 |
| location | [Location](#location)           | No  | Geolocation information of the image (depending on the device hardware information by default).                                              |
| mirror   | boolean                         | No  | Whether mirror photography is enabled (disabled by default). Before using this enumerated value, call [isMirrorSupported](#ismirrorsupported) to check whether mirror photography is supported.|

## DeferredDeliveryImageType<sup>11+</sup>

Enumerates the deferred delivery image types. In deferred delivery, photo and video capture are divided into two phases. In the first phase, an image or video is output to users at a relatively fast speed. In the second phase, a higher-resolution image or video is output again after optimization processing.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name   | Value  | Description        |
| ------- | ---- | ------------ |
| NONE    | 0    | Deferred delivery is not supported.|
| PHOTO   | 1    | Deferred delivery for photo capture.|
| VIDEO   | 2    | Deferred delivery for video capture.|

## DeferredPhotoProxy<sup>11+</sup>

A class object that functions as a thumbnail proxy.

### getThumbnail

getThumbnail(): Promise<image.PixelMap>

Obtains the pixel map of a thumbnail.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<image.PixelMap\> | Pixel map of the thumbnail.|

**Example**

```ts
import image from '@ohos.multimedia.image';

function getThumbnail(proxyObj: camera.DeferredPhotoProxy): void {
  proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
    AppStorage.setOrCreate('proxyThumbnail', thumbnail);
  });
}
```

### release

release(): Promise\<void\>

Releases output resources. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Example**

```ts
async function releaseDeferredPhotoProxy(proxyObj: camera.DeferredPhotoProxy): Promise<void> {
  await proxyObj.release();
}
```

## Photo

Defines a higher-resolution image object.

### Attributes

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| main | [image.Image](js-apis-image.md#image9) |        Yes      | Higher-resolution image.|

### release

release(): Promise\<void\>

Releases output resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Example**

```ts
async function releaseDeferredPhotoProxy(photo: camera.Photo): Promise<void> {
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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function capture(photoOutput: camera.PhotoOutput): void {
  photoOutput.capture().then(() => {
    console.info('Promise returned to indicate that photo capture request success.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to photoOutput capture, error code: ${err.code}.`);
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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to photoOutput capture, error code: ${err.code}.`);
  });
}
```

### confirmCapture<sup>11+</sup>

confirmCapture(): void

Confirms photo capture. This API is generally used in night photo mode when users need to stop the exposure countdown and take a photo in advance.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104         |  Session not running.          |
| 7400201         |  Camera service fatal error.   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function confirmCapture(photoOutput: camera.PhotoOutput): void {
  try {
    photoOutput.confirmCapture();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The confirmCapture call failed. error code: ${err.code}`);
  }
}
```

### isDeferredImageDeliverySupported<sup>11+</sup>

isDeferredImageDeliverySupported(type: DeferredDeliveryImageType): boolean

Checks whether deferred delivery of a certain type is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type              | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
|   type   |  [DeferredDeliveryImageType](#deferreddeliveryimagetype11)  |   Yes  |   Deferred delivery image type.   |

**Return value**

| Type           | Description                   |
| -------------- | ----------------------- |
| boolean | **true**: Deferred delivery is supported.<br>**false**: Deferred delivery is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**Example**

```ts
function isDeferredImageDeliverySupported(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): boolean {
  let res: boolean = false;
  res = photoOutPut.isDeferredImageDeliverySupported(type);
  return res;
}
```

### isDeferredImageDeliveryEnabled<sup>11+</sup>

isDeferredImageDeliveryEnabled(type: DeferredDeliveryImageType): boolean

Checks whether deferred delivery of a certain type is enabled.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type              | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
|   type   |  [DeferredDeliveryImageType](#deferreddeliveryimagetype11)  |   Yes  |   Deferred delivery image type.   |

**Return value**

| Type           | Description                   |
| -------------- | ----------------------- |
| boolean | **true**: Deferred delivery is enabled. **false**: Deferred delivery is disabled.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**Example**

```ts
function isDeferredImageDeliveryEnabled(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): boolean {
  let res: boolean = false;
  res = photoOutPut.isDeferredImageDeliveryEnabled(type);
  return res;
}
```

### deferImageDelivery<sup>11+</sup>

deferImageDelivery(type: DeferredDeliveryImageType): void

Enables deferred delivery of a certain type.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type              | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
|   type   |  [DeferredDeliveryImageType](#deferreddeliveryimagetype11)  |   Yes  |   Deferred delivery image type.   |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**Example**

```ts
function deferImageDelivery(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): void {
  photoOutPut.deferImageDelivery(type);
}
```

### on('photoAvailable')<sup>11+</sup>

on(type: 'photoAvailable', callback: AsyncCallback\<Photo\>): void

Subscribes to events indicating available high-resolution images.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'photoAvailable'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[Photo](#photo)\> | Yes  | Callback used to return the high-resolution image.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, photo: camera.Photo): void {
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
| callback | AsyncCallback\<[Photo](#photo)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, photo: camera.Photo): void {
  let mainImage: image.Image = photo.main;
}

function unRegisterPhotoOutputPhotoAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('photoAvailable', callback);
}
```

### on('deferredPhotoProxyAvailable')<sup>11+</sup>

on(type: 'deferredPhotoProxyAvailable', callback: AsyncCallback\<DeferredPhotoProxy\>): void

Subscribes to events indicating available thumbnail proxies.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'deferredPhotoProxyAvailable'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | Yes  | Callback used to return the thumbnail proxy.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

function callback(err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void {
  proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
    AppStorage.setOrCreate('proxyThumbnail', thumbnail);
  });
}

function registerPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('deferredPhotoProxyAvailable', callback);
}
```

### off('deferredPhotoProxyAvailable')<sup>11+</sup>

off(type: 'deferredPhotoProxyAvailable', callback?: AsyncCallback\<DeferredPhotoProxy\>): void

Unsubscribes from events indicating available thumbnail proxies.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'deferredPhotoProxyAvailable'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)           |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

function callback(err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void {
  proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
    AppStorage.setOrCreate('proxyThumbnail', thumbnail);
  });
}

function unRegisterPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('deferredPhotoProxyAvailable', callback);
}
```

### on('captureStartWithInfo')<sup>11+</sup>

on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo\>): void

Subscribes to capture start events. This API uses an asynchronous callback to return the capture start ID.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'captureStartWithInfo'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[CaptureStartInfo](#capturestartinfo)\> | Yes  | Callback used to return the capture ID.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, captureStartInfo: camera.CaptureStartInfo): void {
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
| callback | AsyncCallback\<[CaptureStartInfo](#capturestartinfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function unRegisterCaptureStartWithInfo(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureStartWithInfo');
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

### on('captureStart')<sup>(deprecated)</sup>

on(type: 'captureStart', callback: AsyncCallback\<number\>): void

Subscribes to capture start events. This API uses an asynchronous callback to return the capture ID.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [on('captureStartWithInfo')](#oncapturestartwithinfo11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and returned when the bottom layer starts exposure each time a photo is taken.|
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the capture ID.           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, captureId: number): void {
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
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [off('captureStartWithInfo')](#offcapturestartwithinfo11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<number\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)           |

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
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, frameShutterInfo: camera.FrameShutterInfo): void {
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
| callback | AsyncCallback\<[FrameShutterInfo](#frameshutterinfo)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)            |

**Example**

```ts
function unregisterPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('frameShutter');
}
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo\>): void

Subscribes to capture end events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding information is returned when the photographing is complete.|
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | Yes  | Callback used to return the result.                 |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, captureEndInfo: camera.CaptureEndInfo): void {
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
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)                 |

**Example**

```ts
function unregisterPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PhotoOutput** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a photo-related API.|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).            |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| callback | ErrorCallback | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)  |

**Example**

```ts
function unregisterPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('error');
}
```

### isQuickThumbnailSupported

isQuickThumbnailSupported(): boolean

Checks whether the quick thumbnail feature is supported.

This API takes effect after [addOutput](#addoutput) and [addInput](#addinput) and before [commitConfig](#commitconfig).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type| Description|
| --------- | ------ |
| boolean | **true**: The quick thumbnail feature is supported.<br>**false**: The quick thumbnail feature is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  session is not running.        |

**Example**

```ts
import common from '@ohos.app.ability.common';

async function isQuickThumbnailSupported(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<boolean> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // Create a CaptureSession instance.
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();
  // Start configuration for the session.
  captureSession.beginConfig();
  // Add a CameraInput instance to the session.
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  captureSession.addInput(cameraInput);
  // Add a PhotoOutput instance to the session.
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);
  captureSession.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  return isSupported;
}
```

### enableQuickThumbnail

enableQuickThumbnail(enabled: boolean): void

Enables or disables the quick thumbnail feature.

This API takes effect after [addOutput](#addoutput) and [addInput](#addinput) and before [commitConfig](#commitconfig).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| enabled    | boolean       | Yes  | Whether to enable the quick thumbnail feature. The value **true** means to enable the quick thumbnail feature, and **false** means to disable it.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  session is not running.        |

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

async function enableQuickThumbnail(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // Create a CaptureSession instance.
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();
  // Start configuration for the session.
  captureSession.beginConfig();
  // Add a CameraInput instance to the session.
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  captureSession.addInput(cameraInput);
  // Add a PhotoOutput instance to the session.
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);
  captureSession.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  if (!isSupported) {
    console.info('Quick Thumbnail is not supported to be turned on.');
    return;
  }
  try {
    photoOutput.enableQuickThumbnail(true);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The enableQuickThumbnail call failed. error code: ${err.code}`);
  }
}
```

### on('quickThumbnail')

on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void

Subscribes to quick thumbnail output events.

The listening takes effect after **enableQuickThumbnail(true)** is called.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type    | string     | Yes  | Event type. The value is fixed at **'quickThumbnail'**.|
| callback | AsyncCallback\<[image.PixelMap](js-apis-image.md#pixelmap7)> | Yes| Callback that returns a **PixelMap** instance.|

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

function callback(err: BusinessError, pixelMap: image.PixelMap): void {
  if (err || pixelMap === undefined) {
      console.error('photoOutput on thumbnail failed');
      return;
  }
  // Display or save the PixelMap instance.
  // do something
}

async function registerQuickThumbnail(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // Create a CaptureSession instance.
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();
  // Start configuration for the session.
  captureSession.beginConfig();
  // Add a CameraInput instance to the session.
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  captureSession.addInput(cameraInput);
  // Add a PhotoOutput instance to the session.
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);
  captureSession.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  if (!isSupported) {
    console.info('Quick Thumbnail is not supported to be turned on.');
    return;
  }
  try {
    photoOutput.enableQuickThumbnail(true);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The enableQuickThumbnail call failed. error code: ${err.code}`);
  }

  photoOutput.on('quickThumbnail', callback);
}
```

### off('quickThumbnail')

off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void

Unsubscribes from quick thumbnail output events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type    | string     | Yes  | Event type. The value is fixed at **'quickThumbnail'**.|
| callback | AsyncCallback\<[image.PixelMap](js-apis-image.md#pixelmap7)> | No| Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterQuickThumbnail(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('quickThumbnail');
}
```

## FrameShutterInfo

Defines the frame shutter information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ---------- |
| captureId | number | Yes  | ID of this capture action. |
| timestamp | number | Yes  | Timestamp when the frame shutter event is triggered.|

## CaptureStartInfo<sup>11+</sup>

Defines the capture start information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type  | Mandatory| Description      |
| ---------- | ------ | ---- | ---------|
| captureId  | number | Yes  | ID of this capture action.|
| time | number | Yes  | Capture timestamp.   |

## CaptureEndInfo

Defines the capture end information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type  | Mandatory| Description      |
| ---------- | ------ | ---- | ---------|
| captureId  | number | Yes  | ID of this capture action.|
| frameCount | number | Yes  | Number of frames captured.   |

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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function startVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.start().then(() => {
    console.info('Promise returned to indicate that start method execution success.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to videoOutput start, error code: ${err.code}.`);
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
import { BusinessError } from '@ohos.base';

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
| Promise\<void\> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function stopVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.stop().then(() => {
    console.info('Promise returned to indicate that stop method execution success.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to videoOutput stop, error code: ${err.code}.`);
  });
}
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

Subscribes to video recording start events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **videoOutput** instance is created. The event is triggered and the corresponding information is returned when the bottom layer starts exposure for the first time.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  The recording starts as long as this event is returned.                    |

**Example**

```ts
function callback(): void {
  console.info('Video frame started');
}

function registerVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameStart', callback);
}
```

### off('frameStart')

off(type: 'frameStart', callback?: AsyncCallback\<void\>): void

Unsubscribes from video recording start events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **videoOutput** instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)                    |

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
function callback(): void {
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
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)                     |

**Example**

```ts
function unregisterVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.off('frameEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **VideoOutput** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type      | Mandatory| Description                                   |
| -------- | ----------- | ---- | -------------------------------------- |
| type     | string      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **videoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a recording-related API such as [start](#start-1) or [CameraOutput.release](#release-1).|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).                |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| callback | ErrorCallback | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)              |

**Example**

```ts
function unregisterVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.off('error');
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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start metadataOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with metadataOutput started.');
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
| Promise\<void\>          | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.start().then(() => {
    console.info('Callback returned with metadataOutput started.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to metadataOutput stop, error code: ${err.code}`);
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
import { BusinessError } from '@ohos.base';

function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the metadataOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with metadataOutput stopped.');
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
| Promise\<void\>         | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.stop().then(() => {
    console.info('Callback returned with metadataOutput stopped.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to metadataOutput stop, error code: ${err.code}`);
  });
}
```

### on('metadataObjectsAvailable')

on(type: 'metadataObjectsAvailable', callback: AsyncCallback\<Array\<MetadataObject\>\>): void

Subscribes to events indicating available metadata objects. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type        | Mandatory| Description                                 |
| -------- | -------------- | ---- | ------------------------------------ |
| type     | string         | Yes  | Event type. The value is fixed at **'metadataObjectsAvailable'**. The event can be listened for when a **metadataOutput** instance is created. This event is triggered and the corresponding metadata is returned when valid metadata is detected.|
| callback | Callback\<Array\<[MetadataObject](#metadataobject)\>\> | Yes  | Callback used to return the metadata.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>): void {
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
| callback | Callback\<Array\<[MetadataObject](#metadataobject)\>\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.off('metadataObjectsAvailable');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to metadata error events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                    |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **metadataOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a metadata-related API such as [start](#start-3) or [CameraOutput.release](#release-1).|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| callback | ErrorCallback | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)          |

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

| Name     | Type  |      Mandatory    |           Description                |
| -------- | ------ | --------------- | -------------------- |
| topLeftX | number |        Yes         | X-axis coordinate of the upper left corner of the rectangle.  |
| topLeftY | number |         Yes         | Y-axis coordinate of the upper left corner of the rectangle.  |
| width    | number |         Yes        | Width of the rectangle, which is a relative value. The value range is [0, 1]. |
| height   | number |         Yes        | Height of the rectangle, which is a relative value. The value range is [0, 1]. |

## MetadataObject

Implements camera metadata, which is the data source of [CameraInput](#camerainput). The metadata is obtained through metadataOutput.on('metadataObjectsAvailable').

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                           | Mandatory | Read-only|Description             |
| -------- | ------------------------------- | ---- | ---- |-----------------|
| type  | [MetadataObjectType](#metadataobjecttype)   | No  |  Yes | Metadata object type.|
| timestamp | number | No  |  Yes | Current timestamp, in milliseconds.|
| boundingBox | [Rect](#rect)           | No  |  Yes | Metadata rectangle.|

## PortraitEffect

Enumerates the portrait effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value   | Description    |
| ----------------| ----  | ---------|
| OFF             | 0      | Disabled.   |
| CIRCLES         | 1      | Circles.   |
| HEART<sup>11+</sup>           | 2      | Heart-shaped.   |
| ROTATED<sup>11+</sup>         | 3      | Rotated.   |
| STUDIO<sup>11+</sup>          | 4      | Studio light. |
| THEATER<sup>11+</sup>         | 5      | Theater light. |

## BeautyType

Enumerates the beauty types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value   | Description    |
| ----------------| ----  | ---------|
| AUTO           | 0      | Automatic.    |
| SKIN_SMOOTH    | 1      | Skin smoothing.    |
| FACE_SLENDER   | 2      | Face slimming.    |
| SKIN_TONE      | 3      | Skin tone perfection.    |

## FlashMode

Enumerates the flash modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Value  | Description       |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | The flash is off.|
| FLASH_MODE_OPEN        | 1    | The flash is on.|
| FLASH_MODE_AUTO        | 2    | The flash mode is auto, indicating that the flash fires automatically depending on the photo capture conditions.|
| FLASH_MODE_ALWAYS_OPEN | 3    | The flash is steady on.|

## ManualExposure<sup>11+</sup>

Provides APIs related to manual exposure.

### getSupportedExposureRange

getSupportedExposureRange(): Array\<number\>

Obtains the supported manual exposure durations.

**System API**: This is a system API.
 
**System capability**: SystemCapability.Multimedia.Camera.Core
 
**Return value**
 
| Type               | Description                                                 |
| ----------          | -----------------------------                         |
|  Array\<number\>| Array of manual exposure durations supported, in ms.                            |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.  |

 **Example**
 
```ts
function getSupportedExposureRange(nightPhotoSession: camera.NightPhotoSession): Array<number> {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  return exposureRange;
}
```

### getExposure

getExposure(): number

Obtains the manual exposure duration in use.

**System API**: This is a system API.
 
**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**
| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| value     | number | Yes  | Manual exposure duration, in ms. |

**Error codes**
 
For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getExposure(portraitSession: camera.PortraitPhotoSession): number {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return;
  }
  let exposure: number = nightPhotoSession.getExposure();
  return exposure;
}
```

### setExposure

setExposure(exposure: number): void

Sets the manual exposure duration, in ms.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                  |
| -------- | --------------------------| ---- | --------------------- |
| value    | number                    | Yes  | Manual exposure duration, which must be one of the supported durations obtained by running [getSupportedExposureRange](#getsupportedexposurerange).|

 **Error codes**

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.  |

```ts
function setExposure(nightPhotoSession: camera.NightPhotoSession): void {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return;
  }
  nightPhotoSession.setExposure(exposureRange[0]);
}
```

## ExposureMode

Enumerates the exposure modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_LOCKED          | 0    | Exposure locked. The metering point cannot be set.|
| EXPOSURE_MODE_AUTO            | 1    | Auto exposure. The metering point can be set by calling [setMeteringPoint](#setmeteringpoint).|
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | Continuous auto exposure. The metering point cannot be set.|

## FocusMode

Enumerates the focus modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                       | Value  | Description         |
| -------------------------- | ---- | ------------ |
| FOCUS_MODE_MANUAL          | 0    | Manual focus. The focal length of the camera can be manually set to change the focus position. However, the focal point cannot be set.    |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | Continuous auto focus. The focal point cannot be set.|
| FOCUS_MODE_AUTO            | 2    | Auto focus. The focal point can be set by calling [setFocusPoint](#setfocuspoint), and auto focus is performed once based on the focal point.   |
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

## Macro

Provides APIs related to macro photography.

### isMacroSupported

isMacroSupported(): boolean

Checks whether macro photography is supported in the current state. This API must be called after **commitConfig**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
|   boolean  | **true**: Macro photography is supported.<br>**false**: Macro photography is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
function isMacroSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = captureSession.isMacroSupported();
  return isSupported;
}
```

### enableMacro

enableMacro(enabled: boolean): void

Enables or disables macro photography. This API can be called only when macro photography is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | Yes  | Whether to enable macro photography. The value **true** means to enable macro photography, and **false** means to disable it.|

**Example**

```ts
function enableMacro(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = captureSession.isMacroSupported();
  if (isSupported) {
    captureSession.enableMacro(true);
  }
}
```

## Session<sup>11+</sup>

Implements a session, which saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera and requests the camera to take a photo or record a video.

### beginConfig

beginConfig(): void

Starts configuration for the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400105                |  Session config locked.               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### commitConfig

commitConfig(callback: AsyncCallback\<void\>): void

Commits the configuration for this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### commitConfig

commitConfig(): Promise\<void\>

Commits the configuration for this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig().then(() => {
    console.info('Promise returned to indicate the commit config success.');
  }).catch((err: BusinessError) => {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The commitConfig call failed. error code: ${err.code}`);
  });
}
```

### canAddInput<sup>11+</sup>

canAddInput(cameraInput: CameraInput): boolean

Determines whether a **CameraInput** instance can be added to this session. This API must be called after [beginConfig](#beginconfig) and before [commitConfig](#commitconfig).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| boolean | **true**: The **CameraInput** instance can be added.<br>**false**: The **CameraInput** instance cannot be added.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function canAddInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  let canAdd: boolean = captureSession.canAddInput(cameraInput);
  console.info(`The input canAddInput: ${canAdd}`);
}
```

### addInput

addInput(cameraInput: CameraInput): void

Adds a [CameraInput](#camerainput) instance to this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### removeInput

removeInput(cameraInput: CameraInput): void

Removes a [CameraInput](#camerainput) instance from this session. This API must be called after [beginConfig](#beginconfig) and before [commitConfig](#commitconfig).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### canAddOutput<sup>11+</sup>

canAddOutput(cameraOutput: CameraOutput): boolean

Determines whether a **CameraOutput** instance can be added to this session. This API must be called after [addInput](#addinput) and before [commitConfig](#commitconfig).

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraOutput | [CameraOutput](#cameraoutput) | Yes  | **CameraOutput** instance to add.|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| boolean | **true**: The **CameraOutput** instance can be added.<br>**false**: The **CameraOutput** instance cannot be added.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function canAddOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {
  let canAdd: boolean = captureSession.canAddOutput(cameraOutput);
  console.info(`This addOutput can add: ${canAdd}`);
}
```

### addOutput

addOutput(cameraOutput: CameraOutput): void

Adds a [CameraOutput](#cameraoutput) instance to this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### removeOutput

removeOutput(cameraOutput: CameraOutput): void

Removes a [CameraOutput](#cameraoutput) instance from this session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### start

start(callback: AsyncCallback\<void\>): void

Starts this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### start

start(): Promise\<void\>

Starts this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start().then(() => {
    console.info('Promise returned to indicate the session start success.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to start the session, error code: ${err.code}.`);
  });
}
```

### stop

stop(callback: AsyncCallback\<void\>): void

Stops this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### stop

stop(): Promise\<void\>

Stops this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop().then(() => {
    console.info('Promise returned to indicate the session stop success.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to stop the session, error code: ${err.code}.`);
  });
}
```

### release

release(callback: AsyncCallback\<void\>): void

Releases this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### release

release(): Promise\<void\>

Releases this session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release().then(() => {
    console.info('Promise returned to indicate that the CaptureSession instance is released successfully.');
  }).catch((err: BusinessError) => {
    let err = error as BusinessError;
    console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
  });
}
```

## Flash<sup>11+</sup>

Provides APIs related to the flash.

### hasFlash

hasFlash(): boolean

Checks whether the camera device has flash. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The camera device has flash.<br>**false**: The camera device does not have flash. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode): boolean

Checks whether a flash mode is supported.

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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setFlashMode

setFlashMode(flashMode: FlashMode): void

Sets a flash mode.

Before the setting, do the following checks:

1. Use [hasFlash](#hasflash) to check whether the camera device has flash.
2. Use [isFlashModeSupported](#isflashmodesupported) to check whether the camera device supports the flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                 |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getFlashMode

getFlashMode(): FlashMode

Obtains the flash mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FlashMode](#flashmode)    | Flash mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

## AutoExposure<sup>11+</sup>

Provides APIs related to auto exposure.

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode): boolean

Checks whether an exposure mode is supported.

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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getExposureMode

getExposureMode(): ExposureMode

Obtains the exposure mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [ExposureMode](#exposuremode)    | Exposure mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setExposureMode

setExposureMode(aeMode: ExposureMode): void

Sets an exposure mode. Before the setting, use [isExposureModeSupported](#isexposuremodesupported) to check whether the target exposure mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getMeteringPoint

getMeteringPoint(): Point

Obtains the metering point of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Metering point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setMeteringPoint

setMeteringPoint(point: Point): void

Sets the metering point, which is the center point of the metering rectangle. The metering point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.<br>The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is<br>based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y},<br>then the coordinate point after conversion is {y/h, 1-x/w}.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | Yes  | Metering point. The value range of x and y must be within [0, 1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.            |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function setMeteringPoint(captureSession: camera.CaptureSession): void {
  const exposurePoint: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setMeteringPoint(exposurePoint);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

### getExposureBiasRange

getExposureBiasRange(): Array\<number\>

Obtains the exposure compensation values of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Array of compensation values. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setExposureBias

setExposureBias(exposureBias: number): void

Sets an exposure compensation value (EV).

Before the setting, you are advised to use [getExposureBiasRange](#getexposurebiasrange) to obtain the supported values.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                |
| -------- | -------------------------------| ---- | ------------------- |
| exposureBias   | number                   | Yes  | EV. The supported EV range can be obtained by calling [getExposureBiasRange](#getexposurebiasrange). If the value passed is not within the supported range, the nearest critical point is used.<br>There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0.<br>If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getExposureValue

getExposureValue(): number

Obtains the exposure value in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Exposure value obtained. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0.<br>If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

## Focus<sup>11+</sup>

Provides APIs related to focus operations.

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode): boolean

Checks whether a focus mode is supported.

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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setFocusMode

setFocusMode(afMode: FocusMode): void

Sets a focus mode.

Before the setting, use [isFocusModeSupported](#isfocusmodesupported) to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getFocusMode

getFocusMode(): FocusMode

Obtains the focus mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FocusMode](#focusmode)   | Focus mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setFocusPoint

setFocusPoint(point: Point): void

Sets the focal point. The focal point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.<br>The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is<br>based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y},<br>then the coordinate point after conversion is {y/h, 1-x/w}.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](#point)         | Yes  | Focal point. The value range of x and y must be within [0, 1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getFocusPoint

getFocusPoint(): Point

Obtains the focal point of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Focal point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getFocalLength

getFocalLength(): number

Obtains the focal length of the camera device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Focal length, in mm. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

## SmoothZoomMode<sup>11+</sup>

Enumerates the smooth zoom modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Value  | Description           |
| ------------ | ---- | -------------- |
| NORMAL       | 0    | Bessel curve mode. |

## SmoothZoomInfo<sup>11+</sup>

Defines the smooth zoom information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type      |   Mandatory  | Description      |
| -------- | ---------- | -------- | ---------- |
| duration |   number   |     Yes   | Total duration of smooth zoom, in ms.|

## Zoom<sup>11+</sup>

Provides APIs related to zoom operations.

### getZoomRatioRange

getZoomRatioRange(): Array\<number\>

Obtains the supported zoom ratio range.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Callback used to return an array containing the minimum and maximum zoom ratios. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setZoomRatio

setZoomRatio(zoomRatio: number): void

Sets a zoom ratio, with a maximum precision of two decimal places.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                 | Mandatory| Description                |
| --------- | -------------------- | ---- | ------------------- |
| zoomRatio | number               | Yes  | Zoom ratio. The supported zoom ratio range can be obtained by calling [getZoomRatioRange](#getzoomratiorange). If the value passed in is not within the supported range, the value within the precision range is retained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getZoomRatio

getZoomRatio(): number

Obtains the zoom ratio in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Zoom ratio obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setSmoothZoom

setSmoothZoom(targetRatio: number, mode?: SmoothZoomMode): void

Sets smooth zoom.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type           | Mandatory| Description              |
| ------------ | -------------- | ---- | ----------------- |
| targetRatio  | number         | Yes  | Target zoom ratio.     |
| mode         | SmoothZoomMode | No  | Smooth zoom mode.     |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### prepareZoom

prepareZoom(): void

Instructs the bottom layer to prepare for zooming, for example, powering on the sensor.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Example**

```ts
import { BusinessError } from '@ohos.base';

function prepareZoom(sessionExtendsZoom: camera.Zoom): void {
  try {
    sessionExtendsZoom.prepareZoom();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The prepareZoom call failed. error code: ${err.code}`);
  }
}
```

### unprepareZoom

unprepareZoom(): void

Instructs the bottom layer to unprepare for zooming.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Example**

```ts
import { BusinessError } from '@ohos.base';

function unprepareZoom(sessionExtendsZoom: camera.Zoom): void {
  try {
    sessionExtendsZoom.unprepareZoom();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The unprepareZoom call failed. error code: ${err.code}`);
  }
}
```

## ZoomRange<sup>11+</sup>

Obtains the supported zoom ratio range. The range is [min, max), which includes the minimum value but excludes the maximum value.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type          | Mandatory| Read-only| Description        |
| -------- | ------------- |---- | ---- | -------------|
| min      | number        | Yes |  Yes | Minimum value of the zoom ratio range.  |
| max      | number        | Yes |  Yes | Maximum value of the zoom ratio range.|


## Stabilization<sup>11+</sup>

Provides APIs for stabilization-related operations.

### isVideoStabilizationModeSupported

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

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### getActiveVideoStabilizationMode

getActiveVideoStabilizationMode(): VideoStabilizationMode

Obtains the video stabilization mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoStabilizationMode](#videostabilizationmode)    | Video stabilization mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

### setVideoStabilizationMode

setVideoStabilizationMode(mode: VideoStabilizationMode): void

Sets a video stabilization mode. Before the setting, use [isVideoStabilizationModeSupported](#isvideostabilizationmodesupported) to check whether the target video stabilization mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

## Beauty<sup>11+</sup>

Provides APIs related to beauty settings.

### getSupportedBeautyTypes

getSupportedBeautyTypes(): Array\<BeautyType\>

Obtains the supported beauty types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type               | Description                                                 |
| ----------          | -----------------------------                         |
|  Array\<[BeautyType](#beautytype)\>| Array of beauty types supported.                            |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedBeautyTypes(portraitSession: camera.PortraitSession): Array<camera.BeautyType> {
  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();
  return beautyTypes;
}
```
### getSupportedBeautyRange

getSupportedBeautyRange(type: BeautyType): Array\<number\>

Obtains the levels that can be set a beauty type. The beauty levels vary according to the device type. The following table is only an example.

| Input Parameter          | Example Return Value   | Return Value Description    |
| ----------------| ----  | ---------|
| AUTO           | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     |Beauty levels supported when **type** is set to **AUTO**. The value **0** means that beauty mode is disabled, and other positive values mean the corresponding automatic beauty levels.   |
| SKIN_SMOOTH    | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     | Beauty levels supported when **type** is set to **SKIN_SMOOTH**. The value **0** means that the skin smoothing feature is disabled, and other positive values mean the corresponding skin smoothing levels.   |
| FACE_SLENDER   | [0, 1, 2, 3, 4, 5]      | Beauty levels supported when **type** is set to **FACE_SLENDER**. The value **0** means that the face slimming feature is disabled, and other positive values mean the corresponding face slimming levels.  |
| SKIN_TONE      | [-1, 16242611]      | Beauty levels supported when **type** is set to **SKIN_TONE**. The value **-1** means that the skin tone perfection feature is disabled. Other non-negative values mean the skin tone perfection levels represented by RGB,<br> for example, 16242611, which is 0xF7D7B3 in hexadecimal format, where F7, D7, and B3 represent the values of the R channel, G channel, and B channel, respectively.   |

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description      |
| -------- | --------------------------| ---- | ----------|
| type     | [BeautyType](#beautytype) | Yes  | Beauty type.  |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
|  Array\<number\>     | Array of levels supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedBeautyRange(portraitSession: camera.PortraitSession): Array<number> {
  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return [];
  }
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);
  return beautyLevels;
}
```

### setBeauty

setBeauty(type: BeautyType, value: number): void

Sets a beauty type and its level. Beauty mode is turned off only when all the [beauty types](#beautytype) obtained through [getSupportedBeautyTypes](#getsupportedbeautytypes) are disabled.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                  |
| -------- | --------------------------| ---- | --------------------- |
| type     | [BeautyType](#beautytype) | Yes  | Beauty type.             |
| value    | number                    | Yes  | Beauty level, which is obtained through [getSupportedBeautyRange](#getsupportedbeautyrange).|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function setBeauty(portraitSession: camera.PortraitSession): void {
  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return;
  }
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return;
  }
  portraitSession.setBeauty(beautyTypes[0], beautyLevels[0]);
}
```

### getBeauty

getBeauty(type: BeautyType): number

Obtains the level of the beauty type in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| type     | [BeautyType](#beautytype) | Yes  | Beauty type.  |

**Return value**
| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| value     | number | Yes  | Beauty level. |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getBeauty(portraitSession: camera.PortraitSession): number {
  const invalidValue: number = -1;
  let beautyTypes = portraitSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return invalidValue;
  }
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return invalidValue;
  }
  portraitSession.setBeauty(beautyTypes[0], beautyLevels[0]);
  let beautyLevel: number = portraitSession.getBeauty(beautyTypes[0]);
  return beautyLevel;
}
```

## ColorEffect<sup>11+</sup>

Provides the APIs for color effect settings.

### getSupportedColorEffects

getSupportedColorEffects(): Array\<ColorEffectType\>

Obtains the supported color effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[ColorEffectType](#coloreffecttype11)>       | Array of color effects supported.          |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
function getSupportedColorEffects(session: camera.PhotoSession): Array<camera.ColorEffectType> {
  let colorEffects: Array<camera.ColorEffectType> = session.getSupportedColorEffects();
  return colorEffects;
}
```

### setColorEffect

setColorEffect(type: ColorEffectType): void

Sets a color effect. Before the setting, use [getSupportedColorEffects](#getsupportedcoloreffects) to obtain the supported color effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| type | [ColorEffectType](#coloreffecttype11)                              | Yes| Color effect, which can be obtained through [getSupportedColorEffects](#getsupportedcoloreffects).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
function setColorEffect(session: camera.PhotoSession, colorEffect: camera.ColorEffectType): void {
  session.setColorEffect(colorEffect);
}
```

### getColorEffect

getColorEffect(): ColorEffectType

Obtains the color effect in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ColorEffectType](#coloreffecttype11)             | Color effect.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
function getColorEffect(session: camera.PhotoSession): camera.ColorEffectType {
  let colorEffect: camera.ColorEffectType = session.getColorEffect();
  return colorEffect;
}
```

## ColorEffectType<sup>11+</sup>

Enumerates the color effect types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                 | Value  | Description      |
| --------------------- | ---- | --------- |
| NORMAL                | 0    | Regular color effect. |
| BRIGHT                | 1    | Bright color effect. |
| SOFT                  | 2    | Soft color effect. |

## ColorManagement<sup>11+</sup>

Provides the APIs for color space settings.

### getSupportedColorSpaces

getSupportedColorSpaces(): Array\<colorSpaceManager.ColorSpace\>

Obtains the supported color spaces.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)>| Array of color spaces supported.    |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                       |
| 202             |  Not System Application.                   |

**Example**

```ts
function getSupportedColorSpaces(session: camera.PhotoSession): Array<colorSpaceManager.ColorSpace> {
  let colorSpaces: Array<colorSpaceManager.ColorSpace> = session.getSupportedColorSpaces();
  return colorSpaces;
}
```
### setColorSpace

setColorSpace(colorSpace: colorSpaceManager.ColorSpace): void

Sets a color space. Before the setting, use [getSupportedColorSpaces](#getsupportedcolorspaces) to obtain the supported color spaces.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                | Mandatory| Description                     |
| ------------ |---------------------- | -- | -------------------------- |
| colorSpace | [colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)  | Yes| Color space, which can be obtained through [getSupportedColorSpaces](#getsupportedcolorspaces).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202             |  Not System Application.            |
| 7400102         |  The colorSpace does not match the format.               |
| 7400103         |  Session not config.                |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
### getActiveColorSpace

getActiveColorSpace(): colorSpaceManager.ColorSpace

Obtains the color space in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)               | Color space.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
function getActiveColorSpace(session: camera.PhotoSession): colorSpaceManager.ColorSpace {
  let colorSpace: colorSpaceManager.ColorSpace = session.getActiveColorSpace();
  return colorSpace;
}
```

## Portrait<sup>11+</sup>

Provides the APIs for portrait photo settings.

### getSupportedPortraitEffects

getSupportedPortraitEffects(): Array\<PortraitEffect\>

Obtains the supported portrait effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[PortraitEffect](#portraiteffect)> | Array of portrait effects supported.              |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                |
| 202             |  Not System Application.            |

**Example**

```ts
function getSupportedPortraitEffects(portraitSession: camera.PortraitSession): Array<camera.PortraitEffect> {
  let portraitEffects: Array<camera.PortraitEffect> = portraitSession.getSupportedPortraitEffects();
  return portraitEffects;
}
```
### setPortraitEffect

setPortraitEffect(effect: PortraitEffect): void

Sets a portrait effect. Before the setting, use [getSupportedPortraitEffects](#getsupportedportraiteffects) to obtain the supported portrait effects and check whether the target portrait effect is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                       | Mandatory| Description                     |
| ------------ |----------------------------- | -- | -------------------------- |
| effect | [PortraitEffect](#portraiteffect)  | Yes| Portrait effect, which can be obtained through [getSupportedPortraitEffects](#getsupportedportraiteffects).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function setPortraitEffect(portraitSession: camera.PortraitSession, portraitEffects: Array<camera.PortraitEffect>): void {
  if (portraitEffects === undefined || portraitEffects.length <= 0) {
    return;
  }
  try {
    portraitSession.setPortraitEffect(portraitEffects[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setPortraitEffect call failed. error code: ${err.code}`);
  }
}
```
### getPortraitEffect

getPortraitEffect(): PortraitEffect

Obtains the portrait effect in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [PortraitEffect](#portraiteffect)               | Portrait effect.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
function getPortraitEffect(portraitSession: camera.PortraitSession): camera.PortraitEffect {
  let portraitEffect: camera.PortraitEffect = portraitSession.getPortraitEffect();
  return portraitEffect;
}
```

## PhysicalAperture<sup>11+</sup>

Defines the physical aperture information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type                      | Mandatory| Description             |
| ---------- | ------------------------- | ---- | -----------------|
| zoomRange  | [ZoomRange](#zoomrange11)   | Yes  | Zoom range of a given physical aperture. |
| apertures  | Array\<number\>           | Yes  | Array of physical apertures supported.     |

## Aperture<sup>11+</sup>

Provides the APIs for aperture settings.

### getSupportedVirtualApertures

getSupportedVirtualApertures(): Array\<number\>

Obtains the supported virtual apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array\<number\> | Array of virtual apertures supported.              |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                             |
| 202             |  Not System Application.                         |

**Example**

```ts
function getSupportedVirtualApertures(session: camera.PortraitPhotoSession): Array<number> {
  let virtualApertures: Array<number> = session.getSupportedVirtualApertures();
  return virtualApertures;
}
```

### getVirtualAperture

getVirtualAperture(): number

Obtains the virtual aperture in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| number               | Virtual aperture.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                             |
| 202             |  Not System Application.                         |

**Example**

```ts
function getVirtualAperture(session: camera.PortraitPhotoSession): number {
  let virtualAperture: number = session.getVirtualAperture();
  return virtualAperture;
}
```

### setVirtualAperture

setVirtualAperture(aperture: number): void

Sets a virtual aperture. Before the setting, use [getSupportedVirtualApertures](#getsupportedvirtualapertures) to obtain the supported virtual apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                   | Mandatory| Description                     |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | Yes| Virtual aperture, which can be obtained by calling [getSupportedVirtualApertures](#getsupportedvirtualapertures).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**Example**

```ts
setVirtualAperture:
function setVirtualAperture(session: camera.PortraitPhotoSession, virtualAperture: number): void {
  session.setVirtualAperture(virtualAperture);
}
```

### getSupportedPhysicalApertures

getSupportedPhysicalApertures(): Array\<PhysicalAperture\>

Obtains the supported physical apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[PhysicalAperture](#physicalaperture11)>    | Array of physical apertures supported.              |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**Example**

```ts
function getSupportedPhysicalApertures(session: camera.PortraitPhotoSession): Array<camera.PhysicalAperture> {
  let physicalApertures: Array<camera.PhysicalAperture> = session.getSupportedPhysicalApertures();
  return physicalApertures;
}
```

### getPhysicalAperture

getPhysicalAperture(): number

Obtains the physical aperture in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                | Description                          |
| -------------------- | ---------------------------- |
| number               | Physical aperture.          |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                             |
| 202             |  Not System Application.                         |

**Example**

```ts
function getPhysicalAperture(session: camera.PortraitPhotoSession): number {
  let physicalAperture: number = session.getPhysicalAperture();
  return physicalAperture;
}
```

### setPhysicalAperture

setPhysicalAperture(aperture: number): void

Sets a physical aperture. Before the setting, use [getSupportedPhysicalApertures](#getsupportedphysicalapertures) to obtain the supported physical apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                   | Mandatory| Description                     |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | Yes| Physical aperture, which can be obtained by calling [getSupportedPhysicalApertures](#getsupportedphysicalapertures).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**Example**

```ts
function setPhysicalAperture(session: camera.PortraitPhotoSession, physicalAperture: number): void {
  session.setPhysicalAperture(physicalAperture);
}
```

## CaptureSession<sup>(deprecated)</sup>

CaptureSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty

Implements a session, which saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera and requests the camera to take a photo or record a video.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [PhotoSession](#photosession11) and [VideoSession](#videosession11) instead.

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **CaptureSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                                                                                                                                                             |
| -------- | ----------------------------------------------------------- | ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig), [commitConfig](#commitconfig), and [addInput](#addinput).|
| callback | ErrorCallback| Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).                                                                                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError): void {
  console.error(`Capture session error code: ${err.code}`);
}

function registerSessionError(captureSession: camera.CaptureSession): void {
  captureSession.on('error', callback);
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **CaptureSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type               | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | ErrorCallback       | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)     |

**Example**

```ts
function unregisterSessionError(captureSession: camera.CaptureSession): void {
  captureSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.off('focusStateChange');
}
```

## PhotoSession<sup>11+</sup>

PhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Macro

Implements a photo session, which sets the parameters of the normal photo mode and saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera. It inherits from [Session](#session11).

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PhotoSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig), [commitConfig](#commitconfig), and [addInput](#addinput).|
| callback | ErrorCallback| Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError): void {
  console.error(`Photo session error code: ${err.code}`);
}

function registerSessionError(photoSession: camera.PhotoSession): void {
  photoSession.on('error', (error: BusinessError) => {
    console.error(`Photo session error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PhotoSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                          |
| -------- | -------------------------------- | ---- | ------------------------------ |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | ErrorCallback| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)    |

**Example**

```ts
function unregisterSessionError(photoSession: camera.PhotoSession): void {
  photoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
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
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('smoothZoomInfoAvailable');
}
```

### on('macroStatusChanged')

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

Subscribes to macro state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\>     | Yes  | Callback used to return the macro state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, macroStatus: boolean): void {
  console.info(`Macro state: ${macroStatus}`);
}

function registerMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.on('macroStatusChanged', callback);
}
```

### off('macroStatusChanged')

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from macro state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```

## VideoSession<sup>11+</sup>

VideoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Macro, Stabilization

Implements a video session, which sets the parameters of the normal video mode and saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera. It inherits from [Session](#session11).

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **VideoSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type             | Mandatory| Description                          |
| -------- | ------------------ | ---- | ------------------------------ |
| type     | string             | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig), [commitConfig](#commitconfig), and [addInput](#addinput).|
| callback | ErrorCallback      | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError): void {
  console.error(`Video session error code: ${err.code}`);
}

function registerSessionError(videoSession: camera.VideoSession): void {
  videoSession.on('error', callback);
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **VideoSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                         | Mandatory| Description                          |
| -------- | --------------------------- | ---- | ------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | ErrorCallback| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)     |

**Example**

```ts
function unregisterSessionError(videoSession: camera.VideoSession): void {
  videoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
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
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('smoothZoomInfoAvailable');
}
```

### on('macroStatusChanged')

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

Subscribes to macro state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\>     | Yes  | Callback used to return the macro state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, macroStatus: boolean): void {
  console.info(`Macro state: ${macroStatus}`);
}

function registerMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.on('macroStatusChanged', callback);
}
```

### off('macroStatusChanged')

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from macro state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.off('macroStatusChanged');
}
```

## PortraitPhotoSession<sup>11+</sup>

PortraitPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Portrait, Aperture

Implements a portrait photo session, which sets the parameters of the portrait photo mode and saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera. It inherits from [Session](#session11).

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PortraitSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig), [commitConfig](#commitconfig), and [addInput](#addinput).|
| callback | ErrorCallback| Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError): void {
  console.error(`Portrait photo session error code: ${err.code}`);
}

function registerSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('error', callback);
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PortraitSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | -------------------------- | ---- | ------------------------------ |
| type     | string                     | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | ErrorCallback| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)   |

**Example**

```ts
function unregisterSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterFocusStateChange(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterSmoothZoomInfo(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('smoothZoomInfoAvailable');
}
```

## NightPhotoSession<sup>11+</sup>

NightPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ColorManagement, ManualExposure

Implements a night photo session, which sets the parameters of the night photo mode and saves all [CameraInput](#camerainput) and [CameraOutput](#cameraoutput) instances required to run the camera. It inherits from [Session](#session11).

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **NightSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfig), [commitConfig](#commitconfig), and [addInput](#addinput).|
| callback | ErrorCallback| Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).|

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError): void {
  console.error(`Night photo session error code: ${err.code}`);
}

function registerSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('error', callback);
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **NightSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | ErrorCallback| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)      |

**Example**

```ts
function unregisterSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterFocusStateChange(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterSmoothZoomInfo(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('smoothZoomInfoAvailable');
}
```

## SketchStatusData<sup>11+</sup>

Defines the PiP status data.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type               | Mandatory| Description       |
| -------------- | ------------------ | ---- | ---------- |
| status         | number             | Yes  | Status of PiP. The options are 0 (stopped), 1 (started), 2 (stopping), and 3 (starting).|
| sketchRatio    | number             | Yes  | Zoom ratio of PiP.|
