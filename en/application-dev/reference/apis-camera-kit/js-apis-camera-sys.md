# @ohos.multimedia.camera (Camera Management) (System API)

The camera module provides a set of camera service APIs for you to easily develop a camera application. The application can access and operate the camera hardware to implement basic operations, such as preview, taking photos, and recording videos. It can also perform more operations, for example, controlling the flash and exposure time, and focusing or adjusting the focus.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.camera (Camera Management)](js-apis-camera.md).

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
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
| PROFESSIONAL_PHOTO<sup>12+</sup>        | 5      | Professional photo mode. **System API**: This is a system API.            |
| PROFESSIONAL_VIDEO<sup>12+</sup>        | 6      | Professional video mode. **System API**: This is a system API.            |
| SLOW_MOTION_VIDEO<sup>12+</sup>        | 7   | Slow-motion video mode. **System API**: This is a system API. |
| HIGH_RESOLUTION_PHOTO<sup>12+</sup>        | 11     | High-resolution photo mode. **System API**: This is a system API.         |
| PANORAMA_PHOTO<sup>12+</sup>        | 15     | Panoramic photo mode. **System API**: This is a system API.         |
| TIME_LAPSE_PHOTO<sup>12+</sup>        | 16     | Time-lapse photo mode. **System API**: This is a system API.         |

## SlowMotionStatus<sup>12+</sup>

Enumerates the slow-motion states.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value  | Description           |
|----------------|-----|---------------|
| DISABLED       | 0   | Disabled.     |
| READY          | 1   | Ready.     |
| VIDEO_START    | 2   | Video start.   |
| VIDEO_DONE     | 3   | Video complete.   |
| FINISHED       | 4   | Finished.     |

## LcdFlashStatus<sup>12+</sup>

Describes the LCD flash information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional | Description        |
| -------- | ----------------------------- |---- |-----| ------------- |
| isLcdFlashNeeded   | boolean | Yes | No  | Whether the LCD flash is required.     |
| lcdCompensation     | number                 | Yes | No  | LCD flash compensation.      |

## Photo<sup>11+</sup>

Defines a higher-resolution image object.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           | Read-only | Optional      | Description|
| ------ | ----------------------------- |-----| ---------- | ---------- |
| raw<sup>12+</sup> | [image.Image](../apis-image-kit/js-apis-image.md#image9)| NA  | Yes  | Raw image.|

## ExposureMode

Enumerates the exposure modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description     |
| ----------------------------- |-----|---------|
| EXPOSURE_MODE_MANUAL<sup>12+</sup>          | 3   | Manual exposure mode.|

## PolicyType<sup>12+</sup>

Enumerates the policy types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description     |
| ----------------------------- |-----|---------|
| PRIVACY<sup>12+</sup>          | 1   | Privacy.|

## CameraManager

Implements camera management. Before calling any API in **CameraManager**, you must use [getCameraManager](js-apis-camera.md#cameragetcameramanager) to obtain a **CameraManager** instance.

### createDepthDataOutput<sup>12+</sup>

createDepthDataOutput(profile: Profile): DepthDataOutput

Creates a **DepthDataOutput** instance. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                             |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](js-apis-camera.md#profile)                             | Yes  | Supported preview profile, which is obtained through [getSupportedOutputCapability](js-apis-camera.md#getsupportedoutputcapability11).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [DepthDataOutput](#depthdataoutput12)    | **DepthDataOutput** instance. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400201                |  Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createDepthDataOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager): camera.DepthDataOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.depthProfiles[0];
  let depthDataOutput: camera.DepthDataOutput | undefined = undefined;
  try {
    depthDataOutput = cameraManager.createDepthDataOutput(profile);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The createDepthDataOutput call failed. error code: ${err.code}`);
  }
  return depthDataOutput;
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

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [muteCameraPersistent](#mutecamerapersistent12) instead.

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

### muteCameraPersistent<sup>12+</sup>

muteCameraPersistent(mute: boolean, type: PolicyType): void

Disables the camera in a persistent manner.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                         | Mandatory | Description                                        |
| -------- |-----------------------------| ---- |--------------------------------------------|
| mute     | boolean                     |  Yes | Whether to mute the camera device. The value **true** means to mute the camera device, and **false** means the opposite.                  |
| type     | [PolicyType](#policytype12) |  Yes | Policy type. For details about the available options, see [PolicyType](#policytype12).|

**Example**

```ts
function muteCameraPersistent(cameraManager: camera.CameraManager): void {
  let mute: boolean = true;
  cameraManager.muteCameraPersistent(mute, camera.PolicyType.PRIVACY);
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
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, curMuted: boolean): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  let isMuted: boolean = curMuted;
  console.info(`cameraMute status: ${isMuted}`);
}

function registerCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraMute', callback);
}
```

### off('cameraMute')

off(type: 'cameraMute', callback?: AsyncCallback\<boolean\>): void

Unsubscribes from camera mute status events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description                                                     |
| -------- | --------------- | ---- |---------------------------------------------------------|
| type     | string          | Yes  | Event type. The value is fixed at **'cameraMute'**, indicating the camera mute status. The event can be listened for when a **CameraManager** instance is obtained.|
| callback | AsyncCallback\<boolean> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('cameraMute')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
| 202 | Not System Application. |
| 7400101 | Parameter missing or parameter type incorrect. |

**Example**

```ts
import { common } from '@kit.AbilityKit';

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

Before the setting, call [isPrelaunchSupported](#isprelaunchsupported) to check whether the camera device supports prelaunch.

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
| 202 | Not System Application. |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed. |
| 7400201 | Camera service fatal error. |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
| 202         	  |  Not System Application.       |
| 7400101 	      |  Parameter missing or parameter type incorrect. |

**Example**

```ts
import { common } from '@kit.AbilityKit';

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

| ID  | Error Message                                          |
| ------- |------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400201 | Camera service fatal error.                    |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## CameraOutputCapability<sup>12+</sup>

Describes the camera output capability.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Type                                               | Read-only| Optional| Description               |
| ----------------------------- | --------------------------------------------------- | ---- | ---- |-------------------|
| depthProfiles                 | Array\<[DepthProfile](#depthprofile12)\>              |  Yes | No| Supported depth stream profiles.       |

## CameraFormat

Enumerates the camera output formats.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_DEPTH_16<sup>12+</sup> |   3000   | Depth map in DEPTH_16 format.     |
| CAMERA_FORMAT_DEPTH_32<sup>12+</sup> |   3001   | Depth map in DEPTH_32 format.     |

## DepthDataAccuracy<sup>12+</sup>

Describes the accuracy of depth data.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description           |
| -------- | ----------------------------- |----- |---| -------------- |
| DEPTH_DATA_ACCURACY_RELATIVE      | number                        |  Yes | No| Relative accuracy, which is the depth map calculated based on the disparity.     |
| DEPTH_DATA_ACCURACY_ABSOLUTE      | number                        |  Yes | No| Absolute accuracy, which is the depth map calculated from distance measurement.     |

## DepthProfile<sup>12+</sup>

Describes the profile of depth data. It inherits from [Profile](js-apis-camera.md#profile).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Read-only| Optional| Description       |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| depthDataAccuracy            | [DepthDataAccuracy](#depthdataaccuracy12)         | Yes |  No | Accuracy of the depth data, which can be either relative accuracy or absolute accuracy.|

## DepthDataQualityLevel<sup>12+</sup>

Enumerates the quality levels of depth data.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description           |
| -------- | ----------------------------- |----- |---| -------------- |
| DEPTH_DATA_QUALITY_BAD     | number            |  Yes | No| The depth map is of poor quality and cannot be used for blurring.     |
| DEPTH_DATA_QUALITY_FAIR      | number          |  Yes | No| The depth map is of average quality and cannot be used for high-quality blurring.     |
| DEPTH_DATA_QUALITY_GOOD      | number          |  Yes | No| The depth map is of high quality and can be used for high-quality blurring.     |

## DepthData<sup>12+</sup>

Describes a depth data object.

### Properties

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                         | Read-only| Optional| Description           |
| -------- | ----------------------------- |----- |---| -------------- |
| format | [CameraFormat](#cameraformat)   | Yes|  No | Camera output format.|
| depthMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)    | Yes|  No | Depth map.|
| qualityLevel | [DepthDataQualityLevel](#depthdataqualitylevel12)   | Yes|  No | Quality level of the depth map.|
| accuracy | [DepthDataAccuracy](#depthdataaccuracy12) | Yes|  No | Accuracy of the depth map.|

### release<sup>12+</sup>

release(): void

Releases depth data output resources.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Example**

```ts
function releaseDepthData(depthData: camera.DepthData): void {
  await depthData.release();
}
```

## DepthDataOutput<sup>12+</sup>

Implements depth data output. It inherits from [CameraOutput](js-apis-camera.md#cameraoutput).

### start<sup>12+</sup>

start(): Promise\<void\>

Starts a depth data output stream. This API uses a promise to return the result.

**System API**: This is a system API.

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

function startDepthDataOutput(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.start().then(() => {
    console.info('Promise returned to indicate that start method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to depth data output start, error code: ${error.code}.`);
  });
}
```

### stop<sup>12+</sup>

stop(): Promise\<void\>

Stops a depth data output stream. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopDepthDataOutput(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.stop().then(() => {
    console.info('Promise returned to indicate that stop method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to depth data output stop, error code: ${error.code}.`);
  });
}
```

### on('depthDataAvailable')<sup>12+</sup>

on(type: 'depthDataAvailable', callback: AsyncCallback\<DepthData\>): void

Subscribes to depth data availability events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'depthDataAvailable'**. The event can be listened for when a **depthDataOutput** instance is created.|
| callback | AsyncCallback\<[DepthData](#depthdata12)\> | Yes  | Callback used to listen for depth data.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, depthData: camera.DepthData): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
}

function registerDepthDataAvailable(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.on('depthDataAvailable', callback);
}
```

