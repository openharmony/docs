# @ohos.multimedia.media (媒体服务)

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

媒体子系统为开发者提供一套简单且易于理解的接口，使得开发者能够方便接入系统并使用系统的媒体资源。

媒体子系统包含了音视频相关媒体业务，提供以下常用功能：

- 音视频播放（[AVPlayer](#avplayer9)<sup>9+</sup>）

- 音视频录制（[AVRecorder](#avrecorder9)<sup>9+</sup>）

- 视频转码（[AVTranscoder](#avtranscoder12)<sup>12+</sup>）

- 获取音视频元数据（[AVMetadataExtractor](#avmetadataextractor11)<sup>11+</sup>）

- 获取视频缩略图（[AVImageGenerator](#avimagegenerator12)<sup>12+</sup>）

- 屏幕录制（[AVScreenCaptureRecorder](#avscreencapturerecorder12)<sup>12+</sup>）

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

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVPlayer](#avplayer9)> | 是   | 回调函数。异步返回AVPlayer实例，失败时返回null。可用于音视频播放。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

异步方式创建音视频播放实例，通过Promise获取返回值。

> **说明：**
>
> - 推荐单个应用创建的音视频播放实例（即音频、视频、音视频三类相加）不超过16个。<!--Del-->
> - 可创建的音视频播放实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568推荐单个应用创建6个以内的音视频播放实例。<!--DelEnd-->

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVPlayer](#avplayer9)> | Promise对象。异步返回AVPlayer实例，失败时返回null。可用于音视频播放。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| callback | AsyncCallback\<[AVRecorder](#avrecorder9)> | 是   | 回调函数。异步返回AVRecorder实例，失败时返回null。可用于录制音视频媒体。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| Promise\<[AVRecorder](#avrecorder9)> | Promise对象。异步返回AVRecorder实例，失败时返回null。可用于录制音视频媒体。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| Promise\<[AVTranscoder](#avtranscoder12)> | Promise对象。异步返回AVTranscoder实例，失败时返回null。可用于视频转码。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| callback | AsyncCallback\<[AVMetadataExtractor](#avmetadataextractor11)> | 是   | 回调函数。当创建AVMetadataExtractor实例成功，err为undefined，data为获取到的AVMetadataExtractor实例，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| Promise\<[AVMetadataExtractor](#avmetadataextractor11)>  | Promise对象。异步返回元数据获取类对象（AVMetadataExtractor）。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/js-apis-audio.md#audiorendererinfo8)  | 是   | 音频播放参数信息。其中audioRenderInfo中的参数usage取值为STREAM_USAGE_UNKNOWN，STREAM_USAGE_MUSIC，STREAM_USAGE_MOVIE，STREAM_USAGE_AUDIOBOOK时，SoundPool播放短音时为混音模式，不会打断其他音频播放。 |
| callback | AsyncCallback<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | 是   | 回调函数。异步返回SoundPool实例，失败时返回null。用于音频池实例的加载播放功能。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/js-apis-audio.md#audiorendererinfo8)  | 是   | 音频播放参数信息 |

**返回值：**

| 类型                                      | 说明                                                         |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | Promise对象。异步返回SoundPool实例，失败时返回null。用于音频池实例的加载播放功能。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
    console.info('Succceeded in creating SoundPool');
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
| Promise\<[AVScreenCaptureRecorder](#avscreencapturerecorder12)> | Promise对象。异步返回AVScreenCaptureRecorder实例，失败时返回null。可用于进行屏幕录制。 |

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

## SoundPool<sup>10+</sup>

type SoundPool = _SoundPool

音频池，提供了系统声音的加载、播放、音量设置、循环设置、停止播放、资源卸载等功能。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

| 类型     | 说明                       |
| -------- | ------------------------------ |
| [_SoundPool](js-apis-inner-multimedia-soundPool.md#soundpool)  | 音频池，提供了系统声音的加载、播放、音量设置、循环设置、停止播放、资源卸载等功能。 |

## PlayParameters<sup>10+</sup>

type PlayParameters = _PlayParameters

表示音频池播放参数设置。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

| 类型     | 说明                       |
| -------- | ------------------------------ |
| [_PlayParameters](js-apis-inner-multimedia-soundPool.md#playparameters)  | 表示音频池播放参数设置。 |

## AVErrorCode<sup>9+</sup>

[媒体错误码](errorcode-media.md)类型枚举

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                                  | 值      | 说明                                 |
| :------------------------------------ | ------- | ------------------------------------ |
| AVERR_OK                              | 0       | 表示操作成功。                       |
| AVERR_NO_PERMISSION                   | 201     | 表示无权限执行此操作。               |
| AVERR_INVALID_PARAMETER               | 401     | 表示传入入参无效。                   |
| AVERR_UNSUPPORT_CAPABILITY            | 801     | 表示当前版本不支持该API能力。        |
| AVERR_NO_MEMORY                       | 5400101 | 表示系统内存不足或服务数量达到上限。 |
| AVERR_OPERATE_NOT_PERMIT              | 5400102 | 表示当前状态不允许或无权执行此操作。 |
| AVERR_IO                              | 5400103 | 表示数据流异常信息。                 |
| AVERR_TIMEOUT                         | 5400104 | 表示系统或网络响应超时。             |
| AVERR_SERVICE_DIED                    | 5400105 | 表示服务进程死亡。                   |
| AVERR_UNSUPPORT_FORMAT                | 5400106 | 表示不支持当前媒体资源的格式。       |
| AVERR_AUDIO_INTERRUPTED<sup>11+</sup> | 5400107 | 表示音频焦点被抢占                   |
| AVERR_IO_HOST_NOT_FOUND<sup>14+</sup> | 5411001 | 表示解析或链接服务端地址错误。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_CONNECTION_TIMEOUT<sup>14+</sup> | 5411002 | 表示网络连接超时。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_NETWORK_ABNORMAL<sup>14+</sup> | 5411003 | 表示网络异常导致的数据或链路异常。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_NETWORK_UNAVAILABLE<sup>14+</sup> | 5411004 | 表示网络被禁用。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_NO_PERMISSION<sup>14+</sup> | 5411005 | 表示无访问权限。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_REQUEST_DENIED<sup>14+</sup> | 5411006 | 表示客户端请求参数错误或超出处理能力。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_RESOURCE_NOT_FOUND<sup>14+</sup> | 5411007 | 表示无可用网络资源。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_SSL_CLIENT_CERT_NEEDED<sup>14+</sup> | 5411008 | 表示服务端校验客户端证书失败。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_SSL_CONNECTION_FAILED<sup>14+</sup> | 5411009 | 表示SSL连接失败。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_SSL_SERVER_CERT_UNTRUSTED<sup>14+</sup> | 5411010 | 表示客户端校验服务端证书失败。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_IO_UNSUPPORTED_REQUEST<sup>14+</sup> | 5411011 | 表示网络协议的原因导致请求不受支持。 <br> **原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。        |
| AVERR_SEEK_CONTINUOUS_UNSUPPORTED<sup>18+</sup> | 5410002 | 表示不支持SEEK_CONTINUOUS模式的seek。 <br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。        |
| AVERR_SUPER_RESOLUTION_UNSUPPORTED<sup>18+</sup> | 5410003 | 表示不支持超分。 <br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。        |
| AVERR_SUPER_RESOLUTION_NOT_ENABLED<sup>18+</sup> | 5410004 | 表示未使能超分。 <br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。        |

## MediaType<sup>8+</sup>

媒体类型枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称           | 值                    | 说明                 |
| -------------- | --------------------- | ------------------- |
| MEDIA_TYPE_AUD | 0                     | 表示音频。 <br> **原子化服务API：** 从API version 11 开始，该接口支持在原子化服务中使用。           |
| MEDIA_TYPE_VID | 1                     | 表示视频。  <br> **原子化服务API：** 从API version 11 开始，该接口支持在原子化服务中使用。          |
| MEDIA_TYPE_SUBTITLE<sup>12+</sup> | 2    | 表示字幕。 <br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |

## CodecMimeType<sup>8+</sup>

Codec MIME类型枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称         | 值                    | 说明                     |
| ------------ | --------------------- | ------------------------ |
| VIDEO_H263   | 'video/h263'          | 表示视频/h263类型。      |
| VIDEO_AVC    | 'video/avc'           | 表示视频/avc类型。       |
| VIDEO_MPEG2  | 'video/mpeg2'         | 表示视频/mpeg2类型。     |
| VIDEO_MPEG4  | 'video/mp4v-es'         | 表示视频/mpeg4类型。     |
| VIDEO_VP8    | 'video/x-vnd.on2.vp8' | 表示视频/vp8类型。       |
| VIDEO_HEVC<sup>11+</sup>   | 'video/hevc'          | 表示视频/H265类型。|
| AUDIO_AAC    | 'audio/mp4a-latm'     | 表示音频/mp4a-latm类型。 <br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |
| AUDIO_VORBIS | 'audio/vorbis'        | 表示音频/vorbis类型。    |
| AUDIO_FLAC   | 'audio/flac'          | 表示音频/flac类型。      |
| AUDIO_MP3<sup>12+</sup>   | 'audio/mpeg'          | 表示音频/mpeg类型。      |
| AUDIO_G711MU<sup>12+</sup>   | 'audio/g711mu'     | 表示音频/G711-mulaw类型。 |
| AUDIO_AMR_NB<sup>18+</sup>   | 'audio/3gpp'     | 表示音频/amr-nb类型。 |
| AUDIO_AMR_WB<sup>18+</sup>   | 'audio/amr-wb'     | 表示音频/amr-wb类型。 |

## MediaDescriptionKey<sup>8+</sup>

媒体信息描述枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                     | 值              | 说明                                                         |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | 'track_index'   | 表示轨道序号，其对应键值类型为number。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| MD_KEY_TRACK_TYPE        | 'track_type'    | 表示轨道类型，其对应键值类型为number，参考[MediaType](#mediatype8)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| MD_KEY_CODEC_MIME        | 'codec_mime'    | 表示codec_mime类型，其对应键值类型为string。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MD_KEY_DURATION          | 'duration'      | 表示媒体时长，其对应键值类型为number，单位为毫秒（ms）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MD_KEY_BITRATE           | 'bitrate'       | 表示比特率，其对应键值类型为number，单位为比特率（bps）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MD_KEY_WIDTH             | 'width'         | 表示视频宽度，其对应键值类型为number，单位为像素（px）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MD_KEY_HEIGHT            | 'height'        | 表示视频高度，其对应键值类型为number，单位为像素（px）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MD_KEY_FRAME_RATE        | 'frame_rate'    | 表示视频帧率，其对应键值类型为number，单位为每100秒的帧数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | 表示声道数，其对应键值类型为number。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MD_KEY_AUD_SAMPLE_RATE   | 'sample_rate'   | 表示采样率，其对应键值类型为number，单位为赫兹（Hz）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| MD_KEY_AUD_SAMPLE_DEPTH<sup>12+</sup>  | 'sample_depth'  | 表示位深，其对应键值类型为number，单位为位（bit）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| MD_KEY_LANGUAGE<sup>12+</sup>  | 'language'  | 表示字幕语言，其对应键值类型为string。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| MD_KEY_TRACK_NAME<sup>12+</sup>  | 'track_name'  | 表示track名称，其对应键值类型为string。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| MD_KEY_HDR_TYPE<sup>12+</sup>  | 'hdr_type'  | 表示视频轨类型，其对应键值类型为string。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

## PlaybackInfoKey<sup>12+</sup>

播放信息描述枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                     | 值              | 说明                                                         |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| SERVER_IP_ADDRESS        | 'server_ip_address'    | 表示服务器IP地址，其对应键值类型为string。  |
| AVG_DOWNLOAD_RATE        | 'average_download_rate'| 表示平均下载速率，其对应键值类型为number，单位为比特率（bps）。 |
| DOWNLOAD_RATE            | 'download_rate'        | 表示1s的下载速率，其对应键值类型为number，单位为比特率（bps）。|
| IS_DOWNLOADING           | 'is_downloading'       | 表示下载状态，1表示在下载状态，0表示非下载状态（下载完成），其对应键值类型为number。|
| BUFFER_DURATION          | 'buffer_duration'      | 表示缓存数据的可播放时长，其对应键值类型为number，单位为秒（s）。|

## BufferingInfoType<sup>8+</sup>

缓存事件类型枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称              | 值   | 说明                             |
| ----------------- | ---- | -------------------------------- |
| BUFFERING_START   | 1    | 表示开始缓冲。当上报BUFFERING_START时，播放器会暂停播放。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                   |
| BUFFERING_END     | 2    | 表示结束缓冲。当上报BUFFERING_END时，播放器会恢复播放。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                   |
| BUFFERING_PERCENT | 3    | 表示缓冲百分比。可参考该事件感知缓冲进度。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                 |
| CACHED_DURATION   | 4    |  表示已缓冲数据预估可播放时长，单位为毫秒（ms）。缓冲区中的数据变化量大于500ms，上报一次。可参考该事件做进度条。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |

## StateChangeReason<sup>9+</sup>

表示播放或录制实例状态机切换原因的枚举，伴随state一起上报。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称       | 值   | 说明                                                         |
| ---------- | ---- | ------------------------------------------------------------ |
| USER       | 1    | 表示用户行为造成的状态切换，由用户或客户端主动调用接口产生。 |
| BACKGROUND | 2    | 表示后台系统行为造成的状态切换，比如应用未注册播控中心权限，退到后台时被系统强制暂停或停止。 |

## AVPlayer<sup>9+</sup>

播放管理类，用于管理和播放媒体资源。在调用AVPlayer的方法前，需要先通过[createAVPlayer()](#mediacreateavplayer9)构建一个AVPlayer实例。

Audio/Video播放demo可参考：[音频播放开发指导](../../media/media/using-avplayer-for-playback.md)、[视频播放开发指导](../../media/media/video-playback.md)。

> **说明：**
>
> 在使用AVPlayer实例的方法时，建议开发者注册相关回调，主动获取当前状态变化。
> - [on('stateChange')](#onstatechange9)：监听播放状态机AVPlayerState切换。
> - [on('error')](#onerror9)：监听错误事件。

### 属性

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称                                                | 类型                                                         | 只读 | 可选 | 说明                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>9+</sup>                                    | string                                                       | 否   | 是   | 媒体URL，只允许在**idle**状态下设置。<br/>支持的视频格式(mp4、mpeg-ts、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac、amr)。<br/>**支持路径示例**：<br>1. fd类型播放：fd://xx。<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http\://xx。<br/>3. https网络播放: https\://xx。<br/>4. hls网络播放路径：http\://xx或者https\://xx。<br>**说明：**<br>- 设置网络播放路径，需[声明权限](../../security/AccessToken/declare-permissions.md)：[ohos.permission.INTERNET](../../security/AccessToken/permissions-for-all.md#ohospermissioninternet)，相关错误码: [201](../errorcode-universal.md)。<br>- 从API version 11开始不支持webm。<br> - 将资源句柄（fd）传递给 AVPlayer 实例之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个 AVPlayer / AVMetadataExtractor / AVImageGenerator / AVTranscoder。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致媒体播放器数据获取异常。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| fdSrc<sup>9+</sup>                                  | [AVFileDescriptor](#avfiledescriptor9)                       | 否   | 是   | 媒体文件描述，只允许在**idle**状态下设置。<br/>使用场景：应用中的媒体资源被连续存储在同一个文件中。<br/>支持的视频格式(mp4、mpeg-ts、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac、amr)。<br/>**使用示例**：<br/>假设一个连续存储的媒体文件: <br/>视频1(地址偏移:0，字节长度:100)；<br/>视频2(地址偏移:101，字节长度:50)；<br/>视频3(地址偏移:151，字节长度:150)；<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }。<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }。<br/>假设是一个独立的媒体文件: 请使用src=fd://xx。<br>**说明：**<br>从API version 11开始不支持webm。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| dataSrc<sup>10+</sup>                               | [AVDataSrcDescriptor](#avdatasrcdescriptor10)                | 否   | 是   | 流式媒体资源描述，只允许在**idle**状态下设置。<br/>使用场景：应用播放从远端下载到本地的文件，在应用未下载完整音视频资源时，提前播放已获取的资源文件。<br/>支持的视频格式(mp4、mpeg-ts、mkv)。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac、amr)。<br/>**使用示例**：<br/>假设用户正在从远端服务器获取音视频媒体文件，希望下载到本地的同时播放已经下载好的部分: <br/>1.用户需要获取媒体文件的总大小size（单位为字节），获取不到时设置为-1。<br/>2.用户需要实现回调函数func用于填写数据，如果size = -1，则func形式为：func(buffer: ArrayBuffer, length: number)，此时播放器只会按照顺序获取数据；否则func形式为：func(buffer: ArrayBuffer, length: number, pos: number)，播放器会按需跳转并获取数据。<br/>3.用户设置AVDataSrcDescriptor {fileSize = size, callback = func}。<br/>**注意事项**：<br/>如果播放的是mp4/m4a格式用户需要保证moov字段（媒体信息字段）在mdat字段（媒体数据字段）之前，或者moov之前的字段小于10M，否则会导致解析失败无法播放。<br>**说明：**<br>从API version 11开始不支持webm。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| surfaceId<sup>9+</sup>                              | string                                                       | 否   | 是   | 视频窗口ID，默认无窗口。<br/>支持在**initialized**状态下设置。<br/>支持在**prepared**/**playing**/**paused**/**completed**/**stopped**状态下重新设置，重新设置时确保已经在**initialized**状态下进行设置，否则重新设置失败，重新设置后视频播放在新的窗口渲染。<br/>使用场景：视频播放的窗口渲染，纯音频播放不用设置。<br/>**使用示例**：<br/>[通过XComponent创建surfaceId](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| loop<sup>9+</sup>                                   | boolean                                                      | 否   | 否   | 视频循环播放属性，默认'false'，设置为'true'表示循环播放，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。<br/>直播场景不支持loop设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| videoScaleType<sup>9+</sup>                         | [VideoScaleType](#videoscaletype9)                           | 否   | 是   | 视频缩放模式，默认VIDEO_SCALE_TYPE_FIT，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioInterruptMode<sup>9+</sup>                     | [audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9)       | 否   | 是   | 音频焦点模型，默认SHARE_MODE，动态属性。<br/>只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。<br/>在第一次调用[play()](#play9)之前设置， 以便此后中断模式生效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioRendererInfo<sup>10+</sup>                     | [audio.AudioRendererInfo](../apis-audio-kit/js-apis-audio.md#audiorendererinfo8) | 否   | 是   | 设置音频渲染信息。若媒体源包含视频，则usage默认值为STREAM_USAGE_MOVIE，否则usage默认值为STREAM_USAGE_MUSIC。rendererFlags默认值为0。若默认usage不满足需求，则须主动配置[audio.AudioRendererInfo](../apis-audio-kit/js-apis-audio.md#audiorendererinfo8)。<br/>只允许在**initialized**状态下设置。<br/>在第一次调用[prepare()](#prepare9)之前设置，以便音频渲染器信息在之后生效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| audioEffectMode<sup>10+</sup>                       | [audio.AudioEffectMode](../apis-audio-kit/js-apis-audio.md#audioeffectmode10)  | 否   | 是   | 设置音频音效模式，默认值为EFFECT_DEFAULT，动态属性。audioRendererInfo的usage变动时会恢复为默认值，只允许在**prepared**/**playing**/**paused**/**completed**状态下设置。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| state<sup>9+</sup>                                  | [AVPlayerState](#avplayerstate9)                             | 是   | 否   | 音视频播放的状态，全状态有效，可查询参数。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                  |
| currentTime<sup>9+</sup>                            | number                                                       | 是   | 否   | 视频的当前播放位置，单位为毫秒（ms），可查询参数。<br/>返回为(-1)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回(-1)。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| duration<sup>9+</sup> | number                                                       | 是   | 否   | 视频时长，单位为毫秒（ms），可查询参数。<br/>返回为(-1)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。<br/>直播场景默认返回(-1)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| width<sup>9+</sup>                                  | number                                                       | 是   | 否   | 视频宽，单位为像素（px），可查询参数。<br/>返回为(0)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| height<sup>9+</sup>                                 | number                                                       | 是   | 否   | 视频高，单位为像素（px），可查询参数。<br/>返回为(0)表示无效值，**prepared**/**playing**/**paused**/**completed**状态下有效。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

### on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: OnAVPlayerStateChangeHandle): void

监听播放状态机AVPlayerState切换的事件。

**原子化服务API：** 从API version 11 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |
| callback | [OnAVPlayerStateChangeHandle](#onavplayerstatechangehandle12) | 是   | 状态机切换事件回调方法。 |

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

### off('stateChange')<sup>9+</sup>

off(type: 'stateChange', callback?: OnAVPlayerStateChangeHandle): void

取消监听播放状态机[AVPlayerState](#avplayerstate9)切换的事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                  |
| ------ | ------ | ---- | ----------------------------------------------------- |
| type   | string | 是   | 状态机切换事件回调类型，取消注册的事件：'stateChange' |
| callback   | [OnAVPlayerStateChangeHandle](#onavplayerstatechangehandle12) | 否   | 状态机切换事件回调方法。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('stateChange');
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

监听[AVPlayer](#avplayer9)的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时[AVPlayerState](#avplayerstate9)也切至error状态，用户需要通过[reset()](#reset9)或者[release()](#release9)退出播放操作。

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

### off('error')<sup>9+</sup>

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

### setMediaSource<sup>12+</sup>

setMediaSource(src:MediaSource, strategy?: PlaybackStrategy): Promise\<void>

流媒体预下载资源设置，下载url对应的流媒体数据，并暂存在内存中。[视频播放开发指导](../../media/media/video-playback.md)。通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| src | [MediaSource](#mediasource12) | 是   | 流媒体预下载媒体来源。 |
| strategy | [PlaybackStrategy](#playbackstrategy12) | 否   | 流媒体预下载播放策略。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### setPlaybackStrategy<sup>12+</sup>

setPlaybackStrategy(strategy: PlaybackStrategy): Promise\<void>

设置播放策略，只能在initialized状态下调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| strategy | [PlaybackStrategy](#playbackstrategy12) | 是   | 播放策略。 |

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### setPlaybackRange<sup>18+</sup>

setPlaybackRange(startTimeMs: number, endTimeMs: number, mode?: SeekMode) : Promise\<void>

设置播放区间，并通过指定的[SeekMode](#seekmode8)跳转到区间开始位置。设置之后，只播放音视频文件设定区间内的内容。该方法异步方式返回执行结果，通过Promise获取返回值。可在**initialized**/**prepared**/**paused**/**stopped**/**completed**状态下使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| startTimeMs | number | 是   | 区间开始位置，单位ms，取值[0, duration)。可以设置-1值，系统将会从0位置开始播放。|
| endTimeMs | number | 是   | 区间结束位置，单位ms，取值(startTimeMs, duration]。可以设置-1值，系统将会播放到资源末尾。|
| mode | [SeekMode](#seekmode8) | 否   | 支持SeekMode.SEEK_PREV_SYNC和SeekMode.SEEK_CLOSEST, <br/>默认值: SeekMode.SEEK_PREV_SYNC。|

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### prepare<sup>9+</sup>

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

### prepare<sup>9+</sup>

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

### setMediaMuted<sup>12+</sup>

setMediaMuted(mediaType: MediaType,  muted: boolean ): Promise\<void>

设置音频静音/取消音频静音。只能在prepared/playing/paused/completed状态下调用。仅支持设置mediaType为音频格式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| mediaType | [MediaType](#mediatype8) | 是   | 播放策略。 |
| muted | boolean | 是   | 是否静音播放。true表示是静音播放，false表示不是静音播放。|

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

### play<sup>9+</sup>

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

### play<sup>9+</sup>

play(): Promise\<void>

开始播放音视频资源，只能在prepared/paused/completed状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 开始播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

暂停播放音视频资源，只能在playing状态调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 暂停播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### pause<sup>9+</sup>

pause(): Promise\<void>

暂停播放音视频资源，只能在playing状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 暂停播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

停止播放音视频资源，只能在prepared/playing/paused/completed状态调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 停止播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### stop<sup>9+</sup>

stop(): Promise\<void>

停止播放音视频资源，只能在prepared/playing/paused/completed状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 停止播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

重置播放，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 重置播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### reset<sup>9+</sup>

reset(): Promise\<void>

重置播放，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 重置播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

销毁播放资源，除released状态外，均可以调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 销毁播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### release<sup>9+</sup>

release(): Promise\<void>

销毁播放资源，除released状态，都可以调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 销毁播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### getTrackDescription<sup>9+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

获取音视频轨道信息，可以在prepared/playing/paused状态调用。获取所有音视轨道信息，应在数据加载回调后调用。使用callback方式异步获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | 是   | 回调函数，当获取音视频轨道信息成功，err为undefined，data为获取到的MediaDescription数组；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### getTrackDescription<sup>9+</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

获取音视频轨道信息，可以在prepared/playing/paused状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise对象，返回音视频轨道信息MediaDescription数组。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### getSelectedTracks<sup>12+</sup>

getSelectedTracks(): Promise\<Array\<number>>

获取已选择的音视频轨道索引，可以在prepared/playing/paused状态调用。通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise\<Array\<number>> | Promise对象，返回已选择音视频轨道索引数组。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

### getPlaybackInfo<sup>12+</sup>

getPlaybackInfo(): Promise\<PlaybackInfo>

获取播放过程信息，可以在prepared/playing/paused状态调用。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<[PlaybackInfo](#playbackinfo12)> | Promise对象，返回播放器信息PlaybackInfo。 |

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

### getPlaybackPosition<sup>18+</sup>

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

### selectTrack<sup>12+</sup>

selectTrack(index: number, mode?: SwitchMode): Promise\<void>

使用AVPlayer播放多音视频轨资源时，选择指定轨道播放，通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| index | number | 是   | 多音视频资源的轨道索引，可通过[getTrackDescription](#gettrackdescription9-1)接口获取当前资源的所有轨道信息[MediaDescription](#mediadescription8)。 |
| mode   | [SwitchMode](#switchmode12) | 否   | 切换视频轨道模式，默认为SMOOTH模式，**仅在DASH协议网络流视频轨切换时生效**，其他场景当前暂不支持。 |

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

### deselectTrack<sup>12+</sup>

deselectTrack(index: number): Promise\<void>

使用AVPlayer播放多音轨视频时取消指定音视频轨道播放，通过Promise获取返回值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| index | number | 是   | 多音视频资源的轨道索引，来自[getTrackDescription](#gettrackdescription9-1)接口所获取的轨道信息[MediaDescription](#mediadescription8)。 |

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

### setDecryptionConfig<sup>11+</sup>

setDecryptionConfig(mediaKeySession: drm.MediaKeySession, secureVideoPath: boolean): void

设置解密配置。当收到[mediaKeySystemInfoUpdate事件](#onmediakeysysteminfoupdate11)时，需根据事件上报的信息创建相关配置并设置解密配置，否则无法播放。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| mediaKeySession | [drm.MediaKeySession](../apis-drm-kit/js-apis-drm.md#mediakeysession) | 是   | 解密会话 |
| secureVideoPath | boolean | 是 | 安全视频通路，true表示选择安全视频通路，false表示选择非安全视频通路 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

关于drm模块的示例具体可见[js-apis-drm.md](../apis-drm-kit/js-apis-drm.md)。
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

### getMediaKeySystemInfos<sup>11+</sup>

getMediaKeySystemInfos(): Array\<drm.MediaKeySystemInfo>

获取当前播放的媒体资源的MediaKeySystemInfo。需要在[mediaKeySystemInfoUpdate事件](#onmediakeysysteminfoupdate11)触发成功后才能调用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
|  Array<[drm.MediaKeySystemInfo](../apis-drm-kit/js-apis-drm.md#mediakeysysteminfo)> | MediaKeySystemInfo数组，MediaKeySystemInfo具有uuid和pssh两个属性。 |

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

### seek<sup>9+</sup>

seek(timeMs: number, mode?:SeekMode): void

跳转到指定播放位置，只能在prepared/playing/paused/completed状态调用，可以通过[seekDone事件](#onseekdone9)确认是否生效。
注：直播场景不支持seek。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, [duration](#属性)]。SEEK_CONTINUOU模式可以额外取值-1，用于表示SEEK_CONTINUOUS模式结束。 |
| mode   | [SeekMode](#seekmode8) | 否   | 基于视频I帧的跳转模式，默认为SEEK_PREV_SYNC模式，**仅在视频资源播放时设置**。 |

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

### isSeekContinuousSupported<sup>18+</sup>

isSeekContinuousSupported() : boolean

查询媒体源是否支持以SEEK_CONTINUOUS模式[SeekMode](#seekmode8)进行[seek](#seek9)，在prepared/playing/paused/completed状态调用返回实际值，其余状态调用返回false。对于不支持SEEK_CONTINUOUS模式进行seek的设备，返回false。

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

### on('seekDone')<sup>9+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

监听seek生效的事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | seek生效的事件回调类型，支持的事件：'seekDone'，除SEEK_CONTINUOUS外的[SeekMode](#seekmode8)每次调用seek后都会回调此事件。 |
| callback | Callback\<number> | 是   | 回调函数。seek生效的事件回调方法，只会上报用户请求的time位置。<br/>**视频播放：**[SeekMode](#seekmode8)会造成实际跳转位置与用户设置产生偏差，精准位置需要通过currentTime获取，事件回调的time仅代表完成用户某一次请求。 |

**示例：**

```ts
avPlayer.on('seekDone', (seekDoneTime:number) => {
  console.info('seekDone called,and seek time is:' + seekDoneTime);
});
```

### off('seekDone')<sup>9+</sup>

off(type: 'seekDone', callback?: Callback\<number>): void

取消监听seek生效的事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                 |
| ------ | ------ | ---- | ---------------------------------------------------- |
| type   | string | 是   | seek生效的事件回调类型，取消注册的事件：'seekDone'。 |
| callback | Callback\<number> | 否   | 回调函数。seek生效的事件回调方法，只会上报用户请求的time位置。<br/>**视频播放：**[SeekMode](#seekmode8)会造成实际跳转位置与用户设置产生偏差，精准位置需要通过currentTime获取，事件回调的time仅代表完成用户某一次请求。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('seekDone');
```

### setSpeed<sup>9+</sup>

setSpeed(speed: PlaybackSpeed): void

设置倍速模式，只能在prepared/playing/paused/completed状态调用，可以通过[speedDone事件](#onspeeddone9)确认是否生效。
注：直播场景不支持setSpeed。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                             | 必填 | 说明               |
| ------ | -------------------------------- | ---- | ------------------ |
| speed  | [PlaybackSpeed](#playbackspeed8) | 是   | 指定播放倍速模式。 |

**示例：**

```ts
avPlayer.setSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X);
```

### on('speedDone')<sup>9+</sup>

on(type: 'speedDone', callback: Callback\<number>): void

监听setSpeed生效的事件

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | setSpeed生效的事件回调类型，支持的事件：'speedDone'，每次调用setSpeed后都会回调此事件。 |
| callback | Callback\<number> | 是   | 回调函数。当setSpeed成功，上报生效的倍速模式，具体见[PlaybackSpeed](#playbackspeed8)。 |

**示例：**

```ts
avPlayer.on('speedDone', (speed:number) => {
  console.info('speedDone called,and speed value is:' + speed);
});
```

### off('speedDone')<sup>9+</sup>

off(type: 'speedDone', callback?: Callback\<number>): void

取消监听setSpeed生效的事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                      |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | 是   | setSpeed生效的事件回调类型，取消注册的事件：'speedDone'。 |
| callback | Callback\<number> | 否   | 回调函数。当setSpeed成功，上报生效的倍速模式，具体见[PlaybackSpeed](#playbackspeed8)。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avPlayer.off('speedDone');
```


### setPlaybackRate<sup>20+</sup>

setPlaybackRate(rate: number): void

设置倍速模式。只能在prepared/playing/paused/completed状态调用，取值范围是[0.125, 4.0]，可以通过[playbackRateDone](#onplaybackratedone20)事件确认是否生效。<br>
>**注意：**
>
>直播场景不支持setPlaybackRate。

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


### on('playbackRateDone')<sup>20+</sup>

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

### off('playbackRateDone')<sup>20+</sup>

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


### setBitrate<sup>9+</sup>

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

### on('bitrateDone')<sup>9+</sup>

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

### off('bitrateDone')<sup>9+</sup>

off(type: 'bitrateDone', callback?: Callback\<number>): void

取消监听setBitrate生效的事件。

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

### on('availableBitrates')<sup>9+</sup>

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

### off('availableBitrates')<sup>9+</sup>

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


### on('mediaKeySystemInfoUpdate')<sup>11+</sup>

on(type: 'mediaKeySystemInfoUpdate', callback: Callback\<Array\<drm.MediaKeySystemInfo>>): void

监听mediaKeySystemInfoUpdate事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 版权保护信息更新上报事件回调类型，支持的事件：'mediaKeySystemInfoUpdate'，当播放内容的版权保护信息更新时上报事件。 |
| callback | Callback\<Array\<drm.[MediaKeySystemInfo](../apis-drm-kit/js-apis-drm.md#mediakeysysteminfo)>> | 是   | 版权保护信息更新上报事件回调方法，上报MediaKeySystemInfo数组。 |

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

### off('mediaKeySystemInfoUpdate')<sup>11+</sup>

off(type: 'mediaKeySystemInfoUpdate', callback?: Callback\<Array\<drm.MediaKeySystemInfo>>): void;

取消监听mediaKeySystemInfoUpdate事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 版权保护信息更新上报事件回调类型，取消注册的事件：'mediaKeySystemInfoUpdate'。 |
| callback | Callback\<Array\<drm.[MediaKeySystemInfo](../apis-drm-kit/js-apis-drm.md#mediakeysysteminfo)>> | 否   | 版权保护信息更新上报事件回调方法，上报版权保护信息数组。如填写该参数，则仅取消注册此回调方法，否则取消注册mediaKeySystemInfoUpdate事件的所有回调方法。 |

**示例：**

```ts
avPlayer.off('mediaKeySystemInfoUpdate');
```

### setVolume<sup>9+</sup>

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

### on('volumeChange')<sup>9+</sup>

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

### off('volumeChange')<sup>9+</sup>

off(type: 'volumeChange', callback?: Callback\<number>): void

取消监听setVolume生效的事件。

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

### on('endOfStream')<sup>9+</sup>

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

### off('endOfStream')<sup>9+</sup>

off(type: 'endOfStream', callback?: Callback\<void>): void

取消监听资源播放至结尾的事件。

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

### on('timeUpdate')<sup>9+</sup>

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

### off('timeUpdate')<sup>9+</sup>

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

### on('durationUpdate')<sup>9+</sup>


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

### off('durationUpdate')<sup>9+</sup>

off(type: 'durationUpdate', callback?: Callback\<number>): void

取消监听资源播放资源的时长。

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

### on('bufferingUpdate')<sup>9+</sup>

on(type: 'bufferingUpdate', callback: OnBufferingUpdateHandler): void

订阅音视频缓存更新事件，仅网络播放支持该订阅事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 播放缓存事件回调类型，支持的事件：'bufferingUpdate'。        |
| callback | [OnBufferingUpdateHandler](#onbufferingupdatehandler12) | 是   | 播放缓存事件回调方法。 |

**示例：**

```ts
avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('bufferingUpdate called,and infoType value is:' + infoType + ', value is :' + value);
});
```

### off('bufferingUpdate')<sup>9+</sup>

off(type: 'bufferingUpdate', callback?: OnBufferingUpdateHandler): void

取消监听音视频缓存更新事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                      |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | 是   | 播放缓存事件回调类型，取消注册的事件：'bufferingUpdate'。 |
| callback | [OnBufferingUpdateHandler](#onbufferingupdatehandler12) | 否   | 播放缓存事件回调方法。 |

**示例：**

```ts
avPlayer.off('bufferingUpdate');
```

### on('startRenderFrame')<sup>9+</sup>

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

### off('startRenderFrame')<sup>9+</sup>

off(type: 'startRenderFrame', callback?: Callback\<void>): void

取消监听视频播放开始首帧渲染的更新事件。

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

### on('videoSizeChange')<sup>9+</sup>

on(type: 'videoSizeChange', callback: OnVideoSizeChangeHandler): void

监听视频播放宽高变化事件，仅视频播放支持该订阅事件，默认只在prepared状态上报一次，但HLS协议码流会在切换分辨率时上报。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频播放宽高变化事件回调类型，支持的事件：'videoSizeChange'。 |
| callback | [OnVideoSizeChangeHandler](#onvideosizechangehandler12) | 是   | 视频播放宽高变化事件回调方法。    |

**示例：**

```ts
avPlayer.on('videoSizeChange', (width: number, height: number) => {
  console.info('videoSizeChange called,and width is:' + width + ', height is :' + height);
});
```

### off('videoSizeChange')<sup>9+</sup>

off(type: 'videoSizeChange', callback?: OnVideoSizeChangeHandler): void

取消监听视频播放宽高变化事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 视频播放宽高变化事件回调类型，取消注册的事件：'videoSizeChange'。 |
| callback | [OnVideoSizeChangeHandler](#onvideosizechangehandler12) | 否   | 视频播放宽高变化事件回调方法。<br/>从API version 12开始支持此参数。    |

**示例：**

```ts
avPlayer.off('videoSizeChange');
```

### on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void

监听音频焦点变化事件，多个音视频资源同时播放时，会根据音频焦点模型[audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9)触发此事件。应用需根据不同焦点变化事件作相应处理。具体可参考[处理音频焦点事件](../../media/audio/audio-playback-concurrency.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'。 |
| callback | Callback\<[audio.InterruptEvent](../apis-audio-kit/js-apis-audio.md#interruptevent9)> | 是   | 音频焦点变化事件回调方法。                           |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

avPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt called,and InterruptEvent info is:' + info);
});
```

### off('audioInterrupt')<sup>9+</sup>

off(type: 'audioInterrupt', callback?: Callback<audio.InterruptEvent>): void

取消监听音频焦点变化事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 音频焦点变化事件回调类型，取消注册的事件：'audioInterrupt'。 |
| callback | Callback\<[audio.InterruptEvent](../apis-audio-kit/js-apis-audio.md#interruptevent9)> | 否   | 音频焦点变化事件回调方法。<br/>从API version 12开始支持此参数。             |

**示例：**

```ts
avPlayer.off('audioInterrupt');
```

### on('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

on(type: 'audioOutputDeviceChangeWithInfo', callback: Callback\<audio.AudioStreamDeviceChangeInfo>): void

订阅监听音频流输出设备变化及原因，使用callback方式返回结果。

在订阅此监听时，建议参考[响应音频流输出设备变更](../../media/audio/audio-output-device-change.md)自行实现设备连接或者断开时的播放器行为。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'audioOutputDeviceChangeWithInfo'。 |
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/js-apis-audio.md#audiostreamdevicechangeinfo11)> | 是   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。 |

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

### off('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

off(type: 'audioOutputDeviceChangeWithInfo', callback?: Callback\<audio.AudioStreamDeviceChangeInfo>): void

取消订阅监听音频流输出设备变化及原因，使用callback方式返回结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'audioOutputDeviceChangeWithInfo'。 |
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/js-apis-audio.md#audiostreamdevicechangeinfo11)> | 否   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。 |

**错误码：**

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |

**示例：**

```ts
avPlayer.off('audioOutputDeviceChangeWithInfo');
```

### addSubtitleFromFd<sup>12+</sup>

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

### addSubtitleFromUrl<sup>12+</sup>

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

### on('subtitleUpdate')<sup>12+</sup>

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

### off('subtitleUpdate')<sup>12+</sup>

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

### on('trackChange')<sup>12+</sup>

on(type: 'trackChange', callback: OnTrackChangeHandler): void

订阅获取轨道变更的事件，当播放的轨道变更时，会通过订阅的回调方法通知用户。用户只能订阅一个轨道变更事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackChange'。 |
| callback | [OnTrackChangeHandler](#ontrackchangehandler12) | 是   | 轨道变更事件回调方法。 |

**示例：**

```ts
avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
  console.info('trackChange info: index=' + index + ' isSelect=' + isSelect);
});
```

### off('trackChange')<sup>12+</sup>

off(type: 'trackChange', callback?: OnTrackChangeHandler): void

取消订阅获取轨道变更的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackChange'。 |
| callback | [OnTrackChangeHandler](#ontrackchangehandler12) | 否   | 取消轨道变更事件的回调方法。 |

**示例：**

```ts
avPlayer.off('trackChange');
```

### on('trackInfoUpdate')<sup>12+</sup>

on(type: 'trackInfoUpdate', callback: Callback\<Array\<MediaDescription>>): void

订阅获取轨道信息更新的事件，当播放的轨道有更新时，会通过订阅的回调方法通知用户。用户只能订阅一个轨道变更事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackInfoUpdate'。 |
| callback | Callback\<Array\<[MediaDescription](#mediadescription8)>> | 是   | 轨道信息更新事件回调方法。 |

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

### off('trackInfoUpdate')<sup>12+</sup>

off(type: 'trackInfoUpdate', callback?: Callback\<Array\<MediaDescription>>): void

取消订阅获取轨道变更的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | 是   | 事件回调类型，支持的事件为：'trackInfoUpdate'。 |
| callback | Callback\<Array\<[MediaDescription](#mediadescription8)>> | 否   | 取消轨道信息更新事件的回调方法。 |

**示例：**

```ts
avPlayer.off('trackInfoUpdate');
```

### on('amplitudeUpdate')<sup>13+</sup>

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

### off('amplitudeUpdate')<sup>13+</sup>

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

### on('seiMessageReceived')<sup>18+</sup>

on(type: 'seiMessageReceived', payloadTypes: Array\<number>, callback: OnSeiMessageHandle): void

订阅获取SEI信息事件，仅适用于HTTP-FLV直播，视频流中包含SEI信息时上报。需在prepare之前订阅，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | 是 | 事件回调类型，支持的事件为：'seiMessageReceived'。 |
| payloadTypes | Array\<number> | 是 | SEI信息的订阅负载类型数组。当前仅支持负载类型为5，即payloadType = 5。|
| callback | [OnSeiMessageHandle](#onseimessagehandle18) | 是 | 用于监听SEI信息事件的回调函数，接收订阅的负载类型。 |

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

### off('seiMessageReceived')<sup>18+</sup>

off(type: 'seiMessageReceived', payloadTypes?: Array\<number>, callback?: OnSeiMessageHandle): void

取消订阅获取SEI信息事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件回调类型，支持的事件为：'seiMessageReceived'。 |
| payloadTypes | Array\<number> | 否   | SEI信息的订阅负载类型。 |
| callback | [OnSeiMessageHandle](#onseimessagehandle18) | 否   | 用于监听SEI信息事件的回调函数，接收订阅的负载类型。 |

**示例：**

```ts
avPlayer.off('seiMessageReceived');
```

### setSuperResolution<sup>18+</sup>

setSuperResolution(enabled: boolean) : Promise\<void>

动态开启/关闭超分算法，可以在 'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped' 状态调用。使用Promise方式返回结果。

在调用[prepare()](#prepare9)前先通过[PlaybackStrategy](#playbackstrategy12)使能超分。

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
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](#playbackstrategy12). Return by promise. |

**示例：**

```ts
avPlayer.setSuperResolution(true);
```

### setVideoWindowSize<sup>18+</sup>

setVideoWindowSize(width: number, height: number) : Promise\<void>

动态设置超分算法的输出分辨率，可以在 'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped' 状态调用。使用Promise方式返回结果。输入参数须在 320x320 ~ 1920x1080 范围内，单位为像素。

在调用[prepare()](#prepare9)前先通过[PlaybackStrategy](#playbackstrategy12)使能超分。

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
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](#playbackstrategy12). Return by promise. |

**示例：**

```ts
avPlayer.setVideoWindowSize(1920, 1080);
```

### on('superResolutionChanged')<sup>18+</sup>

on(type:'superResolutionChanged', callback: OnSuperResolutionChanged): void

订阅监听超分算法开启/关闭事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | 是 | 事件回调类型，支持的事件为：'superResolutionChanged'，当超分算法开启/关闭状态变化时，触发该事件。 |
| callback | [OnSuperResolutionChanged](#onsuperresolutionchanged-18) | 是 | 超分开关事件回调方法。 |

**示例：**

```ts
avPlayer.on('superResolutionChanged', (enabled: boolean) => {
  console.info('superResolutionChanged called, and enabled is:' + enabled);
});
```

### off('superResolutionChanged')<sup>18+</sup>

off(type:'superResolutionChanged', callback?: OnSuperResolutionChanged): void

取消监听超分算法开启/关闭事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | 是 | 事件回调类型，支持的事件为：'superResolutionChanged'，当超分算法开启/关闭状态变化时，触发该事件。 |
| callback | [OnSuperResolutionChanged](#onsuperresolutionchanged-18) | 否 | 超分开关事件回调方法。 |

**示例：**

```ts
avPlayer.off('superResolutionChanged');
```

## AVPlayerState<sup>9+</sup>

type AVPlayerState = 'idle' | 'initialized' | 'prepared' | 'playing' | 'paused' | 'completed' | 'stopped' | 'released' | 'error'

[AVPlayer](#avplayer9)的状态机，可通过state属性主动获取当前状态，也可通过监听[stateChange](#onstatechange9)事件上报当前状态，状态机之间的切换规则，可参考[音频播放开发指导](../../media/media/using-avplayer-for-playback.md)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

|              类型               | 说明                                                         |
| :-----------------------------: | :----------------------------------------------------------- |
|              'idle'               | 闲置状态，AVPlayer刚被创建[createAVPlayer()](#mediacreateavplayer9)或者调用了[reset()](#reset9)方法之后，进入idle状态。<br/>首次创建[createAVPlayer()](#mediacreateavplayer9)，所有属性都为默认值。<br/>调用[reset()](#reset9)方法，url<sup>9+</sup> 或 fdSrc<sup>9+</sup>或dataSrc<sup>10+</sup>属性及loop属性会被重置，其他用户设置的属性将被保留。 |
|           'initialized'           | 资源初始化，在idle 状态设置 url<sup>9+</sup> 或 fdSrc<sup>9+</sup>属性，AVPlayer会进入initialized状态，此时可以配置窗口、音频等静态属性。 |
|            'prepared'             | 已准备状态，在initialized状态调用[prepare()](#prepare9)方法，AVPlayer会进入prepared状态，此时播放引擎的资源已准备就绪。 |
|             'playing'             | 正在播放状态，在prepared/paused/completed状态调用[play()](#play9)方法，AVPlayer会进入playing状态。 |
|             'paused'              | 暂停状态，在playing状态调用pause方法，AVPlayer会进入paused状态。 |
|            'completed'            | 播放至结尾状态，当媒体资源播放至结尾时，如果用户未设置循环播放（loop = true），AVPlayer会进入completed状态，此时调用[play()](#play9)会进入playing状态和重播，调用[stop()](#stop9)会进入stopped状态。 |
|             'stopped'             | 停止状态，在prepared/playing/paused/completed状态调用[stop()](#stop9)方法，AVPlayer会进入stopped状态，此时播放引擎只会保留属性，但会释放内存资源，可以调用[prepare()](#prepare9)重新准备，也可以调用[reset()](#reset9)重置，或者调用[release()](#release9)彻底销毁。 |
|            'released'             | 销毁状态，销毁与当前AVPlayer关联的播放引擎，无法再进行状态转换，调用[release()](#release9)方法后，会进入released状态，结束流程。 |
| 'error' | 错误状态，当**播放引擎**发生**不可逆的错误**（详见[媒体错误码](errorcode-media.md)），则会转换至当前状态，可以调用[reset()](#reset9)重置，也可以调用[release()](#release9)销毁重建。<br/>**注意：** 区分error状态和 [on('error')](#onerror9) ：<br/>1、进入error状态时，会触发on('error')监听事件，可以通过on('error')事件获取详细错误信息；<br/>2、处于error状态时，播放服务进入不可播控的状态，要求客户端设计容错机制，使用[reset()](#reset9)重置或者[release()](#release9)销毁重建；<br/>3、如果客户端收到on('error')，但未进入error状态：<br/>原因1：客户端未按状态机调用API或传入参数错误，被AVPlayer拦截提醒，需要客户端调整代码逻辑；<br/>原因2：播放过程发现码流问题，导致容器、解码短暂异常，不影响连续播放和播控操作的，不需要客户端设计容错机制。 |

## OnTrackChangeHandler<sup>12+</sup>

type OnTrackChangeHandler = (index: number, isSelected: boolean) => void

track变更事件回调方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 参数名   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ------ | ---------------------------------------------------------- |
| index  | number | 是 | 当前变更的track索引。     |
| isSelected | boolean | 是 | 当前变更的track索引是否被选中。true表示处于选中状态，false表示处于非选中状态。 |

## OnAVPlayerStateChangeHandle<sup>12+</sup>

type OnAVPlayerStateChangeHandle = (state: AVPlayerState, reason: StateChangeReason) => void

状态机切换事件回调方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 参数名   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ------ | ---------------------------------------------------------- |
| state  | [AVPlayerState](#avplayerstate9) | 是 | 当前播放状态。     |
| reason | [StateChangeReason](#statechangereason9) | 是 | 当前播放状态的切换原因。 |

## OnBufferingUpdateHandler<sup>12+</sup>

type OnBufferingUpdateHandler = (infoType: BufferingInfoType, value: number) => void

播放缓存事件回调方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 参数名   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| infoType  | [BufferingInfoType](#bufferinginfotype8) | 是 | 缓存时间类型。     |
| value | number | 是 | value值固定为0。 |

## OnVideoSizeChangeHandler<sup>12+</sup>

type OnVideoSizeChangeHandler = (width: number, height: number) => void

视频播放宽高变化事件回调方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 参数名   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| width  | number | 是 | 视频宽度，单位为像素（px）。|
| height | number | 是 | 视频高度，单位为像素（px）。|

## OnSeiMessageHandle<sup>18+</sup>

type OnSeiMessageHandle = (messages: Array\<SeiMessage>, playbackPosition?: number) => void

获取SEI信息，使用场景：订阅SEI信息事件，回调返回SEI详细信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   |   类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| messages | Array\<[SeiMessage](#seimessage18)> | 是  | SEI信息。 |
| playbackPosition | number | 否  | 获取当前播放位置（单位：毫秒）。 |

## OnSuperResolutionChanged <sup>18+</sup>

type OnSuperResolutionChanged = (enabled: boolean) => void

视频超分开关事件回调方法。若通过[PlaybackStrategy](#playbackstrategy12)正确使能超分，超分算法状态变化时会通过此回调上报，视频起播时也会上报超分初始开启/关闭状态。若未使能超分，不会触发该回调。

出现以下两种情况，超分算法会自动关闭。
* 目前超分算法最高仅支持30帧及以下的视频。若视频帧率超过30帧，或者在倍速播放等场景下导致输入帧率超出超分算法处理能力，超分会自动关闭。
* 目前超分算法支持输入分辨率范围为320x320 ~ 1920x1080，单位为像素。若播放过程中输入视频分辨率超出此范围，超分算法会自动关闭。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 参数名   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| enabled  | boolean | 是 | 表示当前超分是否开启。true表示超分开启，false表示超分关闭。     |

## OnPlaybackRateDone<sup>20+</sup>

type OnPlaybackRateDone = (rate: number) => void

播放速率设置完成事件回调方法。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 参数名   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| rate | number | 是 | 播放速率。 |

## AVFileDescriptor<sup>9+</sup>

音视频文件资源描述，一种特殊资源的播放方式，使用场景：应用中的音频资源被连续存储在同一个文件中，需要根据偏移量和长度进行播放。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | 是   | 资源句柄，通过[resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9)获取,也可以通过[fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen)获取。    |
| offset | number | 否   | 资源偏移量，默认值为0，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |
| length | number | 否   | 资源长度，默认值为文件中从偏移量开始的剩余字节，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |

## AVDataSrcDescriptor<sup>10+</sup>

音视频文件资源描述，用于DataSource播放方式，使用场景：应用在未获取完整音视频资源时，允许用户创建播放实例并开始播放，达到提前播放的目的。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fileSize     | number | 是   | 待播放文件大小（字节），-1代表大小未知。如果fileSize设置为-1, 播放模式类似于直播，不能进行seek及setSpeed操作，不能设置loop属性，因此不能重新播放。 |
| callback | (buffer: ArrayBuffer, length: number, pos?: number) => number | 是   | 用户设置的回调函数，用于填写数据。<br>- 函数列式：callback: (buffer: ArrayBuffer, length: number, pos?:number) => number;<br>- buffer，ArrayBuffer类型，表示被填写的内存，必选。<br>- length，number类型，表示被填写内存的最大长度，必选。<br>- pos，number类型，表示填写的数据在资源文件中的位置，可选，当fileSize设置为-1时，该参数禁止被使用。 <br>- 返回值，number类型，返回填充数据的长度，返回-1表示到达流的末尾，返回-2表示遇到不可恢复的错误。|

## SubtitleInfo<sup>12+</sup>

外挂字幕信息，使用场景：订阅外挂字幕事件，回调返回外挂字幕详细信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| text | string | 否  | 字幕文本信息。 |
| startTime | number | 否  | 显示当前字幕文本的开始时间（单位：毫秒）。 |
| duration | number | 否 | 显示当前字幕文本的持续时间（单位：毫秒）。 |

## SeiMessage<sup>18+</sup>

SEI信息内容，描述SEI信息的负载类型和数据。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 只读 | 可选  | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| payloadType | number | 否  | 否  | SEI信息的负载类型。 |
| payload | ArrayBuffer | 否  | 否  | SEI信息的负载数据。 |

## SeekMode<sup>8+</sup>

视频播放的Seek模式枚举，可通过seek方法作为参数传递下去。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称           | 值   | 说明                                                         |
| -------------- | ---- | ------------------------------------------------------------ |
| SEEK_NEXT_SYNC | 0    | 表示跳转到指定时间点的下一个关键帧，建议向后快进的时候用这个枚举值。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| SEEK_PREV_SYNC | 1    | 表示跳转到指定时间点的上一个关键帧，建议向前快进的时候用这个枚举值。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| SEEK_CLOSEST<sup>12+</sup> | 2    | 表示跳转到距离指定时间点最近的帧，建议精准跳转进度的时候用这个枚举值。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SEEK_CONTINUOUS<sup>18+</sup> | 3    | 该模式提供了一种画面平滑流畅变化的Seek体验，应用可以结合进度条控件持续调用Seek方法，AVPlayer根据Seek调用持续流畅地更新画面。<br>应用可以调用[isSeekContinuousSupported](#isseekcontinuoussupported18)方法根据返回结果感知视频源是否支持该模式Seek。<br>对于不支持该Seek模式的视频源调用该模式Seek时，会上报AVERR_SEEK_CONTINUOUS_UNSUPPORTED错误([媒体错误码](#averrorcode9))，同时画面更新的流畅性会降低。<br>该Seek模式不会触发[seekDone事件](#onseekdone9)。<br>当应用需要退出该模式下的Seek时，需要调用`seek(-1, SeekMode.SEEK_CONTINUOUS)`来结束该模式下的Seek。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |

## SwitchMode<sup>12+</sup>

视频播放的selectTrack模式枚举，可通过selectTrack方法作为参数传递下去，当前仅DASH协议视频轨支持该扩展参数。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称           | 值   | 说明                                                         |
| -------------- | ---- | ------------------------------------------------------------ |
| SMOOTH | 0    | 表示切换后视频平滑播放，该模式切换存在延迟，不会立即生效。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SEGMENT | 1    | 表示切换后从当前分片开始位置播放，该模式立即切换，会有重复播放。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| CLOSEST | 2    | 表示从距离当前播放时间点最近的帧开始播放，该模式立即切换，切换后会卡住3到5s，然后恢复播放。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## PlaybackSpeed<sup>8+</sup>

视频播放的倍速枚举，可通过setSpeed方法作为参数传递下去。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称                 | 值   | 说明                           |
| -------------------- | ---- | ------------------------------ |
| SPEED_FORWARD_0_75_X | 0    | 表示视频播放正常播速的0.75倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_1_00_X | 1    | 表示视频播放正常播速。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。         |
| SPEED_FORWARD_1_25_X | 2    | 表示视频播放正常播速的1.25倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_1_75_X | 3    | 表示视频播放正常播速的1.75倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_2_00_X | 4    | 表示视频播放正常播速的2.00倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_0_50_X<sup>12+</sup> | 5    | 表示视频播放正常播速的0.50倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_1_50_X<sup>12+</sup> | 6    | 表示视频播放正常播速的1.50倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_3_00_X<sup>13+</sup> | 7    | 表示视频播放正常播速的3.00倍。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_0_25_X<sup>12+</sup> | 8    | 表示视频播放正常播速的0.25倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEED_FORWARD_0_125_X<sup>12+</sup> | 9    | 表示视频播放正常播速的0.125倍。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## VideoScaleType<sup>9+</sup>

枚举，视频缩放模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称                        | 值   | 说明                                              |
| ----------------------------| ---- | ------------------------------------------------ |
| VIDEO_SCALE_TYPE_FIT        | 0    | 默认比例类型，视频拉伸至与窗口等大。                |
| VIDEO_SCALE_TYPE_FIT_CROP   | 1    | 保持视频宽高比缩放至最短边填满窗口，长边超出窗口部分被裁剪。     |
| VIDEO_SCALE_TYPE_FIT_ASPECT<sup>20+</sup> | 2    | 保持视频宽高比缩放至长边填满窗口，短边居中对齐，未填满部分留黑。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。  |

## MediaDescription<sup>8+</sup>

通过key-value方式获取媒体信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称          | 类型   | 必填 | 说明                                                         |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| [key: string] | Object | 是   | 该键值对支持的key取值范围，请参考[MediaDescriptionKey](#mediadescriptionkey8);每个key值的Object类型和范围，请参考[MediaDescriptionKey](#mediadescriptionkey8)对应Key值的说明 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function printfItemDescription(obj: media.MediaDescription, key: string) {
  let property: Object = obj[key];
  console.info('audio key is ' + key); // 通过key值获取对应的value。key值具体可见[MediaDescriptionKey]。
  console.info('audio value is ' + property); //对应key值得value。其类型可为任意类型，具体key对应value的类型可参考[MediaDescriptionKey]。
}

let avPlayer: media.AVPlayer | undefined = undefined;
media.createAVPlayer((err: BusinessError, player: media.AVPlayer) => {
  if(player != null) {
    avPlayer = player;
    console.info(`Succeeded in creating AVPlayer`);
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          printfItemDescription(arrList[i], media.MediaDescriptionKey.MD_KEY_TRACK_TYPE);  //打印出每条轨道MD_KEY_TRACK_TYPE的值。
        }
      } else {
        console.error(`Failed to get TrackDescription, error:${error}`);
      }
    });
  } else {
    console.error(`Failed to create AVPlayer, error message:${err.message}`);
  }
});
```

## PlaybackInfo<sup>12+</sup>

通过key-value方式获取播放信息。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称          | 类型   | 必填 | 说明                                                         |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| [key: string] | Object | 是   | 该键值对支持的key取值范围，请参考[PlaybackInfoKey](#playbackinfokey12);每个key值的Object类型和范围，请参考[PlaybackInfoKey](#playbackinfokey12)对应Key值的说明。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function printfPlaybackInfo(obj: media.PlaybackInfo, key: string) {
  let property: Object = obj[key];
  console.info('key is ' + key); // 通过key值获取对应的value。key值具体可见[PlaybackInfoKey]。
  console.info('value is ' + property); //对应key值得value。其类型可为任意类型，具体key对应value的类型可参考[PlaybackInfoKey]。
}

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
        printfPlaybackInfo(playbackInfo, media.PlaybackInfoKey.SERVER_IP_ADDRESS); // 打印ip的值。
      } catch (error) {
        console.error(`error = ${error}`);
      }
    }
  } else {
    console.error(`Failed to create AVPlayer, error message:${err.message}`);
  }
});
```

## AVRecorder<sup>9+</sup>

音视频录制管理类，用于音视频媒体录制。在调用AVRecorder的方法前，需要先通过[createAVRecorder()](#mediacreateavrecorder9)构建一个AVRecorder实例。

音视频录制demo可参考：[音频录制开发指导](../../media/media/using-avrecorder-for-recording.md)、[视频录制开发指导](../../media/media/video-recording.md)。

> **说明：**
>
> 使用相机进行视频录制时，需要与相机模块配合，相机模块接口的使用详情见[相机管理](../apis-camera-kit/arkts-apis-camera.md)。

### 属性

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称    | 类型                                 | 只读 | 可选 | 说明               |
| ------- | ------------------------------------ | ---- | ---- | ------------------ |
| state9+ | [AVRecorderState](#avrecorderstate9) | 是   | 否   | 音视频录制的状态。<br>**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |

### prepare<sup>9+</sup>

prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void

异步方式进行音视频录制的参数设置。通过注册回调函数获取返回值。

**需要权限：** ohos.permission.MICROPHONE

不涉及音频录制时，可以不需要获取ohos.permission.MICROPHONE权限。

使用相机视频录制还需要与相机模块配合，相机模块接口的使用详情见[相机管理](../apis-camera-kit/arkts-apis-camera.md)。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                  |
| -------- | -------------------------------------- | ---- | ------------------------------------- |
| config   | [AVRecorderConfig](#avrecorderconfig9) | 是   | 配置音视频录制的相关参数。            |
| callback | AsyncCallback\<void>                   | 是   | 回调函数。当prepare方法成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 201      | Permission denied. Return by callback.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |
| 5400102  | Operate not permit. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 配置参数以实际硬件设备支持的范围为准。
let avRecorderProfile: media.AVRecorderProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : media.CodecMimeType.AUDIO_AAC,
  audioSampleRate : 48000,
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,
  videoBitrate : 2000000,
  videoCodec : media.CodecMimeType.VIDEO_AVC,
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
};
let avRecorderConfig: media.AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : avRecorderProfile,
  url : 'fd://', // 文件需先由调用者创建，赋予读写权限，将文件fd传给此参数，eg.fd://45
  rotation : 0, // 合理值0、90、180、270，非合理值prepare接口将报错。
  location : { latitude : 30, longitude : 130 }
};

avRecorder.prepare(avRecorderConfig, (err: BusinessError) => {
  if (err) {
    console.error('Failed to prepare and error is ' + err.message);
  } else {
    console.info('Succeeded in preparing');
  }
});
```

### prepare<sup>9+</sup>

prepare(config: AVRecorderConfig): Promise\<void>

异步方式进行音视频录制的参数设置。通过Promise获取返回值。

**需要权限：** ohos.permission.MICROPHONE

不涉及音频录制时，可以不需要获ohos.permission.MICROPHONE权限。

使用相机视频录制还需要与相机模块配合，相机模块接口的使用详情见[相机管理](../apis-camera-kit/arkts-apis-camera.md)。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| config | [AVRecorderConfig](#avrecorderconfig9) | 是   | 配置音视频录制的相关参数。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | 异步音视频录制prepare方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201      | Permission denied. Return by promise.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |
| 5400102  | Operate not permit. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 配置参数以实际硬件设备支持的范围为准。
let avRecorderProfile: media.AVRecorderProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : media.CodecMimeType.AUDIO_AAC,
  audioSampleRate : 48000,
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,
  videoBitrate : 2000000,
  videoCodec : media.CodecMimeType.VIDEO_AVC,
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
};
let avRecorderConfig: media.AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : avRecorderProfile,
  url : 'fd://',  // 文件需先由调用者创建，赋予读写权限，将文件fd传给此参数，eg.fd://45
  rotation : 0, // 合理值0、90、180、270，非合理值prepare接口报错。
  location : { latitude : 30, longitude : 130 }
};

avRecorder.prepare(avRecorderConfig).then(() => {
  console.info('Succeeded in preparing');
}).catch((err: BusinessError) => {
  console.error('Failed to prepare and catch error is ' + err.message);
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(callback: AsyncCallback\<string>): void

异步方式获得录制需要的surface。通过注册回调函数获取返回值。此surface提供给调用者，调用者从此surface中获取surfaceBuffer，填入相应的视频数据。

应当注意，填入的视频数据需要携带时间戳（单位ns）和buffersize。时间戳的起始时间请以系统启动时间为基准。

需在[prepare()](#prepare9-2)事件成功触发后，才能调用getInputSurface()方法。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | 是   | 回调函数。当获取surface成功，err为undefined，data为获取到的surfaceId，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let surfaceID: string; // 该surfaceID用于传递给相机接口创造videoOutput。

avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
  if (err) {
    console.error('Failed to do getInputSurface and error is ' + err.message);
  } else {
    console.info('Succeeded in doing getInputSurface');
    surfaceID = surfaceId;
  }
});

```

### getInputSurface<sup>9+</sup>

getInputSurface(): Promise\<string>

异步方式获得录制需要的surface。通过Promise获取返回值。此surface提供给调用者，调用者从此surface中获取surfaceBuffer，填入相应的视频数据。

应当注意，填入的视频数据需要携带时间戳（单位ns）和buffersize。时间戳的起始时间请以系统启动时间为基准。

需在[prepare()](#prepare9-3)事件成功触发后，才能调用getInputSurface方法。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<string> | 异步获得surface的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let surfaceID: string; // 该surfaceID用于传递给相机接口创造videoOutput。

avRecorder.getInputSurface().then((surfaceId: string) => {
  console.info('Succeeded in getting InputSurface');
  surfaceID = surfaceId;
}).catch((err: BusinessError) => {
  console.error('Failed to get InputSurface and catch error is ' + err.message);
});
```

### updateRotation<sup>12+</sup>

updateRotation(rotation: number): Promise\<void>

更新视频旋转角度。通过Promise获取返回值。

当且仅当[prepare()](#prepare9-3)事件成功触发后，且在[start()](#start9)之前，才能调用updateRotation方法。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                        |
| -------- | -------------------- | ---- | --------------------------- |
| rotation | number | 是   | 旋转角度，取值仅支持0、90、180、270度。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 异步返回函数执行结果。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
|   401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.   |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rotation = 90;

avRecorder.updateRotation(rotation).then(() => {
  console.info('Succeeded in updateRotation');
}).catch((err: BusinessError) => {
  console.error('Failed to updateRotation and catch error is ' + err.message);
});
```

### setWillMuteWhenInterrupted<sup>20+</sup>

setWillMuteWhenInterrupted(muteWhenInterrupted: boolean): Promise&lt;void&gt;

设置当前录制音频流是否启用静音打断模式。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名     | 类型             | 必填   | 说明                                                      |
| ---------- |---------------- | ------ |---------------------------------------------------------|
| muteWhenInterrupted | boolean | 是  | 设置当前录制音频流是否启用静音打断模式, true表示启用，false表示不启用，保持为默认打断模式。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt;| Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.setWillMuteWhenInterrupted(true).then(() => {
  console.info('setWillMuteWhenInterrupted Success!');
}).catch((err: BusinessError) => {
  console.error(`setWillMuteWhenInterrupted Fail: ${err}`);
});
```

### start<sup>9+</sup>

start(callback: AsyncCallback\<void>): void

异步方式开始视频录制。通过注册回调函数获取返回值。

纯音频录制需在[prepare()](#prepare9-2)事件成功触发后，才能调用start方法。纯视频录制，音视频录制需在[getInputSurface()](#getinputsurface9)事件成功触发后，才能调用start方法。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   |回调函数。当开始录制视频成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.start((err: BusinessError) => {
  if (err) {
    console.error('Failed to start AVRecorder and error is ' + err.message);
  } else {
    console.info('Succeeded in starting AVRecorder');
  }
});
```

### start<sup>9+</sup>

start(): Promise\<void>

异步方式开始视频录制。通过Promise获取返回值。

纯音频录制需在[prepare()](#prepare9-3)事件成功触发后，才能调用start方法。纯视频录制，音视频录制需在[getInputSurface()](#getinputsurface9-1)事件成功触发后，才能调用start方法。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步开始视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.start().then(() => {
  console.info('Succeeded in starting AVRecorder');
}).catch((err: BusinessError) => {
  console.error('Failed to start AVRecorder and catch error is ' + err.message);
});
```

### pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

异步方式暂停视频录制。通过注册回调函数获取返回值。

需要[start()](#start9)事件成功触发后，才能调用pause方法，可以通过调用[resume()](#resume9)接口来恢复录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                        |
| -------- | -------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当暂停视频录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.pause((err: BusinessError) => {
  if (err) {
    console.error('Failed to pause AVRecorder and error is ' + err.message);
  } else {
    console.info('Succeeded in pausing');
  }
});
```

### pause<sup>9+</sup>

pause(): Promise\<void>

异步方式暂停视频录制。通过Promise获取返回值。

需要[start()](#start9-1)事件成功触发后，才能调用pause方法，可以通过调用[resume()](#resume9-1)接口来恢复录制。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步暂停视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.pause().then(() => {
  console.info('Succeeded in pausing');
}).catch((err: BusinessError) => {
  console.error('Failed to pause AVRecorder and catch error is ' + err.message);
});
```

### resume<sup>9+</sup>

resume(callback: AsyncCallback\<void>): void

异步方式恢复视频录制。通过注册回调函数获取返回值。

需要在[pause()](#pause9-2)事件成功触发后，才能调用resume方法。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当恢复视频录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.resume((err: BusinessError) => {
  if (err) {
    console.error('Failed to resume AVRecorder and error is ' + err.message);
  } else {
    console.info('Succeeded in resuming AVRecorder');
  }
});
```

### resume<sup>9+</sup>

resume(): Promise\<void>

异步方式恢复视频录制。通过Promise获取返回值。

需要在[pause()](#pause9-3)事件成功触发后，才能调用resume方法。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步恢复视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.resume().then(() => {
  console.info('Succeeded in resuming AVRecorder');
}).catch((err: BusinessError) => {
  console.error('Failed to resume  AVRecorder failed and catch error is ' + err.message);
});
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

异步方式停止视频录制。通过注册回调函数获取返回值。

需要在[start()](#start9)或[pause()](#pause9-2)事件成功触发后，才能调用stop方法。

纯音频录制时，需要重新调用[prepare()](#prepare9-2)接口才能重新录制。纯视频录制，音视频录制时，需要重新调用[prepare()](#prepare9-2)和[getInputSurface()](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当停止视频录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.stop((err: BusinessError) => {
  if (err) {
    console.error('Failed to stop AVRecorder and error is ' + err.message);
  } else {
    console.info('Succeeded in stopping AVRecorder');
  }
});
```

### stop<sup>9+</sup>

stop(): Promise\<void>

异步方式停止视频录制。通过Promise获取返回值。

需要在[start()](#start9-1)或[pause()](#pause9-3)事件成功触发后，才能调用stop方法。

纯音频录制时，需要重新调用[prepare()](#prepare9-3)接口才能重新录制。纯视频录制，音视频录制时，需要重新调用[prepare()](#prepare9-3)和[getInputSurface()](#getinputsurface9-1)接口才能重新录制。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步停止视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.stop().then(() => {
  console.info('Succeeded in stopping AVRecorder');
}).catch((err: BusinessError) => {
  console.error('Failed to stop AVRecorder and catch error is ' + err.message);
});
```

### reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

异步方式重置音视频录制。通过注册回调函数获取返回值。

纯音频录制时，需要重新调用[prepare()](#prepare9-2)接口才能重新录制。纯视频录制，音视频录制时，需要重新调用[prepare()](#prepare9-2)和[getInputSurface()](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当重置音视频录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.reset((err: BusinessError) => {
  if (err) {
    console.error('Failed to reset AVRecorder and error is ' + err.message);
  } else {
    console.info('Succeeded in resetting AVRecorder');
  }
});
```

### reset<sup>9+</sup>

reset(): Promise\<void>

异步方式重置音视频录制。通过Promise获取返回值。

纯音频录制时，需要重新调用[prepare()](#prepare9-3)接口才能重新录制。纯视频录制，音视频录制时，需要重新调用[prepare()](#prepare9-3)和[getInputSurface()](#getinputsurface9-1)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                    |
| -------------- | --------------------------------------- |
| Promise\<void> | 异步重置音视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.reset().then(() => {
  console.info('Succeeded in resetting AVRecorder');
}).catch((err: BusinessError) => {
  console.error('Failed to reset and catch error is ' + err.message);
});
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

异步方式释放音视频录制资源。通过注册回调函数获取返回值。

释放音视频录制资源之后，该AVRecorder实例不能再进行任何操作。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当释放音视频录制资源成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.release((err: BusinessError) => {
  if (err) {
    console.error('Failed to release AVRecorder and error is ' + err.message);
  } else {
    console.info('Succeeded in releasing AVRecorder');
  }
});
```

### release<sup>9+</sup>

release(): Promise\<void>

异步方式释放音视频录制资源。通过Promise获取返回值。

释放音视频录制资源之后，该AVRecorder实例不能再进行任何操作。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                        |
| -------------- | ------------------------------------------- |
| Promise\<void> | 异步释放音视频录制资源方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.release().then(() => {
  console.info('Succeeded in releasing AVRecorder');
}).catch((err: BusinessError) => {
  console.error('Failed to release AVRecorder and catch error is ' + err.message);
});
```

### getCurrentAudioCapturerInfo<sup>11+</sup>

getCurrentAudioCapturerInfo(callback: AsyncCallback\<audio.AudioCapturerChangeInfo>): void

异步方式获取当前音频采集参数。通过注册回调函数获取返回值。

在prepare()成功触发后，才能调用此方法。在stop()成功触发后，调用此方法会报错。

**系统能力**：SystemCapability.Multimedia.Media.AVRecorder

**参数**：

| 参数名   | 类型                                                         | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback\<[audio.AudioCapturerChangeInfo](../apis-audio-kit/js-apis-audio.md#audiocapturerchangeinfo9)> | 是   | 回调函数。当获取音频采集参数成功时，err为undefined，data为获取到的audio.AudioCapturerChangeInfo，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. |
| 5400103  | I/O error.             |
| 5400105  | Service died. Return by callback.          |

**示例**：

```ts
import { audio } from '@kit.AudioKit';

let currentCapturerInfo: audio.AudioCapturerChangeInfo;

avRecorder.getCurrentAudioCapturerInfo((err: BusinessError, capturerInfo: audio.AudioCapturerChangeInfo) => {
  if (err) {
    console.error('Failed to get CurrentAudioCapturerInfo and error is ' + err.message);
  } else {
    console.info('Succeeded in getting CurrentAudioCapturerInfo');
    currentCapturerInfo = capturerInfo;
  }
});
```

### getCurrentAudioCapturerInfo<sup>11+</sup>

getCurrentAudioCapturerInfo(): Promise\<audio.AudioCapturerChangeInfo>

异步方式获取当前音频采集参数。通过Promise获取返回值。

在prepare()成功触发后，才能调用此方法。在stop()成功触发后，调用此方法会报错。

**系统能力**：SystemCapability.Multimedia.Media.AVRecorder

**返回值**：

| 类型                                                         | 说明                                              |
| ------------------------------------------------------------ | ------------------------------------------------- |
| Promise\<[audio.AudioCapturerChangeInfo](../apis-audio-kit/js-apis-audio.md#audiocapturerchangeinfo9)> | Promise对象，返回获取的当前音频采集参数。 |

**错误码**：

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400103  | I/O error.                       |
| 5400105  | Service died. Return by promise. |

**示例**：

```ts
import { audio } from '@kit.AudioKit';

let currentCapturerInfo: audio.AudioCapturerChangeInfo;

avRecorder.getCurrentAudioCapturerInfo().then((capturerInfo: audio.AudioCapturerChangeInfo) => {
  console.info('Succeeded in getting CurrentAudioCapturerInfo');
  currentCapturerInfo = capturerInfo;
}).catch((err: BusinessError) => {
  console.error('Failed to get CurrentAudioCapturerInfo and catch error is ' + err.message);
});
```

### getAudioCapturerMaxAmplitude<sup>11+</sup>

getAudioCapturerMaxAmplitude(callback: AsyncCallback\<number>): void

异步方式获取当前音频最大振幅。通过注册回调函数获取返回值。

在prepare()成功触发后，才能调用此方法。在stop()成功触发后，调用此方法会报错。

调用接口时，获取到的返回值是上一次获取最大振幅的时刻到当前这段区间内的音频最大振幅。即，如果在1s的时刻获取了一次最大振幅，在2s时再获取到的最大振幅时1-2s这个区间里面的最大值。

**系统能力**：SystemCapability.Multimedia.Media.AVRecorder

**参数**：

| 参数名   | 类型                   | 必填 | 说明                                 |
| -------- | ---------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<number> | 是   |  回调函数。获取当前音频最大振幅成功时，err为undefined，data为获取到的最大振幅，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. |
| 5400105  | Service died. Return by callback.          |

**示例**：

```ts
let maxAmplitude: number;

avRecorder.getAudioCapturerMaxAmplitude((err: BusinessError, amplitude: number) => {
  if (err) {
    console.error('Failed to get AudioCapturerMaxAmplitude and error is ' + err.message);
  } else {
    console.info('Succeeded in getting AudioCapturerMaxAmplitude');
    maxAmplitude = amplitude;
  }
});
```

### getAudioCapturerMaxAmplitude<sup>11+</sup>

getAudioCapturerMaxAmplitude(): Promise\<number>

异步方式获取当前音频最大振幅参数。通过Promise获取返回值。

在prepare()成功触发后，才能调用此方法。在stop()成功触发后，调用此方法会报错。

调用接口时，获取到的返回值是上一次获取最大振幅的时刻到当前这段区间内的音频最大振幅。即，如果在1s的时刻获取了一次最大振幅，在2s时再获取到的最大振幅时1-2s这个区间里面的最大值。

**系统能力**：SystemCapability.Multimedia.Media.AVRecorder

**返回值**：

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------- |
| Promise\<number> | Promise对象，返回获取的当前音频最大振幅。 |

**错误码**：

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400105  | Service died. Return by promise. |

**示例**：

```ts
let maxAmplitude: number;

avRecorder.getAudioCapturerMaxAmplitude().then((amplitude: number) => {
  console.info('Succeeded in getting AudioCapturerMaxAmplitude');
  maxAmplitude = amplitude;
}).catch((err: BusinessError) => {
  console.error('Failed to get AudioCapturerMaxAmplitude and catch error is ' + err.message);
});
```

### getAvailableEncoder<sup>11+</sup>

getAvailableEncoder(callback: AsyncCallback\<Array\<EncoderInfo>>): void

异步方式获取可用的编码器参数。通过注册回调函数获取返回值。

**系统能力**：SystemCapability.Multimedia.Media.AVRecorder

**参数**：

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<Array\<[EncoderInfo](#encoderinfo11)>> | 是   | 回调函数。获取可用的编码器参数成功时，err为undefined，data为获取到的编码器参数，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. |
| 5400105  | Service died. Return by callback.          |

**示例**：

```ts
let encoderInfo: media.EncoderInfo;

avRecorder.getAvailableEncoder((err: BusinessError, info: media.EncoderInfo[]) => {
  if (err) {
    console.error('Failed to get AvailableEncoder and error is ' + err.message);
  } else {
    console.info('Succeeded in getting AvailableEncoder');
    encoderInfo = info[0];
  }
});
```

### getAvailableEncoder<sup>11+</sup>

getAvailableEncoder(): Promise\<Array\<EncoderInfo>>

异步方式获取可用的编码器参数。通过注册回调函数获取返回值。

**系统能力**：SystemCapability.Multimedia.Media.AVRecorder

**返回值**：

| 类型                                            | 说明                                            |
| ----------------------------------------------- | ----------------------------------------------- |
| Promise\<Array\<[EncoderInfo](#encoderinfo11)>> | Promise对象，返回获取的可用的编码器参数。 |

**错误码**：

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400105  | Service died. Return by promise. |

**示例**：

```ts
let encoderInfo: media.EncoderInfo;

avRecorder.getAvailableEncoder().then((info: media.EncoderInfo[]) => {
  console.info('Succeeded in getting AvailableEncoder');
  encoderInfo = info[0];
}).catch((err: BusinessError) => {
  console.error('Failed to get AvailableEncoder and catch error is ' + err.message);
});
```

### getAVRecorderConfig<sup>11+</sup>

getAVRecorderConfig(callback: AsyncCallback\<AVRecorderConfig>): void

异步方式获取实时的配置参数。通过注册回调函数获取返回值。

只能在[prepare()](#prepare9-2)接口调用后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<[AVRecorderConfig](#avrecorderconfig9)> | 是   | 回调函数。获取实时配置的参数成功时，err为undefined，data为获取到的配置参数，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avConfig: media.AVRecorderConfig;

avRecorder.getAVRecorderConfig((err: BusinessError, config: media.AVRecorderConfig) => {
  if (err) {
    console.error('Failed to get avConfig and error is ' + err.message);
  } else {
    console.info('Succeeded in getting AVRecorderConfig');
    avConfig = config;
  }
});
```

### getAVRecorderConfig<sup>11+</sup>

getAVRecorderConfig(): Promise\<AVRecorderConfig>;

异步方式获取实时的配置参数。通过Promise获取返回值。

只能在[prepare()](#prepare9-3)接口调用后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<[AVRecorderConfig](#avrecorderconfig9)> | 异步获得实时配置参数的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avConfig: media.AVRecorderConfig;

avRecorder.getAVRecorderConfig().then((config: media.AVRecorderConfig) => {
  console.info('Succeeded in getting AVRecorderConfig');
  avConfig = config;
}).catch((err: BusinessError) => {
  console.error('Failed to get AVRecorderConfig and catch error is ' + err.message);
});
```

### on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: OnAVRecorderStateChangeHandler): void

订阅录制状态机AVRecorderState切换的事件，当 AVRecorderState状态机发生变化时，会通过订阅的回调方法通知用户。用户只能订阅一个状态机切换事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |
| callback | [OnAVRecorderStateChangeHandler](#onavrecorderstatechangehandler12) | 是   | 状态机切换事件回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
avRecorder.on('stateChange', async (state: media.AVRecorderState, reason: media.StateChangeReason) => {
  console.info('case state has changed, new state is :' + state + ',and new reason is : ' + reason);
});
```

### off('stateChange')<sup>9+</sup>

off(type: 'stateChange', callback?: OnAVRecorderStateChangeHandler): void

取消订阅播放状态机[AVRecorderState](#avrecorderstate9)切换的事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |
| callback | [OnAVRecorderStateChangeHandler](#onavrecorderstatechangehandler12) | 否   | 状态机切换事件回调方法。<br/>从API version 12开始支持此参数。 |

**示例：**

```ts
avRecorder.off('stateChange');
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅AVRecorder的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时[AVRecorderState](#avrecorderstate9)也切至error状态，用户需要通过[reset()](#reset9-2)或者[release()](#release9-2)退出录制操作。

用户只能订阅一个错误事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 录制错误事件回调类型'error'。 <br>- 'error'：录制过程中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 录制错误事件回调方法。                                       |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 201      | Permission denied.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 801      | Capability not supported. |
| 5400101  | No memory.             |
| 5400102  | Operation not allowed. |
| 5400103  | I/O error.             |
| 5400104  | Time out.              |
| 5400105  | Service died.          |
| 5400106  | Unsupported format.    |
| 5400107  | Audio interrupted.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.on('error', (err: BusinessError) => {
  console.info('case avRecorder.on(error) called, errMessage is ' + err.message);
});
```

### off('error')<sup>9+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅录制错误事件，取消后不再接收到AVRecorder的错误事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 录制错误事件回调类型'error'。 <br>- 'error'：录制过程中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 录制错误事件回调方法。<br/>从API version 12开始支持此参数。                   |

**示例：**

```ts
avRecorder.off('error');
```

### on('audioCapturerChange')<sup>11+</sup>

on(type: 'audioCapturerChange', callback: Callback<audio.AudioCapturerChangeInfo>): void

订阅录音配置变化的回调，任意录音配置的变化会触发变化后的录音配置全量信息回调。

当用户重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   |录音配置变化的回调类型，支持的事件：'audioCapturerChange'。 |
| callback | Callback<[audio.AudioCapturerChangeInfo](../apis-audio-kit/js-apis-audio.md#audiocapturerchangeinfo9)> | 是 | 变化后的录音配置全量信息。|

**错误码：**

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |

**示例：**

```ts
import { audio } from '@kit.AudioKit'

let capturerChangeInfo: audio.AudioCapturerChangeInfo;

avRecorder.on('audioCapturerChange',  (audioCapturerChangeInfo: audio.AudioCapturerChangeInfo) => {
  console.info('audioCapturerChange called');
  capturerChangeInfo = audioCapturerChangeInfo;
});
```

### off('audioCapturerChange')<sup>11+</sup>

off(type: 'audioCapturerChange', callback?: Callback<audio.AudioCapturerChangeInfo>): void

取消订阅录音变化的回调事件。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 录音配置变化的回调类型，支持的事件：'audioCapturerChange'。 |
| callback | Callback<[audio.AudioCapturerChangeInfo](../apis-audio-kit/js-apis-audio.md#audiocapturerchangeinfo9)> | 否 | 变化后的录音配置全量信息。<br/>从API version 12开始支持此参数。|

**示例：**

```ts
avRecorder.off('audioCapturerChange');
```

### on('photoAssetAvailable')<sup>12+</sup>

on(type: 'photoAssetAvailable', callback: Callback\<photoAccessHelper.PhotoAsset>): void

订阅媒体资源回调事件，当[FileGenerationMode](#filegenerationmode12)枚举设置为系统创建媒体文件时，会在[stop](#stop9-2)操作结束后把[PhotoAsset](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoasset)对象回调给应用。

当用户重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   |录像资源的回调类型，支持的事件：'photoAssetAvailable'。 |
| callback | Callback<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoasset)> | 是 | 系统创建的资源文件对应的PhotoAsset对象。|

**错误码：**

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400103  | IO error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**示例：**

<!--code_no_check-->
```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit'
let photoAsset: photoAccessHelper.PhotoAsset;
private context: Context | undefined;
constructor(context: Context) {
  this.context = context; // this.getUIContext().getHostContext();
}

// 例:处理photoAsset回调，保存video。
async function saveVideo(asset: photoAccessHelper.PhotoAsset) {
  console.info("saveVideo called");
  try {
    let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(this.context);
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.saveCameraPhoto();
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply saveVideo successfully');
  } catch (err) {
    console.error(`apply saveVideo failed with error: ${err.code}, ${err.message}`);
  }
}
// 注册photoAsset监听。
avRecorder.on('photoAssetAvailable',  (asset: photoAccessHelper.PhotoAsset) => {
  console.info('photoAssetAvailable called');
  if (asset != undefined) {
    photoAsset = asset;
    // 处理photoAsset回调。
    // 例: this.saveVideo(asset);
  } else {
    console.error('photoAsset is undefined');
  }
});
```

### off('photoAssetAvailable')<sup>12+</sup>

off(type: 'photoAssetAvailable', callback?: Callback<photoAccessHelper.PhotoAsset>): void

取消订阅媒体资源的回调类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 录音配置变化的回调类型，支持的事件：'photoAssetAvailable'。 |
| callback | Callback<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoasset)> | 否 | 系统创建的资源文件对应的PhotoAsset对象。|

**示例：**

```ts
avRecorder.off('photoAssetAvailable');
```

## AVRecorderState<sup>9+</sup>

type AVRecorderState = 'idle' | 'prepared' | 'started' | 'paused' | 'stopped' | 'released' | 'error'

音视频录制的状态机。可通过state属性获取当前状态。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 类型     | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| 'idle'     | 闲置状态。此时可以调用[AVRecorder.prepare()](#prepare9-2)方法设置录制参数，进入prepared状态。AVRecorder刚被创建，或者在任何非released状态下调用[AVRecorder.reset()](#reset9-2)方法，均进入idle状态。 |
| 'prepared' | 参数设置完成。此时可以调用[AVRecorder.start()](#start9)方法开始录制，进入started状态。 |
| 'started'  | 正在录制。此时可以调用[AVRecorder.pause()](#pause9-2)方法暂停录制，进入paused状态。也可以调用[AVRecorder.stop()](#stop9-2)方法结束录制，进入stopped状态。 |
| 'paused'   | 录制暂停。此时可以调用[AVRecorder.resume()](#resume9)方法继续录制，进入started状态。也可以调用[AVRecorder.stop()](#stop9-2)方法结束录制，进入stopped状态。 |
| 'stopped'  | 录制停止。此时可以调用[AVRecorder.prepare()](#prepare9-2)方法设置录制参数，重新进入prepared状态。 |
| 'released' | 录制资源释放。此时不能再进行任何操作。在任何其他状态下，均可以通过调用[AVRecorder.release()](#release9-2)方法进入released状态。 |
| 'error'    | 错误状态。当AVRecorder实例发生不可逆错误，会转换至当前状态。切换至error状态时会伴随[AVRecorder.on('error')事件](#onerror9-1)，该事件会上报详细错误原因。在error状态时，用户需要调用[AVRecorder.reset()](#reset9-2)方法重置AVRecorder实例，或者调用[AVRecorder.release()](#release9-2)方法释放资源。 |

## OnAVRecorderStateChangeHandler<sup>12+</sup>

type OnAVRecorderStateChangeHandler = (state: AVRecorderState, reason: StateChangeReason) => void

状态机切换事件回调方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 参数名   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ------ | ------------------------------------------------------------ |
| state  | [AVRecorderState](#avrecorderstate9) | 是 | 当前录制状态。     |
| reason | [StateChangeReason](#statechangereason9) | 是 | 当前录制状态的切换原因。 |

## AVRecorderConfig<sup>9+</sup>

表示音视频录制的参数设置。

通过audioSourceType和videoSourceType区分纯音频录制、纯视频录制或音视频录制。纯音频录制时，仅需要设置audioSourceType；纯视频录制时，仅需要设置videoSourceType；音视频录制时，audioSourceType和videoSourceType均需要设置。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称            | 类型                                     | 必填 | 说明                                                         |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](#audiosourcetype9)     | 否   | 选择录制的音频源类型。选择音频录制时必填。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。|
| videoSourceType | [VideoSourceType](#videosourcetype9)     | 否   | 选择录制的视频源类型。选择视频录制时必填。                   |
| profile         | [AVRecorderProfile](#avrecorderprofile9) | 是   | 录制的profile，必要参数。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。|
| url             | string                                   | 是   | 录制输出URL：fd://xx (fd number) ![img](figures/zh-cn_image_url.png)，必要参数。 <br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |
|fileGenerationMode<sup>12+</sup> | [FileGenerationMode](#filegenerationmode12)  | 否   |  创建媒体文件的模式，配合[on('photoAssetAvailable')](#onphotoassetavailable12)监听使用。|
| rotation<sup>(deprecated)</sup>        | number                                   | 否   | 录制的视频旋转角度，mp4格式支持0，90，180，270，默认值为0。<br>从API version 6开始支持，从API version 12开始废弃。建议使用[AVMetadata](#avmetadata11).videoOrientation替代。如果同时设置两个值，将会采用[AVMetadata](#avmetadata11).videoOrientation。     |
| location<sup>(deprecated)</sup>        | [Location](#location)                    | 否   | 录制的地理位置，默认不记录地理位置信息。<br>从API version 6开始支持，从API version 12开始废弃。建议使用 [AVMetadata](#avmetadata11).location。如果同时设置两个值，将会采用[AVMetadata](#avmetadata11).location。 |
| metadata<sup>12+</sup>        | [AVMetadata](#avmetadata11)              | 否   | 设置元数据信息。详情见 [AVMetadata](#avmetadata11)。                  |
| maxDuration<sup>18+</sup>        | number             | 否   | 设置录制的最大时长，单位为秒，有效值取值范围[1 , 2^31-1]，无效输入会重置为最大值。录制到达设定时长后，录制会自动停止，并通过stateChange回调录制状态，[AVRecorderState](#avrecorderstate9) = 'stopped'，[StateChangeReason](#statechangereason9) = BACKGROUND。|

## AVRecorderProfile<sup>9+</sup>

音视频录制的配置文件。

> **说明：**
> 此处提供音频参数配置的对照表，每项的具体释义，可查看下述字段解释。
>
> |编码格式|封装格式|采样率|比特率|声道数|
> |----|----|----|----|----|
> |AUDIO_AAC|MP4,M4A|[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000]|[32000-500000]|[1-8]|
> |AUDIO_MP3|MP3|[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000]|<br>- 采样率使用16000以下时，对应比特率范围为[8000 - 64000]。<br>- 采样率使用16000~32000时对应的比特率范围为[8000 - 160000]。<br>- 采样率使用32000以上时对应的比特率范围为[32000 - 320000]。|[1-2]|
> |AUDIO_G711MU|WAV|[8000]|[64000]|[1]|
> |AUDIO_AMR_NB<sup>18+</sup> |AMR|[8000]|[4750, 5150, 5900, 6700, 7400, 7950, 10200, 12200]|[1]|
> |AUDIO_AMR_WB<sup>18+</sup> |AMR|[16000]|[6600, 8850, 12650, 14250, 15850, 18250, 19850, 23050, 23850]|[1]|

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称             | 类型                                         | 必填 | 说明                                                         |
| ---------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioBitrate     | number                                       | 否   | 音频编码比特率，选择音频录制时必填。<br>支持范围：<br>- AAC编码格式支持比特率范围[32000 - 500000]。<br>- G711-mulaw编码格式支持比特率范围[64000]。<br>- MP3编码格式支持范围[8000, 16000, 32000, 40000, 48000, 56000, 64000, 80000, 96000, 112000, 128000, 160000, 192000, 224000, 256000, 320000]。<br>当使用MP3编码格式时，采样率和比特率的映射关系： <br>- 采样率使用16K以下时，对应比特率范围为[8000 - 64000]。<br>- 采样率使用16K~32K时对应的比特率范围为[8000 - 160000]。<br>- 采样率使用32K以上时对应的比特率范围为[32000 - 320000]。<br>- AMR_NB编码格式支持比特率范围[4750, 5150, 5900, 6700, 7400, 7950, 10200, 12200]。<br>- AMR_WB编码格式支持比特率范围[6600, 8850, 12650, 14250, 15850, 18250, 19850, 23050, 23850]。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |
| audioChannels    | number                                       | 否   | 音频采集声道数，选择音频录制时必填。<br>- AAC编码格式支持范围[1 - 8]。<br>- G711-mulaw编码格式支持范围[1]。<br>- MP3编码格式支持范围[1 - 2]。<br>- AMR-NB、AMR-WB编码格式支持范围[1]。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。       |
| audioCodec       | [CodecMimeType](#codecmimetype8)             | 否   | 音频编码格式，选择音频录制时必填。当前支持AUDIO_AAC，AUDIO_MP3，AUDIO_G711MU, AUDIO_AMR_NB, AUDIO_AMR_WB。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。     |
| audioSampleRate  | number                                       | 否   | 音频采样率，选择音频录制时必填。<br>支持范围：<br>- AAC编码支持采样率范围[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 88200, 96000]。<br>- G711-mulaw编码支持采样率范围[8000]。<br>- MP3编码支持采样率范围[8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000]。<br>- AMR_NB编码支持采样率范围[8000]。<br>- AMR_WB编码支持采样率范围[16000]。<br>可变比特率模式，码率仅作参考。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |
| fileFormat       | [ContainerFormatType](#containerformattype8) | 是   | 文件的容器格式，必要参数。当前支持MP4、M4A、MP3、WAV、AMR、AAC封装格式，当前AAC音频封装默认为ADTS帧头格式。不支持在MP4封装格式下使用AUDIO_MP3编码格式。<br>**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。|
| videoBitrate     | number                                       | 否   | 视频编码比特率，选择视频录制时必填，支持范围[10000 - 100000000]。  |
| videoCodec       | [CodecMimeType](#codecmimetype8)             | 否   | 视频编码格式，选择视频录制时必填。当前支持VIDEO_AVC。|
| videoFrameWidth  | number                                       | 否   | 视频帧的宽，选择视频录制时必填，支持范围[176 - 4096]。         |
| videoFrameHeight | number                                       | 否   | 视频帧的高，选择视频录制时必填，支持范围[144 - 4096]。         |
| videoFrameRate   | number                                       | 否   | 视频帧率，选择视频录制时必填，推荐范围[1 - 60]。             |
| isHdr<sup>11+</sup>            | boolean                        | 否   | HDR编码，选择视频录制时选填，isHdr默认为false，对应编码格式没有要求，isHdr为true时，对应的编码格式必须为video/hevc。|
| enableTemporalScale<sup>12+</sup>            | boolean                        | 否   | 视频录制是否支持时域分层编码功能，选择视频录制时选填，enableTemporalScale默认为false。设置为true时，编码输出的码流中部分帧可以支持跳过不编码。|

## AudioSourceType<sup>9+</sup>

表示视频录制中音频源类型的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称                      | 值   | 说明                   |
| ------------------------- | ---- | ---------------------- |
| AUDIO_SOURCE_TYPE_DEFAULT | 0    | 默认的音频输入源类型。 |
| AUDIO_SOURCE_TYPE_MIC     | 1    | 表示MIC的音频输入源。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |
| AUDIO_SOURCE_TYPE_VOICE_RECOGNITION<sup>12+</sup> | 2    | 表示语音识别场景的音频源。 |
| AUDIO_SOURCE_TYPE_VOICE_COMMUNICATION<sup>12+</sup>     | 7    | 表示语音通话场景的音频源。 |
| AUDIO_SOURCE_TYPE_VOICE_MESSAGE<sup>12+</sup> | 10    | 表示短语音消息的音频源。 |
| AUDIO_SOURCE_TYPE_CAMCORDER<sup>12+</sup>     | 13    | 表示相机录像的音频源。 |

## VideoSourceType<sup>9+</sup>

表示视频录制中视频源类型的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称                          | 值   | 说明                            |
| ----------------------------- | ---- | ------------------------------- |
| VIDEO_SOURCE_TYPE_SURFACE_YUV | 0    | 输入surface中携带的是raw data。 |
| VIDEO_SOURCE_TYPE_SURFACE_ES  | 1    | 输入surface中携带的是ES data。  |

## ContainerFormatType<sup>8+</sup>

表示容器格式类型的枚举，缩写为CFT。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称        | 值    | 说明                  |
| ----------- | ----- | --------------------- |
| CFT_MPEG_4  | 'mp4' | 视频的容器格式，MP4。 |
| CFT_MPEG_4A | 'm4a' | 音频的容器格式，M4A。<br> **原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |
| CFT_MP3<sup>12+</sup>  | 'mp3' | 音频的容器格式，MP3。 |
| CFT_WAV<sup>12+</sup>  | 'wav' | 音频的容器格式，WAV。 |
| CFT_AMR<sup>18+</sup>  | 'amr' | 音频的容器格式，AMR。 |
| CFT_AAC<sup>20+</sup>  | 'aac' | 音频的容器格式，AAC。默认为ADTS帧头格式。 |

## Location

视频录制的地理位置。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称      | 类型   | 必填 | 说明             |
| --------- | ------ | ---- | ---------------- |
| latitude  | number | 是   | 地理位置的纬度，取值范围为[-90, 90]。 |
| longitude | number | 是   | 地理位置的经度，取值范围为[-180, 180]。 |

## EncoderInfo<sup>11+</sup>

编码器和规格参数

系统能力：SystemCapability.Multimedia.Media.AVRecorder

| 名称       | 类型                             | 可读 | 可写 | 说明                                                         |
| ---------- | -------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| mimeType   | [CodecMimeType](#codecmimetype8) | 是   | 否   | 编码器MIME类型名称。                                           |
| type       | string                           | 是   | 否   | 编码器类型，audio表示音频编码器，video表示视频编码器。         |
| bitRate    | [Range](#range11)                | 是   | 否   | 比特率，包含该编码器的最大和最小值。                           |
| frameRate  | [Range](#range11)                | 是   | 否   | 视频帧率，包含帧率的最大和最小值，仅视频编码器拥有。          |
| width      | [Range](#range11)                | 是   | 否   | 视频帧的宽度，包含宽度的最大和最小值，仅视频编码器拥有。       |
| height     | [Range](#range11)                | 是   | 否   | 视频帧的高度，包含高度的最大和最小值，仅视频编码器拥有。       |
| channels   | [Range](#range11)                | 是   | 否   | 音频采集声道数，包含声道数的最大和最小值，仅音频编码器拥有。   |
| sampleRate | Array\<number>                    | 是   | 否   | 音频采样率，包含所有可以使用的音频采样率值数组，具体数值依赖编码器类型，仅音频编码器拥有。 |

## Range<sup>11+</sup>

表示一个类型的范围

系统能力：SystemCapability.Multimedia.Media.AVRecorder

| 名称 | 类型   | 可读 | 可写 | 说明         |
| ---- | ------ | ---- | ---- | ------------ |
| min  | number | 是   | 否   | 范围的最小值。 |
| max  | number | 是   | 否   | 范围的最大值。 |

## FileGenerationMode<sup>12+</sup>

表示创建媒体文件模式的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称                          | 值   | 说明                            |
| ----------------------------- | ---- | ------------------------------- |
| APP_CREATE  | 0    | 由应用自行在沙箱创建媒体文件。 |
| AUTO_CREATE_CAMERA_SCENE  | 1    | 由系统创建媒体文件，当前仅在相机录制场景下生效，会忽略应用设置的url。 |

## AVTranscoder<sup>12+</sup>

视频转码管理类，用于视频转码。在调用AVTranscoder的方法前，需要先通过[createAVTranscoder()](#mediacreateavtranscoder12)构建一个AVTranscoder实例。

视频转码demo可参考：[视频转码开发指导](../../media/media/using-avtranscoder-for-transcodering.md)

### 属性

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

| 名称    | 类型                                 | 只读 | 可选 | 说明               |
| ------- | ------------------------------------ | ---- | ---- | ------------------ |
| fdSrc<sup>12+</sup>                                  | [AVFileDescriptor](#avfiledescriptor9)                       |  否  | 否   | 源媒体文件描述，通过该属性设置数据源。<br/> **使用示例**：<br/>假设一个连续存储的媒体文件，地址偏移:0，字节长度:100。其文件描述为 AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br>**说明：** <br> - 将资源句柄（fd）传递给 AVTranscoder 实例之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个 AVPlayer / AVMetadataExtractor / AVImageGenerator / AVTranscoder。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致视频转码数据获取异常。 |
| fdDst<sup>12+</sup>                               | number                 |  否  | 否   | 目标媒体文件描述，通过该属性设置数据输出。在创建AVTranscoder实例后，必须设置fdSrc和fdDst属性。<br>**说明：** <br> - 将资源句柄（fd）传递给 AVTranscoder 实例之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个 AVPlayer / AVMetadataExtractor / AVImageGenerator / AVTranscoder。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致视频转码数据获取异常。 |

### prepare<sup>12+</sup>

prepare(config: AVTranscoderConfig): Promise\<void>

异步方式进行视频转码的参数设置。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| config | [AVTranscoderConfig](#avtranscoderconfig12) | 是   | 配置视频转码的相关参数。 <!--RP1--><!--RP1End-->|

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | 异步视频转码prepare方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 401  | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.              |
| 5400105  | Service died. Return by promise.       |
| 5400106  | Unsupported format. Returned by promise.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 配置参数以实际硬件设备支持的范围为准。
let avTranscoderConfig: media.AVTranscoderConfig = {
  audioBitrate : 200000,
  audioCodec : media.CodecMimeType.AUDIO_AAC,
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,
  videoBitrate : 3000000,
  videoCodec : media.CodecMimeType.VIDEO_AVC,
};

avTranscoder.prepare(avTranscoderConfig).then(() => {
  console.info('prepare success');
}).catch((err: BusinessError) => {
  console.error('prepare failed and catch error is ' + err.message);
});
```

### start<sup>12+</sup>

start(): Promise\<void>

异步方式开始视频转码。通过Promise获取返回值。

需要[prepare()](#prepare12)事件成功触发后，才能调用start方法。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步开始视频转码方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avTranscoder.start().then(() => {
  console.info('start AVTranscoder success');
}).catch((err: BusinessError) => {
  console.error('start AVTranscoder failed and catch error is ' + err.message);
});
```

### pause<sup>12+</sup>

pause(): Promise\<void>

异步方式暂停视频转码。通过Promise获取返回值。

需要[start()](#start12)事件成功触发后，才能调用pause方法，可以通过调用[resume()](#resume12)接口来恢复转码。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步暂停视频转码方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avTranscoder.pause().then(() => {
  console.info('pause AVTranscoder success');
}).catch((err: BusinessError) => {
  console.error('pause AVTranscoder failed and catch error is ' + err.message);
});
```

### resume<sup>12+</sup>

resume(): Promise\<void>

异步方式恢复视频转码。通过Promise获取返回值。

需要在[pause()](#pause12)事件成功触发后，才能调用resume方法。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步恢复视频转码方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avTranscoder.resume().then(() => {
  console.info('resume AVTranscoder success');
}).catch((err: BusinessError) => {
  console.error('resume AVTranscoder failed and catch error is ' + err.message);
});
```

### cancel<sup>12+</sup>

cancel(): Promise\<void>

异步方式取消视频转码。通过Promise获取返回值。

需要在[prepare()](#prepare12)、[start()](#start12)、[pause()](#pause12)或[resume()](#resume12)事件成功触发后，才能调用cancel方法。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步取消视频转码方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avTranscoder.cancel().then(() => {
  console.info('cancel AVTranscoder success');
}).catch((err: BusinessError) => {
  console.error('cancel AVTranscoder failed and catch error is ' + err.message);
});
```

### release<sup>12+</sup>

release(): Promise\<void>

异步方式释放视频转码资源。通过Promise获取返回值。

释放视频转码资源之后，该AVTranscoder实例不能再进行任何操作。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**返回值：**

| 类型           | 说明                                        |
| -------------- | ------------------------------------------- |
| Promise\<void> | 异步释放视频转码资源方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avTranscoder.release().then(() => {
  console.info('release AVTranscoder success');
}).catch((err: BusinessError) => {
  console.error('release AVTranscoder failed and catch error is ' + err.message);
});
```

### on('progressUpdate')<sup>12+</sup>

on(type: 'progressUpdate', callback: Callback\<number>): void

注册转码进度更新事件，并通过注册的回调方法通知开发者。开发者只能注册一个进度更新事件的回调方法，当开发者重复注册时，以最后一次注册的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 进度更新事件回调类型，支持的事件：'progressUpdate'，在转码过程中系统会自动触发此事件。 |
| callback | [Callback\<number>](../apis-basic-services-kit/js-apis-base.md#callback) | 是   | 进度更新事件回调方法，progress: number，表示当前转码进度。 |

**示例：**

```ts
avTranscoder.on('progressUpdate', (progress: number) => {
  console.info('avTranscoder progressUpdate = ' + progress);
});
```

### off('progressUpdate')<sup>12+</sup>

off(type:'progressUpdate', callback?: Callback\<number>): void

取消注册转码进度更新事件。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 进度更新事件回调类型，支持的事件：'progressUpdate'。 |
| callback | [Callback\<number>](../apis-basic-services-kit/js-apis-base.md#callback) | 否   | 已注册的进度更新事件回调。由于当前回调注册时，仅会保留最后一次注册的回调，建议此参数缺省。 |

**示例：**

```ts
avTranscoder.off('progressUpdate');
```

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

注册AVtranscoder的错误事件，该事件仅用于错误提示。如果AVTranscoder上报error事件，开发者需要通过[release()](#release12)退出转码操作。

开发者只能订阅一个错误事件的回调方法，当开发者重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 转码错误事件回调类型'error'。 <br>- 'error'：录制过程中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 转码错误事件回调方法。                                       |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. |
| 801      | Capability not supported. |
| 5400101  | No memory.            |
| 5400102  | Operation not allowed. |
| 5400103  | I/O error.              |
| 5400104  | Time out.            |
| 5400105  | Service died.           |
| 5400106  | Unsupported format.      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avTranscoder.on('error', (err: BusinessError) => {
  console.info('case avTranscoder.on(error) called, errMessage is ' + err.message);
});
```

### off('error')<sup>12+</sup>

off(type:'error', callback?: ErrorCallback): void

取消注册转码错误事件，取消后不再接收到AVTranscoder的错误事件。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 转码错误事件回调类型'error'。 <br>- 'error'：转码过程中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 错误事件回调方法。 |

**示例：**

```ts
avTranscoder.off('error');
```

### on('complete')<sup>12+</sup>

on(type: 'complete', callback: Callback\<void>): void

注册转码完成事件，并通过注册的回调方法通知开发者。开发者只能注册一个进度更新事件的回调方法，当开发者重复注册时，以最后一次注册的回调接口为准。

当AVTranscoder上报complete事件时，当前转码操作已完成，开发者需要通过[release()](#release12)退出转码操作。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 完成事件回调类型，支持的事件：'complete'，在转码过程中系统会自动触发此事件。 |
| callback | [Callback\<void>](../apis-basic-services-kit/js-apis-base.md#callback) | 是   | 完成事件回调方法。 |

**示例：**

```ts
avTranscoder.on('complete', async () => {
  console.info('avTranscoder complete');
  // 开发者须在此监听转码完成事件
  // 须等待avTranscoder.release()之后，再对转码后的文件进行转发、上传、转存等处理
  await avTranscoder.release();
  avTranscoder = undefined;
});
```

### off('complete')<sup>12+</sup>

off(type:'complete', callback?: Callback\<void>): void

取消注册转码完成事件。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 转码完成事件回调类型，支持的事件：'complete'。 |
| callback | [Callback\<void>](../apis-basic-services-kit/js-apis-base.md#callback) | 否   | 完成事件回调方法。 |

**示例：**

```ts
avTranscoder.off('complete');
```

## AVTranscoderConfig<sup>12+</sup>

表示视频转码的参数设置。

**系统能力：** SystemCapability.Multimedia.Media.AVTranscoder

| 名称            | 类型                                    | 只读 | 可选 | 说明                                                         |
| --------------- | ---------------------------------------- |---- | ---- | ------------------------------------------------------------ |
| audioBitrate | number     | 否 | 是 | 输出音频的码率，单位为比特率（bps），支持范围[1-500000]。默认设置为48Kbps。|
| audioCodec | [CodecMimeType](#codecmimetype8)     | 否 | 是  | 输出音频的编码格式，当前仅支持AAC。默认设置为AAC。                   |
| fileFormat         | [ContainerFormatType](#containerformattype8) | 否 | 否   | 输出视频文件的封装格式，当前视频文件仅支持MP4。|
| videoBitrate         | number | 否 |  是  | 输出视频的码率，单位为比特率（bps）。默认码率按输出视频的分辨率设置，[240p，480P]默认码率值为1Mbps，(480P,720P]默认码率值为2Mbps，(720P,1080P]默认码率值为4Mbps，1080P及以上默认值为8Mbps。|
| videoCodec        | [CodecMimeType](#codecmimetype8) | 否 | 是   | 输出视频的编码格式，当前仅支持AVC和HEVC。若源视频编码格式为HEVC，则默认设置为HEVC，否则默认设置为AVC。|
| videoFrameWidth        | number | 否 |  是   | 输出视频帧的宽，单位为像素（px），支持范围[240-3840]。默认设置为源视频帧的宽。|
| videoFrameHeight        | number | 否 |  是   | 输出视频帧的高，单位为像素（px），支持范围[240-2160]。默认设置为源视频帧的高。|



## AVMetadataExtractor<sup>11+</sup>

元数据获取类，用于从媒体资源中获取元数据。在调用AVMetadataExtractor的方法前，需要先通过[createAVMetadataExtractor()](#mediacreateavmetadataextractor11)构建一个AVMetadataExtractor实例。

获取音频或视频元数据的demo可参考：[获取音视频元数据开发指导](../../media/media/avmetadataextractor.md)。

### 属性

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

| 名称                                                | 类型                                                         | 可读 | 可写 | 说明                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fdSrc<sup>11+</sup>                                  | [AVFileDescriptor](#avfiledescriptor9)                       | 是   | 是   | 媒体文件描述，通过该属性设置数据源。在获取元数据之前，必须设置数据源属性，只能设置fdSrc和dataSrc的其中一个。<br/> **使用示例**：<br/>假设一个连续存储的媒体文件，地址偏移:0，字节长度:100。其文件描述为 AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br>**说明：** <br> - 将资源句柄（fd）传递给 AVMetadataExtractor 实例之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个 AVPlayer / AVMetadataExtractor / AVImageGenerator / AVTranscoder。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致音视频元数据获取异常。 |
| dataSrc<sup>11+</sup>                               | [AVDataSrcDescriptor](#avdatasrcdescriptor10)                | 是   | 是   | 流式媒体资源描述，通过该属性设置数据源。在获取元数据之前，必须设置数据源属性，只能设置fdSrc和dataSrc的其中一个。<br/> 当应用从远端获取音视频媒体文件，在应用未下载完整音视频资源时，可以设置dataSrc提前获取该资源的元数据。|

### fetchMetadata<sup>11+</sup>

fetchMetadata(callback: AsyncCallback\<AVMetadata>): void

异步方式获取媒体元数据。通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<[AVMetadata](#avmetadata11)>       | 是   | 回调函数。异步返回音视频元数据对象（AVMetadata）。|

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.fetchMetadata((error: BusinessError, metadata: media.AVMetadata) => {
  if (error) {
    console.error(`Failed to fetch Metadata, err = ${JSON.stringify(error)}`);
    return;
  }
  console.info(`Succeeded in fetching Metadata, genre: ${metadata.genre}`);
});
```

### fetchMetadata<sup>11+</sup>

fetchMetadata(): Promise\<AVMetadata>

异步方式获取媒体元数据。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**返回值：**

| 类型           | 说明                                     |
| -------------- | ---------------------------------------- |
| Promise\<[AVMetadata](#avmetadata11)>  | Promise对象。异步返回音视频元数据对象（AVMetadata）。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.fetchMetadata().then((metadata: media.AVMetadata) => {
  console.info(`Succeeded in fetching Metadata, genre: ${metadata.genre}`);
}).catch((error: BusinessError) => {
  console.error(`Failed to fetch Metadata, error message:${error.message}`);
});
```

### fetchAlbumCover<sup>11+</sup>

fetchAlbumCover(callback: AsyncCallback\<image.PixelMap>): void

异步方式获取音频专辑封面。通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)>    | 是   | 回调函数。异步返回专辑封面。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let pixel_map : image.PixelMap | undefined = undefined;

avMetadataExtractor.fetchAlbumCover((error: BusinessError, pixelMap: image.PixelMap) => {
  if (error) {
    console.error(`Failed to fetch AlbumCover, error = ${JSON.stringify(error)}`);
    return;
  }
  pixel_map = pixelMap;
});
```

### fetchAlbumCover<sup>11+</sup>

fetchAlbumCover(): Promise\<image.PixelMap>

异步方式获取专辑封面。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**返回值：**

| 类型           | 说明                                     |
| -------------- | ---------------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> |  Promise对象。异步返回专辑封面。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let pixel_map : image.PixelMap | undefined = undefined;

avMetadataExtractor.fetchAlbumCover().then((pixelMap: image.PixelMap) => {
  pixel_map = pixelMap;
}).catch((error: BusinessError) => {
  console.error(`Failed to fetch AlbumCover, error message:${error.message}`);
});
```

### release<sup>11+</sup>

release(callback: AsyncCallback\<void>): void

异步方式释放资源。通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<void>                   | 是   |回调函数。当释放资源成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.release((error: BusinessError) => {
  if (error) {
    console.error(`Failed to release, err = ${JSON.stringify(error)}`);
    return;
  }
  console.info(`Succeeded in releasing.`);
});
```

### release<sup>11+</sup>

release(): Promise\<void>

异步方式释放资源。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**返回值：**

| 类型           | 说明                                     |
| -------------- | ---------------------------------------- |
| Promise\<void> | 异步方式释放资源release方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.release().then(() => {
  console.info(`Succeeded in releasing.`);
}).catch((error: BusinessError) => {
  console.error(`Failed to release, error message:${error.message}`);
});
```

## AVMetadata<sup>11+</sup>

音视频元数据，包含各个元数据字段。在[AVRecorderConfig](#avrecorderconfig9)中使用时未声明为当前版本只读的参数可以作为使用[AVRecorder](#avrecorder9)录制时的入参。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| album     | string | 否   | 专辑的标题。当前版本为只读参数。     |
| albumArtist | string | 否   | 专辑的艺术家。当前版本为只读参数。 |
| artist | string | 否   | 媒体资源的艺术家。当前版本为只读参数。 |
| author | string | 否   | 媒体资源的作者。当前版本为只读参数。 |
| dateTime | string | 否   | 媒体资源的创建时间。当前版本为只读参数。 |
| dateTimeFormat | string | 否   | 媒体资源的创建时间，按YYYY-MM-DD HH:mm:ss格式输出。当前版本为只读参数。 |
| composer | string | 否   | 媒体资源的作曲家。当前版本为只读参数。 |
| duration | string | 否   | 媒体资源的时长。当前版本为只读参数。 |
| genre | string | 否   | 媒体资源的类型或体裁。|
| hasAudio | string | 否   | 媒体资源是否包含音频。当前版本为只读参数。 |
| hasVideo | string | 否   | 媒体资源是否包含视频。当前版本为只读参数。 |
| mimeType | string | 否   | 媒体资源的mime类型。当前版本为只读参数。 |
| trackCount | string | 否   | 媒体资源的轨道数量。当前版本为只读参数。 |
| sampleRate | string | 否   | 音频的采样率，单位为赫兹（Hz）。当前版本为只读参数。 |
| title | string | 否   | 媒体资源的标题。当前版本为只读参数。当前版本为只读参数。 |
| videoHeight | string | 否   | 视频的高度，单位为像素。当前版本为只读参数。 |
| videoWidth | string | 否   | 视频的宽度，单位为像素。当前版本为只读参数。 |
| videoOrientation | string | 否   | 视频的旋转方向，单位为度（°）。|
| hdrType<sup>12+</sup> | [HdrType](#hdrtype12) | 否   | 媒体资源的HDR类型。当前版本为只读参数。 |
| location<sup>12+</sup> | [Location](#location) | 否 | 视频的地理位置信息。 |
| customInfo<sup>12+</sup> | Record<string, string> | 否 | 从moov.meta.list 获取的自定义参数键值映射。|

## HdrType<sup>12+</sup>

表示视频HDR类型的枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                      | 值   | 说明                   |
| ------------------------- | ---- | ---------------------- |
| AV_HDR_TYPE_NONE          | 0    | 表示无HDR类型。 |
| AV_HDR_TYPE_VIVID         | 1    | 表示为HDR VIVID类型。 |

## media.createAudioPlayer<sup>(deprecated)</sup>

createAudioPlayer(): AudioPlayer

同步方式创建音频播放实例。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[createAVPlayer](#mediacreateavplayer9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**返回值：**

| 类型                        | 说明                                                         |
| --------------------------- | ------------------------------------------------------------ |
| [AudioPlayer](#audioplayerdeprecated) | 返回AudioPlayer类实例，失败时返回null。可用于音频播放、暂停、停止等操作。 |

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
| callback | AsyncCallback<[VideoPlayer](#videoplayerdeprecated)> | 是   | 回调函数。创建VideoPlayer实例成功时，err为undefined，data为获取到的VideoPlayer实例，否则为错误对象。 |

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
| Promise<[VideoPlayer](#videoplayerdeprecated)> | Promise对象。异步返回VideoPlayer实例，失败时返回null。可用于管理和播放视频媒体。 |

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
| [AudioRecorder](#audiorecorderdeprecated) | 返回AudioRecorder类实例，失败时返回null。可用于录制音频媒体。 |

**示例：**

```ts
let audioRecorder: media.AudioRecorder = media.createAudioRecorder();
```

## MediaErrorCode<sup>(deprecated)</sup>

媒体服务错误类型枚举。

> **说明：**
> 从API version 8开始支持，从API version 11开始废弃，建议使用[媒体错误码](#averrorcode9)替代。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                       | 值   | 说明                                   |
| -------------------------- | ---- | -------------------------------------- |
| MSERR_OK                   | 0    | 表示操作成功。                         |
| MSERR_NO_MEMORY            | 1    | 表示申请内存失败，系统可能无可用内存。 |
| MSERR_OPERATION_NOT_PERMIT | 2    | 表示无权限执行此操作。                 |
| MSERR_INVALID_VAL          | 3    | 表示传入入参无效。                     |
| MSERR_IO                   | 4    | 表示发生IO错误。                       |
| MSERR_TIMEOUT              | 5    | 表示操作超时。                         |
| MSERR_UNKNOWN              | 6    | 表示未知错误。                         |
| MSERR_SERVICE_DIED         | 7    | 表示服务端失效。                       |
| MSERR_INVALID_STATE        | 8    | 表示在当前状态下，不允许执行此操作。   |
| MSERR_UNSUPPORTED          | 9    | 表示在当前版本下，不支持此操作。       |

## AudioPlayer<sup>(deprecated)</sup>

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer](#avplayer9)替代。

音频播放管理类，用于管理和播放音频媒体。在调用AudioPlayer的方法前，需要先通过[createAudioPlayer()](#mediacreateaudioplayerdeprecated)构建一个AudioPlayer实例。

### 属性<sup>(deprecated)</sup>

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

| 名称                            | 类型                                                   | 只读 | 可选 | 说明                                                         |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| src                             | string                                                 | 否   | 否   | 音频媒体URI，支持当前主流的音频格式(m4a、aac、mp3、ogg、wav、amr)。<br>**支持路径示例**：<br>1. fd类型播放：fd://xx<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http\://xx<br/>3. https网络播放: https\://xx<br/>4. hls网络播放路径：http\://xx或者https\://xx <br/>**需要权限：** ohos.permission.READ_MEDIA 或 ohos.permission.INTERNET。 |
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | 否   | 否   | 音频媒体文件描述，使用场景：应用中的音频资源被连续存储在同一个文件中。<br/>**使用示例**：<br/>假设一个连续存储的音乐文件: <br/>音乐1(地址偏移:0，字节长度:100)<br/>音乐2(地址偏移:101，字节长度:50)<br/>音乐3(地址偏移:151，字节长度:150)<br/>1. 播放音乐1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放音乐2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放音乐3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的音乐文件: 请使用src=fd://xx <br/> |
| loop                            | boolean                                                | 否   | 否  | 音频循环播放属性，设置为'true'表示循环播放。                 |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9) | 是   | 是   | 音频焦点模型。                                               |
| currentTime                     | number                                                 | 是   | 否   | 音频的当前播放位置，单位为毫秒（ms）。                       |
| duration                        | number                                                 | 是   | 否   | 音频时长，单位为毫秒（ms）。                                 |
| state                           | [AudioState](#audiostatedeprecated)                              | 是   | 否   | 可以查询音频播放的状态，该状态不可作为调用play/pause/stop等状态切换的触发条件。 |

### play<sup>(deprecated)</sup>

play(): void

开始播放音频资源，需在'dataLoad'事件成功触发后，才能调用。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.play](#play9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```ts
audioPlayer.on('play', () => {    //设置'play'事件回调。
  console.info('audio play called');
});
audioPlayer.play();
```

### pause<sup>(deprecated)</sup>

pause(): void

暂停播放音频资源。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.pause](#pause9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```ts
audioPlayer.on('pause', () => {    //设置'pause'事件回调。
  console.info('audio pause called');
});
audioPlayer.pause();
```

### stop<sup>(deprecated)</sup>

stop(): void

停止播放音频资源。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.stop](#stop9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```ts
audioPlayer.on('stop', () => {    //设置'stop'事件回调。
  console.info('audio stop called');
});
audioPlayer.stop();
```

### reset<sup>(deprecated)</sup>

reset(): void

重置播放音频资源。

> **说明：**
> 从API version 7开始支持，从API version 9开始废弃，建议使用[AVPlayer.reset](#reset9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```ts
audioPlayer.on('reset', () => {    //设置'reset'事件回调。
  console.info('audio reset called');
});
audioPlayer.reset();
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number): void

跳转到指定播放位置。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.seek](#seek9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                        |
| ------ | ------ | ---- | ----------------------------------------------------------- |
| timeMs | number | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围[0, duration]。 |

**示例：**

```ts
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {    //设置'timeUpdate'事件回调。
  if (seekDoneTime == null) {
    console.error('Failed to seek');
    return;
  }
  console.info('Succeeded in seek. seekDoneTime: ' + seekDoneTime);
});
audioPlayer.seek(30000);    //seek到30000ms的位置。
```

### setVolume<sup>(deprecated)</sup>

setVolume(vol: number): void

设置音量。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.setVolume](#setvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |

**示例：**

```ts
audioPlayer.on('volumeChange', () => {    //设置'volumeChange'事件回调。
  console.info('audio volumeChange called');
});
audioPlayer.setVolume(1);    //设置音量到100%。
```

### release<sup>(deprecated)</sup>

release(): void

释放音频资源。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.release](#release9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```ts
audioPlayer.release();
audioPlayer = undefined;
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

获取音频轨道信息。需在'dataLoad'事件成功触发后，才能调用。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.getTrackDescription](#gettrackdescription9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](#mediadescription8)>> | 是   | 回调函数。获取音频轨道信息成功时，err为undefined，data为获取到的MediaDescription数组，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    console.info('Succeeded in getting TrackDescription');
  } else {
    console.error(`Failed to get TrackDescription, error:${error}`);
  }
});
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

获取音频轨道信息。需在'dataLoad'事件成功触发后，才能调用。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.getTrackDescription](#gettrackdescription9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**返回值：**

| 类型                                                   | 说明                                            |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | 音频轨道信息MediaDescription数组Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  console.info('Succeeded in getting TrackDescription');
}).catch((error: BusinessError) => {
  console.error(`Failed to get TrackDescription, error:${error}`);
});
```

### on('bufferingUpdate')<sup>(deprecated)</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

开始订阅音频缓存更新事件。仅网络播放支持该订阅事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('bufferingUpdate')](#onbufferingupdate9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 音频缓存事件回调类型，支持的事件：'bufferingUpdate'。        |
| callback | function | 是   | 音频缓存事件回调方法。<br>[BufferingInfoType](#bufferinginfotype8)value值固定为0。 |

**示例：**

```ts
audioPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('audio bufferingInfo type: ' + infoType);
  console.info('audio bufferingInfo value: ' + value);
});
```

### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')<sup>(deprecated)</sup>

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void): void

开始订阅音频播放事件。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('stateChange')](#onstatechange9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                         |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | 是   | 播放事件回调类型，支持的事件包括：'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange'。<br>- 'play'：完成[play()](#playdeprecated)调用，音频开始播放，触发该事件。<br>- 'pause'：完成[pause()](#pausedeprecated)调用，音频暂停播放，触发该事件。<br>- 'stop'：完成[stop()](#stopdeprecated)调用，音频停止播放，触发该事件。<br>- 'reset'：完成[reset()](#resetdeprecated)调用，播放器重置，触发该事件。<br>- 'dataLoad'：完成音频数据加载后触发该事件，即src属性设置完成后触发该事件。<br>- 'finish'：完成音频播放后触发该事件。<br>- 'volumeChange'：完成[setVolume()](#setvolumedeprecated)调用，播放音量改变后触发该事件。 |
| callback | () => void | 是   | 播放事件回调方法。                                           |

**示例：**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioPlayer: media.AudioPlayer = media.createAudioPlayer();  //创建一个音频播放实例。
audioPlayer.on('dataLoad', () => {            //设置'dataLoad'事件回调，src属性设置成功后，触发此回调。
  console.info('audio set source called');
  audioPlayer.play();                       //开始播放，并触发'play'事件回调。
});
audioPlayer.on('play', () => {                //设置'play'事件回调。
  console.info('audio play called');
  audioPlayer.seek(30000);                  //调用seek方法，并触发'timeUpdate'事件回调。
});
audioPlayer.on('pause', () => {               //设置'pause'事件回调。
  console.info('audio pause called');
  audioPlayer.stop();                       //停止播放，并触发'stop'事件回调。
});
audioPlayer.on('reset', () => {               //设置'reset'事件回调。
  console.info('audio reset called');
  audioPlayer.release();                    //释放播放实例资源。
  audioPlayer = undefined;
});
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {  //设置'timeUpdate'事件回调。
  if (seekDoneTime == null) {
    console.error('Failed to seek');
    return;
  }
  console.info('Succeeded in seek, and seek time is ' + seekDoneTime);
  audioPlayer.setVolume(0.5);                //设置音量为50%，并触发'volumeChange'事件回调。
});
audioPlayer.on('volumeChange', () => {         //设置'volumeChange'事件回调。
  console.info('audio volumeChange called');
  audioPlayer.pause();                       //暂停播放，并触发'pause'事件回调。
});
audioPlayer.on('finish', () => {               //设置'finish'事件回调。
  console.info('audio play finish');
  audioPlayer.stop();                        //停止播放，并触发'stop'事件回调。
});
audioPlayer.on('error', (error: BusinessError) => {  //设置'error'事件回调。
  console.error(`audio error called, error: ${error}`);
});

// 用户选择音频设置fd(本地播放)。
let fdPath = 'fd://';
// path路径的码流可通过"hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上。
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
fs.open(path).then((file) => {
  fdPath = fdPath + '' + file.fd;
  console.info('Succeeded in opening fd, fd is' + fdPath);
  audioPlayer.src = fdPath;  //设置src属性，并触发'dataLoad'事件回调。
}, (err: BusinessError) => {
  console.error('Failed to open fd, err is' + err);
}).catch((err: BusinessError) => {
  console.error('Failed to open fd, err is' + err);
});
```

### on('timeUpdate')<sup>(deprecated)</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

开始订阅音频播放时间更新事件。处于播放状态时，每隔1s上报一次该事件。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('timeUpdate')](#ontimeupdate9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型              | 必填 | 说明                                                         |
| -------- | ----------------- | ---- | ------------------------------------------------------------ |
| type     | string            | 是   | 播放事件回调类型，支持的事件包括：'timeUpdate'。<br>- 'timeUpdate'：音频播放时间戳更新，开始播放后自动触发该事件。 |
| callback | Callback\<number> | 是   | 播放事件回调方法。回调方法入参为更新后的时间戳。             |

**示例：**

```ts
audioPlayer.on('timeUpdate', (newTime: number) => {    //设置'timeUpdate'事件回调。
  if (newTime == null) {
    console.error('Failed to do timeUpadate');
    return;
  }
  console.info('Succeeded in doing timeUpadate. seekDoneTime: ' + newTime);
});
audioPlayer.play();    //开始播放后，自动触发时间戳更新事件。
```

### on('audioInterrupt')<sup>(deprecated)</sup>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

监听音频焦点变化事件，参考[audio.InterruptEvent](../apis-audio-kit/js-apis-audio.md#interruptevent9)。

> **说明：**
> 从API version 9开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('audioInterrupt')](#onaudiointerrupt9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'。 |
| callback | function  | 是   | 音频焦点变化事件回调方法。                               |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt called,and InterruptEvent info is:' + info);
});
```

### on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

开始订阅音频播放错误事件，当上报error错误事件后，用户需处理error事件，退出播放操作。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('error')](#onerror9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 播放错误事件回调类型，支持的事件包括：'error'。<br>- 'error'：音频播放中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 播放错误事件回调方法。                                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioPlayer.on('error', (error: BusinessError) => {  //设置'error'事件回调。
  console.error(`audio error called, error: ${error}`);
});
audioPlayer.setVolume(3);  //设置volume为无效值，触发'error'事件。
```

## AudioState<sup>(deprecated)</sup>

type AudioState = 'idle' | 'playing' | 'paused' | 'stopped' | 'error'

音频播放的状态机。可通过state属性获取当前状态。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVPlayerState](#avplayerstate9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

| 类型    | 说明                                           |
| ------- | ---------------------------------------------- |
| 'idle'    | 音频播放空闲，dataload/reset成功后处于此状态。 |
| 'playing' | 音频正在播放，play成功后处于此状态。           |
| 'paused'  | 音频暂停播放，pause成功后处于此状态。          |
| 'stopped' | 音频播放停止，stop/播放结束后处于此状态。      |
| 'error'   | 错误状态。                                     |

## VideoPlayer<sup>(deprecated)</sup>

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer](#avplayer9)替代。

视频播放管理类，用于管理和播放视频媒体。在调用VideoPlayer的方法前，需要先通过[createVideoPlayer()](#mediacreatevideoplayerdeprecated)构建一个VideoPlayer实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称                            | 类型                                                   | 只读 | 可选 | 说明                                                         |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>                | string                                                 | 否   | 否   | 视频媒体URL，支持当前主流的视频格式(mp4、mpeg-ts、mkv)。<br>**支持路径示例**：<br>1. fd类型播放：fd://xx<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http\://xx<br/>3. https网络播放: https\://xx<br/>4. hls网络播放路径：http\://xx或者https\://xx<br>5. file类型: file\://xx<br/>**说明：**<br>从API version 11开始不支持webm。 |
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | 否   | 否   | 视频媒体文件描述，使用场景：应用中的视频资源被连续存储在同一个文件中。<br/>**使用示例**：<br/>假设一个连续存储的音乐文件: <br/>视频1(地址偏移:0，字节长度:100)<br/>视频2(地址偏移:101，字节长度:50)<br/>视频3(地址偏移:151，字节长度:150)<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的视频文件: 请使用src=fd://xx <br/> |
| loop<sup>8+</sup>               | boolean                                                | 否   | 否   | 视频循环播放属性，设置为'true'表示循环播放。                 |
| videoScaleType<sup>9+</sup>     | [VideoScaleType](#videoscaletype9)                     | 否   | 是   | 视频缩放模式。默认值为VIDEO_SCALE_TYPE_FIT。                                               |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9) | 否   | 是   | 音频焦点模型。                                               |
| currentTime<sup>8+</sup>        | number                                                 | 是   | 否   | 视频的当前播放位置，单位为毫秒（ms）。                       |
| duration<sup>8+</sup>           | number                                                 | 是   | 否   | 视频时长，单位为毫秒（ms），返回-1表示直播模式。             |
| state<sup>8+</sup>              | [VideoPlayState](#videoplaystatedeprecated)                    | 是   | 否   | 视频播放的状态。                                             |
| width<sup>8+</sup>              | number                                                 | 是   | 否   | 视频宽，单位为像素（px）。                                   |
| height<sup>8+</sup>             | number                                                 | 是   | 否   | 视频高，单位为像素（px）。                                   |

### setDisplaySurface<sup>(deprecated)</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

设置SurfaceId。通过回调函数获取返回值。

*注意：SetDisplaySurface需要在设置url和Prepare之间，无音频的视频流必须设置Surface否则Prepare失败。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.surfaceId](#属性)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名    | 类型                 | 必填 | 说明                      |
| --------- | -------------------- | ---- | ------------------------- |
| surfaceId | string               | 是   | SurfaceId.                 |
| callback  | AsyncCallback\<void> | 是   | 回调函数。当设置SurfaceId成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let surfaceId: string = '';
videoPlayer.setDisplaySurface(surfaceId, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set DisplaySurface!');
  } else {
    console.info('Succeeded in setting DisplaySurface!');
  }
});
```

### setDisplaySurface<sup>(deprecated)</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

设置SurfaceId。通过Promise获取返回值。

*注意：SetDisplaySurface需要在设置url和Prepare之间，无音频的视频流必须设置Surface否则Prepare失败。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.surfaceId](#属性)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名    | 类型   | 必填 | 说明      |
| --------- | ------ | ---- | --------- |
| surfaceId | string | 是   | SurfaceId. |

**返回值：**

| 类型           | 说明                           |
| -------------- | ------------------------------ |
| Promise\<void> | 设置SurfaceId的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let surfaceId: string = '';
videoPlayer.setDisplaySurface(surfaceId).then(() => {
  console.info('Succeeded in setting DisplaySurface');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### prepare<sup>(deprecated)</sup>

prepare(callback: AsyncCallback\<void>): void

准备播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.prepare](#prepare9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当准备播放视频成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.prepare((err: BusinessError) => {
  if (err) {
    console.error('Failed to prepare!');
  } else {
    console.info('Succeeded in preparing!');
  }
});
```

### prepare<sup>(deprecated)</sup>

prepare(): Promise\<void>

准备播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.prepare](#prepare9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 准备播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.prepare().then(() => {
  console.info('Succeeded in preparing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### play<sup>(deprecated)</sup>

play(callback: AsyncCallback\<void>): void

开始播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.play](#play9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当开始播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.play((err: BusinessError) => {
  if (err) {
    console.error('Failed to play!');
  } else {
    console.info('Succeeded in playing!');
  }
});
```

### play<sup>(deprecated)</sup>

play(): Promise\<void>

开始播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.play](#play9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 开始播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.play().then(() => {
  console.info('Succeeded in playing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### pause<sup>(deprecated)</sup>

pause(callback: AsyncCallback\<void>): void

通过回调方式暂停播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.pause](#pause9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当暂停播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.pause((err: BusinessError) => {
  if (err) {
    console.error('Failed to pause!');
  } else {
    console.info('Succeeded in pausing!');
  }
});
```

### pause<sup>(deprecated)</sup>

pause(): Promise\<void>

暂停播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.pause](#pause9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 暂停播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.pause().then(() => {
  console.info('Succeeded in pausing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void>): void

通过回调方式停止播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.stop](#stop9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当停止播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.stop((err: BusinessError) => {
  if (err) {
    console.error('Failed to stop!');
  } else {
    console.info('Succeeded in stopping!');
  }
});
```

### stop<sup>(deprecated)</sup>

stop(): Promise\<void>

停止播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.stop](#stop9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 停止播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.stop().then(() => {
  console.info('Succeeded in stopping');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### reset<sup>(deprecated)</sup>

reset(callback: AsyncCallback\<void>): void

重置播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.reset](#reset9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当重置播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.reset((err: BusinessError) => {
  if (err) {
    console.error('Failed to reset!');
  } else {
    console.info('Succeeded in resetting!');
  }
});
```

### reset<sup>(deprecated)</sup>

reset(): Promise\<void>

重置播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.reset](#reset9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.reset().then(() => {
  console.info('Succeeded in resetting');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

跳转到指定播放位置，默认跳转到指定时间点的上一个关键帧。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.seek](#seek9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| callback | AsyncCallback\<number> | 是   | 回调函数。跳转到指定播放位置成功时，err为undefined，data为获取到的跳转到的播放位置，否则为错误对象。                               |

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

let seekTime: number = 5000;
videoPlayer.seek(seekTime, (err: BusinessError, result: number) => {
  if (err) {
    console.error('Failed to do seek!');
  } else {
    console.info('Succeeded in doing seek!');
  }
});
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void

跳转到指定播放位置。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.seek](#seek9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| mode     | [SeekMode](#seekmode8) | 是   | 跳转模式。                                                   |
| callback | AsyncCallback\<number> | 是   | 回调函数。跳转到指定播放位置成功时，err为undefined，data为获取到的跳转到的播放位置，否则为错误对象。                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let seekTime: number = 5000;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC, (err: BusinessError, result: number) => {
    if (err) {
      console.error('Failed to do seek!');
    } else {
      console.info('Succeeded in doing seek!');
    }
  });
}
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number, mode?:SeekMode): Promise\<number>

跳转到指定播放位置，如果没有设置mode则跳转到指定时间点的上一个关键帧。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.seek](#seek9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| mode   | [SeekMode](#seekmode8) | 否   | 基于视频I帧的跳转模式，默认为SEEK_PREV_SYNC模式。            |

**返回值：**

| 类型             | 说明                                        |
| ---------------- | ------------------------------------------- |
| Promise\<number> | 跳转到指定播放位置的Promise返回值，单位ms。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let seekTime: number = 5000;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).seek(seekTime).then((seekDoneTime: number) => { // seekDoneTime表示seek完成后的时间点。
    console.info('Succeeded in doing seek');
  }).catch((error: BusinessError) => {
    console.error(`video catchCallback, error:${error}`);
  });

  (videoPlayer as media.VideoPlayer).seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC).then((seekDoneTime: number) => {
    console.info('Succeeded in doing seek');
  }).catch((error: BusinessError) => {
    console.error(`video catchCallback, error:${error}`);
  });
}
```

### setVolume<sup>(deprecated)</sup>

setVolume(vol: number, callback: AsyncCallback\<void>): void

设置音量。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setVolume](#setvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| vol      | number               | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当设置音量成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let vol: number = 0.5;
videoPlayer.setVolume(vol, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set Volume!');
  } else {
    console.info('Succeeded in setting Volume!');
  }
});
```

### setVolume<sup>(deprecated)</sup>

setVolume(vol: number): Promise\<void>

设置音量。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setVolume](#setvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 设置音量的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let vol: number = 0.5;
videoPlayer.setVolume(vol).then(() => {
  console.info('Succeeded in setting Volume');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### release<sup>(deprecated)</sup>

release(callback: AsyncCallback\<void>): void

释放视频资源。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.release](#release9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当释放视频资源成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.release((err: BusinessError) => {
  if (err) {
    console.error('Failed to release!');
  } else {
    console.info('Succeeded in releasing!');
  }
});
```

### release<sup>(deprecated)</sup>

release(): Promise\<void>

释放视频资源。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.release](#release9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 释放视频资源的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.release().then(() => {
  console.info('Succeeded in releasing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

获取视频轨道信息。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.getTrackDescription](#gettrackdescription9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](#mediadescription8)>> | 是   | 回调函数。获取视频轨道信息成功时，err为undefined，data为获取到的视频轨道信息MediaDescription数组，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if ((arrList) != null) {
    console.info('Succeeded in getting TrackDescription');
  } else {
    console.error(`Failed to get TrackDescription, error:${error}`);
  }
});
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

获取视频轨道信息。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.getTrackDescription](#gettrackdescription9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型                                                   | 说明                                            |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise对象，返回获取的视频轨道信息MediaDescription数组。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    console.info('Succeeded in getting TrackDescription');
  } else {
    console.error('Failed to get TrackDescription');
  }
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### setSpeed<sup>(deprecated)</sup>

setSpeed(speed: number, callback: AsyncCallback\<number>): void

设置播放速度。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setSpeed](#setspeed9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                       |
| -------- | ---------------------- | ---- | ---------------------------------------------------------- |
| speed    | number                 | 是   | 指定播放视频速度，具体见[PlaybackSpeed](#playbackspeed8)。 |
| callback | AsyncCallback\<number> | 是   | 回调函数。设置播放速度成功时，err为undefined，data为设置的播放速度，否则为错误对象。                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).setSpeed(speed, (err: BusinessError, result: number) => {
    if (err) {
      console.error('Failed to set Speed!');
    } else {
      console.info('Succeeded in setting Speed!');
    }
  });
}
```

### setSpeed<sup>(deprecated)</sup>

setSpeed(speed: number): Promise\<number>

设置播放速度。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setSpeed](#setspeed9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                       |
| ------ | ------ | ---- | ---------------------------------------------------------- |
| speed  | number | 是   | 指定播放视频速度，具体见[PlaybackSpeed](#playbackspeed8)。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise对象，返回设置的播放速度，具体见[PlaybackSpeed](#playbackspeed8)。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).setSpeed(speed).then((result: number) => {
    console.info('Succeeded in setting Speed');
  }).catch((error: BusinessError) => {
    console.error(`Failed to set Speed, error:${error}`);//todo:: error.
  });
}
```

### on('playbackCompleted')<sup>(deprecated)</sup>

on(type: 'playbackCompleted', callback: Callback\<void>): void

开始监听视频播放完成事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('stateChange')](#onstatechange9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| type     | string   | 是   | 视频播放完成事件回调类型，支持的事件：'playbackCompleted'。 |
| callback | Callback\<void> | 是   | 视频播放完成事件回调方法。                                  |

**示例：**

```ts
videoPlayer.on('playbackCompleted', () => {
  console.info('playbackCompleted called!');
});
```

### on('bufferingUpdate')<sup>(deprecated)</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

开始监听视频缓存更新事件。仅网络播放支持该订阅事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('bufferingUpdate')](#onbufferingupdate9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频缓存事件回调类型，支持的事件：'bufferingUpdate'。        |
| callback | function | 是   | 视频缓存事件回调方法。<br>[BufferingInfoType](#bufferinginfotype8)value值固定为0。 |

**示例：**

```ts
videoPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('video bufferingInfo type: ' + infoType);
  console.info('video bufferingInfo value: ' + value);
});
```

### on('startRenderFrame')<sup>(deprecated)</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

开始监听视频播放首帧送显上报事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('startRenderFrame')](#onstartrenderframe9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | 是   | 视频播放首帧送显上报事件回调类型，支持的事件：'startRenderFrame'。 |
| callback | Callback\<void> | 是   | 视频播放首帧送显上报事件回调方法。                           |

**示例：**

```ts
videoPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame called!');
});
```

### on('videoSizeChanged')<sup>(deprecated)</sup>

on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void

开始监听视频播放宽高变化事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('videoSizeChange')](#onvideosizechange9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频播放宽高变化事件回调类型，支持的事件：'videoSizeChanged'。 |
| callback | function | 是   | 视频播放宽高变化事件回调方法，width表示宽，height表示高。    |

**示例：**

```ts
videoPlayer.on('videoSizeChanged', (width: number, height: number) => {
  console.info('video width is: ' + width);
  console.info('video height is: ' + height);
});
```
### on('audioInterrupt')<sup>(deprecated)</sup>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

监听音频焦点变化事件，参考[audio.InterruptEvent](../apis-audio-kit/js-apis-audio.md#interruptevent9)。

> **说明：**
> 从API version 9开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('audioInterrupt')](#onaudiointerrupt9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'。 |
| callback | function | 是   | 音频焦点变化事件回调方法。                               |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

videoPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt called,and InterruptEvent info is:' + info);
});
```

### on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

开始监听视频播放错误事件，当上报error错误事件后，用户需处理error事件，退出播放操作。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('error')](#onerror9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 播放错误事件回调类型，支持的事件包括：'error'。<br>- 'error'：视频播放中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 播放错误事件回调方法。                                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.on('error', (error: BusinessError) => {  // 设置'error'事件回调。
  console.error(`video error called, error: ${error}`);
});
videoPlayer.url = 'fd://error';  //设置错误的播放地址，触发'error'事件。
```

## VideoPlayState<sup>(deprecated)</sup>

type VideoPlayState = 'idle' | 'prepared' | 'playing' | 'paused' | 'stopped' | 'error'

视频播放的状态机，可通过state属性获取当前状态。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayerState](#avplayerstate9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 类型     | 说明           |
| -------- | -------------- |
| 'idle'     | 视频播放空闲。 |
| 'prepared' | 视频播放准备。 |
| 'playing'  | 视频正在播放。 |
| 'paused'   | 视频暂停播放。 |
| 'stopped'  | 视频播放停止。 |
| 'error'    | 错误状态。     |

## AudioRecorder<sup>(deprecated)</sup>

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder](#avrecorder9)替代。

音频录制管理类，用于录制音频媒体。在调用AudioRecorder的方法前，需要先通过[createAudioRecorder()](#mediacreateaudiorecorderdeprecated) 构建一个AudioRecorder实例。

### prepare<sup>(deprecated)</sup>

prepare(config: AudioRecorderConfig): void

录音准备。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.prepare](#prepare9-2)替代。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**参数：**

| 参数名 | 类型                                        | 必填 | 说明                                                         |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfigdeprecated) | 是   | 配置录音的相关参数，包括音频输出URI、编码格式、采样率、声道数、输出格式等。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 201      | permission denied     |

**示例：**

```ts
let audioRecorderConfig: media.AudioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://1',       // 文件需先由调用者创建，并给予适当的权限。
  location : { latitude : 30, longitude : 130},
};
audioRecorder.on('prepare', () => {    //设置'prepare'事件回调。
  console.info('prepare called');
});
audioRecorder.prepare(audioRecorderConfig);
```

### start<sup>(deprecated)</sup>

start(): void

开始录制，需在'prepare'事件成功触发后，才能调用start方法。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.start](#start9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```ts
audioRecorder.on('start', () => {    //设置'start'事件回调。
  console.info('audio recorder start called');
});
audioRecorder.start();
```

### pause<sup>(deprecated)</sup>

pause():void

暂停录制，需要在'start'事件成功触发后，才能调用pause方法。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.pause](#pause9-2)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```ts
audioRecorder.on('pause', () => {    //设置'pause'事件回调。
  console.info('audio recorder pause called');
});
audioRecorder.pause();
```

### resume<sup>(deprecated)</sup>

resume():void

恢复录制，需要在'pause'事件成功触发后，才能调用resume方法。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.resume](#resume9)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```ts
audioRecorder.on('resume', () => {    //设置'resume'事件回调。
  console.info('audio recorder resume called');
});
audioRecorder.resume();
```

### stop<sup>(deprecated)</sup>

stop(): void

停止录音。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.stop](#stop9-2)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```ts
audioRecorder.on('stop', () => {    //设置'stop'事件回调。
  console.info('audio recorder stop called');
});
audioRecorder.stop();
```

### release<sup>(deprecated)</sup>

release(): void

释放录音资源。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.release](#release9-2)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```ts
audioRecorder.on('release', () => {    //设置'release'事件回调。
  console.info('audio recorder release called');
});
audioRecorder.release();
audioRecorder = undefined;
```

### reset<sup>(deprecated)</sup>

reset(): void

重置录音。

进行重置录音之前，需要先调用stop()停止录音。重置录音之后，需要调用prepare()设置录音参数项，才能再次进行录音。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.reset](#reset9-2)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```ts
audioRecorder.on('reset', () => {    //设置'reset'事件回调。
  console.info('audio recorder reset called');
});
audioRecorder.reset();
```

### on('prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset')<sup>(deprecated)</sup>

on(type: 'prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset', callback: () => void): void

开始订阅音频录制事件。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.on('stateChange')](#onstatechange9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 录制事件回调类型，支持的事件包括：'prepare'&nbsp;\|&nbsp;'start'&nbsp;\|  'pause' \| ’resume‘ \|&nbsp;'stop'&nbsp;\|&nbsp;'release'&nbsp;\|&nbsp;'reset'。<br/>-&nbsp;'prepare'&nbsp;：完成prepare调用，音频录制参数设置完成，触发该事件。<br/>-&nbsp;'start'&nbsp;：完成start调用，音频录制开始，触发该事件。<br/>-&nbsp;'pause': 完成pause调用，音频暂停录制，触发该事件。<br/>-&nbsp;'resume': 完成resume调用，音频恢复录制，触发该事件。<br/>-&nbsp;'stop'&nbsp;：完成stop调用，音频停止录制，触发该事件。<br/>-&nbsp;'release'&nbsp;：完成release调用，音频释放录制资源，触发该事件。<br/>-&nbsp;'reset'：完成reset调用，音频重置为初始状态，触发该事件。 |
| callback | ()=>void | 是   | 录制事件回调方法。                                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioRecorder: media.AudioRecorder = media.createAudioRecorder();  // 创建一个音频录制实例。
let audioRecorderConfig: media.AudioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://xx',  // 文件需先由调用者创建，并给予适当的权限。
  location : { latitude : 30, longitude : 130}
};
audioRecorder.on('error', (error: BusinessError) => {  // 设置'error'事件回调。
  console.error(`audio error called, error: ${error}`);
});
audioRecorder.on('prepare', () => {  // 设置'prepare'事件回调。
  console.info('prepare called');
  audioRecorder.start();  // 开始录制，并触发'start'事件回调。
});
audioRecorder.on('start', () => {  // 设置'start'事件回调。
  console.info('audio recorder start called');
});
audioRecorder.on('pause', () => {  // 设置'pause'事件回调。
  console.info('audio recorder pause called');
});
audioRecorder.on('resume', () => {  // 设置'resume'事件回调。
  console.info('audio recorder resume called');
});
audioRecorder.on('stop', () => {  // 设置'stop'事件回调。
  console.info('audio recorder stop called');
});
audioRecorder.on('release', () => {  // 设置'release'事件回调。
  console.info('audio recorder release called');
});
audioRecorder.on('reset', () => {  // 设置'reset'事件回调。
  console.info('audio recorder reset called');
});
audioRecorder.prepare(audioRecorderConfig)  // 设置录制参数 ，并触发'prepare'事件回调。
```

### on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

开始订阅音频录制错误事件，当上报error错误事件后，用户需处理error事件，退出录制操作。

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorder.on('error')](#onerror9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 录制错误事件回调类型'error'。<br/>-&nbsp;'error'：音频录制过程中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 录制错误事件回调方法。                                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioRecorderConfig: media.AudioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://xx',   // 文件需先由调用者创建，并给予适当的权限。
  location : { latitude : 30, longitude : 130}
};
audioRecorder.on('error', (error: BusinessError) => {  // 设置'error'事件回调。
  console.error(`audio error called, error: ${error}`);
});
audioRecorder.prepare(audioRecorderConfig);  // prepare不设置参数，触发'error'事件。
```

## AudioRecorderConfig<sup>(deprecated)</sup>

> **说明：**
> 从API version 6开始支持，从API version 9开始废弃，建议使用[AVRecorderConfig](#avrecorderconfig9)替代。

表示音频的录音配置。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

| 名称                                | 类型                                         | 必填 | 说明                                                         |
| ----------------------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioEncoder                        | [AudioEncoder](#audioencoderdeprecated)                | 否   | 音频编码格式，默认设置为AAC_LC。<br/>**说明：** 从API version 8开始废弃，建议使用audioEncoderMime替代。 |
| audioEncodeBitRate                  | number                                       | 否   | 音频编码比特率，默认值为48000。                              |
| audioSampleRate                     | number                                       | 否   | 音频采集采样率，默认值为48000。<br>可变比特率模式，码率仅作参考。                              |
| numberOfChannels                    | number                                       | 否   | 音频采集声道数，默认值为2。                                  |
| format                              | [AudioOutputFormat](#audiooutputformatdeprecated)      | 否   | 音频输出封装格式，默认设置为MPEG_4。<br/>**说明：** 从API version 8开始废弃，建议使用fileFormat替代。 |
| location                            | [Location](#location)                        | 否   | 音频采集的地理位置。                                         |
| uri                                 | string                                       | 是   | 音频输出URI：fd://xx&nbsp;(fd&nbsp;number)<br/>![](figures/zh-cn_image_url.png) <br/>文件需要由调用者创建，并赋予适当的权限。 |
| audioEncoderMime<sup>8+</sup>       | [CodecMimeType](#codecmimetype8)             | 否   | 容器编码格式。                                               |
| fileFormat<sup>8+</sup>             | [ContainerFormatType](#containerformattype8) | 否   | 音频编码格式。                                               |

## AudioEncoder<sup>(deprecated)</sup>

> **说明：**
> 从API version 6开始支持，从API version 8开始废弃，建议使用[CodecMimeType](#codecmimetype8)替代。

表示音频编码格式的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

| 名称    | 值   | 说明                                                         |
| ------- | ---- | ------------------------------------------------------------ |
| DEFAULT | 0    | 默认编码格式。<br/>仅做接口定义，暂不支持使用。              |
| AMR_NB  | 1    | AMR-NB(Adaptive Multi Rate-Narrow Band Speech Codec) 编码格式。<br/>仅做接口定义，暂不支持使用。 |
| AMR_WB  | 2    | AMR-WB(Adaptive Multi Rate-Wide Band Speech Codec) 编码格式。<br/>仅做接口定义，暂不支持使用。 |
| AAC_LC  | 3    | AAC-LC（Advanced&nbsp;Audio&nbsp;Coding&nbsp;Low&nbsp;Complexity）编码格式。 |
| HE_AAC  | 4    | HE_AAC（High-Efficiency Advanced&nbsp;Audio&nbsp;Coding）编码格式。<br/>仅做接口定义，暂不支持使用。 |

## AudioOutputFormat<sup>(deprecated)</sup>

> **说明：**
> 从API version 6开始支持，从API version 8 开始废弃，建议使用[ContainerFormatType](#containerformattype8)替代。

表示音频封装格式的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

| 名称     | 值   | 说明                                                         |
| -------- | ---- | ------------------------------------------------------------ |
| DEFAULT  | 0    | 默认封装格式。<br/>仅做接口定义，暂不支持使用。              |
| MPEG_4   | 2    | 封装为MPEG-4格式。                                           |
| AMR_NB   | 3    | 封装为AMR_NB格式。<br/>仅做接口定义，暂不支持使用。          |
| AMR_WB   | 4    | 封装为AMR_WB格式。<br/>仅做接口定义，暂不支持使用。          |
| AAC_ADTS | 6    | 封装为ADTS（Audio&nbsp;Data&nbsp;Transport&nbsp;Stream）格式，是AAC音频的传输流格式。 |


## media.createAVImageGenerator<sup>12+</sup>

createAVImageGenerator(callback: AsyncCallback\<AVImageGenerator>): void

创建AVImageGenerator实例，通过回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVImageGenerator](#avimagegenerator12)> | 是   | 回调函数。异步返回AVImageGenerator实例，失败时返回null。可用于获取视频缩略图。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
| Promise\<[AVImageGenerator](#avimagegenerator12)> | Promise对象。异步返回AVImageGenerator实例，失败时返回null。可用于获取视频缩略图。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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

## AVImageGenerator<sup>12+</sup>

视频缩略图获取类，用于从视频资源中获取缩略图。在调用AVImageGenerator的方法前，需要先通过[createAVImageGenerator()](#mediacreateavimagegenerator12)构建一个AVImageGenerator实例。

获取视频缩略图的demo可参考：[获取视频缩略图开发指导](../../media/media/avimagegenerator.md)。

### 属性

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

| 名称                                                | 类型                                                         | 可读 | 可写 | 说明                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fdSrc<sup>12+</sup>                                  | [AVFileDescriptor](js-apis-media.md#avfiledescriptor9)                       | 是   | 是   | 媒体文件描述，通过该属性设置数据源。<br/> **使用示例**：<br/>假设一个连续存储的媒体文件，地址偏移:0，字节长度:100。其文件描述为 AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br>**说明：** <br> - 将资源句柄（fd）传递给 AVImageGenerator 实例之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个 AVPlayer / AVMetadataExtractor / AVImageGenerator / AVTranscoder。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致视频缩略图数据获取异常。 |

### fetchFrameByTime<sup>12+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams, callback: AsyncCallback\<image.PixelMap>): void

异步方式获取视频缩略图。通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | 是   | 需要获取的缩略图在视频中的时间点，单位为微秒（μs）。 |
| options | [AVImageQueryOptions](#avimagequeryoptions12)     | 是   | 需要获取的缩略图时间点与视频帧的对应关系。 |
| param | [PixelMapParams](#pixelmapparams12)     | 是   | 需要获取的缩略图的格式参数。 |
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)>   | 是   | 回调函数。获取缩略图成功时，err为undefined，data为PixelMap实例，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// 初始化入参。
let timeUs: number = 0;

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC;

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
};

// 获取缩略图。
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param, (error: BusinessError, pixelMap) => {
      if (error) {
        console.error(`Failed to fetch FrameByTime, err = ${JSON.stringify(error)}`);
        return;
      }
      pixel_map = pixelMap;
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

### fetchFrameByTime<sup>12+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams): Promise<image.PixelMap>

异步方式获取视频缩略图。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | 是   | 需要获取的缩略图在视频中的时间点，单位为微秒（μs）。 |
| options | [AVImageQueryOptions](#avimagequeryoptions12)     | 是   | 需要获取的缩略图时间点与视频帧的对应关系。 |
| param | [PixelMapParams](#pixelmapparams12)    | 是   | 需要获取的缩略图的格式参数。 |

**返回值：**

| 类型           | 说明                                     |
| -------------- | ---------------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | Promise对象，返回视频缩略图对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// 初始化入参。
let timeUs: number = 0;

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC;

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
};

// 获取缩略图。
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param).then((pixelMap: image.PixelMap) => {
      pixel_map = pixelMap;
    }).catch((error: BusinessError) => {
      console.error(`Failed to fetch FrameByTime, error message:${error.message}`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

### fetchScaledFrameByTime<sup>20+</sup>

fetchScaledFrameByTime(timeUs: number, queryMode: AVImageQueryOptions, outputSize?: OutputSize):Promise\<image.PixelMap\>

支持按比例缩放提取视频缩略图。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**参数：**

| 参数名     | 类型                                          | 必填 | 说明                                                 |
| ---------- | --------------------------------------------- | ---- | ---------------------------------------------------- |
| timeUs     | number                                        | 是   | 在视频中需要获取的缩略图的时间点，单位为微秒（μs）。 |
| queryMode  | [AVImageQueryOptions](#avimagequeryoptions12) | 是   | 需要获取的缩略图时间点与视频帧的对应关系。           |
| outputSize | [OutputSize ](#outputsize20)                  | 否   | 定义帧的输出大小。默认按原图大小显示。               |

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | Promise对象。返回视频缩略图对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';
let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;
// 初始化入参。
let timeUs: number = 0;
let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC;
let outputSize: media.OutputSize = {
  width : 300,
  height : 300,
};
// 获取缩略图。
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.fetchScaledFrameByTime(timeUs, queryOption, outputSize).then((pixelMap: image.PixelMap) => {
      pixel_map = pixelMap;
    }).catch((error: BusinessError) => {
      console.error(`Failed to fetch ScaledFrameByTime, error message:${error.message}`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

### release<sup>12+</sup>

release(callback: AsyncCallback\<void>): void

异步方式释放资源。通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<void>                   | 是   | 回调函数。当释放资源成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

//释放资源。
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.release((error: BusinessError) => {
      if (error) {
        console.error(`Failed to release, err = ${JSON.stringify(error)}`);
        return;
      }
      console.info(`Succeeded in releasing`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

### release<sup>12+</sup>

release(): Promise\<void>

异步方式释放资源。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**返回值：**

| 类型           | 说明                                     |
| -------------- | ---------------------------------------- |
| Promise\<void> | 异步方式释放资源release方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

//释放资源
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`Succeeded in creating AVImageGenerator`);
    avImageGenerator.release().then(() => {
      console.info(`Succeeded in releasing.`);
    }).catch((error: BusinessError) => {
      console.error(`Failed to release, error message:${error.message}`);
    });
  } else {
    console.error(`Failed to creat AVImageGenerator, error message:${err.message}`);
  };
});
```

## AVImageQueryOptions<sup>12+</sup>

需要获取的缩略图时间点与视频帧的对应关系。

在获取视频缩略图时，传入的时间点与实际取得的视频帧所在时间点不一定相等，需要指定传入的时间点与实际取得的视频帧的时间关系。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

| 名称                     | 值              | 说明                                                         |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| AV_IMAGE_QUERY_NEXT_SYNC       | 0   | 表示选取传入时间点或之后的关键帧。                       |
| AV_IMAGE_QUERY_PREVIOUS_SYNC        | 1    | 表示选取传入时间点或之前的关键帧。 |
| AV_IMAGE_QUERY_CLOSEST_SYNC        | 2    | 表示选取离传入时间点最近的关键帧。                 |
| AV_IMAGE_QUERY_CLOSEST             | 3    | 表示选取离传入时间点最近的帧，该帧不一定是关键帧。 |

## PixelMapParams<sup>12+</sup>

获取视频缩略图时，输出缩略图的格式参数。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

| 名称   | 类型   | 可读 | 可写 | 说明                                                                            |
|--------|--------|------|------|---------------------------------------------------------------------------------|
| width  | number | 是   | 是   | 输出的缩略图宽度。应保证大于0且不大于原始视频宽度。否则返回的缩略图不会进行缩放。 |
| height | number | 是   | 是   | 输出的缩略图高度。应保证大于0且不大于原始视频高度。否则返回的缩略图不会进行缩放。 |

## OutputSize<sup>20+</sup>

用于获取视频缩略图时，来定义输出图像大小。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

| 名称   | 类型   | 只读 | 可选 | 说明                                                         |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| width  | number | 否   | 是   | 输出的缩略图宽度。<br/>- 如果该值小于0，宽度是视频的原始宽度。<br/>- 如果值为0或未分配任何值，缩放比例同高度比例。 |
| height | number | 否   | 是   | 输出的缩略图高度。<br/>- 如果该值小于0，高度是视频的原始高度。<br/>- 如果值为0或未分配任何值，缩放比例同宽度比例。 |

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
| [MediaSource](#mediasource12) | MediaSource返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)

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
import { common } from '@kit.AbilityKit';
import { resourceManager } from '@kit.LocalizationKit';

private context: Context | undefined;
constructor(context: Context) {
  this.context = context; // this.getUIContext().getHostContext();
}
let mgr = this.context.resourceManager;
let fileDescriptor = await mgr.getRawFd("xxx.m3u8");

let fd:string = fileDescriptor.fd.toString();
let offset:string = fileDescriptor.offset.toString();
let length:string = fileDescriptor.length.toString();
let fdUrl:string = "fd://" + fd + "?offset=" + offset + "&size=" + length;

let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl,  headers);

let mimeType : media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
mediaSource.setMimeType(mimeType);

```
## media.createMediaSourceWithStreamData<sup>19+</sup>

createMediaSourceWithStreamData(streams: Array\<MediaStream>): MediaSource

创建流媒体多码率媒体来源实例方法，当前仅支持HTTP-FLV协议格式多码率。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名  | 类型                                 | 必填 | 说明                                                  |
| ------- | ------------------------------------ | ---- | ----------------------------------------------------- |
| streams | Array<[MediaStream](#mediastream19)> | 是 | 可设置MediaStream数组，支持的流媒体格式：HTTP-FLV。 |

**返回值：**

| 类型                          | 说明                |
| ----------------------------- | ------------------- |
| [MediaSource](#mediasource12) | 返回MediaSource，用于媒体资源设置。 |

**示例1：**

```ts
let streams : Array<media.MediaStream> = [];
streams.push({url: "http://xxx/480p.flv", width: 854, height: 480, bitrate: 800000});
streams.push({url: "http://xxx/720p.flv", width: 1280, height: 720, bitrate: 2000000});
streams.push({url: "http://xxx/1080p.flv", width: 1280, height: 720, bitrate: 2000000});
let mediaSource : media.MediaSource = media.createMediaSourceWithStreamData(streams);
```

## MediaStream<sup>19+</sup>

媒体流数据信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称  | 类型   | 只读 | 可选 | 说明                                                         |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| url     | string | 否   | 否   | 媒体资源链接，当前仅支持http或者https。                                                 |
| width   | number | 否   | 否   | 媒体资源视频宽像素值。未知时可以填0，此时将无法通过[PlaybackStrategy](#playbackstrategy12)优选匹配。 |
| height  | number | 否   | 否   | 媒体资源视频高像素值。未知时可以填0，此时将无法通过[PlaybackStrategy](#playbackstrategy12)优选匹配。 |
| bitrate | number | 否   | 否   | 媒体资源码率值，单位bps。                                        |

## MediaSource<sup>12+</sup>

媒体数据信息。来源自[createMediaSourceWithUrl](#mediacreatemediasourcewithurl12)。

**系统能力：** SystemCapability.Multimedia.Media.Core

### setMimeType<sup>12+</sup>

setMimeType(mimeType: AVMimeTypes): void

设置媒体MIME类型，以帮助播放器处理扩展的媒体源。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| mimeType | [AVMimeTypes](#mediasource12) | 是   | 媒体MIME类型。 |

### setMediaResourceLoaderDelegate<sup>18+</sup>

setMediaResourceLoaderDelegate(resourceLoader: MediaSourceLoader): void

设置MediaSourceLoader，帮助播放器请求媒体数据。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| resourceLoader | [MediaSourceLoader](#mediasourceloader18) | 是   | 应用实现的媒体数据获取接口，方便播放器获取数据。 |

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';

let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();

let sourceOpenCallback: media.SourceOpenCallback = (request: media.MediaSourceLoadingRequest) => {
  console.log(`Opening resource: ${request.url}`);
  // 成功打开资源，返回唯一的句柄, 保证uuid和request对应。
  uuid += 1;
  requests.set(uuid, request);
  return uuid;
};

let sourceReadCallback: media.SourceReadCallback = (uuid: number, requestedOffset: number, requestedLength: number) => {
  console.log(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
  // 判断uuid是否合法、存储read请求，不要在read请求阻塞去推送数据和头信息。
};

let sourceCloseCallback: media.SourceCloseCallback = (uuid: number) => {
  console.log(`Closing resource with handle ${uuid}`);
  // 清除当前uuid相关资源。
  requests.remove(uuid);
};

// 应用按需实现。
let resourceLoader: media.MediaSourceLoader = {
  open: sourceOpenCallback,
  read: sourceReadCallback,
  close: sourceCloseCallback
};

mediaSource.setMediaResourceLoaderDelegate(resourceLoader);
```

## SourceOpenCallback<sup>18+</sup>

type SourceOpenCallback = (request: MediaSourceLoadingRequest) => number

由应用实现此回调函数，应用需处理传入的资源打开请求，并返回所打开资源对应的唯一句柄。
>
>**注意：** 客户端在处理完请求后应立刻返回。
>

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| request | [MediaSourceLoadingRequest](#mediasourceloadingrequest18) | 是  | 	打开请求参数，包含请求资源的具体信息和数据推送方式。 |

**返回值：**

| 类型   | 说明                 |
| -------- | -------------------- |
| number  | 当前资源打开请求的句柄。大于0表示请求成功，小于或等于0表示请求失败。<br/> - request对象对应句柄唯一。|

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';

let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();

let sourceOpenCallback: media.SourceOpenCallback = (request: media.MediaSourceLoadingRequest) => {
  console.log(`Opening resource: ${request.url}`);
  // 成功打开资源，返回唯一的句柄, 保证uuid和request对应。
  uuid += 1;
  requests.set(uuid, request);
  return uuid;
};
```

## SourceReadCallback<sup>18+</sup>

type SourceReadCallback = (uuid: number, requestedOffset: number, requestedLength: number) => void

由应用实现此回调函数，应用需记录读取请求，并在数据充足时通过对应的MediaSourceLoadingRequest对象的[respondData](#responddata18)方法推送数据。
>
>**注意：** 客户端在处理完请求后应立刻返回。
>

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| uuid | number | 是  | 	资源句柄的标识。 |
| requestedOffset | number | 是  | 	当前媒体数据相对于资源起始位置的偏移量。 |
| requestedLength | number | 是  | 	当前请求的长度。值为-1时，表示到达资源末尾，此时推送完成后需通过[finishLoading](#finishloading18)方法通知播放器推送结束。 |

**示例：**

```ts
let sourceReadCallback: media.SourceReadCallback = (uuid: number, requestedOffset: number, requestedLength: number) => {
  console.log(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
  // 判断uuid是否合法、存储read请求，不要在read请求阻塞去推送数据和头信息。
};
```

## SourceCloseCallback<sup>18+</sup>

type SourceCloseCallback = (uuid: number) => void

由应用实现此回调函数，应用应释放相关资源。
>
>**注意：** 客户端在处理完请求后应立刻返回。
>

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| uuid      | number | 是  | 	资源句柄的标识。 |

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';

let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();

let sourceCloseCallback: media.SourceCloseCallback = (uuid: number) => {
  console.log(`Closing resource with handle ${uuid}`);
  // 清除当前uuid相关资源。
  requests.remove(uuid);
};
```

## MediaSourceLoader<sup>18+</sup>

用于定义媒体数据加载器，需要应用程序对其进行实现。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| open | [SourceOpenCallback](#sourceopencallback18) | 是  | 由应用程序实现的回调函数，用于处理资源打开请求。 |
| read | [SourceReadCallback](#sourcereadcallback18) | 是  | 由应用程序实现的回调函数，用于处理资源读取请求。 |
| close | [SourceCloseCallback](#sourceclosecallback18) | 是  | 由应用程序实现的回调函数，用于处理资源关闭请求。 |

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';

let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
let uuid: number = 1;
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let mediaSourceLoader: media.MediaSourceLoader = {
  open: (request: media.MediaSourceLoadingRequest) => {
    console.log(`Opening resource: ${request.url}`);
    // 成功打开资源，返回唯一的句柄, 保证uuid和request对应。
    uuid += 1;
    requests.set(uuid, request);
    return uuid;
  },
  read: (uuid: number, requestedOffset: number, requestedLength: number) => {
    console.log(`Reading resource with handle ${uuid}, offset: ${requestedOffset}, length: ${requestedLength}`);
    // 判断uuid是否合法、存储read请求，不要在read请求阻塞去推送数据和头信息。
  },
  close: (uuid: number) => {
    console.log(`Closing resource with handle ${uuid}`);
    // 清除当前uuid相关资源。
    requests.remove(uuid);
  }
};

mediaSource.setMediaResourceLoaderDelegate(mediaSourceLoader);
let playStrategy : media.PlaybackStrategy = {
  preferredBufferDuration: 20,
};

async function setupPlayer() {
  let player = await media.createAVPlayer();
  player.setMediaSource(mediaSource, playStrategy);
}
```

## MediaSourceLoadingRequest<sup>18+</sup>

用于定义加载请求的对象。应用程序通过该对象来获取请求的资源位置，通过该对象和播放器进行数据交互。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

### 属性

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型    | 只读   | 可选   | 说明                |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url        | string                        | 否   | 否   | 资源url，需要应用程序打开的资源路径。 |
| header     | Record<string, string>        | 否   | 是   | 网络请求标头，如果存在需要应用在下载数据是将头信息设置到http请求中。 |

### respondData<sup>18+</sup>

respondData(uuid: number, offset: number, buffer: ArrayBuffer): number

用于应用程序向播放器发送数据。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| uuid | number | 是  | 	资源句柄的标识。 |
| offset | number | 是  | 	当前媒体数据相对于资源起始位置的偏移量。 |
| buffer | ArrayBuffer | 是  | 	响应播放器的媒体数据。<br/>**注意：** 不要传输无关数据，会影响正常数据解析和播放。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| number | 当前服务端接受的字节数。<br>- 返回值小于0表示操作失败。<br>- 返回值为-2时，表示播放器不再需要当前数据，客户端应停止当前读取过程。<br>- 返回值为-3时，表示播放器的缓冲区已满，客户端应等待下一次读取。 |

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let uuid = 1;

let request = requests.get(uuid);
let offset = 0; // 当前媒体数据相对于资源起始位置的偏移量
let buf = new ArrayBuffer(0); // 由应用定义，推送给播放器的数据
let num = request.respondData(uuid, offset, buf);
```

### respondHeader<sup>18+</sup>

respondHeader(uuid: number, header?: Record<string, string>, redirectUrl?: string): void

用于应用程序向播放器发送响应头信息，应在第一次调用[respondData](#responddata18)方法之前调用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| uuid | number | 是  | 	资源句柄的标识。 |
| header | Record<string, string> | 否  | HTTP响应中的头部信息。应用可将头部信息字段与底层支持解析字段取交集传递或直接传入对应的所有头部信息。<br> - 底层播放需要解析的字段包括Transfer-Encoding、Location、Content-Type、Content-Range、Content-Encode、Accept-Ranges、content-length。 |
| redirectUrl | string | 否  | 	如果存在，为HTTP响应中的重定向URL。 |

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let uuid = 1;

// 应用根据情况填充。
let header:Record<string, string> = {
  'Transfer-Encoding':'xxx',
  'Location' : 'xxx',
  'Content-Type' : 'xxx',
  'Content-Range' : 'xxx',
  'Content-Encode' : 'xxx',
  'Accept-Ranges' : 'xxx',
  'content-length' : 'xxx'
};
let request = requests.get(uuid);
request.respondHeader(uuid, header);
```

### finishLoading<sup>18+</sup>

finishLoading(uuid: number, state: LoadingRequestError): void

应用程序用于通知播放器当前请求状态的接口。针对服务侧请求的单个资源，推送完全部资源后需要发送LOADING_ERROR_SUCCESS状态告知该资源推送结束。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| uuid | number | 是  | 	资源句柄的标识。 |
| state  | [LoadingRequestError](#loadingrequesterror18) | 是  | 请求的状态。 |

**示例：**

```ts
import HashMap from '@ohos.util.HashMap';
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let uuid = 1;

let request = requests.get(uuid);
let loadingError = media.LoadingRequestError.LOADING_ERROR_SUCCESS;
request.finishLoading(uuid, loadingError);
```

## LoadingRequestError<sup>18+</sup>

枚举，数据加载过程中状态变化的原因。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                 | 值   | 说明                           |
| -------------------- | ---- | ------------------------------ |
| LOADING_ERROR_SUCCESS | 0    | 由客户端返回，表示已经推送到资源末尾。 |
| LOADING_ERROR_NOT_READY | 1    | 由客户端返回，表示资源尚未准备好可供访问。|
| LOADING_ERROR_NO_RESOURCE | 2    | 由客户端返回，表示请求的资源URL不存在。 |
| LOADING_ERROR_INVAID_HANDLE | 3    | 由客户端返回，表示请求的资源句柄uuid无效。 |
| LOADING_ERROR_ACCESS_DENIED | 4    | 由客户端返回，表示客户端没有权限请求该资源。 |
| LOADING_ERROR_ACCESS_TIMEOUT | 5    | 由客户端返回，表示访问资源过程超时。 |
| LOADING_ERROR_AUTHORIZE_FAILED | 6    | 由客户端返回，表示授权失败。 |

## AVMimeTypes<sup>12+</sup>

媒体MIME类型，通过[setMimeType](#setmimetype12)设置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.Core


| 名称       | 值   | 说明                                                         |
| ---------- | ---- | ------------------------------------------------------------ |
| APPLICATION_M3U8       | application/m3u8    | 表示m3u8本地文件。 |


## PlaybackStrategy<sup>12+</sup>

播放策略。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称  | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| preferredWidth| number | 否   | 播放策略首选宽度，设置范围为大于0的整数，如1080，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| preferredHeight | number | 否   | 播放策略首选高度，设置范围为大于0的整数，如1920，单位为像素（px）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| preferredBufferDuration | number | 否  | 播放策略首选缓冲持续时间，单位s，取值范围1-20。<br>具体使用方式可参考[在线视频播放卡顿优化实践](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-online-video-playback-lags-practice)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| preferredHdr | boolean | 否   | 播放策略true是hdr，false非hdr，默认非hdr。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| enableSuperResolution<sup>18+</sup> | boolean | 否   | 表示是否使能超分功能。true表示使能超分，false表示不使能超分，默认为false。<br>若不使能超分，则后续不能调用超分相关接口。若使能超分，则超分功能默认开启，默认目标分辨率为1920x1080，单位为像素。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| showFirstFrameOnPrepare<sup>17+</sup> | boolean | 否   | 播放策略true是Prepare之后显示视频起播首帧，false是Prepare之后不显示视频起播首帧，默认不显示。<br>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。 |
| mutedMediaType | [MediaType](#mediatype8) | 否 | 静音播放的媒体类型，仅支持设置 MediaType.MEDIA_TYPE_AUD。 |
| preferredAudioLanguage<sup>13+</sup> | string | 否 | 播放策略首选音轨语言。dash场景下应用可按需设置。非dash场景暂不支持，建议缺省。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |
| preferredSubtitleLanguage<sup>13+</sup> | string | 否 | 播放策略首选字幕语言。dash场景下应用可按需设置。非dash场景暂不支持，建议缺省。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |
| preferredBufferDurationForPlaying<sup>18+</sup> | number | 否 | 播放策略首选起播缓冲水线。当起播缓冲时间超过该值，开始播放。单位s，取值范围0-20。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| thresholdForAutoQuickPlay<sup>18+</sup> | number | 否 | 智能追帧水线，单位为s，取值应不小于2s，且需大于起播缓冲水线，默认设置为5s。<br>播放策略可以通过设置智能追帧水线来保证直播的实时性。flv直播场景下应用可按需设置，非flv直播场景暂不支持。网络状态的变化可能会导致播放器在某段时间内积压大量数据。播放器会定期检查当前播放时间与缓存中最新的帧时间戳之间的差值，当这个差值过大时，播放器将以1.2倍速开始智能追帧。[speedDone事件](#onspeeddone9)会回调特定值100，表示智能追帧开启成功。当差值小于起播缓冲水线时，则停止追帧并恢复到正常播放速度。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |

## AVScreenCaptureRecordPreset<sup>12+</sup>

进行屏幕录制时的编码、封装格式参数的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

| 名称                              | 值   | 说明                                         |
| --------------------------------- | ---- | -------------------------------------------- |
| SCREEN_RECORD_PRESET_H264_AAC_MP4 | 0    | 使用视频H264编码，音频AAC编码，MP4封装格式。 |
| SCREEN_RECORD_PRESET_H265_AAC_MP4 | 1    | 使用视频H265编码，音频AAC编码，MP4封装格式。 |

## AVScreenCaptureStateCode<sup>12+</sup>

屏幕录制的状态回调。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

| 名称                                     | 值   | 说明                     |
| ---------------------------------------- | ---- | ------------------------ |
| SCREENCAPTURE_STATE_STARTED              | 0    | 录屏已开始。             |
| SCREENCAPTURE_STATE_CANCELED             | 1    | 录屏被取消。             |
| SCREENCAPTURE_STATE_STOPPED_BY_USER      | 2    | 录屏被用户手动停止。     |
| SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER | 3    | 录屏被其他录屏打断。     |
| SCREENCAPTURE_STATE_STOPPED_BY_CALL      | 4    | 录屏被来电打断。         |
| SCREENCAPTURE_STATE_MIC_UNAVAILABLE      | 5    | 录屏无法使用麦克风收音。 |
| SCREENCAPTURE_STATE_MIC_MUTED_BY_USER    | 6    | 麦克风被用户关闭。       |
| SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER  | 7    | 麦克风被用户打开。       |
| SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE  | 8    | 录屏进入隐私页面。       |
| SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE   | 9    | 录屏退出隐私页面。       |
| SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES   | 10    | 系统用户切换，录屏中断。       |

## AVScreenCaptureFillMode<sup>18+</sup>

进行屏幕录制时视频填充模式的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

| 名称                              | 值   | 说明                                         |
| --------------------------------- | ---- | -------------------------------------------- |
| PRESERVE_ASPECT_RATIO | 0    | 保持与原始图像相同的宽高比例，即与物理屏幕宽高比例一致。 |
| SCALE_TO_FILL | 1    | 进行图像拉伸填充，适配设置的宽度和高度。 |

## AVScreenCaptureStrategy<sup>20+</sup>

录屏策略。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

| 名称                  | 类型    | 必填 | 说明                 |
| --------------------- | ------- | --- | -------------------- |
| keepCaptureDuringCall | boolean | 否  | 蜂窝通话时是否保持录屏。 |

## AVScreenCaptureRecordConfig<sup>12+</sup>

表示录屏参数配置。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

| 名称              | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| fd                | number                                                       | 是   | 录制输出的文件fd。                                           |
| frameWidth        | number                                                       | 否   | 录屏的视频宽度，默认屏幕宽度，根据不同屏幕默认值不同，单位px。 |
| frameHeight       | number                                                       | 否   | 录屏的视频高度，默认屏幕高度，根据不同屏幕默认值不同，单位px。 |
| videoBitrate      | number                                                       | 否   | 录屏的视频比特率，默认10000000。                             |
| audioSampleRate   | number                                                       | 否   | 录屏的音频采样率，内录的系统音和外录的麦克风都是用此采样率，默认48000，仅支持设置48000或16000。 |
| audioChannelCount | number                                                       | 否   | 录屏的音频通道数，内录的系统音和外录的麦克风都是用此通道数，默认2声道，仅支持设置1或2声道。 |
| audioBitrate      | number                                                       | 否   | 录屏的音频比特率，内录的系统音和外录的麦克风都是用此比特率，默认96000。 |
| preset            | [AVScreenCaptureRecordPreset](#avscreencapturerecordpreset12) | 否   | 录屏使用的编码和封装格式，默认SCREEN_RECORD_PRESET_H264_AAC_MP4格式。 |
| displayId<sup>15+</sup>            | number | 否   | 指定录屏使用的屏幕，默认主屏幕。 |
| fillMode<sup>18+</sup>            | [AVScreenCaptureFillMode](#avscreencapturefillmode18)| 否   | 录屏时视频流的填充模式。 |
| strategy<sup>20+</sup>            | [AVScreenCaptureStrategy](#avscreencapturestrategy20)| 否   | 录屏策略。 |

## AVScreenCaptureRecorder<sup>12+</sup>

屏幕录制管理类，用于进行屏幕录制。在调用AVScreenCaptureRecorder的方法前，需要先通过[createAVScreenCaptureRecorder()](#mediacreateavscreencapturerecorder12)创建一个AVScreenCaptureRecorder实例。

### init<sup>12+</sup>

init(config: AVScreenCaptureRecordConfig): Promise\<void>

异步方式进行录屏初始化，设置录屏参数。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| config | [AVScreenCaptureRecordConfig](#avscreencapturerecordconfig12) | 是   | 配置屏幕录制的相关参数。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<void> | 异步录屏初始化方法的Promise返回值。 |

**错误码：**

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. Return by promise. |
| 5400103  | IO error. Return by promise.                   |
| 5400105  | Service died. Return by promise.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avCaptureConfig: media.AVScreenCaptureRecordConfig = {
    fd: 0, // 文件需要先有调用者创建，赋予写权限，将文件fd传给此参数。
    frameWidth: 640,
    frameHeight: 480
    // 补充其他参数。
};

avScreenCaptureRecorder.init(avCaptureConfig).then(() => {
    console.info('Succeeded in initing avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to init avScreenCaptureRecorder, error: ' + err.message);
});
```

### startRecording<sup>12+</sup>

startRecording(): Promise\<void>

异步方式开始录屏。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                             |
| -------------- | -------------------------------- |
| Promise\<void> | 异步开始录屏方法的Promise返回值. |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.startRecording().then(() => {
    console.info('Succeeded in starting avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to start avScreenCaptureRecorder, error: ' + err.message);
});
```

### stopRecording<sup>12+</sup>

stopRecording(): Promise\<void>

异步方式结束录屏。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | 异步结束录屏方法的Promise返回值。 |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.stopRecording().then(() => {
    console.info('Succeeded in stopping avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to stop avScreenCaptureRecorder, error: ' + err.message);
});
```

### skipPrivacyMode<sup>12+</sup>

skipPrivacyMode(windowIDs: Array\<number>): Promise\<void>

录屏时，应用可对本应用的隐私窗口做安全豁免。通过Promise获取返回值。
如录屏时，用户在本应用进行输入密码等操作，应用不会进行黑屏处理。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| windowIDs | Array\<number> | 是   | 需要豁免隐私的窗口列表，包括主窗口id和子窗口id，窗口属性获取方法可以参考[窗口API引用](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)。 |

**返回值：**

| 类型           | 说明                             |
| -------------- | -------------------------------- |
| Promise\<void> | 豁免隐私窗口的Promise返回值. |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowIDs = [];
avScreenCaptureRecorder.skipPrivacyMode(windowIDs).then(() => {
    console.info('Succeeded in skipping privacy mode');
}).catch((err: BusinessError) => {
    console.info('Failed to skip privacy mode, error: ' + err.message);
});
```

### setMicEnabled<sup>12+</sup>

setMicEnabled(enable: boolean): Promise\<void>

异步方式设置麦克风开关。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| enable | boolean | 是   | 麦克风开关控制，true代表麦克风打开，false代表麦克风关闭。 |

**返回值：**

| 类型           | 说明                                    |
| -------------- | --------------------------------------- |
| Promise\<void> | 异步设置麦克风开关方法的Promise返回值。 |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.setMicEnabled(true).then(() => {
    console.info('Succeeded in setMicEnabled avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to setMicEnabled avScreenCaptureRecorder, error: ' + err.message);
});
```

### release<sup>12+</sup>

release(): Promise\<void>

异步方式释放录屏。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | 异步释放录屏方法的Promise返回值。 |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.release().then(() => {
    console.info('Succeeded in releasing avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Faile to release avScreenCaptureRecorder, error: ' + err.message);
});
```

### on('stateChange')<sup>12+</sup>

on(type: 'stateChange', callback: Callback\<AVScreenCaptureStateCode>): void

订阅录屏状态切换的事件，当状态发生的时候，会通过订阅的回调通知用户。用户只能订阅一个状态切换的回调方法，重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'stateChange'。            |
| callback | function | 是   | 状态切换事件回调方法，[AVScreenCaptureStateCode](#avscreencapturestatecode12)表示切换到的状态。 |

**示例：**

```ts
avScreenCaptureRecorder.on('stateChange', (state: media.AVScreenCaptureStateCode) => {
    console.info('avScreenCaptureRecorder stateChange to ' + state);
});
```

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅AVScreenCaptureRecorder的错误事件，用户可以根据应用自身逻辑对错误事件进行处理。用户只能订阅一个错误事件的回调方法，重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型          | 必填 | 说明                                    |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | 是   | 错误事件回调类型，支持的事件：'error'。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 录屏错误事件回调方法。                  |

**错误码：**

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 201      | permission denied.     |
| 5400103  | IO error. Return by ErrorCallback. |
| 5400105  | Service died. Return by ErrorCallback. |

**示例：**

```ts
avScreenCaptureRecorder.on('error', (err: BusinessError) => {
    console.error('avScreenCaptureRecorder error:' + err.message);
});
```

### off('stateChange')<sup>12+</sup>

 off(type: 'stateChange', callback?: Callback\<AVScreenCaptureStateCode>): void

取消订阅状态切换回调事件。用户可以指定填入状态切换的回调方法来取消订阅。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'stateChange'。            |
| callback | function | 否   | 状态切换事件回调方法，[AVScreenCaptureStateCode](#avscreencapturestatecode12)表示切换到的状态，不填此参数则会取消最后一次订阅事件。 |

**示例：**

```ts
avScreenCaptureRecorder.off('stateChange');
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅错误回调事件。用户可以指定填入错误回调方法来取消订阅。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                       |
| -------- | -------- | ---- | ---------------------------------------------------------- |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'error'。                |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 录屏错误事件回调方法，不填此参数则会取消最后一次订阅事件。 |

**示例：**

```ts
avScreenCaptureRecorder.off('error');
```