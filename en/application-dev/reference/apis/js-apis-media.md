# Media

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The multimedia subsystem provides a set of simple and easy-to-use APIs for you to access the system and use media resources.

This subsystem offers various media services covering audio and video, which provide the following capabilities:

- Audio playback ([AudioPlayer](#audioplayer))
- Video playback ([VideoPlayer](#videoplayer8))
- Audio recording ([AudioRecorder](#audiorecorder))

The following capabilities will be provided in later versions: data source audio/video playback, audio/video encoding and decoding, container encapsulation and decapsulation, and media capability query.

## Modules to Import

```js
import media from '@ohos.multimedia.media';
```

##  media.createAudioPlayer

createAudioPlayer(): [AudioPlayer](#audioplayer)

Creates an **AudioPlayer** instance in synchronous mode.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Return value**

| Type                       | Description                                                        |
| --------------------------- | ------------------------------------------------------------ |
| [AudioPlayer](#audioplayer) | Returns the **AudioPlayer** instance if the operation is successful; returns **null** otherwise. After the instance is created, you can start, pause, or stop audio playback.|

**Example**

```js
let audioPlayer = media.createAudioPlayer();
```

## media.createVideoPlayer<sup>8+</sup>

createVideoPlayer(callback: AsyncCallback\<[VideoPlayer](#videoplayer8)>): void

Creates a **VideoPlayer** instance in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                       | Mandatory| Description                          |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[VideoPlayer](#videoplayer8)> | Yes  | Callback used to return the **VideoPlayer** instance created.|

**Example**

```js
let videoPlayer

media.createVideoPlayer((error, video) => {
   if (typeof(video) != 'undefined') {
       videoPlayer = video;
       console.info('video createVideoPlayer success');
   } else {
       console.info(`video createVideoPlayer fail, error:${error.message}`);
   }
});
```

## media.createVideoPlayer<sup>8+</sup>

createVideoPlayer(): Promise<[VideoPlayer](#videoplayer8)>

Creates a **VideoPlayer** instance in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                 | Description                               |
| ------------------------------------- | ----------------------------------- |
| Promise<[VideoPlayer](#videoplayer8)> | Promise used to return the **VideoPlayer** instance created.|

**Example**

```js
let videoPlayer

media.createVideoPlayer().then((video) => {
   if (typeof(video) != 'undefined') {
       videoPlayer = video;
       console.info('video createVideoPlayer success');
   } else {
       console.info('video createVideoPlayer fail');
   }
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});
```

## media.createAudioRecorder

createAudioRecorder(): AudioRecorder

Creates an **AudioRecorder** instance to control audio recording.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Return value**

| Type                           | Description                                     |
| ------------------------------- | ----------------------------------------- |
| [AudioRecorder](#audiorecorder) | Returns the **AudioRecorder** instance if the operation is successful; returns **null** otherwise.|

**Example**

```js
let audioRecorder = media.createAudioRecorder();
```




## MediaErrorCode<sup>8+</sup>

Enumerates the media error codes.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                      | Value  | Description                                  |
| -------------------------- | ---- | -------------------------------------- |
| MSERR_OK                   | 0    | The operation is successful.                        |
| MSERR_NO_MEMORY            | 1    | Failed to allocate memory. The system may have no available memory.|
| MSERR_OPERATION_NOT_PERMIT | 2    | No permission to perform this operation.                |
| MSERR_INVALID_VAL          | 3    | Invalid input parameter.                    |
| MSERR_IO                   | 4    | An I/O error occurs.                      |
| MSERR_TIMEOUT              | 5    | The operation times out.                        |
| MSERR_UNKNOWN              | 6    | An unknown error occurs.                        |
| MSERR_SERVICE_DIED         | 7    | Invalid server.                      |
| MSERR_INVALID_STATE        | 8    | The operation is not allowed in the current state.  |
| MSERR_UNSUPPORTED          | 9    | The operation is not supported in the current version.      |

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
| AUDIO_AAC    | "audio/mp4a-latm"     | Audio in MP4A-LATM format.|
| AUDIO_VORBIS | 'audio/vorbis'        | Audio in Vorbis format.   |
| AUDIO_FLAC   | 'audio/flac'          | Audio in FLAC format.     |

## MediaDescriptionKey<sup>8+</sup>

Enumerates the media description keys.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | "track_index"   | Track index, which is a number.                      |
| MD_KEY_TRACK_TYPE        | "track_type"    | Track type, which is a number. For details, see [MediaType](#mediatype8).|
| MD_KEY_CODEC_MIME        | "codec_mime"    | Codec MIME type, which is a string.                |
| MD_KEY_DURATION          | "duration"      | Media duration, which is a number, in units of ms.    |
| MD_KEY_BITRATE           | "bitrate"       | Bit rate, which is a number, in units of bit/s.   |
| MD_KEY_WIDTH             | "width"         | Video width, which is a number, in units of pixel.    |
| MD_KEY_HEIGHT            | "height"        | Video height, which is a number, in units of pixel.    |
| MD_KEY_FRAME_RATE        | "frame_rate"    | Video frame rate, which is a number, in units of 100 fps.|
| MD_KEY_AUD_CHANNEL_COUNT | "channel_count" | Number of audio channels, which is a number.                        |
| MD_KEY_AUD_SAMPLE_RATE   | "sample_rate"   | Sampling rate, which is a number, in units of Hz.      |

## BufferingInfoType<sup>8+</sup>

Enumerates the buffering event types.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name             | Value  | Description                            |
| ----------------- | ---- | -------------------------------- |
| BUFFERING_START   | 1    | Buffering starts.                  |
| BUFFERING_END     | 2    | Buffering ends.                  |
| BUFFERING_PERCENT | 3    | Buffering progress, in percent.                |
| CACHED_DURATION   | 4    | Cache duration, in milliseconds.|

## AudioPlayer

Provides APIs to manage and play audio. Before calling an API of **AudioPlayer**, you must use [createAudioPlayer()](#mediacreateaudioplayer) to create an **AudioPlayer** instance.

For details about the audio playback demo, see [Audio Playback Development](../../media/audio-playback.md).

### Attributes<a name=audioplayer_attributes></a>

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name       | Type                     | Readable| Writable| Description                                                        |
| ----------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| src         | string                    | Yes  | Yes  | Audio media URI. The mainstream audio formats (MPEG-4, AAC, MPEG-3, OGG, and WAV) are supported.<br>**Example of supported URIs**:<br>1. FD playback: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP network playback: http://xx<br>3. HLS network playback: under development<br>**Note**:<br>To use media materials, you must declare the read permission. Otherwise, the media materials cannot be played properly. |
| loop        | boolean                   | Yes  | Yes  | Whether to loop audio playback. The value **true** means to loop audio playback, and **false** means the opposite.                |
| currentTime | number                    | Yes  | No  | Current audio playback position.                                        |
| duration    | number                    | Yes  | No  | Audio duration.                                                  |
| state       | [AudioState](#audiostate) | Yes  | No  | Audio playback state.                                            |

### play<a name=audioplayer_play></a>

play(): void

Starts to play audio resources. This API can be called only after the [dataLoad](#audioplayer_on) event is triggered.

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

Switches the audio resource to be played.

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

| Name| Type  | Mandatory| Description                                |
| ------ | ------ | ---- | ------------------------------------ |
| timeMs | number | Yes  | Position to seek to, in milliseconds.|

**Example**

```js
audioPlayer.on('timeUpdate', (seekDoneTime) => {    // Set the 'timeUpdate' event callback.
    if (typeof (seekDoneTime) == 'undefined') {
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
| vol    | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1** indicates the maximum volume (100%).|

**Example**

```js
audioPlayer.on('volumeChange', () => {    // Set the 'volumeChange' event callback.
    console.log('audio volumeChange success');
});
audioPlayer.setVolume(1);    // Set the volume to 100%.
```

### release<a name=audioplayer_release></a>

release(): void

Releases the audio playback resource.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```js
audioPlayer.release();
audioPlayer = undefined;
```

### getTrackDescription<sup>8+</sup><a name=audioplayer_gettrackdescription1></a>

getTrackDescription(callback: AsyncCallback<Array\<MediaDescription>>): void

Obtains the audio track information. This API uses a callback to return the result. It can be called only after the [dataLoad](#audioplayer_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                      |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return the audio track information obtained.|

**Example**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('audio key is ' + item);
        console.info('audio value is ' + property);
    }
}

audioPlayer.getTrackDescription((error, arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        for (let i = 0; i < arrlist.length; i++) {
            printfDescription(arrlist[i]);
        }
    } else {
        console.log(`audio getTrackDescription fail, error:${error.message}`);
    }
});
```

### getTrackDescription<sup>8+</sup><a name=audioplayer_gettrackdescription2></a>

getTrackDescription(): Promise<Array\<MediaDescription>>

Obtains the audio track information. This API uses a promise to return the result. It can be called only after the [dataLoad](#audioplayer_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Return value**

| Type                                                  | Description                           |
| ------------------------------------------------------ | ------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return the audio track information obtained.|

**Example**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('audio key is ' + item);
        console.info('audio value is ' + property);
    }
}

audioPlayer.getTrackDescription().then((arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        arrayDescription = arrlist;
    } else {
        console.log('audio getTrackDescription fail');
    }
}).catch((error) => {
   console.info(`audio catchCallback, error:${error.message}`);
});

for (let i = 0; i < arrayDescription.length; i++) {
    printfDescription(arrayDescription[i]);
}
```

### on('bufferingUpdate')<sup>8+</sup>

on(type: 'bufferingUpdate', callback: (infoType: [BufferingInfoType](#bufferinginfotype8), value: number) => void): void

Subscribes to the audio buffering update event.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is 'bufferingUpdate' in this case.       |
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
| type     | string     | Yes  | Event type. The following events are supported:<br>- 'play': triggered when the [play()](#audioplayer_play) API is called and audio playback starts.<br>- 'pause': triggered when the [pause()](#audioplayer_pause) API is called and audio playback is paused.<br>- 'stop': triggered when the [stop()](#audioplayer_stop) API is called and audio playback stops.<br>- 'reset': triggered when the [reset()](#audioplayer_reset) API is called and audio playback is reset.<br>- 'dataLoad': triggered when the audio data is loaded, that is, when the **src** attribute is configured.<br>- 'finish': triggered when the audio playback is finished.<br>- 'volumeChange': triggered when the [setVolume()](#audioplayer_setvolume) API is called and the playback volume is changed. |
| callback | () => void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```js
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
    if (typeof(seekDoneTime) == "undefined") {
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
    console.info(`audio error called, errName is ${error.name}`);
    console.info(`audio error called, errCode is ${error.code}`);
    console.info(`audio error called, errMessage is ${error.message}`);
});

// Set the FD (local playback) of the video file selected by the user.
let fdPath = 'fd://'
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd success fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}).catch((err) => {
   console.info('open fd failed err is' + err);
});
audioPlayer.src = fdPath;  // Set the src attribute and trigger the 'dataLoad' event callback.
```

### on('timeUpdate')

on(type: 'timeUpdate', callback: Callback\<number>): void

Subscribes to the 'timeUpdate' event.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type             | Mandatory| Description                                                        |
| -------- | ----------------- | ---- | ------------------------------------------------------------ |
| type     | string            | Yes  | Event type, which is 'timeUpdate' in this case.<br>The 'timeUpdate' event is triggered when the [seek()](#audioplayer_seek) API is called.|
| callback | Callback\<number> | Yes  | Callback invoked when the event is triggered. The input parameter of the callback is the time when the seek operation is successful.            |

**Example**

```js
audioPlayer.on('timeUpdate', (seekDoneTime) => {    // Set the 'timeUpdate' event callback.
    if (typeof (seekDoneTime) == 'undefined') {
        console.info('audio seek fail');
        return;
    }
    console.log('audio seek success. seekDoneTime: ' + seekDoneTime);
});
audioPlayer.seek(30000); // Seek to 30000 ms.
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to the audio playback error event.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is 'error' in this case.<br>The 'error' event is triggered when an error occurs during audio playback.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
audioPlayer.on('error', (error) => {      // Set the error event callback.
    console.info(`audio error called, errName is ${error.name}`);      // Print the error name.
    console.info(`audio error called, errCode is ${error.code}`);      // Print the error code.
    console.info(`audio error called, errMessage is ${error.message}`);// Print the detailed description of the error type.
});
audioPlayer.setVolume(3); // Set volume to an invalid value to trigger the 'error' event.
```

## AudioState

Enumerates the audio playback states. You can obtain the state through the **state** attribute.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name              | Type  | Description          |
| ------------------ | ------ | -------------- |
| idle               | string | The audio player is idle.|
| playing            | string | Audio playback is in progress.|
| paused             | string | Audio playback is paused.|
| stopped            | string | Audio playback is stopped.|
| error<sup>8+</sup> | string | Audio playback is in the error state.    |

## VideoPlayer<sup>8+</sup>

Provides APIs to manage and play video. Before calling an API of **VideoPlayer**, you must call [createVideoPlayer()](#mediacreatevideoplayer8) to create a [VideoPlayer](#videoplayer8) instance.

For details about the video playback demo, see [Video Playback Development](../../media/video-playback.md).

### Attributes<a name=videoplayer_attributes></a>

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                    | Type                              | Readable| Writable| Description                                                        |
| ------------------------ | ---------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>         | string                             | Yes  | Yes  | Video media URL. The mainstream video formats (MPEG-4, MPEG-TS, WebM, and MKV) are supported.<br>**Example of supported URIs**:<br>1. FD playback: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP network playback: http://xx<br>3. HLS network playback: under development<br>**Note**:<br>To use media materials, you must declare the read permission. Otherwise, the media materials cannot be played properly. |
| loop<sup>8+</sup>        | boolean                            | Yes  | Yes  | Whether to loop video playback. The value **true** means to loop video playback, and **false** means the opposite.                |
| currentTime<sup>8+</sup> | number                             | Yes  | No  | Current video playback position.                                        |
| duration<sup>8+</sup>    | number                             | Yes  | No  | Video duration. The value **-1** indicates the live streaming mode.                              |
| state<sup>8+</sup>       | [VideoPlayState](#videoplaystate8) | Yes  | No  | Video playback state.                                            |
| width<sup>8+</sup>       | number                             | Yes  | No  | Video width.                                                    |
| height<sup>8+</sup>      | number                             | Yes  | No  | Video height.                                                    |

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

Sets **SurfaceId**. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name   | Type    | Mandatory| Description                     |
| --------- | -------- | ---- | ------------------------- |
| surfaceId | string   | Yes  | Surface ID to set.                |
| callback  | function | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.setDisplaySurface(surfaceId, (err) => {
    if (typeof (err) == 'undefined') {
        console.info('setDisplaySurface success!');
    } else {
        console.info('setDisplaySurface fail!');
    }
});
```

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

Sets **SurfaceId**. This API uses a promise to return the result.

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
videoPlayer.setDisplaySurface(surfaceId).then(() => {
    console.info('setDisplaySurface success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});
```

### prepare<sup>8+</sup>

prepare(callback: AsyncCallback\<void>): void

Prepares for video playback. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                    |
| -------- | -------- | ---- | ------------------------ |
| callback | function | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.prepare((err) => {
    if (typeof (err) == 'undefined') {
        console.info('prepare success!');
    } else {
        console.info('prepare fail!');
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
   console.info(`video catchCallback, error:${error.message}`);
});
```

### play<sup>8+</sup>

play(callback: AsyncCallback\<void>): void;

Starts to play video resources. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                    |
| -------- | -------- | ---- | ------------------------ |
| callback | function | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.play((err) => {
    if (typeof (err) == 'undefined') {
        console.info('play success!');
    } else {
        console.info('play fail!');
    }
});
```

### play<sup>8+</sup>

play(): Promise\<void>;

Starts to play video resources. This API uses a promise to return the result.

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
   console.info(`video catchCallback, error:${error.message}`);
});
```

### pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses video playback. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                    |
| -------- | -------- | ---- | ------------------------ |
| callback | function | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.pause((err) => {
    if (typeof (err) == 'undefined') {
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
   console.info(`video catchCallback, error:${error.message}`);
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

Stops video playback. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                    |
| -------- | -------- | ---- | ------------------------ |
| callback | function | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.stop((err) => {
    if (typeof (err) == 'undefined') {
        console.info('stop success!');
    } else {
        console.info('stop fail!');
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
   console.info(`video catchCallback, error:${error.message}`);
});
```

### reset<sup>8+</sup>

reset(callback: AsyncCallback\<void>): void

Switches the video resource to be played. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                    |
| -------- | -------- | ---- | ------------------------ |
| callback | function | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.reset((err) => {
    if (typeof (err) == 'undefined') {
        console.info('reset success!');
    } else {
        console.info('reset fail!');
    }
});
```

### reset<sup>8+</sup>

reset(): Promise\<void>

Switches the video resource to be played. This API uses a promise to return the result.

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
   console.info(`video catchCallback, error:${error.message}`);
});
```

### seek<sup>8+</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. The next key frame at the specified position is played. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                |
| -------- | -------- | ---- | ------------------------------------ |
| timeMs   | number   | Yes  | Position to seek to, in milliseconds.|
| callback | function | Yes  | Callback used to return the result.      |

**Example**

```js
videoPlayer.seek((seekTime, err) => {
    if (typeof (err) == 'undefined') {
        console.info('seek success!');
    } else {
        console.info('seek fail!');
    }
});
```

### seek<sup>8+</sup>

seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                  | Mandatory| Description                                |
| -------- | ---------------------- | ---- | ------------------------------------ |
| timeMs   | number                 | Yes  | Position to seek to, in milliseconds.|
| mode     | [SeekMode](#seekmode8) | Yes  | Seek mode.                          |
| callback | function               | Yes  | Callback used to return the result.      |

**Example**

```js
videoPlayer.seek((seekTime, seekMode, err) => {
    if (typeof (err) == 'undefined') {
        console.info('seek success!');
    } else {
        console.info('seek fail!');
    }
});
```

### seek<sup>8+</sup>

seek(timeMs: number, mode?:SeekMode): Promise\<number>

Seeks to the specified playback position. If **mode** is not specified, the next key frame at the specified position is played. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name| Type                  | Mandatory| Description                                |
| ------ | ---------------------- | ---- | ------------------------------------ |
| timeMs | number                 | Yes  | Position to seek to, in milliseconds.|
| mode   | [SeekMode](#seekmode8) | No  | Seek mode.                          |

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.seek(seekTime).then((seekDoneTime) => { // seekDoneTime indicates the position after the seek operation is complete.
    console.info('seek success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});

videoPlayer.seek(seekTime, seekMode).then((seekDoneTime) => {
    console.info('seek success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});
```

### setVolume<sup>8+</sup>

setVolume(vol: number, callback: AsyncCallback\<void>): void

Sets the volume. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| vol      | number   | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1** indicates the maximum volume (100%).|
| callback | function | Yes  | Callback used to return the result.                                        |

**Example**

```js
videoPlayer.setVolume((vol, err) => {
    if (typeof (err) == 'undefined') {
        console.info('setVolume success!');
    } else {
        console.info('setVolume fail!');
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
| vol    | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1** indicates the maximum volume (100%).|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.setVolume(vol).then() => {
    console.info('setVolume success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

Releases the video playback resource. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                    |
| -------- | -------- | ---- | ------------------------ |
| callback | function | Yes  | Callback used to return the result.|

**Example**

```js
videoPlayer.release((err) => {
    if (typeof (err) == 'undefined') {
        console.info('release success!');
    } else {
        console.info('release fail!');
    }
});
```

### release<sup>8+</sup>

release(): Promise\<void>

Releases the video playback resource. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
videoPlayer.release().then() => {
    console.info('release success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(callback: AsyncCallback<Array\<MediaDescription>>): void

Obtains the video track information. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                      |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return the video track information obtained.|

**Example**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('video key is ' + item);
        console.info('video value is ' + property);
    }
}

videoPlayer.getTrackDescription((error, arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        for (let i = 0; i < arrlist.length; i++) {
            printfDescription(arrlist[i]);
        }
    } else {
        console.log(`video getTrackDescription fail, error:${error.message}`);
    }
});
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(): Promise<Array\<MediaDescription>>

Obtains the video track information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                                  | Description                           |
| ------------------------------------------------------ | ------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | Promise used to return the video track information obtained.|

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
videoPlayer.getTrackDescription().then((arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        arrayDescription = arrlist;
    } else {
        console.log('video getTrackDescription fail');
    }
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});
for (let i = 0; i < arrayDescription.length; i++) {
    printfDescription(arrayDescription[i]);
}
```

### setSpeed<sup>8+</sup>

setSpeed(speed:number, callback: AsyncCallback\<number>): void

Sets the video playback speed. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                      |
| -------- | -------- | ---- | ---------------------------------------------------------- |
| speed    | number   | Yes  | Video playback speed. For details, see [PlaybackSpeed](#playbackspeed8).|
| callback | function | Yes  | Callback used to return the result.                                  |

**Example**

```js
videoPlayer.setSpeed((speed:number, err) => {
    if (typeof (err) == 'undefined') {
        console.info('setSpeed success!');
    } else {
        console.info('setSpeed fail!');
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

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise\<number> | Promise used to return the result.|

**Example**

```js
videoPlayer.setSpeed(speed).then() => {
    console.info('setSpeed success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error.message}`);
});
```

### on('playbackCompleted')<sup>8+</sup>

on(type: 'playbackCompleted', callback: Callback\<void>): void

Subscribes to the video playback completion event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| type     | string   | Yes  | Event type, which is 'playbackCompleted' in this case.|
| callback | function | Yes  | Callback invoked when the event is triggered.                                 |

**Example**

```js
videoPlayer.on('playbackCompleted', () => {
    console.info('playbackCompleted success!');
});
```

### on('bufferingUpdate')<sup>8+</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to the video buffering update event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is 'bufferingUpdate' in this case.       |
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
| type     | string          | Yes  | Event type, which is 'startRenderFrame' in this case.|
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
| type     | string   | Yes  | Event type, which is 'videoSizeChanged' in this case.|
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

Subscribes to the video playback error event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is 'error' in this case.<br>The 'error' event is triggered when an error occurs during video playback.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
videoPlayer.on('error', (error) => {      // Set the 'error' event callback.
    console.info(`video error called, errName is ${error.name}`);      // Print the error name.
    console.info(`video error called, errCode is ${error.code}`);      // Print the error code.
    console.info(`video error called, errMessage is ${error.message}`);// Print the detailed description of the error type.
});
videoPlayer.setVolume(3);  // Set volume to an invalid value to trigger the 'error' event.
```

## VideoPlayState<sup>8+</sup>

Enumerates the video playback states. You can obtain the state through the **state** attribute.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name    | Type  | Description          |
| -------- | ------ | -------------- |
| idle     | string | The video player is idle.|
| prepared | string | Video playback is being prepared.|
| playing  | string | Video playback is in progress.|
| paused   | string | Video playback is paused.|
| stopped  | string | Video playback is stopped.|
| error    | string | Video playback is in the error state.    |

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

## MediaDescription<sup>8+</sup>

### [key : string] : Object

Defines media information in key-value mode.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name | Type  | Description                                                        |
| ----- | ------ | ------------------------------------------------------------ |
| key   | string | Key of the media information. For details about the keys, see [MediaDescriptionKey](#mediadescriptionkey8).|
| value | any    | Value of the key. For details about the values, see [MediaDescriptionKey](#mediadescriptionkey8).|

**Example**

```js
function printfItemDescription(obj, key) {
    let property = obj[key];
    console.info('audio key is ' + key);
    console.info('audio value is ' + property);
}

audioPlayer.getTrackDescription((error, arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        for (let i = 0; i < arrlist.length; i++) {
            printfItemDescription(arrlist[i], MD_KEY_TRACK_TYPE);  // Print the MD_KEY_TRACK_TYPE value of each track.
        }
    } else {
        console.log(`audio getTrackDescription fail, error:${error.message}`);
    }
});
```

## AudioRecorder

Implements audio recording. Before calling an API of **AudioRecorder**, you must call [createAudioRecorder()](#mediacreateaudiorecorder) to create an [AudioRecorder](#audiorecorder) instance.

For details about the audio recording demo, see [Audio Recording Development](../../media/audio-recorder.md).

### prepare<a name=audiorecorder_prepare></a>

prepare(config: AudioRecorderConfig): void

Prepares for recording.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfig) | Yes  | Audio recording parameters, including the audio output URI, encoding format, sampling rate, number of audio channels, and output format.|

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

Releases the audio recording resource.

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
| type     | string   | Yes  | Event type. The following events are supported: 'prepare'\|'start'\|  'pause' \| 'resume' \|'stop'\|'release'\|'reset'<br>- The 'prepare' event is triggered when the [prepare](#audiorecorder_prepare) API is called and the audio recording parameters are set.<br>- The 'start' event is triggered when the [start](#audiorecorder_start) API is called and audio recording starts.<br>- The 'pause' event is triggered when the [pause](#audiorecorder_pause) API is called and audio recording is paused.<br>- The 'resume' event is triggered when the [resume](#audiorecorder_resume) API is called and audio recording is resumed.<br>- The 'stop' event is triggered when the [stop](#audiorecorder_stop) API is called and audio recording stops.<br>- The 'release' event is triggered when the [release](#audiorecorder_release) API is called and the recording resource is released.<br>- The 'reset' event is triggered when the [reset](#audiorecorder_reset) API is called and audio recording is reset.|
| callback | ()=>void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```js
let audiorecorder = media.createAudioRecorder();                                  // Create an AudioRecorder instance.
let audioRecorderConfig = {
    audioEncoder : media.AudioEncoder.AAC_LC, ,
    audioEncodeBitRate : 22050,
    audioSampleRate : 22050,
    numberOfChannels : 2,
    format : media.AudioOutputFormat.AAC_ADTS,
    uri : 'fd://xx',                                                            // The file must be created by the caller and granted with proper permissions.
    location : { latitude : 30, longitude : 130},
}
audioRecorder.on('error', (error) => {                                             // Set the error event callback.
    console.info(`audio error called, errName is ${error.name}`);
    console.info(`audio error called, errCode is ${error.code}`);
    console.info(`audio error called, errMessage is ${error.message}`);
});
audioRecorder.on('prepare', () => {                                              // Set the prepare event callback.
    console.log('prepare success');
    audioRecorder.start();                                                       // Start recording and trigger the start event callback.
});
audioRecorder.on('start', () => {                                                 // Set the start event callback.
    console.log('audio recorder start success');
});
audioRecorder.on('pause', () => {                                                 // Set the pause event callback.
    console.log('audio recorder pause success');
});
audioRecorder.on('resume', () => {                                                 // Set the resume event callback.
    console.log('audio recorder resume success');
});
audioRecorder.on('stop', () => {                                                 // Set the stop event callback.
    console.log('audio recorder stop success');
});
audioRecorder.on('release', () => {                                                 // Set the release event callback.
    console.log('audio recorder release success');
});
audioRecorder.on('reset', () => {                                                 // Set the reset event callback.
    console.log('audio recorder reset success');
});
audioRecorder.prepare(audioRecorderConfig)                                       // Set recording parameters and trigger the prepare event callback.
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to the audio recording error event.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is 'error' in this case.<br>The 'error' event is triggered when an error occurs during audio recording.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
audioRecorder.on('error', (error) => {                                  // Set the error event callback.
    console.info(`audio error called, errName is ${error.name}`);       // Print the error name.
    console.info(`audio error called, errCode is ${error.code}`);       // Print the error code.
    console.info(`audio error called, errMessage is ${error.message}`); // Print the detailed description of the error type.
});
audioRecorder.prepare();                                                  // Do no set any parameter in prepare and trigger the error event callback.
```

## AudioRecorderConfig

Describes audio recording configurations.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name                 | Type                               | Mandatory| Description                                                        |
| --------------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| audioEncoder<sup>(deprecated)</sup>          | [AudioEncoder](#audioencoder)           | No  | Audio encoding format. The default value is **AAC_LC**.<br>**Note**: This parameter is deprecated since API version 8. Use **audioEncoderMime** instead.                            |
| audioEncodeBitRate    | number                                  | No  | Audio encoding bit rate. The default value is **48000**.                             |
| audioSampleRate       | number                                  | No  | Audio sampling rate. The default value is **48000**.                             |
| numberOfChannels      | number                                  | No  | Number of audio channels. The default value is **2**.                                 |
| format<sup>(deprecated)</sup>                | [AudioOutputFormat](#audiooutputformat) | No  | Audio output format. The default value is **MPEG_4**.<br>**Note**: This parameter is deprecated since API version 8. Use **fileFormat** instead.                        |
| location              | [Location](#location)                   | No  | Geographical location of the recorded audio.                                        |
| uri                   | string                                  | Yes  | Audio output URI. Supported: fd://xx (fd number)<br>![](figures/en-us_image_url.png) <br>The file must be created by the caller and granted with proper permissions.|
| audioEncoderMime<sup>8+</sup>      | [CodecMimeType](#codecmimetype8)        | No  | Audio encoding format.          |
| fileFormat<sup>8+</sup>      | [ContainerFormatType](#containerformattype8)        | No  | Audio encoding format.        |


## AudioEncoder<sup>(deprecated)</sup>

> **NOTE**
> This API is deprecated since API version 8. You are advised to use [CodecMimeType](#codecmimetype8) instead.

Enumerates the audio encoding formats.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name   | Default Value| Description                                                        |
| ------- | ------ | ------------------------------------------------------------ |
| DEFAULT | 0      | Default encoding format.<br>This API is defined but not implemented yet.|
| AMR_NB  | 1      | AMR-NB.<br>This API is defined but not implemented yet.|
| AMR_WB  | 2      | Adaptive Multi Rate-Wide Band Speech Codec (AMR-WB).<br>This API is defined but not implemented yet.|
| AAC_LC  | 3      | Advanced Audio Coding Low Complexity (AAC-LC).|
| HE_AAC  | 4      | High-Efficiency Advanced Audio Coding (HE_AAC).<br>This API is defined but not implemented yet.|


## AudioOutputFormat<sup>(deprecated)</sup>

> **NOTE**
> This API is deprecated since API version 8. You are advised to use [ContainerFormatType](#containerformattype8) instead.

Enumerates the audio output formats.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name    | Default Value| Description                                                        |
| -------- | ------ | ------------------------------------------------------------ |
| DEFAULT  | 0      | Default encapsulation format.<br>This API is defined but not implemented yet.|
| MPEG_4   | 2      | MPEG-4.                                          |
| AMR_NB   | 3      | AMR_NB.<br>This API is defined but not implemented yet.|
| AMR_WB   | 4      | AMR_WB.<br>This API is defined but not implemented yet.|
| AAC_ADTS | 6      | Audio Data Transport Stream (ADTS), which is a transport stream format of AAC-based audio.|


## ContainerFormatType<sup>8+</sup>

Enumerates the container format types (CFTs).

**System capability**: SystemCapability.Multimedia.Media.Core

| Name       | Value   | Description                 |
| ----------- | ----- | --------------------- |
| CFT_MPEG_4  | "mp4" | Video container format MPEG-4.|
| CFT_MPEG_4A | "m4a" | Audio container format M4A.|

## Location

Describes the geographical location of the recorded video.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name     | Type| Mandatory| Description            |
| --------- | -------- | ---- | ---------------- |
| latitude  | number   | Yes  | Latitude of the geographical location.|
| longitude | number   | Yes  | Longitude of the geographical location.|
