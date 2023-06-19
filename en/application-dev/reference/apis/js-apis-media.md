# @ohos.multimedia.media (Media)

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The multimedia subsystem provides a set of simple and easy-to-use APIs for you to access the system and use media resources.

This subsystem offers the following audio and video services:

- Audio and video playback, implemented by the [AVPlayer](#avplayer9)<sup>9+</sup> class. This class has integrated [AudioPlayer](#audioplayerdeprecated)<sup>6+</sup> and [VideoPlayer](#videoplayer)<sup>8+</sup>, with the state machine and error codes upgraded. It is recommended.
- Audio and video recording, implemented by the [AVRecorder](#avrecorder9)<sup>9+</sup> class. This class has integrated [AudioRecorder](#audiorecorderdeprecated)<sup>6+</sup> and [VideoRecorder](#videorecorder9)<sup>9+</sup>. It is recommended.
- Audio playback, implemented by the [AudioPlayer](#audioplayerdeprecated)<sup>6+</sup> class. It is deprecated. You are advised to use [AVPlayer](#avplayer9)<sup>9+</sup>.
- Video playback, implemented by the [VideoPlayer](#videoplayerdeprecated)<sup>8+</sup> class. It is deprecated. You are advised to use [AVPlayer](#avplayer9)<sup>9+</sup>.
- Audio recording, implemented by the [AudioRecorder](#audiorecorderdeprecated)<sup>6+</sup> class. It is deprecated. You are advised to use [AVRecorder](#avrecorder9)<sup>9+</sup>.
- Video recording, implemented by the [VideoRecorder](#videorecorder9)<sup>9+</sup> class. It is deprecated. You are advised to use [AVRecorder](#avrecorder9)<sup>9+</sup>.

## Modules to Import

```js
import media from '@ohos.multimedia.media';
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(callback: AsyncCallback\<AVPlayer>): void

Creates an **AVPlayer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVPlayer](#avplayer9)> | Yes  | Callback used to return the result. If the operation is successful, an **AVPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to play audio and video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

```js
let avPlayer;

media.createAVPlayer((error, video) => {
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

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVPlayer](#avplayer9)> | Promise used to return the result. If the operation is successful, an **AVPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to play audio and video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```js
let avPlayer;

media.createAVPlayer().then((video) => {
  if (video != null) {
    avPlayer = video;
    console.info('createAVPlayer success');
  } else {
    console.error('createAVPlayer fail');
  }
}).catch((error) => {
  console.error(`AVPlayer catchCallback, error message:${error.message}`);
});
```

## media.createAVRecorder<sup>9+</sup>

createAVRecorder(callback: AsyncCallback\<AVRecorder>): void

Creates an **AVRecorder** instance. This API uses an asynchronous callback to return the result.
Only one **AVRecorder** instance can be created per device.

To use the camera to record videos, the camera module is required. For details about how to use the APIs provided by the camera module, see [Camera Management](js-apis-camera.md).

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVRecorder](#avrecorder9)> | Yes  | Callback used to return the result. If the operation is successful, an **AVRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record audio and video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

```js
let avRecorder;

media.createAVRecorder((error, recorder) => {
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
Only one **AVRecorder** instance can be created per device.

To use the camera to record videos, the camera module is required. For details about how to use the APIs provided by the camera module, see [Camera Management](js-apis-camera.md).

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type                                | Description                                                        |
| ------------------------------------ | ------------------------------------------------------------ |
| Promise\<[AVRecorder](#avrecorder9)> | Promise used to return the result. If the operation is successful, an **AVRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record audio and video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```js
let avRecorder;

media.createAVRecorder().then((recorder) => {
  if (recorder != null) {
    avRecorder = recorder;
    console.info('createAVRecorder success');
  } else {
    console.error('createAVRecorder fail');
  }
}).catch((error) => {
  console.error(`createAVRecorder catchCallback, error message:${error.message}`);
});
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void

Creates a **VideoRecorder** instance. This API uses an asynchronous callback to return the result.
Only one **VideoRecorder** instance can be created per device.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[VideoRecorder](#videorecorder9)> | Yes  | Callback used to return the result. If the operation is successful, a **VideoRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

```js
let videoRecorder;

media.createVideoRecorder((error, video) => {
  if (video != null) {
    videoRecorder = video;
    console.info('video createVideoRecorder success');
  } else {
    console.error(`video createVideoRecorder fail, error message:${error.message}`);
  }
});
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(): Promise\<VideoRecorder>

Creates a **VideoRecorder** instance. This API uses a promise to return the result.
Only one **VideoRecorder** instance can be created per device.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[VideoRecorder](#videorecorder9)> | Promise used to return the result. If the operation is successful, a **VideoRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```js
let videoRecorder;

media.createVideoRecorder().then((video) => {
  if (video != null) {
    videoRecorder = video;
    console.info('video createVideoRecorder success');
  } else {
    console.error('video createVideoRecorder fail');
  }
}).catch((error) => {
  console.error(`video catchCallback, error message:${error.message}`);
});
```

## AVErrorCode<sup>9+</sup><a name=averrorcode></a>

Enumerates the [media error codes](../errorcodes/errorcode-media.md).

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                      | Value     | Description                                |
| :------------------------- | ------- | ------------------------------------ |
| AVERR_OK                   | 0       | The operation is successful.                      |
| AVERR_NO_PERMISSION        | 201     | You do not have the permission to perform the operation.              |
| AVERR_INVALID_PARAMETER    | 401     | Invalid input parameter.                  |
| AVERR_UNSUPPORT_CAPABILITY | 801     | Unsupported API.       |
| AVERR_NO_MEMORY            | 5400101 | The system memory is insufficient or the number of services reaches the upper limit.|
| AVERR_OPERATE_NOT_PERMIT   | 5400102 | The operation is not allowed in the current state or you do not have the permission to perform the operation.|
| AVERR_IO                   | 5400103 | The data stream is abnormal.                |
| AVERR_TIMEOUT              | 5400104 | The system or network response times out.            |
| AVERR_SERVICE_DIED         | 5400105 | The service process is dead.                  |
| AVERR_UNSUPPORT_FORMAT     | 5400106 | The format of the media asset is not supported.      |

## MediaType<sup>8+</sup>

Enumerates the media types.

**System capability**: SystemCapability.Multimedia.Media.Core

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
| VIDEO_MPEG4  | 'video/mp4v-es'       | Video in MPEG-4 format.    |
| VIDEO_VP8    | 'video/x-vnd.on2.vp8' | Video in VP8 format.      |
| AUDIO_AAC    | 'audio/mp4a-latm'     | Audio in MP4A-LATM format.|
| AUDIO_VORBIS | 'audio/vorbis'        | Audio in Vorbis format.   |
| AUDIO_FLAC   | 'audio/flac'          | Audio in FLAC format.     |

## MediaDescriptionKey<sup>8+</sup>

Enumerates the media description keys.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | 'track_index'   | Track index, which is a number.                      |
| MD_KEY_TRACK_TYPE        | 'track_type'    | Track type, which is a number. For details, see [MediaType](#mediatype8).|
| MD_KEY_CODEC_MIME        | 'codec_mime'    | Codec MIME type, which is a string.                |
| MD_KEY_DURATION          | 'duration'      | Media duration, which is a number, in units of ms.    |
| MD_KEY_BITRATE           | 'bitrate'       | Bit rate, which is a number, in units of bit/s.   |
| MD_KEY_WIDTH             | 'width'         | Video width, which is a number, in units of pixel.    |
| MD_KEY_HEIGHT            | 'height'        | Video height, which is a number, in units of pixel.    |
| MD_KEY_FRAME_RATE        | 'frame_rate'    | Video frame rate, which is a number, in units of 100 fps.|
| MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | Number of audio channels, which is a number.                        |
| MD_KEY_AUD_SAMPLE_RATE   | 'sample_rate'   | Sampling rate, which is a number, in units of Hz.      |

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

| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| USER       | 1    | State transition triggered by user behavior. It happens when a user or the client calls an API.|
| BACKGROUND | 2    | State transition caused by system behavior. For example, if an application does not have the permission of Media Controller, the application is forcibly suspended or stopped by the system when it switches to the background.|

## AVPlayer<sup>9+</sup>

A playback management class that provides APIs to manage and play media assets. Before calling any API in **AVPlayer**, you must use [createAVPlayer()](#mediacreateavplayer9) to create an **AVPlayer** instance.

For details about the audio and video playback demo, see [Audio Playback](../../media/using-avplayer-for-playback.md) and [Video Playback](../../media/video-playback.md).

### Attributes<a name=avplayer_attributes></a>

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

| Name                                               | Type                                                  | Readable| Writable| Description                                                        |
| --------------------------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>9+</sup>                                    | string                                                 | Yes  | Yes  | URL of the media asset. It is a static attribute and can be set only when the AVPlayer is in the idle state. <br>The video formats MP4, MPEG-TS, WebM, and MKV are supported.<br>The audio formats M4A, AAC, MP3, OGG, and WAV are supported.<br>**Examples of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http://xx<br>3. HTTPS: https://xx<br>4. HLS: http://xx or https://xx|
| fdSrc<sup>9+</sup>                                  | [AVFileDescriptor](#avfiledescriptor9)                 | Yes  | Yes  | FD of the media asset. It is a static attribute and can be set only when the AVPlayer is in the idle state.<br>This attribute is required when media assets of an application are continuously stored in a file.<br>**Example:**<br>Assume that a media file that stores continuous assets consists of the following:<br>Video 1 (address offset: 0, byte length: 100)<br>Video 2 (address offset: 101; byte length: 50)<br>Video 3 (address offset: 151, byte length: 150)<br>1. To play video 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play video 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play video 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent media file, use **src=fd://xx**.|
| surfaceId<sup>9+</sup>                              | string                                                 | Yes  | Yes  | Video window ID. By default, there is no video window. It is a static attribute and can be set only when the AVPlayer is in the initialized state.<br>It is used to render the window for video playback and therefore is not required in audio-only playback scenarios.<br>**Example:**<br>[Create a surface ID through XComponent](../arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid).|
| loop<sup>9+</sup>                                   | boolean                                                | Yes  | Yes  | Whether to loop playback. The value **true** means to loop playback, and **false** (default) means the opposite. It is a dynamic attribute<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.|
| videoScaleType<sup>9+</sup>                         | [VideoScaleType](#videoscaletype9)                     | Yes  | Yes  | Video scaling type. The default value is **VIDEO_SCALE_TYPE_FIT_CROP**. It is a dynamic attribute<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.|
| audioInterruptMode<sup>9+</sup>                     | [audio.InterruptMode](js-apis-audio.md#interruptmode9) | Yes  | Yes  | Audio interruption mode. The default value is **SHARE_MODE**. It is a dynamic attribute<br>and can be set only when the AVPlayer is in the prepared, playing, paused, or completed state.|
| state<sup>9+</sup>                                  | [AVPlayerState](#avplayerstate9)                       | Yes  | No  | AVPlayer state. It can be used as a query parameter when the AVPlayer is in any state.                  |
| currentTime<sup>9+</sup>                            | number                                                 | Yes  | No  | Current video playback position, in ms. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **-1** indicates an invalid value.|
| duration<sup>9+</sup><a name=avplayer_duration></a> | number                                                 | Yes  | No  | Video duration, in ms. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **-1** indicates an invalid value.<br>In live streaming scenarios, **-1** is returned by default.|
| width<sup>9+</sup>                                  | number                                                 | Yes  | No  | Video width, in pixels. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **0** indicates an invalid value.|
| height<sup>9+</sup>                                 | number                                                 | Yes  | No  | Video height, in pixels. It can be used as a query parameter when the AVPlayer is in the prepared, playing, paused, or completed state.<br>The value **0** indicates an invalid value.|

**NOTE**

After the resource handle (FD) is transferred to the AVPlayer, do not use the resource handle to perform read and write operations, including but not limited to transferring it to multiple AVPlayers. Competition occurs when multiple AVPlayers use the same resource handle to read and write files at the same time, resulting in playback errors.

### on('stateChange')<sup>9+</sup><a name = stateChange_on></a>

on(type: 'stateChange', callback: (state: AVPlayerState, reason: StateChangeReason) => void): void

Subscribes to AVPlayer state changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case. This event can be triggered by both user operations and the system.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the following information:<br>state: [AVPlayerState](#avplayerstate9), indicating the AVPlayer state.<br>reason: [StateChangeReason](#statechangereason9), indicating the reason for the state transition.|

**Example**

```js
avPlayer.on('stateChange', async (state, reason) => {
  switch (state) {
    case 'idle':
      console.info('state idle called')
      break;
    case 'initialized':
      console.info('initialized prepared called')
      break;
    case 'prepared':
      console.info('state prepared called')
      break;
    case 'playing':
      console.info('state playing called')
      break;
    case 'paused':
      console.info('state paused called')
      break;
    case 'completed':
      console.info('state completed called')
      break;
    case 'stopped':
      console.info('state stopped called')
      break;
    case 'released':
      console.info('state released called')
      break;
    case 'error':
      console.info('state error called')
      break;
    default:
      console.info('unkown state :' + state)
      break;
  }
})
```

### off('stateChange')<sup>9+</sup><a name = stateChange_off></a>

off(type: 'stateChange'): void

Unsubscribes from AVPlayer state changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                 |
| ------ | ------ | ---- | ----------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'stateChange'** in this case.|

**Example**

```js
avPlayer.off('stateChange')
```

### on('error')<sup>9+</sup><a name = error_on></a>

on(type: 'error', callback: ErrorCallback): void

Subscribes to AVPlayer errors. This event is used only for error prompt and does not require the user to stop playback control. If the [AVPlayer state](#avplayerstate9) is also switched to error, call **reset()** or **release()** to exit the playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'error'** in this case. This event can be triggered by both user operations and the system.|
| callback | function | Yes  | Callback used to return the error code ID and error message.|

The AVPlayer provides the following error types<a name = error_info></a>:

| ID| Error Message             | Description                                                        |
| -------- | --------------------- | ------------------------------------------------------------ |
| 201      | No Permission:        | No permission to perform the operation. The [AVPlayer state](#avplayerstate9) is error.|
| 401      | Invalid Parameter:    | Incorrect input parameter, causing an invalid call.                                    |
| 801      | Unsupport Capability: | Unsupported API, causing an invalid call.                             |
| 5400101  | No Memory:            | Insufficient memory. The [AVPlayer state](#avplayerstate9) is error.|
| 5400102  | Operate Not Permit:   | Unsupported operation in the current state, causing an invalid call.                      |
| 5400103  | IO Error:             | A stream exception is detected during playback. The [AVPlayer state](#avplayerstate9) is error.|
| 5400104  | Network Timeout:      | The response times out due to a network error. The [AVPlayer state](#avplayerstate9) is error.|
| 5400105  | Service Died:         | The playback process is dead. The [AVPlayer state](#avplayerstate9) is error. In this case, you need to release the instance and then create an instance again.|
| 5400106  | Unsupport Format:     | Unsupported file format. The [AVPlayer state](#avplayerstate9) is error.|

**Example**

```js
avPlayer.on('error', (error) => {
  console.error('error happened,and error message is :' + error.message)
  console.error('error happened,and error code is :' + error.code)
})
```

### off('error')<sup>9+</sup><a name = error_off></a>

off(type: 'error'): void

Unsubscribes from AVPlayer errors.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | Yes  | Event type, which is **'error'** in this case.|

**Example**

```js
avPlayer.off('error')
```

### prepare<sup>9+</sup><a name=avplayer_prepare></a>

prepare(callback: AsyncCallback\<void>): void

Prepares for audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the initialized state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | function | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupport format. Return by callback.      |

**Example**

```js
avPlayer.prepare((err) => {
  if (err == null) {
    console.info('prepare success');
  } else {
    console.error('prepare filed,error message is :' + err.message)
  }
})
```

### prepare<sup>9+</sup>

prepare(): Promise\<void>

Prepares for audio and video playback. This API uses a promise to return the result. It can be called only when the AVPlayer is in the initialized state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400106  | Unsupport format. Return by promise.      |

**Example**

```js
avPlayer.prepare().then(() => {
  console.info('prepare success');
}, (err) => {
  console.error('prepare filed,error message is :' + err.message)
})
```

### play<sup>9+</sup><a name=avplayer_play></a>

play(callback: AsyncCallback\<void>): void

Starts to play an audio and video asset. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the prepared, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | function | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```js
avPlayer.play((err) => {
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

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```js
avPlayer.play().then(() => {
  console.info('play success');
}, (err) => {
  console.error('play filed,error message is :' + err.message)
})
```

### pause<sup>9+</sup><a name=avplayer_pause></a>

pause(callback: AsyncCallback\<void>): void

Pauses audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the playing state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | function | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```js
avPlayer.pause((err) => {
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

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```js
avPlayer.pause().then(() => {
  console.info('pause success');
}, (err) => {
  console.error('pause filed,error message is :' + err.message)
})
```

### stop<sup>9+</sup><a name=avplayer_stop></a>

stop(callback: AsyncCallback\<void>): void

Stops audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the prepared, playing, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | function | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```js
avPlayer.stop((err) => {
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

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```js
avPlayer.stop().then(() => {
  console.info('stop success');
}, (err) => {
  console.error('stop filed,error message is :' + err.message)
})
```

### reset<sup>9+</sup><a name=avplayer_reset></a>

reset(callback: AsyncCallback\<void>): void

Resets audio and video playback. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the initialized, prepared, playing, paused, completed, stopped, or error state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | function | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```js
avPlayer.reset((err) => {
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

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```js
avPlayer.reset().then(() => {
  console.info('reset success');
}, (err) => {
  console.error('reset filed,error message is :' + err.message)
})
```

### release<sup>9+</sup><a name=avplayer_release></a>

release(callback: AsyncCallback\<void>): void

Releases the playback resources. This API uses an asynchronous callback to return the result. It can be called when the AVPlayer is in any state except released.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| callback | function | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```js
avPlayer.release((err) => {
  if (err == null) {
    console.info('reset success');
  } else {
    console.error('release filed,error message is :' + err.message)
  }
})
```

### release<sup>9+</sup>

release(): Promise\<void>

Releases the playback resources. This API uses a promise to return the result. It can be called when the AVPlayer is in any state except released.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```js
avPlayer.release().then(() => {
  console.info('release success');
}, (err) => {
  console.error('release filed,error message is :' + err.message)
})
```

### getTrackDescription<sup>9+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the audio and video track information. This API uses an asynchronous callback to return the result. It can be called only when the AVPlayer is in the prepared, playing, or paused state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the audio and video track information.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**Example**

```js
function printfDescription(obj) {
  for (let item in obj) {
    let property = obj[item];
    console.info('audio key is ' + item);
    console.info('audio value is ' + property);
  }
}

avPlayer.getTrackDescription((error, arrList) => {
  if ((arrList) != null) {
    for (let i = 0; i < arrList.length; i++) {
      printfDescription(arrList[i]);
    }
  } else {
    console.log(`video getTrackDescription fail, error:${error}`);
  }
});
```

### getTrackDescription<sup>9+</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

Obtains the audio and video track information. This API uses a promise to return the result. It can be called only when the AVPlayer is in the prepared, playing, or paused state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Return value**

| Type                                                  | Description                                             |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return a **MediaDescription** array, which records the audio and video track information.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**Example**

```js
let arrayDescription;

function printfDescription(obj) {
  for (let item in obj) {
    let property = obj[item];
    console.info('audio key is ' + item);
    console.info('audio value is ' + property);
  }
}
avPlayer.getTrackDescription().then((arrList) => {
  if (arrList != null) {
    arrayDescription = arrList;
  } else {
    console.log('video getTrackDescription fail');
  }
}).catch((error) => {
  console.info(`video catchCallback, error:${error}`);
});
for (let i = 0; i < arrayDescription.length; i++) {
  printfDescription(arrayDescription[i]);
}
```

### seek<sup>9+</sup><a name=avplayer_seek></a>

seek(timeMs: number, mode?:SeekMode): void

Seeks to the specified playback position. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the seek operation takes effect by subscribing to the [seekDone](#seekDone_on) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type                  | Mandatory| Description                                                        |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | Yes  | Position to seek to, in ms. The value range is [0, [duration](#avplayer_duration)].|
| mode   | [SeekMode](#seekmode8) | No  | Seek mode based on the video I frame. The default value is **SEEK_PREV_SYNC**. **Set this parameter only for video playback.**|

**Example**

```js
let seekTime = 1000
avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC)
```

### on('seekDone')<sup>9+</sup><a name = seekDone_on></a>

on(type: 'seekDone', callback: Callback\<number>): void

Subscribes to the event to check whether the seek operation takes effect.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'seekDone'** in this case. This event is triggered each time **seek()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the time position requested by the user.<br>For video playback, [SeekMode](#seekmode8) may cause the actual position to be different from that requested by the user. The exact position can be obtained from the **currentTime** attribute. The time in this callback only means that the requested seek operation is complete.|

**Example**

```js
avPlayer.on('seekDone', (seekDoneTime:number) => {
  console.info('seekDone success,and seek time is:' + seekDoneTime)
})
```

### off('seekDone')<sup>9+</sup><a name = seekDone_off></a>

off(type: 'seekDone'): void

Unsubscribes from the event that checks whether the seek operation takes effect.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                |
| ------ | ------ | ---- | ---------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'seekDone'** in this case.|

**Example**

```js
avPlayer.off('seekDone')
```

### setSpeed<sup>9+</sup>

setSpeed(speed: PlaybackSpeed): void

Sets the playback speed. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [speedDone](#speedDone_on) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type                            | Mandatory| Description              |
| ------ | -------------------------------- | ---- | ------------------ |
| speed  | [PlaybackSpeed](#playbackspeed8) | Yes  | Playback speed to set.|

**Example**

```js
avPlayer.setSpeed(media.PlaybackSpeed.SPEED_FORWARD_2_00_X)
```

### on('speedDone')<sup>9+</sup><a name = speedDone_on></a>

on(type: 'speedDone', callback: Callback\<number>): void

Subscribes to the event to check whether the playback speed is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'speedDone'** in this case. This event is triggered each time **setSpeed()** is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. It reports the speed set. For details, see [PlaybackSpeed](#playbackspeed8).|

**Example**

```js
avPlayer.on('speedDone', (speed:number) => {
  console.info('speedDone success,and speed value is:' + speed)
})
```

### off('speedDone')<sup>9+</sup><a name = speedDone_off></a>

off(type: 'speedDone'): void

Unsubscribes from the event that checks whether the playback speed is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                     |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'speedDone'** in this case.|

**Example**

```js
avPlayer.off('speedDone')
```

### setBitrate<sup>9+</sup>

setBitrate(bitrate: number): void

Sets the bit rate, which is valid only for HTTP Live Streaming (HLS) streams. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [bitrateDone](#bitrateDone_on) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| bitrate | number | Yes  | Bit rate to set. You can obtain the available bit rates of the current HLS stream by subscribing to the [availableBitrates](#availableBitrates_on) event. If the bit rate to set is not in the list of the available bit rates, the AVPlayer selects from the list the minimum bit rate that is closed to the bit rate to set. If the length of the available bit rate list obtained through the event is 0, no bit rate can be set and the **bitrateDone** callback will not be triggered.|

**Example**

```js
let bitrate = 96000
avPlayer.setBitrate(bitrate)
```

### on('bitrateDone')<sup>9+</sup><a name = bitrateDone_on></a>

on(type: 'bitrateDone', callback: Callback\<number>): void

Subscribes to the event to check whether the bit rate is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bitrateDone'** in this case. This event is triggered each time **setBitrate()** is called.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the effective bit rate.            |

**Example**

```js
avPlayer.on('bitrateDone', (bitrate:number) => {
  console.info('bitrateDone success,and bitrate value is:' + bitrate)
})
```

### off('bitrateDone')<sup>9+</sup><a name = bitrateDone_off></a>

off(type: 'bitrateDone'): void

Unsubscribes from the event that checks whether the bit rate is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'bitrateDone'** in this case.|

**Example**

```js
avPlayer.off('bitrateDone')
```

### on('availableBitrates')<sup>9+</sup><a name = availableBitrates_on></a>

on(type: 'availableBitrates', callback: (bitrates: Array\<number>) => void): void

Subscribes to available bit rates of HLS streams. This event is reported only after the AVPlayer switches to the prepared state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'availableBitrates'** in this case. This event is triggered once after the AVPlayer switches to the prepared state.|
| callback | function | Yes  | Callback invoked when the event is triggered. It returns an array that holds the available bit rates. If the array length is 0, no bit rate can be set.|

**Example**

```js
avPlayer.on('availableBitrates', (bitrates: Array<number>) => {
  console.info('availableBitrates success,and availableBitrates length is:' + bitrates.length)
})
```

### off('availableBitrates')<sup>9+</sup><a name = availableBitrates_off></a>

off(type: 'availableBitrates'): void

Unsubscribes from available bit rates of HLS streams.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'availableBitrates'** in this case.|

**Example**

```js
avPlayer.off('availableBitrates')
```

### setVolume<sup>9+</sup>

setVolume(volume: number): void

Sets the volume. This API can be called only when the AVPlayer is in the prepared, playing, paused, or completed state. You can check whether the setting takes effect by subscribing to the [volumeChange](#volumeChange_on) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| volume | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|

**Example**

```js
let volume = 1.0
avPlayer.setVolume(volume)
```

### on('volumeChange')<sup>9+</sup><a name = volumeChange_on></a>

on(type: 'volumeChange', callback: Callback\<number>): void

Subscribes to the event to check whether the volume is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'volumeChange'** in this case. This event is triggered each time **setVolume()** is called.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the effective volume.           |

**Example**

```js
avPlayer.on('volumeChange', (vol:number) => {
  console.info('volumeChange success,and new volume is :' + vol)
})
```

### off('volumeChange')<sup>9+</sup><a name = volumeChange_off></a>

off(type: 'volumeChange'): void

Unsubscribes from the event that checks whether the volume is successfully set.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'volumeChange'** in this case.|

**Example**

```js
avPlayer.off('volumeChange')
```

### on('endOfStream')<sup>9+</sup><a name = endOfStream_on></a>

on(type: 'endOfStream', callback: Callback\<void>): void

Subscribes to the event that indicates the end of the stream being played. If **loop=1** is set, the AVPlayer seeks to the beginning of the stream and plays the stream again. If **loop** is not set, the completed state is reported through the [stateChange](#stateChange_on) event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'endOfStream'** in this case. This event is triggered when the AVPlayer finishes playing the media asset.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                              |

**Example**

```js
avPlayer.on('endOfStream', () => {
  console.info('endOfStream success')
})
```

### off('endOfStream')<sup>9+</sup><a name = endOfStream_off></a>

off(type: 'endOfStream'): void

Unsubscribes from the event that indicates the end of the stream being played.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'endOfStream'** in this case.|

**Example**

```js
avPlayer.off('endOfStream')
```

### on('timeUpdate')<sup>9+</sup><a name = timeUpdate_on></a>

on(type: 'timeUpdate', callback: Callback\<number>): void

Subscribes to playback position changes. It is used to refresh the current position of the progress bar. By default, this event is reported every 1 second. However, it is reported immediately upon a successful seek operation.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                          |
| -------- | -------- | ---- | ---------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'timeUpdate'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the current playback position, in ms.                                    |

**Example**

```js
avPlayer.on('timeUpdate', (time:number) => {
  console.info('timeUpdate success,and new time is :' + time)
})
```

### off('timeUpdate')<sup>9+</sup><a name = timeUpdate_off></a>

off(type: 'timeUpdate'): void

Unsubscribes from playback position changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                              |
| ------ | ------ | ---- | -------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'timeUpdate'** in this case.|

**Example**

```js
avPlayer.off('timeUpdate')
```

### on('durationUpdate')<sup>9+</sup><a name = durationUpdate_on></a>

on(type: 'durationUpdate', callback: Callback\<number>): void

Subscribes to media asset duration changes. It is used to refresh the length of the progress bar. By default, this event is reported once when the AVPlayer switches to the prepared state. However, it can be repeatedly reported for special streams that trigger duration changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                              |
| -------- | -------- | ---- | -------------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'durationUpdate'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the media asset duration, in ms.                                        |

**Example**

```js
avPlayer.on('durationUpdate', (duration) => {
  console.info('durationUpdate success,new duration is :' + duration)
})
```

### off('durationUpdate')<sup>9+</sup><a name = durationUpdate_off></a>

off(type: 'durationUpdate'): void

Unsubscribes from media asset duration changes.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                  |
| ------ | ------ | ---- | ------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'durationUpdate'** in this case.|

**Example**

```js
avPlayer.off('durationUpdate')
```

### on('bufferingUpdate')<sup>9+</sup><a name = bufferingUpdate_on></a>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to audio and video buffer changes. This subscription is supported only in network playback scenarios.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | function | Yes  | Callback invoked when the event is triggered.<br>When [BufferingInfoType](#bufferinginfotype8) is set to **BUFFERING_PERCENT** or **CACHED_DURATION**, **value** is valid. Otherwise, **value** is fixed at **0**.|

**Example**

```js
avPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('bufferingUpdate success,and infoType value is:' + infoType + ', value is :' + value)
})
```

### off('bufferingUpdate')<sup>9+</sup><a name = bufferingUpdate_off></a>

off(type: 'bufferingUpdate'): void

Unsubscribes from audio and video buffer changes. 

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                     |
| ------ | ------ | ---- | --------------------------------------------------------- |
| type   | string | Yes  | Event type, which is **'bufferingUpdate'** in this case.|

**Example**

```js
avPlayer.off('bufferingUpdate')
```

### on('startRenderFrame')<sup>9+</sup><a name = startRenderFrame_on></a>

on(type: 'startRenderFrame', callback: Callback\<void>): void

Subscribes to the event that indicates rendering starts for the first frame. This subscription is supported only in the video playback scenarios. This event only means that the playback service sends the first frame to the display module. The actual rendering effect depends on the rendering performance of the display service.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'startRenderFrame'** in this case.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                          |

**Example**

```js
avPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame success')
})
```

### off('startRenderFrame')<sup>9+</sup><a name = startRenderFrame_off></a>

off(type: 'startRenderFrame'): void

Unsubscribes from the event that indicates rendering starts for the first frame.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'startRenderFrame'** in this case.|

**Example**

```js
avPlayer.off('startRenderFrame')
```

### on('videoSizeChange')<sup>9+</sup><a name = videoSizeChange_on></a>

on(type: 'videoSizeChange', callback: (width: number, height: number) => void): void

Subscribes to video size (width and height) changes. This subscription is supported only in the video playback scenarios. By default, this event is reported only once in the prepared state. However, it is also reported upon resolution changes in the case of HLS streams.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'videoSizeChange'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered. **width** indicates the video width, and **height** indicates the video height.   |

**Example**

```js
avPlayer.on('videoSizeChange', (width: number, height: number) => {
  console.info('videoSizeChange success,and width is:' + width + ', height is :' + height)
})
```

### off('videoSizeChange')<sup>9+</sup><a name = videoSizeChange_off></a>

off(type: 'videoSizeChange'): void

Unsubscribes from video size changes. 

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'videoSizeChange'** in this case.|

**Example**

```js
avPlayer.off('videoSizeChange')
```

### on('audioInterrupt')<sup>9+</sup><a name = audioInterrupt_on></a>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

Subscribes to the audio interruption event. When multiple audio and video assets are played at the same time, this event is triggered based on the audio interruption mode [audio.InterruptMode](js-apis-audio.md#interruptmode9).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                    |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | Yes  | Event type, which is **'audioInterrupt'** in this case.|
| callback | [audio.InterruptEvent<sup>9+</sup>](js-apis-audio.md#interruptevent9) | Yes  | Callback invoked when the event is triggered.                              |

**Example**

```js
import audio from '@ohos.multimedia.audio';

avPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt success,and InterruptEvent info is:' + info)
})
```

### off('audioInterrupt')<sup>9+</sup><a name = audioInterrupt_off></a>

off(type: 'audioInterrupt'): void

Unsubscribes from the audio interruption event.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'audioInterrupt'** in this case.|

**Example**

```js
avPlayer.off('audioInterrupt')
```

## AVPlayerState<sup>9+</sup><a name = avplayerstate></a>

Enumerates the states of the [AVPlayer](#avplayer9). Your application can proactively obtain the AVPlayer state through the **state** attribute or obtain the reported AVPlayer state by subscribing to the [stateChange](#stateChange_on) event. For details about the rules for state transition, see [Audio Playback](../../media/using-avplayer-for-playback.md).

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

|              Name              |  Type | Description                                                        |
| :-----------------------------: | :----: | :----------------------------------------------------------- |
|              idle               | string | The AVPlayer enters this state after [createAVPlayer()](#mediacreateavplayer9) or **reset()** is called.<br>In case **createAVPlayer()** is used, all attributes are set to their default values.<br>In case **reset()** is called, the **url<sup>9+</sup>** or **fdSrc<sup>9+</sup>** attribute is reset, and other attributes are retained.|
|           initialized           | string | The AVPlayer enters this state after **url<sup>9+</sup>** or **fdSrc<sup>9+</sup>** attribute is set in the idle state. In this case, you can configure static attributes such as the window and audio.|
|            prepared             | string | The AVPlayer enters this state when **prepare()** is called in the initialized state. In this case, the playback engine has prepared the resources.|
|             playing             | string | The AVPlayer enters this state when **play()** is called in the prepared, paused, or completed state.|
|             paused              | string | The AVPlayer enters this state when **pause()** is called in the playing state.|
|            completed            | string | The AVPlayer enters this state when a media asset finishes playing and loop playback is not set (no **loop = 1**). In this case, if **play()** is called, the AVPlayer enters the playing state and replays the media asset; if **stop()** is called, the AVPlayer enters the stopped state.|
|             stopped             | string | The AVPlayer enters this state when **stop()** is called in the prepared, playing, paused, or completed state. In this case, the playback engine retains the attributes but releases the memory resources. You can call **prepare()** to prepare the resources again, call **reset()** to reset the attributes, or call **release()** to destroy the playback engine.|
|            released             | string | The AVPlayer enters this state when **release()** is called. The playback engine associated with the **AVPlayer** instance is destroyed, and the playback process ends. This is the final state.|
| error<a name = error_state></a> | string | The AVPlayer enters this state when an irreversible error occurs in the playback engine. You can call **reset()** to reset the attributes or call **release()** to destroy the playback engine. For details on the errors, see [Error Classification](#error_info).<br>**NOTE** Relationship between the error state and the [on('error')](#error_on) event<br>1. When the AVPlayer enters the error state, the [on('error')](#error_on) event is triggered. You can obtain the detailed error information through this event.<br>2. When the AVPlayer enters the error state, the playback service stops. This requires the client to design a fault tolerance mechanism to call **reset()** or **release()**.<br>3. The client receives [on('error')](#error_on) event but the AVPlayer does not enter the error state. This situation occurs due to either of the following reasons:<br>Cause 1: The client calls an API in an incorrect state or passes in an incorrect parameter, and the AVPlayer intercepts the call. If this is the case, the client must correct its code logic.<br>Cause 2: A stream error is detected during playback. As a result, the container and decoding are abnormal for a short period of time, but continuous playback and playback control operations are not affected. If this is the case, the client does not need to design a fault tolerance mechanism.|

## AVFileDescriptor<sup>9+</sup>

Describes an audio and video file asset. It is used to specify a particular asset for playback based on its offset and length within a file.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name  | Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | Yes  | Resource handle, which is obtained by calling **resourceManager.getRawFileDescriptor**.    |
| offset | number | Yes  | Resource offset, which needs to be entered based on the preset asset information. An invalid value causes a failure to parse audio and video assets.|
| length | number | Yes  | Resource length, which needs to be entered based on the preset asset information. An invalid value causes a failure to parse audio and video assets.|

## SeekMode<sup>8+</sup>

Enumerates the video playback seek modes, which can be passed in the **seek** API.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name          | Value  | Description                                                        |
| -------------- | ---- | ------------------------------------------------------------ |
| SEEK_NEXT_SYNC | 0    | Seeks to the next key frame at the specified position. You are advised to use this value for the rewind operation.|
| SEEK_PREV_SYNC | 1    | Seeks to the previous key frame at the specified position. You are advised to use this value for the fast-forward operation.|

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

## VideoScaleType<sup>9+</sup>

Enumerates the video scale modes.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                     | Value  | Description                                            |
| ------------------------- | ---- | ------------------------------------------------ |
| VIDEO_SCALE_TYPE_FIT      | 0    | The video will be stretched to fit the window.                          |
| VIDEO_SCALE_TYPE_FIT_CROP | 1    | The video will be stretched to fit the window, without changing its aspect ratio. The content may be cropped.|

## MediaDescription<sup>8+</sup>

Defines media information in key-value mode.

**System capability**: SystemCapability.Multimedia.Media.Core

**Example**

```js
import media from '@ohos.multimedia.media'
function printfItemDescription(obj, key) {
  let property = obj[key];
  console.info('audio key is ' + key); // Specify a key. For details about the keys, see [MediaDescriptionKey].
  console.info('audio value is ' + property); // Obtain the value of the key. The value can be any type. For details about the types, see [MediaDescriptionKey].
}
let audioPlayer = media.createAudioPlayer();
audioPlayer.getTrackDescription((error, arrList) => {
  if (arrList != null) {
    for (let i = 0; i < arrList.length; i++) {
      printfItemDescription(arrList[i], media.MediaDescriptionKey.MD_KEY_TRACK_TYPE);  // Print the MD_KEY_TRACK_TYPE value of each track.
    }
  } else {
    console.log(`audio getTrackDescription fail, error:${error}`);
  }
});
```

## AVRecorder<sup>9+</sup>

A recording management class that provides APIs to record media assets. Before calling any API in **AVRecorder**, you must use **createAVRecorder()** to create an **AVRecorder** instance.

For details about the audio and video recording demo, see [Audio Recording](../../media/using-avrecorder-for-recording.md) and [Video Recording](../../media/video-recording.md).

> **NOTE**
>
> To use the camera to record videos, the camera module is required. For details about how to use the APIs provided by the camera module, see [Camera Management](js-apis-camera.md).

### Attributes

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name   | Type                                | Readable| Writable| Description              |
| ------- | ------------------------------------ | ---- | ---- | ------------------ |
| state9+ | [AVRecorderState](#avrecorderstate9) | Yes  | No  | AVRecorder state.|

### prepare<sup>9+</sup><a name=avrecorder_prepare></a>

prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void

Sets audio and video recording parameters. This API uses an asynchronous callback to return the result.

**Required permissions:** ohos.permission.MICROPHONE

This permission is required only if audio recording is involved.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                                  | Mandatory| Description                                 |
| -------- | -------------------------------------- | ---- | ------------------------------------- |
| config   | [AVRecorderConfig](#avrecorderconfig9) | Yes  | Audio and video recording parameters to set.           |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission denied. Return by callback.  |
| 401      | Parameter error. Return by callback.    |
| 5400102  | Operate not permit. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
// Configure the parameters based on those supported by the hardware device.
let AVRecorderProfile = {
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
let AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : AVRecorderProfile,
  url : 'fd://', // Before passing in an FD to this parameter, the file must be created by the caller and granted with the read and write permissions. Example value: eg.fd://45.
  rotation: 0, // The value can be 0, 90, 180, or 270. If any other value is used, prepare() reports an error.
  location : { latitude : 30, longitude : 130 }
}

avRecorder.prepare(AVRecorderConfig, (err) => {
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

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name| Type                                  | Mandatory| Description                      |
| ------ | -------------------------------------- | ---- | -------------------------- |
| config | [AVRecorderConfig](#avrecorderconfig9) | Yes  | Audio and video recording parameters to set.|

**Return value**

| Type          | Description                                      |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201      | Permission denied. Return by promise.  |
| 401      | Parameter error. Return by promise.    |
| 5400102  | Operate not permit. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
// Configure the parameters based on those supported by the hardware device.
let AVRecorderProfile = {
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
let AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : AVRecorderProfile,
  url : 'fd://',  // Before passing in an FD to this parameter, the file must be created by the caller and granted with the read and write permissions. Example value: eg.fd://45.
  rotation: 0, // The value can be 0, 90, 180, or 270. If any other value is used, prepare() reports an error.
  location : { latitude : 30, longitude : 130 }
}

avRecorder.prepare(AVRecorderConfig).then(() => {
  console.info('prepare success');
}).catch((err) => {
  console.error('prepare failed and catch error is ' + err.message);
});

```

### getInputSurface<sup>9+</sup><a name=avrecorder_getinputsurface></a>

getInputSurface(callback: AsyncCallback\<string>): void

Obtains the surface required for recording. This API uses an asynchronous callback to return the result. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding video data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp must be based on the system startup time.

This API can be called only after the **prepare()** API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to obtain the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
let surfaceID = null; // The surfaceID is transferred to the camera API to create a videoOutput instance.

avRecorder.getInputSurface((err, surfaceId) => {
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

This API can be called only after the **prepare()** API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<string> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
let surfaceID = null; // The surfaceID is transferred to the camera API to create a videoOutput instance.

avRecorder.getInputSurface().then((surfaceId) => {
  console.info('getInputSurface success');
  surfaceID = surfaceId;
}).catch((err) => {
  console.error('getInputSurface failed and catch error is ' + err.message);
});
```

### start<sup>9+</sup><a name=avrecorder_start></a>

start(callback: AsyncCallback\<void>): void

Starts recording. This API uses an asynchronous callback to return the result.

For audio-only recording, this API can be called only after the **prepare()** API is called. For video-only recording, this API can be called only after the **getInputSurface()** API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
avRecorder.start((err) => {
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

For audio-only recording, this API can be called only after the **prepare()** API is called. For video-only recording, this API can be called only after the **getInputSurface()** API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
avRecorder.start().then(() => {
  console.info('start AVRecorder success');
}).catch((err) => {
  console.error('start AVRecorder failed and catch error is ' + err.message);
});
```

### pause<sup>9+</sup><a name=avrecorder_pause></a>

pause(callback: AsyncCallback\<void>): void

Pauses recording. This API uses an asynchronous callback to return the result.

This API can be called only after the **start()** API is called. You can call **resume()** to resume recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                       |
| -------- | -------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to obtain the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
avRecorder.pause((err) => {
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

This API can be called only after the **start()** API is called. You can call **resume()** to resume recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
avRecorder.pause().then(() => {
  console.info('pause AVRecorder success');
}).catch((err) => {
  console.error('pause AVRecorder failed and catch error is ' + err.message);
});
```

### resume<sup>9+</sup><a name=avrecorder_resume></a>

resume(callback: AsyncCallback\<void>): void

Resumes recording. This API uses an asynchronous callback to return the result.

This API can be called only after the **pause()** API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
avRecorder.resume((err) => {
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

This API can be called only after the **pause()** API is called.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
avRecorder.resume().then(() => {
  console.info('resume AVRecorder success');
}).catch((err) => {
  console.error('resume AVRecorder failed and catch error is ' + err.message);
});
```

### stop<sup>9+</sup><a name=avrecorder_stop></a>

stop(callback: AsyncCallback\<void>): void

Stops recording. This API uses an asynchronous callback to return the result.

This API can be called only after the **start()** or **pause()** API is called.

For audio-only recording, you can call **prepare()** again for re-recording. For video-only recording or audio and video recording, you can call **prepare()** and **getInputSurface()** again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
avRecorder.stop((err) => {
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

This API can be called only after the **start()** or **pause()** API is called.

For audio-only recording, you can call **prepare()** again for re-recording. For video-only recording or audio and video recording, you can call **prepare()** and **getInputSurface()** again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
avRecorder.stop().then(() => {
  console.info('stop AVRecorder success');
}).catch((err) => {
  console.error('stop AVRecorder failed and catch error is ' + err.message);
});
```

### reset<sup>9+</sup><a name=avrecorder_reset></a>

reset(callback: AsyncCallback\<void>): void

Resets audio and video recording. This API uses an asynchronous callback to return the result.

For audio-only recording, you can call **prepare()** again for re-recording. For video-only recording or audio and video recording, you can call **prepare()** and **getInputSurface()** again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**Example**

```js
avRecorder.reset((err) => {
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

For audio-only recording, you can call **prepare()** again for re-recording. For video-only recording or audio and video recording, you can call **prepare()** and **getInputSurface()** again for re-recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Return value**

| Type          | Description                                   |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```js
avRecorder.reset().then(() => {
  console.info('reset AVRecorder success');
}).catch((err) => {
  console.error('reset AVRecorder failed and catch error is ' + err.message);
});
```

### release<sup>9+</sup><a name=avrecorder_release></a>

release(callback: AsyncCallback\<void>): void

Releases the audio and video recording resources. This API uses an asynchronous callback to return the result.

After the resources are released, you can no longer perform any operation on the **AVRecorder** instance.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```js
avRecorder.release((err) => {
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

**Return value**

| Type          | Description                                       |
| -------------- | ------------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```js
avRecorder.release().then(() => {
  console.info('release AVRecorder success');
}).catch((err) => {
  console.error('release AVRecorder failed and catch error is ' + err.message);
});
```

### on('stateChange')<sup>9+</sup><a name=avrecorder_onstatechange></a>

on(type: 'stateChange', callback: (state: AVRecorderState, reason: StateChangeReason) => void): void

Subscribes to AVRecorder state changes. An application can subscribe to only one AVRecorder state change event. When the application initiates multiple subscriptions to this event, the last subscription prevails.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'stateChange'** in this case. This event can be triggered by both user operations and the system.|
| callback | function | Yes  | Callback invoked when the event is triggered. It reports the following information:<br>**state**: [AVRecorderState](#avrecorderstate9), indicating the AVRecorder state.<br>**reason**: [StateChangeReason](#statechangereason9), indicating the reason for the state transition.|

**Example**

```js
avRecorder.on('stateChange', async (state, reason) => {
  console.info('case state has changed, new state is :' + state + ',and new reason is : ' + reason);
});
```

### off('stateChange')<sup>9+</sup>

off(type: 'stateChange'): void

Unsubscribes from AVRecorder state changes.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'stateChange'** in this case. This event can be triggered by both user operations and the system.|

**Example**

```js
avRecorder.off('stateChange');
```

### on('error')<sup>9+</sup><a name=avrecorder_onerror></a>

on(type: 'error', callback: ErrorCallback): void

Subscribes to AVRecorder errors. This event is used only for error prompt and does not require the user to stop recording control. If the [AVRecorderState](#avrecorderstate9) is also switched to error, call **reset()** or **release()** to exit the recording.

An application can subscribe to only one AVRecorder error event. When the application initiates multiple subscriptions to this event, the last subscription prevails.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during recording.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**Example**

```js
avRecorder.on('error', (err) => {
  console.error('case avRecorder.on(error) called, errMessage is ' + err.message);
});
```

### off('error')<sup>9+</sup>

off(type: 'error'): void

Unsubscribes from AVRecorder errors. After the unsubscription, your application can no longer receive AVRecorder errors.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during recording.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**Example**

```js
avRecorder.off('error');
```

## AVRecorderState<sup>9+</sup>

Enumerates the AVRecorder states. You can obtain the state through the **state** attribute.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name    | Type  | Description                                                        |
| -------- | ------ | ------------------------------------------------------------ |
| idle     | string | The AVRecorder enters this state when the AVRecorder is just created or the [reset()](#avrecorder_reset) API is called in any non-released state. In this state, you can call [prepare()](#avrecorder_prepare) to set recording parameters.  |
| prepared | string | The AVRecorder enters this state when the parameters are set. In this state, you can call [start()](#avrecorder_start) to start recording.|
| started  | string | The AVRecorder enters this state when the recording starts. In this state, you can call [pause()](#avrecorder_pause) to pause the recording or call [stop()](#avrecorder_stop) to stop recording.|
| paused   | string | The AVRecorder enters this state when the recording is paused. In this state, you can call [resume()](#avrecorder_resume) to continue the recording or call [stop()](#avrecorder_stop) to stop recording.|
| stopped  | string | The AVRecorder enters this state when the recording stops. In this state, you can call [prepare()](#avrecorder_prepare) to set recording parameters.|
| released | string | The AVRecorder enters this state when the recording resources are released. In this state, no operation can be performed. In any other state, you can call [release()](#avrecorder_release) to enter the released state.|
| error    | string | The AVRecorder enters this state when an irreversible error occurs in the **AVRecorder** instance. In this state, the [on('error') event](#avrecorder_onerror) is reported, with the detailed error cause. In the error state, you must call [reset()](#avrecorder_reset) to reset the **AVRecorder** instance or call [release()](#avrecorder_release) to release the resources.|

## AVRecorderConfig<sup>9+</sup>

Describes the audio and video recording parameters.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name           | Type                                    | Mandatory| Description                                                        |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](#audiosourcetype9)     | No  | Type of the audio source to record. This parameter is mandatory for audio recording.                  |
| videoSourceType | [VideoSourceType](#videosourcetype9)     | No  | Type of the video source to record. This parameter is mandatory for video recording.                  |
| profile         | [AVRecorderProfile](#avrecorderprofile9) | Yes  | Recording profile. This parameter is mandatory.                                   |
| url             | string                                   | Yes  | Recording output URL: fd://xx (fd number).<br>![img](figures/en-us_image_url.png)<br>This parameter is mandatory.|
| rotation        | number                                   | No  | Rotation angle of the recorded video. The value can only be 0 (default), 90, 180, or 270.      |
| location        | [Location](#location)                    | No  | Geographical location of the recorded video. By default, the geographical location information is not recorded.                    |

The **audioSourceType** and **videoSourceType** parameters are used to distinguish audio-only recording, video-only recording, and audio and video recording. For audio-only recording, set only **audioSourceType**. For video-only recording, set only **videoSourceType**. For audio and video recording, set both **audioSourceType** and **videoSourceType**.

## AVRecorderProfile<sup>9+</sup>

Describes the audio and video recording profile.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name            | Type                                        | Mandatory| Description                                                        |
| ---------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioBitrate     | number                                       | No  | Audio encoding bit rate. This parameter is mandatory for audio recording.                        |
| audioChannels    | number                                       | No  | Number of audio channels. This parameter is mandatory for audio recording.                        |
| audioCodec       | [CodecMimeType](#codecmimetype8)             | No  | Audio encoding format. This parameter is mandatory for audio recording. Only **AUDIO_AAC** is supported.     |
| audioSampleRate  | number                                       | No  | Audio sampling rate. This parameter is mandatory for audio recording.                            |
| fileFormat       | [ContainerFormatType](#containerformattype8) | Yes  | Container format of a file. This parameter is mandatory.                                  |
| videoBitrate     | number                                       | No  | Video encoding bit rate. This parameter is mandatory for video recording.                        |
| videoCodec       | [CodecMimeType](#codecmimetype8)             | No  | Video encoding format. This parameter is mandatory for video recording. You need to query the encoding capabilities (including the encoding format and resolution) supported by the device.|
| videoFrameWidth  | number                                       | No  | Width of a video frame. This parameter is mandatory for video recording.                            |
| videoFrameHeight | number                                       | No  | Height of a video frame. This parameter is mandatory for video recording.                            |
| videoFrameRate   | number                                       | No  | Video frame rate. This parameter is mandatory for video recording.                              |

## AudioSourceType<sup>9+</sup>

Enumerates the audio source types for video recording.

**System capability**: SystemCapability.Multimedia.Media.AVRecorder

| Name                     | Value  | Description                  |
| ------------------------- | ---- | ---------------------- |
| AUDIO_SOURCE_TYPE_DEFAULT | 0    | Default audio input source.|
| AUDIO_SOURCE_TYPE_MIC     | 1    | Mic audio input source. |

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
| CFT_MPEG_4A | 'm4a' | Audio container format M4A.|

## Location

Describes the geographical location of the recorded video.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name     | Type  | Mandatory| Description            |
| --------- | ------ | ---- | ---------------- |
| latitude  | number | Yes  | Latitude of the geographical location.|
| longitude | number | Yes  | Longitude of the geographical location.|

## VideoRecorder<sup>9+</sup>

> **NOTE**
>
> This class is deprecated after AVRecorder<sup>9+</sup> is released. You are advised to use [AVRecorder](#avrecorder9) instead.

Implements video recording. Before calling any API in the **VideoRecorder** class, you must use [createVideoRecorder()](#mediacreatevideorecorder9) to create a [VideoRecorder](#videorecorder9) instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name              | Type                                  | Readable| Writable| Description            |
| ------------------ | -------------------------------------- | ---- | ---- | ---------------- |
| state<sup>9+</sup> | [VideoRecordState](#videorecordstate9) | Yes  | No  | Video recording state.|

### prepare<sup>9+</sup><a name=videorecorder_prepare1></a>

prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void;

Sets video recording parameters. This API uses an asynchronous callback to return the result.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                                        | Mandatory| Description                               |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| config   | [VideoRecorderConfig](#videorecorderconfig9) | Yes  | Video recording parameters to set.           |
| callback | AsyncCallback\<void>                         | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 201      | Permission denied. Return by callback.     |
| 401      | Parameter error. Return by callback.       |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.          |

**Example**

```js
// Configure the parameters based on those supported by the hardware device.
let videoProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : 'audio/mp4a-latm',
  audioSampleRate : 48000,
  fileFormat : 'mp4',
  videoBitrate : 2000000,
  videoCodec : 'video/avc',
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
}

let videoConfig = {
  audioSourceType : 1,
  videoSourceType : 0,
  profile : videoProfile,
  url : 'fd://xx',   // The file must be created by the caller and granted with proper permissions.
  orientationHint : 0,
  location : { latitude : 30, longitude : 130 },
}

// asyncallback
videoRecorder.prepare(videoConfig, (err) => {
  if (err == null) {
    console.info('prepare success');
  } else {
    console.error('prepare failed and error is ' + err.message);
  }
})
```

### prepare<sup>9+</sup><a name=videorecorder_prepare2></a>

prepare(config: VideoRecorderConfig): Promise\<void>;

Sets video recording parameters. This API uses a promise to return the result.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name| Type                                        | Mandatory| Description                    |
| ------ | -------------------------------------------- | ---- | ------------------------ |
| config | [VideoRecorderConfig](#videorecorderconfig9) | Yes  | Video recording parameters to set.|

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201      | Permission denied. Return by promise.     |
| 401      | Parameter error. Return by promise.       |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.          |

**Example**

```js
// Configure the parameters based on those supported by the hardware device.
let videoProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : 'audio/mp4a-latm',
  audioSampleRate : 48000,
  fileFormat : 'mp4',
  videoBitrate : 2000000,
  videoCodec : 'video/avc',
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
}

let videoConfig = {
  audioSourceType : 1,
  videoSourceType : 0,
  profile : videoProfile,
  url : 'fd://xx',   // The file must be created by the caller and granted with proper permissions.
  orientationHint : 0,
  location : { latitude : 30, longitude : 130 },
}

// promise
videoRecorder.prepare(videoConfig).then(() => {
  console.info('prepare success');
}).catch((err) => {
  console.error('prepare failed and catch error is ' + err.message);
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(callback: AsyncCallback\<string>): void;

Obtains the surface required for recording. This API uses an asynchronous callback to return the result. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp must be based on the system startup time.

This API can be called only after [prepare()](#videorecorder_prepare1) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to obtain the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```js
// asyncallback
let surfaceID = null;                                               // Surface ID passed to the external system.
videoRecorder.getInputSurface((err, surfaceId) => {
  if (err == null) {
    console.info('getInputSurface success');
    surfaceID = surfaceId;
  } else {
    console.error('getInputSurface failed and error is ' + err.message);
  }
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(): Promise\<string>;

 Obtains the surface required for recording. This API uses a promise to return the result. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp must be based on the system startup time.

This API can be called only after [prepare()](#videorecorder_prepare1) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<string> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```js
// promise
let surfaceID = null;                                               // Surface ID passed to the external system.
videoRecorder.getInputSurface().then((surfaceId) => {
  console.info('getInputSurface success');
  surfaceID = surfaceId;
}).catch((err) => {
  console.error('getInputSurface failed and catch error is ' + err.message);
});
```

### start<sup>9+</sup><a name=videorecorder_start1></a>

start(callback: AsyncCallback\<void>): void;

Starts video recording. This API uses an asynchronous callback to return the result.

This API can be called only after [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface9) are called, because the data source must pass data to the surface first.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```js
// asyncallback
videoRecorder.start((err) => {
  if (err == null) {
    console.info('start videorecorder success');
  } else {
    console.error('start videorecorder failed and error is ' + err.message);
  }
});
```

### start<sup>9+</sup><a name=videorecorder_start2></a>

start(): Promise\<void>;

Starts video recording. This API uses a promise to return the result.

This API can be called only after [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface9) are called, because the data source must pass data to the surface first.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```js
// promise
videoRecorder.start().then(() => {
  console.info('start videorecorder success');
}).catch((err) => {
  console.error('start videorecorder failed and catch error is ' + err.message);
});
```

### pause<sup>9+</sup><a name=videorecorder_pause1></a>

pause(callback: AsyncCallback\<void>): void;

Pauses video recording. This API uses an asynchronous callback to return the result.

This API can be called only after [start()](#videorecorder_start1) is called. You can resume recording by calling [resume()](#videorecorder_resume1).

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```js
// asyncallback
videoRecorder.pause((err) => {
  if (err == null) {
    console.info('pause videorecorder success');
  } else {
    console.error('pause videorecorder failed and error is ' + err.message);
  }
});
```

### pause<sup>9+</sup><a name=videorecorder_pause2></a>

pause(): Promise\<void>;

Pauses video recording. This API uses a promise to return the result.

This API can be called only after [start()](#videorecorder_start1) is called. You can resume recording by calling [resume()](#videorecorder_resume1).

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```js
// promise
videoRecorder.pause().then(() => {
  console.info('pause videorecorder success');
}).catch((err) => {
  console.error('pause videorecorder failed and catch error is ' + err.message);
});
```

### resume<sup>9+</sup><a name=videorecorder_resume1></a>

resume(callback: AsyncCallback\<void>): void;

Resumes video recording. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```js
// asyncallback
videoRecorder.resume((err) => {
  if (err == null) {
    console.info('resume videorecorder success');
  } else {
    console.error('resume videorecorder failed and error is ' + err.message);
  }
});
```

### resume<sup>9+</sup><a name=videorecorder_resume2></a>

resume(): Promise\<void>;

Resumes video recording. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```js
// promise
videoRecorder.resume().then(() => {
  console.info('resume videorecorder success');
}).catch((err) => {
  console.error('resume videorecorder failed and catch error is ' + err.message);
});
```

### stop<sup>9+</sup><a name=videorecorder_stop1></a>

stop(callback: AsyncCallback\<void>): void;

Stops video recording. This API uses an asynchronous callback to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface9) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**Example**

```js
// asyncallback
videoRecorder.stop((err) => {
  if (err == null) {
    console.info('stop videorecorder success');
  } else {
    console.error('stop videorecorder failed and error is ' + err.message);
  }
});
```

### stop<sup>9+</sup><a name=videorecorder_stop2></a>

stop(): Promise\<void>;

Stops video recording. This API uses a promise to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface9) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**Example**

```js
// promise
videoRecorder.stop().then(() => {
  console.info('stop videorecorder success');
}).catch((err) => {
  console.error('stop videorecorder failed and catch error is ' + err.message);
});
```

### release<sup>9+</sup><a name=videorecorder_release1></a>

release(callback: AsyncCallback\<void>): void;

Releases the video recording resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                            |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```js
// asyncallback
videoRecorder.release((err) => {
  if (err == null) {
    console.info('release videorecorder success');
  } else {
    console.error('release videorecorder failed and error is ' + err.message);
  }
});
```

### release<sup>9+</sup><a name=videorecorder_release2></a>

release(): Promise\<void>;

Releases the video recording resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                     |
| -------------- | ----------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**Example**

```js
// promise
videoRecorder.release().then(() => {
  console.info('release videorecorder success');
}).catch((err) => {
  console.error('release videorecorder failed and catch error is ' + err.message);
});
```

### reset<sup>9+</sup><a name=videorecorder_reset1></a>

reset(callback: AsyncCallback\<void>): void;

Resets video recording. This API uses an asynchronous callback to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface9) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | I/O error. Return by callback.    |
| 5400105  | Service died. Return by callback. |

**Example**

```js
// asyncallback
videoRecorder.reset((err) => {
  if (err == null) {
    console.info('reset videorecorder success');
  } else {
    console.error('reset videorecorder failed and error is ' + err.message);
  }
});
```

### reset<sup>9+</sup><a name=videorecorder_reset2></a>

reset(): Promise\<void>;

Resets video recording. This API uses a promise to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface9) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                        |
| -------- | -------------------------------- |
| 5400103  | I/O error. Return by promise.    |
| 5400105  | Service died. Return by promise. |

**Example**

```js
// promise
videoRecorder.reset().then(() => {
  console.info('reset videorecorder success');
}).catch((err) => {
  console.error('reset videorecorder failed and catch error is ' + err.message);
});
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to video recording error events. After an error event is reported, you must handle the event and exit the recording.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during video recording.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | I/O error. Return by callback.    |
| 5400105  | Service died. Return by callback. |

**Example**

```js
// This event is reported when an error occurs during the retrieval of videoRecordState.
videoRecorder.on('error', (error) => {                                  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`); 
})
```

## VideoRecordState<sup>9+</sup>

Enumerates the video recording states. You can obtain the state through the **state** attribute.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name    | Type  | Description                  |
| -------- | ------ | ---------------------- |
| idle     | string | The video recorder is idle.        |
| prepared | string | The video recording parameters are set.|
| playing  | string | Video recording is in progress.        |
| paused   | string | Video recording is paused.        |
| stopped  | string | Video recording is stopped.        |
| error    | string | Video recording is in the error state.            |

## VideoRecorderConfig<sup>9+</sup>

Describes the video recording parameters.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name           | Type                                          | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](#audiosourcetype9)           | Yes  | Type of the audio source for video recording.                                      |
| videoSourceType | [VideoSourceType](#videosourcetype9)           | Yes  | Type of the video source for video recording.                                      |
| profile         | [VideoRecorderProfile](#videorecorderprofile9) | Yes  | Video recording profile.                                         |
| rotation        | number                                         | No  | Rotation angle of the recorded video. The value can only be 0 (default), 90, 180, or 270.      |
| location        | [Location](#location)                          | No  | Geographical location of the recorded video. By default, the geographical location information is not recorded.                |
| url             | string                                         | Yes  | Video output URL. Supported: fd://xx (fd number)<br>![](figures/en-us_image_url.png) |

## VideoRecorderProfile<sup>9+</sup>

Describes the video recording profile.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name            | Type                                        | Mandatory| Description            |
| ---------------- | -------------------------------------------- | ---- | ---------------- |
| audioBitrate     | number                                       | Yes  | Audio encoding bit rate.|
| audioChannels    | number                                       | Yes  | Number of audio channels.|
| audioCodec       | [CodecMimeType](#codecmimetype8)             | Yes  | Audio encoding format.  |
| audioSampleRate  | number                                       | Yes  | Audio sampling rate.    |
| fileFormat       | [ContainerFormatType](#containerformattype8) | Yes  | Container format of a file.|
| videoBitrate     | number                                       | Yes  | Video encoding bit rate.|
| videoCodec       | [CodecMimeType](#codecmimetype8)             | Yes  | Video encoding format.  |
| videoFrameWidth  | number                                       | Yes  | Width of the recorded video frame.|
| videoFrameHeight | number                                       | Yes  | Height of the recorded video frame.|
| videoFrameRate   | number                                       | Yes  | Video frame rate.  |

## media.createAudioPlayer<sup>(deprecated)</sup><a name=createaudioplayer></a>

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

```js
let audioPlayer = media.createAudioPlayer();
```

## media.createVideoPlayer<sup>(deprecated)</sup><a name=createvideoplayer></a>

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

```js
let videoPlayer;

media.createVideoPlayer((error, video) => {
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

```js
let videoPlayer;

media.createVideoPlayer().then((video) => {
  if (video != null) {
    videoPlayer = video;
    console.info('video createVideoPlayer success');
  } else {
    console.error('video createVideoPlayer fail');
  }
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## media.createAudioRecorder<sup>(deprecated)</sup><a name=createaudiorecorder></a>

createAudioRecorder(): AudioRecorder

Creates an **AudioRecorder** instance to control audio recording.
Only one **AudioRecorder** instance can be created per device.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [createAVRecorder](#mediacreateavrecorder9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [AudioRecorder](#audiorecorderdeprecated) | If the operation is successful, the **AudioRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record audio.|

**Example**

```js
let audioRecorder = media.createAudioRecorder();
```

## MediaErrorCode<sup>(deprecated)</sup><a name=mediaerrorcode></a>

Enumerates the media error codes.

> **NOTE**
>
> This enum is supported since API version 8 and deprecated since API version 9. You are advised to use [Media Error Codes](../errorcodes/errorcode-media.md) instead.

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

### Attributes<a name=audioplayer_attributes></a>

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name                           | Type                                                  | Readable| Writable| Description                                                        |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| src                             | string                                                 | Yes  | Yes  | Audio file URI. The mainstream audio formats (M4A, AAC, MP3, OGG, and WAV) are supported.<br>**Examples of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http://xx<br>3. HTTPS: https://xx<br>4. HLS: http://xx or https://xx<br>**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.INTERNET|
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | Yes  | Yes  | Description of the audio file. This attribute is required when audio assets of an application are continuously stored in a file.<br>**Example:**<br>Assume that a music file that stores continuous music assets consists of the following:<br>Music 1 (address offset: 0, byte length: 100)<br>Music 2 (address offset: 101; byte length: 50)<br>Music 3 (address offset: 151, byte length: 150)<br>1. To play music 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play music 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play music 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent music file, use **src=fd://xx**.<br>|
| loop                            | boolean                                                | Yes  | Yes  | Whether to loop audio playback. The value **true** means to loop audio playback, and **false** means the opposite.                |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](js-apis-audio.md#interruptmode9) | Yes  | Yes  | Audio interruption mode.                                              |
| currentTime                     | number                                                 | Yes  | No  | Current audio playback position, in ms.                      |
| duration                        | number                                                 | Yes  | No  | Audio duration, in ms.                                |
| state                           | [AudioState](#audiostate)                              | Yes  | No  | Audio playback state. This state cannot be used as the condition for triggering the call of **play()**, **pause()**, or **stop()**.|

### play<a name=audioplayer_play></a>

play(): void

Starts to play an audio asset. This API can be called only after the [dataLoad](#audioplayer_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```js
audioPlayer.on('play', () => {    // Set the 'play' event callback.
  console.log('audio play success');
});
audioPlayer.play();
```

### pause<a name=audioplayer_pause></a>

pause(): void

Pauses audio playback.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```js
audioPlayer.on('pause', () => {    // Set the 'pause' event callback.
  console.log('audio pause success');
});
audioPlayer.pause();
```

### stop<a name=audioplayer_stop></a>

stop(): void

Stops audio playback.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```js
audioPlayer.on('stop', () => {    // Set the 'stop' event callback.
  console.log('audio stop success');
});
audioPlayer.stop();
```

### reset<sup>7+</sup><a name=audioplayer_reset></a>

reset(): void

Resets the audio asset to be played.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```js
audioPlayer.on('reset', () => {    // Set the 'reset' event callback.
  console.log('audio reset success');
});
audioPlayer.reset();
```

### seek<a name=audioplayer_seek></a>

seek(timeMs: number): void

Seeks to the specified playback position.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                       |
| ------ | ------ | ---- | ----------------------------------------------------------- |
| timeMs | number | Yes  | Position to seek to, in ms. The value range is [0, duration].|

**Example**

```js
audioPlayer.on('timeUpdate', (seekDoneTime) => {    // Set the 'timeUpdate' event callback.
  if (seekDoneTime == null) {
    console.info('audio seek fail');
    return;
  }
  console.log('audio seek success. seekDoneTime: ' + seekDoneTime);
});
audioPlayer.seek(30000); // Seek to 30000 ms.
```

### setVolume<a name=audioplayer_setvolume></a>

setVolume(vol: number): void

Sets the volume.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|

**Example**

```js
audioPlayer.on('volumeChange', () => {    // Set the 'volumeChange' event callback.
  console.log('audio volumeChange success');
});
audioPlayer.setVolume(1);    // Set the volume to 100%.
```

### release<a name=audioplayer_release></a>

release(): void

Releases the audio playback resources.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```js
audioPlayer.release();
audioPlayer = undefined;
```

### getTrackDescription<sup>8+</sup><a name=audioplayer_gettrackdescription1></a>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the audio track information. This API uses an asynchronous callback to return the result. It can be called only after the [dataLoad](#audioplayer_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the audio track information.|

**Example**

```js
function printfDescription(obj) {
  for (let item in obj) {
    let property = obj[item];
    console.info('audio key is ' + item);
    console.info('audio value is ' + property);
  }
}

audioPlayer.getTrackDescription((error, arrList) => {
  if (arrList != null) {
    for (let i = 0; i < arrList.length; i++) {
      printfDescription(arrList[i]);
    }
  } else {
    console.log(`audio getTrackDescription fail, error:${error}`);
  }
});
```

### getTrackDescription<sup>8+</sup><a name=audioplayer_gettrackdescription2></a>

getTrackDescription(): Promise\<Array\<MediaDescription>>

Obtains the audio track information. This API uses a promise to return the result. It can be called only after the [dataLoad](#audioplayer_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Return value**

| Type                                                  | Description                                           |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return a **MediaDescription** array, which records the audio track information.|

**Example**

```js
function printfDescription(obj) {
  for (let item in obj) {
    let property = obj[item];
    console.info('audio key is ' + item);
    console.info('audio value is ' + property);
  }
}
let arrayDescription = null
audioPlayer.getTrackDescription().then((arrList) => {
  if (arrList != null) {
    arrayDescription = arrList;
  } else {
    console.log('audio getTrackDescription fail');
  }
}).catch((error) => {
  console.info(`audio catchCallback, error:${error}`);
});

for (let i = 0; i < arrayDescription.length; i++) {
  printfDescription(arrayDescription[i]);
}
```

### on('bufferingUpdate')<sup>8+</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to the audio buffering update event. This API works only under online playback.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | function | Yes  | Callback invoked when the event is triggered.<br>When [BufferingInfoType](#bufferinginfotype8) is set to **BUFFERING_PERCENT** or **CACHED_DURATION**, **value** is valid. Otherwise, **value** is fixed at **0**.|

**Example**

```js
audioPlayer.on('bufferingUpdate', (infoType, value) => {
  console.log('audio bufferingInfo type: ' + infoType);
  console.log('audio bufferingInfo value: ' + value);
});
```

 ### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')<a name = audioplayer_on></a>

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void): void

Subscribes to the audio playback events.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type      | Mandatory| Description                                                        |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | Yes  | Event type. The following events are supported:<br>- 'play': triggered when the [play()](#audioplayer_play) API is called and audio playback starts.<br>- 'pause': triggered when the [pause()](#audioplayer_pause) API is called and audio playback is paused.<br>- 'stop': triggered when the [stop()](#audioplayer_stop) API is called and audio playback stops.<br>- 'reset': triggered when the [reset()](#audioplayer_reset) API is called and audio playback is reset.<br>- 'dataLoad': triggered when the audio data is loaded, that is, when the **src** attribute is configured.<br>- 'finish': triggered when the audio playback is finished.<br>- 'volumeChange': triggered when the [setVolume()](#audioplayer_setvolume) API is called and the playback volume is changed.|
| callback | () => void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```js
import fs from '@ohos.file.fs';

let audioPlayer = media.createAudioPlayer();  // Create an AudioPlayer instance.
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
audioPlayer.on('timeUpdate', (seekDoneTime) => {  // Set the 'timeUpdate' event callback.
  if (seekDoneTime == null) {
    console.info('audio seek fail');
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
audioPlayer.on('error', (error) => {           // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});

// Set the FD (local playback) of the audio file selected by the user.
let fdPath = 'fd://';
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
fs.open(path).then((file) => {
  fdPath = fdPath + '' + file.fd;
  console.info('open fd success fd is' + fdPath);
  audioPlayer.src = fdPath;  // Set the src attribute and trigger the 'dataLoad' event callback.
}, (err) => {
  console.info('open fd failed err is' + err);
}).catch((err) => {
  console.info('open fd failed err is' + err);
});
```

### on('timeUpdate')

on(type: 'timeUpdate', callback: Callback\<number>): void

Subscribes to the **'timeUpdate'** event. This event is reported every second when the audio playback is in progress.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type             | Mandatory| Description                                                        |
| -------- | ----------------- | ---- | ------------------------------------------------------------ |
| type     | string            | Yes  | Event type, which is **'timeUpdate'** in this case.<br>The **'timeUpdate'** event is triggered when the audio playback starts after an audio playback timestamp update.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. The input parameter is the updated timestamp.            |

**Example**

```js
audioPlayer.on('timeUpdate', (newTime) => {    // Set the 'timeUpdate' event callback.
  if (newTime == null) {
    console.info('audio timeUpadate fail');
    return;
  }
  console.log('audio timeUpadate success. seekDoneTime: ' + newTime);
});
audioPlayer.play();    // The 'timeUpdate' event is triggered when the playback starts.
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to audio playback error events. After an error event is reported, you must handle the event and exit the playback.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during audio playback.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
audioPlayer.on('error', (error) => {      // Set the 'error' event callback.
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

## VideoPlayer<sup>(deprecated)</sup><a name=videoplayer></a>

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer](#avplayer9) instead.

Provides APIs to manage and play video. Before calling any API of **VideoPlayer**, you must use [createVideoPlayer()](#createvideoplayer) to create a **VideoPlayer** instance.

### Attributes<a name=videoplayer_attributes></a>

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                           | Type                                                  | Readable| Writable| Description                                                        |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>                | string                                                 | Yes  | Yes  | Video URL. The mainstream video formats (MP4, MPEG-TS, WebM, and MKV) are supported.<br>**Example of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http://xx<br>3. HTTPS: https://xx<br>4. HLS: http://xx or https://xx<br>|
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | Yes  | Yes  | Description of a video file. This attribute is required when video assets of an application are continuously stored in a file.<br>**Example:**<br>Assume that a music file that stores continuous music assets consists of the following:<br>Video 1 (address offset: 0, byte length: 100)<br>Video 2 (address offset: 101; byte length: 50)<br>Video 3 (address offset: 151, byte length: 150)<br>1. To play video 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play video 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play video 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent video file, use **src=fd://xx**.<br>|
| loop<sup>8+</sup>               | boolean                                                | Yes  | Yes  | Whether to loop video playback. The value **true** means to loop video playback, and **false** means the opposite.                |
| videoScaleType<sup>9+</sup>     | [VideoScaleType](#videoscaletype9)                     | Yes  | Yes  | Video scale type.                                              |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](js-apis-audio.md#interruptmode9) | Yes  | Yes  | Audio interruption mode.                                              |
| currentTime<sup>8+</sup>        | number                                                 | Yes  | No  | Current video playback position, in ms.                      |
| duration<sup>8+</sup>           | number                                                 | Yes  | No  | Video duration, in ms. The value **-1** indicates the live mode.            |
| state<sup>8+</sup>              | [VideoPlayState](#videoplayerstate)                    | Yes  | No  | Video playback state.                                            |
| width<sup>8+</sup>              | number                                                 | Yes  | No  | Video width, in pixels.                                  |
| height<sup>8+</sup>             | number                                                 | Yes  | No  | Video height, in pixels.                                  |

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

Sets **SurfaceId**. This API uses an asynchronous callback to return the result.

**SetDisplaySurface** must be called between the URL setting and the calling of **prepare**. A surface must be set for video streams without audio. Otherwise, the calling of **prepare** fails.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name   | Type                | Mandatory| Description                     |
| --------- | -------------------- | ---- | ------------------------- |
| surfaceId | string               | Yes  | Surface ID to set.                |
| callback  | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
let surfaceId = null;
videoPlayer.setDisplaySurface(surfaceId, (err) => {
  if (err == null) {
    console.info('setDisplaySurface success!');
  } else {
    console.error('setDisplaySurface fail!');
  }
});
```

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

Sets **SurfaceId**. This API uses a promise to return the result.

**SetDisplaySurface** must be called between the URL setting and the calling of **prepare**. A surface must be set for video streams without audio. Otherwise, the calling of **prepare** fails.

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

```js
let surfaceId = null;
videoPlayer.setDisplaySurface(surfaceId).then(() => {
  console.info('setDisplaySurface success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### prepare<sup>8+</sup>

prepare(callback: AsyncCallback\<void>): void

Prepares for video playback. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.prepare((err) => {
  if (err == null) {
    console.info('prepare success!');
  } else {
    console.error('prepare fail!');
  }
});
```

### prepare<sup>8+</sup>

prepare(): Promise\<void>

Prepares for video playback. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.prepare().then(() => {
  console.info('prepare success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### play<sup>8+</sup>

play(callback: AsyncCallback\<void>): void;

Starts to play video assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.play((err) => {
  if (err == null) {
    console.info('play success!');
  } else {
    console.error('play fail!');
  }
});
```

### play<sup>8+</sup>

play(): Promise\<void>;

Starts to play video assets. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.play().then(() => {
  console.info('play success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses video playback. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.pause((err) => {
  if (err == null) {
    console.info('pause success!');
  } else {
    console.info('pause fail!');
  }
});
```

### pause<sup>8+</sup>

pause(): Promise\<void>

Pauses video playback. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.pause().then(() => {
  console.info('pause success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

Stops video playback. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.stop((err) => {
  if (err == null) {
    console.info('stop success!');
  } else {
    console.error('stop fail!');
  }
});
```

### stop<sup>8+</sup>

stop(): Promise\<void>

Stops video playback. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.stop().then(() => {
  console.info('stop success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### reset<sup>8+</sup>

reset(callback: AsyncCallback\<void>): void

Resets the video asset to be played. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.reset((err) => {
  if (err == null) {
    console.info('reset success!');
  } else {
    console.error('reset fail!');
  }
});
```

### reset<sup>8+</sup>

reset(): Promise\<void>

Resets the video asset to be played. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.reset().then(() => {
  console.info('reset success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### seek<sup>8+</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. The previous key frame at the specified position is played. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | Yes  | Position to seek to, in ms. The value range is [0, duration].|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.                              |

**Example**

```js
let seekTime = 5000;
videoPlayer.seek(seekTime, (err, result) => {
  if (err == null) {
    console.info('seek success!');
  } else {
    console.error('seek fail!');
  }
});
```

### seek<sup>8+</sup>

seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | Yes  | Position to seek to, in ms. The value range is [0, duration].|
| mode     | [SeekMode](#seekmode8) | Yes  | Seek mode.                                                  |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.                              |

**Example**

```js
import media from '@ohos.multimedia.media'
let seekTime = 5000;
videoPlayer.seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC, (err, result) => {
  if (err == null) {
    console.info('seek success!');
  } else {
    console.error('seek fail!');
  }
});
```

### seek<sup>8+</sup>

seek(timeMs: number, mode?:SeekMode): Promise\<number>

Seeks to the specified playback position. If **mode** is not specified, the previous key frame at the specified position is played. This API uses a promise to return the result.

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

```js
import media from '@ohos.multimedia.media'
let seekTime = 5000;
videoPlayer.seek(seekTime).then((seekDoneTime) => { // seekDoneTime indicates the position after the seek operation is complete.
  console.info('seek success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});

videoPlayer.seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC).then((seekDoneTime) => {
  console.info('seek success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### setVolume<sup>8+</sup>

setVolume(vol: number, callback: AsyncCallback\<void>): void

Sets the volume. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| vol      | number               | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                                        |

**Example**

```js
let vol = 0.5;
videoPlayer.setVolume(vol, (err, result) => {
  if (err == null) {
    console.info('setVolume success!');
  } else {
    console.error('setVolume fail!');
  }
});
```

### setVolume<sup>8+</sup>

setVolume(vol: number): Promise\<void>

Sets the volume. This API uses a promise to return the result.

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

```js
let vol = 0.5;
videoPlayer.setVolume(vol).then(() => {
  console.info('setVolume success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

Releases the video playback resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.release((err) => {
  if (err == null) {
    console.info('release success!');
  } else {
    console.error('release fail!');
  }
});
```

### release<sup>8+</sup>

release(): Promise\<void>

Releases the video playback resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.release().then(() => {
  console.info('release success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the video track information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the video track information.|

**Example**

```js
function printfDescription(obj) {
  for (let item in obj) {
    let property = obj[item];
    console.info('video key is ' + item);
    console.info('video value is ' + property);
  }
}

videoPlayer.getTrackDescription((error, arrList) => {
  if ((arrList) != null) {
    for (let i = 0; i < arrList.length; i++) {
      printfDescription(arrList[i]);
    }
  } else {
    console.log(`video getTrackDescription fail, error:${error}`);
  }
});
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

Obtains the video track information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                                  | Description                                           |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return a **MediaDescription** array, which records the video track information.|

**Example**

```js
function printfDescription(obj) {
  for (let item in obj) {
    let property = obj[item];
    console.info('video key is ' + item);
    console.info('video value is ' + property);
  }
}

let arrayDescription;
videoPlayer.getTrackDescription().then((arrList) => {
  if (arrList != null) {
    arrayDescription = arrList;
  } else {
    console.log('video getTrackDescription fail');
  }
}).catch((error) => {
  console.info(`video catchCallback, error:${error}`);
});
for (let i = 0; i < arrayDescription.length; i++) {
  printfDescription(arrayDescription[i]);
}
```

### setSpeed<sup>8+</sup>

setSpeed(speed:number, callback: AsyncCallback\<number>): void

Sets the video playback speed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                                                      |
| -------- | ---------------------- | ---- | ---------------------------------------------------------- |
| speed    | number                 | Yes  | Video playback speed. For details, see [PlaybackSpeed](#playbackspeed8).|
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.                                  |

**Example**

```js
import media from '@ohos.multimedia.media'
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;

videoPlayer.setSpeed(speed, (err, result) => {
  if (err == null) {
    console.info('setSpeed success!');
  } else {
    console.error('setSpeed fail!');
  }
});
```

### setSpeed<sup>8+</sup>

setSpeed(speed:number): Promise\<number>

Sets the video playback speed. This API uses a promise to return the result.

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

```js
import media from '@ohos.multimedia.media'
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;

videoPlayer.setSpeed(speed).then(() => {
  console.info('setSpeed success');
}).catch((error) => {
  console.error(`video catchCallback, error:${error}`);
});
```

### on('playbackCompleted')<sup>8+</sup>

on(type: 'playbackCompleted', callback: Callback\<void>): void

Subscribes to the video playback completion event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| type     | string   | Yes  | Event type, which is **'playbackCompleted'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered.                                 |

**Example**

```js
videoPlayer.on('playbackCompleted', () => {
  console.info('playbackCompleted success!');
});
```

### on('bufferingUpdate')<sup>8+</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to the video buffering update event. Only network playback supports this subscription.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | function | Yes  | Callback invoked when the event is triggered.<br>When [BufferingInfoType](#bufferinginfotype8) is set to **BUFFERING_PERCENT** or **CACHED_DURATION**, **value** is valid. Otherwise, **value** is fixed at **0**.|

**Example**

```js
videoPlayer.on('bufferingUpdate', (infoType, value) => {
  console.log('video bufferingInfo type: ' + infoType);
  console.log('video bufferingInfo value: ' + value);
});
```

### on('startRenderFrame')<sup>8+</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

Subscribes to the frame rendering start event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type           | Mandatory| Description                                                        |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | Yes  | Event type, which is **'startRenderFrame'** in this case.|
| callback | Callback\<void> | Yes  | Callback invoked when the event is triggered.                          |

**Example**

```js
videoPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame success!');
});
```

### on('videoSizeChanged')<sup>8+</sup>

on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void

Subscribes to the video width and height change event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'videoSizeChanged'** in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered. **width** indicates the video width, and **height** indicates the video height.   |

**Example**

```js
videoPlayer.on('videoSizeChanged', (width, height) => {
  console.log('video width is: ' + width);
  console.log('video height is: ' + height);
});
```

### on('error')<sup>8+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to video playback error events. After an error event is reported, you must handle the event and exit the playback.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during video playback.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
videoPlayer.on('error', (error) => {      // Set the 'error' event callback.
  console.error(`video error called, error: ${error}`);
});
videoPlayer.url = 'fd://error';  // Set an incorrect URL to trigger the 'error' event.
```

## VideoPlayState<sup>(deprecated)</sup><a name=videoplayerstate></a>

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

Implements audio recording. Before calling any API of **AudioRecorder**, you must use [createAudioRecorder()](#mediacreateaudiorecorder) to create an **AudioRecorder** instance.

### prepare<a name=audiorecorder_prepare></a>

prepare(config: AudioRecorderConfig): void

Prepares for recording.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfigdeprecated) | Yes  | Audio recording parameters, including the audio output URI, encoding format, sampling rate, number of audio channels, and output format.|

**Example**

```js
let audioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://1',       // The file must be created by the caller and granted with proper permissions.
  location : { latitude : 30, longitude : 130},
}
audioRecorder.on('prepare', () => {    // Set the 'prepare' event callback.
  console.log('prepare success');
});
audioRecorder.prepare(audioRecorderConfig);
```


### start<a name=audiorecorder_start></a>

start(): void

Starts audio recording. This API can be called only after the [prepare](#audiorecorder_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```js
audioRecorder.on('start', () => {    // Set the 'start' event callback.
  console.log('audio recorder start success');
});
audioRecorder.start();
```

### pause<a name=audiorecorder_pause></a>

pause():void

Pauses audio recording. This API can be called only after the [start](#audiorecorder_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```js
audioRecorder.on('pause', () => {    // Set the 'pause' event callback.
  console.log('audio recorder pause success');
});
audioRecorder.pause();
```

### resume<a name=audiorecorder_resume></a>

resume():void

Resumes audio recording. This API can be called only after the [pause](#audiorecorder_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```js
audioRecorder.on('resume', () => { // Set the 'resume' event callback.
  console.log('audio recorder resume success');
});
audioRecorder.resume();
```

### stop<a name=audiorecorder_stop></a>

stop(): void

Stops audio recording.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```js
audioRecorder.on('stop', () => {    // Set the 'stop' event callback.
  console.log('audio recorder stop success');
});
audioRecorder.stop();
```

### release<a name=audiorecorder_release></a>

release(): void

Releases the audio recording resources.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```js
audioRecorder.on('release', () => {    // Set the 'release' event callback.
  console.log('audio recorder release success');
});
audioRecorder.release();
audioRecorder = undefined;
```

### reset<a name=audiorecorder_reset></a>

reset(): void

Resets audio recording.

Before resetting audio recording, you must call [stop()](#audiorecorder_stop) to stop recording. After audio recording is reset, you must call [prepare()](#audiorecorder_prepare) to set the recording parameters for another recording.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```js
audioRecorder.on('reset', () => {    // Set the 'reset' event callback.
  console.log('audio recorder reset success');
});
audioRecorder.reset();
```

### on('prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset')<a name=audiorecorder_on></a>

on(type: 'prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset', callback: () => void): void

Subscribes to the audio recording events.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The following events are supported:<br>- 'prepare': triggered when the [prepare](#audiorecorder_prepare) API is called and the audio recording parameters are set.<br>- 'start': triggered when the [start](#audiorecorder_start) API is called and audio recording starts.<br>- 'pause': triggered when the [pause](#audiorecorder_pause) API is called and audio recording is paused.<br>- 'resume': triggered when the [resume](#audiorecorder_resume) API is called and audio recording is resumed.<br>- 'stop': triggered when the [stop](#audiorecorder_stop) API is called and audio recording stops.<br>- 'release': triggered when the [release](#audiorecorder_release) API is called and the recording resources are released.<br>- 'reset': triggered when the [reset](#audiorecorder_reset) API is called and audio recording is reset.|
| callback | ()=>void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```js
let audioRecorder = media.createAudioRecorder();                                  // Create an AudioRecorder instance.
let audioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://xx',                                                            // The file must be created by the caller and granted with proper permissions.
  location : { latitude : 30, longitude : 130},
}
audioRecorder.on('error', (error) => {                                             // Set the 'error' event callback.
  console.info(`audio error called, error: ${error}`);
});
audioRecorder.on('prepare', () => {                                              // Set the 'prepare' event callback.
  console.log('prepare success');
  audioRecorder.start();                                                       // Start recording and trigger the 'start' event callback.
});
audioRecorder.on('start', () => {                                                 // Set the 'start' event callback.
  console.log('audio recorder start success');
});
audioRecorder.on('pause', () => {                                                 // Set the 'pause' event callback.
  console.log('audio recorder pause success');
});
audioRecorder.on('resume', () => {                                                 // Set the 'resume' event callback.
  console.log('audio recorder resume success');
});
audioRecorder.on('stop', () => {                                                 // Set the 'stop' event callback.
  console.log('audio recorder stop success');
});
audioRecorder.on('release', () => {                                                 // Set the 'release' event callback.
  console.log('audio recorder release success');
});
audioRecorder.on('reset', () => {                                                 // Set the 'reset' event callback.
  console.log('audio recorder reset success');
});
audioRecorder.prepare(audioRecorderConfig)                                       // Set recording parameters and trigger the 'prepare' event callback.
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to audio recording error events. After an error event is reported, you must handle the event and exit the recording.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>This event is triggered when an error occurs during audio recording.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
let audioRecorderConfig = {
  audioEncoder : media.AudioEncoder.AAC_LC,
  audioEncodeBitRate : 22050,
  audioSampleRate : 22050,
  numberOfChannels : 2,
  format : media.AudioOutputFormat.AAC_ADTS,
  uri : 'fd://xx',                                                     // The file must be created by the caller and granted with proper permissions.
  location : { latitude : 30, longitude : 130},
}
audioRecorder.on('error', (error) => {                                  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});
audioRecorder.prepare(audioRecorderConfig);                            // Do no set any parameter in prepare and trigger the 'error' event callback.
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
| audioEncoderMime<sup>8+</sup>       | [CodecMimeType](#codecmimetype8)             | No  | Audio encoding format.                                              |
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
