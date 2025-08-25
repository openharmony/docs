# Interface (AVSessionController)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--SE: @ccfriend-->
<!--TSE: @chenmingxi1_huawei-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 10.

Through the AV session controller, you can query the session ID, send commands and events to a session, and obtain session metadata and playback state information.

## Modules to Import

```ts
import { avSession } from '@kit.AVSessionKit';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type  | Read-Only| Optional| Description                                   |
| :-------- | :----- | :--- | :--- | :-------------------------------------- |
| sessionId<sup>10+</sup> | string | Yes  | No  | Unique session ID of the AVSessionController object.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';

let tag: string = "createNewSession";
let sessionId: string = "";
let AVSessionController: avSession.AVSessionController;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  AVSessionController = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

Obtains the remote playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                                        |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\> | Yes  | Callback used to return the remote playback state.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {
  if (err) {
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('getAVPlaybackState : SUCCESS');
  }
});
```

## getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>

Obtains the remote playback state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                       | Description                                                        |
| --------- | ------------------------------------------------------------ |
| Promise<[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\>  | Promise used to return the remote playback state. |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info('getAVPlaybackState : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getAVMetadata<sup>10+</sup>

getAVMetadata(): Promise\<AVMetadata>

Obtains the session metadata. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[AVMetadata](arkts-apis-avsession-i.md#avmetadata10)\> | Promise used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVMetadata().then((metadata: avSession.AVMetadata) => {
  console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getAVMetadata<sup>10+</sup>

getAVMetadata(callback: AsyncCallback\<AVMetadata>): void

Obtains the session metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVMetadata](arkts-apis-avsession-i.md#avmetadata10)\> | Yes  | Callback used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVMetadata((err: BusinessError, metadata: avSession.AVMetadata) => {
  if (err) {
    console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
  }
});
```

## getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(): Promise\<string>

Obtains the name of the playlist. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type            | Description                          |
| ---------------- | ----------------------------- |
| Promise<string\> | Promise used to return the playlist name.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVQueueTitle().then((title: string) => {
  console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(callback: AsyncCallback\<string>): void

Obtains the name of the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                     |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback<string\> | Yes  | Callback used to return the playlist name.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVQueueTitle((err: BusinessError, title: string) => {
  if (err) {
    console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
  }
});
```

## getAVQueueItems<sup>10+</sup>

getAVQueueItems(): Promise\<Array\<AVQueueItem>>

Obtains the information related to the items in the queue. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                         | Description                          |
| --------------------------------------------- | ----------------------------- |
| Promise<Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\>\> | Promise used to return the items in the queue.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVQueueItems().then((items: avSession.AVQueueItem[]) => {
  console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getAVQueueItems<sup>10+</sup>

getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void

Obtains the information related to the items in the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                | Mandatory| Description                     |
| -------- | --------------------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback<Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\>\> | Yes  | Callback used to return the items in the playlist.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVQueueItems((err: BusinessError, items: avSession.AVQueueItem[]) => {
  if (err) {
    console.error(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
  }
});
```

## skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number): Promise\<void>

Sends the ID of an item in the playlist to the session for processing. The session can play the song. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type   | Mandatory| Description                                       |
| ------ | ------- | ---- | ------------------------------------------- |
| itemId | number  | Yes  | ID of an item in the playlist.|

**Return value**

| Type          | Description                                                            |
| -------------- | --------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the item ID is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let queueItemId = 0;
avsessionController.skipToQueueItem(queueItemId).then(() => {
  console.info('SkipToQueueItem successfully');
}).catch((err: BusinessError) => {
  console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void

Sends the ID of an item in the playlist to the session for processing. The session can play the song. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                                                       |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| itemId   | number                | Yes  | ID of an item in the playlist.               |
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let queueItemId = 0;
avsessionController.skipToQueueItem(queueItemId, (err: BusinessError) => {
  if (err) {
    console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SkipToQueueItem successfully');
  }
});
```

## getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

Obtains the output device information. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)\> | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getOutputDevice().then((deviceInfo: avSession.OutputDeviceInfo) => {
  console.info('GetOutputDevice : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

Obtains the output device information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                          |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)\> | Yes  | Callback used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getOutputDevice((err: BusinessError, deviceInfo: avSession.OutputDeviceInfo) => {
  if (err) {
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('GetOutputDevice : SUCCESS');
  }
});
```

## sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent): Promise\<void>

Sends a key event to the session corresponding to this controller. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                                                        | Mandatory| Description      |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| event  | [KeyEvent](../apis-input-kit/js-apis-keyevent.md) | Yes  | Key event.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 600101  | Session service exception. |
| 600102  | The session does not exist. |
| 600103  | The session controller does not exist. |
| 600105  | Invalid session command. |
| 600106  | The session is not activated. |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the event is sent, no value is returned; otherwise, an error object is returned.|

**Example**

```ts
import { Key, KeyEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyItem: Key = {code:0x49, pressedTime:2, deviceId:0};
let event:KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};


avsessionController.sendAVKeyEvent(event).then(() => {
  console.info('SendAVKeyEvent Successfully');
}).catch((err: BusinessError) => {
  console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

Sends a key event to the session corresponding to this controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description      |
| -------- | ------------------------------------------------------------ | ---- | ---------- |
| event    | [KeyEvent](../apis-input-kit/js-apis-keyevent.md) | Yes  | Key event.|
| callback | AsyncCallback\<void>                                         | Yes  | Callback used to return the result. If the event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 600101  | Session service exception. |
| 600102  | The session does not exist. |
| 600103  | The session controller does not exist. |
| 600105  | Invalid session command. |
| 600106  | The session is not activated. |

**Example**

```ts
import { Key, KeyEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyItem: Key = {code:0x49, pressedTime:2, deviceId:0};
let event:KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};
avsessionController.sendAVKeyEvent(event, (err: BusinessError) => {
  if (err) {
    console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SendAVKeyEvent Successfully');
  }
});
```

## getLaunchAbility<sup>10+</sup>

getLaunchAbility(): Promise\<WantAgent>

Obtains the WantAgent object saved by the application in the session. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)\> | Promise used to return the object saved by calling [setLaunchAbility](arkts-apis-avsession-AVSession.md#setlaunchability10). The object includes the application property, such as the bundle name, ability name, and device ID.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getLaunchAbility().then((agent: object) => {
  console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
}).catch((err: BusinessError) => {
  console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getLaunchAbility<sup>10+</sup>

getLaunchAbility(callback: AsyncCallback\<WantAgent>): void

Obtains the WantAgent object saved by the application in the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)\> | Yes  | Callback used to return the object saved by calling [setLaunchAbility](arkts-apis-avsession-AVSession.md#setlaunchability10). The object includes the application property, such as the bundle name, ability name, and device ID.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getLaunchAbility((err: BusinessError, agent: object) => {
  if (err) {
    console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
  }
});
```

## getRealPlaybackPositionSync<sup>10+</sup>

getRealPlaybackPositionSync(): number

Obtains the playback position.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Playback position, in milliseconds.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
let time: number = avsessionController.getRealPlaybackPositionSync();
```

## isActive<sup>10+</sup>

isActive(): Promise\<boolean>

Checks whether the session is activated. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | Promise used to return the activation state. If the session is activated, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.isActive().then((isActive: boolean) => {
  console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
}).catch((err: BusinessError) => {
  console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## isActive<sup>10+</sup>

isActive(callback: AsyncCallback\<boolean>): void

Checks whether the session is activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<boolean\> | Yes  | Callback used to return the activation state. If the session is activated, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.isActive((err: BusinessError, isActive: boolean) => {
  if (err) {
    console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
  }
});
```

## destroy<sup>10+</sup>

destroy(): Promise\<void>

Destroys this controller. A controller can no longer be used after being destroyed. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the controller is destroyed, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.destroy().then(() => {
  console.info('Destroy : SUCCESS ');
}).catch((err: BusinessError) => {
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

Destroys this controller. A controller can no longer be used after being destroyed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the controller is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.destroy((err: BusinessError) => {
  if (err) {
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Destroy : SUCCESS ');
  }
});
```

## getValidCommands<sup>10+</sup>

getValidCommands(): Promise\<Array\<AVControlCommandType>>

Obtains valid commands supported by the session. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<Array<[AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)\>\> | Promise used to return a set of valid commands.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getValidCommands().then((validCommands: avSession.AVControlCommandType[]) => {
  console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getValidCommands<sup>10+</sup>

getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void

Obtains valid commands supported by the session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)\>\> | Yes  | Callback used to return a set of valid commands.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getValidCommands((err: BusinessError, validCommands: avSession.AVControlCommandType[]) => {
  if (err) {
    console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
  }
});
```

## sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand): Promise\<void>

Sends a control command to the session through the controller. This API uses a promise to return the result.

> **NOTE**
>
> Before using **sendControlCommand**, the controller must ensure that the corresponding listeners are registered for the media session. For details about how to register the listeners, see [on'play'](arkts-apis-avsession-AVSession.md#onplay10), [on'pause'](arkts-apis-avsession-AVSession.md#onpause10), and the like.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVControlCommand](arkts-apis-avsession-i.md#avcontrolcommand10) | Yes  | Command to send.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avCommand: avSession.AVControlCommand = {command:'play'};
avsessionController.sendControlCommand(avCommand).then(() => {
  console.info('SendControlCommand successfully');
}).catch((err: BusinessError) => {
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

Sends a control command to the session through the controller. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Before using **sendControlCommand**, the controller must ensure that the corresponding listeners are registered for the media session. For details about how to register the listeners, see [on'play'](arkts-apis-avsession-AVSession.md#onplay10), [on'pause'](arkts-apis-avsession-AVSession.md#onpause10), and the like.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                          |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVControlCommand](arkts-apis-avsession-i.md#avcontrolcommand10) | Yes  | Command to send.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.                    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avCommand: avSession.AVControlCommand = {command:'play'};
avsessionController.sendControlCommand(avCommand, (err: BusinessError) => {
  if (err) {
    console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SendControlCommand successfully');
  }
});
```

## sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}): Promise\<void>

Sends a custom control command to the session through the controller. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | Yes  | Name of the custom control command.|
| args | {[key: string]: Object} | Yes  | Parameters in key-value pair format carried in the custom control command.|

> **NOTE**
>
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md).

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the command is sent, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';

let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});
let commandName = "my_command";
if (controller !== undefined) {
  (controller as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}).then(() => {
    console.info('SendCommonCommand successfully');
  }).catch((err: BusinessError) => {
    console.error(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

## sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

Sends a custom control command to the session through the controller. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                 | Mandatory| Description                          |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | Yes  | Name of the custom control command.|
| args | {[key: string]: Object} | Yes  | Parameters in key-value pair format carried in the custom control command.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.                    |

> **NOTE**
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
          
let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});
let commandName = "my_command";
if (controller !== undefined) {
  (controller as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}, (err: BusinessError) => {
    if (err) {
      console.error(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}
```

## sendCustomData<sup>20+</sup>

sendCustomData(data: Record\<string, Object>): Promise\<void>

Sends custom data to the remote device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name| Type                  | Mandatory| Description                                                        |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| data   | Record\<string, Object> | Yes  | Custom data filled by the application. Only objects with the key **'customData'** and of the type string are parsed on the server.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist.                                  |
| 6600103  | The session controller does not exist.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
          
let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});

if (controller !== undefined) {
  (controller as avSession.AVSessionController).sendCustomData({customData : "This is my data"})
}
```

## getExtras<sup>10+</sup>

getExtras(): Promise\<{[key: string]: Object}>

Obtains the custom media packet set by the provider. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<{[key: string]: Object}\>   | Promise used to return the custom media packet. The content of the packet is the same as that set in **setExtras**.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
         
let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});
if (controller !== undefined) {
  (controller as avSession.AVSessionController).getExtras().then((extras) => {
    console.info(`getExtras : SUCCESS : ${extras}`);
  }).catch((err: BusinessError) => {
    console.error(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

## getExtras<sup>10+</sup>

getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void

Obtains the custom media packet set by the provider. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<{[key: string]: Object}\> | Yes  | Callback used to return the custom media packet. The content of the packet is the same as that set in **setExtras**.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600107  |Too many commands or events. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';

let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});
if (controller !== undefined) {
  (controller as avSession.AVSessionController).getExtras((err, extras) => {
    if (err) {
      console.error(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`getExtras : SUCCESS : ${extras}`);
    }
  });
}
```

## getExtrasWithEvent<sup>18+</sup>

getExtrasWithEvent(extraEvent: string): Promise\<ExtraInfo>

Obtains the custom media packet set by the remote distributed media provider based on the remote distributed event type. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| extraEvent | string | Yes| Remote distributed event type.<br>Currently, the following event types are supported:<br>**'AUDIO_GET_VOLUME'**: obtains the volume of the remote device.<br>**'AUDIO_GET_AVAILABLE_DEVICES'**: obtains all remote devices that can be connected.<br>**'AUDIO_GET_PREFERRED_OUTPUT_DEVICE_FOR_RENDERER_INFO'**: obtains the actual remote audio device.|

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[ExtraInfo](arkts-apis-avsession-t.md#extrainfo18)\>   | Promise used to return the custom media packet set by the remote distributed media provider.<br>The **ExtraInfo** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md).|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let controller: avSession.AVSessionController | ESObject;
const COMMON_COMMAND_STRING_1 = 'AUDIO_GET_VOLUME';
const COMMON_COMMAND_STRING_2 = 'AUDIO_GET_AVAILABLE_DEVICES';
const COMMON_COMMAND_STRING_3 = 'AUDIO_GET_PREFERRED_OUTPUT_DEVICE_FOR_RENDERER_INFO';
if (controller !== undefined) {
  controller.getExtrasWithEvent(COMMON_COMMAND_STRING_1).then(() => {
    console.info(`${[COMMON_COMMAND_STRING_1]}`);
  }).catch((err: BusinessError) => {
    console.error(`getExtrasWithEvent failed with err: ${err.code}, ${err.message}`);
  })

  controller.getExtrasWithEvent(COMMON_COMMAND_STRING_2).then(() => {
    console.info(`${[COMMON_COMMAND_STRING_2]}`);
  }).catch((err: BusinessError) => {
    console.error(`getExtrasWithEvent failed with err: ${err.code}, ${err.message}`);
  })

  controller.getExtrasWithEvent(COMMON_COMMAND_STRING_3).then(() => {
    console.info(`${[COMMON_COMMAND_STRING_3]}`);
  }).catch((err: BusinessError) => {
    console.error(`getExtrasWithEvent failed with err: ${err.code}, ${err.message}`);
  })
}
```

## on('metadataChange')<sup>10+</sup>

on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)

Subscribes to metadata change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'metadataChange'** is triggered when the session metadata changes.|
| filter   | Array\<keyof&nbsp;[AVMetadata](arkts-apis-avsession-i.md#avmetadata10)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any metadata field change will trigger the event, and **Array<keyof&nbsp;[AVMetadata](arkts-apis-avsession-i.md#avmetadata10)\>** indicates that only changes to the listed metadata field will trigger the event.|
| callback | (data: [AVMetadata](arkts-apis-avsession-i.md#avmetadata10)) => void                    | Yes  | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('metadataChange', 'all', (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

avsessionController.on('metadataChange', ['assetId', 'title', 'description'], (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

```

## off('metadataChange')<sup>10+</sup>

off(type: 'metadataChange', callback?: (data: AVMetadata) => void)

Unsubscribes from metadata change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                              | Mandatory| Description                                                   |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | Yes  | Event type, which is **'metadataChange'** in this case.        |
| callback | (data: [AVMetadata](arkts-apis-avsession-i.md#avmetadata10)) => void        | No  | Callback used for subscription. The **data** parameter in the callback indicates the changed metadata.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('metadataChange');
```

## on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)

Subscribes to playback state change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description     |
| --------| -----------|-----|------------|
| type     | string    | Yes  | Event type. The event **'playbackStateChange'** is triggered when the playback state changes.|
| filter   | Array\<keyof&nbsp;[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any playback state field change will trigger the event, and **Array<keyof&nbsp;[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\>** indicates that only changes to the listed playback state field will trigger the event.|
| callback | (state: [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)) => void       | Yes  | Callback used for subscription. The **state** parameter in the callback indicates the changed playback state.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

avsessionController.on('playbackStateChange', ['state', 'speed', 'loopMode'], (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});
```

## off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)

Unsubscribes from playback state change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'playbackStateChange'** in this case.   |
| callback | (state: [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)) => void         | No  | Callback function, where the **state** parameter indicates the new playback state.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('playbackStateChange');
```

## on('callMetadataChange')<sup>11+</sup>

on(type: 'callMetadataChange', filter: Array\<keyof CallMetadata> | 'all', callback: Callback\<CallMetadata>): void

Subscribes to call metadata change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description     |
| --------| -----------|-----|------------|
| type     | string    | Yes  | Event type. The event **'callMetadataChange'** is triggered when the call metadata changes.|
| filter   | Array\<keyof&nbsp;[CallMetadata](arkts-apis-avsession-i.md#callmetadata11)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any call metadata field change will trigger the event, and **Array<keyof&nbsp;[CallMetadata](arkts-apis-avsession-i.md#callmetadata11)\>** indicates that only changes to the listed metadata field will trigger the event.|
| callback | Callback<[CallMetadata](arkts-apis-avsession-i.md#callmetadata11)\>   | Yes  | Callback used for subscription. The **callmetadata** parameter in the callback indicates the changed call metadata.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('callMetadataChange', 'all', (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.name}`);
});

avsessionController.on('callMetadataChange', ['name'], (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.name}`);
});
```

## off('callMetadataChange')<sup>11+</sup>

off(type: 'callMetadataChange', callback?: Callback\<CallMetadata>): void

Unsubscribes from call metadata change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'callMetadataChange'** in this case.   |
| callback | Callback<[CallMetadata](arkts-apis-avsession-i.md#callmetadata11)\>       | No  | Callback used for unsubscription. The **calldata** parameter in the callback indicates the changed call metadata.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('callMetadataChange');
```

## on('callStateChange')<sup>11+</sup>

on(type: 'callStateChange', filter: Array\<keyof AVCallState> | 'all', callback: Callback\<AVCallState>): void

Subscribes to call state change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description     |
| --------| -----------|-----|------------|
| type     | string    | Yes  | Event type. The event **'callStateChange'** is triggered when the call state changes.|
| filter   | Array<keyof&nbsp;[AVCallState](arkts-apis-avsession-i.md#avcallstate11)\>&nbsp;&#124;&nbsp;'all' | Yes  | The value **'all'** indicates that any call state field change will trigger the event, and **Array<keyof&nbsp;[AVCallState](arkts-apis-avsession-i.md#avcallstate11)\>** indicates that only changes to the listed call state field will trigger the event.|
| callback | Callback<[AVCallState](arkts-apis-avsession-i.md#avcallstate11)\>       | Yes  | Callback function, where the **callstate** parameter indicates the new call state.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('callStateChange', 'all', (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});

avsessionController.on('callStateChange', ['state'], (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});
```

## off('callStateChange')<sup>11+</sup>

off(type: 'callStateChange', callback?: Callback\<AVCallState>): void

Unsubscribes from call state change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'callStateChange'** in this case.   |
| callback | Callback<[AVCallState](arkts-apis-avsession-i.md#avcallstate11)\>           | No  | Callback function, where the **callstate** parameter indicates the new call metadata.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('callMetadataChange');
```

## on('sessionDestroy')<sup>10+</sup>

on(type: 'sessionDestroy', callback: () => void)

Subscribes to session destruction events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description                                                        |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | Yes  | Event type. The event **'sessionDestroy'** is triggered when a session is destroyed.|
| callback | () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                 |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('sessionDestroy', () => {
  console.info('on sessionDestroy : SUCCESS ');
});
```

## off('sessionDestroy')<sup>10+</sup>

off(type: 'sessionDestroy', callback?: () => void)

Unsubscribes from session destruction events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type      | Mandatory| Description                                                     |
| -------- | ---------- | ---- | ----------------------------------------------------- |
| type     | string     | Yes  | Event type, which is **'sessionDestroy'** in this case.        |
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('sessionDestroy');
```

## on('activeStateChange')<sup>10+</sup>

on(type: 'activeStateChange', callback: (isActive: boolean) => void)

Subscribes to session activation state change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                      | Yes  | Event type. The event **'activeStateChange'** is triggered when the activation state of the session changes.|
| callback | (isActive: boolean) => void | Yes  | Callback used for subscription. The **isActive** parameter in the callback specifies whether the session is activated. The value **true** means that the service is activated, and **false** means the opposite.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ----------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  |The session controller does not exist. |

**Example**

```ts
avsessionController.on('activeStateChange', (isActive: boolean) => {
  console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);
});
```

## off('activeStateChange')<sup>10+</sup>

off(type: 'activeStateChange', callback?: (isActive: boolean) => void)

Unsubscribes from session activation state change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                     |
| -------- | --------------------------- | ---- | ----------------------------------------------------- |
| type     | string                      | Yes  | Event type, which is **'activeStateChange'** in this case.     |
| callback | (isActive: boolean) => void | No  | Callback used for unsubscription. The **isActive** parameter in the callback specifies whether the session is activated. The value **true** means that the session is activated, and **false** means the opposite.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('activeStateChange');
```

## on('validCommandChange')<sup>10+</sup>

on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)

Subscribes to valid command change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'validCommandChange'** is triggered when the valid commands supported by the session changes.|
| callback | (commands: Array<[AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)\>) => void | Yes  | Callback used for subscription. The **commands** parameter in the callback is a set of valid commands.                    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('validCommandChange', (validCommands: avSession.AVControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

## off('validCommandChange')<sup>10+</sup>

off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)

Unsubscribes from valid command change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'validCommandChange'** in this case.        |
| callback | (commands: Array<[AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)\>) => void | No  | Callback used for unsubscription. The **commands** parameter in the callback is a set of valid commands.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message          |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('validCommandChange');
```

## on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Subscribes to output device change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is triggered when the output device changes.|
| callback | (state: [ConnectionState](arkts-apis-avsession-e.md#connectionstate10), device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | Yes  | Callback used for subscription. The **device** parameter in the callback indicates the output device information.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ----------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange state: ${state}, device : ${device}`);
});
```

## off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Unsubscribes from output device change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                     |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | Yes  | Event type, which is **'outputDeviceChange'** in this case.     |
| callback | (state: [ConnectionState](arkts-apis-avsession-e.md#connectionstate10), device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | No  | Callback function, where the **device** parameter specifies the output device information.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID | Error Message         |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('outputDeviceChange');
```

## on('sessionEvent')<sup>10+</sup>

on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key: string]: Object}) => void): void

Subscribes to session event change events. This API is called by the controller.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'sessionEvent'** is triggered when the session event changes.|
| callback | (sessionEvent: string, args: {[key: string]: Object}) => void         | Yes  | Callback used for subscription. **sessionEvent** in the callback indicates the name of the session event that changes, and **args** indicates the parameters carried in the event.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
       
let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});
if (controller !== undefined) {
  (controller as avSession.AVSessionController).on('sessionEvent', (sessionEvent, args) => {
    console.info(`OnSessionEvent, sessionEvent is ${sessionEvent}, args: ${JSON.stringify(args)}`);
  });
}
```

## off('sessionEvent')<sup>10+</sup>

off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key: string]: Object}) => void): void

Unsubscribes from session events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'sessionEvent'** in this case.   |
| callback | (sessionEvent: string, args: {[key: string]: Object}) => void         | No  | Callback used for unsubscription. **sessionEvent** in the callback indicates the name of the session event that changes, and **args** indicates the parameters carried in the event.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('sessionEvent');
```

## on('queueItemsChange')<sup>10+</sup>

on(type: 'queueItemsChange', callback: (items: Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\>) => void): void

Subscribes to playlist item change events. This API is called by the controller.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                  | Mandatory| Description                                                                        |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| type     | string                                                | Yes  | Event type. The event **'queueItemsChange'** is triggered when one or more items in the playlist changes.|
| callback | (items: Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\>) => void  | Yes  | Callback used for subscription. The **items** parameter in the callback indicates the changed items in the playlist.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('queueItemsChange', (items: avSession.AVQueueItem[]) => {
  console.info(`OnQueueItemsChange, items length is ${items.length}`);
});
```

## off('queueItemsChange')<sup>10+</sup>

off(type: 'queueItemsChange', callback?: (items: Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\>) => void): void

Unsubscribes from playback item change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                                | Mandatory| Description                                                                                               |
| -------- | ---------------------------------------------------- | ---- | --------------------------------------------------------------------------------------------------- |
| type     | string                                               | Yes  | Event type, which is **'queueItemsChange'** in this case.                                                    |
| callback | (items: Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\>) => void | No  | Callback used for unsubscription. The **items** parameter in the callback indicates the changed items in the playlist.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('queueItemsChange');
```

## on('queueTitleChange')<sup>10+</sup>

on(type: 'queueTitleChange', callback: (title: string) => void): void

Subscribes to playlist name change events. This API is called by the controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                                            |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The event **'queueTitleChange'** is triggered when the playlist name changes.|
| callback | (title: string) => void | Yes  | Callback used for subscription. The **title** parameter in the callback indicates the changed playlist name.                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.on('queueTitleChange', (title: string) => {
  console.info(`queueTitleChange, title is ${title}`);
});
```

## off('queueTitleChange')<sup>10+</sup>

off(type: 'queueTitleChange', callback?: (title: string) => void): void

Unsubscribes from playlist name change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                   | Mandatory| Description                                                                                                   |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type, which is **'queueTitleChange'** in this case.                                                        |
| callback | (title: string) => void | No  | Callback used for unsubscription. The **items** parameter in the callback indicates the changed playlist name.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('queueTitleChange');
```

## on('extrasChange')<sup>10+</sup>

on(type: 'extrasChange', callback: (extras: {[key: string]: Object}) => void): void

Subscribes to custom media packet change events. This API is called by the controller.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The event **'extrasChange'** is triggered when the provider sets a custom media packet.|
| callback | (extras: {[key: string]: Object}) => void         | Yes  | Callback used for subscription. The **extras** parameter in the callback indicates the custom media packet set by the provider. This packet is the same as that set in **dispatchSessionEvent**.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';

let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});
if (controller !== undefined) {
  (controller as avSession.AVSessionController).on('extrasChange', (extras) => {
    console.info(`Caught extrasChange event,the new extra is: ${JSON.stringify(extras)}`);
  });
}
```

## off('extrasChange')<sup>10+</sup>

off(type: 'extrasChange', callback?: (extras: {[key: string]: Object}) => void): void

Unsubscribes from custom media packet change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                   | Mandatory| Description                                                                                                   |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type, which is **'extrasChange'** in this case.                                                        |
| callback | (extras: {[key: string]: Object}) => void | No  | Callback used for unsubscription.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ----------------                       |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
avsessionController.off('extrasChange');
```

## on('customDataChange')<sup>20+</sup>

on(type: 'customDataChange', callback: Callback\<Record\<string, Object>>): void

Subscribes to events indicating that custom data is sent to a remote device.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | Yes  | Event type. The event **'customDataChange'** is triggered when the provider sends custom data.|
| callback | Callback\<Record\<string, Object>> | Yes  | Callback used to receive the custom data.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';

let tag: string = "createNewSession";
let sessionId: string = "";
let controller:avSession.AVSessionController | undefined = undefined;
avSession.createAVSession(context, tag, "audio").then(async (data:avSession.AVSession)=> {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  controller = await currentAVSession.getController();
  console.info('CreateAVSession : SUCCESS :sessionid = ${sessionid}');
}).catch((err: BusinessError) => {
  console.error('CreateAVSession BusinessError:code: ${err.code}, message: ${err.message}')
});
if (controller !== undefined) {
  (controller as avSession.AVSessionController).on('customDataChange', (callback) => {
    console.info(`Caught customDataChange event,the new callback is: ${JSON.stringify(callback)}`);
  });
}
```

## off('customDataChange')<sup>20+</sup>

off(type: 'customDataChange', callback?: Callback\<Record\<string, Object>>): void

Unsubscribes from events indicating that custom data is sent to a remote device.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                             | Yes  | Event type, which is **'customDataChange'** in this case.        |
| callback | Callback\<Record\<string, Object>> | No  | Callback used for unsubscription. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist.                       |

**Example**

```ts
avsessionController.off('customDataChange');
```

## getAVPlaybackStateSync<sup>10+</sup>

getAVPlaybackStateSync(): AVPlaybackState;

Obtains the playback state of this session. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                       | Description                                                        |
| --------- | ------------------------------------------------------------ |
| [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)  | Playback state of the session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let playbackState: avSession.AVPlaybackState = avsessionController.getAVPlaybackStateSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAVPlaybackStateSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## getAVMetadataSync<sup>10+</sup>

getAVMetadataSync(): AVMetadata

Obtains the session metadata. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| [AVMetadata](arkts-apis-avsession-i.md#avmetadata10) | Session metadata.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let metaData: avSession.AVMetadata = avsessionController.getAVMetadataSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAVMetadataSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## getAVCallState<sup>11+</sup>

getAVCallState(): Promise\<AVCallState>

Obtains the call state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[AVCallState](arkts-apis-avsession-i.md#avcallstate11)\> | Promise used to return the call state obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVCallState().then((callstate: avSession.AVCallState) => {
  console.info(`getAVCallState : SUCCESS : state : ${callstate.state}`);
}).catch((err: BusinessError) => {
  console.error(`getAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getAVCallState<sup>11+</sup>

getAVCallState(callback: AsyncCallback\<AVCallState>): void

Obtains the call state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVCallState](arkts-apis-avsession-i.md#avcallstate11)\> | Yes  | Callback used to return the call state obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVCallState((err: BusinessError, callstate: avSession.AVCallState) => {
  if (err) {
    console.error(`getAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getAVCallState : SUCCESS : state : ${callstate.state}`);
  }
});
```

## getCallMetadata<sup>11+</sup>

getCallMetadata(): Promise\<CallMetadata>

Obtains the call metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[CallMetadata](arkts-apis-avsession-i.md#callmetadata11)\> | Promise used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getCallMetadata().then((calldata: avSession.CallMetadata) => {
  console.info(`getCallMetadata : SUCCESS : name : ${calldata.name}`);
}).catch((err: BusinessError) => {
  console.error(`getCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getCallMetadata<sup>11+</sup>

getCallMetadata(callback: AsyncCallback\<CallMetadata>): void

Obtains the call metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[CallMetadata](arkts-apis-avsession-i.md#callmetadata11)\> | Yes  | Callback used to return the metadata obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getCallMetadata((err: BusinessError, calldata: avSession.CallMetadata) => {
  if (err) {
    console.error(`getCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getCallMetadata : SUCCESS : name : ${calldata.name}`);
  }
});
```

## getAVQueueTitleSync<sup>10+</sup>

getAVQueueTitleSync(): string

Obtains the name of the playlist of this session. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type            | Description                          |
| ---------------- | ----------------------------- |
| string | Playlist name.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let currentQueueTitle: string = avsessionController.getAVQueueTitleSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAVQueueTitleSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## getAVQueueItemsSync<sup>10+</sup>

getAVQueueItemsSync(): Array\<AVQueueItem\>

Obtains the information related to the items in the playlist of this session. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                         | Description                          |
| --------------------------------------------- | ----------------------------- |
| Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\> | Items in the queue.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let currentQueueItems: Array<avSession.AVQueueItem> = avsessionController.getAVQueueItemsSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAVQueueItemsSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

Obtains the output device information. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                           | Description                             |
| ----------------------------------------------- | --------------------------------- |
| [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10) | Information about the output device.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let currentOutputDevice: avSession.OutputDeviceInfo = avsessionController.getOutputDeviceSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOutputDeviceSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## isActiveSync<sup>10+</sup>

isActiveSync(): boolean

Checks whether the session is activated. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| boolean | Returns **true** is returned if the session is activated; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isActive: boolean = avsessionController.isActiveSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`isActiveSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## getValidCommandsSync<sup>10+</sup>

getValidCommandsSync(): Array\<AVControlCommandType\>

Obtains valid commands supported by the session. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Array<[AVControlCommandType](arkts-apis-avsession-t.md#avcontrolcommandtype10)\> | A set of valid commands.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let validCommands: Array<avSession.AVControlCommandType> = avsessionController.getValidCommandsSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getValidCommandsSync error, error code: ${error.code}, error message: ${error.message}`);
}
```