### off('depthDataAvailable')<sup>12+</sup>

off(type: 'depthDataAvailable', callback?: AsyncCallback\<DepthData\>): void

Unsubscribes from depth data availability events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'depthDataAvailable'**. The event can be listened for when a **depthDataOutput** instance is created.|
| callback | AsyncCallback\<[DepthData](#depthdata12)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, depthData: camera.DepthData): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
}

function unRegisterDepthDataAvailable(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.off('depthDataAvailable', callback);
}
```

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **DepthDataOutput** error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **depthDataOutput** instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(depthDataOutputError: BusinessError): void {
  console.error(`Depth data output error code: ${depthDataOutputError.code}`);
}

function registerDepthDataOutputError(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.on('error', callback)
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **DepthDataOutput** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **depthDataOutput** instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterDepthDataOutputError(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.off('error');
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

| Name            | Type  |   Read-only   | Optional | Description                                                                                               |
| --------------- | ------ | --------- |-----|---------------------------------------------------------------------------------------------------|
| skinSmoothLevel | number |  No      | No  | Skin smoothing level, which is obtained through [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange12). For example, the value **1** indicates level-1 smoothing.       |
| faceSlender     | number |  No      | No  | Face slimming level, which is obtained through [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange12). For example, the value **1** indicates level-1 slimming.       |
| skinTone        | number |  No      | No  | Skin tone perfection level, which is obtained through [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange12). For example, the value **0xBF986C** indicates a specific color.|

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
import { common } from '@kit.AbilityKit';

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

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message                   |
| --------------- |-------------------------|
| 202             | Not System Application. |

**Example**

```ts
function isSketchSupported(previewOutput: camera.PreviewOutput): boolean {
  try {
    let isSupported: boolean = previewOutput.isSketchSupported();
    return isSupported;
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isSketchSupported call failed. error code: ${err.code}`);
  }
  return false;
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

| Name    | Type     | Mandatory| Description                      |
|---------|---------| ---- | ------------------------ |
| enabled | boolean | Yes| Whether to enable PiP preview. The value **true** means to enable PiP preview, and **false** means to disable it.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID    | Error Message                       |
|-----------|-----------------------------|
| 202       | Not System Application.     |
| 7400102   | Operation not allowed.      |
| 7400103   | Session not config.         |
| 7400201   | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

| ID  | Error Message                                          |
|---------|------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400103 | Session not config.                            |
| 7400201 | Camera service fatal error.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

Subscribes to PiP status change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'sketchStatusChanged'**. The event can be listened for when a PiP preview stream is created. This event is triggered when PiP preview is enabled or disabled or the zoom ratio changes while PiP preview is enabled.|
| callback | AsyncCallback\<[SketchStatusData](#sketchstatusdata11)\> | Yes  | Callback used to return the PiP status data.           |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                         |
|---------|-------------------------------|
| 202     | Not System Application.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(error: BusinessError, data: camera.SketchStatusData): void {
  if (error !== undefined && error.code !== 0) {
    console.error(`Callback Error, errorCode: ${error.code}`);
    return;
  }
  console.info(`sketch errorCode is ${error.code}, data is ${JSON.stringify(data)}`);
}

function registerSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('sketchStatusChanged', callback);
}
```

### off('sketchStatusChanged')<sup>11+</sup>

off(type: 'sketchStatusChanged', callback?: AsyncCallback\<SketchStatusData\>): void

Unsubscribes from PiP status change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'sketchStatusChanged'**. The event can be listened for when a PiP preview stream is created.|
| callback | AsyncCallback\<[SketchStatusData](#sketchstatusdata11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('sketchStatusChanged')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)          |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                         |
|---------|-------------------------------|
| 202     | Not System Application.       |

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

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**Example**

```ts
import { image } from '@kit.ImageKit';

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

| Type           | Description              |
| -------------- |------------------|
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**Example**

```ts
async function releaseDeferredPhotoProxy(proxyObj: camera.DeferredPhotoProxy): Promise<void> {
  await proxyObj.release();
}
```

## PhotoOutput

Implements output information used in a photo session. It inherits from [CameraOutput](js-apis-camera.md#cameraoutput).

### burstCapture<sup>12+</sup>

burstCapture(setting: PhotoCaptureSetting): Promise\<void\>

Starts the burst mode, in which users can capture a series of photos in quick succession. This API is generally used in photo mode. After the burst mode starts, the bottom layer continues displaying photos. You can call [confirmCapture](#confirmcapture11) to cancel the burst mode.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name | Type                                       | Mandatory| Description    |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](js-apis-camera.md#photocapturesetting) | Yes  | Shooting parameters. The input of **undefined** is processed as if no parameters were passed.|

**Return value**

| Type           | Description                     |
| -------------- | ------------------------   |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |
| 7400101         |  Parameter missing or parameter type incorrect.          |
| 7400104         |  Session not running.          |
| 7400201         |  Camera service fatal error.   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function burstCapture(photoOutput: camera.PhotoOutput): void {
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
  photoOutput.burstCapture(settings).then(() => {
    console.info('Promise returned to indicate that photo burstCapture request success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to photo output burstCapture, error code: ${error.code}.`);
  });
}
```

### confirmCapture<sup>11+</sup>

confirmCapture()

Confirms photo capture. This API is generally used in night photo mode when users need to stop the exposure countdown and take a photo in advance.

This API is used to end the burst mode, which is started by calling [burstCapture](#burstcapture12).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |
| 7400104         |  Session not running.          |
| 7400201         |  Camera service fatal error.   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

| ID        | Error Message                                               |
| --------------- |-----------------------------------------------------|
| 7400101                | Parameter missing or parameter type incorrect.      |
| 7400104                | Session not running.                                |
| 7400201                | Camera service fatal error.                         |
| 202                    | Not System Application.                             |

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

### isAutoHighQualityPhotoSupported<sup>12+</sup>

isAutoHighQualityPhotoSupported(): boolean

Checks whether automatic high quality is supported for photos.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | Whether automatic high quality is supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isAutoHighQualityPhotoSupported(photoOutput: camera.PhotoOutput): boolean {
  return photoOutput.isAutoHighQualityPhotoSupported();
}
```

### enableAutoHighQualityPhoto<sup>12+</sup>

enableAutoHighQualityPhoto(enabled: boolean): void

Enables automatic high quality for photos. 

