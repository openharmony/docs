# Functions
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(callback: AsyncCallback\<AVPlayer>): void

异步方式创建音视频播放实例，通过注册回调函数获取返回值。

> **说明：**
>
> - 推荐单个应用创建的音视频播放实例（即音频、视频、音视频三类相加）不超过16个。<!--Del-->
> - 可创建的音视频播放实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放实例。<!--DelEnd-->
> - 应用需要按照实际业务需求合理使用AVPlayer对象，按需创建并及时释放，避免持有过多AVPlayer实例导致内存消耗过大，否则在一定情况下可能导致系统终止应用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVPlayer](arkts-apis-media-AVPlayer.md)> | 是   | 回调函数。异步返回AVPlayer实例，失败时返回null。可用于音视频播放。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer;
media.createAVPlayer((error: BusinessError, video: media.AVPlayer) => {
  if (video != null) {
    avPlayer = video;
    console.info('Succeeded in creating AVPlayer');
  } else {
    console.error(`Failed to create AVPlayer, error message:${error.message}`);
  }
});
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(): Promise\<AVPlayer>

异步方式创建音视频播放实例。使用Promise异步回调。

> **说明：**
>
> - 推荐单个应用创建的音视频播放实例（即音频、视频、音视频三类相加）不超过16个。<!--Del-->
> - 可创建的音视频播放实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放实例。<!--DelEnd-->
> - 应用需要按照实际业务需求合理使用AVPlayer对象，按需创建并及时释放，避免持有过多AVPlayer实例导致内存消耗过大，否则在一定情况下可能导致系统终止应用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVPlayer](arkts-apis-media-AVPlayer.md)> | Promise对象。异步返回AVPlayer实例，失败时返回null。可用于音视频播放。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                      |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer;
media.createAVPlayer().then((video: media.AVPlayer) => {
  if (video != null) {
    avPlayer = video;
    console.info('Succeeded in creating AVPlayer');
  } else {
    console.error('Failed to create AVPlayer');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to create AVPlayer, error message:${error.message}`);
});
```

## media.createAVRecorder<sup>9+</sup>

createAVRecorder(callback: AsyncCallback\<AVRecorder>): void

异步方式创建音视频录制实例。通过注册回调函数获取返回值。

> **说明：**
>
> 应用可创建多个音视频录制实例，但由于设备共用音频通路，一个设备仅能有一个实例进行音频录制。创建第二个实例录制音频时，将会因为音频通路冲突导致创建失败。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                         |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVRecorder](arkts-apis-media-AVRecorder.md)> | 是   | 回调函数。异步返回AVRecorder实例，失败时返回null。可用于录制音视频媒体。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let avRecorder: media.AVRecorder;

media.createAVRecorder((error: BusinessError, recorder: media.AVRecorder) => {
  if (recorder != null) {
    avRecorder = recorder;
    console.info('Succeeded in creating AVRecorder');
  } else {
    console.error(`Failed to create AVRecorder, error message:${error.message}`);
  }
});
```

## media.createAVRecorder<sup>9+</sup>

createAVRecorder(): Promise\<AVRecorder>

异步方式创建音视频录制实例。通过Promise获取返回值。

> **说明：**
>
> 应用可创建多个音视频录制实例，但由于设备共用音频通路，一个设备仅能有一个实例进行音频录制。创建第二个实例录制音频时，将会因为音频通路冲突导致创建失败。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型                                 | 说明                                                         |
| ------------------------------------ | ------------------------------------------------------------ |
| Promise\<[AVRecorder](arkts-apis-media-AVRecorder.md)> | Promise对象。异步返回AVRecorder实例，失败时返回null。可用于录制音视频媒体。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                      |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let avRecorder: media.AVRecorder;
media.createAVRecorder().then((recorder: media.AVRecorder) => {
  if (recorder != null) {
    avRecorder = recorder;
    console.info('Succeeded in creating AVRecorder');
  } else {
    console.error('Failed to create AVRecorder');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to create AVRecorder, error message:${error.message}`);
});
```

## media.createAVTranscoder<sup>12+</sup>

createAVTranscoder(): Promise\<AVTranscoder>

异步方式创建视频转码实例，通过Promise获取返回值。

> **说明：**

> 可创建的视频转码实例不能超过2个。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVTranscoder](arkts-apis-media-AVTranscoder.md)> | Promise对象。异步返回AVTranscoder实例，失败时返回null。可用于视频转码。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                      |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avTranscoder: media.AVTranscoder | undefined = undefined;
media.createAVTranscoder().then((transcoder: media.AVTranscoder) => {
  if (transcoder != null) {
    avTranscoder = transcoder;
    console.info('Succeeded in creating AVTranscoder');
  } else {
    console.error('Failed to create AVTranscoder');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to create AVTranscoder, error message:${error.message}`);
});
```

## media.createAVMetadataExtractor<sup>11+</sup>

createAVMetadataExtractor(callback: AsyncCallback\<AVMetadataExtractor>): void

异步方式创建AVMetadataExtractor实例，通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVMetadataExtractor](arkts-apis-media-AVMetadataExtractor.md)> | 是   | 回调函数。当创建AVMetadataExtractor实例成功，err为undefined，data为获取到的AVMetadataExtractor实例，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Returned by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avMetadataExtractor: media.AVMetadataExtractor;
media.createAVMetadataExtractor((error: BusinessError, extractor: media.AVMetadataExtractor) => {
  if (extractor != null) {
    avMetadataExtractor = extractor;
    console.info('Succeeded in creating AVMetadataExtractor');
  } else {
    console.error(`Failed to create AVMetadataExtractor, error message:${error.message}`);
  }
});
```

