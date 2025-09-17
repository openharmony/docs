# @ohos.multimedia.audio (Audio Management) (System API)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

The module provides basic audio management capabilities, including audio volume and audio device management, and audio data collection and rendering.

This module provides the following common audio-related functions:

- [AudioManager](#audiomanager): audio management.
- [TonePlayer](#toneplayer9): tone player, used to manage and play Dual Tone Multi Frequency (DTMF) tones, such as dial tones and ringback tones.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.multimedia.audio (Audio Management)](arkts-apis-audio.md).

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## Constants

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                                   | Type     | Read-Only| Description              |
| --------------------------------------- | ----------| ---- | ------------------ |
| LOCAL_NETWORK_ID<sup>9+</sup>           | string    | Yes| Network ID of the local device.|

## audio.createTonePlayer<sup>9+</sup>

createTonePlayer(options: AudioRendererInfo, callback: AsyncCallback&lt;TonePlayer&gt;): void

Creates a TonePlayer instance. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Parameters**

| Name  | Type                                            | Mandatory| Description           |
| -------- | ----------------------------------------------- | ---- | -------------- |
| options  | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)        | Yes  | Audio renderer information.|
| callback | AsyncCallback<[TonePlayer](#toneplayer9)>       | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the TonePlayer instance obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioRendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_DTMF,
  rendererFlags : 0
};
let tonePlayer: audio.TonePlayer;

audio.createTonePlayer(audioRendererInfo, (err, data) => {
  console.info(`callback call createTonePlayer: audioRendererInfo: ${audioRendererInfo}`);
  if (err) {
    console.error(`callback call createTonePlayer return error: ${err.message}`);
  } else {
    console.info(`callback call createTonePlayer return data: ${data}`);
    tonePlayer = data;
  }
});
```

## audio.createTonePlayer<sup>9+</sup>

createTonePlayer(options: AudioRendererInfo): Promise&lt;TonePlayer&gt;

Creates a TonePlayer instance. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Parameters**

| Name | Type                                          | Mandatory| Description        |
| :------ | :---------------------------------------------| :--- | :----------- |
| options | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)      | Yes  | Audio renderer information.|

**Return value**

| Type                                     | Description                            |
| ----------------------------------------- | -------------------------------- |
| Promise<[TonePlayer](#toneplayer9)>       | Promise used to return the TonePlayer instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let tonePlayer: audio.TonePlayer;
async function createTonePlayerBefore(){
  let audioRendererInfo: audio.AudioRendererInfo = {
    usage : audio.StreamUsage.STREAM_USAGE_DTMF,
    rendererFlags : 0
  };
  tonePlayer = await audio.createTonePlayer(audioRendererInfo);
}
```

## audio.createAsrProcessingController<sup>12+</sup>

createAsrProcessingController(audioCapturer: AudioCapturer): AsrProcessingController

Creates an Automatic Speech Recognition (ASR) processing controller.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type                                          | Mandatory| Description      |
| :------ | :---------------------------------------------| :--- |:---------|
| audioCapturer | [AudioCapturer](arkts-apis-audio-AudioCapturer.md)      | Yes  | Callback used to return the AudioCapturer instance.|

**Return value**

| Type                                                   | Description        |
|-------------------------------------------------------| ------------ |
| [AsrProcessingController](#asrprocessingcontroller12) | ASR processing controller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
};

let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};

audio.createAudioCapturer(audioCapturerOptions, (err, data) => {
  if (err) {
    console.error(`AudioCapturer Created : Error: ${err}`);
  } else {
    console.info('AudioCapturer Created : Success : SUCCESS');
    let audioCapturer = data;
    let asrProcessingController = audio.createAsrProcessingController(audioCapturer);
    console.info('AsrProcessingController Created : Success : SUCCESS');
  }
});
```

## AudioVolumeType

Enumerates the audio stream types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                        | Value     | Description      |
| ---------------------------- | ------ | ---------- |
| SYSTEM<sup>20+</sup>         | 6      | System sound.|
| ULTRASONIC<sup>10+</sup>     | 10     | Audio stream for ultrasonic.|
| ALL<sup>9+</sup>             | 100    | All public audio streams.|

## InterruptRequestResultType<sup>9+</sup>

Enumerates the result types of audio interruption requests.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

| Name                        | Value     | Description      |
| ---------------------------- | ------ | ---------- |
| INTERRUPT_REQUEST_GRANT      | 0      | The audio interruption request is accepted.|
| INTERRUPT_REQUEST_REJECT     | 1      | The audio interruption request is denied. There may be a stream with a higher priority.|

## DeviceFlag

Enumerates the audio device flags.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                           |  Value    | Description                       |
| ------------------------------- | ------ |---------------------------|
| NONE_DEVICES_FLAG<sup>9+</sup>  | 0      | No device is available.|
| DISTRIBUTED_OUTPUT_DEVICES_FLAG<sup>9+</sup> | 4   | Distributed output device.|
| DISTRIBUTED_INPUT_DEVICES_FLAG<sup>9+</sup>  | 8   | Distributed input device.|
| ALL_DISTRIBUTED_DEVICES_FLAG<sup>9+</sup>    | 12  | Distributed input and output device.|

## EffectFlag<sup>18+</sup>

Enumerates the audio effect flags.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                           |  Value    | Description                       |
| ------------------------------- | ------ |------------------------------|
| RENDER_EFFECT_FLAG  | 0      | Rendered audio effect flag.  |
| CAPTURE_EFFECT_FLAG | 1      | Captured audio effect flag.  |

## AudioEffectProperty<sup>18+</sup>

Describes the audio effect properties.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name              | Type| Read-Only| Optional| Description      |
| ------------------ | ---- | ---- |---| --------- |
| name         | string | No| No| Audio effect name.|
| category     | string | No| No| Audio effect category.|
| flag        | [EffectFlag](#effectflag18) | No| No| Audio effect flag.|

## StreamUsage

Enumerates the audio stream usage.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                                     |  Value   | Description                         |
| ------------------------------------------| ------ |-----------------------------|
| STREAM_USAGE_SYSTEM<sup>10+</sup>         | 9      | System tone (such as screen lock sound effect or key tone).|
| STREAM_USAGE_DTMF<sup>10+</sup>           | 14     | Dial tone.|
| STREAM_USAGE_ENFORCED_TONE<sup>10+</sup>  | 15     | Forcible tone (such as camera shutter sound effect).|
| STREAM_USAGE_ULTRASONIC<sup>10+</sup>     | 16     | Ultrasonic (currently provided only for MSDP).|
| STREAM_USAGE_VOICE_CALL_ASSISTANT<sup>12+</sup>     | 21     | Voice assistant for calls.|

## InterruptRequestType<sup>9+</sup>

Enumerates the audio interruption request types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

| Name                              |  Value    | Description                      |
| ---------------------------------- | ------ | ------------------------- |
| INTERRUPT_REQUEST_TYPE_DEFAULT     | 0      |  Default type, which can be used to interrupt audio requests. |

## VolumeFlag<sup>12+</sup>

Enumerates the volume-related operations.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                              | Value| Description      |
| ---------------------------------- |---|----------|
| FLAG_SHOW_SYSTEM_UI | 1 | Displays the system volume bar.|

## AsrNoiseSuppressionMode<sup>12+</sup>

Enumerates the noise suppression modes in ASR.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name|  Value| Description|
|-------|-------|-------|
| BYPASS | 0 |Bypass noise suppression.|
| STANDARD | 1 |Standard noise suppression.|
| NEAR_FIELD | 2 |Near-field noise suppression.|
| FAR_FIELD | 3 |Far-field noise suppression.|

## AsrAecMode<sup>12+</sup>

Enumerates the Acoustic Echo Cancellation (AEC) modes in ASR.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name|  Value| Description|
|-------|-------|-------|
| BYPASS | 0 |Bypass AEC.|
| STANDARD | 1 |Standard AEC.|

## AsrWhisperDetectionMode<sup>12+</sup>

Enumerates the ASR whisper detection modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name | Value| Description      |
|-----|---|----------|
| BYPASS  | 0 | ASR whisper detection disabled.|
| STANDARD | 1 | Standard ASR whisper detection model. |

## AsrVoiceControlMode<sup>12+</sup>

Enumerates the ASR voice control modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name                     | Value| Description                                   |
|-------------------------|---|---------------------------------------|
| AUDIO_2_VOICE_TX        | 0 | ASR voice control takes effect only for media audio streams.                           |
| AUDIO_MIX_2_VOICE_TX    | 1 | ASR voice control takes effect for both media audio streams and microphone audio streams.                     |
| AUDIO_2_VOICE_TX_EX     | 2 | ASR voice control takes effect only for media audio streams. Media streams are reported to the call recording module.    |
| AUDIO_MIX_2_VOICE_TX_EX | 3 | ASR voice control takes effect for both media audio streams and microphone audio streams. Media streams are reported to the call recording module.|

## AsrVoiceMuteMode<sup>12+</sup>

Enumerates the ASR voice mute modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name            | Value| Description                 |
|----------------|---|---------------------|
| OUTPUT_MUTE    | 0 | The local output is muted.           |
| INPUT_MUTE     | 1 | The local microphone input is muted.       |
| TTS_MUTE       | 2 | The media audio delivered by the application is muted locally.    |
| CALL_MUTE      | 3 | The audio streams of calls are muted.         |
| OUTPUT_MUTE_EX | 4 | The local output is muted, and media audio streams are sent to the call recording module.|

## InterruptResult<sup>9+</sup>

Describes the audio interruption result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

| Name         | Type                                                           | Read-Only| Optional| Description            |
| --------------| -------------------------------------------------------------- | ---- |---| ---------------- |
| requestResult | [InterruptRequestResultType](#interruptrequestresulttype9)     | No| No| Audio interruption request type.|
| interruptNode | number                                                         | No| No| Node to interrupt.|

## VolumeEvent<sup>9+</sup>

Describes the event received by the application when the volume is changed.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name      | Type                               | Read-Only| Optional| Description                                       |
| ---------- | ----------------------------------- | ---- |---|-------------------------------------------|
| volumeGroupId | number                           | No| No| Volume group ID. It can be used as an input parameter of **getGroupManager**.|
| networkId  | string                              | No| No| Network ID.|

## ConnectType<sup>9+</sup>

Enumerates the types of connected devices.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                           |  Value    | Description                  |
| :------------------------------ | :----- | :--------------------- |
| CONNECT_TYPE_LOCAL              | 1      | Local device.        |
| CONNECT_TYPE_DISTRIBUTED        | 2      | Distributed device.           |

## VolumeGroupInfos<sup>9+</sup>

Describes the volume group information. The value is an array of [VolumeGroupInfo](#volumegroupinfo9) and is read-only.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

## VolumeGroupInfo<sup>9+</sup>

Describes the volume group information.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                       | Type                      | Read-Only| Optional| Description      |
| -------------------------- | -------------------------- | ---- | ---- | ---------- |
| networkId<sup>9+</sup>     | string                     | Yes  | No  | Network ID of the device. |
| groupId<sup>9+</sup>       | number                     | Yes  | No  | Group ID of the device.|
| mappingId<sup>9+</sup>     | number                     | Yes  | No  | Group mapping ID.|
| groupName<sup>9+</sup>     | string                     | Yes  | No  | Group name.|
| type<sup>9+</sup>          | [ConnectType](#connecttype9)| Yes  | No  | Type of the connected device.|

## SourceType<sup>8+</sup>

Enumerates the audio source types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                                        |  Value    | Description                  |
| :------------------------------------------- | :----- | :--------------------- |
| SOURCE_TYPE_WAKEUP <sup>10+</sup>            | 3 | Audio recording source in voice wake-up scenarios.<br>**Required permissions**: ohos.permission.MANAGE_INTELLIGENT_VOICE |
| SOURCE_TYPE_VOICE_CALL<sup>11+</sup>            | 4 | Audio source in voice calls.<br>**Required permissions**: ohos.permission.RECORD_VOICE_CALL |
| SOURCE_TYPE_VOICE_TRANSCRIPTION<sup>18+</sup>   | 12     | Audio source for speech-to-text conversion.|

## VolumeAdjustType<sup>10+</sup>

Enumerates the volume adjustment types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                  |  Value    | Description                                         |
| :--------------------- | :----- | :-------------------------------------------- |
| VOLUME_UP              | 0      | Adjusts the volume upwards.|
| VOLUME_DOWN            | 1      | Adjusts the volume downwards.|

## AudioManager

Implements audio volume and audio device management. Before calling any API in AudioManager, you must use [getAudioManager](arkts-apis-audio-f.md#audiogetaudiomanager) to create an AudioManager instance.

### setExtraParameters<sup>11+</sup>

setExtraParameters(mainKey: string, kvpairs: Record<string, string\>): Promise&lt;void&gt;

Sets extended audio parameters. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MODIFY_AUDIO_SETTINGS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| mainKey | string | Yes  | Main key of the audio parameter to set.|
| kvpairs | Record<string, string\> | Yes  | Sub-KV pair of the audio parameter to set.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message                                                                                                      |
|-----|------------------------------------------------------------------------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let kvpairs = {} as Record<string, string>;
kvpairs = {
  'key_example': 'value_example'
};

audioManager.setExtraParameters('key_example', kvpairs).then(() => {
  console.info('Promise returned to indicate a successful setting of the extra parameters.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the audio extra parameters ${err}`);
});
```

### getExtraParameters<sup>11+</sup>

getExtraParameters(mainKey: string, subKeys?: Array\<string>): Promise\<Record\<string, string>>

Obtains the value of an audio parameter. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ |--| ---------------------- |
| mainKey | string | Yes| Main key of the audio parameter whose value is to be obtained.|
| subKeys | Array\<string> | No| Subkey of the audio parameter whose value is to be obtained.|

**Return value**

| Type                 | Description                               |
| --------------------- | ----------------------------------- |
| Promise\<Record\<string, string>> | Promise used to return the value of the audio parameter.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------ | -------------------------|
| 202 | Not system App. |
|  401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let subKeys: Array<String> = ['key_example'];
audioManager.getExtraParameters('key_example', subKeys).then((value: Record<string, string>) => {
  console.info(`Promise returned to indicate that the value of the audio extra parameters is obtained ${value}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get the audio extra parameters ${err}`);
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene, callback: AsyncCallback<void\>\): void

Sets an audio scene. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                | Mandatory| Description                |
| :------- | :----------------------------------- | :--- | :------------------- |
| scene    | [AudioScene](arkts-apis-audio-e.md#audioscene8) | Yes  | Audio scene to set.      |
| callback | AsyncCallback<void\>                 | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the audio scene mode. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the audio scene mode.');
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene\): Promise<void\>

Sets an audio scene. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name| Type                                | Mandatory| Description          |
| :----- | :----------------------------------- | :--- | :------------- |
| scene  | [AudioScene](arkts-apis-audio-e.md#audioscene8) | Yes  | Audio scene to set.|

**Return value**

| Type          | Description                |
| :------------- | :------------------- |
| Promise<void\> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL).then(() => {
  console.info('Promise returned to indicate a successful setting of the audio scene mode.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the audio scene mode ${err}`);
});
```

### getEffectManager<sup>18+</sup>

getEffectManager(): AudioEffectManager

Obtains an AudioEffectManager instance.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                          | Description                         |
|----------------------------------------------| ----------------------------- |
| [AudioEffectManager](#audioeffectmanager18) | AudioEffectManager instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioEffectManager: audio.AudioEffectManager = audioManager.getEffectManager();
```

