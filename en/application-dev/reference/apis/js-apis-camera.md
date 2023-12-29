# @ohos.multimedia.camera (Camera Management)

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import camera from '@ohos.multimedia.camera';
```

## camera.getCameraManager

getCameraManager(context: BaseContext): CameraManager

Obtains a **CameraManager** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [BaseContext](js-apis-inner-application-baseContext.md)      | Yes  | Application context.                  |

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
## camera.getModeManager

getModeManager(context: BaseContext): ModeManager

Obtains a **ModeManager** instance. This API returns the result synchronously.

Mode management, as an enhancement to **CameraManager**, is used to manage advanced camera features such as portrait mode.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [BaseContext](js-apis-inner-application-baseContext.md)      | Yes  | Application context.                  |

**Return value**

| Type                                 | Description      |
| --------------------------------------| -----------|
| [ModeManager](#modemanager)           | Mode manager.|

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

function getModeManager(context: common.BaseContext): camera.ModeManager | undefined {
  let modeManager: camera.ModeManager | undefined = undefined;
  try {
    modeManager = camera.getModeManager(context);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getModeManager call failed. error code: ${err.code}`);
  }
  return modeManager;
}
```

## CameraStatus

Enumerates the camera statuses.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | A camera appears.  |
| CAMERA_STATUS_DISAPPEAR   | 1    | The camera disappears.    |
| CAMERA_STATUS_AVAILABLE   | 2    | The camera is available.      |
| CAMERA_STATUS_UNAVAILABLE | 3    | The camera is unavailable.    |

## Profile

Defines the camera profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| format   | [CameraFormat](#cameraformat) | Yes | Output format.     |
| size     | [Size](#size)                 | Yes | Resolution.      |

## FrameRateRange

Defines the frame rate range.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| min      | number                        | Yes | Minimum frame rate.     |
| max      | number                        | Yes | Maximum frame rate.     |

## VideoProfile

Defines the video profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Mandatory| Description       |
| ------------------------- | ----------------------------------------- | --- |----------- |
| frameRateRange            | [FrameRateRange](#frameraterange)         | Yes | Frame rate range, in units of frames per second (FPS).|

## CameraOutputCapability

Defines the camera output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Type                                              | Mandatory| Description               |
| ----------------------------- | -------------------------------------------------- | --- |------------------- |
| previewProfiles               | Array\<[Profile](#profile)\>                        | Yes | Supported preview profiles.   |
| photoProfiles                 | Array\<[Profile](#profile)\>                        | Yes | Supported shooting profiles.   |
| videoProfiles                 | Array\<[VideoProfile](#videoprofile)\>              | Yes | Supported video recording profiles.   |
| supportedMetadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Supported metadata object types.|

## CameraErrorCode

Enumerates the camera error codes, which are returned when an API call is incorrect or the **on()** API is used to listen for the error status.

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

## CameraMode

Enumerates the camera modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value   | Description    |
| ----------------| ----  | ---------|
| PORTRAIT         | 1    | Portrait mode. |

## FilterType

Enumerates the filter types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value   | Description    |
| ----------------| ----  | ---------|
| NONE           | 0      | No filter.    |
| CLASSIC        | 1      | Classic.    |
| DAWN           | 2      | Dawn.    |
| PURE           | 3      | Pure.    |
| GREY           | 4      | Gray.    |
| NATURAL        | 5      | Natural.    |
| MORI           | 6      | Mori.    |
| FAIR           | 7      | Fair.    |
| PINK           | 8      | Pink.    |


## PortraitEffect

Enumerates the portrait effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value   | Description    |
| ----------------| ----  | ---------|
| OFF             | 0      | Disabled.   |
| CIRCLES         | 1      | Circles.   |

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

## CameraManager

Implements camera management. Before calling any API in **CameraManager**, you must use **getCameraManager** to obtain a **CameraManager** instance.

### getSupportedCameras

getSupportedCameras(): Array\<CameraDevice\>

Obtains supported cameras. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[CameraDevice](#cameradevice)>            | An array of supported cameras.                  |

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

### getSupportedOutputCapability

getSupportedOutputCapability(camera:CameraDevice): CameraOutputCapability

Obtains the output capability supported by a camera. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | Yes| Target camera, which is obtained through **getSupportedCameras**.      |

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

### isCameraMuted

isCameraMuted(): boolean

Checks whether the camera is muted.

Before calling the API, ensure that the camera can be muted. You can use [isCameraMuteSupported](#iscameramutesupported) to check whether the camera can be muted.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                                        |
| ---------- | -------------------------------------------- |
| boolean    | Returns **true** if the camera is muted; returns **false** otherwise.|

**Example**

```ts
function isCameraMuted(cameraManager: camera.CameraManager): boolean {
  let isMuted: boolean = cameraManager.isCameraMuted();
  return isMuted;
}
```

### isCameraMuteSupported

isCameraMuteSupported(): boolean

Checks whether the camera can be muted.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the camera can be muted; returns **false** otherwise.|

**Example**

```ts
function isCameraMuteSupported(cameraManager: camera.CameraManager): boolean {
  let isMuteSupported: boolean = cameraManager.isCameraMuteSupported();
  return isMuteSupported;
}
```

### muteCamera

muteCamera(mute: boolean): void

Mutes or unmutes the camera.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                             | Mandatory | Description       |
| -------- | --------------------------------- | ---- | ---------- |
| mute     | boolean                           |  Yes |  Whether to mute the camera. The value **true** means to mute the camera, and **false** means the opposite. |

**Example**

```ts
function muteCamera(cameraManager: camera.CameraManager): void {
  let mute: boolean = true;
  cameraManager.muteCamera(mute);
}
```

### createCameraInput

createCameraInput(camera: CameraDevice): CameraInput

Creates a **CameraInput** instance with the specified **CameraDevice** object. This API returns the result synchronously.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| cameraDevice   | [CameraDevice](#cameradevice)         | Yes  | Target **CameraDevice** object, which is obtained through **getSupportedCameras**.  |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | **CameraInput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function createCameraInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput {
  let cameraInput: camera.CameraInput;
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
| position | [CameraPosition](#cameraposition)           | Yes  | Camera position, which is obtained through **getSupportedCameras**. This API obtains a **CameraDevice** object, which contains the camera position information. |
| type     | [CameraType](#cameratype)                   | Yes  | Camera type, which is obtained through **getSupportedCameras**. This API obtains a **CameraDevice** object, which contains the camera type information. |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | **CameraInput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

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
    console.log(`The createCameraInput call failed. error code: ${err.code}`);
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
| profile  | [Profile](#profile)                             | Yes  | Supported preview profiles, which are obtained through **getSupportedOutputCapability**.|
| surfaceId| string | Yes  | Surface ID, which is obtained from [XComponent](../arkui-ts/ts-basic-components-xcomponent.md) or [ImageReceiver](js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PreviewOutput](#previewoutput)    | **PreviewOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

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
    console.log(`The createPreviewOutput call failed. error code: ${err.code}`);
  }
  return previewOutput;
}
```

