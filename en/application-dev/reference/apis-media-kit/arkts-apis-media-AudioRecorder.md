# Deprecated Interface (AudioRecorder, deprecated)

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder](arkts-apis-media-AVRecorder.md) instead.

AudioRecorder is a class for audio recording management. It provides APIs to record audio. Before calling any API in AudioRecorder, you must use [createAudioRecorder()](arkts-apis-media-f.md#mediacreateaudiorecorderdeprecated) to create an AudioRecorder instance.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## prepare<sup>(deprecated)</sup>

prepare(config: AudioRecorderConfig): void

Prepares for recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.prepare](arkts-apis-media-AVRecorder.md#prepare9) instead.

**Required permissions:** ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name| Type                                       | Mandatory| Description                                                        |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](arkts-apis-media-i.md#audiorecorderconfigdeprecated) | Yes  | Audio recording parameters, including the audio output URI, encoding format, sampling rate, number of audio channels, and output format.|

**Error codes**

For details about the error codes, see [Media Error Codes](errorcode-media.md).

| ID| Error Message             |
| -------- | --------------------- |
| 201      | permission denied     |

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
};
audioRecorder.on('prepare', () => {    // Set the 'prepare' event callback.
  console.info('prepare called');
});
audioRecorder.prepare(audioRecorderConfig);
```

## start<sup>(deprecated)</sup>

start(): void

Starts audio recording. This API can be called only after the **'prepare'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.start](arkts-apis-media-AVRecorder.md#start9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('start', () => {    // Set the 'start' event callback.
  console.info('audio recorder start called');
});
audioRecorder.start();
```

## pause<sup>(deprecated)</sup>

pause():void

Pauses audio recording. This API can be called only after the **'start'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.pause](arkts-apis-media-AVRecorder.md#pause9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('pause', () => {    // Set the 'pause' event callback.
  console.info('audio recorder pause called');
});
audioRecorder.pause();
```

## resume<sup>(deprecated)</sup>

resume():void

Resumes audio recording. This API can be called only after the **'pause'** event is triggered.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.resume](arkts-apis-media-AVRecorder.md#resume9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('resume', () => { // Set the 'resume' event callback.
  console.info('audio recorder resume called');
});
audioRecorder.resume();
```

## stop<sup>(deprecated)</sup>

stop(): void

Stops audio recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.stop](arkts-apis-media-AVRecorder.md#stop9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('stop', () => {    // Set the 'stop' event callback.
  console.info('audio recorder stop called');
});
audioRecorder.stop();
```

## release<sup>(deprecated)</sup>

release(): void

Releases the audio recording resources.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.release](arkts-apis-media-AVRecorder.md#release9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('release', () => {    // Set the 'release' event callback.
  console.info('audio recorder release called');
});
audioRecorder.release();
audioRecorder = undefined;
```

## reset<sup>(deprecated)</sup>

reset(): void

Resets audio recording.

Before resetting audio recording, you must call **stop()** to stop recording. After audio recording is reset, you must call **prepare()** to set the recording configurations for another recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.reset](arkts-apis-media-AVRecorder.md#reset9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Example**

```ts
audioRecorder.on('reset', () => {    // Set the 'reset' event callback.
  console.info('audio recorder reset called');
});
audioRecorder.reset();
```

## on('prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset')<sup>(deprecated)</sup>

on(type: 'prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset', callback: () => void): void

Subscribes to the audio recording events.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.on('stateChange')](arkts-apis-media-AVRecorder.md#onstatechange9) instead.

**System capability**: SystemCapability.Multimedia.Media.AudioRecorder

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The following events are supported: 'prepare'\|'start'\|  'pause' \| 'resume' \|'stop'\|'release'\|'reset'<br>- 'prepare': triggered when the **prepare()** API is called and the audio recording parameters are set.<br>- 'start': triggered when the **start()** API is called and audio recording starts.<br>- 'pause': triggered when the **pause()** API is called and audio recording is paused.<br>- 'resume': triggered when the **resume()** API is called and audio recording is resumed.<br>- 'stop': triggered when the **stop()** API is called and audio recording stops.<br>- 'release': triggered when the **release()** API is called and the recording resources are released.<br>- 'reset': triggered when the **reset()** API is called and audio recording is reset.|
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
};
audioRecorder.on('error', (error: BusinessError) => {  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});
audioRecorder.on('prepare', () => {  // Set the 'prepare' event callback.
  console.info('prepare called');
  audioRecorder.start();  // // Start recording and trigger the 'start' event callback.
});
audioRecorder.on('start', () => {  // Set the 'start' event callback.
  console.info('audio recorder start called');
});
audioRecorder.on('pause', () => {  // Set the 'pause' event callback.
  console.info('audio recorder pause called');
});
audioRecorder.on('resume', () => {  // Set the 'resume' event callback.
  console.info('audio recorder resume called');
});
audioRecorder.on('stop', () => {  // Set the 'stop' event callback.
  console.info('audio recorder stop called');
});
audioRecorder.on('release', () => {  // Set the 'release' event callback.
  console.info('audio recorder release called');
});
audioRecorder.on('reset', () => {  // Set the 'reset' event callback.
  console.info('audio recorder reset called');
});
audioRecorder.prepare(audioRecorderConfig)  // // Set recording parameters and trigger the 'prepare' event callback.
```

## on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to audio recording error events. After an error event is reported, you must handle the event and exit the recording.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [AVRecorder.on('error')](arkts-apis-media-AVRecorder.md#onerror9) instead.

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
};
audioRecorder.on('error', (error: BusinessError) => {  // Set the 'error' event callback.
  console.error(`audio error called, error: ${error}`);
});
audioRecorder.prepare(audioRecorderConfig);  // // Do not set any parameter in prepare and trigger the 'error' event callback.
```