Before using this API, call [isAutoHighQualityPhotoSupported](#isautohighqualityphotosupported12) to check whether automatic high quality is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type              | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
|   enabled   |  boolean  |   Yes  |   Whether to enable automatic high quality for photos.   |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableAutoHighQualityPhoto(photoOutput: camera.PhotoOutput): void {
  return photoOutput.enableAutoHighQualityPhoto(true);
}
```

### on('deferredPhotoProxyAvailable')<sup>11+</sup>

on(type: 'deferredPhotoProxyAvailable', callback: AsyncCallback\<DeferredPhotoProxy\>): void

Subscribes to events indicating available thumbnail proxies. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'deferredPhotoProxyAvailable'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | Yes  | Callback used to return the thumbnail proxy.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

function callback(err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
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
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('deferredPhotoProxyAvailable')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)           |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

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
| 202                	 |  Not System Application.        |
| 7400104                |  session is not running.        |

**Example**

```ts
import { common } from '@kit.AbilityKit';

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
| 202                	 |  Not System Application.        |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  session is not running.        |
| 7400201                |  Camera service fatal error.        |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

Subscribes to quick thumbnail output events. This API uses an asynchronous callback to return the result.

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
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

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
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | No| Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('quickThumbnail')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Example**

```ts
function unregisterQuickThumbnail(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('quickThumbnail');
}
```

## VideoOutput

Implements output information used in a video session. It inherits from [CameraOutput](js-apis-camera.md#cameraoutput).

### isMirrorSupported<sup>12+</sup>

isMirrorSupported(): boolean

Checks whether video mirroring is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | Whether video mirroring is supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                |  Not System Application.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isMirrorSupported(videoOutput: camera.VideoOutput): boolean {
  return videoOutput.isMirrorSupported();
}
```

### enableMirror<sup>12+</sup>

enableMirror(enabled: boolean): void

Enables video mirroring.

Before using this API, call [isMirrorSupported](#ismirrorsupported12) to check whether video mirroring is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type              | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
|   enabled   |  boolean  |   Yes  |   Whether to enable video mirroring.   |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.  |
| 7400103                |  Session not config.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableMirror(videoOutput: camera.VideoOutput): void {
  return videoOutput.enableMirror(true);
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

## BeautyQuery<sup>12+</sup>

Provides APIs to obtain and set the beauty effect.

### getSupportedBeautyTypes<sup>12+</sup>

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
| 202                |  Not System Application.                                   |
| 7400103                |  Session not config.                                   |

**Example**

```ts
function getSupportedBeautyTypes(portraitPhotoSession: camera.PortraitPhotoSession): Array<camera.BeautyType> {
  let beautyTypes: Array<camera.BeautyType> = portraitPhotoSession.getSupportedBeautyTypes();
  return beautyTypes;
}
```

### getSupportedBeautyRange<sup>12+</sup>

getSupportedBeautyRange(type: BeautyType): Array\<number\>

Obtains the levels that can be set a beauty type.

The beauty levels vary according to the device type. The following table is only an example.

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
| 202                |  Not System Application.                                   |
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

## ManualExposureQuery<sup>12+</sup>

Provides APIs to obtain the manual exposure range supported.

### getSupportedExposureRange<sup>12+</sup>

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
| 202                |  Not System Application.  |
| 7400101            |  Parameter missing or parameter type incorrect.  |
| 7400103            |  Session not config, only throw in session usage.  |

 **Example**

```ts
function getSupportedExposureRange(nightPhotoSession: camera.NightPhotoSession): Array<number> {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  return exposureRange;
}
```

## ManualExposure<sup>11+</sup>

ManualExposure extends [ManualExposureQuery](#manualexposurequery12)

Provides APIs to obtain and set the exposure duration.

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
| 202                    |  Not System Application.                               |
| 7400101                |  Parameter missing or parameter type incorrect.        |
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

| Name     | Type                   | Mandatory| Description                                                                     |
| -------- | --------------------------| ---- |-------------------------------------------------------------------------|
| value    | number                    | Yes  | Manual exposure duration, which must be one of the supported durations obtained by running [getSupportedExposureRange](#getsupportedexposurerange12).|

 **Error codes**

| ID        | Error Message       |
| --------------- | --------------- |
| 202                	 |  Not System Application.  |
| 7400102                |  Operation not allowed.   |
| 7400103                |  Session not config.      |

```ts
function setExposure(nightPhotoSession: camera.NightPhotoSession): void {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return;
  }
  nightPhotoSession.setExposure(exposureRange[0]);
}
```

## MacroQuery<sup>12+</sup>

Provides the API to check the support for macro photography.

### isMacroSupported<sup>12+</sup>

isMacroSupported(): boolean

Checks whether macro photography is supported in the current state. This API must be called after [commitConfig](js-apis-camera.md#commitconfig11-1).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
|   boolean  | **true**: Macro photography is supported.<br>**false**: Macro photography is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                    |
|---------|--------------------------|
| 202     | Not System Application.  |

**Example**

```ts
function isMacroSupported(photoSession: camera.PhotoSessionForSys): boolean {
  let isSupported: boolean = photoSession.isMacroSupported();
  return isSupported;
}
```

## Macro<sup>11+</sup>

Macro extends [MacroQuery](#macroquery12)

Provides the API to enable macro photography.

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

| ID   | Error Message                    |
|----------|--------------------------|
| 202      | Not System Application.  |
| 7400102  | Operation not allowed.   |
| 7400103  | Session not config.      |

**Example**

```ts
function enableMacro(photoSession: camera.PhotoSessionForSys): void {
  let isSupported: boolean = photoSession.isMacroSupported();
  if (isSupported) {
    photoSession.enableMacro(true);
  }
}
```

## SceneFeatureType<sup>12+</sup>

Enumerates the scene features.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| MOON_CAPTURE_BOOST       | 0      | Moon scene. **System API**: This is a system API.           |

## SceneFeatureDetectionResult<sup>12+</sup>

Describes the scene feature detection result.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  |   Mandatory  | Description      |
| -------- | ---------- | -------- | -------- | ---------- |
| featureType |   [SceneFeatureType](#scenefeaturetype12)   |   Yes    |    Yes   | Scene feature type. |
| detected |   boolean   |   Yes    |    Yes   | Detection result. The value **true** means that the specified scene feature is detected.|

## SceneDetection<sup>12+</sup>

Provides the scene detection capability.

### isSceneFeatureSupported<sup>12+</sup>

isSceneFeatureSupported(type: SceneFeatureType): boolean

Checks whether a scene feature is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                                       | Mandatory | Description         |
|-------|-------------------------------------------|-----|-------------|
| type  | [SceneFeatureType](#scenefeaturetype12)   | Yes  | Scene feature. |

**Return value**

| Type       | Description          |
|-----------|--------------|
| boolean   | **true**: The scene feature is supported.<br>**false**: The scene feature is not supported. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                          |
|---------|------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |

**Example**

```ts
function isSceneFeatureSupported(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): boolean {
  let isSupported: boolean = photoSession.isSceneFeatureSupported(featureType);
  return isSupported;
}
```

### enableSceneFeature<sup>12+</sup>

enableSceneFeature(type: SceneFeatureType, enabled: boolean): void

Enables or disables a scene feature. This API must be called after [SceneFeatureDetectionResult](#scenefeaturedetectionresult12) of the corresponding scene feature is received.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory | Description                         |
|---------|-------------------------------------------|-----|-----------------------------|
| type    | [SceneFeatureType](#scenefeaturetype12)   | Yes  | Scene feature.              |
| enabled | boolean                                   | Yes  | Whether to enable the scene feature. The value **true** means to enable the scene feature, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                          |
|---------|------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableSceneFeature(photoSession: camera.PhotoSessionForSys, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput): void {
  photoSession.beginConfig();
  photoSession.addInput(cameraInput);
  photoSession.addOutput(previewOutput);
  photoSession.commitConfig();

  photoSession.on('featureDetection', camera.SceneFeatureType.MOON_CAPTURE_BOOST,
    (err: BusinessError, statusObject: camera.SceneFeatureDetectionResult) => {
      if (err !== undefined && err.code !== 0) {
        console.error(`Callback Error, errorCode: ${err.code}`);
        return;
      }
      console.info(
        `on featureDetectionStatus featureType:${statusObject.featureType} detected:${statusObject.detected}`);
      if (statusObject.featureType === camera.SceneFeatureType.MOON_CAPTURE_BOOST) {
        try {
          photoSession.enableSceneFeature(statusObject.featureType, statusObject.detected);
        } catch (error) {
          let err = error as BusinessError;
          console.error(`The enableSceneFeature call failed. error code: ${err.code}`);
        }
      }
    });
}
```

## ZoomPointInfo<sup>12+</sup>

Describes the equivalent focal length information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type       |   Read-only  | Optional | Description      |
| -------- | ---------- | -------- |-----| ---------- |
| zoomRatio |   number   |   Yes    | No  | Zoom ratio.|
| equivalentFocalLength |   number   |   Yes    | No  | Equivalent focal length corresponding to the current focal length ratio.|

## ZoomQuery<sup>12+</sup>

Provides the API to obtain the equivalent focal length information list in the current mode.

### getZoomPointInfos<sup>12+</sup>

getZoomPointInfos(): Array\<ZoomPointInfo\>

Obtains the equivalent focal length information list in the current mode.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type               | Description                                                 |
| ----------          | -----------------------------                         |
|  Array\<[ZoomPointInfo](#zoompointinfo12)\>| Equivalent focal length information list in the current mode.                  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                    |  Not System Application.                      |
| 7400103                |  Session not config.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomPointInfos(): Array<ZoomPointInfo> {
  try {
    let zoomPointInfos: Array<ZoomPointInfo> = sessionExtendsZoom.getZoomPointInfos();
	return zoomPointInfos;
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getZoomPointInfos call failed. error code: ${err.code}`);
  }
}
```

## Zoom<sup>11+</sup>

Zoom extend [ZoomQuery](#zoomquery12)

Provides APIs to process the zoom effect of a camera device, including obtaining the current zoom ratio, setting a zoom ratio, setting a zoom ratio in a smooth manner, and preparing or unpreparing for zooming.

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
import { BusinessError } from '@kit.BasicServicesKit';

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
import { BusinessError } from '@kit.BasicServicesKit';

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

Beauty extends [BeautyQuery](#beautyquery12)

Provides APIs to obtain and set the beauty effect.

### setBeauty<sup>11+</sup>

setBeauty(type: BeautyType, value: number): void

Sets a beauty type and its level. Beauty mode is turned off only when all the [beauty types](#beautytype) obtained through [getSupportedBeautyTypes](#getsupportedbeautytypes12) are disabled.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                                               |
| -------- | --------------------------| ---- |-------------------------------------------------------------------|
| type     | [BeautyType](#beautytype) | Yes  | Beauty type.                                                            |
| value    | number                    | Yes  | Beauty level, which is obtained through [getSupportedBeautyRange](#getsupportedbeautyrange12).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                |  Not System Application.                                   |
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
| 202                |  Not System Application.                                   |
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

## ColorEffectQuery<sup>12+</sup>

Provides the API to obtain the color effects supported.

### getSupportedColorEffects<sup>12+</sup>

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

## ColorEffect<sup>11+</sup>

ColorEffect extends [ColorEffectQuery](#coloreffectquery12)

Provides the APIs to obtain and set the lens color effect.

### setColorEffect<sup>11+</sup>

setColorEffect(type: ColorEffectType): void

Sets a color effect. Before the setting, call [getSupportedColorEffects](#getsupportedcoloreffects12) to obtain the supported color effects.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| type | [ColorEffectType](#coloreffecttype11)                              | Yes| Color effect, which can be obtained through [getSupportedColorEffects](#getsupportedcoloreffects12).  |

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
| BLACK_WHITE<sup>12+</sup>    | 3    | Black and white color effect. |

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

Sets a portrait effect. Before the setting, call [getSupportedPortraitEffects](#getsupportedportraiteffects10) to obtain the supported portrait effects and check whether the target portrait effect is supported.

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
import { BusinessError } from '@kit.BasicServicesKit';

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

| Name      | Type                      |  Read-only| Optional | Description              |
| ---------- | ------------------------- | ----- |-----| ----------------- |
| zoomRange  | [ZoomRange](#zoomrange11) | No   | No  | Zoom range of a given physical aperture. |
| apertures  | Array\<number\>           | No   | No  | Array of physical apertures supported.     |

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

Sets a virtual aperture. Before the setting, call [getSupportedVirtualApertures](#getsupportedvirtualapertures11) to obtain the supported virtual apertures.

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

Sets a physical aperture. Before the setting, call [getSupportedPhysicalApertures](#getsupportedphysicalapertures11) to obtain the supported physical apertures.

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
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Beauty.getSupportedBeautyTypes](#getsupportedbeautytypes12) instead.

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
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Beauty.getSupportedBeautyRange](#getsupportedbeautyrange12) instead.

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

PhotoSessionForSys extends PhotoSession, Beauty, ColorEffect, ColorManagement, Macro, SceneDetection

Implements a photo session for system applications, which sets the parameters of the normal photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

## PhotoSession<sup>11+</sup>

PhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorManagement

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

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, macroStatus: boolean): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
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
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('macroStatusChanged')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

**Example**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```

### on('featureDetection')<sup>12+</sup>

on(type: 'featureDetection', featureType: SceneFeatureType, callback: AsyncCallback\<SceneFeatureDetectionResult\>): void

Subscribe to scene feature detection status change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | Yes  | Event type. The value is fixed at **'featureDetection'**. The event can be listened for when a photo session is created.|
| featureType     | [SceneFeatureType](#scenefeaturetype12)      | Yes  | Scene feature type.|
| callback | AsyncCallback\<[SceneFeatureDetectionResult](#scenefeaturedetectionresult12)\>     | Yes  | Callback used to return the status of the scene feature detection. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, result: camera.SceneFeatureDetectionResult): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`feature type: ${result.featureType}`);
  console.info(`feature status: ${result.detected}`);
}

function registerFeatureDetectionStatus(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): void {
  photoSession.on('featureDetection', featureType, callback);
}
```

### off('featureDetection')<sup>12+</sup>

off(type: 'featureDetection', featureType: SceneFeatureType, callback?: AsyncCallback\<SceneFeatureDetectionResult\>): void

Unsubscribe from camera feature detection status change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | Yes  | Event type. The value is fixed at **'featureDetection'**. The event can be listened for when a session is created.|
| featureType     | [SceneFeatureType](#scenefeaturetype12)      | Yes  | Scene feature type.|
| callback | AsyncCallback\<[SceneFeatureDetectionResult](#scenefeaturedetectionresult12)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('featureDetection')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

**Example**

```ts
function unregisterFeatureDetectionStatus(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): void {
  photoSession.off('featureDetection', featureType);
}
```

## VideoSessionForSys<sup>11+</sup>

VideoSessionForSys extends VideoSession, Beauty, ColorEffect, ColorManagement, Macro

Implements a video session for system applications, which sets the parameters of the normal video mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

## VideoSession<sup>11+</sup>

VideoSession extends Session, Flash, AutoExposure, Focus, Zoom, Stabilization, ColorManagement

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

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, macroStatus: boolean): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
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
| callback | AsyncCallback\<boolean\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('macroStatusChanged')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

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

Subscribes to **PortraitSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Portrait photo session error code: ${err.code}`);
}

function registerSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('error', callback);
}
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PortraitSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | -------------------------- | ---- | ------------------------------ |
| type     | string                     | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('error')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)   |

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
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
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
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

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
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('smoothZoomInfoAvailable')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

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

Subscribes to **NightSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Night photo session error code: ${err.code}`);
}

function registerSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('error', callback);
}
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **NightSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('error')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)      |

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
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
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
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

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
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('smoothZoomInfoAvailable')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterSmoothZoomInfo(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('smoothZoomInfoAvailable');
}
```

### on('lcdFlashStatus')<sup>12+</sup>

on(type: 'lcdFlashStatus', callback: AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\>): void

Subscribes to LCD flash status change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'lcdFlashStatus'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\> | Yes  | Callback used to return the LCD flash status change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, lcdFlashStatus: camera.LcdFlashStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`lcdFlashStatus: ${lcdFlashStatus}`);
}

function registerLcdFlashStatus(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('lcdFlashStatus', callback);
}
```

### off('lcdFlashStatus')<sup>12+</sup>

off(type: 'lcdFlashStatus', callback?: AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\>): void

Unsubscribes from LCD flash status change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'lcdFlashStatus'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('lcdFlashStatus')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                     |
|-------|---------------------------|
| 202   | Not System Application.   |

**Example**

```ts
function unregisterLcdFlashStatus(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('lcdFlashStatus');
}
```

## HighResolutionPhotoSession<sup>12+</sup>

HighResolutionPhotoSession extends Session, AutoExposure, Focus

Implements a high-resolution photo session, which sets the parameters of the high-resolution photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **HighResolutionPhotoSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).       |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                |   Not System Application.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`High resolution photo session error code: ${err.code}`);
}

function registerSessionError(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.on('error', callback);
}
```
### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **HighResolutionPhotoSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('error')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                |   Not System Application.               |

**Example**

```ts
function unregisterSessionError(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                |   Not System Application.               |

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

function registerFocusStateChange(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202                |   Not System Application.               |

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterFocusStateChange(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.off('focusStateChange');
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

## SlowMotionVideoSession<sup>12+</sup>

SlowMotionVideoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect

Implements a slow-motion video session, which sets the parameters of the slow-motion video mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

> **NOTE**
>
> In slow-motion video mode, only preview streams and video streams can be added.
### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **SlowMotionVideoSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).       |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Portrait photo session error code: ${err.code}`);
}

function registerSessionError(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **SlowMotionVideoSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type       | Mandatory| Description                          |
| -------- | -------------------------- | ---- | ------------------------------ |
| type     | string                     | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('error')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)   |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterSessionError(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

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

function registerFocusStateChange(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterFocusStateChange(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

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

function registerSmoothZoomInfo(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('smoothZoomInfoAvailable')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterSmoothZoomInfo(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('smoothZoomInfoAvailable');
}
```

### on('slowMotionStatus')<sup>12+</sup>

on(type: 'slowMotionStatus', callback: AsyncCallback\<SlowMotionStatus\>): void

Subscribes to slow-motion status change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                                       | Mandatory| Description                                        |
| -------- |---------------------------------------------------------------------------| ---- |--------------------------------------------|
| type     | string                                                                    | Yes  | Event type. The value is fixed at **'slowMotionStatus'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SlowMotionStatus](#slowmotionstatus12)\> | Yes  | Callback used to return the slow-motion status change.    |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, slowMotionStatus: camera.SlowMotionStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The slow motion status: ${slowMotionStatus}`);
}

function registerSlowMotionStatus(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('slowMotionStatus', callback);
}
```

### off('slowMotionStatus')<sup>12+</sup>

off(type: 'slowMotionStatus', callback?: AsyncCallback\<SlowMotionStatus\>): void

Unsubscribes from slow-motion status change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'slowMotionStatus'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SlowMotionStatus](#slowmotionstatus12)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('slowMotionStatus')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application.                               |

**Example**

```ts
function unregisterSlowMotionStatus(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('slowMotionStatus');
}
```
### isSlowMotionDetectionSupported<sup>12+</sup>

isSlowMotionDetectionSupported(): boolean

Checks whether the device supports slow-motion detection.

> **NOTE**
>
> This API must be called after [commitConfig](js-apis-camera.md#commitconfig11-1) is called.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                                                                                    |
| ---------- |----------------------------------------------------------------------------------------|
| boolean    | **true**: The device supports slow-motion detection.<br>**false**: The device does not support slow-motion detection.<br>If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application.                               |
| 7400103 |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isSlowMotionDetectionSupported(slowMotionVideoSession: camera.SlowMotionVideoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = slowMotionVideoSession.isSlowMotionDetectionSupported();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### setSlowMotionDetectionArea<sup>12+</sup>

setSlowMotionDetectionArea(area: Rect): void

Sets an area for slow-motion detection.

> **NOTE**
>
> Before the setting, call [isSlowMotionDetectionSupported](#isslowmotiondetectionsupported12) to check whether the device supports slow-motion detection.
This API must be called after [commitConfig](js-apis-camera.md#commitconfig11-1) is called.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                           | Mandatory| Description                         |
| -------- | ---------------------------------------------- | ---- | --------------------------- |
| area  | [Rect](js-apis-camera.md#rect)      | Yes  | Area.                  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application.                            |
| 7400101 |  Parameter missing or parameter type incorrect.     |
| 7400103 |  Session not config.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setSlowMotionDetectionArea(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  try {
    slowMotionVideoSession.setSlowMotionDetectionArea({topLeftX: 0.1, topLeftY: 0.1, width: 0.8, height: 0.8});
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setSlowMotionDetectionArea call failed. error code: ${err.code}`);
  }
}
```

## PanoramaPhotoSession<sup>12+</sup>

PanoramaPhotoSession extends Session, Focus, AutoExposure, WhiteBalance, ColorEffect

Implements a panoramic photo session, which sets the parameters of the panoramic photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **PanoramaPhotoSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Panorama photo session error code: ${err.code}`);
}

function registerSessionError(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.on('error', callback);
}
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **PanoramaPhotoSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('error')** with the specified callback is canceled. (The callback object cannot be an anonymous function.)      |

**Example**

```ts
function unregisterSessionError(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.off('error');
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
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.on('focusStateChange', callback);
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
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Example**

```ts
function unregisterFocusStateChange(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.off('focusStateChange');
}
```

## IsoInfo<sup>12+</sup>

Describes the ISO information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type   | Read-only| Optional| Description          |
| ---- | ------- | ---- |--| -------------- |
| iso  | number  | Yes  | Yes| ISO.       |

---

## ExposureInfo<sup>12+</sup>

Describes the exposure information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name             | Type   | Read-only| Optional | Description              |
| ----------------- | ------- | ---- |-----| ------------------ |
| exposureTime | number  | Yes  | Yes  | Exposure time, in ms.|

---

## ApertureInfo<sup>12+</sup>

Describes the aperture information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type   | Read-only| Optional | Description      |
| --------- | ------- | ---- |-----| ---------- |
| aperture  | number  | Yes  | Yes  | Aperture.  |

---

## LuminationInfo<sup>12+</sup>

Describes the illumination information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name       | Type   | Read-only| Optional | Description      |
| ----------- | ------- | ---- |-----| ---------- |
| lumination  | number  | Yes  | Yes  | Illumination. The value range is [0,1].|

## CameraFormat

Enumerates the camera output formats.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_DNG<sup>12+</sup>  | 4         | Raw image in DNG format. **System API**: This is a system API.        |

## ExposureMeteringMode<sup>12+</sup>

Enumerates the exposure metering modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| MATRIX          | 0    | Performs metering on a wide area of the image.|
| CENTER          | 1    | Performs metering on the entire image, with the center allocated with the maximum weight.|
| SPOT            | 2    | Performs metering around 2.5% of the metering points.|

## AutoExposureQuery<sup>12+</sup>

Provides APIs to check whether a device supports an exposure mode or exposure metering mode and obtain the exposure compensation range.

### isExposureMeteringModeSupported<sup>12+</sup>

isExposureMeteringModeSupported(aeMeteringMode: ExposureMeteringMode): boolean

Checks whether an exposure metering mode is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMeteringMode   | [ExposureMeteringMode](#exposuremeteringmode12)  | Yes  | Metering mode.                     |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The exposure metering mode is supported.<br>**false**: The exposure metering mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.                                   |
| 7400103                |  Session not config.                                   |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isExposureMeteringModeSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = professionalPhotoSession.isExposureModeSupported(camera.ExposureMeteringMode.CENTER);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isExposureMeteringModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## AutoExposure

AutoExposure extends [AutoExposureQuery](#autoexposurequery12)

Provides APIs related to automatic exposure of a camera device, including obtaining and setting the exposure mode and measurement point, obtaining the compensation range, setting the exposure compensation, and obtaining the exposure metering mode.

### getExposureMeteringMode<sup>12+</sup>

getExposureMeteringMode(): ExposureMeteringMode

Obtains the exposure metering mode in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [ExposureMeteringMode](#exposuremeteringmode12)    | Exposure metering mode obtained. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMeteringMode(professionalPhotoSession: camera.ProfessionalPhotoSession): camera.ExposureMeteringMode | undefined {
  let exposureMeteringMode: camera.ExposureMeteringMode | undefined = undefined;
  try {
    exposureMeteringMode = professionalPhotoSession.getExposureMeteringMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureMeteringMode call failed. error code: ${err.code}`);
  }
  return exposureMeteringMode;
}
```

### setExposureMeteringMode<sup>12+</sup>

setExposureMeteringMode(aeMeteringMode: ExposureMeteringMode): void

Sets an exposure metering mode. 

Before the setting, call [isExposureMeteringModeSupported](#isexposuremeteringmodesupported12) to check whether the target exposure metering mode is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMeteringMode   | [ExposureMeteringMode](#exposuremeteringmode12)  | Yes  | Metering mode.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMeteringMode(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    professionalPhotoSession.setExposureMeteringMode(camera.ExposureMeteringMode.CENTER);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setExposureMeteringMode call failed. error code: ${err.code}`);
  }
}
```

## FocusQuery<sup>12+</sup>

Provides the API to check whether the focus assist is supported.

### isFocusAssistSupported<sup>12+</sup>

isFocusAssistSupported(): boolean

Checks whether the focus assist is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The focus assist is supported.<br>**false**: The focus assist is not supported. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusAssistSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let status: boolean = false;
  try {
    status = professionalPhotoSession.isFocusAssistSupported();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFocusAssistSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## Focus

Focus extends [FocusQuery](#focusquery12)

Provides APIs to obtain and set the camera focus mode and focus position.

### setFocusAssist<sup>12+</sup>

setFocusAssist(enabled: boolean): void

Sets the focus assist. 

Before the setting, call [isFocusAssistSupported](#isfocusassistsupported12) to check whether the device supports the focus assist.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| enabled | boolean | Yes  | **true**: Enables the focus assist.<br>**false**: Disables the focus assist.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusAssist(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    professionalPhotoSession.setFocusAssist(false);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusAssist call failed. error code: ${err.code}`);
  }
}
```

### getFocusAssist<sup>12+</sup>

getFocusAssist(): boolean

Checks whether the focus assist is enabled.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The focus assist is enabled.<br>**false**: The focus assist is disabled.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusAssist(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let isFocusAssistOpened: boolean;
  try {
    isFocusAssistOpened = professionalPhotoSession.getFocusAssist();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusAssist call failed. error code: ${err.code}`);
  }
  return isFocusAssistOpened;
}
```

## ManualFocus<sup>12+</sup>

Provides APIs related to manual focus operations.

### setFocusDistance<sup>12+</sup>

setFocusDistance(distance: number): void

Sets the manual focus distance.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| distance | number | Yes  | Manual focus distance. The value is a floating point number in the range [0, 1]. The value **0** indicates a close-up shot, and **1** indicates a long shot.<br> |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusDistance(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    let distance: number = 0.5;
    professionalPhotoSession.setFocusDistance(distance);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusDistance call failed. error code: ${err.code}`);
  }
}
```

### getFocusDistance<sup>12+</sup>

getFocusDistance(): number

Obtains the focus distance in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Normalized value of the focus distance.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusDistance(professionalPhotoSession: camera.ProfessionalPhotoSession): number {
  let distance: number = 0;
  try {
    distance = professionalPhotoSession.getFocusDistance();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusDistance call failed. error code: ${err.code}`);
  }
  return distance;
}
```

## ManualIsoQuery<sup>12+</sup>

Provides APIs to check whether a camera device supports manual ISO setting and obtain the ISO range supported by the device.

### isManualIsoSupported<sup>12+</sup>

isManualIsoSupported(): boolean

Checks whether manual ISO setting is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: Manual ISO setting is supported.<br>**false**: Manual ISO setting is not supported. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isManualIsoSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let status: boolean = false;
  try {
    status = professionalPhotoSession.isManualIsoSupported();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isManualIsoSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### getIsoRange<sup>12+</sup>

getIsoRange(): Array\<number\>

Obtains the supported ISO range.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | ISO range. The value range is [50, 100, ..., 6400]. The actual value depends on the bottom-layer capability. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getIsoRange(professionalPhotoSession: camera.ProfessionalPhotoSession): Array<number> {
  let isoRange: Array<number> = [];
  try {
    isoRange = professionalPhotoSession.getIsoRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getIsoRange call failed. error code: ${err.code}`);
  }
  return isoRange;
}
```

## ManualIso<sup>12+</sup>

ManualIso extends [ManualIsoQuery](#manualisoquery12)

Provides APIs for obtaining and setting the manual ISO (sensitivity) of a camera device.

### setIso<sup>12+</sup>
setIso(iso: number): void

Sets the ISO.

**NOTE**: When the ISO is set to 0, automatic ISO is used.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| iso | number | Yes  | ISO.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setIso(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    let iso: number = 200;
    professionalPhotoSession.setIso(iso);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setIso call failed. error code: ${err.code}`);
  }
}
```

### getIso<sup>12+</sup>

getIso(): number

Obtains the ISO in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | ISO.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getIso(professionalPhotoSession: camera.ProfessionalPhotoSession): number {
  let iso: number = 0;
  try {
    iso = professionalPhotoSession.getIso();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getIso call failed. error code: ${err.code}`);
  }
  return iso;
}
```

## WhiteBalanceMode<sup>12+</sup>

Enumerates the white balance modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| AUTO          | 0    | Automatic.|
| CLOUDY        | 1    | Cloudy.|
| INCANDESCENT  | 2    | Incandescent light.|
| FLUORESCENT   | 3    | Fluorescence light.|
| DAYLIGHT     	| 4    | Daylight.|
| MANUAL        | 5    | Manual.|

## WhiteBalanceQuery<sup>12+</sup>

Provides APIs to check whether a white balance mode is supported and obtain the white balance mode range supported.

### isWhiteBalanceModeSupported<sup>12+</sup>

isWhiteBalanceModeSupported(mode: WhiteBalanceMode): boolean

Checks whether a white balance mode is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core
**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| mode   | [WhiteBalanceMode](#whitebalancemode12)  | Yes  | White balance mode.                     |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | **true**: The white balance mode is supported.<br>**false**: The white balance mode is not supported. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isWhiteBalanceModeSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let status: boolean = false;
  try {
	let mode: WhiteBalanceMode = camera.WhiteBalanceMode.DAYLIGHT;
    status = professionalPhotoSession.isWhiteBalanceModeSupported(mode);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isWhiteBalanceModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### getWhiteBalanceRange<sup>12+</sup>

getWhiteBalanceRange(): Array\<number\>

Obtains the white balance range, in which users can manually adjust the white balance.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | White balance range, for example, [2800, ...,10000], in units of K (Kelvin). The actual value depends on the bottom-layer capability. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getWhiteBalanceRange(professionalPhotoSession: camera.ProfessionalPhotoSession): Array<number> {
  let range: Array<number> = [];
  try {
    range = professionalPhotoSession.getWhiteBalanceRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getWhiteBalanceRange call failed. error code: ${err.code}`);
  }
  return range;
}
```

## WhiteBalance<sup>12+</sup>

WhiteBalance extends [WhiteBalanceQuery](#whitebalancequery12)

Provides APIs to process white balance, including obtaining and setting the white balance mode and white balance value.

### setWhiteBalanceMode<sup>12+</sup>

setWhiteBalanceMode(mode: WhiteBalanceMode): void

Sets a white balance mode. 

Before the setting, call [isWhiteBalanceModeSupported](#iswhitebalancemodesupported12) to check whether the target white balance mode is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| mode   | [WhiteBalanceMode](#whitebalancemode12)  | Yes  | White balance mode.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setWhiteBalanceMode(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    professionalPhotoSession.setWhiteBalanceMode(camera.WhiteBalanceMode.DAYLIGHT);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setWhiteBalanceMode call failed. error code: ${err.code}`);
  }
}
```

### getWhiteBalanceMode<sup>12+</sup>

getWhiteBalanceMode(): WhiteBalanceMode

Obtains the white balance mode in use.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [WhiteBalanceMode](#whitebalancemode12)    | White balance mode in use. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getWhiteBalanceMode(professionalPhotoSession: camera.ProfessionalPhotoSession): camera.WhiteBalanceMode | undefined {
  let whiteBalanceMode: camera.WhiteBalanceMode | undefined = undefined;
  try {
    whiteBalanceMode = professionalPhotoSession.getWhiteBalanceMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getWhiteBalanceMode call failed. error code: ${err.code}`);
  }
  return whiteBalanceMode;
}
```

### setWhiteBalance<sup>12+</sup>

setWhiteBalance(whiteBalance: number): void

Sets a white balance value.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| whiteBalance | number | Yes  | White balance value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setWhiteBalance(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    let whiteBalance: number = 1000;
    professionalPhotoSession.setWhiteBalance(whiteBalance);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setWhiteBalance call failed. error code: ${err.code}`);
  }
}
```

### getWhiteBalance<sup>12+</sup>

getWhiteBalance(): number

Obtains the current white balance value.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | White balance value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getWhiteBalance(professionalPhotoSession: camera.ProfessionalPhotoSession): number {
  let whiteBalance: number = 0;
  try {
    whiteBalance = professionalPhotoSession.getWhiteBalance();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getWhiteBalance call failed. error code: ${err.code}`);
  }
  return whiteBalance;
}
```

## ProfessionalPhotoSession<sup>12+</sup>

ProfessionalPhotoSession extends Session, AutoExposure, ManualExposure, Focus, ManualFocus, WhiteBalance, ManualIso, Flash, Zoom, ColorEffect, Aperture

Implements a professional photo session, which sets the parameters of the professional photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session12).

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **ProfessionalPhotoSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Professional photo session error code: ${err.code}`);
}

