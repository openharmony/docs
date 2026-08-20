# Functions

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @chris2981-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=39ee8583645d55abbaea4002eba3f819dc0cd1a2 translatedAt=2026-08-19T10:02:55.493Z pushedAt=2026-08-20T02:41:59.896Z -->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(callback: AsyncCallback\<AVPlayer>): void

Creates an AVPlayer instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - You are advised to create a maximum of 16 AVPlayer instances for an application in both audio and video playback scenarios.<!--Del-->
> - The actual number of instances that can be created may be different. It depends on the specifications of the device chip in use. For example, in the case of RK3568, you are advised to create a maximum of 6 AVPlayer instances for an application in audio and video playback scenarios.<!--DelEnd-->
> - Applications must properly manage AVPlayer instances according to their specific needs, creating and freeing them when necessary. Holding too many AVPlayer instances can lead to high memory usage, and in some cases, the system might terminate applications to free up resources.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVPlayer](arkts-apis-media-AVPlayer.md)> | Yes  | Callback used to return the result. If the operation is successful, an AVPlayer instance is returned; otherwise, **null** is returned. The instance can be used to play audio and video.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer;
media.createAVPlayer((error: BusinessError, video: media.AVPlayer) => {
  if (video) {
    avPlayer = video;
    console.info('Succeeded in creating AVPlayer');
  } else {
    console.error(`Failed to create AVPlayer, error message:${error.message}`);
  }
});
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(): Promise\<AVPlayer>

Creates an AVPlayer instance. This API uses a promise to return the result.