### disableSafeMediaVolume<sup>12+</sup>

disableSafeMediaVolume(): Promise&lt;void&gt;

Disables the safe volume mode. This API uses a promise to return the result.

When the device plays at a high volume for a long time while the safe volume mode is disabled, the system does not automatically remind the user to decrease the volume to a safe volume.

**Required permissions**: ohos.permission.MODIFY_AUDIO_SETTINGS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                      | Description                         |
|------------------------------------------| ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.disableSafeMediaVolume().then(() => {
  console.info('disableSafeMediaVolume success.');
}).catch((err: BusinessError) => {
  console.error(`disableSafeMediaVolume fail: ${err.code},${err.message}`);
});
```

### on('volumeChange')<sup>(deprecated)</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [on('volumeChange')](arkts-apis-audio-AudioVolumeManager.md#onvolumechangedeprecated) in AudioVolumeManager.

Subscribes to the system volume change event, which is triggered when the system volume is changed. This API uses an asynchronous callback to return the result.

Currently, when multiple AudioManager instances are used in a single process, only the subscription of the last instance takes effect, and the subscription of other instances is overwritten (even if the last instance does not initiate a subscription). Therefore, you are advised to use a single AudioManager instance.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'volumeChange'** is triggered when the system volume is changed.|
| callback | Callback<[VolumeEvent](#volumeevent9)> | Yes  | Callback used to return the changed volume.|

**Example**

```ts
audioManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### on('ringerModeChange')<sup>(deprecated)</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