### createPhotoOutput

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

Creates a **PhotoOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | Yes  | Supported shooting profiles, which are obtained through **getSupportedOutputCapability**.|
| surfaceId| string            | Yes  | Surface ID, which is obtained from [ImageReceiver](js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | **PhotoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

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
    console.log(`The createPhotoOutput call failed. error code: ${err.code}`);
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
| profile  | [VideoProfile](#videoprofile)               | Yes  | Supported video recording profiles, which are obtained through **getSupportedOutputCapability**.|
| surfaceId| string          | Yes  | Surface ID, which is obtained from [VideoRecorder](js-apis-media.md#videorecorder9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoOutput](#videooutput)   | **VideoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

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
    console.log(`The createPhotoOutput call failed. error code: ${err.code}`);
  }
  return videoOutput;
}
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes:Array\<MetadataObjectType\>): MetadataOutput

Creates a **MetadataOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Metadata object types, which are obtained through **getSupportedOutputCapability**.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [MetadataOutput](#metadataoutput)   | **MetadataOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function createMetadataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): void {
  let metadataObjectTypes: Array<camera.MetadataObjectType> = cameraOutputCapability.supportedMetadataObjectTypes;
  let metadataOutput: camera.MetadataOutput;
  try {
    metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.log(`createMetadataOutput error. error code: ${err.code}`);
  }
}
```

### createCaptureSession

createCaptureSession(): CaptureSession

Creates a **CaptureSession** instance. This API returns the result synchronously.

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
    console.log(`createCaptureSession error. error code: ${err.code}`);
  }
  return captureSession;
}
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo\>): void

Subscribes to camera status events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'cameraStatus'**. The event can be listened for when a **CameraManager** instance is obtained. This event is triggered and the corresponding information is returned only when the device is enabled or disabled.|
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | Yes  | Callback used to return the camera status change.|                 |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraStatus', (err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo) => {
    console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
    console.log(`status: ${cameraStatusInfo.status}`);
  });
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
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | No  | Callback used for unsubscription. If a callback is passed in, only the subscription matching that callback is canceled.|                 |

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
| type     | string          | Yes  | Event type. The value is fixed at **'cameraMute'**, indicating the camera mute status. The event can be listened for when a **CameraManager** instance is obtained. This event is triggered and the status is returned when the camera is enabled or disabled.|
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the mute status. The value **true** means that the camera is enabled, and **false** means that the camera is disabled.              |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraMute', (err: BusinessError, curMuted: boolean) => {
    let isMuted: boolean = curMuted;
    console.log(`cameraMute status: ${isMuted}`);
  })
}
```

### off('cameraMute')

