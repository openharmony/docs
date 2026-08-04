# Interface (AVPlayer)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chennotfound-->
<!--Designer: @chennotfound-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

播放管理接口，用于管理和播放媒体资源。支持音视频播放、播放控制（播放、暂停、停止、跳转、倍速等）、状态管理和事件监听。适用于本地音视频播放、网络流媒体播放、直播等多种场景。使用AVPlayer可以快速实现播放功能，简化开发流程，提升应用性能和用户体验。在调用AVPlayer的方法前，需要先通过[createAVPlayer()](arkts-apis-media-f.md#mediacreateavplayer9)构建一个AVPlayer实例。

在使用AVPlayer实例的方法时，建议开发者注册相关回调，主动获取当前状态变化。[on('stateChange')](#onstatechange9)：监听播放状态机AVPlayerState切换。[on('error')](#onerror9)：监听错误事件。

应用需要控制AVPlayer实例数量，播放结束后应及时调用release()释放资源。建议同时持有的AVPlayer实例数量不超过合理范围，避免内存消耗过大触发系统保护机制终止应用。

音视频播放开发指导请参考：[使用AVPlayer播放音频(ArkTS)](../../media/media/using-avplayer-for-playback.md)和[使用AVPlayer播放视频(ArkTS)](../../media/media/video-playback.md)。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 9开始支持。

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称                                                | 类型                                                         | 只读 | 可选 | 说明                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>9+</sup>                                    | string                                                       | 否   | 是   | 媒体URL，只允许在**idle**状态下设置。<br/>支持的视频格式：mp4、mpeg-ts、mkv。<br>支持的音频格式：m4a、aac、mp3、ogg、wav、flac、amr、ape。<br/>**支持路径示例**：<br>1. fd类型播放：fd://xx。<br>![](figures/image-url.png)<br>2. http网络播放：`http://xx`。<br/>3. https网络播放：`https://xx`。<br/>4. HLS网络播放路径：`http://xx`或者`https://xx`。<br>**说明：**<br>- 设置网络播放路径，需[声明权限](../../security/AccessToken/declare-permissions.md)：[ohos.permission.INTERNET](../../security/AccessToken/permissions-for-all.md#ohospermissioninternet)，相关错误码: [201 权限校验失败](../errorcode-universal.md#201-权限校验失败)。<br>- 从API version 11开始不支持webm。<br> - 将资源句柄（fd）传递给AVPlayer实例之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个AVPlayer / AVMetadataExtractor / AVImageGenerator / AVTranscoder。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致媒体播放器数据获取异常。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fdSrc<sup>9+</sup>                                  | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                       | 否   | 是   | 媒体文件描述，只允许在**idle**状态下设置。<br/>**使用场景**：应用中的媒体资源被连续存储在同一个文件中。<br/>支持的视频格式（mp4、mpeg-ts、mkv）。<br>支持的音频格式（m4a、aac、mp3、ogg、wav、flac、amr、ape）。<br/>**使用示例**：<br/>假设一个连续存储的媒体文件：<br/>视频1（地址偏移：0，字节长度:100）；<br/>视频2（地址偏移：101，字节长度：50）；<br/>视频3（地址偏移：151，字节长度：150）；<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }。<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }。<br/>假设是一个独立的媒体文件: 请使用src=fd://xx。<br>**说明：**<br>从API version 11开始不支持webm。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| dataSrc<sup>10+</sup>                               | [AVDataSrcDescriptor](arkts-apis-media-i.md#avdatasrcdescriptor10)                | 否   | 是   | 流式媒体资源描述，只允许在**idle**状态下设置。<br/>**使用场景**：应用播放从远端下载到本地的文件，在应用未下载完整音视频资源时，提前播放已获取的资源数据。若将已获取的资源数据写入到本地文件中，同时从本地文件中读取数据，即可实现边播边缓存的能力。<br/>支持的视频格式（mp4、mpeg-ts、mkv）。<br>支持的音频格式（m4a、aac、mp3、ogg、wav、flac、amr、ape）。<br/>**使用示例**：<br/>假设用户正在从远端服务器获取音视频媒体文件，希望下载到本地的同时播放已经下载好的部分：<br/>1.用户需要获取媒体文件的总大小size（单位为字节），获取不到时设置为-1。<br/>2.用户需要实现回调函数func用于填写数据，如果size = -1，则func形式为：func(buffer: ArrayBuffer, length: number)，此时播放器只会按照顺序获取数据；否则func形式为：func(buffer: ArrayBuffer, length: number, pos: number)，播放器会按需跳转并获取数据。<br/>3.用户设置AVDataSrcDescriptor {fileSize = size, callback = func}。<br/>**注意事项**：<br/>如果播放的是mp4/m4a格式用户需要保证moov字段（媒体信息字段）在mdat字段（媒体数据字段）之前，或者moov之前的字段小于10M，否则会导致解析失败无法播放。<br>**说明：**<br>从API version 11开始不支持webm。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| surfaceId<sup>9+</sup>                              | string                                                       | 否   | 是   | 视频窗口ID，默认值为空（表示未设置窗口）。<br/>仅支持在**initialized**状态下初始化。<br/>初始化后可以在**prepared**/**playing**/**paused**/**completed**/**stopped**状态下重新设置，重新设置后视频播放将在新的窗口渲染。<br/>使用场景：视频播放时的窗口渲染（纯音频播放时不涉及）。<br/>**使用示例**：<br/>通过[getXComponentSurfaceId](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9)接口创建surfaceId。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| loop<sup>9+</sup>                                   | boolean                                                      | 否   | 否   | 循环播放属性，默认false，设置为true表示循环播放，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。<br/>直播场景不支持loop设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| videoScaleType<sup>9+</sup>                         | [VideoScaleType](arkts-apis-media-e.md#videoscaletype9)                           | 否   | 是   | 视频缩放模式，默认VIDEO_SCALE_TYPE_FIT，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioInterruptMode<sup>9+</sup>                     | [audio.InterruptMode](../apis-audio-kit/arkts-apis-audio-e.md#interruptmode9)       | 否   | 是   | 音频焦点模型，默认SHARE_MODE，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。<br/>在第一次调用[play()](#play9)之前设置， 以便此后中断模式生效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioRendererInfo<sup>10+</sup>                     | [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8) | 否   | 是   | 设置音频渲染信息。若媒体源包含视频，则usage默认值为STREAM_USAGE_MOVIE，否则usage默认值为STREAM_USAGE_MUSIC。rendererFlags默认值为0。若默认usage不满足需求，则须主动配置[audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)。<br/>只允许在**initialized**状态下设置。<br/>在第一次调用[prepare()](#prepare9)之前设置，以便音频渲染器信息在之后生效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioEffectMode<sup>10+</sup>                       | [audio.AudioEffectMode](../apis-audio-kit/arkts-apis-audio-e.md#audioeffectmode10)  | 否   | 是   | 设置音频音效模式。<br>当需要启用特定音效时设置此参数，不设置时使用默认值EFFECT_DEFAULT（默认音效，适合普通播放场景），动态属性。<br>EFFECT_NONE适合需要原始音频的场景，其他音效模式适合特定的音频处理需求。<br>audioRendererInfo的usage变动时会恢复为默认值，只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| state<sup>9+</sup>                                  | [AVPlayerState](arkts-apis-media-t.md#avplayerstate9)                             | 是   | 否   | 音视频播放的状态，全状态有效，可查询参数。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                  |
| currentTime<sup>9+</sup>                            | number                                                       | 是   | 否   | 当前播放位置，单位为毫秒（ms），可查询参数。<br/>返回为（-1）表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回（-1）。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| duration<sup>9+</sup> | number                                                       | 是   | 否   | 音视频时长，单位为毫秒（ms），可查询参数。<br/>返回为（-1）表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回（-1）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| width<sup>9+</sup>                                  | number                                                       | 是   | 否   | 视频宽，单位为像素（px），可查询参数。<br/>返回为（0）表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| height<sup>9+</sup>                                 | number                                                       | 是   | 否   | 视频高，单位为像素（px），可查询参数。<br/>返回为（0）表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| playlistLoopMode                     | [PlaylistLoopMode](arkts-apis-media-e.md#playlistloopmode)      | 否   | 是   | 在播放媒体列表时，设置循环模式。默认值为PLAYLIST_LOOP_MODE_ALL，表示循环播放列表中的所有项目。<br/>**起始版本：** 26.0.0 <br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。|
| privacyType | [audio.AudioPrivacyType](../apis-audio-kit/arkts-apis-audio-e.md#audioprivacytype10) | 否   | 是   | 音频隐私配置。<br>当需要设置音频隐私级别时设置此参数，不设置时使用默认值PRIVACY_TYPE_PUBLIC（公开音频，适合普通播放场景）。<br>PRIVACY_TYPE_PRIVATE（私密音频）适合隐私敏感的音频内容播放。<br>详细信息请参阅[audio.AudioPrivacyType](../apis-audio-kit/arkts-apis-audio-e.md#audioprivacytype10)。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: OnAVPlayerStateChangeHandle): void

注册监听播放状态机AVPlayerState切换的事件。

**原子化服务API：** 从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件回调类型，用于注册监听播放状态机AVPlayerState切换事件，支持的事件类型：'stateChange'。用户操作和系统都会触发此事件。 |
| callback<sup>12+</sup> | [OnAVPlayerStateChangeHandle](arkts-apis-media-t.md#onavplayerstatechangehandle12) | 是   | 状态机切换事件回调方法，若存在多次注册监听，则最后一次注册监听生效。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听播放状态机AVPlayerState切换的事件。
  avPlayer.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
    switch (state) {
      case 'idle':
        console.info('state idle called');
        break;
      case 'initialized':
        console.info('state initialized called');
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
}
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
| callback<sup>12+</sup>   | [OnAVPlayerStateChangeHandle](arkts-apis-media-t.md#onavplayerstatechangehandle12) | 否   | 状态机切换事件回调方法。取消注册监听stateChange事件的所有回调方法，不支持取消某个单个注册监听。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收播放状态机AVPlayerState切换的事件。
  avPlayer.off('stateChange');
}
```

## on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

监听[AVPlayer](arkts-apis-media-AVPlayer.md)的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时[AVPlayerState](arkts-apis-media-t.md#avplayerstate9)也切至error状态，用户需要通过[reset()](#reset9)或者[release()](#release9)退出播放操作。若调用[reset()](#reset9)方法后，播放状态仍为error状态，建议直接调用[release()](#release9)方法，退出播放操作。

**原子化服务API：** 从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件回调类型，用于注册监听AVPlayer错误事件，支持的事件类型：'error'。用户操作和系统都会触发此事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 错误事件回调方法，使用播放器的过程中发生错误，会提供错误码ID和错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

在API version 9-13，针对网络、服务器等数据流异常，接口上报5400103；从API version 14开始，对应错误细化为错误码5411001-5411012。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 201      | Permission denied. |
| 401      | The parameter check failed. |
| 801      | Capability not supported. |
| 5400101  | No memory. |
| 5400102  | Operation not allowed. |
| 5400103  | I/O error.  <br>适用版本：9-13    |
| 5400104  | Time out.              |
| 5400105  | Service died.     |
| 5400106  | Unsupported format.     |
| 5410002  | Seek continuous unsupported.  <br>适用版本：18+     |
| 5411001  | IO can not find host.  <br>适用版本：14+    |
| 5411002  | IO connection timeout.  <br>适用版本：14+  |
| 5411003  | IO network abnormal.  <br>适用版本：14+     |
| 5411004  | IO network unavailable.  <br>适用版本：14+  |
| 5411005  | IO no permission.  <br>适用版本：14+        |
| 5411006  | IO request denied.  <br>适用版本：14+  |
| 5411007  | IO resource not found.  <br>适用版本：14+ |
| 5411008  | IO SSL client cert needed.  <br>适用版本：14+    |
| 5411009  | IO SSL connect fail.  <br>适用版本：14+     |
| 5411010  | IO SSL server cert untrusted.  <br>适用版本：14+    |
| 5411011  | IO unsupported request.  <br>适用版本：14+      |
| 5411012  | Http cleartext traffic is not permitted.  <br>适用版本：23+     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听AVPlayer的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。
  avPlayer.on('error', (error: BusinessError) => {
    console.info('error happened,and error message is :' + error.message);
    console.info('error happened,and error code is :' + error.code);
  });
}
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
| callback<sup>12+</sup> | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 错误事件回调方法，使用播放器的过程中发生错误，会提供错误码ID和错误信息。如果填写该参数，仅取消注册此回调方法，否则取消注册error事件的所有回调方法。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再监听AVPlayer的错误事件。
  avPlayer.off('error');
}
```

## setMediaSource<sup>12+</sup>

setMediaSource(src:MediaSource, strategy?: PlaybackStrategy): Promise\<void>

流媒体预下载资源设置。预下载是指在播放前预先下载部分媒体数据，可减少播放开始时的等待时间，提升用户体验。下载URL对应的流媒体数据并暂存在内存中，此接口只能在idle状态下调用。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| src | [MediaSource](arkts-apis-media-MediaSource.md) | 是   | 流媒体预下载的媒体来源对象。 |
| strategy | [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12) | 否   | 流媒体预下载的播放策略。不传此参数时，播放器不应用特定的播放策略。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.      |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
async function test(){
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
}
```

## getTrackSelectionFilter

getTrackSelectionFilter(): Promise\<TrackSelectionFilter>

获取播放器当前配置的轨道选择过滤器。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<[TrackSelectionFilter](arkts-apis-media-i.md#trackselectionfilter)> | Promise对象，返回当前配置的轨道选择过滤器。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test() {
  let player = await media.createAVPlayer();
  player.getTrackSelectionFilter().then((selectionFilter: media.TrackSelectionFilter) => {
    console.info(`Succeeded in getting TrackSelectionFilter: ${selectionFilter}`);
  }).catch((err: BusinessError) => {
    console.error('Failed to getTrackSelectionFilter, error message is:' + err.message);
  });
}

```

## setTrackSelectionFilter

setTrackSelectionFilter(filter : TrackSelectionFilter): Promise\<void>

为播放器设置轨道选择过滤器，播放器将使用该过滤器来选择可用的轨道用于播放。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| filter | [TrackSelectionFilter](arkts-apis-media-i.md#trackselectionfilter) | 是   | 轨道选择过滤器配置对象，用于设置视频/音频轨道的选择条件，如比特率范围、分辨率范围、帧率范围等。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test() {
  let player = await media.createAVPlayer();
  let selectionFilter: media.TrackSelectionFilter = {
    maxVideoBitrate: 80000,
    minVideoBitrate: 0,
    maxVideoFrameRate: 60,
    minVideoFrameRate: 0,
    maxVideoResolution: { width: 1080, height: 720 },
    minVideoResolution: { width: 0, height: 0 },
    preferredVideoMimeTypes: [media.CodecMimeType.VIDEO_AVC],
    maxAudioBitrate: 8000,
    minAudioBitrate: 0,
    maxAudioChannels: 3,
    preferredAudioMimeTypes: [media.CodecMimeType.AUDIO_AAC, media.CodecMimeType.AUDIO_MP3],
    preferredAudioLanguages: [],
    preferredSubtitleLanguages: []
  };
  player.setTrackSelectionFilter(selectionFilter).then(() => {
    console.info('Succeeded in setting TrackSelectionFilter');
  }).catch((err: BusinessError) => {
    console.error('Failed to setTrackSelectionFilter, error message is:' + err.message);
  });
}
```

## addPlaybackMediaSource

addPlaybackMediaSource(src: MediaSource, id?: string): Promise\<string>

向播放器的播放列表添加一个新的播放源。使用Promise异步回调。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| src | [MediaSource](arkts-apis-media-MediaSource.md) | 是   | 要添加到播放列表的媒体源对象。 |
| id | string | 否   | 播放列表中已有媒体源的唯一标识ID，新添加的媒体源会插入到指定媒体源之前。如果未指定，默认添加到列表末尾。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<string> | Promise对象，返回对应媒体资源的唯一ID。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400108  | The media source ID does not exist in the playlist. Returned by promise.|

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();
  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};
  let mediaSource1: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  let source1 = await player.addPlaybackMediaSource(mediaSource1);
  let mediaSource2: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video2.mp4", headers);
  let source2 = await player.addPlaybackMediaSource(mediaSource2, source1);
}
```

## removePlaybackMediaSource

removePlaybackMediaSource(id: string): Promise\<void>

从播放器的播放列表中移除指定的媒体源。使用Promise异步回调。

> **注意：**
>
> - 如果该ID在当前播放列表中不存在，将返回错误码。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| id | string | 是   | 要移除的媒体源的唯一标识ID。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400108  | The media source ID does not exist in the playlist. Returned via promise. |

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();
  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};
  let mediaSource1: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  let sourceId = await player.addPlaybackMediaSource(mediaSource1);
  await player.removePlaybackMediaSource(sourceId);
}
```

## clearPlaybackList

clearPlaybackList(): Promise\<void>

清空播放列表中的所有项目，当前正在播放的媒体将会立即终止。使用Promise异步回调。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned via promise. |

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();
  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};
  let mediaSource1: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  let sourceId1 = await player.addPlaybackMediaSource(mediaSource1);
  let mediaSource2: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video2.mp4", headers);
  let sourceId2 = await player.addPlaybackMediaSource(mediaSource2, sourceId1);
  await player.clearPlaybackList();
}
```

## getCurrentMediaSource

getCurrentMediaSource(): MediaSource | undefined;

获取当前正在播放的媒体源对象，可以在prepared/playing/paused/completed状态调用。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| MediaSource \| undefined | 如果操作成功，则返回当前媒体源，否则返回 undefined。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();
  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};
  let mediaSource: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  await player.addPlaybackMediaSource(mediaSource);
  let currentMediaSource: media.MediaSource | undefined = player.getCurrentMediaSource();
}
```

## getMediaSources

getMediaSources(): Array<MediaSource | undefined>

获取当前播放列表中所有媒体源的数组，可以在idle/prepared/playing/paused/completed/stopped状态调用。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Array<[MediaSource](arkts-apis-media-MediaSource.md) \| undefined> | 播放列表中的媒体源数组。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();
  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};
  let mediaSource1: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  let sourceId1 = await player.addPlaybackMediaSource(mediaSource1);
  let mediaSource2: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video2.mp4", headers);
  let sourceId2 = await player.addPlaybackMediaSource(mediaSource2);
  let sources: Array<media.MediaSource | undefined> = player.getMediaSources();
}
```

## advanceToNextMediaSource

advanceToNextMediaSource(): Promise\<void>

结束当前媒体源的播放，并开始播放媒体源列表中的下一个媒体源。使用Promise异步回调。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400108  | The previous media source does not exist in the playlist. Returned via promise. |

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();

  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};
  let mediaSource1: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  await player.addPlaybackMediaSource(mediaSource1);
  let mediaSource2: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video2.mp4", headers);
  await player.addPlaybackMediaSource(mediaSource2);

  await player.prepare();
  await player.play();
  await player.advanceToNextMediaSource();
}
```

## advanceToPrevMediaSource

advanceToPrevMediaSource(): Promise\<void>

结束当前媒体源的播放，并开始播放媒体源列表中的上一个媒体源。使用Promise异步回调。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400108  | The next media source does not exist in the playlist. Returned via promise. |

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();

  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};
  let mediaSource1: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  await player.addPlaybackMediaSource(mediaSource1);
  let mediaSource2: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video2.mp4", headers);
  await player.addPlaybackMediaSource(mediaSource2);
  let mediaSource3: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video3.mp4", headers);
  await player.addPlaybackMediaSource(mediaSource3);

  await player.prepare();
  await player.play();
  await player.advanceToNextMediaSource();
  await player.advanceToPrevMediaSource();
}
```

