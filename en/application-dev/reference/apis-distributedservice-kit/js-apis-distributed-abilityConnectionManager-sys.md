# @ohos.abilityConnectionManager (Cross-Device Connection Management) (System API)

The **abilityConnectionManager** module provides APIs for cross-device connection management. After successful networking between devices (login with the same account and enabling of Bluetooth on the devices), a system application and third-party application can start a [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) of the same application across the devices. After a connection is successfully established, data can be transmitted across the devices, including strings, [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) byte streams, images, and transport streams.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import { abilityConnectionManager } from '@kit.DistributedServiceKit';
```

## abilityConnectionManager.on

on(type:&nbsp;'collaborateEvent'&nbsp;|&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Registers a callback listener for the **collaborateEvent** and **receiveImage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type, which can be:<br>\- `collaborateEvent`: event triggered when `collaborateEvent()` is called.<br>\- `receiveImage`: event triggered when `sendImage()` is called.  |
| sessionId | number  | Yes   | ID of the collaborative session.   |
| callback | Callback&lt;[EventCallbackInfo](js-apis-distributed-abilityConnectionManager.md#eventcallbackinfo)&gt; | Yes   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.on("collaborateEvent", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session collaborateEvent, sessionId is', callbackInfo.sessionId);
  });

  abilityConnectionManager.on("receiveImage", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session receiveImage, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off

off(type:&nbsp;'collaborateEvent'&nbsp;|&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Unregisters the callback listener for the **collaborateEvent** and **receiveImage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type, which can be:<br>\- `collaborateEvent`: event triggered when `collaborateEvent()` is called.<br>\- `receiveImage`: event triggered when `sendImage()` is called.   |
| sessionId | number  | Yes   | ID of the collaborative session.   |
| callback | Callback&lt;[EventCallbackInfo](js-apis-distributed-abilityConnectionManager.md#eventcallbackinfo)&gt; | No   | Registered callback function.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.off("collaborateEvent", this.sessionId);
  abilityConnectionManager.off("receiveImage", this.sessionId);
  ```

## abilityConnectionManager.sendImage

sendImage(sessionId:&nbsp;number,&nbsp;image:&nbsp;image.PixelMap,&nbsp;quality?:&nbsp;number):&nbsp;Promise&lt;void&gt;

Sends images from one device to another after a connection is successfully established.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| image | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes   | Image information.|
| quality | number | No   | Image compression quality. The value range is [0, 100]. The default value is **30**.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import CameraService from '../model/CameraService';
  import { photoAccessHelper } from '@kit.MediaLibraryKit';
  import { image } from '@kit.ImageKit';
  import { fileIo as fs } from '@kit.CoreFileKit';

  try {
    let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select(photoSelectOptions).then((photoSelectResult) => {
      if (!photoSelectResult) {
        hilog.error(0x0000, 'testTag', 'photoSelectResult = null');
      return;
      }

      let file = fs.openSync(photoSelectResult.photoUris[0], fs.OpenMode.READ_ONLY);
      hilog.info(0x0000, 'testTag', 'file.fd:' + file.fd);

      let imageSourceApi: image.ImageSource = image.createImageSource(file.fd);
      if (imageSourceApi) {
        imageSourceApi.createPixelMap().then((pixelMap) => {
          abilityConnectionManager.sendImage(this.sessionId, pixelMap)
        });
      } else {
        hilog.info(0x0000, 'testTag', 'imageSourceApi is undefined');
      }
    })
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'photoPicker failed with error: ' + JSON.stringify(error));
  }
  ```

## abilityConnectionManager.createStream

createStream(sessionId:&nbsp;number,&nbsp;param:&nbsp;StreamParam):&nbsp;Promise&lt;number&gt;

Creates transport streams to send images and videos from one device to another after a connection is successfully established.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| param | [StreamParam](#streamparam) | Yes   | Transport stream information.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;number&gt; | Promise used to return the result. The number in the promise indicates the creation result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](./errorcode-device-manager.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 32300001      | Only one stream can be created for the current session.|
| 32300003      | Bitrate not supported.|
| 32300004      | Color space not supported.|

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'startStream');
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    let surfaceId = abilityConnectionManager.getSurfaceId(streamId, surfaceParam);
    hilog.info(0x0000, 'testTag', 'surfaceId is'+surfaceId);
    AppStorage.setOrCreate<string>('surfaceId', surfaceId);
    await CameraService.initCamera(surfaceId, 0);
    abilityConnectionManager.startStream(streamId);
  })
  ```

## abilityConnectionManager.setSurfaceId

setSurfaceId(sessionId:&nbsp;number,&nbsp;surfaceId:&nbsp;string,&nbsp;param:&nbsp;SurfaceParam):&nbsp;void

