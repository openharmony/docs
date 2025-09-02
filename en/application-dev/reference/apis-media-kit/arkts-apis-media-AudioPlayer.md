# Deprecated Interface (AudioPlayer, deprecated)

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer](arkts-apis-media-AVPlayer.md) instead.

AudioPlayer is a class for audio playback management. It provides APIs to manage and play audio. Before calling any API in AudioPlayer, you must use [createAudioPlayer()](arkts-apis-media-f.md#mediacreateaudioplayerdeprecated) to create an AudioPlayer instance.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## Properties<sup>(deprecated)</sup>

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

| Name                           | Type                                                  | Read-Only| Optional| Description                                                        |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| src                             | string                                                 | No  | No  | Audio file URI. The mainstream audio formats (M4A, AAC, MP3, OGG, WAV, and AMR) are supported.<br>**Example of supported URLs**:<br>1. FD: fd://xx<br>![](figures/en-us_image_url.png)<br>2. HTTP: http\://xx<br>3. HTTPS: https\://xx<br>4. HLS: http\://xx or https\://xx<br>**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.INTERNET|
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                 | No  | No  | Description of the audio file. This property is required when audio assets of an application are continuously stored in a file.<br>**Example:**<br>Assume that a music file that stores continuous music assets consists of the following:<br>Music 1 (address offset: 0, byte length: 100)<br>Music 2 (address offset: 101; byte length: 50)<br>Music 3 (address offset: 151, byte length: 150)<br>1. To play music 1: AVFileDescriptor { fd = resource handle; offset = 0; length = 100; }<br>2. To play music 2: AVFileDescriptor { fd = resource handle; offset = 101; length = 50; }<br>3. To play music 3: AVFileDescriptor { fd = resource handle; offset = 151; length = 150; }<br>To play an independent music file, use **src=fd://xx**.<br>|
| loop                            | boolean                                                | No  | No | Whether to loop audio playback. The value **true** means to loop audio playback, and **false** means the opposite.                |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](../apis-audio-kit/arkts-apis-audio-e.md#interruptmode9) | Yes  | Yes  | Audio interruption mode.                                              |
| currentTime                     | number                                                 | Yes  | No  | Current audio playback position, in ms.                      |
| duration                        | number                                                 | Yes  | No  | Audio duration, in ms.                                |
| state                           | [AudioState](arkts-apis-media-t.md#audiostatedeprecated)                              | Yes  | No  | Audio playback state. This state cannot be used as the condition for triggering the call of **play()**, **pause()**, or **stop()**.|

## play<sup>(deprecated)</sup>

play(): void

Starts to play an audio asset. This API can be called only after the **'dataLoad'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.play](arkts-apis-media-AVPlayer.md#play9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('play', () => {    // Set the 'play' event callback.
  console.info('audio play called');
});
audioPlayer.play();
```

## pause<sup>(deprecated)</sup>

pause(): void

Pauses audio playback.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.pause](arkts-apis-media-AVPlayer.md#pause9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('pause', () => {    // Set the 'pause' event callback.
  console.info('audio pause called');
});
audioPlayer.pause();
```

## stop<sup>(deprecated)</sup>

stop(): void

Stops audio playback.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.stop](arkts-apis-media-AVPlayer.md#stop9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('stop', () => {    // Set the 'stop' event callback.
  console.info('audio stop called');
});
audioPlayer.stop();
```

## reset<sup>(deprecated)</sup>

reset(): void

Resets the audio asset to be played.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [AVPlayer.reset](arkts-apis-media-AVPlayer.md#reset9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.on('reset', () => {    // Set the 'reset' event callback.
  console.info('audio reset called');
});
audioPlayer.reset();
```

## seek<sup>(deprecated)</sup>

seek(timeMs: number): void