off(type: 'cameraMute', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from camera mute status events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'cameraMute'**, indicating the camera mute status. The event can be listened for when a **CameraManager** instance is obtained.|
| callback | AsyncCallback\<boolean> | No  | Callback used for unsubscription. If a callback is passed in, only the subscription matching that callback is canceled.              |

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

Checks whether a camera supports prelaunch.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| camera | [CameraDevice](#cameradevice) | Yes| Camera object.|

**Return value**

| Type| Description|
| -------- | --------------- |
| boolean | Returns whether the camera supports prelaunch. The value **true** means that the camera supports prelaunch, and **false** means the opposite.|

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
    console.log(`PreLaunch supported states: ${isSupported}`);
    return isSupported;
  }
  return isSupported;
}
```

### setPrelaunchConfig

setPrelaunchConfig(prelaunchConfig: PrelaunchConfig): void

Sets prelaunch configuration.

Before the setting, use [isPrelaunchSupported](#isprelaunchsupported) to check whether the device supports prelaunch.

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

Prelaunches the camera. This API is called when a user clicks the system camera icon to start the camera application.

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

Creates a deferred **PreviewOutput** instance and adds it to the data stream instead of a common **PreviewOutput** instance during stream configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| profile | [Profile](#profile) | Yes| Configuration file of the camera preview stream.|

**Return value**

| Type| Description|
| -------- | --------------- |
| [PreviewOutput](#previewoutput) | Returns a **PreviewOutput** instance.|

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
## ModeManager

Implements camera mode management. Before calling any API in this class, you must use [getModeManager](#cameragetmodemanager) to obtain a **ModeManager** instance.

### getSupportedModes

getSupportedModes(device: CameraDevice): Array\<CameraMode\>

Obtains the modes supported by a camera device. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | -------------------------- | ---- | ------------------- |
| device | [CameraDevice](#cameradevice)      | Yes  |   **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras). |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[CameraMode](#cameramode)>            | Array of the supported modes.                  |

**Example**

```ts
function getSupportedModes(modeManager: camera.ModeManager, cameraDevice: camera.CameraDevice): Array<camera.CameraMode> {
  let cameraModes: Array<camera.CameraMode> = modeManager.getSupportedModes(cameraDevice);
  return cameraModes;
}
```

### getSupportedOutputCapability

getSupportedOutputCapability(device:CameraDevice, mode: CameraMode): CameraOutputCapability

Obtains the output capability supported by a camera device in the specified mode. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| device       | [CameraDevice](#cameradevice)                              | Yes| **CameraDevice** instance, which is obtained through [getSupportedCameras](#getsupportedcameras).  |
| mode         | [CameraMode](#cameramode)                                  | Yes| Mode, which is obtained by calling [getSupportedModes](#getsupportedmodes).      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```ts
function getSupportedOutputCapability(cameraManager: camera.CameraManager, modeManager: camera.ModeManager): camera.CameraOutputCapability | undefined {
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  if (cameras == undefined || cameras.length <= 0) {
    return undefined;
  }
  let cameraDevice: camera.CameraDevice = cameras[0];
  let cameraModes: Array<camera.CameraMode> = modeManager.getSupportedModes(cameraDevice);
  if (cameraModes === undefined || cameraModes.length <= 0) {
    return undefined;
  }
  let mode: camera.CameraMode = cameraModes[0];
  let cameraOutputCapability: camera.CameraOutputCapability = modeManager.getSupportedOutputCapability(cameraDevice, mode);
  return cameraOutputCapability;
}
```
### createCaptureSession

createCaptureSession(mode: CameraMode): CaptureSession

Creates a session for a mode.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| mode | [CameraMode](#cameramode)                              | Yes| Mode, which is obtained by calling [getSupportedModes](#getsupportedmodes).      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CaptureSession](#capturesession)            | **CaptureSession** instance created.                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function createCaptureSession(cameraManager: camera.CameraManager, modeManager: camera.ModeManager): camera.CaptureSession {
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  if (cameras == undefined || cameras.length <= 0) {
    return;
  }
  let cameraDevice: camera.CameraDevice = cameras[0];
  let cameraModes: Array<camera.CameraMode> = modeManager.getSupportedModes(cameraDevice);
  if (cameraModes === undefined || cameraModes.length <= 0) {
    return;
  }
  let mode: camera.CameraMode = cameraModes[0];
  let captureSession: camera.CaptureSession
  try {
    captureSession = modeManager.createCaptureSession(mode);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The createCaptureSession call failed. error code: ${err.code}`);
  }
  return captureSession;
}
```

## PrelaunchConfig

Defines the camera prelaunch configuration.

Currently, the configuration is used for sensor-level prelaunch. It will be used for stream-level prelaunch in a later version.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| cameraDevice | [CameraDevice](#cameradevice) |        Yes      | Camera object.|

## CameraStatusInfo

Describes the camera status information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| camera | [CameraDevice](#cameradevice) |        Yes      | Camera object.|
| status | [CameraStatus](#camerastatus) |        Yes       | Camera status.|

## CameraPosition

Enumerates the camera positions.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Value  | Description           |
| --------------------------- | ---- | -------------- |
| CAMERA_POSITION_UNSPECIFIED | 0    | Unspecified position. |
| CAMERA_POSITION_BACK        | 1    | Rear camera.      |
| CAMERA_POSITION_FRONT       | 2    | Front camera.      |

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
| PHONE                        | 0x0E     | Camera of a smartphone.|
| TABLET                       | 0x11     | Camera of a tablet.|

## CameraDevice

Defines the camera device information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type                               | Mandatory| Description       |
| -------------- | --------------------------------- | ---- | ---------- |
| cameraId       | string                            | Yes  | **CameraDevice** object.|
| cameraPosition | [CameraPosition](#cameraposition) | Yes  | Camera position.   |
| cameraType     | [CameraType](#cameratype)         | Yes  | Camera type.   |
| connectionType | [ConnectionType](#connectiontype) | Yes  | Camera connection type.|
| hostDeviceName | string                            | Yes  | Name of the remote device.<br>**System API**: This is a system API.|
| hostDeviceType | [hostDeviceType](#hostdevicetype) | Yes  | Type of the remote device.<br>**System API**: This is a system API.|

## Size

Enumerates the camera output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type  | Readable| Writable| Description        |
| ------ | ------ | ---- | ---- | ------------ |
| height | number | Yes  | Yes  | Image height, in pixels.|
| width  | number | Yes  | Yes  | Image width, in pixels.|

## Point

Enumerates the point coordinates, which are used for focus and exposure configuration.

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

## CameraInput

Provides camera information used in **[CaptureSession](#capturesession)**.

### open

open\(callback: AsyncCallback\<void\>\): void

Opens this camera. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to open the camera. ${err.code}`);
      return;
    }
    console.log('Callback returned with camera opened.');
  });
}
```

### open

open(): Promise\<void\>

Opens this camera. This API uses a promise to return the result.

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
    console.log('Promise returned with camera opened.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to open the camera. ${err.code}`);
  });
}
```

### close

close\(callback: AsyncCallback\<void\>\): void

Closes this camera. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to close the cameras. ${err.code}`);
      return;
    }
    console.log('Callback returned with camera closed.');
  });
}
```

### close

close(): Promise\<void\>

Closes this camera. This API uses a promise to return the result.

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
    console.log('Promise returned with camera closed.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to close the cameras. ${err.code}`);
  });
}
```

### on('error')

on(type: 'error', camera:CameraDevice, callback: ErrorCallback): void

Subscribes to **CameraInput** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **CameraInput** instance is created. This event is triggered and the result is returned when an error occurs on the camera. For example, if the device is unavailable or a conflict occurs, the error information is returned.|
| cameraDevice   | [CameraDevice](#cameradevice)    | Yes  | **CameraDevice** object.|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {
  cameraInput.on('error', cameraDevice, (error: BusinessError) => {
    console.log(`Camera input error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', camera:CameraDevice, callback?: ErrorCallback): void