Subscribes to the ringer mode change event, which is triggered when [audioringmode](arkts-apis-audio-e.md#audioringmode) is changed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [on('ringerModeChange')](arkts-apis-audio-AudioVolumeGroupManager.md#onringermodechange9) in AudioVolumeGroupManager.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | Yes  | Event type. The event **'ringerModeChange'** is triggered when the ringer mode is changed.|
| callback | Callback<[AudioRingMode](arkts-apis-audio-e.md#audioringmode)> | Yes  | Callback used to return the changed ringer mode.                                                  |

**Example**

```ts
audioManager.on('ringerModeChange', (ringerMode: audio.AudioRingMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
});
```

## forceVolumeKeyControlType<sup>20+</sup>

forceVolumeKeyControlType(volumeType: AudioVolumeType, duration: number): void

Sets the type of volume that the volume keys should control.

**Required permissions**: ohos.permission.MODIFY_AUDIO_SETTINGS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| volumeType     | [AudioVolumeType](#audiovolumetype)                       | Yes  | Type of volume to control.|
| duration |number | Yes  | Duration that the volume keys will control this type of volume if no volume key events occur. When this time expires, the forced volume type setting is canceled. The maximum duration is 10 seconds. If the duration is set to **-1**, the setting is canceled.|

**Error codes**
For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |
| 6800301  | Crash or blocking occurs in system process. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();

// Set the volume control type to ringtone mode.
let volumeType = audio.AudioVolumeType.RINGTONE;
let duration = 10;
audioVolumeManager.forceVolumeKeyControlType(volumeType, duration);

// Cancel the custom volume control, and restore the default volume control.
let volumeTypeDefault = audio.AudioVolumeType.MEDIA;
let durationToCancel = -1;
audioVolumeManager.forceVolumeKeyControlType(volumeTypeDefault, durationToCancel);
```

## AudioVolumeManager<sup>9+</sup>

Implements audio volume management. Before calling an API in AudioVolumeManager, you must use [getVolumeManager](arkts-apis-audio-AudioManager.md#getvolumemanager9) to obtain an AudioVolumeManager instance.

### getVolumeGroupInfos<sup>9+</sup>

getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos\>\): void

Obtains the volume groups. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| networkId | string                                    | Yes  | Network ID of the device. The network ID of the local device is **audio.LOCAL_NETWORK_ID**.   |
| callback  | AsyncCallback&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the volume groups obtained; otherwise, **err** is an error object.|

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeManager.getVolumeGroupInfos(audio.LOCAL_NETWORK_ID, (err: BusinessError, value: audio.VolumeGroupInfos) => {
  if (err) {
    console.error(`Failed to obtain the volume group infos list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
});
```

### getVolumeGroupInfos<sup>9+</sup>

getVolumeGroupInfos(networkId: string\): Promise<VolumeGroupInfos\>

Obtains the volume groups. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type              | Mandatory| Description                |
| ---------- | ------------------| ---- | -------------------- |
| networkId | string             | Yes  | Network ID of the device. The network ID of the local device is **audio.LOCAL_NETWORK_ID**.  |

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | Promise used to return the volume group information list.|

**Example**

```ts
async function getVolumeGroupInfos(){
  let volumegroupinfos: audio.VolumeGroupInfos = await audio.getAudioManager().getVolumeManager().getVolumeGroupInfos(audio.LOCAL_NETWORK_ID);
  console.info('Promise returned to indicate that the volumeGroup list is obtained.'+JSON.stringify(volumegroupinfos))
}
```

### getVolumeGroupInfosSync<sup>10+</sup>

getVolumeGroupInfosSync(networkId: string\): VolumeGroupInfos

Obtains the volume groups. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type              | Mandatory| Description                |
| ---------- | ------------------| ---- | -------------------- |
| networkId | string             | Yes  | Network ID of the device. The network ID of the local device is **audio.LOCAL_NETWORK_ID**.  |

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| [VolumeGroupInfos](#volumegroupinfos9) | Volume group information list.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let volumegroupinfos: audio.VolumeGroupInfos = audioVolumeManager.getVolumeGroupInfosSync(audio.LOCAL_NETWORK_ID);
  console.info(`Indicate that the volumeGroup list is obtained. ${JSON.stringify(volumegroupinfos)}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volumeGroup list ${error}`);
}
```

### getAppVolumePercentageForUid<sup>19+</sup>

getAppVolumePercentageForUid(uid: number\): Promise<number\>

Obtains the volume of an application based on the application ID. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description                              |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| uid    | number                                   | Yes  | Application ID.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise used to return the application volume (ranging from 0 to 100).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed.|

**Example**

```ts
let uid: number = 20010041; // Application ID.

audioVolumeManager.getAppVolumePercentageForUid(20010041).then((value: number) => {
  console.info(`app volume is ${value}.`);
});
```

### setAppVolumePercentageForUid<sup>19+</sup>

setAppVolumePercentageForUid(uid: number, volume: number\): Promise<void\>

Sets the volume for an application based on the application ID. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description      |
| ---------- | ---------------------------------------- | ---- |----------|
| uid    | number                                   | Yes  | Application ID.  |
| volume    | number                                   | Yes  | Volume to set.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed.|
| 6800301 | Crash or blocking occurs in system process. |

**Example**

```ts
let uid: number = 20010041; // Application ID.
let volume: number = 20;    // Volume to set.

audioVolumeManager.setAppVolumePercentageForUid(uid, volume).then(() => {
  console.info(`set app volume success.`);
});
```

### isAppVolumeMutedForUid<sup>19+</sup>

isAppVolumeMutedForUid(uid: number, owned: boolean\): Promise<boolean\>

Checks whether the application volume is muted based on the application ID. This API uses a promise to return the result.

> **NOTE**
>
> If multiple callers have muted the application, it will only be unmuted when all callers have explicitly unmuted it.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description                                       |
| ---------- | ---------------------------------------- | ---- |-------------------------------------------|
| uid    | number                                   | Yes  | Application ID.                                   |
| owned    | boolean                                   | Yes  | Mute state to check. **true** to check the mute state for the current caller, **false** to check the mute state for the application.|

**Return value**

| Type               | Description                 |
| ------------------- |---------------------|
| Promise&lt;boolean&gt; | Promise used to return the result, indicating whether the application volume is muted. **true** if muted, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|

**Example**

```ts
let uid: number = 20010041; // Application ID.

audioVolumeManager.isAppVolumeMutedForUid(uid, true).then((value: boolean) => {
  console.info(`app muted state is ${value}.`);
});
```

### setAppVolumeMutedForUid<sup>19+</sup>

setAppVolumeMutedForUid(uid: number, muted: boolean\): Promise<void\>

Sets the mute state for an application based on the application ID. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description                            |
| ---------- | ---------------------------------------- | ---- |--------------------------------|
| uid    | number                                   | Yes  | Application ID.                        |
| owned    | boolean                                   | Yes  | Mute state to set. **true** to mute, **false** otherwise.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed.|
| 6800301 | Crash or blocking occurs in system process. |

**Example**

```ts
let uid: number = 20010041; // Application ID.

audioVolumeManager.setAppVolumeMutedForUid(uid, true).then(() => {
  console.info(`set app mute state success.`);
});
```

### on('appVolumeChangeForUid')<sup>19+</sup>

on(type: 'appVolumeChangeForUid', uid: number, callback: Callback\<VolumeEvent>): void

Subscribes to the application-level volume change event of an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                               |
| -------- | -------------------------------------- | ---- |-----------------------------------|
| type     | string                                 | Yes  | Event type. The event **'appVolumeChangeForUid'** is triggered when the application-level volume is changed.|
| uid | number |  Yes  | Application ID.                         |
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | Yes  | Callback used to return the changed volume.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
let uid: number = 20010041; // Application ID.

audioVolumeManager.on('appVolumeChangeForUid', uid, (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### off('appVolumeChangeForUid')<sup>19+</sup>

off(type: 'appVolumeChangeForUid', callback?: Callback\<VolumeEvent>): void

Unsubscribes from the application-level volume change event of an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type. The event **'appVolumeChangeForUid'** is triggered when the application-level volume is changed.|
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | No  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioVolumeManager.off('appVolumeChangeForUid');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let appVolumeChangeForUidCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};

audioVolumeManager.on('appVolumeChangeForUid', appVolumeChangeForUidCallback);

audioVolumeManager.off('appVolumeChangeForUid', appVolumeChangeForUidCallback);
```

### on('activeVolumeTypeChange')<sup>20+</sup>

on(type: 'activeVolumeTypeChange', callback: Callback\<AudioVolumeType>): void

Subscribes to the active volume type change event. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'activeVolumeTypeChange'** is triggered when the active volume type changes.|
| callback | Callback\<[AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype)> | Yes  | Callback used to return the changed active volume type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeManager.on('activeVolumeTypeChange', (volumeType: audio.AudioVolumeType) => {
  console.info(`VolumeType of stream: ${volumeType} `);
});
```

### off('activeVolumeTypeChange')<sup>20+</sup>

off(type: 'activeVolumeTypeChange', callback?: Callback\<AudioVolumeType>): void

Unsubscribes from the active volume type change event. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'activeVolumeTypeChange'** is triggered when the active volume type changes.|
| callback | Callback\<[AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype)> | No  | Callback used to return the changed active volume type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioVolumeManager.off('activeVolumeTypeChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let activeVolumeTypeChangeCallback = (volumeType: audio.AudioVolumeType) => {
  console.info(`VolumeType of stream: ${volumeType} `);
};

audioVolumeManager.on('activeVolumeTypeChange', activeVolumeTypeChangeCallback);

audioVolumeManager.off('activeVolumeTypeChange', activeVolumeTypeChangeCallback);
```

## AudioVolumeGroupManager<sup>9+</sup>

Manages the volume of an audio group. Before calling any API in AudioVolumeGroupManager, you must use [getVolumeGroupManager](arkts-apis-audio-AudioVolumeManager.md#getvolumegroupmanager9) to obtain an AudioVolumeGroupManager instance.

### setVolume<sup>9+</sup>

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

Sets the volume for a stream. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume. The volume range can be obtained by calling [getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated) and [getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated).|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful volume setting.');
});
```

### setVolume<sup>9+</sup>

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

Sets the volume for a stream. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume. The volume range can be obtained by calling [getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated) and [getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated).|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioVolumeGroupManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### setVolumeWithFlag<sup>12+</sup>

setVolumeWithFlag(volumeType: AudioVolumeType, volume: number, flags: number): Promise&lt;void&gt;

Sets the volume for a stream, with a flag to specify whether to display the system volume bar during the volume change. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                  |
| ---------- | ----------------------------------- | ---- |--------------------------------------|
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                              |
| volume     | number                              | Yes  | Volume. The volume range can be obtained by calling [getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated) and [getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated).|
| flags      | number                              | Yes  | Whether to display the system volume bar. The value **0** means not to display the system volume bar, and **1** means the opposite.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |

**Example**

```ts
audioVolumeGroupManager.setVolumeWithFlag(audio.AudioVolumeType.MEDIA, 10, 1).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### mute<sup>9+</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes a stream. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Mute status to set. **true** to mute, **false** otherwise.|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.mute(audio.AudioVolumeType.MEDIA, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the stream. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the stream is muted.');
});
```

### mute<sup>9+</sup>

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

Mutes or unmutes a stream. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Mute status to set. **true** to mute, **false** otherwise.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioVolumeGroupManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
  console.info('Promise returned to indicate that the stream is muted.');
});
```

### setRingerMode<sup>9+</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

Sets the ringer mode. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | Yes  | Ringer mode.          |
| callback | AsyncCallback&lt;void&gt;       | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the ringer mode. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the ringer mode.');
});
```

### setRingerMode<sup>9+</sup>

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

