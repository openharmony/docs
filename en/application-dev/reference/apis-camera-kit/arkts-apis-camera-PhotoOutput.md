# Interface (PhotoOutput)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

PhotoOutput implements output information used in a photo session. It inherits from [CameraOutput](arkts-apis-camera-CameraOutput.md).

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## capture

capture(callback: AsyncCallback\<void\>): void

Captures a photo with the default photo capture parameters. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

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

## capture

capture(): Promise\<void\>

Captures a photo with the default photo capture parameters. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

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

## capture

capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void\>): void

Captures a photo with the specified photo capture parameters. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                        | Mandatory| Description                 |
| -------- | ------------------------------------------- | ---- | -------------------- |
| setting  | [PhotoCaptureSetting](arkts-apis-camera-i.md#photocapturesetting) | Yes  | Photo capture settings.            |
| callback | AsyncCallback\<void\>                        | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned. |

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

## capture

capture(setting: PhotoCaptureSetting): Promise\<void\>

Captures a photo with the specified photo capture parameters. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description     |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](arkts-apis-camera-i.md#photocapturesetting) | Yes  | Photo capture parameters. The input of **undefined** is processed as if no parameters were passed.|

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

## on('photoAvailable')<sup>11+</sup>

on(type: 'photoAvailable', callback: AsyncCallback\<Photo\>): void

Subscribes to events indicating available high-resolution images. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'photoAvailable'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[Photo](arkts-apis-camera-Photo.md)\> | Yes  | Callback used to return the high-resolution image.|

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

## off('photoAvailable')<sup>11+</sup>

off(type: 'photoAvailable', callback?: AsyncCallback\<Photo\>): void

Unsubscribes from events indicating available high-resolution images.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'photoAvailable'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[Photo](arkts-apis-camera-Photo.md)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

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

## on('captureStartWithInfo')<sup>11+</sup>

on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo\>): void

Subscribes to capture start events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'captureStartWithInfo'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[CaptureStartInfo](arkts-apis-camera-i.md#capturestartinfo11)\> | Yes  | Callback used to return the capture ID.|

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

## off('captureStartWithInfo')<sup>11+</sup>

off(type: 'captureStartWithInfo', callback?: AsyncCallback\<CaptureStartInfo\>): void

Unsubscribes from capture start events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStartWithInfo'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[CaptureStartInfo](arkts-apis-camera-i.md#capturestartinfo11)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function unRegisterCaptureStartWithInfo(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureStartWithInfo');
}
```

## isMovingPhotoSupported<sup>12+</sup>

isMovingPhotoSupported(): boolean

Checks whether taking moving photos is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | Check result for the support of taking moving photos. **true** if supported, **false** otherwise.|

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

## enableMovingPhoto<sup>12+</sup>

enableMovingPhoto(enabled: boolean): void

Enables or disables the feature of taking moving photos.

**Required permissions:** ohos.permission.MICROPHONE

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| enabled  | boolean                | Yes  | Whether to enable the feature of taking moving photos. **true** to enable, **false** otherwise.    |

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

## on('photoAssetAvailable')<sup>12+</sup>

on(type: 'photoAssetAvailable', callback: AsyncCallback\<photoAccessHelper.PhotoAsset\>): void

Subscribes to photo asset available events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'photoAssetAvailable'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAsset.md)\> | Yes  | Callback used to return the photo asset.|

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

## off('photoAssetAvailable')<sup>12+</sup>

off(type: 'photoAssetAvailable', callback?: AsyncCallback\<photoAccessHelper.PhotoAsset\>): void

Unsubscribes from photo asset available events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory | Description                                                                        |
| -------- | ---------- |-----|----------------------------------------------------------------------------|
| type     | string     | Yes  | Event type. The value is fixed at **'photoAssetAvailable'**. The event can be listened for when a photoOutput instance is created.                        |
| callback | AsyncCallback\<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAsset.md)\> | No  | Callback used for unsubscription. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function offPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('photoAssetAvailable');
}
```

## isMirrorSupported

isMirrorSupported(): boolean

Checks whether mirror photography is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | Check result for the support of mirror photography. **true** if supported, **false** otherwise.|

**Example**

```ts
function isMirrorSupported(photoOutput: camera.PhotoOutput): boolean {
  let isSupported: boolean = photoOutput.isMirrorSupported();
  return isSupported;
}
```

## enableMirror<sup>13+</sup>

enableMirror(enabled: boolean): void

Enables dynamic photo capture.

