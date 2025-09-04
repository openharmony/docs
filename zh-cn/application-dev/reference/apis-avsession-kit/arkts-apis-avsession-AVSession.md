# Interface (AVSession)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 10开始支持。

调用[avSession.createAVSession](arkts-apis-avsession-f.md#avsessioncreateavsession10)后，返回会话的实例，可以获得会话ID，完成设置元数据，播放状态信息等操作。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型   | 只读 | 可选 | 说明                          |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId<sup>10+</sup> | string | 是   | 否   | AVSession对象唯一的会话标识。 |
| sessionType<sup>10+</sup> | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10) | 是   | 否   | AVSession会话类型。 |

**示例：**

```ts
let sessionId: string = currentAVSession.sessionId;
let sessionType: avSession.AVSessionType = currentAVSession.sessionType;
```

## setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata): Promise\<void>

设置会话元数据。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| data   | [AVMetadata](arkts-apis-avsession-i.md#avmetadata10) | 是   | 会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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
  // LRC中有两类元素：一种是时间标签+歌词，一种是ID标签。
  // 例如：[00:25.44]xxx\r\n[00:26.44]xxx\r\n
  lyric: "lrc格式歌词内容",
  // singleLyricText字段存储单条歌词文本，不包含时间戳。
  // 例如："单条歌词内容"。
  singleLyricText: "单条歌词内容",
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

设置会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [AVMetadata](arkts-apis-avsession-i.md#avmetadata10) | 是   | 会话元数据。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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
  // LRC中有两类元素：一种是时间标签+歌词，一种是ID标签。
  // 例如：[00:25.44]xxx\r\n[00:26.44]xxx\r\n
  lyric: "lrc格式歌词内容",
  // singleLyricText字段存储单条歌词文本，不包含时间戳。
  // 例如："单条歌词内容"。
  singleLyricText: "单条歌词内容",
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

设置通话会话元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| data   | [CallMetadata](arkts-apis-avsession-i.md#callmetadata11) | 是   | 通话会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当通话元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置通话会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [CallMetadata](arkts-apis-avsession-i.md#callmetadata11) | 是   | 通话会话元数据。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当通话元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置通话状态。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| state   | [AVCallState](arkts-apis-avsession-i.md#avcallstate11) | 是   | 通话状态。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当通话元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置通话状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state     | [AVCallState](arkts-apis-avsession-i.md#avcallstate11) | 是   | 通话状态。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当通话元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置会话播放状态。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明                                           |
| ------ | ----------------------------------- | ---- | ---------------|
| state   | [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放状态设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置会话播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                           |
| -------- | ----------------------------------- | ---- | ---------------|
| state     | [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |
| callback | AsyncCallback\<void>                | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置一个WantAgent用于拉起会话的Ability。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明     |
| ------- | --------------| ---- | ----------------------------|
| ability | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当Ability设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgentInfo对象。
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

设置一个WantAgent用于拉起会话的Ability。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                          | 必填 | 说明     |
| -------- | --------------| ---- | --------- |
| ability  | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。  |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当Ability设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgentInfo对象。
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

媒体提供方设置一个会话内自定义事件，包括事件名和键值对形式的事件内容，结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明     |
| ------- | --------------| ---- | ----------------------------|
| event | string | 是   | 需要设置的会话事件的名称。 |
| args | {[key: string]: Object} | 是   | 需要传递的会话事件内容。 |

> **说明：**
> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当事件设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

媒体提供方设置一个会话内自定义事件，包括事件名和键值对形式的事件内容，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明     |
| ------- | --------------| ---- | ----------------------------|
| event | string | 是   | 需要设置的会话事件的名称。 |
| args | {[key: string]: Object} | 是   | 需要传递的会话事件内容。 |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当会话事件设置成功，err为undefined，否则返回错误对象。 |

> **说明：**

> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置媒体播放列表。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                 | 必填 | 说明                               |
| ------ | ------------------------------------ | ---- | ---------------------------------- |
| items  | Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\> | 是   | 播放列表单项的队列，用以表示播放列表。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放列表设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置媒体播放列表。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明     |
| -------- | ------------------------------------ | ---- | ----------------------------|
| items    | Array<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)\> | 是   | 播放列表单项的队列，用以表示播放列表。                          |
| callback | AsyncCallback\<void>                 | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置媒体播放列表名称。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| title  | string | 是   | 播放列表的名称。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放列表设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置媒体播放列表名称。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明     |
| -------- | --------------------- | ---- | ----------------------------|
| title    | string                | 是   | 播放列表名称字段。                          |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

媒体提供方设置键值对形式的自定义媒体数据包，结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明     |
| ------- | --------------| ---- | ----------------------------|
| extras | {[key: string]: Object} | 是   | 需要传递的自定义媒体数据包键值对。 |

> **说明：**

> 参数extras支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当自定义媒体数据包设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

媒体提供方设置键值对形式的自定义媒体数据包，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明     |
| ------- | --------------| ---- | ----------------------------|
| extras | {[key: string]: Object} | 是   | 需要传递的自定义媒体数据包键值对。 |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当自定义媒体数据包设置成功，err为undefined，否则返回错误对象。 |

> **说明：**

> 参数extras支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

发送私有数据到远端设备。使用Promise异步回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| data   | Record\<string, Object> | 是   | 应用程序填充的自定义数据。服务端仅解析key为'customData'，且Object为string类型的对象。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist.                                  |

**示例：**

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

获取本会话对应的控制器。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                 | 说明                          |
| ---------------------| ----------------------------- |
| Promise<[AVSessionController](arkts-apis-avsession-AVSessionController.md)> | Promise对象。返回会话控制器。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

获取本会话相应的控制器。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                       |
| -------- | ----------------------------| ---- | -------------------------- |
| callback | AsyncCallback<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\> | 是   | 回调函数。返回会话控制器。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设备建立连接后，获取投播控制器。结果通过Promise异步回调方式返回。如果 avsession 未处于投播状态，则控制器将返回 null。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型     | 说明     |
| --------- | --------- |
| Promise<[AVCastController](arkts-apis-avsession-AVCastController.md)\>  | Promise对象。返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | --------------------------------------- |
| 6600102| The session does not exist.           |
| 6600109| The remote connection is not established. |

**示例：**

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

设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。如果 avsession 未处于投播状态，则控制器将返回 null。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型     | 必填 | 说明     |
| --------- | ----------------------------| ---- | --------- |
| callback  | AsyncCallback<[AVCastController](arkts-apis-avsession-AVCastController.md)\> | 是   | 回调函数，返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息                                  |
| -------- |---------------------------------------|
| 6600102| The session does not exist.           |
| 6600109| The remote connection is not established. |

**示例：**

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

通过会话获取播放设备信息。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                           | 说明                              |
| ---------------| --------------------------------- |
| Promise<[OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)> | Promise对象。返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

通过会话获取播放设备相关信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                           |
| -------- | ----------------------| ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)\> | 是   | 回调函数，返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

激活会话，激活后可正常使用会话。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当会话激活成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

激活会话，激活后可正常使用会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当会话激活成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

禁用当前会话的功能，可通过[activate](#activate10)恢复。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当禁用会话成功，无返回结果，否则返回错误对象。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

禁用当前会话。结果通过callback异步回调方式返回。

禁用当前会话的功能，可通过[activate](#activate10)恢复。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当禁用会话成功，err为undefined，否则返回错误对象。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

销毁当前会话，使当前会话完全失效。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当会话销毁成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

销毁当前会话，使当前会话完全失效。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当会话销毁成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

设置播放命令监听事件。注册该监听，说明应用支持播放指令。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件为`'play'`，当播放命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。                                        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('play', () => {
  console.info('on play entry');
});
```

## on('pause')<sup>10+</sup>

on(type: 'pause', callback: () => void): void

设置暂停命令监听事件。注册该监听，说明应用支持暂停指令。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件为`'pause'`，当暂停命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('pause', () => {
  console.info('on pause entry');
});
```

## on('stop')<sup>10+</sup>

on(type:'stop', callback: () => void): void

设置停止命令监听事件。注册该监听，说明应用支持停止指令。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件是`'stop'`，当停止命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('stop', () => {
  console.info('on stop entry');
});
```

## on('playNext')<sup>10+</sup>

on(type:'playNext', callback: () => void): void

设置播放下一首命令监听事件。注册该监听，说明应用支持下一首指令。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playNext'`，当播放下一首命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playNext', () => {
  console.info('on playNext entry');
});
```

## on('playPrevious')<sup>10+</sup>

on(type:'playPrevious', callback: () => void): void

设置播放上一首命令监听事件。注册该监听，说明应用支持上一首指令。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playPrevious'`，当播放上一首命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。       |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playPrevious', () => {
  console.info('on playPrevious entry');
});
```

## on('fastForward')<sup>10+</sup>

on(type: 'fastForward', callback: (time?: number) => void): void

设置快进命令监听事件。注册该监听，说明应用支持快进指令。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件是 `'fastForward'`，当快进命令被发送到会话时，触发该事件回调。 |
| callback | (time?: number) => void | 是   | 回调函数。参数time是时间节点，单位为秒。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('fastForward', (time?: number) => {
  console.info('on fastForward entry');
});
```

## on('rewind')<sup>10+</sup>

on(type:'rewind', callback: (time?: number) => void): void

设置快退命令监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件是`'rewind'`，当快退命令被发送到会话时，触发该事件回调。 |
| callback | (time?: number) => void | 是   | 回调函数。参数time是时间节点，单位为秒。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('rewind', (time?: number) => {
  console.info('on rewind entry');
});
```

## on('playWithAssetId')<sup>20+</sup>

on(type:'playWithAssetId', callback: Callback\<string>): void

设置指定资源id进行播放的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playWithAssetId'`，当指定资源id进行播放时，触发该事件回调。 |
| callback | Callback\<string> | 是   | 回调函数。参数assetId是媒体id。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
let playWithAssetIdCallback = (assetId: string) => {
  console.info(`on playWithAssetId entry,  assetId = ${assetId}`);
}
currentAVSession.on('playWithAssetId', playWithAssetIdCallback);
```

## off('playWithAssetId')<sup>20+</sup>

off(type: 'playWithAssetId', callback?: Callback\<string>): void

取消指定资源id进行播放的事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'playWithAssetId'`。 |
| callback | Callback\<string> | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。参数assetId是媒体id。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playWithAssetId');
```

## on('seek')<sup>10+</sup>

on(type: 'seek', callback: (time: number) => void): void

设置跳转节点监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | --------- |
| type     | string                 | 是   | 事件回调类型，支持事件`'seek'`：当跳转节点命令被发送到会话时，触发该事件。 |
| callback | (time: number) => void | 是   | 回调函数。参数time是时间节点，单位为毫秒。                   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('seek', (time: number) => {
  console.info(`on seek entry time : ${time}`);
});
```

## on('setSpeed')<sup>10+</sup>

on(type: 'setSpeed', callback: (speed: number) => void): void

设置播放速率的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明     |
| -------- | ----------------------- | ---- | --------- |
| type     | string                  | 是   | 事件回调类型，支持事件`'setSpeed'`：当设置播放速率的命令被发送到会话时，触发该事件。 |
| callback | (speed: number) => void | 是   | 回调函数。参数speed是播放倍速。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('setSpeed', (speed: number) => {
  console.info(`on setSpeed speed : ${speed}`);
});
```

## on('setLoopMode')<sup>10+</sup>

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

设置循环模式的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                   | 必填 | 说明  |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | 是   | 事件回调类型，支持事件`'setLoopMode'`：当设置循环模式的命令被发送到会话时，触发该事件。 |
| callback | (mode: [LoopMode](arkts-apis-avsession-e.md#loopmode10)) => void | 是   | 回调函数。参数mode是循环模式。                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('setLoopMode', (mode: avSession.LoopMode) => {
  console.info(`on setLoopMode mode : ${mode}`);
});
```

## on('setTargetLoopMode')<sup>18+</sup>

on(type: 'setTargetLoopMode', callback: Callback\<LoopMode>): void

设置目标循环模式的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                   | 必填 | 说明  |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | 是   | 事件回调类型，支持事件`'setTargetLoopMode'`。<br>- `'setTargetLoopMode'`：当设置目标循环模式的命令被发送到会话时，触发该事件。 |
| callback | Callback<[LoopMode](arkts-apis-avsession-e.md#loopmode10)> | 是   | 回调函数。参数表示目标循环模式。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('setTargetLoopMode', (mode: avSession.LoopMode) => {
  console.info(`on setTargetLoopMode mode : ${mode}`);
});
```

## on('toggleFavorite')<sup>10+</sup>

on(type: 'toggleFavorite', callback: (assetId: string) => void): void

设置是否收藏的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明     |
| -------- | ------------------------- | ---- | --------- |
| type     | string                    | 是   | 事件回调类型，支持事件`'toggleFavorite'`：当是否收藏的命令被发送到会话时，触发该事件。 |
| callback | (assetId: string) => void | 是   | 回调函数。参数assetId是媒体ID。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('toggleFavorite', (assetId: string) => {
  console.info(`on toggleFavorite mode : ${assetId}`);
});
```

