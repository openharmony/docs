# Interface (AVPlayer)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xushubo; @chennotfound-->
<!--Designer: @dongyu_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 9.

AVPlayer is a playback management class. It provides APIs to manage and play media assets. Before calling any API in AVPlayer, you must use [createAVPlayer()](arkts-apis-media-f.md#mediacreateavplayer9) to create an AVPlayer instance.

Applications must properly manage AVPlayer instances according to their specific needs, creating and freeing them when necessary. Holding too many AVPlayer instances can lead to high memory usage, and in some cases, the system might terminate applications to free up resources.

For details about the audio and video playback demo, see [Audio Playback](../../media/media/using-avplayer-for-playback.md) and [Video Playback](../../media/media/video-playback.md).

> **NOTE**
>
> When using the AVPlayer instance, you are advised to register the following callbacks to proactively obtain status changes:
>
> - [on('stateChange')](#onstatechange9): listens for AVPlayer state changes.
> - [on('error')](#onerror9): listens for error events.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name                                               | Type                                                        | Read-Only| Optional| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>9+</sup>                                    | string                                                       | No  | Yes  | URL of the media asset. It can be set only when the AVPlayer is in the idle state. <br>The video formats MP4, MPEG-TS, and MKV are supported.<br>The audio formats M4A, AAC, MP3, OGG, WAV, FLAC, AMR, and APE are supported.<br>**Example of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http\://xx<br>3. HTTPS: https\://xx<br>4. HLS: http\://xx or https\://xx<br>**NOTE**<br>- To set a network playback path, you must declare the [ohos.permission.INTERNET](../../security/AccessToken/permissions-for-all.md#ohospermissioninternet) permission by following the instructions provided in [Declaring Permissions](../../security/AccessToken/declare-permissions.md). The error code [201](../errorcode-universal.md) may be reported.<br>- WebM is no longer supported since API version 11.<br> - After the resource handle (FD) is transferred to an AVPlayer instance, do not use the resource handle to perform other read and write operations, including but not limited to transferring this handle to other AVPlayer, AVMetadataExtractor, AVImageGenerator, or AVTranscoder instance. Competition occurs when multiple AVPlayers use the same resource handle to read and write files at the same time, resulting in errors in obtaining data.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fdSrc<sup>9+</sup>                                  | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                       | No  | Yes  | FD of the media asset. It can be set only when the AVPlayer is in the idle state.<br>This property is required when media assets of an application are continuously stored in a file.<br>The video formats MP4, MPEG-TS, and MKV are supported.<br>The audio formats M4A, AAC, MP3, OGG, WAV, FLAC, AMR, and APE are supported.<br>**Example:**<br>Assume that a media file that stores continuous assets consists of the following:<br>Video 1 (address offset: 0, byte length: 100)<br>Video 2 (address offset: 101; byte length: 50)<br>Video 3 (address offset: 151, byte length: 150)<br>1. To play video 1: AVFileDescriptor { fd = resource handle; offset = 0; length = 100; }<br>2. To play video 2: AVFileDescriptor { fd = resource handle; offset = 101; length = 50; }<br>3. To play video 3: AVFileDescriptor { fd = resource handle; offset = 151; length = 150; }<br>To play an independent media file, use **src=fd://xx**.<br>**NOTE**<br>WebM is no longer supported since API version 11.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| dataSrc<sup>10+</sup>                               | [AVDataSrcDescriptor](arkts-apis-media-i.md#avdatasrcdescriptor10)                | No  | Yes  | Descriptor of a streaming media asset. It can be set only when the AVPlayer is in the idle state.<br>Use scenario: An application starts playing a media file while the file is still being downloaded from the remote to the local host.<br>The video formats MP4, MPEG-TS, and MKV are supported.<br>The audio formats M4A, AAC, MP3, OGG, WAV, FLAC, AMR, and APE are supported.<br>**Example:**<br>A user is obtaining an audio and video file from a remote server and wants to play the downloaded file content. To implement this scenario, do as follows:<br>1. Obtain the total file size, in bytes. If the total size cannot be obtained, set **fileSize** to **-1**.<br>2. Implement the **func** callback to fill in data. If **fileSize** is **-1**, the format of **func** is **func(buffer: ArrayBuffer, length: number)**, and the AVPlayer obtains data in sequence; otherwise, the format is **func(buffer: ArrayBuffer, length: number, pos: number)**, and the AVPlayer seeks and obtains data in the required positions.<br>3. Set **AVDataSrcDescriptor {fileSize = size, callback = func}**.<br>**Notes:**<br>If the media file to play is in MP4/M4A format, ensure that the **moov** field (specifying the media information) is before the **mdat** field (specifying the media data) or the fields before the **moov** field is less than 10 MB. Otherwise, the parsing fails and the media file cannot be played.<br>**NOTE**<br>WebM is no longer supported since API version 11.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| surfaceId<sup>9+</sup>                              | string                                                       | No  | Yes  | Video window ID. By default, there is no video window.<br>This parameter can be set when the AVPlayer is in the initialized state.<br>It can be set again when the AVPlayer is in the prepared, playing, paused, completed, or stopped state, in the prerequisite that the video window ID has been set in the initialized state. After the new setting is performed, the video is played in the new window.<br>It is used to render the window for video playback and therefore is not required in audio-only playback scenarios.<br>**Example:**<br>[Create a surface ID through XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| loop<sup>9+</sup>                                   | boolean                                                      | No  | No  | Whether to loop playback. **true** to loop, **false** otherwise. The default value is **false**. It is a dynamic property<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.<br>This setting is not supported in live mode.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| videoScaleType<sup>9+</sup>                         | [VideoScaleType](arkts-apis-media-e.md#videoscaletype9)                           | No  | Yes  | Video scale type. The default value is **VIDEO_SCALE_TYPE_FIT**. It is a dynamic property<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| audioInterruptMode<sup>9+</sup>                     | [audio.InterruptMode](../apis-audio-kit/arkts-apis-audio-e.md#interruptmode9)       | No  | Yes  | Audio interruption mode. The default value is **SHARE_MODE**. It is a dynamic property<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.<br>To take effect, this property must be set before [play()](#play9) is called for the first time.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| audioRendererInfo<sup>10+</sup>                     | [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8) | No  | Yes  | Audio renderer information. If the media source contains videos, the default value of **usage** is **STREAM_USAGE_MOVIE**. Otherwise, the default value of **usage** is **STREAM_USAGE_MUSIC**. The default value of **rendererFlags** is 0. If the default value of **usage** does not meet the requirements, configure [audio.AudioRendererInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiorendererinfo8).<br>This parameter can be set only when the AVPlayer is in the initialized state.<br>To take effect, this property must be set before [prepare()](#prepare9) is called for the first time.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| audioEffectMode<sup>10+</sup>                       | [audio.AudioEffectMode](../apis-audio-kit/arkts-apis-audio-e.md#audioeffectmode10)  | No  | Yes  | Audio effect mode. The audio effect mode is a dynamic property and is restored to the default value **EFFECT_DEFAULT** when **usage** of **audioRendererInfo** is changed. It can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| state<sup>9+</sup>                                  | [AVPlayerState](arkts-apis-media-t.md#avplayerstate9)                             | Yes  | No  | AVPlayer state. It can be used as a query parameter when the AVPlayer is in any state.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                 |
| currentTime<sup>9+</sup>                            | number                                                       | Yes  | No  | Current video playback position, in ms. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **-1** indicates an invalid value.<br>In live mode, **-1** is returned by default.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| duration<sup>9+</sup> | number                                                       | Yes  | No  | Video duration, in ms. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **-1** indicates an invalid value.<br>In live mode, **-1** is returned by default.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| width<sup>9+</sup>                                  | number                                                       | Yes  | No  | Video width, in px. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **0** indicates an invalid value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| height<sup>9+</sup>                                 | number                                                       | Yes  | No  | Video height, in px. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **0** indicates an invalid value.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: OnAVPlayerStateChangeHandle): void

Subscribes to AVPlayer state changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case. This event can be triggered by both user operations and the system.|
| callback | [OnAVPlayerStateChangeHandle](arkts-apis-media-t.md#onavplayerstatechangehandle12) | Yes  | Callback invoked when the event is triggered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
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

Unsubscribes from [AVPlayerState](arkts-apis-media-t.md#avplayerstate9) state changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                 |
| ------ | ------ | ---- | ----------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'stateChange'** in this case.|
| callback   | [OnAVPlayerStateChangeHandle](arkts-apis-media-t.md#onavplayerstatechangehandle12) | No  | Callback invoked when the event is triggered.<br>This parameter is supported since API version 12.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('stateChange');
```

## on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to [AVPlayer](arkts-apis-media-AVPlayer.md) errors. This event is used only for error prompt and does not require the user to stop playback control. If the [AVPlayerState](arkts-apis-media-t.md#avplayerstate9) is also switched to error, call [reset()](#reset9) or [release()](#release9) to exit the playback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'error'** in this case. This event can be triggered by both user operations and the system.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return the error code ID and error message.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

In API versions 9 to 13, error code 5400103 is reported when the network or server data flow is abnormal. In API version 14 and later, error codes 5411001 to 5411011 are reported for refined management.

| ID| Error Message             |
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

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let avPlayer = await media.createAVPlayer();
avPlayer.on('error', (error: BusinessError) => {
  console.info('error happened,and error message is :' + error.message);
  console.info('error happened,and error code is :' + error.code);
});
```

## off('error')<sup>9+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from AVPlayer errors.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | Yes  | Event type, which is **'error'** in this case.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the error code ID and error message.<br>This parameter is supported since API version 12.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
avPlayer.off('error');
```

## setMediaSource<sup>12+</sup>

setMediaSource(src:MediaSource, strategy?: PlaybackStrategy): Promise\<void>

Sets a source of streaming media that can be pre-downloaded, downloads the media data, and temporarily stores the data in the memory. For details about how to use the API, see [Video Playback](../../media/media/video-playback.md) This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| src | [MediaSource](arkts-apis-media-MediaSource.md) | Yes  | Source of the streaming media to pre-download.|
| strategy | [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12) | No  | strategy for playing the pre-downloaded streaming media.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

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

Sets a playback strategy. This API can be called only when the AVPlayer is in the initialized state.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| strategy | [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12) | Yes  | Playback strategy.|

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed. |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit';

private context: Context | undefined;
constructor(context: Context) {
  this.context = context; // this.getUIContext().getHostContext();
}

let player = await media.createAVPlayer();
let fileDescriptor = await this.context?.resourceManager.getRawFd('xxx.mp4');
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

Sets the playback range and seeks to the start position of the range based on the specified [SeekMode](arkts-apis-media-e.md#seekmode8). After the setting, only the content in the specified range of the audio or video file is played. This API uses a promise to return the result. It can be used in the initialized, prepared, paused, stopped, or completed state.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| startTimeMs | number | Yes  | Start position of the range, in ms. The value range is [0, duration). If **-1** is passed in, the system starts playing from position 0.|
| endTimeMs | number | Yes  | End position of the range, in ms. The value range is (startTimeMs, duration]. If **-1** is passed in, the system plays the content until it reaches the final part of the asset.|
| mode | [SeekMode](arkts-apis-media-e.md#seekmode8) | No  | Seek mode, which can be **SeekMode.SEEK_PREV_SYNC** or **SeekMode.SEEK_CLOSEST**.<br>The default value is **SeekMode.SEEK_PREV_SYNC**.|

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401  | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
avPlayer.setPlaybackRange(0, 6000, media.SeekMode.SEEK_CLOSEST).then(() => {
  console.info('Succeeded setPlaybackRange');
}).catch((err: BusinessError) => {
  console.error('Failed to setPlaybackRange' + err.message);
});
```

## prepare<sup>9+</sup>

prepare(callback: AsyncCallback\<void>): void

Prepares for audio and video playback. This API can be called only when the AVPlayer is in the initialized state. The state changes can be detected by subscribing to the [stateChange](#onstatechange9) event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupported format. Return by callback.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized state before proceeding.
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

Prepares for audio and video playback. This API can be called only when the AVPlayer is in the initialized state. The state changes can be detected by subscribing to the [stateChange](#onstatechange9) event. This API uses a promise to return the result.

If your application frequently switches between short videos, you can create multiple AVPlayer objects to prepare the next video in advance, thereby improving the switching performance. For details, see [Smooth Switchover Between Online Short Videos](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-smooth-switching).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400106  | Unsupported format. Return by promise.      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized state before proceeding.
avPlayer.prepare().then(() => {
  console.info('Succeeded in preparing');
}, (err: BusinessError) => {
  console.error('Failed to prepare,error message is :' + err.message);
});
```

## setMediaMuted<sup>12+</sup>

setMediaMuted(mediaType: MediaType,  muted: boolean ): Promise\<void>

Mutes or unmutes the audio.

Starting from API version 20, this API can be used to mute or unmute the video display.

This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| mediaType | [MediaType](arkts-apis-media-e.md#mediatype8) | Yes  | Media type.|
| muted | boolean | Yes  | For API version 12 to 19, only audio formats are supported. This parameter specifies whether to mute or unmute the audio. **true** to mute, **false** otherwise.<br>Starting from API version 20, video formats are also supported. This parameter specifies whether to mute or unmute the video display. **true** to mute, **false** otherwise.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message|
| -------- | ----------------------------------------- |
| 401 | The parameter check failed. Return by promise. |
| 5400102 | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized state before proceeding.
avPlayer.prepare().then(() => {
  console.info('Succeeded in preparing');
  avPlayer.setMediaMuted(media.MediaType.MEDIA_TYPE_AUD, true);
}, (err: BusinessError) => {
  console.error('Failed to prepare,error message is :' + err.message);
});
```

## play<sup>9+</sup>

play(callback: AsyncCallback\<void>): void

Starts to play an audio and video asset. This API can be called only when the AVPlayer is in the prepared, paused, or completed state. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

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

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, paused, or completed state before proceeding.
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

Starts to play an audio and video asset. This API can be called only when the AVPlayer is in the prepared, paused, or completed state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, paused, or completed state before proceeding.
avPlayer.play().then(() => {
  console.info('Succeeded in playing');
}, (err: BusinessError) => {
  console.error('Failed to play,error message is :' + err.message);
});
```

## pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses audio and video playback. This API can be called only when the AVPlayer is in the playing state. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

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

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the playing state before proceeding.
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

Pauses audio and video playback. This API can be called only when the AVPlayer is in the playing state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the playing state before proceeding.
avPlayer.pause().then(() => {
  console.info('Succeeded in pausing');
}, (err: BusinessError) => {
  console.error('Failed to pause,error message is :' + err.message);
});
```

## stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

Stops audio and video playback. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

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

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
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

Stops audio and video playback. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
avPlayer.stop().then(() => {
  console.info('Succeeded in stopping');
}, (err: BusinessError) => {
  console.error('Failed to stop,error message is :' + err.message);
});
```

## reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

Resets audio and video playback. This API can be called only when the AVPlayer is in the initialized, prepared, playing, paused, completed, stopped, or error state. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

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

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized, prepared, playing, paused, completed, stopped, or error state before proceeding.
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

Resets audio and video playback. This API can be called only when the AVPlayer is in the initialized, prepared, playing, paused, completed, stopped, or error state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized, prepared, playing, paused, completed, stopped, or error state before proceeding.
avPlayer.reset().then(() => {
  console.info('Succeeded in resetting');
}, (err: BusinessError) => {
  console.error('Failed to reset,error message is :' + err.message);
});
```

## release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

Releases the playback resources. This API can be called when the AVPlayer is in any state except released. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

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

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach a state other than released before proceeding.
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

Releases the playback resources. This API can be called when the AVPlayer is in any state except released. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach a state other than released before proceeding.
avPlayer.release().then(() => {
  console.info('Succeeded in releasing');
}, (err: BusinessError) => {
  console.error('Failed to release,error message is :' + err.message);
});
```

## getTrackDescription<sup>9+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the audio and video track information. This API can be called only when the AVPlayer is in the prepared, playing, or paused state. To obtain information about all audio and video tracks, this API must be called after the data loading callback is triggered. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the MediaDescription array obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, or paused state before proceeding.
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

Obtains the audio and video track information. This API can be called only when the AVPlayer is in the prepared, playing, or paused state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Promise used to return the MediaDescription array that holds the audio and video track information.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, or paused state before proceeding.
avPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  console.info('Succeeded in getting TrackDescription');
}).catch((error: BusinessError) => {
  console.error(`Failed to get TrackDescription, error:${error}`);
});
```

## getSelectedTracks<sup>12+</sup>

getSelectedTracks(): Promise\<Array\<number>>

Obtains the indexes of the selected audio or video tracks. This API can be called only when the AVPlayer is in the prepared, playing, or paused state. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise\<Array\<number>> | Promise used to return the index array.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, or paused state before proceeding.
avPlayer.getSelectedTracks().then((arrList: Array<number>) => {
  console.info('Succeeded in getting SelectedTracks');
}).catch((error: BusinessError) => {
  console.error(`Failed to get SelectedTracks, error:${error}`);
});
```

## getPlaybackInfo<sup>12+</sup>

getPlaybackInfo(): Promise\<PlaybackInfo>

Obtains the playback information. This API can be called only when the AVPlayer is in the prepared, playing, or paused state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<[PlaybackInfo](arkts-apis-media-i.md#playbackinfo12)> | Promise used to return **PlaybackInfo**.|

**Example**

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
        console.info(`AVPlayer getPlaybackInfo = ${JSON.stringify(playbackInfo)}`); // Print PlaybackInfo.
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

Obtains the current playback position. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
| number | Current playback time, in milliseconds.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized state before proceeding.
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

Selects a track when the AVPlayer is used to play a resource with multiple audio and video tracks. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| index | number | Yes  | Index of the track. You can call [getTrackDescription](#gettrackdescription9-1) to obtain all track information [MediaDescription](arkts-apis-media-i.md#mediadescription8) of the current resource.|
| mode   | [SwitchMode](arkts-apis-media-e.md#switchmode12) | No  | Video track switch mode. The default mode is **SMOOTH**. This parameter takes effect only for the switch of a video track for DASH streams.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | The parameter check failed. Return by promise.       |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer = await media.createAVPlayer();
let audioTrackIndex: Object = 0;
avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    for (let i = 0; i < arrList.length; i++) {
      if (i != 0) {
        // Obtain the audio track list.
        audioTrackIndex = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
      }
    }
  } else {
    console.error(`Failed to get TrackDescription, error:${error}`);
  }
});

// Select an audio track.
avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
```

## deselectTrack<sup>12+</sup>

deselectTrack(index: number): Promise\<void>

Deselects a track when the AVPlayer is used to play a resource with multiple audio and video tracks. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| index | number | Yes  | Track index, which is obtained from [MediaDescription](arkts-apis-media-i.md#mediadescription8) by calling [getTrackDescription](#gettrackdescription9-1).|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401      | The parameter check failed. Return by promise.       |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avPlayer: media.AVPlayer = await media.createAVPlayer();
let audioTrackIndex: Object = 0;
avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    for (let i = 0; i < arrList.length; i++) {
      if (i != 0) {
        // Obtain the audio track list.
        audioTrackIndex = arrList[i][media.MediaDescriptionKey.MD_KEY_TRACK_INDEX];
      }
    }
  } else {
    console.error(`Failed to get TrackDescription, error:${error}`);
  }
});

// Select an audio track.
avPlayer.selectTrack(parseInt(audioTrackIndex.toString()));
// Deselect the audio track and restore to the default audio track.
avPlayer.deselectTrack(parseInt(audioTrackIndex.toString()));
```

## setDecryptionConfig<sup>11+</sup>

setDecryptionConfig(mediaKeySession: drm.MediaKeySession, secureVideoPath: boolean): void

Sets the decryption configuration. When receiving a [mediaKeySystemInfoUpdate event](#onmediakeysysteminfoupdate11), create the related configuration and set the decryption configuration based on the information in the reported event. Otherwise, the playback fails.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| mediaKeySession | [drm.MediaKeySession](../apis-drm-kit/arkts-apis-drm-MediaKeySession.md) | Yes  | Decryption session.|
| secureVideoPath | boolean | Yes| Secure video channel. **true** if a secure video channel is selected, **false** otherwise.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

For details about the DRM module, see [@ohos.multimedia.drm](../apis-drm-kit/arkts-apis-drm.md).

```ts
import { drm } from '@kit.DrmKit';

let avPlayer = await media.createAVPlayer();
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

## getMediaKeySystemInfos<sup>11+</sup>

getMediaKeySystemInfos(): Array\<drm.MediaKeySystemInfo>

Obtains the media key system information of the media asset that is being played. This API must be called after the [mediaKeySystemInfoUpdate event](#onmediakeysysteminfoupdate11) is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
|  Array<[drm.MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)> | Array of MediaKeySystemInfo objects, each of which contains the **uuid** and **pssh** properties.|

**Example**

```ts
import { drm } from '@kit.DrmKit';

let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the mediaKeySystemInfoUpdate event to successfully trigger before proceeding.
const infos = avPlayer.getMediaKeySystemInfos();
console.info('GetMediaKeySystemInfos count: ' + infos.length);
for (let i = 0; i < infos.length; i++) {
  console.info('GetMediaKeySystemInfos uuid: ' + infos[i]["uuid"]);
  console.info('GetMediaKeySystemInfos pssh: ' + infos[i]["pssh"]);
}
```

## seek<sup>9+</sup>

seek(timeMs: number, mode?:SeekMode): void

Seeks to the specified playback position. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the seek operation takes effect by subscribing to the [seekDone](#onseekdone9) event.
This API is not supported in live mode.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type                  | Mandatory| Description                                                        |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | Yes  | Position to seek to, in ms. The value range is [0, [duration](#properties)]. In SEEK_CONTINUOU mode, the value **-1** can be used to indicate the end of SEEK_CONTINUOUS mode.|
| mode   | [SeekMode](arkts-apis-media-e.md#seekmode8) | No  | Seek mode based on the video I frame. The default value is **SEEK_PREV_SYNC**. **Set this parameter only for video playback.**|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
let seekTime: number = 1000;
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC);
```

```ts
// Use SEEK_CONTINUOUS with the onChange callback of the Slider. When slideMode is Moving, it triggers continuous seeking during the drag.
let avPlayer = await media.createAVPlayer();
let slideMovingTime: number = 2000;
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
avPlayer.seek(slideMovingTime, media.SeekMode.SEEK_CONTINUOUS);

// To end the seek when slideMode is End, call seek(-1, media.SeekMode.SEEK_CONTINUOUS).
avPlayer.seek(-1, media.SeekMode.SEEK_CONTINUOUS);
```

## isSeekContinuousSupported<sup>18+</sup>

isSeekContinuousSupported() : boolean

Checks whether the media source supports [seek](#seek9) in SEEK_CONTINUOUS mode (specified by [SeekMode](arkts-apis-media-e.md#seekmode8)). The actual value is returned when this API is called in the prepared, playing, paused, or completed state. The value **false** is returned if it is called in other states. For devices that do not support the seek operation in SEEK_CONTINUOUS mode, **false** is returned.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| boolean | Check result for the support of the seek operation in SEEK_CONTINUOUS mode. **true** if supported, **false** otherwise.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
let isSupported = avPlayer.isSeekContinuousSupported();
```

## on('seekDone')<sup>9+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

Subscribes to the event to check whether the seek operation takes effect.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'seekDone'** in this case. This event is triggered each time **seek()** is called, except in SEEK_CONTINUOUS mode.|
| callback | Callback\<number> | Yes  |  Callback invoked when the event is triggered. It reports the time position requested by the user.<br>For video playback, [SeekMode](arkts-apis-media-e.md#seekmode8) may cause the actual position to be different from that requested by the user. The exact position can be obtained from the **currentTime** property. The time in this callback only means that the requested seek operation is complete.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('seekDone', (seekDoneTime:number) => {
  console.info('seekDone called,and seek time is:' + seekDoneTime);
});
```

## off('seekDone')<sup>9+</sup>

off(type: 'seekDone', callback?: Callback\<number>): void

Unsubscribes from the event that checks whether the seek operation takes effect.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                |
| ------ | ------ | ---- | ---------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'seekDone'** in this case.|
| callback | Callback\<number> | No  |  Callback invoked when the event is triggered. It reports the time position requested by the user.<br>For video playback, [SeekMode](arkts-apis-media-e.md#seekmode8) may cause the actual position to be different from that requested by the user. The exact position can be obtained from the **currentTime** property. The time in this callback only means that the requested seek operation is complete.<br>This parameter is supported since API version 12.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('seekDone');
```

## setSpeed<sup>9+</sup>

setSpeed(speed: PlaybackSpeed): void

Sets the playback speed. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [speedDone](#onspeeddone9) event.
This API is not supported in live mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type                            | Mandatory| Description              |
| ------ | -------------------------------- | ---- | ------------------ |
| speed  | [PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8) | Yes  | Playback speed to set.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
avPlayer.setSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X);
```

## on('speedDone')<sup>9+</sup>

on(type: 'speedDone', callback: Callback\<number>): void

Subscribes to the event to check whether the playback speed is successfully set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'speedDone'** in this case. This event is triggered each time **setSpeed()** is called.|
| callback | Callback\<number> | Yes  | Callback used to return the result. When the call of **setSpeed** is successful, the effective speed mode is reported. For details, see [PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8).|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('speedDone', (speed:number) => {
  console.info('speedDone called,and speed value is:' + speed);
});
```

## off('speedDone')<sup>9+</sup>

off(type: 'speedDone', callback?: Callback\<number>): void

Unsubscribes from the event that checks whether the playback speed is successfully set.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                     |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'speedDone'** in this case.|
| callback | Callback\<number> | No  | Callback used to return the result. When the call of **setSpeed** is successful, the effective speed mode is reported. For details, see [PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8).<br>This parameter is supported since API version 12.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('speedDone');
```

## setPlaybackRate<sup>20+</sup>

setPlaybackRate(rate: number): void

Sets the playback rate. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. The value range is [0.125, 4.0]. You can check whether the setting takes effect through the [playbackRateDone](#onplaybackratedone20) event.

> **NOTE**
>
> This API is not supported in live mode.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type                            | Mandatory| Description              |
| ------ | -------------------------------- | ---- | ------------------ |
| rate  | number | Yes  | Playback rate, which is in the range [0.125, 4.0].|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400108  | The parameter check failed, parameter value out of range.      |
| 5400102  | Operation not allowed, if invalid state or live stream.     |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
avPlayer.setPlaybackRate(2.0);
```

## on('playbackRateDone')<sup>20+</sup>

on(type: 'playbackRateDone', callback: OnPlaybackRateDone): void

Subscribes to the event indicating that the playback rate set by calling [setPlaybackRate](#setplaybackrate20) is applied.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'playbackRateDone'** in this case. This event is triggered each time **setPlaybackRate** is called.|
| callback | [OnPlaybackRateDone](#onplaybackratedone20) | Yes  | Callback invoked when the event is triggered. It reports the new playback rate.<br>This parameter is supported since API version 20.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('playbackRateDone', (rate:number) => {
  console.info('playbackRateDone called,and rate value is:' + rate);
});
```

## off('playbackRateDone')<sup>20+</sup>

off(type: 'playbackRateDone', callback?: OnPlaybackRateDone): void

Unsubscribes from the event indicating that the playback rate set by calling [setPlaybackRate](#setplaybackrate20) is applied.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                     |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'playbackRateDone'** in this case.|
| callback | [OnPlaybackRateDone](#onplaybackratedone20) | No  |  Callback invoked when the event is triggered. It reports the new playback rate. If this parameter is specified, only the specified callback is unregistered. Otherwise, all callbacks associated with the specified event will be unregistered.<br>This parameter is supported since API version 20.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('playbackRateDone');
```

## setBitrate<sup>9+</sup>

setBitrate(bitrate: number): void

Sets the bit rate for the streaming media. This API is valid only for HLS/DASH streams. By default, the AVPlayer selects a proper bit rate based on the network connection speed. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [bitrateDone](#onbitratedone9) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| bitrate | number | Yes  | Bit rate to set. You can obtain the available bit rates of the current HLS/DASH stream by subscribing to the [availableBitrates](#onavailablebitrates9) event. If the bit rate to set is not in the list of the available bit rates, the AVPlayer selects from the list the bit rate that is closed to the bit rate to set. If the length of the available bit rate list obtained through the event is 0, no bit rate can be set and the **bitrateDone** callback will not be triggered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
let bitrate: number = 96000;
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the prepared, playing, paused, or completed state before proceeding.
avPlayer.setBitrate(bitrate);
```

## on('bitrateDone')<sup>9+</sup>

on(type: 'bitrateDone', callback: Callback\<number>): void

Subscribes to the event to check whether the bit rate is successfully set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bitrateDone'** in this case. This event is triggered each time **setBitrate()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the effective bit rate.            |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('bitrateDone', (bitrate:number) => {
  console.info('bitrateDone called,and bitrate value is:' + bitrate);
});
```

## off('bitrateDone')<sup>9+</sup>

off(type: 'bitrateDone', callback?: Callback\<number>): void

Unsubscribes from the event that checks whether the bit rate is successfully set.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'bitrateDone'** in this case.|
| callback | Callback\<number> | No  | Callback invoked when the event is triggered. It reports the effective bit rate.<br>This parameter is supported since API version 12.            |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('bitrateDone');
```

## on('availableBitrates')<sup>9+</sup>

on(type: 'availableBitrates', callback: Callback\<Array\<number>>): void

Subscribes to available bit rates of HLS/DASH streams. This event is reported only after the AVPlayer switches to the prepared state.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'availableBitrates'** in this case. This event is triggered once after the AVPlayer switches to the prepared state.|
| callback | Callback\<Array\<number>> | Yes  | Callback invoked when the event is triggered. It returns an array that holds the available bit rates. If the array length is 0, no bit rate can be set.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
  console.info('availableBitrates called,and availableBitrates length is:' + bitrates.length);
});
```

## off('availableBitrates')<sup>9+</sup>

off(type: 'availableBitrates', callback?: Callback\<Array\<number>>): void

Unsubscribes from available bit rates of HLS/DASH streams. This event is reported after [prepare](#prepare9) is called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'availableBitrates'** in this case.|
| callback | Callback\<Array\<number>> | No  | Callback invoked when the event is triggered. It returns an array that holds the available bit rates. If the array length is 0, no bit rate can be set.<br>This parameter is supported since API version 12.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('availableBitrates');
```


## on('mediaKeySystemInfoUpdate')<sup>11+</sup>

on(type: 'mediaKeySystemInfoUpdate', callback: Callback\<Array\<drm.MediaKeySystemInfo>>): void

Subscribes to media key system information changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'mediaKeySystemInfoUpdate'** in this case. This event is triggered when the copyright protection information of the media asset being played changes.|
| callback | Callback\<Array\<drm.[MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)>> | Yes  | Callback invoked when the event is triggered. It reports a **MediaKeySystemInfo** array.|

**Example**

```ts
import { drm } from '@kit.DrmKit';

let avPlayer = await media.createAVPlayer();
avPlayer.on('mediaKeySystemInfoUpdate', (mediaKeySystemInfo: Array<drm.MediaKeySystemInfo>) => {
    for (let i = 0; i < mediaKeySystemInfo.length; i++) {
      console.info('mediaKeySystemInfoUpdate happened uuid: ' + mediaKeySystemInfo[i]["uuid"]);
      console.info('mediaKeySystemInfoUpdate happened pssh: ' + mediaKeySystemInfo[i]["pssh"]);
    }
});
```

## off('mediaKeySystemInfoUpdate')<sup>11+</sup>

off(type: 'mediaKeySystemInfoUpdate', callback?: Callback\<Array\<drm.MediaKeySystemInfo>>): void;

Unsubscribes from media key system information changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'mediaKeySystemInfoUpdate'** in this case.|
| callback | Callback\<Array\<drm.[MediaKeySystemInfo](../apis-drm-kit/arkts-apis-drm-i.md#mediakeysysteminfo)>> | No  | Callback invoked when the event is triggered. It reports a **MediaKeySystemInfo** array. If this parameter is specified, only the specified callback is unregistered. Otherwise, all callbacks associated with the specified event will be unregistered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('mediaKeySystemInfoUpdate');
```

## setVolume<sup>9+</sup>

setVolume(volume: number): void

Sets the volume. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [volumeChange](#onvolumechange9) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| volume | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
let volume: number = 1.0;
avPlayer.setVolume(volume);
```

## on('volumeChange')<sup>9+</sup>

on(type: 'volumeChange', callback: Callback\<number>): void

Subscribes to the event to check whether the volume is successfully set.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'volumeChange'** in this case. This event is triggered each time **setVolume()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the effective volume.           |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('volumeChange', (vol: number) => {
  console.info('volumeChange called,and new volume is :' + vol);
});
```

## off('volumeChange')<sup>9+</sup>

off(type: 'volumeChange', callback?: Callback\<number>): void

Unsubscribes from the event that checks whether the volume is successfully set.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'volumeChange'** in this case.|
| callback | Callback\<number> | No  | Callback invoked when the event is triggered. It reports the effective volume.<br>This parameter is supported since API version 12.           |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('volumeChange');
```

## on('endOfStream')<sup>9+</sup>

on(type: 'endOfStream', callback: Callback\<void>): void

Subscribes to the event that indicates the end of the stream being played. If **[loop](#properties) = true** is set, the AVPlayer seeks to the beginning of the stream and plays the stream again. If **loop** is not set, the completed state is reported through the [stateChange](#onstatechange9) event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'endOfStream'** in this case. This event is triggered when the AVPlayer finishes playing the media asset.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                              |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('endOfStream', () => {
  console.info('endOfStream called');
});
```

## off('endOfStream')<sup>9+</sup>

off(type: 'endOfStream', callback?: Callback\<void>): void

Unsubscribes from the event that indicates the end of the stream being played.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'endOfStream'** in this case.|
| callback | Callback\<void> | No  | Callback invoked when the event is triggered.<br>This parameter is supported since API version 12.                              |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('endOfStream');
```

## on('timeUpdate')<sup>9+</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

Subscribes to playback position changes. It is used to refresh the current position of the progress bar. By default, this event is reported every 100 ms. However, it is reported immediately upon a successful seek operation.

The **'timeUpdate'** event is not supported in live mode.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                          |
| -------- | -------- | ---- | ---------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'timeUpdate'** in this case.|
| callback | Callback\<number> | Yes  | Callback used to return the current time.                                    |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('timeUpdate', (time:number) => {
  console.info('timeUpdate called,and new time is :' + time);
});
```

## off('timeUpdate')<sup>9+</sup>

off(type: 'timeUpdate', callback?: Callback\<number>): void

Unsubscribes from playback position changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                              |
| ------ | ------ | ---- | -------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'timeUpdate'** in this case.|
| callback | Callback\<number> | No  | Callback used to return the current time.<br>This parameter is supported since API version 12.            |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('timeUpdate');
```

## on('durationUpdate')<sup>9+</sup>


on(type: 'durationUpdate', callback: Callback\<number>): void

Subscribes to media asset duration changes. It is used to refresh the length of the progress bar. By default, this event is reported once in the prepared state. However, it can be repeatedly reported for special streams that trigger duration changes.
The **'durationUpdate'** event is not supported in live mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                              |
| -------- | -------- | ---- | -------------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'durationUpdate'** in this case.|
| callback | Callback\<number> | Yes  | Callback used to return the resource duration.       |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('durationUpdate', (duration: number) => {
  console.info('durationUpdate called,new duration is :' + duration);
});
```

## off('durationUpdate')<sup>9+</sup>

off(type: 'durationUpdate', callback?: Callback\<number>): void

Unsubscribes from media asset duration changes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'durationUpdate'** in this case.|
| callback | Callback\<number> | No  | Callback used to return the resource duration.<br>This parameter is supported since API version 12.       |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('durationUpdate');
```

## on('bufferingUpdate')<sup>9+</sup>

on(type: 'bufferingUpdate', callback: OnBufferingUpdateHandler): void

Subscribes to audio and video buffer changes. This subscription is supported only in network playback scenarios.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | [OnBufferingUpdateHandler](arkts-apis-media-t.md#onbufferingupdatehandler12) | Yes  | Callback invoked when the event is triggered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('bufferingUpdate called,and infoType value is:' + infoType + ', value is :' + value);
});
```

## off('bufferingUpdate')<sup>9+</sup>

off(type: 'bufferingUpdate', callback?: OnBufferingUpdateHandler): void

Unsubscribes from audio and video buffer changes. 

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                     |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'bufferingUpdate'** in this case.|
| callback | [OnBufferingUpdateHandler](arkts-apis-media-t.md#onbufferingupdatehandler12) | No  | Callback invoked when the event is triggered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('bufferingUpdate');
```

## on('startRenderFrame')<sup>9+</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

Subscribes to the event that indicates rendering starts for the first frame. This subscription is supported only in video playback scenarios. This event only means that the playback service sends the first frame to the display module. The actual rendering effect depends on the rendering performance of the display service.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'startRenderFrame'** in this case.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                          |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame called');
});
```

## off('startRenderFrame')<sup>9+</sup>

off(type: 'startRenderFrame', callback?: Callback\<void>): void

Unsubscribes from the event that indicates rendering starts for the first frame.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'startRenderFrame'** in this case.|
| callback | Callback\<void> | No  | Callback invoked when the event is triggered.<br>This parameter is supported since API version 12.                  |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('startRenderFrame');
```

## on('videoSizeChange')<sup>9+</sup>

on(type: 'videoSizeChange', callback: OnVideoSizeChangeHandler): void

Subscribes to video size (width and height) changes. This subscription is supported only in video playback scenarios. By default, this event is reported only once in the prepared state. However, it is also reported upon resolution changes in the case of HLS streams.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'videoSizeChange'** in this case.|
| callback | [OnVideoSizeChangeHandler](arkts-apis-media-t.md#onvideosizechangehandler12) | Yes  | Callback invoked when the event is triggered.   |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('videoSizeChange', (width: number, height: number) => {
  console.info('videoSizeChange called,and width is:' + width + ', height is :' + height);
});
```

## off('videoSizeChange')<sup>9+</sup>

off(type: 'videoSizeChange', callback?: OnVideoSizeChangeHandler): void

Unsubscribes from video size changes. 

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'videoSizeChange'** in this case.|
| callback | [OnVideoSizeChangeHandler](arkts-apis-media-t.md#onvideosizechangehandler12) | No  | Callback invoked when the event is triggered.<br>This parameter is supported since API version 12.   |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('videoSizeChange');
```

## on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: Callback\<audio.InterruptEvent>): void

Subscribes to the audio interruption event. When multiple audio and video assets are played at the same time, this event is triggered based on the audio interruption mode [audio.InterruptMode](../apis-audio-kit/arkts-apis-audio-e.md#interruptmode9). The application needs to perform corresponding processing based on different audio interruption events. For details, see [Handling Audio Interruption Events](../../media/audio/audio-playback-concurrency.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'audioInterrupt'** in this case.|
| callback | Callback\<[audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)> | Yes  | Callback invoked when the event is triggered.                          |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let avPlayer = await media.createAVPlayer();
avPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt called,and InterruptEvent info is:' + info);
});
```

## off('audioInterrupt')<sup>9+</sup>

off(type: 'audioInterrupt', callback?: Callback<audio.InterruptEvent>): void

Unsubscribes from the audio interruption event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'audioInterrupt'** in this case.|
| callback | Callback\<[audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)> | No  | Callback invoked when the event is triggered.<br>This parameter is supported since API version 12.            |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('audioInterrupt');
```

## on('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

on(type: 'audioOutputDeviceChangeWithInfo', callback: Callback\<audio.AudioStreamDeviceChangeInfo>): void

Subscribes to audio stream output device changes and reasons. This API uses an asynchronous callback to return the result.

When subscribing to this event, you are advised to implement the player behavior when the device is connected or disconnected by referring to [Responding to Audio Output Device Changes](../../media/audio/audio-output-device-change.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type, which is **'audioOutputDeviceChangeWithInfo'** in this case.|
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | Yes  | Callback used to return the output device descriptor of the current audio stream and the change reason.|

**Error codes**

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.       |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let avPlayer = await media.createAVPlayer();
avPlayer.on('audioOutputDeviceChangeWithInfo', (data: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`${JSON.stringify(data)}`);
});
```

## off('audioOutputDeviceChangeWithInfo')<sup>11+</sup>

off(type: 'audioOutputDeviceChangeWithInfo', callback?: Callback\<audio.AudioStreamDeviceChangeInfo>): void

Unsubscribes from audio stream output device changes and reasons. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type, which is **'audioOutputDeviceChangeWithInfo'** in this case.|
| callback | Callback\<[audio.AudioStreamDeviceChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | No  | Callback used to return the output device descriptor of the current audio stream and the change reason.|

**Error codes**

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('audioOutputDeviceChangeWithInfo');
```

## addSubtitleFromFd<sup>12+</sup>

addSubtitleFromFd(fd: number, offset?: number, length?: number): Promise\<void>

Adds an external subtitle to a video based on the FD. Currently, the external subtitle must be set after **fdSrc** of the video resource is set in an AVPlayer instance. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type                  | Mandatory| Description                                                        |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| fd | number   | Yes  | Resource handle, which is obtained by calling [resourceManager.getRawFd](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9).|
| offset | number | No  | Resource offset, which needs to be entered based on the preset asset information. An invalid value causes a failure to parse subtitle assets. The default value is **0**.|
| length | number | No  | Resource length, which needs to be entered based on the preset asset information. The default value is the remaining bytes from the offset in the file. An invalid value causes a failure to parse subtitle assets. The default value is **0**.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

<!--code_no_check-->
```ts
import { common } from '@kit.AbilityKit'

let avPlayer = await media.createAVPlayer();
private context: Context | undefined;
constructor(context: Context) {
  this.context = context; // this.getUIContext().getHostContext();
}
let fileDescriptor = await this.context?.resourceManager.getRawFd('xxx.srt');

avPlayer.addSubtitleFromFd(fileDescriptor.fd, fileDescriptor.offset, fileDescriptor.length);
```

## addSubtitleFromUrl<sup>12+</sup>

addSubtitleFromUrl(url: string): Promise\<void>

Adds an external subtitle to a video based on the URL. Currently, the external subtitle must be set after **fdSrc** of the video resource is set in an AVPlayer instance. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| url    | string | Yes  | Address of the external subtitle file.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | The parameter check failed. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

<!--code_no_check-->
```ts
let fdUrl:string = 'http://xxx.xxx.xxx/xx/index.srt';
let avPlayer: media.AVPlayer = await media.createAVPlayer();
avPlayer.addSubtitleFromUrl(fdUrl);
```

## on('subtitleUpdate')<sup>12+</sup>

on(type: 'subtitleUpdate', callback: Callback\<SubtitleInfo>): void

Subscribes to subtitle update events. When external subtitles exist, the system notifies the application through the subscribed-to callback. An application can subscribe to only one subtitle update event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | Yes  | Event type, which is **'subtitleUpdate'** in this case. The event is triggered when the external subtitle is updated.|
| callback | function | Yes  | Callback invoked when the subtitle is updated.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
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

Unsubscribes from subtitle update events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | Yes  | Event type, which is **'subtitleUpdate'** in this case. The event is triggered when the external subtitle is updated.|
| callback | function | No  | Callback that has been registered to listen for subtitle update events.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('subtitleUpdate');
```

## on('trackChange')<sup>12+</sup>

on(type: 'trackChange', callback: OnTrackChangeHandler): void

Subscribes to track change events. When the track changes, the system notifies the application through the subscribed-to callback. An application can subscribe to only one track change event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | Yes  | Event type, which is **'trackChange'** in this case. The event is triggered when the track changes.|
| callback | [OnTrackChangeHandler](arkts-apis-media-t.md#ontrackchangehandler12) | Yes  | Callback invoked when the event is triggered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('trackChange', (index: number, isSelect: boolean) => {
  console.info('trackChange info: index=' + index + ' isSelect=' + isSelect);
});
```

## off('trackChange')<sup>12+</sup>

off(type: 'trackChange', callback?: OnTrackChangeHandler): void

Unsubscribes from track change events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | Yes  | Event type, which is **'trackChange'** in this case. The event is triggered when the track changes.|
| callback | [OnTrackChangeHandler](arkts-apis-media-t.md#ontrackchangehandler12) | No  | Callback that has been registered to listen for track changes.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('trackChange');
```

## on('trackInfoUpdate')<sup>12+</sup>

on(type: 'trackInfoUpdate', callback: Callback\<Array\<MediaDescription>>): void

Subscribes to track information update events. When the track information is updated, the system notifies the application through the subscribed-to callback. An application can subscribe to only one track change event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | Yes  | Event type, which is **'trackInfoUpdate'** in this case. The event is triggered when the track information is updated.|
| callback | Callback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Yes  | Callback invoked when the event is triggered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
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

Unsubscribes from track information update events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type | string | Yes  | Event type, which is **'trackInfoUpdate'** in this case. The event is triggered when the track information is updated.|
| callback | Callback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | No  | Callback that has been registered to listen for track information updates.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('trackInfoUpdate');
```

## on('amplitudeUpdate')<sup>13+</sup>

on(type: 'amplitudeUpdate', callback: Callback\<Array\<number>>): void

Subscribes to update events of the maximum audio level value, which is periodically reported when audio resources are played.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'amplitudeUpdate'** in this case. The event is triggered when the amplitude changes.|
| callback | Callback\<Array\<number>> | Yes  | Callback invoked when the event is triggered.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('amplitudeUpdate', (value: Array<number>) => {
  console.info(`amplitudeUpdate called,and amplitudeUpdate = ${value}`);
});
```

## off('amplitudeUpdate')<sup>13+</sup>

off(type: 'amplitudeUpdate', callback?: Callback\<Array\<number>>): void

Unsubscribes from update events of the maximum amplitude.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'amplitudeUpdate'** in this case. The event is triggered when the amplitude changes.|
| callback | Callback\<Array\<number>> | No  | Callback that has been registered to listen for amplitude updates.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('amplitudeUpdate');
```

## on('seiMessageReceived')<sup>18+</sup>

on(type: 'seiMessageReceived', payloadTypes: Array\<number>, callback: OnSeiMessageHandle): void

Subscribes to events indicating that a Supplemental Enhancement Information (SEI) message is received. This applies only to HTTP-FLV live streaming and is triggered when SEI messages are present in the video stream. You must initiate the subscription before calling **prepare**. If you initiate multiple subscriptions to this event, the last subscription is applied.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | Yes| Event type, which is **'seiMessageReceived'** in this case. The event is triggered when an SEI message is received.|
| payloadTypes | Array\<number> | Yes| Array of subscribed-to payload types of SEI messages. Currently, only payloadType = 5 is supported.|
| callback | [OnSeiMessageHandle](arkts-apis-media-t.md#onseimessagehandle18) | Yes| Callback used to listen for SEI message events and receive the subscribed-to payload types.|

**Example**

```ts
import util from '@ohos.util';

let avPlayer = await media.createAVPlayer();

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

Unsubscribes from the events indicating that an SEI message is received.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'seiMessageReceived'** in this case. The event is triggered when an SEI message is received.|
| payloadTypes | Array\<number> | No  | Array of subscribed-to payload types of SEI messages.|
| callback | [OnSeiMessageHandle](arkts-apis-media-t.md#onseimessagehandle18) | No  | Callback used to listen for SEI message events and receive the subscribed-to payload types.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('seiMessageReceived');
```

## setSuperResolution<sup>18+</sup>

setSuperResolution(enabled: boolean) : Promise\<void>

Enables or disables super resolution. This API can be called when the AVPlayer is in the initialized, prepared, playing, paused, completed, or stopped state. This API uses a promise to return the result.

Before calling [prepare()](#prepare9), enable super resolution by using [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| enabled    | boolean | Yes  | Whether to enable or disable super resolution. **true** to enable, **false** otherwise.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by promise. |
| 5410003  | Super-resolution not supported. Return by promise. |
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12). Return by promise. |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized, prepared, playing, paused, completed, or stopped state before proceeding.
avPlayer.setSuperResolution(true);
```

## setVideoWindowSize<sup>18+</sup>

setVideoWindowSize(width: number, height: number) : Promise\<void>

Sets the resolution of the output video after super resolution. This API can be called when the AVPlayer is in the initialized, prepared, playing, paused, completed, or stopped state. This API uses a promise to return the result. The input parameter values s must be in the range of 320 x 320 to 1920 x 1080 (in px).

Before calling [prepare()](#prepare9), enable super resolution by using [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| width    | number | Yes  | Target width of the output video after super resolution. The value range is [320-1920], in px.|
| height    | number | Yes  | Target height of the output video after super resolution. The value range is [320-1080], in px.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Return by promise. |
| 5400102  | Operation not allowed. Return by promise. |
| 5410003  | Super-resolution not supported. Return by promise. |
| 5410004  | Missing enable super-resolution feature in [PlaybackStrategy](arkts-apis-media-i.md#playbackstrategy12). Return by promise. |

**Example**

```ts
let avPlayer = await media.createAVPlayer();
// Here is only an example. In real development, you must wait for the stateChange event to successfully trigger and reach the initialized, prepared, playing, paused, completed, or stopped state before proceeding.
avPlayer.setVideoWindowSize(1920, 1080);
```

## on('superResolutionChanged')<sup>18+</sup>

on(type:'superResolutionChanged', callback: OnSuperResolutionChanged): void

Subscribes to the event indicating that super resolution is enabled or disabled.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | Yes| Event type, which is **'superResolutionChanged'** in this case. The event is triggered when super resolution is enabled or disabled.|
| callback | [OnSuperResolutionChanged](arkts-apis-media-t.md#onsuperresolutionchanged-18) | Yes| Callback used to listen for super resolution status changes.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.on('superResolutionChanged', (enabled: boolean) => {
  console.info('superResolutionChanged called, and enabled is:' + enabled);
});
```

## off('superResolutionChanged')<sup>18+</sup>

off(type:'superResolutionChanged', callback?: OnSuperResolutionChanged): void

Unsubscribes from the event indicating that super resolution is enabled or disabled.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string | Yes| Event type, which is **'superResolutionChanged'** in this case. The event is triggered when super resolution is enabled or disabled.|
| callback | [OnSuperResolutionChanged](arkts-apis-media-t.md#onsuperresolutionchanged-18) | No| Callback used to listen for super resolution status changes.|

**Example**

```ts
let avPlayer = await media.createAVPlayer();
avPlayer.off('superResolutionChanged');
```