Sets the binding relationship between transport streams and surfaces.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| surfaceId | string | Yes   | Unique ID of the surface.|
| param | [SurfaceParam](#surfaceparam) | Yes   | Surface configuration parameters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'setSurfaceId');
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    let surfaceId = abilityConnectionManager.getSurfaceId(streamId, surfaceParam);
    abilityConnectionManager.setSurfaceId(streamId, surfaceId, surfaceParam);
  })
  ```

## abilityConnectionManager.getSurfaceId

getSurfaceId(sessionId:&nbsp;number,&nbsp;param:&nbsp;SurfaceParam):&nbsp;string

Obtains the unique ID of the surface bound to the specified transport streams.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| param | [SurfaceParam](#surfaceparam) | Yes   | Surface configuration parameters.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| string | Unique ID of the surface.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'getSurfaceId');
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    let surfaceId = abilityConnectionManager.getSurfaceId(streamId, surfaceParam);
  })
  ```

## abilityConnectionManager.updateSurfaceParam

updateSurfaceParam(sessionId:&nbsp;number,&nbsp;param:&nbsp;SurfaceParam):&nbsp;void

Updates the configuration of the surface bound to the specified transport streams.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| param | [SurfaceParam](#surfaceparam) | Yes   | Surface configuration parameters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'updateSurfaceParam');
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    abilityConnectionManager.updateSurfaceParam(streamId, surfaceParam);
  })
  ```

## abilityConnectionManager.destroyStream

destroyStream(sessionId:&nbsp;number):&nbsp;void

Destroys the transport streams after the sending of images and videos is complete.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'destroyStream called');
  abilityConnectionManager.destroyStream(sessionId)
  ```

## abilityConnectionManager.startStream

startStream(sessionId:&nbsp;number):&nbsp;void

Starts transmission of the specified transport streams.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Device Management Error Codes](./errorcode-device-manager.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 32300002      | The stream at the receive end is not started. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'startStream called');
  abilityConnectionManager.startStream(sessionId)
  ```

## abilityConnectionManager.stopStream

stopStream(sessionId:&nbsp;number):&nbsp;void

Stops transmission of the specified transport streams.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'stopStream called');
  abilityConnectionManager.stopStream(sessionId)
  ```

## CollaborateEventInfo

Defines the collaboration event information.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type  | Readable  | Writable  | Mandatory  | Description     |
| -------- | ------ | ---- | ---- | ---- | ------- |
| eventType | [CollaborateEventType](#collaborateeventtype) | Yes   | No   | Yes   | Collaboration event type.|
| eventMsg | string | Yes   | No   | No   | Collaboration event message.|

## StreamParam

Defines stream transmission configuration parameters.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type   | Readable  | Writable  | Mandatory  | Description         |
| -------- | ------ | ---- | ---- | ---- | ----------- |
| name  | string   | Yes   | No   | Yes   |   Name of the transport stream. The name must be the same on the TX end and RX end.|
| role  | [StreamRole](#streamrole)     | Yes   | No   | Yes   |   Stream transmission mode (TX stream or RX stream).|
| bitrate  | number   | Yes   | No   | No   |   Video bit rate (valid only at the TX end).|
| colorSpaceConversionTarget  | [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)     | Yes   | No   | No   |   Target color space for conversion.|

## SurfaceParam

Defines surface configuration parameters.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type  | Readable  | Writable  | Mandatory  | Description     |
| -------- | ------ | ---- | ---- | ---- | ------- |
| width | number | Yes   | No   | Yes   | Encoding width. Set this parameter prior to stream transmission. Once stream transmission starts, the setting cannot be updated until the stream transmission ends. If you need to update the setting, stop stream transmission first.|
| height | number | Yes   | No   | Yes  | Encoding length. Set this parameter prior to stream transmission. Once stream transmission starts, the setting cannot be updated until the stream transmission ends. If you need to update the setting, stop stream transmission first.|
| format | [VideoPixelFormat](#videopixelformat) | Yes   | No   | No   | Video pixel format (valid only at the TX end).|
| rotation | number | Yes   | No   | No   | Video rotation angle.|
| flip | [FlipOptions](#flipoptions) | Yes   | No   | No   | Video flip option.|

## CollaborateEventType

Enumerates collaboration event types.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Value| Description|
| -------- | -------- |
| SEND_FAILURE   | Task sending failure.|
| COLOR_SPACE_CONVERSION_FAILURE | Color space conversion failure.|

## FlipOptions

Enumerates video flip options.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Value| Description|
| -------- | -------- |
| HORIZONTAL   | Horizontal flip.|
| VERTICAL | Vertical flip.|

## StreamRole

Enumerates stream transmission modes.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Value| Description|
| -------- | -------- |
| SOURCE  | TX stream.|
| SINK  | RX stream.|

## VideoPixelFormat

Enumerates video pixel formats.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Value| Description|
| -------- | -------- |
| UNKNOWN   | Unknown pixel format.|
| NV12  | NV12, YUV420 semi-planar format.|
| NV21  | NV21, YUV420 semi-planar format.|