## advanceToMediaSource

advanceToMediaSource(id: string): Promise\<void>

结束当前媒体源的播放，并开始播放列表中指定的媒体源。使用Promise异步回调。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| id    | string | 是 | 要跳转播放的媒体源的唯一标识ID。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400108  | The mediasource does not exist in the playlist. Returned via promise. |

**示例：**

```ts
async function test() {
  let player = await media.createAVPlayer();
  let headers: Record<string, string> = {"User-Agent" : "MyApp/1.0"};

  let mediaSource1: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video1.mp4", headers);
  let sourceId1 = await player.addPlaybackMediaSource(mediaSource1);
  let mediaSource2: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video2.mp4", headers);
  let sourceId2 = await player.addPlaybackMediaSource(mediaSource2);
  let mediaSource3: media.MediaSource = media.createMediaSourceWithUrl("http://example.com/video3.mp4", headers);
  let sourceId3 = await player.addPlaybackMediaSource(mediaSource3);
  await player.prepare();
  await player.play();
  await player.advanceToMediaSource(sourceId3);
}
```

## setPlaybackStrategy<sup>12+</sup>

setPlaybackStrategy(strategy: PlaybackStrategy): Promise\<void>

设置播放策略，只能在initialized状态下调用。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| strategy | [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12) | 是   | 播放策略配置对象，用于设置播放器的各项参数，如preferredWidth、preferredHeight、preferredBufferDuration、preferredHdr、mutedMediaType等，以优化播放体验。 |

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