Unsubscribes from **CameraInput** error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **CameraInput** instance is created. This event is triggered and the result is returned when an error occurs on the camera. For example, if the device is unavailable or a conflict occurs, the error information is returned.|
| cameraDevice   | [CameraDevice](#cameradevice)    | Yes  | **CameraDevice** object.|
| callback | ErrorCallback | No  | Callback used for unsubscription. If a callback is passed in, only the subscription matching that callback is canceled.  |

**Example**

```ts

function unregisterCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {
  cameraInput.off('error', cameraDevice);
}
```

## FlashMode

Enumerates the flash modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Value  | Description       |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | The flash is off.|
| FLASH_MODE_OPEN        | 1    | The flash is on.|
| FLASH_MODE_AUTO        | 2    | The flash mode is auto, indicating that the flash fires automatically depending on the shooting conditions.|
| FLASH_MODE_ALWAYS_OPEN | 3    | The flash is steady on.|

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
| FOCUS_MODE_AUTO            | 2    | Auto focus. The focal point can be set by calling [setFocusPoint](#setfocuspoint), and auto focus is performed once based on the focal point. After the auto focus operation is complete (regardless of whether the focus is successful or fails), the focus mode is locked. To enable the camera to initiate another auto focus, the application must call **CONTINUOUS_AUTO** again.   |
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

## CaptureSession

Implements a shooting session, which saves all **[CameraInput](#camerainput)** and **[CameraOutput](#cameraoutput)** instances required to run the camera and requests the camera to complete shooting or video recording.

### beginConfig

beginConfig(): void

Starts configuration for the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

Commits the configuration for this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

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
    console.log('Callback invoked to indicate the commit config success.');
  });
}
```

### commitConfig

commitConfig(): Promise\<void\>

Commits the configuration for this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                     |
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
    console.log('Promise returned to indicate the commit config success.');
  }).catch((err: BusinessError) => {
    // If the operation fails, error.code is returned and processed.
    console.error(`The commitConfig call failed. error code: ${err.code}`);
  });
}
```

### addInput

addInput(cameraInput: CameraInput): void

Adds a [CameraInput](#camerainput) instance to the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function addInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.addInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.log(`The addInput call failed. error code: ${err.code}`);
  }
}
```

### removeInput

removeInput(cameraInput: CameraInput): void

Removes a [CameraInput](#camerainput) instance from the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function removeInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.removeInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.log(`The removeInput call failed. error code: ${err.code}`);
  }
}
```

### addOutput

addOutput(cameraOutput: CameraOutput): void

Adds a [CameraOutput](#cameraoutput) instance to the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to add.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function addOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {
  try {
    captureSession.addOutput(cameraOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.log(`The addOutput call failed. error code: ${err.code}`);
  }
}
```

### removeOutput

removeOutput(cameraOutput: CameraOutput): void

Removes a [CameraOutput](#cameraoutput) instance from the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to remove.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function removeOutput(captureSession: camera.CaptureSession, previewOutput: camera.PreviewOutput): void {
  try {
    captureSession.removeOutput(previewOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.log(`The removeOutput call failed. error code: ${err.code}`);
  }
}
```

### start

start\(callback: AsyncCallback\<void\>\): void

Starts this **CaptureSession**. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to start the session ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate the session start success.');
  });
}
```

### start

start\(\): Promise\<void\>

Starts this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise used to return the result.|

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
    console.log('Promise returned to indicate the session start success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start the session ${err.code}`);
  });
}
```

### stop

stop\(callback: AsyncCallback\<void\>\): void

Stops this **CaptureSession**. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to stop the session ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate the session stop success.');
  });
}
```

### stop

stop(): Promise\<void\>

Stops this **CaptureSession**. This API uses a promise to return the result.

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
    console.log('Promise returned to indicate the session stop success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to stop the session ${err.code}`);
  });
}
```

### release

release\(callback: AsyncCallback\<void\>\): void

Releases this **CaptureSession**. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to release the CaptureSession instance ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate that the CaptureSession instance is released successfully.');
  });
}
```

### release

release(): Promise\<void\>

Releases this **CaptureSession**. This API uses a promise to return the result.

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
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to release the CaptureSession instance ${err.code}`);
  });
}
```

