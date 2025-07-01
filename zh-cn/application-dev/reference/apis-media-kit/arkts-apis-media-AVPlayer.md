# Interface (AVPlayer)

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

播放管理类，用于管理和播放媒体资源。在调用AVPlayer的方法前，需要先通过[createAVPlayer()](arkts-apis-media-f.md#mediacreateavplayer9)构建一个AVPlayer实例。

Audio/Video播放demo可参考：[音频播放开发指导](../../media/media/using-avplayer-for-playback.md)、[视频播放开发指导](../../media/media/video-playback.md)。

> **说明：**
>
> 在使用AVPlayer实例的方法时，建议开发者注册相关回调，主动获取当前状态变化。
>
> - [on('stateChange')](#onstatechange9)：监听播放状态机AVPlayerState切换。
> - [on('error')](#onerror9)：监听错误事件。

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称                                                | 类型                                                         | 只读 | 可选 | 说明                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>9+</sup>                                    | string                                                       | 否   | 是   | 媒体URL，只允许在**idle**状态下设置。<br/>支持的视频格式(mp4、mpeg-ts、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac、amr)。<br/>**支持路径示例**：<br>1. fd类型播放：fd://xx。<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http\://xx。<br/>3. https网络播放: https\://xx。<br/>4. hls网络播放路径：http\://xx或者https\://xx。<br>**说明：**<br>- 设置网络播放路径，需[声明权限](../../security/AccessToken/declare-permissions.md)：[ohos.permission.INTERNET](../../security/AccessToken/permissions-for-all.md#ohospermissioninternet)，相关错误码: [201](../errorcode-universal.md)。<br>- 从API version 11开始不支持webm。<br> - 将资源句柄（fd）传递给 AVPlayer 实例之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个 AVPlayer / AVMetadataExtractor / AVImageGenerator / AVTranscoder。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致媒体播放器数据获取异常。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fdSrc<sup>9+</sup>                                  | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                       | 否   | 是   | 媒体文件描述，只允许在**idle**状态下设置。<br/>使用场景：应用中的媒体资源被连续存储在同一个文件中。<br/>支持的视频格式(mp4、mpeg-ts、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac、amr)。<br/>**使用示例**：<br/>假设一个连续存储的媒体文件: <br/>视频1(地址偏移:0，字节长度:100)；<br/>视频2(地址偏移:101，字节长度:50)；<br/>视频3(地址偏移:151，字节长度:150)；<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }。<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }。<br/>假设是一个独立的媒体文件: 请使用src=fd://xx。<br>**说明：**<br>从API version 11开始不支持webm。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| dataSrc<sup>10+</sup>                               | [AVDataSrcDescriptor](arkts-apis-media-i.md#avdatasrcdescriptor10)                | 否   | 是   | 流式媒体资源描述，只允许在**idle**状态下设置。<br/>使用场景：应用播放从远端下载到本地的文件，在应用未下载完整音视频资源时，提前播放已获取的资源文件。<br/>支持的视频格式(mp4、mpeg-ts、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac、amr)。<br/>**使用示例**：<br/>假设用户正在从远端服务器获取音视频媒体文件，希望下载到本地的同时播放已经下载好的部分: <br/>1.用户需要获取媒体文件的总大小size（单位为字节），获取不到时设置为-1。<br/>2.用户需要实现回调函数func用于填写数据，如果size = -1，则func形式为：func(buffer: ArrayBuffer, length: number)，此时播放器只会按照顺序获取数据；否则func形式为：func(buffer: ArrayBuffer, length: number, pos: number)，播放器会按需跳转并获取数据。<br/>3.用户设置AVDataSrcDescriptor {fileSize = size, callback = func}。<br/>**注意事项**：<br/>如果播放的是mp4/m4a格式用户需要保证moov字段（媒体信息字段）在mdat字段（媒体数据字段）之前，或者moov之前的字段小于10M，否则会导致解析失败无法播放。<br>**说明：**<br>从API version 11开始不支持webm。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| surfaceId<sup>9+</sup>                              | string                                                       | 否   | 是   | 视频窗口ID，默认无窗口。<br/>支持在**initialized**状态下设置。<br/>支持在**prepared**/**playing**/**paused**/**completed**/**stopped**状态下重新设置，重新设置时确保已经在**initialized**状态下进行设置，否则重新设置失败，重新设置后视频播放在新的窗口渲染。<br/>使用场景：视频播放的窗口渲染，纯音频播放不用设置。<br/>**使用示例**：<br/>[通过XComponent创建surfaceId](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| loop<sup>9+</sup>                                   | boolean                                                      | 否   | 否   | 视频循环播放属性，默认'false'，设置为'true'表示循环播放，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。<br/>直播场景不支持loop设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| videoScaleType<sup>9+</sup>                         | [VideoScaleType](arkts-apis-media-e.md#videoscaletype9)                           | 否   | 是   | 视频缩放模式，默认VIDEO_SCALE_TYPE_FIT，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioInterruptMode<sup>9+</sup>                     | [audio.InterruptMode](../apis-audio-kit/arkts-apis-audio-e.md#interruptmode9)       | 否   | 是   | 音频焦点模型，默认SHARE_MODE，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。<br/>在第一次调用[play()](#play9)之前设置， 以便此后中断模式生效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioRendererInfo<sup>10+</sup>                     | [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8) | 否   | 是   | 设置音频渲染信息。若媒体源包含视频，则usage默认值为STREAM_USAGE_MOVIE，否则usage默认值为STREAM_USAGE_MUSIC。rendererFlags默认值为0。若默认usage不满足需求，则须主动配置[audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)。<br/>只允许在**initialized**状态下设置。<br/>在第一次调用[prepare()](#prepare9)之前设置，以便音频渲染器信息在之后生效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioEffectMode<sup>10+</sup>                       | [audio.AudioEffectMode](../apis-audio-kit/arkts-apis-audio-e.md#audioeffectmode10)  | 否   | 是   | 设置音频音效模式，默认值为EFFECT_DEFAULT，动态属性。audioRendererInfo的usage变动时会恢复为默认值，只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| state<sup>9+</sup>                                  | [AVPlayerState](arkts-apis-media-t.md#avplayerstate9)                             | 是   | 否   | 音视频播放的状态，全状态有效，可查询参数。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                  |
| currentTime<sup>9+</sup>                            | number                                                       | 是   | 否   | 视频的当前播放位置，单位为毫秒（ms），可查询参数。<br/>返回为(-1)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回(-1)。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| duration<sup>9+</sup> | number                                                       | 是   | 否   | 视频时长，单位为毫秒（ms），可查询参数。<br/>返回为(-1)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回(-1)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| width<sup>9+</sup>                                  | number                                                       | 是   | 否   | 视频宽，单位为像素（px），可查询参数。<br/>返回为(0)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| height<sup>9+</sup>                                 | number                                                       | 是   | 否   | 视频高，单位为像素（px），可查询参数。<br/>返回为(0)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

## on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: OnAVPlayerStateChangeHandle): void

监听播放状态机AVPlayerState切换的事件。

**原子化服务API：** 从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |
| callback | [OnAVPlayerStateChangeHandle](arkts-apis-media-t.md#onavplayerstatechangehandle12) | 是   | 状态机切换事件回调方法。 |

**示例：**

```ts
avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
  switch (state) {
    case 'idle':
      console.info('state idle called');
      break;
    case 'initialized':
      console.info('initialized prepared called');
      break;
    case 'prepared':
      console.info('state prepared called');
      break;
    case 'playing':
      console.info('state playing called');
      break;
    case 'paused':
      console.info('state paused called');
      break;
    case 'completed':
      console.info('state completed called');
      break;
    case 'stopped':
      console.info('state stopped called');
      break;
    case 'released':
      console.info('state released called');
      break;
    case 'error':
      console.info('state error called');
      break;
    default:
      console.info('unknown state :' + state);
      break;
  }
});
```

## off('stateChange')<sup>9+</sup>

off(type: 'stateChange', callback?: OnAVPlayerStateChangeHandle): void

取消监听播放状态机[AVPlayerState](arkts-apis-media-t.md#avplayerstate9)切换的事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                  |
| ------ | ------ | ---- | ----------------------------------------------------- |
| type   | string | 是   | 状态机切换事件回调类型，取消注册的事件：'stateChange' |
| callback   | [OnAVPlayerStateChangeHandle](arkts-apis-media-t.md#onavplayerstatechangehandle12) | 否   | 状态机切换事件回调方法。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('stateChange');
```

## on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

监听[AVPlayer](arkts-apis-media-AVPlayer.md)的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时[AVPlayerState](arkts-apis-media-t.md#avplayerstate9)也切至error状态，用户需要通过[reset()](#reset9)或者[release()](#release9)退出播放操作。

**原子化服务API：** 从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 错误事件回调方法，使用播放器的过程中发生错误，会提供错误码ID和错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

在API version 9-13，针对网络、服务器等数据流异常，接口上报5400103；从API version 14开始，对应错误细化为错误码5411001-5411011。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 201      | Permission denied.     |
| 401      | The parameter check failed. |
| 801      | Capability not supported. |
| 5400101  | No memory. |
| 5400102  | Operation not allowed.|
| 5400103  | I/O error.             |
| 5400104  | Time out.              |
| 5400105  | Service died.         |
| 5400106  | Unsupported format.     |
| 5411001  | IO can not find host.    |
| 5411002  | IO connection timeout.  |
| 5411003  | IO network abnormal.     |
| 5411004  | IO network unavailable.  |
| 5411005  | IO no permission.        |
| 5411006  | IO request denied.  |
| 5411007  | IO resource not found. |
| 5411008  | IO SSL client cert needed.    |
| 5411009  | IO SSL connect fail.     |
| 5411010  | IO SSL server cert untrusted.    |
| 5411011  | IO unsupported request.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.on('error', (error: BusinessError) => {
  console.info('error happened,and error message is :' + error.message);
  console.info('error happened,and error code is :' + error.code);
});
```

## off('error')<sup>9+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消监听播放的错误事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | 是   | 错误事件回调类型，取消注册的事件：'error' |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 错误事件回调方法，使用播放器的过程中发生错误，会提供错误码ID和错误信息。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('error');
```

## setMediaSource<sup>12+</sup>

setMediaSource(src:MediaSource, strategy?: PlaybackStrategy): Promise\<void>

流媒体预下载资源设置，下载url对应的流媒体数据，并暂存在内存中。[视频播放开发指导](../../media/media/video-playback.md)。通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| src | [MediaSource](arkts-apis-media-MediaSource.md) | 是   | 流媒体预下载媒体来源。 |
| strategy | [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12) | 否   | 流媒体预下载播放策略。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
let player = await media.createAVPlayer();
let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
let playStrategy : media.PlaybackStrategy = {
  preferredWidth: 1,
  preferredHeight: 2,
  preferredBufferDuration: 3,
  preferredHdr: false,
  preferredBufferDurationForPlaying: 1,
  thresholdForAutoQuickPlay: 5
};
player.setMediaSource(mediaSource, playStrategy);
```

## setPlaybackStrategy<sup>12+</sup>

setPlaybackStrategy(strategy: PlaybackStrategy): Promise\<void>

设置播放策略，只能在initialized状态下调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| strategy | [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12) | 是   | 播放策略。 |

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

private context: Context | undefined;
constructor(context: Context) {
  this.context = context; // this.getUIContext().getHostContext();
}

let player = await media.createAVPlayer();
let fileDescriptor = await this.context.resourceManager.getRawFd('xxx.mp4');
player.fdSrc = fileDescriptor
let playStrategy : media.PlaybackStrategy = {
  preferredWidth: 1,
  preferredHeight: 2,
  preferredBufferDuration: 3,
  preferredHdr: false,
  mutedMediaType: media.MediaType.MEDIA_TYPE_AUD,
  preferredBufferDurationForPlaying: 1,
  thresholdForAutoQuickPlay: 5
};
player.setPlaybackStrategy(playStrategy);
```

## setPlaybackRange<sup>18+</sup>

setPlaybackRange(startTimeMs: number, endTimeMs: number, mode?: SeekMode) : Promise\<void>

设置播放区间，并通过指定的[SeekMode](arkts-apis-media-e.md#seekmode8)跳转到区间开始位置。设置之后，只播放音视频文件设定区间内的内容。该方法异步方式返回执行结果，通过Promise获取返回值。可在**initialized**/**prepared**/**paused**/**stopped**/**completed**状态下使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| startTimeMs | number | 是   | 区间开始位置，单位ms，取值[0, duration)。可以设置-1值，系统将会从0位置开始播放。|
| endTimeMs | number | 是   | 区间结束位置，单位ms，取值(startTimeMs, duration]。可以设置-1值，系统将会播放到资源末尾。|
| mode | [SeekMode](arkts-apis-media-e.md#seekmode8) | 否   | 支持SeekMode.SEEK_PREV_SYNC和SeekMode.SEEK_CLOSEST, <br/>默认值: SeekMode.SEEK_PREV_SYNC。|

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401  | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.setPlaybackRange(0, 6000, media.SeekMode.SEEK_CLOSEST).then(() => {
  console.info('Succeeded setPlaybackRange');
}).catch((err: BusinessError) => {
  console.error('Failed to setPlaybackRange' + err.message);
});
```

## prepare<sup>9+</sup>

prepare(callback: AsyncCallback\<void>): void

准备播放音频/视频，需在[stateChange](#onstatechange9)事件成功触发至initialized状态后，才能调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 准备播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupported format. Return by callback.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.prepare((err: BusinessError) => {
  if (err) {
    console.error('Failed to prepare,error message is :' + err.message);
  } else {
    console.info('Succeeded in preparing');
  }
});
```

## prepare<sup>9+</sup>

prepare(): Promise\<void>

准备播放音频/视频，需在[stateChange](#onstatechange9)事件成功触发至initialized状态后，才能调用。通过Promise获取返回值。

如果应用使用到多个短视频频繁切换的场景，为了提升切换性能，可以考虑创建多个AVPlayer对象，提前准备下一个视频，详情参见[在线短视频流畅切换](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-smooth-switching)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 准备播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400106  | Unsupported format. Return by promise.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.prepare().then(() => {
  console.info('Succeeded in preparing');
}, (err: BusinessError) => {
  console.error('Failed to prepare,error message is :' + err.message);
});
```

## setMediaMuted<sup>12+</sup>

setMediaMuted(mediaType: MediaType,  muted: boolean ): Promise\<void>

设置音频静音/取消音频静音。

从API 20开始，支持设置关闭视频画面/取消关闭视频画面。

只能在prepared/playing/paused/completed状态下调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| mediaType | [MediaType](arkts-apis-media-e.md#mediatype8) | 是   | 播放策略。 |
| muted | boolean | 是   | API 12-19，仅支持设置音频格式，表示音频是否静音播放。true表示是静音播放，false表示不是静音播放。<br>API20增加支持设置视频格式，表示视频画面是否关闭，true表示关闭画面，false表示恢复画面。|

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 准备播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------- |
| 401 | The parameter check failed. Return by promise. |
| 5400102 | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.prepare().then(() => {
  console.info('Succeeded in preparing');
  avPlayer.setMediaMuted(media.MediaType.MEDIA_TYPE_AUD, true);
}, (err: BusinessError) => {
  console.error('Failed to prepare,error message is :' + err.message);
});
```

## play<sup>9+</sup>

play(callback: AsyncCallback\<void>): void

开始播放音视频资源，只能在prepared/paused/completed状态调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 开始播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.play((err: BusinessError) => {
  if (err) {
    console.error('Failed to play,error message is :' + err.message);
  } else {
    console.info('Succeeded in playing');
  }
});
```

## play<sup>9+</sup>

play(): Promise\<void>

开始播放音视频资源，只能在prepared/paused/completed状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 开始播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.play().then(() => {
  console.info('Succeeded in playing');
}, (err: BusinessError) => {
  console.error('Failed to play,error message is :' + err.message);
});
```

## pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

暂停播放音视频资源，只能在playing状态调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 暂停播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.pause((err: BusinessError) => {
  if (err) {
    console.error('Failed to pause,error message is :' + err.message);
  } else {
    console.info('Succeeded in pausing');
  }
});
```

## pause<sup>9+</sup>

pause(): Promise\<void>

暂停播放音视频资源，只能在playing状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 暂停播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.pause().then(() => {
  console.info('Succeeded in pausing');
}, (err: BusinessError) => {
  console.error('Failed to pause,error message is :' + err.message);
});
```

## stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

停止播放音视频资源，只能在prepared/playing/paused/completed状态调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 停止播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.stop((err: BusinessError) => {
  if (err) {
    console.error('Failed to stop,error message is :' + err.message);
  } else {
    console.info('Succeeded in stopping');
  }
});
```

## stop<sup>9+</sup>

stop(): Promise\<void>

停止播放音视频资源，只能在prepared/playing/paused/completed状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 停止播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.stop().then(() => {
  console.info('Succeeded in stopping');
}, (err: BusinessError) => {
  console.error('Failed to stop,error message is :' + err.message);
});
```

## reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

重置播放，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 重置播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.reset((err: BusinessError) => {
  if (err) {
    console.error('Failed to reset,error message is :' + err.message);
  } else {
    console.info('Succeeded in resetting');
  }
});
```

## reset<sup>9+</sup>

reset(): Promise\<void>

重置播放，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 重置播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.reset().then(() => {
  console.info('Succeeded in resetting');
}, (err: BusinessError) => {
  console.error('Failed to reset,error message is :' + err.message);
});
```

## release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

销毁播放资源，除released状态外，均可以调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 销毁播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.release((err: BusinessError) => {
  if (err) {
    console.error('Failed to release,error message is :' + err.message);
  } else {
    console.info('Succeeded in releasing');
  }
});
```

## release<sup>9+</sup>

release(): Promise\<void>

销毁播放资源，除released状态，都可以调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 销毁播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.release().then(() => {
  console.info('Succeeded in releasing');
}, (err: BusinessError) => {
  console.error('Failed to release,error message is :' + err.message);
});
```

## getTrackDescription<sup>9+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

获取音视频轨道信息，可以在prepared/playing/paused状态调用。获取所有音视轨道信息，应在数据加载回调后调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | 是   | 回调函数，当获取音视频轨道信息成功，err为undefined，data为获取到的MediaDescription数组；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if ((arrList) != null) {
    console.info('Succeeded in doing getTrackDescription');
  } else {
    console.error(`Failed to do getTrackDescription, error:${error}`);
  }
});
```

## getTrackDescription<sup>9+</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

获取音视频轨道信息，可以在prepared/playing/paused状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Promise对象，返回音视频轨道信息MediaDescription数组。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  console.info('Succeeded in getting TrackDescription');
}).catch((error: BusinessError) => {
  console.error(`Failed to get TrackDescription, error:${error}`);
});
```

## getSelectedTracks<sup>12+</sup>

getSelectedTracks(): Promise\<Array\<number>>

获取已选择的音视频轨道索引，可以在prepared/playing/paused状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise\<Array\<number>> | Promise对象，返回已选择音视频轨道索引数组。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.getSelectedTracks().then((arrList: Array<number>) => {
  console.info('Succeeded in getting SelectedTracks');
}).catch((error: BusinessError) => {
  console.error(`Failed to get SelectedTracks, error:${error}`);
});
```

## getPlaybackInfo<sup>12+</sup>

getPlaybackInfo(): Promise\<PlaybackInfo>

获取播放过程信息，可以在prepared/playing/paused状态调用。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<[PlaybackInfo](arkts-apis-media-i.md#playbackinfo12)> | Promise对象，返回播放器信息PlaybackInfo。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer | undefined = undefined;
let playbackInfo: media.PlaybackInfo | undefined = undefined;
media.createAVPlayer(async (err: BusinessError, player: media.AVPlayer) => {
  if (player != null) {
    avPlayer = player;
    console.info(`Succeeded in creating AVPlayer`);
    if (avPlayer) {
      try {
        playbackInfo = await avPlayer.getPlaybackInfo();
        console.info(`AVPlayer getPlaybackInfo = ${JSON.stringify(playbackInfo)}`); // 打印整个PlaybackInfo的值。
      } catch (error) {
        console.error(`error = ${error}`);
      }
    }
  } else {
    console.error(`Failed to create AVPlayer, error message:${err.message}`);
  }
});
```

## getPlaybackPosition<sup>18+</sup>

getPlaybackPosition(): number

获取当前播放位置，可以在prepared/playing/paused/completed状态调用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| number | 返回当前播放位置的时间，单位：毫秒（ms）。|

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.prepare().then(() => {
  console.info('Succeeded in preparing');
  let playbackPosition: number = avPlayer.getPlaybackPosition();
  console.info(`AVPlayer getPlaybackPosition== ${playbackPosition}`);
}, (err: BusinessError) => {
  console.error('Failed to prepare,error message is :' + err.message);
});
```

## selectTrack<sup>12+</sup>

selectTrack(index: number, mode?: SwitchMode): Promise\<void>

使用AVPlayer播放多音视频轨资源时，选择指定轨道播放，通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| index | number | 是   | 多音视频资源的轨道索引，可通过[getTrackDescription](#gettrackdescription9-1)接口获取当前资源的所有轨道信息[MediaDescription](arkts-apis-media-i.md#mediadescription8)。 |
| mode   | [SwitchMode](arkts-apis-media-e.md#switchmode12) | 否   | 切换视频轨道模式，默认为SMOOTH模式，**仅在DASH协议网络流视频轨切换时生效**，其他场景当前暂不支持。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 选择轨道完成的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | The parameter check failed. Return by promise.       |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer = await media.createAVPlayer();
let audioTrackIndex: Object = 0;
avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    for (let i = 0; i < arrList.length; i++) {
      if (i != 0) {
        // 获取音频轨道列表。
        audioTrackIndex = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
      }
    }
  } else {
    console.error(`Failed to get TrackDescription, error:${error}`);
  }
});

// 选择其中一个音频轨道。
avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
```

## deselectTrack<sup>12+</sup>

deselectTrack(index: number): Promise\<void>

使用AVPlayer播放多音轨视频时取消指定音视频轨道播放，通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| index | number | 是   | 多音视频资源的轨道索引，来自[getTrackDescription](#gettrackdescription9-1)接口所获取的轨道信息[MediaDescription](arkts-apis-media-i.md#mediadescription8)。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 取消选择曲目完成的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | The parameter check failed. Return by promise.       |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer = await media.createAVPlayer();
let audioTrackIndex: Object = 0;
avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    for (let i = 0; i < arrList.length; i++) {
      if (i != 0) {
        // 获取音频轨道列表。
        audioTrackIndex = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
      }
    }
  } else {
    console.error(`Failed to get TrackDescription, error:${error}`);
  }
});

// 选择其中一个音频轨道。
avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
// 取消选择上次选中的音频轨道，并恢复到默认音频轨道。
avPlayer.deselectTrack(parseInt(audioTrackIndex.toString()));
```

## setDecryptionConfig<sup>11+</sup>

setDecryptionConfig(mediaKeySession: drm.MediaKeySession, secureVideoPath: boolean): void

设置解密配置。当收到[mediaKeySystemInfoUpdate事件](#onmediakeysysteminfoupdate11)时，需根据事件上报的信息创建相关配置并设置解密配置，否则无法播放。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| mediaKeySession | [drm.MediaKeySession](../apis-drm-kit/arkts-apis-drm-MediaKeySession.md) | 是   | 解密会话 |
| secureVideoPath | boolean | 是 | 安全视频通路，true表示选择安全视频通路，false表示选择非安全视频通路 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

关于drm模块的示例具体可见[@ohos.multimedia.drm](../apis-drm-kit/arkts-apis-drm.md)。

```ts
import { drm } from '@kit.DrmKit';

// 创建MediaKeySystem系统。
let keySystem:drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
// 创建MediaKeySession解密会话。
let keySession:drm.MediaKeySession = keySystem.createMediaKeySession(drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
// 生成许可证请求、设置许可证响应等。
// 安全视频通路标志。
let secureVideoPath:boolean = false;
// 设置解密配置。
avPlayer.setDecryptionConfig(keySession, secureVideoPath);
```

## getMediaKeySystemInfos<sup>11+</sup>

getMediaKeySystemInfos(): Array\<drm.MediaKeySystemInfo>

获取当前播放的媒体资源的MediaKeySystemInfo。需要在[mediaKeySystemInfoUpdate事件](#onmediakeysysteminfoupdate11)触发成功后才能调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
|  Array<[drm.MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)> | MediaKeySystemInfo数组，MediaKeySystemInfo具有uuid和pssh两个属性。 |

**示例：**

```ts
import { drm } from '@kit.DrmKit';

const infos = avPlayer.getMediaKeySystemInfos();
console.info('GetMediaKeySystemInfos count: ' + infos.length);
for (let i = 0; i < infos.length; i++) {
  console.info('GetMediaKeySystemInfos uuid: ' + infos[i]["uuid"]);
  console.info('GetMediaKeySystemInfos pssh: ' + infos[i]["pssh"]);
}
```

## seek<sup>9+</sup>

seek(timeMs: number, mode?:SeekMode): void

跳转到指定播放位置，只能在prepared/playing/paused/completed状态调用，可以通过[seekDone事件](#onseekdone9)确认是否生效。
注：直播场景不支持seek。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, [duration](#属性)]。SEEK_CONTINUOU模式可以额外取值-1，用于表示SEEK_CONTINUOUS模式结束。 |
| mode   | [SeekMode](arkts-apis-media-e.md#seekmode8) | 否   | 基于视频I帧的跳转模式，默认为SEEK_PREV_SYNC模式，**仅在视频资源播放时设置**。 |

**示例：**

```ts
let seekTime: number = 1000;
avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC);
```

```ts
// SEEK_CONTINUOUS 可以结合Slider的onChange回调方法进行对应处理，当slideMode为Moving时，触发拖动过程的SeekContinuous。
let slideMovingTime: number = 2000;
avPlayer.seek(slideMovingTime, media.SeekMode.SEEK_CONTINUOUS);

// 当slideMode为End时，调用seek(-1, media.SeekMode.SEEK_CONTINUOUS)结束seek。
avPlayer.seek(-1, media.SeekMode.SEEK_CONTINUOUS);
```

## isSeekContinuousSupported<sup>18+</sup>

isSeekContinuousSupported() : boolean

查询媒体源是否支持以SEEK_CONTINUOUS模式[SeekMode](arkts-apis-media-e.md#seekmode8)进行[seek](#seek9)，在prepared/playing/paused/completed状态调用返回实际值，其余状态调用返回false。对于不支持SEEK_CONTINUOUS模式进行seek的设备，返回false。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| boolean | 媒体源是否支持以SEEK_CONTINUOUS模式进行seek。 |

**示例：**

```ts
let isSupported = avPlayer.isSeekContinuousSupported();
```

## on('seekDone')<sup>9+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

监听seek生效的事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | seek生效的事件回调类型，支持的事件：'seekDone'，除SEEK_CONTINUOUS外的[SeekMode](arkts-apis-media-e.md#seekmode8)每次调用seek后都会回调此事件。 |
| callback | Callback\<number> | 是   | 回调函数。seek生效的事件回调方法，只会上报用户请求的time位置。<br/>**视频播放：**[SeekMode](arkts-apis-media-e.md#seekmode8)会造成实际跳转位置与用户设置产生偏差，精准位置需要通过currentTime获取，事件回调的time仅代表完成用户某一次请求。 |

**示例：**

```ts
avPlayer.on('seekDone', (seekDoneTime:number) => {
  console.info('seekDone called,and seek time is:' + seekDoneTime);
});
```

## off('seekDone')<sup>9+</sup>

off(type: 'seekDone', callback?: Callback\<number>): void

取消监听seek生效的事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                 |
| ------ | ------ | ---- | ---------------------------------------------------- |
| type   | string | 是   | seek生效的事件回调类型，取消注册的事件：'seekDone'。 |
| callback | Callback\<number> | 否   | 回调函数。seek生效的事件回调方法，只会上报用户请求的time位置。<br/>**视频播放：**[SeekMode](arkts-apis-media-e.md#seekmode8)会造成实际跳转位置与用户设置产生偏差，精准位置需要通过currentTime获取，事件回调的time仅代表完成用户某一次请求。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('seekDone');
```

## setSpeed<sup>9+</sup>

setSpeed(speed: PlaybackSpeed): void

设置倍速模式，只能在prepared/playing/paused/completed状态调用，可以通过[speedDone事件](#onspeeddone9)确认是否生效。
注：直播场景不支持setSpeed。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                             | 必填 | 说明               |
| ------ | -------------------------------- | ---- | ------------------ |
| speed  | [PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8) | 是   | 指定播放倍速模式。 |

**示例：**

```ts
avPlayer.setSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X);
```

## on('speedDone')<sup>9+</sup>

on(type: 'speedDone', callback: Callback\<number>): void

监听setSpeed生效的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | setSpeed生效的事件回调类型，支持的事件：'speedDone'，每次调用setSpeed后都会回调此事件。 |
| callback | Callback\<number> | 是   | 回调函数。当setSpeed成功，上报生效的倍速模式，具体见[PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8)。 |

**示例：**

```ts
avPlayer.on('speedDone', (speed:number) => {
  console.info('speedDone called,and speed value is:' + speed);
});
```

## off('speedDone')<sup>9+</sup>

off(type: 'speedDone', callback?: Callback\<number>): void

取消监听setSpeed生效的事件。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                      |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | 是   | setSpeed生效的事件回调类型，取消注册的事件：'speedDone'。 |
| callback | Callback\<number> | 否   | 回调函数。当setSpeed成功，上报生效的倍速模式，具体见[PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8)。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('speedDone');
```

## setPlaybackRate<sup>20+</sup>

setPlaybackRate(rate: number): void

设置倍速模式。只能在prepared/playing/paused/completed状态调用，取值范围是[0.125, 4.0]，可以通过[playbackRateDone](#onplaybackratedone20)事件确认是否生效。

> **注意：**
>
> 直播场景不支持setPlaybackRate。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                             | 必填 | 说明               |
| ------ | -------------------------------- | ---- | ------------------ |
| rate  | number | 是   | 指定播放倍速速率。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400108  | The parameter check failed, parameter value out of range.      |
| 5400102  | Operation not allowed，if invalid state or live stream.      |

**示例：**

```ts
avPlayer.setPlaybackRate(2.0);
```

## on('playbackRateDone')<sup>20+</sup>

on(type: 'playbackRateDone', callback: OnPlaybackRateDone): void

监听[setPlaybackRate](#setplaybackrate20)生效的事件。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | setPlaybackRate生效的事件回调类型，支持的事件：'playbackRateDone'，每次调用setPlaybackRate后都会回调此事件。 |
| callback | [OnPlaybackRateDone](#onplaybackratedone20) | 是   | setPlaybackRate生效的事件回调方法，上报设置后的播放速率。<br/>从API version 20开始支持此参数。 |

**示例：**

```ts
avPlayer.on('playbackRateDone', (rate:number) => {
  console.info('playbackRateDone called,and rate value is:' + rate);
});
```

## off('playbackRateDone')<sup>20+</sup>

off(type: 'playbackRateDone', callback?: OnPlaybackRateDone): void

取消监听[setPlaybackRate](#setplaybackrate20)生效的事件。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                      |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | 是   | setPlaybackRate生效的事件回调类型，取消注册的事件：'playbackRateDone'。 |
| callback | [OnPlaybackRateDone](#onplaybackratedone20) | 否   |  setPlaybackRate生效的事件回调方法，上报设置后的播放速率。如填写该参数，则仅取消注册此回调方法，否则取消注册playbackRateDone事件的所有回调方法。<br/>从API version 20开始支持此参数。 |

**示例：**

```ts
avPlayer.off('playbackRateDone');
```

## setBitrate<sup>9+</sup>

setBitrate(bitrate: number): void

设置比特率，以播放所指定比特率的流媒体资源，当前仅对**HLS/DASH协议网络流**有效。默认情况下，AVPlayer会根据网络连接速度选择合适的比特率。只能在prepared/playing/paused/completed状态调用，可以通过[bitrateDone](#onbitratedone9)事件确认是否生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| bitrate | number | 是   | 指定比特率，须通过[availableBitrates](#onavailablebitrates9)事件获得当前HLS/DASH协议网络流可用的比特率列表，如果用户指定的比特率不在此列表中，则播放器将从可用比特率列表中选择最接近的比特率。如果通过availableBitrates事件获得的比特率列表长度为0，则不支持指定比特率，也不会产生bitrateDone回调。 |

**示例：**

```ts
let bitrate: number = 96000;
avPlayer.setBitrate(bitrate);
```

## on('bitrateDone')<sup>9+</sup>

on(type: 'bitrateDone', callback: Callback\<number>): void

监听setBitrate生效的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | setBitrate生效的事件回调类型，支持的事件：'bitrateDone'，每次调用setBitrate后都会回调此事件。 |
| callback | Callback\<number> | 是   | setBitrate生效的事件回调方法，上报生效的比特率。             |

**示例：**

```ts
avPlayer.on('bitrateDone', (bitrate:number) => {
  console.info('bitrateDone called,and bitrate value is:' + bitrate);
});
```

## off('bitrateDone')<sup>9+</sup>

off(type: 'bitrateDone', callback?: Callback\<number>): void

取消监听setBitrate生效的事件。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | setBitrate生效的事件回调类型，取消注册的事件：'bitrateDone'。 |
| callback | Callback\<number> | 否   | setBitrate生效的事件回调方法，上报生效的比特率。<br/>从API version 12开始支持此参数。             |

**示例：**

```ts
avPlayer.off('bitrateDone');
```

## on('availableBitrates')<sup>9+</sup>

on(type: 'availableBitrates', callback: Callback\<Array\<number>>): void

监听HLS/DASH协议网络流可用的比特率列表，只会在切换prepared状态后上报。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | HLS/DASH协议网络流可用比特率上报事件回调类型，支持的事件：'availableBitrates'，只会在prepared之后上报一次。 |
| callback | Callback\<Array\<number>> | 是   | HLS/DASH协议网络流可用比特率上报事件回调方法，使用数组存放支持的比特率。如果数组长度为0，则不支持指定比特率。 |

**示例：**

```ts
avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
  console.info('availableBitrates called,and availableBitrates length is:' + bitrates.length);
});
```

## off('availableBitrates')<sup>9+</sup>

off(type: 'availableBitrates', callback?: Callback\<Array\<number>>): void

取消监听HLS/DASH协议网络流可用的比特率列表，调用[prepare](#prepare9)后，上报此事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | HLS/DASH协议网络流可用比特率上报事件回调类型，取消注册的事件：'availableBitrates'。 |
| callback | Callback\<Array\<number>> | 否   | HLS/DASH协议网络流可用比特率上报事件回调方法，使用数组存放支持的比特率。如果数组长度为0，则不支持指定比特率。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('availableBitrates');
```


## on('mediaKeySystemInfoUpdate')<sup>11+</sup>

on(type: 'mediaKeySystemInfoUpdate', callback: Callback\<Array\<drm.MediaKeySystemInfo>>): void

监听mediaKeySystemInfoUpdate事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 版权保护信息更新上报事件回调类型，支持的事件：'mediaKeySystemInfoUpdate'，当播放内容的版权保护信息更新时上报事件。 |
| callback | Callback\<Array\<drm.[MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)>> | 是   | 版权保护信息更新上报事件回调方法，上报MediaKeySystemInfo数组。 |

**示例：**

```ts
import { drm } from '@kit.DrmKit';

avPlayer.on('mediaKeySystemInfoUpdate', (mediaKeySystemInfo: Array<drm.MediaKeySystemInfo>) => {
    for (let i = 0; i < mediaKeySystemInfo.length; i++) {
      console.info('mediaKeySystemInfoUpdate happened uuid: ' + mediaKeySystemInfo[i]["uuid"]);
      console.info('mediaKeySystemInfoUpdate happened pssh: ' + mediaKeySystemInfo[i]["pssh"]);
    }
});
```

## off('mediaKeySystemInfoUpdate')<sup>11+</sup>

off(type: 'mediaKeySystemInfoUpdate', callback?: Callback\<Array\<drm.MediaKeySystemInfo>>): void;

取消监听mediaKeySystemInfoUpdate事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 版权保护信息更新上报事件回调类型，取消注册的事件：'mediaKeySystemInfoUpdate'。 |
| callback | Callback\<Array\<drm.[MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)>> | 否   | 版权保护信息更新上报事件回调方法，上报版权保护信息数组。如填写该参数，则仅取消注册此回调方法，否则取消注册mediaKeySystemInfoUpdate事件的所有回调方法。 |

**示例：**

```ts
avPlayer.off('mediaKeySystemInfoUpdate');
```

## setVolume<sup>9+</sup>

setVolume(volume: number): void

设置媒体播放音量，只能在prepared/playing/paused/completed状态调用，可以通过[volumeChange事件](#onvolumechange9)确认是否生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| volume | number | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |

**示例：**

```ts
let volume: number = 1.0;
avPlayer.setVolume(volume);
```

## on('volumeChange')<sup>9+</sup>

on(type: 'volumeChange', callback: Callback\<number>): void

监听setVolume生效的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | setVolume生效的事件回调类型，支持的事件：'volumeChange'，每次调用setVolume后都会回调此事件。 |
| callback | Callback\<number> | 是   | setVolume生效的事件回调方法，上报生效的媒体音量。            |

**示例：**

```ts
avPlayer.on('volumeChange', (vol: number) => {
  console.info('volumeChange called,and new volume is :' + vol);
});
```

## off('volumeChange')<sup>9+</sup>

off(type: 'volumeChange', callback?: Callback\<number>): void

取消监听setVolume生效的事件。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | setVolume生效的事件回调类型，取消注册的事件：'volumeChange'。 |
| callback | Callback\<number> | 否   | setVolume生效的事件回调方法，上报生效的媒体音量。<br/>从API version 12开始支持此参数。            |

**示例：**

```ts
avPlayer.off('volumeChange');
```

## on('endOfStream')<sup>9+</sup>

on(type: 'endOfStream', callback: Callback\<void>): void

监听资源播放至结尾的事件；如果用户设置[loop](#属性)=true，播放会跳转至开头重播；如果用户没有设置loop，会通过[stateChange](#onstatechange9)上报completed状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 资源播放至结尾的事件回调类型，支持的事件：'endOfStream'，当播放至结尾时会上报此事件。 |
| callback | Callback\<void> | 是   | 资源播放至结尾的事件回调方法。                               |

**示例：**

```ts
avPlayer.on('endOfStream', () => {
  console.info('endOfStream called');
});
```

## off('endOfStream')<sup>9+</sup>

off(type: 'endOfStream', callback?: Callback\<void>): void

取消监听资源播放至结尾的事件。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 资源播放至结尾的事件回调类型，取消注册的事件：'endOfStream'。 |
| callback | Callback\<void> | 否   | 资源播放至结尾的事件回调方法。<br/>从API version 12开始支持此参数。                               |

**示例：**

```ts
avPlayer.off('endOfStream');
```

## on('timeUpdate')<sup>9+</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

监听资源播放当前时间，单位为毫秒（ms），用于刷新进度条当前位置，默认间隔100ms时间上报，因用户操作(seek)产生的时间变化会立刻上报。

注：直播场景不支持timeUpdate上报。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                           |
| -------- | -------- | ---- | ---------------------------------------------- |
| type     | string   | 是   | 时间更新的回调类型，支持的事件：'timeUpdate'。 |
| callback | Callback\<number> | 是   | 回调函数。返回当前时间。                                     |

**示例：**

```ts
avPlayer.on('timeUpdate', (time:number) => {
  console.info('timeUpdate called,and new time is :' + time);
});
```

## off('timeUpdate')<sup>9+</sup>

off(type: 'timeUpdate', callback?: Callback\<number>): void

取消监听资源播放当前时间。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                               |
| ------ | ------ | ---- | -------------------------------------------------- |
| type   | string | 是   | 时间更新的回调类型，取消注册的事件：'timeUpdate'。 |
| callback | Callback\<number> | 否   | 回调函数。返回当前时间。<br/>从API version 12开始支持此参数。             |

**示例：**

```ts
avPlayer.off('timeUpdate');
```

## on('durationUpdate')<sup>9+</sup>


on(type: 'durationUpdate', callback: Callback\<number>): void

监听资源播放资源的时长，单位为毫秒（ms），用于刷新进度条长度，默认只在prepared上报一次，同时允许一些特殊码流刷新多次时长。
注：直播场景不支持durationUpdate上报。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                               |
| -------- | -------- | ---- | -------------------------------------------------- |
| type     | string   | 是   | 时长更新的回调类型，支持的事件：'durationUpdate'。 |
| callback | Callback\<number> | 是   | 回调函数。返回资源时长。        |

**示例：**

```ts
avPlayer.on('durationUpdate', (duration: number) => {
  console.info('durationUpdate called,new duration is :' + duration);
});
```

## off('durationUpdate')<sup>9+</sup>

off(type: 'durationUpdate', callback?: Callback\<number>): void

取消监听资源播放资源的时长。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | ------------------------------------------------------ |
| type   | string | 是   | 时长更新的回调类型，取消注册的事件：'durationUpdate'。 |
| callback | Callback\<number> | 否   | 回调函数。返回资源时长。<br/>从API version 12开始支持此参数。        |

**示例：**

```ts
avPlayer.off('durationUpdate');
```

## on('bufferingUpdate')<sup>9+</sup>

on(type: 'bufferingUpdate', callback: OnBufferingUpdateHandler): void

订阅音视频缓存更新事件，仅网络播放支持该订阅事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 播放缓存事件回调类型，支持的事件：'bufferingUpdate'。        |
| callback | [OnBufferingUpdateHandler](arkts-apis-media-t.md#onbufferingupdatehandler12) | 是   | 播放缓存事件回调方法。 |

**示例：**

```ts
avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('bufferingUpdate called,and infoType value is:' + infoType + ', value is :' + value);
});
```

## off('bufferingUpdate')<sup>9+</sup>

off(type: 'bufferingUpdate', callback?: OnBufferingUpdateHandler): void

取消监听音视频缓存更新事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                      |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | 是   | 播放缓存事件回调类型，取消注册的事件：'bufferingUpdate'。 |
| callback | [OnBufferingUpdateHandler](arkts-apis-media-t.md#onbufferingupdatehandler12) | 否   | 播放缓存事件回调方法。 |

**示例：**

```ts
avPlayer.off('bufferingUpdate');
```

## on('startRenderFrame')<sup>9+</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

订阅视频播放开始首帧渲染的更新事件，仅视频播放支持该订阅事件，该事件仅代表播放服务将第一帧画面送显示模块，实际效果依赖显示服务渲染性能。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频播放开始首帧渲染事件回调类型，支持的事件：'startRenderFrame'。 |
| callback | Callback\<void> | 是   | 视频播放开始首帧渲染事件回调方法。                           |

**示例：**

```ts
avPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame called');
});
```

## off('startRenderFrame')<sup>9+</sup>

off(type: 'startRenderFrame', callback?: Callback\<void>): void

取消监听视频播放开始首帧渲染的更新事件。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 视频播放开始首帧渲染事件回调类型，取消注册的事件：'startRenderFrame'。 |
| callback | Callback\<void> | 否   | 视频播放开始首帧渲染事件回调方法。<br/>从API version 12开始支持此参数。                   |

**示例：**

```ts
avPlayer.off('startRenderFrame');
```

## on('videoSizeChange')<sup>9+</sup>

on(type: 'videoSizeChange', callback: OnVideoSizeChangeHandler): void

监听视频播放宽高变化事件，仅视频播放支持该订阅事件，默认只在prepared状态上报一次，但HLS协议码流会在切换分辨率时上报。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频播放宽高变化事件回调类型，支持的事件：'videoSizeChange'。 |
| callback | [OnVideoSizeChangeHandler](arkts-apis-media-t.md#onvideosizechangehandler12) | 是   | 视频播放宽高变化事件回调方法。    |

**示例：**

```ts
avPlayer.on('videoSizeChange', (width: number, height: number) => {
  console.info('videoSizeChange called,and width is:' + width + ', height is :' + height);
});
```

## off('videoSizeChange')<sup>9+</sup>

off(type: 'videoSizeChange', callback?: OnVideoSizeChangeHandler): void

取消监听视频播放宽高变化事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 视频播放宽高变化事件回调类型，取消注册的事件：'videoSizeChange'。 |
| callback | [OnVideoSizeChangeHandler](arkts-apis-media-t.md#onvideosizechangehandler12) | 否   | 视频播放宽高变化事件回调方法。<br/>从API version 12开始支持此参数。    |

**示例：**

```ts
avPlayer.off('videoSizeChange');
```

## on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void

监听音频焦点变化事件，多个音视频资源同时播放时，会根据音频焦点模型[audio.InterruptMode](../apis-audio-kit/arkts-apis-audio-e.md#interruptmode9)触发此事件。应用需根据不同焦点变化事件作相应处理。具体可参考[处理音频焦点事件](../../media/audio/audio-playback-concurrency.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'。 |
| callback | Callback\<[audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)> | 是   | 音频焦点变化事件回调方法。                           |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

avPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt called,and InterruptEvent info is:' + info);
});
```

## off('audioInterrupt')<sup>9+</sup>

off(type: 'audioInterrupt', callback?: Callback<audio.InterruptEvent>): void

取消监听音频焦点变化事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 音频焦点变化事件回调类型，取消注册的事件：'audioInterrupt'。 |
| callback | Callback\<[audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)> | 否   | 音频焦点变化事件回调方法。<br/>从API version 12开始支持此参数。             |

**示例：**

```ts
avPlayer.off('audioInterrupt');
```

## on('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

on(type: 'audioOutputDeviceChangeWithInfo', callback: Callback\<audio.AudioStreamDeviceChangeInfo>): void

订阅监听音频流输出设备变化及原因，使用callback方式返回结果。

在订阅此监听时，建议参考[响应音频流输出设备变更](../../media/audio/audio-output-device-change.md)自行实现设备连接或者断开时的播放器行为。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'audioOutputDeviceChangeWithInfo'。 |
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | 是   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。 |

**错误码：**

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.       |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

avPlayer.on('audioOutputDeviceChangeWithInfo', (data: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`${JSON.stringify(data)}`);
});
```

## off('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

off(type: 'audioOutputDeviceChangeWithInfo', callback?: Callback\<audio.AudioStreamDeviceChangeInfo>): void

取消订阅监听音频流输出设备变化及原因，使用callback方式返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'audioOutputDeviceChangeWithInfo'。 |
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | 否   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。 |

**错误码：**

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |

**示例：**

```ts
avPlayer.off('audioOutputDeviceChangeWithInfo');
```

## addSubtitleFromFd<sup>12+</sup>

addSubtitleFromFd(fd: number, offset?: number, length?: number): Promise\<void>

依据fd为视频添加外挂字幕，当前仅支持与视频资源同时设置（在avplayer设置fdSrc视频资源后设置外挂字幕）。使用Promise方式返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| fd | number   | 是   | 资源句柄，通过[resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9)获取。 |
| offset | number | 否   | 资源偏移量，需要基于预置资源的信息输入，非法值会造成字幕频资源解析错误，默认值:0。 |
| length | number | 否   | 资源长度，默认值为文件中从偏移量开始的剩余字节，需要基于预置资源的信息输入，非法值会造成字幕频资源解析错误，默认值:0。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | 添加外挂字幕addSubtitleFromFd方法的Promise返回值。 |

**错误码：**

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit'

private context: Context | undefined;
constructor(context: Context) {
  this.context = context; // this.getUIContext().getHostContext();
}
let fileDescriptor = await this.context.resourceManager.getRawFd('xxx.srt');

avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length);
```

## addSubtitleFromUrl<sup>12+</sup>

addSubtitleFromUrl(url: string): Promise\<void>

依据url为视频添加外挂字幕，当前仅支持与视频资源同时设置（在avplayer设置fdSrc视频资源后设置外挂字幕）。使用Promise方式返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| url    | string | 是   | 外挂字幕文件地址。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | 添加外挂字幕addSubtitleFromUrl方法的Promise返回值。 |

**错误码：**

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
let fdUrl:string = 'http://xxx.xxx.xxx/xx/index.srt';

let avPlayer: media.AVPlayer = await media.createAVPlayer();
avPlayer.addSubtitleFromUrl(fdUrl);
```

## on('subtitleUpdate')<sup>12+</sup>

on(type: 'subtitleUpdate', callback: Callback\<SubtitleInfo>): void

订阅获取外挂字幕的事件，当有外挂字幕时，会通过订阅的回调方法通知用户。用户只能订阅一个外挂字幕事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'subtitleUpdate'。 |
| callback | function | 是   | 外挂字幕事件回调方法。 |

**示例：**

```ts
avPlayer.on('subtitleUpdate', async (info: media.SubtitleInfo) => {
  if (info) {
    let text = (!info.text) ? '' : info.text
    let startTime = (!info.startTime) ? 0 : info.startTime
    let duration = (!info.duration) ? 0 : info.duration
    console.info('subtitleUpdate info: text=' + text + ' startTime=' + startTime +' duration=' + duration);
  } else {
    console.info('subtitleUpdate info is null');
  }
});
```

## off('subtitleUpdate')<sup>12+</sup>

off(type: 'subtitleUpdate', callback?: Callback\<SubtitleInfo>): void

取消订阅获取外挂字幕的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'subtitleUpdate'。 |
| callback | function | 否   | 取消外挂字幕事件的回调方法。 |

**示例：**

```ts
avPlayer.off('subtitleUpdate');
```

## on('trackChange')<sup>12+</sup>

on(type: 'trackChange', callback: OnTrackChangeHandler): void

订阅获取轨道变更的事件，当播放的轨道变更时，会通过订阅的回调方法通知用户。用户只能订阅一个轨道变更事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackChange'。 |
| callback | [OnTrackChangeHandler](arkts-apis-media-t.md#ontrackchangehandler12) | 是   | 轨道变更事件回调方法。 |

**示例：**

```ts
avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
  console.info('trackChange info: index=' + index + ' isSelect=' + isSelect);
});
```

## off('trackChange')<sup>12+</sup>

off(type: 'trackChange', callback?: OnTrackChangeHandler): void

取消订阅获取轨道变更的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackChange'。 |
| callback | [OnTrackChangeHandler](arkts-apis-media-t.md#ontrackchangehandler12) | 否   | 取消轨道变更事件的回调方法。 |

**示例：**

```ts
avPlayer.off('trackChange');
```

## on('trackInfoUpdate')<sup>12+</sup>

on(type: 'trackInfoUpdate', callback: Callback\<Array\<MediaDescription>>): void

订阅获取轨道信息更新的事件，当播放的轨道有更新时，会通过订阅的回调方法通知用户。用户只能订阅一个轨道变更事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackInfoUpdate'。 |
| callback | Callback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | 是   | 轨道信息更新事件回调方法。 |

**示例：**

```ts
avPlayer.on('trackInfoUpdate', (info: Array<media.MediaDescription>) => {
  if (info) {
    for (let i = 0; i < info.length; i++) {
      let propertyIndex: Object = info[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
      let propertyType: Object = info[i][media.MediaDescriptionKey.MD_KEY_TRACK_TYPE];
      console.info('track info: index=' + propertyIndex + ' tracktype=' + propertyType);
    }
  } else {
    console.info('track info is null');
  }
});
```

## off('trackInfoUpdate')<sup>12+</sup>

off(type: 'trackInfoUpdate', callback?: Callback\<Array\<MediaDescription>>): void

取消订阅获取轨道变更的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackInfoUpdate'。 |
| callback | Callback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | 否   | 取消轨道信息更新事件的回调方法。 |

**示例：**

```ts
avPlayer.off('trackInfoUpdate');
```

## on('amplitudeUpdate')<sup>13+</sup>

on(type: 'amplitudeUpdate', callback: Callback\<Array\<number>>): void

订阅音频最大电平值，音频资源播放时定时上报。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件回调类型，支持的事件为：'amplitudeUpdate'。 |
| callback | Callback\<Array\<number>> | 是   | 音频最大电平值更新事件回调方法。 |

**示例：**

```ts
avPlayer.on('amplitudeUpdate', (value: Array<number>) => {
  console.info('amplitudeUpdate called,and amplitudeUpdate = ${value}');
});
```

## off('amplitudeUpdate')<sup>13+</sup>

off(type: 'amplitudeUpdate', callback?: Callback\<Array\<number>>): void

取消订阅获取音频最大电平值事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 事件回调类型，支持的事件为：'amplitudeUpdate'。 |
| callback | Callback\<Array\<number>> | 否   | 取消音频最大电平值更新事件回调方法。 |

**示例：**

```ts
avPlayer.off('amplitudeUpdate');
```

## on('seiMessageReceived')<sup>18+</sup>

on(type: 'seiMessageReceived', payloadTypes: Array\<number>, callback: OnSeiMessageHandle): void

订阅获取SEI信息事件，仅适用于HTTP-FLV直播，视频流中包含SEI信息时上报。需在prepare之前订阅，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | 是 | 事件回调类型，支持的事件为：'seiMessageReceived'。 |
| payloadTypes | Array\<number> | 是 | SEI信息的订阅负载类型数组。当前仅支持负载类型为5，即payloadType = 5。|
| callback | [OnSeiMessageHandle](arkts-apis-media-t.md#onseimessagehandle18) | 是 | 用于监听SEI信息事件的回调函数，接收订阅的负载类型。 |

**示例：**

```ts
import util from '@ohos.util';

avPlayer.on('seiMessageReceived', [5], (messages: Array<media.SeiMessage>, playbackPosition?: number) =>
{
  console.info('seiMessageReceived playbackPosition ' + playbackPosition);

  for (let key = 0; key < messages.length; key++) {
    console.info('seiMessageReceived messages payloadType ' + messages[key].payloadType + ' payload size ' + messages[key].payload.byteLength);

    let textDecoder = util.TextDecoder.create("utf-8",{ignoreBOM: true});
    let ab = messages[key]?.payload?.slice(16, messages[key].payload.byteLength);
    let result: Uint8Array = new Uint8Array(ab);
    let retStr: string = textDecoder.decodeToString(result);
    console.info('seiMessageReceived messages payload ' + retStr);
  }
});
```

## off('seiMessageReceived')<sup>18+</sup>

off(type: 'seiMessageReceived', payloadTypes?: Array\<number>, callback?: OnSeiMessageHandle): void

取消订阅获取SEI信息事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件回调类型，支持的事件为：'seiMessageReceived'。 |
| payloadTypes | Array\<number> | 否   | SEI信息的订阅负载类型。 |
| callback | [OnSeiMessageHandle](arkts-apis-media-t.md#onseimessagehandle18) | 否   | 用于监听SEI信息事件的回调函数，接收订阅的负载类型。 |

**示例：**

```ts
avPlayer.off('seiMessageReceived');
```

## setSuperResolution<sup>18+</sup>

setSuperResolution(enabled: boolean) : Promise\<void>

动态开启/关闭超分算法，可以在 'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped' 状态调用。使用Promise方式返回结果。

在调用[prepare()](#prepare9)前先通过[PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12)使能超分。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| enabled    | boolean | 是   | 表示是否开启超分。true表示开启超分，false表示关闭超分。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | 开启/关闭超分setSuperResolution方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by promise. |
| 5410003  | Super-resolution not supported. Return by promise. |
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12). Return by promise. |

**示例：**

```ts
avPlayer.setSuperResolution(true);
```

## setVideoWindowSize<sup>18+</sup>

setVideoWindowSize(width: number, height: number) : Promise\<void>

动态设置超分算法的输出分辨率，可以在 'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped' 状态调用。使用Promise方式返回结果。输入参数须在 320x320 ~ 1920x1080 范围内，单位为像素。

在调用[prepare()](#prepare9)前先通过[PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12)使能超分。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| width    | number | 是   | 超分算法的目标输出视频宽度，取值范围为[320-1920]，单位为像素。 |
| height    | number | 是   | 超分算法的目标输出视频高度，取值范围为[320-1080]，单位为像素。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | 配置超分目标输出分辨率setVideoWindowSize方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5410003  | Super-resolution not supported. Return by promise. |
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12). Return by promise. |

**示例：**

```ts
avPlayer.setVideoWindowSize(1920, 1080);
```

## on('superResolutionChanged')<sup>18+</sup>

on(type:'superResolutionChanged', callback: OnSuperResolutionChanged): void

订阅监听超分算法开启/关闭事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | 是 | 事件回调类型，支持的事件为：'superResolutionChanged'，当超分算法开启/关闭状态变化时，触发该事件。 |
| callback | [OnSuperResolutionChanged](arkts-apis-media-t.md#onsuperresolutionchanged-18) | 是 | 超分开关事件回调方法。 |

**示例：**

```ts
avPlayer.on('superResolutionChanged', (enabled: boolean) => {
  console.info('superResolutionChanged called, and enabled is:' + enabled);
});
```

## off('superResolutionChanged')<sup>18+</sup>

off(type:'superResolutionChanged', callback?: OnSuperResolutionChanged): void

取消监听超分算法开启/关闭事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | 是 | 事件回调类型，支持的事件为：'superResolutionChanged'，当超分算法开启/关闭状态变化时，触发该事件。 |
| callback | [OnSuperResolutionChanged](arkts-apis-media-t.md#onsuperresolutionchanged-18) | 否 | 超分开关事件回调方法。 |

**示例：**

```ts
avPlayer.off('superResolutionChanged');
```