let player = await media.createAVPlayer();
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let fileDescriptor = await context.resourceManager.getRawFd('xxx.mp4');
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

设置播放区间，并通过指定的[SeekMode](arkts-apis-media-e.md#seekmode8)跳转到区间开始位置。设置之后，只播放音视频文件设定区间内的内容。使用Promise异步回调。可在**initialized**/**prepared**/**paused**/**stopped**/**completed**状态下使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| startTimeMs | number | 是   | 区间开始位置，单位为毫秒（ms）。<br>取值原则：该值必须为整数，范围为[0, duration)。可以取值-1，表示从0位置开始播放。小于-1的其他值不满足要求会报错。|
| endTimeMs | number | 是   | 区间结束位置，单位为毫秒（ms）。<br>取值原则：该值必须为整数，范围为(startTimeMs, duration]。可以取值-1，表示播放到资源末尾。|
| mode | [SeekMode](arkts-apis-media-e.md#seekmode8) | 否   | 支持SeekMode.SEEK_PREV_SYNC和SeekMode.SEEK_CLOSEST, <br/>默认值为SeekMode.SEEK_PREV_SYNC。|

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401  | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.setPlaybackRange(0, 6000, media.SeekMode.SEEK_CLOSEST).then(() => {
    console.info('Succeeded setPlaybackRange');
  }).catch((err: BusinessError) => {
    console.error('Failed to setPlaybackRange' + err.message);
  });
}
```

## prepare<sup>9+</sup>

prepare(callback: AsyncCallback\<void>): void

准备播放音频/视频，需在[stateChange](#onstatechange9)事件成功触发至initialized状态后，才能调用。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 准备播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupported format. Return by callback.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized状态后才能调用。
  avPlayer.prepare((err: BusinessError) => {
    if (err) {
      console.error(`Failed to prepare.Code:${err.code},message:${err.message}`);
    } else {
      console.info('Succeeded in preparing');
    }
  });
}
```

## prepare<sup>9+</sup>

prepare(): Promise\<void>

准备播放音频/视频，需在[stateChange](#onstatechange9)事件成功触发至initialized状态后，才能调用。使用Promise异步回调。

如果应用使用到多个短视频频繁切换的场景，为了提升切换性能，可以考虑创建多个AVPlayer对象，提前准备下一个视频，详情参见[在线短视频流畅切换](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-smooth-switching)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400106  | Unsupported format. Return by promise.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized状态后才能调用。
  avPlayer.prepare().then(() => {
    console.info('Succeeded in preparing');
  }, (err: BusinessError) => {
    console.error(`Failed to prepare.Code:${err.code},message:${err.message}`);
  });
}
```

## setMediaMuted<sup>12+</sup>

setMediaMuted(mediaType: MediaType,  muted: boolean ): Promise\<void>

设置音频静音/取消音频静音，从API version 20开始，增加支持设置画面显示/不显示。使用Promise异步回调。

只能在prepared/playing/paused/completed状态下调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| mediaType | [MediaType](arkts-apis-media-e.md#mediatype8) | 是   | 媒体类型枚举，决定静音或画面显示的控制范围。<br>**API version 12-19**：仅支持MEDIA_TYPE_AUD，影响音频静音。<br>**API version 20及以后**：支持MEDIA_TYPE_VID，影响视频画面显示。 |
| muted | boolean | 是   | **API version 12-19**：仅支持设置音频播放策略，表示音频是否静音播放。true为静音播放，false为取消静音播放。<br>**API version 20及以后**：增加支持设置视频播放策略，表示视频画面是否关闭。true为关闭画面，false为恢复画面。|

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------------------- |
| 401 | The parameter check failed. Return by promise. |
| 5400102 | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized状态后才能调用。
  avPlayer.prepare().then(() => {
    console.info('Succeeded in preparing');
    avPlayer.setMediaMuted(media.MediaType.MEDIA_TYPE_AUD, true);
  }, (err: BusinessError) => {
    console.error(`Failed to prepare.Code:${err.code},message:${err.message}`);
  });
}
```

## play<sup>9+</sup>

play(callback: AsyncCallback\<void>): void

开始播放音视频资源，只能在prepared/paused/completed状态调用。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 开始播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/paused/completed状态后才能调用。
  avPlayer.play((err: BusinessError) => {
    if (err) {
      console.error(`Failed to play.Code:${err.code},message:${err.message}`);
    } else {
      console.info('Succeeded in playing');
    }
  });
}
```

## play<sup>9+</sup>

play(): Promise\<void>

开始播放音视频资源，只能在prepared/paused/completed状态调用。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/paused/completed状态后才能调用。
  avPlayer.play().then(() => {
    console.info('Succeeded in playing');
  }, (err: BusinessError) => {
    console.error(`Failed to play.Code:${err.code},message:${err.message}`);
  });
}
```

## pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

暂停播放音视频资源，只能在playing状态调用。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 暂停播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至playing状态后才能调用。
  avPlayer.pause((err: BusinessError) => {
    if (err) {
      console.error(`Failed to pause.Code:${err.code},message:${err.message}`);
    } else {
      console.info('Succeeded in pausing');
    }
  });
}
```

## pause<sup>9+</sup>

pause(): Promise\<void>

暂停播放音视频资源，只能在playing状态调用。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至playing状态后才能调用。
  avPlayer.pause().then(() => {
    console.info('Succeeded in pausing');
  }, (err: BusinessError) => {
    console.error(`Failed to pause.Code:${err.code},message:${err.message}`);
  });
}
```

## stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

停止播放音视频资源，只能在prepared/playing/paused/completed状态调用。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 停止播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop.Code:${err.code},message:${err.message}`);
    } else {
      console.info('Succeeded in stopping');
    }
  });
}
```

## stop<sup>9+</sup>

stop(): Promise\<void>

停止播放音视频资源，只能在prepared/playing/paused/completed状态调用。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.stop().then(() => {
    console.info('Succeeded in stopping');
  }, (err: BusinessError) => {
    console.error(`Failed to stop.Code:${err.code},message:${err.message}`);
  });
}
```

## reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

重置播放，将播放器恢复到idle状态并清除已设置的媒体资源，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 重置播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized/prepared/playing/paused/completed/stopped/error状态后才能调用。
  avPlayer.reset((err: BusinessError) => {
    if (err) {
      console.error(`Failed to reset.Code:${err.code},message:${err.message}`);
    } else {
      console.info('Succeeded in resetting');
    }
  });
}
```

## reset<sup>9+</sup>

reset(): Promise\<void>