### hasFlash

hasFlash(): boolean

Checks whether the device has flash. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the device has flash; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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
| boolean    | Returns **true** if the flash mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

Sets a flash mode for the device.

Before the setting, do the following checks:

1. Use **[hasFlash](#hasflash)** to check whether the device has flash.
2. Use **[isFlashModeSupported](#isflashmodesupported)** to check whether the device supports the flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                 |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.      |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

function getFlashMode(captureSession: camera.CaptureSession): camera.FlashMode {
  let flashMode: camera.FlashMode;
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

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode): boolean;

Checks whether an exposure mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.                     |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the exposure mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

function getExposureMode(captureSession: camera.CaptureSession): camera.ExposureMode {
  let exposureMode: camera.ExposureMode;
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

Sets an exposure mode for the device.

Before the setting, use [isExposureModeSupported](#isexposuremodesupported) to check whether the target exposure mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.               |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

Obtains the metering point of the device.  

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

function getMeteringPoint(captureSession: camera.CaptureSession): camera.Point {
  let exposurePoint: camera.Point;
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

Sets the metering point, which is the center point of the metering rectangle. The metering point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | Yes  | Metering point. The value range of x and y must be within [0,1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.            |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

Obtains the exposure compensation values of the device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | An array of compensation values. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

Before the setting, you are advised to use **[getExposureBiasRange](#getexposurebiasrange)** to obtain the supported values.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                |
| -------- | -------------------------------| ---- | ------------------- |
| exposureBias   | number                   | Yes  | EV. The supported EV range can be obtained by calling **getExposureBiasRange**. If the value passed is not within the supported range, the nearest critical point is used. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function setExposureBias(captureSession: camera.CaptureSession, biasRangeArray: Array<number>): void {
  let exposureBias = biasRangeArray[0];
  try {
    captureSession.setExposureBias(exposureBias);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setExposureBias call failed. error code: ${err.code}`);
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
| number    | Exposure value obtained. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function getExposureValue(captureSession: camera.CaptureSession): number {
  const invalid_value: number = -1;
  let exposureValue: number = invalid_value;
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
| boolean    | Returns **true** if the focus mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

Sets a focus mode for the device.

Before the setting, use **[isFocusModeSupported](#isfocusmodesupported)** to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.      |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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

function getFocusMode(captureSession: camera.CaptureSession): camera.FocusMode {
  let afMode: camera.FocusMode;
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

Sets the focal point. The focal point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| Point1    | [Point](#point)         | Yes  | Focal point. The value range of x and y must be within [0,1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.  |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function setFocusPoint(captureSession: camera.CaptureSession): void {
  const Point1: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setFocusPoint(Point1);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);
  }
}
```

### getFocusPoint

getFocusPoint(): Point

Obtains the focal point of the device.

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

function getFocusPoint(captureSession: camera.CaptureSession): camera.Point {
  let point: camera.Point;
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

Obtains the focal length of the device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Focal length obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function getFocalLength(captureSession: camera.CaptureSession): number {
  const invalid_value: number = -1;
  let focalLength: number = invalid_value;
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
| zoomRatio | number               | Yes  | Zoom ratio. The supported zoom ratio range can be obtained by calling **getZoomRatioRange**. If the value passed is not within the supported range, the nearest critical point is used.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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
  const invalid_value: number = -1;
  let zoomRatio: number = invalid_value;
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

### isVideoStabilizationModeSupported

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean

Checks whether the specified video stabilization mode is supported. 

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                            |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the video stabilization mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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
| VideoStabilizationMode    | Video stabilization mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function getActiveVideoStabilizationMode(captureSession: camera.CaptureSession): camera.VideoStabilizationMode {
  let vsMode: camera.VideoStabilizationMode;
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

Sets a video stabilization mode for the device.

Before the setting, use [isVideoStabilizationModeSupported](#isvideostabilizationmodesupported) to check whether the target video stabilization mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.  |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

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
### getSupportedFilters

getSupportedFilters(): Array\<number>

Obtains the supported filter types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
|  Array\<FilterType\>     | Array of the supported filter types.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedFilters(portraitSession: camera.PortraitSession): Array<camera.FilterType> {
  let filterTypes: Array<camera.FilterType> = portraitSession.getSupportedFilters();
  return filterTypes;
}
```
### setFilter

setFilter(filter: number): void

Sets a filter type.

Before the setting, use [getSupportedFilters](#getsupportedfilters) to obtain the supported filter types and check whether the target filter type is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                       | Mandatory| Description                 |
| -------- | ----------------------------| ---- | ---------------------|
| filter     | [number](#filtertype) | Yes  | Filter type to set. |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function setFilter(portraitSession: camera.PortraitSession, filterTypes: Array<camera.FilterType>): void {
  if (filterTypes === undefined || filterTypes.length <= 0) {
    return;
  }
  portraitSession.setFilter(filterTypes[0]);
}
```

### getFilter

 getFilter(): number

Obtains the filter type in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                    | Description                        |
| ----------               | ----------------------------|
| [number](#filtertype)| Filter type in use. For details, see [FilterType](#filtertype).|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getFilter(portraitSession: camera.PortraitSession): number {
  let filterType: number = portraitSession.getFilter();
  return filterType;
}
```
### getSupportedBeautyTypes

getSupportedBeautyTypes(): Array<[BeautyType](#beautytype)>

Obtains the supported beauty types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type               | Description                                                 |
| ----------          | -----------------------------                         |
|  Array\<[BeautyType](#beautytype)\>| Array of the supported beauty types.                            |

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
| type     | [BeautyType](#beautytype) | Yes  | Beauty type.              |
| value    | number                    | Yes  | Beauty level, which can be obtained through [getSupportedBeautyRange](#getsupportedbeautyrange).|

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
  const invalid_value: number = -1;
  let beautyTypes = portraitSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return invalid_value;
  }
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return invalid_value;
  }
  portraitSession.setBeauty(beautyTypes[0], beautyLevels[0]);
  let beautyLevel: number = portraitSession.getBeauty(beautyTypes[0]);
  return beautyLevel;
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    console.log(`Focus state: ${focusState}`);
  });
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](#focusstate)\> | No  | Callback used for unsubscription. |

**Example**

```ts
function unregisterFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.off('focusStateChange');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to **CaptureSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as **beginConfig()**, **commitConfig()**, and **addInput**.|
| callback | ErrorCallback| Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.on('error', (error: BusinessError) => {
    console.log(`Capture session error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **CaptureSession** error events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | ErrorCallback| No  | Callback used for unsubscription.      |

**Example**

```ts
function unregisterCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.off('error');
}
```
## PortraitSession

This class inherits from [CaptureSession](#capturesession). It is used to set parameters of portrait mode.

### getSupportedPortraitEffects

getSupportedPortraitEffects(): Array<[PortraitEffect](#portraiteffect)>

Obtains the supported portrait effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[PortraitEffect](#portraiteffect) > | Array of the supported portrait effects.              |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedPortraitEffects(portraitSession: camera.PortraitSession): Array<camera.PortraitEffect> {
  let portraitEffects: Array<camera.PortraitEffect> = portraitSession.getSupportedPortraitEffects();
  return portraitEffects;
}
```
### setPortraitEffect

setPortraitEffect(effect: PortraitEffect): void

Sets a portrait effect.

Before the setting, use [getSupportedPortraitEffects](#getsupportedportraiteffects) to obtain the supported portrait effects and check whether the target portrait effect is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| effect | [PortraitEffect](#portraiteffect)                              | Yes| Portrait effect, which can be obtained through [getSupportedPortraitEffects](#getsupportedportraiteffects).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

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
| [PortraitEffect](#portraiteffect)               | Portrait effect in use.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedPortraitEffects(portraitSession: camera.PortraitSession): Array<camera.PortraitEffect> {
  let portraitEffects: Array<camera.PortraitEffect> = portraitSession.getSupportedPortraitEffects();
  return portraitEffects;
}
```

## CameraOutput

Implements output information used in a **[CaptureSession](#capturesession)**. It is the base class of **output**.

## PreviewOutput

Implements preview output. It inherits **[CameraOutput](#cameraoutput)**.

### start

start(callback: AsyncCallback\<void\>): void

Starts to output preview streams. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to start the previewOutput. ${err.code}`);
      return;
    }
    console.log('Callback returned with previewOutput started.');
  });
}
```

### start

start(): Promise\<void\>

Starts to output preview streams. This API uses a promise to return the result.

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
    console.log('Promise returned with previewOutput started.');
  }).catch((err: BusinessError) => {
    console.log('Failed to previewOutput start '+ err.code);
  });
}
```

### stop

stop(callback: AsyncCallback\<void\>): void

Stops outputting preview streams. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to stop the previewOutput. ${err.code}`);
      return;
    }
    console.log('Callback returned with previewOutput stopped.');
  })
}
```

### stop

stop(): Promise\<void\>

Stops outputting preview streams. This API uses a promise to return the result.

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
    console.log('Callback returned with previewOutput stopped.');
  }).catch((err: BusinessError) => {
    console.log('Failed to previewOutput stop '+ err.code);
  });
}
```

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
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
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
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.log('Failed to previewOutput release '+ err.code);
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
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. The preview starts as long as this event is returned.                    |

**Example**

```ts
function registerPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('frameStart', () => {
    console.log('Preview frame started');
  });
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
| callback | AsyncCallback\<void\> | No  | Callback used for unsubscription.                    |

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
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. The preview ends as long as this event is returned.                |

**Example**

```ts
function registerPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
  });
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
| callback | AsyncCallback\<void\> | No  | Callback used for unsubscription.               |

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
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a preview-related API such as **start()** or **release()**.|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode). |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('error', (previewOutputError: BusinessError) => {
    console.log(`Preview output error code: ${previewOutputError.code}`);
  })
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
| callback | ErrorCallback | No  | Callback used for unsubscription. |

**Example**

```ts
function unregisterPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('error');
}
```

### addDeferredSurface

addDeferredSurface(surfaceId: string): void

Adds a surface for delayed preview. This API can run after **session.commitConfig()** or **session.start()** is called.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| surfaceId | string | Yes| Surface ID, which is obtained from **[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)**.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |

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

Defines geolocation information.

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

Defines the settings for photo capture.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                           | Mandatory | Description             |
| -------- | ------------------------------- | ---- | -----------------|
| quality  | [QualityLevel](#qualitylevel)   | No  | Photo quality.        |
| rotation | [ImageRotation](#imagerotation) | No  | Rotation angle of the photo.     |
| location | [Location](#location)           | No  | Geolocation information of the photo.  |
| mirror   | boolean                         | No  |Whether mirroring is enabled. By default, mirroring is disabled.|

## PhotoOutput

Implements output information used in a shooting session. This class inherits from [CameraOutput](#cameraoutput).

### capture

capture(callback: AsyncCallback\<void\>): void

Captures a photo with the default shooting parameters. This API uses an asynchronous callback to return the result.

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
      console.error(`Failed to capture the photo ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
  });
}
```

### capture

capture(): Promise\<void\>

Captures a photo with the default shooting parameters. This API uses a promise to return the result.

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
    console.log('Promise returned to indicate that photo capture request success.');
  }).catch((err: BusinessError) => {
    console.log('Failed to photoOutput capture '+ err.code);
  });
}
```

### capture

capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void\>): void

Captures a photo with the specified shooting parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                        | Mandatory| Description                 |
| -------- | ------------------------------------------- | ---- | -------------------- |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | Yes  | Shooting settings.            |
| callback | AsyncCallback\<void\>                        | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned. |

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function capture(photoOutput: camera.PhotoOutput): void {
  let captureLocation: camera.Location = {
    latitude: 0,
    longitude: 0,
    altitude: 0,
  }
  let settings: camera.PhotoCaptureSetting = {
    quality: camera.QualityLevel.QUALITY_LEVEL_LOW,
    rotation: camera.ImageRotation.ROTATION_0,
    location: captureLocation,
    mirror: false
  }
  photoOutput.capture(settings, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to capture the photo ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
  });
}
```

### capture

capture(setting?: PhotoCaptureSetting): Promise\<void\>

Captures a photo with the specified shooting parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description     |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](#photocapturesetting) | No  | Shooting parameters. The input of **undefined** is processed as if no parameters were passed.|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function capture(photoOutput: camera.PhotoOutput): void {
  let captureLocation: camera.Location = {
    latitude: 0,
    longitude: 0,
    altitude: 0,
  }
  let settings: camera.PhotoCaptureSetting = {
    quality: camera.QualityLevel.QUALITY_LEVEL_LOW,
    rotation: camera.ImageRotation.ROTATION_0,
    location: captureLocation,
    mirror: false
  }
  photoOutput.capture(settings).then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
  }).catch((err: BusinessError) => {
    console.log('Failed to photoOutput capture '+ err.code);
  });
}
```

### isMirrorSupported

isMirrorSupported(): boolean

Checks whether mirroring is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | Returns **true** if mirroring is supported; returns **false** otherwise.|

**Example**

```ts
function isMirrorSupported(photoOutput: camera.PhotoOutput): boolean {
  let isSupported: boolean = photoOutput.isMirrorSupported();
  return isSupported;
}
```

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

function releasePhotoOutput(photoOutput: camera.PhotoOutput): void {
  photoOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the PreviewOutput instance ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
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

function releasePhotoOutput(photoOutput: camera.PhotoOutput): void {
  photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.log('Failed to photoOutput release '+ err.code);
  });
}
```

### on('captureStart')

on(type: 'captureStart', callback: AsyncCallback\<number\>): void

Subscribes to shooting start events. This API uses an asynchronous callback to return the capture ID.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and returned when the bottom layer starts exposure each time a photo is taken.|
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the capture ID.           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureStart', (err: BusinessError, captureId: number) => {
    console.log(`photo capture stated, captureId : ${captureId}`);
  });
}
```

### off('captureStart')

off(type: 'captureStart', callback?: AsyncCallback\<number\>): void

Unsubscribes from shooting start events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<number\> | No  | Callback used for unsubscription.           |

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

function registerPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('frameShutter', (err: BusinessError, frameShutterInfo: camera.FrameShutterInfo) => {
    console.log(`photo capture end, captureId : ${frameShutterInfo.captureId}`);
    console.log(`Timestamp for frame : ${frameShutterInfo.timestamp}`);
  });
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
| callback | AsyncCallback\<[FrameShutterInfo](#frameshutterinfo)\> | No  | Callback used for unsubscription.            |

**Example**

```ts
function unregisterPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('frameShutter');
}
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo\>): void

Subscribes to shooting end events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding information is returned when the photographing is complete.|
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | Yes  | Callback used to return the result.                 |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
    console.log(`photo capture end, captureId : ${captureEndInfo.captureId}`);
    console.log(`frameCount : ${captureEndInfo.frameCount}`);
  });
}
```

### off('captureEnd')

off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo\>): void

Unsubscribes from shooting end events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | No  | Callback used for unsubscription.                 |

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
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a photographing-related API.|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).            |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('error', (error: BusinessError) => {
    console.log(`Photo output error code: ${error.code}`);
  });
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
| callback | ErrorCallback | No  | Callback used for unsubscription.          |

