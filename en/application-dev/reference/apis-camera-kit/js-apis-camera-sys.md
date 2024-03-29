# @ohos.multimedia.camera (Camera Management) (System API)

The camera module provides a set of camera service APIs for you to easily develop a camera application. The application can access and operate the camera hardware to implement basic operations, such as preview, taking photos, and recording videos. It can also perform more operations, for example, controlling the flash and exposure time, and focusing or adjusting the focus.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.camera (Camera Management)](js-apis-camera.md).

## Modules to Import

```ts
import camera from '@ohos.multimedia.camera';
```

## CameraDevice

Defines the camera device information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type                              | Read-only| Mandatory| Description       |
| -------------- | --------------------------------- | ---- | ---- |---------- |
| hostDeviceName | string                            | Yes  | Yes  | Name of the remote device. **System API**: This is a system API.|
| hostDeviceType | [HostDeviceType](#hostdevicetype) | Yes  | Yes  | Type of the remote device. **System API**: This is a system API.|

## HostDeviceType

Enumerates the remote camera types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value      | Description          |
| ---------------------------- | ----     | ------------- |
| UNKNOWN_TYPE                 | 0        | Unknown type.     |
| PHONE                        | 0x0E     | Phone camera.|
| TABLET                       | 0x11     | Tablet camera.|

## SceneMode<sup>11+</sup>

Enumerates the camera scene modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| PORTRAIT_PHOTO       | 3      | Portrait photo mode. **System API**: This is a system API.           |
| NIGHT_PHOTO        | 4      | Night photo mode. **System API**: This is a system API.            |

## CameraManager

Implements camera management. Before calling any API in **CameraManager**, you must use [getCameraManager](js-apis-camera.md#cameragetcameramanager) to obtain a **CameraManager** instance.

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

function callback(err: BusinessError, curMuted: boolean): void {
  let isMuted: boolean = curMuted;
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
| callback | AsyncCallback\<boolean> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('cameraMute') with the specified callback is canceled. (The callback object cannot be an anonymous function.)                 |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, curMuted: boolean): void {
  let isMuted: boolean = curMuted;
}

function unregisterCameraMute(cameraManager: camera.CameraManager): void {
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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed. |

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
| profile | [Profile](js-apis-camera.md#profile) | Yes| Configuration file of the camera preview stream.|

**Return value**

| Type| Description|
| -------- | --------------- |
| [PreviewOutput](#previewoutput) | **PreviewOutput** instance obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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
| cameraId | string | Yes| Camera ID.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

## PrelaunchConfig

Defines the camera prelaunch configuration.

Currently, the configuration is used for sensor-level prelaunch. It will be used for stream-level prelaunch in a later version.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

|            Name                |                     Type                 |     Read-only   |     Mandatory    | Description      |
| ------------------------------- | ---------------------------------------- | ----------- | ------------ | ---------- |
| cameraDevice                    | [CameraDevice](#cameradevice)            |      No    |       Yes     | Camera device.        |
| restoreParamType<sup>11+</sup>  | [RestoreParamType](#restoreparamtype11)  |      No    |       No     | Type of the parameter used for prelaunch.   |
| activeTime<sup>11+</sup>        | number                                   |      No    |       No     | Activation time, in minutes.|
| settingParam<sup>11+</sup>      |  [SettingParam](#settingparam11)         |      No    |       No     | Setting parameter.     |

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

| Name            | Type  |   Read-only   |    Mandatory   | Description      |
| --------------- | ------ | --------- | ---------- | ---------- |
| skinSmoothLevel | number |  No      |  N/A       | Skin smoothing level, which is obtained through [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11). For example, the value **1** indicates level-1 smoothing.|
| faceSlender     | number |  No      |  N/A       | Face slimming level, which is obtained through [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11). For example, the value **1** indicates level-1 slimming.|
| skinTone        | number |  No      |  N/A       | Skin tone perfection level, which is obtained through [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11). For example, the value **0xBF986C** indicates a specific color.|

## PreviewOutput

Implements preview output. It inherits from [CameraOutput](js-apis-camera.md#cameraoutput).

### addDeferredSurface

addDeferredSurface(surfaceId: string): void

Adds a surface for delayed preview. This API can run after [Session.commitConfig](js-apis-camera.md#commitconfig11-1) or [Session.start](js-apis-camera.md#start11-1) is called.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| surfaceId | string | Yes| Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |

**Example**

```ts
import common from '@ohos.app.ability.common';

async function preview(context: common.BaseContext, cameraDevice: camera.CameraDevice, previewProfile: camera.Profile, photoProfile: camera.Profile, mode: camera.SceneMode, previewSurfaceId: string): Promise<void> {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameraDevice);
  const previewOutput: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);
  const photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  const session: camera.Session  = cameraManager.createSession(mode);
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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function enableSketch(previewOutput: camera.PreviewOutput, session: camera.Session, cameraInput: camera.CameraInput): void {
  try {
    session.beginConfig();
    session.addInput(cameraInput);
    session.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    session.commitConfig();
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
| surfaceId | string | Yes| Surface ID, which is obtained from [XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function attachSketchSurface(previewOutput: camera.PreviewOutput, session: camera.Session, cameraInput: camera.CameraInput, sketchSurfaceId: string): void {
  try {
    session.beginConfig();
    session.addInput(cameraInput);
    session.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    session.commitConfig();
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
| callback | AsyncCallback\<[SketchStatusData](#sketchstatusdata11)\> | Yes  | Callback used to return the PiP status data.           |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: camera.SketchStatusData): void {
  console.info(`sketch errorCode is ${error.code}, data is ${JSON.stringify(data)}`);
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
| callback | AsyncCallback\<[SketchStatusData](#sketchstatusdata11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('sketchStatusChanged') with the specified callback is canceled. (The callback object cannot be an anonymous function.)          |

**Example**

```ts
function unregisterSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('sketchStatusChanged');
}
```

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

### getThumbnail<sup>11+</sup>

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

### release<sup>11+</sup>

release(): Promise\<void\>

Releases output resources. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Example**

```ts
async function releaseDeferredPhotoProxy(proxyObj: camera.DeferredPhotoProxy): Promise<void> {
  await proxyObj.release();
}
```

## PhotoOutput

Implements output information used in a photo session. It inherits from [CameraOutput](js-apis-camera.md#cameraoutput).

### confirmCapture<sup>11+</sup>

confirmCapture()

Confirms photo capture. This API is generally used in night photo mode when users need to stop the exposure countdown and take a photo in advance.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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
  res = photoOutput.isDeferredImageDeliverySupported(type);
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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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
  res = photoOutput.isDeferredImageDeliveryEnabled(type);
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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**Example**

```ts
function deferImageDelivery(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): void {
  photoOutput.deferImageDelivery(type);
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
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('deferredPhotoProxyAvailable') with the specified callback is canceled. (The callback object cannot be an anonymous function.)           |

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

### isQuickThumbnailSupported

isQuickThumbnailSupported(): boolean

Checks whether the quick thumbnail feature is supported.

This API must be called after [addOutput](js-apis-camera.md#addoutput11) or [addInput](js-apis-camera.md#addinput11) and before [commitConfig](js-apis-camera.md#commitconfig11-1).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type| Description|
| --------- | ------ |
| boolean | **true**: The quick thumbnail feature is supported.<br>**false**: The quick thumbnail feature is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  session is not running.        |

**Example**

```ts
import common from '@ohos.app.ability.common';

async function isQuickThumbnailSupported(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<boolean> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // Create a CaptureSession instance.
  let session: camera.Session = cameraManager.createSession(mode);
  // Start configuration for the session.
  session.beginConfig();
  // Add a CameraInput instance to the session.
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // Add a PhotoOutput instance to the session.
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  session.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  return isSupported;
}
```

### enableQuickThumbnail

enableQuickThumbnail(enabled: boolean): void

Enables or disables the quick thumbnail feature.

This API must be called after [addOutput](js-apis-camera.md#addoutput11) or [addInput](js-apis-camera.md#addinput11) and before [commitConfig](js-apis-camera.md#commitconfig11-1).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| enabled    | boolean       | Yes  | Whether to enable the quick thumbnail feature. The value **true** means to enable the quick thumbnail feature, and **false** means to disable it.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  session is not running.        |

**Example**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

async function enableQuickThumbnail(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // Create a CaptureSession instance.
  let session: camera.Session = cameraManager.createSession(mode);
  // Start configuration for the session.
  session.beginConfig();
  // Add a CameraInput instance to the session.
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // Add a PhotoOutput instance to the session.
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  session.addOutput(photoOutput);
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
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | Yes| Callback that returns a **PixelMap** instance.|

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

async function registerQuickThumbnail(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // Create a CaptureSession instance.
  let session: camera.Session = cameraManager.createSession(mode);
  // Start configuration for the session.
  session.beginConfig();
  // Add a CameraInput instance to the session.
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // Add a PhotoOutput instance to the session.
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  session.addOutput(photoOutput);
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
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | No| Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('quickThumbnail') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterQuickThumbnail(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('quickThumbnail');
}
```

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

## ManualExposure<sup>11+</sup>

Provides APIs related to manual exposure.

### getSupportedExposureRange<sup>11+</sup>

getSupportedExposureRange(): Array\<number\>

Obtains the supported manual exposure durations.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type               | Description                                                 |
| ----------          | -----------------------------                         |
|  Array\<number\>| Array of manual exposure durations supported, in ms.                            |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

### getExposure<sup>11+</sup>

getExposure(): number

Obtains the manual exposure duration in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**
| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| value     | number | Yes  | Manual exposure duration, in ms. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getExposure(nightPhotoSession: camera.NightPhotoSession): number | undefined {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return undefined;
  }
  let exposure: number = nightPhotoSession.getExposure();
  return exposure;
}
```

### setExposure<sup>11+</sup>

setExposure(exposure: number): void

Sets the manual exposure duration, in ms.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                  |
| -------- | --------------------------| ---- | --------------------- |
| value    | number                    | Yes  | Manual exposure duration, which must be one of the supported durations obtained by running [getSupportedExposureRange](#getsupportedexposurerange11).|

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

## Macro<sup>11+</sup>

Provides APIs related to macro photography.

### isMacroSupported<sup>11+</sup>

isMacroSupported(): boolean

Checks whether macro photography is supported in the current state. This API must be called after **commitConfig**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
|   boolean  | **true**: Macro photography is supported.<br>**false**: Macro photography is not supported.|

**Example**

```ts
function isMacroSupported(photoSession: camera.PhotoSessionForSys): boolean {
  let isSupported: boolean = photoSession.isMacroSupported();
  return isSupported;
}
```

### enableMacro<sup>11+</sup>

enableMacro(enabled: boolean): void

Enables or disables macro photography. This API can be called only when macro photography is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | Yes  | Whether to enable macro photography. The value **true** means to enable macro photography, and **false** means to disable it.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202             |  Not System Application.                  |
| 7400103         |  Session not config.                      |

**Example**

```ts
function enableMacro(photoSession: camera.PhotoSessionForSys): void {
  let isSupported: boolean = photoSession.isMacroSupported();
  if (isSupported) {
    photoSession.enableMacro(true);
  }
}
```

## Zoom<sup>11+</sup>

Provides APIs related to zoom operations.

### prepareZoom<sup>11+</sup>

prepareZoom(): void

Instructs the bottom layer to prepare for zooming, for example, powering on the sensor.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                    |  Not System Application.                      |
| 7400103                |  Session not config.                          |

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

### unprepareZoom<sup>11+</sup>

unprepareZoom(): void

Instructs the bottom layer to unprepare for zooming.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                    |  Not System Application.                      |
| 7400103                |  Session not config.                          |

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

| Name    | Type          | Read-only| Mandatory| Description        |
| -------- | ------------- |---- | ---- | -------------|
| min      | number        | Yes |  N/A  | Minimum value of the zoom ratio range. |
| max      | number        | Yes |  N/A  | Maximum value of the zoom ratio range.|

## Beauty<sup>11+</sup>

Provides APIs related to beauty settings.

### getSupportedBeautyTypes<sup>11+</sup>

getSupportedBeautyTypes(): Array\<BeautyType\>

Obtains the supported beauty types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type               | Description                                                 |
| ----------          | -----------------------------                         |
|  Array\<[BeautyType](#beautytype)\>| Array of beauty types supported.                            |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedBeautyTypes(portraitPhotoSession: camera.PortraitPhotoSession): Array<camera.BeautyType> {
  let beautyTypes: Array<camera.BeautyType> = portraitPhotoSession.getSupportedBeautyTypes();
  return beautyTypes;
}
```

### getSupportedBeautyRange<sup>11+</sup>

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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedBeautyRange(portraitPhotoSession: camera.PortraitPhotoSession): Array<number> {
  let beautyTypes: Array<camera.BeautyType> = portraitPhotoSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return [];
  }
  let beautyLevels: Array<number> = portraitPhotoSession.getSupportedBeautyRange(beautyTypes[0]);
  return beautyLevels;
}
```

### setBeauty<sup>11+</sup>

setBeauty(type: BeautyType, value: number): void

Sets a beauty type and its level. Beauty mode is turned off only when all the [beauty types](#beautytype) obtained through [getSupportedBeautyTypes](#getsupportedbeautytypes11) are disabled.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                  |
| -------- | --------------------------| ---- | --------------------- |
| type     | [BeautyType](#beautytype) | Yes  | Beauty type.             |
| value    | number                    | Yes  | Beauty level, which is obtained through [getSupportedBeautyRange](#getsupportedbeautyrange11).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function setBeauty(portraitPhotoSession: camera.PortraitPhotoSession): void {
  let beautyTypes: Array<camera.BeautyType> = portraitPhotoSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return;
  }
  let beautyLevels: Array<number> = portraitPhotoSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return;
  }
  portraitPhotoSession.setBeauty(beautyTypes[0], beautyLevels[0]);
}
```

### getBeauty<sup>11+</sup>

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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getBeauty(portraitPhotoSession: camera.PortraitPhotoSession): number {
  const invalidValue: number = -1;
  let beautyTypes = portraitPhotoSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return invalidValue;
  }
  let beautyLevels: Array<number> = portraitPhotoSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return invalidValue;
  }
  portraitPhotoSession.setBeauty(beautyTypes[0], beautyLevels[0]);
  let beautyLevel: number = portraitPhotoSession.getBeauty(beautyTypes[0]);
  return beautyLevel;
}
```

## ColorEffect<sup>11+</sup>

Provides the APIs for color effect settings.

### getSupportedColorEffects<sup>11+</sup>

getSupportedColorEffects(): Array\<ColorEffectType\>

Obtains the supported color effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[ColorEffectType](#coloreffecttype11)>       | Array of color effects supported.          |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**Example**

```ts
function getSupportedColorEffects(session: camera.PhotoSessionForSys): Array<camera.ColorEffectType> {
  let colorEffects: Array<camera.ColorEffectType> = session.getSupportedColorEffects();
  return colorEffects;
}
```

### setColorEffect<sup>11+</sup>

setColorEffect(type: ColorEffectType): void

Sets a color effect. Before the setting, use [getSupportedColorEffects](#getsupportedcoloreffects11) to obtain the supported color effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| type | [ColorEffectType](#coloreffecttype11)                              | Yes| Color effect, which can be obtained through [getSupportedColorEffects](#getsupportedcoloreffects11).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
function setColorEffect(session: camera.PhotoSessionForSys, colorEffect: camera.ColorEffectType): void {
  session.setColorEffect(colorEffect);
}
```

### getColorEffect<sup>11+</sup>

getColorEffect(): ColorEffectType

Obtains the color effect in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ColorEffectType](#coloreffecttype11)             | Color effect.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
function getColorEffect(session: camera.PhotoSessionForSys): camera.ColorEffectType {
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

### getSupportedColorSpaces<sup>11+</sup>

getSupportedColorSpaces(): Array\<colorSpaceManager.ColorSpace\>

Obtains the supported color spaces.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)>| Array of color spaces supported.    |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                       |
| 202             |  Not System Application.                   |

**Example**

```ts
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';

function getSupportedColorSpaces(session: camera.PhotoSessionForSys): Array<colorSpaceManager.ColorSpace> {
  let colorSpaces: Array<colorSpaceManager.ColorSpace> = session.getSupportedColorSpaces();
  return colorSpaces;
}
```

### setColorSpace<sup>11+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpace): void

Sets a color space. Before the setting, use [getSupportedColorSpaces](#getsupportedcolorspaces11) to obtain the supported color spaces.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                | Mandatory| Description                     |
| ------------ |---------------------- | -- | -------------------------- |
| colorSpace | [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)  | Yes| Color space, which can be obtained through [getSupportedColorSpaces](#getsupportedcolorspaces11).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202             |  Not System Application.                       |
| 7400102         |  The colorSpace does not match the format.     |
| 7400103         |  Session not config.                           |

**Example**

```ts
import { BusinessError } from '@ohos.base';
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';

function setColorSpace(session: camera.PhotoSessionForSys, colorSpaces: Array<colorSpaceManager.ColorSpace>): void {
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

### getActiveColorSpace<sup>11+</sup>

getActiveColorSpace(): colorSpaceManager.ColorSpace

Obtains the color space in use.

**System API**: This is a system API.

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
| 202             |  Not System Application.                         |

**Example**

```ts
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';

function getActiveColorSpace(session: camera.PhotoSessionForSys): colorSpaceManager.ColorSpace {
  let colorSpace: colorSpaceManager.ColorSpace = session.getActiveColorSpace();
  return colorSpace;
}
```

## Portrait<sup>11+</sup>

Provides the APIs for portrait photo settings.

### getSupportedPortraitEffects<sup>10+</sup>

getSupportedPortraitEffects(): Array\<PortraitEffect\>

Obtains the supported portrait effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[PortraitEffect](#portraiteffect)> | Array of portrait effects supported.              |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                |
| 202             |  Not System Application.            |

**Example**

```ts
function getSupportedPortraitEffects(portraitPhotoSession: camera.PortraitPhotoSession): Array<camera.PortraitEffect> {
  let portraitEffects: Array<camera.PortraitEffect> = portraitPhotoSession.getSupportedPortraitEffects();
  return portraitEffects;
}
```

### setPortraitEffect<sup>10+</sup>

setPortraitEffect(effect: PortraitEffect): void

Sets a portrait effect. Before the setting, use [getSupportedPortraitEffects](#getsupportedportraiteffects10) to obtain the supported portrait effects and check whether the target portrait effect is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                       | Mandatory| Description                     |
| ------------ |----------------------------- | -- | -------------------------- |
| effect | [PortraitEffect](#portraiteffect)  | Yes| Portrait effect, which can be obtained through [getSupportedPortraitEffects](#getsupportedportraiteffects10).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                                   |
| 202             |  Not System Application.                         |

**Example**

```ts
import { BusinessError } from '@ohos.base';

function setPortraitEffect(portraitPhotoSession: camera.PortraitPhotoSession, portraitEffects: Array<camera.PortraitEffect>): void {
  if (portraitEffects === undefined || portraitEffects.length <= 0) {
    return;
  }
  try {
    portraitPhotoSession.setPortraitEffect(portraitEffects[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setPortraitEffect call failed. error code: ${err.code}`);
  }
}
```

### getPortraitEffect<sup>10+</sup>

getPortraitEffect(): PortraitEffect

Obtains the portrait effect in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [PortraitEffect](#portraiteffect)               | Portrait effect.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                |
| 202             |  Not System Application.            |

**Example**

```ts
function getPortraitEffect(portraitPhotoSession: camera.PortraitPhotoSession): camera.PortraitEffect {
  let portraitEffect: camera.PortraitEffect = portraitPhotoSession.getPortraitEffect();
  return portraitEffect;
}
```

## PhysicalAperture<sup>11+</sup>

Defines the physical aperture information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type                      |  Read-only|  Mandatory| Description              |
| ---------- | ------------------------- | ----- | ----- | ----------------- |
| zoomRange  | [ZoomRange](#zoomrange11) | No   | N/A   | Zoom range of a given physical aperture. |
| apertures  | Array\<number\>           | No   | N/A   | Array of physical apertures supported.     |

## Aperture<sup>11+</sup>

Provides the APIs for aperture settings.

### getSupportedVirtualApertures<sup>11+</sup>

getSupportedVirtualApertures(): Array\<number\>

Obtains the supported virtual apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array\<number\> | Array of virtual apertures supported.              |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

### getVirtualAperture<sup>11+</sup>

getVirtualAperture(): number

Obtains the virtual aperture in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| number               | Virtual aperture.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

### setVirtualAperture<sup>11+</sup>

setVirtualAperture(aperture: number): void

Sets a virtual aperture. Before the setting, use [getSupportedVirtualApertures](#getsupportedvirtualapertures11) to obtain the supported virtual apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                   | Mandatory| Description                     |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | Yes| Virtual aperture, which can be obtained by calling [getSupportedVirtualApertures](#getsupportedvirtualapertures11).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**Example**

```ts
function setVirtualAperture(session: camera.PortraitPhotoSession, virtualAperture: number): void {
  session.setVirtualAperture(virtualAperture);
}
```

### getSupportedPhysicalApertures<sup>11+</sup>

getSupportedPhysicalApertures(): Array\<PhysicalAperture\>

Obtains the supported physical apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[PhysicalAperture](#physicalaperture11)>    | Array of physical apertures supported.              |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

### getPhysicalAperture<sup>11+</sup>

getPhysicalAperture(): number

Obtains the physical aperture in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                | Description                          |
| -------------------- | ---------------------------- |
| number               | Physical aperture.          |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

### setPhysicalAperture<sup>11+</sup>

setPhysicalAperture(aperture: number): void

Sets a physical aperture. Before the setting, use [getSupportedPhysicalApertures](#getsupportedphysicalapertures11) to obtain the supported physical apertures.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                   | Mandatory| Description                     |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | Yes| Physical aperture, which can be obtained by calling [getSupportedPhysicalApertures](#getsupportedphysicalapertures11).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

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

Implements a capture session, which saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera and requests the camera to complete shooting or video recording.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [PhotoSession](#photosession11) and [VideoSession](#videosession11) instead.

### getSupportedBeautyTypes<sup>(deprecated)</sup>

getSupportedBeautyTypes(): Array\<BeautyType>

Obtains the supported beauty types.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Beauty.getSupportedBeautyTypes](#getsupportedbeautytypes11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type               | Description                                                 |
| ----------          | -----------------------------                         |
|  Array\<[BeautyType](#beautytype)\>| Array of beauty types supported.                            |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedBeautyTypes(captureSession: camera.CaptureSession): Array<camera.BeautyType> {
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  return beautyTypes;
}
```

### getSupportedBeautyRange<sup>(deprecated)</sup>

getSupportedBeautyRange(type: BeautyType): Array\<number\>

Obtains the levels that can be set a beauty type. The beauty levels vary according to the device type. The following table is only an example.

| Input Parameter          | Example Return Value   | Return Value Description    |
| ----------------| ----  | ---------|
| AUTO           | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     |Beauty levels supported when **type** is set to **AUTO**. The value **0** means that beauty mode is disabled, and other positive values mean the corresponding automatic beauty levels.   |
| SKIN_SMOOTH    | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     | Beauty levels supported when **type** is set to **SKIN_SMOOTH**. The value **0** means that the skin smoothing feature is disabled, and other positive values mean the corresponding skin smoothing levels.   |
| FACE_SLENDER   | [0, 1, 2, 3, 4, 5]      | Beauty levels supported when **type** is set to **FACE_SLENDER**. The value **0** means that the face slimming feature is disabled, and other positive values mean the corresponding face slimming levels.  |
| SKIN_TONE      | [-1, 16242611]      | Beauty levels supported when **type** is set to **SKIN_TONE**. The value **-1** means that the skin tone perfection feature is disabled. Other non-negative values mean the skin tone perfection levels represented by RGB,<br> for example, 16242611, which is 0xF7D7B3 in hexadecimal format, where F7, D7, and B3 represent the values of the R channel, G channel, and B channel, respectively.   |

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11) instead.

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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedBeautyRange(captureSession: camera.CaptureSession): Array<number> {
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return [];
  }
  let beautyLevels: Array<number> = captureSession.getSupportedBeautyRange(beautyTypes[0]);
  return beautyLevels;
}
```

### setBeauty<sup>(deprecated)</sup>

setBeauty(type: BeautyType, value: number): void

Sets a beauty type and its level. Beauty mode is turned off only when all the [beauty types](#beautytype) obtained through [getSupportedBeautyTypes](#getsupportedbeautytypesdeprecated) are disabled.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Beauty.setBeauty](#setbeauty11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                  |
| -------- | --------------------------| ---- | --------------------- |
| type     | [BeautyType](#beautytype) | Yes  | Beauty type.             |
| value    | number                    | Yes  | Beauty level, which is obtained through [getSupportedBeautyRange](#getsupportedbeautyrangedeprecated).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function setBeauty(captureSession: camera.CaptureSession): void {
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return;
  }
  let beautyLevels: Array<number> = captureSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return;
  }
  captureSession.setBeauty(beautyTypes[0], beautyLevels[0]);
}
```

### getBeauty<sup>(deprecated)</sup>

getBeauty(type: BeautyType): number

Obtains the level of the beauty type in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Beauty.getBeauty](#getbeauty11) instead.

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

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getBeauty(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return invalidValue;
  }
  let beautyLevels: Array<number> = captureSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return invalidValue;
  }
  captureSession.setBeauty(beautyTypes[0], beautyLevels[0]);
  let beautyLevel: number = captureSession.getBeauty(beautyTypes[0]);
  return beautyLevel;
}
```

## PhotoSessionForSys<sup>11+</sup>

PhotoSessionForSys extends PhotoSession, Beauty, ColorEffect, ColorManagement, Macro

Implements a photo session for system applications, which sets the parameters of the normal photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

## PhotoSession<sup>11+</sup>

PhotoSession extends Session, Flash, AutoExposure, Focus, Zoom

Implements a photo session, which sets the parameters of the normal photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('macroStatusChanged')<sup>11+</sup>

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

### off('macroStatusChanged')<sup>11+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from macro state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('macroStatusChanged') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```

## VideoSessionForSys<sup>11+</sup>

VideoSessionForSys extends VideoSession, Beauty, ColorEffect, ColorManagement, Macro

Implements a video session for system applications, which sets the parameters of the normal video mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

## VideoSession<sup>11+</sup>

VideoSession extends Session, Flash, AutoExposure, Focus, Zoom, Stabilization

Implements a video session, which sets the parameters of the normal video mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('macroStatusChanged')<sup>11+</sup>

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

### off('macroStatusChanged')<sup>11+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from macro state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | Yes  | Event type. The value is fixed at **'macroStatusChanged'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('macroStatusChanged') with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.off('macroStatusChanged');
}
```

## PortraitPhotoSession<sup>11+</sup>

PortraitPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Portrait, Aperture

Implements a portrait photo session, which sets the parameters of the portrait photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PortraitSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).       |

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

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PortraitSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | -------------------------- | ---- | ------------------------------ |
| type     | string                     | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)   |

**Example**

```ts
function unregisterSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

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

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('focusStateChange') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('smoothZoomInfoAvailable') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterSmoothZoomInfo(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('smoothZoomInfoAvailable');
}
```

## NightPhotoSession<sup>11+</sup>

NightPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ColorManagement, ManualExposure

Implements a night photo session, which sets the parameters of the night photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **NightSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).|

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

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **NightSession** error events. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('error') with the specified callback is canceled. (The callback object cannot be an anonymous function.)      |

**Example**

```ts
function unregisterSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

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

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('focusStateChange') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event on('smoothZoomInfoAvailable') with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

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

| Name         | Type     | Read-only| Mandatory| Description       |
| ------------- | -------- | ---- | ---- | ---------- |
| status        | number   | No  | Yes  | Status of PiP. The options are 0 (stopped), 1 (started), 2 (stopping), and 3 (starting).|
| sketchRatio   | number   | No  | Yes  | Zoom ratio of PiP.|