function registerSessionError(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **ProfessionalPhotoSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback, which is optional. If a callback function is passed in, it is an anonymous function.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterSessionError(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

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

function registerFocusStateChange(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterFocusStateChange(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

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

function registerSmoothZoomInfo(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('smoothZoomInfoAvailable')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterSmoothZoomInfo(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('smoothZoomInfoAvailable');
}
```

### on('isoInfoChange')<sup>12+</sup>

on(type: 'isoInfoChange', callback: AsyncCallback\<IsoInfo\>): void

Subscribes to automatic ISO change events to obtain real-time ISO information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'isoInfoChange'**.        |
| callback | AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>| Yes  | Callback used to return the ISO information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isoInfoCallback(err: BusinessError, info: camera.IsoInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`ISO value: ${info.iso}`);
}

function registerIsoInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('isoInfoChange', isoInfoCallback);
}
```

### off('isoInfoChange')<sup>12+</sup>

off(type: 'isoInfoChange', callback?: AsyncCallback\<IsoInfo\>): void

Unsubscribes from automatic ISO change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'isoInfoChange'**.        |
| callback | AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('isoInfoChange')**.|

**Error codes**

| ID| Error Message                   |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterIsoInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('isoInfoChange');
}
```

### on('exposureInfoChange')<sup>12+</sup>

on(type: 'exposureInfoChange', callback: AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>): void

Subscribes to exposure information change events to obtain the exposure information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'exposureInfoChange'**.        |
| callback | AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>| Yes  | Callback used to return the exposure information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function exposureInfoCallback(err: BusinessError, info: camera.ExposureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`exposureTimeValue: ${info.exposureTime}`);
}

function registerExposureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('exposureInfoChange', exposureInfoCallback);
}
```

### off('exposureInfoChange')<sup>12+</sup>

off(type: 'exposureInfoChange', callback?: AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>): void

Unsubscribes from exposure information change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'exposureInfoChange'**.        |
| callback | AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('exposureInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterExposureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('exposureInfoChange');
}
```

### on('apertureInfoChange')<sup>12+</sup>

on(type: 'apertureInfoChange', callback: AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>): void

Subscribes to aperture change events to obtain the real-time aperture information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'apertureInfoChange'**.        |
| callback | AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>| Yes  | Callback used to return the aperture information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function apertureInfoCallback(err: BusinessError, info: camera.ApertureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Aperture value: ${info.aperture}`);
}

function registerApertureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('apertureInfoChange', apertureInfoCallback);
}
```

### off('apertureInfoChange')<sup>12+</sup>

off(type: 'apertureInfoChange', callback?: AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>): void

Unsubscribes from aperture change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'apertureInfoChange'**.        |
| callback | AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('apertureInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterApertureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('apertureInfoChange');
}
```

### on('luminationInfoChange')<sup>12+</sup>

on(type: 'luminationInfoChange', callback: AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>): void

Subscribes to illumination change events to obtain real-time illumination information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'luminationInfoChange'**.        |
| callback | AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>| Yes  | Callback used to return the illumination information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function luminationInfoCallback(err: BusinessError, info: camera.LuminationInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Lumination: ${info.lumination}`);
}

function registerLuminationInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('luminationInfoChange', luminationInfoCallback);
}
```

### off('luminationInfoChange')<sup>12+</sup>

off(type: 'luminationInfoChange', callback?: AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>): void

Unsubscribes from illumination change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'luminationInfoChange'**.        |
| callback | AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('luminationInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterLuminationInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('luminationInfoChange');
}
```

## ProfessionalVideoSession<sup>12+</sup>

ProfessionalVideoSession extends Session, AutoExposure, ManualExposure, Focus, ManualFocus, WhiteBalance, ManualIso, Flash, Zoom, ColorEffect, Aperture

Implements a professional video session, which sets the parameters of the professional video mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session12).

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **ProfessionalVideo** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Professional video session error code: ${err.code}`);
}

