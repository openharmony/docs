# Interface (CameraManager)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

CameraManager implements camera management. Before calling any API in CameraManager, you must use [getCameraManager](arkts-apis-camera-f.md#cameragetcameramanager) to obtain a CameraManager instance.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## getSupportedCameras

getSupportedCameras(): Array\<CameraDevice\>

Obtains the supported camera devices. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[CameraDevice](arkts-apis-camera-i.md#cameradevice)>            | Array of camera devices supported.                  |

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

## getSupportedSceneModes<sup>11+</sup>

getSupportedSceneModes(camera: CameraDevice): Array\<SceneMode\>

Obtains the scene modes supported by a camera device. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| camera | [CameraDevice](arkts-apis-camera-i.md#cameradevice)                              | Yes| CameraDevice instance, which is obtained through [getSupportedCameras](#getsupportedcameras). An error code is returned if the input parameter is invalid.      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[SceneMode](arkts-apis-camera-e.md#scenemode11)>            | Array of scene modes supported.                  |

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

## getSupportedOutputCapability<sup>11+</sup>

getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability

Obtains the output capability supported by a camera device in a given scene mode. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| camera | [CameraDevice](arkts-apis-camera-i.md#cameradevice)                              | Yes| CameraDevice instance, which is obtained through [getSupportedCameras](#getsupportedcameras).      |
| mode | [SceneMode](arkts-apis-camera-e.md#scenemode11)                              | Yes| Scene mode, which is obtained through [getSupportedSceneModes](#getsupportedscenemodes11).      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](arkts-apis-camera-i.md#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```ts
function getSupportedOutputCapability(camera: camera.CameraDevice, cameraManager: camera.CameraManager, sceneMode: camera.SceneMode): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(camera, sceneMode);
  return cameraOutputCapability;
}
```

## isCameraMuted

isCameraMuted(): boolean

Checks whether this camera is muted.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                                        |
| ---------- | -------------------------------------------- |
| boolean    | Check result. The value **true** means that the camera device is muted, and **false** means the opposite.|

**Example**

```ts
function isCameraMuted(cameraManager: camera.CameraManager): boolean {
  let isMuted: boolean = cameraManager.isCameraMuted();
  return isMuted;
}
```

## createCameraInput

createCameraInput(camera: CameraDevice): CameraInput

Creates a CameraInput instance with the specified CameraDevice instance. This API returns the result synchronously.

Before calling this API, call [getSupportedCameras](#getsupportedcameras) to obtain the list of supported camera devices, select the camera device that meets the requirements based on the actual usage scenario, and then create the CameraInput instance.

**Required permissions**: ohos.permission.CAMERA

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                              |
| -------- | ------------------------------------------- | ---- |--------------------------------------------------|
| camera  | [CameraDevice](arkts-apis-camera-i.md#cameradevice)         | Yes  | CameraDevice instance, which is obtained through [getSupportedCameras](#getsupportedcameras).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](arkts-apis-camera-CameraInput.md)    | CameraInput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createCameraInput

createCameraInput(position: CameraPosition, type: CameraType): CameraInput

Creates a CameraInput instance with the specified camera position and type. This API returns the result synchronously.

Before calling this API, specify the camera position and type based on the usage scenario. For example, open the front camera for the selfie feature

**Required permissions**: ohos.permission.CAMERA

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| position | [CameraPosition](arkts-apis-camera-e.md#cameraposition)           | Yes  | Camera position. You need to obtain the supported camera object by calling [getSupportedCameras](#getsupportedcameras) and then obtain the device position information based on the returned camera object. |
| type     | [CameraType](arkts-apis-camera-e.md#cameratype)                   | Yes  | Camera type. You need to obtain the supported camera object by calling [getSupportedCameras](#getsupportedcameras) and then obtain the camera type based on the returned camera object.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](arkts-apis-camera-CameraInput.md)    | CameraInput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput

Creates a PreviewOutput instance. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                             |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](arkts-apis-camera-i.md#profile)                             | Yes  | Supported preview profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string | Yes  | Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) or [ImageReceiver](../apis-image-kit/arkts-apis-image-ImageReceiver.md).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PreviewOutput](arkts-apis-camera-PreviewOutput.md)  | PreviewOutput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createPreviewOutput<sup>12+</sup>

createPreviewOutput(surfaceId: string): PreviewOutput

Creates a PreviewOutput instance without configuration. This API returns the result synchronously. It must be used with [preconfig](arkts-apis-camera-PhotoSession.md#preconfig12).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                             |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| surfaceId| string | Yes  | Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) or [ImageReceiver](../apis-image-kit/arkts-apis-image-ImageReceiver.md).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PreviewOutput](arkts-apis-camera-PreviewOutput.md)    | PreviewOutput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createPhotoOutput<sup>11+</sup>

createPhotoOutput(profile?: Profile): PhotoOutput

Creates a PhotoOutput instance. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- |----| ----------------------------------- |
| profile  | [Profile](arkts-apis-camera-i.md#profile)                         | No | Supported photo profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).<br>In API version 11, this parameter is mandatory. Since API version 12, it will overwrite the preconfigured parameters passed in through [preconfig](arkts-apis-camera-PhotoSession.md#preconfig12).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](arkts-apis-camera-PhotoOutput.md)   | PhotoOutput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput

Creates a VideoOutput instance. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                             |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| profile  | [VideoProfile](arkts-apis-camera-i.md#videoprofile)               | Yes  | Supported video profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string          | Yes  | Surface ID, which is obtained from [AVRecorder](../apis-media-kit/arkts-apis-media-AVRecorder.md).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoOutput](arkts-apis-camera-VideoOutput.md)   | VideoOutput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createVideoOutput<sup>12+</sup>

createVideoOutput(surfaceId: string): VideoOutput

Creates a VideoOutput instance without configuration. This API returns the result synchronously. It must be used with [preconfig](arkts-apis-camera-VideoSession.md#preconfig12).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type    | Mandatory   | Description                                                                        |
|-----------|--------|-------|----------------------------------------------------------------------------|
| surfaceId | string | Yes    | Surface ID, which is obtained from [AVRecorder](../apis-media-kit/arkts-apis-media-AVRecorder.md).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoOutput](arkts-apis-camera-VideoOutput.md)   | VideoOutput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createMetadataOutput

createMetadataOutput(metadataObjectTypes: Array\<MetadataObjectType\>): MetadataOutput

Creates a MetadataOutput instance. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array\<[MetadataObjectType](arkts-apis-camera-e.md#metadataobjecttype)\>  | Yes | Metadata object types, which are obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [MetadataOutput](arkts-apis-camera-MetadataOutput.md)   | MetadataOutput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createSession<sup>11+</sup>

createSession\<T extends Session\>(mode: SceneMode): T

Creates a Session instance with a given scene mode. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type             | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| mode     | [SceneMode](arkts-apis-camera-e.md#scenemode11)     | Yes  | Scene mode. The API does not take effect if the input parameter is invalid (for example, the value is out of range, null, or undefined).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [T extends Session](arkts-apis-camera-Session.md)   | Session instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                                                                                                                          |
|---------|------------------------------------------------------------------------------------------------------------------------------------------------|
| 7400101 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3.Parameter verification failed. |  
| 7400201 | Camera service fatal error.                                                                                                                    |

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

## on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo\>): void

Subscribes to camera status events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'cameraStatus'**. The event can be listened for when a CameraManager instance is obtained. This event is triggered and the corresponding information is returned only when the camera device is enabled or disabled.|
| callback | AsyncCallback\<[CameraStatusInfo](arkts-apis-camera-i.md#camerastatusinfo)\> | Yes  | Callback used to return the camera status change.|

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

## off('cameraStatus')

off(type: 'cameraStatus', callback?: AsyncCallback\<CameraStatusInfo\>): void

Unsubscribes from camera status events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'cameraStatus'**. The event can be listened for when a CameraManager instance is obtained.|
| callback | AsyncCallback\<[CameraStatusInfo](arkts-apis-camera-i.md#camerastatusinfo)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.off('cameraStatus');
}
```

## on('foldStatusChange')<sup>12+</sup>

on(type: 'foldStatusChange', callback: AsyncCallback\<FoldStatusInfo\>): void

Subscribes to fold status change events of the foldable device. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'foldStatusChange'**. The event is triggered when the fold state of the foldable device changes.|
| callback | AsyncCallback\<[FoldStatusInfo](arkts-apis-camera-i.md#foldstatusinfo12)\> | Yes  | Callback used to return the fold state information about the foldable device.|

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

## off('foldStatusChange')<sup>12+</sup>

off(type: 'foldStatusChange', callback?: AsyncCallback\<FoldStatusInfo\>): void

Unsubscribes from fold state change events of the foldable device.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'foldStatusChange'**. The event is triggered when the fold state of the foldable device changes.|
| callback | AsyncCallback\<[FoldStatusInfo](arkts-apis-camera-i.md#foldstatusinfo12)\> | No  | Callback used to return the fold state information about the foldable device. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFoldStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.off('foldStatusChange');
}
```

## isTorchSupported<sup>11+</sup>

isTorchSupported(): boolean

Checks whether the camera device supports the flashlight.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for the support of the flashlight. **true** if supported, **false** otherwise.|

**Example**

```ts
function isTorchSupported(cameraManager: camera.CameraManager): boolean {
  let isSupported = cameraManager.isTorchSupported();
  return isSupported;
}
```

## isTorchModeSupported<sup>11+</sup>

isTorchModeSupported(mode: TorchMode): boolean

Checks whether a flashlight mode is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| mode | [TorchMode](arkts-apis-camera-e.md#torchmode11) | Yes| Flashlight mode. If the input parameter is null or undefined, it is treated as 0 and the flashlight is turned off.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for the support of the flashlight mode. **true** if supported, **false** otherwise.|

**Example**

```ts
function isTorchModeSupported(cameraManager: camera.CameraManager, torchMode: camera.TorchMode): boolean {
  let isSupported = cameraManager.isTorchModeSupported(torchMode);
  return isSupported;
}
```

## getTorchMode<sup>11+</sup>

getTorchMode(): TorchMode

Obtains the flashlight mode of this camera device.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [TorchMode](arkts-apis-camera-e.md#torchmode11)    | Flashlight mode.|

**Example**

```ts
function getTorchMode(cameraManager: camera.CameraManager): camera.TorchMode | undefined {
  let torchMode: camera.TorchMode | undefined = undefined;
  torchMode = cameraManager.getTorchMode();
  return torchMode;
}
```

## setTorchMode<sup>11+</sup>

setTorchMode(mode: TorchMode): void

Sets the flashlight mode.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| mode | [TorchMode](arkts-apis-camera-e.md#torchmode11) | Yes| Flashlight mode. If the input parameter is null or undefined, it is treated as 0 and the flashlight is turned off.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
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

## on('torchStatusChange')<sup>11+</sup>

on(type: 'torchStatusChange', callback: AsyncCallback\<TorchStatusInfo\>): void

Subscribes to flashlight status change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'torchStatusChange'**. The event can be listened for when a CameraManager instance is obtained. Currently, this event is triggered only in the following scenarios: The flashlight is turned on or turned off, or becomes unavailable or available.|
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

## off('torchStatusChange')<sup>11+</sup>

off(type: 'torchStatusChange', callback?: AsyncCallback\<TorchStatusInfo\>): void

Unsubscribes from flashlight status change events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'torchStatusChange'**. The event can be listened for when a CameraManager instance is obtained.|
| callback | AsyncCallback\<TorchStatusInfo> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterTorchStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.off('torchStatusChange');
}
```

## getCameraDevice<sup>18+</sup>

getCameraDevice(position:CameraPosition, type: CameraType): CameraDevice

Obtains the specified camera based on the camera position and type.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| position | [CameraPosition](arkts-apis-camera-e.md#cameraposition)   | Yes  | Camera position.|
| type     | [CameraType](arkts-apis-camera-e.md#cameratype)   | Yes  | Camera type.|

**Return value**

| Type            | Description                    |
| -----------------| ------------------------ |
|  [CameraDevice](arkts-apis-camera-i.md#cameradevice)     | Camera obtained.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';

function getCameraDevice(cameraManager: camera.CameraManager, position: camera.CameraPosition, type: camera.CameraType): void {
  try {
    let curCameraDev: camera.CameraDevice | undefined = undefined;
    curCameraDev = cameraManager.getCameraDevice(position, type);
  } catch (error) {
    // If the operation fails, an error code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getCameraDevice call failed. error code: ${err.code}`);
  }
}
```

## getCameraConcurrentInfos<sup>18+</sup>

getCameraConcurrentInfos(cameras: Array\<CameraDevice\>): Array\<CameraConcurrentInfo\>

Obtains the concurrency information of the specified cameras. If the return value is an empty array, concurrency is not supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| cameras | Array\<[CameraDevice](arkts-apis-camera-i.md#cameradevice)\>  | Yes  | Array of CameraDevice objects. You are advised to use the front and rear cameras obtained by calling [getCameraDevice](#getcameradevice18).|

**Return value**

| Type            | Description                    |
| -----------------| ------------------------ |
|  Array\<[CameraConcurrentInfo](arkts-apis-camera-i.md#cameraconcurrentinfo18)\>    |  Array of concurrency information corresponding to the provided CameraDevice objects, with a one-to-one mapping.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';

function getCameraConcurrentInfos(cameraManager: camera.CameraManager, cameraDeviceArray: Array<camera.CameraDevice>): void {
  try {
    let cameraConcurrentInfos: Array<camera.CameraConcurrentInfo> = [];
    cameraConcurrentInfos = cameraManager.getCameraConcurrentInfos(cameraDeviceArray);
  } catch (error) {
    // If the operation fails, an error code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getCameraConcurrentInfos call failed. error code: ${err.code}`);
  }
}
```

## getSupportedOutputCapability<sup>(deprecated)</sup>

getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability

Obtains the output capability supported by a camera device. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getSupportedOutputCapability](#getsupportedoutputcapability11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| camera | [CameraDevice](arkts-apis-camera-i.md#cameradevice)                              | Yes| CameraDevice instance, which is obtained through [getSupportedCameras](#getsupportedcameras). An error code is returned if the input parameter is invalid.     |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](arkts-apis-camera-i.md#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```ts
function getSupportedOutputCapability(camera: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(camera);
  return cameraOutputCapability;
}
```

## createPhotoOutput<sup>(deprecated)</sup>

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

Creates a PhotoOutput instance. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [createPhotoOutput](#createphotooutput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](arkts-apis-camera-i.md#profile)                         | Yes  | Supported photo profile, which is obtained through [getSupportedOutputCapability](#getsupportedoutputcapability11).|
| surfaceId| string            | Yes  | Surface ID, which is obtained from [ImageReceiver](../apis-image-kit/arkts-apis-image-ImageReceiver.md).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](arkts-apis-camera-PhotoOutput.md)   | PhotoOutput instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## createCaptureSession<sup>(deprecated)</sup>

createCaptureSession(): CaptureSession

Creates a CaptureSession instance. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [createSession](#createsession11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CaptureSession](arkts-apis-camera-CaptureSession.md)   | CaptureSession instance created. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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