Sets the ringer mode. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | Yes  | Ringer mode.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioVolumeGroupManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
  console.info('Promise returned to indicate a successful setting of the ringer mode.');
});
```

### setMicMute<sup>11+</sup>

setMicMute(mute: boolean): Promise&lt;void&gt;

Mutes or unmutes the microphone. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name| Type   | Mandatory| Description                                         |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | Yes  | Mute status to set. **true** to mute, **false** otherwise.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeGroupManager.setMicMute(true).then(() => {
  console.info('Promise returned to indicate that the mic is muted.');
});
```

### adjustVolumeByStep<sup>10+</sup>

adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback&lt;void&gt;): void

Adjusts the volume of the stream with the highest priority by step. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | Yes  | Volume adjustment type.                                            |
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.adjustVolumeByStep(audio.VolumeAdjustType.VOLUME_UP, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to adjust the volume by step. ${err}`);
    return;
  } else {
    console.info('Success to adjust the volume by step.');
  }
});
```
### adjustVolumeByStep<sup>10+</sup>

adjustVolumeByStep(adjustType: VolumeAdjustType): Promise&lt;void&gt;

Adjusts the volume of the stream with the highest priority by step. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | Yes  | Volume adjustment type.                                            |

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.adjustVolumeByStep(audio.VolumeAdjustType.VOLUME_UP).then(() => {
  console.info('Success to adjust the volume by step.');
}).catch((error: BusinessError) => {
  console.error('Fail to adjust the volume by step.');
});
```

### adjustSystemVolumeByStep<sup>10+</sup>

adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType, callback: AsyncCallback&lt;void&gt;): void

Adjusts the volume of a stream by step. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | Yes  | Volume adjustment type.                                      |
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.adjustSystemVolumeByStep(audio.AudioVolumeType.MEDIA, audio.VolumeAdjustType.VOLUME_UP, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to adjust the system volume by step ${err}`);
  } else {
    console.info('Success to adjust the system volume by step.');
  }
});
```
### adjustSystemVolumeByStep<sup>10+</sup>

adjustSystemVolumeByStep(volumeType: AudioVolumeType, adjustType: VolumeAdjustType): Promise&lt;void&gt;

Adjusts the volume of a stream by step. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | Yes  | Volume adjustment type.                                            |

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| -------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.adjustSystemVolumeByStep(audio.AudioVolumeType.MEDIA, audio.VolumeAdjustType.VOLUME_UP).then(() => {
  console.info('Success to adjust the system volume by step.');
}).catch((error: BusinessError) => {
  console.error('Fail to adjust the system volume by step.');
});
```
## AudioEffectManager<sup>18+</sup>

Manages audio effects. Before calling an API in AudioEffectManager, you must use [getEffectManager](#geteffectmanager18) to obtain an AudioEffectManager instance.


### getSupportedAudioEffectProperty<sup>18+</sup>

getSupportedAudioEffectProperty(): Array\<AudioEffectProperty>

Obtains the supported audio effects. This API returns the result synchronously.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                                                     | Description                                   |
| --------------------------------------------------------------------------| --------------------------------------- |
| Array\<[AudioEffectProperty](#audioeffectproperty18)>     | Properties of the audio effects supported.             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800301 | System error. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let propertyArray: Array<audio.AudioEffectProperty> = audioStreamManager.getSupportedAudioEffectProperty();
  console.info(`The effect modes are: ${propertyArray}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getSupportedAudioEffectProperty ERROR: ${error}`);
}
```


### getAudioEffectProperty<sup>18+</sup>

getAudioEffectProperty(): Array\<AudioEffectProperty>

Obtains the audio effect in use. This API returns the result synchronously.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                                                     | Description                                   |
| --------------------------------------------------------------------------| --------------------------------------- |
| Array\<[AudioEffectProperty](#audioeffectproperty18)>     | Audio effect in use.                       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800301 | System error. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let propertyArray: Array<audio.AudioEffectProperty> = audioStreamManager.getAudioEffectProperty();
  console.info(`The effect modes are: ${propertyArray}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAudioEffectProperty ERROR: ${error}`);
}
```

### setAudioEffectProperty<sup>18+</sup>

setAudioEffectProperty(propertyArray: Array\<AudioEffectProperty>): void

Sets an audio effect in use. This API returns the result synchronously.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.core

**Parameters**

| Name       | Type                                                 | Mandatory    | Description                        |
| ------------- | ----------------------------------------------------- | -------- | ---------------------------- |
| propertyArray | Array\<[AudioEffectProperty](#audioeffectproperty18)> | Yes      |  Property of the audio effect.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800101 | Parameter verification failed. Possible causes: 1.more than one enhanceProps of the same enhanceClass in input Array; 2.input audioEnhanceProperties are not supported by current device. 3.names of enhanceProp or enhanceClass are incorrect.|
| 6800301 | System error. Return by callback. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let propertyArray: Array<audio.AudioEffectProperty> = audioEffectManager.getAudioEffectProperty();
  console.info(`The effect modes are: ${propertyArray}`);
  audioEffectManager.setAudioEffectProperty(propertyArray);
} catch (err) {
  let error = err as BusinessError;
  console.error(`setAudioEffectProperty ERROR: ${error}`);
}
```

## AudioRoutingManager<sup>9+</sup>

Implements audio routing management. Before calling any API in AudioRoutingManager, you must use [getRoutingManager](arkts-apis-audio-AudioManager.md#getroutingmanager9) to obtain an AudioRoutingManager instance.

### selectInputDevice<sup>9+</sup>

selectInputDevice(inputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

Selects an audio input device. Currently, only one input device can be selected. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | Input device.              |
| callback                    | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**
```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.INPUT_DEVICE,
  deviceType : audio.DeviceType.MIC,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function selectInputDevice(){
  audioRoutingManager.selectInputDevice(inputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select input devices result callback: SUCCESS');
    }
  });
}
```

### selectInputDevice<sup>9+</sup>

selectInputDevice(inputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

Selects an audio input device. Currently, only one input device can be selected. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | Input device.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.INPUT_DEVICE,
  deviceType : audio.DeviceType.MIC,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function getRoutingManager(){
  audioRoutingManager.selectInputDevice(inputAudioDeviceDescriptor).then(() => {
    console.info('Select input devices result promise: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
}
```

### selectOutputDevice<sup>9+</sup>

selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

Selects an audio output device. Currently, only one output device can be selected. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | Output device.              |
| callback                    | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**
```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.SPEAKER,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function selectOutputDevice(){
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select output devices result callback: SUCCESS'); }
  });
}
```

### selectOutputDevice<sup>9+</sup>

selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

Selects an audio output device. Currently, only one output device can be selected. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | Output device.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.SPEAKER,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function selectOutputDevice(){
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor).then(() => {
    console.info('Select output devices result promise: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
}
```

### selectOutputDeviceByFilter<sup>9+</sup>

selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

Selects an audio output device based on the filter criteria. Currently, only one output device can be selected. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| filter                      | [AudioRendererFilter](#audiorendererfilter9)                 | Yes  | Filter criteria.              |
| outputAudioDevices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | Output device.              |
| callback                    | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**
```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.SPEAKER,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function selectOutputDeviceByFilter(){
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select output devices by filter result callback: SUCCESS'); }
  });
}
```

### selectOutputDeviceByFilter<sup>9+</sup>

selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

Selects an audio output device based on the filter criteria. Currently, only one output device can be selected. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                | Type                                                        | Mandatory| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| filter                | [AudioRendererFilter](#audiorendererfilter9)                 | Yes  | Filter criteria.              |
| outputAudioDevices    | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | Output device.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};

let outputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.SPEAKER,
  id : 1,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function selectOutputDeviceByFilter(){
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor).then(() => {
    console.info('Select output devices by filter result promise: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  })
}
```

### selectInputDeviceByFilter<sup>18+</sup>