## on('skipToQueueItem')<sup>10+</sup>

on(type: 'skipToQueueItem', callback: (itemId: number) => void): void

设置播放列表其中某项被选中的监听事件，session端可以选择对这个单项歌曲进行播放。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------ | ---- | ------------------------------------- |
| type     | string                   | 是   | 事件回调类型，支持事件`'skipToQueueItem'`：当播放列表选中单项的命令被发送到会话时，触发该事件。 |
| callback | (itemId: number) => void | 是   | 回调函数。参数itemId是选中的播放列表项的ID。                                                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('skipToQueueItem', (itemId: number) => {
  console.info(`on skipToQueueItem id : ${itemId}`);
});
```

## on('handleKeyEvent')<sup>10+</sup>

on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void

设置蓝牙/有线等外设接入的按键输入事件的监听，监听多媒体按键事件中播放、暂停、上下一首、快进、快退的指令。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型    | 必填 | 说明     |
| -------- | --------- | ---- | --------- |
| type     | string    | 是   | 事件回调类型，支持事件`'handleKeyEvent'`：当按键事件被发送到会话时，触发该事件。 |
| callback | (event: [KeyEvent](../apis-input-kit/js-apis-keyevent.md)) => void | 是   | 回调函数。参数event是按键事件。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | --------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { KeyEvent } from '@kit.InputKit';

currentAVSession.on('handleKeyEvent', (event: KeyEvent) => {
  console.info(`on handleKeyEvent event : ${event}`);
});

```