Seeks to the specified playback position.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.seek](arkts-apis-media-AVPlayer.md#seek9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                       |
| ------ | ------ | ---- | ----------------------------------------------------------- |
| timeMs | number | Yes  | Position to seek to, in ms. The value range is [0, duration].|

**Example**

```ts
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {    // Set the 'timeUpdate' event callback.
  if (seekDoneTime == null) {
    console.error('Failed to seek');
    return;
  }
  console.info('Succeeded in seek. seekDoneTime: ' + seekDoneTime);
});
audioPlayer.seek(30000); // Seek to 30000 ms.
```

## setVolume<sup>(deprecated)</sup>

setVolume(vol: number): void

Sets the volume.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.setVolume](arkts-apis-media-AVPlayer.md#setvolume9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | Yes  | Relative volume. The value ranges from 0.00 to 1.00. The value **1.00** indicates the maximum volume (100%).|

**Example**

```ts
audioPlayer.on('volumeChange', () => {    // Set the 'volumeChange' event callback.
  console.info('audio volumeChange called');
});
audioPlayer.setVolume(1);    // Set the volume to 100%.
```

## release<sup>(deprecated)</sup>

release(): void

Releases the audio playback resources.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.release](arkts-apis-media-AVPlayer.md#release9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Example**

```ts
audioPlayer.release();
audioPlayer = undefined;
```

## getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

Obtains the audio track information. It can be called only after the **'dataLoad'** event is triggered. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.getTrackDescription](arkts-apis-media-AVPlayer.md#gettrackdescription9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                      |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the MediaDescription array obtained; otherwise, **err** is an error object.|

**Example**

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

## getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

Obtains the audio track information. It can be called only after the **'dataLoad'** event is triggered. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.getTrackDescription](arkts-apis-media-AVPlayer.md#gettrackdescription9-1) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Return value**

| Type                                                  | Description                                           |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Promise used to return a **MediaDescription** array, which records the audio track information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  console.info('Succeeded in getting TrackDescription');
}).catch((error: BusinessError) => {
  console.error(`Failed to get TrackDescription, error:${error}`);
});
```

## on('bufferingUpdate')<sup>(deprecated)</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

Subscribes to the audio buffering update event. This API works only under online playback.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AVPlayer.on('bufferingUpdate')](arkts-apis-media-AVPlayer.md#onbufferingupdate9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'bufferingUpdate'** in this case.       |
| callback | function | Yes  | Callback invoked when the event is triggered.<br>The value of [BufferingInfoType](arkts-apis-media-e.md#bufferinginfotype8) is fixed at **0**.|

**Example**

```ts
audioPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('audio bufferingInfo type: ' + infoType);
  console.info('audio bufferingInfo value: ' + value);
});
```

## on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')<sup>(deprecated)</sup>

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void): void

Subscribes to the audio playback events.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.on('stateChange')](arkts-apis-media-AVPlayer.md#onstatechange9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioPlayer

**Parameters**

| Name  | Type      | Mandatory| Description                                                        |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | Yes  | Event type. The following events are supported:<br>- 'play': triggered when the [play()](#playdeprecated) API is called and audio playback starts.<br>- 'pause': triggered when the [pause()](#pausedeprecated) API is called and audio playback is paused.<br>- 'stop': triggered when the [stop()](#stopdeprecated) API is called and audio playback stops.<br>- 'reset': triggered when the [reset()](#resetdeprecated) API is called and audio playback is reset.<br>- 'dataLoad': triggered when the audio data is loaded, that is, when the **src** property is configured.<br>- 'finish': triggered when the audio playback is finished.<br>- 'volumeChange': triggered when the [setVolume()](#setvolumedeprecated) API is called and the playback volume is changed.|
| callback | () => void | Yes  | Callback invoked when the event is triggered.                                          |

**Example**

```ts
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioPlayer: media.AudioPlayer = media.createAudioPlayer();  // Create an AudioPlayer instance.
audioPlayer.on('dataLoad', () => {            // Set the 'dataLoad' event callback, which is triggered when the src property is set successfully.
  console.info('audio set source called');
  audioPlayer.play();                       // Start the playback and trigger the 'play' event callback.
});
audioPlayer.on('play', () => {                // Set the 'play' event callback.
  console.info('audio play called');
  audioPlayer.seek(30000);                  // Call the seek() API and trigger the 'timeUpdate' event callback.
});
audioPlayer.on('pause', () => {               // Set the 'pause' event callback.
  console.info('audio pause called');
  audioPlayer.stop();                       // Stop the playback and trigger the 'stop' event callback.
});
audioPlayer.on('reset', () => {               // Set the 'reset' event callback.
  console.info('audio reset called');
  audioPlayer.release();                    // Release the AudioPlayer instance.
  audioPlayer = undefined;
});
audioPlayer.on('timeUpdate', (seekDoneTime: number) => {  // Set the 'timeUpdate' event callback.
  if (seekDoneTime == null) {
    console.error('Failed to seek');
    return;
  }
  console.info('Succeeded in seek, and seek time is ' + seekDoneTime);
  audioPlayer.setVolume(0.5);                // Set the volume to 50% and trigger the 'volumeChange' event callback.
});
audioPlayer.on('volumeChange', () => {         // Set the 'volumeChange' event callback.
  console.info('audio volumeChange called');
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
fs.open(path).then((file) => {
  fdPath = fdPath + '' + file.fd;
  console.info('Succeeded in opening fd, fd is' + fdPath);
  audioPlayer.src = fdPath;  // Set the src property and trigger the 'dataLoad' event callback.
}, (err: BusinessError) => {
  console.error('Failed to open fd, err is' + err);
}).catch((err: BusinessError) => {
  console.error('Failed to open fd, err is' + err);
});
```

## on('timeUpdate')<sup>(deprecated)</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

Subscribes to the **'timeUpdate'** event. This event is reported every second when the audio playback is in progress.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.on('timeUpdate')](arkts-apis-media-AVPlayer.md#ontimeupdate9) instead.

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
    console.error('Failed to do timeUpadate');
    return;
  }
  console.info('Succeeded in doing timeUpadate. seekDoneTime: ' + newTime);
});
audioPlayer.play();    // The 'timeUpdate' event is triggered when the playback starts.
```

## on('audioInterrupt')<sup>(deprecated)</sup>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

Subscribes to the audio interruption event. For details, see [audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9).

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 9. You are advised to use [AVPlayer.on('audioInterrupt')](arkts-apis-media-AVPlayer.md#onaudiointerrupt9) instead.

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
  console.info('audioInterrupt called,and InterruptEvent info is:' + info);
});
```

## on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to audio playback error events. After an error event is reported, you must handle the event and exit the playback.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVPlayer.on('error')](arkts-apis-media-AVPlayer.md#onerror9) instead.

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
