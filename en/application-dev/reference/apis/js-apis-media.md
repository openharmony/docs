# Media

> **NOTE**
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The multimedia subsystem provides a set of simple and easy-to-use APIs for you to access the system and use media resources.

This subsystem offers various media services covering audio and video, which provide the following capabilities:

- Audio playback ([AudioPlayer](#audioplayer))
- Video playback ([VideoPlayer](#videoplayer8))
- Audio recording ([AudioRecorder](#audiorecorder))
- Video recording ([VideoRecorder](#VideoRecorder<sup>8+</sup>))

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

createVideoPlayer: Promise<[VideoPlayer](#videoplayer8)>

Creates a **VideoPlayer** instance in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                 | Description                               |
| ------------------------------------- | ----------------------------------- |
| Promise<[VideoPlayer](#videoplayer8)> | Promise used to return the **VideoPlayer** instance created.|

**Example**

```js
let videoPlayer

function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}

await media.createVideoPlayer.then((video) => {
    if (typeof(video) != 'undefined') {
       videoPlayer = video;
       console.info('video createVideoPlayer success');
   } else {
       console.info('video createVideoPlayer fail');
   }
}, failureCallback).catch(catchCallback);
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
let audiorecorder = media.createAudioRecorder(); 
```

## media.createVideoRecorder<sup>8+</sup>

createVideoRecorder(callback: AsyncCallback\<[VideoRecorder](#videorecorder8)>): void

Creates a **VideoRecorder** instance in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                                           | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[VideoRecorder](#videorecorder8)> | Yes  | Callback used to return the **VideoRecorder** instance created.|

**Example**

```js
let videoRecorder

media.createVideoRecorder((error, video) => {
   if (typeof(video) != 'undefined') {
       videoRecorder = video;
       console.info('video createVideoRecorder success');
   } else {
       console.info(`video createVideoRecorder fail, error:${error.message}`);
   }
});
```

## media.createVideoRecorder<sup>8+</sup>

createVideoRecorder: Promise<[VideoRecorder](#videorecorder8)>

Creates a **VideoRecorder** instance in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type                                     | Description                               |
| ----------------------------------------- | ----------------------------------- |
| Promise<[VideoRecorder](#videorecorder8)> | Promise used to return the **VideoRecorder** instance created.|

**Example**

```js
let videoRecorder

function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}

await media.createVideoRecorder.then((video) => {
    if (typeof(video) != 'undefined') {
       videoRecorder = video;
       console.info('video createVideoRecorder success');
   } else {
       console.info('video createVideoRecorder fail');
   }
}, failureCallback).catch(catchCallback);
```



## MediaErrorCode<sup>8+</sup>

Enumerates the media error codes.

| Name                      | Value  | Description                                                        |
| -------------------------- | ---- | ------------------------------------------------------------ |
| MSERR_OK                   | 0    | The operation is successful.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_NO_MEMORY            | 1    | Failed to allocate memory. The system may have no available memory.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_OPERATION_NOT_PERMIT | 2    | No permission to perform this operation.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_INVALID_VAL          | 3    | Invalid input parameter.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_IO                   | 4    | An I/O error occurs.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_TIMEOUT              | 5    | The operation times out.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_UNKNOWN              | 6    | An unknown error occurs.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_SERVICE_DIED         | 7    | Invalid server.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_INVALID_STATE        | 8    | The operation is not allowed in the current state.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MSERR_UNSUPPORTED          | 9    | The operation is not supported in the current version.<br>**System capability**: SystemCapability.Multimedia.Media.Core|

## MediaType<sup>8+</sup>

Enumerates the media types.

| Name          | Value  | Description                                                        |
| -------------- | ---- | ------------------------------------------------------------ |
| MEDIA_TYPE_AUD | 0    | Media.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MEDIA_TYPE_VID | 1    | Video.<br>**System capability**: SystemCapability.Multimedia.Media.Core|

## CodecMimeType<sup>8+</sup>

Enumerates the codec MIME types.

| Name        | Value               | Description                                                        |
| ------------ | ----------------- | ------------------------------------------------------------ |
| VIDEO_MPEG4  | "video/mp4v-es"  | Video in MPEG-4 format.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| AUDIO_AAC    | "audio/mp4a-latm" | Audio in MP4A-LATM format.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| AUDIO_VORBIS | "audio/vorbis"    | Audio in Vorbis format.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| AUDIO_FLAC   | "audio/flac"      | Audio in FLAC format.<br>**System capability**: SystemCapability.Multimedia.Media.Core|

## MediaDescriptionKey<sup>8+</sup>

Enumerates the media description keys.

| Name                    | Value             | Description                                                        |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | "track_index"   | Track index, which is a number.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_TRACK_TYPE        | "track_type"    | Track type, which is a number. For details, see [MediaType](#mediatype8).<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_CODEC_MIME        | "codec_mime"    | Codec MIME type, which is a string.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_DURATION          | "duration"      | Media duration, which is a number, in units of ms.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_BITRATE           | "bitrate"       | Bit rate, which is a number, in units of bit/s.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_WIDTH             | "width"         | Video width, which is a number, in units of pixel.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_HEIGHT            | "height"        | Video height, which is a number, in units of pixel.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_FRAME_RATE        | "frame_rate"    | Video frame rate, which is a number, in units of 100 fps.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_AUD_CHANNEL_COUNT | "channel_count" | Number of audio channels, which is a number.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| MD_KEY_AUD_SAMPLE_RATE   | "sample_rate"   | Sampling rate, which is a number, in units of Hz.<br>**System capability**: SystemCapability.Multimedia.Media.Core|

## BufferingInfoType<sup>8+</sup>

Enumerates the buffering event types.

| Name             | Value  | Description                                                        |
| ----------------- | ---- | ------------------------------------------------------------ |
| BUFFERING_START   | 1    | Buffering starts.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| BUFFERING_END     | 2    | Buffering ends.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| BUFFERING_PERCENT | 3    | Buffering progress, in percent.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| CACHED_DURATION   | 4    | Cache duration, in milliseconds.<br>**System capability**: SystemCapability.Multimedia.Media.Core|

## AudioPlayer

Provides methods to manage and play audio. Before calling a method of **AudioPlayer**, you must use [createAudioPlayer()](#mediacreateaudioplayer) to create an **AudioPlayer** instance.

For details about the audio playback demo, see [Audio Playback Development](../../media/audio-playback.md).

### Attributes<a name=audioplayer_Attributes></a>

| Name       | Type                     | Readable| Writable| Description                                                        |
| ----------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| src         | string                    | Yes  | Yes  | Audio media URI. The mainstream audio formats (MP4, AAC, MP3, and OGG) are supported.<br>**Example of supported URIs**:<br>1. FD playback: fd://xxx<br>![en-us_image_0000001164217678](figures/en-us_image_url.png)<br>2. HTTP network playback path (under development)<br>3. HLS network playback path (under development)<br>**Note**:<br>To use media materials, you must declare the read permission. Otherwise, the media materials cannot be played properly.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| loop        | boolean                   | Yes  | Yes  | Whether to loop audio playback. The value **true** means to loop audio playback, and **false** means the opposite.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| currentTime | number                    | Yes  | No  | Current audio playback position.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| duration    | number                    | Yes  | No  | Audio duration.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| state       | [AudioState](#audiostate) | Yes  | No  | Audio playback state.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|

### play<a name=audioplayer_play></a>

play(): void

Starts to play audio resources. This method can be called only after the [dataLoad](#on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')) event is triggered.

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

| Name| Type  | Mandatory| Description                          |
| ------ | ------ | ---- | ------------------------------ |
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

getTrackDescription(callback: AsyncCallback<Array<[MediaDescription](#mediadescription8)>>): void

Obtains the audio track information. This API uses a callback to return the result.

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

getTrackDescription(): Promise<Array<[MediaDescription](#mediadescription8)>>

Obtains the audio track information. This API uses a promise to return the result.

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
function failureCallback(error) {
    console.info(`audio failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`audio catchCallback, error:${error.message}`);
}

await audioPlayer.getTrackDescription.then((arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        arrayDescription = arrlist;
    } else {
        console.log('audio getTrackDescription fail');
    }
}, failureCallback).catch(catchCallback);
for (let i = 0; i < arrayDescription.length; i++) {
    printfDescription(arrayDescription[i]);
}
```

### on('bufferingUpdate')<sup>8+</sup>

on(type: 'bufferingUpdate', callback: (infoType: [BufferingInfoType](#bufferinginfotype8), value: number) => void): void

Subscribes to the audio buffering update event.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Type of the event to subscribe to, which is 'bufferingUpdate' in this example.       |
| callback | (infoType: [BufferingInfoType](#bufferinginfotype8), value: number) => void | Yes  | Callback invoked when the event is triggered.<br>When [BufferingInfoType](#bufferinginfotype8) is set to **BUFFERING_PERCENT** or **CACHED_DURATION**, **value** is valid. Otherwise, **value** is fixed at **0**.|

**Example**

```js
audioPlayer.on('bufferingUpdate', (infoType, value) => {
    console.log('audio bufferingInfo type: ' + infoType);
    console.log('audio bufferingInfo value: ' + value);
});
```

 ### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void): void

Subscribes to the audio playback events.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type      | Mandatory| Description                                                        |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | Yes  | Type of the event to subscribe to. The following events are supported: 'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange'<br>- The 'play' event is triggered when the [play()](#play) method is called and audio playback starts.<br>- The 'pause' event is triggered when the [pause()](#pause) method is called and audio playback is paused.<br>- The 'stop' event is triggered when the [stop()](#stop) method is called and audio playback stops.<br>- The 'reset' event is triggered when the [reset()](#reset7) method is called and audio playback is reset.<br>- The 'dataLoad' event is triggered when the audio data is loaded, that is, when the **src** attribute is configured.<br>- The 'finish' event is triggered when the audio playback is finished.<br>- The 'volumeChange' event is triggered when the [setVolume()](#setvolume) method is called and the playback volume is changed.|
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
    audioPlayer.seek(30000);                  // Call the seek() method and trigger the 'timeUpdate' event callback.
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
let path = 'data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
await fileIO.open(path).then(fdNumber) => {
   fdPath = fdPath + '' + fdNumber;
   console.info('open fd sucess fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}),catch((err) => {
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
| type     | string            | Yes  | Type of the event to subscribe to, which is 'timeUpdate' in this method.<br>The 'timeUpdate' event is triggered when the [seek()](#seek) method is called.|
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
| type     | string        | Yes  | Type of the event to subscribe to, which is 'error' in this method.<br>The 'error' event is triggered when an error occurs during audio playback.|
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

| Name              | Type  | Description                                                        |
| ------------------ | ------ | ------------------------------------------------------------ |
| idle               | string | The audio player is idle.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| playing            | string | Audio playback is in progress.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| paused             | string | Audio playback is paused.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| stopped            | string | Audio playback is stopped.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|
| error<sup>8+</sup> | string | Audio playback is in the error state.<br>**System capability**: SystemCapability.Multimedia.Media.AudioPlayer|

## VideoPlayer<sup>8+</sup>

Provides methods to manage and play video. Before calling a method of the **VideoPlayer** class, you must call [createVideoPlayer()](#media.createvideoplayer8) to create a [VideoPlayer](#videoplayer8) instance.

For details about the video playback demo, see [Video Playback Development](../../media/video-playback.md).

### Attributes<a name=videoplayer_attributes></a>

| Name                    | Type                              | Readable| Writable| Description                                                        |
| ------------------------ | ---------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>         | string                             | Yes  | Yes  | Video media URL. The mainstream video formats (MPEG-4, MPEG-TS, WebM, and MKV) are supported.<br>**Example of supported URIs**:<br>1. FD playback: fd://xxx<br>![en-us_image_0000001164217678](figures/en-us_image_url.png)<br>**Note**:<br>To use media materials, you must declare the read permission. Otherwise, the media materials cannot be played properly.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| loop<sup>8+</sup>        | boolean                            | Yes  | Yes  | Whether to loop video playback. The value **true** means to loop video playback, and **false** means the opposite.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| currentTime<sup>8+</sup> | number                             | Yes  | No  | Current video playback position.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| duration<sup>8+</sup>    | number                             | Yes  | No  | Video duration. The value **-1** indicates the live streaming mode.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| state<sup>8+</sup>       | [VideoPlayState](#videoplaystate8) | Yes  | No  | Video playback state.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| width<sup>8+</sup>       | number                             | Yes  | No  | Video width.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| height<sup>8+</sup>      | number                             | Yes  | No  | Video height.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

Sets **SurfaceId**. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name   | Type    | Mandatory| Description                     |
| --------- | -------- | ---- | ------------------------- |
| surfaceId | string   | Yes  | Surface ID to set.                |
| callback  | function | Yes  | Callback used to set **SurfaceId**.|

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

| Type         | Description                          |
| ------------- | ------------------------------ |
| Promise<void> | Promise used to set **SurfaceId**.|

**Example**

```js
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.setDisplaySurface(surfaceId).then(() => {
    console.info('setDisplaySurface success');
}, failureCallback).catch(catchCallback);
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
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.prepare().then(() => {
    console.info('prepare success');
}, failureCallback).catch(catchCallback);
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
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.play().then(() => {
    console.info('play success');
}, failureCallback).catch(catchCallback);
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
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.pause().then(() => {
    console.info('pause success');
}, failureCallback).catch(catchCallback);
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
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.stop().then(() => {
    console.info('stop success');
}, failureCallback).catch(catchCallback);
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
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.reset().then(() => {
    console.info('reset success');
}, failureCallback).catch(catchCallback);
```

### seek<sup>8+</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

Seeks to the specified playback position. The next key frame at the specified position is played. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                          |
| -------- | -------- | ---- | ------------------------------ |
| timeMs   | number   | Yes  | Position to seek to, in milliseconds.|
| callback | function | Yes  | Callback used to return the result.|

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

| Name  | Type    | Mandatory| Description                                    |
| -------- | -------- | ---- | ---------------------------------------- |
| timeMs   | number   | Yes  | Position to seek to, in milliseconds.          |
| mode     | SeekMode | Yes  | Seek mode. For details, see [SeekMode](#seekmode8).|
| callback | function | Yes  | Callback used to return the result.          |

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

| Name| Type    | Mandatory| Description                                  |
| ------ | -------- | ---- | -------------------------------------- |
| timeMs | number   | Yes  | Position to seek to, in milliseconds.        |
| mode   | SeekMode | No  | Seek mode. For details, see [SeekMode](#seekmode8).|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.seek(seekTime).then((seekDoneTime) => { // seekDoneTime indicates the position after the seek operation is complete.
    console.info('seek success');
}, failureCallback).catch(catchCallback);

await videoPlayer.seek(seekTime, seekMode).then((seekDoneTime) => {
    console.info('seek success');
}, failureCallback).catch(catchCallback);
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
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.setVolume(vol).then() => {
    console.info('setVolume success');
}, failureCallback).catch(catchCallback);
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
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.release().then() => {
    console.info('release success');
}, failureCallback).catch(catchCallback);
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(callback: AsyncCallback<Array<[MediaDescription](#mediadescription8>>)>>): void

Obtains the video track information. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                      |
| -------- | -------- | ---- | -------------------------- |
| callback | function | Yes  | Callback used to return the video track information obtained.|

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

getTrackDescription(): Promise<Array<[MediaDescription](#mediadescription8>>)>>

Obtains the video track information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Return value**

| Type                                                    | Description                           |
| -------------------------------------------------------- | ------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8>>)>> | Promise used to return the video track information obtained.|

**Example**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('video key is ' + item);
        console.info('video value is ' + property);
    }
}
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}

let arrayDescription;
await videoPlayer.getTrackDescription().then((arrlist) => {
    if (typeof (arrlist) != 'undefined') {
        arrayDescription = arrlist;
    } else {
        console.log('video getTrackDescription fail');
    }
}, failureCallback).catch(catchCallback);
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

**Example**

```js
function failureCallback(error) {
    console.info(`video failureCallback, error:${error.message}`);
}
function catchCallback(error) {
    console.info(`video catchCallback, error:${error.message}`);
}
await videoPlayer.setSpeed(speed).then() => {
    console.info('setSpeed success');
}, failureCallback).catch(catchCallback);
```

### on('playbackCompleted')<sup>8+</sup>

on(type: 'playbackCompleted', callback: Callback\<void>): void

Subscribes to the video playback completion event.

**System capability**: SystemCapability.Multimedia.Media.VideoPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| type     | string   | Yes  | Type of the event to subscribe to, which is 'playbackCompleted' in this example.|
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
| type     | string   | Yes  | Type of the event to subscribe to, which is 'bufferingUpdate' in this example.       |
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

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Type of the event to subscribe to, which is 'startRenderFrame' in this example.|
| callback | function | Yes  | Callback invoked when the event is triggered.                          |

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
| type     | string   | Yes  | Type of the event to subscribe to, which is 'videoSizeChanged' in this example.|
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

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Type of the event to subscribe to, which is 'error' in this method.<br>The 'error' event is triggered when an error occurs during video playback.|
| callback | function | Yes  | Callback invoked when the event is triggered.                                      |

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

| Name    | Type  | Description                                                        |
| -------- | ------ | ------------------------------------------------------------ |
| idle     | string | The video player is idle.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| prepared | string | Video playback is being prepared.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| playing  | string | Video playback is in progress.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| paused   | string | Video playback is paused.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| stopped  | string | Video playback is stopped.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| error    | string | Video playback is in the error state.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|

## SeekMode<sup>8+</sup>

Enumerates the video playback seek modes, which can be passed in the **seek** method.

| Name          | Value  | Description                                                        |
| -------------- | ---- | ------------------------------------------------------------ |
| SEEK_NEXT_SYNC | 0    | Seeks to the next key frame at the specified position. You are advised to use this value for the rewind operation.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| SEEK_PREV_SYNC | 1    | Seeks to the previous key frame at the specified position. You are advised to use this value for the fast-forward operation.<br>**System capability**: SystemCapability.Multimedia.Media.Core|

## PlaybackSpeed<sup>8+</sup>

Enumerates the video playback speeds, which can be passed in the **setSpeed** method.

| Name                | Value  | Description                                                        |
| -------------------- | ---- | ------------------------------------------------------------ |
| SPEED_FORWARD_0_75_X | 0    | Plays the video at 0.75 times the normal speed.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| SPEED_FORWARD_1_00_X | 1    | Plays the video at the normal speed.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| SPEED_FORWARD_1_25_X | 2    | Plays the video at 1.25 times the normal speed.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| SPEED_FORWARD_1_75_X | 3    | Plays the video at 1.75 times the normal speed.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|
| SPEED_FORWARD_2_00_X | 4    | Plays the video at 2.00 times the normal speed.<br>**System capability**: SystemCapability.Multimedia.Media.VideoPlayer|

## MediaDescription<sup>8+</sup>

### [key : string] : any

Defines media information in key-value mode.

| Name | Type  | Description                                                        |
| ----- | ------ | ------------------------------------------------------------ |
| key   | string | Key of the media information. For details about the keys, see [MediaDescriptionKey](#mediadescriptionkey8).<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| value | any    | Value of the key. For details about the values, see [MediaDescriptionKey](#mediadescriptionkey8).<br>**System capability**: SystemCapability.Multimedia.Media.Core|

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

Implements audio recording. Before calling a method of the **AudioRecorder** class, you must call [createAudioRecorder()](#media.createaudiorecorder) to create an [AudioRecorder](#audiorecorder) instance.

For details about the audio recording demo, see [Audio Recording Development](../../media/audio-recorder.md).

### prepare<a name=audiorecorder_prepare></a>

prepare(config: AudioRecorderConfig): void

Prepares for recording.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfig) | Yes  | Audio recording parameters, including the audio output URI, [encoding format](#audioencoder), sampling rate, number of audio channels, and [output format](#audiooutputformat).|

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

Starts audio recording. This method can be called only after the [prepare](#audiorecorder_on) event is triggered.

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

Pauses audio recording. This method can be called only after the [start](#audiorecorder_on) event is triggered.

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

Resumes audio recording. This method can be called only after the [pause](#audiorecorder_on) event is triggered.

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
| type     | string   | Yes  | Type of the event to subscribe to. The following events are supported: 'prepare'\|'start'\|  'pause' \| 'resume' \|'stop'\|'release'\|'reset'<br>- The 'prepare' event is triggered when the [prepare](#audiorecorder_prepare) method is called and the audio recording parameters are set.<br>- The 'start' event is triggered when the [start](#audiorecorder_start) method is called and audio recording starts.<br>- The 'pause' event is triggered when the [pause](#audiorecorder_pause) method is called and audio recording is paused.<br>- The 'resume' event is triggered when the [resume](#audiorecorder_resume) method is called and audio recording is resumed.<br>- The 'stop' event is triggered when the [stop](#audiorecorder_stop) method is called and audio recording stops.<br>- The 'release' event is triggered when the [release](#audiorecorder_release) method is called and the recording resource is released.<br>- The 'reset' event is triggered when the [reset](#audiorecorder_reset) method is called and audio recording is reset.|
| callback | ()=>void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```js
let audiorecorder = media.createAudioRecorder();  								// Create an AudioRecorder instance.
let audioRecorderConfig = {
    audioEncoder : media.AudioEncoder.AAC_LC, ,
    audioEncodeBitRate : 22050,
    audioSampleRate : 22050,
    numberOfChannels : 2,
    format : media.AudioOutputFormat.AAC_ADTS,
    uri : 'fd://xx',                                                            // The file must be created by the caller and granted with proper permissions.
    location : { latitude : 30, longitude : 130},
}
audioRecorder.on('error', (error) => {             								// Set the 'error' event callback.
	console.info(`audio error called, errName is ${error.name}`);
    console.info(`audio error called, errCode is ${error.code}`);
    console.info(`audio error called, errMessage is ${error.message}`);
});
audioRecorder.on('prepare', () => {              								// Set the 'prepare' event callback.
    console.log('prepare success');
    audioRecorder.start();                       								// Start recording and trigger the 'start' event callback.
});
audioRecorder.on('start', () => {    		     								// Set the 'start' event callback.
    console.log('audio recorder start success');
});
audioRecorder.on('pause', () => {    		     								// Set the 'pause' event callback.
    console.log('audio recorder pause success');
});
audioRecorder.on('resume', () => {    		     								// Set the 'resume' event callback.
    console.log('audio recorder resume success');
});
audioRecorder.on('stop', () => {    		     								// Set the 'stop' event callback.
    console.log('audio recorder stop success');
});
audioRecorder.on('release', () => {    		     								// Set the 'release' event callback.
    console.log('audio recorder release success');
});
audioRecorder.on('reset', () => {    		     								// Set the 'reset' event callback.
    console.log('audio recorder reset success');
});
audioRecorder.prepare(audioRecorderConfig)       								// Set recording parameters and trigger the 'prepare' event callback.
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Subscribes to the audio recording error event.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to, which is 'error' in this method.<br>The 'error' event is triggered when an error occurs during audio recording.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
audioRecorder.on('error', (error) => {      							// Set the 'error' event callback.
	console.info(`audio error called, errName is ${error.name}`);       // Print the error name.
    console.info(`audio error called, errCode is ${error.code}`);       // Print the error code.
    console.info(`audio error called, errMessage is ${error.message}`); // Print the detailed description of the error type.
});
audioRecorder.prepare();  												// Do no set any parameter in prepare and trigger the 'error' event callback.
```

## AudioRecorderConfig

Describes audio recording configurations.

| Name                 | Type                               | Mandatory| Description                                                        |
| --------------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| audioEncoder          | [AudioEncoder](#audioencoder)           | No  | Audio encoding format. The default value is **AAC_LC**.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| audioEncodeBitRate    | number                                  | No  | Audio encoding bit rate. The default value is **48000**.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| audioSampleRate       | number                                  | No  | Audio sampling rate. The default value is **48000**.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| numberOfChannels      | number                                  | No  | Number of audio channels. The default value is **2**.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| format                | [AudioOutputFormat](#audiooutputformat) | No  | Audio output format. The default value is **MPEG_4**.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| location<sup>8+</sup> | [Location](#location8)                  | No  | Geographical location of the recorded audio.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| uri                   | string                                  | Yes  | Audio output URI. Supported: fd://xx&nbsp;(fd&nbsp;number)<br>![en-us_image_0000001164217678](figures/en-us_image_url.png) <br>The file must be created by the caller and granted with proper permissions.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|


## AudioEncoder

Enumerates the audio encoding formats.

| Name   | Default Value| Description                                                        |
| ------- | ------ | ------------------------------------------------------------ |
| DEFAULT | 0      | Default audio encoding format, which is Adaptive Multi Rate-Narrow Band Speech Codec (AMR-NB).<br>This API is merely defined in OpenHarmony 3.1 Release and cannot be used currently. It can be used in OpenHarmony 3.1 MR.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| AMR_NB  | 1      | AMR-NB.<br>This API is merely defined in OpenHarmony 3.1 Release and cannot be used currently. It can be used in OpenHarmony 3.1 MR.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| AMR_WB  | 2      | Adaptive Multi Rate-Wide Band Speech Codec (AMR-WB).<br>This API is merely defined in OpenHarmony 3.1 Release and cannot be used currently. It can be used in OpenHarmony 3.1 MR.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| AAC_LC  | 3      | Advanced Audio Coding Low Complexity (AAC-LC).<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| HE_AAC  | 4      | High-Efficiency Advanced&nbsp;Audio&nbsp;Coding (HE_AAC).<br>This API is merely defined in OpenHarmony 3.1 Release and cannot be used currently. It can be used in OpenHarmony 3.1 MR.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|


## AudioOutputFormat

Enumerates the audio output formats.

| Name    | Default Value| Description                                                        |
| -------- | ------ | ------------------------------------------------------------ |
| DEFAULT  | 0      | Default encapsulation format, which is MPEG-4.<br>This API is merely defined in OpenHarmony 3.1 Release and cannot be used currently. It can be used in OpenHarmony 3.1 MR.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| MPEG_4   | 2      | MPEG-4.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| AMR_NB   | 3      | AMR_NB.<br>This API is merely defined in OpenHarmony 3.1 Release and cannot be used currently. It can be used in OpenHarmony 3.1 MR.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| AMR_WB   | 4      | AMR_WB.<br>This API is merely defined in OpenHarmony 3.1 Release and cannot be used currently. It can be used in OpenHarmony 3.1 MR.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|
| AAC_ADTS | 6      | Audio Data Transport Stream (ADTS), which is a transport stream format of AAC-based audio.<br>**System capability**: SystemCapability.Multimedia.Media.AudioRecorder|

## VideoRecorder<sup>8+</sup>

Implements video recording. Before calling a method of the **VideoRecorder** class, you must call [createVideoRecorder()](#media.createvideorecorder8) to create a [VideoRecorder](#videorecorder8) instance.

For details about the video recording demo, see [Video Recording Development](../../media/video-recorder.md).

### Attributes

| Name              | Type                                 | Readable| Writable| Description            |
| ------------------ | ------------------------------------- | ---- | ---- | ---------------- |
| state<sup>8+</sup> | [VideoRecordState](#videorecordstate) | Yes  | No  | Video recording state.|

### prepare<sup>8+</sup><a name=videorecorder_prepare1></a>

prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void;

Sets video recording parameters in asynchronous mode. This API uses a callback to return the result.

**Required permissions:** ohos.permission.MICROPHONE ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                                       | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| config   | [VideoRecorderConfig](#videorecorderconfig) | Yes  | Video recording parameters to set.           |
| callback | AsyncCallback\<void>                        | Yes  | Callback used to return the result.|

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
let videoRecorder = null;
let events = require('events');
let eventEmitter = new events.EventEmitter();                              

eventEmitter.on('prepare', () => {
    videoRecorder.prepare(videoConfig, (err) => {
        if (typeof (err) == 'undefined') {
            console.info('prepare success');
        } else {
            console.info('prepare failed and error is ' + err.message);
        }
    });
});

media.createVideoRecorder((err, recorder) => {
    if (typeof (err) == 'undefined' && typeof (recorder) != 'undefined') {
        videoRecorder = recorder;
        console.info('createVideoRecorder success');
        eventEmitter.emit('prepare');                                        // Trigger the 'prepare' event.
    } else {
        console.info('createVideoRecorder failed and error is ' + err.message);
    }
});
```

### prepare<sup>8+</sup><a name=videorecorder_prepare2></a>

prepare(config: VideoRecorderConfig): Promise\<void>;

Sets video recording parameters in asynchronous mode. This API uses a promise to return the result.

**Required permissions:** ohos.permission.MICROPHONE ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name| Type                                       | Mandatory| Description                    |
| ------ | ------------------------------------------- | ---- | ------------------------ |
| config | [VideoRecorderConfig](#videorecorderconfig) | Yes  | Video recording parameters to set.|

**Return value**

| Type          | Description                                    |
| -------------- | ---------------------------------------- |
| Promise\<void> | Promise used to return the result.|

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
let videoRecorder = null;
await media.createVideoRecorder().then((recorder) => {
    if (typeof (recorder) != 'undefined') {
        videoRecorder = recorder;
        console.info('createVideoRecorder success');
    } else {
        console.info('createVideoRecorder failed');
    }
}, (err) => {
    console.info('error hanppend message is ' + err.message);
}).catch((err) => {
    console.info('catch err error message is ' + err.message);
});

await videoRecorder.prepare(videoConfig).then(() => {
    console.info('prepare success');
}, (err) => {
    console.info('prepare failed and error is ' + err.message);
}).catch((err) => {
    console.info('prepare failed and catch error is ' + err.message);
});
```

### getInputSurface<sup>8+</sup>

getInputSurface(callback: AsyncCallback\<string>): void;

Obtains the surface required for recording in asynchronous mode. This surface is provided for the caller. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp is based on the system startup time.

This method can be called only after [prepare()](#videorecorder_prepare1) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                  | Mandatory| Description                       |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to obtain the result.|

**Example**

```js
// asyncallback
let surfaceID = null;   											// Surface ID passed to the external system.
videoRecorder.getInputSurface((err, surfaceId) => {
    if (typeof (err) == 'undefined') {
        console.info('getInputSurface success');
        surfaceID = surfaceId;
    } else {
        console.info('getInputSurface failed and error is ' + err.message);
    }
});
```

### getInputSurface<sup>8+</sup>

getInputSurface(): Promise\<string>;

 Obtains the surface required for recording in asynchronous mode. This surface is provided for the caller. The caller obtains the **surfaceBuffer** from this surface and fills in the corresponding data.

Note that the video data must carry the timestamp (in ns) and buffer size, and the start time of the timestamp is based on the system startup time.

This method can be called only after [prepare()](#videorecorder_prepare1) is called.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type            | Description                            |
| ---------------- | -------------------------------- |
| Promise\<string> | Promise used to return the result.|

**Example**

```js
// promise
let surfaceID = null;   											// Surface ID passed to the external system.
await videoRecorder.getInputSurface().then((surfaceId) => {
    console.info('getInputSurface success');
    surfaceID = surfaceId;
}, (err) => {
    console.info('getInputSurface failed and error is ' + err.message);
}).catch((err) => {
    console.info('getInputSurface failed and catch error is ' + err.message);
});
```

### start<sup>8+</sup><a name=videorecorder_start1></a>

start(callback: AsyncCallback\<void>): void;

Starts video recording in asynchronous mode. This API uses a callback to return the result.

This method can be called only after [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface8) are called, because the data source must pass data to the surface first.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
// asyncallback
videoRecorder.start((err) => {
    if (typeof (err) == 'undefined') {
        console.info('start videorecorder success');
    } else {
        console.info('start videorecorder failed and error is ' + err.message);
    }
});
```

### start<sup>8+</sup><a name=videorecorder_start2></a>

start(): Promise\<void>;

Starts video recording in asynchronous mode. This API uses a promise to return the result.

This method can be called only after [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface8) are called, because the data source must pass data to the surface first.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
// promise
await videoRecorder.start().then(() => {
    console.info('start videorecorder success');
}, (err) => {
    console.info('start videorecorder failed and error is ' + err.message);
}).catch((err) => {
    console.info('start videorecorder failed and catch error is ' + err.message);
});
```

### pause<sup>8+</sup><a name=videorecorder_pause1></a>

pause(callback: AsyncCallback\<void>): void;

Pauses video recording in asynchronous mode. This API uses a callback to return the result.

This method can be called only after [start()](#videorecorder_start1) is called. You can resume recording by calling [resume()](#videorecorder_resume1).

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
// asyncallback
videoRecorder.pause((err) => {
    if (typeof (err) == 'undefined') {
        console.info('pause videorecorder success');
    } else {
        console.info('pause videorecorder failed and error is ' + err.message);
    }
});
```

### pause<sup>8+</sup><a name=videorecorder_pause2></a>

pause(): Promise\<void>;

Pauses video recording in asynchronous mode. This API uses a promise to return the result.

This method can be called only after [start()](#videorecorder_start1) is called. You can resume recording by calling [resume()](#videorecorder_resume1).

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
// promise
await videoRecorder.pause().then(() => {
    console.info('pause videorecorder success');
}, (err) => {
    console.info('pause videorecorder failed and error is ' + err.message);
}).catch((err) => {
    console.info('pause videorecorder failed and catch error is ' + err.message);
});
```

### resume<sup>8+</sup><a name=videorecorder_resume1></a>

resume(callback: AsyncCallback\<void>): void;

Resumes video recording in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
// asyncallback
videoRecorder.resume((err) => {
    if (typeof (err) == 'undefined') {
        console.info('resume videorecorder success');
    } else {
        console.info('resume videorecorder failed and error is ' + err.message);
    }
});
```

### resume<sup>8+</sup><a name=videorecorder_resume2></a>

resume(): Promise\<void>;

Resumes video recording in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
// promise
await videoRecorder.resume().then(() => {
    console.info('resume videorecorder success');
}, (err) => {
    console.info('resume videorecorder failed and error is ' + err.message);
}).catch((err) => {
    console.info('resume videorecorder failed and catch error is ' + err.message);
});
```

### stop<sup>8+</sup><a name=videorecorder_stop1></a>

stop(callback: AsyncCallback\<void>): void;

Stops video recording in asynchronous mode. This API uses a callback to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface8) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
// asyncallback
videoRecorder.stop((err) => {
    if (typeof (err) == 'undefined') {
        console.info('stop videorecorder success');
    } else {
        console.info('stop videorecorder failed and error is ' + err.message);
    }
});
```

### stop<sup>8+</sup><a name=videorecorder_stop2></a>

stop(): Promise\<void>;

Stops video recording in asynchronous mode. This API uses a promise to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface8) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
// promise
await videoRecorder.stop().then(() => {
    console.info('stop videorecorder success');
}, (err) => {
    console.info('stop videorecorder failed and error is ' + err.message);
}).catch((err) => {
    console.info('stop videorecorder failed and catch error is ' + err.message);
});
```

### release<sup>8+</sup><a name=videorecorder_release1></a>

release(callback: AsyncCallback\<void>): void;

Releases the video recording resource in asynchronous mode. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                            |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
// asyncallback
videoRecorder.release((err) => {
    if (typeof (err) == 'undefined') {
        console.info('release videorecorder success');
    } else {
        console.info('release videorecorder failed and error is ' + err.message);
    }
});
```

### release<sup>8+</sup><a name=videorecorder_release2></a>

release(): Promise\<void>;

Releases the video recording resource in asynchronous mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type          | Description                                     |
| -------------- | ----------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
// promise
await videoRecorder.release().then(() => {
    console.info('release videorecorder success');
}, (err) => {
    console.info('release videorecorder failed and error is ' + err.message);
}).catch((err) => {
    console.info('release videorecorder failed and catch error is ' + err.message);
});
```

### reset<sup>8+</sup><a name=videorecorder_reset1></a>

reset(callback: AsyncCallback\<void>): void;

Resets video recording in asynchronous mode. This API uses a callback to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface8) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
// asyncallback
videoRecorder.reset((err) => {
    if (typeof (err) == 'undefined') {
        console.info('reset videorecorder success');
    } else {
        console.info('reset videorecorder failed and error is ' + err.message);
    }
});
```

### reset<sup>8+</sup><a name=videorecorder_reset2></a>

reset(): Promise\<void>;

Resets video recording in asynchronous mode. This API uses a promise to return the result.

To start another recording, you must call [prepare()](#videorecorder_prepare1) and [getInputSurface()](#getinputsurface8) again.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
// promise
await videoRecorder.reset().then(() => {
    console.info('reset videorecorder success');
}, (err) => {
    console.info('reset videorecorder failed and error is ' + err.message);
}).catch((err) => {
    console.info('reset videorecorder failed and catch error is ' + err.message);
});
```

### on('error')<sup>8+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to the video recording error event.

**System capability**: SystemCapability.Multimedia.Media.VideoRecorder

**Parameters**

| Name  | Type         | Mandatory| Description                                                        |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | Yes  | Type of the event to subscribe to, which is 'error' in this method.<br>The 'error' event is triggered when an error occurs during video recording.|
| callback | ErrorCallback | Yes  | Callback invoked when the event is triggered.                                      |

**Example**

```js
videoRecorder.on('error', (error) => {      							// Set the 'error' event callback.
	console.info(`audio error called, errName is ${error.name}`);       // Print the error name.
    console.info(`audio error called, errCode is ${error.code}`);       // Print the error code.
    console.info(`audio error called, errMessage is ${error.message}`); // Print the detailed description of the error type.
});
// This event is reported when an error occurs during the retrieval of videoRecordState.
```

## VideoRecordState<sup>8+</sup>

Enumerates the video recording states. You can obtain the state through the **state** attribute.

| Name    | Type  | Description                                                        |
| -------- | ------ | ------------------------------------------------------------ |
| idle     | string | The video recorder is idle.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| prepared | string | The video recording parameters are set.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| playing  | string | Video recording is in progress.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| paused   | string | Video recording is paused.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| stopped  | string | Video recording is stopped.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| error    | string | Video recording is in the error state.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|

## VideoRecorderConfig<sup>8+</sup>

Describes the video recording parameters.

| Name           | Type                                                  | Mandatory| Description                                                        |
| --------------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](#audiosourcetype<sup>8+</sup>)           | Yes  | Type of the audio source for video recording.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| videoSourceType | [VideoSourceType](#videosourcetype<sup>8+</sup>)           | Yes  | Type of the video source for video recording.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| profile         | [VideoRecorderProfile](#videorecorderprofile<sup>8+</sup>) | Yes  | Video recording profile.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| orientationHint | number                                                     | No  | Rotation angle of the recorded video.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| location        | [Location](#location8)                                     | No  | Geographical location of the recorded video.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| url             | string                                                     | Yes  | Video output URL. Supported: fd://xx&nbsp;(fd&nbsp;number)<br>![en-us_image_0000001164217678](figures/en-us_image_url.png) <br>The file must be created by the caller and granted with proper permissions.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|

## AudioSourceType<sup>8+</sup>

Enumerates the audio source types for video recording.

| Name                     | Value  | Description                                                        |
| ------------------------- | ---- | ------------------------------------------------------------ |
| AUDIO_SOURCE_TYPE_DEFAULT | 0    | Default audio input source.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| AUDIO_SOURCE_TYPE_MIC     | 1    | Mic audio input source.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|

## VideoSourceType<sup>8+</sup>

Enumerates the video source types for video recording.

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| VIDEO_SOURCE_TYPE_SURFACE_YUV | 0    | The input surface carries raw data.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| VIDEO_SOURCE_TYPE_SURFACE_ES  | 1    | The input surface carries ES data.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|

## VideoRecorderProfile<sup>8+</sup>

Describes the video recording profile.

| Name            | Type                                    | Mandatory| Description                                                        |
| ---------------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioBitrate     | number                                       | Yes  | Audio encoding bit rate.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| audioChannels    | number                                       | Yes  | Number of audio channels.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| audioCodec       | [CodecMimeType](#CodecMimeType8)             | Yes  | Audio encoding format.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| audioSampleRate  | number                                       | Yes  | Audio sampling rate.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| fileFormat       | [ContainerFormatType](#containerformattype8) | Yes  | Container format of a file.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| videoCodec       | [CodecMimeType](#CodecMimeType8)             | Yes  | Video encoding format.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| videoFrameWidth  | number                                       | Yes  | Width of the recorded video frame.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|
| videoFrameHeight | number                                       | Yes  | Height of the recorded video frame.<br>**System capability**: SystemCapability.Multimedia.Media.VideoRecorder|

## ContainerFormatType<sup>8+</sup>

Enumerates the container format types (CFTs).

| Name       | Value   | Description                                                        |
| ----------- | ----- | ------------------------------------------------------------ |
| CFT_MPEG_4  | "mp4" | Video container format MP4.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| CFT_MPEG_4A | "m4a" | Audio container format M4A.<br>**System capability**: SystemCapability.Multimedia.Media.Core|

## Location<sup>8+</sup>

Describes the geographical location of the recorded video.

| Name     | Type| Mandatory| Description                                                        |
| --------- | -------- | ---- | ------------------------------------------------------------ |
| latitude  | number   | Yes  | Latitude of the geographical location.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
| longitude | number   | Yes  | Longitude of the geographical location.<br>**System capability**: SystemCapability.Multimedia.Media.Core|