**Example**

```ts
function unregisterPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('error');
}
```

### isQuickThumbnailSupported

isQuickThumbnailSupported(): boolean

Checks whether the quick thumbnail feature is supported.

This API takes effect after **CaptureSession.addOutput** and **CaptureSession.addInput** and before **CaptureSession.commitConfig**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type| Description|
| --------- | ------ |
| boolean | Returns whether the quick thumbnail feature is supported. The value **true** means that the quick thumbnail feature is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  session is not running        |

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
  // Add the photoOutput object to the session.
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);
  captureSession.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  return isSupported;
}
```

### enableQuickThumbnail

enableQuickThumbnail(enabled: boolean): void

Enables or disables the quick thumbnail feature.

This API takes effect after **CaptureSession.addOutput** and **CaptureSession.addInput** and before **CaptureSession.commitConfig**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| enabled    | boolean       | Yes  | Whether to enable the quick thumbnail feature. The value **true** means to enable the quick thumbnail feature, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Camera Error Codes](../errorcodes/errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  session is not running        |

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
    console.log('Quick Thumbnail is not supported to be turned on.');
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
| callback | AsyncCallback\<[image.PixelMap](js-apis-image.md#pixelmap7)> | Yes| Promise that returns a **PixelMap** instance.|

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

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
    console.log('Quick Thumbnail is not supported to be turned on.');
    return;
  }
  try {
    photoOutput.enableQuickThumbnail(true);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The enableQuickThumbnail call failed. error code: ${err.code}`);
  }

  photoOutput.on('quickThumbnail', (err: BusinessError, pixelMap: image.PixelMap) => {
    if (err || pixelMap === undefined) {
      console.error('photoOutput on thumbnail failed');
      return;
    }
    // Display or save the PixelMap instance.
    // do something
  })
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
| callback | AsyncCallback\<[image.PixelMap](js-apis-image.md#pixelmap7)> | No| Callback used for unsubscription.|

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

## CaptureEndInfo

Defines the capture end information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type  | Mandatory| Description      |
| ---------- | ------ | ---- | ---------|
| captureId  | number | Yes  | ID of this capture action.|
| frameCount | number | Yes  | Number of frames captured.   |

## VideoOutput

Implements output information used in a video recording session. This class inherits from [CameraOutput](#cameraoutput).

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
      console.error(`Failed to start the video output ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate the video output start success.');
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
    console.log('Promise returned to indicate that start method execution success.');
  }).catch((err: BusinessError) => {
    console.log('Failed to videoOutput start '+ err.code);
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
      console.error(`Failed to stop the video output ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate the video output stop success.');
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
    console.log('Promise returned to indicate that stop method execution success.');
  }).catch((err: BusinessError) => {
    console.log('Failed to videoOutput stop '+ err.code);
  });
}
```

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

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the PreviewOutput instance ${err.code}`);
      return;
    }
    console.log('Callback invoked to indicate that the videoOutput instance is released successfully.');
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

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the videoOutput instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.log('Failed to videoOutput release '+ err.code);
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
function registerVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameStart', () => {
    console.log('Video frame started');
  });
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
| callback | AsyncCallback\<void\> | No  | Callback used for unsubscription.                    |

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
function registerVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
  });
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
| callback | AsyncCallback\<void\> | No  | Callback used for unsubscription.                     |

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
| type     | string      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **videoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a recording-related API such as **start()** and **release()**.|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).                |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.on('error', (error: BusinessError) => {
    console.log(`Video output error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **VideoOutput** error events.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type      | Mandatory| Description                                   |
| -------- | ----------- | ---- | -------------------------------------- |
| type     | string      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **videoOutput** instance is created.|
| callback | ErrorCallback | No  | Callback used for unsubscription.              |

**Example**

```ts
function unregisterVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.off('error');
}
```

## MetadataOutput

Implements metadata streams. It inherits **[CameraOutput](#cameraoutput)**.

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
      console.error(`Failed to start metadataOutput. ${err.code}`);
      return;
    }
    console.log('Callback returned with metadataOutput started.');
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
    console.log('Callback returned with metadataOutput started.');
  }).catch((err: BusinessError) => {
    console.log('Failed to metadataOutput start '+ err.code);
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
      console.error(`Failed to stop the metadataOutput. ${err.code}`);
      return;
    }
    console.log('Callback returned with metadataOutput stopped.');
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
    console.log('Callback returned with metadataOutput stopped.');
  }).catch((err: BusinessError) => {
    console.log('Failed to metadataOutput stop '+ err.code);
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

function registerMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.on('metadataObjectsAvailable', (err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>) => {
    console.log(`metadata output metadataObjectsAvailable`);
  });
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
| callback | Callback\<Array\<[MetadataObject](#metadataobject)\>\> | No  | Callback used for unsubscription.|

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
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **metadataOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a metadata-related API such as **start()** and **release()**.|
| callback | ErrorCallback | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function registerMetadataOutputError(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.on('error', (metadataOutputError: BusinessError) => {
    console.log(`Metadata output error code: ${metadataOutputError.code}`);
  });
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
| callback | ErrorCallback | No  | Callback used for unsubscription.          |

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
| FACE_DETECTION            | 0    | Face detection. The detection point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.<br> The coordinate system is based on the horizontal device direction with the device's charging port on the right.<br> If the layout of a preview screen of an application is based on the vertical direction with the charging port on the lower side,<br> the layout width and height are {w, h} and the return point is {x, y}, then the coordinate point after conversion is {1-y, x}.|

## Rect

Defines a rectangle.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  |      Mandatory    |           Description                |
| -------- | ------ | --------------- | -------------------- |
| topLeftX | number |        Yes         | X-axis coordinate of the upper left corner of the rectangle.  |
| topLeftY | number |         Yes         | Y-axis coordinate of the upper left corner of the rectangle.  |
| width    | number |         Yes        | Width of the rectangle.             |
| height   | number |         Yes          |Height of the rectangle.             |

## MetadataObject

Implements camera metadata, which is the data source of [CameraInput](#camerainput). The metadata is obtained through metadataOutput.on('metadataObjectsAvailable').

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                           | Mandatory | Description             |
| -------- | ------------------------------- | ---- | -----------------|
| type  | [MetadataObjectType](#metadataobjecttype)   | No  | Metadata data type. Only face recognition is supported.|
| timestamp | number | No  | Current timestamp, in milliseconds.|
| boundingBox | [Rect](#rect)           | No  | Metadata rectangle.|
