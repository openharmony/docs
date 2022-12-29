# Media

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The multimedia subsystem provides a set of simple and easy-to-use APIs for you to access the system and use media resources.

This subsystem offers various media services covering audio and video, which provide the following capabilities:

- Audio playback ([AudioPlayer](#audioplayer))
- Video playback ([VideoPlayer](#videoplayer8))
- Audio recording ([AudioRecorder](#audiorecorder))
- Video recording ([VideoRecorder](#videorecorder9))

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

Creates a **VideoPlayer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                       | Mandatory| Description                          |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[VideoPlayer](#videoplayer8)> | Yes  | Callback used to return the result. If the operation is successful, the **VideoPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to manage and play video.|

**Example**

```js
let videoPlayer

media.createVideoPlayer((error, video) => {
   if (video != null) {
       videoPlayer = video;
       console.info('video createVideoPlayer success');
   } else {
       console.info(`video createVideoPlayer fail, error:${error}`);
   }
});
```

## media.createVideoPlayer<sup>8+</sup>

createVideoPlayer(): Promise<[VideoPlayer](#videoplayer8)>

Creates a **VideoPlayer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                 | Description                                                        |
| ------------------------------------- | ------------------------------------------------------------ |
| Promise<[VideoPlayer](#videoplayer8)> | Promise used to return the result. If the operation is successful, the **VideoPlayer** instance is returned; otherwise, **null** is returned. The instance can be used to manage and play video.|

**Example**

```js
let videoPlayer

media.createVideoPlayer().then((video) => {
   if (video != null) {
       videoPlayer = video;
       console.info('video createVideoPlayer success');
   } else {
       console.info('video createVideoPlayer fail');
   }
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

## media.createAudioRecorder

createAudioRecorder(): AudioRecorder

Creates an **AudioRecorder** instance to control audio recording.
Only one **AudioRecorder** instance can be created per device.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| [AudioRecorder](#audiorecorder) | Returns the **AudioRecorder** instance if the operation is successful; returns **null** otherwise. The instance can be used to record audio.|

**Example**

```js
let audioRecorder = media.createAudioRecorder();
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(callback: AsyncCallback\<[VideoRecorder](#videorecorder9)>): void

Creates a **VideoRecorder** instance. This API uses an asynchronous callback to return the result.
Only one **AudioRecorder** instance can be created per device.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[VideoRecorder](#videorecorder9)> | Yes  | Callback used to return the result. If the operation is successful, the **VideoRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**Example**

```js
let videoRecorder

media.createVideoRecorder((error, video) => {
   if (video != null) {
       videoRecorder = video;
       console.info('video createVideoRecorder success');
   } else {
       console.info(`video createVideoRecorder fail, error:${error}`);
   }
});
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(): Promise<[VideoRecorder](#videorecorder9)>

Creates a **VideoRecorder** instance. This API uses a promise to return the result.
Only one **AudioRecorder** instance can be created per device.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

**Return value**

| Type                                     | Description                                                        |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[VideoRecorder](#videorecorder9)> | Promise used to return the result. If the operation is successful, the **VideoRecorder** instance is returned; otherwise, **null** is returned. The instance can be used to record video.|

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                     |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**Example**

```js
let videoRecorder

media.createVideoRecorder().then((video) => {
    if (video != null) {
       videoRecorder = video;
       console.info('video createVideoRecorder success');
   } else {
       console.info('video createVideoRecorder fail');
   }
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
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

## AudioPlayer

Provides APIs to manage and play audio. Before calling an API of **AudioPlayer**, you must use [createAudioPlayer()](#mediacreateaudioplayer) to create an **AudioPlayer** instance.

For details about the audio playback demo, see [Audio Playback Development](../../media/audio-playback.md).

### Attributes<a name=audioplayer_attributes></a>

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name                           | Type                                                  | Readable| Writable| Description                                                        |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| src                             | string                                                 | Yes  | Yes  | Audio file URI. The mainstream audio formats (M4A, AAC, MPEG-3, OGG, and WAV) are supported.<br>**Examples of supported URI schemes**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http://xx<br>3. HTTPS: https://xx<br>4. HLS: http://xx or https://xx<br>**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.INTERNET|
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | Yes  | Yes  | Description of the audio file. This attribute is required when audio resources of an application are continuously stored in a file.<br>**Example:**<br>Assume that a music file that stores continuous music resources consists of the following:<br>Music 1 (address offset: 0, byte length: 100)<br>Music 2 (address offset: 101; byte length: 50)<br>Music 3 (address offset: 151, byte length: 150)<br>1. To play music 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play music 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play music 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent music file, use **src=fd://xx**.<br>|
| loop                            | boolean                                                | Yes  | Yes  | Whether to loop audio playback. The value **true** means to loop audio playback, and **false** means the opposite.                |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](js-apis-audio.md#interruptmode9) | Yes  | Yes  | Audio interruption mode.                                              |
| currentTime                     | number                                                 | Yes  | No  | Current audio playback position, in ms.                      |
| duration                        | number                                                 | Yes  | No  | Audio duration, in ms.                                |
| state                           | [AudioState](#audiostate)                              | Yes  | No  | Audio playback state. This state cannot be used as the condition for triggering the call of **play()**, **pause()**, or **stop()**.|
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

Obtains the audio track information. This API uses an asynchronous callback to return the result. It can be called only after the [dataLoad](#audioplayer_on) event is triggered.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the audio track information.|

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

getTrackDescription(): Promise<Array\<MediaDescription>>

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

on(type: 'bufferingUpdate', callback: (infoType: [BufferingInfoType](#bufferinginfotype8), value: number) => void): void

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
import fileio from '@ohos.fileio'

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
    console.info(`audio error called, error: ${error}`);
});

// Set the FD (local playback) of the video file selected by the user.
let fdPath = 'fd://';
// The stream in the path can be pushed to the device by running the "hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" command.
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
fileio.open(path).then((fdValue) => {
   fdPath = fdPath + '' + fdValue;
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
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>The **'error'** event is triggered when an error occurs during audio playback.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
audioPlayer.on('error', (error) => {      // Set the 'error' event callback.
    console.info(`audio error called, error: ${error}`); 
});
audioPlayer.setVolume(3); // Set volume to an invalid value to trigger the 'error' event.
```

## AudioState

Enumerates the audio playback states. You can obtain the state through the **state** attribute.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name   | Type  | Description                                          |
| ------- | ------ | ---------------------------------------------- |
| idle    | string |  No audio playback is in progress. The audio player is in this state after the **'dataload'** or **'reset'** event is triggered.|
| playing | string | Audio playback is in progress. The audio player is in this state after the **'play'** event is triggered.          |
| paused  | string | Audio playback is paused. The audio player is in this state after the **'pause'** event is triggered.         |
| stopped | string | Audio playback is stopped. The audio player is in this state after the **'stop'** event is triggered.     |
| error   | string | Audio playback is in the error state.                                    |

## AVFileDescriptor<sup>9+</sup>

Describes audio and video file resources. It is used to specify a particular resource for playback based on its offset and length within a file.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | Yes  | Resource handle, which is obtained by calling **resourceManager.getRawFileDescriptor**.      |
| offset | number | Yes  | Resource offset, which needs to be entered based on the preset resource information. An invalid value causes a failure to parse audio and video resources.|
| length | number | Yes  | Resource length, which needs to be entered based on the preset resource information. An invalid value causes a failure to parse audio and video resources.|

## VideoPlayer<sup>8+</sup>

Provides APIs to manage and play video. Before calling an API of **VideoPlayer**, you must use [createVideoPlayer()](#mediacreatevideoplayer8) to create a [VideoPlayer](#videoplayer8) instance.

For details about the video playback demo, see [Video Playback Development](../../media/video-playback.md).

### Attributes<a name=videoplayer_attributes></a>

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                    | Type                              | Readable| Writable| Description                                                        |
| ------------------------ | ---------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>         | string                             | Yes  | Yes  | Video URL. The mainstream video formats (MPEG-4, MPEG-TS, WebM, and MKV) are supported.<br>**Example of supported URIs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http://xx<br>3. HTTPS: https://xx<br>4. HLS: http://xx or https://xx<br>|
| fdSrc<sup>9+</sup> | [AVFileDescriptor](#avfiledescriptor9) | Yes| Yes| Description of a video file. This attribute is required when video resources of an application are continuously stored in a file.<br>**Example:**<br>Assume that a music file that stores continuous music resources consists of the following:<br>Video 1 (address offset: 0, byte length: 100)<br>Video 2 (address offset: 101; byte length: 50)<br>Video 3 (address offset: 151, byte length: 150)<br>1. To play video 1: AVFileDescriptor {fd = resource handle; offset = 0; length = 100; }<br>2. To play video 2: AVFileDescriptor {fd = resource handle; offset = 101; length = 50; }<br>3. To play video 3: AVFileDescriptor {fd = resource handle; offset = 151; length = 150; }<br>To play an independent video file, use **src=fd://xx**.<br>|
| loop<sup>8+</sup>        | boolean                            | Yes  | Yes  | Whether to loop video playback. The value **true** means to loop video playback, and **false** means the opposite.                |
| videoScaleType<sup>9+</sup>        | [VideoScaleType](#videoscaletype9)                   | Yes  | Yes  | Video scale type.      |
| audioInterruptMode<sup>9+</sup>        | [audio.InterruptMode](js-apis-audio.md#interruptmode9)  | Yes  | Yes  | Audio interruption mode.      |
| currentTime<sup>8+</sup> | number                             | Yes  | No  | Current video playback position, in ms.                      |
| duration<sup>8+</sup>    | number                             | Yes  | No  | Video duration, in ms. The value **-1** indicates the live mode.            |
| state<sup>8+</sup>       | [VideoPlayState](#videoplaystate8) | Yes  | No  | Video playback state.                                            |
| width<sup>8+</sup>       | number                             | Yes  | No  | Video width, in pixels.                                  |
| height<sup>8+</sup>      | number                             | Yes  | No  | Video height, in pixels.                                  |

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

Sets **SurfaceId**. This API uses an asynchronous callback to return the result.

*Note: **SetDisplaySurface** must be called between the URL setting and the calling of **prepare**. A surface must be set for video streams without audio. Otherwise, the calling of **prepare** fails.

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
        console.info('setDisplaySurface fail!');
    }
});
```

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

Sets **SurfaceId**. This API uses a promise to return the result.

*Note: **SetDisplaySurface** must be called between the URL setting and the calling of **prepare**. A surface must be set for video streams without audio. Otherwise, the calling of **prepare** fails.

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
   console.info(`video catchCallback, error:${error}`);
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
   console.info(`video catchCallback, error:${error}`);
});
```

### play<sup>8+</sup>

play(callback: AsyncCallback\<void>): void;

Starts to play video resources. This API uses an asynchronous callback to return the result.

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
   console.info(`video catchCallback, error:${error}`);
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
   console.info(`video catchCallback, error:${error}`);
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
   console.info(`video catchCallback, error:${error}`);
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
        console.info('reset fail!');
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
   console.info(`video catchCallback, error:${error}`);
});
```

### seek<sup>8+</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. The next key frame at the specified position is played. This API uses an asynchronous callback to return the result.

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
        console.info('seek fail!');
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
        console.info('seek fail!');
    }
});
```

### seek<sup>8+</sup>

seek(timeMs: number, mode?:SeekMode): Promise\<number>

Seeks to the specified playback position. If **mode** is not specified, the next key frame at the specified position is played. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name| Type                  | Mandatory| Description                                                        |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | Yes  | Position to seek to, in ms. The value range is [0, duration].|
| mode   | [SeekMode](#seekmode8) | No  | Seek mode.                                                  |

**Return value**

| Type          | Description                                       |
| -------------- | ------------------------------------------- |
| Promise\<number>| Promise used to return the playback position, in ms.|

**Example**

```js
import media from '@ohos.multimedia.media'
let seekTime = 5000;
videoPlayer.seek(seekTime).then((seekDoneTime) => { // seekDoneTime indicates the position after the seek operation is complete.
    console.info('seek success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});

videoPlayer.seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC).then((seekDoneTime) => {
    console.info('seek success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### setVolume<sup>8+</sup>

setVolume(vol: number, callback: AsyncCallback\<void>): void

Sets the volume. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| vol      | number               | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1** indicates the maximum volume (100%).|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                                        |

**Example**

```js
let vol = 0.5;
videoPlayer.setVolume(vol, (err, result) => {
    if (err == null) {
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
let vol = 0.5;
videoPlayer.setVolume(vol).then(() => {
    console.info('setVolume success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

Releases the video playback resource. This API uses an asynchronous callback to return the result.

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
videoPlayer.release().then(() => {
    console.info('release success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(callback: AsyncCallback<Array\<MediaDescription>>): void

Obtains the video track information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | Yes  | Callback used to return a **MediaDescription** array, which records the video track information.|

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

getTrackDescription(): Promise<Array\<MediaDescription>>

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
   console.info(`video catchCallback, error:${error}`);
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
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>The **'error'** event is triggered when an error occurs during video playback.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
videoPlayer.on('error', (error) => {      // Set the 'error' event callback.
    console.info(`video error called, error: ${error}`);
});
videoPlayer.url = 'fd://error';  // Set an incorrect URL to trigger the 'error' event.
```

### on('availableBitratesCollect')<sup>9+</sup>

on(type: 'availableBitratesCollect', callback: (bitrates: Array\<number>) => void): void

Subscribes to the video playback bit rate reporting event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'availableBitratesCollect'** in this case. This event is reported only once when the playback starts.|
| callback | function | Yes  | Callback used to return supported bit rates, in an array.          |

**Example**

```js
videoPlayer.on('availableBitratesCollect', (bitrates) => {
    for (let i = 0; i < bitrates.length; i++) {
        console.info('case availableBitratesCollect bitrates: '  + bitrates[i]);  // Print bit rates.
    }
});
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

## VideoScaleType<sup>9+</sup>

Enumerates the video scale modes.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

| Name                        | Value| Description    |
| ---------------------------- | ------ | ---------- |
| VIDEO_SCALE_TYPE_FIT     | 0      | The video will be stretched to fit the window.|
| VIDEO_SCALE_TYPE_FIT_CROP| 1      | The video will be stretched to fit the window, without changing its aspect ratio. The content may be cropped.    |

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

## AudioRecorder

Implements audio recording. Before calling an API of **AudioRecorder**, you must use [createAudioRecorder()](#mediacreateaudiorecorder) to create an [AudioRecorder](#audiorecorder) instance.

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
| type     | string   | Yes  | Event type. The following events are supported:<br>- 'prepare': triggered when the [prepare](#audiorecorder_prepare) API is called and the audio recording parameters are set.<br>- 'start': triggered when the [start](#audiorecorder_start) API is called and audio recording starts.<br>- 'pause': triggered when the [pause](#audiorecorder_pause) API is called and audio recording is paused.<br>- 'resume': triggered when the [resume](#audiorecorder_resume) API is called and audio recording is resumed.<br>- 'stop': triggered when the [stop](#audiorecorder_stop) API is called and audio recording stops.<br>- 'release': triggered when the [release](#audiorecorder_release) API is called and the recording resource is released.<br>- 'reset': triggered when the [reset](#audiorecorder_reset) API is called and audio recording is reset.|
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
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>The **'error'** event is triggered when an error occurs during audio recording.|
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
    console.info(`audio error called, error: ${error}`); 
});
audioRecorder.prepare(audioRecorderConfig);                            // Do no set any parameter in prepare and trigger the 'error' event callback.
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

| Name   | Value  | Description                                                        |
| ------- | ---- | ------------------------------------------------------------ |
| DEFAULT | 0    | Default encoding format.<br>This API is defined but not implemented yet.             |
| AMR_NB  | 1    | AMR-NB.<br>This API is defined but not implemented yet.|
| AMR_WB  | 2    | Adaptive Multi Rate-Wide Band Speech Codec (AMR-WB).<br>This API is defined but not implemented yet.|
| AAC_LC  | 3    | Advanced Audio Coding Low Complexity (AAC-LC).|
| HE_AAC  | 4    | High-Efficiency Advanced Audio Coding (HE_AAC).<br>This API is defined but not implemented yet.|


## AudioOutputFormat<sup>(deprecated)</sup>

> **NOTE**
> This API is deprecated since API version 8. You are advised to use [ContainerFormatType](#containerformattype8) instead.

Enumerates the audio output formats.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

| Name    | Value  | Description                                                        |
| -------- | ---- | ------------------------------------------------------------ |
| DEFAULT  | 0    | Default encapsulation format.<br>This API is defined but not implemented yet.             |
| MPEG_4   | 2    | MPEG-4.                                          |
| AMR_NB   | 3    | AMR_NB.<br>This API is defined but not implemented yet.         |
| AMR_WB   | 4    | AMR_WB.<br>This API is defined but not implemented yet.         |
| AAC_ADTS | 6    | Audio Data Transport Stream (ADTS), which is a transport stream format of AAC-based audio.|

## VideoRecorder<sup>9+</sup>

Implements video recording. Before calling an API of the **VideoRecorder** class, you must call [createVideoRecorder()](#mediacreatevideorecorder9) to create a [VideoRecorder](#videorecorder9) instance.

For details about the video recording demo, see [Video Recording Development](../../media/video-recorder.md).

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

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission denied. Return by callback.  |
| 401      | Parameter error. Return by callback.    |
| 5400102  | Operate not permit. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
let videoProfile = {
    audioBitrate : 48000,
    audioChannels : 2,
    audioCodec : 'audio/mp4a-latm',
    audioSampleRate : 48000,
    fileFormat : 'mp4',
    videoBitrate : 48000,
    videoCodec : 'video/mp4v-es',
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
        console.info('prepare failed and error is ' + err.message);
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

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 201      | Permission denied. Return by promise.  |
| 401      | Parameter error. Return by promise.    |
| 5400102  | Operate not permit. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
let videoProfile = {
    audioBitrate : 48000,
    audioChannels : 2,
    audioCodec : 'audio/mp4a-latm',
    audioSampleRate : 48000,
    fileFormat : 'mp4',
    videoBitrate : 48000,
    videoCodec : 'video/mp4v-es',
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
    console.info('prepare failed and catch error is ' + err.message);
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(callback: AsyncCallback\<string>): void;

Obtains the surface required for recording in asynchronous mode. This surface is provided for the caller. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp is based on the system startup time.

This API can be called only after [prepare()](#videorecorder_prepare1) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

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
// asyncallback
let surfaceID = null;                                               // Surface ID passed to the external system.
videoRecorder.getInputSurface((err, surfaceId) => {
    if (err == null) {
        console.info('getInputSurface success');
        surfaceID = surfaceId;
    } else {
        console.info('getInputSurface failed and error is ' + err.message);
    }
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(): Promise\<string>;

 Obtains the surface required for recording in asynchronous mode. This surface is provided for the caller. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp is based on the system startup time.

This API can be called only after [prepare()](#videorecorder_prepare1) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

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
// promise
let surfaceID = null;                                               // Surface ID passed to the external system.
videoRecorder.getInputSurface().then((surfaceId) => {
    console.info('getInputSurface success');
    surfaceID = surfaceId;
}).catch((err) => {
    console.info('getInputSurface failed and catch error is ' + err.message);
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

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
// asyncallback
videoRecorder.start((err) => {
    if (err == null) {
        console.info('start videorecorder success');
    } else {
        console.info('start videorecorder failed and error is ' + err.message);
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

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
// promise
videoRecorder.start().then(() => {
    console.info('start videorecorder success');
}).catch((err) => {
    console.info('start videorecorder failed and catch error is ' + err.message);
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

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
// asyncallback
videoRecorder.pause((err) => {
    if (err == null) {
        console.info('pause videorecorder success');
    } else {
        console.info('pause videorecorder failed and error is ' + err.message);
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

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
// promise
videoRecorder.pause().then(() => {
    console.info('pause videorecorder success');
}).catch((err) => {
    console.info('pause videorecorder failed and catch error is ' + err.message);
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

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
// asyncallback
videoRecorder.resume((err) => {
    if (err == null) {
        console.info('resume videorecorder success');
    } else {
        console.info('resume videorecorder failed and error is ' + err.message);
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

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
// promise
videoRecorder.resume().then(() => {
    console.info('resume videorecorder success');
}).catch((err) => {
    console.info('resume videorecorder failed and catch error is ' + err.message);
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

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**Example**

```js
// asyncallback
videoRecorder.stop((err) => {
    if (err == null) {
        console.info('stop videorecorder success');
    } else {
        console.info('stop videorecorder failed and error is ' + err.message);
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

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**Example**

```js
// promise
videoRecorder.stop().then(() => {
    console.info('stop videorecorder success');
}).catch((err) => {
    console.info('stop videorecorder failed and catch error is ' + err.message);
});
```

### release<sup>9+</sup><a name=videorecorder_release1></a>

release(callback: AsyncCallback\<void>): void;

Releases the video recording resource. This API uses an asynchronous callback to return the result.

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
        console.info('release videorecorder failed and error is ' + err.message);
    }
});
```

### release<sup>9+</sup><a name=videorecorder_release2></a>

release(): Promise\<void>;

Releases the video recording resource. This API uses a promise to return the result.

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
    console.info('release videorecorder failed and catch error is ' + err.message);
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
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**Example**

```js
// asyncallback
videoRecorder.reset((err) => {
    if (err == null) {
        console.info('reset videorecorder success');
    } else {
        console.info('reset videorecorder failed and error is ' + err.message);
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
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**Example**

```js
// promise
videoRecorder.reset().then(() => {
    console.info('reset videorecorder success');
}).catch((err) => {
    console.info('reset videorecorder failed and catch error is ' + err.message);
});
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to video recording error events. After an error event is reported, you must handle the event and exit the recording.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Event type, which is **'error'** in this case.<br>The **'error'** event is triggered when an error occurs during video recording.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Error codes**

For details about the error codes, see [Media Error Codes](../errorcodes/errorcode-media.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**Example**

```js
// This event is reported when an error occurs during the retrieval of videoRecordState.
videoRecorder.on('error', (error) => {                                  // Set the 'error' event callback.
    console.info(`audio error called, error: ${error}`); 
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
| rotation        | number                                         | No  | Rotation angle of the recorded video.                                        |
| location        | [Location](#location)                          | No  | Geographical location of the recorded video.                                        |
| url             | string                                         | Yes  | Video output URL. Supported: fd://xx (fd number)<br>![](figures/en-us_image_url.png) |

## AudioSourceType<sup>9+</sup>

Enumerates the audio source types for video recording.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name                     | Value  | Description                  |
| ------------------------- | ---- | ---------------------- |
| AUDIO_SOURCE_TYPE_DEFAULT | 0    | Default audio input source.|
| AUDIO_SOURCE_TYPE_MIC     | 1    | Mic audio input source. |

## VideoSourceType<sup>9+</sup>

Enumerates the video source types for video recording.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**System API**: This is a system API.

| Name                         | Value  | Description                           |
| ----------------------------- | ---- | ------------------------------- |
| VIDEO_SOURCE_TYPE_SURFACE_YUV | 0    | The input surface carries raw data.|
| VIDEO_SOURCE_TYPE_SURFACE_ES  | 1    | The input surface carries ES data. |

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

## ContainerFormatType<sup>8+</sup>

Enumerates the container format types (CFTs).

**System capability**: SystemCapability.Multimedia.Media.Core

| Name       | Value   | Description                 |
| ----------- | ----- | --------------------- |
| CFT_MPEG_4  | 'mp4' | Video container format MPEG-4.|
| CFT_MPEG_4A | 'm4a' | Audio container format M4A.|

## Location

Describes the geographical location of the recorded video.

**System capability**: SystemCapability.Multimedia.Media.Core

| Name     | Type  | Mandatory| Description            |
| --------- | ------ | ---- | ---------------- |
| latitude  | number | Yes  | Latitude of the geographical location.|
| longitude | number | Yes  | Longitude of the geographical location.|