> **NOTE**
>
> - You are advised to create a maximum of 16 AVPlayer instances for an application in both audio and video playback scenarios.<!--Del-->
> - The actual number of instances that can be created may be different. It depends on the specifications of the device chip in use. For example, in the case of RK3568, you are advised to create a maximum of 6 AVPlayer instances for an application in audio and video playback scenarios.<!--DelEnd-->
> - Applications should reasonably use AVPlayer objects in accordance with actual service requirements, create them on demand, and release them in a timely manner. This avoids excessive memory consumption caused by holding too many AVPlayer instances, which may result in the system terminating the application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVPlayer](arkts-apis-media-AVPlayer.md)> | Promise used to return the result. If the operation is successful, an AVPlayer instance is returned for audio and video playback. Otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer;
media.createAVPlayer().then((video: media.AVPlayer) => {
  if (video) {
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

Creates an AVRecorder instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> An application can create multiple AVRecorder instances. However, because the device shares a common audio channel, only one instance can record audio at a time. Any attempt to create the second instance for audio recording fails due to audio channel conflicts.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVRecorder](arkts-apis-media-AVRecorder.md)> | Yes  | Callback function, which returns an **AVRecorder** instance for recording audio and video. Otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let avRecorder: media.AVRecorder;

media.createAVRecorder((error: BusinessError, recorder: media.AVRecorder) => {
  if (recorder) {
    avRecorder = recorder;
    console.info('Succeeded in creating AVRecorder');
  } else {
    console.error(`Failed to create AVRecorder, error message:${error.message}`);
  }
});
```

## media.createAVRecorder<sup>9+</sup>

createAVRecorder(): Promise\<AVRecorder>

Creates an AVRecorder instance. This API uses a promise to return the result.

> **NOTE**
>
> An application can create multiple AVRecorder instances. However, because the device shares a common audio channel, only one instance can record audio at a time. Any attempt to create the second instance for audio recording fails due to audio channel conflicts.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| Promise\<[AVRecorder](arkts-apis-media-AVRecorder.md)> | Promise used to return an **AVRecorder** instance, which can be used to record audio and video. Otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let avRecorder: media.AVRecorder;
media.createAVRecorder().then((recorder: media.AVRecorder) => {
  if (recorder) {
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

Creates an AVTranscoder instance. This API uses a promise to return the result.

> **NOTE**
>
> A maximum of 2 AVTranscoder instances can be created.

**Atomic service API**: This API can be used in atomic services since API version 22.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVTranscoder](arkts-apis-media-AVTranscoder.md)> | Promise used to return the result. If the operation is successful, an AVTranscoder instance is returned; otherwise, **null** is returned. The instance can be used for video transcoding.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avTranscoder: media.AVTranscoder | undefined = undefined;
media.createAVTranscoder().then((transcoder: media.AVTranscoder) => {
  if (transcoder) {
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

Creates an AVMetadataExtractor instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVMetadataExtractor](arkts-apis-media-AVMetadataExtractor.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the AVMetadataExtractor instance created; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avMetadataExtractor: media.AVMetadataExtractor;
media.createAVMetadataExtractor((error: BusinessError, extractor: media.AVMetadataExtractor) => {
  if (extractor) {
    avMetadataExtractor = extractor;
    console.info('Succeeded in creating AVMetadataExtractor');
  } else {
    console.error(`Failed to create AVMetadataExtractor, error message:${error.message}`);
  }
});
```

## media.createAVMetadataExtractor<sup>11+</sup>

createAVMetadataExtractor(): Promise\<AVMetadataExtractor>

Creates an AVMetadataExtractor instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[AVMetadataExtractor](arkts-apis-media-AVMetadataExtractor.md)>  | Promise used to return the AVMetadataExtractor instance.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avMetadataExtractor: media.AVMetadataExtractor;
media.createAVMetadataExtractor().then((extractor: media.AVMetadataExtractor) => {
  if (extractor) {
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

Creates a SoundPool instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - In versions earlier than API version 18, the bottom layer of the created SoundPool object is in singleton mode. Therefore, an application process can create only one SoundPool instance.
> - In API version 18 and later, the bottom layer of the created SoundPool object is in multiton mode. Therefore, an application process can create a maximum of 128 SoundPool instances.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| maxStreams | number | Yes  | Maximum number of streams that can be played by the SoundPool instance. The value is an integer ranging from 1 to 32.|
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)  | Yes  | Audio renderer parameters. When the **usage** parameter in **audioRenderInfo** is set to **STREAM_USAGE_UNKNOWN**, **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, or **STREAM_USAGE_AUDIOBOOK**, the SoundPool uses the audio mixing mode when playing a short sound, without interrupting the playback of other audios. SoundPool supports setting **rendererFlags** to **1** for low-latency playback.|
| callback | AsyncCallback<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | Yes  | Callback used to return the result. If the operation is successful, a SoundPool instance is returned; otherwise, **null** is returned. The instance is used for loading and playback.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

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

Creates a SoundPool instance. This API uses a promise to return the result.

> **NOTE**
>
> - In versions earlier than API version 18, the bottom layer of the created SoundPool object is in singleton mode. Therefore, an application process can create only one SoundPool instance.
> - In API version 18 and later, the bottom layer of the created SoundPool object is in multiton mode. Therefore, an application process can create a maximum of 128 SoundPool instances.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| maxStreams | number | Yes  | Maximum number of streams that can be played by the SoundPool instance. The value is an integer ranging from 1 to 32.|
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8)  | Yes  | Audio renderer parameters.|

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | Promise used to return the result. If the operation is successful, a SoundPool instance is returned; otherwise, **null** is returned. The instance is used for loading and playback.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```js
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
};

media.createSoundPool(5, audioRendererInfo).then((soundpool_: media.SoundPool) => {
  if (soundpool_) {
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

Creates an AVScreenCaptureRecorder instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[AVScreenCaptureRecorder](arkts-apis-media-AVScreenCaptureRecorder.md)> | Promise used to return the result. If the operation is successful, an AVScreenCaptureRecorder instance is returned; otherwise, **null** is returned. The instance can be used for screen capture.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avScreenCaptureRecorder: media.AVScreenCaptureRecorder;
media.createAVScreenCaptureRecorder().then((captureRecorder: media.AVScreenCaptureRecorder) => {
  if (captureRecorder) {
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

Creates an AVImageGenerator instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVImageGenerator](arkts-apis-media-AVImageGenerator.md)> | Yes  | Callback used to return the result. If the operation is successful, an AVImageGenerator instance is returned; otherwise, **null** is returned. The API can be used to obtain a video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avImageGenerator: media.AVImageGenerator;
media.createAVImageGenerator((error: BusinessError, generator: media.AVImageGenerator) => {
  if (generator) {
    avImageGenerator = generator;
    console.info('Succeeded in creating AVImageGenerator');
  } else {
    console.error(`Failed to create AVImageGenerator, error message:${error.message}`);
  }
});
```

## media.createAVImageGenerator<sup>12+</sup>

createAVImageGenerator(): Promise\<AVImageGenerator>

Creates an AVImageGenerator instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVImageGenerator](arkts-apis-media-AVImageGenerator.md)> | Promise used to return the result. If the operation is successful, an AVImageGenerator instance is returned; otherwise, **null** is returned. The API can be used to obtain a video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avImageGenerator: media.AVImageGenerator;
media.createAVImageGenerator().then((generator: media.AVImageGenerator) => {
  if (generator) {
    avImageGenerator = generator;
    console.info('Succeeded in creating AVImageGenerator');
  } else {
    console.error('Failed to create AVImageGenerator');
  }
}).catch((error: BusinessError) => {
  console.error(`Failed to create AVImageGenerator, error message:${error.message}`);
});
```

## media.createMediaSourceWithUrl<sup>12+</sup>

createMediaSourceWithUrl(url: string, headers?: Record\<string, string>): MediaSource

Creates a media source for streaming media to be pre-downloaded.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| url | string | Yes | - URL of the media source. The following streaming media formats are supported: HLS, HTTP-FLV, DASH, and HTTPS.<br> - FD path of the local M3U8 file. |
| headers | Record\<string, string> | No  | HTTP header customized for streaming media pre-download. If this parameter is not passed, the default HTTP header of the network request is used.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| [MediaSource](arkts-apis-media-MediaSource.md) | MediaSource instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 5400101  | No memory.  |

**Example 1**

```ts
let headers: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  headers);
```

**Example 2**

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

Creates a multi-bitrate media source for streaming media. Currently, only the HTTP-FLV multi-bitrate media source is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name | Type                                | Mandatory| Description                                                 |
| ------- | ------------------------------------ | ---- | ----------------------------------------------------- |
| streams | Array<[MediaStream](arkts-apis-media-i.md#mediastream19)> | Yes| Array of MediaStream objects. The supported streaming media format is HTTP-FLV.|

**Return value**

| Type                         | Description               |
| ----------------------------- | ------------------- |
| [MediaSource](arkts-apis-media-MediaSource.md) | MediaSource instance.|

**Example**

```ts
let streams : Array<media.MediaStream> = [];
streams.push({url: "http://xxx/480p.flv", width: 854, height: 480, bitrate: 800000});
streams.push({url: "http://xxx/720p.flv", width: 1280, height: 720, bitrate: 2000000});
streams.push({url: "http://xxx/1080p.flv", width: 1920, height: 1080, bitrate: 2000000});
let mediaSource : media.MediaSource = media.createMediaSourceWithStreamData(streams);
```

## media.createMediaSourceWithFd

createMediaSourceWithFd(fdSrc: AVFileDescriptor): MediaSource | undefined

Creates a media source using a file descriptor.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name | Type                                | Mandatory| Description                                                 |
| ------- | ------------------------------------ | ---- | ----------------------------------------------------- |
| fdSrc | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9) | Yes| Media file descriptor.|

**Return value**

| Type                         | Description               |
| ----------------------------- | ------------------- |
| [MediaSource](arkts-apis-media-MediaSource.md) \| undefined | MediaSource instance.|

**Example**

```ts
import { common } from '@kit.AbilityKit';

let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let fdSrc = await context.resourceManager.getRawFd('xxx.mp4');
let mediaSource : media.MediaSource | undefined = media.createMediaSourceWithFd(fdSrc);
```

## media.createMediaSourceWithDataSource

createMediaSourceWithDataSource(dataSrc: AVDataSrcDescriptor): MediaSource | undefined

Creates a media source using the custom data source.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name | Type                                | Mandatory| Description                                                 |
| ------- | ------------------------------------ | ---- | ----------------------------------------------------- |
| dataSrc | [AVDataSrcDescriptor](arkts-apis-media-i.md#avdatasrcdescriptor10) | Yes| Streaming media resource descriptor.|

**Return value**

| Type                         | Description               |
| ----------------------------- | ------------------- |
| [MediaSource](arkts-apis-media-MediaSource.md) \| undefined | MediaSource instance.|

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';

let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let fileDescriptor = await context.resourceManager.getRawFd('xxx.mp4');
let file = fs.openSync("xxx.mp4");
let dataSrc: media.AVDataSrcDescriptor = {
  fileSize: fileDescriptor.length,
  callback: (buf: ArrayBuffer, length: number, pos?: number) => {
    let readLen = 0;
    if (pos) {
      let option: ReadOptions = {
        offset: pos,
        length: length,
      };
      readLen = fs.readSync(file.fd, buf, option);
    }
    return readLen > 0 ? readLen : -1;
  }
}
let mediaSource : media.MediaSource | undefined =  media.createMediaSourceWithDataSource(dataSrc);
```

## media.createAudioPlayer<sup>(deprecated)</sup>

createAudioPlayer(): AudioPlayer

Creates an AudioPlayer instance in synchronous mode.

> **NOTE**
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [createAVPlayer](#mediacreateavplayer9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Return value**

| Type                       | Description                                                        |
| --------------------------- | ------------------------------------------------------------ |
| [AudioPlayer](arkts-apis-media-AudioPlayer.md) | If the operation is successful, an AudioPlayer instance is returned; otherwise, **null** is returned. After the instance is created, you can start, pause, or stop audio playback.|

**Example**

```ts
let audioPlayer: media.AudioPlayer = media.createAudioPlayer();
```

## media.createVideoPlayer<sup>(deprecated)</sup>

createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void

Creates a **VideoPlayer** instance. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [createAVPlayer](#mediacreateavplayer9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[VideoPlayer](arkts-apis-media-VideoPlayer.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the VideoPlayer instance created; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
```

## media.createVideoPlayer<sup>(deprecated)</sup>

createVideoPlayer(): Promise\<VideoPlayer>

Creates a VideoPlayer instance. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [createAVPlayer](#mediacreateavplayer9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| Promise<[VideoPlayer](arkts-apis-media-VideoPlayer.md)> | Promise used to return the result. If the operation is successful, a VideoPlayer instance is returned; otherwise, **null** is returned. The instance can be used to manage and play video.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer().then((video: media.VideoPlayer) => {
  if (video) {
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

Creates an AudioRecorder instance to control audio recording. Only one AudioRecorder instance can be created per device.

> **NOTE**
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [createAVRecorder](#mediacreateavrecorder9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [AudioRecorder](arkts-apis-media-AudioRecorder.md) | If the operation is successful, an AudioRecorder instance is returned; otherwise, **null** is returned. The instance can be used to record audio.|

**Example**

```ts
let audioRecorder: media.AudioRecorder = media.createAudioRecorder();
```

## media.createAVAdsController

createAVAdsController(player: AVPlayer): Promise\<AVAdsController | undefined>

Creates an ad playback controller associated with a player instance. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| player | [AVPlayer](arkts-apis-media-AVPlayer.md) | Yes   | Player instance created. |

**Return value**

| Type                            | Description                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVAdsController](arkts-apis-media-AVAdsController.md) \| undefined> | Promise used to return the result. The **AVAdsController** instance is returned if the operation is successful; **undefined** is returned otherwise. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5400108  | The player object corresponding to player does not exist or is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test() {
  let player: media.AVPlayer = await media.createAVPlayer();
  media.createAVAdsController(player).then((adsController: media.AVAdsController | undefined) => {
    if (adsController) {
      console.info('Succeeded in creating AVAdsController');
    } else {
      console.error('Failed to create AVAdsController');
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to create AVAdsController, error: ${error}`);
  });
}
```

## media.createMediaSourceWithDirectory

createMediaSourceWithDirectory(path: string): Promise\<MediaSource | undefined>

Creates a media source object based on the specified directory path. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Parameters**

| Name   | Type     | Mandatory | Description                 |
| -------- | -------- | ---- | -------------------- |
| path | string | Yes   | Directory path for creating a media source. |

**Return value**

| Type                            | Description                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[MediaSource](arkts-apis-media-MediaSource.md) \| undefined> | Promise used to return the result. The **MediaSource** instance is returned if the operation is successful; **undefined** is returned otherwise. |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID | Error Message                                  |
| -------- | ----------------------------------------- |
| 5411007  | The directory specified by the path parameter does not exist or inaccessible. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test() {
  media.createMediaSourceWithDirectory("/data/storage/el2/base/media/cache/").then((mediaSource: media.MediaSource | undefined) => {
    if (mediaSource) {
      console.info('Succeeded in creating MediaSource with directory');
    } else {
      console.error('Failed to create MediaSource with directory');
    }
  }).catch((error: BusinessError) => {
    console.error(`Failed to create MediaSource with directory, error: ${error}`);
  });
}
```

## media.createAVDownloaderManager

createAVDownloaderManager(): Promise\<AVDownloaderManager>

Creates an offline download task manager instance. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Multimedia.Media.Core

**Return value**

| Type                            | Description                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVDownloaderManager](arkts-apis-media-AVDownloaderManager.md)> | Promise used to return the offline download task manager instance. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function test() {
  media.createAVDownloaderManager().then((downloaderManager: media.AVDownloaderManager) => {
    console.info('Succeeded in creating AVDownloaderManager');
  }).catch((error: BusinessError) => {
    console.error(`Failed to create AVDownloaderManager, error: ${error}`);
  });
}
```