## media.createAVMetadataExtractor<sup>11+</sup>

createAVMetadataExtractor(): Promise\<AVMetadataExtractor>

异步方式创建AVMetadataExtractor实例，通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**返回值：**

| 类型           | 说明                                     |
| -------------- | ---------------------------------------- |
| Promise\<[AVMetadataExtractor](arkts-apis-media-AVMetadataExtractor.md)>  | Promise对象。异步返回元数据获取类对象（AVMetadataExtractor）。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Returned by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avMetadataExtractor: media.AVMetadataExtractor;
media.createAVMetadataExtractor().then((extractor: media.AVMetadataExtractor) => {
  if (extractor != null) {
    avMetadataExtractor = extractor;
    console.info('Succeeded in creating AVMetadataExtractor');
  } else {
    console.error(`Failed to create AVMetadataExtractor`);
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to create AVMetadataExtractor, error message:${error.message}`);
});
```

## media.createSoundPool<sup>10+</sup>

createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo, callback: AsyncCallback\<SoundPool>): void

创建音频池实例，使用callback方式异步获取返回值。

> **说明：**
>
> - API 18以下版本，创建的SoundPool对象底层为单实例模式，一个应用进程只能够创建1个SoundPool实例。
> - API 18及API 18以上版本，创建的SoundPool对象底层为多实例模式，一个应用进程最多能够创建128个SoundPool实例。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                         |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| maxStreams | number | 是   | soundPool实例的最大播放的流数，设置范围为1-32的正整数。 |
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)  | 是   | 音频播放参数信息。其中audioRenderInfo中的参数usage取值为STREAM_USAGE_UNKNOWN，STREAM_USAGE_MUSIC，STREAM_USAGE_MOVIE，STREAM_USAGE_AUDIOBOOK时，SoundPool播放短音时为混音模式，不会打断其他音频播放。 |
| callback | AsyncCallback<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | 是   | 回调函数。异步返回SoundPool实例，失败时返回null。用于音频池实例的加载播放功能。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**示例：**

```js
import { audio } from '@kit.AudioKit';

let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
};

media.createSoundPool(5, audioRendererInfo, (error, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`Failed to createSoundPool`);
    return;
  } else {
    soundPool = soundPool_;
    console.info(`Succeeded in createSoundPool`);
  }
});
```

## media.createSoundPool<sup>10+</sup>

createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo): Promise\<SoundPool>

创建音频池实例，通过Promise获取返回值。