重置播放，将播放器恢复到idle状态并清除已设置的媒体资源，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized/prepared/playing/paused/completed/stopped/error状态后才能调用。
  avPlayer.reset().then(() => {
    console.info('Succeeded in resetting');
  }, (err: BusinessError) => {
    console.error(`Failed to reset.Code:${err.code},message:${err.message}`);
  });
}
```

## release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

销毁播放资源，除released状态外，AVPlayer在其他状态都可以调用该接口。应用需要按照实际业务需求合理使用AVPlayer对象，按需创建并及时释放，避免持有过多AVPlayer实例导致内存消耗过大，否则可能导致系统终止应用。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 销毁播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发除released以外的状态才能调用。
  avPlayer.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release.Code:${err.code},message:${err.message}`);
    } else {
      console.info('Succeeded in releasing');
    }
  });
}
```

## release<sup>9+</sup>

release(): Promise\<void>

销毁播放资源，除released状态外，AVPlayer在其他状态都可以调用该接口。应用需要按照实际业务需求合理使用AVPlayer对象，按需创建并及时释放，避免持有过多AVPlayer实例导致内存消耗过大，否则可能导致系统终止应用。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发除released以外的状态才能调用。
  avPlayer.release().then(() => {
    console.info('Succeeded in releasing');
  }, (err: BusinessError) => {
    console.error(`Failed to release.Code:${err.code},message:${err.message}`);
  });
}
```

## getTrackDescription<sup>9+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

获取音视频轨道信息，可以在prepared/playing/paused状态调用。获取所有音视频轨道信息，应在数据加载回调后调用。使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | 是   | 回调函数，当获取音视频轨道信息成功，err为undefined，data为获取到的MediaDescription数组；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused状态后才能调用。
  avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
    if (error) {
      console.error(`Failed to do getTrackDescription, error:${error}`);
    } else {
      console.info('Succeeded in doing getTrackDescription');
    }
  });
}
```

## getTrackDescription<sup>9+</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

获取音视频轨道信息，可以在prepared/playing/paused状态调用。使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Promise对象，返回音视频轨道信息MediaDescription数组。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused状态后才能调用。
  avPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
    console.info('Succeeded in getting TrackDescription');
  }).catch((error: BusinessError) => {
    console.error(`Failed to get TrackDescription.Code:${error.code},message:${error.message}`);
  });
}
```

## getSelectedTracks<sup>12+</sup>

getSelectedTracks(): Promise\<Array\<number>>

获取已选择的音视频轨道索引，可以在prepared/playing/paused状态调用。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise\<Array\<number>> | Promise对象，返回已选择音视频轨道索引数组。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused状态后才能调用。
  avPlayer.getSelectedTracks().then((arrList: Array<number>) => {
    console.info('Succeeded in getting SelectedTracks');
  }).catch((error: BusinessError) => {
    console.error(`Failed to get SelectedTracks.Code:${error.code},message:${error.message}`);
  });
}
```

## getPlaybackInfo<sup>12+</sup>

getPlaybackInfo(): Promise\<PlaybackInfo>

获取播放过程信息，可以在prepared/playing/paused状态调用。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<[PlaybackInfo](arkts-apis-media-i.md#playbackinfo12)> | Promise对象。resolve返回PlaybackInfo对象，包含播放过程中的信息，如播放状态、缓冲状态等详细播放信息；reject返回错误信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer | undefined;
let playbackInfo: media.PlaybackInfo | undefined;
media.createAVPlayer(async (err: BusinessError, player: media.AVPlayer) => {
  if (player) {
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

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized状态后才能调用。
  avPlayer.prepare().then(() => {
    console.info('Succeeded in preparing');
    let playbackPosition: number = avPlayer.getPlaybackPosition();
    console.info(`AVPlayer getPlaybackPosition== ${playbackPosition}`);
  }, (err: BusinessError) => {
    console.error(`Failed to prepare.Code:${err.code},message:${err.message}`);
  });
}
```

## getCurrentPresentationTimestamp<sup>23+</sup>

getCurrentPresentationTimestamp() : number

获取当前播放位置，可以在播放（playing）/暂停（paused）/完成（completed）状态调用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| number | 返回当前播放位置的时间，单位：微秒（μs）。|

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized状态后才能调用。
  avPlayer.play().then(() => {
    console.info('Succeeded in playing');
    let currentPresentation: number = avPlayer.getCurrentPresentationTimestamp();
    console.info(`AVPlayer getCurrentPresentationTimestamp== ${currentPresentation}`);
  }, (err: BusinessError) => {
    console.error(`Failed to play.Code:${err.code},message:${err.message}`);
  });
}
```

## selectTrack<sup>12+</sup>

selectTrack(index: number, mode?: SwitchMode): Promise\<void>

使用AVPlayer播放多音视频轨资源时，允许用户以指定模式切换到指定轨道以继续播放。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| index | number | 是   | 多音视频资源的轨道索引。该值必须为整数。<br>取值约束：可通过[getTrackDescription](#gettrackdescription9-1)接口返回的音视频轨道信息[MediaDescription](arkts-apis-media-i.md#mediadescription8)中读取的key为MD_KEY_TRACK_INDEX所对应的值。<br>每个key值的Object类型和范围，请参考[MediaDescriptionKey](arkts-apis-media-e.md#mediadescriptionkey8)对应Key值的说明。 |
| mode   | [SwitchMode](arkts-apis-media-e.md#switchmode12) | 否   | 切换轨道的模式。<br>取值约束：该模式仅适用于视频轨道的切换。<br>默认值为SMOOTH模式，在片段末尾进行切换，以确保视频播放的连续性。**仅在DASH/HLS协议网络流视频轨切换时生效。**<br>从API版本26.0.0开始支持HLS协议网络流视频。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | The parameter check failed. Return by promise.       |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function  test(){
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  let audioTrackIndex: Object = 0;
  avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
    if (arrList != null) {
      // 遍历轨道描述列表，提取非首个轨道的索引用于音频轨道选择。
      for (let i = 0; i < arrList.length; i++) {
        if (i != 0) {
          // 获取音频轨道列表。
          audioTrackIndex = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
        }
      }
    } else {
      console.error(`Failed to get TrackDescription.Code:${error.code},message:${error.message}`);
    }
  });

  // 选择其中一个音频轨道。
  avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
}
```

## deselectTrack<sup>12+</sup>

deselectTrack(index: number): Promise\<void>

使用AVPlayer播放多音轨视频时取消指定音视频轨道播放，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| index | number | 是   | 多音视频资源的轨道索引，来自[getTrackDescription](#gettrackdescription9-1)接口所获取的轨道信息[MediaDescription](arkts-apis-media-i.md#mediadescription8)。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

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
    console.error(`Failed to get TrackDescription.Code:${error.code},message:${error.message}`);
  }
});

// 选择其中一个音频轨道。
avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
// 取消选择上次选中的音频轨道，并恢复到默认音频轨道。
avPlayer.deselectTrack(parseInt(audioTrackIndex.toString()));
```

## setDecryptionConfig<sup>11+</sup>

setDecryptionConfig(mediaKeySession: drm.MediaKeySession, secureVideoPath: boolean): void

设置解密配置。当收到[on('mediaKeySystemInfoUpdate')](#onmediakeysysteminfoupdate11)事件时，需根据事件上报的MediaKeySystemInfo信息创建MediaKeySystem和MediaKeySession对象，并调用setDecryptionConfig设置解密配置，否则无法播放。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| mediaKeySession | [drm.MediaKeySession](../apis-drm-kit/arkts-apis-drm-MediaKeySession.md) | 是   | 解密会话对象，用于播放DRM加密内容。 |
| secureVideoPath | boolean | 是 | 是否使用安全视频通路。true表示使用安全视频通路（用于播放受保护的DRM内容），false表示使用非安全视频通路（用于播放普通内容）。当播放DRM加密的高清视频内容时，通常需要设置为true。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

关于drm模块的示例具体可见[@ohos.multimedia.drm](../apis-drm-kit/arkts-apis-drm.md)。

```ts
import { drm } from '@kit.DrmKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 创建MediaKeySystem系统。
  let keySystem:drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
  // 创建MediaKeySession解密会话。
  let keySession:drm.MediaKeySession = keySystem.createMediaKeySession(drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
  // 生成许可证请求、设置许可证响应等。
  // 安全视频通路标志。
  let secureVideoPath:boolean = false;
  // 设置解密配置。
  avPlayer.setDecryptionConfig(keySession, secureVideoPath);
}
```

## getMediaKeySystemInfos<sup>11+</sup>

getMediaKeySystemInfos(): Array\<drm.MediaKeySystemInfo>

获取当前播放的媒体资源的MediaKeySystemInfo。需要在[on('mediaKeySystemInfoUpdate')](#onmediakeysysteminfoupdate11)事件触发成功后才能调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                                                      | 说明                                                                                                      |
|-----------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------|
| Array<[drm.MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)> | MediaKeySystemInfo数组，MediaKeySystemInfo具有uuid和pssh两个属性。当返回值为undefined时，表示mediaKeySystemInfoUpdate事件未触发。 |


**示例：**

```ts
import { drm } from '@kit.DrmKit';

