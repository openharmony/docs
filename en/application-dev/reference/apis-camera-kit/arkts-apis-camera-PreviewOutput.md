# Interface (PreviewOutput)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=e78a6cc17babc03b49d63c81464e0e9d7953f5bb translatedAt=2026-08-11T02:00:04.022Z pushedAt=2026-08-11T11:41:11.947Z -->

PreviewOutput implements preview output. It inherits from [CameraOutput](arkts-apis-camera-CameraOutput.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

Subscribes to preview frame start events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                    |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a previewOutput instance is created. This event is triggered and returned when the bottom layer starts exposure for the first time.|
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

## off('frameStart')

off(type: 'frameStart', callback?: AsyncCallback\<void\>): void

Unsubscribes from preview frame start events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                    |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a previewOutput instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameStart');
}
```

## on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback\<void\>): void

Subscribes to preview frame end events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a previewOutput instance is created. This event is triggered and returned when the last frame of preview ends.|
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

## off('frameEnd')

off(type: 'frameEnd', callback?: AsyncCallback\<void\>): void

Unsubscribes from preview frame end events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a previewOutput instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameEnd');
}
```

## on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to PreviewOutput error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a previewOutput instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a preview-related API such as [Session.start](arkts-apis-camera-Session.md#start11-1) or [CameraOutput.release](arkts-apis-camera-CameraOutput.md#release-1).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode). |

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

## off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from PreviewOutput error events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a previewOutput instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('error');
}
```

## getSupportedFrameRates<sup>12+</sup>

 getSupportedFrameRates(): Array\<FrameRateRange\>

Obtains the supported frame rates.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     |     Description    |
| -------------  | ------------ |
| Array<[FrameRateRange](arkts-apis-camera-i.md#frameraterange)> | Array of supported frame rates. If the API call fails, undefined is returned.|

**Example**

```ts
function getSupportedFrameRates(previewOutput: camera.PreviewOutput): Array<camera.FrameRateRange> {
  let supportedFrameRatesArray: Array<camera.FrameRateRange> = previewOutput.getSupportedFrameRates();
  return supportedFrameRatesArray;
}
```

## setFrameRate<sup>12+</sup>

setFrameRate(minFps: number, maxFps: number): void

Sets a frame rate range for preview streams. The range must be within the supported frame rate range,

which can be obtained by calling [getSupportedFrameRates](#getsupportedframerates12).

> **NOTE**
> This API is valid only in [PhotoSession](arkts-apis-camera-PhotoSession.md) or [VideoSession](arkts-apis-camera-VideoSession.md) mode.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| minFps   | number        | Yes  | Minimum frame rate, in fps. When the maximum value is less than the minimum value, the API does not take effect.|
| maxFps   | number        | Yes  | Maximum frame rate, in fps. When the minimum value is greater than the maximum value, the API does not take effect.|

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

## getActiveFrameRate<sup>12+</sup>

getActiveFrameRate(): FrameRateRange

Obtains the configured frame rate range.

This API is valid only after [setFrameRate](#setframerate12) is called to set a frame rate range for preview streams.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     |     Description    |
| -------------  | ------------ |
| [FrameRateRange](arkts-apis-camera-i.md#frameraterange) | Frame rate range.|

**Example**

```ts
function getActiveFrameRate(previewOutput: camera.PreviewOutput): camera.FrameRateRange {
  let activeFrameRate: camera.FrameRateRange = previewOutput.getActiveFrameRate();
  return activeFrameRate;
}
```

## getActiveProfile<sup>12+</sup>

getActiveProfile(): Profile

Obtains the profile that takes effect currently.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [Profile](arkts-apis-camera-i.md#profile) | Profile obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400201 | Camera service fatal error.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## getPreviewRotation<sup>12+</sup>

getPreviewRotation(displayRotation?: number): ImageRotation

Obtains the preview rotation angle.

- Device' natural orientation: the default orientation for using a device. For example, the default orientation of the bar-type phone is in portrait mode, with the charging port facing downward.

- Camera lens angle: equivalent to the angle at which the camera is rotated clockwise to match the device's natural orientation. For example, the rear camera sensor of a bar-type phone is installed in landscape mode. Therefore, it needs to be rotated by 90 degrees clockwise to match the device's natural orientation.

- [Screen Rotation](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-multi-device-window-direction): indicates the clockwise rotation angle of the device screen.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| displayRotation | number  | No  | Screen rotation angle of the display. It is obtained by calling [display.getDefaultDisplaySync](../apis-arkui/js-apis-display.md#displaygetdefaultdisplaysync9).<br> Since API version 23, the input parameter **displayRotation** is optional. If no parameter is passed, the system obtains the **displayRotation** value to calculate rotation angle of a video.<br> The value ranges from 0 to 360, in degrees.|

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [ImageRotation](arkts-apis-camera-e.md#imagerotation) | The preview rotation angle obtained. If the API call fails, undefined is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.<br>Applicable versions: 12-22 |
| 7400201 | Camera service fatal error.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function testGetPreviewRotation(previewOutput: camera.PreviewOutput, imageRotation : camera.ImageRotation): camera.ImageRotation {
  let previewRotation: camera.ImageRotation = camera.ImageRotation.ROTATION_0;
  try {
    previewRotation = previewOutput.getPreviewRotation(imageRotation);
    console.info(`Preview rotation is: ${previewRotation}`);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The previewOutput.getPreviewRotation call failed. error code: ${err.code}`);
  }
  return previewRotation;
}

