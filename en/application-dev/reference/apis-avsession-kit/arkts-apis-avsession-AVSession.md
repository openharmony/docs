# Interface (AVSession)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 10.

An AVSession object is created by calling [avSession.createAVSession](arkts-apis-avsession-f.md#avsessioncreateavsession10). The object enables you to obtain the session ID and set the metadata and playback state. 

## Modules to Import

```ts
import { avSession } from '@kit.AVSessionKit';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

| Name     | Type  | Read-Only| Optional| Description                         |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId<sup>10+</sup> | string | Yes  | No  | Unique session ID of the AVSession object.|
| sessionType<sup>10+</sup> | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10) | Yes  | No  | AVSession type.|

**Example**

```ts
let sessionId: string = currentAVSession.sessionId;
let sessionType: avSession.AVSessionType = currentAVSession.sessionType;
```

## setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata): Promise\<void>

Sets session metadata. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                     | Mandatory| Description        |
| ------ | ------------------------- | ---- | ------------ |
| data   | [AVMetadata](arkts-apis-avsession-i.md#avmetadata10) | Yes  | Session metadata.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let metadata: avSession.AVMetadata = {
  assetId: "121278",
  title: "lose yourself",
  artist: "Eminem",
  author: "ST",
  album: "Slim shady",
  writer: "ST",
  composer: "ST",
  duration: 2222,
  mediaImage: "https://www.example.com/example.jpg",
  subtitle: "8 Mile",
  description: "Rap",
  // The LRC contains two types of elements: time tag + lyrics, and ID tag.
  // Example: [00:25.44]xxx\r\n[00:26.44]xxx\r\n
  lyric: "Lyrics in LRC format",
  // The singleLyricText field stores a single line of lyric text without timestamps.
  // Example: "Content of a single lyric line"
  singleLyricText: "Content of a single lyric line",
  previousAssetId: "121277",
  nextAssetId: "121279"
};
currentAVSession.setAVMetadata(metadata).then(() => {
  console.info('SetAVMetadata successfully');
}).catch((err: BusinessError) => {
  console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void

Sets session metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                 |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [AVMetadata](arkts-apis-avsession-i.md#avmetadata10) | Yes  | Session metadata.                         |
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let metadata: avSession.AVMetadata = {
  assetId: "121278",
  title: "lose yourself",
  artist: "Eminem",
  author: "ST",
  album: "Slim shady",
  writer: "ST",
  composer: "ST",
  duration: 2222,
  mediaImage: "https://www.example.com/example.jpg",
  subtitle: "8 Mile",
  description: "Rap",
  // The LRC contains two types of elements: time tag + lyrics, and ID tag.
  // Example: [00:25.44]xxx\r\n[00:26.44]xxx\r\n
  lyric: "Lyrics in LRC format",
  // The singleLyricText field stores a single line of lyric text without timestamps.
  // Example: "Content of a single lyric line"
  singleLyricText: "Content of a single lyric line",
  previousAssetId: "121277",
  nextAssetId: "121279"
};
currentAVSession.setAVMetadata(metadata, (err: BusinessError) => {
  if (err) {
    console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SetAVMetadata successfully');
  }
});
```

## setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata): Promise\<void>

Sets call metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                     | Mandatory| Description        |
| ------ | ------------------------- | ---- | ------------ |
| data   | [CallMetadata](arkts-apis-avsession-i.md#callmetadata11) | Yes  | Call metadata.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

let value = await resourceManager.getSysResourceManager().getRawFileContent('IMAGE_URI');
    let imageSource = await image.createImageSource(value.buffer);
    let imagePixel = await imageSource.createPixelMap({desiredSize:{width: 150, height: 150}});
    let calldata: avSession.CallMetadata = {
      name: "xiaoming",
      phoneNumber: "111xxxxxxxx",
      avatar: imagePixel
    };
currentAVSession.setCallMetadata(calldata).then(() => {
  console.info('setCallMetadata successfully');
}).catch((err: BusinessError) => {
  console.error(`setCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata, callback: AsyncCallback\<void>): void

Sets call metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                 |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [CallMetadata](arkts-apis-avsession-i.md#callmetadata11) | Yes  | Call metadata.                         |
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function setCallMetadata() {
  let value = await resourceManager.getSysResourceManager().getRawFileContent('IMAGE_URI');
  let imageSource = await image.createImageSource(value.buffer);
  let imagePixel = await imageSource.createPixelMap({desiredSize:{width: 150, height: 150}});
  let calldata: avSession.CallMetadata = {
    name: "xiaoming",
    phoneNumber: "111xxxxxxxx",
    avatar: imagePixel
  };
  currentAVSession.setCallMetadata(calldata, (err: BusinessError) => {
    if (err) {
      console.error(`setCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('setCallMetadata successfully');
    }
  });
}
```

## setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState): Promise\<void>

Sets the call state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                     | Mandatory| Description        |
| ------ | ------------------------- | ---- | ------------ |
| state   | [AVCallState](arkts-apis-avsession-i.md#avcallstate11) | Yes  | Call state.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let calldata: avSession.AVCallState = {
  state: avSession.CallState.CALL_STATE_ACTIVE,
  muted: false
};
currentAVSession.setAVCallState(calldata).then(() => {
  console.info('setAVCallState successfully');
}).catch((err: BusinessError) => {
  console.error(`setAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState, callback: AsyncCallback\<void>): void