## on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

设置播放设备变化的监听事件。应用接入[系统投播组件](ohos-multimedia-avcastpicker.md)，当用户通过组件切换设备时，会收到设备切换的回调。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型 | 必填 | 说明     |
| -------- | ------------------------| ---- | --------- |
| type     | string                                                  | 是   | 事件回调类型，支持事件`'outputDeviceChange'`：当播放设备变化时，触发该事件。 |
| callback | (state: [ConnectionState](arkts-apis-avsession-e.md#connectionstate10), device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | 是   | 回调函数，参数device是设备相关信息。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange device : ${device}`);
});
```

## on('commonCommand')<sup>10+</sup>

on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void

设置自定义控制命令变化的监听器。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型  |   必填 | 说明     |
| -------- | --------- | ---- | --------- |
| type     | string    | 是   | 事件回调类型，支持事件`'commonCommand'`：当自定义控制命令变化时，触发该事件。 |
| callback | (command: string, args: {[key: string]: Object}) => void         | 是   | 回调函数，command为变化的自定义控制命令名，args为自定义控制命令的参数，参数内容与[sendCommonCommand](arkts-apis-avsession-AVSessionController.md#sendcommoncommand10)方法设置的参数内容完全一致。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

取消会话播放事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'play'`。|
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('play');
```

## off('pause')<sup>10+</sup>

off(type: 'pause', callback?: () => void): void

取消会话暂停事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'pause'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('pause');
```