async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在mediaKeySystemInfoUpdate事件触发成功后才能调用。
  const infos = avPlayer.getMediaKeySystemInfos();
  console.info('GetMediaKeySystemInfos count: ' + infos.length);
  for (let i = 0; i < infos.length; i++) {
    console.info('GetMediaKeySystemInfos uuid: ' + infos[i]["uuid"]);
    console.info('GetMediaKeySystemInfos pssh: ' + infos[i]["pssh"]);
  }
}
```

## seek<sup>9+</sup>

seek(timeMs: number, mode?:SeekMode): void

跳转到指定播放位置，只能在prepared/playing/paused/completed状态调用，可以通过[on('seekDone')](#onseekdone9)事件确认是否生效。

> **注意：**
>
> 从API版本26.0.0开始，直播场景支持seek。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, [duration](#属性)]。<br>当模式为[SEEK_CONTINUOUS](arkts-apis-media-e.md#seekmode8)时，可以取值-1，表示SEEK_CONTINUOUS模式结束。该值必须为整数。 |
| mode   | [SeekMode](arkts-apis-media-e.md#seekmode8) | 否   | 基于视频I帧的跳转模式，默认值为SEEK_PREV_SYNC模式，**仅在视频资源播放时设置**。 |

**示例：**

```ts
async function  test(){
  let avPlayer = await media.createAVPlayer();
  let seekTime: number = 1000;
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC);
}
```

```ts
async function  test(){
  // SEEK_CONTINUOUS 可以结合Slider的onChange回调方法进行对应处理，当slideMode为Moving时，触发拖动过程的SeekContinuous。
  let avPlayer = await media.createAVPlayer();
  let slideMovingTime: number = 2000;
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.seek(slideMovingTime, media.SeekMode.SEEK_CONTINUOUS);

  // 当slideMode为End时，调用seek(-1, media.SeekMode.SEEK_CONTINUOUS)结束seek。
  avPlayer.seek(-1, media.SeekMode.SEEK_CONTINUOUS);
}
```

## isSeekContinuousSupported<sup>18+</sup>

isSeekContinuousSupported() : boolean

查询媒体源是否支持以SEEK_CONTINUOUS模式[SeekMode](arkts-apis-media-e.md#seekmode8)进行[seek](#seek9)，在prepared/playing/paused/completed状态调用返回实际值，其余状态调用返回false。对于不支持SEEK_CONTINUOUS模式进行seek的设备，返回false。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| boolean | 媒体源是否支持以SEEK_CONTINUOUS模式进行seek。true表示支持，false表示不支持。 |

**示例：**

```ts
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  let isSupported = avPlayer.isSeekContinuousSupported();
}
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
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收seek生效的事件回调。
  avPlayer.on('seekDone', (seekDoneTime:number) => {
    console.info('seekDone called,and seek time is:' + seekDoneTime);
  });
}
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
| callback<sup>12+</sup> | Callback\<number> | 否   | 回调函数。seek生效的事件回调方法，只会上报用户请求的time位置。<br/>**视频播放：**[SeekMode](arkts-apis-media-e.md#seekmode8)会造成实际跳转位置与用户设置产生偏差，精准位置需要通过currentTime获取，事件回调的time仅代表完成用户某一次请求。如果填写该参数，仅取消注册此回调的方法，否则取消注册seekDone事件的所有回调方法。 |

**示例：**

```ts
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收seek生效的事件回调。
  avPlayer.off('seekDone');
}
```

## setSpeed<sup>9+</sup>

setSpeed(speed: PlaybackSpeed): void

设置倍速模式，只能在prepared/playing/paused/completed状态调用，可以通过[on('speedDone')](#onspeeddone9)事件确认是否生效。

setSpeed使用固定的枚举倍速值，适合标准倍速场景；setPlaybackRate支持任意倍速值且取值范围更大，适合自定义倍速场景。两者功能相同，建议根据API版本和精度需求选择：API version 9-19，使用setSpeed；API version 20及以上且需要精确倍速控制，使用setPlaybackRate。

> **注意：**
>
> 直播场景不支持setSpeed。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                             | 必填 | 说明               |
| ------ | -------------------------------- | ---- | ------------------ |
| speed  | [PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8) | 是   | 指定播放倍速模式，设置后播放器将按照指定倍速播放，如SPEED_FORWARD_2_00_X表示以2倍速播放。 |

**示例：**

```ts
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.setSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X);
}
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
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收setSpeed生效事件回调。
  avPlayer.on('speedDone', (speed:number) => {
    console.info('speedDone called,and speed value is:' + speed);
  });
}
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
| callback<sup>12+</sup> | Callback\<number> | 否   | 回调函数。当setSpeed成功，上报生效的倍速模式，具体见[PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8)。如果填写该参数，仅取消注册此回调方法，否则取消注册speedDone事件的所有回调方法。 |

**示例：**

```ts
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收setSpeed生效事件回调。
  avPlayer.off('speedDone');
}
```

## setPlaybackRate<sup>20+</sup>

setPlaybackRate(rate: number): void

设置倍速模式。只能在'prepared' | 'playing' | 'paused' | 'completed'状态下调用，在API版本26.0.0及以上的取值范围是[0.125, 8.0]，API版本26.0.0以下的取值范围是[0.125, 4.0]，可以通过[playbackRateDone](#onplaybackratedone20)事件确认是否生效。

> **注意：**
>
> 直播场景不支持setPlaybackRate。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                             | 必填 | 说明               |
| ------ | -------------------------------- | ---- | ------------------ |
| rate  | number | 是   | 指定播放倍速速率值，单位为倍速（x）。<br>在API版本26.0.0之前的取值范围是[0.125, 4.0]，API版本26.0.0及以后的取值范围是[0.125, 8.0]。默认值为1.0x（正常速度）。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400108  | The parameter check failed, parameter value out of range.      |
| 5400102  | Operation not allowed, if invalid state or live stream.      |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.setPlaybackRate(2.0);
}
```

## getPlaybackRate<sup>23+</sup>

getPlaybackRate(): Promise\<number>

获取当前播放器的播放速率。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型             | 说明           |
| ---------------- | -------------- |
| Promise\<number> | Promise对象，返回播放倍速速率。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.getPlaybackRate().then((rate: number) => {
    console.info('Succeeded getPlaybackRate' + rate);
  });
}
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
| callback | [OnPlaybackRateDone](arkts-apis-media-t.md#onplaybackratedone20) | 是   | setPlaybackRate生效的事件回调方法，上报设置后的播放速率。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收setPlaybackRate生效的事件。
  avPlayer.on('playbackRateDone', (rate:number) => {
    console.info('playbackRateDone called,and rate value is:' + rate);
  });
}
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
| callback | [OnPlaybackRateDone](arkts-apis-media-t.md#onplaybackratedone20) | 否   |  setPlaybackRate生效的事件回调方法，上报设置后的播放速率。如果填写该参数，仅取消注册此回调方法，否则取消注册playbackRateDone事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收setPlaybackRate生效的事件。
  avPlayer.off('playbackRateDone');
}
```

## getLoadedTimeRanges

getLoadedTimeRanges(): Promise\<Array\<Range>>

获取已加载的时间区间段的列表。使用Promise异步回调。

> **说明：**
>
> - 对于本地媒体资源，返回的时间区间为0到整个媒体时长。
> - 对于网络媒体资源，返回本地已缓存的时间区间段的列表。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型             | 说明           |
| ---------------- | -------------- |
| Promise\<Array\<[Range](arkts-apis-media-i.md#range11)>> | Promise对象，返回播放器当前已加载的时间区间段的列表。<br>时间区间段以播放时间轴上的[start, end]位置表示，单位为毫秒（ms）。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.getLoadedTimeRanges().then((range: Array<media.Range>) => {
    console.info(`Succeeded in calling getLoadedTimeRanges: ${range}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to getLoadedTimeRanges.Code:${err.code},message:${err.message}`);
  });
}
```

## getSeekableTimeRanges

getSeekableTimeRanges(): Promise\<Array\<Range>>

获取可跳转的时间区间段的列表。使用Promise异步回调。

> **说明：**
>
> - 对于本地媒体资源及支持分段请求的媒体资源，返回的时间区间为0到整个媒体时长。
> - 对于仅支持分块传输的媒体资源，没有可跳转的时间范围。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型             | 说明           |
| ---------------- | -------------- |
| Promise\<Array\<[Range](arkts-apis-media-i.md#range11)>> | Promise对象，返回播放器当前可跳转的时间区间段的列表。<br>时间区间段以播放时间轴上的[start, end]位置表示，单位为毫秒（ms）。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.getSeekableTimeRanges().then((range: Array<media.Range>) => {
    console.info(`Succeeded in calling getSeekableTimeRanges: ${range}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to getSeekableTimeRanges.Code:${err.code},message:${err.message}`);
  });
}
```

## seekToDefaultPosition

seekToDefaultPosition(): void

跳转到播放源的默认接入点。直播流为当前推荐的最新接入点；点播视频通常为视频起始位置（等同于seek(0)）。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test(){
  let avPlayer = await media.createAVPlayer();
  try {
    avPlayer.seekToDefaultPosition()
    console.info('Succeeded in calling seekToDefaultPosition.');
  } catch (err) {
    console.error(`Failed to seekToDefaultPosition.Code:${err.code},message:${err.message}`);
  }
}
```

## setBitrate<sup>9+</sup>

setBitrate(bitrate: number): void

