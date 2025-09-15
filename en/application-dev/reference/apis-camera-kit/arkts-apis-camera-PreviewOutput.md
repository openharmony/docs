# Interface (PreviewOutput)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

PreviewOutput implements preview output. It inherits from [CameraOutput](arkts-apis-camera-CameraOutput.md).

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
| Array<[FrameRateRange](arkts-apis-camera-i.md#frameraterange)> | Array of supported frame rates.|

**Example**

```ts
function getSupportedFrameRates(previewOutput: camera.PreviewOutput): Array<camera.FrameRateRange> {
  let supportedFrameRatesArray: Array<camera.FrameRateRange> = previewOutput.getSupportedFrameRates();
  return supportedFrameRatesArray;
}
```

## setFrameRate<sup>12+</sup>

setFrameRate(minFps: number, maxFps: number): void

Sets a frame rate range for preview streams. The range must be within the supported frame rate range, which can be obtained by calling [getSupportedFrameRates](#getsupportedframerates12).

> **NOTE**
>
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

getPreviewRotation(displayRotation: number): ImageRotation

Obtains the preview rotation degree.

- Device' natural orientation: The default orientation of the device (phone) is in portrait mode, with the charging port facing downward.
- Camera lens angle: equivalent to the angle at which the camera is rotated clockwise to match the device's natural direction. The rear camera sensor of a phone is installed in landscape mode. Therefore, it needs to be rotated by 90 degrees clockwise to match the device's natural direction.
- Screen orientation: The top-left corner of the image displayed on the screen is the first pixel, which is the coordinate origin. In the case of lock screen, the direction is the same as the device's natural orientation.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| displayRotation | number  | Yes  | Screen rotation angle of the display. It is obtained by calling [display.getDefaultDisplaySync](../apis-arkui/js-apis-display.md#displaygetdefaultdisplaysync9).|

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [ImageRotation](arkts-apis-camera-e.md#imagerotation) | Preview rotation degree.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                        |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.  |
| 7400201 | Camera service fatal error.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## setPreviewRotation<sup>12+</sup>

setPreviewRotation(previewRotation: ImageRotation, isDisplayLocked?: boolean): void

Sets the preview rotation degree.

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
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](arkts-apis-camera-Session.md#start11) instead.

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
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](arkts-apis-camera-Session.md#start11-1) instead.

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
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](arkts-apis-camera-Session.md#stop11) instead.

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
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](arkts-apis-camera-Session.md#stop11-1) instead.

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