## off('stop')<sup>10+</sup>

off(type: 'stop', callback?: () => void): void

取消会话停止事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'stop'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('stop');
```

## off('playNext')<sup>10+</sup>

off(type: 'playNext', callback?: () => void): void

取消会话播放下一首事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是 `'playNext'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playNext');
```

## off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious', callback?: () => void): void

取消会话播放上一首事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'playPrevious'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playPrevious');
```

## off('fastForward')<sup>10+</sup>

off(type: 'fastForward', callback?: () => void): void

取消会话快进事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'fastForward'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('fastForward');
```

## off('rewind')<sup>10+</sup>

off(type: 'rewind', callback?: () => void): void

取消会话快退事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'rewind'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('rewind');
```

## off('seek')<sup>10+</sup>

off(type: 'seek', callback?: (time: number) => void): void

取消跳转节点事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                          |
| -------- | ---------------------- | ---- | ----------|
| type     | string                 | 是   | 关闭对应的监听事件，支持关闭事件`'seek'`。       |
| callback | (time: number) => void | 否   | 回调函数，参数time是时间节点，单位为毫秒。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('seek');
```

## off('setSpeed')<sup>10+</sup>

off(type: 'setSpeed', callback?: (speed: number) => void): void

取消播放速率变化事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                           |
| -------- | ----------------------- | ---- | -------------------------------------------|
| type     | string                  | 是   | 关闭对应的监听事件，支持关闭事件`'setSpeed'`。    |
| callback | (speed: number) => void | 否   | 回调函数，参数speed是播放倍速。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('setSpeed');
```