> **说明：**
>
> - API 18以下版本，创建的SoundPool对象底层为单实例模式，一个应用进程只能够创建1个SoundPool实例。
> - API 18及API 18以上版本，创建的SoundPool对象底层为多实例模式，一个应用进程最多能够创建128个SoundPool实例。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                         |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| maxStreams | number | 是   | soundPool实例的最大播放的流数，设置范围为1-32的正整数。 |
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)  | 是   | 音频播放参数信息 |

**返回值：**

| 类型                                      | 说明                                                         |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | Promise对象。异步返回SoundPool实例，失败时返回null。用于音频池实例的加载播放功能。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                      |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**示例：**

```js
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
};

media.createSoundPool(5, audioRendererInfo).then((soundpool_: media.SoundPool) => {
  if (soundpool_ != null) {
    soundPool = soundpool_;
    console.info('Succeeded in creating SoundPool');
  } else {
    console.error('Failed to create SoundPool');
  }
}, (error: BusinessError) => {
  console.error(`soundpool catchCallback, error message:${error.message}`);
});
```

## media.createAVScreenCaptureRecorder<sup>12+</sup>

createAVScreenCaptureRecorder(): Promise\<AVScreenCaptureRecorder>

创建屏幕录制实例，通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[AVScreenCaptureRecorder](arkts-apis-media-AVScreenCaptureRecorder.md)> | Promise对象。异步返回AVScreenCaptureRecorder实例，失败时返回null。可用于进行屏幕录制。 |

**错误码：**

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avScreenCaptureRecorder: media.AVScreenCaptureRecorder;
media.createAVScreenCaptureRecorder().then((captureRecorder: media.AVScreenCaptureRecorder) => {
  if (captureRecorder != null) {
    avScreenCaptureRecorder = captureRecorder;
    console.info('Succeeded in createAVScreenCaptureRecorder');
  } else {
    console.error('Failed to createAVScreenCaptureRecorder');
  }
}).catch((error: BusinessError) => {
  console.error(`createAVScreenCaptureRecorder catchCallback, error message:${error.message}`);
});
```

## media.createAVImageGenerator<sup>12+</sup>

createAVImageGenerator(callback: AsyncCallback\<AVImageGenerator>): void

创建AVImageGenerator实例，通过回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVImageGenerator](arkts-apis-media-AVImageGenerator.md)> | 是   | 回调函数。异步返回AVImageGenerator实例，失败时返回null。可用于获取视频缩略图。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Returned by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avImageGenerator: media.AVImageGenerator;
media.createAVImageGenerator((error: BusinessError, generator: media.AVImageGenerator) => {
  if (generator != null) {
    avImageGenerator = generator;
    console.info('Succeeded in creating AVImageGenerator');
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${error.message}`);
  }
});
```

## media.createAVImageGenerator<sup>12+</sup>

createAVImageGenerator(): Promise\<AVImageGenerator>

创建AVImageGenerator对象，通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVImageGenerator](arkts-apis-media-AVImageGenerator.md)> | Promise对象。异步返回AVImageGenerator实例，失败时返回null。可用于获取视频缩略图。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                      |
| -------- | ----------------------------- |
| 5400101  | No memory. Returned by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avImageGenerator: media.AVImageGenerator;
media.createAVImageGenerator().then((generator: media.AVImageGenerator) => {
  if (generator != null) {
    avImageGenerator = generator;
    console.info('Succeeded in creating AVImageGenerator');
  } else {
    console.error('Failed to creat AVImageGenerator');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to creat AVImageGenerator, error message:${error.message}`);
});
```

## media.createMediaSourceWithUrl<sup>12+</sup>

createMediaSourceWithUrl(url: string, headers?: Record\<string, string>): MediaSource

创建流媒体预下载媒体来源实例方法。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| url | string | 是   | - 流媒体预下载媒体来源url，支持的流媒体格式：HLS、HTTP-FLV、Dash、Https。<br> - 本地m3u8的fd路径。  |
| headers | Record\<string, string> | 否   | 支持流媒体预下载HttpHeader自定义。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| [MediaSource](arkts-apis-media-MediaSource.md) | MediaSource返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 5400101  | No memory.  |

**示例1：**

```ts
let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
```

**示例2：**

<!--code_no_check-->
```ts
import { media } from "@kit.MediaKit";