function registerSessionError(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **ProfessionalVideo** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback, which is optional. If a callback function is passed in, it is an anonymous function.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterSessionError(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

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

function registerFocusStateChange(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterFocusStateChange(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

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

function registerSmoothZoomInfo(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('smoothZoomInfoAvailable')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterSmoothZoomInfo(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('smoothZoomInfoAvailable');
}
```

### on('isoInfoChange')<sup>12+</sup>

on(type: 'isoInfoChange', callback: AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>): void

Subscribes to automatic ISO change events to obtain real-time ISO information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'isoInfoChange'**.        |
| callback | AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>| Yes  | Callback used to return the ISO information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isoInfoCallback(err: BusinessError, info: camera.IsoInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`ISO value: ${info.iso}`);
}

function registerIsoInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('isoInfoChange', isoInfoCallback);
}
```

### off('isoInfoChange')<sup>12+</sup>

off(type: 'isoInfoChange', callback?: AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>): void

Unsubscribes from automatic ISO change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'isoInfoChange'**.        |
| callback | AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('isoInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterIsoInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('isoInfoChange');
}
```

### on('exposureInfoChange')<sup>12+</sup>

on(type: 'exposureInfoChange', callback: AsyncCallback\<[ExposureInfo]((js-apis-camera-sys.md#exposureinfo12))\>): void

Subscribes to exposure information change events to obtain the exposure information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'exposureInfoChange'**.        |
| callback | AsyncCallback\<[ExposureInfo]((js-apis-camera-sys.md#exposureinfo12))\>| Yes  | Callback used to return the exposure information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function exposureInfoCallback(err: BusinessError, info: camera.ExposureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`exposureTimeValue: ${info.exposureTime}`);
}

function registerExposureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('exposureInfoChange', exposureInfoCallback);
}
```

### off('exposureInfoChange')<sup>12+</sup>

off(type: 'exposureInfoChange', callback?: AsyncCallback\<[ExposureInfo]((js-apis-camera-sys.md#exposureinfo12))\>): void

Unsubscribes from exposure information change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'exposureInfoChange'**.        |
| callback | AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('exposureInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterExposureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('exposureInfoChange');
}
```

### on('apertureInfoChange')<sup>12+</sup>

on(type: 'apertureInfoChange', callback: AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>): void

Subscribes to aperture change events to obtain the aperture information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'apertureInfoChange'**.        |
| callback | AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>| Yes  | Callback used to return the aperture information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function apertureInfoCallback(err: BusinessError, info: camera.ApertureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Aperture value: ${info.aperture}`);
}

function registerApertureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('apertureInfoChange', apertureInfoCallback);
}
```

### off('apertureInfoChange')<sup>12+</sup>

off(type: 'apertureInfoChange', callback?: AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>): void

Unsubscribes from aperture change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'apertureInfoChange'**.        |
| callback | AsyncCallback\<[ApertureInfo](js-apis-camera-sys.md#apertureinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('apertureInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterApertureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('apertureInfoChange');
}
```

### on('luminationInfoChange')<sup>12+</sup>

on(type: 'luminationInfoChange', callback: AsyncCallback\<[LuminationInfo]((js-apis-camera-sys.md#luminationinfo12))\>): void

Subscribes to illumination change events to obtain illumination information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'luminationInfoChange'**.        |
| callback | AsyncCallback\<[LuminationInfo]((js-apis-camera-sys.md#luminationinfo12))\>| Yes  | Callback used to return the illumination information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function luminationInfoCallback(err: BusinessError, info: camera.LuminationInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Lumination: ${info.lumination}`);
}

function registerLuminationInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('luminationInfoChange', luminationInfoCallback);
}
```

### off('luminationInfoChange')<sup>12+</sup>

off(type: 'luminationInfoChange', callback?: AsyncCallback\<[LuminationInfo]((js-apis-camera-sys.md#luminationinfo12))\>): void

Unsubscribes from illumination change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'luminationInfoChange'**.        |
| callback | AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12))\>| No  | Callback, which is optional and is used to match **callback** in **on('luminationInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterLuminationInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('luminationInfoChange');
}
```

## MacroPhotoSession<sup>12+</sup>

MacroPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ManualFocus

Implements a macro photo session, which sets the parameters of the macro photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **MacroPhotoSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                                                       | Mandatory | Description                                                                                                                                                                     |
|----------|---------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type     | string                                                                    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).                                                                                                          |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`MacroPhotoSession error code: ${err.code}`);
}

function registerSessionError(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **MacroPhotoSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                                                       | Mandatory| Description                                                         |
|----------|---------------------------------------------------------------------------|----|-------------------------------------------------------------|
| type     | string                                                                    | Yes | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.                       |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
function unregisterSessionError(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                                     |
|-----------|---------------------------------------------|----|-------------------------------------------------------------------------|
| type      | string                                      | Yes | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | Yes | Callback used to return the focus state change.                                                       |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

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

function registerFocusStateChange(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                          |
|-----------|---------------------------------------------|----|--------------------------------------------------------------|
| type      | string                                      | Yes | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.                  |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | No | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
function unregisterFocusStateChange(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

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

function registerSmoothZoomInfo(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
function unregisterSmoothZoomInfo(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.off('smoothZoomInfoAvailable');
}
```

## MacroVideoSession<sup>12+</sup>

MacroVideoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ManualFocus

Implements a macro video session, which sets the parameters of the macro video mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session11).

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **MacroVideoSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                                                       | Mandatory | Description                                                                                                                                                                     |
|----------|---------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type     | string                                                                    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).                                                                                                          |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`MacroPhotoSession error code: ${err.code}`);
}

function registerSessionError(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **MacroVideoSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                                                       | Mandatory| Description                                                         |
|----------|---------------------------------------------------------------------------|----|-------------------------------------------------------------|
| type     | string                                                                    | Yes | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.                       |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
function unregisterSessionError(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                                     |
|-----------|---------------------------------------------|----|-------------------------------------------------------------------------|
| type      | string                                      | Yes | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | Yes | Callback used to return the focus state change.                                                       |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

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

function registerFocusStateChange(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                                         | Mandatory| Description                                                          |
|-----------|---------------------------------------------|----|--------------------------------------------------------------|
| type      | string                                      | Yes | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.                  |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | No | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
function unregisterFocusStateChange(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

Subscribes to smooth zoom state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | Yes  | Callback used to return the smooth zoom state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

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

function registerSmoothZoomInfo(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

Unsubscribes from smooth zoom state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'smoothZoomInfoAvailable'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID| Error Message                      |
|-------|----------------------------|
| 202   | Not System Application.    |

**Example**

```ts
function unregisterSmoothZoomInfo(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.off('smoothZoomInfoAvailable');
}
```

## FlashQuery<sup>12+</sup>

Provides APIs to obtain the flash information of a camera device, including whether the LCD flash is supported.

### isLcdFlashSupported<sup>12+</sup>

isLcdFlashSupported(): boolean

Checks whether the LCD flash is supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | **true**: The LCD flash is supported.<br>**false**: The LCD flash is not supported.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400103                |  Session not config, only throw in session usage. |

**Example**

```ts
function isLcdFlashSupported(nightPhotoSession: camera.NightPhotoSession): boolean {
  return nightPhotoSession.isLcdFlashSupported();
}
```

## TimeLapseRecordState<sup>12+</sup>

Enumerates the time-lapse recording states.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| IDLE          | 0    | Recording not started.|
| RECORDING     | 1    | Recording.|

## TimeLapsePreviewType<sup>12+</sup>

Enumerates the time-lapse preview types, which affect the shooting algorithm.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| DARK         | 1    | Dark environment, a scenario with poor illumination, for example, at night or in a dark area.|
| LIGHT        | 2    | Bright environment, a scenario with good illumination, for example, in the daytime or under light.|

## TryAEInfo<sup>12+</sup>

Describes the Try AE parameters. Try AE indicates that the hardware reports the status based on the ambient illumination change during time-lapse photographing.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type   | Read-only| Optional| Description          |
| ---- | ------- | ---- |--| -------------- |
| isTryAEDone        | boolean  | Yes  | No| Whether Try AE is complete.       |
| isTryAEHintNeeded  | boolean  | Yes  | Yes| Whether Try AE is required.       |
| previewType        | [TimeLapsePreviewType](#timelapsepreviewtype12) | Yes  | Yes| Preview type.       |
| captureInterval    | number   | Yes  | Yes| Shooting interval, in ms.       |

## TimeLapsePhotoSession<sup>12+</sup>

TimeLapsePhotoSession extends Session, Focus, ManualFocus, AutoExposure, ManualExposure, ManualIso, WhiteBalance, Zoom, ColorEffect

Implements a time-lapse photo session, which sets the parameters of the time-lapse photo mode and saves all [CameraInput](js-apis-camera.md#camerainput) and [CameraOutput](js-apis-camera.md#cameraoutput) instances required to run the camera. It inherits from [Session](js-apis-camera.md#session12).

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to **TimeLapsePhotoSession** error events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](js-apis-camera.md#beginconfig11), [commitConfig](js-apis-camera.md#commitconfig11-1), and [addInput](js-apis-camera.md#addinput11).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| Yes  | Callback used to return an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Time lapse photo session error code: ${err.code}`);
}

function registerSessionError(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from **TimeLapsePhotoSession** error events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                          |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback, which is optional. If a callback function is passed in, it is an anonymous function.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterSessionError(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                      |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

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

function registerFocusStateChange(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | No  | Callback used to return the result. This parameter is optional. If this parameter is specified, the subscription to the specified event **on('focusStateChange')** with the specified callback is canceled. (The callback object cannot be an anonymous function.) |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 202     |  Not System Application. |

**Example**

```ts
function unregisterFocusStateChange(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('focusStateChange');
}
```

### on('isoInfoChange')<sup>12+</sup>

on(type: 'isoInfoChange', callback: AsyncCallback\<IsoInfo\>): void

Subscribes to automatic ISO change events to obtain real-time ISO information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'isoInfoChange'**.        |
| callback | AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>| Yes  | Callback used to return the ISO information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isoInfoCallback(err: BusinessError, info: camera.IsoInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`ISO value: ${info.iso}`);
}

function registerIsoInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('isoInfoChange', isoInfoCallback);
}
```

### off('isoInfoChange')<sup>12+</sup>

off(type: 'isoInfoChange', callback?: AsyncCallback\<IsoInfo\>): void

Unsubscribes from automatic ISO change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'isoInfoChange'**.        |
| callback | AsyncCallback\<[IsoInfo](js-apis-camera-sys.md#isoinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('isoInfoChange')**.|

**Error codes**

| ID| Error Message                   |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterIsoInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('isoInfoChange');
}
```

### on('exposureInfoChange')<sup>12+</sup>

on(type: 'exposureInfoChange', callback: AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>): void

Subscribes to exposure information change events to obtain the exposure information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'exposureInfoChange'**.        |
| callback | AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>| Yes  | Callback used to return the exposure information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function exposureInfoCallback(err: BusinessError, info: camera.ExposureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`exposureTimeValue: ${info.exposureTime}`);
}

function registerExposureInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('exposureInfoChange', exposureInfoCallback);
}
```

### off('exposureInfoChange')<sup>12+</sup>

off(type: 'exposureInfoChange', callback?: AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>): void

Unsubscribes from exposure information change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'exposureInfoChange'**.        |
| callback | AsyncCallback\<[ExposureInfo](js-apis-camera-sys.md#exposureinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('exposureInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterExposureInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('exposureInfoChange');
}
```

### on('luminationInfoChange')<sup>12+</sup>

on(type: 'luminationInfoChange', callback: AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>): void

Subscribes to illumination change events to obtain real-time illumination information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'luminationInfoChange'**.        |
| callback | AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>| Yes  | Callback used to return the illumination information.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function luminationInfoCallback(err: BusinessError, info: camera.LuminationInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Lumination: ${info.lumination}`);
}

function registerLuminationInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('luminationInfoChange', luminationInfoCallback);
}
```

### off('luminationInfoChange')<sup>12+</sup>

off(type: 'luminationInfoChange', callback?: AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>): void

Unsubscribes from illumination change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'luminationInfoChange'**.        |
| callback | AsyncCallback\<[LuminationInfo](js-apis-camera-sys.md#luminationinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('luminationInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterLuminationInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('luminationInfoChange');
}
```

### on('tryAEInfoChange')<sup>12+</sup>

on(type: 'tryAEInfoChange', callback: AsyncCallback\<[TryAEInfo](js-apis-camera-sys.md#tryaeinfo12)\>): void

Subscribes to Try AE change events to obtain real-time Try AE parameters. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'tryAEInfoChange'**.        |
| callback | AsyncCallback\<[TryAEInfo](js-apis-camera-sys.md#tryaeinfo12)\>| Yes  | Callback used to return the Try AE parameters.        |

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function tryAEInfoCallback(err: BusinessError, info: camera.TryAEInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`TryAEInfo: ${info.isTryAEDone}, ${info.isTryAEHintNeeded}, ${info.previewType}, ${info.captureInterval}`);
}

function registerTryAEInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('tryAEInfoChange', tryAEInfoCallback);
}
```

### off('tryAEInfoChange')<sup>12+</sup>

off(type: 'tryAEInfoChange', callback?: AsyncCallback\<[TryAEInfo](js-apis-camera-sys.md#tryaeinfo12)\>): void

Unsubscribes from Try AE change events.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                     | Mandatory| Description                              |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | Yes  | Event type. The value is fixed at **'tryAEInfoChange'**.        |
| callback | AsyncCallback\<[TryAEInfo](js-apis-camera-sys.md#tryaeinfo12)\>| No  | Callback, which is optional and is used to match **callback** in **on('tryAEInfoChange')**.|

**Error codes**

| ID| Error Message                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**Example**

```ts
function unregisterTryAEInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('tryAEInfoChange');
}
```

### isTryAENeeded<sup>12+</sup>

isTryAENeeded(): boolean

Checks whether Try AE is required.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean   | Result indicating whether Try AE is required. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103 |  Session not config.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isTryAENeeded(timeLapsePhotoSession: camera.TimeLapsePhotoSession): boolean {
  let needed = false;
  try {
    needed = timeLapsePhotoSession.isTryAENeeded();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isTryAENeeded call failed. error code: ${err.code}`);
  }
  return needed;
}
```

### startTryAE<sup>12+</sup>

startTryAE(): void

Starts to execute Try AE.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103 | Session not config.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startTryAE(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.startTryAE();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The startTryAE call failed. error code: ${err.code}`);
  }
}
```

### stopTryAE<sup>12+</sup>

stopTryAE(): void

Stops the execution of Try AE.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103 | Session not config.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopTryAE(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.stopTryAE();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The stopTryAE call failed. error code: ${err.code}`);
  }
}
```

### getSupportedTimeLapseIntervalRange<sup>12+</sup>

getSupportedTimeLapseIntervalRange(): Array\<number\>

Obtains the supported time-lapse shooting interval range.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Interval range, in ms. The value depends on the underlying capability. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getSupportedTimeLapseIntervalRange(timeLapsePhotoSession: camera.TimeLapsePhotoSession): Array<number> {
  let intervalRange: Array<number> = [];
  try {
    intervalRange = timeLapsePhotoSession.getSupportedTimeLapseIntervalRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getSupportedTimeLapseIntervalRange call failed. error code: ${err.code}`);
  }
  return intervalRange;
}
```

### getTimeLapseInterval<sup>12+</sup>

getTimeLapseInterval(): number

Obtains the current time-lapse shooting interval.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Shooting interval, in ms.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getTimeLapseInterval(timeLapsePhotoSession: camera.TimeLapsePhotoSession): number {
  let interval: number = 0;
  try {
    interval = timeLapsePhotoSession.getTimeLapseInterval();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getTimeLapseInterval call failed. error code: ${err.code}`);
  }
  return interval;
}
```

### setTimeLapseInterval<sup>12+</sup>
setTimeLapseInterval(interval: number): void

Sets a time-lapse shooting interval.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| interval | number | Yes  | Shooting interval, in ms.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setTimeLapseInterval(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    let interval: number = 10000;
    timeLapsePhotoSession.setTimeLapseInterval(interval);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setTimeLapseInterval call failed. error code: ${err.code}`);
  }
}
```

### getTimeLapseRecordState<sup>12+</sup>

getTimeLapseRecordState(): TimeLapseRecordState

Obtains the time-lapse shooting state.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [TimeLapseRecordState](#timelapserecordstate12)    | Shooting state. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getTimeLapseRecordState(timeLapsePhotoSession: camera.TimeLapsePhotoSession): camera.TimeLapseRecordState {
  let state = camera.TimeLapseRecordState.IDLE;
  try {
    state = timeLapsePhotoSession.getTimeLapseRecordState();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getTimeLapseRecordState call failed. error code: ${err.code}`);
  }
  return state;
}
```

### setTimeLapseRecordState<sup>12+</sup>

setTimeLapseRecordState(state: TimeLapseRecordState): void

Sets the time-lapse shooting state.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| state   | [TimeLapseRecordState](#timelapserecordstate12)  | Yes  | Shooting state.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setTimeLapseRecordState(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.setTimeLapseRecordState(camera.TimeLapseRecordState.RECORDING);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setTimeLapseRecordState call failed. error code: ${err.code}`);
  }
}
```

### getTimeLapsePreviewType<sup>12+</sup>

getTimeLapsePreviewType(): TimeLapsePreviewType

Obtains the time-lapse preview type.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [TimeLapsePreviewType](#timelapsepreviewtype12)    | Preview type. If the operation fails, an error code defined in [CameraErrorCode](js-apis-camera.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getTimeLapsePreviewType(timeLapsePhotoSession: camera.TimeLapsePhotoSession): camera.TimeLapsePreviewType {
  let type = camera.TimeLapsePreviewType.DARK;
  try {
    type = timeLapsePhotoSession.getTimeLapsePreviewType();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getTimeLapsePreviewType call failed. error code: ${err.code}`);
  }
  return type;
}
```

### setTimeLapsePreviewType<sup>12+</sup>

setTimeLapsePreviewType(type: TimeLapsePreviewType): void

Sets the time-lapse preview type.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| state   | [TimeLapsePreviewType](#timelapsepreviewtype12)  | Yes  | Preview type.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setTimeLapsePreviewType(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.setTimeLapsePreviewType(camera.TimeLapsePreviewType.LIGHT);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setTimeLapsePreviewType call failed. error code: ${err.code}`);
  }
}
```