## off('setLoopMode')<sup>10+</sup>

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

取消循环模式变化事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明     |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | 是   | 关闭对应的监听事件，支持关闭事件`'setLoopMode'`。|
| callback | (mode: [LoopMode](arkts-apis-avsession-e.md#loopmode10)) => void | 否   | 回调函数，参数mode是循环模式。<br>- 当监听事件取消成功，err为undefined，否则返回错误对象。<br>- 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('setLoopMode');
```

## off('setTargetLoopMode')<sup>18+</sup>

off(type: 'setTargetLoopMode', callback?: Callback\<LoopMode>): void

取消目标循环模式变化事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明     |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | 是   | 关闭对应的监听事件，支持关闭事件`'setTargetLoopMode'`。|
| callback | Callback<[LoopMode](arkts-apis-avsession-e.md#loopmode10)> | 否   | 回调函数，参数表示目标循环模式。<br>- 当监听事件取消成功，err为undefined，否则返回错误对象。<br>- 该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('setTargetLoopMode');
```

## off('toggleFavorite')<sup>10+</sup>

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

取消是否收藏的事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明     |
| -------- | ------------------------- | ---- | -------------------------|
| type     | string                    | 是   | 关闭对应的监听事件，支持关闭事件`'toggleFavorite'`。            |
| callback | (assetId: string) => void | 否   | 回调函数，参数assetId是媒体ID。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('toggleFavorite');
```

## off('skipToQueueItem')<sup>10+</sup>

off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void

取消播放列表单项选中的事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明    |
| -------- | ------------------------ | ---- | ----------------------|
| type     | string                   | 是   | 关闭对应的监听事件，支持关闭事件`'skipToQueueItem'`。    |
| callback | (itemId: number) => void | 否   | 回调函数，参数itemId是播放列表单项ID。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | --------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('skipToQueueItem');
```

## off('handleKeyEvent')<sup>10+</sup>

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

取消按键事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型  |   必填 | 说明     |
| -------- | --------- | ---- | --------- |
| type     | string    | 是   | 关闭对应的监听事件，支持关闭事件`'handleKeyEvent'`。             |
| callback | (event: [KeyEvent](../apis-input-kit/js-apis-keyevent.md)) => void | 否   | 回调函数，参数event是按键事件。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('handleKeyEvent');
```

## off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

取消播放设备变化的事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型 | 必填 | 说明   |
| -------- | ------------------------| ---- | -----------------------|
| type     | string                                                  | 是   | 关闭对应的监听事件，支持关闭事件`'outputDeviceChange'`。     |
| callback | (state: [ConnectionState](arkts-apis-avsession-e.md#connectionstate10), device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | 否   | 回调函数，参数device是设备相关信息。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('outputDeviceChange');
```

## off('commonCommand')<sup>10+</sup>

off(type: 'commonCommand', callback?: (command: string, args: {[key: string]: Object}) => void): void

取消自定义控制命令的变化事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型  |   必填 | 说明  |
| -------- | --------- | ---- | ----------------------|
| type     | string    | 是   | 取消对应的监听事件，支持事件`'commonCommand'`。    |
| callback | (command: string, args: {[key: string]: Object}) => void         | 否   | 回调函数，参数command是变化的自定义控制命令名，args为自定义控制命令的参数。<br>该参数为可选参数，若不填写该参数，则认为取消所有对command事件的监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('commonCommand');
```

## on('answer')<sup>11+</sup>

on(type: 'answer', callback: Callback\<void>): void

设置通话接听的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型   |  必填 | 说明     |
| -------- | --------- | ---- | --------- |
| type     | string    | 是   | 事件回调类型，支持事件`'answer'`：当通话接听时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('answer', () => {
  console.info('on call answer');
});
```

## off('answer')<sup>11+</sup>

off(type: 'answer', callback?: Callback\<void>): void

取消通话接听事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'answer'`。 |
| callback | Callback\<void>     | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('answer');
```

## on('hangUp')<sup>11+</sup>

on(type: 'hangUp', callback: Callback\<void>): void

设置通话挂断的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型  |   必填 | 说明     |
| -------- | --------- | ---- | --------- |
| type     | string    | 是   | 事件回调类型，支持事件`'hangUp'`：当通话挂断时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数。                                             |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('hangUp', () => {
  console.info('on call hangUp');
});
```

## off('hangUp')<sup>11+</sup>

off(type: 'hangUp', callback?: Callback\<void>): void

取消通话挂断事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'hangUp'`。 |
| callback | Callback\<void>      | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('hangUp');
```

## on('toggleCallMute')<sup>11+</sup>

on(type: 'toggleCallMute', callback: Callback\<void>): void

设置通话静音的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型  |   必填 | 说明     |
| -------- | --------- | ---- | --------- |
| type     | string    | 是   | 事件回调类型，支持事件`'toggleCallMute'`：当通话静音或解除静音时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数。                                             |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('toggleCallMute', () => {
  console.info('on call toggleCallMute');
});
```

## off('toggleCallMute')<sup>11+</sup>

off(type: 'toggleCallMute', callback?: Callback\<void>): void

取消通话静音事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'toggleCallMute'`。 |
| callback | Callback\<void>    | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('toggleCallMute');
```

## on('castDisplayChange')<sup>12+</sup>

on(type: 'castDisplayChange', callback: Callback\<CastDisplayInfo>): void

设置扩展屏投播显示设备变化的监听事件。

每个指令支持注册多个回调，如果需要只执行最新监听，需要先注销旧的监听，否则新旧监听都会触发回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string    | 是   | 事件回调类型，支持事件`'castDisplayChange'`：当扩展屏投播显示设备变化时触发事件。 |
| callback | Callback\<[CastDisplayInfo](arkts-apis-avsession-i.md#castdisplayinfo12)\>   | 是   | 回调函数。参数是扩展屏投播显示设备信息。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

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

取消扩展屏投播显示设备变化事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string    | 是   | 关闭对应的监听事件，支持的事件是`'castDisplayChange'`。 |
| callback | Callback\<[CastDisplayInfo](arkts-apis-avsession-i.md#castdisplayinfo12)\>  | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('castDisplayChange');
```

## stopCasting<sup>10+</sup>

stopCasting(callback: AsyncCallback\<void>): void

结束投播。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600109  | The remote connection is not established. |

**示例：**

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

结束投播。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当成功结束投播，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 6600109  | The remote connection is not established. |

**示例：**

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

使用同步方法获取当前输出设备信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------| --------------------------------- |
| [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10) | 当前输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息 |
|---------| --------------------------------------- |
| 6600101 | Session service exception. |
| 6600102 | The session does not exist. |

**示例：**

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

获取当前系统中所有支持扩展屏投播的显示设备。通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**返回值：**

| 类型                                            | 说明                              |
| ----------------| --------------------------------- |
| Promise<Array<[CastDisplayInfo](arkts-apis-avsession-i.md#castdisplayinfo12)>>| Promise对象，返回当前系统中所有支持扩展屏投播的显示设备。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息 |
|---------| --------------------------------------- |
| 6600101 | Session service exception. |
| 6600102 | The session does not exist. |

**示例：**

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

设置媒体id播放监听事件。

> **说明：**
> 从 API version 11 开始支持，从 API version 20 开始废弃。建议使用[on('playWithAssetId')](#onplaywithassetid20)设置媒体id播放监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明     |
| -------- | -------------------- | ---- | --------- |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playFromAssetId'`，当媒体id播放时，触发该事件回调。 |
| callback | (assetId: number) => void | 是   | 回调函数。参数assetId是媒体id。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playFromAssetId', (assetId: number) => {
  console.info('on playFromAssetId entry');
});
```

## off('playFromAssetId')<sup>(deprecated)</sup>

off(type: 'playFromAssetId', callback?: (assetId: number) => void): void

取消媒体id播放事件监听。指定callback，可取消对应监听；未指定callback，取消所有事件监听。

> **说明：**
> 从 API version 11 开始支持，从 API version 20 开始废弃。建议使用[off('playWithAssetId')](#offplaywithassetid20)取消媒体id播放事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                   |
| -------- | -------------------- | ---- | ---------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'playFromAssetId'`。 |
| callback | (assetId: number) => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。参数assetId是媒体id。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------|
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playFromAssetId');
```

## on('customDataChange')<sup>20+</sup>

on(type: 'customDataChange', callback: Callback\<Record\<string, Object>>): void

注册从远程设备发送的自定义数据的监听器。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 事件回调类型，支持事件'customDataChange'，当媒体提供方发送自定义数据时，触发该事件。 |
| callback | Callback\<Record\<string, Object>> | 是   | 回调函数，用于接收自定义数据。                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist.                                  |

**示例：**

```ts
currentAVSession.on('customDataChange', (callback) => {
    console.info(`Caught customDataChange event,the new callback is: ${JSON.stringify(callback)}`);
});
```

## off('customDataChange')<sup>20+</sup>

off(type: 'customDataChange', callback?: Callback\<Record\<string, Object>>): void

取消自定义数据监听。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | 是   | 取消对应的监听事件，支持的事件是'customDataChange'。         |
| callback | Callback\<Record\<string, Object>> | 否   | 注册监听事件时的回调函数。该参数为可选参数，若不填写该参数，则认为取消会话所有与此事件相关的监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist.                                  |

**示例：**

```ts
currentAVSession.off('customDataChange');
```
