# Interface (AVCastController)

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

在投播建立后，调用[avSession.getAVCastController](arkts-apis-avsession-AVSession.md#getavcastcontroller10)后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

获取当前的远端播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\> | 是   | 回调函数，返回远端播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

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

## getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>

获取当前的远端播放状态。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise<[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\>  | Promise对象。返回远端播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info('getAVPlaybackState : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getSupportedDecoders<sup>19+</sup>

getSupportedDecoders(): Promise\<Array\<DecoderType>>

获取当前远端设备的解码方式。使用Promise异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise\<Array\<[DecoderType](arkts-apis-avsession-e.md#decodertype19)\>\> | Promise对象。返回远端设备所支持的解码能力列表。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getSupportedDecoders().then((decoderTypes: avSession.DecoderType[]) => {
  console.info(`getSupportedDecoders : SUCCESS : decoderTypes.length : ${decoderTypes.length}`);
  if (decoderTypes.length > 0 ) {
    console.info(`getSupportedDecoders : SUCCESS : decoderTypes[0] : ${decoderTypes[0]}`);
  }
}).catch((err: BusinessError) => {
  console.error(`getSupportedDecoders BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getRecommendedResolutionLevel<sup>19+</sup>

getRecommendedResolutionLevel(decoderType: DecoderType): Promise\<ResolutionLevel>

通过传递解码方式，获取推荐的分辨率。使用Promise异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| decoderType | [DecoderType](arkts-apis-avsession-e.md#decodertype19) | 是 | 设备所支持的解码格式。<br>设备所支持的解码格式包括：<br>'OH_AVCODEC_MIMETYPE_VIDEO_AVC'：VIDEO AVC，<br>'OH_AVCODEC_MIMETYPE_VIDEO_HEVC'：VIDEO HEVC，<br>'OH_AVCODEC_MIMETYPE_AUDIO_VIVID'：AUDIO AV3A。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise\<[ResolutionLevel](arkts-apis-avsession-e.md#resolutionlevel19)\> | Promise对象。返回远端设备推荐的分辨率。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let decoderType = avSession.DecoderType.OH_AVCODEC_MIMETYPE_VIDEO_AVC;
let resolutionLeve = avSession.ResolutionLevel;
aVCastController.getRecommendedResolutionLevel(decoderType).then((resolutionLeve) => {
  console.info('getRecommendedResolutionLevel successfully');
}).catch((err: BusinessError) => {
  console.error(`getRecommendedResolutionLevel BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getSupportedHdrCapabilities<sup>19+</sup>

getSupportedHdrCapabilities(): Promise\<Array\<hdrCapability.HDRFormat>>

获取当前的远端设备所支持的HDR能力。使用Promise异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise\<Array\<[hdrCapability.HDRFormat](../apis-arkgraphics2d/js-apis-hdrCapability.md#hdrformat)\>\> | Promise对象。返回远端设备所支持的HDR能力。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import type hdrCapability from './@ohos.graphics.hdrCapability';

aVCastController.getSupportedHdrCapabilities().then((hdrFormats: hdrCapability.HDRFormat[]) => {
  console.info(`getSupportedHdrCapabilities : SUCCESS : hdrFormats.length : ${hdrFormats.length}`);
  if (hdrFormats.length > 0 ) {
    console.info(`getSupportedHdrCapabilities : SUCCESS : descriptors[0] : ${hdrFormats[0]}`);
  }
}).catch((err: BusinessError) => {
  console.error(`getSupportedHdrCapabilities BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getSupportedPlaySpeeds<sup>19+</sup>

getSupportedPlaySpeeds(): Promise\<Array\<number>>

获取当前的远端设备所支持倍速播放列表。使用Promise异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise\<Array\<number\>\> | Promise对象。返回远端设备所支持的倍速播放列表。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getSupportedPlaySpeeds().then((nums: number[]) => {
  console.info(`getSupportedPlaySpeeds : SUCCESS : hdrFormats.length : ${nums.length}`);
  if (nums.length > 0 ) {
    console.info(`getSupportedPlaySpeeds : SUCCESS : descriptors[0] : ${nums[0]}`);
  }
}).catch((err: BusinessError) => {
  console.error(`getSupportedPlaySpeeds BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand): Promise\<void>

通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVCastControlCommand](arkts-apis-avsession-i.md#avcastcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600105  | Invalid session command.Stop sending the command or event,sending commands supported by the controlled end. |
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

## sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void>): void

通过会话控制器发送命令到其对应的会话。结果通过callback异步回调方式返回。


**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVCastControlCommand](arkts-apis-avsession-i.md#avcastcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600105  | Invalid session command.Stop sending the command or event,sending commands supported by the controlled end. |
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

## prepare<sup>10+</sup>

prepare(item: AVQueueItem, callback: AsyncCallback\<void>): void

准备播放媒体资源，即进行播放资源的加载和缓冲。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放。
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
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲。
aVCastController.prepare(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('prepare successfully');
  }
});
```

## prepare<sup>10+</sup>

prepare(item: AVQueueItem): Promise\<void>

准备播放媒体资源，即进行播放资源的加载和缓冲。结果通过Promise异步回调方式返回。


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放。
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
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲。
aVCastController.prepare(playItem).then(() => {
  console.info('prepare successfully');
}).catch((err: BusinessError) => {
  console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## start<sup>10+</sup>

start(item: AVQueueItem, callback: AsyncCallback\<void>): void

启动播放某个媒体资源。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放。
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

// 启动播放。
aVCastController.start(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`start BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('start successfully');
  }
});
```

## start<sup>10+</sup>

start(item: AVQueueItem): Promise\<void>

启动播放某个媒体资源。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置播放参数，开始播放。
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
// 启动播放。
aVCastController.start(playItem).then(() => {
  console.info('start successfully');
}).catch((err: BusinessError) => {
  console.error(`start BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getCurrentItem<sup>10+</sup>

getCurrentItem(callback: AsyncCallback\<AVQueueItem>): void

获取当前投播的资源信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

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

## getCurrentItem<sup>10+</sup>

getCurrentItem(): Promise\<AVQueueItem>

获取当前投播的资源信息。结果通过Promise异步回调方式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)> | Promise对象，返回当前的播放资源，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getCurrentItem().then((value: avSession.AVQueueItem) => {
  console.info('getCurrentItem successfully');
}).catch((err: BusinessError) => {
  console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## getValidCommands<sup>11+</sup>

getValidCommands(callback: AsyncCallback<Array\<AVCastControlCommandType>>): void

获取当前支持的命令。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback<Array<[AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)>> | 是 | 回调函数。返回当前支持的命令。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getValidCommands((err: BusinessError, state: avSession.AVCastControlCommandType[]) => {
  if (err) {
    console.error(`getValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('getValidCommands successfully');
  }
});
```

## getValidCommands<sup>11+</sup>

getValidCommands(): Promise<Array\<AVCastControlCommandType>>

获取当前支持的命令。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型 | 说明 |
| -------------- | ----------------------------- |
| Promise<Array\<[AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)>> | Promise对象，返回当前支持的命令。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.getValidCommands().then((state: avSession.AVCastControlCommandType[]) => {
  console.info('getValidCommands successfully');
}).catch((err: BusinessError) => {
  console.error(`getValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## processMediaKeyResponse<sup>12+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
let keyRequestCallback: avSession.KeyRequestCallback = async(assetId: string, requestData: Uint8Array) => {
  // 根据assetId获取对应的DRM url。
  let drmUrl = 'http://license.xxx.xxx.com:8080/drmproxy/getLicense';
  // 从服务器获取许可证，需要开发者根据实际情况进行赋值。
  let licenseResponseData: Uint8Array = new Uint8Array();
  console.info(`Succeeded in get license by ${drmUrl}.`);
  aVCastController.processMediaKeyResponse(assetId, licenseResponseData);
}
```

## release<sup>11+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

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

## release<sup>11+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.release().then(() => {
  console.info('release successfully');
}).catch((err: BusinessError) => {
  console.error(`release BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

## on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void): void

设置播放状态变化的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playbackStateChange'`：当播放状态变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注播放状态所有字段变化；Array<keyof&nbsp;[AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)\> 表示关注Array中的字段变化。 |
| callback | (state: [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)) => void         | 是   | 回调函数，参数state是变化后的播放状态。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

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

## off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void): void

媒体控制器取消监听播放状态变化的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playbackStateChange'`。    |
| callback | (state: [AVPlaybackState](arkts-apis-avsession-i.md#avplaybackstate10)) => void         | 否   | 回调函数，参数state是变化后的播放状态。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('playbackStateChange');
```

## on('mediaItemChange')<sup>10+</sup>

on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void

设置投播当前播放媒体内容的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'mediaItemChange'`：当播放的媒体内容变化时，触发该事件。 |
| callback | Callback<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)>         | 是   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.on('mediaItemChange', (item: avSession.AVQueueItem) => {
  console.info(`on mediaItemChange state : ${item.itemId}`);
});
```

## off('mediaItemChange')<sup>10+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('mediaItemChange');
```

## on('playNext')<sup>10+</sup>

on(type: 'playNext', callback: Callback\<void>): void

设置播放下一首资源的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playNext'`：当播放下一首状态变化时，触发该事件。 |
| callback | Callback\<void\>         | 是   | 回调函数。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.on('playNext', () => {
  console.info('on playNext');
});
```

## off('playNext')<sup>10+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('playNext');
```

## on('playPrevious')<sup>10+</sup>

on(type: 'playPrevious', callback: Callback\<void>): void

设置播放上一首资源的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playPrevious'`：当播放上一首状态变化时，触发该事件。 |
| callback | Callback\<void\>         | 是   | 回调函数。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.on('playPrevious', () => {
  console.info('on playPrevious');
});
```

## off('playPrevious')<sup>10+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('playPrevious');
```

## on('requestPlay')<sup>11+</sup>

on(type: 'requestPlay', callback: Callback\<AVQueueItem>): void

设置请求播放的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'requestPlay'`：当请求播放状态变化时，触发该事件。 |
| callback | Callback\<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)>                | 是   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。当监听事件注册成功，err为undefined，否则返回错误对象。  | 

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.on('requestPlay', (item: avSession.AVQueueItem) => {
  console.info(`on requestPlay state : ${item.itemId}`);
});
```

## off('requestPlay')<sup>11+</sup>

off(type: 'requestPlay', callback?: Callback\<AVQueueItem>): void

取消设置请求播放的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------| ---- | ----------------------------------------------------- |
| type     | string                                                      | 是   | 取消对应的监听事件，支持事件`'requestPlay'`。    |
| callback | Callback\<[AVQueueItem](arkts-apis-avsession-i.md#avqueueitem10)>             | 否   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('requestPlay');
```

## on('endOfStream')<sup>11+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.on('endOfStream', () => {
  console.info('on endOfStream');
});
```

## off('endOfStream')<sup>11+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('endOfStream');
```

## on('seekDone')<sup>10+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

设置seek结束的监听事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'seekDone'`：当seek结束时，触发该事件。 |
| callback | Callback\<number\>         | 是   | 回调函数，返回seek后播放的位置。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.on('seekDone', (pos: number) => {
  console.info(`on seekDone pos：${pos} `);
});
```

## off('seekDone')<sup>10+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('seekDone');
```

## on('validCommandChange')<sup>11+</sup>

on(type: 'validCommandChange', callback: Callback\<Array\<AVCastControlCommandType>>)

会话支持的有效命令变化监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'validCommandChange'`：当检测到会话的合法命令发生改变时，触发该事件。 |
| callback | Callback<Array<[AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)\>\>   | 是   | 回调函数。参数commands是有效命令的集合。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
aVCastController.on('validCommandChange', (validCommands: avSession.AVCastControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

## off('validCommandChange')<sup>11+</sup>

off(type: 'validCommandChange', callback?: Callback\<Array\<AVCastControlCommandType>>)

媒体控制器取消监听会话有效命令变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'validCommandChange'`。         |
| callback | Callback<Array<[AVCastControlCommandType](arkts-apis-avsession-t.md#avcastcontrolcommandtype10)\>\> | 否   | 回调函数。参数commands是有效命令的集合。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
aVCastController.off('validCommandChange');
```

## on('error')<sup>10+</sup>

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

aVCastController.on('error', (error: BusinessError) => {
  console.info(`error happened, error code: ${error.code}, error message : ${error.message}.`)
})
```

## off('error')<sup>10+</sup>

off(type: 'error'): void

取消监听播放的错误事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | 是   | 错误事件回调类型，取消注册的事件：'error'。 |

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
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('error')
```

## on('keyRequest')<sup>12+</sup>

on(type: 'keyRequest', callback: KeyRequestCallback): void

在线DRM资源投播时，设置许可证请求的事件监听。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type     | string  | 是   | 事件回调类型，支持事件`'keyRequest'`：当DRM资源播放需要许可证时，触发该事件。 |
| callback | [KeyRequestCallback](arkts-apis-avsession-t.md#keyrequestcallback12)  | 是   | 回调函数，媒体资源及许可证请求数据。|


**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
let keyRequestCallback: avSession.KeyRequestCallback = async(assetId: string, requestData: Uint8Array) => {
  console.info(`Succeeded in keyRequestCallback. assetId: ${assetId}, requestData: ${requestData}`);
}
aVCastController.on('keyRequest', keyRequestCallback);
```

## off('keyRequest')<sup>12+</sup>

off(type: 'keyRequest', callback?: KeyRequestCallback): void

取消监听许可证请求的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持的事件是`'keyRequest'`。 |
| callback |  [KeyRequestCallback](arkts-apis-avsession-t.md#keyrequestcallback12)  | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception.You are advised to:1.Scheduled retry.2.Destroy the current session or session controller and re-create it. |

**示例：**

```ts
aVCastController.off('keyRequest');
```

## on('castControlGenericError')<sup>13+</sup>

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

## off('castControlGenericError')<sup>13+</sup>

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

## on('castControlIoError')<sup>13+</sup>

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

## off('castControlIoError')<sup>13+</sup>

off(type: 'castControlIoError', callback?: ErrorCallback): void

取消监听投播输入/输出的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 取消对应的监听事件，支持的事件是'castControlIoError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
aVCastController.off('castControlIoError');
```

## on('castControlParsingError')<sup>13+</sup>

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

## off('castControlParsingError')<sup>13+</sup>

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

## on('castControlDecodingError')<sup>13+</sup>

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

## off('castControlDecodingError')<sup>13+</sup>

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

## on('castControlAudioRendererError')<sup>13+</sup>

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

## off('castControlAudioRendererError')<sup>13+</sup>

off(type: 'castControlAudioRendererError', callback?: ErrorCallback): void

取消监听投播音频渲染器的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 取消对应的监听事件，支持的事件是'castControlAudioRendererError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|

**示例：**

```ts
aVCastController.off('castControlAudioRendererError');
```

## on('castControlDrmError')<sup>13+</sup>

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

## off('castControlDrmError')<sup>13+</sup>

off(type: 'castControlDrmError', callback?: ErrorCallback): void

取消监听投播drm的错误事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 取消对应的监听事件，支持的事件是'castControlDrmError'。 |
| callback | ErrorCallback | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 401 |  Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
aVCastController.off('castControlDrmError');
```