设置比特率，以播放所指定比特率的流媒体资源，当前仅对**HLS/DASH协议网络流**有效。默认情况下，AVPlayer会根据网络连接速度选择合适的比特率。只能在prepared/playing/paused/completed状态调用，可以通过[bitrateDone](#onbitratedone9)事件确认是否生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| bitrate | number | 是   | 指定比特率，单位为比特每秒（bps）。<br>须通过[availableBitrates](#onavailablebitrates9)事件获得当前HLS/DASH协议网络流可用的比特率列表，如果用户指定的比特率不在此列表中，则播放器将从可用比特率列表中选择最接近的比特率。<br>如果通过availableBitrates事件获得的比特率列表长度为0，则不支持指定比特率，也不会产生bitrateDone回调。 |

**示例：**

```ts
async function  test(){
  let avPlayer = await media.createAVPlayer();
  let bitrate: number = 96000;
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.setBitrate(bitrate);
}
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
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收setBitrate生效事件回调。
  avPlayer.on('bitrateDone', (bitrate:number) => {
    console.info('bitrateDone called,and bitrate value is:' + bitrate);
  });
}
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
| callback<sup>12+</sup> | Callback\<number> | 否   | setBitrate生效的事件回调方法，上报生效的比特率。如果填写该参数，仅取消注册此回调方法，否则取消注册bitrateDone事件的所有回调方法。           |

**示例：**

```ts
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收setBitrate生效事件回调。
  avPlayer.off('bitrateDone');
}
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
async function  test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，播放状态切换prepared状态时，接收到HLS/DASH协议网络流可用的比特率列表回调。
  avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
    console.info('availableBitrates called,and availableBitrates length is:' + bitrates.length);
  });
}
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
| callback<sup>12+</sup> | Callback\<Array\<number>> | 否   | HLS/DASH协议网络流可用比特率上报事件回调方法，使用数组存放支持的比特率。如果数组长度为0，则不支持指定比特率。如果填写该参数，仅取消注册此回调方法，否则取消注册availableBitrates事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收HLS/DASH协议网络流可用的比特率列表回调。
  avPlayer.off('availableBitrates');
}
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

async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收mediaKeySystemInfoUpdate事件回调。
  avPlayer.on('mediaKeySystemInfoUpdate', (mediaKeySystemInfo: Array<drm.MediaKeySystemInfo>) => {
    for (let i = 0; i < mediaKeySystemInfo.length; i++) {
      console.info('mediaKeySystemInfoUpdate happened uuid: ' + mediaKeySystemInfo[i]["uuid"]);
      console.info('mediaKeySystemInfoUpdate happened pssh: ' + mediaKeySystemInfo[i]["pssh"]);
    }
  });
}
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
| callback | Callback\<Array\<drm.[MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)>> | 否   | 版权保护信息更新上报事件回调方法，上报版权保护信息数组。如果填写该参数，仅取消注册此回调方法，否则取消注册mediaKeySystemInfoUpdate事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收mediaKeySystemInfoUpdate事件回调。
  avPlayer.off('mediaKeySystemInfoUpdate');
}
```

## setLoudnessGain<sup>21+</sup>

setLoudnessGain(loudnessGain: number): Promise\<void>

设置播放器的响度增益。响度是指音频的主观感知强度，响度增益通过调整音频信号的强度来改变感知音量，与setVolume的相对音量调节不同。调用该接口后，响度增益立即生效。使用Promise异步回调。

> **说明：**
>
> - 当播放处于prepared/playing/paused/completed/stopped状态时，可调用该接口。
> - 调用此接口时，需确保已设置音频渲染信息AVPlayer.audioRendererInfo，audioRendererInfo的usage参数必须是[STREAM_USAGE_MUSIC](../apis-audio-kit/arkts-apis-audio-e.md#streamusage)、[STREAM_USAGE_MOVIE](../apis-audio-kit/arkts-apis-audio-e.md#streamusage)、[STREAM_USAGE_AUDIOBOOK](../apis-audio-kit/arkts-apis-audio-e.md#streamusage)其中之一。
> - 该接口不支持高清通路的响度设置。
> - 音频流的时延模式必须是普通时延。
> - 该接口错误信息通过[on('error')](#onerror9)回调。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| loudnessGain | number | 是   | 设置播放器的响度值，单位为分贝（dB），响度范围为[-90.0, 24.0]。默认值为0.0dB。|

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

async function test(){
  let avPlayer = await media.createAVPlayer();

  let loudnessGain: number = 1.0;
  avPlayer.audioRendererInfo = {
    usage: audio.StreamUsage.STREAM_USAGE_MOVIE,
    rendererFlags: 0
  }
  avPlayer.setLoudnessGain(loudnessGain);
}
```

## setVolume<sup>9+</sup>

setVolume(volume: number): void

设置媒体播放音量，只能在prepared/playing/paused/completed状态调用，可以通过[on('volumeChange')](#onvolumechange9)事件确认是否生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| volume | number | 是   | 指定的相对音量大小，取值范围为[0.00, 1.00]，1表示最大音量，即100%。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  let volume: number = 1.0;
  avPlayer.setVolume(volume);
}
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
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收setVolume生效的事件回调。
  avPlayer.on('volumeChange', (vol: number) => {
    console.info('volumeChange called,and new volume is :' + vol);
  });
}
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
| callback<sup>12+</sup> | Callback\<number> | 否   | setVolume生效的事件回调方法，上报生效的媒体音量。如果填写该参数，仅取消注册此回调方法，否则取消注册volumeChange事件的所有回调方法。            |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收setVolume生效的事件。
  avPlayer.off('volumeChange');
}
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
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收endOfStream事件回调。
  avPlayer.on('endOfStream', () => {
    console.info('endOfStream called');
  });
}
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
| callback<sup>12+</sup> | Callback\<void> | 否   | 资源播放至结尾的事件回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册endOfStream事件的所有回调方法。                               |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收endOfStream事件回调。
  avPlayer.off('endOfStream');
}
```

## on('timeUpdate')<sup>9+</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

监听资源播放当前时间，单位为毫秒（ms），用于刷新进度条当前位置，默认间隔100ms时间上报，因用户操作（seek）产生的时间变化会立刻上报。

>**注意：**
>
>- 直播场景不支持timeUpdate上报。
>- 操作（seek）时必须等待seekdone结束才能根据timeUpdate来更新进度条。
>- 在pause状态下，缓冲结束时播放器会上报timeUpdate事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                           |
| -------- | -------- | ---- | ---------------------------------------------- |
| type     | string   | 是   | 时间更新的回调类型，支持的事件：'timeUpdate'。 |
| callback | Callback\<number> | 是   | 回调函数。返回当前时间。                                     |

**示例1：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收资源播放当前时间事件回调。
  avPlayer.on('timeUpdate', (time:number) => {
    console.info('timeUpdate called,and new time is :' + time);
  });
}
```

**示例2：**

```ts
async function test() {
  let avPlayer = await media.createAVPlayer();

  let isSeeking = false;    // 标记是否正在seek。
  let seekTargetTime = 0;   // 记录目标时间，单位为毫秒（ms）。

  // 1.监听seekDone：确认跳转完成。
  avPlayer.on('seekDone', (seekDoneTime: number) => {
    console.info('seekDone called, and seek time is: ' + seekDoneTime);
    isSeeking = false;
    seekTargetTime = seekDoneTime; // 可选：记录最终定位时间。
  });

  // 2.监听timeUpdate：只在seekDone后才更新进度。
  avPlayer.on('timeUpdate', (time: number) => {
    // 关键逻辑：只有seekDone之后才允许更新进度条。
    if (isSeeking) {
      console.info('seek in progress, ignore timeUpdate');
      return; // 忽略seek期间的timeUpdate。
    }

    // 真正的播放进度更新（seekDone后才生效）。
    console.info('timeUpdate: ' + time + ' ms');
    // 此处进行进度条更新。
  });

  // 3.模拟seek操作。
  let seekTime: number = 1000;
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused/completed状态后才能调用。
  avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC); // 单位为毫秒（ms）。
  isSeeking = true; // 标记正在seek。
}
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
| callback<sup>12+</sup> | Callback\<number> | 否   | 回调函数。返回当前时间。如果填写该参数，仅取消注册此回调方法，否则取消注册timeUpdate事件的所有回调方法。             |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收资源播放当前时间事件回调。
  avPlayer.off('timeUpdate');
}
```

## on('durationUpdate')<sup>9+</sup>


on(type: 'durationUpdate', callback: Callback\<number>): void

监听资源播放资源的时长，单位为毫秒（ms），用于刷新进度条长度，默认只在prepared上报一次，同时允许一些特殊码流刷新多次时长。

> **注意：**
>
> 直播场景不支持durationUpdate上报。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                               |
| -------- | -------- | ---- | -------------------------------------------------- |
| type     | string   | 是   | 时长更新的回调类型，支持的事件：'durationUpdate'。 |
| callback | Callback\<number> | 是   | 回调函数。返回资源时长。        |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收资源播放资源的时长事件回调。
  avPlayer.on('durationUpdate', (duration: number) => {
    console.info('durationUpdate called,new duration is :' + duration);
  });
}
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
| callback<sup>12+</sup> | Callback\<number> | 否   | 回调函数。返回资源时长。如果填写该参数，仅取消注册此回调方法，否则取消注册durationUpdate事件的所有回调方法。        |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收资源播放资源的时长事件回调。
  avPlayer.off('durationUpdate');
}
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
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收音视频缓存更新事件回调。
  avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
    console.info('bufferingUpdate called,and infoType value is:' + infoType + ', value is :' + value);
  });
}
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
| callback | [OnBufferingUpdateHandler](arkts-apis-media-t.md#onbufferingupdatehandler12) | 否   | 播放缓存事件回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册bufferingUpdate事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收资源播放资源的时长事件回调。
  avPlayer.off('bufferingUpdate');
}
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
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听后，开始接收视频播放开始首帧渲染的更新事件回调。
  avPlayer.on('startRenderFrame', () => {
    console.info('startRenderFrame called');
  });
}
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
| callback<sup>12+</sup> | Callback\<void> | 否   | 视频播放开始首帧渲染事件回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册startRenderFrame事件的所有回调方法。                   |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收视频播放开始首帧渲染的更新事件回调。
  avPlayer.off('startRenderFrame');
}
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
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听视频播放宽高变化事件，仅视频播放支持该订阅事件，默认只在prepared状态上报一次。
  avPlayer.on('videoSizeChange', (width: number, height: number) => {
    console.info('videoSizeChange called,and width is:' + width + ', height is :' + height);
  });
}
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
| callback<sup>12+</sup> | [OnVideoSizeChangeHandler](arkts-apis-media-t.md#onvideosizechangehandler12) | 否   | 视频播放宽高变化事件回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册videoSizeChange事件的所有回调方法。    |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再监听视频播放宽高变化事件。
  avPlayer.off('videoSizeChange');
}
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