Before calling this API, check whether dynamic photo capture is supported by calling [isMovingPhotoSupported](#ismovingphotosupported12) and whether mirroring is supported by calling [isMirrorSupported](#ismirrorsupported).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                       |
|----------| ---------------------- | ---- |---------------------------|
| enabled | boolean                | Yes  | Whether to enable or disable dynamic photo capture. **true** to enable, **false** otherwise.|

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

## getSupportedMovingPhotoVideoCodecTypes<sup>13+</sup>

getSupportedMovingPhotoVideoCodecTypes(): Array\<VideoCodecType\>

Obtains the supported video codec types of moving photos.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description               |
| -------------- |-------------------|
| Array\<[VideoCodecType](arkts-apis-camera-e.md#videocodectype13)\> | Array holding the supported video codec types.|

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

## setMovingPhotoVideoCodecType<sup>13+</sup>

setMovingPhotoVideoCodecType(codecType: VideoCodecType): void

Sets a video codec type for moving photos.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                                 | Mandatory|  Description               |
| ------------- |-------------------------------------|-------| ------------        |
| codecType     | [VideoCodecType](arkts-apis-camera-e.md#videocodectype13) |  Yes   |Video codec type. |

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

## on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo\>): void

Subscribes to frame shutter events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'frameShutter'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[FrameShutterInfo](arkts-apis-camera-i.md#frameshutterinfo)\> | Yes  | Callback used to return the result. A new photo capture request can be delivered as long as this event is returned.            |

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

## off('frameShutter')

off(type: 'frameShutter', callback?: AsyncCallback\<FrameShutterInfo\>): void

Unsubscribes from frame shutter events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'frameShutter'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[FrameShutterInfo](arkts-apis-camera-i.md#frameshutterinfo)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('frameShutter');
}
```

## on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo\>): void

Subscribes to capture end events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a photoOutput instance is created. This event is triggered and the corresponding information is returned when the photo capture is complete.|
| callback | AsyncCallback\<[CaptureEndInfo](arkts-apis-camera-i.md#captureendinfo)\> | Yes  | Callback used to return the result.                 |

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

## off('captureEnd')

off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo\>): void

Unsubscribes from capture end events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[CaptureEndInfo](arkts-apis-camera-i.md#captureendinfo)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureEnd');
}
```

## on('frameShutterEnd')<sup>12+</sup>

on(type: 'frameShutterEnd', callback: AsyncCallback\<FrameShutterEndInfo\>): void

Subscribes to frame shutter end events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'frameShutterEnd'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[FrameShutterEndInfo](arkts-apis-camera-i.md#frameshutterendinfo12)\> | Yes  | Callback used to return the result. It is invoked when the frame shutter ends.  |

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

## off('frameShutterEnd')<sup>12+</sup>

off(type: 'frameShutterEnd', callback?: AsyncCallback\<FrameShutterEndInfo\>): void

Unsubscribes from frame shutter end events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at **'frameShutterEnd'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<[FrameShutterEndInfo](arkts-apis-camera-i.md#frameshutterendinfo12)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputFrameShutterEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('frameShutterEnd');
}
```

## on('captureReady')<sup>12+</sup>

on(type: 'captureReady', callback: AsyncCallback\<void\>): void

Subscribes to capture ready events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| type     | string                | Yes  | Event type. The value is fixed at **'captureReady'**. The event can be listened for when a photoOutput instance is created. The event is triggered and the corresponding information is returned when it is ready to take the next photo.|
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

## off('captureReady')<sup>12+</sup>

off(type: 'captureReady', callback?: AsyncCallback\<void\>): void

Unsubscribes from capture ready events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                               | Yes  | Event type. The value is fixed at **'captureReady'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<void\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputCaptureReady(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureReady');
}
```

## on('estimatedCaptureDuration')<sup>12+</sup>

on(type: 'estimatedCaptureDuration', callback: AsyncCallback\<number\>): void

Subscribes to estimated capture duration events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'estimatedCaptureDuration'**. The event can be listened for when a photoOutput instance is created. This event is triggered and the corresponding information is returned when the photo capture is complete.|
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

## off('estimatedCaptureDuration')<sup>12+</sup>

off(type: 'estimatedCaptureDuration', callback?: AsyncCallback\<number\>): void

Unsubscribes from estimated capture duration events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type. The value is fixed at **'estimatedCaptureDuration'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<number\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputEstimatedCaptureDuration(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('estimatedCaptureDuration');
}
```

## on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to PhotoOutput error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a photoOutput instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a photo-related API.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode).            |

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

## off('error')

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from PhotoOutput error events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a photoOutput instance is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('error');
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

## getPhotoRotation<sup>12+</sup>

getPhotoRotation(deviceDegree: number): ImageRotation

Obtains the photo rotation degree.

- Device' natural orientation: The default orientation of the device (phone) is in portrait mode, with the charging port facing downward.
- Camera lens angle: equivalent to the angle at which the camera is rotated clockwise to match the device's natural direction. The rear camera sensor of a phone is installed in landscape mode. Therefore, it needs to be rotated by 90 degrees clockwise to match the device's natural direction.
- Screen orientation: The upper left corner of the image displayed on the screen is the first pixel, which is the coordinate origin. In the case of lock screen, the direction is the same as the device's natural orientation.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| deviceDegree | number | Yes  | Rotation angle.|

**Return value**

|      Type     | Description       |
| -------------  |-----------|
| [ImageRotation](arkts-apis-camera-e.md#imagerotation) | Photo rotation degree.|

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


## on('captureStart')<sup>(deprecated)</sup>

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
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a photoOutput instance is created. This event is triggered and returned when the bottom layer starts exposure each time a photo is taken.|
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

## off('captureStart')<sup>(deprecated)</sup>

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
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a photoOutput instance is created.|
| callback | AsyncCallback\<number\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureStart');
}
```
