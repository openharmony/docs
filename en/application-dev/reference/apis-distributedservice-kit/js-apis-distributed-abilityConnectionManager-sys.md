# @ohos.abilityConnectionManager (Cross-Device Connection Management) (System API)

The **abilityConnectionManager** module provides APIs for cross-device connection management. After successful networking between devices (login with the same account and enabling of Bluetooth on the devices), a system application and third-party application can start a [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md) of the same application across the devices. After a connection is successfully established, data can be transmitted across the devices, including strings, [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) byte streams, images, and transport streams.

> **NOTE**
>
> The initial APIs of this module are supported since API version 16. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { abilityConnectionManager } from '@kit.DistributedServiceKit';
```

## abilityConnectionManager.on

on(type:&nbsp;'receiveData'&nbsp;|&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Registers a callback listener for the **receiveData** and **receiveImage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type, which can be:<br>\- `receiveData`: event triggered when **sendData()** is called.<br>\- `receiveImage`: event triggered when **sendImage()** is called.  |
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

  abilityConnectionManager.on("receiveData", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session receiveData, sessionId is', callbackInfo.sessionId);
  });

  abilityConnectionManager.on("receiveImage", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session receiveImage, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off

off(type:&nbsp;'receiveData'&nbsp;|&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

Unregisters the callback listener for the **receiveData** and **receiveImage** events.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                   | Mandatory  | Description   |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | Yes   |   Event type, which can be:<br>\- `receiveData`: event triggered when **sendData()** is called.<br>\- `receiveImage`: event triggered when **sendImage()** is called.   |
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

  abilityConnectionManager.off("receiveData", this.sessionId);
  abilityConnectionManager.off("receiveImage", this.sessionId);
  ```


## abilityConnectionManager.sendData

sendData(sessionId:&nbsp;number,&nbsp;data:&nbsp;ArrayBuffer):&nbsp;Promise&lt;void&gt;;

Sends [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) byte streams from one device to another after a connection is successfully established.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| data | [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) | Yes   | Byte stream information.|

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

  let textEncoder = util.TextEncoder.create("utf-8");
  const arrayBuffer  = textEncoder.encodeInto("data send success");

  abilityConnectionManager.sendData(this.sessionId, arrayBuffer.buffer).then(() => {
    hilog.info(0x0000, 'testTag', "sendMessage success");
  }).catch(() => {
    hilog.info(0x0000, 'testTag', "sendMessage failed");
  })
  ```

## abilityConnectionManager.sendImage

sendImage(sessionId:&nbsp;number,&nbsp;image:&nbsp;image.PixelMap):&nbsp;Promise&lt;void&gt;;

Sends images from one device to another after a connection is successfully established.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

**System API**: This is a system API.

**Parameters**

| Name      | Type                                     | Mandatory  | Description   |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | Yes   | ID of the collaborative session.|
| image | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes   | Image information.|

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

createStream(sessionId:&nbsp;number,&nbsp;param:&nbsp;StreamParam):&nbsp;Promise&lt;number&gt;;

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
| Promise&lt;number&gt; | Promise used to return the result of the number type.|

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

## StreamParam

Stream transmission configuration parameters.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Name      | Type   | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| name  | string   | Yes   | No   |   Name of the transport stream. The name must be the same on the TX end and RX end.|
| role  | [StreamRole](#streamrole)     | Yes   | No   |   Stream transmission mode (TX stream or RX stream).|

## StreamRole

Enumerates stream transmission modes.

**System capability**: SystemCapability.DistributedSched.AppCollaboration

| Value| Description| 
| -------- | -------- |
| SOURCE  | TX stream.| 
| SINK  | RX stream.|