async function test(){
  let avPlayer = await media.createAVPlayer();
  // 监听音频焦点变化事件，多个音视频资源同时播放时，会根据音频焦点模型audio.InterruptMode触发此事件。
  avPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
    console.info('audioInterrupt called,and InterruptEvent info is:' + info);
  });
}
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
| callback<sup>12+</sup> | Callback\<[audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)> | 否   | 音频焦点变化事件回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册audioInterrupt事件的所有回调方法。             |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收音频焦点变化事件回调。
  avPlayer.off('audioInterrupt');
}
```

## on('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

on(type: 'audioOutputDeviceChangeWithInfo', callback: Callback\<audio.AudioStreamDeviceChangeInfo>): void

订阅监听音频流输出设备变化及原因。使用callback异步回调。

在订阅此监听时，建议参考[响应输出设备变更时合理暂停](../../media/audio/audio-output-device-change.md)自行实现设备连接或者断开时的播放器行为。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'audioOutputDeviceChangeWithInfo'。 |
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | 是   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.       |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

async function test(){
  let avPlayer = await media.createAVPlayer();
  // 开始监听音频流输出设备变化及原因。
  avPlayer.on('audioOutputDeviceChangeWithInfo', (data: audio.AudioStreamDeviceChangeInfo) => {
    console.info(`${JSON.stringify(data)}`);
  });
}
```

## off('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

off(type: 'audioOutputDeviceChangeWithInfo', callback?: Callback\<audio.AudioStreamDeviceChangeInfo>): void

取消订阅监听音频流输出设备变化及原因。使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'audioOutputDeviceChangeWithInfo'。 |
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | 否   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。如果填写该参数，仅取消注册此回调方法，否则取消注册audioOutputDeviceChangeWithInfo事件的所有回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.      |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收音频流输出设备变化事件。
  avPlayer.off('audioOutputDeviceChangeWithInfo');
}
```

## addSubtitleFromFd<sup>12+</sup>

addSubtitleFromFd(fd: number, offset?: number, length?: number): Promise\<void>

依据fd为视频添加外挂字幕，当前仅支持与视频资源同时设置（在AVPlayer设置fdSrc视频资源后设置外挂字幕）。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| fd | number   | 是   | 资源句柄，通过[resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9)获取。 |
| offset | number | 否   | 资源偏移量。取值范围[0, +∞)。需要基于预置资源的信息输入，非法值会造成字幕资源解析错误。默认值为0。单位为字节。|
| length | number | 否   | 资源长度。取值范围[0, +∞)。如果不传递该参数，默认使用文件中从偏移量开始的剩余字节；如果传递该参数，默认值为0，需要基于预置资源的信息输入，非法值会造成字幕资源解析错误。|

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit'

let avPlayer = await media.createAVPlayer();
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let fileDescriptor = await context.resourceManager.getRawFd('xxx.srt');

avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length);
```

## addSubtitleFromUrl<sup>12+</sup>

addSubtitleFromUrl(url: string): Promise\<void>

依据URL为视频添加外挂字幕，当前仅支持与视频资源同时设置（在AVPlayer设置fdSrc视频资源后设置外挂字幕）。使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| url    | string | 是   | 外挂字幕文件地址。支持http/https网络地址和本地文件路径。当前支持的字幕文件格式包括srt、vtt等常见格式。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

<!--code_no_check-->
```ts
async function test(){
  let fdUrl:string = 'https://abc.bcd.example/cde/index.srt'; // 此处仅为示意，请替换为真实资源文件URL。
  let avPlayer: media.AVPlayer = await media.createAVPlayer();
  avPlayer.addSubtitleFromUrl(fdUrl);
}
```

## on('subtitleUpdate')<sup>12+</sup>

on(type: 'subtitleUpdate', callback: Callback\<SubtitleInfo>): void

订阅获取外挂字幕的事件，当有外挂字幕时，会通过订阅的回调方法通知用户。用户只能订阅一个外挂字幕事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，用于注册监听外挂字幕更新事件，支持的事件类型为：'subtitleUpdate'。 |
| callback | Callback\<[SubtitleInfo](arkts-apis-media-i.md#subtitleinfo12)> | 是   | 外挂字幕事件回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 订阅获取外挂字幕的事件，当有外挂字幕时，会触发事件。
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
}
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
| callback | Callback\<[SubtitleInfo](arkts-apis-media-i.md#subtitleinfo12)> | 否   | 取消外挂字幕事件的回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册subtitleUpdate事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收获取外挂字幕的事件。
  avPlayer.off('subtitleUpdate');
}
```

## on('trackChange')<sup>12+</sup>

on(type: 'trackChange', callback: OnTrackChangeHandler): void

订阅获取轨道变更的事件，当播放的轨道变更时，会通过订阅的回调方法通知用户。用户只能订阅一个轨道变更事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，用于注册监听轨道变更事件，支持的事件类型为：'trackChange'。 |
| callback | [OnTrackChangeHandler](arkts-apis-media-t.md#ontrackchangehandler12) | 是   | 轨道变更事件回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 订阅获取轨道变更的事件，当播放的轨道变更时，会触发事件回调。
  avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
    console.info('trackChange info: index=' + index + ' isSelect=' + isSelect);
  });
}
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
| callback | [OnTrackChangeHandler](arkts-apis-media-t.md#ontrackchangehandler12) | 否   | 取消轨道变更事件的回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册trackChange事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收轨道变更的事件。
  avPlayer.off('trackChange');
}
```

## on('trackInfoUpdate')<sup>12+</sup>

on(type: 'trackInfoUpdate', callback: Callback\<Array\<MediaDescription>>): void

订阅获取轨道信息更新的事件，当播放的轨道有更新时，会通过订阅的回调方法通知用户。用户只能订阅一个轨道变更事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，用于注册监听轨道信息更新事件，支持的事件类型为：'trackInfoUpdate'。 |
| callback | Callback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | 是   | 轨道信息更新事件回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 订阅获取轨道信息更新的事件，当播放的轨道有更新时，会触发事件回调。
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
}
```

## off('trackInfoUpdate')<sup>12+</sup>

off(type: 'trackInfoUpdate', callback?: Callback\<Array\<MediaDescription>>): void

取消订阅获取轨道信息更新的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackInfoUpdate'。 |
| callback | Callback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | 否   | 取消轨道信息更新事件的回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册trackInfoUpdate事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收轨道信息更新的事件。
  avPlayer.off('trackInfoUpdate');
}
```

## on('amplitudeUpdate')<sup>13+</sup>

on(type: 'amplitudeUpdate', callback: Callback\<Array\<number>>): void

订阅音频最大电平值（振幅强度），用于音频可视化等场景，音频资源播放时定时上报。电平值表示音频信号的瞬时振幅大小。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件回调类型，用于注册监听音频最大电平值更新事件，支持的事件类型为：'amplitudeUpdate'。 |
| callback | Callback\<Array\<number>> | 是   | 音频最大电平值更新事件回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 订阅音频最大电平值，音频资源播放时定时上报。
  avPlayer.on('amplitudeUpdate', (value: Array<number>) => {
    console.info(`amplitudeUpdate called,and amplitudeUpdate = ${value}`);
  });
}
```

## off('amplitudeUpdate')<sup>13+</sup>

off(type: 'amplitudeUpdate', callback?: Callback\<Array\<number>>): void

取消订阅获取音频最大电平值事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 事件回调类型，支持的事件为：'amplitudeUpdate'。 |
| callback | Callback\<Array\<number>> | 否   | 取消音频最大电平值更新事件回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册amplitudeUpdate事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收获取音频最大电平值事件上报。
  avPlayer.off('amplitudeUpdate');
}
```

## on('seiMessageReceived')<sup>18+</sup>

on(type: 'seiMessageReceived', payloadTypes: Array\<number>, callback: OnSeiMessageHandle): void

