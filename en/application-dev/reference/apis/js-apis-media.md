# Audio Playback and Recording

## Modules to Import

```
import media from '@ohos.multimedia.media';
```

## Required Permissions

None

## media.createAudioPlayer

Creates an  **AudioPlayer**  instance.

**Return values**

| Type                        | Description                                                  |
| --------------------------- | ------------------------------------------------------------ |
| [AudioPlayer](#audioplayer) | Returns the **AudioPlayer** instance if the operation is successful; returns **null** otherwise. |

**Example**

```
var audioplayer = media.createAudioPlayer(); 
```

## media.createAudioRecorder

createAudioRecorder(): AudioRecorder

Creates an  **AudioRecorder**  instance to control audio recording.

**Return values**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| [AudioRecorder](#audiorecorder) | Returns the **AudioRecorder** instance if the operation is successful; returns **null** otherwise. |

**Example**

```
var audiorecorder = media.createAudioRecorder(); 
```

## AudioPlayer

Manages and plays audio. Before calling a method of  **AudioPlayer**, you must use  [createAudioPlayer()](#mediacreateaudioplayer)  to create an  **AudioPlayer**  instance.

### Attributes

| Name        | Type                      | Readable | Writable | Description                                                  |
| ----------- | ------------------------- | -------- | -------- | ------------------------------------------------------------ |
| src         | string                    | Yes      | Yes      | Audio media URI. Popular audio formats (mp4, aac, mp3, and ogg) are supported. The value can be a local absolute path starting with **file://**. |
| loop        | boolean                   | Yes      | Yes      | Whether to loop audio playback. The value **true** means to loop playback. |
| currentTime | number                    | Yes      | No       | Current playback position.                                   |
| duration    | number                    | Yes      | No       | Audio duration.                                              |
| state       | [AudioState](#audiostate) | Yes      | No       | Playback status.                                             |

### play

play\(\): void

Starts audio playback.

**Example**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('play', () => {
  console.log('Playback starts.');
});
audioplayer.play();
```

### pause

pause\(\): void

Pauses audio playback.

**Example**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('pause', () => {
  console.log('Playback paused.');
});
audioplayer.pause();
```


### stop

stop\(\): void

Stops audio playback.

**Example**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('stop',() => {
  console.log('Playback stopped.');
});
audioplayer.stop();
```


### seek

seek\(timeMs: number\): void

Seeks to the specified playback position.

**Parameters**

| Name   | Type   | Mandatory | Description                   |
| ------ | ------ | --------- | ----------------------------- |
| timeMs | number | Yes       | Playback position to seek to. |

**Example**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('timeupdate', (action) => {
  var newTime = audioplayer.currenTime;
  if(newTime >= 30000) {
    console.info('Seek succeeded. New time: ' + newTime);
  } else {
    console.info('Seek failed.');
  }
});
audioplayer.seek(30000);
```

### setVolume

setVolume\(vol: number\): void

Sets the volume.

**Parameters**

| Name | Type   | Mandatory | Description                                                  |
| ---- | ------ | --------- | ------------------------------------------------------------ |
| vol  | number | Yes       | Relative volume. The value ranges from 0.00 to 1.00. The value **1** indicates the maximum volume (100%). |

**Example**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('volumeChange', () => {
  console.log('Playback volume changed.');
});
audioplayer.setVolume(1);
```

### reset<sup>7+</sup>

reset\(\): void

Switches the audio resource to be played.

**Example**

```
audioplay.reset();
```

### release

release\(\): void

Releases audio resources.

**Example**

```
audioplay.release();
```

### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')

Listens for audio playback events.

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void)

**Parameters**

| Name     | Type     | Mandatory | Description                                                  |
| -------- | -------- | --------- | ------------------------------------------------------------ |
| type     | string   | Yes       | Type of the playback event to listen for. The following events are supported: **play**, **pause**, **stop**, **reset**, **dataLoad**, **finish**, and **volumeChange**.<br>- The **play** event is triggered when audio playback starts. <br/>- The **pause** event is triggered when audio playback is paused.<br/>- The **stop** event is triggered when audio playback stops.<br/>- The **reset** event is triggered when the player is reset.<br/>- The **dataLoad** event is triggered when audio data is loaded.<br/>- The **finish** event is triggered when audio playback is finished.<br/>- The **volumeChange** event is triggered when the playback volume changes. |
| callback | function | Yes       | Callback used to listen for the playback event.              |

**Example**

```
audioplayer.src = 'file://xxx/sounds.mp4';
audioplayer.on('play', () => {
  console.log('Playback starts.');
});
audioplayer.play();
```

### on('timeUpdate')

on(type: 'timeUpdate', callback: Callback\<number>): void

Listens for audio playback timestamp update events.

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| -------- | ---------------------- | --------- | ------------------------------------------------------------ |
| type     | string                 | Yes       | Type of the playback event to listen for. Only the **timeUpdate** event is supported.<br>- The **timeUpdate** event is triggered when the audio playback timestamp is updated. It is also triggered when the **seek** method is called. |
| callback | Callback&lt;number&gt; | Yes       | Callback used to listen for the playback event.              |

**Example**

```
audioplayer.src = 'file://xxx/sounds.mp4';
audioplayer.on('timeupdate', (newTime ) => {
  if(newTime >= 30000) {
    console.info('Seek succeeded. New time: ' + newTime);
  } else {
    console.info('Seek failed.');
  }
});
audioplayer.seek(30000);
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Listens for playback error events.

**Parameters**

| Name     | Type          | Mandatory | Description                                                  |
| -------- | ------------- | --------- | ------------------------------------------------------------ |
| type     | string        | Yes       | Type of the playback error event to listen for.<br>- The **error** event is triggered when an error occurs during audio playback. |
| callback | ErrorCallback | Yes       | Callback used to listen for the playback event.              |

**Example**

```
audioplayer.src = 'file:///data/sounds.mp4';
audioplayer.on('error', (err) => {
   console.info('error callback info: ' + err);
});
audioplayer.setVolume(30000);
```


## AudioState

Describes the audio playback state.

| Name    | Description                |
| ------- | -------------------------- |
| idle    | Audio playback is idle.    |
| playing | The audio is being played. |
| paused  | Audio playback is paused.  |
| stopped | Audio playback is stopped. |

## AudioRecorder

Provides methods to record audio. Before calling an  **AudioRecorder**  method, you must use  [createAudioRecorder\(\)](#mediacreateaudiorecorder)  to create an  **AudioRecorder**  instance.

### prepare

prepare(config: AudioRecorderConfig): void

**Parameters**

| Name   | Type                                        | Mandatory | Description                                                  |
| ------ | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfig) | Yes       | Recording parameters, including the audio output URI, encoding format, sampling rate, and number of audio channels |

**Example**

    ```
    let audioRecorderConfig = {
        audioEncoder : AAC_LC ,
        audioEncodeBitRate : 22050,
        audioSampleRate : 22050,
        numberOfChannels : 2,
        format : AAC_ADTS,
        uri : 'file:///data/accounts/account_0/appdata/appdata/recorder/test.m4a',
    }
    audiorecorder.prepare(audioRecorderConfig)
    ```
### start

start(): void

Starts audio recording.

**Example**

```
audiorecorder.start();
```

### stop

stop(): void

Stops audio recording.

**Example**

```
audiorecorder.stop();
```

### release

release(): void

**Example**

```
audiorecorder.release();
```

### reset

reset(): void

Resets audio recording.

Before resetting audio recording, you must call  **stop\(\)**  to stop recording. After audio recording is reset, you must call  **prepare\(\)**  to set the recording configurations for another recording.

**Example**

```
audiorecorder.reset();
```

### on('prepare' | 'start' |  'stop' | 'release' | 'reset')

on(type: 'prepare' | 'start' | 'stop' | 'release' | 'reset', callback: () => void): void

Listens for audio recording events.

**Parameters**

| Name     | Type     | Mandatory | Description                                                  |
| -------- | -------- | --------- | ------------------------------------------------------------ |
| type     | string   | Yes       | Type of the audio recording event to listen for. The following events are supported: **prepare**, **start**, **stop**, **release**, and **reset**.<br>- The **prepare** event is triggered when the audio recording preparation is complete.<br/>- The **start** event is triggered when audio recording starts.<br/>- The **stop** event is triggered when audio recording stops.<br/>- The **release** event is triggered when resources related to audio recording are released.<br/>- The **reset** event is triggered when audio recording is reset. |
| callback | function | Yes       | Callback used to listen for the audio recording event.       |

**Example**

```
audiorecorder.on('prepare', () => {
  console.log('Preparation succeeded.');
  audiorecorder.start();
});
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

Listens for audio recording error events.

**Parameters**

| Name     | Type     | Mandatory | Description                                                  |
| -------- | -------- | --------- | ------------------------------------------------------------ |
| type     | string   | Yes       | Type of the audio recording error event to listen for.<br>- The **error** event is triggered when an error occurs during audio recording. |
| callback | function | Yes       | Callback used to listen for the audio recording event.       |

## AudioRecorderConfig

Describes audio recording configurations.

| Name               | Type                                    | Mandatory | Description                                                  |
| ------------------ | --------------------------------------- | --------- | ------------------------------------------------------------ |
| audioEncoder       | [AudioEncoder](#audioencoder)           | No        | Audio encoding format. The default value is **AAC_LC**.      |
| audioEncodeBitRate | number                                  | No        | Bit rate for audio encoding. The default value is **48000**. |
| audioSampleRate    | number                                  | No        | Audio sampling rate. The default value is **48000**.         |
| numberOfChannels   | number                                  | No        | Number of audio channels. The default value is **2**.        |
| format             | [AudioOutputFormat](#audiooutputformat) | No        | Audio output format. The default value is **MPEG_4**.        |
| uri                | string                                  | Yes       | Audio output URI. The following types of URIs are supported:<br/>1. Absolute path:<br>file:///data/data/ohos.xxx.xxx/cache/test.mp4![en-us_image_0000001164217678](figures/en-us_image_0000001164217678.png)<br/> 2. Path with the file descriptor (FD): file://1 (FD number) |

## AudioEncoder

Enumerates audio encoding formats.

| Name   | Default Value | Description                                    |
| ------ | ------------- | ---------------------------------------------- |
| AAC_LC | 3             | Advanced Audio Coding Low Complexity (AAC-LC). |

## AudioOutputFormat

Enumerates audio output formats.

| Name     | Default Value | Description                                                  |
| -------- | ------------- | ------------------------------------------------------------ |
| MPEG_4   | 2             | MPEG-4.                                                      |
| AAC_ADTS | 6             | Audio Data Transport Stream (ADTS), a transmission stream format of Advanced Audio Coding (AAC) audio. |