selectInputDeviceByFilter(filter: AudioCapturerFilter, inputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

Selects an audio input device based on the filter criteria. Currently, only one input device can be selected. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                | Type                                                               | Mandatory| Description    |
| ----------------------|-------------------------------------------------------------------| ---- |--------|
| filter                      | [AudioCapturerFilter](#audiocapturerfilter18)                     | Yes  | Filter criteria.|
| inputAudioDevices | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | Yes  | Input device.|

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|


**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputAudioCapturerFilter: audio.AudioCapturerFilter = {
    uid : 20010041,
    capturerInfo : {
        source: audio.SourceType.SOURCE_TYPE_MIC,
        capturerFlags: 0
    }
};

let inputAudioDeviceDescriptor: audio.AudioDeviceDescriptors = [{
    deviceRole : audio.DeviceRole.INPUT_DEVICE,
    deviceType : audio.DeviceType.MIC,
    id : 1,
    name : "",
    address : "",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
    displayName : "",
}];

async function selectInputDeviceByFilter(){
    let audioManager = audio.getAudioManager();  // Create an AudioManager instance.
    let audioRoutingManager = audioManager.getRoutingManager();  // Call an API of AudioManager to create an AudioRoutingManager instance.
    audioRoutingManager.selectInputDeviceByFilter(inputAudioCapturerFilter, inputAudioDeviceDescriptor).then(() => {
        console.info('Select input devices by filter result promise: SUCCESS');
    }).catch((err: BusinessError) => {
        console.error(`Result ERROR: ${err}`);
    })
}
```

### getPreferredOutputDeviceByFilter<sup>18+</sup>

getPreferredOutputDeviceByFilter(filter: AudioRendererFilter): AudioDeviceDescriptors

Obtains an audio output device based on the filter criteria.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| filter                      | [AudioRendererFilter](#audiorendererfilter9)                 | Yes  | Filter criteria.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)| return the device list. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|

**Example**
```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};

async function selectOutputDeviceByFilter(){
    let audioManager = audio.getAudioManager();  // Create an AudioManager instance.
    let audioRoutingManager = audioManager.getRoutingManager();  // Call an API of AudioManager to create an AudioRoutingManager instance.
    let desc : audio.AudioDeviceDescriptors = audioRoutingManager.getPreferredOutputDeviceByFilter(outputAudioRendererFilter);
    console.info(`device descriptor: ${desc}`);
}
```

### getPreferredInputDeviceByFilter<sup>18+</sup>

getPreferredInputDeviceByFilter(filter: AudioCapturerFilter): AudioDeviceDescriptors

Obtains an audio input device based on the filter criteria. Currently, only one input device can be acquired.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                | Type                                           | Mandatory| Description                     |
|---------------------|-----------------------------------------------| ---- | ------------------------- |
| filter              | [AudioCapturerFilter](#audiocapturerfilter18) | Yes  | Filter criteria.|

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | return the device list. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputAudioCapturerFilter: audio.AudioCapturerFilter = {
    uid : 20010041,
    capturerInfo : {
        source: audio.SourceType.SOURCE_TYPE_MIC,
        capturerFlags: 0
    }
};

async function getPreferredInputDeviceByFilter(){
    let audioManager = audio.getAudioManager();  // Create an AudioManager instance.
    let audioRoutingManager = audioManager.getRoutingManager();  // Call an API of AudioManager to create an AudioRoutingManager instance.
    let desc: audio.AudioDeviceDescriptors = audioRoutingManager.getPreferredInputDeviceByFilter(inputAudioCapturerFilter);
    console.info(`device descriptor: ${desc}`);
}
```

### excludeOutputDevices<sup>18+</sup>

excludeOutputDevices(usage: DeviceUsage, devices: AudioDeviceDescriptors): Promise&lt;void&gt;

Excludes output devices. Once this API is successfully called, audio will no longer be played on the specified devices.

> **NOTE**
>
> This API can exclude only external output devices, but not local output devices.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | Yes  | Device type. Only output devices can be excluded.              |
| devices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | List of output devices to exclude.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let usage: audio.DeviceUsage.MEDIA_OUTPUT_DEVICES;
let excludedDevices: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 3,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function excludeOutputDevices(){
  audioRoutingManager.excludeOutputDevices(usage, excludedDevices, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Exclude Output Devices result callback: SUCCESS'); }
  });
}
```

### unexcludeOutputDevices<sup>18+</sup>

unexcludeOutputDevices(usage: DeviceUsage, devices: AudioDeviceDescriptors): Promise&lt;void&gt;

Restores previously excluded output devices. Once this API is called successfully, the audio output device can be reselected.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | Yes  | Device type. Only output devices can be excluded.              |
| devices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | Yes  | Lit of output devices to restore.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let usage: audio.DeviceUsage.MEDIA_OUTPUT_DEVICES;
let unexcludedDevices: audio.AudioDeviceDescriptors = [{
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 3,
  name : "",
  address : "",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : "",
}];

async function unexcludeOutputDevices(){
  audioRoutingManager.unexcludeOutputDevices(usage, unexcludedDevices, (err: BusinessError) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Unexclude Output Devices result callback: SUCCESS'); }
  });
}
```

### unexcludeOutputDevices<sup>18+</sup>

unexcludeOutputDevices(usage: DeviceUsage): Promise&lt;void&gt;

Restores all previously excluded output devices that are used for a specific purpose. Once this API is called successfully, the audio output device can be reselected.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | Yes  | Device type. Only output devices can be excluded.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let usage: audio.DeviceUsage.MEDIA_OUTPUT_DEVICES;