订阅获取SEI信息事件，仅适用于HTTP-FLV直播，视频流中包含SEI信息时上报。需在prepare之前订阅，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | 是 | 事件回调类型，用于注册监听SEI信息接收事件，支持的事件类型为：'seiMessageReceived'。仅适用于HTTP-FLV直播流。 |
| payloadTypes | Array\<number> | 是 | SEI信息的订阅负载类型数组，用于指定要监听的SEI消息类型。当前仅支持负载类型为5（payloadType = 5）。|
| callback | [OnSeiMessageHandle](arkts-apis-media-t.md#onseimessagehandle18) | 是 | 用于监听SEI信息事件的回调函数，接收订阅的负载类型。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

async function test(){
  let avPlayer = await media.createAVPlayer();

  // 监听后，开始接收seiMessageReceived事件回调。订阅payloadType为5的SEI消息，并解码payload（去除前16字节头部）为UTF-8字符串
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
}
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
| callback | [OnSeiMessageHandle](arkts-apis-media-t.md#onseimessagehandle18) | 否   | 用于监听SEI信息事件的回调函数，接收订阅的负载类型。如果填写该参数，仅取消注册此回调方法，否则取消注册seiMessageReceived事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收seiMessageReceived事件回调。
  avPlayer.off('seiMessageReceived');
}
```

## setSuperResolution<sup>18+</sup>

setSuperResolution(enabled: boolean) : Promise\<void>

动态开启/关闭超分辨率（超分）算法。超分辨率是一种视频画质增强技术，可将低分辨率视频提升至更高分辨率显示。可在'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped'状态下调用。使用Promise异步回调。

> **说明：**
>
> - 在调用[prepare()](#prepare9)前先通过[PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12)使能超分。
> - 默认目标分辨率为1920x1080，单位为像素（px）。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| enabled    | boolean | 是   | 表示是否开启超分。true表示开启超分（当需要提升低分辨率视频的显示质量时选择），false表示关闭超分（当原始分辨率已足够或不需要超分处理时选择）。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by promise. |
| 5410003  | Super-resolution not supported. Return by promise. |
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12). Return by promise. |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  let url: string = 'http://abc.bcd.efg/aa/test.mp4';    // 此处仅为示意，请替换为真实资源文件URL。
  avPlayer.url = url;
  let playStrategy : media.PlaybackStrategy = {
      enableSuperResolution: true
  };
  avPlayer.setPlaybackStrategy(playStrategy);
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized/prepared/playing/paused/completed/stopped状态后才能调用。
  avPlayer.setSuperResolution(true);
}
```

## setVideoWindowSize<sup>18+</sup>

setVideoWindowSize(width: number, height: number) : Promise\<void>

动态设置超分算法的输出分辨率。可在 'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped' 状态下调用。使用Promise异步回调。

输入参数须在320x320~1920x1080范围内，单位为像素（px）。

在调用[prepare()](#prepare9)前先通过[PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12)使能超分。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| width    | number | 是   | 超分算法的目标输出视频宽度，取值范围为[320-1920]，单位为像素（px）。 |
| height    | number | 是   | 超分算法的目标输出视频高度，取值范围为[320-1080]，单位为像素（px）。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5410003  | Super-resolution not supported. Return by promise. |
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12). Return by promise. |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  let url: string = 'http://abc.bcd.efg/aa/test.mp4';    // 此处仅为示意，请替换为真实资源文件URL。
  avPlayer.url = url;
  let playStrategy : media.PlaybackStrategy = {
      enableSuperResolution: true
  };
  avPlayer.setPlaybackStrategy(playStrategy);
  avPlayer.setSuperResolution(true);
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至initialized/prepared/playing/paused/completed/stopped状态后才能调用。
  avPlayer.setVideoWindowSize(1920, 1080);
}
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
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 订阅监听超分算法开启/关闭事件。
  avPlayer.on('superResolutionChanged', (enabled: boolean) => {
    console.info('superResolutionChanged called, and enabled is:' + enabled);
  });
}
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
| callback | [OnSuperResolutionChanged](arkts-apis-media-t.md#onsuperresolutionchanged-18) | 否 | 超分开关事件回调方法。如果填写该参数，仅取消注册此回调方法，否则取消注册superResolutionChanged事件的所有回调方法。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  // 取消后，不再接收超分算法开启/关闭事件。
  avPlayer.off('superResolutionChanged');
}
```

## onPlaybackContentChanged

onPlaybackContentChanged(callback: Callback\<string>):void;

注册监听器用于监听播放内容变更事件。当播放列表中的当前播放源发生变化时（如调用advanceToNextMediaSource、advanceToMediaSource等方法切换播放源），触发此事件。使用callback异步回调。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<string> | 是 | 回调函数，用于接收播放内容变更事件。回调参数为id（string类型），表示当前播放的媒体源的唯一标识符ID。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.onPlaybackContentChanged((id: string) => {
    console.info('MediaSourceChange called, SourceId:' + id);
  });
}
```

## offPlaybackContentChanged

offPlaybackContentChanged(callback?: Callback\<string>):void;

取消监听播放列表中当前媒体源变更事件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<string> | 否 | 指定要取消注册的回调方法。若未指定此参数，则取消订阅该事件的所有回调函数。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  let callback = (id: string) => {
    console.info('MediaSourceChange callback called');
  };

  avPlayer.onPlaybackContentChanged(callback);
  avPlayer.offPlaybackContentChanged(callback);
}
```

## getPlaybackStatisticMetrics<sup>23+</sup>

getPlaybackStatisticMetrics(): Promise\<PlaybackMetrics>

获取当前播放器的统计指标信息，可以在准备（prepared）/播放（playing）/暂停（paused）/完成（completed）/停止（stopped）状态调用。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                         | 说明                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| Promise\<[PlaybackMetrics](arkts-apis-media-t.md#playbackmetrics23)> | Promise对象。resolve返回PlaybackMetrics对象，包含播放器统计指标信息，如播放时长、缓冲时长、错误次数等统计数据；reject返回错误信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer | undefined;
let playbackMetrics: media.PlaybackMetrics | undefined;
media.createAVPlayer(async (err: BusinessError, player: media.AVPlayer) => {
  if (player) {
    avPlayer = player;
    console.info(`Succeeded in creating AVPlayer`);
    if (avPlayer) {
      try {
        playbackMetrics = await avPlayer.getPlaybackStatisticMetrics();
        console.info(`AVPlayer getPlaybackStatisticMetrics = ${JSON.stringify(playbackMetrics)}`); // 打印整个playbackMetrics的值。
      } catch (error) {
        console.error(`error = ${error}`);
      }
    }
  } else {
    console.error(`Failed to create AVPlayer, error message:${err.message}`);
  }
});
```

## onMetricsEvent<sup>23+</sup>

onMetricsEvent(callback: Callback\<Array\<AVMetricsEvent>>): void

订阅播放过程中的指标事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<Array\<[AVMetricsEvent](arkts-apis-media-i.md#avmetricsevent23)>> | 是   | 上报指标事件信息的回调方法，接收AVMetricsEvent数组作为参数。使用callback异步回调。|

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.onMetricsEvent((info: Array<media.AVMetricsEvent>) => {
    if (info) {
      for (let i = 0; i < info.length; i++) {
        console.info('metrics info: index=' + i + ' info=' + JSON.stringify(info));
      }
    } else {
      console.info('metrics info is null');
    }
  });
}
```

## offMetricsEvent<sup>23+</sup>

offMetricsEvent(callback?: Callback\<Array\<AVMetricsEvent>>): void

取消订阅播放过程中的指标事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<Array\<[AVMetricsEvent](arkts-apis-media-i.md#avmetricsevent23)>> | 否   | 指定要取消注册的回调方法。若未填写该参数，则取消订阅该事件的所有回调方法。|

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.offMetricsEvent();
}
```

## onTimedMetaData

onTimedMetaData(callback: Callback\<AVTimedMetaData>): void

注册监听器以检测基于时间的元数据。目前只支持HLS的#EXT-X-DATERANGE和DASH的Event Stream信息，例如监听插播的元数据信息。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<[AVTimedMetaData](arkts-apis-media-i.md#avtimedmetadata)> | 是   | 回调函数，返回上报基于时间的元数据。|

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.onTimedMetaData((data: media.AVTimedMetaData) => {
  });
}
```

## offTimedMetaData

offTimedMetaData(callback?: Callback\<AVTimedMetaData>): void

取消注册监听器以检测基于时间的元数据。目前只支持HLS的#EXT-X-DATERANGE和DASH的Event Stream信息，例如取消监听插播的元数据信息。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<[AVTimedMetaData](arkts-apis-media-i.md#avtimedmetadata)> | 否   | 回调函数，返回上报基于时间的元数据。如果未填写该参数，则取消订阅该事件的所有回调函数。 |

**示例：**

```ts
async function test(){
  let avPlayer = await media.createAVPlayer();
  avPlayer.offTimedMetaData();
}
```

## getCurrentTrack

getCurrentTrack(trackType: MediaType): Promise\<number>

获取指定媒体类型的选定轨道。使用Promise异步回调。

只有当AVPlayer处于prepared、playing或者paused状态时，才能调用该接口。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| trackType | [MediaType](arkts-apis-media-e.md#mediatype8)| 是   | 媒体类型枚举，决定获取轨道索引的类型。<br>仅支持设置MEDIA_TYPE_AUD获取音频轨道索引、MEDIA_TYPE_VID获取视频轨道索引。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<number> | Promise对象，返回指定媒体类型选中轨道的索引值。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400101  | No memory. Return by promise.|
| 5400102  | Operation not allowed. Return by promise.|
| 5400103  | I/O error. Return by promise.|
| 5400105  | Service died. Return by promise.|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test(){
  let avPlayer = await media.createAVPlayer();
  // 此处仅为示意，实际开发中需要在stateChange事件成功触发至prepared/playing/paused状态后才能调用。
  let myTrackId : number;
  let trackType: media.MediaType = media.MediaType.MEDIA_TYPE_AUD;
  avPlayer.getCurrentTrack(trackType).then((trackId: number) => {
    console.info('Succeeded in getting CurrentTrack');
    myTrackId = trackId;
  }).catch((error: BusinessError) => {
    console.error(`Failed to get CurrentTrack.Code:${error.code},message:${error.message}`);
  });
}
```