function testGetPreviewRotationWithOutParam(previewOutput: camera.PreviewOutput): camera.ImageRotation {
  let previewRotation: camera.ImageRotation = camera.ImageRotation.ROTATION_0;
  try {
    previewRotation = previewOutput.getPreviewRotation();
    console.info(`Preview rotation is: ${previewRotation}`);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The previewOutput.testGetPreviewRotationWithOutParam call failed. error code: ${err.code}`);
  }
  return previewRotation;
}
```

## setPreviewRotation<sup>12+</sup>

setPreviewRotation(previewRotation: ImageRotation, isDisplayLocked?: boolean): void

Sets the preview rotation angle.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| previewRotation | [ImageRotation](arkts-apis-camera-e.md#imagerotation)  | Yes  | Preview rotation angle.|
| isDisplayLocked | boolean  | No  | Whether the orientation of the surface is locked when the screen rotates. If this parameter is not set, the default value **false** is used, indicating that the orientation is not locked. **true** if locked, **false** otherwise. For details, see [SurfaceRotationOptions](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#surfacerotationoptions12).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.  |
| 7400201 | Camera service fatal error.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## start<sup>(deprecated)</sup>

start(callback: AsyncCallback\<void\>): void

Starts to output preview streams. This API uses an asynchronous callback to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](arkts-apis-camera-Session.md#start11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the preview stream output starts successfully, **err** is **undefined**; otherwise, **err** is an error object with an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode).|

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

## start<sup>(deprecated)</sup>

start(): Promise\<void\>

Starts to output preview streams. This API uses a promise to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](arkts-apis-camera-Session.md#start11-1) instead.

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

## stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void\>): void

Stops outputting preview streams. This API uses an asynchronous callback to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](arkts-apis-camera-Session.md#stop11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the preview stream output stops successfully, **err** is **undefined**; otherwise, **err** is an error object.|

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

## stop<sup>(deprecated)</sup>

stop(): Promise\<void\>

Stops outputting preview streams. This API uses a promise to return the result.

> **NOTE**
>This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](arkts-apis-camera-Session.md#stop11-1) instead.

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

## isBandwidthCompressionSupported<sup>23+</sup>

isBandwidthCompressionSupported(): boolean

Checks whether preview bandwidth compression is supported. This involves reducing data volume through encoding to minimize bandwidth usage during transmission.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | Check result for the support of preview bandwidth compression. **true** if supported, **false** otherwise.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isBandwidthCompressionSupported(previewOutput: camera.PreviewOutput): boolean {
  let supported: boolean = false;
  try {
    supported = previewOutput.isBandwidthCompressionSupported();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The previewOutput.isBandwidthCompressionSupported call failed. error code: ${err.code}`);
  }
  return supported;
}
```

## enableBandwidthCompression<sup>23+</sup>

enableBandwidthCompression(enabled: boolean): void

Enables preview bandwidth compression.

Before enabling this feature, you can call [isBandwidthCompressionSupported](#isbandwidthcompressionsupported23) to check whether the device supports preview bandwidth compression.

> **NOTE**
> This function must be called prior to [Session.commitConfig](arkts-apis-camera-Session.md#commitconfig11). Otherwise, the preview output stream format will be affected.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| enabled  | boolean | Yes | Whether to enable preview bandwidth compression. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID   | Error Message                                          |
| -------- |----------------------------------------------- |
| 7400102  | Operation not allowed. |
| 7400103  | Session not config. |
| 7400201  | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableBandwidthCompression(previewOutput: camera.PreviewOutput, enabled: boolean): void {
  try {
    previewOutput.enableBandwidthCompression(enabled);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The previewOutput.enableBandwidthCompression call failed. error code: ${err.code}`);
  }
}
```

## addDeferredSurface<sup>24+</sup>

addDeferredSurface(surfaceId: string): void

Adds a surface for delayed preview. This API can run after [commitConfig](arkts-apis-camera-Session.md#commitconfig11-1) or [start](arkts-apis-camera-Session.md#start11-1) is called.

**Atomic service API**: This API can be used in atomic services since API version 24.

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
import { BusinessError } from '@kit.BasicServicesKit';

async function preview(cameraManager: camera.CameraManager, cameraInfo: camera.CameraDevice, previewProfile: camera.Profile, photoProfile: camera.Profile, mode: camera.SceneMode, previewSurfaceId: string): Promise<void> {
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameraInfo);
  let previewOutput: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  let session: camera.Session  = cameraManager.createSession(mode);
  session.beginConfig();
  session.addInput(cameraInput);
  session.addOutput(previewOutput);
  session.addOutput(photoOutput);
  await session.commitConfig();
  try {
    await session.start();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`start session failed. error code: ${err.code}`);
  }
  previewOutput.addDeferredSurface(previewSurfaceId);
}
```

## isLogViewAssistSupported

isLogViewAssistSupported(): boolean

Checks whether view assist is supported for LOG videos. After view assist is enabled, the preview image is restored to the original color gamut, and the recorded video is still in the LOG format.

> **NOTE**
>
> View assist is supported for a resolution of 1080p or lower only.

**Since**: 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type            | Description                     |
| -------------- | ----------------------- |
| boolean | Whether view assist is supported. The value **true** indicates it is supported, and **false** indicates otherwise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isLogViewAssistSupported(previewOutput: camera.PreviewOutput): boolean {
  let supported: boolean = false;
  try {
      supported = previewOutput.isLogViewAssistSupported();
  } catch (error) {
      // If the operation fails, error.code is returned and processed.
      let err = error as BusinessError;
      console.error(`The previewOutput.isLogViewAssistSupported call failed. error code: ${err.code}`);
  }
  return supported;
}
```

## setLogViewAssistEnable

setLogViewAssistEnable(enable: boolean): void

Before enabling view assist for LOG videos, you can call [isLogViewAssistSupported](#islogviewassistsupported) to check whether the device supports view assist for preview.

> **NOTE**
> 
> - This API can be called only after [Session.commitConfig](arkts-apis-camera-Session.md#commitconfig11) is called.
> - View assist for preview is supported for a resolution of 1080p or lower only.

**Since**: 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory | Description                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| enable  | boolean | Yes  | Whether to enable view assist. The value **true** indicates that view assist is enabled, and the value **false** indicates otherwise. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md) and [Universal Error Codes](../errorcode-universal.md).

| ID    | Error Message                                           |
| -------- |----------------------------------------------- |
| 801  | Capability not supported. |
| 7400103  | Session not config. |
| 7400201  | Camera service fatal error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setLogViewAssistEnable(previewOutput: camera.PreviewOutput, enable: boolean): void {
  try {
      previewOutput.setLogViewAssistEnable(enable);
  } catch (error) {
      // If the operation fails, error.code is returned and processed.
      let err = error as BusinessError;
      console.error(`The previewOutput.setLogViewAssistEnable call failed. error code: ${err.code}`);
  }
}
```