# Audio Management

>  **NOTE**<br/>
>  The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

This module provides the following common audio-related functions:

- [AudioManager](#audiomanager): audio management.
- [AudioRenderer](#audiorenderer8): audio rendering, used to play Pulse Code Modulation (PCM) audio data.
- [AudioCapturer](#audiocapturer8): audio capture, used to record PCM audio data.

## Modules to Import

```
import audio from '@ohos.multimedia.audio';
```


## audio.getAudioManager

getAudioManager(): AudioManager

Obtains an **AudioManager** instance.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**
| Type                         | Description        |
| ----------------------------- | ------------ |
| [AudioManager](#audiomanager) | **AudioManager** instance.|

**Example**
```
var audioManager = audio.getAudioManager();
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void

Obtains an **AudioRenderer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                           | Mandatory| Description            |
| -------- | ----------------------------------------------- | ---- | ---------------- |
| options  | [AudioRendererOptions](#audiorendereroptions8)  | Yes  | Renderer configurations.    |
| callback | AsyncCallback<[AudioRenderer](#audiorenderer8)> | Yes  | Callback used to return the **AudioRenderer** instance.|

**Example**

```
import audio from '@ohos.multimedia.audio';
var audioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
    channels: audio.AudioChannel.CHANNEL_1,
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

var audioRendererInfo = {
    content: audio.ContentType.CONTENT_TYPE_SPEECH,
    usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
    rendererFlags: 1
}

var audioRendererOptions = {
    streamInfo: audioStreamInfo,
    rendererInfo: audioRendererInfo
}

audio.createAudioRenderer(audioRendererOptions,(err, data) => {
    if (err) {
        console.error(`AudioRenderer Created : Error: ${err.message}`);
    }
    else {
        console.info('AudioRenderer Created : Success : SUCCESS');
        let audioRenderer = data;
    }
});
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions): Promise<AudioRenderer\>

Obtains an **AudioRenderer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type                                          | Mandatory| Description        |
| :------ | :--------------------------------------------- | :--- | :----------- |
| options | [AudioRendererOptions](#audiorendereroptions8) | Yes  | Renderer configurations.|

**Return value**

| Type                                     | Description            |
| ----------------------------------------- | ---------------- |
| Promise<[AudioRenderer](#audiorenderer8)> | Promise used to return the **AudioRenderer** instance.|

**Example**

```
import audio from '@ohos.multimedia.audio';

var audioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
    channels: audio.AudioChannel.CHANNEL_1,
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

var audioRendererInfo = {
    content: audio.ContentType.CONTENT_TYPE_SPEECH,
    usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
    rendererFlags: 1
}

var audioRendererOptions = {
    streamInfo: audioStreamInfo,
    rendererInfo: audioRendererInfo
}

var audioRenderer;
audio.createAudioRenderer(audioRendererOptions).then((data) => {
    audioRenderer = data;
    console.info('AudioFrameworkRenderLog: AudioRenderer Created : Success : Stream Type: SUCCESS');
}).catch((err) => {
    console.info('AudioFrameworkRenderLog: AudioRenderer Created : ERROR : '+err.message);
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions, callback: AsyncCallback<AudioCapturer\>): void

Obtains an **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                                           | Mandatory| Description            |
| :------- | :---------------------------------------------- | :--- | :--------------- |
| options  | [AudioCapturerOptions](#audiocaptureroptions8)  | Yes  | Capturer configurations.|
| callback | AsyncCallback<[AudioCapturer](#audiocapturer8)> | Yes  | Callback used to return the **AudioCapturer** instance.|

**Example**

```
import audio from '@ohos.multimedia.audio';
var audioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
    channels: audio.AudioChannel.CHANNEL_2,
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

var audioCapturerInfo = {
    source: audio.SourceType.SOURCE_TYPE_MIC,
    capturerFlags: 1
}

var audioCapturerOptions = {
    streamInfo: audioStreamInfo,
    capturerInfo: audioCapturerInfo
}

audio.createAudioCapturer(audioCapturerOptions,(err, data) => {
    if (err) {
        console.error(`AudioCapturer Created : Error: ${err.message}`);
    }
    else {
        console.info('AudioCapturer Created : Success : SUCCESS');
        let audioCapturer = data;
    }
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions): Promise<AudioCapturer\>

Obtains an **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type                                          | Mandatory| Description            |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| options | [AudioCapturerOptions](#audiocaptureroptions8) | Yes  | Capturer configurations.|

**Return value**

| Type                                     | Description          |
| ----------------------------------------- | -------------- |
| Promise<[AudioCapturer](#audiocapturer8)> | Promise used to return the **AudioCapturer** instance.|

**Example**

```
import audio from '@ohos.multimedia.audio';

var audioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
    channels: audio.AudioChannel.CHANNEL_2,
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

var audioCapturerInfo = {
    source: audio.SourceType.SOURCE_TYPE_MIC,
    capturerFlags: 1
}

var audioCapturerOptions = {
    streamInfo: audioStreamInfo,
    capturerInfo: audioCapturerInfo
}

var audioCapturer;
audio.createAudioRenderer(audioCapturerOptions).then((data) => {
    audioCapturer = data;
    console.info('AudioCapturer Created : Success : Stream Type: SUCCESS');
}).catch((err) => {
    console.info('AudioCapturer Created : ERROR : '+err.message);
});
```

## AudioVolumeType

Enumerates the audio stream types.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                        | Default Value| Description      |
| ---------------------------- | ------ | ---------- |
| VOICE_CALL<sup>8+</sup>      | 0      | Audio stream for voice calls.|
| RINGTONE                     | 2      | Audio stream for ringtones.    |
| MEDIA                        | 3      | Audio stream for media purpose.    |
| VOICE_ASSISTANT<sup>8+</sup> | 9      | Audio stream for voice assistant.|


## DeviceFlag

Enumerates the audio device flags.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name               | Default Value| Description      |
| ------------------- | ------ | ---------- |
| OUTPUT_DEVICES_FLAG | 1      | Output device.|
| INPUT_DEVICES_FLAG  | 2      | Input device.|
| ALL_DEVICES_FLAG    | 3      | All devices.|


## DeviceRole

Enumerates the audio device roles.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name         | Default Value| Description          |
| ------------- | ------ | -------------- |
| INPUT_DEVICE  | 1      | Input role.|
| OUTPUT_DEVICE | 2      | Output role.|


## DeviceType

Enumerates the audio device types.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name            | Default Value| Description                                                     |
| ---------------- | ------ | --------------------------------------------------------- |
| INVALID          | 0      | Invalid device.                                               |
| EARPIECE         | 1      | Earpiece.                                                   |
| SPEAKER          | 2      | Speaker.                                                 |
| WIRED_HEADSET    | 3      | Wired headset with a microphone.                                     |
| WIRED_HEADPHONES | 4      | Wired headset without microphone.                                     |
| BLUETOOTH_SCO    | 7      | Bluetooth device using Synchronous Connection Oriented (SCO) links.     |
| BLUETOOTH_A2DP   | 8      | Bluetooth device using Advanced Audio Distribution Profile (A2DP) links.|
| MIC              | 15     | Microphone.                                                 |
| USB_HEADSET      | 22     | USB Type-C headset.                                      |

## ActiveDeviceType

Enumerates the active device types.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name         | Default Value| Description                                                |
| ------------- | ------ | ---------------------------------------------------- |
| SPEAKER       | 2      | Speaker.                                            |
| BLUETOOTH_SCO | 7      | Bluetooth device using the SCO links.|

## AudioRingMode

Enumerates the ringer modes.

**System capability**: SystemCapability.Multimedia.Audio.Communication

| Name               | Default Value| Description      |
| ------------------- | ------ | ---------- |
| RINGER_MODE_SILENT  | 0      | Silent mode.|
| RINGER_MODE_VIBRATE | 1      | Vibration mode.|
| RINGER_MODE_NORMAL  | 2      | Normal mode.|

## AudioSampleFormat<sup>8+</sup>

Enumerate the audio sample formats.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                 | Default Value| Description                      |
| --------------------- | ------ | -------------------------- |
| SAMPLE_FORMAT_INVALID | -1     | Invalid format.                |
| SAMPLE_FORMAT_U8      | 0      | Unsigned 8-bit integer.           |
| SAMPLE_FORMAT_S16LE   | 1      | Signed 16-bit integer, little endian.|
| SAMPLE_FORMAT_S24LE   | 2      | Signed 24-bit integer, little endian.|
| SAMPLE_FORMAT_S32LE   | 3      | Signed 32-bit integer, little endian.|

## AudioChannel<sup>8+</sup>

Enumerates the audio channels.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name     | Default Value  | Description    |
| --------- | -------- | -------- |
| CHANNEL_1 | 0x1 << 0 | Mono.|
| CHANNEL_2 | 0x1 << 1 | Dual-channel.|

## AudioSamplingRate<sup>8+</sup>

Enumerates the audio sampling rates.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name             | Default Value| Description           |
| ----------------- | ------ | --------------- |
| SAMPLE_RATE_8000  | 8000   | The sampling rate is 8000. |
| SAMPLE_RATE_11025 | 11025  | The sampling rate is 11025.|
| SAMPLE_RATE_12000 | 12000  | The sampling rate is 12000.|
| SAMPLE_RATE_16000 | 16000  | The sampling rate is 16000.|
| SAMPLE_RATE_22050 | 22050  | The sampling rate is 22050.|
| SAMPLE_RATE_24000 | 24000  | The sampling rate is 24000.|
| SAMPLE_RATE_32000 | 32000  | The sampling rate is 32000.|
| SAMPLE_RATE_44100 | 44100  | The sampling rate is 44100.|
| SAMPLE_RATE_48000 | 48000  | The sampling rate is 48000.|
| SAMPLE_RATE_64000 | 64000  | The sampling rate is 64000.|
| SAMPLE_RATE_96000 | 96000  | The sampling rate is 96000.|

## AudioEncodingType<sup>8+</sup>

Enumerates the audio encoding types.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                 | Default Value| Description     |
| --------------------- | ------ | --------- |
| ENCODING_TYPE_INVALID | -1     | Invalid.   |
| ENCODING_TYPE_RAW     | 0      | PCM encoding.|

## ContentType

Enumerates the audio content types.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                              | Default Value| Description      |
| ---------------------------------- | ------ | ---------- |
| CONTENT_TYPE_UNKNOWN               | 0      | Unknown content.|
| CONTENT_TYPE_SPEECH                | 1      | Speech.    |
| CONTENT_TYPE_MUSIC                 | 2      | Music.    |
| CONTENT_TYPE_MOVIE                 | 3      | Movie.    |
| CONTENT_TYPE_SONIFICATION          | 4      | Sonification content.|
| CONTENT_TYPE_RINGTONE<sup>8+</sup> | 5      | Ringtone.    |

## StreamUsage

Enumerates the audio stream usage.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                              | Default Value| Description      |
| ---------------------------------- | ------ | ---------- |
| STREAM_USAGE_UNKNOWN               | 0      | Unknown usage.|
| STREAM_USAGE_MEDIA                 | 1      | Used for media.    |
| STREAM_USAGE_VOICE_COMMUNICATION   | 2      | Used for voice communication.|
| STREAM_USAGE_NOTIFICATION_RINGTONE | 6      | Used for notification.|

## AudioState<sup>8+</sup>

Enumerates the audio states.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name          | Default Value| Description            |
| -------------- | ------ | ---------------- |
| STATE_INVALID  | -1     | Invalid state.      |
| STATE_NEW      | 0      | Creating instance state.|
| STATE_PREPARED | 1      | Prepared.      |
| STATE_RUNNING  | 2      | Running.    |
| STATE_STOPPED  | 3      | Stopped.      |
| STATE_RELEASED | 4      | Released.      |
| STATE_PAUSED   | 5      | Paused.      |

## AudioRendererRate<sup>8+</sup>

Enumerates the audio renderer rates.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Default Value| Description      |
| ------------------ | ------ | ---------- |
| RENDER_RATE_NORMAL | 0      | Normal rate.|
| RENDER_RATE_DOUBLE | 1      | Double rate.   |
| RENDER_RATE_HALF   | 2      | Half rate. |

## InterruptType

Enumerates the audio interruption types.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name                | Default Value| Description                  |
| -------------------- | ------ | ---------------------- |
| INTERRUPT_TYPE_BEGIN | 1      | Audio interruption started.|
| INTERRUPT_TYPE_END   | 2      | Audio interruption ended.|

## InterruptForceType<sup>9+</sup>

Enumerates the types of force that causes audio interruption.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name           | Default Value| Description                                |
| --------------- | ------ | ------------------------------------ |
| INTERRUPT_FORCE | 0      | Forced action taken by the system.  |
| INTERRUPT_SHARE | 1      | The application can choose to take action or ignore.|

## InterruptHint

Enumerates the hints provided along with audio interruption.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name                              | Default Value| Description                                        |
| ---------------------------------- | ------ | -------------------------------------------- |
| INTERRUPT_HINT_NONE<sup>8+</sup>   | 0      | None.                                    |
| INTERRUPT_HINT_RESUME              | 1      | Resume the playback.                              |
| INTERRUPT_HINT_PAUSE               | 2      | Paused/Pause the playback.                              |
| INTERRUPT_HINT_STOP                | 3      | Stopped/Stop the playback.                              |
| INTERRUPT_HINT_DUCK                | 4      | Ducked the playback. (In ducking, the audio volume is reduced, but not silenced.)|
| INTERRUPT_HINT_UNDUCK<sup>8+</sup> | 5      | Unducked the playback.                              |

## InterruptActionType

Enumerates the returned event types for audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name          | Default Value| Description              |
| -------------- | ------ | ------------------ |
| TYPE_ACTIVATED | 0      | Focus gain event.|
| TYPE_INTERRUPT | 1      | Audio interruption event.|

## AudioStreamInfo<sup>8+</sup>

Describes audio stream information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name        | Type                                    | Mandatory| Description              |
| ------------ | ---------------------------------------- | ---- | ------------------ |
| samplingRate | [AudioSamplingRate](#audiosamplingrate8) | Yes  | Audio sampling rate.|
| channels     | [AudioChannel](#audiochannel8)           | Yes  | Number of audio channels.|
| sampleFormat | [AudioSampleFormat](#audiosampleformat8) | Yes  | Audio sample format.    |
| encodingType | [AudioEncodingType](#audioencodingtype8) | Yes  | Audio encoding type.    |

## AudioRendererInfo<sup>8+</sup>

Describes audio renderer information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                       | Mandatory| Description            |
| ------------- | --------------------------- | ---- | ---------------- |
| content       | [ContentType](#contenttype) | Yes  | Audio content type.      |
| usage         | [StreamUsage](#streamusage) | Yes  | Audio stream usage.|
| rendererFlags | number                      | Yes  | Audio renderer flags.|

## AudioRendererOptions<sup>8+</sup>

Describes audio renderer configurations.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name        | Type                                    | Mandatory| Description            |
| ------------ | ---------------------------------------- | ---- | ---------------- |
| streamInfo   | [AudioStreamInfo](#audiostreaminfo8)     | Yes  | Audio stream information.|
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) | Yes  | Audio renderer information.|

## InterruptEvent<sup>9+</sup>

Describes the interruption event received by the application when playback is interrupted.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name     | Type                                      | Mandatory| Description                                |
| --------- | ------------------------------------------ | ---- | ------------------------------------ |
| eventType | [InterruptType](#interrupttype)            | Yes  | Whether the interruption has started or ended.        |
| forceType | [InterruptForceType](#interruptforcetype9) | Yes  | Whether the interruption is taken by the system or to be taken by the application.|
| hintType  | [InterruptHint](#interrupthint)            | Yes  | Hint provided along the interruption.                          |

## AudioInterrupt

Describes input parameters of audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name           | Type                       | Mandatory| Description                                                        |
| --------------- | --------------------------- | ---- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](#streamusage) | Yes  | Audio stream usage.                                            |
| contentType     | [ContentType](#contenttype) | Yes  | Audio content type.                                          |
| pauseWhenDucked | boolean                     | Yes  | Whether audio playback can be paused during audio interruption. The value **true** means that audio playback can be paused during audio interruption, and **false** means the opposite.|

## InterruptAction

Describes the callback invoked for audio interruption or focus gain events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name      | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| actionType | [InterruptActionType](#interruptactiontype) | Yes  | Returned event type. The value **TYPE_ACTIVATED** means the focus gain event, and **TYPE_INTERRUPT** means the audio interruption event.|
| type       | [InterruptType](#interrupttype)             | No  | Type of the audio interruption event.                                              |
| hint       | [InterruptHint](interrupthint)              | No  | Hint provided along with the audio interruption event.                                              |
| activated  | boolean                                     | No  | Whether the focus is gained or released. The value **true** means that the focus is gained or released, and **false** means that the focus fails to be gained or released.|

## VolumeEvent<sup>8+</sup>

Describes the event received by the application when the volume is changed.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name      | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume level. The value range can be obtained by calling **getMinVolume** and **getMaxVolume**.|
| updateUi   | boolean                             | Yes  | Whether to show the volume change in UI.                                    |

## DeviceChangeAction

Describes the device connection status and device information.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name             | Type                                             | Mandatory| Description              |
| :---------------- | :------------------------------------------------ | :--- | :----------------- |
| type              | [DeviceChangeType](#DeviceChangeType)             | Yes  | Device connection status.|
| deviceDescriptors | [AudioDeviceDescriptors](#AudioDeviceDescriptors) | Yes  | Device information.        |

## DeviceChangeType

Enumerates the device connection statuses.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name      | Default Value| Description          |
| :--------- | :----- | :------------- |
| CONNECT    | 0      | Connected.    |
| DISCONNECT | 1      | Disconnected.|

## AudioCapturerOptions<sup>8+</sup>

Describes audio capturer configurations.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name        | Type                                   | Mandatory| Description            |
| ------------ | --------------------------------------- | ---- | ---------------- |
| streamInfo   | [AudioStreamInfo](#audiostreaminfo8)    | Yes  | Audio stream information.|
| capturerInfo | [AudioCapturerInfo](#audiocapturerinfo) | Yes  | Audio capturer information.|

## AudioCapturerInfo<sup>8+</sup><a name="audiocapturerinfo"></a>

Describes audio capturer information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                     | Mandatory| Description            |
| :------------ | :------------------------ | :--- | :--------------- |
| source        | [SourceType](#sourcetype) | Yes  | Audio source type.      |
| capturerFlags | number                    | Yes  | Audio capturer flags.|

## SourceType<sup>8+</sup><a name="sourcetype"></a>

Enumerates the audio source types.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                           | Default Value| Description                  |
| :------------------------------ | :----- | :--------------------- |
| SOURCE_TYPE_INVALID             | -1     | Invalid audio source.        |
| SOURCE_TYPE_MIC                 | 0      | Mic source.           |
| SOURCE_TYPE_VOICE_COMMUNICATION | 7      | Voice communication source.|

## AudioScene<sup>8+</sup><a name="audioscene"></a>

Enumerates the audio scenes.

**System capability**: SystemCapability.Multimedia.Audio.Communication

| Name                  | Default Value| Description                                         |
| :--------------------- | :----- | :-------------------------------------------- |
| AUDIO_SCENE_DEFAULT    | 0      | Default audio scene.                               |
| AUDIO_SCENE_RINGING    | 1      | Ringing audio scene.<br>This is a system API and cannot be called by third-party applications.|
| AUDIO_SCENE_PHONE_CALL | 2      | Phone call audio scene.<br>This is a system API and cannot be called by third-party applications.|
| AUDIO_SCENE_VOICE_CHAT | 3      | Voice chat audio scene.                               |

## AudioManager

Implements audio volume and audio device management. Before calling any API in **AudioManager**, you must use [getAudioManager](#audiogetaudiomanager) to create an **AudioManager** instance.

### setVolume

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

Sets the volume for a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume to set. The value range can be obtained by calling **getMinVolume** and **getMaxVolume**.|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result.                                  |

**Example**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err) => {
    if (err) {
        console.error('Failed to set the volume. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate a successful volume setting.');
});
```

### setVolume

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

Sets the volume for a stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume to set. The value range can be obtained by calling **getMinVolume** and **getMaxVolume**.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
    console.log('Promise returned to indicate a successful volume setting.');
});
```

### getVolume

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the volume of a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the volume.|

**Example**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
       console.error('Failed to obtain the volume. ${err.message}');
       return;
   }
   console.log('Callback invoked to indicate that the volume is obtained.');
});
```

### getVolume

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the volume of a stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the volume.|

**Example**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promise returned to indicate that the volume is obtained.' + value);
});
```

### getMinVolume

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum volume allowed for a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the minimum volume.|

**Example**

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the minimum volume. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the minimum volume is obtained.' + value);
});
```

### getMinVolume

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the minimum volume allowed for a stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the minimum volume.|

**Example**

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promised returned to indicate that the minimum volume is obtained.' + value);
});
```

### getMaxVolume

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum volume allowed for a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                  |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.          |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the maximum volume.|

**Example**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the maximum volume. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the maximum volume is obtained.' + value);
});
```

### getMaxVolume

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the maximum volume allowed for a stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum volume.|

**Example**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data) => {
    console.log('Promised returned to indicate that the maximum volume is obtained.');
});
```

### mute

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Mute status to set. The value **true** means to mute the stream, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result.               |

**Example**

```
audioManager.mute(audio.AudioVolumeType.MEDIA, true, (err) => {
    if (err) {
        console.error('Failed to mute the stream. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the stream is muted.');
});
```

### mute

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

Mutes or unmutes a stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Mute status to set. The value **true** means to mute the stream, and **false** means the opposite.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**


```
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
    console.log('Promise returned to indicate that the stream is muted.');
});
```


### isMute

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is muted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                           |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                   |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the mute status of the stream. The value **true** means that the stream is muted, and **false** means the opposite.|

**Example**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
       console.error('Failed to obtain the mute status. ${err.message}');
       return;
   }
   console.log('Callback invoked to indicate that the mute status of the stream is obtained.' + value);
});
```


### isMute

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is muted. This method uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                  | Description                                                  |
| ---------------------- | ------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the mute status of the stream. The value **true** means that the stream is muted, and **false** means the opposite.|

**Example**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promise returned to indicate that the mute status of the stream is obtained.' + value);
});
```

### isActive

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is active. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                             |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                     |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the active status of the stream. The value **true** means that the stream is active, and **false** means the opposite.|

**Example**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the stream. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the active status of the stream is obtained.' + value);
});
```

### isActive

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is active. This method uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                  | Description                                                    |
| ---------------------- | -------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the active status of the stream. The value **true** means that the stream is active, and **false** means the opposite.|

**Example**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promise returned to indicate that the active status of the stream is obtained.' + value);
});
```

### setRingerMode

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

Sets the ringer mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](#audioringmode) | Yes  | Ringer mode.          |
| callback | AsyncCallback&lt;void&gt;       | Yes  | Callback used to return the result.|

**Example**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err) => {
   if (err) {
       console.error('Failed to set the ringer mode.​ ${err.message}');
       return;
    }
    console.log('Callback invoked to indicate a successful setting of the ringer mode.');
});
```

### setRingerMode

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

Sets the ringer mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](#audioringmode) | Yes  | Ringer mode.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
    console.log('Promise returned to indicate a successful setting of the ringer mode.');
});
```


### getRingerMode

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

Obtains the ringer mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                                | Mandatory| Description                    |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](#audioringmode)&gt; | Yes  | Callback used to return the ringer mode.|

**Example**

```
audioManager.getRingerMode((err, value) => {
   if (err) {
       console.error('Failed to obtain the ringer mode.​ ${err.message}');
       return;
   }
   console.log('Callback invoked to indicate that the ringer mode is obtained.' + value);
});
```


### getRingerMode

getRingerMode(): Promise&lt;AudioRingMode&gt;

Obtains the ringer mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                          | Description                           |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](#audioringmode)&gt; | Promise used to return the ringer mode.|

**Example**

```
audioManager.getRingerMode().then((value) => {
    console.log('Promise returned to indicate that the ringer mode is obtained.' + value);
});
```

### setAudioParameter

setAudioParameter(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets an audio parameter. This API uses an asynchronous callback to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| key      | string                    | Yes  | Key of the audio parameter to set.  |
| value    | string                    | Yes  | Value of the audio parameter to set.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```
audioManager.setAudioParameter('key_example', 'value_example', (err) => {
    if (err) {
        console.error('Failed to set the audio parameter. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate a successful setting of the audio parameter.');
});
```

### setAudioParameter

setAudioParameter(key: string, value: string): Promise&lt;void&gt;

Sets an audio parameter. This API uses a promise to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| key    | string | Yes  | Key of the audio parameter to set.|
| value  | string | Yes  | Value of the audio parameter to set.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```
audioManager.setAudioParameter('key_example', 'value_example').then(() => {
    console.log('Promise returned to indicate a successful setting of the audio parameter.');
});
```

### getAudioParameter

getAudioParameter(key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of an audio parameter. This API uses an asynchronous callback to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                        |
| -------- | --------------------------- | ---- | ---------------------------- |
| key      | string                      | Yes  | Key of the audio parameter whose value is to be obtained.      |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the value of the audio parameter.|

**Example**

```
audioManager.getAudioParameter('key_example', (err, value) => {
    if (err) {
        console.error('Failed to obtain the value of the audio parameter. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the value of the audio parameter is obtained.' + value);
});
```

### getAudioParameter

getAudioParameter(key: string): Promise&lt;string&gt;

Obtains the value of an audio parameter. This API uses a promise to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| key    | string | Yes  | Key of the audio parameter whose value is to be obtained.|

**Return value**

| Type                 | Description                               |
| --------------------- | ----------------------------------- |
| Promise&lt;string&gt; | Promise used to return the value of the audio parameter.|

**Example**

```
audioManager.getAudioParameter('key_example').then((value) => {
    console.log('Promise returned to indicate that the value of the audio parameter is obtained.' + value);
});
```

### getDevices

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the audio devices with a specific flag. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceFlag | [DeviceFlag](#deviceflag)                                    | Yes  | Audio device flag.    |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Yes  | Callback used to return the device list.|

**Example**
```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err, value) => {
   if (err) {
       console.error('Failed to obtain the device list. ${err.message}');
       return;
   }
   console.log('Callback invoked to indicate that the device list is obtained.');
});
```

### getDevices

getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the audio devices with a specific flag. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                     | Mandatory| Description            |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceFlag | [DeviceFlag](#deviceflag) | Yes  | Audio device flag.|

**Return value**

| Type                                                        | Description                     |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise used to return the device list.|

**Example**

```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    console.log('Promise returned to indicate that the device list is obtained.');
});
```

### setDeviceActive

setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets a device to the active state. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description                    |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | Yes  | Audio device type.      |
| active     | boolean                               | Yes  | Active state to set. The value **true** means to set the device to the active state, and **false** means the opposite.          |
| callback   | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result.|

**Example**

```
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true, (err) => {
    if (err) {
        console.error('Failed to set the active status of the device. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the device is set to the active status.');
});
```

### setDeviceActive

setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise&lt;void&gt;

Sets a device to the active state. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description              |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | Yes  | Audio device type.|
| active     | boolean                               | Yes  | Active state to set. The value **true** means to set the device to the active state, and **false** means the opposite.    |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**


```
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true).then(() => {
    console.log('Promise returned to indicate that the device is set to the active status.');
});
```

### isDeviceActive

isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a device is active. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description                    |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | Yes  | Audio device type.      |
| callback   | AsyncCallback&lt;boolean&gt;          | Yes  | Callback used to return the active state of the device.|

**Example**

```
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the device. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the active status of the device is obtained.');
});
```


### isDeviceActive

isDeviceActive(deviceType: ActiveDeviceType): Promise&lt;boolean&gt;

Checks whether a device is active. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description              |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | Yes  | Audio device type.|

**Return value**

| Type                   | Description                     |
| ---------------------- | ------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the active state of the device.|

**Example**

```
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER).then((value) => {
    console.log('Promise returned to indicate that the active status of the device is obtained.' + value);
});
```

### setMicrophoneMute

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes the microphone. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                     | Mandatory| Description                                         |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | Yes  | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                     |

**Example**

```
audioManager.setMicrophoneMute(true, (err) => {
    if (err) {
        console.error('Failed to mute the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the microphone is muted.');
});
```

### setMicrophoneMute

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

Mutes or unmutes the microphone. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name| Type   | Mandatory| Description                                         |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | Yes  | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```
audioManager.setMicrophoneMute(true).then(() => {
    console.log('Promise returned to indicate that the microphone is muted.');
});
```

### isMicrophoneMute

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the microphone is muted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                        | Mandatory| Description                                                   |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the mute status of the microphone. The value **true** means that the microphone is muted, and **false** means the opposite.|

**Example**

```
audioManager.isMicrophoneMute((err, value) => {
    if (err) {
        console.error('Failed to obtain the mute status of the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the mute status of the microphone is obtained.' + value);
});
```

### isMicrophoneMute

isMicrophoneMute(): Promise&lt;boolean&gt;

Checks whether the microphone is muted. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the mute status of the microphone. The value **true** means that the microphone is muted, and **false** means the opposite.|

**Example**


```
audioManager.isMicrophoneMute().then((value) => {
    console.log('Promise returned to indicate that the mute status of the microphone is obtained.', + value);
});
```

### on('volumeChange')<sup>8+</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

Subscribes to system volume change events.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Type of event to subscribe to. The value **volumeChange** means the system volume change event, which is triggered when a system volume change is detected.|
| callback | Callback<[VolumeEvent](#volumeevent8)> | Yes  | Callback used to return the system volume change event.                                                  |

**Example**

```
audioManager.on('volumeChange', (volumeEvent) => {
    console.log('VolumeType of stream: ' + volumeEvent.volumeType);
    console.log('Volume level: ' + volumeEvent.volume);
    console.log('Whether to updateUI: ' + volumeEvent.updateUi);
});
```

### on('ringerModeChange')<sup>8+</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

Subscribes to ringer mode change events.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | Yes  | Type of event to subscribe to. The value **ringerModeChange** means the ringer mode change event, which is triggered when a ringer mode change is detected.|
| callback | Callback<[AudioRingMode](#audioringmode)> | Yes  | Callback used to return the updated ringer mode.                                                  |

**Example**

```
audioManager.on('ringerModeChange', (ringerMode) => {
    console.log('Updated ringermode: ' + ringerMode);
});
```

### on('deviceChange')

on(type: 'deviceChange', callback: Callback<DeviceChangeAction\>): void

Subscribes to device change events. When a device is connected or disconnected, registered clients will receive the callback.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                                | Mandatory| Description                                      |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | Yes  | Type of event to subscribe to. The value **deviceChange** means the device change event, which is triggered when a device connection status change is detected.|
| callback | Callback<[DeviceChangeAction](#DeviceChangeAction)\> | Yes  | Callback used to return the device update details.                        |

**Example**

```
audioManager.on('deviceChange', (deviceChanged) => {
    console.info("device change type : " + deviceChanged.type);
    console.info("device descriptor size : " + deviceChanged.deviceDescriptors.length);
    console.info("device change descriptor : " + deviceChanged.deviceDescriptors[0].deviceRole);
    console.info("device change descriptor : " + deviceChanged.deviceDescriptors[0].deviceType);
});
```

### off('deviceChange')

off(type: 'deviceChange', callback?: Callback<DeviceChangeAction\>): void

Unsubscribes from device change events.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | Yes  | Type of event to unsubscribe from. The value **deviceChange** means the device change event, which is triggered when a device connection status change is detected.|
| callback | Callback<[DeviceChangeAction](#DeviceChangeAction)> | No  | Callback used to return the device update details.                        |

**Example**

```
audioManager.off('deviceChange', (deviceChanged) => {
    console.log("Should be no callback.");
});
```

### on('interrupt')

on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void

Subscribes to audio interruption events. When the application's audio is interrupted by another playback event, the application will receive the callback.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                                         | Mandatory| Description                                                        |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type      | string                                        | Yes  | Type of event to subscribe to. The value **interrupt** means the audio interruption event, which is triggered when the audio playback of the current application is interrupted by another application.|
| interrupt | AudioInterrupt                                | Yes  | Audio interruption event type.                                    |
| callback  | Callback<[InterruptAction](#interruptaction)> | Yes  | Callback invoked for the audio interruption event.                                      |

**Example**

```
var interAudioInterrupt = {
    streamUsage:2,
    contentType:0,
    pauseWhenDucked:true
};
audioManager.on('interrupt', interAudioInterrupt, (InterruptAction) => {
    if (InterruptAction.actionType === 0) {
        console.log("An event to gain the audio focus starts.");
        console.log("Focus gain event:" + JSON.stringify(InterruptAction));
    }
    if (InterruptAction.actionType === 1) {
        console.log("An audio interruption event starts.");
        console.log("Audio interruption event:" + JSON.stringify(InterruptAction));
    }
});
```

### off('interrupt')

off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback\<InterruptAction>): void

Unsubscribes from audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                                         | Mandatory| Description                                                        |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type      | string                                        | Yes  | Type of event to unsubscribe from. The value **interrupt** means the audio interruption event, which is triggered when the audio playback of the current application is interrupted by another application.|
| interrupt | AudioInterrupt                                | Yes  | Audio interruption event type.                                    |
| callback  | Callback<[InterruptAction](#interruptaction)> | No  | Callback invoked for the audio interruption event.                                      |

**Example**

```
var interAudioInterrupt = {
    streamUsage:2,
    contentType:0,
    pauseWhenDucked:true
};
audioManager.off('interrupt', interAudioInterrupt, (InterruptAction) => {
    if (InterruptAction.actionType === 0) {
        console.log("An event to release the audio focus starts.");
        console.log("Focus release event:" + JSON.stringify(InterruptAction));
    }
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene, callback: AsyncCallback<void\>\): void

Sets an audio scene. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                | Mandatory| Description                |
| :------- | :----------------------------------- | :--- | :------------------- |
| scene    | <a href="#audioscene">AudioScene</a> | Yes  | Audio scene to set.      |
| callback | AsyncCallback<void\>                 | Yes  | Callback used to return the result.|

**Example**

```
audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL, (err) => {
   if (err) {
       console.error('Failed to set the audio scene mode.​ ${err.message}');
       return;
    }
    console.log('Callback invoked to indicate a successful setting of the audio scene mode.');
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene\): Promise<void\>

Sets an audio scene. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name| Type                                | Mandatory| Description          |
| :----- | :----------------------------------- | :--- | :------------- |
| scene  | <a href="#audioscene">AudioScene</a> | Yes  | Audio scene to set.|

**Return value**

| Type          | Description                |
| :------------- | :------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL).then(() => {
    console.log('Promise returned to indicate a successful setting of the audio scene mode.');
}).catch ((err) => {
    console.log('Failed to set the audio scene mode');
});
```

### getAudioScene<sup>8+</sup>

getAudioScene\(callback: AsyncCallback<AudioScene\>\): void

Obtains the audio scene. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                               | Mandatory| Description                        |
| :------- | :-------------------------------------------------- | :--- | :--------------------------- |
| callback | AsyncCallback<<a href="#audioscene">AudioScene</a>> | Yes  | Callback used to return the audio scene.|

**Example**

```
audioManager.getAudioScene((err, value) => {
   if (err) {
       console.error('Failed to obtain the audio scene mode.​ ${err.message}');
       return;
   }
   console.log('Callback invoked to indicate that the audio scene mode is obtained.' + value);
});
```


### getAudioScene<sup>8+</sup>

getAudioScene\(\): Promise<AudioScene\>

Obtains the audio scene. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                         | Description                        |
| :-------------------------------------------- | :--------------------------- |
| Promise<<a href="#audioscene">AudioScene</a>> | Promise used to return the audio scene.|

**Example**

```
audioManager.getAudioScene().then((value) => {
    console.log('Promise returned to indicate that the audio scene mode is obtained.' + value);
}).catch ((err) => {
    console.log('Failed to obtain the audio scene mode');
});
```

## AudioDeviceDescriptor

Describes an audio device.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name      | Type                   | Readable| Writable| Description      |
| ---------- | ------------------------- | ---- | ---- | ---------- |
| deviceRole | [DeviceRole](#devicerole) | Yes  | No  | Device role.|
| deviceType | [DeviceType](#devicetype) | Yes  | No  | Device type.|

## AudioDeviceDescriptors

Array of [AudioDeviceDescriptor](#audiodevicedescriptor), which is read-only.

**Example**

```
import audio from '@ohos.multimedia.audio';

function displayDeviceProp(value) {
    deviceRoleValue = value.deviceRole;
    deviceTypeValue = value.deviceType;

}

var deviceRoleValue = null;
var deviceTypeValue = null;
const promise = audio.getAudioManager().getDevices(1);
promise.then(function (value) {
    console.info('AudioFrameworkTest: Promise: getDevices OUTPUT_DEVICES_FLAG');
    value.forEach(displayDeviceProp);
    if (deviceTypeValue != null && deviceRoleValue != null){
        console.info('AudioFrameworkTest: Promise: getDevices : OUTPUT_DEVICES_FLAG :  PASS');
    }
    else{
        console.info('AudioFrameworkTest: Promise: getDevices : OUTPUT_DEVICES_FLAG :  FAIL');
    }
});
```

## AudioRenderer<sup>8+</sup>

Provides APIs for audio rendering. Before calling any API in **AudioRenderer**, you must use [createAudioRenderer](#audiocreateaudiorenderer8) to create an **AudioRenderer** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name | Type                    | Readable| Writable| Description              |
| ----- | -------------------------- | ---- | ---- | ------------------ |
| state<sup>8+</sup> | [AudioState](#audiostate8) | Yes  | No  | Audio renderer state.|

**Example**

```
var state = audioRenderer.state;
```

### getRendererInfo<sup>8+</sup>

getRendererInfo(callback: AsyncCallback<AudioRendererInfo\>): void

Obtains the renderer information of this **AudioRenderer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                    | Mandatory| Description                  |
| :------- | :------------------------------------------------------- | :--- | :--------------------- |
| callback | AsyncCallback<[AudioRendererInfo](#audiorendererinfo8)\> | Yes  | Callback used to return the renderer information.|

**Example**

```
audioRenderer.getRendererInfo((err, rendererInfo) => {
    console.log('Renderer GetRendererInfo:');
    console.log('Renderer content:' + rendererInfo.content);
    console.log('Renderer usage:' + rendererInfo.usage);
    console.log('Renderer flags:' + rendererInfo.rendererFlags);
});
```

### getRendererInfo<sup>8+</sup>

getRendererInfo(): Promise<AudioRendererInfo\>

Obtains the renderer information of this **AudioRenderer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                              | Description                           |
| -------------------------------------------------- | ------------------------------- |
| Promise<[AudioRendererInfo](#audiorendererinfo8)\> | Promise used to return the renderer information.|

**Example**

```
var resultFlag = true;
audioRenderer.getRendererInfo().then((rendererInfo) => {
    console.log('Renderer GetRendererInfo:');
    console.log('Renderer content:' + rendererInfo.content);
    console.log('Renderer usage:' + rendererInfo.usage);
    console.log('Renderer flags:' + rendererInfo.rendererFlags);
}).catch((err) => {
    console.log('AudioFrameworkRenderLog: RendererInfo :ERROR: '+err.message);
    resultFlag = false;
});
```

### getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

Obtains the stream information of this **AudioRenderer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                | Mandatory| Description                |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | Yes  | Callback used to return the stream information.|

**Example**

```
audioRenderer.getStreamInfo((err, streamInfo) => {
    console.log('Renderer GetStreamInfo:');
    console.log('Renderer sampling rate:' + streamInfo.samplingRate);
    console.log('Renderer channel:' + streamInfo.channels);
    console.log('Renderer format:' + streamInfo.sampleFormat);
    console.log('Renderer encoding type:' + streamInfo.encodingType);
});
```

### getStreamInfo<sup>8+</sup>

getStreamInfo(): Promise<AudioStreamInfo\>

Obtains the stream information of this **AudioRenderer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                          | Description                  |
| :--------------------------------------------- | :--------------------- |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | Promise used to return the stream information.|

**Example**

```
audioRenderer.getStreamInfo().then((streamInfo) => {
    console.log('Renderer GetStreamInfo:');
    console.log('Renderer sampling rate:' + streamInfo.samplingRate);
    console.log('Renderer channel:' + streamInfo.channels);
    console.log('Renderer format:' + streamInfo.sampleFormat);
    console.log('Renderer encoding type:' + streamInfo.encodingType);
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

Starts the renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```
audioRenderer.start((err) => {
    if (err) {
        console.error('Renderer start failed.');
    } else {
        console.info('Renderer start success.');
    }
});
```

### start<sup>8+</sup>

start(): Promise<void\>

Starts the renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
audioRenderer.start().then(() => {
    console.log('Renderer started');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses rendering. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```
audioRenderer.pause((err) => {
    if (err) {
        console.error('Renderer pause failed');
    } else {
        console.log('Renderer paused.');
    }
});
```

### pause<sup>8+</sup>

pause(): Promise\<void>

Pauses rendering. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
audioRenderer.pause().then(() => {
    console.log('Renderer paused');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### drain<sup>8+</sup>

drain(callback: AsyncCallback\<void>): void

Drains the playback buffer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```
audioRenderer.drain((err) => {
    if (err) {
        console.error('Renderer drain failed');
    } else {
        console.log('Renderer drained.');
    }
});
```

### drain<sup>8+</sup>

drain(): Promise\<void>

Drains the playback buffer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
audioRenderer.drain().then(() => {
    console.log('Renderer drained successfully');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

Stops rendering. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```
audioRenderer.stop((err) => {
    if (err) {
        console.error('Renderer stop failed');
    } else {
        console.log('Renderer stopped.');
    }
});
```

### stop<sup>8+</sup>

stop(): Promise\<void>

Stops rendering. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
audioRenderer.stop().then(() => {
    console.log('Renderer stopped successfully');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

Releases the renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```
audioRenderer.release((err) => {
    if (err) {
        console.error('Renderer release failed');
    } else {
        console.log('Renderer released.');
    }
});
```

### release<sup>8+</sup>

release(): Promise\<void>

Releases the renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
audioRenderer.release().then(() => {
    console.log('Renderer released successfully');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### write<sup>8+</sup>

write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void

Writes the buffer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| buffer   | ArrayBuffer            | Yes  | Buffer to be written.                               |
| callback | AsyncCallback\<number> | Yes  | Returns the number of bytes written if the operation is successful; returns an error code otherwise.|

**Example**

```
import audio from '@ohos.multimedia.audio';
import fileio from '@ohos.fileio';

let ss = fileio.createStreamSync(filePath, 'r');
let buf = new ArrayBuffer(bufferSize);
ss.readSync(buf);
audioRenderer.write(buf, (err, writtenbytes) => {
    if (writtenbytes < 0) {
        console.error('write failed.');
    } else {
       console.log('Actual written bytes: ' + writtenbytes);
    }
});
```

### write<sup>8+</sup>

write(buffer: ArrayBuffer): Promise\<number>

Writes the buffer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Returns the number of bytes written if the operation is successful; returns an error code otherwise.|

**Example**

```
import audio from '@ohos.multimedia.audio';
import fileio from '@ohos.fileio';

var filePath = 'data/StarWars10s-2C-48000-4SW.wav';
let ss = fileio.createStreamSync(filePath, 'r');
let buf = new ArrayBuffer(bufferSize);
ss.readSync(buf);
audioRenderer.write(buf).then((writtenbytes) => {
    if (writtenbytes < 0) {
        console.error('write failed.');
    } else {
        console.log('Actual written bytes: ' + writtenbytes);
    }
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback\<number>): void

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                  | Mandatory| Description            |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the timestamp.|

**Example**

```
audioRenderer.getAudioTime((err, timestamp) => {
    console.log('Current timestamp: ' + timestamp);
});
```

### getAudioTime<sup>8+</sup>

getAudioTime(): Promise\<number>

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                   |
| ---------------- | ----------------------- |
| Promise\<number> | Promise used to return the timestamp.|

**Example**

```
audioRenderer.getAudioTime().then((timestamp) => {
    console.log('Current timestamp: ' + timestamp);
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback\<number>): void

Obtains a reasonable minimum buffer size in bytes for rendering. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the buffer size.|

**Example**

```
var bufferSize = audioRenderer.getBufferSize(async(err, bufferSize) => {
    if (err) {
        console.error('getBufferSize error');
    }
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(): Promise\<number>

Obtains a reasonable minimum buffer size in bytes for rendering. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise\<number> | Promise used to return the buffer size.|

**Example**

```
var bufferSize;
await audioRenderer.getBufferSize().then(async function (data) => {
    console.info('AudioFrameworkRenderLog: getBufferSize :SUCCESS '+data);
    bufferSize=data;
}).catch((err) => {
    console.info('AudioFrameworkRenderLog: getBufferSize :ERROR : '+err.message);
});
```

### setRenderRate<sup>8+</sup>

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void

Sets the render rate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                    | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| rate     | [AudioRendererRate](#audiorendererrate8) | Yes  | Audio render rate.            |
| callback | AsyncCallback\<void>                     | Yes  | Callback used to return the result.|

**Example**

```
audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL, (err) => {
    if (err) {
        console.error('Failed to set params');
    } else {
        console.log('Callback invoked to indicate a successful render rate setting.');
    }
});
```

### setRenderRate<sup>8+</sup>

setRenderRate(rate: AudioRendererRate): Promise\<void>

Sets the render rate. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type                                    | Mandatory| Description        |
| ------ | ---------------------------------------- | ---- | ------------ |
| rate   | [AudioRendererRate](#audiorendererrate8) | Yes  | Audio render rate.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL).then(() => {
    console.log('setRenderRate SUCCESS');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### getRenderRate<sup>8+</sup>

getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void

Obtains the current render rate. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                   | Mandatory| Description              |
| -------- | ------------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback<[AudioRendererRate](#audiorendererrate8)> | Yes  | Callback used to return the audio render rate.|

**Example**

```
audioRenderer.getRenderRate((err, renderrate) => {
    console.log('getRenderRate: ' + renderrate);
});
```

### getRenderRate<sup>8+</sup>

getRenderRate(): Promise\<AudioRendererRate>

Obtains the current render rate. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                             | Description                     |
| ------------------------------------------------- | ------------------------- |
| Promise<[AudioRendererRate](#audiorendererrate8)> | Promise used to return the audio render rate.|

**Example**

```
audioRenderer.getRenderRate().then((renderRate) => {
    console.log('getRenderRate: ' + renderRate);
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### on('interrupt')<sup>9+</sup>

on(type: 'interrupt', callback: Callback\<InterruptEvent>): void

Subscribes to audio interruption events. This API uses a callback to get interrupt events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                       | Yes  | Type of event to subscribe to. The value **interrupt** means the audio interruption event, which is triggered when audio playback is interrupted.|
| callback | Callback<[InterruptEvent](#interruptevent9)> | Yes  | Callback used to return the audio interruption event.                                    |

**Example**

```
var isPlay;
var started;
audioRenderer.on('interrupt', async(interruptEvent) => {
    if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
        switch (interruptEvent.hintType) {
            case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
                console.log('Force paused. Stop writing');
                isPlay = false;
                break;
            case audio.InterruptHint.INTERRUPT_HINT_STOP:
                console.log('Force stopped. Stop writing');
                isPlay = false;
                break;
        }
    } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
        switch (interruptEvent.hintType) {
            case audio.InterruptHint.INTERRUPT_HINT_RESUME:
                console.log('Resume force paused renderer or ignore');
                await audioRenderer.start().then(async function () {
                    console.info('AudioInterruptMusic: renderInstant started :SUCCESS ');
                    started = true;
                }).catch((err) => {
                    console.info('AudioInterruptMusic: renderInstant start :ERROR : '+err.message);
                    started = false;
                });
                if (started) {
                    isPlay = true;
                    console.info('AudioInterruptMusic Renderer started : isPlay : '+isPlay);
                } else {
                    console.error('AudioInterruptMusic Renderer start failed');
                }
                break;
            case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
                console.log('Choose to pause or ignore');
                if (isPlay == true) {
                    isPlay == false;
                    console.info('AudioInterruptMusic: Media PAUSE : TRUE');
                }
                else {
                    isPlay = true;
                    console.info('AudioInterruptMusic: Media PLAY : TRUE');
                }
                break;
        }
    }
});
```

### on('markReach')<sup>8+</sup>

on(type: 'markReach', frame: number, callback: (position: number) => {}): void

Subscribes to mark reached events. When the number of frames rendered reaches the value of the **frame** parameter, the callback is invoked.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                    | Mandatory| Description                                     |
| :------- | :----------------------- | :--- | :---------------------------------------- |
| type     | string                   | Yes  | Type of event to subscribe to. The value **markReach** means the mark reached event, which is triggered when the number of frames captured reaches the value of the **frame** parameter.|
| frame    | number                   | Yes  | Number of frames to trigger the event. The value must be greater than **0**.        |
| callback | (position: number) => {} | Yes  | Callback invoked when the event is triggered.                   |

**Example**

```
audioRenderer.on('markReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
    }
});
```


### off('markReach') <sup>8+</sup>

off(type: 'markReach'): void

Unsubscribes from mark reached events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type  | Mandatory| Description                                             |
| :----- | :----- | :--- | :------------------------------------------------ |
| type   | string | Yes  | Type of event to unsubscribe from. The value is fixed at **markReach**.|

**Example**

```
audioRenderer.off('markReach');
```

### on('periodReach') <sup>8+</sup>

on(type: "periodReach", frame: number, callback: (position: number) => {}): void

Subscribes to period reached events. When the period of frame rendering reaches the value of the **frame** parameter, the callback is invoked.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                    | Mandatory| Description                                       |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | Yes  | Type of event to subscribe to. The value **periodReach** means the period reached event, which is triggered when the period of frame rendering reaches the value of the **frame** parameter.|
| frame    | number                   | Yes  | Period during which frame rendering is listened. The value must be greater than **0**.          |
| callback | (position: number) => {} | Yes  | Callback invoked when the event is triggered.                     |

**Example**

```
audioRenderer.on('periodReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
    }
});
```

### off('periodReach') <sup>8+</sup>

off(type: 'periodReach'): void

Unsubscribes from period reached events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| :----- | :----- | :--- | :-------------------------------------------------- |
| type   | string | Yes  | Type of event to unsubscribe from. The value is fixed at **periodReach**.|

**Example**

```
audioRenderer.off('periodReach')
```

### on('stateChange') <sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

Subscribes to state change events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Type of event to subscribe to. The value **stateChange** means the state change event.|
| callback | [AudioState](#audiostate8) | Yes  | Callback used to return the state change.                           |

**Example**

```
audioRenderer.on('stateChange', (state) => {
    if (state == 1) {
        console.log("audio renderer state is: STATE_PREPARED");
    }
    if (state == 2) {
        console.log("audio renderer state is: STATE_RUNNING");
    }
});
```

## AudioCapturer<sup>8+</sup>

Provides APIs for audio capture. Before calling any API in **AudioCapturer**, you must use [createAudioCapturer](#audiocreateaudiocapturer8) to create an **AudioCapturer** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name | Type                    | Readable| Writable| Description            |
| :---- | :------------------------- | :--- | :--- | :--------------- |
| state<sup>8+</sup>  | [AudioState](#audiostate8) | Yes| No  | Audio capturer state.|

**Example**

```
var state = audioCapturer.state;
```

### getCapturerInfo<sup>8+</sup>

getCapturerInfo(callback: AsyncCallback<AudioCapturerInfo\>): void

Obtains the capturer information of this **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                             | Mandatory| Description                                |
| :------- | :-------------------------------- | :--- | :----------------------------------- |
| callback | AsyncCallback<AudioCapturerInfo\> | Yes  | Callback used to return the capturer information.|

**Example**

```
audioCapturer.getCapturerInfo((err, capturerInfo) => {
    if (err) {
        console.error('Failed to get capture info');
    } else {
        console.log('Capturer getCapturerInfo:');
        console.log('Capturer source:' + capturerInfo.source);
        console.log('Capturer flags:' + capturerInfo.capturerFlags);
    }
});
```


### getCapturerInfo<sup>8+</sup>

getCapturerInfo(): Promise<AudioCapturerInfo\>

Obtains the capturer information of this **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                             | Description                               |
| :------------------------------------------------ | :---------------------------------- |
| Promise<[AudioCapturerInfo](#audiocapturerinfo)\> | Promise used to return the capturer information.|

**Example**

```
audioCapturer.getCapturerInfo().then((audioParamsGet) => {
    if (audioParamsGet != undefined) {
        console.info('AudioFrameworkRecLog: Capturer CapturerInfo:');
        console.info('AudioFrameworkRecLog: Capturer SourceType:' + audioParamsGet.source);
        console.info('AudioFrameworkRecLog: Capturer capturerFlags:' + audioParamsGet.capturerFlags);
    }else {
        console.info('AudioFrameworkRecLog: audioParamsGet is : '+audioParamsGet);
        console.info('AudioFrameworkRecLog: audioParams getCapturerInfo are incorrect: ');
    }
}).catch((err) => {
    console.log('AudioFrameworkRecLog: CapturerInfo :ERROR: '+err.message);
});
```

### getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

Obtains the stream information of this **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                                                | Mandatory| Description                            |
| :------- | :--------------------------------------------------- | :--- | :------------------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | Yes  | Callback used to return the stream information.|

**Example**

```
audioCapturer.getStreamInfo((err, streamInfo) => {
    if (err) {
        console.error('Failed to get stream info');
    } else {
        console.log('Capturer GetStreamInfo:');
        console.log('Capturer sampling rate:' + streamInfo.samplingRate);
        console.log('Capturer channel:' + streamInfo.channels);
        console.log('Capturer format:' + streamInfo.sampleFormat);
        console.log('Capturer encoding type:' + streamInfo.encodingType);
    }
});
```

### getStreamInfo<sup>8+</sup>

getStreamInfo(): Promise<AudioStreamInfo\>

Obtains the stream information of this **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                          | Description                           |
| :--------------------------------------------- | :------------------------------ |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | Promise used to return the stream information.|

**Example**

```
audioCapturer.getStreamInfo().then((audioParamsGet) => {
    console.info('getStreamInfo:');
    console.info('sampleFormat:' + audioParamsGet.sampleFormat);
    console.info('samplingRate:' + audioParamsGet.samplingRate);
    console.info('channels:' + audioParamsGet.channels);
    console.info('encodingType:' + audioParamsGet.encodingType);
}).catch((err) => {
    console.log('getStreamInfo :ERROR: ' + err.message);
});
```

### start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

Starts capturing. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
audioCapturer.start((err) => {
    if (err) {
        console.error('Capturer start failed.');
    } else {
        console.info('Capturer start success.');
    }
});
```


### start<sup>8+</sup>

start(): Promise<void\>

Starts capturing. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type          | Description                         |
| :------------- | :---------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
audioCapturer.start().then(() => {
    console.info('AudioFrameworkRecLog: ---------START---------');
    console.info('AudioFrameworkRecLog: Capturer started :SUCCESS ');
    console.info('AudioFrameworkRecLog: AudioCapturer : STATE : '+audioCapturer.state);
    console.info('AudioFrameworkRecLog: Capturer started :SUCCESS ');
    if ((audioCapturer.state == audio.AudioState.STATE_RUNNING)) {
        stateFlag = true;
    }
}).catch((err) => {
    console.info('AudioFrameworkRecLog: Capturer start :ERROR : '+err.message);
    stateFlag=false;
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback<void\>): void

Stops capturing. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
audioCapturer.stop((err) => {
    if (err) {
        console.error('Capturer stop failed');
    } else {
        console.log('Capturer stopped.');
    }
});
```


### stop<sup>8+</sup>

stop(): Promise<void\>

Stops capturing. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type          | Description                         |
| :------------- | :---------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
audioCapturer.stop().then(() => {
    console.info('AudioFrameworkRecLog: ---------RELEASE RECORD---------');
    console.info('AudioFrameworkRecLog: Capturer stopped : SUCCESS');
    if ((audioCapturer.state == audioCapturer.AudioState.STATE_STOPPED)){
        stateFlag=true;
        console.info('AudioFrameworkRecLog: resultFlag : '+stateFlag);
    }
}).catch((err) => {
    console.info('AudioFrameworkRecLog: Capturer stop:ERROR : '+err.message);
    stateFlag=false;
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback<void\>): void

Releases this **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                | Mandatory| Description                               |
| :------- | :------------------- | :--- | :---------------------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. |

**Example**

```
audioCapturer.release((err) => {
    if (err) {
        console.error('capturer release failed');
    } else {
        console.log('capturer released.');
    }
});
```


### release<sup>8+</sup>

release(): Promise<void\>

Releases this **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type          | Description                         |
| :------------- | :---------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
audioCapturer.release().then(() => {
    console.info('AudioFrameworkRecLog: ---------RELEASE RECORD---------');
    console.info('AudioFrameworkRecLog: Capturer release : SUCCESS');
    console.info('AudioFrameworkRecLog: AudioCapturer : STATE : '+audioCapturer.state);
    stateFlag=true;
    console.info('AudioFrameworkRecLog: stateFlag : '+stateFlag);
    expect(stateFlag).assertTrue();
    done();
}).catch((err) => {
    console.info('AudioFrameworkRecLog: Capturer stop:ERROR : '+err.message);
    stateFlag=false
});
```


### read<sup>8+</sup>

read(size: number, isBlockingRead: boolean, callback: AsyncCallback<ArrayBuffer\>): void

Reads the buffer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name        | Type                       | Mandatory| Description                            |
| :------------- | :-------------------------- | :--- | :------------------------------- |
| size           | number                      | Yes  | Number of bytes to read.                  |
| isBlockingRead | boolean                     | Yes  | Whether to block the read operation.                |
| callback       | AsyncCallback<ArrayBuffer\> | Yes  | Callback used to return the buffer.|

**Example**

```
audioCapturer.read(bufferSize, true, async(err, buffer) => {
    if (!err) {
        console.log("Success in reading the buffer data");
    }
});
```


### read<sup>8+</sup>

read(size: number, isBlockingRead: boolean): Promise<ArrayBuffer\>

Reads the buffer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name        | Type   | Mandatory| Description            |
| :------------- | :------ | :--- | :--------------- |
| size           | number  | Yes  | Number of bytes to read.  |
| isBlockingRead | boolean | Yes  | Whether to block the read operation.|

**Return value**

| Type                 | Description                                                  |
| :-------------------- | :----------------------------------------------------- |
| Promise<ArrayBuffer\> | Returns the buffer data read if the operation is successful; returns an error code otherwise.|

**Example**

```
audioCapturer.read(bufferSize, true).then((buffer) => {
    console.info('buffer read successfully');
}).catch((err) => {
    console.info('ERROR : '+err.message);
});
```


### getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback<number\>): void

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                  | Mandatory| Description                          |
| :------- | :--------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<number\> | Yes  | Callback used to return the timestamp.|

**Example**

```
audioCapturer.getAudioTime((err, timestamp) => {
    console.log('Current timestamp: ' + timestamp);
});
```


### getAudioTime<sup>8+</sup>

getAudioTime(): Promise<number\>

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type            | Description                         |
| :--------------- | :---------------------------- |
| Promise<number\> | Promise used to return the timestamp.|

**Example**

```
audioCapturer.getAudioTime().then((audioTime) => {
    console.info('AudioFrameworkRecLog: AudioCapturer getAudioTime : Success' + audioTime );
}).catch((err) => {
    console.info('AudioFrameworkRecLog: AudioCapturer Created : ERROR : '+err.message);
});
```


### getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback<number\>): void

Obtains a reasonable minimum buffer size in bytes for capturing. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                  | Mandatory| Description                                |
| :------- | :--------------------- | :--- | :----------------------------------- |
| callback | AsyncCallback<number\> | Yes  | Callback used to return the buffer size.|

**Example**

```
audioCapturer.getBufferSize((err, bufferSize) => {
    if (!err) {
        console.log('BufferSize : ' + bufferSize);
        audioCapturer.read(bufferSize, true).then((buffer) => {
            console.info('Buffer read is ' + buffer );
        }).catch((err) => {
            console.info('AudioFrameworkRecLog: AudioCapturer Created : ERROR : '+err.message);
        });
    }
});
```


### getBufferSize<sup>8+</sup>

getBufferSize(): Promise<number\>

Obtains a reasonable minimum buffer size in bytes for capturing. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type            | Description                               |
| :--------------- | :---------------------------------- |
| Promise<number\> | Promise used to return the buffer size.|

**Example**

```
audioCapturer.getBufferSize().then((bufferSize) => {
    if (!err) {
        console.log('BufferSize : ' + bufferSize);
        audioCapturer.read(bufferSize, true).then((buffer) => {
            console.info('Buffer read is ' + buffer );
        }).catch((err) => {
            console.info('ERROR : '+err.message);
        });
    }
});
```


### on('markReach')<sup>8+</sup>

on(type: 'markReach', frame: number, callback: (position: number) => {}): void

Subscribes to mark reached events. When the number of frames captured reaches the value of the **frame** parameter, the callback is invoked.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                   | Mandatory| Description                                      |
| :------- | :---------------------- | :--- | :----------------------------------------- |
| type     | string                  | Yes  | Type of event to subscribe to. The value **markReach** means the mark reached event, which is triggered when the number of frames captured reaches the value of the **frame** parameter. |
| frame    | number                  | Yes  | Number of frames to trigger the event. The value must be greater than **0**.          |
| callback | position: number) => {} | Yes  | Callback invoked when the event is triggered.|

**Example**

```
audioCapturer.on('markReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
    }
});
```

### off('markReach')<sup>8+</sup>

off(type: 'markReach'): void

Unsubscribes from mark reached events.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name| Type  | Mandatory| Description                                         |
| :----- | :----- | :--- | :-------------------------------------------- |
| type   | string | Yes  | Type of event to unsubscribe from. The value **markReach** means the mark reached event, which is triggered when the number of frames captured reaches the value of the **frame** parameter.|

**Example**

```
audioCapturer.off('markReach');
```

### on('periodReach')<sup>8+</sup>

on(type: "periodReach", frame: number, callback: (position: number) => {}): void

Subscribes to mark reached events. When the period of frame capturing reaches the value of the **frame** parameter, the callback is invoked.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                    | Mandatory| Description                                       |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | Yes  | Type of event to subscribe to. The value **periodReach** means the period reached event, which is triggered when the period of frame capturing reaches the value of the **frame** parameter.|
| frame    | number                   | Yes  | Period during which frame rendering is listened. The value must be greater than **0**.           |
| callback | (position: number) => {} | Yes  | Callback invoked when the event is triggered.   |

**Example**

```
audioCapturer.on('periodReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
    }
});
```

### off('periodReach')<sup>8+</sup>

off(type: 'periodReach'): void

Unsubscribes from period reached events.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name| Type  | Mandatory| Description                                           |
| :----- | :----- | :--- | :---------------------------------------------- |
| type   | string | Yes  | Type of event to unsubscribe from. The value **periodReach** means the period reached event, which is triggered when the period of frame capturing reaches the value of the **frame** parameter.|

**Example**

```
audioCapturer.off('periodReach')
```

### on('stateChange') <sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

Subscribes to state change events.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Type of event to subscribe to. The value **stateChange** means the state change event.|
| callback | [AudioState](#audiostate8) | Yes  | Callback used to return the state change.                           |

**Example**

```
audioCapturer.on('stateChange', (state) => {
    if (state == 1) {
        console.log("audio capturer state is: STATE_PREPARED");
    }
    if (state == 2) {
        console.log("audio capturer state is: STATE_RUNNING");
    }
});
```