Sets the call state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                 |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state     | [AVCallState](arkts-apis-avsession-i.md#avcallstate11) | Yes  | Call state.                         |
| callback | AsyncCallback\<void>      | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avcalldata: avSession.AVCallState = {
  state: avSession.CallState.CALL_STATE_ACTIVE,
  muted: false
};
currentAVSession.setAVCallState(avcalldata, (err: BusinessError) => {
  if (err) {
    console.error(`setAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('setAVCallState successfully');
  }
});
```

## setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState): Promise\<void>

Sets information related to the session playback state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name| Type                               | Mandatory| Description                                          |
| ------ | ----------------------------------- | ---- | ---------------|
| state   | [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10) | Yes  | Information related to the session playback state.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let playbackState: avSession.AVPlaybackState = {
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
  speed: 1.0,
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},
  bufferedTime:1000,
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
  isFavorite:true
};
currentAVSession.setAVPlaybackState(playbackState).then(() => {
  console.info('SetAVPlaybackState successfully');
}).catch((err: BusinessError) => {
  console.error(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void

Sets information related to the session playback state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                          |
| -------- | ----------------------------------- | ---- | ---------------|
| state     | [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10) | Yes  | Information related to the session playback state.|
| callback | AsyncCallback\<void>                | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let PlaybackState: avSession.AVPlaybackState = {
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
  speed: 1.0,
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},
  bufferedTime:1000,
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
  isFavorite:true
};
currentAVSession.setAVPlaybackState(PlaybackState, (err: BusinessError) => {
  if (err) {
    console.error(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SetAVPlaybackState successfully');
  }
});
```

## setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent): Promise\<void>

Sets a launcher ability. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description    |
| ------- | --------------| ---- | ----------------------------|
| ability | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes  | Application properties, such as the bundle name, ability name, and deviceID.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgentInfo object.
let wantAgentInfo: wantAgent.WantAgentInfo = {
  wants: [
    {
      deviceId: "deviceId",
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility",
      action: "action1",
      entities: ["entity1"],
      type: "MIMETYPE",
      uri: "key = {true,true,false}",
      parameters:
        {
          mykey0: 2222,
          mykey1: [1, 2, 3],
          mykey2: "[1, 2, 3]",
          mykey3: "ssssssssssssssssssssssssss",
          mykey4: [false, true, false],
          mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
          mykey6: true
        }
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentAVSession.setLaunchAbility(agent).then(() => {
    console.info('SetLaunchAbility successfully');
  }).catch((err: BusinessError) => {
    console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
  });
});
```

## setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void

Sets a launcher ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description    |
| -------- | --------------| ---- | --------- |
| ability  | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes  | Application properties, such as the bundle name, ability name, and deviceID. |
| callback | AsyncCallback\<void>                          | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgentInfo object.
let wantAgentInfo: wantAgent.WantAgentInfo = {
  wants: [
    {
      deviceId: "deviceId",
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility",
      action: "action1",
      entities: ["entity1"],
      type: "MIMETYPE",
      uri: "key = {true,true,false}",
      parameters:
        {
          mykey0: 2222,
          mykey1: [1, 2, 3],
          mykey2: "[1, 2, 3]",
          mykey3: "ssssssssssssssssssssssssss",
          mykey4: [false, true, false],
          mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
          mykey6: true
        }
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentAVSession.setLaunchAbility(agent, (err: BusinessError) => {
    if (err) {
      console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('SetLaunchAbility successfully');
    }
  });
});
```

## dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>

Dispatches a custom event in the session, including the event name and event content in key-value pair format. This API uses a promise to return the result. It is called by the provider.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description    |
| ------- | --------------| ---- | ----------------------------|
| event | string | Yes  | Name of the session event.|
| args | {[key: string]: Object} | Yes  | Content of the session event.|

> **NOTE**
> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md).

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(()=>{
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context: Context = this.getUIContext().getHostContext() as Context;

            avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
            if (err) {
                console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
                currentAVSession = data;
            }
            });
            let eventName = "dynamic_lyric";
            if (currentAVSession !== undefined) {
            (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}).then(() => {
                console.info('dispatchSessionEvent successfully');
            }).catch((err: BusinessError) => {
                console.error(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
            })
            }
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

Dispatches a custom event in the session, including the event name and event content in key-value pair format. This API uses an asynchronous callback to return the result. It is called by the provider.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description    |
| ------- | --------------| ---- | ----------------------------|
| event | string | Yes  | Name of the session event.|
| args | {[key: string]: Object} | Yes  | Content of the session event.|
| callback | AsyncCallback\<void>                          | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

> **NOTE**

> The **args** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(()=>{
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context: Context = this.getUIContext().getHostContext() as Context;

            avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
            if (err) {
                console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
                currentAVSession = data;
            }
            });
            let eventName: string = "dynamic_lyric";
            if (currentAVSession !== undefined) {
            (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}, (err: BusinessError) => {
                if (err) {
                console.error(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
                }
            })
            }
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>): Promise\<void>

Sets a playlist. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                | Mandatory| Description                              |
| ------ | ------------------------------------ | ---- | ---------------------------------- |
| items  | Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\> | Yes  | Playlist to set.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function setAVQueueItems() {
  let value = await resourceManager.getSysResourceManager().getRawFileContent('IMAGE_URI');
  let imageSource = await image.createImageSource(value.buffer);
  let imagePixel = await imageSource.createPixelMap({desiredSize:{width: 150, height: 150}});
  let queueItemDescription_1: avSession.AVMediaDescription = {
    assetId: '001',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    mediaImage : imagePixel,
    extras: {extras:'any'}
  };
  let queueItem_1: avSession.AVQueueItem = {
    itemId: 1,
    description: queueItemDescription_1
  };
  let queueItemDescription_2: avSession.AVMediaDescription = {
    assetId: '002',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    mediaImage: imagePixel,
    extras: {extras:'any'}
  };
  let queueItem_2: avSession.AVQueueItem = {
    itemId: 2,
    description: queueItemDescription_2
  };
  let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];
  currentAVSession.setAVQueueItems(queueItemsArray).then(() => {
    console.info('SetAVQueueItems successfully');
  }).catch((err: BusinessError) => {
    console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

## setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>, callback: AsyncCallback\<void>): void

Sets a playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description    |
| -------- | ------------------------------------ | ---- | ----------------------------|
| items    | Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\> | Yes  | Playlist to set.                         |
| callback | AsyncCallback\<void>                 | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function setAVQueueItems() {
  let value = await resourceManager.getSysResourceManager().getRawFileContent('IMAGE_URI');
  let imageSource = await image.createImageSource(value.buffer);
  let imagePixel = await imageSource.createPixelMap({desiredSize:{width: 150, height: 150}});
  let queueItemDescription_1: avSession.AVMediaDescription = {
    assetId: '001',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    mediaImage : imagePixel,
    extras: {extras:'any'}
  };
  let queueItem_1: avSession.AVQueueItem = {
    itemId: 1,
    description: queueItemDescription_1
  };
  let queueItemDescription_2: avSession.AVMediaDescription = {
    assetId: '002',
    title: 'music_name',
    subtitle: 'music_sub_name',
    description: 'music_description',
    mediaImage: imagePixel,
    extras: {extras:'any'}
  };
  let queueItem_2: avSession.AVQueueItem = {
    itemId: 2,
    description: queueItemDescription_2
  };
  let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];
  currentAVSession.setAVQueueItems(queueItemsArray, (err: BusinessError) => {
    if (err) {
      console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('SetAVQueueItems successfully');
    }
  });
}
```

## setAVQueueTitle<sup>10+</sup>

setAVQueueTitle(title: string): Promise\<void>

Sets a name for the playlist. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| title  | string | Yes  | Name of the playlist.|

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let queueTitle = 'QUEUE_TITLE';
currentAVSession.setAVQueueTitle(queueTitle).then(() => {
  console.info('SetAVQueueTitle successfully');
}).catch((err: BusinessError) => {
  console.error(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## setAVQueueTitle<sup>10+</sup>

setAVQueueTitle(title: string, callback: AsyncCallback\<void>): void

Sets a name for the playlist. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description    |
| -------- | --------------------- | ---- | ----------------------------|
| title    | string                | Yes  | Name of the playlist.                         |
| callback | AsyncCallback\<void>  | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let queueTitle = 'QUEUE_TITLE';
currentAVSession.setAVQueueTitle(queueTitle, (err: BusinessError) => {
  if (err) {
    console.error(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SetAVQueueTitle successfully');
  }
});
```

## setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}): Promise\<void>

Sets a custom media packet in the form of key-value pairs. This API uses a promise to return the result. It is called by the provider.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description    |
| ------- | --------------| ---- | ----------------------------|
| extras | {[key: string]: Object} | Yes  | Key-value pairs of the custom media packet.|

> **NOTE**

> The **extras** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md).

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the setting is successful, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(() => {
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context: Context = this.getUIContext().getHostContext() as Context;

            avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
              if (err) {
                console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
              } else {
                currentAVSession = data;
                if (currentAVSession !== undefined) {
                  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}).then(() => {
                      console.info('setExtras successfully');
                  }).catch((err: BusinessError) => {
                      console.error(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
                  })
                }
              }
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void

Sets a custom media packet in the form of key-value pairs. This API uses an asynchronous callback to return the result. It is called by the provider.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name | Type                                         | Mandatory| Description    |
| ------- | --------------| ---- | ----------------------------|
| extras | {[key: string]: Object} | Yes  | Key-value pairs of the custom media packet.|
| callback | AsyncCallback\<void>                          | Yes  | Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

> **NOTE**

> The **extras** parameter supports the following data types: string, number, Boolean, object, array, and file descriptor. For details, see [@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md).

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(()=>{
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context: Context = this.getUIContext().getHostContext() as Context;

            avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
            if (err) {
                console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
                currentAVSession = data;
            }
            });
            if (currentAVSession !== undefined) {
            (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}, (err: BusinessError) => {
                if (err) {
                console.error(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
                }
            })
            }
          })
      }
    .width('100%')
    .height('100%')
  }
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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600102  | The session does not exist.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(()=>{
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context: Context = this.getUIContext().getHostContext() as Context;

            avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
            if (err) {
                console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
                currentAVSession = data;
            }
            });
            if (currentAVSession !== undefined) {
            (currentAVSession as avSession.AVSession).sendCustomData({customData : "This is custom data"}).then(() => {
                console.info('sendCustomData successfully');
            }).catch((err: BusinessError) => {
                console.error(`sendCustomData BusinessError: code: ${err.code}, message: ${err.message}`);
            })
            }
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## getController<sup>10+</sup>

getController(): Promise\<AVSessionController>

Obtains the controller corresponding to this session. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                                | Description                         |
| ---------------------| ----------------------------- |
| Promise<[AVSessionController](arkts-apis-avsession-AVSessionController.md)> | Promise used to return the session controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';
  build() {
    Column() {
      Text(this.message)
        .onClick(async ()=>{
          try {
            let context: Context = this.getUIContext().getHostContext() as Context;
            let currentAVSession: avSession.AVSession = await avSession.createAVSession(context, 'SESSION_NAME', 'audio');
            let avSessionController: avSession.AVSessionController;
            currentAVSession.getController().then((avController: avSession.AVSessionController) => {
              avsessionController = avController;
              console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
            }).catch((err: BusinessError) => {
              console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
            });
          } catch (err) {
            if (err) {
              console.error(`AVSession create Error: ${JSON.stringify(err)}`);
            }
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## getController<sup>10+</sup>

getController(callback: AsyncCallback\<AVSessionController>): void

Obtains the controller corresponding to this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type    | Mandatory| Description                      |
| -------- | ----------------------------| ---- | -------------------------- |
| callback | AsyncCallback<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\> | Yes  | Callback used to return the session controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { avSession } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          let context: Context = this.getUIContext().getHostContext() as Context;
          let currentAVSession: avSession.AVSession = await avSession.createAVSession(context, 'SESSION_NAME', 'audio');
          let avsessionController: avSession.AVSessionController;
          currentAVSession.getController((err: BusinessError, avcontroller: avSession.AVSessionController) => {
            if (err) {
              console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
              avsessionController = avcontroller;
              console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
            }
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## getAVCastController<sup>10+</sup>

getAVCastController(): Promise\<AVCastController>

Obtains the cast controller when a casting connection is set up. This API uses a promise to return the result. If the session is not in the cast state, the controller returns **null**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Return value**

| Type    | Description    |
| --------- | --------- |
| Promise<[AVCastController](arkts-apis-avsession-AVCastController.md)\>  | Promise used to return the cast controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | --------------------------------------- |
| 6600102| The session does not exist.           |
| 6600109| The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let aVCastController: avSession.AVCastController;
currentAVSession.getAVCastController().then((avcontroller: avSession.AVCastController) => {
  aVCastController = avcontroller;
  console.info('getAVCastController : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getAVCastController<sup>10+</sup>

getAVCastController(callback: AsyncCallback\<AVCastController>): void

Obtains the cast controller when a casting connection is set up. This API uses an asynchronous callback to return the result. If the session is not in the cast state, the controller returns **null**.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name   | Type    | Mandatory| Description    |
| --------- | ----------------------------| ---- | --------- |
| callback  | AsyncCallback<[AVCastController](arkts-apis-avsession-AVCastController.md)\> | Yes  | Callback used to return the cast controller.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message                                 |
| -------- |---------------------------------------|
| 6600102| The session does not exist.           |
| 6600109| The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let aVCastController: avSession.AVCastController;
currentAVSession.getAVCastController((err: BusinessError, avcontroller: avSession.AVCastController) => {
  if (err) {
    console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    aVCastController = avcontroller;
    console.info('getAVCastController : SUCCESS');
  }
});
```

## getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

Obtains information about the output device for this session. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                          | Description                             |
| ---------------| --------------------------------- |
| Promise<[OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)> | Promise used to return the output device information.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.getOutputDevice().then((outputDeviceInfo: avSession.OutputDeviceInfo) => {
  console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
})
```

## getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

Obtains information about the output device for this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                          |
| -------- | ----------------------| ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)\> | Yes  | Callback used to return the information obtained.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.getOutputDevice((err: BusinessError, outputDeviceInfo: avSession.OutputDeviceInfo) => {
  if (err) {
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);
  }
});
```

## activate<sup>10+</sup>

activate(): Promise\<void>

Activates this session. A session can be used only after being activated. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the session is activated, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.activate().then(() => {
  console.info('Activate : SUCCESS ');
}).catch((err: BusinessError) => {
  console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## activate<sup>10+</sup>

activate(callback: AsyncCallback\<void>): void

Activates this session. A session can be used only after being activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the session is activated, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.activate((err: BusinessError) => {
  if (err) {
    console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Activate : SUCCESS ');
  }
});
```

## deactivate<sup>10+</sup>

deactivate(): Promise\<void>

Deactivates this session. You can use [activate](#activate10) to activate the session again. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the session is deactivated, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.deactivate().then(() => {
  console.info('Deactivate : SUCCESS ');
}).catch((err: BusinessError) => {
  console.error(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## deactivate<sup>10+</sup>

deactivate(callback: AsyncCallback\<void>): void

Deactivates this session. This API uses an asynchronous callback to return the result.

Deactivates this session. You can use [activate](#activate10) to activate the session again.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the session is deactivated, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.deactivate((err: BusinessError) => {
  if (err) {
    console.error(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Deactivate : SUCCESS ');
  }
});
```

## destroy<sup>10+</sup>

destroy(): Promise\<void>

Destroys this session. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If the session is destroyed, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.destroy().then(() => {
  console.info('Destroy : SUCCESS ');
}).catch((err: BusinessError) => {
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

Destroys this session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the session is destroyed, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.destroy((err: BusinessError) => {
  if (err) {
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Destroy : SUCCESS ');
  }
});
```

## on('play')<sup>10+</sup>

on(type: 'play', callback: () => void): void

Subscribes to play command events. The subscription means that the application supports the play command.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'play'** is triggered when the command for starting playback is sent to the session.|
| callback | () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.                                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('play', () => {
  console.info('on play entry');
});
```

## on('pause')<sup>10+</sup>

on(type: 'pause', callback: () => void): void

Subscribes to pause command events. The subscription means that the application supports the pause command.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'pause'** is triggered when the command for pausing the playback is sent to the session.|
| callback | () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('pause', () => {
  console.info('on pause entry');
});
```

## on('stop')<sup>10+</sup>

on(type:'stop', callback: () => void): void

Subscribes to stop command events. The subscription means that the application supports the stop command.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'stop'** is triggered when the command for stopping the playback is sent to the session.|
| callback | () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('stop', () => {
  console.info('on stop entry');
});
```

## on('playNext')<sup>10+</sup>

on(type:'playNext', callback: () => void): void

Subscribes to playNext command events. The subscription means that the application supports the playNext command.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'playNext'** is triggered when the command for playing the next item is sent to the session.|
| callback | () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.    |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('playNext', () => {
  console.info('on playNext entry');
});
```

## on('playPrevious')<sup>10+</sup>

on(type:'playPrevious', callback: () => void): void

Subscribes to playPrevious command events. The subscription means that the application supports the playPrevious command.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'playPrevious'** is triggered when the command for playing the previous item sent to the session.|
| callback | () => void | Yes  | Callback used for subscription. If the subscription is successful, **err** is **undefined**; otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('playPrevious', () => {
  console.info('on playPrevious entry');
});
```

## on('fastForward')<sup>10+</sup>

on(type: 'fastForward', callback: (time?: number) => void): void

Subscribes to fastForward command events. The subscription means that the application supports the fastForward command.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'fastForward'** is triggered when the command for fast forwarding is sent to the session.|
| callback | (time?: number) => void | Yes  | Callback used for subscription. The **time** parameter in the callback indicates the time to seek to, in seconds.   |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('fastForward', (time?: number) => {
  console.info('on fastForward entry');
});
```

## on('rewind')<sup>10+</sup>

on(type:'rewind', callback: (time?: number) => void): void

Subscribes to rewind command events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'rewind'** is triggered when the command for rewinding is sent to the session.|
| callback | (time?: number) => void | Yes  | Callback used for subscription. The **time** parameter in the callback indicates the time to seek to, in seconds.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('rewind', (time?: number) => {
  console.info('on rewind entry');
});
```

## on('playWithAssetId')<sup>20+</sup>

on(type:'playWithAssetId', callback: Callback\<string>): void

Subscribes to playback events with a given media asset ID.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'playWithAssetId'** is triggered when the media asset ID is played.|
| callback | Callback\<string> | Yes  | Callback The **assetId** parameter in the callback indicates the media asset ID.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
let playWithAssetIdCallback = (assetId: string) => {
  console.info(`on playWithAssetId entry,  assetId = ${assetId}`);
}
currentAVSession.on('playWithAssetId', playWithAssetIdCallback);
```

## off('playWithAssetId')<sup>20+</sup>

off(type: 'playWithAssetId', callback?: Callback\<string>): void

Unsubscribes from playback events with a given media asset ID. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'playWithAssetId'** in this case.|
| callback | Callback\<string> | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. The **assetId** parameter in the callback indicates the media asset ID.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('playWithAssetId');
```

## on('seek')<sup>10+</sup>

on(type: 'seek', callback: (time: number) => void): void

Subscribes to seek command events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | --------- |
| type     | string                 | Yes  | Event type. The event **'seek'** is triggered when the seek command is sent to the session.|
| callback | (time: number) => void | Yes  | Callback used for subscription. The **time** parameter in the callback indicates the time to seek to, in milliseconds.                  |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('seek', (time: number) => {
  console.info(`on seek entry time : ${time}`);
});
```

## on('setSpeed')<sup>10+</sup>

on(type: 'setSpeed', callback: (speed: number) => void): void

Subscribes to setSpeed command events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description    |
| -------- | ----------------------- | ---- | --------- |
| type     | string                  | Yes  | Event type. The event **'setSpeed'** is triggered when the command for setting the playback speed is sent to the session.|
| callback | (speed: number) => void | Yes  | Callback used for subscription. The **speed** parameter in the callback indicates the playback speed.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('setSpeed', (speed: number) => {
  console.info(`on setSpeed speed : ${speed}`);
});
```

## on('setLoopMode')<sup>10+</sup>

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

Subscribes to setLoopMode command events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                  | Mandatory| Description |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | Yes  | Event type. The event **'setLoopMode'** is triggered when the command for setting the loop mode is sent to the session.|
| callback | (mode: [LoopMode](arkts-apis-avsession-e.md#loopmode10)) => void | Yes  | Callback used for subscription. The **mode** parameter in the callback indicates the loop mode.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('setLoopMode', (mode: avSession.LoopMode) => {
  console.info(`on setLoopMode mode : ${mode}`);
});
```

## on('setTargetLoopMode')<sup>18+</sup>

on(type: 'setTargetLoopMode', callback: Callback\<LoopMode>): void

Subscribes to setTargetLoopMode command events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                                  | Mandatory| Description |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | Yes  | Event type. The event **'setTargetLoopMode'**<br>is triggered when the command for setting the target loop mode is sent to the session.|
| callback | Callback<[LoopMode](arkts-apis-avsession-e.md#loopmode10)> | Yes  | Callback used for subscription. The **LoopMode** parameter in the callback indicates the target loop mode.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('setTargetLoopMode', (mode: avSession.LoopMode) => {
  console.info(`on setTargetLoopMode mode : ${mode}`);
});
```

## on('toggleFavorite')<sup>10+</sup>

on(type: 'toggleFavorite', callback: (assetId: string) => void): void

Subscribes to toggleFavorite command events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description    |
| -------- | ------------------------- | ---- | --------- |
| type     | string                    | Yes  | Event type. The event **'toggleFavorite'** is triggered when the command for favoriting the media asset is sent to the session.|
| callback | (assetId: string) => void | Yes  | Callback used for subscription. The **assetId** parameter in the callback indicates the media asset ID.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('toggleFavorite', (assetId: string) => {
  console.info(`on toggleFavorite mode : ${assetId}`);
});
```

## on('skipToQueueItem')<sup>10+</sup>

on(type: 'skipToQueueItem', callback: (itemId: number) => void): void

Subscribes to the event that indicates an item in the playlist is selected. The session can play the selected item.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------ | ---- | ------------------------------------- |
| type     | string                   | Yes  | Event type. The event **'skipToQueueItem'** is triggered when an item in the playlist is selected.|
| callback | (itemId: number) => void | Yes  | Callback used for subscription. The **itemId** parameter in the callback indicates the ID of the selected item.                                               |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('skipToQueueItem', (itemId: number) => {
  console.info(`on skipToQueueItem id : ${itemId}`);
});
```

## on('handleKeyEvent')<sup>10+</sup>

on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void

Subscribes to key events of external devices such as Bluetooth and wired devices to listen for the play, pause, previous, next, fast-forward, and rewind commands in the key events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type   | Mandatory| Description    |
| -------- | --------- | ---- | --------- |
| type     | string    | Yes  | Event type. The event **'handleKeyEvent'** is triggered when a key event is sent to the session.|
| callback | (event: [KeyEvent](../apis-input-kit/js-apis-keyevent.md)) => void | Yes  | Callback used for subscription. The **event** parameter in the callback indicates the key event.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | --------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { KeyEvent } from '@kit.InputKit';

currentAVSession.on('handleKeyEvent', (event: KeyEvent) => {
  console.info(`on handleKeyEvent event : ${event}`);
});

```

## on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Subscribes to output device change events. After the application integrates the [AVCastPicker component](ohos-multimedia-avcastpicker.md), the application receives the device change callback when the user switches the device through the component.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type| Mandatory| Description    |
| -------- | ------------------------| ---- | --------- |
| type     | string                                                  | Yes  | Event type. The event **'outputDeviceChange'** is triggered when the output device changes.|
| callback | (state: [ConnectionState](arkts-apis-avsession-e.md#connectionstate10), device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | Yes  | Callback function, where the **device** parameter specifies the output device information.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                        |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange device : ${device}`);
});
```

## on('commonCommand')<sup>10+</sup>

on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void

Subscribes to custom control command change events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type |   Mandatory| Description    |
| -------- | --------- | ---- | --------- |
| type     | string    | Yes  | Event type. The event **'commonCommand'** is triggered when a custom control command changes.|
| callback | (command: string, args: {[key: string]: Object}) => void         | Yes  | Callback used for subscription. The **command** parameter in the callback indicates the name of the changed custom control command, and **args** indicates the parameters carried in the command. The parameters must be the same as those set in [sendCommonCommand](arkts-apis-avsession-AVSessionController.md#sendcommoncommand10).         |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() { 
    Column() {
        Text(this.message)
          .onClick(()=>{
            let currentAVSession: avSession.AVSession | undefined = undefined;
            let tag = "createNewSession";
            let context: Context = this.getUIContext().getHostContext() as Context;

            avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
            if (err) {
                console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
                currentAVSession = data;
            }
            });
            if (currentAVSession !== undefined) {
            (currentAVSession as avSession.AVSession).on('commonCommand', (commonCommand, args) => {
                console.info(`OnCommonCommand, the command is ${commonCommand}, args: ${JSON.stringify(args)}`);
            });
            }
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## off('play')<sup>10+</sup>

off(type: 'play', callback?: () => void): void

Unsubscribes from play command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'play'** in this case.|
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('play');
```

## off('pause')<sup>10+</sup>

off(type: 'pause', callback?: () => void): void

Unsubscribes from pause command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'pause'** in this case.|
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('pause');
```

## off('stop')<sup>10+</sup>

off(type: 'stop', callback?: () => void): void

Unsubscribes from stop command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'stop'** in this case.|
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('stop');
```

## off('playNext')<sup>10+</sup>

off(type: 'playNext', callback?: () => void): void

Unsubscribes from playNext command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'playNext'** in this case.|
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('playNext');
```

## off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious', callback?: () => void): void

Unsubscribes from playPrevious command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'playPrevious'** in this case.|
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('playPrevious');
```

## off('fastForward')<sup>10+</sup>

off(type: 'fastForward', callback?: () => void): void

Unsubscribes from fastForward command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'fastForward'** in this case.|
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('fastForward');
```

## off('rewind')<sup>10+</sup>

off(type: 'rewind', callback?: () => void): void

Unsubscribes from rewind command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'rewind'** in this case.|
| callback | () => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('rewind');
```

## off('seek')<sup>10+</sup>

off(type: 'seek', callback?: (time: number) => void): void

Unsubscribes from seek command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                         |
| -------- | ---------------------- | ---- | ----------|
| type     | string                 | Yes  | Event type, which is **'seek'** in this case.      |
| callback | (time: number) => void | No  | Callback used for unsubscription. The **time** parameter in the callback indicates the time to seek to, in milliseconds.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('seek');
```

## off('setSpeed')<sup>10+</sup>

off(type: 'setSpeed', callback?: (speed: number) => void): void

Unsubscribes from setSpeed command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                          |
| -------- | ----------------------- | ---- | -------------------------------------------|
| type     | string                  | Yes  | Event type, which is **'setSpeed'** in this case.   |
| callback | (speed: number) => void | No  | Callback used for unsubscription. The **speed** parameter in the callback indicates the playback speed.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('setSpeed');
```

## off('setLoopMode')<sup>10+</sup>

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

Unsubscribes from setLoopMode command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description    |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | Yes  | Event type, which is **'setLoopMode'** in this case.|
| callback | (mode: [LoopMode](arkts-apis-avsession-e.md#loopmode10)) => void | No  | Callback used for unsubscription. The **mode** parameter in the callback indicates the loop mode.<br>- If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>- The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('setLoopMode');
```

## off('setTargetLoopMode')<sup>18+</sup>

off(type: 'setTargetLoopMode', callback?: Callback\<LoopMode>): void

Unsubscribes from setTargetLoopMode command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description    |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | Yes  | Event type, which is **'setTargetLoopMode'** in this case.|
| callback | Callback<[LoopMode](arkts-apis-avsession-e.md#loopmode10)> | No  | Callback used for unsubscription. The **LoopMode** parameter in the callback indicates the target loop mode.<br>- If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>- The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [AVSession Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('setTargetLoopMode');
```

## off('toggleFavorite')<sup>10+</sup>

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

Unsubscribes from toggleFavorite command events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description    |
| -------- | ------------------------- | ---- | -------------------------|
| type     | string                    | Yes  | Event type, which is **'toggleFavorite'** in this case.           |
| callback | (assetId: string) => void | No  | Callback used for unsubscription. The **assetId** parameter in the callback indicates the media asset ID.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('toggleFavorite');
```

## off('skipToQueueItem')<sup>10+</sup>

off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void

Unsubscribes from the event that indicates an item in the playlist is selected. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                     | Mandatory| Description   |
| -------- | ------------------------ | ---- | ----------------------|
| type     | string                   | Yes  | Event type, which is **'skipToQueueItem'** in this case.   |
| callback | (itemId: number) => void | No  | Callback used for unsubscription. The **itemId** parameter in the callback indicates the ID of the item.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | --------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('skipToQueueItem');
```

## off('handleKeyEvent')<sup>10+</sup>

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

Unsubscribes from key events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type |   Mandatory| Description    |
| -------- | --------- | ---- | --------- |
| type     | string    | Yes  | Event type, which is **'handleKeyEvent'** in this case.            |
| callback | (event: [KeyEvent](../apis-input-kit/js-apis-keyevent.md)) => void | No  | Callback used for unsubscription. The **event** parameter in the callback indicates the key event.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                             |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('handleKeyEvent');
```

## off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

Unsubscribes from playback device change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type| Mandatory| Description  |
| -------- | ------------------------| ---- | -----------------------|
| type     | string                                                  | Yes  | Event type, which is **'outputDeviceChange'** in this case.    |
| callback | (state: [ConnectionState](arkts-apis-avsession-e.md#connectionstate10), device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | No  | Callback function, where the **device** parameter specifies the output device information.<br>If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                       |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('outputDeviceChange');
```

## off('commonCommand')<sup>10+</sup>

off(type: 'commonCommand', callback?: (command: string, args: {[key: string]: Object}) => void): void

Unsubscribes from custom control command change events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type |   Mandatory| Description |
| -------- | --------- | ---- | ----------------------|
| type     | string    | Yes  | Event type, which is **'commonCommand'** in this case.   |
| callback | (command: string, args: {[key: string]: Object}) => void         | No  | Callback used for unsubscription. The **command** parameter in the callback indicates the name of the changed custom control command, and **args** indicates the parameters carried in the command.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('commonCommand');
```

## on('answer')<sup>11+</sup>

on(type: 'answer', callback: Callback\<void>): void

Subscribes to call answer events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type  |  Mandatory| Description    |
| -------- | --------- | ---- | --------- |
| type     | string    | Yes  | Event type. The event **'answer'** is triggered when a call is answered.|
| callback | Callback\<void>                                               | Yes  | Callback used to return the result.                     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('answer', () => {
  console.info('on call answer');
});
```

## off('answer')<sup>11+</sup>

off(type: 'answer', callback?: Callback\<void>): void

Unsubscribes from call answer events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'answer'** in this case.|
| callback | Callback\<void>     | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.   |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('answer');
```

## on('hangUp')<sup>11+</sup>

on(type: 'hangUp', callback: Callback\<void>): void

Subscribes to call hangup events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type |   Mandatory| Description    |
| -------- | --------- | ---- | --------- |
| type     | string    | Yes  | Event type. The event **'hangUp'** is triggered when a call is hung up.|
| callback | Callback\<void>                                               | Yes  | Callback used to return the result.                                            |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('hangUp', () => {
  console.info('on call hangUp');
});
```

## off('hangUp')<sup>11+</sup>

off(type: 'hangUp', callback?: Callback\<void>): void

Unsubscribes from call answer events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'hangUp'** in this case.|
| callback | Callback\<void>      | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('hangUp');
```

## on('toggleCallMute')<sup>11+</sup>

on(type: 'toggleCallMute', callback: Callback\<void>): void

Subscribes to call mute events.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type |   Mandatory| Description    |
| -------- | --------- | ---- | --------- |
| type     | string    | Yes  | Event type. The event **'toggleCallMute'** is triggered when a call is muted or unmuted.|
| callback | Callback\<void>                                               | Yes  | Callback used to return the result.                                            |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('toggleCallMute', () => {
  console.info('on call toggleCallMute');
});
```

## off('toggleCallMute')<sup>11+</sup>

off(type: 'toggleCallMute', callback?: Callback\<void>): void

Unsubscribes from call mute events. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'toggleCallMute'** in this case.|
| callback | Callback\<void>    | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('toggleCallMute');
```

## on('castDisplayChange')<sup>12+</sup>

on(type: 'castDisplayChange', callback: Callback\<CastDisplayInfo>): void

Subscribes to cast display change events in the case of extended screens.

Multiple callbacks can be registered for this event. To ensure only the latest callback executes, unregister previous listeners first. Otherwise, all registered callbacks will fire on state changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string    | Yes  | Event type. The event **'castDisplayChange'** is triggered when the cast display in the case of extended screens changes.|
| callback | Callback\<[CastDisplayInfo](arkts-apis-avsession-i.md#castdisplayinfo12)\>   | Yes  | Callback used to return the information about the cast display.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
let castDisplay: avSession.CastDisplayInfo;
currentAVSession.on('castDisplayChange', (display: avSession.CastDisplayInfo) => {
    if (display.state === avSession.CastDisplayState.STATE_ON) {
        castDisplay = display;
        console.info(`Succeeded in castDisplayChange display : ${display.id} ON`);
    } else if (display.state === avSession.CastDisplayState.STATE_OFF){
        console.info(`Succeeded in castDisplayChange display : ${display.id} OFF`);
    }
});
```

## off('castDisplayChange')<sup>12+</sup>

 off(type: 'castDisplayChange', callback?: Callback\<CastDisplayInfo>): void

Unsubscribes from cast display change events in the case of extended screens. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string    | Yes  | Event type, which is **'castDisplayChange'** in this case.|
| callback | Callback\<[CastDisplayInfo](arkts-apis-avsession-i.md#castdisplayinfo12)\>  | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('castDisplayChange');
```

## stopCasting<sup>10+</sup>

stopCasting(callback: AsyncCallback\<void>): void

Stops castings. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                                 | Mandatory| Description                                 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result. If the command is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.stopCasting((err: BusinessError) => {
  if (err) {
    console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('stopCasting successfully');
  }
});
```

## stopCasting<sup>10+</sup>

stopCasting(): Promise\<void>

Stops castings. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result. If casting stops, no value is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 6600109  | The remote connection is not established. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

currentAVSession.stopCasting().then(() => {
  console.info('stopCasting successfully');
}).catch((err: BusinessError) => {
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

Obtains the output device information. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Return value**

| Type                                           | Description                             |
| ----------------| --------------------------------- |
| [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10) | Information about the output device.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID  | Error Message|
|---------| --------------------------------------- |
| 6600101 | Session service exception. |
| 6600102 | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let currentOutputDevice: avSession.OutputDeviceInfo = currentAVSession.getOutputDeviceSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOutputDeviceSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## getAllCastDisplays<sup>12+</sup>

getAllCastDisplays(): Promise<Array\<CastDisplayInfo>>

Obtains all displays that support extended screen projection in the current system. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**Return value**

| Type                                           | Description                             |
| ----------------| --------------------------------- |
| Promise<Array<[CastDisplayInfo](arkts-apis-avsession-i.md#castdisplayinfo12)>>| Promise used to return the information about all the cast displays.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID  | Error Message|
|---------| --------------------------------------- |
| 6600101 | Session service exception. |
| 6600102 | The session does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let castDisplay: avSession.CastDisplayInfo;
currentAVSession.getAllCastDisplays().then((data: Array< avSession.CastDisplayInfo >) => {
    if (data.length >= 1) {
       castDisplay = data[0];
     }
   }).catch((err: BusinessError) => {
     console.error(`Failed to getAllCastDisplay. Code: ${err.code}, message: ${err.message}`);
   });
```

## on('playFromAssetId')<sup>(deprecated)</sup>

on(type:'playFromAssetId', callback: (assetId: number) => void): void

Subscribes to playback events with a given media asset ID.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 20. You are advised to use [on('playWithAssetId')](#onplaywithassetid20) instead.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name  | Type                | Mandatory| Description    |
| -------- | -------------------- | ---- | --------- |
| type     | string               | Yes  | Event type. The event **'playFromAssetId'** is triggered when the media asset ID is played.|
| callback | (assetId: number) => void | Yes  | Callback The **assetId** parameter in the callback indicates the media asset ID.     |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.on('playFromAssetId', (assetId: number) => {
  console.info('on playFromAssetId entry');
});
```

## off('playFromAssetId')<sup>(deprecated)</sup>

off(type: 'playFromAssetId', callback?: (assetId: number) => void): void

Unsubscribes from playback events with a given media asset ID. If a callback is specified, the corresponding listener is unregistered. If no callback is specified, all listeners for the specified event are unregistered.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 20. You are advised to use [off('playWithAssetId')](#offplaywithassetid20) instead.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Parameters**

| Name   | Type                 | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | Yes  | Event type, which is **'playFromAssetId'** in this case.|
| callback | (assetId: number) => void | No  | Callback used for unsubscription. If the unsubscription is successful, **err** is **undefined**; otherwise, **err** is an error object.<br>The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session. The **assetId** parameter in the callback indicates the media asset ID.                           |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message|
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**Example**

```ts
currentAVSession.off('playFromAssetId');
```

## on('customDataChange')<sup>20+</sup>

on(type: 'customDataChange', callback: Callback\<Record\<string, Object>>): void

Subscribes to events indicating that custom data is sent to a remote device.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. The event **'customDataChange'** is triggered when the provider sends custom data.|
| callback | Callback\<Record\<string, Object>> | Yes  | Callback used to receive the custom data.                              |

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600102  | The session does not exist.                                  |

**Example**

```ts
currentAVSession.on('customDataChange', (callback) => {
    console.info(`Caught customDataChange event,the new callback is: ${JSON.stringify(callback)}`);
});
```

## off('customDataChange')<sup>20+</sup>

off(type: 'customDataChange', callback?: Callback\<Record\<string, Object>>): void

Unsubscribes from events indicating that custom data is sent to a remote device.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type, which is **'customDataChange'** in this case.        |
| callback | Callback\<Record\<string, Object>> | No  | Callback used for unsubscription. The **callback** parameter is optional. If it is not specified, all the subscriptions to the specified event are canceled for this session.|

**Error codes**

For details about the error codes, see [AVSession Management Error Codes](errorcode-avsession.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600102  | The session does not exist.                                  |

**Example**

```ts
currentAVSession.off('customDataChange');
```
