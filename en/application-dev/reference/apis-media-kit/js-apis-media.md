# @ohos.multimedia.media (Media)

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The multimedia subsystem provides a set of simple and easy-to-use APIs for you to access the system and use media resources.

This subsystem offers the following audio and video services:

- Audio and video playback ([AVPlayer](#avplayer9)<sup>9+</sup>)

- Audio and video recording [AVRecorder](#avrecorder9)<sup>9+</sup>)

- Obtaining audio and video metadata ([AVMetadataExtractor](#avmetadataextractor11)<sup>11+</sup>).

- Obtaining video thumbnails ([AVImageGenerator](#avimagegenerator12)<sup>12+</sup>)

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(callback: AsyncCallback\<AVPlayer>): void

Creates an **AVPlayer** instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - A maximum of 13 instances can be created in video-only playback scenarios.
> - A maximum of 16 instances can be created in both audio and video playback scenarios.<!--Del-->
> - The actual number of instances that can be created may be different. It depends on the specifications of the device chip in use. For example, in the case of RK3568, a maximum of 6 instances can be created in video-only playback scenarios.<!--DelEnd-->

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVPlayer](#avplayer9)> | Yes  | Callback used to return the result. If the operation is successful, an **AVPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to play audio and video.|

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
  if (video != null) {
    avPlayer = video;
    console.info('createAVPlayer success');
  } else {
    console.error(`createAVPlayer fail, error message:${error.message}`);
  }
});
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(): Promise\<AVPlayer>

Creates an **AVPlayer** instance. This API uses a promise to return the result.

> **NOTE**
>
> - A maximum of 13 instances can be created in video-only playback scenarios.
> - A maximum of 16 instances can be created in both audio and video playback scenarios.<!--Del-->
> - The actual number of instances that can be created may be different. It depends on the specifications of the device chip in use. For example, in the case of RK3568, a maximum of 6 instances can be created in video-only playback scenarios.<!--DelEnd-->

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVPlayer](#avplayer9)> | Promise used to return the result. If the operation is successful, an **AVPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to play audio and video.|

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
  if (video != null) {
    avPlayer = video;
    console.info('createAVPlayer success');
  } else {
    console.error('createAVPlayer fail');
  }
}).catch((error: BusinessError) => {
  console.error(`AVPlayer catchCallback, error message:${error.message}`);
});
```

## media.createAVRecorder<sup>9+</sup>

createAVRecorder(callback: AsyncCallback\<AVRecorder>): void

Creates an **AVRecorder** instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - A maximum of 2 instances can be created in audio and video recording scenarios.
> - Only one instance can perform audio recording on a device at one time, since all the applications share the audio channel. Any attempt to create the second instance for audio recording fails due to audio channel conflicts.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVRecorder](#avrecorder9)> | Yes  | Callback used to return the result. If the operation is successful, an **AVRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record audio and video.|

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
  if (recorder != null) {
    avRecorder = recorder;
    console.info('createAVRecorder success');
  } else {
    console.error(`createAVRecorder fail, error message:${error.message}`);
  }
});
```

## media.createAVRecorder<sup>9+</sup>

createAVRecorder(): Promise\<AVRecorder>

Creates an **AVRecorder** instance. This API uses a promise to return the result.

> **NOTE**
>
> - A maximum of 2 instances can be created in audio and video recording scenarios.
> - Only one instance can perform audio recording on a device at one time, since all the applications share the audio channel. Any attempt to create the second instance for audio recording fails due to audio channel conflicts.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| Promise\<[AVRecorder](#avrecorder9)> | Promise used to return the result. If the operation is successful, an **AVRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record audio and video.|

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
  if (recorder != null) {
    avRecorder = recorder;
    console.info('createAVRecorder success');
  } else {
    console.error('createAVRecorder fail');
  }
}).catch((error: BusinessError) => {
  console.error(`createAVRecorder catchCallback, error message:${error.message}`);
});
```

## media.createAVMetadataExtractor<sup>11+</sup>

createAVMetadataExtractor(callback: AsyncCallback\<AVMetadataExtractor>): void

Creates an **AVMetadataExtractor** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVMetadataExtractor](#avmetadataextractor11)> | Yes  | Callback used to return the result. If the operation is successful, an **AVMetadataExtractor** instance is returned; otherwise, **null** is returned. The interface can be used to obtain audio and video metadata.|

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
  if (extractor != null) {
    avMetadataExtractor = extractor;
    console.info('createAVMetadataExtractor success');
  } else {
    console.error(`createAVMetadataExtractor fail, error message:${error.message}`);
  }
});
```

## media.createAVMetadataExtractor<sup>11+</sup>

createAVMetadataExtractor(): Promise\<AVMetadataExtractor>

Creates an **AVMetadataExtractor** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVMetadataExtractor](#avmetadataextractor11)> | Promise used to return the result. If the operation is successful, an **AVMetadataExtractor** instance is returned; otherwise, **null** is returned. The interface can be used to obtain audio and video metadata.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avMetadataExtractor: media.AVMetadataExtractor;
media.createAVMetadataExtractor().then((extractor: media.AVMetadataExtractor) => {
  if (extractor != null) {
    avMetadataExtractor = extractor;
    console.info('createAVMetadataExtractor success');
  } else {
    console.error('createAVMetadataExtractor fail');
  }
}).catch((error: BusinessError) => {
  console.error(`AVMetadataExtractor catchCallback, error message:${error.message}`);
});
```

## media.createSoundPool<sup>10+</sup>

createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo, callback: AsyncCallback\<SoundPool>): void

Creates a **SoundPool** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| maxStreams | number | Yes  | Maximum number of streams that can be played by the **SoundPool** instance.|
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/js-apis-audio.md#audiorendererinfo8)  | Yes  | Audio renderer parameters.|
| callback | AsyncCallback<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | Yes  | Callback used to return the result. If the operation is successful, a **SoundPool** instance is returned; otherwise, **null** is returned. The instance is used for loading and playback.|

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
}

media.createSoundPool(5, audioRendererInfo, (error, soundPool_: media.SoundPool) => {
  if (error) {
    console.error(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});
```

## media.createSoundPool<sup>10+</sup>

createSoundPool(maxStreams: number, audioRenderInfo: audio.AudioRendererInfo): Promise\<SoundPool>

Creates a **SoundPool** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.SoundPool

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| maxStreams | number | Yes  | Maximum number of streams that can be played by the **SoundPool** instance.|
| audioRenderInfo | [audio.AudioRendererInfo](../apis-audio-kit/js-apis-audio.md#audiorendererinfo8)  | Yes  | Audio renderer parameters.|

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[SoundPool](js-apis-inner-multimedia-soundPool.md)> | Promise used to return the result. If the operation is successful, a **SoundPool** instance is returned; otherwise, **null** is returned. The instance is used for loading and playback.|

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
}

media.createSoundPool(5, audioRendererInfo).then((soundpool_: media.SoundPool) => {
  if (soundpool_ != null) {
    soundPool = soundpool_;
    console.info('create SoundPool success');
  } else {
    console.error('create SoundPool fail');
  }
}, (error: BusinessError) => {
  console.error(`soundpool catchCallback, error message:${error.message}`);
});
```

## media.createAVScreenCaptureRecorder<sup>12+</sup>

createAVScreenCaptureRecorder(): Promise\<AVScreenCaptureRecorder>

Creates an **AVScreenCaptureRecorder** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[AVScreenCaptureRecorder](#avscreencapturerecorder12)> | Promise used to return the result. If the operation is successful, an **AVScreenCaptureRecorder** instance is returned; otherwise, **null** is returned. The instance can be used for screen capture.|

**Error codes**

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avScreenCaptureRecorder: media.AVScreenCaptureRecorder;
media.createAVScreenCaptureRecorder().then((captureRecorder: media.AVScreenCaptureRecorder) => {
  if (captureRecorder != null) {
    avScreenCaptureRecorder = captureRecorder;
    console.info('createAVScreenCaptureRecorder success');
  } else {
    console.error('createAVScreenCaptureRecorder fail');
  }
}).catch((error: BusinessError) => {
  console.error(`createAVScreenCaptureRecorder catchCallback, error message:${error.message}`);
});
```

## AVErrorCode<sup>9+</sup>

Enumerates the [media error codes](errorcode-media.md).

**System capability**: SystemCapability.Multimedia.Media.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name                                 | Value     | Description                                |
| :------------------------------------ | ------- | ------------------------------------ |
| AVERR_OK                              | 0       | The operation is successful.                      |
| AVERR_NO_PERMISSION                   | 201     | You do not have the permission to perform the operation.              |
| AVERR_INVALID_PARAMETER               | 401     | Invalid input parameter.                  |
| AVERR_UNSUPPORT_CAPABILITY            | 801     | Unsupported API.       |
| AVERR_NO_MEMORY                       | 5400101 | The system memory is insufficient or the number of services reaches the upper limit.|
| AVERR_OPERATE_NOT_PERMIT              | 5400102 | The operation is not allowed in the current state or you do not have the permission to perform the operation.|
| AVERR_IO                              | 5400103 | The data stream is abnormal.                |
| AVERR_TIMEOUT                         | 5400104 | The system or network response times out.            |
| AVERR_SERVICE_DIED                    | 5400105 | The service process is dead.                  |
| AVERR_UNSUPPORT_FORMAT                | 5400106 | The format of the media asset is not supported.      |
| AVERR_AUDIO_INTERRUPTED<sup>11+</sup> | 5400107 | The audio focus is interrupted.                  |

## MediaType<sup>8+</sup>

Enumerates the media types.

**System capability**: SystemCapability.Multimedia.Media.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name          | Value  | Description      |
| -------------- | ---- | ---------- |
| MEDIA_TYPE_AUD | 0    | Media.|
| MEDIA_TYPE_VID | 1    | Video.|

## CodecMimeType<sup>8+</sup>

Enumerates the codec MIME types.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name        | Value                   | Description                    |
| ------------ | --------------------- | ------------------------ |
| VIDEO_H263   | 'video/h263'          | Video in H.263 format.     |
| VIDEO_AVC    | 'video/avc'           | Video in AVC format.      |
| VIDEO_MPEG2  | 'video/mpeg2'         | Video in MPEG-2 format.    |
| VIDEO_MPEG4  | 'video/mp4v-es'         | Video in MPEG-4 format.    |
| VIDEO_VP8    | 'video/x-vnd.on2.vp8' | Video in VP8 format.      |
| VIDEO_HEVC<sup>11+</sup>   | 'video/hevc'          | Video in H.265 format.|
| AUDIO_AAC    | 'audio/mp4a-latm'     | Audio in MP4A-LATM format.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| AUDIO_VORBIS | 'audio/vorbis'        | Audio in Vorbis format.   |
| AUDIO_FLAC   | 'audio/flac'          | Audio in FLAC format.     |

## MediaDescriptionKey<sup>8+</sup>

Enumerates the media description keys.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | 'track_index'   | Track index, which is a number.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_TRACK_TYPE        | 'track_type'    | Track type, which is a number. For details, see [MediaType](#mediatype8).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_CODEC_MIME        | 'codec_mime'    | Codec MIME type, which is a string.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_DURATION          | 'duration'      | Media duration, which is a number, in units of ms.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_BITRATE           | 'bitrate'       | Bit rate, which is a number, in units of bit/s.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_WIDTH             | 'width'         | Video width, which is a number, in units of pixel.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_HEIGHT            | 'height'        | Video height, which is a number, in units of pixel.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_FRAME_RATE        | 'frame_rate'    | Video frame rate, which is a number, in units of 100 fps.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | Number of audio channels, which is a number.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_AUD_SAMPLE_RATE   | 'sample_rate'   | Sampling rate, which is a number, in units of Hz.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MD_KEY_AUD_SAMPLE_DEPTH<sup>12+</sup>  | 'sample_depth'  | Bit depth, which is a number, in units of bits.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## BufferingInfoType<sup>8+</sup>

Enumerates the buffering event types.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name             | Value  | Description                            |
| ----------------- | ---- | -------------------------------- |
| BUFFERING_START   | 1    | Buffering starts.                  |
| BUFFERING_END     | 2    | Buffering ends.                  |
| BUFFERING_PERCENT | 3    | Buffering progress, in percent.                |
| CACHED_DURATION   | 4    | Cache duration, in ms.|

## StateChangeReason<sup>9+</sup>

Enumerates the reasons for the state transition of the **AVPlayer** or **AVRecorder** instance. The enum value is reported together with **state**.

**System capability**: SystemCapability.Multimedia.Media.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| USER       | 1    | State transition triggered by user behavior. It happens when a user or the client calls an API.|
| BACKGROUND | 2    | State transition caused by background system behavior. For example, if an application does not have the permission of Media Controller, the application is forcibly suspended or stopped by the system when it switches to the background.|

## AVPlayer<sup>9+</sup>

A playback management class that provides APIs to manage and play media assets. Before calling any API in **AVPlayer**, you must use [createAVPlayer()](#mediacreateavplayer9) to create an **AVPlayer** instance.

For details about the audio and video playback demo, see [Audio Playback](../../media/media/using-avplayer-for-playback.md) and [Video Playback](../../media/media/video-playback.md).

### Attributes

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name                                               | Type                                                        | Readable| Writable| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>9+</sup>                                    | string                                                       | Yes  | Yes  | URL of the media asset. It can be set only when the AVPlayer is in the idle state. <br>The video formats MP4, MPEG-TS, and MKV are supported.<br>The audio formats M4A, AAC, MP3, OGG, WAV, FLAC, and AMR are supported.<br>**Example of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http\://xx<br>3. HTTPS: https\://xx<br>4. HLS: http\://xx or https\://xx<br>**NOTE**<br>- To set a network playback path, you must declare the [ohos.permission.INTERNET](../../security/AccessToken/permissions-for-all.md#ohospermissioninternet) permission. The error code [201](../errorcode-universal.md) may be reported.<br>- WebM is no longer supported since API version 11.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fdSrc<sup>9+</sup>                                  | [AVFileDescriptor](#avfiledescriptor9)                       | Yes  | Yes  | FD of the media asset. It can be set only when the AVPlayer is in the idle state.<br>This attribute is required when media assets of an application are continuously stored in a file.<br>The video formats MP4, MPEG-TS, and MKV are supported.<br>The audio formats M4A, AAC, MP3, OGG, WAV, FLAC, and AMR are supported.<br>**Example:**<br>Assume that a media file that stores continuous assets consists of the following:<br>Video 1 (address offset: 0, byte length: 100)<br>Video 2 (address offset: 101; byte length: 50)<br>Video 3 (address offset: 151, byte length: 150)<br>1. To play video 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play video 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play video 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent media file, use **src=fd://xx**.<br>**NOTE**<br>WebM is no longer supported since API version 11.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| dataSrc<sup>10+</sup>                               | [AVDataSrcDescriptor](#avdatasrcdescriptor10)                | Yes  | Yes  | Descriptor of a streaming media asset. It can be set only when the AVPlayer is in the idle state.<br>Use scenario: An application starts playing a media file while the file is still being downloaded from the remote to the local host.<br>The video formats MP4, MPEG-TS, and MKV are supported.<br>The audio formats M4A, AAC, MP3, OGG, WAV, FLAC, and AMR are supported.<br>**Example:**<br>A user is obtaining an audio and video file from a remote server and wants to play the downloaded file content. To implement this scenario, do as follows:<br>1. Obtain the total file size, in bytes. If the total size cannot be obtained, set **fileSize** to **-1**.<br>2. Implement the **func** callback to fill in data. If **fileSize** is **-1**, the format of **func** is **func(buffer: ArrayBuffer, length: number)**, and the AVPlayer obtains data in sequence; otherwise, the format is **func(buffer: ArrayBuffer, length: number, pos: number)**, and the AVPlayer seeks and obtains data in the required positions.<br>3. Set **AVDataSrcDescriptor {fileSize = size, callback = func}**.<br>**Notes:**<br>If the media file to play is in MP4/M4A format, ensure that the **moov** field (specifying the media information) is before the **mdat** field (specifying the media data) or the fields before the **moov** field is less than 10 MB. Otherwise, the parsing fails and the media file cannot be played.<br>**NOTE**<br>WebM is no longer supported since API version 11.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| surfaceId<sup>9+</sup>                              | string                                                       | Yes  | Yes  | Video window ID. By default, there is no video window.<br>This parameter can be set when the AVPlayer is in the initialized state.<br>It can be set again when the AVPlayer is in the prepared, playing, paused, completed, or stopped state, in the prerequisite that the video window ID has been set in the initialized state. After the new setting is performed, the video is played in the new window.<br>It is used to render the window for video playback and therefore is not required in audio-only playback scenarios.<br>**Example:**<br>[Create a surface ID through XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| loop<sup>9+</sup>                                   | boolean                                                      | Yes  | Yes  | Whether to loop playback. The value **true** means to loop playback, and **false** (default) means the opposite. It is a dynamic attribute<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.<br>This setting is not supported in live mode.|
| videoScaleType<sup>9+</sup>                         | [VideoScaleType](#videoscaletype9)                           | Yes  | Yes  | Video scale type. The default value is **VIDEO_SCALE_TYPE_FIT**. It is a dynamic attribute<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.|
| audioInterruptMode<sup>9+</sup>                     | [audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9)       | Yes  | Yes  | Audio interruption mode. The default value is **SHARE_MODE**. It is a dynamic attribute<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.<br>To take effect, this attribute must be set before [play()](#play9) is called for the first time.|
| audioRendererInfo<sup>10+</sup>                     | [audio.AudioRendererInfo](../apis-audio-kit/js-apis-audio.md#audiorendererinfo8) | Yes  | Yes  | Audio renderer information. The default values of **usage** and **rendererFlags** are **STREAM_USAGE_MUSIC** and **0**, respectively.<br>This parameter can be set only when the AVPlayer is in the initialized state.<br>To take effect, this attribute must be set before [prepare()](#prepare9) is called for the first time.|
| audioEffectMode<sup>10+</sup>                       | [audio.AudioEffectMode](../apis-audio-kit/js-apis-audio.md#audioeffectmode10)  | Yes  | Yes  | Audio effect mode. The audio effect mode is a dynamic attribute and is restored to the default value **EFFECT_DEFAULT** when **usage** of **audioRendererInfo** is changed. It can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.|
| state<sup>9+</sup>                                  | [AVPlayerState](#avplayerstate9)                             | Yes  | No  | AVPlayer state. It can be used as a query parameter when the AVPlayer is in any state.                  |
| currentTime<sup>9+</sup>                            | number                                                       | Yes  | No  | Current video playback position, in ms. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **-1** indicates an invalid value.<br>In live mode, **-1** is returned by default.|
| duration<sup>9+</sup> | number                                                       | Yes  | No  | Video duration, in ms. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **-1** indicates an invalid value.<br>In live mode, **-1** is returned by default.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| width<sup>9+</sup>                                  | number                                                       | Yes  | No  | Video width, in px. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **0** indicates an invalid value.|
| height<sup>9+</sup>                                 | number                                                       | Yes  | No  | Video height, in px. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **0** indicates an invalid value.|

**NOTE**

After the resource handle (FD) is transferred to the AVPlayer, do not use the resource handle to perform read and write operations, including but not limited to transferring it to multiple AVPlayers. Competition occurs when multiple AVPlayers use the same resource handle to read and write files at the same time, resulting in playback errors.

### on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void

Subscribes to AVPlayer state changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case. This event can be triggered by both user operations and the system.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the following information:<br>state: [AVPlayerState](#avplayerstate9), indicating the AVPlayer state.<br>reason: [StateChangeReason](#statechangereason9), indicating the reason for the state transition.|

**Example**

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
})
```

### off('stateChange')<sup>9+</sup>

off(type: 'stateChange'): void

Unsubscribes from AVPlayer state changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type  | Mandatory| Description                                                 |
| ------ | ------ | ---- | ----------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'stateChange'** in this case.|

**Example**

```ts
avPlayer.off('stateChange')
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to AVPlayer errors. This event is used only for error prompt and does not require the user to stop playback control. If [AVPlayerState](#avplayerstate9) is also switched to error, call [reset()](#reset9) or [release()](#release9) to exit the playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'error'** in this case. This event can be triggered by both user operations and the system.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return the error code ID and error message.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message             |
| -------- | --------------------- |
| 201      | Permission denied     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 801      | Capability not supported. |
| 5400101  | No Memory. Return by callback. |
| 5400102  | Operation not allowed.|
| 5400103  | I/O error             |
| 5400104  | Time out              |
| 5400105  | Service Died.         |
| 5400106  | Unsupport Format.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.on('error', (error: BusinessError) => {
  console.info('error happened,and error message is :' + error.message)
  console.info('error happened,and error code is :' + error.code)
})
```

### off('error')<sup>9+</sup>

off(type: 'error'): void

Unsubscribes from AVPlayer errors.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | Yes  | Event type, which is **'error'** in this case.|

**Example**

```ts
avPlayer.off('error')
```

### setMediaSource<sup>12+</sup>

setMediaSource(src:MediaSource, strategy?: PlaybackStrategy): Promise\<void>

Sets a source of streaming media that can be pre-downloaded, downloads the media data, and temporarily stores the data in the memory. For details about how to use the API, see [Video Playback](../../media/media/video-playback.md)

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| src | [MediaSource](#mediasource12) | Yes  | Source of the streaming media to pre-download.|
| strategy | [PlaybackStrategy](#playbackstrategy12) | No  | strategy for playing the pre-downloaded streaming media.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { media } from '@kit.MediaKit';

let player = await media.createAVPlayer();
let header: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  header);
let playStrategy : media.PlaybackStrategy = {preferredWidth: 1, preferredHeight: 2, preferredBufferDuration: 3, preferredHdr: false};
player.setMediaSource(mediaSource, playStrategy);
```

### prepare<sup>9+</sup>

prepare(callback: AsyncCallback\<void>): void

Prepares for audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the initialized state. The state changes can be detected by subscribing to the [stateChange](#onstatechange9) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupport format. Return by callback.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.prepare((err: BusinessError) => {
  if (err == null) {
    console.info('prepare success');
  } else {
    console.error('prepare filed,error message is :' + err.message)
  }
})
```

### prepare<sup>9+</sup>

prepare(): Promise\<void>

Prepares for audio and video playback. This API uses a promise to return the result. It can be called only when the AVPlayer is in the initialized state. The state changes can be detected by subscribing to the [stateChange](#onstatechange9) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400106  | Unsupport format. Return by promise.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.prepare().then(() => {
  console.info('prepare success');
}, (err: BusinessError) => {
  console.error('prepare filed,error message is :' + err.message)
})
```

### play<sup>9+</sup>

play(callback: AsyncCallback\<void>): void

Starts to play an audio and video asset. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the prepared, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.play((err: BusinessError) => {
  if (err == null) {
    console.info('play success');
  } else {
    console.error('play filed,error message is :' + err.message)
  }
})
```

### play<sup>9+</sup>

play(): Promise\<void>

Starts to play an audio and video asset. This API uses a promise to return the result. It can be called only when the AVPlayer is in the prepared, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.play().then(() => {
  console.info('play success');
}, (err: BusinessError) => {
  console.error('play filed,error message is :' + err.message)
})
```

### pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the playing state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.pause((err: BusinessError) => {
  if (err == null) {
    console.info('pause success');
  } else {
    console.error('pause filed,error message is :' + err.message)
  }
})
```

### pause<sup>9+</sup>

pause(): Promise\<void>

Pauses audio and video playback. This API uses a promise to return the result. It can be called only when the AVPlayer is in the playing state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.pause().then(() => {
  console.info('pause success');
}, (err: BusinessError) => {
  console.error('pause filed,error message is :' + err.message)
})
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

Stops audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the prepared, playing, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.stop((err: BusinessError) => {
  if (err == null) {
    console.info('stop success');
  } else {
    console.error('stop filed,error message is :' + err.message)
  }
})
```

### stop<sup>9+</sup>

stop(): Promise\<void>

Stops audio and video playback. This API uses a promise to return the result. It can be called only when the AVPlayer is in the prepared, playing, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.stop().then(() => {
  console.info('stop success');
}, (err: BusinessError) => {
  console.error('stop filed,error message is :' + err.message)
})
```

### reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

Resets audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the initialized, prepared, playing, paused, completed, stopped, or error state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.reset((err: BusinessError) => {
  if (err == null) {
    console.info('reset success');
  } else {
    console.error('reset filed,error message is :' + err.message)
  }
})
```

### reset<sup>9+</sup>

reset(): Promise\<void>

Resets audio and video playback. This API uses a promise to return the result. It can be called only when the AVPlayer is in the initialized, prepared, playing, paused, completed, stopped, or error state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.reset().then(() => {
  console.info('reset success');
}, (err: BusinessError) => {
  console.error('reset filed,error message is :' + err.message)
})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases the playback resources. This API uses an asynchronous callback to return the result. It can be called when the AVPlayer is in any state except released.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.release((err: BusinessError) => {
  if (err == null) {
    console.info('release success');
  } else {
    console.error('release filed,error message is :' + err.message)
  }
})
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases the playback resources. This API uses a promise to return the result. It can be called when the AVPlayer is in any state except released.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.release().then(() => {
  console.info('release success');
}, (err: BusinessError) => {
  console.error('release filed,error message is :' + err.message)
})
```

### getTrackDescription<sup>9+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the audio and video track information. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the prepared, playing, or paused state. To obtain information about all audio and video tracks, this API must be called after the data loading callback is triggered.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the audio and video track information.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if ((arrList) != null) {
    console.info('getTrackDescription success');
  } else {
    console.error(`video getTrackDescription fail, error:${error}`);
  }
});
```

### getTrackDescription<sup>9+</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

Obtains the audio and video track information. This API uses a promise to return the result. It can be called only when the AVPlayer is in the prepared, playing, or paused state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return a **MediaDescription** array, which records the audio and video track information.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  console.info('getTrackDescription success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### selectTrack<sup>12+</sup>

selectTrack(index: number): Promise\<void>

Selects an audio track when the AVPlayer is used to play a video with multiple audio tracks. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| index | number | Yes  | Index of the audio track, which is obtained from [MediaDescription](#mediadescription8).|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Return by callback.       |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

let avPlayer: media.AVPlayer | undefined = undefined;
media.createAVPlayer((err: BusinessError, player: media.AVPlayer) => {
  if(player != null) {
    avPlayer = player;
    console.info(`createAVPlayer success`);
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          if (i != 0) {
            // Obtain the audio track list.
            let audioTrackIndex: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
          }
        }
      } else {
        console.error(`audio getTrackDescription fail, error:${error}`);
      }
    });
  } else {
    console.error(`createAVPlayer fail, error message:${err.message}`);
  }
});

// Select an audio track.
avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
```

### deselectTrack<sup>12+</sup>

deselectTrack(index: number): Promise\<void>

Deselects an audio track when the AVPlayer is used to play a video with multiple audio tracks. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| index | number | Yes  | Index of the audio track, which is obtained from [MediaDescription](#mediadescription8).|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Return by callback.       |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

let avPlayer: media.AVPlayer | undefined = undefined;
media.createAVPlayer((err: BusinessError, player: media.AVPlayer) => {
  if(player != null) {
    avPlayer = player;
    console.info(`createAVPlayer success`);
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          if (i != 0) {
            // Obtain the audio track list.
            let audioTrackIndex: Object = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
          }
        }
      } else {
        console.error(`audio getTrackDescription fail, error:${error}`);
      }
    });
  } else {
    console.error(`createAVPlayer fail, error message:${err.message}`);
  }
});

// Select an audio track.
avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
// Deselect the audio track and restore to the default audio track.
avPlayer.deselectTrack(parseInt(audioTrackIndex.toString()));
```

### setDecryptionConfig<sup>11+</sup>

setDecryptionConfig(mediaKeySession: drm.MediaKeySession, secureVideoPath: boolean): void

Sets the decryption configuration. When receiving a [mediaKeySystemInfoUpdate event](#onmediakeysysteminfoupdate11), create the related configuration and set the decryption configuration based on the information in the reported event. Otherwise, the playback fails.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| mediaKeySession | [drm.MediaKeySession](../apis-drm-kit/js-apis-drm.md#mediakeysession) | Yes  | Decryption session.|
| secureVideoPath | boolean | Yes| Secure video channel. The value **true** means that a secure video channel is selected, and **false** means that a non-secure video channel is selected.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

For details about the DRM module, see [js-apis-drm.md](../apis-drm-kit/js-apis-drm.md).
```ts
import drm from '@ohos.multimedia.drm'

// Create a media key system.
let keySystem:drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
// Create a media key session.
let keySession:drm.MediaKeySession = keySystem.createMediaKeySession(drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
// Generate a media key request and set the response to the media key request.
// Flag indicating whether a secure video channel is used.
let secureVideoPath:boolean = false;
// Set the decryption configuration.
avPlayer.setDecryptionConfig(keySession, secureVideoPath);
```

### getMediaKeySystemInfos<sup>11+</sup>

getMediaKeySystemInfos(): Array\<drm.MediaKeySystemInfo>

Obtains the media key system information of the media asset that is being played. This API must be called after the [mediaKeySystemInfoUpdate event](#onmediakeysysteminfoupdate11) is triggered.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
|  Array<[drm.MediaKeySystemInfo](../apis-drm-kit/js-apis-drm.md#mediakeysysteminfo)> | Array of **MediaKeySystemInfo** objects, each of which contains the **uuid** and **pssh** attributes.|

**Example**

```ts
import drm from '@ohos.multimedia.drm'

const infos = avPlayer.getMediaKeySystemInfos();
console.info('GetMediaKeySystemInfos count: ' + infos.length);
for (let i = 0; i < infos.length; i++) {
  console.info('GetMediaKeySystemInfos uuid: ' + infos[i]["uuid"]);
  console.info('GetMediaKeySystemInfos pssh: ' + infos[i]["pssh"]);
}
```

### seek<sup>9+</sup>

seek(timeMs: number, mode?:SeekMode): void

Seeks to the specified playback position. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the seek operation takes effect by subscribing to the [seekDone](#onseekdone9) event.
This API is not supported in live mode.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type                  | Mandatory| Description                                                        |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | Yes  | Position to seek to, in ms. The value range is [0, [duration](#attributes)].|
| mode   | [SeekMode](#seekmode8) | No  | Seek mode based on the video I frame. The default value is **SEEK_PREV_SYNC**. **Set this parameter only for video playback.**|

**Example**

```ts
let seekTime: number = 1000
avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC)
```

### on('seekDone')<sup>9+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

Subscribes to the event to check whether the seek operation takes effect.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'seekDone'** in this case. This event is triggered each time **seek()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the time position requested by the user.<br>For video playback, [SeekMode](#seekmode8) may cause the actual position to be different from that requested by the user. The exact position can be obtained from the **currentTime** attribute. The time in this callback only means that the requested seek operation is complete.|

**Example**

```ts
avPlayer.on('seekDone', (seekDoneTime:number) => {
  console.info('seekDone success,and seek time is:' + seekDoneTime)
})
```

### off('seekDone')<sup>9+</sup>

off(type: 'seekDone'): void

Unsubscribes from the event that checks whether the seek operation takes effect.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type  | Mandatory| Description                                                |
| ------ | ------ | ---- | ---------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'seekDone'** in this case.|

**Example**

```ts
avPlayer.off('seekDone')
```

### setSpeed<sup>9+</sup>

setSpeed(speed: PlaybackSpeed): void

Sets the playback speed. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [speedDone](#onspeeddone9) event.
This API is not supported in live mode.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type                            | Mandatory| Description              |
| ------ | -------------------------------- | ---- | ------------------ |
| speed  | [PlaybackSpeed](#playbackspeed8) | Yes  | Playback speed to set.|

**Example**

```ts
avPlayer.setSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X)
```

### on('speedDone')<sup>9+</sup>

on(type: 'speedDone', callback: Callback\<number>): void

Subscribes to the event to check whether the playback speed is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'speedDone'** in this case. This event is triggered each time **setSpeed()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the speed set. For details, see [PlaybackSpeed](#playbackspeed8).|

**Example**

```ts
avPlayer.on('speedDone', (speed:number) => {
  console.info('speedDone success,and speed value is:' + speed)
})
```

### off('speedDone')<sup>9+</sup>

off(type: 'speedDone'): void

Unsubscribes from the event that checks whether the playback speed is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                     |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'speedDone'** in this case.|

**Example**

```ts
avPlayer.off('speedDone')
```

### setBitrate<sup>9+</sup>

setBitrate(bitrate: number): void

Sets the bit rate, which is valid only for HTTP Live Streaming (HLS) streams. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [bitrateDone](#onbitratedone9) event. Note that the AVPlayer selects a proper bit rate based on the network connection speed.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| bitrate | number | Yes  | Bit rate to set. You can obtain the available bit rates of the current HLS stream by subscribing to the [availableBitrates](#onavailablebitrates9) event. If the bit rate to set is not in the list of the available bit rates, the AVPlayer selects from the list the minimum bit rate that is closed to the bit rate to set. If the length of the available bit rate list obtained through the event is 0, no bit rate can be set and the **bitrateDone** callback will not be triggered.|

**Example**

```ts
let bitrate: number = 96000
avPlayer.setBitrate(bitrate)
```

### on('bitrateDone')<sup>9+</sup>

on(type: 'bitrateDone', callback: Callback\<number>): void

Subscribes to the event to check whether the bit rate is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bitrateDone'** in this case. This event is triggered each time **setBitrate()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the effective bit rate.            |

**Example**

```ts
avPlayer.on('bitrateDone', (bitrate:number) => {
  console.info('bitrateDone success,and bitrate value is:' + bitrate)
})
```

### off('bitrateDone')<sup>9+</sup>

off(type: 'bitrateDone'): void

Unsubscribes from the event that checks whether the bit rate is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'bitrateDone'** in this case.|

**Example**

```ts
avPlayer.off('bitrateDone')
```

### on('availableBitrates')<sup>9+</sup>

on(type: 'availableBitrates', callback: (bitrates: Array\<number>) => void): void

Subscribes to available bit rates of HLS streams. This event is reported only after the AVPlayer switches to the prepared state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'availableBitrates'** in this case. This event is triggered once after the AVPlayer switches to the prepared state.|
| callback | function | Yes  | Callback invoked when the event is triggered. It returns an array that holds the available bit rates. If the array length is 0, no bit rate can be set.|

**Example**

```ts
avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
  console.info('availableBitrates success,and availableBitrates length is:' + bitrates.length)
})
```

### off('availableBitrates')<sup>9+</sup>

off(type: 'availableBitrates'): void

Unsubscribes from available bit rates of HLS streams. This event is reported after [prepare](#prepare9) is called.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'availableBitrates'** in this case.|

**Example**

```ts
avPlayer.off('availableBitrates')
```


### on('mediaKeySystemInfoUpdate')<sup>11+</sup>

on(type: 'mediaKeySystemInfoUpdate', callback: (mediaKeySystemInfo: Array\<drm.MediaKeySystemInfo>) => void): void

Subscribes to media key system information changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'mediaKeySystemInfoUpdate'** in this case. This event is triggered when the copyright protection information of the media asset being played changes.|
| callback | function | Yes  | Callback invoked when the event is triggered. It returns an array that holds the media key system information. For details, see [MediaKeySystemInfo](../apis-drm-kit/js-apis-drm.md#mediakeysysteminfo).|

**Example**

```ts

import drm from './@ohos.multimedia.drm';

avPlayer.on('mediaKeySystemInfoUpdate', (mediaKeySystemInfo: Array<drm.MediaKeySystemInfo>) => {
    for (let i = 0; i < mediaKeySystemInfo.length; i++) {
      console.info('mediaKeySystemInfoUpdate happened uuid: ' + mediaKeySystemInfo[i]["uuid"]);
      console.info('mediaKeySystemInfoUpdate happened pssh: ' + mediaKeySystemInfo[i]["pssh"]);
    }
})
```

### off('mediaKeySystemInfoUpdate')<sup>11+</sup>

off(type: 'mediaKeySystemInfoUpdate', callback?: (mediaKeySystemInfo: Array<drm.MediaKeySystemInfo>) => void): void;

Unsubscribes from media key system information changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'mediaKeySystemInfoUpdate'** in this case.|
| callback | function | No  | Callback invoked when the event is triggered. It returns an array that holds the media key system information. For details, see [MediaKeySystemInfo](../apis-drm-kit/js-apis-drm.md#mediakeysysteminfo). If this parameter is specified, only the specified callback is unregistered. Otherwise, all callbacks associated with the specified event will be unregistered.|

**Example**

```ts
avPlayer.off('mediaKeySystemInfoUpdate')
```

### setVolume<sup>9+</sup>

setVolume(volume: number): void

Sets the volume. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [volumeChange](#onvolumechange9) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| volume | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|

**Example**

```ts
let volume: number = 1.0
avPlayer.setVolume(volume)
```

### on('volumeChange')<sup>9+</sup>

on(type: 'volumeChange', callback: Callback\<number>): void

Subscribes to the event to check whether the volume is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'volumeChange'** in this case. This event is triggered each time **setVolume()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the effective volume.           |

**Example**

```ts
avPlayer.on('volumeChange', (vol: number) => {
  console.info('volumeChange success,and new volume is :' + vol)
})
```

### off('volumeChange')<sup>9+</sup>

off(type: 'volumeChange'): void

Unsubscribes from the event that checks whether the volume is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'volumeChange'** in this case.|

**Example**

```ts
avPlayer.off('volumeChange')
```

### on('endOfStream')<sup>9+</sup>

on(type: 'endOfStream', callback: Callback\<void>): void

Subscribes to the event that indicates the end of the stream being played. If **[loop](#attributes) = true** is set, the AVPlayer seeks to the beginning of the stream and plays the stream again. If **loop** is not set, the completed state is reported through the [stateChange](#onstatechange9) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'endOfStream'** in this case. This event is triggered when the AVPlayer finishes playing the media asset.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                              |

**Example**

```ts
avPlayer.on('endOfStream', () => {
  console.info('endOfStream success')
})
```

### off('endOfStream')<sup>9+</sup>

off(type: 'endOfStream'): void

Unsubscribes from the event that indicates the end of the stream being played.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'endOfStream'** in this case.|

**Example**

```ts
avPlayer.off('endOfStream')
```

### on('timeUpdate')<sup>9+</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

Subscribes to playback position changes. It is used to refresh the current position of the progress bar. By default, this event is reported every 100 ms. However, it is reported immediately upon a successful seek operation.
The **'timeUpdate'** event is not supported in live mode.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                                          |
| -------- | -------- | ---- | ---------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'timeUpdate'** in this case.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the current playback position, in ms.                                    |

**Example**

```ts
avPlayer.on('timeUpdate', (time:number) => {
  console.info('timeUpdate success,and new time is :' + time)
})
```

### off('timeUpdate')<sup>9+</sup>

off(type: 'timeUpdate'): void

Unsubscribes from playback position changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type  | Mandatory| Description                                              |
| ------ | ------ | ---- | -------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'timeUpdate'** in this case.|

**Example**

```ts
avPlayer.off('timeUpdate')
```

### on('durationUpdate')<sup>9+</sup>


on(type: 'durationUpdate', callback: Callback\<number>): void

Subscribes to media asset duration changes. It is used to refresh the length of the progress bar. By default, this event is reported once in the prepared state. However, it can be repeatedly reported for special streams that trigger duration changes.
The **'durationUpdate'** event is not supported in live mode.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                                              |
| -------- | -------- | ---- | -------------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'durationUpdate'** in this case.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the media asset duration, in ms.                                        |

**Example**

```ts
avPlayer.on('durationUpdate', (duration: number) => {
  console.info('durationUpdate success,new duration is :' + duration)
})
```

### off('durationUpdate')<sup>9+</sup>

off(type: 'durationUpdate'): void

Unsubscribes from media asset duration changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'durationUpdate'** in this case.|

**Example**

```ts
avPlayer.off('durationUpdate')
```

### on('bufferingUpdate')<sup>9+</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to audio and video buffer changes. This subscription is supported only in network playback scenarios.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | function | Yes  | Callback invoked when the event is triggered.<br>When [BufferingInfoType](#bufferinginfotype8) is set to **BUFFERING_PERCENT** or **CACHED_DURATION**, **value** is valid. Otherwise, **value** is fixed at **0**.|

**Example**

```ts
avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('bufferingUpdate success,and infoType value is:' + infoType + ', value is :' + value)
})
```

### off('bufferingUpdate')<sup>9+</sup>

off(type: 'bufferingUpdate'): void

Unsubscribes from audio and video buffer changes. 

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                     |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'bufferingUpdate'** in this case.|

**Example**

```ts
avPlayer.off('bufferingUpdate')
```

### on('startRenderFrame')<sup>9+</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

Subscribes to the event that indicates rendering starts for the first frame. This subscription is supported only in video playback scenarios. This event only means that the playback service sends the first frame to the display module. The actual rendering effect depends on the rendering performance of the display service.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'startRenderFrame'** in this case.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                          |

**Example**

```ts
avPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame success')
})
```

### off('startRenderFrame')<sup>9+</sup>

off(type: 'startRenderFrame'): void

Unsubscribes from the event that indicates rendering starts for the first frame.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'startRenderFrame'** in this case.|

**Example**

```ts
avPlayer.off('startRenderFrame')
```

### on('videoSizeChange')<sup>9+</sup>

on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void

Subscribes to video size (width and height) changes. This subscription is supported only in video playback scenarios. By default, this event is reported only once in the prepared state. However, it is also reported upon resolution changes in the case of HLS streams.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'videoSizeChange'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered. **width** indicates the video width, and **height** indicates the video height.   |

**Example**

```ts
avPlayer.on('videoSizeChange', (width: number, height: number) => {
  console.info('videoSizeChange success,and width is:' + width + ', height is :' + height)
})
```

### off('videoSizeChange')<sup>9+</sup>

off(type: 'videoSizeChange'): void

Unsubscribes from video size changes. 

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'videoSizeChange'** in this case.|

**Example**

```ts
avPlayer.off('videoSizeChange')
```

### on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

Subscribes to the audio interruption event. When multiple audio and video assets are played at the same time, this event is triggered based on the audio interruption mode [audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'audioInterrupt'** in this case.|
| callback | [audio.InterruptEvent<sup>9+</sup>](../apis-audio-kit/js-apis-audio.md#interruptevent9) | Yes  | Callback invoked when the event is triggered.                              |

**Example**

```ts
import { audio } from '@kit.AudioKit';

avPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt success,and InterruptEvent info is:' + info)
})
```

### off('audioInterrupt')<sup>9+</sup>

off(type: 'audioInterrupt'): void

Unsubscribes from the audio interruption event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'audioInterrupt'** in this case.|

**Example**

```ts
avPlayer.off('audioInterrupt')
```

### on('audioOutputDeviceChangeWithInfo') <sup>11+</sup>

on(type: 'audioOutputDeviceChangeWithInfo', callback: Callback\<audio.AudioStreamDeviceChangeInfo>): void

Subscribes to audio stream output device changes and reasons. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'outputDeviceChangeWithInfo'** is triggered when the output device is changed.|
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/js-apis-audio.md#audiostreamdevicechangeinfo11)> | Yes  | Callback used to return the output device descriptor of the current audio stream and the change reason.|

**Error codes**

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.       |

**Example**

```ts
import { audio } from '@kit.AudioKit';

avPlayer.on('audioOutputDeviceChangeWithInfo', (data: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`${JSON.stringify(data)}`);
});
```

### off('audioOutputDeviceChangeWithInfo') <sup>11+</sup>

off(type: 'audioOutputDeviceChangeWithInfo', callback?: Callback\<audio.AudioStreamDeviceChangeInfo>): void

Unsubscribes from audio stream output device changes and reasons. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'outputDeviceChange'** is triggered when the audio output device is changed.|
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/js-apis-audio.md#audiostreamdevicechangeinfo11)> | No  | Callback used to return the output device descriptor of the current audio stream and the change reason.|

**Error codes**

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |

**Example**

```ts
avPlayer.off('audioOutputDeviceChangeWithInfo');
```

## AVPlayerState<sup>9+</sup>

Enumerates the states of the [AVPlayer](#avplayer9). Your application can proactively obtain the AVPlayer state through the **state** attribute or obtain the reported AVPlayer state by subscribing to the [stateChange](##onstatechange9) event. For details about the rules for state transition, see [Audio Playback](../../media/media/using-avplayer-for-playback.md).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

|              Name              |  Type | Description                                                        |
| :-----------------------------: | :----: | :----------------------------------------------------------- |
|              idle               | string | The AVPlayer enters this state after [createAVPlayer()](#mediacreateavplayer9) or [reset()](#reset9) is called.<br>In case [createAVPlayer()](#mediacreateavplayer9) is used, all attributes are set to their default values.<br>In case [reset()](#reset9) is called, the **url<sup>9+</sup>**, **fdSrc<sup>9+</sup>**, or **dataSrc<sup>10+</sup>** attribute and the **loop** attribute are reset, and other attributes are retained.|
|           initialized           | string | The AVPlayer enters this state after **url<sup>9+</sup>** or **fdSrc<sup>9+</sup>** attribute is set in the idle state. In this case, you can configure static attributes such as the window and audio.|
|            prepared             | string | The AVPlayer enters this state when [prepare()](#prepare9) is called in the initialized state. In this case, the playback engine has prepared the resources.|
|             playing             | string | The AVPlayer enters this state when [play()](#play9) is called in the prepared, paused, or completed state.|
|             paused              | string | The AVPlayer enters this state when **pause()** is called in the playing state.|
|            completed            | string | The AVPlayer enters this state when a media asset finishes playing and loop playback is not set (no **loop = true**). In this case, if [play()](#play9) is called, the AVPlayer enters the playing state and replays the media asset; if [stop()](#stop9) is called, the AVPlayer enters the stopped state.|
|             stopped             | string | The AVPlayer enters this state when [stop()](#stop9) is called in the prepared, playing, paused, or completed state. In this case, the playback engine retains the attributes but releases the memory resources. You can call [prepare()](#prepare9) to prepare the resources again, call [reset()](#reset9) to reset the attributes, or call [release()](#release9) to destroy the playback engine.|
|            released             | string | The AVPlayer enters this state when [release()](#release9) is called. The playback engine associated with the **AVPlayer** instance is destroyed, and the playback process ends. This is the final state.|
| error | string | The AVPlayer enters this state when an irreversible error occurs in the playback engine. You can call [reset()](#reset9) to reset the attributes or call [release()](#release9) to destroy the playback engine. For details about the error codes, see [Media Error Codes](errorcode-media.md).<br>**NOTE** Relationship between the error state and the [on('error')](#onerror9) event<br>1. When the AVPlayer enters the error state, the **on('error')** event is triggered. You can obtain the detailed error information through this event.<br>2. When the AVPlayer enters the error state, the playback service stops. This requires the client to design a fault tolerance mechanism to call [reset()](#reset9) or [release()](#release9).<br>3. The client receives **on('error')** event but the AVPlayer does not enter the error state. This situation occurs due to either of the following reasons:<br>Cause 1: The client calls an API in an incorrect state or passes in an incorrect parameter, and the AVPlayer intercepts the call. If this is the case, the client must correct its code logic.<br>Cause 2: A stream error is detected during playback. As a result, the container and decoding are abnormal for a short period of time, but continuous playback and playback control operations are not affected. If this is the case, the client does not need to design a fault tolerance mechanism.|

## AVFileDescriptor<sup>9+</sup>

Describes an audio and video file asset. It is used to specify a particular asset for playback based on its offset and length within a file.

**System capability**: SystemCapability.Multimedia.Media.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | Yes  | Resource handle, which is obtained by calling [resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9).    |
| offset | number | No  | Resource offset, which needs to be entered based on the preset asset information. The default value is **0**. An invalid value causes a failure to parse audio and video assets.|
| length | number | No  | Resource length, which needs to be entered based on the preset asset information. The default value is the remaining bytes from the offset in the file. An invalid value causes a failure to parse audio and video assets.|

## AVDataSrcDescriptor<sup>10+</sup>

Defines the descriptor of an audio and video file, which is used in DataSource playback mode.<br>Use scenario: An application can create a playback instance and start playback before it finishes downloading the audio and video resources.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fileSize     | number | Yes  | Size of the file to play, in bytes. The value **-1** indicates that the size is unknown. If **fileSize** is set to **-1**, the playback mode is similar to the live mode. In this mode, the **seek** and **setSpeed** operations cannot be performed, and the **loop** attribute cannot be set, indicating that loop playback is unavailable.|
| callback | function | Yes  | Callback used to fill in data.<br>- Function: callback: (buffer: ArrayBuffer, length: number, pos?:number) => number;<br>- **buffer**: memory to be filled. The value is of the ArrayBuffer type. This parameter is mandatory.<br>- **length**: maximum length of the memory to be filled. The value is of the number type. This parameter is mandatory.<br>- **pos**: position of the data to be filled in the file. The value is of the number type. This parameter is optional. When **fileSize** is set to **-1**, this parameter cannot be used.<br>- Return value: length of the data to be filled, which is of the number type.|


## SeekMode<sup>8+</sup>

Enumerates the video playback seek modes, which can be passed in the **seek** API.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name          | Value  | Description                                                        |
| -------------- | ---- | ------------------------------------------------------------ |
| SEEK_NEXT_SYNC | 0    | Seeks to the next key frame at the specified position. You are advised to use this value for the rewind operation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SEEK_PREV_SYNC | 1    | Seeks to the previous key frame at the specified position. You are advised to use this value for the fast-forward operation.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SEEK_CLOSEST<sup>12+</sup> | 2    | Seeks to the frame closest to the specified position. You are advised to use this value for accurate seek.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## PlaybackSpeed<sup>8+</sup>

Enumerates the video playback speeds, which can be passed in the **setSpeed** API.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                | Value  | Description                          |
| -------------------- | ---- | ------------------------------ |
| SPEED_FORWARD_0_75_X | 0    | Plays the video at 0.75 times the normal speed.|
| SPEED_FORWARD_1_00_X | 1    | Plays the video at the normal speed.        |
| SPEED_FORWARD_1_25_X | 2    | Plays the video at 1.25 times the normal speed.|
| SPEED_FORWARD_1_75_X | 3    | Plays the video at 1.75 times the normal speed.|
| SPEED_FORWARD_2_00_X | 4    | Plays the video at 2.00 times the normal speed.|
| SPEED_FORWARD_0_50_X<sup>12+</sup> | 5    | Plays the video at 0.50 times the normal speed.|
| SPEED_FORWARD_1_50_X<sup>12+</sup> | 6    | Plays the video at 1.50 times the normal speed.|

## VideoScaleType<sup>9+</sup>

Enumerates the video scale modes.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                     | Value  | Description                                            |
| ------------------------- | ---- | ------------------------------------------------ |
| VIDEO_SCALE_TYPE_FIT      | 0    | Default mode. The video will be stretched to fit the window.             |
| VIDEO_SCALE_TYPE_FIT_CROP | 1    | The video will be stretched to fit the window, without changing its aspect ratio. The content may be cropped.|

## MediaDescription<sup>8+</sup>

Defines media information in key-value mode.

**System capability**: SystemCapability.Multimedia.Media.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name         | Type  | Mandatory| Description                                                        |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| [key: string] | Object | Yes  | For details about the key range supported and the object type and range of each key, see [MediaDescriptionKey](#mediadescriptionkey8).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

function printfItemDescription(obj: media.MediaDescription, key: string) {
  let property: Object = obj[key];
  console.info('audio key is ' + key); // Specify a key. For details about the keys, see [MediaDescriptionKey].
  console.info('audio value is ' + property); // Obtain the value of the key. The value can be any type. For details about the types, see [MediaDescriptionKey].
}

let avPlayer: media.AVPlayer | undefined = undefined;
media.createAVPlayer((err: BusinessError, player: media.AVPlayer) => {
  if(player != null) {
    avPlayer = player;
    console.info(`createAVPlayer success`);
    avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
      if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
          printfItemDescription(arrList[i], media.MediaDescriptionKey.MD_KEY_TRACK_TYPE);  // Print the MD_KEY_TRACK_TYPE value of each track.
        }
      } else {
        console.error(`audio getTrackDescription fail, error:${error}`);
      }
    });
  } else {
    console.error(`createAVPlayer fail, error message:${err.message}`);
  }
});
```

## AVRecorder<sup>9+</sup>

A recording management class that provides APIs to record media assets. Before calling any API in **AVRecorder**, you must use [createAVRecorder()](#mediacreateavrecorder9) to create an **AVRecorder** instance.

For details about the audio and video recording demo, see [Audio Recording](../../media/media/using-avrecorder-for-recording.md) and [Video Recording](../../media/media/video-recording.md).

> **NOTE**
>
> To use the camera to record videos, the camera module is required. For details about how to use the APIs provided by the camera module, see [Camera Management](../apis-camera-kit/js-apis-camera.md).

### Attributes

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name   | Type                                | Readable| Writable| Description              |
| ------- | ------------------------------------ | ---- | ---- | ------------------ |
| state9+ | [AVRecorderState](#avrecorderstate9) | Yes  | No  | AVRecorder state.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

### prepare<sup>9+</sup>

prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void

Sets audio and video recording parameters. This API uses an asynchronous callback to return the result.

**Required permissions:** ohos.permission.MICROPHONE

This permission is required only if audio recording is involved.

To use the camera to record videos, the camera module is required. For details about how to use the APIs provided by the camera module, see [Camera Management](../apis-camera-kit/js-apis-camera.md).

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                                  | Mandatory| Description                                 |
| -------- | -------------------------------------- | ---- | ------------------------------------- |
| config   | [AVRecorderConfig](#avrecorderconfig9) | Yes  | Audio and video recording parameters to set.           |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission denied. Return by callback.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |
| 5400102  | Operate not permit. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Configure the parameters based on those supported by the hardware device.
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
}
let avRecorderConfig: media.AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : avRecorderProfile,
  url : 'fd://', // Before passing in an FD to this parameter, the file must be created by the caller and granted with the read and write permissions. Example value: fd://45.
  rotation: 0, // The value can be 0, 90, 180, or 270. If any other value is used, prepare() reports an error.
  location : { latitude : 30, longitude : 130 }
}

avRecorder.prepare(avRecorderConfig, (err: BusinessError) => {
  if (err == null) {
    console.info('prepare success');
  } else {
    console.error('prepare failed and error is ' + err.message);
  }
})
```

### prepare<sup>9+</sup>

prepare(config: AVRecorderConfig): Promise\<void>

Sets audio and video recording parameters. This API uses a promise to return the result.

**Required permissions:** ohos.permission.MICROPHONE

This permission is required only if audio recording is involved.

To use the camera to record videos, the camera module is required. For details about how to use the APIs provided by the camera module, see [Camera Management](../apis-camera-kit/js-apis-camera.md).

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type                                  | Mandatory| Description                      |
| ------ | -------------------------------------- | ---- | -------------------------- |
| config | [AVRecorderConfig](#avrecorderconfig9) | Yes  | Audio and video recording parameters to set.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201      | Permission denied. Return by promise.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |
| 5400102  | Operate not permit. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Configure the parameters based on those supported by the hardware device.
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
}
let avRecorderConfig: media.AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : avRecorderProfile,
  url : 'fd://', // Before passing in an FD to this parameter, the file must be created by the caller and granted with the read and write permissions. Example value: fd://45.
  rotation: 0, // The value can be 0, 90, 180, or 270. If any other value is used, prepare() reports an error.
  location : { latitude : 30, longitude : 130 }
}

avRecorder.prepare(avRecorderConfig).then(() => {
  console.info('prepare success');
}).catch((err: BusinessError) => {
  console.error('prepare failed and catch error is ' + err.message);
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(callback: AsyncCallback\<string>): void

Obtains the surface required for recording. This API uses an asynchronous callback to return the result. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding video data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp must be based on the system startup time.

This API can be called only after the [prepare()](#prepare9-2) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let surfaceID: string; // The surfaceID is transferred to the camera API to create a videoOutput instance.

avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
  if (err == null) {
    console.info('getInputSurface success');
    surfaceID = surfaceId;
  } else {
    console.error('getInputSurface failed and error is ' + err.message);
  }
});

```

### getInputSurface<sup>9+</sup>

getInputSurface(): Promise\<string>

Obtains the surface required for recording. This API uses a promise to return the result. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding video data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp must be based on the system startup time.

This API can be called only after the [prepare()](#prepare9-3) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<string> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let surfaceID: string; // The surfaceID is transferred to the camera API to create a videoOutput instance.

avRecorder.getInputSurface().then((surfaceId: string) => {
  console.info('getInputSurface success');
  surfaceID = surfaceId;
}).catch((err: BusinessError) => {
  console.error('getInputSurface failed and catch error is ' + err.message);
});
```

### updateRotation<sup>12+</sup>

updateRotation(rotation: number): Promise\<void>

Updates the video rotation angle.

This API can be called only after the [prepare()](#prepare9-3) event is triggered and before the [start()](#start9) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                       |
| -------- | -------------------- | ---- | --------------------------- |
| rotation | number | Yes  | Rotation angle, which can only be 0, 90, 180, or 270 degrees.|

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
|   401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.   |
| 5400102  | Operate not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rotation = 90

avRecorder.updateRotation(rotation).then(() => {
  console.info('updateRotation success');
}).catch((err: BusinessError) => {
  console.error('updateRotation failed and catch error is ' + err.message);
});
```

### start<sup>9+</sup>

start(callback: AsyncCallback\<void>): void

Starts recording. This API uses an asynchronous callback to return the result.

For audio-only recording, this API can be called only after the [prepare()](#prepare9-2) API is called. For video-only recording, this API can be called only after the [getInputSurface()](#getinputsurface9) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.start((err: BusinessError) => {
  if (err == null) {
    console.info('start AVRecorder success');
  } else {
    console.error('start AVRecorder failed and error is ' + err.message);
  }
});
```

### start<sup>9+</sup>

start(): Promise\<void>

Starts recording. This API uses a promise to return the result.

For audio-only recording, this API can be called only after the [prepare()](#prepare9-3) API is called. For video-only recording, this API can be called only after the [getInputSurface()](#getinputsurface9-1) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.start().then(() => {
  console.info('start AVRecorder success');
}).catch((err: BusinessError) => {
  console.error('start AVRecorder failed and catch error is ' + err.message);
});
```

### pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses recording. This API uses an asynchronous callback to return the result.

This API can be called only after the [start()](#start9) API is called. You can call [resume()](#resume9) to resume recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                       |
| -------- | -------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.pause((err: BusinessError) => {
  if (err == null) {
    console.info('pause AVRecorder success');
  } else {
    console.error('pause AVRecorder failed and error is ' + err.message);
  }
});
```

### pause<sup>9+</sup>

pause(): Promise\<void>

Pauses recording. This API uses a promise to return the result.

This API can be called only after the [start()](#start9-1) API is called. You can call [resume()](#resume9-1) to resume recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.pause().then(() => {
  console.info('pause AVRecorder success');
}).catch((err: BusinessError) => {
  console.error('pause AVRecorder failed and catch error is ' + err.message);
});
```

### resume<sup>9+</sup>

resume(callback: AsyncCallback\<void>): void

Resumes recording. This API uses an asynchronous callback to return the result.

This API can be called only after the [pause()](#pause9-2) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.resume((err: BusinessError) => {
  if (err == null) {
    console.info('resume AVRecorder success');
  } else {
    console.error('resume AVRecorder failed and error is ' + err.message);
  }
});
```

### resume<sup>9+</sup>

resume(): Promise\<void>

Resumes recording. This API uses a promise to return the result.

This API can be called only after the [pause()](#pause9-3) API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.resume().then(() => {
  console.info('resume AVRecorder success');
}).catch((err: BusinessError) => {
  console.error('resume AVRecorder failed and catch error is ' + err.message);
});
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

Stops recording. This API uses an asynchronous callback to return the result.

This API can be called only after the [start()](#start9) or [pause()](#pause9-2) API is called.

For audio-only recording, you can call [prepare()](#prepare9-2) again for re-recording. For video-only recording or audio and video recording, you can call [prepare()](#prepare9-2) and [getInputSurface()](#getinputsurface9) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.stop((err: BusinessError) => {
  if (err == null) {
    console.info('stop AVRecorder success');
  } else {
    console.error('stop AVRecorder failed and error is ' + err.message);
  }
});
```

### stop<sup>9+</sup>

stop(): Promise\<void>

Stops recording. This API uses a promise to return the result.

This API can be called only after the [start()](#start9-1) or [pause()](#pause9-3) API is called.

For audio-only recording, you can call [prepare()](#prepare9-3) again for re-recording. For video-only recording or audio and video recording, you can call [prepare()](#prepare9-3) and [getInputSurface()](#getinputsurface9-1) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.stop().then(() => {
  console.info('stop AVRecorder success');
}).catch((err: BusinessError) => {
  console.error('stop AVRecorder failed and catch error is ' + err.message);
});
```

### reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

Resets audio and video recording. This API uses an asynchronous callback to return the result.

For audio-only recording, you can call [prepare()](#prepare9-2) again for re-recording. For video-only recording or audio and video recording, you can call [prepare()](#prepare9-2) and [getInputSurface()](#getinputsurface9) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.reset((err: BusinessError) => {
  if (err == null) {
    console.info('reset AVRecorder success');
  } else {
    console.error('reset AVRecorder failed and error is ' + err.message);
  }
});
```

### reset<sup>9+</sup>

reset(): Promise\<void>

Resets audio and video recording. This API uses a promise to return the result.

For audio-only recording, you can call [prepare()](#prepare9-3) again for re-recording. For video-only recording or audio and video recording, you can call [prepare()](#prepare9-3) and [getInputSurface()](#getinputsurface9-1) again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type          | Description                                   |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.reset().then(() => {
  console.info('reset AVRecorder success');
}).catch((err: BusinessError) => {
  console.error('reset AVRecorder failed and catch error is ' + err.message);
});
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases the audio and video recording resources. This API uses an asynchronous callback to return the result.

After the resources are released, you can no longer perform any operation on the **AVRecorder** instance.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.release((err: BusinessError) => {
  if (err == null) {
    console.info('release AVRecorder success');
  } else {
    console.error('release AVRecorder failed and error is ' + err.message);
  }
});
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases the audio and video recording resources. This API uses a promise to return the result.

After the resources are released, you can no longer perform any operation on the **AVRecorder** instance.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type          | Description                                       |
| -------------- | ------------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.release().then(() => {
  console.info('release AVRecorder success');
}).catch((err: BusinessError) => {
  console.error('release AVRecorder failed and catch error is ' + err.message);
});
```

### getCurrentAudioCapturerInfo<sup>11+</sup>

getCurrentAudioCapturerInfo(callback: AsyncCallback\<audio.AudioCapturerChangeInfo>): void

Obtains the information about the current audio capturer. This API uses an asynchronous callback to return the result.

This API can be called only after the **prepare()** API is called. If this API is called after **stop()** is successfully called, an error is reported.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback\<[audio.AudioCapturerChangeInfo](../apis-audio-kit/js-apis-audio.md#audiocapturerchangeinfo9)> | Yes  | Callback used to return the audio capturer information.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
let currentCapturerInfo: audio.AudioCapturerChangeInfo;

avRecorder.getCurrentAudioCapturerInfo((err: BusinessError, capturerInfo: audio.AudioCapturerChangeInfo) => {
  if (err == null) {
    console.info('getCurrentAudioCapturerInfo success');
    currentCapturerInfo = capturerInfo;
  } else {
    console.error('getCurrentAudioCapturerInfo failed and error is ' + err.message);
  }
});
```

### getCurrentAudioCapturerInfo<sup>11+</sup>

getCurrentAudioCapturerInfo(): Promise\<audio.AudioCapturerChangeInfo>

Obtains the information about the current audio capturer. This API uses a promise to return the result.

This API can be called only after the **prepare()** API is called. If this API is called after **stop()** is successfully called, an error is reported.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type                                                        | Description                                             |
| ------------------------------------------------------------ | ------------------------------------------------- |
| Promise\<[audio.AudioCapturerChangeInfo](../apis-audio-kit/js-apis-audio.md#audiocapturerchangeinfo9)> | Promise used to return the audio capturer information.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400103  | I/O error.                       |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
let currentCapturerInfo: audio.AudioCapturerChangeInfo;

avRecorder.getCurrentAudioCapturerInfo().then((capturerInfo: audio.AudioCapturerChangeInfo) => {
  console.info('getCurrentAudioCapturerInfo success');
  currentCapturerInfo = capturerInfo;
}).catch((err: BusinessError) => {
  console.error('getCurrentAudioCapturerInfo failed and catch error is ' + err.message);
});
```

### getAudioCapturerMaxAmplitude<sup>11+</sup>

getAudioCapturerMaxAmplitude(callback: AsyncCallback\<number>): void

Obtains the maximum amplitude of the current audio capturer. This API uses an asynchronous callback to return the result.

This API can be called only after the **prepare()** API is called. If this API is called after **stop()** is successfully called, an error is reported.

The return value is the maximum amplitude within the duration from the time the maximum amplitude is obtained last time to the current time. For example, if you have obtained the maximum amplitude at 1s and you call this API again at 2s, then the return value is the maximum amplitude within the duration from 1s to 2s.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                  | Mandatory| Description                                |
| -------- | ---------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the maximum amplitude.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
let maxAmplitude: number;

avRecorder.getAudioCapturerMaxAmplitude((err: BusinessError, amplitude: number) => {
  if (err == null) {
    console.info('getAudioCapturerMaxAmplitude success');
    maxAmplitude = amplitude;
  } else {
    console.error('getAudioCapturerMaxAmplitude failed and error is ' + err.message);
  }
});
```

### getAudioCapturerMaxAmplitude<sup>11+</sup>

getAudioCapturerMaxAmplitude(): Promise\<number>

Obtains the maximum amplitude of the current audio capturer. This API uses a promise to return the result.

This API can be called only after the **prepare()** API is called. If this API is called after **stop()** is successfully called, an error is reported.

The return value is the maximum amplitude within the duration from the time the maximum amplitude is obtained last time to the current time. For example, if you have obtained the maximum amplitude at 1s and you call this API again at 2s, then the return value is the maximum amplitude within the duration from 1s to 2s.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------- |
| Promise\<number>| Promise used to return the maximum amplitude.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
let maxAmplitude: number;

avRecorder.getAudioCapturerMaxAmplitude().then((amplitude: number) => {
  console.info('getAudioCapturerMaxAmplitude success');
  maxAmplitude = amplitude;
}).catch((err: BusinessError) => {
  console.error('getAudioCapturerMaxAmplitude failed and catch error is ' + err.message);
});
```

### getAvailableEncoder<sup>11+</sup>

getAvailableEncoder(callback: AsyncCallback\<Array\<EncoderInfo>>): void

Obtains available encoders. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<Array\<[EncoderInfo](#encoderinfo11)>> | Yes  | Callback used to return the information about the available encoders.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
let encoderInfo: media.EncoderInfo;

avRecorder.getAvailableEncoder((err: BusinessError, info: media.EncoderInfo) => {
  if (err == null) {
    console.info('getAvailableEncoder success');
    encoderInfo = info;
  } else {
    console.error('getAvailableEncoder failed and error is ' + err.message);
  }
});
```

### getAvailableEncoder<sup>11+</sup>

getAvailableEncoder(): Promise\<Array\<EncoderInfo>>

Obtains available encoders. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type                                           | Description                                           |
| ----------------------------------------------- | ----------------------------------------------- |
| Promise\<Array\<[EncoderInfo](#encoderinfo11)>> | Promise used to return the information about the available encoders.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
let encoderInfo: media.EncoderInfo;

avRecorder.getAvailableEncoder().then((info: media.EncoderInfo) => {
  console.info('getAvailableEncoder success');
  encoderInfo = info;
}).catch((err: BusinessError) => {
  console.error('getAvailableEncoder failed and catch error is ' + err.message);
});
```

### getAVRecorderConfig<sup>11+</sup>

getAVRecorderConfig(callback: AsyncCallback\<AVRecorderConfig>): void

Obtains the real-time configuration of this AVRecorder. This API uses an asynchronous callback to return the result.

This API can be called only after [prepare()](#prepare9-2) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<[AVRecorderConfig](#avrecorderconfig9)> | Yes  | Callback used to return the real-time configuration.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let AVRecorderConfig: AVRecorderConfig;

avRecorder.getAVRecorderConfig((err: BusinessError, config: AVRecorderConfig) => {
  if (err == null) {
    console.info('getAVRecorderConfig success');
    AVRecorderConfig = config;
  } else {
    console.error('getAVRecorderConfig failed and error is ' + err.message);
  }
});
```

### getAVRecorderConfig<sup>11+</sup>

getAVRecorderConfig(): Promise\<AVRecorderConfig>;

Obtains the real-time configuration of this AVRecorder. This API uses a promise to return the result.

This API can be called only after [prepare()](#prepare9-3) is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<[AVRecorderConfig](#avrecorderconfig9)> | Promise used to return the real-time configuration.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let AVRecorderConfig: AVRecorderConfig;

avRecorder.getAVRecorderConfig().then((config: AVRecorderConfig) => {
  console.info('getAVRecorderConfig success');
  AVRecorderConfig = config;
}).catch((err: BusinessError) => {
  console.error('getAVRecorderConfig failed and catch error is ' + err.message);
});
```

### on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void

Subscribes to AVRecorder state changes. An application can subscribe to only one AVRecorder state change event. When the application initiates multiple subscriptions to this event, the last subscription prevails.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case. This event can be triggered by both user operations and the system.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the following information:<br>**state**: [AVRecorderState](#avrecorderstate9), indicating the AVRecorder state.<br>**reason**: [StateChangeReason](#statechangereason9), indicating the reason for the state transition.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**Example**

```ts
avRecorder.on('stateChange', async (state: media.AVRecorderState, reason: media.StateChangeReason) => {
  console.info('case state has changed, new state is :' + state + ',and new reason is : ' + reason);
});
```

### off('stateChange')<sup>9+</sup>

off(type: 'stateChange'): void

Unsubscribes from AVRecorder state changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'stateChange'** in this case. This event can be triggered by both user operations and the system.|

**Example**

```ts
avRecorder.off('stateChange');
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to AVRecorder errors. This event is used only for error prompt and does not require the user to stop recording control. If the [AVRecorderState](#avrecorderstate9) is also switched to error, call [reset()](#reset9-2) or [release()][release()](#release9-2) to exit the recording.

An application can subscribe to only one AVRecorder error event. When the application initiates multiple subscriptions to this event, the last subscription prevails.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during recording.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback invoked when the event is triggered.                                      |

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 201      | Permission denied.     |
| 401      | The Parameter check faild. |
| 801      | Capability not supported. |
| 5400101  | No memory. Return by callback.             |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400104  | Time out. Return by callback.              |
| 5400105  | Service died. Return by callback.          |
| 5400106  | Unsupport format. Return by callback.      |
| 5400107  | Audio interrupted. Return by callback.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.on('error', (err: BusinessError) => {
  console.info('case avRecorder.on(error) called, errMessage is ' + err.message);
});
```

### off('error')<sup>9+</sup>

off(type: 'error'): void

Unsubscribes from AVRecorder errors. After the unsubscription, your application can no longer receive AVRecorder errors.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during recording.|

**Example**

```ts
avRecorder.off('error');
```

### on('audioCapturerChange')<sup>11+</sup>

on(type: 'audioCapturerChange', callback: Callback<audio.AudioCapturerChangeInfo>): void

Subscribes to audio capturer configuration changes. Any configuration change triggers the callback that returns the entire configuration information.

When the application initiates multiple subscriptions to this event, the last subscription prevails.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  |Event type, which is **'audioCapturerChange'** in this case.|
| callback | Callback<[audio.AudioCapturerChangeInfo](../apis-audio-kit/js-apis-audio.md#audiocapturerchangeinfo9)> | Yes| Callback used to return the entire configuration information about the audio capturer.|

**Error codes**

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |

**Example**

```ts
let capturerChangeInfo: audio.AudioCapturerChangeInfo;

avRecorder.on('audioCapturerChange',  (audioCapturerChangeInfo: audio.AudioCapturerChangeInfo) => {
  console.info('audioCapturerChange success');
  capturerChangeInfo = audioCapturerChangeInfo;
});
```

### off('audioCapturerChange')<sup>11+</sup>

off(type: 'audioCapturerChange'): void

Subscribes to audio capturer configuration changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'audioCapturerChange'** in this case.|

**Example**

```ts
avRecorder.off('audioCapturerChange');
```

## AVRecorderState<sup>9+</sup>

Enumerates the AVRecorder states. You can obtain the state through the **state** attribute.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name    | Type  | Description                                                        |
| -------- | ------ | ------------------------------------------------------------ |
| idle     | string | The AVRecorder enters this state after it is just created or the [AVRecorder.reset()](#reset9-2) API is called when the AVRecorder is in any state except released. In this state, you can call [AVRecorder.prepare()](#prepare9-2) to set recording parameters.  |
| prepared | string | The AVRecorder enters this state when the parameters are set. In this state, you can call [AVRecorder.start()](#start9) to start recording.|
| started  | string | The AVRecorder enters this state when the recording starts. In this state, you can call [AVRecorder.pause()](#pause9-2) to pause recording or call [AVRecorder.stop()](#stop9-2) to stop recording.|
| paused   | string | The AVRecorder enters this state when the recording is paused. In this state, you can call [AVRecorder.resume()](#resume9) to continue recording or call [AVRecorder.stop()](#stop9-2) to stop recording.|
| stopped  | string | The AVRecorder enters this state when the recording stops. In this state, you can call [AVRecorder.prepare()](#prepare9-2) to set recording parameters so that the AVRecorder enters the prepared state again.|
| released | string | The AVRecorder enters this state when the recording resources are released. In this state, no operation can be performed. In any other state, you can call [AVRecorder.release()](#release9-2) to enter the released state.|
| error    | string | The AVRecorder enters this state when an irreversible error occurs in the **AVRecorder** instance. In this state, the [AVRecorder.on('error') event](#onerror9-1) is reported, with the detailed error cause. In the error state, you must call [AVRecorder.reset()](#reset9-2) to reset the **AVRecorder** instance or call [AVRecorder.release()](#release9-2) to release the resources.|

## AVRecorderConfig<sup>9+</sup>

Describes the audio and video recording parameters.

The **audioSourceType** and **videoSourceType** parameters are used to distinguish audio-only recording, video-only recording, and audio and video recording. For audio-only recording, set only **audioSourceType**. For video-only recording, set only **videoSourceType**. For audio and video recording, set both **audioSourceType** and **videoSourceType**.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name           | Type                                    | Mandatory| Description                                                        |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](#audiosourcetype9)     | No  | Type of the audio source to record. This parameter is mandatory for audio recording.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| videoSourceType | [VideoSourceType](#videosourcetype9)     | No  | Type of the video source to record. This parameter is mandatory for video recording.                  |
| profile         | [AVRecorderProfile](#avrecorderprofile9) | Yes  | Recording profile. This parameter is mandatory.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| url             | string                                   | Yes  | Recording output URL: fd://xx (fd number).<br>![img](figures/en-us_image_url.png)<br>This parameter is mandatory.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| rotation<sup>(deprecated)</sup>        | number                                   | No  | Rotation angle of the recorded video. The value can be 0 (default), 90, 180, or 270 for MP4 videos.<br>This API is supported since API version 6 and deprecated since API version 12. You are advised to use **[AVMetadata](#avmetadata11).videoOrientation** instead. If both parameters are set, **[AVMetadata](#avmetadata11).videoOrientation** is used.    |
| location<sup>(deprecated)</sup>        | [Location](#location)                    | No  | Geographical location of the recorded video. By default, the geographical location information is not recorded.<br>This API is supported since API version 6 and deprecated since API version 12. You are advised to use **[AVMetadata](#avmetadata11).location** instead. If both parameters are set, **[AVMetadata](#avmetadata11).location** is used.|
| metadata<sup>12+</sup>        | [AVMetadata](#avmetadata11)              | No  | Metadata. For details, see [AVMetadata](#avmetadata11).                 |

<!--RP1-->
## AVRecorderProfile<sup>9+</sup>

Describes the audio and video recording profile.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name            | Type                                        | Mandatory| Description                                                        |
| ---------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioBitrate     | number                                       | No  | Audio encoding bit rate. This parameter is mandatory for audio recording. The value range is [8000 - 384000].<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| audioChannels    | number                                       | No  | Number of audio channels. This parameter is mandatory for audio recording. The value range is [1 - 2].<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| audioCodec       | [CodecMimeType](#codecmimetype8)             | No  | Audio encoding format. This parameter is mandatory for audio recording. Only **AUDIO_AAC** is supported.<br>**Atomic service API**: This API can be used in atomic services since API version 12.    |
| audioSampleRate  | number                                       | No  | Audio sampling rate. This parameter is mandatory for audio recording. The value range is [8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000, 64000, 96000].<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| fileFormat       | [ContainerFormatType](#containerformattype8) | Yes  | Container format of a file. This parameter is mandatory.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| videoBitrate     | number                                       | No  | Video encoding bit rate. This parameter is mandatory for video recording. The value range is [1 - 3000000]. |
| videoCodec       | [CodecMimeType](#codecmimetype8)             | No  | Video encoding format. This parameter is mandatory for video recording. Currently, VIDEO_AVC is supported.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| videoFrameWidth  | number                                       | No  | Width of a video frame. This parameter is mandatory for video recording. The value range is [2 - 1920].        |
| videoFrameHeight | number                                       | No  | Height of a video frame. This parameter is mandatory for video recording. The value range is [2 - 1080].        |
| videoFrameRate   | number                                       | No  | Video frame rate. This parameter is mandatory for video recording. The value range is [1 - 30].            |
| isHdr<sup>11+</sup>            | boolean                        | No  | HDR encoding. This parameter is optional for video recording. The default value is **false**, and there is no requirement on the encoding format. When **isHdr** is set to **true**, the encoding format must be **video/hevc**.|
| enableTemporalScale<sup>12+</sup>            | boolean                        | No  | Whether temporal layered encoding is supported. This parameter is optional for video recording. The default value is **false**. If this parameter is set to **true**, some frames in the video output streams can be skipped without being encoded.|
<!--RP1End-->

## AudioSourceType<sup>9+</sup>

Enumerates the audio source types for video recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name                     | Value  | Description                  |
| ------------------------- | ---- | ---------------------- |
| AUDIO_SOURCE_TYPE_DEFAULT | 0    | Default audio input source.|
| AUDIO_SOURCE_TYPE_MIC     | 1    | Microphone audio input source.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## VideoSourceType<sup>9+</sup>

Enumerates the video source types for video recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name                         | Value  | Description                           |
| ----------------------------- | ---- | ------------------------------- |
| VIDEO_SOURCE_TYPE_SURFACE_YUV | 0    | The input surface carries raw data.|
| VIDEO_SOURCE_TYPE_SURFACE_ES  | 1    | The input surface carries ES data. |

## ContainerFormatType<sup>8+</sup>

Enumerates the container format types (CFTs).

**System capability**: SystemCapability.Multimedia.Media.Core

| Name       | Value   | Description                 |
| ----------- | ----- | --------------------- |
| CFT_MPEG_4  | 'mp4' | Video container format MP4.|
| CFT_MPEG_4A | 'm4a' | Audio container format M4A.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## Location

Describes the geographical location of the recorded video.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name     | Type  | Mandatory| Description            |
| --------- | ------ | ---- | ---------------- |
| latitude  | number | Yes  | Latitude of the geographical location.|
| longitude | number | Yes  | Longitude of the geographical location.|

## EncoderInfo<sup>11+</sup>

Describes the information about an encoder.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name      | Type                            | Readable| Writable| Description                                                        |
| ---------- | -------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| mimeType   | [CodecMimeType](#codecmimetype8) | Yes  | No  | MIME type of the encoder.                                          |
| type       | string                           | Yes  | No  | Encoder type. The value **audio** means an audio encoder, and **video** means a video encoder.        |
| bitRate    | [Range](#range11)                | Yes  | No  | Bit rate range of the encoder, with the minimum and maximum bit rates specified.                          |
| frameRate  | [Range](#range11)                | Yes  | No  | Video frame rate range, with the minimum and maximum frame rates specified. This parameter is available only for video encoders.          |
| width      | [Range](#range11)                | Yes  | No  | Video frame width range, with the minimum and maximum widths specified. This parameter is available only for video encoders.      |
| height     | [Range](#range11)                | Yes  | No  | Video frame height range, with the minimum and maximum heights specified. This parameter is available only for video encoders.      |
| channels   | [Range](#range11)                | Yes  | No  | Number of audio channels for the audio capturer, with the minimum and maximum numbers of audio channels specified. This parameter is available only for audio encoders.  |
| sampleRate | Array\<number>                    | Yes  | No  | Audio sampling rate, including all available audio sampling rates. This parameter is available only for audio encoders.|

## Range<sup>11+</sup>

Describes a range.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name| Type  | Readable| Writable| Description        |
| ---- | ------ | ---- | ---- | ------------ |
| min  | number | Yes  | No  | Minimum value.|
| max  | number | Yes  | No  | Maximum value.|



## AVMetadataExtractor<sup>11+</sup>

Provides APIs to obtain metadata from media resources. Before calling any API of **AVMetadataExtractor**, you must use [createAVMetadataExtractor()](#mediacreateavmetadataextractor11) to create an **AVMetadataExtractor** instance.

For details about the demo for obtaining audio or video metadata, see [Obtaining Audio/Video Metadata](../../media/media/avmetadataextractor.md).

### Attributes

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

| Name                                               | Type                                                        | Readable| Writable| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fdSrc<sup>11+</sup>                                  | [AVFileDescriptor](#avfiledescriptor9)                       | Yes  | Yes  | Media file descriptor, which specifies the data source. Before obtaining metadata, you must set the data source through either **fdSrc** or **dataSrc**.<br>**Example:**<br>There is a media file that stores continuous assets, the address offset is 0, and the byte length is 100. Its file descriptor is **AVFileDescriptor {fd = resourceHandle; offset = 0; length = 100; }**.|
| dataSrc<sup>11+</sup>                               | [AVDataSrcDescriptor](#avdatasrcdescriptor10)                | Yes  | Yes  | Streaming media resource descriptor, which specifies the data source. Before obtaining metadata, you must set the data source through either **fdSrc** or **dataSrc**.<br> When an application obtains a media file from the remote, you can set **dataSrc** to obtain the metadata before the application finishes the downloading.|

### fetchMetadata<sup>11+</sup>

fetchMetadata(callback: AsyncCallback\<AVMetadata>): void

Obtains media metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<[AVMetadata](#avmetadata11)>       | Yes  | Callback used to return the result, which is an **AVMetadata** instance.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.fetchMetadata((error: BusinessError, metadata: media.AVMetadata) => {
  if (error) {
    console.error(`fetchMetadata callback failed, err = ${JSON.stringify(error)}`);
    return;
  }
  console.info(`fetchMetadata callback success, genre: ${metadata.genre}`);
});
```

### fetchMetadata<sup>11+</sup>

fetchMetadata(): Promise\<AVMetadata>

Obtains media metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[AVMetadata](#avmetadata11)>  | Promise used to return the result, which is an **AVMetadata** instance.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.fetchMetadata().then((metadata: media.AVMetadata) => {
  console.info(`fetchMetadata callback success, genre: ${metadata.genre}`)
}).catch((error: BusinessError) => {
  console.error(`fetchMetadata catchCallback, error message:${error.message}`);
});
```

### fetchAlbumCover<sup>11+</sup>

fetchAlbumCover(callback: AsyncCallback\<image.PixelMap>): void

Obtains the cover of the audio album. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)>    | Yes  | Callback used to return the album cover.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let pixel_map : image.PixelMap | undefined = undefined;

avMetadataExtractor.fetchAlbumCover((error: BusinessError, pixelMap: image.PixelMap) => {
  if (error) {
    console.error(`fetchAlbumCover callback failed, error = ${JSON.stringify(error)}`);
    return;
  }
  pixel_map = pixelMap;
});
```

### fetchAlbumCover<sup>11+</sup>

fetchAlbumCover(): Promise\<image.PixelMap>

Obtains the cover of the audio album. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> |  Promise used to return the album cover.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let pixel_map : image.PixelMap | undefined = undefined;

avMetadataExtractor.fetchAlbumCover().then((pixelMap: image.PixelMap) => {
  pixel_map = pixelMap;
}).catch((error: BusinessError) => {
  console.error(`fetchAlbumCover catchCallback, error message:${error.message}`);
});
```

### release<sup>11+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **AVMetadataExtractor** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.release((error: BusinessError) => {
  if (error) {
    console.error(`release failed, err = ${JSON.stringify(error)}`);
    return;
  }
  console.info(`release success.`);
});
```

### release<sup>11+</sup>

release(): Promise\<void>

Releases this **AVMetadataExtractor** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avMetadataExtractor.release().then(() => {
  console.info(`release success.`);
}).catch((error: BusinessError) => {
  console.error(`release catchCallback, error message:${error.message}`);
});
```

## AVMetadata<sup>11+</sup>

Defines the audio and video metadata. Parameters that are not declared as read-only in [AVRecorderConfig](#avrecorderconfig9) can be used as input parameters for recording of [AVRecorder](#avrecorder9).

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| album     | string | No  | Title of the album. This parameter is read-only in the current version.    |
| albumArtist | string | No  | Artist of the album. This parameter is read-only in the current version.|
| artist | string | No  | Artist of the media asset. This parameter is read-only in the current version.|
| author | string | No  | Author of the media asset. This parameter is read-only in the current version.|
| dateTime | string | No  | Time when the media asset is created. This parameter is read-only in the current version.|
| dateTimeFormat | string | No  | Time when the media asset is created. The value is in the YYYY-MM-DD HH:mm:ss format. This parameter is read-only in the current version.|
| composer | string | No  | Composer of the media asset. This parameter is read-only in the current version.|
| duration | string | No  | Duration of the media asset. This parameter is read-only in the current version.|
| genre | string | No  | Type or genre of the media asset.|
| hasAudio | string | No  | Whether the media asset contains audio. This parameter is read-only in the current version.|
| hasVideo | string | No  | Whether the media asset contains a video. This parameter is read-only in the current version.|
| mimeType | string | No  | MIME type of the media asset. This parameter is read-only in the current version.|
| trackCount | string | No  | Number of tracks of the media asset. This parameter is read-only in the current version.|
| sampleRate | string | No  | Audio sampling rate, in Hz. This parameter is read-only in the current version.|
| title | string | No  | Title of the media asset. This parameter is read-only in the current version. This parameter is read-only in the current version.|
| videoHeight | string | No  | Video height, in px. This parameter is read-only in the current version.|
| videoWidth | string | No  | Video width, in px. This parameter is read-only in the current version.|
| videoOrientation | string | No  | Video rotation direction, in degrees.|
| hdrType<sup>12+</sup> | [HdrType](#hdrtype12) | No  | HDR type of the media asset.|
| location<sup>12+</sup> | [Location](#location) | No| Geographical location of the media asset.|
| customInfo<sup>12+</sup> | Record<string, string> | No| Custom key-value mappings obtained from **moov.meta.list**.|

## HdrType<sup>12+</sup>

Enumerates the HDR types.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                     | Value  | Description                  |
| ------------------------- | ---- | ---------------------- |
| AV_HDR_TYPE_NONE          | 0    | No HDR.|
| AV_HDR_TYPE_VIVID         | 1    | HDR VIVID.|

## media.createAudioPlayer<sup>(deprecated)</sup>

createAudioPlayer(): AudioPlayer

Creates an **AudioPlayer** instance in synchronous mode.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [createAVPlayer](#mediacreateavplayer9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Return value**

| Type                       | Description                                                        |
| --------------------------- | ------------------------------------------------------------ |
| [AudioPlayer](#audioplayerdeprecated) | If the operation is successful, an **AudioPlayer** instance is returned; otherwise, **null** is returned. After the instance is created, you can start, pause, or stop audio playback.|

**Example**

```ts
let audioPlayer: media.AudioPlayer = media.createAudioPlayer();
```

## media.createVideoPlayer<sup>(deprecated)</sup>

createVideoPlayer(callback: AsyncCallback\<VideoPlayer>): void

Creates a **VideoPlayer** instance. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [createAVPlayer](#mediacreateavplayer9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[VideoPlayer](#videoplayerdeprecated)> | Yes  | Callback used to return the result. If the operation is successful, a **VideoPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to manage and play video.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error(`video createVideoPlayer fail, error:${error}`);
  }
});
```

## media.createVideoPlayer<sup>(deprecated)</sup>

createVideoPlayer(): Promise\<VideoPlayer>

Creates a **VideoPlayer** instance. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [createAVPlayer](#mediacreateavplayer9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| Promise<[VideoPlayer](#videoplayerdeprecated)> | Promise used to return the result. If the operation is successful, a **VideoPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to manage and play video.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer().then((video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error('video createVideoPlayer fail');
  }
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## media.createAudioRecorder<sup>(deprecated)</sup>

createAudioRecorder(): AudioRecorder

Creates an **AudioRecorder** instance to control audio recording.
Only one **AudioRecorder** instance can be created per device.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [createAVRecorder](#mediacreateavrecorder9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [AudioRecorder](#audiorecorderdeprecated) | If the operation is successful, an **AudioRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record audio.|

**Example**

```ts
let audioRecorder: media.AudioRecorder = media.createAudioRecorder();
```

## MediaErrorCode<sup>(deprecated)</sup>

Enumerates the media error codes.

> **NOTE**
>
> This enum is supported since API version 8 and deprecated since API version 11. You are advised to use [Media Error Codes](#averrorcode9) instead.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                      | Value  | Description                                  |
| -------------------------- | ---- | -------------------------------------- |
| MSERR_OK                   | 0    | The operation is successful.                        |
| MSERR_NO_MEMORY            | 1    | Failed to allocate memory. The system may have no available memory.|
| MSERR_OPERATION_NOT_PERMIT | 2    | No permission to perform the operation.                |
| MSERR_INVALID_VAL          | 3    | Invalid input parameter.                    |
| MSERR_IO                   | 4    | An I/O error occurs.                      |
| MSERR_TIMEOUT              | 5    | The operation times out.                        |
| MSERR_UNKNOWN              | 6    | An unknown error occurs.                        |
| MSERR_SERVICE_DIED         | 7    | Invalid server.                      |
| MSERR_INVALID_STATE        | 8    | The operation is not allowed in the current state.  |
| MSERR_UNSUPPORTED          | 9    | The operation is not supported in the current version.      |

## AudioPlayer<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer](#avplayer9) instead.

Provides APIs to manage and play audio. Before calling any API in **AudioPlayer**, you must use [createAudioPlayer()](#mediacreateaudioplayerdeprecated) to create an **AudioPlayer** instance.

### Attributes<sup>(deprecated)</sup>

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name                           | Type                                                  | Readable| Writable| Description                                                        |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| src                             | string                                                 | Yes  | Yes  | Audio file URI. The mainstream audio formats (M4A, AAC, MP3, OGG, WAV, and AMR) are supported.<br>**Example of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http\://xx<br>3. HTTPS: https\://xx<br>4. HLS: http\://xx or https\://xx<br>**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.INTERNET|
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | Yes  | Yes  | Description of the audio file. This attribute is required when audio assets of an application are continuously stored in a file.<br>**Example:**<br>Assume that a music file that stores continuous music assets consists of the following:<br>Music 1 (address offset: 0, byte length: 100)<br>Music 2 (address offset: 101; byte length: 50)<br>Music 3 (address offset: 151, byte length: 150)<br>1. To play music 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play music 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play music 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent music file, use **src=fd://xx**.<br>|
| loop                            | boolean                                                | Yes  | Yes  | Whether to loop audio playback. The value **true** means to loop audio playback, and **false** means the opposite.                |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9) | Yes  | Yes  | Audio interruption mode.                                              |
| currentTime                     | number                                                 | Yes  | No  | Current audio playback position, in ms.                      |
| duration                        | number                                                 | Yes  | No  | Audio duration, in ms.                                |
| state                           | [AudioState](#audiostatedeprecated)                              | Yes  | No  | Audio playback state. This state cannot be used as the condition for triggering the call of **play()**, **pause()**, or **stop()**.|

### play<sup>(deprecated)</sup>

play(): void

Starts to play an audio asset. This API can be called only after the **'dataLoad'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.play](#play9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('play', () => {    // Set the 'play' event callback.
  console.info('audio play success');
});
audioPlayer.play();
```

### pause<sup>(deprecated)</sup>

pause(): void

Pauses audio playback.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.pause](#pause9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('pause', () => {    // Set the 'pause' event callback.
  console.info('audio pause success');
});
audioPlayer.pause();
```

### stop<sup>(deprecated)</sup>

stop(): void

Stops audio playback.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.stop](#stop9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('stop', () => {    // Set the 'stop' event callback.
  console.info('audio stop success');
});
audioPlayer.stop();
```

### reset<sup>(deprecated)</sup>

reset(): void

Resets the audio asset to be played.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [AVPlayer.reset](#reset9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('reset', () => {    // Set the 'reset' event callback.
  console.info('audio reset success');
});
audioPlayer.reset();
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number): void

Seeks to the specified playback position.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.seek](#seek9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                       |
| ------ | ------ | ---- | ----------------------------------------------------------- |
| timeMs | number | Yes  | Position to seek to, in ms. The value range is [0, duration].|

**Example**

```ts
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {    // Set the 'timeUpdate' event callback.
  if (seekDoneTime == null) {
    console.error('audio seek fail');
    return;
  }
  console.info('audio seek success. seekDoneTime: ' + seekDoneTime);
});
audioPlayer.seek(30000); // Seek to 30000 ms.
```

### setVolume<sup>(deprecated)</sup>

setVolume(vol: number): void

Sets the volume.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.setVolume](#setvolume9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|

**Example**

```ts
audioPlayer.on('volumeChange', () => {    // Set the 'volumeChange' event callback.
  console.info('audio volumeChange success');
});
audioPlayer.setVolume(1);    // Set the volume to 100%.
```

### release<sup>(deprecated)</sup>

release(): void

Releases the audio playback resources.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.release](#release9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.release();
audioPlayer = undefined;
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the audio track information. This API uses an asynchronous callback to return the result. It can be called only after the **'dataLoad'** event is triggered.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.getTrackDescription](#gettrackdescription9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the audio track information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    console.info('audio getTrackDescription success');
  } else {
    console.error(`audio getTrackDescription fail, error:${error}`);
  }
});
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

Obtains the audio track information. This API uses a promise to return the result. It can be called only after the **'dataLoad'** event is triggered.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.getTrackDescription](#gettrackdescription9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Return value**

| Type                                                  | Description                                           |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return a **MediaDescription** array, which records the audio track information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  console.info('audio getTrackDescription success');
}).catch((error: BusinessError) => {
  console.error(`audio catchCallback, error:${error}`);
});
```

### on('bufferingUpdate')<sup>(deprecated)</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to the audio buffering update event. This API works only under online playback.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.on('bufferingUpdate')](#onbufferingupdate9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | function | Yes  | Callback invoked when the event is triggered.<br>When [BufferingInfoType](#bufferinginfotype8) is set to **BUFFERING_PERCENT** or **CACHED_DURATION**, **value** is valid. Otherwise, **value** is fixed at **0**.|

**Example**

```ts
audioPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('audio bufferingInfo type: ' + infoType);
  console.info('audio bufferingInfo value: ' + value);
});
```

### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')<sup>(deprecated)</sup>

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void): void

Subscribes to the audio playback events.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.on('stateChange')](#onstatechange9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type      | Mandatory| Description                                                        |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | Yes  | Event type. The following events are supported:<br>- 'play': triggered when the [play()](#playdeprecated) API is called and audio playback starts.<br>- 'pause': triggered when the [pause()](#pausedeprecated) API is called and audio playback is paused.<br>- 'stop': triggered when the [stop()](#stopdeprecated) API is called and audio playback stops.<br>- 'reset': triggered when the [reset()](#resetdeprecated) API is called and audio playback is reset.<br>- 'dataLoad': triggered when the audio data is loaded, that is, when the **src** attribute is configured.<br>- 'finish': triggered when the audio playback is finished.<br>- 'volumeChange': triggered when the [setVolume()](#setvolumedeprecated) API is called and the playback volume is changed.|
| callback | () => void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioPlayer: media.AudioPlayer = media.createAudioPlayer();  // Create an AudioPlayer instance.
audioPlayer.on('dataLoad', () => {            // Set the 'dataLoad' event callback, which is triggered when the src attribute is set successfully.
  console.info('audio set source success');
  audioPlayer.play();                       // Start the playback and trigger the 'play' event callback.
});
audioPlayer.on('play', () => {                // Set the 'play' event callback.
  console.info('audio play success');
  audioPlayer.seek(30000);                  // Call the seek() API and trigger the 'timeUpdate' event callback.
});
audioPlayer.on('pause', () => {               // Set the 'pause' event callback.
  console.info('audio pause success');
  audioPlayer.stop();                       // Stop the playback and trigger the 'stop' event callback.
});
audioPlayer.on('reset', () => {               // Set the 'reset' event callback.
  console.info('audio reset success');
  audioPlayer.release();                    // Release the AudioPlayer instance.
  audioPlayer = undefined;
});
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {  // Set the 'timeUpdate' event callback.
  if (seekDoneTime == null) {
    console.error('audio seek fail');
    return;
  }
  console.info('audio seek success, and seek time is ' + seekDoneTime);
  audioPlayer.setVolume(0.5);                // Set the volume to 50% and trigger the 'volumeChange' event callback.
});
audioPlayer.on('volumeChange', () => {         // Set the 'volumeChange' event callback.
  console.info('audio volumeChange success');
  audioPlayer.pause();                       // Pause the playback and trigger the 'pause' event callback.
});
audioPlayer.on('finish', () => {               // Set the 'finish' event callback.
  console.info('audio play finish');
  audioPlayer.stop();                        // Stop the playback and trigger the 'stop' event callback.
});
audioPlayer.on('error', (error: BusinessError) => {  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});

// Set the FD (local playback) of the audio file selected by the user.
let fdPath = 'fd://';
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
fileIo.open(path).then((file) => {
  fdPath = fdPath + '' + file.fd;
  console.info('open fd success fd is' + fdPath);
  audioPlayer.src = fdPath;  // Set the src attribute and trigger the 'dataLoad' event callback.
}, (err: BusinessError) => {
  console.error('open fd failed err is' + err);
}).catch((err: BusinessError) => {
  console.error('open fd failed err is' + err);
});
```

### on('timeUpdate')<sup>(deprecated)</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

Subscribes to the **'timeUpdate'** event. This event is reported every second when the audio playback is in progress.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.on('timeUpdate')](#ontimeupdate9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type             | Mandatory| Description                                                        |
| -------- | ----------------- | ---- | ------------------------------------------------------------ |
| type     | string            | Yes  | Event type, which is **'timeUpdate'** in this case.<br>The **'timeUpdate'** event is triggered when the audio playback starts after an audio playback timestamp update.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. The input parameter is the updated timestamp.            |

**Example**

```ts
audioPlayer.on('timeUpdate', (newTime: number) => {    // Set the 'timeUpdate' event callback.
  if (newTime == null) {
    console.error('audio timeUpadate fail');
    return;
  }
  console.info('audio timeUpadate success. seekDoneTime: ' + newTime);
});
audioPlayer.play();    // The 'timeUpdate' event is triggered when the playback starts.
```

### on('audioInterrupt')<sup>(deprecated)</sup>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

Subscribes to the audio interruption event. For details, see [audio.InterruptEvent](../apis-audio-kit/js-apis-audio.md#interruptevent9).

> **NOTE**
>
> This API is supported in API version 9 and deprecated since API version 9. You are advised to use [AVPlayer.on('audioInterrupt')](#onaudiointerrupt9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'audioInterrupt'** in this case.|
| callback | function  | Yes  | Callback invoked when the event is triggered.                              |

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt success,and InterruptEvent info is:' + info)
})
```

### on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to audio playback error events. After an error event is reported, you must handle the event and exit the playback.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.on('error')](#onerror9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during audio playback.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioPlayer.on('error', (error: BusinessError) => {  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});
audioPlayer.setVolume(3); // Set volume to an invalid value to trigger the 'error' event.
```

## AudioState<sup>(deprecated)</sup>

Enumerates the audio playback states. You can obtain the state through the **state** attribute.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayerState](#avplayerstate9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name   | Type  | Description                                          |
| ------- | ------ | ---------------------------------------------- |
| idle    | string | No audio playback is in progress. The audio player is in this state after the **'dataload'** or **'reset'** event is triggered.|
| playing | string | Audio playback is in progress. The audio player is in this state after the **'play'** event is triggered.          |
| paused  | string | Audio playback is paused. The audio player is in this state after the **'pause'** event is triggered.         |
| stopped | string | Audio playback is stopped. The audio player is in this state after the **'stop'** event is triggered.     |
| error   | string | Audio playback is in the error state.                                    |

## VideoPlayer<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer](#avplayer9) instead.

Provides APIs to manage and play video. Before calling any API of **VideoPlayer**, you must use [createVideoPlayer()](#mediacreatevideoplayerdeprecated) to create a **VideoPlayer** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                           | Type                                                  | Readable| Writable| Description                                                        |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>                | string                                                 | Yes  | Yes  | Video URL. The video formats MP4, MPEG-TS, and MKV are supported.<br>**Example of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http\://xx<br>3. HTTPS: https\://xx<br>4. HLS: http\://xx or https\://xx<br>5. File type: file\://xx<br>**NOTE**<br>WebM is no longer supported since API version 11.|
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | Yes  | Yes  | Description of a video file. This attribute is required when video assets of an application are continuously stored in a file.<br>**Example:**<br>Assume that a music file that stores continuous music assets consists of the following:<br>Video 1 (address offset: 0, byte length: 100)<br>Video 2 (address offset: 101; byte length: 50)<br>Video 3 (address offset: 151, byte length: 150)<br>1. To play video 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play video 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play video 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent video file, use **src=fd://xx**.<br>|
| loop<sup>8+</sup>               | boolean                                                | Yes  | Yes  | Whether to loop video playback. The value **true** means to loop video playback, and **false** means the opposite.                |
| videoScaleType<sup>9+</sup>     | [VideoScaleType](#videoscaletype9)                     | Yes  | Yes  | Video scale type. The default value is **VIDEO_SCALE_TYPE_FIT**.                                              |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](../apis-audio-kit/js-apis-audio.md#interruptmode9) | Yes  | Yes  | Audio interruption mode.                                              |
| currentTime<sup>8+</sup>        | number                                                 | Yes  | No  | Current video playback position, in ms.                      |
| duration<sup>8+</sup>           | number                                                 | Yes  | No  | Video duration, in ms. The value **-1** indicates the live mode.            |
| state<sup>8+</sup>              | [VideoPlayState](#videoplaystatedeprecated)                    | Yes  | No  | Video playback state.                                            |
| width<sup>8+</sup>              | number                                                 | Yes  | No  | Video width, in px.                                  |
| height<sup>8+</sup>             | number                                                 | Yes  | No  | Video height, in px.                                  |

### setDisplaySurface<sup>(deprecated)</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

Sets **SurfaceId**. This API uses an asynchronous callback to return the result.

*Note: **SetDisplaySurface** must be called between the URL setting and the calling of **prepare**. A surface must be set for video streams without audio. Otherwise, the calling of **prepare** fails.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.surfaceId](#attributes) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name   | Type                | Mandatory| Description                     |
| --------- | -------------------- | ---- | ------------------------- |
| surfaceId | string               | Yes  | Surface ID to set.                |
| callback  | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let surfaceId: string = '';
videoPlayer.setDisplaySurface(surfaceId, (err: BusinessError) => {
  if (err == null) {
    console.info('setDisplaySurface success!');
  } else {
    console.error('setDisplaySurface fail!');
  }
});
```

### setDisplaySurface<sup>(deprecated)</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

Sets **SurfaceId**. This API uses a promise to return the result.

*Note: **SetDisplaySurface** must be called between the URL setting and the calling of **prepare**. A surface must be set for video streams without audio. Otherwise, the calling of **prepare** fails.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.surfaceId](#attributes) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name   | Type  | Mandatory| Description     |
| --------- | ------ | ---- | --------- |
| surfaceId | string | Yes  | Surface ID to set.|

**Return value**

| Type          | Description                          |
| -------------- | ------------------------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let surfaceId: string = '';
videoPlayer.setDisplaySurface(surfaceId).then(() => {
  console.info('setDisplaySurface success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### prepare<sup>(deprecated)</sup>

prepare(callback: AsyncCallback\<void>): void

Prepares for video playback. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.prepare](#prepare9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.prepare((err: BusinessError) => {
  if (err == null) {
    console.info('prepare success!');
  } else {
    console.error('prepare fail!');
  }
});
```

### prepare<sup>(deprecated)</sup>

prepare(): Promise\<void>

Prepares for video playback. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.prepare](#prepare9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.prepare().then(() => {
  console.info('prepare success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### play<sup>(deprecated)</sup>

play(callback: AsyncCallback\<void>): void

Starts to play video assets. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.play](#play9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.play((err: BusinessError) => {
  if (err == null) {
    console.info('play success!');
  } else {
    console.error('play fail!');
  }
});
```

### play<sup>(deprecated)</sup>

play(): Promise\<void>

Starts to play video assets. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.play](#play9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.play().then(() => {
  console.info('play success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### pause<sup>(deprecated)</sup>

pause(callback: AsyncCallback\<void>): void

Pauses video playback. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.pause](#pause9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.pause((err: BusinessError) => {
  if (err == null) {
    console.info('pause success!');
  } else {
    console.error('pause fail!');
  }
});
```

### pause<sup>(deprecated)</sup>

pause(): Promise\<void>

Pauses video playback. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.pause](#pause9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.pause().then(() => {
  console.info('pause success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void>): void

Stops video playback. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.stop](#stop9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.stop((err: BusinessError) => {
  if (err == null) {
    console.info('stop success!');
  } else {
    console.error('stop fail!');
  }
});
```

### stop<sup>(deprecated)</sup>

stop(): Promise\<void>

Stops video playback. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.stop](#stop9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.stop().then(() => {
  console.info('stop success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### reset<sup>(deprecated)</sup>

reset(callback: AsyncCallback\<void>): void

Resets the video asset to be played. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.reset](#reset9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.reset((err: BusinessError) => {
  if (err == null) {
    console.info('reset success!');
  } else {
    console.error('reset fail!');
  }
});
```

### reset<sup>(deprecated)</sup>

reset(): Promise\<void>

Resets the video asset to be played. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.reset](#reset9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.reset().then(() => {
  console.info('reset success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. The previous key frame at the specified position is played. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.seek](#seek9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | Yes  | Position to seek to, in ms. The value range is [0, duration].|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error(`video createVideoPlayer fail, error:${error}`);
  }
});

let seekTime: number = 5000;
videoPlayer.seek(seekTime, (err: BusinessError, result: number) => {
  if (err == null) {
    console.info('seek success!');
  } else {
    console.error('seek fail!');
  }
});
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.seek](#seek9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | Yes  | Position to seek to, in ms. The value range is [0, duration].|
| mode     | [SeekMode](#seekmode8) | Yes  | Seek mode.                                                  |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error(`video createVideoPlayer fail, error:${error}`);
  }
});
let seekTime: number = 5000;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC, (err: BusinessError, result: number) => {
    if (err == null) {
      console.info('seek success!');
    } else {
      console.error('seek fail!');
    }
  });
}
```

### seek<sup>(deprecated)</sup>

seek(timeMs: number, mode?:SeekMode): Promise\<number>

Seeks to the specified playback position. If **mode** is not specified, the previous key frame at the specified position is played. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.seek](#seek9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name| Type                  | Mandatory| Description                                                        |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | Yes  | Position to seek to, in ms. The value range is [0, duration].|
| mode   | [SeekMode](#seekmode8) | No  | Seek mode based on the video I frame. The default value is **SEEK_PREV_SYNC**.           |

**Return value**

| Type            | Description                                       |
| ---------------- | ------------------------------------------- |
| Promise\<number>| Promise used to return the playback position, in ms.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error(`video createVideoPlayer fail, error:${error}`);
  }
});
let seekTime: number = 5000;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).seek(seekTime).then((seekDoneTime: number) => { // seekDoneTime indicates the position after the seek operation is complete.
    console.info('seek success');
  }).catch((error: BusinessError) => {
    console.error(`video catchCallback, error:${error}`);
  });

  (videoPlayer as media.VideoPlayer).seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC).then((seekDoneTime: number) => {
    console.info('seek success');
  }).catch((error: BusinessError) => {
    console.error(`video catchCallback, error:${error}`);
  });
}
```

### setVolume<sup>(deprecated)</sup>

setVolume(vol: number, callback: AsyncCallback\<void>): void

Sets the volume. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.setVolume](#setvolume9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| vol      | number               | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                                        |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let vol: number = 0.5;
videoPlayer.setVolume(vol, (err: BusinessError) => {
  if (err == null) {
    console.info('setVolume success!');
  } else {
    console.error('setVolume fail!');
  }
});
```

### setVolume<sup>(deprecated)</sup>

setVolume(vol: number): Promise\<void>

Sets the volume. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.setVolume](#setvolume9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let vol: number = 0.5;
videoPlayer.setVolume(vol).then(() => {
  console.info('setVolume success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### release<sup>(deprecated)</sup>

release(callback: AsyncCallback\<void>): void

Releases the video playback resources. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.release](#release9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.release((err: BusinessError) => {
  if (err == null) {
    console.info('release success!');
  } else {
    console.error('release fail!');
  }
});
```

### release<sup>(deprecated)</sup>

release(): Promise\<void>

Releases the video playback resources. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.release](#release9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.release().then(() => {
  console.info('release success');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the video track information. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.getTrackDescription](#gettrackdescription9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the video track information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if ((arrList) != null) {
    console.info('video getTrackDescription success');
  } else {
    console.error(`video getTrackDescription fail, error:${error}`);
  }
});
```

### getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

Obtains the video track information. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.getTrackDescription](#gettrackdescription9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                                  | Description                                           |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return a **MediaDescription** array, which records the video track information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    console.info('video getTrackDescription success');
  } else {
    console.error('video getTrackDescription fail');
  }
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### setSpeed<sup>(deprecated)</sup>

setSpeed(speed: number, callback: AsyncCallback\<number>): void

Sets the video playback speed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.setSpeed](#setspeed9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                                                      |
| -------- | ---------------------- | ---- | ---------------------------------------------------------- |
| speed    | number                 | Yes  | Video playback speed. For details, see [PlaybackSpeed](#playbackspeed8).|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error(`video createVideoPlayer fail, error:${error}`);
  }
});
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).setSpeed(speed, (err: BusinessError, result: number) => {
    if (err == null) {
      console.info('setSpeed success!');
    } else {
      console.error('setSpeed fail!');
    }
  });
}
```

### setSpeed<sup>(deprecated)</sup>

setSpeed(speed: number): Promise\<number>

Sets the video playback speed. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.setSpeed](#setspeed9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                      |
| ------ | ------ | ---- | ---------------------------------------------------------- |
| speed  | number | Yes  | Video playback speed. For details, see [PlaybackSpeed](#playbackspeed8).|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number>| Promise used to return playback speed. For details, see [PlaybackSpeed](#playbackspeed8).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error(`video createVideoPlayer fail, error:${error}`);
  }
});
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).setSpeed(speed).then((result: number) => {
    console.info('setSpeed success');
  }).catch((error: BusinessError) => {
    console.error(`video catchCallback, error:${error}`);
  });
}
```

### on('playbackCompleted')<sup>(deprecated)</sup>

on(type: 'playbackCompleted', callback: Callback\<void>): void

Subscribes to the video playback completion event.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.on('stateChange')](#onstatechange9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'playbackCompleted'** in this case.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                                 |

**Example**

```ts
videoPlayer.on('playbackCompleted', () => {
  console.info('playbackCompleted success!');
});
```

### on('bufferingUpdate')<sup>(deprecated)</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to the video buffering update event. Only network playback supports this subscription.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.on('bufferingUpdate')](#onbufferingupdate9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | function | Yes  | Callback invoked when the event is triggered.<br>When [BufferingInfoType](#bufferinginfotype8) is set to **BUFFERING_PERCENT** or **CACHED_DURATION**, **value** is valid. Otherwise, **value** is fixed at **0**.|

**Example**

```ts
videoPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('video bufferingInfo type: ' + infoType);
  console.info('video bufferingInfo value: ' + value);
});
```

### on('startRenderFrame')<sup>(deprecated)</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

Subscribes to the frame rendering start event.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.on('startRenderFrame')](#onstartrenderframe9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type           | Mandatory| Description                                                        |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | Yes  | Event type, which is **'startRenderFrame'** in this case.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                          |

**Example**

```ts
videoPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame success!');
});
```

### on('videoSizeChanged')<sup>(deprecated)</sup>

on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void

Subscribes to the video width and height change event.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.on('videoSizeChange')](#onvideosizechange9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'videoSizeChanged'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered. **width** indicates the video width, and **height** indicates the video height.   |

**Example**

```ts
videoPlayer.on('videoSizeChanged', (width: number, height: number) => {
  console.info('video width is: ' + width);
  console.info('video height is: ' + height);
});
```
### on('audioInterrupt')<sup>(deprecated)</sup>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

Subscribes to the audio interruption event. For details, see [audio.InterruptEvent](../apis-audio-kit/js-apis-audio.md#interruptevent9).

> **NOTE**
>
> This API is supported in API version 9 and deprecated since API version 9. You are advised to use [AVPlayer.on('audioInterrupt')](#onaudiointerrupt9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'audioInterrupt'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered.                              |

**Example**

```ts
import { audio } from '@kit.AudioKit';

videoPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt success,and InterruptEvent info is:' + info)
})
```

### on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to video playback error events. After an error event is reported, you must handle the event and exit the playback.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.on('error')](#onerror9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during video playback.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.on('error', (error: BusinessError) => {  // Set the 'error' event callback.
  console.error(`video error called, error: ${error}`);
});
videoPlayer.url = 'fd://error';  // Set an incorrect URL to trigger the 'error' event.
```

## VideoPlayState<sup>(deprecated)</sup>

Enumerates the video playback states. You can obtain the state through the **state** attribute.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayerState](#avplayerstate9) instead.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name    | Type  | Description          |
| -------- | ------ | -------------- |
| idle     | string | The video player is idle.|
| prepared | string | Video playback is being prepared.|
| playing  | string | Video playback is in progress.|
| paused   | string | Video playback is paused.|
| stopped  | string | Video playback is stopped.|
| error    | string | Video playback is in the error state.    |

## AudioRecorder<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder](#avrecorder9) instead.

Implements audio recording. Before calling any API of **AudioRecorder**, you must use [createAudioRecorder()](#mediacreateaudiorecorderdeprecated) to create an **AudioRecorder** instance.

### prepare<sup>(deprecated)</sup>

prepare(config: AudioRecorderConfig): void

Prepares for recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.prepare](#prepare9-2) instead.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfigdeprecated) | Yes  | Audio recording parameters, including the audio output URI, encoding format, sampling rate, number of audio channels, and output format.|

**Example**

```ts
let audioRecorderConfig: media.AudioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://1',       // The file must be created by the caller and granted with proper permissions.
  location : { latitude : 30, longitude : 130},
}
audioRecorder.on('prepare', () => {    // Set the 'prepare' event callback.
  console.info('prepare success');
});
audioRecorder.prepare(audioRecorderConfig);
```

### start<sup>(deprecated)</sup>

start(): void

Starts audio recording. This API can be called only after the **'prepare'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.start](#start9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('start', () => {    // Set the 'start' event callback.
  console.info('audio recorder start success');
});
audioRecorder.start();
```

### pause<sup>(deprecated)</sup>

pause():void

Pauses audio recording. This API can be called only after the **'start'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.pause](#pause9-2) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('pause', () => {    // Set the 'pause' event callback.
  console.info('audio recorder pause success');
});
audioRecorder.pause();
```

### resume<sup>(deprecated)</sup>

resume():void

Resumes audio recording. This API can be called only after the **'pause'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.resume](#resume9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('resume', () => { // Set the 'resume' event callback.
  console.info('audio recorder resume success');
});
audioRecorder.resume();
```

### stop<sup>(deprecated)</sup>

stop(): void

Stops audio recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.stop](#stop9-2) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('stop', () => {    // Set the 'stop' event callback.
  console.info('audio recorder stop success');
});
audioRecorder.stop();
```

### release<sup>(deprecated)</sup>

release(): void

Releases the audio recording resources.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.release](#release9-2) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('release', () => {    // Set the 'release' event callback.
  console.info('audio recorder release success');
});
audioRecorder.release();
audioRecorder = undefined;
```

### reset<sup>(deprecated)</sup>

reset(): void

Resets audio recording.

Before resetting audio recording, you must call **stop()** to stop recording. After audio recording is reset, you must call **prepare()** to set the recording configurations for another recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.reset](#reset9-2) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('reset', () => {    // Set the 'reset' event callback.
  console.info('audio recorder reset success');
});
audioRecorder.reset();
```

### on('prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset')<sup>(deprecated)</sup>

on(type: 'prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset', callback: () => void): void

Subscribes to the audio recording events.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.on('stateChange')](#onstatechange9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The following events are supported:<br>- 'prepare': triggered when the **prepare()** API is called and the audio recording parameters are set.<br>- 'start': triggered when the **start()** API is called and audio recording starts.<br>- 'pause': triggered when the **pause()** API is called and audio recording is paused.<br>- 'resume': triggered when the **resume()** API is called and audio recording is resumed.<br>- 'stop': triggered when the **stop()** API is called and audio recording stops.<br>- 'release': triggered when the **release()** API is called and the recording resources are released.<br>- 'reset': triggered when the **reset()** API is called and audio recording is reset.|
| callback | ()=>void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioRecorder: media.AudioRecorder = media.createAudioRecorder(); // Create an AudioRecorder instance.
let audioRecorderConfig: media.AudioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://xx',  // The file must be created by the caller and granted with proper permissions.
  location : { latitude : 30, longitude : 130}
}
audioRecorder.on('error', (error: BusinessError) => {  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});
audioRecorder.on('prepare', () => {  // Set the 'prepare' event callback.
  console.info('prepare success');
  audioRecorder.start();  // // Start recording and trigger the 'start' event callback.
});
audioRecorder.on('start', () => {  // Set the 'start' event callback.
  console.info('audio recorder start success');
});
audioRecorder.on('pause', () => {  // Set the 'pause' event callback.
  console.info('audio recorder pause success');
});
audioRecorder.on('resume', () => {  // Set the 'resume' event callback.
  console.info('audio recorder resume success');
});
audioRecorder.on('stop', () => {  // Set the 'stop' event callback.
  console.info('audio recorder stop success');
});
audioRecorder.on('release', () => {  // Set the 'release' event callback.
  console.info('audio recorder release success');
});
audioRecorder.on('reset', () => {  // Set the 'reset' event callback.
  console.info('audio recorder reset success');
});
audioRecorder.prepare(audioRecorderConfig)  // // Set recording parameters and trigger the 'prepare' event callback.
```

### on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to audio recording error events. After an error event is reported, you must handle the event and exit the recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.on('error')](#onerror9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during audio recording.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioRecorderConfig: media.AudioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://xx',   // The file must be created by the caller and granted with proper permissions.
  location : { latitude : 30, longitude : 130}
}
audioRecorder.on('error', (error: BusinessError) => {  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});
audioRecorder.prepare(audioRecorderConfig);  // // Do not set any parameter in prepare and trigger the 'error' event callback.
```

## AudioRecorderConfig<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorderConfig](#avrecorderconfig9) instead.

Describes audio recording configurations.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name                               | Type                                        | Mandatory| Description                                                        |
| ----------------------------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioEncoder                        | [AudioEncoder](#audioencoderdeprecated)                | No  | Audio encoding format. The default value is **AAC_LC**.<br>**Note**: This parameter is deprecated since API version 8. Use **audioEncoderMime** instead.|
| audioEncodeBitRate                  | number                                       | No  | Audio encoding bit rate. The default value is **48000**.                             |
| audioSampleRate                     | number                                       | No  | Audio sampling rate. The default value is **48000**.                             |
| numberOfChannels                    | number                                       | No  | Number of audio channels. The default value is **2**.                                 |
| format                              | [AudioOutputFormat](#audiooutputformatdeprecated)      | No  | Audio output format. The default value is **MPEG_4**.<br>**Note**: This parameter is deprecated since API version 8. Use **fileFormat** instead.|
| location                            | [Location](#location)                        | No  | Geographical location of the recorded audio.                                        |
| uri                                 | string                                       | Yes  | Audio output URI. Supported: fd://xx (fd number)<br>![](figures/en-us_image_url.png) <br>The file must be created by the caller and granted with proper permissions.|
| audioEncoderMime<sup>8+</sup>       | [CodecMimeType](#codecmimetype8)             | No  | Container encoding format.                                              |
| fileFormat<sup>8+</sup>             | [ContainerFormatType](#containerformattype8) | No  | Audio encoding format.                                              |

## AudioEncoder<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 8. You are advised to use [CodecMimeType](#codecmimetype8) instead.

Enumerates the audio encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name   | Value  | Description                                                        |
| ------- | ---- | ------------------------------------------------------------ |
| DEFAULT | 0    | Default encoding format.<br>This API is defined but not implemented yet.             |
| AMR_NB  | 1    | AMR-NB.<br>This API is defined but not implemented yet.|
| AMR_WB  | 2    | Adaptive Multi Rate-Wide Band Speech Codec (AMR-WB).<br>This API is defined but not implemented yet.|
| AAC_LC  | 3    | Advanced Audio Coding Low Complexity (AAC-LC).|
| HE_AAC  | 4    | High-Efficiency Advanced Audio Coding (HE_AAC).<br>This API is defined but not implemented yet.|

## AudioOutputFormat<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 8. You are advised to use [ContainerFormatType](#containerformattype8) instead.

Enumerates the audio output formats.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name    | Value  | Description                                                        |
| -------- | ---- | ------------------------------------------------------------ |
| DEFAULT  | 0    | Default encapsulation format.<br>This API is defined but not implemented yet.             |
| MPEG_4   | 2    | MPEG-4.                                          |
| AMR_NB   | 3    | AMR_NB.<br>This API is defined but not implemented yet.         |
| AMR_WB   | 4    | AMR_WB.<br>This API is defined but not implemented yet.         |
| AAC_ADTS | 6    | Audio Data Transport Stream (ADTS), which is a transport stream format of AAC-based audio.|


## media.createAVImageGenerator<sup>12+</sup>

createAVImageGenerator(callback: AsyncCallback\<AVImageGenerator>): void

Creates an **AVImageGenerator** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVImageGenerator](#avimagegenerator12)> | Yes  | Callback used to return the result. If the operation is successful, an **AVImageGenerator** instance is returned; otherwise, **null** is returned. The API can be used to obtain a video thumbnail.|

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
  if (generator != null) {
    avImageGenerator = generator;
    console.info('createAVImageGenerator success');
  } else {
    console.error(`createAVImageGenerator fail, error message:${error.message}`);
  }
});
```

## media.createAVImageGenerator<sup>12+</sup>

createAVImageGenerator(): Promise\<AVImageGenerator>

Creates an **AVImageGenerator** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVImageGenerator](#avimagegenerator12)> | Promise used to return the result. If the operation is successful, an **AVImageGenerator** instance is returned; otherwise, **null** is returned. The API can be used to obtain a video thumbnail.|

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
  if (generator != null) {
    avImageGenerator = generator;
    console.info('createAVImageGenerator success');
  } else {
    console.error('createAVImageGenerator fail');
  }
}).catch((error: BusinessError) => {
  console.error(`AVImageGenerator catchCallback, error message:${error.message}`);
});
```

## AVImageGenerator<sup>12+</sup>

Provides APIs to obtain a thumbnail from a video. Before calling any API of **AVImageGenerator**, you must use [createAVImageGenerator()](#mediacreateavimagegenerator12) to create an **AVImageGenerator** instance.

For details about the demo for obtaining video thumbnails, see [Obtaining Video Thumbnails](../../media/media/avimagegenerator.md).

### Attributes

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

| Name                                               | Type                                                        | Readable| Writable| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| fdSrc<sup>12+</sup>                                  | [AVFileDescriptor](js-apis-media.md#avfiledescriptor9)                       | Yes  | Yes  | Media file descriptor, which specifies the data source.<br>**Example:**<br>There is a media file that stores continuous assets, the address offset is 0, and the byte length is 100. Its file descriptor is **AVFileDescriptor {fd = resourceHandle; offset = 0; length = 100; }**.|

### fetchFrameByTime<sup>12+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams, callback: AsyncCallback\<image.PixelMap>): void

Obtains a video thumbnail. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | Yes  | Time of the video for which a thumbnail is to be obtained, in μs.|
| options | [AVImageQueryOptions](#avimagequeryoptions12)     | Yes  | Relationship between the time passed in and the video frame.|
| param | [PixelMapParams](#pixelmapparams12)     | Yes  | Format parameters of the thumbnail to be obtained.|
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)>   | Yes  | Callback used to return the video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |
| 5400106  | Unsupported format. Returned by callback.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';
import { image } from '@kit.ImageKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// Initialize input parameters.
let timeUs: number = 0

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
}

// Obtain the thumbnail.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`createAVImageGenerator success`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param, (error: BusinessError, pixelMap) => {
      if (error) {
        console.error(`fetchFrameByTime callback failed, err = ${JSON.stringify(error)}`)
        return
      }
      pixel_map = pixelMap;
    });
  } else {
    console.error(`createAVImageGenerator fail, error message:${err.message}`);
  };
});
```

### fetchFrameByTime<sup>12+</sup>

fetchFrameByTime(timeUs: number, options: AVImageQueryOptions, param: PixelMapParams): Promise<image.PixelMap>

Obtains a video thumbnail. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| timeUs | number                   | Yes  | Time of the video for which a thumbnail is to be obtained, in μs.|
| options | [AVImageQueryOptions](#avimagequeryoptions12)     | Yes  | Relationship between the time passed in and the video frame.|
| param | [PixelMapParams](#pixelmapparams12)    | Yes  | Format parameters of the thumbnail to be obtained.|

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | Promise used to return the video thumbnail.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |
| 5400106  | Unsupported format. Returned by promise.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';
import { image } from '@kit.ImageKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;
let pixel_map : image.PixelMap | undefined = undefined;

// Initialize input parameters.
let timeUs: number = 0

let queryOption: media.AVImageQueryOptions = media.AVImageQueryOptions.AV_IMAGE_QUERY_NEXT_SYNC

let param: media.PixelMapParams = {
  width : 300,
  height : 300,
}

// Obtain the thumbnail.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`createAVImageGenerator success`);
    avImageGenerator.fetchFrameByTime(timeUs, queryOption, param).then((pixelMap: image.PixelMap) => {
      pixel_map = pixelMap;
    }).catch((error: BusinessError) => {
      console.error(`fetchFrameByTime catchCallback, error message:${error.message}`);
    });
  } else {
    console.error(`createAVImageGenerator fail, error message:${err.message}`);
  };
});
```

### release<sup>12+</sup>

release(callback: AsyncCallback\<void>): void

Releases this **AVMetadataExtractor** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Returned by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

// Release the instance.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`createAVImageGenerator success`);
    avImageGenerator.release((error: BusinessError) => {
      if (error) {
        console.error(`release failed, err = ${JSON.stringify(error)}`);
        return;
      }
      console.info(`release success.`);
    });
  } else {
    console.error(`createAVImageGenerator fail, error message:${err.message}`);
  };
});
```

### release<sup>12+</sup>

release(): Promise\<void>

Releases this **AVMetadataExtractor** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

let avImageGenerator: media.AVImageGenerator | undefined = undefined;

// Release the instance.
media.createAVImageGenerator((err: BusinessError, generator: media.AVImageGenerator) => {
  if(generator != null){
    avImageGenerator = generator;
    console.info(`createAVImageGenerator success`);
    avImageGenerator.release().then(() => {
      console.info(`release success.`);
    }).catch((error: BusinessError) => {
      console.error(`release catchCallback, error message:${error.message}`);
    });
  } else {
    console.error(`creatAVImageGenerator fail, error message:${err.message}`);
  };
});
```

## AVImageQueryOptions<sup>12+</sup>

Enumerates the relationship between the video frame and the time at which the video thumbnail is obtained.

The time passed in for obtaining the thumbnail may be different from the time of the video frame for which the thumbnail is actually obtained. Therefore, you need to specify their relationship.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| AV_IMAGE_QUERY_NEXT_SYNC       | 0   | The key frame at or next to the specified time is selected.                      |
| AV_IMAGE_QUERY_PREVIOUS_SYNC        | 1    | The key frame at or prior to the specified time is selected.|
| AV_IMAGE_QUERY_CLOSEST_SYNC        | 2    | The key frame closest to the specified time is selected.                |

## PixelMapParams<sup>12+</sup>

Defines the format parameters of the video thumbnail to be obtained.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

| Name    | Type  |  Readable  |   Writable   |  Description                  |
| -------- | ------ |   ------| ------ | ---------------------- |
| width     | number |  Yes  |  Yes  |  Width of the thumbnail.        |
| height | number |  Yes  |  Yes  | Height of the thumbnail.|

## media.createMediaSourceWithUrl<sup>12+</sup>

createMediaSourceWithUrl(url: string, headers?: Record\<string, string>): MediaSource

Creates a media source for streaming media to be pre-downloaded.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| url | string | Yes  | - URL of the media source. The following streaming media formats are supported: HLS, HTTP-FLV, DASH, and HTTPS.<br> - FD path of the local M3U8 file. |
| header | Record\<string, string> | No  | HTTP header customized for streaming media pre-download.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| [MediaSource](#mediasource12) | **MediaSource** instance.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 5400101  | No memory. Return by callback. |

**Example 1**

```ts
import { media } from '@kit.MediaKit';

let header: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl("http://xxx",  header);
```

**Example 2**

```ts
import { media } from '@kit.MediaKit';
import { resourceManager } from '@kit.LocalizationKit';

private mgr: resourceManager.ResourceManager | null = null;
mrg = ctx.resourceManager;
this.fileDescriptor = await this.mgr.getRawFd("xxx.m3u8");

let fd:string = this.fileDescriptor.fd.toString();
let offset:string = this.fileDescriptor.offset.toString();
let length:string = this.fileDescriptor.length.toString();
let fdUrl:string = "fd://" + "?offset=" + offset + "&size=" + length;

let header: Record<string, string> = {"User-Agent" : "User-Agent-Value"};
let mediaSource : media.MediaSource = media.createMediaSourceWithUrl(fdUrl,  header);

let mimeType = media.AVMimeTypes = media.AVMimeTypes.APPLICATION_M3U8;
mediaSource.setMimeType(mimeType);

```

## MediaSource<sup>12+</sup>

Defines the media data information, which is from [createMediaSourceWithUrl](#mediacreatemediasourcewithurl12).

**System capability**: SystemCapability.Multimedia.Media.Core

### setMimeType<sup>12+</sup>

setMimeType(mimeType: AVMimeTypes): void

Sets the MIME type to help the player process extended media sources.

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| mimeType | [AVMimeTypes](#mediasource12) | Yes  | MIME type.|

## AVMimeTypes<sup>12+</sup>

Enumerates the MIME type, which is set by using [setMimeType](#setmimetype12).

**System capability**: SystemCapability.Multimedia.Media.Core


| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| APPLICATION       | application/m3u8    | Local M3U8 file.|


## PlaybackStrategy<sup>12+</sup>

Describes the playback strategy.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| preferredWidth| number | No  | Preferred width, which is of the int type, for example, **1080**.|
| preferredHeight | number | No  | Preferred height, which is of the int type, for example, **1920**.|
| preferredBufferDuration | number | No | Preferred buffer duration, in seconds. The value ranges from 1 to 20.|
| preferredHdr | boolean | No  | Whether HDR is preferred. The value **true** means that HDR is preferred, and **false** means the opposite.|

## AVScreenCaptureRecordPreset<sup>12+</sup>

Enumerates the encoding and encapsulation formats used during screen capture.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name                             | Value  | Description                                        |
| --------------------------------- | ---- | -------------------------------------------- |
| SCREEN_RECORD_PRESET_H264_AAC_MP4 | 0    | The H.264 video encoding format, AAC audio encoding format, and MP4 encapsulation format are used.|
| SCREEN_RECORD_PRESET_H265_AAC_MP4 | 1    | The H.265 video encoding format, AAC audio encoding format, and MP4 encapsulation format are used.|

## AVScreenCaptureStateCode<sup>12+</sup>

Enumerates the screen capture states used in callbacks.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name                                    | Value  | Description                    |
| ---------------------------------------- | ---- | ------------------------ |
| SCREENCAPTURE_STATE_STARTED              | 0    | Screen capture is started.            |
| SCREENCAPTURE_STATE_CANCELED             | 1    | Screen capture is canceled.            |
| SCREENCAPTURE_STATE_STOPPED_BY_USER      | 2    | Screen capture is manually stopped by the user.    |
| SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER | 3    | Screen capture is interrupted by another screen capture.    |
| SCREENCAPTURE_STATE_STOPPED_BY_CALL      | 4    | Screen capture is interrupted by an incoming call.        |
| SCREENCAPTURE_STATE_MIC_UNAVAILABLE      | 5    | The microphone is unavailable during screen capture.|
| SCREENCAPTURE_STATE_MIC_MUTED_BY_USER    | 6    | The microphone is muted by the user.      |
| SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER  | 7    | The microphone is unmuted by the user.      |
| SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE  | 8    | The system enters a privacy page during screen capture.      |
| SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE   | 9    | The system exits a privacy page during screen capture.      |

## AVScreenCaptureRecordConfig<sup>12+</sup>

Defines the screen capture parameters.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

| Name             | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| fd                | number                                                       | Yes  | FD of the file output.                                          |
| frameWidth        | number                                                       | No  | Video width, in px. The default value varies according to the display in use.|
| frameHeight       | number                                                       | No  | Video height, in px. The default value varies according to the display in use.|
| videoBitrate      | number                                                       | No  | Video bit rate . The default value is **10000000**.                            |
| audioSampleRate   | number                                                       | No  | Audio sampling rate. This value is used for both internal capture and external capture (using microphones). Only **48000** (default value) and **16000** are supported.|
| audioChannelCount | number                                                       | No  | Number of audio channels. This value is used for both internal capture and external capture (using microphones). Only **1** and **2** (default) are supported.|
| audioBitrate      | number                                                       | No  | Audio bit rate. This value is used for both internal capture and external capture (using microphones). The default value is **96000**.|
| preset            | [AVScreenCaptureRecordPreset](#avscreencapturerecordpreset12) | No  | Encoding and encapsulation format used. The default value is **SCREEN_RECORD_PRESET_H264_AAC_MP4**.|

## AVScreenCaptureRecorder<sup>12+</sup>

Provides APIs to manage screen capture. Before calling any API in **AVScreenCaptureRecorder**, you must use **createAVScreenCaptureRecorder()** to create an **AVScreenCaptureRecorder** instance.

### init<sup>12+</sup>

init(config: AVScreenCaptureRecordConfig): Promise\<void>

Initializes screen capture and sets screen capture parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name| Type                                                        | Mandatory| Description                    |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| config | [AVScreenCaptureRecordConfig](#avscreencapturerecordconfig12) | Yes  | Screen capture parameters to set.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. Return by promise. |
| 5400103  | IO error. Return by promise.                   |
| 5400105  | Service died. Return by promise.               |

**Example**

```ts
let avCaptureConfig: media.AVScreenCaptureRecordConfig = {
    fd: 0, // Before passing in an FD to this parameter, the file must be created by the caller and granted with the write permissions.
    frameWidth: 640,
    frameHeight: 480
    // Add other parameters.
}

avScreenCaptureRecorder.init(avCaptureConfig).then(() => {
    console.info('avScreenCaptureRecorder init success');
}).catch((err: BusinessError) => {
    console.info('avScreenCaptureRecorder init failed, error: ' + err.message);
})
```

### startRecording<sup>12+</sup>

startRecording(): Promise\<void>

Starts screen capture. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type          | Description                            |
| -------------- | -------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
avScreenCaptureRecorder.startRecording().then(() => {
    console.info('avScreenCaptureRecorder start success');
}).catch((err: BusinessError) => {
    console.info('avScreenCaptureRecorder start failed, error: ' + err.message);
})
```

### stopRecording+</sup>

stopRecording(): Promise\<void>

Stops screen capture. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
avScreenCaptureRecorder.stopRecording().then(() => {
    console.info('avScreenCaptureRecorder stop success');
}).catch((err: BusinessError) => {
    console.info('avScreenCaptureRecorder stop failed, error: ' + err.message);
})
```

### setMicEnabled<sup>12+</sup>

setMicEnabled(enable: boolean): Promise\<void>

Enables or disables the microphone. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| enable | boolean | Yes  | Whether to enable or disable the microphone. The value **true** means to enable the microphone, and **false** means the opposite.|

**Return value**

| Type          | Description                                   |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
avScreenCaptureRecorder.setMicEnabled(true).then(() => {
    console.info('avScreenCaptureRecorder setMicEnabled success');
}).catch((err: BusinessError) => {
    console.info('avScreenCaptureRecorder setMicEnabled failed, error: ' + err.message);
})
```

### release+</sup>

release(): Promise\<void>

Releases this **AVScreenCaptureRecorder** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Return value**

| Type          | Description                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```ts
avScreenCaptureRecorder.release().then(() => {
    console.info('avScreenCaptureRecorder release success');
}).catch((err: BusinessError) => {
    console.info('avScreenCaptureRecorder release failed, error: ' + err.message);
})
```

### on('stateChange')<sup>12+</sup>

on(type: 'stateChange', callback: Callback\<AVScreenCaptureStateCode>): void

Subscribes to screen capture state changes. An application can subscribe to only one screen capture state change event. When the application initiates multiple subscriptions to this event, the last subscription prevails.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case.           |
| callback | function | Yes  | Callback invoked when the event is triggered. **AVScreenCaptureStateCode** indicates the new state.|

**Example**

```ts
avScreenCaptureRecorder.on('stateChange', (state: media.AVScreenCaptureStateCode) => {
    console.info('avScreenCaptureRecorder stateChange to ' + state);
})
```

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to AVScreenCaptureRecorder errors. You can handle the errors based on the application logic. An application can subscribe to only one AVScreenCaptureRecorder error event. When the application initiates multiple subscriptions to this event, the last subscription prevails.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type         | Mandatory| Description                                   |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | Yes  | Event type, which is **'error'** in this case.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                 |

**Error codes**

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by ErrorCallback. |
| 5400105  | Service died. Return by ErrorCallback. |

**Example**

```ts
avScreenCaptureRecorder.on('error', (err: BusinessError) => {
    console.error('avScreenCaptureRecorder error:' + err.message);
})
```

### off('stateChange')<sup>12+</sup>

 off(type: 'stateChange', callback?: Callback\<AVScreenCaptureStateCode>): void

Unsubscribes from screen capture state changes. You can specify a callback to cancel the specified subscription.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case.           |
| callback | function | No  | Callback used for unsubscription. **AVScreenCaptureStateCode** indicates the new state. If this parameter is not specified, the last subscription is canceled.|

**Example**

```ts
avScreenCaptureRecorder.off('stateChange');
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from AVScreenCaptureRecorder errors. You can specify a callback to cancel the specified subscription.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Parameters**

| Name  | Type    | Mandatory| Description                                                      |
| -------- | -------- | ---- | ---------------------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'error'** in this case.               |
| callback | function | No  | Callback used for unsubscription. If this parameter is not specified, the last subscription is canceled.|

**Example**

```ts
avScreenCaptureRecorder.off('error');
```