async function unexcludeOutputDevices(){
  audioRoutingManager.unexcludeOutputDevices(usage).then(() => {
    console.info('Unexclude Output Devices result promise: SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  });
}
```

### getExcludedDevices<sup>18+</sup>

getExcludedDevices(usage: DeviceUsage): AudioDeviceDescriptors

Obtains excluded output devices.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | Yes  | Device type. Only output devices can be excluded.              |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | List of excluded output devices.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let usage: audio.DeviceUsage.MEDIA_OUTPUT_DEVICES;

async function getExcludedDevices(){
  let desc: audio.AudioDeviceDescriptors = audioRoutingManager.getExcludedDevices(usage);
  console.info(`device descriptor: ${desc}`);
}
```

## AudioRendererChangeInfo<sup>9+</sup>

Describes the audio renderer change event.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Type                                      | Read-Only| Optional| Description                         |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| clientUid          | number                                    | Yes  | No  | UID of the audio renderer client.|
| rendererState      | [AudioState](arkts-apis-audio-e.md#audiostate8)                 | Yes  | No  | Audio state.|

## AudioCapturerChangeInfo<sup>9+</sup>

Describes the audio capturer change event.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name              | Type                                      | Read-Only| Optional| Description                         |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| clientUid          | number                                    | Yes  | No  | UID of the audio capturer client.|
| capturerState      | [AudioState](arkts-apis-audio-e.md#audiostate8)                 | Yes  | No  | Audio state.|

## AudioDeviceDescriptor

Describes an audio device.

**System API**: This is a system API.

| Name                         | Type                      | Read-Only| Optional| Description      |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| networkId<sup>9+</sup>        | string                     | Yes  | No  | ID of the device network.<br> **System capability**: SystemCapability.Multimedia.Audio.Device|
| interruptGroupId<sup>9+</sup> | number                     | Yes  | No  | ID of the interruption group to which the device belongs.<br> **System capability**: SystemCapability.Multimedia.Audio.Device|
| volumeGroupId<sup>9+</sup>    | number                     | Yes  | No  | ID of the volume group to which the device belongs.<br> **System capability**: SystemCapability.Multimedia.Audio.Device|
| dmDeviceType<sup>18+</sup>    | number                     | Yes  | Yes| Subtype ID of the device.<br> **System capability**: SystemCapability.Multimedia.Audio.Core|

## AudioRendererFilter<sup>9+</sup>

Implements filter criteria. Before calling **selectOutputDeviceByFilter**, you must obtain an AudioRendererFilter instance.

**System API**: This is a system API.

| Name         | Type                                    | Read-Only| Optional| Description         |
| -------------| ---------------------------------------- | ---- |---| -------------- |
| uid          | number                                   |  No | Yes| Application ID.<br> **System capability**: SystemCapability.Multimedia.Audio.Core|
| rendererInfo | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8) |  No | Yes| Audio renderer information.<br> **System capability**: SystemCapability.Multimedia.Audio.Renderer|
| rendererId   | number                                   |  No | Yes| Unique ID of an audio stream.<br> **System capability**: SystemCapability.Multimedia.Audio.Renderer|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};
```

## AudioCapturerFilter<sup>18+</sup>

Filter criteria. Before calling **selectOutputDeviceByFilter**, you must obtain an AudioCapturerFilter instance.

**System API**: This is a system API.

| Name         | Type                                    | Read-Only| Optional| Description         |
| -------------| ---------------------------------------- | ---- |---| -------------- |
| uid          | number                                   |  No | Yes| Application ID.<br> **System capability**: SystemCapability.Multimedia.Audio.Core|
| capturerInfo | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8) |  No | Yes| Audio capturer information.<br> **System capability**: SystemCapability.Multimedia.Audio.Capturer|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let inputAudioCapturerFilter: audio.AudioCapturerFilter = {
    uid : 20010041,
    capturerInfo : {
        source: audio.SourceType.SOURCE_TYPE_MIC,
        capturerFlags: 0
    }
};
```

## AudioSpatialEnabledStateForDevice<sup>12+</sup>

Describes the enabled status of spatial audio rendering of the device.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

| Name                | Type                                                        | Read-Only| Optional| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- |---| ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | No| No| Descriptor of the device.    |
| enabled               | boolean                                                      | No| No| Whether spatial audio rendering or head tracking is enabled. **true** if enabled, **false** otherwise. |

## AudioSpatializationManager<sup>11+</sup>

Implements spatial audio management. Before calling any API in AudioSpatializationManager, you must use [getSpatializationManager](arkts-apis-audio-AudioManager.md#getspatializationmanager18) to obtain an AudioSpatializationManager instance.

### isSpatializationSupported<sup>11+</sup>

isSpatializationSupported(): boolean

Checks whether the system supports spatial audio rendering. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for the support of spatial audio rendering. **true** if supported, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let isSpatializationSupported: boolean = audioSpatializationManager.isSpatializationSupported();
  console.info(`AudioSpatializationManager isSpatializationSupported: ${isSpatializationSupported}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### isSpatializationSupportedForDevice<sup>11+</sup>

isSpatializationSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor): boolean

Checks whether a device supports spatial audio rendering. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | Yes  | Descriptor of the device.    |

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for the support of spatial audio rendering. **true** if supported, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor: audio.AudioDeviceDescriptor = {
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 1,
  name : "",
  address : "123",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : ""
};

try {
  let isSpatializationSupportedForDevice: boolean = audioSpatializationManager.isSpatializationSupportedForDevice(deviceDescriptor);
  console.info(`AudioSpatializationManager isSpatializationSupportedForDevice: ${isSpatializationSupportedForDevice}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### isHeadTrackingSupported<sup>11+</sup>

isHeadTrackingSupported(): boolean

Checks whether the system supports head tracking. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for the support of head tracking. **true** if supported, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isHeadTrackingSupported: boolean = audioSpatializationManager.isHeadTrackingSupported();
  console.info(`AudioSpatializationManager isHeadTrackingSupported: ${isHeadTrackingSupported}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### isHeadTrackingSupportedForDevice<sup>11+</sup>

isHeadTrackingSupportedForDevice(deviceDescriptor: AudioDeviceDescriptor): boolean

Checks whether a device supports head tracking. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | Yes  | Descriptor of the device.    |

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for the support of head tracking. **true** if supported, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor: audio.AudioDeviceDescriptor = {
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 1,
  name : "",
  address : "123",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : ""
};

try {
  let isHeadTrackingSupportedForDevice: boolean = audioSpatializationManager.isHeadTrackingSupportedForDevice(deviceDescriptor);
  console.info(`AudioSpatializationManager isHeadTrackingSupportedForDevice: ${isHeadTrackingSupportedForDevice}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### setSpatializationEnabled<sup>(deprecated)</sup>

setSpatializationEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Enables or disables spatial audio rendering. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setspatializationenabled12) instead.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| enable                      | boolean                                                      | Yes  | Whether to enable or disable spatial audio rendering. **true** to enable, **false** otherwise. |
| callback                    | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**
```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;

audioSpatializationManager.setSpatializationEnabled(enable, (err: BusinessError) => {
  if (err) {
    console.error(`Result ERROR: ${err}`);
  } else {
    console.info(`setSpatializationEnabled success`);
  }
});
```

### setSpatializationEnabled<sup>(deprecated)</sup>

setSpatializationEnabled(enable: boolean): Promise&lt;void&gt;

Enables or disables spatial audio rendering. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setspatializationenabled12) instead.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                | Type                                                        | Mandatory| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| enable                | boolean                                                      | Yes  | Whether to enable or disable spatial audio rendering. **true** to enable, **false** otherwise. |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;

audioSpatializationManager.setSpatializationEnabled(enable).then(() => {
  console.info(`setSpatializationEnabled success`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});
```
### setSpatializationEnabled<sup>12+</sup>

setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise&lt;void&gt;

Enables or disables spatial audio rendering for a device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                | Type                                                        | Mandatory| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | Yes  | Descriptor of the device.    |
| enabled               | boolean                                                      | Yes  | Whether to enable or disable spatial audio rendering. **true** to enable, **false** otherwise. |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |


**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor: audio.AudioDeviceDescriptor = {
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 1,
  name : "",
  address : "123",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : ""
};
let enabled: boolean = true;

audioSpatializationManager.setSpatializationEnabled(deviceDescriptor, enabled).then(() => {
  console.info(`setSpatializationEnabled success`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});
```

### isSpatializationEnabled<sup>(deprecated)</sup>

isSpatializationEnabled(): boolean

Checks whether spatial audio rendering is enabled. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [isSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean](#isspatializationenabled12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for whether spatial audio rendering is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isSpatializationEnabled: boolean = audioSpatializationManager.isSpatializationEnabled();
  console.info(`AudioSpatializationManager isSpatializationEnabled: ${isSpatializationEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### isSpatializationEnabled<sup>12+</sup>

isSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean

Checks whether spatial audio rendering is enabled. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                | Type                                                        | Mandatory| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | Yes  | Descriptor of the device.    |

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for whether spatial audio rendering is enabled for the device. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor: audio.AudioDeviceDescriptor = {
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 1,
  name : "",
  address : "123",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : ""
};

try {
  let isSpatializationEnabled: boolean = audioSpatializationManager.isSpatializationEnabled(deviceDescriptor);
  console.info(`AudioSpatializationManager isSpatializationEnabled: ${isSpatializationEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### on('spatializationEnabledChange')<sup>(deprecated)</sup>

on(type: 'spatializationEnabledChange', callback: Callback<boolean\>): void

Subscribes to the spatial audio rendering status change event, which is triggered when the spatial audio rendering status is changed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [on(type: 'spatializationEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void](#onspatializationenabledchangeforanydevice12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string | Yes  | Event type. The event **'spatializationEnabledChange'** is triggered when the spatial audio rendering status is changed.|
| callback | Callback<boolean\> | Yes  | Callback used to return the result, indicating whether spatial audio rendering is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('spatializationEnabledChange', (isSpatializationEnabled: boolean) => {
  console.info(`isSpatializationEnabled: ${isSpatializationEnabled}`);
});
```

### on('spatializationEnabledChangeForAnyDevice')<sup>12+</sup>

on(type: 'spatializationEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void

Subscribes to the spatial audio rendering status change event, which is triggered when the spatial audio rendering status is changed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string | Yes  | Event type. The event **'spatializationEnabledChangeForAnyDevice'** is triggered when the spatial audio rendering status is changed.|
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | Yes  | Callback used to return the device information and the enabled status of spatial audio rendering.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('spatializationEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
});
```

### off('spatializationEnabledChange')<sup>(deprecated)</sup>

off(type: 'spatializationEnabledChange', callback?: Callback<boolean\>): void

Unsubscribes from the spatial audio rendering status change event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [off(type: 'spatializationEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void](#offspatializationenabledchangeforanydevice12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | Yes  | Event type. The event **'spatializationEnabledChange'** is triggered when the spatial audio rendering status is changed.|
| callback | Callback<boolean\> | No  | Callback used to return the result, indicating whether spatial audio rendering is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioSpatializationManager.off('spatializationEnabledChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let spatializationEnabledChangeCallback = (isSpatializationEnabled: boolean) => {
  console.info(`isSpatializationEnabled: ${isSpatializationEnabled}`);
};

audioSpatializationManager.on('spatializationEnabledChange', spatializationEnabledChangeCallback);

audioSpatializationManager.off('spatializationEnabledChange', spatializationEnabledChangeCallback);
```

### off('spatializationEnabledChangeForAnyDevice')<sup>12+</sup>

off(type: 'spatializationEnabledChangeForAnyDevice', callback?: Callback<AudioSpatialEnabledStateForDevice\>): void

Unsubscribes from the spatial audio rendering status change event. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string | Yes  | Event type. The event **'spatializationEnabledChangeForAnyDevice'** is triggered when the spatial audio rendering status is changed.|
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | Yes  | Callback used to return the device information and the enabled status of spatial audio rendering.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

// Cancel all subscriptions to the event.
audioSpatializationManager.off('spatializationEnabledChangeForAnyDevice');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let spatializationEnabledChangeForAnyDeviceCallback = (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
};

audioSpatializationManager.on('spatializationEnabledChangeForAnyDevice', spatializationEnabledChangeForAnyDeviceCallback);

audioSpatializationManager.off('spatializationEnabledChangeForAnyDevice', spatializationEnabledChangeForAnyDeviceCallback);
```

### setHeadTrackingEnabled<sup>(deprecated)</sup>

setHeadTrackingEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Enables or disables head tracking. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setheadtrackingenabled12) instead.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                      | Type                                                        | Mandatory| Description                     |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| enable                      | boolean                                                      | Yes  | Whether to enable or disable head tracking. **true** to enable, **false** otherwise. |
| callback                    | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**
```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;

audioSpatializationManager.setHeadTrackingEnabled(enable, (err: BusinessError) => {
  if (err) {
    console.error(`Result ERROR: ${err}`);
  } else {
    console.info(`setHeadTrackingEnabled success`);
  }
});
```

### setHeadTrackingEnabled<sup>(deprecated)</sup>

setHeadTrackingEnabled(enable: boolean): Promise&lt;void&gt;

Enables or disables head tracking. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setheadtrackingenabled12) instead.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                | Type                                                        | Mandatory| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| enable                | boolean                                                      | Yes  | Whether to enable or disable head tracking. **true** to enable, **false** otherwise. |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;

audioSpatializationManager.setHeadTrackingEnabled(enable).then(() => {
  console.info(`setHeadTrackingEnabled success`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});
```

### setHeadTrackingEnabled<sup>12+</sup>

setHeadTrackingEnabled(enable: boolean): Promise&lt;void&gt;

Enables or disables head tracking for a device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                | Type                                                        | Mandatory| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | Yes  | Descriptor of the device.    |
| enable                | boolean                                                      | Yes  | Whether to enable or disable head tracking. **true** to enable, **false** otherwise. |

**Return value**

| Type                 | Description                        |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor: audio.AudioDeviceDescriptor = {
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 1,
  name : "",
  address : "123",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : ""
};
let enable: boolean = true;

audioSpatializationManager.setHeadTrackingEnabled(deviceDescriptor, enable).then(() => {
  console.info(`setHeadTrackingEnabled success`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});
```

### isHeadTrackingEnabled<sup>(deprecated)</sup>

isHeadTrackingEnabled(): boolean

Checks whether head tracking is enabled. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [isHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean](#isheadtrackingenabled12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for whether head tracking is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isHeadTrackingEnabled: boolean = audioSpatializationManager.isHeadTrackingEnabled();
  console.info(`AudioSpatializationManager isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### isHeadTrackingEnabled<sup>12+</sup>

isHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean

Checks whether head tracking is enabled for a device. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name                | Type                                                        | Mandatory| Description                     |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | Yes  | Descriptor of the device.    |

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result for whether head tracking is enabled for the device. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let deviceDescriptor: audio.AudioDeviceDescriptor = {
  deviceRole : audio.DeviceRole.OUTPUT_DEVICE,
  deviceType : audio.DeviceType.BLUETOOTH_A2DP,
  id : 1,
  name : "",
  address : "123",
  sampleRates : [44100],
  channelCounts : [2],
  channelMasks : [0],
  networkId : audio.LOCAL_NETWORK_ID,
  interruptGroupId : 1,
  volumeGroupId : 1,
  displayName : ""
};

try {
  let isHeadTrackingEnabled: boolean = audioSpatializationManager.isHeadTrackingEnabled(deviceDescriptor);
  console.info(`AudioSpatializationManager isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### on('headTrackingEnabledChange')<sup>(deprecated)</sup>

on(type: 'headTrackingEnabledChange', callback: Callback<boolean\>): void

Subscribes to the head tracking status change event, which is triggered when the head tracking status is changed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [on(type: 'headTrackingEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void](#onheadtrackingenabledchangeforanydevice12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                                | Mandatory| Description                                      |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string | Yes  | Event type. The event **'headTrackingEnabledChange'** is triggered when the head tracking status is changed.|
| callback | Callback<boolean\> | Yes  | Callback used to return the result, indicating whether head tracking is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('headTrackingEnabledChange', (isHeadTrackingEnabled: boolean) => {
  console.info(`isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
});
```

### on('headTrackingEnabledChangeForAnyDevice')<sup>12+</sup>

on(type: 'headTrackingEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void

Subscribes to the head tracking status change event, which is triggered when the head tracking status is changed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                                | Mandatory| Description                                      |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string | Yes  | Event type. The event **'headTrackingEnabledChangeForAnyDevice'** is triggered when the head tracking status is changed.|
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | Yes  | Callback used to return the result, indicating whether head tracking is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('headTrackingEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
});
```

### off('headTrackingEnabledChange')<sup>(deprecated)</sup>

off(type: 'headTrackingEnabledChange', callback?: Callback<boolean\>): void

Unsubscribes from the head tracking status change event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 11 and deprecated since API version 12. You are advised to use [off(type: 'headTrackingEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void](#offheadtrackingenabledchangeforanydevice12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | Yes  | Event type. The event **'headTrackingEnabledChange'** is triggered when the head tracking status is changed.|
| callback | Callback<boolean\> | No  | Callback used to return the result, indicating whether head tracking is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

// Cancel all subscriptions to the event.
audioSpatializationManager.off('headTrackingEnabledChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let headTrackingEnabledChangeCallback = (isHeadTrackingEnabled: boolean) => {
  console.info(`isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
};

audioSpatializationManager.on('headTrackingEnabledChange', headTrackingEnabledChangeCallback);

audioSpatializationManager.off('headTrackingEnabledChange', headTrackingEnabledChangeCallback);
```

### off('headTrackingEnabledChangeForAnyDevice')<sup>12+</sup>

off(type: 'headTrackingEnabledChangeForAnyDevice', callback?: Callback<AudioSpatialEnabledStateForDevice\>): void

Unsubscribes from the head tracking status change event. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | Yes  | Event type. The event **'headTrackingEnabledChangeForAnyDevice'** is triggered when the head tracking status is changed.|
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | Yes  | Callback used to return the result, indicating whether head tracking is enabled. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

// Cancel all subscriptions to the event.
audioSpatializationManager.off('headTrackingEnabledChangeForAnyDevice');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let headTrackingEnabledChangeForAnyDeviceCallback = (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
};

audioSpatializationManager.on('headTrackingEnabledChangeForAnyDevice', headTrackingEnabledChangeForAnyDeviceCallback);

audioSpatializationManager.off('headTrackingEnabledChangeForAnyDevice', headTrackingEnabledChangeForAnyDeviceCallback);
```

### updateSpatialDeviceState<sup>11+</sup>

updateSpatialDeviceState(spatialDeviceState: AudioSpatialDeviceState): void

Updates the state information of a spatial device. This API returns the result synchronously.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| spatialDeviceState     | [AudioSpatialDeviceState](#audiospatialdevicestate11)     | Yes  | New state information of the spatial device.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let spatialDeviceState: audio.AudioSpatialDeviceState = {
  address: "123",
  isSpatializationSupported: true,
  isHeadTrackingSupported: true,
  spatialDeviceType: audio.AudioSpatialDeviceType.SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE
};

try {
  audioSpatializationManager.updateSpatialDeviceState(spatialDeviceState);
  console.info(`AudioSpatializationManager updateSpatialDeviceState success`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### setSpatializationSceneType<sup>12+</sup>

setSpatializationSceneType(spatializationSceneType: AudioSpatializationSceneType): void

Sets the scene type for spatial audio rendering. This API returns the result synchronously.

**Required permissions**: ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| spatializationSceneType     | [AudioSpatializationSceneType](#audiospatializationscenetype12)     | Yes  | Scene type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  audioSpatializationManager.setSpatializationSceneType(audio.AudioSpatializationSceneType.DEFAULT);
  console.info(`AudioSpatializationManager setSpatializationSceneType success`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### getSpatializationSceneType<sup>12+</sup>

getSpatializationSceneType(): AudioSpatializationSceneType

Obtains the scene type of spatial audio rendering in use. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| [AudioSpatializationSceneType](#audiospatializationscenetype12) | Scene type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let spatializationSceneType: audio.AudioSpatializationSceneType = audioSpatializationManager.getSpatializationSceneType();
  console.info(`AudioSpatializationManager spatializationSceneType: ${spatializationSceneType}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## AudioSpatialDeviceState<sup>11+</sup>

Defines the state information of a spatial device.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

| Name                         | Type                      | Read-Only| Optional| Description      |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| address | string         | No| No| Address of the spatial device.|
| isSpatializationSupported | boolean        | No| No| Whether the spatial device supports spatial audio rendering. **true** if supported, **false** otherwise.|
| isHeadTrackingSupported | boolean        | No| No| Whether the spatial device supports head tracking. **true** if supported, **false** otherwise.|
| spatialDeviceType | [AudioSpatialDeviceType](#audiospatialdevicetype11)   | No| No| Type of the spatial device.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let spatialDeviceState: audio.AudioSpatialDeviceState = {
  address: "123",
  isSpatializationSupported: true,
  isHeadTrackingSupported: true,
  spatialDeviceType: audio.AudioSpatialDeviceType.SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE
};
```

## AudioSpatialDeviceType<sup>11+</sup>

Enumerates the types of spatial devices.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

| Name                              |  Value    | Description                      |
| ---------------------------------- | ------ | ------------------------- |
| SPATIAL_DEVICE_TYPE_NONE                   | 0      |  No spatial device. |
| SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE       | 1      |  In-ear headphones.      |
| SPATIAL_DEVICE_TYPE_HALF_IN_EAR_HEADPHONE  | 2      |  Half-in-ear headphones.    |
| SPATIAL_DEVICE_TYPE_OVER_EAR_HEADPHONE     | 3      |  Over-ear headphones.      |
| SPATIAL_DEVICE_TYPE_GLASSES                | 4      |  Glasses.      |
| SPATIAL_DEVICE_TYPE_OTHERS                 | 5      |  Other type of the spatial device.|

## AudioSpatializationSceneType<sup>12+</sup>

Enumerates the scene types available for spatial audio rendering.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

| Name                              |  Value    | Description                      |
| ---------------------------------- | ------ | ------------------------- |
| DEFAULT                            | 0      |  Default scene.           |
| MUSIC                              | 1      |  Music scene for spatial audio rendering.           |
| MOVIE                              | 2      |  Movie scene for spatial audio rendering.           |
| AUDIOBOOK                          | 3      |  Audiobook scene for spatial audio rendering.         |

## ToneType<sup>9+</sup>

Enumerates the tone types of the player.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

| Name                                             |  Value   | Description                         |
| :------------------------------------------------ | :----- | :----------------------------|
| TONE_TYPE_DIAL_0                                  | 0      | DTMF tone of key 0.                |
| TONE_TYPE_DIAL_1                                  | 1      | DTMF tone of key 1.                |
| TONE_TYPE_DIAL_2                                  | 2      | DTMF tone of key 2.                |
| TONE_TYPE_DIAL_3                                  | 3      | DTMF tone of key 3.                |
| TONE_TYPE_DIAL_4                                  | 4      | DTMF tone of key 4.                |
| TONE_TYPE_DIAL_5                                  | 5      | DTMF tone of key 5.                |
| TONE_TYPE_DIAL_6                                  | 6      | DTMF tone of key 6.                |
| TONE_TYPE_DIAL_7                                  | 7      | DTMF tone of key 7.                |
| TONE_TYPE_DIAL_8                                  | 8      | DTMF tone of key 8.                |
| TONE_TYPE_DIAL_9                                  | 9      | DTMF tone of key 9.                |
| TONE_TYPE_DIAL_S                                  | 10     | DTMF tone of the star key (*).                |
| TONE_TYPE_DIAL_P                                  | 11     | DTMF tone of the pound key (#).                |
| TONE_TYPE_DIAL_A                                  | 12     | DTMF tone of key A.                |
| TONE_TYPE_DIAL_B                                  | 13     | DTMF tone of key B.                |
| TONE_TYPE_DIAL_C                                  | 14     | DTMF tone of key C.                |
| TONE_TYPE_DIAL_D                                  | 15     | DTMF tone of key D.                |
| TONE_TYPE_COMMON_SUPERVISORY_DIAL                 | 100    | Supervisory tone - dial tone.         |
| TONE_TYPE_COMMON_SUPERVISORY_BUSY                 | 101    | Supervisory tone - busy.             |
| TONE_TYPE_COMMON_SUPERVISORY_CONGESTION           | 102    | Supervisory tone - congestion.           |
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK            | 103    | Supervisory tone - radio path acknowledgment.     |
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE  | 104    | Supervisory tone - radio path not available.    |
| TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING         | 106    | Supervisory tone - call waiting tone.       |
| TONE_TYPE_COMMON_SUPERVISORY_RINGTONE             | 107    | Supervisory tone - ringing tone.           |
| TONE_TYPE_COMMON_SUPERVISORY_CALL_HOLDING<sup>18+</sup>  | 108  | Call hold tone.           |
| TONE_TYPE_COMMON_PROPRIETARY_BEEP                 | 200    | Proprietary tone - beep tone.         |
| TONE_TYPE_COMMON_PROPRIETARY_ACK                  | 201    | Proprietary tone - ACK.               |
| TONE_TYPE_COMMON_PROPRIETARY_PROMPT               | 203    | Proprietary tone - PROMPT.            |
| TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP          | 204    | Proprietary tone - double beep tone.         |

## TonePlayer<sup>9+</sup>

Provides APIs for playing and managing DTMF tones, such as dial tones, ringback tones, supervisory tones, and proprietary tones.
Before calling any API in TonePlayer, you must use [createTonePlayer](#audiocreatetoneplayer9) to create a TonePlayer instance.

**System API**: This is a system API.

### load<sup>9+</sup>

load(type: ToneType, callback: AsyncCallback&lt;void&gt;): void

Loads the DTMF tone configuration. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Parameters**

| Name         | Type                       | Mandatory | Description                           |
| :--------------| :-------------------------- | :-----| :------------------------------ |
| type           | [ToneType](#tonetype9)       | Yes   | Tone type.                |
| callback       | AsyncCallback<void\>        | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

tonePlayer.load(audio.ToneType.TONE_TYPE_DIAL_5, (err: BusinessError) => {
  if (err) {
    console.error(`callback call load failed error: ${err.message}`);
    return;
  } else {
    console.info('callback call load success');
  }
});
```

### load<sup>9+</sup>

load(type: ToneType): Promise&lt;void&gt;

Loads the DTMF tone configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Parameters**

| Name        | Type                   | Mandatory |  Description            |
| :------------- | :--------------------- | :---  | ---------------- |
| type           | [ToneType](#tonetype9)   | Yes   | Tone type. |

**Return value**

| Type           | Description                       |
| :--------------| :-------------------------- |
| Promise<void\> | Promise that returns no value.|

**Example**

```ts
tonePlayer.load(audio.ToneType.TONE_TYPE_DIAL_1).then(() => {
  console.info('promise call load ');
}).catch(() => {
  console.error('promise call load fail');
});
```

### start<sup>9+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

Starts DTMF tone playing. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

tonePlayer.start((err: BusinessError) => {
  if (err) {
    console.error(`callback call start failed error: ${err.message}`);
    return;
  } else {
    console.info('callback call start success');
  }
});
```

### start<sup>9+</sup>

start(): Promise&lt;void&gt;

Starts DTMF tone playing. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Return value**

| Type          | Description                         |
| :------------- | :---------------------------- |
| Promise<void\> | Promise that returns no value.|

**Example**

```ts
tonePlayer.start().then(() => {
  console.info('promise call start');
}).catch(() => {
  console.error('promise call start fail');
});
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

Stops the tone that is being played. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Parameters**

| Name  | Type                | Mandatory| Description                          |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

tonePlayer.stop((err: BusinessError) => {
  if (err) {
    console.error(`callback call stop error: ${err.message}`);
    return;
  } else {
    console.error('callback call stop success ');
  }
});
```

### stop<sup>9+</sup>

stop(): Promise&lt;void&gt;

Stops the tone that is being played. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Return value**

| Type          | Description                         |
| :------------- | :---------------------------- |
| Promise<void\> | Promise that returns no value.|

**Example**

```ts
tonePlayer.stop().then(() => {
  console.info('promise call stop finish');
}).catch(() => {
  console.error('promise call stop fail');
});
```

### release<sup>9+</sup>

release(callback: AsyncCallback&lt;void&gt;): void

Releases the resources associated with the TonePlayer instance. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Parameters**

| Name  | Type                | Mandatory| Description                           |
| :------- | :------------------- | :--- | :---------------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

tonePlayer.release((err: BusinessError) => {
  if (err) {
    console.error(`callback call release failed error: ${err.message}`);
    return;
  } else {
    console.info('callback call release success ');
  }
});
```

### release<sup>9+</sup>

release(): Promise&lt;void&gt;

Releases the resources associated with the TonePlayer instance. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Tone

**Return value**

| Type          | Description                         |
| :------------- | :---------------------------- |
| Promise<void\> | Promise that returns no value.|

**Example**

```ts
tonePlayer.release().then(() => {
  console.info('promise call release');
}).catch(() => {
  console.error('promise call release fail');
});
```

## AsrProcessingController<sup>12+</sup>

Implements an ASR processing controller.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

### setAsrAecMode<sup>12+</sup>

setAsrAecMode(mode: AsrAecMode): boolean

Sets an ASR AEC mode. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name| Type                        | Mandatory| Description|
|-------|----------------------------|-------|-------|
| mode | [AsrAecMode](#asraecmode12) | Yes|ASR AEC mode.|

**Return value**

| Type| Description                                   |
|-------|---------------------------------------|
| boolean | Setting result. **true** if successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed. |

**Example**

```ts
let flag = asrProcessingController.setAsrAecMode(audio.AsrAecMode.BYPASS);
```

### getAsrAecMode<sup>12+</sup>

getAsrAecMode(): AsrAecMode

Obtains the ASR AEC mode in use. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type| Description|
|-------|-------|
| [AsrAecMode](#asraecmode12) |ASR AEC mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 6800104 | Operation not allowed. |


**Example**

```ts
let mode = asrProcessingController.getAsrAecMode();
```

### setAsrNoiseSuppressionMode<sup>12+</sup>

setAsrNoiseSuppressionMode(mode: AsrNoiseSuppressionMode): boolean

Sets an ASR noise suppression mode. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name| Type                                                   | Mandatory| Description|
|-------|-------------------------------------------------------|-------|-------|
| mode | [AsrNoiseSuppressionMode](#asrnoisesuppressionmode12) | Yes|ASR noise suppression mode.|

**Return value**

| Type| Description                                    |
|-------|----------------------------------------|
| boolean | Setting result. **true** if successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed. |

**Example**

```ts
let flag = asrProcessingController.setAsrNoiseSuppressionMode(audio.AsrNoiseSuppressionMode.BYPASS);
```

### getAsrNoiseSuppressionMode<sup>12+</sup>

getAsrNoiseSuppressionMode(): AsrNoiseSuppressionMode

Obtains the ASR noise suppression mode in use. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                     |Description|
|-------------------------|-------|
| [AsrNoiseSuppressionMode](#asrnoisesuppressionmode12) |ASR noise suppression mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 6800104 | Operation not allowed. |

**Example**

```ts
let mode = asrProcessingController.getAsrNoiseSuppressionMode();
```

### isWhispering<sup>12+</sup>

isWhispering(): boolean

Checks whether it is in the whisper state.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type| Description                      |
|-------|--------------------------|
| boolean | Check result for whether it is in the whisper state. **true** if in the whisper state, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 6800104 | Operation not allowed. |

**Example**

```ts
let flag = asrProcessingController.isWhispering();
```

### setAsrWhisperDetectionMode<sup>12+</sup>

setAsrWhisperDetectionMode(mode: AsrWhisperDetectionMode): boolean

Sets an ASR whisper detection mode.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type                 | Mandatory| Description    |
|------|---------------------|-------|--------|
| mode | [AsrWhisperDetectionMode](#asrwhisperdetectionmode12) | Yes| ASR whisper detection mode.|

**Return value**

| Type| Description                                    |
|-------|----------------------------------------|
| boolean | Setting result. **true** if successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters unspecified; 2.Incorrect parameter types.                 |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed.                 |

**Example**

```ts
let flag = asrProcessingController.setAsrWhisperDetectionMode(audio.AsrWhisperDetectionMode.BYPASS);
```


### getAsrWhisperDetectionMode<sup>12+</sup>

getAsrWhisperDetectionMode(): AsrWhisperDetectionMode

Obtains the ASR whisper detection mode. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type| Description    |
|-------|--------|
| [AsrWhisperDetectionMode](#asrwhisperdetectionmode12) | ASR whisper detection mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 6800104 | Operation not allowed.                 |

**Example**

```ts
let mode = asrProcessingController.getAsrWhisperDetectionMode();
```


### setAsrVoiceControlMode<sup>12+</sup>

setAsrVoiceControlMode(mode: AsrVoiceControlMode, enable: boolean): boolean

Sets an ASR voice control mode of the uplink channel for reporting modem and call recording during a call.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type                 | Mandatory| Description    |
|------|---------------------|-------|--------|
| mode | [AsrVoiceControlMode](#asrvoicecontrolmode12) | Yes| ASR voice control mode.|
| enable   | boolean             | Yes| Whether to enable the ASR voice control mode. **true** to enable, **false** otherwise.  |

**Return value**

| Type| Description                                                           |
|-------|---------------------------------------------------------------|
| boolean | Setting result. **true** if successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters unspecified; 2.Incorrect parameter types.                 |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed.                 |

**Example**

```ts
let flag = asrProcessingController.setAsrVoiceControlMode(audio.AsrVoiceControlMode.AUDIO_2_VOICE_TX, true);
```

### setAsrVoiceMuteMode<sup>12+</sup>

setAsrVoiceMuteMode(mode: AsrVoiceMuteMode, enable: boolean): boolean

Sets an ASR voice mute mode.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type                                   | Mandatory| Description      |
|------|---------------------------------------|-------|----------|
| mode | [AsrVoiceMuteMode](#asrvoicemutemode12) | Yes| ASR voice mute mode.|
| enable   | boolean                               | Yes| Whether to enable the ASR voice mute mode. **true** to enable, **false** otherwise.|

**Return value**

| Type| Description                                              |
|-------|--------------------------------------------------|
| boolean | Setting result. **true** if successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID  | Error Message                                    |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters unspecified; 2.Incorrect parameter types.                 |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed.                 |

**Example**

```ts
let flag = asrProcessingController.setAsrVoiceMuteMode(audio.AsrVoiceMuteMode.OUTPUT_MUTE, true);
```
