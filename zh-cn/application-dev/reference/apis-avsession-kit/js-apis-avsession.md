# @ohos.multimedia.avsession (媒体会话管理)

媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。

该模块提供以下媒体会话相关的常用功能：

- [AVSession](#avsession10) : 会话，可用于设置元数据、播放状态信息等操作。
- [AVSessionController](#avsessioncontroller10): 会话控制器，可用于查看会话ID，完成对会话发送命令及事件，获取会话元数据、播放状态信息等操作。
- [AVCastController](#avcastcontroller10): 投播控制器，可用于投播场景下，完成播放控制、远端播放状态监听、远端播放状态信息获取等操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>

创建会话对象，一个Ability只能存在一个会话，重复创建会失败，结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                           |
| ------ | ------------------------------- | ---- | ------------------------------ |
| context| [Context](../apis-ability-kit/js-apis-inner-app-context.md) | 是| 需要使用UIAbilityContext，用于系统获取应用组件的相关信息。 |
| tag    | string                          | 是   | 会话的自定义名称。             |
| type   | [AVSessionType](#avsessiontype10) | 是   | 会话类型。 |

**返回值：**

| 类型                              | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSession](#avsession10)\> | Promise对象。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string;  // 供后续函数入参使用

avSession.createAVSession(context, tag, "audio").then((data: avSession.AVSession) => {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
}).catch((err: BusinessError) => {
  console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void

创建会话对象，一个Ability只能存在一个会话，重复创建会失败，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context| [Context](../apis-ability-kit/js-apis-inner-app-context.md) | 是| 需要使用UIAbilityContext，用于系统获取应用组件的相关信息。     |
| tag      | string                                  | 是   | 会话的自定义名称。                                           |
| type     | [AVSessionType](#avsessiontype10)         | 是   | 会话类型。                               |
| callback | AsyncCallback<[AVSession](#avsession10)\> | 是   | 回调函数。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string;  // 供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    sessionId = currentAVSession.sessionId;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});
```

## ProtocolType<sup>11+</sup>

远端设备支持的协议类型的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| TYPE_LOCAL<sup>11+</sup>      | 0    | 本地设备，包括设备本身的内置扬声器或音频插孔、A2DP 设备。 |
| TYPE_CAST_PLUS_STREAM<sup>11+</sup>      | 2    | Cast+的Stream模式。表示媒体正在其他设备上展示。 |
| TYPE_DLNA<sup>12+</sup>      | 4    | DLNA协议。表示媒体正在其他设备上展示。 |

## DistributedSessionType<sup>16+</sup>

远端分布式设备支持的会话类型。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                                     | 值 | 说明                        |
|----------------------------------------|---|---------------------------|
| TYPE_SESSION_REMOTE      | 0 | 远端设备会话。       |
| TYPE_SESSION_MIGRATE_IN  | 1 | 迁移至本端的设备会话。 |
| TYPE_SESSION_MIGRATE_OUT | 2 | 迁移至远端的设备会话。 |

## AVSessionType<sup>10+<sup>

type AVSessionType = 'audio' | 'video' | 'voice_call' | 'video_call'

当前会话支持的会话类型。

该类型可取的值为下表字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 类型  | 说明 |
| -----  | ---- |
| 'audio' | 音频 |
| 'video' | 视频 |
| 'voice_call'<sup>11+<sup> | 音频通话 |
| 'video_call'<sup>12+<sup> | 视频通话 |

## AVSession<sup>10+</sup>

调用[avSession.createAVSession](#avsessioncreateavsession10)后，返回会话的实例，可以获得会话ID，完成设置元数据，播放状态信息等操作。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型   | 可读 | 可写 | 说明                          |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId | string | 是   | 否   | AVSession对象唯一的会话标识。 |
| sessionType| [AVSessionType](#avsessiontype10) | 是   | 否   | AVSession会话类型。 |

**示例：**

```ts
let sessionId: string = currentAVSession.sessionId;
let sessionType: avSession.AVSessionType = currentAVSession.sessionType;
```

### setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata): Promise\<void>

设置会话元数据。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| data   | [AVMetadata](#avmetadata10) | 是   | 会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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
  previousAssetId: "121277",
  nextAssetId: "121279"
};
currentAVSession.setAVMetadata(metadata).then(() => {
  console.info('SetAVMetadata successfully');
}).catch((err: BusinessError) => {
  console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void

设置会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [AVMetadata](#avmetadata10) | 是   | 会话元数据。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata): Promise\<void>

设置通话会话元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| data   | [CallMetadata](#callmetadata11) | 是   | 通话会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当通话元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

let value = await resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI');
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

### setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata, callback: AsyncCallback\<void>): void

设置通话会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [CallMetadata](#callmetadata11) | 是   | 通话会话元数据。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当通话元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function setCallMetadata() {
  let value = await resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI');
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

### setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState): Promise\<void>

设置通话状态。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| state   | [AVCallState](#avcallstate11) | 是   | 通话状态。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当通话元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState, callback: AsyncCallback\<void>): void

设置通话状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state     | [AVCallState](#avcallstate11) | 是   | 通话状态。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当通话元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState): Promise\<void>

设置会话播放状态。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明                                           |
| ------ | ----------------------------------- | ---- | ---------------------------------------------- |
| state   | [AVPlaybackState](#avplaybackstate10) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放状态设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void

设置会话播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                           |
| -------- | ----------------------------------- | ---- | ---------------------------------------------- |
| state     | [AVPlaybackState](#avplaybackstate10) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |
| callback | AsyncCallback\<void>                | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent): Promise\<void>

设置一个WantAgent用于拉起会话的Ability。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| ability | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当Ability设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgentInfo对象
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

### setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void

设置一个WantAgent用于拉起会话的Ability。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                                                         |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| ability  | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。  |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当Ability设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { wantAgent } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// WantAgentInfo对象
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

### dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>

媒体提供方设置一个会话内自定义事件，包括事件名和键值对形式的事件内容, 结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| event | string | 是   | 需要设置的会话事件的名称 |
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
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

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
```

### dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

媒体提供方设置一个会话内自定义事件，包括事件名和键值对形式的事件内容, 结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| event | string | 是   | 需要设置的会话事件的名称 |
| args | {[key: string]: Object} | 是   | 需要传递的会话事件内容。 |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当会话事件设置成功，err为undefined，否则返回错误对象。 |

> **说明：**

> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

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
```

### setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>): Promise\<void>

设置媒体播放列表。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                 | 必填 | 说明                               |
| ------ | ------------------------------------ | ---- | ---------------------------------- |
| items  | Array<[AVQueueItem](#avqueueitem10)\> | 是   | 播放列表单项的队列，用以表示播放列表。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放列表设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function setAVQueueItems() {
  let value = await resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI');
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

### setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>, callback: AsyncCallback\<void>): void

设置媒体播放列表。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ----------------------------------------------------------- |
| items    | Array<[AVQueueItem](#avqueueitem10)\> | 是   | 播放列表单项的队列，用以表示播放列表。                          |
| callback | AsyncCallback\<void>                 | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { image } from '@kit.ImageKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function setAVQueueItems() {
  let value = await resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI');
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

### setAVQueueTitle<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### setAVQueueTitle<sup>10+</sup>

setAVQueueTitle(title: string, callback: AsyncCallback\<void>): void

设置媒体播放列表名称。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| title    | string                | 是   | 播放列表名称字段。                          |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}): Promise\<void>

媒体提供方设置键值对形式的自定义媒体数据包, 结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| extras | {[key: string]: Object} | 是   | 需要传递的自定义媒体数据包键值对 |

> **说明：**

> 参数extras支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当自定义媒体数据包设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}).then(() => {
    console.info('setExtras successfully');
  }).catch((err: BusinessError) => {
    console.error(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

### setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void

媒体提供方设置键值对形式的自定义媒体数据包, 结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| extras | {[key: string]: Object} | 是   | 需要传递的自定义媒体数据包键值对 |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当自定义媒体数据包设置成功，err为undefined，否则返回错误对象。 |

> **说明：**

> 参数extras支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

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
```

### getController<sup>10+</sup>

getController(): Promise\<AVSessionController>

获取本会话对应的控制器。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                 | 说明                          |
| ---------------------------------------------------- | ----------------------------- |
| Promise<[AVSessionController](#avsessioncontroller10)> | Promise对象。返回会话控制器。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avsessionController: avSession.AVSessionController;
currentAVSession.getController().then((avcontroller: avSession.AVSessionController) => {
  avsessionController = avcontroller;
  console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
}).catch((err: BusinessError) => {
  console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getController<sup>10+</sup>

getController(callback: AsyncCallback\<AVSessionController>): void

获取本会话相应的控制器。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                       |
| -------- | ----------------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVSessionController](#avsessioncontroller10)\> | 是   | 回调函数。返回会话控制器。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avsessionController: avSession.AVSessionController;
currentAVSession.getController((err: BusinessError, avcontroller: avSession.AVSessionController) => {
  if (err) {
    console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    avsessionController = avcontroller;
    console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
  }
});
```

### getAVCastController<sup>10+</sup>

getAVCastController(): Promise\<AVCastController>

设备建立连接后，获取投播控制器。结果通过Promise异步回调方式返回。如果 avsession 未处于投播状态，则控制器将返回 null。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise<[AVCastController](#avcastcontroller10)\>  | Promise对象。返回投播控制器实例。 |

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

### getAVCastController<sup>10+</sup>

getAVCastController(callback: AsyncCallback\<AVCastController>): void

设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。如果 avsession 未处于投播状态，则控制器将返回 null。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | 是   | 回调函数，返回投播控制器实例。 |

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

### getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

通过会话获取播放设备信息。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                           | 说明                              |
| ---------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo10)> | Promise对象。返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

通过会话获取播放设备相关信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                           |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo10)\> | 是   | 回调函数，返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### activate<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### activate<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### deactivate<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### deactivate<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### destroy<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### destroy<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### on('play')<sup>10+</sup>

on(type: 'play', callback: () => void): void

设置播放命令监听事件。注册该监听，说明应用支持播放指令。

每个播放命令仅支持注册一个回调，如果注册新的回调，将替换前一个回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件为`'play'`当播放命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。                                        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('play', () => {
  console.info('on play entry');
});
```

### on('pause')<sup>10+</sup>

on(type: 'pause', callback: () => void): void

设置暂停命令监听事件。注册该监听，说明应用支持暂停指令。

每个播放命令仅支持注册一个回调，如果注册新的回调，将替换前一个回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件为`'pause'`，当暂停命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('pause', () => {
  console.info('on pause entry');
});
```

### on('stop')<sup>10+</sup>

on(type:'stop', callback: () => void): void

设置停止命令监听事件。注册该监听，说明应用支持停止指令。

每个播放命令仅支持注册一个回调，如果注册新的回调，将替换前一个回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'stop'`，当停止命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('stop', () => {
  console.info('on stop entry');
});
```

### on('playNext')<sup>10+</sup>

on(type:'playNext', callback: () => void): void

设置播放下一首命令监听事件。注册该监听，说明应用支持下一首指令。

每个播放命令仅支持注册一个回调，如果注册新的回调，将替换前一个回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playNext'`，当播放下一首命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playNext', () => {
  console.info('on playNext entry');
});
```

### on('playPrevious')<sup>10+</sup>

on(type:'playPrevious', callback: () => void): void

设置播放上一首命令监听事件。注册该监听，说明应用支持上一首指令。

每个播放命令仅支持注册一个回调，如果注册新的回调，将替换前一个回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playPrevious'`当播放上一首命令被发送到会话时，触发该事件回调。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。       |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playPrevious', () => {
  console.info('on playPrevious entry');
});
```

### on('fastForward')<sup>10+</sup>

on(type: 'fastForward', callback: (time?: number) => void): void

设置快进命令监听事件。注册该监听，说明应用支持快进指令。

每个播放命令仅支持注册一个回调，如果注册新的回调，将替换前一个回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是 `'fastForward'`，当快进命令被发送到会话时，触发该事件回调。 |
| callback | (time?: number) => void | 是   | 回调函数。参数time是时间节点，单位为秒。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('fastForward', (time?: number) => {
  console.info('on fastForward entry');
});
```

### on('rewind')<sup>10+</sup>

on(type:'rewind', callback: (time?: number) => void): void

设置快退命令监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'rewind'`，当快退命令被发送到会话时，触发该事件回调。 |
| callback | (time?: number) => void | 是   | 回调函数。参数time是时间节点，单位为秒。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('rewind', (time?: number) => {
  console.info('on rewind entry');
});
```

### on('playFromAssetId')<sup>11+</sup>

on(type:'playFromAssetId', callback: (assetId: number) => void): void

设置媒体id播放监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playFromAssetId'`，当媒体id播放时，触发该事件回调。 |
| callback | callback: (assetId: number) => void | 是   | 回调函数。参数assetId是媒体id。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playFromAssetId', (assetId: number) => {
  console.info('on playFromAssetId entry');
});
```

### off('playFromAssetId')<sup>11+</sup>

off(type: 'playFromAssetId', callback?: (assetId: number) => void): void

取消媒体id播放事件监听，关闭后，不再进行该事件回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'playFromAssetId'`。 |
| callback | callback: (assetId: number) => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。参数assetId是媒体id。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playFromAssetId');
```

### on('seek')<sup>10+</sup>

on(type: 'seek', callback: (time: number) => void): void

设置跳转节点监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 事件回调类型，支持事件`'seek'`：当跳转节点命令被发送到会话时，触发该事件。 |
| callback | (time: number) => void | 是   | 回调函数。参数time是时间节点，单位为毫秒。                   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('seek', (time: number) => {
  console.info(`on seek entry time : ${time}`);
});
```

### on('setSpeed')<sup>10+</sup>

on(type: 'setSpeed', callback: (speed: number) => void): void

设置播放速率的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | 是   | 事件回调类型，支持事件`'setSpeed'`：当设置播放速率的命令被发送到会话时，触发该事件。 |
| callback | (speed: number) => void | 是   | 回调函数。参数speed是播放倍速。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('setSpeed', (speed: number) => {
  console.info(`on setSpeed speed : ${speed}`);
});
```

### on('setLoopMode')<sup>10+</sup>

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

设置循环模式的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                   | 必填 | 说明  |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | 是   | 事件回调类型，支持事件`'setLoopMode'`：当设置循环模式的命令被发送到会话时，触发该事件。 |
| callback | (mode: [LoopMode](#loopmode10)) => void | 是   | 回调函数。参数mode是循环模式。                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('setLoopMode', (mode: avSession.LoopMode) => {
  console.info(`on setLoopMode mode : ${mode}`);
});
```

### on('toggleFavorite')<sup>10+</sup>

on(type: 'toggleFavorite', callback: (assetId: string) => void): void

设置是否收藏的监听事件

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 事件回调类型，支持事件`'toggleFavorite'`：当是否收藏的命令被发送到会话时，触发该事件。 |
| callback | (assetId: string) => void | 是   | 回调函数。参数assetId是媒体ID。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('toggleFavorite', (assetId: string) => {
  console.info(`on toggleFavorite mode : ${assetId}`);
});
```

### on('skipToQueueItem')<sup>10+</sup>

on(type: 'skipToQueueItem', callback: (itemId: number) => void): void

设置播放列表其中某项被选中的监听事件，session端可以选择对这个单项歌曲进行播放。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                                                      |
| -------- | ------------------------ | ---- | ---------------------------------------------------------------------------------------- |
| type     | string                   | 是   | 事件回调类型，支持事件`'skipToQueueItem'`：当播放列表选中单项的命令被发送到会话时，触发该事件。 |
| callback | (itemId: number) => void | 是   | 回调函数。参数itemId是选中的播放列表项的ID。                                                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('skipToQueueItem', (itemId: number) => {
  console.info(`on skipToQueueItem id : ${itemId}`);
});
```

### on('handleKeyEvent')<sup>10+</sup>

on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void

设置蓝牙/有线等外设接入的按键输入事件的监听，监听多媒体按键事件中播放、暂停、上下一首、快进、快退的指令。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'handleKeyEvent'`：当按键事件被发送到会话时，触发该事件。 |
| callback | (event: [KeyEvent](../apis-input-kit/js-apis-keyevent.md)) => void | 是   | 回调函数。参数event是按键事件。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

设置播放设备变化的监听事件。应用接入[系统投播组件](ohos-multimedia-avcastpicker.md)，当用户通过组件切换设备时，会收到设备切换的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | 是   | 事件回调类型，支持事件`'outputDeviceChange'`：当播放设备变化时，触发该事件。 |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 是   | 回调函数，参数device是设备相关信息。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange device : ${device}`);
});
```

### on('commonCommand')<sup>10+</sup>

on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void

设置自定义控制命令变化的监听器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'commonCommand'`：当自定义控制命令变化时，触发该事件。 |
| callback | (command: string, args: {[key:string]: Object}) => void         | 是   | 回调函数，command为变化的自定义控制命令名，args为自定义控制命令的参数，参数内容与[sendCommonCommand](#sendcommoncommand10)方法设置的参数内容完全一致。          |

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

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

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
```

### off('play')<sup>10+</sup>

off(type: 'play', callback?: () => void): void

取消会话播放事件监听，关闭后，不再进行该事件回调。

取消回调时，需要更新支持的命令列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'play'`|
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('play');
```

### off('pause')<sup>10+</sup>

off(type: 'pause', callback?: () => void): void

取消会话暂停事件监听，关闭后，不再进行该事件回调。

取消回调时，需要更新支持的命令列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'pause'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('pause');
```

### off('stop')<sup>10+</sup>

off(type: 'stop', callback?: () => void): void

取消会话停止事件监听，关闭后，不再进行该事件回调。

取消回调时，需要更新支持的命令列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'stop'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('stop');
```

### off('playNext')<sup>10+</sup>

off(type: 'playNext', callback?: () => void): void

取消会话播放下一首事件监听，关闭后，不再进行该事件回调。

取消回调时，需要更新支持的命令列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是 `'playNext'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playNext');
```

### off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious', callback?: () => void): void

取消会话播放上一首事件监听，关闭后，不再进行该事件回调。

取消回调时，需要更新支持的命令列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'playPrevious'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playPrevious');
```

### off('fastForward')<sup>10+</sup>

off(type: 'fastForward', callback?: () => void): void

取消会话快进事件监听，关闭后，不再进行该事件回调。

取消回调时，需要更新支持的命令列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'fastForward'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('fastForward');
```

### off('rewind')<sup>10+</sup>

off(type: 'rewind', callback?: () => void): void

取消会话快退事件监听，关闭后，不再进行该事件回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'rewind'`。 |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('rewind');
```

### off('seek')<sup>10+</sup>

off(type: 'seek', callback?: (time: number) => void): void

取消监听跳转节点事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                          |
| -------- | ---------------------- | ---- | ----------------------------------------- |
| type     | string                 | 是   | 关闭对应的监听事件，支持关闭事件`'seek'`。       |
| callback | (time: number) => void | 否   | 回调函数，参数time是时间节点，单位为毫秒。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('seek');
```

### off('setSpeed')<sup>10+</sup>

off(type: 'setSpeed', callback?: (speed: number) => void): void

取消监听播放速率变化事件。

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
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('setSpeed');
```

### off('setLoopMode')<sup>10+</sup>

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

取消监听循环模式变化事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明     |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | 是   | 关闭对应的监听事件，支持关闭事件`'setLoopMode'`。|
| callback | (mode: [LoopMode](#loopmode10)) => void | 否   | 回调函数，参数mode是循环模式。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('setLoopMode');
```

### off('toggleFavorite')<sup>10+</sup>

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

取消监听是否收藏的事件

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | -------------------------------------------------------- |
| type     | string                    | 是   | 关闭对应的监听事件，支持关闭事件`'toggleFavorite'`。            |
| callback | (assetId: string) => void | 否   | 回调函数，参数assetId是媒体ID。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('toggleFavorite');
```

### off('skipToQueueItem')<sup>10+</sup>

off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void

取消监听播放列表单项选中的事件

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                                                                                                                        |
| -------- | ------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| type     | string                   | 是   | 关闭对应的监听事件，支持关闭事件`'skipToQueueItem'`。                                                                                                          |
| callback | (itemId: number) => void | 否   | 回调函数，参数itemId是播放列表单项ID。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('skipToQueueItem');
```

### off('handleKeyEvent')<sup>10+</sup>

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

取消监听按键事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 关闭对应的监听事件，支持关闭事件`'handleKeyEvent'`。             |
| callback | (event: [KeyEvent](../apis-input-kit/js-apis-keyevent.md)) => void | 否   | 回调函数，参数event是按键事件。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('handleKeyEvent');
```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

取消监听播放设备变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                      |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | 是   | 关闭对应的监听事件，支持关闭事件`'outputDeviceChange'`。     |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 否   | 回调函数，参数device是设备相关信息。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('outputDeviceChange');
```


### off('commonCommand')<sup>10+</sup>

off(type: 'commonCommand', callback?: (command: string, args: {[key:string]: Object}) => void): void

取消监听自定义控制命令的变化。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'commonCommand'`。    |
| callback | (command: string, args: {[key:string]: Object}) => void         | 否   | 回调函数，参数command是变化的自定义控制命令名，args为自定义控制命令的参数。<br>该参数为可选参数，若不填写该参数，则认为取消所有对command事件的监听。                      |

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

### on('answer')<sup>11+</sup>

on(type: 'answer', callback: Callback\<void>): void;

设置通话接听的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'answer'`：当通话接听时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数                      |

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

### off('answer')<sup>11+</sup>

off(type: 'answer', callback?: Callback\<void>): void;

取消通话接听事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'answer'`。 |
| callback | Callback\<void>     | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('answer');
```

### on('hangUp')<sup>11+</sup>

on(type: 'hangUp', callback: Callback\<void>): void;

设置通话挂断的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'hangUp'`：当通话挂断时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数                                             |

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

### off('hangUp')<sup>11+</sup>

off(type: 'hangUp', callback?: Callback\<void>): void;

取消通话挂断事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'hangUp'`。 |
| callback | Callback\<void>      | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('hangUp');
```

### on('toggleCallMute')<sup>11+</sup>

on(type: 'toggleCallMute', callback: Callback\<void>): void;

设置通话静音的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'toggleCallMute'`：当通话静音或解除静音时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数                                             |

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

### off('toggleCallMute')<sup>11+</sup>

off(type: 'toggleCallMute', callback?: Callback\<void>): void;

取消通话静音事件的监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'toggleCallMute'`。 |
| callback | Callback\<void>    | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('toggleCallMute');
```

### on('castDisplayChange')<sup>12+</sup>

on(type: 'castDisplayChange', callback: Callback\<CastDisplayInfo>): void

设置扩展屏投播显示设备变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'castDisplayChange'`：当扩展屏投播显示设备变化时触发事件。 |
| callback | Callback<[CastDisplayInfo](#castdisplayinfo12)>   | 是   | 回调函数。参数是扩展屏投播显示设备信息。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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
### off('castDisplayChange')<sup>12+</sup>

 off(type: 'castDisplayChange', callback?: Callback\<CastDisplayInfo>): void

取消扩展屏投播显示设备变化事件监听，关闭后，不再进行该事件回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string                                                       | 是   | 关闭对应的监听事件，支持的事件是`'castDisplayChange'`。 |
| callback | Callback<[CastDisplayInfo](#castdisplayinfo12)>   | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('castDisplayChange');
```

### stopCasting<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### stopCasting<sup>10+</sup>

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
| -------- | ---------------------------------------- |
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

### getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

使用同步方法获取当前输出设备信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| [OutputDeviceInfo](#outputdeviceinfo10) | 当前输出设备信息。 |

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
### getAllCastDisplays<sup>12+</sup>

getAllCastDisplays(): Promise<Array\<CastDisplayInfo>>

获取当前系统中所有支持扩展屏投播的显示设备。通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| Promise<Array<[CastDisplayInfo](#castdisplayinfo12)>>| Promise对象，返回当前系统中所有支持扩展屏投播的显示设备。 |

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

## AVCastControlCommandType<sup>10+</sup>

type AVCastControlCommandType = 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind' |
  'seek' | 'setVolume' | 'setSpeed' | 'setLoopMode' | 'toggleFavorite' | 'toggleMute'

投播控制器可传递的命令。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 类型             | 说明         |
| ---------------- | ------------ |
| 'play'           | 播放         |
| 'pause'          | 暂停         |
| 'stop'           | 停止         |
| 'playNext'       | 下一首       |
| 'playPrevious'   | 上一首       |
| 'fastForward'    | 快进         |
| 'rewind'         | 快退         |
| 'seek'           | 跳转某一节点 |
| 'setVolume'      | 设置音量     |
| 'setSpeed'       | 设置播放倍速 |
| 'setLoopMode'    | 设置循环模式 |
| 'toggleFavorite' | 是否收藏     |
| 'toggleMute'     | 设置静音状态 |

## AVCastControlCommand<sup>10+</sup>

投播控制器接受的命令的对象描述。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称      | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVCastControlCommandType](#avcastcontrolcommandtype10)     | 是   | 命令           |
| parameter | [media.PlaybackSpeed](../apis-media-kit/js-apis-media.md#playbackspeed8) &#124; number &#124; string &#124; [LoopMode](#loopmode10) | 否   | 命令对应的参数 |

## AVCastController<sup>10+</sup>

在投播建立后，调用[avSession.getAVCastController](#getavcastcontroller10)后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

获取当前的远端播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[AVPlaybackState](#avplaybackstate10)\> | 是   | 回调函数，返回远端播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {
  if (err) {
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('getAVPlaybackState : SUCCESS');
  }
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>

获取当前的远端播放状态。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise<[AVPlaybackState](#avplaybackstate10)\>  | Promise对象。返回远端播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info('getAVPlaybackState : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand): Promise\<void>

通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVCastControlCommand](#avcastcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avCommand: avSession.AVCastControlCommand = {command:'play'};
aVCastController.sendControlCommand(avCommand).then(() => {
  console.info('SendControlCommand successfully');
}).catch((err: BusinessError) => {
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void>): void

通过会话控制器发送命令到其对应的会话。结果通过callback异步回调方式返回。


**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVCastControlCommand](#avcastcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avCommand: avSession.AVCastControlCommand = {command:'play'};
aVCastController.sendControlCommand(avCommand, (err: BusinessError) => {
  if (err) {
    console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SendControlCommand successfully');
  }
});
```

### prepare<sup>10+</sup>

prepare(item: AVQueueItem, callback: AsyncCallback\<void>): void

准备播放媒体资源，即进行播放资源的加载和缓冲。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |   

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲
aVCastController.prepare(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('prepare successfully');
  }
});
```


### prepare<sup>10+</sup>

prepare(item: AVQueueItem): Promise\<void>

准备播放媒体资源，即进行播放资源的加载和缓冲。结果通过Promise异步回调方式返回。


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲
aVCastController.prepare(playItem).then(() => {
  console.info('prepare successfully');
}).catch((err: BusinessError) => {
  console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### start<sup>10+</sup>

start(item: AVQueueItem, callback: AsyncCallback\<void>): void

启动播放某个媒体资源。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |   

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};

// 启动播放
aVCastController.start(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`start BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('start successfully');
  }
});
```

### start<sup>10+</sup>

start(item: AVQueueItem): Promise\<void>

启动播放某个媒体资源。结果通过Promise异步回调方式返回。


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// 启动播放
aVCastController.start(playItem).then(() => {
  console.info('start successfully');
}).catch((err: BusinessError) => {
  console.error(`start BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getCurrentItem<sup>10+</sup>

getCurrentItem(callback: AsyncCallback\<AVQueueItem>): void

获取当前投播的资源信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<[AVQueueItem](#avqueueitem10)>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getCurrentItem((err: BusinessError, value: avSession.AVQueueItem) => {
  if (err) {
    console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('getCurrentItem successfully');
  }
});
```

### getCurrentItem<sup>10+</sup>

getCurrentItem(): Promise\<AVQueueItem>

获取当前投播的资源信息。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<[AVQueueItem](#avqueueitem10)> | Promise对象，返回当前的播放资源，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getCurrentItem().then((value: avSession.AVQueueItem) => {
  console.info('getCurrentItem successfully');
}).catch((err: BusinessError) => {
  console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getValidCommands<sup>11+</sup>

getValidCommands(callback: AsyncCallback<Array\<AVCastControlCommandType>>): void

获取当前支持的命令。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | Array<[AVCastControlCommandType](#avcastcontrolcommandtype10)> | 是 | 回调函数。返回当前支持的命令。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getValidCommands((err: BusinessError, state: avSession.AVCastControlCommandType) => {
  if (err) {
    console.error(`getValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('getValidCommands successfully');
  }
});
```

### getValidCommands<sup>11+</sup>

getValidCommands(): Promise<Array\<AVCastControlCommandType>>

获取当前支持的命令。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型 | 说明 |
| -------------- | ----------------------------- |
| Promise<Array\<[AVCastControlCommandType](#avcastcontrolcommandtype10)>> | Promise对象，返回当前支持的命令。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getValidCommands().then((state: avSession.AVCastControlCommandType) => {
  console.info('getValidCommands successfully');
}).catch((err: BusinessError) => {
  console.error(`getValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### processMediaKeyResponse<sup>12+</sup>

processMediaKeyResponse(assetId: string, response: Uint8Array): Promise\<void>

在线DRM资源投播时，处理许可证响应。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| assetId | string                  | 是   | 媒体ID。 |
| response | Uint8Array             | 是   | 许可证响应。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象，当处理许可证响应成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
let keyRequestCallback: avSession.KeyRequestCallback = async(assetId: string, requestData: Uint8Array) => {
  // 根据assetId获取对应的DRM url
  let drmUrl = 'http://license.xxx.xxx.com:8080/drmproxy/getLicense';
  // 从服务器获取许可证，需要开发者根据实际情况进行赋值
  let licenseResponseData: Uint8Array = new Uint8Array();
  console.info(`Succeeded in get license by ${drmUrl}.`);
  aVCastController.processMediaKeyResponse(assetId, licenseResponseData);
}
```

### release<sup>11+</sup>

release(callback: AsyncCallback\<void>): void

销毁当前controller，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void>       | 是   | 回调函数。当命令执行成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.release((err: BusinessError) => {
  if (err) {
    console.error(`release BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('release successfully');
  }
});
```

### release<sup>11+</sup>

release(): Promise\<void>

销毁当前controller。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象，controller销毁成功，无结果返回，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.release().then(() => {
  console.info('release successfully');
}).catch((err: BusinessError) => {
  console.error(`release BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void): void

设置播放状态变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playbackStateChange'`：当播放状态变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注播放状态所有字段变化；Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\> 表示关注Array中的字段变化。 |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | 是   | 回调函数，参数state是变化后的播放状态。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

let playbackFilter: Array<keyof avSession.AVPlaybackState> = ['state', 'speed', 'loopMode'];
aVCastController.on('playbackStateChange', playbackFilter, (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});
```

### off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void): void

媒体控制器取消监听播放状态变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playbackStateChange'`。    |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | 否   | 回调函数，参数state是变化后的播放状态。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('playbackStateChange');
```

### on('mediaItemChange')<sup>10+</sup>

on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void

设置投播当前播放媒体内容的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'mediaItemChange'`：当播放的媒体内容变化时，触发该事件。 |
| callback | (callback: [AVQueueItem](#avqueueitem10)) => void         | 是   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('mediaItemChange', (item: avSession.AVQueueItem) => {
  console.info(`on mediaItemChange state : ${item.itemId}`);
});
```

### off('mediaItemChange')<sup>10+</sup>

off(type: 'mediaItemChange'): void

取消设置投播当前播放媒体内容的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'mediaItemChange'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('mediaItemChange');
```

### on('playNext')<sup>10+</sup>

on(type: 'playNext', callback: Callback\<void>): void

设置播放下一首资源的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playNext'`：当播放下一首状态变化时，触发该事件。 |
| callback | Callback\<void\>         | 是   | 回调函数                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('playNext', () => {
  console.info('on playNext');
});
```

### off('playNext')<sup>10+</sup>

off(type: 'playNext'): void

取消设置播放下一首资源的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playNext'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('playNext');
```

### on('playPrevious')<sup>10+</sup>

on(type: 'playPrevious', callback: Callback\<void>): void

设置播放上一首资源的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playPrevious'`：当播放上一首状态变化时，触发该事件。 |
| callback | Callback\<void\>         | 是   | 回调函数                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('playPrevious', () => {
  console.info('on playPrevious');
});
```

### off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious'): void

取消设置播放上一首资源的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playPrevious'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('playPrevious');
```

### on('requestPlay')<sup>11+</sup>

on(type: 'requestPlay', callback: Callback\<AVQueueItem>): void

设置请求播放的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'requestPlay'`：当请求播放状态变化时，触发该事件。 |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void               | 是   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。当监听事件注册成功，err为undefined，否则返回错误对象。  | 

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('requestPlay', (item: avSession.AVQueueItem) => {
  console.info(`on requestPlay state : ${item.itemId}`);
});
```

### off('requestPlay')<sup>11+</sup>

off(type: 'requestPlay', callback?: Callback\<AVQueueItem>): void

取消设置请求播放的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------| ---- | ----------------------------------------------------- |
| type     | string                                                      | 是   | 取消对应的监听事件，支持事件`'requestPlay'`。    |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void              | 否   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('requestPlay');
```

### on('endOfStream')<sup>11+</sup>

on(type: 'endOfStream', callback: Callback\<void>): void

设置播放结束的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | string                                                      | 是   | 事件回调类型，支持事件`'endOfStream'`：当资源播放结束时，触发该事件。 |
| callback | Callback\<void\>                                            | 是   | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('endOfStream', () => {
  console.info('on endOfStream');
});
```

### off('endOfStream')<sup>11+</sup>

off(type: 'endOfStream', callback?: Callback\<void>): void

取消设置播放结束的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------| ---- | ----------------------------------------------------- |
| type     | string                                                      | 是   | 取消对应的监听事件，支持事件`'endOfStream'`。    |
| callback | Callback\<void\>                                            | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('endOfStream');
```

### on('seekDone')<sup>10+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

设置seek结束的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'seekDone'`：当seek结束时，触发该事件。 |
| callback | Callback\<number\>         | 是   | 回调函数，返回seek后播放的位置                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('seekDone', (pos: number) => {
  console.info(`on seekDone pos：${pos} `);
});
```

### off('seekDone')<sup>10+</sup>

off(type: 'seekDone'): void

取消设置seek结束的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'seekDone'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('seekDone');
```

### on('validCommandChange')<sup>11+</sup>

on(type: 'validCommandChange', callback: Callback\<Array\<AVCastControlCommandType>>)

会话支持的有效命令变化监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'validCommandChange'`：当检测到会话的合法命令发生改变时，触发该事件。 |
| callback | Callback<Array<[AVCastControlCommandType](#avcastcontrolcommandtype10)\>\>   | 是   | 回调函数。参数commands是有效命令的集合。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
aVCastController.on('validCommandChange', (validCommands: avSession.AVCastControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

### off('validCommandChange')<sup>11+</sup>

off(type: 'validCommandChange', callback?: Callback\<Array\<AVCastControlCommandType>>)

媒体控制器取消监听会话有效命令变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'validCommandChange'`。         |
| callback | Callback<Array<[AVCastControlCommandType](#avcastcontrolcommandtype10)\>\> | 否   | 回调函数。参数commands是有效命令的集合。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
aVCastController.off('validCommandChange');
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

监听远端播放器的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件。 |
| callback | ErrorCallback | 是   | 错误事件回调方法：远端播放过程中发生的错误，会提供错误码ID和错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)以及[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 5400101  | No memory.            |
| 5400102  | Operation not allowed.   |
| 5400103  | I/O error.             |
| 5400104  | Time out.      |
| 5400105  | Service died.         |
| 5400106  | Unsupport format.     |
| 6600101  | Session service exception.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.on('error', (error: BusinessError) => {
  console.info(`error happened, error code: ${error.code}, error message : ${error.message}.`)
})
```

### off('error')<sup>10+</sup>

off(type: 'error'): void

取消监听播放的错误事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | 是   | 错误事件回调类型，取消注册的事件：'error' |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)以及[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 5400101  | No memory.            |
| 5400102  | Operation not allowed.   |
| 5400103  | I/O error.             |
| 5400104  | Time out.      |
| 5400105  | Service died.         |
| 5400106  | Unsupport format.     |
| 6600101  | Session service exception.     |

**示例：**

```ts
aVCastController.off('error')
```

### on('keyRequest')<sup>12+</sup>

on(type: 'keyRequest', callback: KeyRequestCallback): void

在线DRM资源投播时，设置许可证请求的事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type     | string  | 是   | 事件回调类型，支持事件`'keyRequest'`：当DRM资源播放需要许可证时，触发该事件。 |
| callback | [KeyRequestCallback](#keyrequestcallback12)  | 是   | 回调函数，媒体资源及许可证请求数据。|


**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
let keyRequestCallback: avSession.KeyRequestCallback = async(assetId: string, requestData: Uint8Array) => {
  console.info(`Succeeded in keyRequestCallback. assetId: ${assetId}, requestData: ${requestData}`);
}
aVCastController.on('keyRequest', keyRequestCallback);
```
### off('keyRequest')<sup>12+</sup>

off(type: 'keyRequest', callback?: KeyRequestCallback): void

取消监听许可证请求的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持的事件是`'keyRequest'`。 |
| callback |  [KeyRequestCallback](#keyrequestcallback12)  | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('keyRequest');
```

### on('castControlGenericError')<sup>13+</sup>

on(type: 'castControlGenericError', callback: ErrorCallback): void

监听投播通用错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'castControlGenericError'。 |
| callback | ErrorCallback | 是   | 投播通用错误事件回调方法。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 6611000  | The error code for cast control is unspecified.      |
| 6611001  | An unspecified error occurs in the remote player.   |
| 6611002  | The playback position falls behind the live window.     |
| 6611003  | The process of cast control times out.    |
| 6611004  | The runtime check failed.      |
| 6611100  | Cross-device data transmission is locked.    |
| 6611101  | The specified seek mode is not supported.   |
| 6611102  | The position to seek to is out of the range of the media asset or the specified seek mode is not supported.  |
| 6611103  | The specified playback mode is not supported.       |
| 6611104  | The specified playback speed is not supported.    |
| 6611105  | The action failed because either the media source device or the media sink device has been revoked.   |
| 6611106  | The parameter is invalid, for example, the url is illegal to play.  |
| 6611107  | Allocation of memory failed.  |
| 6611108  | Operation is not allowed.    |

**示例：**

```ts
aVCastController.on('castControlGenericError', (error: BusinessError) => {
  console.info(`castControlGenericError happened, error code: ${error.code}, error message : ${error.message}.`)
})
```

### off('castControlGenericError')<sup>13+</sup>

off(type: 'castControlGenericError', callback?: ErrorCallback): void

取消监听投播通用的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 	取消对应的监听事件，支持的事件是'castControlGenericError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
aVCastController.off('castControlGenericError');
```

### on('castControlIoError')<sup>13+</sup>

on(type: 'castControlIoError', callback: ErrorCallback): void

监听投播输入/输出的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'castControlIoError'。 |
| callback | ErrorCallback | 是   | 投播输入/输出的错误事件回调方法。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 6612000  | An unspecified input/output error occurs.     |
| 6612001  | Network connection failure.   |
| 6612002  | Network timeout.     |
| 6612003  | Invalid "Content-Type" HTTP header.    |
| 6612004  | The HTTP server returns an unexpected HTTP response status code.      |
| 6612005  | The file does not exist.    |
| 6612006  | No permission is granted to perform the IO operation.   |
| 6612007  | Access to cleartext HTTP traffic is not allowed by the app's network security configuration. |
| 6612008  | Reading data out of the data bound.    |
| 6612100  | The media does not contain any contents that can be played.   |
| 6612101  | The media cannot be read, for example, because of dust or scratches.   |
| 6612102  | This resource is already in use. |
| 6612103  | The content using the validity interval has expired.  |
| 6612104  | Using the requested content to play is not allowed.    |
| 6612105  | The use of the allowed content cannot be verified.  |
| 6612106  | The number of times this content has been used as requested has reached the maximum allowed number of uses.  |
| 6612107  | An error occurs when sending packet from source device to sink device.    |

**示例：**

```ts
aVCastController.on('castControlIoError', (error: BusinessError) => {
  console.info(`castControlIoError happened, error code: ${error.code}, error message : ${error.message}.`)
})
```

### off('castControlIoError')<sup>13+</sup>

off(type: 'castControlIoError', callback?: ErrorCallback): void

取消监听投播输入/输出的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 	取消对应的监听事件，支持的事件是'castControlIoError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
aVCastController.off('castControlIoError');
```

### on('castControlParsingError')<sup>13+</sup>

on(type: 'castControlParsingError', callback: ErrorCallback): void

监听投播解析的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'castControlParsingError'。 |
| callback | ErrorCallback | 是   | 投播解析的错误事件回调方法。 |

**错误码：**

| 错误码ID  | 错误信息              |
| -------- | --------------------- |
| 401      |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 6613000  | Unspecified error related to content parsing.     |
| 6613001  | Parsing error associated with media container format bit streams.   |
| 6613002  | Parsing error associated with the media manifest.     |
| 6613003  | An error occurs when attempting to extract a file with an unsupported media container format or an unsupported media container feature.    |
| 6613004  | Unsupported feature in the media manifest.    |

**示例：**

```ts
aVCastController.on('castControlParsingError', (error: BusinessError) => {
  console.info(`castControlParsingError happened, error code: ${error.code}, error message : ${error.message}.`)
})
```

### off('castControlParsingError')<sup>13+</sup>

off(type: 'castControlParsingError', callback?: ErrorCallback): void

取消监听投播解析的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 	取消对应的监听事件，支持的事件是'castControlParsingError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
aVCastController.off('castControlParsingError');
```

### on('castControlDecodingError')<sup>13+</sup>

on(type: 'castControlDecodingError', callback: ErrorCallback): void

监听投播解码的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'castControlDecodingError'。 |
| callback | ErrorCallback | 是   | 投播解码的错误事件回调方法。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 6614000  | Unspecified decoding error.     |
| 6614001  | Decoder initialization failed.   |
| 6614002  | Decoder query failed.     |
| 6614003  | Decoding the media samples failed.    |
| 6614004  | The format of the content to decode exceeds the capabilities of the device.    |
| 6614005  | The format of the content to decode is not supported.    |

**示例：**

```ts
aVCastController.on('castControlDecodingError', (error: BusinessError) => {
  console.info(`castControlDecodingError happened, error code: ${error.code}, error message : ${error.message}.`)
})
```
### off('castControlDecodingError')<sup>13+</sup>

off(type: 'castControlDecodingError', callback?: ErrorCallback): void

取消监听投播解码的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 	取消对应的监听事件，支持的事件是'castControlDecodingError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
aVCastController.off('castControlDecodingError');
```

### on('castControlAudioRendererError')<sup>13+</sup>

on(type: 'castControlAudioRendererError', callback: ErrorCallback): void

监听投播音频渲染器的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'castControlAudioRendererError'。 |
| callback | ErrorCallback | 是   | 投播音频渲染器的错误事件回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)以及[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 6615000  | Unspecified errors related to the audio renderer.     |
| 6615001  | Initializing the audio renderer failed.   |
| 6615002  | The audio renderer fails to write data.     |

**示例：**

```ts
aVCastController.on('castControlAudioRendererError', (error: BusinessError) => {
  console.info(`castControlAudioRendererError happened, error code: ${error.code}, error message : ${error.message}.`)
})
```
### off('castControlAudioRendererError')<sup>13+</sup>

off(type: 'castControlAudioRendererError', callback?: ErrorCallback): void

取消监听投播音频渲染器的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 	取消对应的监听事件，支持的事件是'castControlAudioRendererError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|

**示例：**

```ts
aVCastController.off('castControlAudioRendererError');
```

### on('castControlDrmError')<sup>13+</sup>

on(type: 'castControlDrmError', callback: ErrorCallback): void

监听投播drm的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'castControlDrmError'。 |
| callback | ErrorCallback | 是   | 投播drm的错误事件回调方法。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 6616000  | Unspecified error related to DRM.     |
| 6616001  | The chosen DRM protection scheme is not supported by the device.  |
| 6616002  | Device provisioning failed.    |
| 6616003  | The DRM-protected content to play is incompatible.     |
| 6616004  | Failed to obtain a license.   |
| 6616005  | The operation is disallowed by the license policy.     |
| 6616006  | An error occurs in the DRM system.     |
| 6616007  | The device has revoked DRM privileges.   |
| 6616008  | The DRM license being loaded into the open DRM session has expired.      |
| 6616100  | An error occurs when the DRM processes the key response.     |

**示例：**

```ts
aVCastController.on('castControlDrmError', (error: BusinessError) => {
  console.info(`castControlDrmError happened, error code: ${error.code}, error message : ${error.message}.`)
})
```

### off('castControlDrmError')<sup>13+</sup>

off(type: 'castControlDrmError', callback?: ErrorCallback): void

取消监听投播drm的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 	取消对应的监听事件，支持的事件是'castControlDrmError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
aVCastController.off('castControlDrmError');
```

## KeyRequestCallback<sup>12+</sup>
type KeyRequestCallback = (assetId: string, requestData: Uint8Array) => void

许可证请求事件的回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| assetId     | string  | 是   | 媒体ID。 |
| requestData |  Uint8Array  | 是   | 媒体许可证请求数据。                            |

**示例：**
<!--code_no_check-->
```ts
let keyRequestCallback: avSession.KeyRequestCallback = async(assetId: string, requestData: Uint8Array) => {
  console.info(`Succeeded in keyRequestCallback. assetId: ${assetId}, requestData: ${requestData}`);
}
```

## CastDisplayState<sup>12+</sup>

投播显示设备状态的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| STATE_OFF      | 1    | 设备断开，扩展屏不再显示内容。    |
| STATE_ON      | 2    | 设备连接成功，扩展屏可用。 |


## CastDisplayInfo<sup>12+</sup>

扩展屏投播显示设备相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.ExtendedDisplayCast

| 名称            | 类型                      | 只读 | 可选 | 说明                                                                  |
| --------------- |-------------------------| ---- | ---- |---------------------------------------------------------------------|
| id            | number                  | 否    | 否    | 投播显示设备的ID，该参数应为整数。  |
| name     | string                  | 否    | 否    | 投播显示设备的名称。           |
| state          | [CastDisplayState](#castdisplaystate12)          | 否    | 否    |投播显示设备状态。            |
| width          | number          | 否    | 否    | 投播显示设备的屏幕宽度，单位为px，该参数应为整数。          |  
| height          | number          | 否    | 否    | 投播显示设备的屏幕高度，单位为px，该参数应为整数。            |  

## ConnectionState<sup>10+</sup>

连接状态枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| STATE_CONNECTING      | 0    | 设备连接中    |
| STATE_CONNECTED      | 1    | 设备连接成功 |
| STATE_DISCONNECTED      | 6    | 设备断开连接 |

## AVMetadata<sup>10+</sup>

媒体元数据的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| assetId         | string                  | 是   | 媒体ID。歌曲的唯一标识，由应用自定义。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                     |
| title           | string                  | 否   | 标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                 |
| artist          | string                  | 否   | 艺术家。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                |
| author          | string                  | 否   | 专辑作者。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                               |
| avQueueName<sup>12+</sup>       | string                  | 否   | 歌单（歌曲列表）名称。                                                               |
| avQueueId<sup>11+</sup>       | string                  | 否   | 歌单（歌曲列表）唯一标识Id。                                                               |
| avQueueImage<sup>11+</sup>    | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) &#124; string | 否   | 歌单（歌曲列表）封面图，图片的像素数据或者图片路径地址(本地路径或网络路径)。<br>应用通过setAVMetadata设置图片数据，当设置的数据类型为PixelMap时，通过getAVMetadata获取的将为PixelMap。设置为url图片路径，获取的亦为url图片路径  |                       
| album           | string                  | 否   | 专辑名称。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                               |
| writer          | string                  | 否   | 词作者。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                |
| composer        | string                  | 否   | 作曲者。                                                                |
| duration        | number                  | 否   | 媒体时长，单位毫秒（ms）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                  |
| mediaImage      | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) &#124; string | 否   | 图片的像素数据或者图片路径地址(本地路径或网络路径)。<br>应用通过setAVMetadata设置图片数据，当设置的数据类型为PixelMap时，通过getAVMetadata获取的将为PixelMap。设置为url图片路径，获取的亦为url图片路径  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                             |
| publishDate     | Date                    | 否   | 发行日期。                                                             |
| subtitle        | string                  | 否   | 子标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                |
| description     | string                  | 否   | 媒体描述。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                               |
| lyric           | string                  | 否   | 媒体歌词内容。应用需将歌词内容拼接为一个字符串传入。<br>字符串长度需小于等于40960字节。<br>**说明：** 系统支持简单版的LRC格式（Simple LRC format）的歌词文本内容。当传入的歌词内容不规范（如出现重复的时间戳等），将导致解析失败以及在系统中显示异常。 |
| previousAssetId | string                  | 否   | 上一首媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                            |
| nextAssetId     | string                  | 否   | 下一首媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                            |
| filter<sup>11+</sup>        | number         | 否   | 当前session支持的协议，默认为TYPE_CAST_PLUS_STREAM。具体取值参考[ProtocolType](#protocoltype11)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                   |
| drmSchemes<sup>12+</sup>        | Array\<string>         | 否   | 当前session支持的DRM方案，取值为DRM方案uuid。|
| skipIntervals<sup>11+</sup>  | [SkipIntervals](#skipintervals11)        | 否   | 快进快退支持的时间间隔，默认为SECONDS_15，即15秒。                            |
|displayTags<sup>11+</sup>     | number                           | 否   | 媒体资源的金标类型，取值参考[DisplayTag](#displaytag11)。                                                          |

## AVMediaDescription<sup>10+</sup>

播放列表媒体元数据的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                    | 必填  | 说明                     |
| ------------ | ----------------------- | ---- | ----------------------- |
| assetId      | string                  | 是   | 播放列表媒体ID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。          |
| title        | string                  | 否   | 播放列表媒体标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。        |
| subtitle     | string                  | 否   | 播放列表媒体子标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| description  | string                  | 否   | 播放列表媒体描述的文本。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| mediaImage | image.PixelMap \| string   | 否   | 播放列表媒体图片像素数据。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| extras       | {[key: string]: Object}    | 否   | 播放列表媒体额外字段。     |
| mediaUri     | string                  | 否   | 播放列表媒体URI。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| mediaType     | string                  | 否   | 播放列表媒体类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| mediaSize     | number                  | 否   | 播放列表媒体的大小。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| albumTitle     | string                  | 否   | 播放列表媒体专辑标题。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| albumCoverUri     | string                  | 否   | 播放列表媒体专辑标题URI。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。    |
| lyricContent     | string                  | 否   | 播放列表媒体歌词内容。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| lyricUri     | string                  | 否   | 播放列表媒体歌词URI。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| artist     | string                  | 否   | 播放列表媒体专辑作者。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| fdSrc     | media.AVFileDescriptor        | 否   | 播放列表媒体本地文件的句柄。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| dataSrc<sup>12+</sup>     | media.AVDataSrcDescriptor        | 否   | 播放列表数据源描述。         |
| drmScheme<sup>12+</sup>     | string        | 否   | 播放列表媒体支持的DRM方案，由uuid表示。       |
| duration     | number                  | 否   | 播放列表媒体播放时长。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| startPosition     | number                  | 否   | 播放列表媒体起始播放位置。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| creditsPosition     | number                  | 否   | 播放列表媒体的片尾播放位置。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| appName     | string                  | 否   | 播放列表提供的应用的名字。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
|displayTags<sup>11+</sup>     | number | 否   | 媒体资源的金标类型，取值参考[DisplayTag](#displaytag11)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。        |

## AVQueueItem<sup>10+</sup>

播放列表中单项的相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                        | 必填 | 说明                        |
| ------------ | ------------------------------------------ | ---- | --------------------------- |
| itemId       | number                                     | 是   | 播放列表中单项的ID。          |
| description  | [AVMediaDescription](#avmediadescription10)  | 否   | 播放列表中单项的媒体元数据。   |

## AVPlaybackState<sup>10+</sup>

媒体播放状态的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                  | 必填 | 说明     |
| ------------ | ------------------------------------- | ---- | ------- |
| state        | [PlaybackState](#playbackstate10)       | 否   | 播放状态<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| speed        | number                                | 否   | 播放倍速<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| position     | [PlaybackPosition](#playbackposition10) | 否   | 播放位置<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bufferedTime | number                                | 否   | 缓冲时间<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| loopMode     | [LoopMode](#loopmode10)                 | 否   | 循环模式<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| isFavorite   | boolean                               | 否   | 是否收藏<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| activeItemId<sup>10+</sup> | number                  | 否   | 正在播放的媒体Id<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| volume<sup>10+</sup> | number                  | 否   | 正在播放的媒体音量<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| maxVolume<sup>11+</sup> | number                    | 否   | 最大音量<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| muted<sup>11+</sup>     | boolean                   | 否   | 当前静音状态，true表示静音<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| duration<sup>11+</sup>     | number                   | 否   | 当前媒体资源的时长 |
| videoWidth<sup>11+</sup>  | number                  | 否   | 媒体资源的视频宽度，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| videoHeight<sup>11+</sup> |  number                 | 否   | 媒体资源的视频高度，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| extras<sup>10+</sup> | {[key: string]: Object}       | 否   | 自定义媒体数据<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## PlaybackPosition<sup>10+</sup>

媒体播放位置的相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称        | 类型   | 必填 | 说明               |
| ----------- | ------ | ---- | ------------------ |
| elapsedTime | number | 是   | 已用时间，单位毫秒（ms）。 |
| updateTime  | number | 是   | 更新时间，单位毫秒（ms）。 |

## CallMetadata<sup>11+</sup>

通话会话元数据相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| name            | string                  | 否    | 来电人姓名（别名）。    |                                                                                                                      
| phoneNumber     | string                  | 否    | 来电电话号码            |                                                   
| avatar          | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)          | 否    | 来电人头像。            |                                                   

## AVCallState<sup>11+</sup>

通话状态相关属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------  | ---- |---------------------------------------------------------------------|
| state           | [CallState](#callstate11)                 | 是    | 当前通话状态。      |                                                                                                                      
| muted           | boolean                   | 是    | 通话mic是否静音。 <br>true：静音。 <br>false：不是静音。|                                                                  
 
## CallState<sup>11+</sup>

表示通话状态的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明      |
| --------------------------  | ---- | -------- |
| CALL_STATE_IDLE             | 0    | 空闲状态   |
| CALL_STATE_INCOMING         | 1    | 来电     |
| CALL_STATE_ACTIVE           | 2    | 接通     |
| CALL_STATE_DIALING          | 3    | 响铃     |
| CALL_STATE_WAITING          | 4    | 等待接通  |
| CALL_STATE_HOLDING          | 5    | 保持     |
| CALL_STATE_DISCONNECTING    | 6    | 挂断     |

## DisplayTag<sup>11+</sup>

枚举，表示当前媒体资源的金标，即应用媒体音源的特殊类型标识。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明           |
| --------------------------  | ---- | ------------ |
| TAG_AUDIO_VIVID             | 1    | AUDIO VIVID  |

## AVCastCategory<sup>10+</sup>

投播的类别枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| CATEGORY_LOCAL      | 0    | 本地播放，默认播放设备，声音从本机或者连接的蓝牙耳机设备出声。     |
| CATEGORY_REMOTE      | 1    | 远端播放，远端播放设备，声音从其他设备发出声音或者画面。  |

## DeviceType<sup>10+</sup>

播放设备的类型枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| DEVICE_TYPE_LOCAL      | 0    | 本地播放类型 <br> **系统能力：** SystemCapability.Multimedia.AVSession.Core|
| DEVICE_TYPE_BLUETOOTH      | 10   | 蓝牙设备 <br> **系统能力：** SystemCapability.Multimedia.AVSession.Core |
| DEVICE_TYPE_TV      | 2    | 电视 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast |
| DEVICE_TYPE_SMART_SPEAKER      | 3   | 音箱设备 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast |

## DeviceInfo<sup>10+</sup>

播放设备的相关信息。

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| castCategory   | AVCastCategory        | 是   | 投播的类别。  <br> **系统能力：** SystemCapability.Multimedia.AVSession.Core  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceId   | string | 是   | 播放设备的ID。<br> **系统能力：** SystemCapability.Multimedia.AVSession.Core  <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceName | string | 是   | 播放设备的名称。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| deviceType | DeviceType | 是   | 播放设备的类型。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| supportedProtocols<sup>11+</sup> | number | 否   | 播放设备支持的协议。默认为TYPE_LOCAL。具体取值参考[ProtocolType](#protocoltype11)。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast   <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| supportedDrmCapabilities<sup>12+</sup> | Array\<string> | 否   | 播放设备支持的DRM能力。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast   <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| manufacturer<sup>13+</sup> | string | 否   | 播放设备生产厂家。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。|
| modelName<sup>13+</sup> | string | 否   | 播放设备型号名称。 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast  <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。|

## OutputDeviceInfo<sup>10+</sup>

播放设备的相关信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| devices | Array\<DeviceInfo\> | 是   | 播放设备的集合。    |

## LoopMode<sup>10+</sup>

表示媒体播放循环模式的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称               | 值   | 说明     |
| ------------------ | ---- | -------- |
| LOOP_MODE_SEQUENCE | 0    | 顺序播放 |
| LOOP_MODE_SINGLE   | 1    | 单曲循环 |
| LOOP_MODE_LIST     | 2    | 表单循环 |
| LOOP_MODE_SHUFFLE  | 3    | 随机播放 |
| LOOP_MODE_CUSTOM<sup>11+</sup>   | 4    | 自定义播放  |

## PlaybackState<sup>10+</sup>

表示媒体播放状态的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| PLAYBACK_STATE_INITIAL      | 0    | 初始状态     |
| PLAYBACK_STATE_PREPARE      | 1    | 播放准备状态  |
| PLAYBACK_STATE_PLAY         | 2    | 正在播放     |
| PLAYBACK_STATE_PAUSE        | 3    | 暂停         |
| PLAYBACK_STATE_FAST_FORWARD | 4    | 快进         |
| PLAYBACK_STATE_REWIND       | 5    | 快退         |
| PLAYBACK_STATE_STOP         | 6    | 停止         |
| PLAYBACK_STATE_COMPLETED    | 7    | 播放完成     |
| PLAYBACK_STATE_RELEASED     | 8    | 释放         |
| PLAYBACK_STATE_ERROR        | 9    | 错误         |
| PLAYBACK_STATE_IDLE<sup>11+</sup>        | 10    | 空闲     |
| PLAYBACK_STATE_BUFFERING<sup>11+</sup>         | 11    | 缓冲   |

## AVSessionController<sup>10+</sup>

AVSessionController控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型   | 可读 | 可写 | 说明                                    |
| :-------- | :----- | :--- | :--- | :-------------------------------------- |
| sessionId | string | 是   | 否   | AVSessionController对象唯一的会话标识。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let AVSessionController: avSession.AVSessionController;
avSession.createController(currentAVSession.sessionId).then((controller: avSession.AVSessionController) => {
  AVSessionController = controller;
}).catch((err: BusinessError) => {
  console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

获取当前的远端播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[AVPlaybackState](#avplaybackstate10)\> | 是   | 回调函数，返回远端播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>

获取当前的远端播放状态。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise<[AVPlaybackState](#avplaybackstate10)\>  | Promise对象。返回远端播放状态。  |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info('getAVPlaybackState : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVMetadata<sup>10+</sup>

getAVMetadata(): Promise\<AVMetadata>

获取会话元数据。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<[AVMetadata](#avmetadata10)\> | Promise对象，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVMetadata().then((metadata: avSession.AVMetadata) => {
  console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVMetadata<sup>10+</sup>

getAVMetadata(callback: AsyncCallback\<AVMetadata>): void

获取会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVMetadata](#avmetadata10)\> | 是   | 回调函数，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(): Promise\<string>

获取当前会话播放列表的名称。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型             | 说明                           |
| ---------------- | ----------------------------- |
| Promise<string\> | Promise对象。返回播放列表名称。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVQueueTitle().then((title: string) => {
  console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(callback: AsyncCallback\<string>): void

获取当前播放列表的名称。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback<string\> | 是   | 回调函数，返回播放列表名称。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(): Promise\<Array\<AVQueueItem>>

获取当前会话播放列表相关信息。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                          | 说明                           |
| --------------------------------------------- | ----------------------------- |
| Promise<Array<[AVQueueItem](#avqueueitem10)\>\> | Promise对象。返回播放列表队列。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVQueueItems().then((items: avSession.AVQueueItem[]) => {
  console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void

获取当前播放列表相关信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                      |
| -------- | --------------------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback<Array<[AVQueueItem](#avqueueitem10)\>\> | 是   | 回调函数，返回播放列表队列。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number): Promise\<void>

设置指定播放列表单项的ID，发送给session端处理，session端可以选择对这个单项歌曲进行播放。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                                        |
| ------ | ------- | ---- | ------------------------------------------- |
| itemId | number  | 是   | 播放列表单项的ID值，用以表示选中的播放列表单项。 |

**返回值：**

| 类型           | 说明                                                             |
| -------------- | --------------------------------------------------------------- |
| Promise\<void> | Promise对象。当播放列表单项ID设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let queueItemId = 0;
avsessionController.skipToQueueItem(queueItemId).then(() => {
  console.info('SkipToQueueItem successfully');
}).catch((err: BusinessError) => {
  console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void

设置指定播放列表单项的ID，发送给session端处理，session端可以选择对这个单项歌曲进行播放。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                        |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| itemId   | number                | 是   | 播放列表单项的ID值，用以表示选中的播放列表单项。                |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

获取播放设备信息。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo10)\> | Promise对象，返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getOutputDevice().then((deviceInfo: avSession.OutputDeviceInfo) => {
  console.info('GetOutputDevice : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

获取播放设备信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                           |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo10)\> | 是   | 回调函数，返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600103  | The session controller does not exist. |

**示例：**

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

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent): Promise\<void>

发送按键事件到控制器对应的会话。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| event  | [KeyEvent](../apis-input-kit/js-apis-keyevent.md) | 是   | 按键事件。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 600101  | Session service exception. |
| 600102  | The session does not exist. |
| 600103  | The session controller does not exist. |
| 600105  | Invalid session command. |
| 600106  | The session is not activated. |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当事件发送成功，无返回结果，否则返回错误对象。 |

**示例：**

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

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

发送按键事件到会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明       |
| -------- | ------------------------------------------------------------ | ---- | ---------- |
| event    | [KeyEvent](../apis-input-kit/js-apis-keyevent.md) | 是   | 按键事件。 |
| callback | AsyncCallback\<void>                                         | 是   | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 600101  | Session service exception. |
| 600102  | The session does not exist. |
| 600103  | The session controller does not exist. |
| 600105  | Invalid session command. |
| 600106  | The session is not activated. |

**示例：**

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

### getLaunchAbility<sup>10+</sup>

getLaunchAbility(): Promise\<WantAgent>

获取应用在会话中保存的WantAgent对象。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                    | 说明                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)\> | Promise对象，返回在[setLaunchAbility](#setlaunchability10)保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getLaunchAbility().then((agent: object) => {
  console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
}).catch((err: BusinessError) => {
  console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getLaunchAbility<sup>10+</sup>

getLaunchAbility(callback: AsyncCallback\<WantAgent>): void

获取应用在会话中保存的WantAgent对象。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)\> | 是   | 回调函数。返回在[setLaunchAbility](#setlaunchability10)保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getRealPlaybackPositionSync<sup>10+</sup>

getRealPlaybackPositionSync(): number

获取当前播放位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 时间节点，毫秒数。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
let time: number = avsessionController.getRealPlaybackPositionSync();
```

### isActive<sup>10+</sup>

isActive(): Promise\<boolean>

获取会话是否被激活。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | Promise对象，返回会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.isActive().then((isActive: boolean) => {
  console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
}).catch((err: BusinessError) => {
  console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### isActive<sup>10+</sup>

isActive(callback: AsyncCallback\<boolean>): void

判断会话是否被激活。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<boolean\> | 是   | 回调函数，返回会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### destroy<sup>10+</sup>

destroy(): Promise\<void>

销毁当前控制器，销毁后当前控制器不可再用。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当控制器销毁成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.destroy().then(() => {
  console.info('Destroy : SUCCESS ');
}).catch((err: BusinessError) => {
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

销毁当前控制器，销毁后当前控制器不可再用。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当控制器销毁成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getValidCommands<sup>10+</sup>

getValidCommands(): Promise\<Array\<AVControlCommandType>>

获取会话支持的有效命令。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<Array<[AVControlCommandType](#avcontrolcommandtype10)\>\> | Promise对象。返回有效命令的集合。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getValidCommands().then((validCommands: avSession.AVControlCommandType[]) => {
  console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getValidCommands<sup>10+</sup>

getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void

获取会话支持的有效命令。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[AVControlCommandType](#avcontrolcommandtype10)\>\> | 是   | 回调函数，返回有效命令的集合。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand): Promise\<void>

通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。

> **说明：**
>
> 媒体控制方在使用sendControlCommand命令前，需要确保控制对应的媒体会话注册了对应的监听，注册媒体会话相关监听的方法请参见接口[on'play'](#onplay10)、[on'pause'](#onpause10)等。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVControlCommand](#avcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avCommand: avSession.AVControlCommand = {command:'play'};
avsessionController.sendControlCommand(avCommand).then(() => {
  console.info('SendControlCommand successfully');
}).catch((err: BusinessError) => {
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

通过会话控制器发送命令到其对应的会话。结果通过callback异步回调方式返回。

> **说明：**
>
> 媒体控制方在使用sendControlCommand命令前，需要确保控制对应的媒体会话注册了对应的监听，注册媒体会话相关监听的方法请参见接口[on'play'](#onplay10)、[on'pause'](#onpause10)等。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVControlCommand](#avcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception.                |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command.           |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events.      |

**示例：**

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

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}): Promise\<void>

通过会话控制器发送自定义控制命令到其对应的会话。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | 是   | 需要设置的自定义控制命令的名称 |
| args | {[key: string]: Object} | 是   | 需要传递的控制命令键值对 |

> **说明：**
> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  sessionId = (currentAVSession as avSession.AVSession).sessionId;
  avSession.createController(sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

let commandName = "my_command";
if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}).then(() => {
    console.info('SendCommonCommand successfully');
  }).catch((err: BusinessError) => {
    console.error(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

通过会话控制器发送自定义命令到其对应的会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | 是   | 需要设置的自定义控制命令的名称 |
| args | {[key: string]: Object} | 是   | 需要传递的控制命令键值对 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

> **说明：**
> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](../apis-ability-kit/js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.|
| 6600101  | Session service exception.                |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command.           |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

let commandName = "my_command";
if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}, (err: BusinessError) => {
    if (err) {
        console.error(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}
```

### getExtras<sup>10+</sup>

getExtras(): Promise\<{[key: string]: Object}>

获取媒体提供方设置的自定义媒体数据包。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<{[key: string]: Object}\>   | Promise对象，返回媒体提供方设置的自定义媒体数据包，数据包的内容与setExtras设置的内容完全一致。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).getExtras().then((extras) => {
    console.info(`getExtras : SUCCESS : ${extras}`);
  }).catch((err: BusinessError) => {
    console.error(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

### getExtras<sup>10+</sup>

getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void

获取媒体提供方设置的自定义媒体数据包,结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<{[key: string]: Object}\> | 是   | 回调函数，返回媒体提供方设置的自定义媒体数据包，数据包的内容与setExtras设置的内容完全一致。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).getExtras((err, extras) => {
    if (err) {
      console.error(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`getExtras : SUCCESS : ${extras}`);
    }
  });
}
```

### on('metadataChange')<sup>10+</sup>

on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)

设置元数据变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'metadataChange'`：当元数据变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVMetadata](#avmetadata10)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注元数据所有字段变化；Array<keyof&nbsp;[AVMetadata](#avmetadata10)\> 表示关注Array中的字段变化。 |
| callback | (data: [AVMetadata](#avmetadata10)) => void                    | 是   | 回调函数，参数data是变化后的元数据。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('metadataChange', 'all', (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

avsessionController.on('metadataChange', ['assetId', 'title', 'description'], (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

```

### off('metadataChange')<sup>10+</sup>

off(type: 'metadataChange', callback?: (data: AVMetadata) => void)

媒体控制器取消监听元数据变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                                                    |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | 是   | 取消对应的监听事件，支持事件`'metadataChange'`。         |
| callback | (data: [AVMetadata](#avmetadata10)) => void        | 否   | 回调函数，参数data是变化后的元数据。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('metadataChange');
```

### on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)

设置播放状态变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'playbackStateChange'`：当播放状态变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注播放状态所有字段变化；Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\> 表示关注Array中的字段变化。 |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void       | 是   | 回调函数，参数state是变化后的播放状态。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

avsessionController.on('playbackStateChange', ['state', 'speed', 'loopMode'], (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});
```

### off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)

媒体控制器取消监听播放状态变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playbackStateChange'`。    |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | 否   | 回调函数，参数state是变化后的播放状态。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('playbackStateChange');
```

### on('callMetadataChange')<sup>11+</sup>

on(type: 'callMetadataChange', filter: Array\<keyof CallMetadata> | 'all', callback: Callback\<CallMetadata>): void;

设置通话元数据变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'callMetadataChange'`：当通话元数据变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[CallMetadata](#callmetadata11)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注通话元数据所有字段变化；Array<keyof&nbsp;[CallMetadata](#callmetadata11)\> 表示关注Array中的字段变化。 |
| callback | Callback<[CallMetadata](#callmetadata11)\>\>   | 是   | 回调函数，参数callmetadata是变化后的通话元数据。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('callMetadataChange', 'all', (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.name}`);
});

avsessionController.on('callMetadataChange', ['name'], (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.name}`);
});
```

### off('callMetadataChange')<sup>11+</sup>

off(type: 'callMetadataChange', callback?: Callback\<CallMetadata>): void;

取消设置通话元数据变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'callMetadataChange'`。    |
| callback | Callback<[CallMetadata](#callmetadata11)\>       | 否   | 回调函数，参数calldata是变化后的通话原数据。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('callMetadataChange');
```

### on('callStateChange')<sup>11+</sup>

on(type: 'callStateChange', filter: Array\<keyof AVCallState> | 'all', callback: Callback\<AVCallState>): void;

设置通话状态变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'callStateChange'`：当通话状态变化时，触发该事件。 |
| filter   | Array<keyof&nbsp;[AVCallState](#avcallstate11)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注通话状态所有字段变化；Array<keyof&nbsp;[AVCallState](#avcallstate11)\> 表示关注Array中的字段变化。 |
| callback | Callback<[AVCallState](#avcallstate11)\>       | 是   | 回调函数，参数callstate是变化后的通话状态。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('callStateChange', 'all', (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});

avsessionController.on('callStateChange', ['state'], (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});
```

### off('callStateChange')<sup>11+</sup>

off(type: 'callStateChange', callback?: Callback\<AVCallState>): void;

取消设置通话状态变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'callStateChange'`。    |
| callback | Callback<[AVCallState](#avcallstate11)\>           | 否   | 回调函数，参数callstate是变化后的通话状态。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('callMetadataChange');
```

### on('sessionDestroy')<sup>10+</sup>

on(type: 'sessionDestroy', callback: () => void)

会话销毁的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                         |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | 是   | 事件回调类型，支持事件`'sessionDestroy'`：当检测到会话销毁时，触发该事件）。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。                  |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('sessionDestroy', () => {
  console.info('on sessionDestroy : SUCCESS ');
});
```

### off('sessionDestroy')<sup>10+</sup>

off(type: 'sessionDestroy', callback?: () => void)

媒体控制器取消监听会话的销毁事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                      |
| -------- | ---------- | ---- | ----------------------------------------------------- |
| type     | string     | 是   | 取消对应的监听事件，支持事件`'sessionDestroy'`。         |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('sessionDestroy');
```

### on('activeStateChange')<sup>10+</sup>

on(type: 'activeStateChange', callback: (isActive: boolean) => void)

会话的激活状态的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                      | 是   | 事件回调类型，支持事件`'activeStateChange'`：当检测到会话的激活状态发生改变时，触发该事件。 |
| callback | (isActive: boolean) => void | 是   | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。                   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  |The session controller does not exist. |

**示例：**

```ts
avsessionController.on('activeStateChange', (isActive: boolean) => {
  console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);
});
```

### off('activeStateChange')<sup>10+</sup>

off(type: 'activeStateChange', callback?: (isActive: boolean) => void)

媒体控制器取消监听会话激活状态变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                      |
| -------- | --------------------------- | ---- | ----------------------------------------------------- |
| type     | string                      | 是   | 取消对应的监听事件，支持事件`'activeStateChange'`。      |
| callback | (isActive: boolean) => void | 否   | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('activeStateChange');
```

### on('validCommandChange')<sup>10+</sup>

on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)

会话支持的有效命令变化监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'validCommandChange'`：当检测到会话的合法命令发生改变时，触发该事件。 |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | 是   | 回调函数。参数commands是有效命令的集合。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('validCommandChange', (validCommands: avSession.AVControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

### off('validCommandChange')<sup>10+</sup>

off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)

媒体控制器取消监听会话有效命令变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'validCommandChange'`。         |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | 否   | 回调函数。参数commands是有效命令的集合。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('validCommandChange');
```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

设置播放设备变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | 是   | 事件回调类型，支持事件为`'outputDeviceChange'`：当播放设备变化时，触发该事件）。 |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 是   | 回调函数，参数device是设备相关信息。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange state: ${state}, device : ${device}`);
});
```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

媒体控制器取消监听分布式设备变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                      |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | 是   | 取消对应的监听事件，支持事件`'outputDeviceChange'`。      |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 否   | 回调函数，参数device是设备相关信息。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID  | 错误信息          |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('outputDeviceChange');
```

### on('sessionEvent')<sup>10+</sup>

on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key:string]: Object}) => void): void

媒体控制器设置会话自定义事件变化的监听器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'sessionEvent'`：当会话事件变化时，触发该事件。 |
| callback | (sessionEvent: string, args: {[key:string]: object}) => void         | 是   | 回调函数，sessionEvent为变化的会话事件名，args为事件的参数。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).on('sessionEvent', (sessionEvent, args) => {
    console.info(`OnSessionEvent, sessionEvent is ${sessionEvent}, args: ${JSON.stringify(args)}`);
  });
}
```

### off('sessionEvent')<sup>10+</sup>

off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key:string]: Object}) => void): void

媒体控制器取消监听会话事件的变化通知。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'sessionEvent'`。    |
| callback | (sessionEvent: string, args: {[key:string]: Object}) => void         | 否   | 回调函数，参数sessionEvent是变化的事件名，args为事件的参数。<br>该参数为可选参数，若不填写该参数，则认为取消所有对sessionEvent事件的监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('sessionEvent');
```

### on('queueItemsChange')<sup>10+</sup>

on(type: 'queueItemsChange', callback: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

媒体控制器设置会话自定义播放列表变化的监听器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                                                                         |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| type     | string                                                | 是   | 事件回调类型，支持事件`'queueItemsChange'`：当session修改播放列表时，触发该事件。 |
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void  | 是   | 回调函数，items为变化的播放列表。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('queueItemsChange', (items: avSession.AVQueueItem[]) => {
  console.info(`OnQueueItemsChange, items length is ${items.length}`);
});
```

### off('queueItemsChange')<sup>10+</sup>

off(type: 'queueItemsChange', callback?: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

媒体控制器取消监听播放列表变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                                                                                                |
| -------- | ---------------------------------------------------- | ---- | --------------------------------------------------------------------------------------------------- |
| type     | string                                               | 是   | 取消对应的监听事件，支持事件`'queueItemsChange'`。                                                     |
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void | 否   | 回调函数，参数items是变化的播放列表。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('queueItemsChange');
```

### on('queueTitleChange')<sup>10+</sup>

on(type: 'queueTitleChange', callback: (title: string) => void): void

媒体控制器设置会话自定义播放列表的名称变化的监听器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                             |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------- |
| type     | string                  | 是   | 事件回调类型，支持事件`'queueTitleChange'`：当session修改播放列表名称时，触发该事件。 |
| callback | (title: string) => void | 是   | 回调函数，title为变化的播放列表名称。                                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('queueTitleChange', (title: string) => {
  console.info(`queueTitleChange, title is ${title}`);
});
```

### off('queueTitleChange')<sup>10+</sup>

off(type: 'queueTitleChange', callback?: (title: string) => void): void

媒体控制器取消监听播放列表名称变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | 是   | 取消对应的监听事件，支持事件`'queueTitleChange'`。                                                         |
| callback | (title: string) => void | 否   | 回调函数，参数items是变化的播放列表名称。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('queueTitleChange');
```

### on('extrasChange')<sup>10+</sup>

on(type: 'extrasChange', callback: (extras: {[key:string]: Object}) => void): void

媒体控制器设置自定义媒体数据包事件变化的监听器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'extrasChange'`：当媒体提供方设置自定义媒体数据包时，触发该事件。 |
| callback | (extras: {[key:string]: object}) => void         | 是   | 回调函数，extras为媒体提供方新设置的自定义媒体数据包，该自定义媒体数据包与dispatchSessionEvent方法设置的数据包完全一致。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).on('extrasChange', (extras) => {
    console.info(`Caught extrasChange event,the new extra is: ${JSON.stringify(extras)}`);
  });
}
```

### off('extrasChange')<sup>10+</sup>

off(type: 'extrasChange', callback?: (extras: {[key:string]: Object}) => void): void

媒体控制器取消监听自定义媒体数据包变化事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | 是   | 取消对应的监听事件，支持事件`'extrasChange'`。                                                         |
| callback | ({[key:string]: Object}) => void | 否   | 注册监听事件时的回调函数。<br>该参数为可选参数，若不填写该参数，则认为取消会话所有与此事件相关的监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------                       |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.             |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('extrasChange');
```

### getAVPlaybackStateSync<sup>10+</sup>

getAVPlaybackStateSync(): AVPlaybackState;

使用同步方法获取当前会话的播放状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| [AVPlaybackState](#avplaybackstate10)  | 当前会话的播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let playbackState: avSession.AVPlaybackState = avsessionController.getAVPlaybackStateSync();
} catch (err) {
  let error = err as BusinessError;
  console.info(`getAVPlaybackStateSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

### getAVMetadataSync<sup>10+</sup>

getAVMetadataSync(): AVMetadata

使用同步方法获取会话元数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| [AVMetadata](#avmetadata10) | 会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let metaData: avSession.AVMetadata = avsessionController.getAVMetadataSync();
} catch (err) {
  let error = err as BusinessError;
  console.info(`getAVMetadataSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

### getAVCallState<sup>11+</sup>

getAVCallState(): Promise\<AVCallState>

获取通话状态数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<[AVCallState](#avcallstate11)\> | Promise对象，返回通话状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getAVCallState().then((callstate: avSession.AVCallState) => {
  console.info(`getAVCallState : SUCCESS : state : ${callstate.state}`);
}).catch((err: BusinessError) => {
  console.error(`getAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVCallState<sup>11+</sup>

getAVCallState(callback: AsyncCallback\<AVCallState>): void

获取通话状态数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVCallState](#avcallstate11)\> | 是   | 回调函数，返回通话状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getCallMetadata<sup>11+</sup>

getCallMetadata(): Promise\<CallMetadata>

获取通话会话的元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<[CallMetadata](#callmetadata11)\> | Promise对象，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avsessionController.getCallMetadata().then((calldata: avSession.CallMetadata) => {
  console.info(`getCallMetadata : SUCCESS : name : ${calldata.name}`);
}).catch((err: BusinessError) => {
  console.error(`getCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getCallMetadata<sup>11+</sup>

getCallMetadata(callback: AsyncCallback\<CallMetadata>): void

获取通话会话的元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[CallMetadata](#callmetadata11)\> | 是   | 回调函数，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

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

### getAVQueueTitleSync<sup>10+</sup>

getAVQueueTitleSync(): string

使用同步方法获取当前会话播放列表的名称。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型             | 说明                           |
| ---------------- | ----------------------------- |
| string | 当前会话播放列表名称。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let currentQueueTitle: string = avsessionController.getAVQueueTitleSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAVQueueTitleSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

### getAVQueueItemsSync<sup>10+</sup>

getAVQueueItemsSync(): Array\<AVQueueItem\>

使用同步方法获取当前会话播放列表相关信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                          | 说明                           |
| --------------------------------------------- | ----------------------------- |
| Array<[AVQueueItem](#avqueueitem10)\> | 当前会话播放列表队列。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let currentQueueItems: Array<avSession.AVQueueItem> = avsessionController.getAVQueueItemsSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAVQueueItemsSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

### getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

使用同步方法获取当前输出设备信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| [OutputDeviceInfo](#outputdeviceinfo10) | 当前输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let currentOutputDevice: avSession.OutputDeviceInfo = avsessionController.getOutputDeviceSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOutputDeviceSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

### isActiveSync<sup>10+</sup>

isActiveSync(): boolean

使用同步方法判断会话是否被激活。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| boolean | 会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isActive: boolean = avsessionController.isActiveSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`isActiveSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

### getValidCommandsSync<sup>10+</sup>

getValidCommandsSync(): Array\<AVControlCommandType\>

使用同步方法获取会话支持的有效命令。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Array<[AVControlCommandType](#avcontrolcommandtype10)\> | 会话支持的有效命令的集合。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let validCommands: Array<avSession.AVControlCommandType> = avsessionController.getValidCommandsSync();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getValidCommandsSync error, error code: ${error.code}, error message: ${error.message}`);
}
```

## AVControlCommandType<sup>10+</sup>

type AVControlCommandType = 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind' |
  'seek' | 'setSpeed' | 'setLoopMode' | 'toggleFavorite' | 'playFromAssetId' | 'answer' | 'hangUp' | 'toggleCallMute'

会话可传递的命令。

该类型可取的值为下表字符串的并集。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 类型             | 说明         |
| ---------------- | ------------ |
| 'play'           | 播放         |
| 'pause'          | 暂停         |
| 'stop'           | 停止         |
| 'playNext'       | 下一首       |
| 'playPrevious'   | 上一首       |
| 'fastForward'    | 快进         |
| 'rewind'         | 快退         |
| 'seek'           | 跳转某一节点 |
| 'setSpeed'       | 设置播放倍速 |
| 'setLoopMode'    | 设置循环模式 |
| 'toggleFavorite' | 是否收藏     |
| 'playFromAssetId'| 播放指定的assetid |
|'answer'          | 接听        |
| 'hangUp'         | 挂断        |
|'toggleCallMute'  | 设置通话静音状态 |

## AVControlCommand<sup>10+</sup>

会话接受的命令的对象描述。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVControlCommandType](#avcontrolcommandtype10)     | 是   | 命令           |
| parameter | [LoopMode](#loopmode10) &#124; string &#124; number | 否   | 命令对应的参数 |


## AVCastPickerOptions<sup>14+</sup>

拉起的投播半模态窗口相关属性。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| sessionType         | [AVSessionType](#avsessiontype10)  | 否   | 会话类型，默认值为'audio'。<br>当前仅支持'audio'、'video'会话类型。如果传入'voice_call'、'video_call'，将按照传入默认值'audio'处理。            |

## AVCastPickerHelper<sup>14+</sup>

投播半模态对象，可拉起半模态窗口，选择投播设备。在使用前，需要创建AVCastPickerHelper实例。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

### constructor<sup>14+</sup>

constructor(context: Context)

创建AVCastPickerHelper对象，获取context参考[getContext](../apis-arkui/js-apis-getContext.md)。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context | 是   | 应用上下文（仅支持[UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)）。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { avSession } from '@kit.AVSessionKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(40)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            let context = getContext(this) as common.Context;
            let avCastPicker = new avSession.AVCastPickerHelper(context);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### select<sup>14+</sup>

select(options?: AVCastPickerOptions): Promise\<void>

通过选择模式拉起AVCastPicker界面，用户可以选择投播设备。接口采用Promise异步返回形式，传入可选参数AVCastPickerOptions对象，无返回值。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| options  | [AVCastPickerOptions](#avcastpickeroptions14) | 否   | AVCastPicker选择选项。无此参数时，以AVCastPickerOptions默认值拉起。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function avCastPicker(context: common.Context) {
  let avCastPickerOptions : avSession.AVCastPickerOptions = {
    sessionType : 'video',
  }
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.select(avCastPickerOptions).then(() => {
    console.info('select successfully');
  }).catch((err: BusinessError) => {
    console.error(`AVCastPicker.select failed with err: ${err.code}, ${err.message}`);
  });
}
```
### on('pickerStateChange')<sup>14+</sup>

on(type: 'pickerStateChange', callback: Callback<AVCastPickerState\>) : void

设置半模态窗口变化的监听事件。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'pickerStateChange'`：当半模态窗口变化时，触发该事件。 |
| callback | Callback\<[AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11)>       | 是   | 回调函数，参数state是变化后的半模态窗口状态。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { AVCastPickerState } from '@kit.AVSessionKit';

async function onPickerStateChange(context: common.Context) {
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.on('pickerStateChange', (state: AVCastPickerState) => {
    console.info(`picker state change : ${state}`);
  });
}
```

### off('pickerStateChange')<sup>14+</sup>

off(type: 'pickerStateChange', callback?: Callback<AVCastPickerState\>) : void

取消半模态窗口变化的监听事件，关闭后，不再进行该事件回调。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                                                    |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | 是   | 取消对应的监听事件，支持事件`'pickerStateChange'`。         |
| callback | Callback\<[AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11)> | 否   | 回调函数，参数state是变化后的半模态窗口状态。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                           |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

async function onPickerStateChange(context: common.Context) {
  let avCastPicker = new avSession.AVCastPickerHelper(context);
  avCastPicker.off('pickerStateChange');
}
```

## AVSessionErrorCode<sup>10+</sup>

会话发生错误时的错误码。

| 名称                                   | 值      | 说明                             |
| -------------------------------------- | ------- | ------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION             | 6600101 | 会话服务端异常。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_SESSION_NOT_EXIST             | 6600102 | 会话不存在。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_CONTROLLER_NOT_EXIST          | 6600103 | 会话控制器不存在。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_REMOTE_CONNECTION_ERR         | 6600104 | 远端会话连接失败。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_COMMAND_INVALID               | 6600105 | 无效会话命令。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br>**系统能力：** SystemCapability.Multimedia.AVSession.Core|
| ERR_CODE_SESSION_INACTIVE              | 6600106 | 会话未激活。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_MESSAGE_OVERLOAD              | 6600107 | 命令&消息过载。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_DEVICE_CONNECTION_FAILED      | 6600108 | 设备连接失败。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_REMOTE_CONNECTION_NOT_EXIST   | 6600109 | 远端会话不存在。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.Core |
| ERR_CODE_CAST_CONTROL_UNSPECIFIED<sup>13+</sup>    | 6611000 | 未被定义的投播错误码。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_REMOTE_ERROR<sup>13+</sup>    | 6611001 | 远端播放器中发生不明错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_BEHIND_LIVE_WINDOW<sup>13+</sup>     | 6611002 | 播放出现延迟。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_TIMEOUT<sup>13+</sup>     | 6611003 | 投播控制进程超时。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_RUNTIME_CHECK_FAILED<sup>13+</sup>      | 6611004 | 运行时检查失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAYER_NOT_WORKING<sup>13+</sup>      | 6611100 | 跨设备数据传输被锁定。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_SEEK_MODE_UNSUPPORTED<sup>13+</sup>      | 6611101 | 不支持指定的查找模式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_ILLEGAL_SEEK_TARGET<sup>13+</sup>      | 6611102 | 要搜索的位置超出媒体的范围，或者不支持当前搜索模式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAY_MODE_UNSUPPORTED<sup>13+</sup>      | 6611103 |  不支持指定的播放模式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PLAY_SPEED_UNSUPPORTED<sup>13+</sup>      | 6611104 | 不支持指定的播放速度。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DEVICE_MISSING<sup>13+</sup>      | 6611105 | 操作失败，因为媒体源设备或媒体接收器设备已被销毁。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_INVALID_PARAM<sup>13+</sup>       | 6611106 | 该参数无效。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_NO_MEMORY<sup>13+</sup>       | 6611107 | 内存分配失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_OPERATION_NOT_ALLOWED<sup>13+</sup>       | 6611108 | 不被允许的操作。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_UNSPECIFIED<sup>13+</sup>       | 6612000 | 未指定的输入/输出错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_FAILED<sup>13+</sup>       | 6612001 | 网络连接失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_CONNECTION_TIMEOUT<sup>13+</sup>       | 6612002 | 网络连接超时。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_INVALID_HTTP_CONTENT_TYPE <sup>13+</sup>      | 6612003 | 无效的"Content-Type"。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_BAD_HTTP_STATUS<sup>13+</sup>        | 6612004 | HTTP服务器返回一个意外的HTTP响应状态码。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_FILE_NOT_FOUND<sup>13+</sup>   | 6612005 | 文件不存在。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NO_PERMISSION<sup>13+</sup>    | 6612006 | 不允许执行输入/输出的IO操作。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CLEARTEXT_NOT_PERMITTED<sup>13+</sup>    | 6612007 | 应用的网络安全配置不允许访问明文HTTP流量。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_READ_POSITION_OUT_OF_RANGE<sup>13+</sup>        | 6612008 | 从数据绑定中读取数据。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NO_CONTENTS<sup>13+</sup>     | 6612100 | 媒体中没有可播放的内容。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_READ_ERROR<sup>13+</sup>        | 6612101 | 媒体无法读取。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CONTENT_BUSY<sup>13+</sup>         | 6612102 | 该资源正在使用中。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_CONTENT_EXPIRED<sup>13+</sup>    | 6612103 | 输入/输出的IO请求内容已过期。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_USE_FORBIDDEN<sup>13+</sup>    | 6612104 | 不允许播放请求内容。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NOT_VERIFIED<sup>13+</sup>     | 6612105 | 无法验证所允许的内容。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_EXHAUSTED_ALLOWED_USES<sup>13+</sup>     | 6612106 | 此内容已达到允许的最大使用次数。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_IO_NETWORK_PACKET_SENDING_FAILED<sup>13+</sup>   | 6612107 | 从源设备发送数据包到接收设备时出现错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_UNSPECIFIED<sup>13+</sup>    | 6613000 | 未指定的内容解析错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_MALFORMED<sup>13+</sup>    | 6613001 | 媒体容器比特流的格式解析错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_MALFORMED<sup>13+</sup>     | 6613002 | 媒体清单解析错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_CONTAINER_UNSUPPORTED<sup>13+</sup>   | 6613003 | 文件的媒体容器格式/媒体容器特性不被支持。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_PARSING_MANIFEST_UNSUPPORTED<sup>13+</sup>      | 6613004 | 媒体清单中不支持的特性。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_UNSPECIFIED<sup>13+</sup>     | 6614000 | 未指定的解码错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_INIT_FAILED<sup>13+</sup>   | 6614001 | 解码器初始化失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_QUERY_FAILED<sup>13+</sup>     | 6614002 | 解码器查询失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FAILED<sup>13+</sup>     | 6614003 | 媒体样本解码失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FORMAT_EXCEEDS_CAPABILITIES<sup>13+</sup>    | 6614004 | 设备的能力无法解码当前格式。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DECODING_FORMAT_UNSUPPORTED<sup>13+</sup>    | 6614005 | 不支持的解码格式。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_UNSPECIFIED<sup>13+</sup>       | 6615000 | 未指定的音频渲染器错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_INIT_FAILED <sup>13+</sup>     | 6615001 | 音频渲染器初始化失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_AUDIO_RENDERER_WRITE_FAILED<sup>13+</sup>    | 6615002 | 音频渲染器写入数据失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_UNSPECIFIED<sup>13+</sup>      | 6616000 | 未指定的DRM相关错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_SCHEME_UNSUPPORTED<sup>13+</sup>  | 6616001 | 设备不支持所选择的DRM保护方案。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_PROVISIONING_FAILED<sup>13+</sup>   | 6616002 | 设备配置失败。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_CONTENT_ERROR<sup>13+</sup>  | 6616003 | 受DRM保护的内容无法播放。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_LICENSE_ACQUISITION_FAILED<sup>13+</sup>    | 6616004 | 获取许可证失败。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_DISALLOWED_OPERATION<sup>13+</sup>     | 6616005 | 许可证策略不允许该操作。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_SYSTEM_ERROR<sup>13+</sup>     | 6616006 | DRM系统中发生错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_DEVICE_REVOKED<sup>13+</sup>     | 6616007 | 设备已撤销DRM权限。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_LICENSE_EXPIRED<sup>13+</sup>   | 6616008 | 加载中的DRM许可证已过期。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
| ERR_CODE_CAST_CONTROL_DRM_PROVIDE_KEY_RESPONSE_ERROR<sup>13+</sup>    | 6616100 | DRM处理密钥响应时发生错误。 <br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br>**系统能力：** SystemCapability.Multimedia.AVSession.AVCast|

## SkipIntervals<sup>11+</sup>

表示session支持的快进快退时间间隔的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                   | 值 | 说明                     |
| ---------------------- | -- | ----------------------- |
| SECONDS_10             | 10 | 时间为10秒。             |
| SECONDS_15             | 15 | 时间为15秒。             |
| SECONDS_30             | 30 | 时间为30秒。             |