async function test(context: Context){
    // this.getUIContext().getHostContext();
    let mgr = context?.resourceManager;
    if (!mgr) {
        return;
    }
    let fileDescriptor = await mgr.getRawFd("xxx.m3u8");

    let fd: string = fileDescriptor.fd.toString();
    let offset: string = fileDescriptor.offset.toString();
    let length: string = fileDescriptor.length.toString();
    let fdUrl: string = "fd://" + fd + "?offset=" + offset + "&size=" + length;

    let mediaSource: media.MediaSource = media.createMediaSourceWithUrl(fdUrl);
}

```

## media.createMediaSourceWithStreamData<sup>19+</sup>

createMediaSourceWithStreamData(streams: Array\<MediaStream>): MediaSource

创建流媒体多码率媒体来源实例方法，当前仅支持HTTP-FLV协议格式多码率。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名  | 类型                                 | 必填 | 说明                                                  |
| ------- | ------------------------------------ | ---- | ----------------------------------------------------- |
| streams | Array<[MediaStream](arkts-apis-media-i.md#mediastream19)> | 是 | 可设置MediaStream数组，支持的流媒体格式：HTTP-FLV。 |

**返回值：**

| 类型                          | 说明                |
| ----------------------------- | ------------------- |
| [MediaSource](arkts-apis-media-MediaSource.md) | 返回MediaSource，用于媒体资源设置。 |

**示例：**

```ts
let streams : Array<media.MediaStream> = [];
streams.push({url: "http://xxx/480p.flv", width: 854, height: 480, bitrate: 800000});
streams.push({url: "http://xxx/720p.flv", width: 1280, height: 720, bitrate: 2000000});
streams.push({url: "http://xxx/1080p.flv", width: 1920, height: 1080, bitrate: 2000000});
let mediaSource : media.MediaSource = media.createMediaSourceWithStreamData(streams);
```

## media.createAudioPlayer<sup>(deprecated)</sup>

createAudioPlayer(): AudioPlayer

同步方式创建音频播放实例。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[createAVPlayer](#mediacreateavplayer9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**返回值：**

| 类型                        | 说明                                                         |
| --------------------------- | ------------------------------------------------------------ |
| [AudioPlayer](arkts-apis-media-AudioPlayer.md) | 返回AudioPlayer类实例，失败时返回null。可用于音频播放、暂停、停止等操作。 |

**示例：**

```ts
let audioPlayer: media.AudioPlayer = media.createAudioPlayer();
```

## media.createVideoPlayer<sup>(deprecated)</sup>

createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void

异步方式创建视频播放实例，通过注册回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[createAVPlayer](#mediacreateavplayer9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                                         |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[VideoPlayer](arkts-apis-media-VideoPlayer.md)> | 是   | 回调函数。创建VideoPlayer实例成功时，err为undefined，data为获取到的VideoPlayer实例，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
```

## media.createVideoPlayer<sup>(deprecated)</sup>

createVideoPlayer(): Promise\<VideoPlayer>

异步方式创建视频播放实例，通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[createAVPlayer](#mediacreateavplayer9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型                                 | 说明                                                         |
| ------------------------------------ | ------------------------------------------------------------ |
| Promise<[VideoPlayer](arkts-apis-media-VideoPlayer.md)> | Promise对象。异步返回VideoPlayer实例，失败时返回null。可用于管理和播放视频媒体。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer().then((video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error('Failed to create VideoPlayer');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to create VideoPlayer, error:${error}`);
});
```

## media.createAudioRecorder<sup>(deprecated)</sup>

createAudioRecorder(): AudioRecorder

创建音频录制的实例来控制音频的录制。
一台设备只允许创建一个录制实例。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[createAVRecorder](#mediacreateavrecorder9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**返回值:**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| [AudioRecorder](arkts-apis-media-AudioRecorder.md) | 返回AudioRecorder类实例，失败时返回null。可用于录制音频媒体。 |

**示例：**

```ts
let audioRecorder: media.AudioRecorder = media.createAudioRecorder();
```

