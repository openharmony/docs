# @ohos.multimedia.audio (Audio Management)

The **Audio** module provides basic audio management capabilities, including audio volume and audio device management, and audio data collection and rendering.

This module provides the following common audio-related functions:

- [AudioManager](#audiomanager): audio management.
- [AudioRenderer](#audiorenderer8): audio rendering, used to play Pulse Code Modulation (PCM) audio data.
- [AudioCapturer](#audiocapturer8): audio capture, used to record PCM audio data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## Constants

| Name                                   | Type     | Readable | Writable| Description              |
| --------------------------------------- | ----------| ---- | ---- | ------------------ |
| DEFAULT_VOLUME_GROUP_ID<sup>9+</sup>    | number    | Yes  | No  | Default volume group ID.<br> **System capability**: SystemCapability.Multimedia.Audio.Volume      |
| DEFAULT_INTERRUPT_GROUP_ID<sup>9+</sup> | number    | Yes  | No  | Default audio interruption group ID.<br> **System capability**: SystemCapability.Multimedia.Audio.Interrupt      |

**Example**

```ts
import { audio } from '@kit.AudioKit';

const defaultVolumeGroupId = audio.DEFAULT_VOLUME_GROUP_ID;
const defaultInterruptGroupId = audio.DEFAULT_INTERRUPT_GROUP_ID;
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
```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void

Creates an **AudioRenderer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                           | Mandatory| Description            |
| -------- | ----------------------------------------------- | ---- | ---------------- |
| options  | [AudioRendererOptions](#audiorendereroptions8)  | Yes  | Renderer configurations.    |
| callback | AsyncCallback<[AudioRenderer](#audiorenderer8)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the **AudioRenderer** instance obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_1,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
  rendererFlags: 0
}

let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
}

audio.createAudioRenderer(audioRendererOptions,(err, data) => {
  if (err) {
    console.error(`AudioRenderer Created: Error: ${err}`);
  } else {
    console.info('AudioRenderer Created: Success: SUCCESS');
    let audioRenderer = data;
  }
});
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions): Promise<AudioRenderer\>

Creates an **AudioRenderer** instance. This API uses a promise to return the result.

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

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_1,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
  rendererFlags: 0
}

let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
}

let audioRenderer: audio.AudioRenderer;
audio.createAudioRenderer(audioRendererOptions).then((data) => {
  audioRenderer = data;
  console.info('AudioFrameworkRenderLog: AudioRenderer Created : Success : Stream Type: SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: AudioRenderer Created : ERROR : ${err}`);
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions, callback: AsyncCallback<AudioCapturer\>): void

Creates an **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Required permissions**: ohos.permission.MICROPHONE

This permission is required only when [SourceType](#sourcetype8) is set to **SOURCE_TYPE_MIC**.

**Parameters**

| Name  | Type                                           | Mandatory| Description            |
| :------- | :---------------------------------------------- | :--- | :--------------- |
| options  | [AudioCapturerOptions](#audiocaptureroptions8)  | Yes  | Capturer configurations.|
| callback | AsyncCallback<[AudioCapturer](#audiocapturer8)> | Yes  | Callback used to return the result. If the operation is successful, an **AudioCapturer** instance is returned; otherwise, an error object with either of the following error codes is returned:<br>Error code 6800301: indicates a parameter verification exception, permission verification exception, or system processing exception. For details, see system logs.<br>Error code 6800101: indicates that a mandatory parameter is null or the parameter type is incorrect.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
}

audio.createAudioCapturer(audioCapturerOptions, (err, data) => {
  if (err) {
    console.error(`AudioCapturer Created : Error: ${err}`);
  } else {
    console.info('AudioCapturer Created : Success : SUCCESS');
    let audioCapturer = data;
  }
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions): Promise<AudioCapturer\>

Creates an **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Required permissions**: ohos.permission.MICROPHONE

This permission is required only when [SourceType](#sourcetype8) is set to **SOURCE_TYPE_MIC**.

**Parameters**

| Name | Type                                          | Mandatory| Description            |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| options | [AudioCapturerOptions](#audiocaptureroptions8) | Yes  | Capturer configurations.|

**Return value**

| Type                                     | Description                  |
| ----------------------------------------- |----------------------|
| Promise<[AudioCapturer](#audiocapturer8)> | Promise used to return the result. If the operation is successful, an **AudioCapturer** instance is returned; otherwise, an error object with either of the following error codes is returned:<br>Error code 6800301: indicates a parameter verification exception, permission verification exception, or system processing exception. For details, see system logs.<br>Error code 6800101: indicates that a mandatory parameter is null or the parameter type is incorrect.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

let audioCapturerOptions:audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
}

let audioCapturer: audio.AudioCapturer;
audio.createAudioCapturer(audioCapturerOptions).then((data) => {
  audioCapturer = data;
  console.info('AudioCapturer Created : Success : Stream Type: SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`AudioCapturer Created : ERROR : ${err}`);
});
```

## AudioVolumeType

Enumerates the audio stream types.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name                        | Value     | Description      |
| ---------------------------- | ------ | ---------- |
| VOICE_CALL<sup>8+</sup>      | 0      | Audio stream for voice calls.|
| RINGTONE                     | 2      | Audio stream for ringtones.    |
| MEDIA                        | 3      | Audio stream for media purpose.    |
| ALARM<sup>10+</sup>          | 4      | Audio stream for alarming.    |
| ACCESSIBILITY<sup>10+</sup>  | 5      | Audio stream for accessibility.  |
| VOICE_ASSISTANT<sup>8+</sup> | 9      | Audio stream for voice assistant.|

## InterruptMode<sup>9+</sup>

Enumerates the audio interruption modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

| Name                        | Value     | Description      |
| ---------------------------- | ------ | ---------- |
| SHARE_MODE                   | 0      | Shared mode.|
| INDEPENDENT_MODE             | 1      | Independent mode.|

## DeviceFlag

Enumerates the audio device flags.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                           |  Value    | Description                       |
| ------------------------------- | ------ |---------------------------|
| OUTPUT_DEVICES_FLAG             | 1      | Output device.                    |
| INPUT_DEVICES_FLAG              | 2      | Input device.                    |
| ALL_DEVICES_FLAG                | 3      | All devices.                    |

## DeviceUsage<sup>12+</sup>

Enumerates the usage scenarios of audio devices.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                           |  Value    | Description                       |
| ------------------------------- | ------ |---------------------------|
| MEDIA_OUTPUT_DEVICES | 1      | Media output device.|
| MEDIA_INPUT_DEVICES  | 2      | Media input device.|
| ALL_MEDIA_DEVICES    | 3      | All media devices.|
| CALL_OUTPUT_DEVICES  | 4      | Call output device.|
| CALL_INPUT_DEVICES   | 8      | Call input device.|
| ALL_CALL_DEVICES     | 12     | All call devices.|

## DeviceRole

Enumerates the audio device roles.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name         |  Value   | Description          |
| ------------- | ------ | -------------- |
| INPUT_DEVICE  | 1      | Input role.|
| OUTPUT_DEVICE | 2      | Output role.|

## DeviceType

Enumerates the audio device types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                | Value    | Description                                                     |
| ---------------------| ------ | --------------------------------------------------------- |
| INVALID              | 0      | Invalid device.                                               |
| EARPIECE             | 1      | Earpiece.                                                   |
| SPEAKER              | 2      | Speaker.                                                 |
| WIRED_HEADSET        | 3      | Wired headset with a microphone.                                     |
| WIRED_HEADPHONES     | 4      | Wired headset without microphone.                                     |
| BLUETOOTH_SCO        | 7      | Bluetooth device using Synchronous Connection Oriented (SCO) links.     |
| BLUETOOTH_A2DP       | 8      | Bluetooth device using Advanced Audio Distribution Profile (A2DP) links.|
| MIC                  | 15     | Microphone.                                                 |
| USB_HEADSET          | 22     | USB Type-C headset.                                      |
| DISPLAY_PORT<sup>12+</sup>        | 23     | Display port (DP), which is used to connect to external devices.          |
| REMOTE_CAST<sup>12+</sup>        | 24     | Remote cast device.          |
| DEFAULT<sup>9+</sup> | 1000   | Default device type.                                           |

## CommunicationDeviceType<sup>9+</sup>

Enumerates the device types used for communication.

**System capability**: SystemCapability.Multimedia.Audio.Communication

| Name         | Value    | Description         |
| ------------- | ------ | -------------|
| SPEAKER       | 2      | Speaker.     |

## AudioRingMode

Enumerates the ringer modes.

**System capability**: SystemCapability.Multimedia.Audio.Communication

| Name               |  Value   | Description      |
| ------------------- | ------ | ---------- |
| RINGER_MODE_SILENT  | 0      | Silent mode.|
| RINGER_MODE_VIBRATE | 1      | Vibration mode.|
| RINGER_MODE_NORMAL  | 2      | Normal mode.|

## AudioSampleFormat<sup>8+</sup>

Enumerates the audio sample formats.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                               |  Value   | Description                      |
| ---------------------------------- | ------ | -------------------------- |
| SAMPLE_FORMAT_INVALID              | -1     | Invalid format.                |
| SAMPLE_FORMAT_U8                   | 0      | Unsigned 8-bit integer.           |
| SAMPLE_FORMAT_S16LE                | 1      | Signed 16-bit integer, little endian.|
| SAMPLE_FORMAT_S24LE                | 2      | Signed 24-bit integer, little endian.<br>Due to system restrictions, only some devices support this sampling format.|
| SAMPLE_FORMAT_S32LE                | 3      | Signed 32-bit integer, little endian.<br>Due to system restrictions, only some devices support this sampling format.|
| SAMPLE_FORMAT_F32LE<sup>9+</sup>   | 4      | Signed 32-bit floating point number, little endian.<br>Due to system restrictions, only some devices support this sampling format.|

## AudioErrors<sup>9+</sup>

Enumerates the audio error codes.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                | Value     | Description        |
| ---------------------| --------| ----------------- |
| ERROR_INVALID_PARAM  | 6800101 | Invalid parameter.        |
| ERROR_NO_MEMORY      | 6800102 | Memory allocation failure.    |
| ERROR_ILLEGAL_STATE  | 6800103 | Unsupported state.      |
| ERROR_UNSUPPORTED    | 6800104 | Unsupported parameter value.   |
| ERROR_TIMEOUT        | 6800105 | Processing timeout.        |
| ERROR_STREAM_LIMIT   | 6800201 | Too many audio streams.|
| ERROR_SYSTEM         | 6800301 | System error.    |

## AudioChannel<sup>8+</sup>

Enumerates the audio channels.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name     |  Value      | Description  |
| --------- | -------- |------|
| CHANNEL_1 | 0x1 << 0 | One audio channel (mono).|
| CHANNEL_2 | 0x1 << 1 | Two audio channels (stereo).|
| CHANNEL_3<sup>11+</sup> | 3 | Three audio channels.|
| CHANNEL_4<sup>11+</sup> | 4 | Four audio channels.|
| CHANNEL_5<sup>11+</sup> | 5 | Five audio channels.|
| CHANNEL_6<sup>11+</sup> | 6 | Six audio channels.|
| CHANNEL_7<sup>11+</sup> | 7 | Seven audio channels.|
| CHANNEL_8<sup>11+</sup> | 8 | Eight audio channels.|
| CHANNEL_9<sup>11+</sup> | 9 | Nine audio channels.|
| CHANNEL_10<sup>11+</sup> | 10 | Ten audio channels.|
| CHANNEL_12<sup>11+</sup> | 12 | Twelve audio channels.|
| CHANNEL_14<sup>11+</sup> | 14 | Fourteen audio channels.|
| CHANNEL_16<sup>11+</sup> | 16 | Sixteen audio channels.|

## AudioSamplingRate<sup>8+</sup>

Enumerates the audio sampling rates. The sampling rates supported vary according to the device in use.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name             |  Value   | Description           |
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
| SAMPLE_RATE_88200<sup>12+</sup> | 88200  | The sampling rate is 88200.|
| SAMPLE_RATE_96000 | 96000  | The sampling rate is 96000.|
| SAMPLE_RATE_176400<sup>12+</sup> | 176400  | The sampling rate is 176400.|
| SAMPLE_RATE_192000<sup>12+</sup> | 192000  | The sampling rate is 192000.|

## AudioEncodingType<sup>8+</sup>

Enumerates the audio encoding types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                 |  Value   | Description     |
| --------------------- | ------ | --------- |
| ENCODING_TYPE_INVALID | -1     | Invalid.   |
| ENCODING_TYPE_RAW     | 0      | PCM encoding.|

## AudioChannelLayout<sup>11+</sup>

Enumerates the audio channel layouts.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                           |  Value             | Description                                         |
| ------------------------------ | ---------------- | --------------------------------------------- |
| CH_LAYOUT_UNKNOWN              | 0x0              | Unknown.                                |
| CH_LAYOUT_MONO                 | 0x4              | Mono.                              |
| CH_LAYOUT_STEREO               | 0x3              | Stereo.                            |
| CH_LAYOUT_STEREO_DOWNMIX       | 0x60000000       | Stereo downmix.                    |
| CH_LAYOUT_2POINT1              | 0xB              | 2.1.                               |
| CH_LAYOUT_3POINT0              | 0x103            | 3.0.                               |
| CH_LAYOUT_SURROUND             | 0x7              | Surround.                          |
| CH_LAYOUT_3POINT1              | 0xF              | 3.1.                               |
| CH_LAYOUT_4POINT0              | 0x107            | 4.0.                               |
| CH_LAYOUT_QUAD                 | 0x33             | Quad.                              |
| CH_LAYOUT_QUAD_SIDE            | 0x603            | Quad side.                         |
| CH_LAYOUT_2POINT0POINT2        | 0x3000000003     | 2.0.2.                             |
| CH_LAYOUT_AMB_ORDER1_ACN_N3D   | 0x100000000001   | First-order FOA file in ACN_N3D (ITU standards). |
| CH_LAYOUT_AMB_ORDER1_ACN_SN3D  | 0x100000001001   | First-order FOA file in ACN_SN3D (ITU standards).|
| CH_LAYOUT_AMB_ORDER1_FUMA      | 0x100000000101   | First-order FOA file in FUMA (ITU standards).    |
| CH_LAYOUT_4POINT1              | 0x10F            | 4.1.                                 |
| CH_LAYOUT_5POINT0              | 0x607            | 5.0.                               |
| CH_LAYOUT_5POINT0_BACK         | 0x37             | 5.0 back.                          |
| CH_LAYOUT_2POINT1POINT2        | 0x300000000B     | 2.1.2.                             |
| CH_LAYOUT_3POINT0POINT2        | 0x3000000007     | 3.0.2.                             |
| CH_LAYOUT_5POINT1              | 0x60F            | 5.1.                               |
| CH_LAYOUT_5POINT1_BACK         | 0x3F             | 5.1 back.                          |
| CH_LAYOUT_6POINT0              | 0x707            | 6.0.                               |
| CH_LAYOUT_HEXAGONAL            | 0x137            | Hexagonal.                         |
| CH_LAYOUT_3POINT1POINT2        | 0x500F           | 3.1.2.                             |
| CH_LAYOUT_6POINT0_FRONT        | 0x6C3            | 6.0 front.                         |
| CH_LAYOUT_6POINT1              | 0x70F            | 6.1.                               |
| CH_LAYOUT_6POINT1_BACK         | 0x13F            | 6.1 back.                          |
| CH_LAYOUT_6POINT1_FRONT        | 0x6CB            | 6.1 front.                         |
| CH_LAYOUT_7POINT0              | 0x637            | 7.0.                               |
| CH_LAYOUT_7POINT0_FRONT        | 0x6C7            | 7.0 front.                         |
| CH_LAYOUT_7POINT1              | 0x63F            | 7.1.                               |
| CH_LAYOUT_OCTAGONAL            | 0x737            | Octagonal.                         |
| CH_LAYOUT_5POINT1POINT2        | 0x300000060F     | 5.1.2.                             |
| CH_LAYOUT_7POINT1_WIDE         | 0x6CF            | 7.1 wide.                          |
| CH_LAYOUT_7POINT1_WIDE_BACK    | 0xFF             | 7.1 wide back.                     |
| CH_LAYOUT_AMB_ORDER2_ACN_N3D   | 0x100000000002   | Second-order HOA file in ACN_N3D (ITU standards). |
| CH_LAYOUT_AMB_ORDER2_ACN_SN3D  | 0x100000001002   | Second-order HOA file in ACN_SN3D (ITU standards).|
| CH_LAYOUT_AMB_ORDER2_FUMA      | 0x100000000102   | Second-order HOA file in FUMA (ITU standards).    |
| CH_LAYOUT_5POINT1POINT4        | 0x2D60F          | 5.1.4.                             |
| CH_LAYOUT_7POINT1POINT2        | 0x300000063F     | 7.1.2.                             |
| CH_LAYOUT_7POINT1POINT4        | 0x2D63F          | 7.1.4.                             |
| CH_LAYOUT_10POINT2             | 0x180005737      | 10.2.                              |
| CH_LAYOUT_9POINT1POINT4        | 0x18002D63F      | 9.1.4.                             |
| CH_LAYOUT_9POINT1POINT6        | 0x318002D63F     | 9.1.6.                             |
| CH_LAYOUT_HEXADECAGONAL        | 0x18003F737      | Hexadecagonal.                     |
| CH_LAYOUT_AMB_ORDER3_ACN_N3D   | 0x100000000003   | Third-order HOA file in ACN_N3D (ITU standards). |
| CH_LAYOUT_AMB_ORDER3_ACN_SN3D  | 0x100000001003   | Third-order HOA file in ACN_SN3D (ITU standards).|
| CH_LAYOUT_AMB_ORDER3_FUMA      | 0x100000000103   | Third-order HOA file in FUMA (ITU standards).    |

## ContentType<sup>(deprecated)</sup>

Enumerates the audio content types.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 10. You are advised to use [StreamUsage](#streamusage) to declare the audio stream type.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                              |  Value   | Description      |
| ---------------------------------- | ------ | ---------- |
| CONTENT_TYPE_UNKNOWN               | 0      | Unknown content.|
| CONTENT_TYPE_SPEECH                | 1      | Speech.    |
| CONTENT_TYPE_MUSIC                 | 2      | Music.    |
| CONTENT_TYPE_MOVIE                 | 3      | Movie.    |
| CONTENT_TYPE_SONIFICATION          | 4      | Notification tone.  |
| CONTENT_TYPE_RINGTONE<sup>8+</sup> | 5      | Ringtone.    |

## StreamUsage

Enumerates the audio stream usage.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                                     |  Value   | Description                                                                                                                                         |
| ------------------------------------------| ------ |---------------------------------------------------------------------------------------------------------------------------------------------|
| STREAM_USAGE_UNKNOWN                      | 0      | Unknown content.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                    |
| STREAM_USAGE_MEDIA<sup>(deprecated)</sup>                        | 1      | Media.<br> This enumerated value is supported since API version 7 and deprecated since API version 10. You are advised to use **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, **STREAM_USAGE_GAME**, or **STREAM_USAGE_AUDIOBOOK** instead.|
| STREAM_USAGE_MUSIC<sup>10+</sup>          | 1      | Music.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                     |
| STREAM_USAGE_VOICE_COMMUNICATION          | 2      | VoIP voice call.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| STREAM_USAGE_VOICE_ASSISTANT<sup>9+</sup> | 3      | Voice assistant.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                     |
| STREAM_USAGE_ALARM<sup>10+</sup>          | 4      | Audio stream for alarming.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                     |
| STREAM_USAGE_VOICE_MESSAGE<sup>10+</sup>  | 5      | Voice message.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                    |
| STREAM_USAGE_NOTIFICATION_RINGTONE<sup>(deprecated)</sup>        | 6      | Notification tone.<br> This enumerated value is deprecated since API version 10. You are advised to use **STREAM_USAGE_RINGTONE** instead.                                                                         |
| STREAM_USAGE_RINGTONE<sup>10+</sup>       | 6      | Ringtone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                    |
| STREAM_USAGE_NOTIFICATION<sup>10+</sup>   | 7      | Notification.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                      |
| STREAM_USAGE_ACCESSIBILITY<sup>10+</sup>  | 8      | Accessibility.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                   |
| STREAM_USAGE_MOVIE<sup>10+</sup>          | 10     | Movie or video.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                  |
| STREAM_USAGE_GAME<sup>10+</sup>           | 11     | Gaming.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                    |
| STREAM_USAGE_AUDIOBOOK<sup>10+</sup>      | 12     | Audiobooks (including crosstalks and storytelling), news radio, and podcasts.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                   |
| STREAM_USAGE_NAVIGATION<sup>10+</sup>     | 13     | Navigation.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                     |
| STREAM_USAGE_VIDEO_COMMUNICATION<sup>12+</sup>     | 17     | VoIP video call.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                       |

## AudioState<sup>8+</sup>

Enumerates the audio states.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name          | Value    | Description            |
| -------------- | ------ | ---------------- |
| STATE_INVALID  | -1     | Invalid state.      |
| STATE_NEW      | 0      | Creating instance state.|
| STATE_PREPARED | 1      | Prepared.      |
| STATE_RUNNING  | 2      | Running.|
| STATE_STOPPED  | 3      | Stopped.      |
| STATE_RELEASED | 4      | Released.      |
| STATE_PAUSED   | 5      | Paused.      |

## AudioEffectMode<sup>10+</sup>

Enumerates the audio effect modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Value    | Description      |
| ------------------ | ------ | ---------- |
| EFFECT_NONE        | 0      | The audio effect is disabled.|
| EFFECT_DEFAULT     | 1      | The default audio effect is used.|

## AudioRendererRate<sup>8+</sup>

Enumerates the audio renderer rates.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Value    | Description      |
| ------------------ | ------ | ---------- |
| RENDER_RATE_NORMAL | 0      | Normal rate.|
| RENDER_RATE_DOUBLE | 1      | Double rate.   |
| RENDER_RATE_HALF   | 2      | Half rate. |

## InterruptType

Enumerates the audio interruption types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name                |  Value    | Description                  |
| -------------------- | ------ | ---------------------- |
| INTERRUPT_TYPE_BEGIN | 1      | Audio interruption started.|
| INTERRUPT_TYPE_END   | 2      | Audio interruption ended.|

## InterruptForceType<sup>9+</sup>

Enumerates the types of force that causes audio interruption.

The force type is obtained when an [InterruptEvent](#interruptevent9) is received.

This type specifies whether the audio interruption operation is forcibly performed by the system. The operation information (such as audio pause or stop) can be obtained through [InterruptHint](#interrupthint). For details about the audio interruption strategy, see [Processing Audio Interruption Events](../../media/audio/audio-playback-concurrency.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name           |  Value   | Description                                |
| --------------- | ------ | ------------------------------------ |
| INTERRUPT_FORCE | 0      | The operation is forcibly performed by the system.  |
| INTERRUPT_SHARE | 1      | The operation will not be performed by the system. [InterruptHint](#interrupthint) is used to provide recommended operations for the application, and the application can determine the next processing mode.|

## InterruptHint

Enumerates the hints provided along with audio interruption.

The hint is obtained when an [InterruptEvent](#interruptevent9) is received.

The hint specifies the operation (such as audio pause or volume adjustment) to be performed on audio streams based on the focus policy.

You can determine whether the operation is forcibly performed by the system based on [InterruptForceType](#interruptforcetype9) in **InterruptEvent**. For details about the audio interruption strategy, see [Processing Audio Interruption Events](../../media/audio/audio-playback-concurrency.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name                              |  Value    | Description                                        |
| ---------------------------------- | ------ | -------------------------------------------- |
| INTERRUPT_HINT_NONE<sup>8+</sup>   | 0      | None.                                     |
| INTERRUPT_HINT_RESUME              | 1      | A hint is displayed, indicating that the audio stream is restored. The application can proactively trigger operations related to rendering or recording.<br>This operation cannot be forcibly performed by the system, and the corresponding [InterruptForceType](#interruptforcetype9) must be **INTERRUPT_SHARE**.|
| INTERRUPT_HINT_PAUSE               | 2      | A hint is displayed, indicating that the audio stream is paused and the audio focus is lost temporarily.<br>The **INTERRUPT_HINT_RESUME** event will be triggered when the focus is gained. |
| INTERRUPT_HINT_STOP                | 3      | A hint is displayed, indicating that the audio stream stops and the audio focus is lost.               |
| INTERRUPT_HINT_DUCK                | 4      | A hint is displayed, indicating that audio ducking starts and the audio is played at a lower volume.|
| INTERRUPT_HINT_UNDUCK<sup>8+</sup> | 5      | A hint is displayed, indicating that audio ducking ends and the audio is played at the normal volume.           |

## AudioStreamInfo<sup>8+</sup>

Describes audio stream information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name        | Type                                              | Mandatory| Description              |
| ------------ | ------------------------------------------------- | ---- | ------------------ |
| samplingRate | [AudioSamplingRate](#audiosamplingrate8)          | Yes  | Audio sampling rate.|
| channels     | [AudioChannel](#audiochannel8)                    | Yes  | Number of audio channels.|
| sampleFormat | [AudioSampleFormat](#audiosampleformat8)          | Yes  | Audio sample format.    |
| encodingType | [AudioEncodingType](#audioencodingtype8)          | Yes  | Audio encoding type.    |
| channelLayout<sup>11+</sup> | [AudioChannelLayout](#audiochannellayout11)  | No  | Audio channel layout. The default value is **0x0**.|

## AudioRendererInfo<sup>8+</sup>

Describes audio renderer information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                       | Mandatory | Description            |
| ------------- | --------------------------- | ---- | ---------------- |
| content       | [ContentType](#contenttypedeprecated) | No  | Audio content type.<br>This parameter is mandatory in API versions 8 and 9 and optional since API version 10. The default value is **CONTENT_TYPE_UNKNOWN**. [ContentType](#contenttypedeprecated) is deprecated. You are advised to use [StreamUsage](#streamusage) to declare the audio stream type.|
| usage         | [StreamUsage](#streamusage) | Yes  | Audio stream usage.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| rendererFlags | number                      | Yes  | Audio renderer flags.<br>The value **0** means an audio renderer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## AudioRendererOptions<sup>8+</sup>

Describes audio renderer configurations.

| Name        | Type                                    | Mandatory | Description            |
| ------------ | ---------------------------------------- | ---- | ---------------- |
| streamInfo   | [AudioStreamInfo](#audiostreaminfo8)     | Yes  | Audio stream information.<br>**System capability**: SystemCapability.Multimedia.Audio.Renderer|
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) | Yes  | Audio renderer information.<br>**System capability**: SystemCapability.Multimedia.Audio.Renderer|
| privacyType<sup>10+</sup> | [AudioPrivacyType](#audioprivacytype10) | No| Whether the audio stream can be recorded by other applications. The default value is **0**.<br>**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture|

## AudioPrivacyType<sup>10+</sup>

Enumerates whether an audio stream can be recorded by other applications.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name                | Value  | Description                            |
| -------------------- | ---- | -------------------------------- |
| PRIVACY_TYPE_PUBLIC  | 0    | The audio stream can be recorded by other applications.  |
| PRIVACY_TYPE_PRIVATE | 1    | The audio stream cannot be recorded by other applications.|

## InterruptEvent<sup>9+</sup>

Describes the interruption event received by the application when playback is interrupted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name     | Type                                      |Mandatory  | Description                                |
| --------- | ------------------------------------------ | ---- | ------------------------------------ |
| eventType | [InterruptType](#interrupttype)            | Yes  | Whether the interruption has started or ended.        |
| forceType | [InterruptForceType](#interruptforcetype9) | Yes  | Whether the interruption is taken by the system or to be taken by the application.|
| hintType  | [InterruptHint](#interrupthint)            | Yes  | Hint provided along the interruption.                          |

## VolumeEvent<sup>9+</sup>

Describes the event received by the application when the volume is changed.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name      | Type                               | Mandatory  | Description                                       |
| ---------- | ----------------------------------- | ---- |-------------------------------------------|
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                   |
| volume     | number                              | Yes  | Volume to set. The value range can be obtained by calling **getMinVolume** and **getMaxVolume**. |
| updateUi   | boolean                             | Yes  | Whether the volume change is shown on the UI. The value **true** means that the volume change is shown, and **false** means the opposite.            |

## MicStateChangeEvent<sup>9+</sup>

Describes the event received by the application when the microphone mute status is changed.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name      | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- |-------------------------------------------------------- |
| mute | boolean | Yes  | Mute status of the microphone. The value **true** means that the microphone is muted, and **false** means the opposite.         |

## DeviceChangeAction

Describes the device connection status and device information.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name             | Type                                             | Mandatory| Description              |
| :---------------- | :------------------------------------------------ | :--- | :----------------- |
| type              | [DeviceChangeType](#devicechangetype)             | Yes  | Device connection status.|
| deviceDescriptors | [AudioDeviceDescriptors](#audiodevicedescriptors) | Yes  | Device information.        |

## ChannelBlendMode<sup>11+</sup>

Enumerates the audio channel blending modes.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                                        |  Value    | Description                  |
| :------------------------------------------- | :----- | :--------------------- |
| MODE_DEFAULT | 0     | The audio channels are not blended. |
| MODE_BLEND_LR | 1      | The left and right audio channels are blended.|
| MODE_ALL_LEFT | 2      | The left channel is replicated into the right channel. |
| MODE_ALL_RIGHT | 3 | The right channel is replicated into the left channel.|

## AudioStreamDeviceChangeReason<sup>11+</sup>

Enumerates the reasons for audio stream device is changed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name                                       |  Value    | Description             |
|:------------------------------------------| :----- |:----------------|
| REASON_UNKNOWN | 0 | Unknown reason.          |
| REASON_NEW_DEVICE_AVAILABLE | 1 | A new device is available.        |
| REASON_OLD_DEVICE_UNAVAILABLE | 2 | The old device is unavailable. When this reason is reported, the application should consider pausing audio playback.|
| REASON_OVERRODE | 3 | Forcibly selected.|

## AudioStreamDeviceChangeInfo<sup>11+</sup>

Describes the event received by the application when the audio stream device is changed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name             | Type                                                               | Mandatory| Description              |
| :---------------- |:------------------------------------------------------------------| :--- | :----------------- |
| devices              | [AudioDeviceDescriptors](#audiodevicedescriptors)                 | Yes  | Device information.|
| changeReason | [AudioStreamDeviceChangeReason](#audiostreamdevicechangereason11) | Yes  | Reason for the change.|

## DeviceChangeType

Enumerates the device connection statuses.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name      | Value  | Description          |
| :--------- | :--- | :------------- |
| CONNECT    | 0    | Connected.    |
| DISCONNECT | 1    | Disconnected.|

## AudioCapturerOptions<sup>8+</sup>

Describes audio capturer configurations.

| Name                               | Type                                                     | Mandatory| Description                                                        |
| ----------------------------------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| streamInfo                          | [AudioStreamInfo](#audiostreaminfo8)                      | Yes  | Audio stream information.<br>**System capability**: SystemCapability.Multimedia.Audio.Capturer  |
| capturerInfo                        | [AudioCapturerInfo](#audiocapturerinfo8)                   | Yes  | Audio capturer information.<br>**System capability**: SystemCapability.Multimedia.Audio.Capturer       |
| playbackCaptureConfig<sup>(deprecated)</sup> | [AudioPlaybackCaptureConfig](#audioplaybackcaptureconfigdeprecated) | No  | Configuration of internal audio recording.<br>**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture<br> This API is supported since API version 10 and deprecated since API version 12. The Audio module does not provide APIs for internal recording. You can use [AVScreenCapture](../apis-media-kit/_a_v_screen_capture.md) to perform internal recording.|

## AudioCapturerInfo<sup>8+</sup>

Describes audio capturer information.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                     | Mandatory| Description            |
| :------------ | :------------------------ | :--- | :--------------- |
| source        | [SourceType](#sourcetype8) | Yes  | Audio source type.      |
| capturerFlags | number                    | Yes  | Audio capturer flags.<br>The value **0** means an audio capturer.|

## SourceType<sup>8+</sup>

Enumerates the audio source types.

| Name                                        |  Value    | Description                  |
| :------------------------------------------- | :----- | :--------------------- |
| SOURCE_TYPE_INVALID                          | -1     | Invalid audio source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_MIC                              | 0      | Mic source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|
| SOURCE_TYPE_VOICE_RECOGNITION<sup>9+</sup>   | 1      | Voice recognition source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_PLAYBACK_CAPTURE<sup>(deprecated)</sup>   | 2 | Internal audio recording source.<br>**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture<br> This API is supported since API version 10 and deprecated since API version 12. The Audio module does not provide APIs for internal recording. You can use [AVScreenCapture](../apis-media-kit/_a_v_screen_capture.md) to perform internal recording.|
| SOURCE_TYPE_VOICE_COMMUNICATION              | 7      | Voice communication source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|
| SOURCE_TYPE_VOICE_MESSAGE<sup>12+</sup>      | 10     | Voice message source.<br>**System capability**: SystemCapability.Multimedia.Audio.Core|

## AudioPlaybackCaptureConfig<sup>(deprecated)</sup>

Defines the configuration of internal audio recording.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 12. The Audio module does not provide APIs for internal recording. You can use [AVScreenCapture](../apis-media-kit/_a_v_screen_capture.md) to perform internal recording.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name         | Type                                         | Mandatory| Description                            |
| ------------- | --------------------------------------------- | ---- | -------------------------------- |
| filterOptions | [CaptureFilterOptions](#capturefilteroptionsdeprecated) | Yes  | Options for filtering the played audio streams to be recorded.|

## CaptureFilterOptions<sup>(deprecated)</sup>

Defines the options for filtering the played audio streams to be recorded.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 12. The Audio module does not provide APIs for internal recording. You can use [AVScreenCapture](../apis-media-kit/_a_v_screen_capture.md) to perform internal recording.

**Required permissions**: ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO

- In API version 10, **CaptureFilterOptions** supports **StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION**, and therefore the **ohos.permission.CAPTURE_VOICE_DOWNLINK_AUDIO** permission is required. Only system applications can request this permission.

- Since API version 11, **CaptureFilterOptions** does not support **StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION**. Therefore, no permission is required for calling this API.

**System capability**: SystemCapability.Multimedia.Audio.PlaybackCapture

| Name  | Type                              | Mandatory| Description                                                        |
| ------ | ---------------------------------- | ---- | ------------------------------------------------------------ |
| usages | Array<[StreamUsage](#streamusage)> | Yes  | **StreamUsage** of the audio stream to be recorded. You can specify zero or more stream usages. If the array is empty, the audio stream for which **StreamUsage** is **STREAM_USAGE_MUSIC**, **STREAM_USAGE_MOVIE**, **STREAM_USAGE_GAME**, or **STREAM_USAGE_AUDIOBOOK** is recorded by default.|

## AudioScene<sup>8+</sup>

Enumerates the audio scenes.

**System capability**: SystemCapability.Multimedia.Audio.Communication

| Name                  |  Value    | Description                                         |
| :--------------------- | :----- | :-------------------------------------------- |
| AUDIO_SCENE_DEFAULT                  | 0      | Default audio scene.                               |
| AUDIO_SCENE_RINGING<sup>12+</sup>    | 1      | Normal mode.|
| AUDIO_SCENE_PHONE_CALL<sup>12+</sup> | 2      | Phone call scene.|
| AUDIO_SCENE_VOICE_CHAT               | 3      | Voice chat scene.                               |

## AudioConcurrencyMode<sup>12+</sup>

Enumerates the audio concurrency modes.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                  | Value| Description     |
| :--------------------- |:--|:--------|
| CONCURRENCY_DEFAULT | 0 | Uses the system strategy by default.    |
| CONCURRENCY_MIX_WITH_OTHERS | 1 | Mixes audio with other applications that are playing audio.    |
| CONCURRENCY_DUCK_OTHERS | 2 | Lowers the volume of the application that is currently playing the audio.|
| CONCURRENCY_PAUSE_OTHERS | 3 | Pauses the application that is currently playing the audio.|

## AudioSessionDeactivatedReason<sup>12+</sup>

Enumerates the reasons for deactivating an audio session.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name                  | Value| Description    |
| :--------------------- |:--|:-------|
| DEACTIVATED_LOWER_PRIORITY | 0 | The application focus is preempted.|
| DEACTIVATED_TIME_OUT | 1 | The application times out after the stream is stopped.   |

## AudioSessionStrategy<sup>12+</sup>

Describes an audio session strategy.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                                             | Mandatory| Description            |
| :------------ |:------------------------------------------------| :--- | :--------------- |
| concurrencyMode        | [AudioConcurrencyMode](#audioconcurrencymode12) | Yes  | Audio concurrency mode.      |

## AudioSessionDeactivatedEvent<sup>12+</sup>

Describes the event indicating that an audio session is deactivated.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name         | Type                                                               | Mandatory| Description            |
| :------------ |:------------------------------------------------------------------| :--- | :--------------- |
| reason        | [AudioSessionDeactivatedReason](#audiosessiondeactivatedreason12) | Yes  | Reason for deactivating an audio session.      |

## AudioManager

Implements audio volume and audio device management. Before calling any API in **AudioManager**, you must use [getAudioManager](#audiogetaudiomanager) to create an **AudioManager** instance.

### setAudioParameter<sup>(deprecated)</sup>

setAudioParameter(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets an audio parameter. This API uses an asynchronous callback to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and are not common parameters. Sample parameters are used in the sample code below.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.MODIFY_AUDIO_SETTINGS

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| key      | string                    | Yes  | Key of the audio parameter to set.  |
| value    | string                    | Yes  | Value of the audio parameter to set.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setAudioParameter('key_example', 'value_example', (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the audio parameter. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the audio parameter.');
});
```

### setAudioParameter<sup>(deprecated)</sup>

setAudioParameter(key: string, value: string): Promise&lt;void&gt;

Sets an audio parameter. This API uses a promise to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and are not common parameters. Sample parameters are used in the sample code below.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.MODIFY_AUDIO_SETTINGS

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| key    | string | Yes  | Key of the audio parameter to set.|
| value  | string | Yes  | Value of the audio parameter to set.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setAudioParameter('key_example', 'value_example').then(() => {
  console.info('Promise returned to indicate a successful setting of the audio parameter.');
});
```

### getAudioParameter<sup>(deprecated)</sup>

getAudioParameter(key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of an audio parameter. This API uses an asynchronous callback to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. The substitute API is available only for system applications.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                        |
| -------- | --------------------------- | ---- | ---------------------------- |
| key      | string                      | Yes  | Key of the audio parameter whose value is to be obtained.      |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio parameter value obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getAudioParameter('key_example', (err: BusinessError, value: string) => {
  if (err) {
    console.error(`Failed to obtain the value of the audio parameter. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the value of the audio parameter is obtained ${value}.`);
});
```

### getAudioParameter<sup>(deprecated)</sup>

getAudioParameter(key: string): Promise&lt;string&gt;

Obtains the value of an audio parameter. This API uses a promise to return the result.

This API is used to extend the audio configuration based on the hardware capability. The supported audio parameters vary according to the device and can be obtained from the device manual. The example below is for reference only.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. The substitute API is available only for system applications.

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

```ts
audioManager.getAudioParameter('key_example').then((value: string) => {
  console.info(`Promise returned to indicate that the value of the audio parameter is obtained ${value}.`);
});
```

### getAudioScene<sup>8+</sup>

getAudioScene\(callback: AsyncCallback<AudioScene\>\): void

Obtains the audio scene. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                               | Mandatory| Description                        |
| :------- | :-------------------------------------------------- | :--- | :--------------------------- |
| callback | AsyncCallback<[AudioScene](#audioscene8)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio scene obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getAudioScene((err: BusinessError, value: audio.AudioScene) => {
  if (err) {
    console.error(`Failed to obtain the audio scene mode. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the audio scene mode is obtained ${value}.`);
});
```

### getAudioScene<sup>8+</sup>

getAudioScene\(\): Promise<AudioScene\>

Obtains the audio scene. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                         | Description                        |
| :-------------------------------------------- | :--------------------------- |
| Promise<[AudioScene](#audioscene8)> | Promise used to return the audio scene.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getAudioScene().then((value: audio.AudioScene) => {
  console.info(`Promise returned to indicate that the audio scene mode is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to obtain the audio scene mode ${err}`);
});
```

### getAudioSceneSync<sup>10+</sup>

getAudioSceneSync\(\): AudioScene

Obtains the audio scene. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                         | Description                        |
| :-------------------------------------------- | :--------------------------- |
| [AudioScene](#audioscene8) | Audio scene.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: audio.AudioScene = audioManager.getAudioSceneSync();
  console.info(`indicate that the audio scene mode is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the audio scene mode ${error}`);
}
```

### getVolumeManager<sup>9+</sup>

getVolumeManager(): AudioVolumeManager

Obtains an **AudioVolumeManager** instance.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                                     | Description                         |
|-----------------------------------------| ----------------------------- |
| [AudioVolumeManager](#audiovolumemanager9) | **AudioVolumeManager** instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioVolumeManager: audio.AudioVolumeManager = audioManager.getVolumeManager();
```

### getStreamManager<sup>9+</sup>

getStreamManager(): AudioStreamManager

Obtains an **AudioStreamManager** instance.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                        | Description                         |
|--------------------------------------------| ----------------------------- |
| [AudioStreamManager](#audiostreammanager9) | **AudioStreamManager** instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamManager: audio.AudioStreamManager = audioManager.getStreamManager();
```

### getRoutingManager<sup>9+</sup>

getRoutingManager(): AudioRoutingManager

Obtains an **AudioRoutingManager** instance.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                                      | Description                         |
|------------------------------------------| ----------------------------- |
| [AudioRoutingManager](#audioroutingmanager9) | **AudioRoutingManager** instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioRoutingManager: audio.AudioRoutingManager = audioManager.getRoutingManager();
```

### getSessionManager<sup>12+</sup>

getSessionManager(): AudioSessionManager

Obtains an **AudioSessionManager** instance.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                                          | Description                         |
|----------------------------------------------| ----------------------------- |
| [AudioSessionManager](#audiosessionmanager12) | **AudioSessionManager** instance.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
```

### setVolume<sup>(deprecated)</sup>

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

Sets the volume for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setVolume](#setvolume9) in **AudioVolumeGroupManager**. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume to set. The value range can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful volume setting.');
});
```

### setVolume<sup>(deprecated)</sup>

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

Sets the volume for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setVolume](#setvolume9) in **AudioVolumeGroupManager**. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer when **volumeType** is set to **AudioVolumeType.RINGTONE**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volume     | number                              | Yes  | Volume to set. The value range can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the volume of a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getVolume](#getvolume9) in **AudioVolumeGroupManager**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream volume obtained; otherwise, **err** is an error object. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume is obtained.');
});
```

### getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the volume of a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getVolume](#getvolume9) in **AudioVolumeGroupManager**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the volume of the stream. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Example**

```ts
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promise returned to indicate that the volume is obtained ${value} .`);
});
```

### getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum volume allowed for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getMinVolume](#getminvolume9) in **AudioVolumeGroupManager**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the minimum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the minimum volume is obtained. ${value}`);
});
```

### getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the minimum volume allowed for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getMinVolume](#getminvolume9) in **AudioVolumeGroupManager**.

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

```ts
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promised returned to indicate that the minimum volume is obtained. ${value}`);
});
```

### getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum volume allowed for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getMaxVolume](#getmaxvolume9) in **AudioVolumeGroupManager**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                  |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.          |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the maximum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the maximum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the maximum volume is obtained. ${value}`);
});
```

### getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the maximum volume allowed for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getMaxVolume](#getmaxvolume9) in **AudioVolumeGroupManager**.

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

```ts
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data: number) => {
  console.info('Promised returned to indicate that the maximum volume is obtained.');
});
```

### mute<sup>(deprecated)</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only for system applications.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Mute status to set. The value **true** means to mute the stream, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.mute(audio.AudioVolumeType.MEDIA, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the stream. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the stream is muted.');
});
```

### mute<sup>(deprecated)</sup>

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

Mutes or unmutes a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only for system applications.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                 |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                         |
| mute       | boolean                             | Yes  | Mute status to set. The value **true** means to mute the stream, and **false** means the opposite.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**


```ts
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
  console.info('Promise returned to indicate that the stream is muted.');
});
```

### isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is muted. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isMute](#ismute9) in **AudioVolumeGroupManager**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                           |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                   |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isMute(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the stream is obtained. ${value}`);
});
```

### isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is muted. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isMute](#ismute9) in **AudioVolumeGroupManager**.

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

```ts
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the stream is obtained ${value}.`);
});
```

### isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is active. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isActive](#isactive9) in **AudioStreamManager**.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                             |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                     |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is active or **false** if not active; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isActive(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the active status of the stream. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the active status of the stream is obtained ${value}.`);
});
```

### isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is active. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isActive](#isactive9) in **AudioStreamManager**.

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

```ts
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the active status of the stream is obtained ${value}.`);
});
```

### setRingerMode<sup>(deprecated)</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

Sets the ringer mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                           | Mandatory| Description                    |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](#audioringmode) | Yes  | Ringer mode.          |
| callback | AsyncCallback&lt;void&gt;       | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the ringer mode. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the ringer mode.');
});
```

### setRingerMode<sup>(deprecated)</sup>

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

Sets the ringer mode. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only for system applications.


**Required permissions**: ohos.permission.ACCESS_NOTIFICATION_POLICY

This permission is required only for muting or unmuting the ringer.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](#audioringmode) | Yes  | Ringer mode.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
  console.info('Promise returned to indicate a successful setting of the ringer mode.');
});
```

### getRingerMode<sup>(deprecated)</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

Obtains the ringer mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getRingerMode](#getringermode9) in **AudioVolumeGroupManager**.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name  | Type                                                | Mandatory| Description                    |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](#audioringmode)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the ringer mode obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getRingerMode((err: BusinessError, value: audio.AudioRingMode) => {
  if (err) {
    console.error(`Failed to obtain the ringer mode. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the ringer mode is obtained ${value}.`);
});
```

### getRingerMode<sup>(deprecated)</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

Obtains the ringer mode. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getRingerMode](#getringermode9) in **AudioVolumeGroupManager**.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Return value**

| Type                                          | Description                           |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](#audioringmode)&gt; | Promise used to return the ringer mode.|

**Example**

```ts
audioManager.getRingerMode().then((value: audio.AudioRingMode) => {
  console.info(`Promise returned to indicate that the ringer mode is obtained ${value}.`);
});
```

### getDevices<sup>(deprecated)</sup>

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the audio devices with a specific flag. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getDevices](#getdevices9) in **AudioRoutingManager**.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceFlag | [DeviceFlag](#deviceflag)                                    | Yes  | Audio device flag.    |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio devices obtained; otherwise, **err** is an error object.|

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err: BusinessError, value: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`Failed to obtain the device list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device list is obtained.');
});
```

### getDevices<sup>(deprecated)</sup>

getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the audio devices with a specific flag. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getDevices](#getdevices9) in **AudioRoutingManager**.

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

```ts
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data: audio.AudioDeviceDescriptors) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

### setDeviceActive<sup>(deprecated)</sup>

setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets a device to the active state. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCommunicationDevice](#setcommunicationdevice9) in **AudioRoutingManager**.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description         |
| ---------- | ------------------------------------- | ---- |-------------|
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | Yes  | Active audio device type.  |
| active     | boolean                               | Yes  | Active state to set. The value **true** means to set the device to the active state, and **false** means the opposite.    |
| callback   | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device is set to the active status.');
});
```

### setDeviceActive<sup>(deprecated)</sup>

setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise&lt;void&gt;

Sets a device to the active state. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCommunicationDevice](#setcommunicationdevice9) in **AudioRoutingManager**.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description              |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | Yes  | Active audio device type.|
| active     | boolean                               | Yes  | Active state to set. The value **true** means to set the device to the active state, and **false** means the opposite.    |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**


```ts
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true).then(() => {
  console.info('Promise returned to indicate that the device is set to the active status.');
});
```

### isDeviceActive<sup>(deprecated)</sup>

isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a device is active. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isCommunicationDeviceActive](#iscommunicationdeviceactive9) in **AudioRoutingManager**.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description                    |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | Yes  | Active audio device type.      |
| callback   | AsyncCallback&lt;boolean&gt;          | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is active or **false** if not active; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the active status of the device is obtained.');
});
```

### isDeviceActive<sup>(deprecated)</sup>

isDeviceActive(deviceType: ActiveDeviceType): Promise&lt;boolean&gt;

Checks whether a device is active. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isCommunicationDeviceActive](#iscommunicationdeviceactive9) in **AudioRoutingManager**.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name    | Type                                 | Mandatory| Description              |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | Yes  | Active audio device type.|

**Return value**

| Type                   | Description                           |
| ---------------------- |---------------------------------------|
| Promise&lt;boolean&gt; | Promise used to return the active status of the device. The value **true** means that the device is active, and **false** means the opposite. |

**Example**

```ts
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER).then((value: boolean) => {
  console.info(`Promise returned to indicate that the active status of the device is obtained ${value}.`);
});
```

### setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes the microphone. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                     | Mandatory| Description                                         |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | Yes  | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.setMicrophoneMute(true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the microphone. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the microphone is muted.');
});
```

### setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

Mutes or unmutes the microphone. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name| Type   | Mandatory| Description                                         |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | Yes  | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioManager.setMicrophoneMute(true).then(() => {
  console.info('Promise returned to indicate that the microphone is muted.');
});
```

### isMicrophoneMute<sup>(deprecated)</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the microphone is muted. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isMicrophoneMute](#ismicrophonemute9) in **AudioVolumeGroupManager**.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                        | Mandatory| Description                                                   |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the microphone is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioManager.isMicrophoneMute((err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status of the microphone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### isMicrophoneMute<sup>(deprecated)</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

Checks whether the microphone is muted. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isMicrophoneMute](#ismicrophonemute9) in **AudioVolumeGroupManager**.

**Required permissions**: ohos.permission.MICROPHONE

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the mute status of the microphone. The value **true** means that the microphone is muted, and **false** means the opposite.|

**Example**

```ts
audioManager.isMicrophoneMute().then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### on('deviceChange')<sup>(deprecated)</sup>

on(type: 'deviceChange', callback: Callback<DeviceChangeAction\>): void

Subscribes to audio device change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the connection status of an audio device is changed. 

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [on('deviceChange')](#ondevicechange9) in **AudioRoutingManager**.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                                | Mandatory| Description                                      |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | Yes  | Event type. The value is fixed at **'deviceChange'**.|
| callback | Callback<[DeviceChangeAction](#devicechangeaction)\> | Yes  | Callback used to return the device change details.|

**Example**

```ts
audioManager.on('deviceChange', (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`device change type : ${deviceChanged.type} `);
  console.info(`device descriptor size : ${deviceChanged.deviceDescriptors.length} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceRole} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceType} `);
});
```

### off('deviceChange')<sup>(deprecated)</sup>

off(type: 'deviceChange', callback?: Callback<DeviceChangeAction\>): void

Unsubscribes from audio device change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [off('deviceChange')](#offdevicechange9) in **AudioRoutingManager**.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | Yes  | Event type. The value is fixed at **'deviceChange'**.|
| callback | Callback<[DeviceChangeAction](#devicechangeaction)> | No  | Callback used to return the device change details.|

**Example**

```ts
audioManager.off('deviceChange');
```

### on('interrupt')<sup>(deprecated)</sup>

on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void

Subscribes to audio interruption events. This API uses an asynchronous callback to return the result. Such an event is triggered when the application's audio is interrupted by another playback event. 

Same as [on('audioInterrupt')](#onaudiointerrupt9), this API is used to listen for focus is changed. However, this API is used in scenarios without audio streams (no **AudioRenderer** instance is created), such as frequency modulation (FM) and voice wakeup.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. You are advised to use [on('audioInterrupt')](#onaudiointerrupt10) in **AudioCapturer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                                                     | Mandatory| Description                                                        |
| --------- |---------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                                                  | Yes  | Event type. The value is fixed at **'interrupt'**.|
| interrupt | [AudioInterrupt](#audiointerruptdeprecated)             | Yes  | Audio interruption event type.                                    |
| callback  | Callback<[InterruptAction](#interruptactiondeprecated)> | Yes  | Callback used to return the audio interruption event.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let interAudioInterrupt: audio.AudioInterrupt = {
  streamUsage:2,
  contentType:0,
  pauseWhenDucked:true
};
audioManager.on('interrupt', interAudioInterrupt, (InterruptAction: audio.InterruptAction) => {
  if (InterruptAction.actionType === 0) {
    console.info('An event to gain the audio focus starts.');
    console.info(`Focus gain event: ${InterruptAction} `);
  }
  if (InterruptAction.actionType === 1) {
    console.info('An audio interruption event starts.');
    console.info(`Audio interruption event: ${InterruptAction} `);
  }
});
```

### off('interrupt')<sup>(deprecated)</sup>

off(type: 'interrupt', interrupt: AudioInterrupt, callback?: Callback\<InterruptAction>): void

Unsubscribes from audio interruption events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 11. You are advised to use [off('audioInterrupt')](#offaudiointerrupt10) in **AudioCapturer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                                                     | Mandatory| Description                                                        |
| --------- |---------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type      | string                                                  | Yes  | Event type. The value is fixed at **'interrupt'**.|
| interrupt | [AudioInterrupt](#audiointerruptdeprecated)                       | Yes  | Audio interruption event type.                                    |
| callback  | Callback<[InterruptAction](#interruptactiondeprecated)> | No  | Callback used to return the audio interruption event.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let interAudioInterrupt: audio.AudioInterrupt = {
  streamUsage:2,
  contentType:0,
  pauseWhenDucked:true
};
audioManager.off('interrupt', interAudioInterrupt, (InterruptAction: audio.InterruptAction) => {
  if (InterruptAction.actionType === 0) {
    console.info('An event to release the audio focus starts.');
    console.info(`Focus release event: ${InterruptAction} `);
  }
});
```

## AudioVolumeManager<sup>9+</sup>

Implements audio volume management. Before calling an API in **AudioVolumeManager**, you must use [getVolumeManager](#getvolumemanager9) to obtain an **AudioVolumeManager** instance.

### getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager\>\): void

Obtains the volume group manager. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- |-----------------------------------------------------------|
| groupId    | number                                    | Yes  | Volume group ID. The default value is **LOCAL_VOLUME_GROUP_ID**.                         |
| callback   | AsyncCallback&lt;[AudioVolumeGroupManager](#audiovolumegroupmanager9)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the volume group manager obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let groupId: number = audio.DEFAULT_VOLUME_GROUP_ID;
audioVolumeManager.getVolumeGroupManager(groupId, (err: BusinessError, value: audio.AudioVolumeGroupManager) => {
  if (err) {
    console.error(`Failed to obtain the volume group infos list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
});

```

### getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number\): Promise<AudioVolumeGroupManager\>

Obtains the volume group manager. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description                              |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| groupId    | number                                   | Yes  | Volume group ID. The default value is **LOCAL_VOLUME_GROUP_ID**.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt; [AudioVolumeGroupManager](#audiovolumegroupmanager9) &gt; | Promise used to return the volume group manager.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let groupId: number = audio.DEFAULT_VOLUME_GROUP_ID;
let audioVolumeGroupManager: audio.AudioVolumeGroupManager | undefined = undefined;
async function getVolumeGroupManager(){
  audioVolumeGroupManager = await audioVolumeManager.getVolumeGroupManager(groupId);
  console.info('Promise returned to indicate that the volume group infos list is obtained.');
}
```

### getVolumeGroupManagerSync<sup>10+</sup>

getVolumeGroupManagerSync(groupId: number\): AudioVolumeGroupManager

Obtains the volume group manager. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description                              |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| groupId    | number                                   | Yes  | Volume group ID. The default value is **LOCAL_VOLUME_GROUP_ID**.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| [AudioVolumeGroupManager](#audiovolumegroupmanager9) | Volume group manager.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioVolumeGroupManager: audio.AudioVolumeGroupManager = audioVolumeManager.getVolumeGroupManagerSync(audio.DEFAULT_VOLUME_GROUP_ID);
  console.info(`Get audioVolumeGroupManager success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get audioVolumeGroupManager, error: ${error}`);
}
```

### on('volumeChange')<sup>9+</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

Subscribes to system volume change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the system volume is changed.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The value is fixed at **'volumeChange'**.|
| callback | Callback<[VolumeEvent](#volumeevent9)> | Yes  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### off('volumeChange')<sup>12+</sup>

off(type: 'volumeChange', callback?: Callback\<VolumeEvent>): void

Unsubscribes from system volume change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The value is fixed at **'volumeChange'**.|
| callback | Callback<[VolumeEvent](#volumeevent9)> | No  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters missing; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeManager.off('volumeChange');
```

## AudioVolumeGroupManager<sup>9+</sup>

Manages the volume of an audio group. Before calling any API in **AudioVolumeGroupManager**, you must use [getVolumeGroupManager](#getvolumegroupmanager9) to obtain an **AudioVolumeGroupManager** instance.

### getVolume<sup>9+</sup>

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the volume of a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream volume obtained; otherwise, **err** is an error object. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolume9) and [getMaxVolume](#getmaxvolume9).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume is obtained.');
});
```

### getVolume<sup>9+</sup>

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
| Promise&lt;number&gt; | Promise used to return the volume of the stream. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolume9) and [getMaxVolume](#getmaxvolume9).|

**Example**

```ts
audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promise returned to indicate that the volume is obtained ${value}.`);
});
```

### getVolumeSync<sup>10+</sup>

getVolumeSync(volumeType: AudioVolumeType): number;

Obtains the volume of a stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| number | Volume of the stream. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolume9) and [getMaxVolume](#getmaxvolume9).|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioVolumeGroupManager.getVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume, error ${error}.`);
}
```

### getMinVolume<sup>9+</sup>

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum volume allowed for a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the minimum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the minimum volume is obtained. ${value}`);
});
```

### getMinVolume<sup>9+</sup>

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

```ts
audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promised returned to indicate that the minimum volume is obtained ${value}.`);
});
```

### getMinVolumeSync<sup>10+</sup>

getMinVolumeSync(volumeType: AudioVolumeType): number;

Obtains the minimum volume allowed for a stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| number | Minimum volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioVolumeGroupManager.getMinVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the minimum volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the minimum volume, error ${error}.`);
}
```

### getMaxVolume<sup>9+</sup>

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum volume allowed for a stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                  |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.          |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the maximum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the maximum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the maximum volume is obtained. ${value}`);
});
```

### getMaxVolume<sup>9+</sup>

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

```ts
audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data: number) => {
  console.info('Promised returned to indicate that the maximum volume is obtained.');
});
```

### getMaxVolumeSync<sup>10+</sup>

getMaxVolumeSync(volumeType: AudioVolumeType): number;

Obtains the maximum volume allowed for a stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| number | Maximum volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioVolumeGroupManager.getMaxVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the maximum volume is obtained. ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the maximum volume, error ${error}.`);
}
```

### isMute<sup>9+</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is muted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                           |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                   |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the stream is obtained ${value}.`);
});
```

### isMute<sup>9+</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is muted. This API uses a promise to return the result.

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

```ts
audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the stream is obtained ${value}.`);
});
```

### isMuteSync<sup>10+</sup>

isMuteSync(volumeType: AudioVolumeType): boolean

Checks whether a stream is muted. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                  | Description                                                  |
| ---------------------- | ------------------------------------------------------ |
| boolean | **true**: The stream is muted.<br>**false**: The stream is not muted.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioVolumeGroupManager.isMuteSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the mute status of the stream is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the mute status of the stream, error ${error}.`);
}
```

### getRingerMode<sup>9+</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

Obtains the ringer mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                                | Mandatory| Description                    |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](#audioringmode)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the ringer mode obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getRingerMode((err: BusinessError, value: audio.AudioRingMode) => {
  if (err) {
    console.error(`Failed to obtain the ringer mode. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the ringer mode is obtained ${value}.`);
});
```

### getRingerMode<sup>9+</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

Obtains the ringer mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                                          | Description                           |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](#audioringmode)&gt; | Promise used to return the ringer mode.|

**Example**

```ts
audioVolumeGroupManager.getRingerMode().then((value: audio.AudioRingMode) => {
  console.info(`Promise returned to indicate that the ringer mode is obtained ${value}.`);
});
```

### getRingerModeSync<sup>10+</sup>

getRingerModeSync(): AudioRingMode

Obtains the ringer mode. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                                          | Description                           |
| ---------------------------------------------- | ------------------------------- |
| [AudioRingMode](#audioringmode) | Ringer mode.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: audio.AudioRingMode = audioVolumeGroupManager.getRingerModeSync();
  console.info(`Indicate that the ringer mode is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the ringer mode, error ${error}.`);
}
```

### on('ringerModeChange')<sup>9+</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

Subscribes to ringer mode change events. This API uses an asynchronous callback to return the result. Such an event is triggered when [audioringmode](#audioringmode) is changed.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'ringerModeChange'**.|
| callback | Callback<[AudioRingMode](#audioringmode)> | Yes  | Callback used to return the changed ringer mode.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeGroupManager.on('ringerModeChange', (ringerMode: audio.AudioRingMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
});
```

### setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes the microphone. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG (available only for system applications)

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                     | Mandatory| Description                                         |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | Yes  | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.setMicrophoneMute(true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the microphone. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the microphone is muted.');
});
```

### setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

Mutes or unmutes the microphone. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG (available only for system applications)

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name| Type   | Mandatory| Description                                         |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | Yes  | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioVolumeGroupManager.setMicrophoneMute(true).then(() => {
  console.info('Promise returned to indicate that the microphone is muted.');
});
```

### isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the microphone is muted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                        | Mandatory| Description                                                   |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the microphone is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMicrophoneMute((err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status of the microphone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

Checks whether the microphone is muted. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the mute status of the microphone. The value **true** means that the microphone is muted, and **false** means the opposite.|

**Example**

```ts
audioVolumeGroupManager.isMicrophoneMute().then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### isMicrophoneMuteSync<sup>10+</sup>

isMicrophoneMuteSync(): boolean

Checks whether the microphone is muted. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | **true**: The microphone is muted.<br>**false**: The microphone is not muted.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioVolumeGroupManager.isMicrophoneMuteSync();
  console.info(`Indicate that the mute status of the microphone is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the mute status of the microphone, error ${error}.`);
}
```

### on('micStateChange')<sup>9+</sup>

on(type: 'micStateChange', callback: Callback&lt;MicStateChangeEvent&gt;): void

Subscribes to microphone state change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the microphone state is changed.

Currently, when multiple **AudioManager** instances are used in a single process, only the subscription of the last instance takes effect, and the subscription of other instances is overwritten (even if the last instance does not initiate a subscription). Therefore, you are advised to use a single **AudioManager** instance.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The value is fixed at **'micStateChange'**.|
| callback | Callback<[MicStateChangeEvent](#micstatechangeevent9)> | Yes  | Callback used to return the changed microphone state.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeGroupManager.on('micStateChange', (micStateChange: audio.MicStateChangeEvent) => {
  console.info(`Current microphone status is: ${micStateChange.mute} `);
});
```

### isVolumeUnadjustable<sup>10+</sup>

isVolumeUnadjustable(): boolean

Checks whether the fixed volume mode is enabled. When the fixed volume mode is enabled, the volume cannot be adjusted. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                  | Description                                                  |
| ---------------------- | ------------------------------------------------------ |
| boolean            | **true**: The fixed volume mode is enabled.<br>**false**: The fixed volume mode is disabled.|

**Example**

```ts
let volumeAdjustSwitch: boolean = audioVolumeGroupManager.isVolumeUnadjustable();
console.info(`Whether it is volume unadjustable: ${volumeAdjustSwitch}.`);
```

### getSystemVolumeInDb<sup>10+</sup>

getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback&lt;number&gt;): void

Obtains the volume gain. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volumeLevel | number                         | Yes  | Volume level.                                              |
| device     | [DeviceType](#devicetype)           | Yes  | Device type.                                              |
| callback   | AsyncCallback&lt;number&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the volume gain obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getSystemVolumeInDb(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER, (err: BusinessError, dB: number) => {
  if (err) {
    console.error(`Failed to get the volume DB. ${err}`);
  } else {
    console.info(`Success to get the volume DB. ${dB}`);
  }
});
```
### getSystemVolumeInDb<sup>10+</sup>

getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise&lt;number&gt;

Obtains the volume gain. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volumeLevel | number                              | Yes  | Volume level.                                            |
| device     | [DeviceType](#devicetype)           | Yes  | Device type.                                              |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the volume gain (in dB).|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getSystemVolumeInDb(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER).then((value: number) => {
  console.info(`Success to get the volume DB. ${value}`);
}).catch((error: BusinessError) => {
  console.error(`Fail to adjust the system volume by step. ${error}`);
});
```

### getSystemVolumeInDbSync<sup>10+</sup>

getSystemVolumeInDbSync(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): number

Obtains the volume gain. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes  | Audio stream type.                                            |
| volumeLevel | number                              | Yes  | Volume level.                                            |
| device     | [DeviceType](#devicetype)           | Yes  | Device type.                                              |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| number | Volume gain (in dB).|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioVolumeGroupManager.getSystemVolumeInDbSync(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER);
  console.info(`Success to get the volume DB. ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Fail to adjust the system volume by step. ${error}`);
}
```

### getMaxAmplitudeForInputDevice<sup>12+</sup>

getMaxAmplitudeForInputDevice(inputDevice: AudioDeviceDescriptor): Promise&lt;number&gt;

Obtains the maximum amplitude of the audio stream for an input device. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ----------- | ------------------------------------- | ---- | --------------------------------------------------- |
| inputDevice | [AudioDeviceDescriptor](#audiodevicedescriptor) | Yes  | Descriptor of the target device.                                |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum amplitude, which ranges from 0 to 1.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

audioRoutingManager.getPreferredInputDeviceForCapturerInfo(capturerInfo).then((data) => {
  audioVolumeGroupManager.getMaxAmplitudeForInputDevice(data[0]).then((value) => {
    console.info(`mic volatileume amplitude is: ${value}`);
  }).catch((err: BusinessError) => {
    console.error("getMaxAmplitudeForInputDevice error" + JSON.stringify(err));
  })
}).catch((err: BusinessError) => {
  console.error("get outputDeviceId error" + JSON.stringify(err));
})
```

### getMaxAmplitudeForOutputDevice<sup>12+</sup>

getMaxAmplitudeForOutputDevice(outputDevice: AudioDeviceDescriptor): Promise&lt;number&gt;

Obtains the maximum amplitude of the audio stream for an output device. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ------------ | --------------------------------------- | ---- | -------------------------------------------------------- |
| outputDevice | [AudioDeviceDescriptor](#audiodevicedescriptor) | Yes  | Descriptor of the target device.                                            |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum amplitude, which ranges from 0 to 1.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
}

audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo).then((data) => {
  audioVolumeGroupManager.getMaxAmplitudeForOutputDevice(data[0]).then((value) => {
    console.info(`mic volatileume amplitude is: ${value}`);
  }).catch((err: BusinessError) => {
    console.error("getMaxAmplitudeForOutputDevice error" + JSON.stringify(err));
  })
}).catch((err: BusinessError) => {
  console.error("getPreferOutputDeviceForRendererInfo error" + JSON.stringify(err));
})
```

## AudioStreamManager<sup>9+</sup>

Implements audio stream management. Before calling any API in **AudioStreamManager**, you must use [getStreamManager](#getstreammanager9) to obtain an **AudioStreamManager** instance.

### getCurrentAudioRendererInfoArray<sup>9+</sup>

getCurrentAudioRendererInfoArray(callback: AsyncCallback&lt;AudioRendererChangeInfoArray&gt;): void

Obtains the information about the current audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback<[AudioRendererChangeInfoArray](#audiorendererchangeinfoarray9)> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the information about the current audio renderer obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getCurrentAudioRendererInfoArray(async (err: BusinessError, AudioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray) => {
  console.info('getCurrentAudioRendererInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getCurrentAudioRendererInfoArray :ERROR: ${err}`);
  } else {
    if (AudioRendererChangeInfoArray != null) {
      for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
        let AudioRendererChangeInfo: audio.AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
        console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
        console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
        console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
        console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`);
        for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }
});
```

### getCurrentAudioRendererInfoArray<sup>9+</sup>

getCurrentAudioRendererInfoArray(): Promise&lt;AudioRendererChangeInfoArray&gt;

Obtains the information about the current audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                                         | Description                                      |
| ------------------------------------------------------------ | ------------------------------------------------ |
| Promise<[AudioRendererChangeInfoArray](#audiorendererchangeinfoarray9)> | Promise used to return the renderer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function getCurrentAudioRendererInfoArray(){
  await audioStreamManager.getCurrentAudioRendererInfoArray().then((AudioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray) => {
    console.info(`getCurrentAudioRendererInfoArray ######### Get Promise is called ##########`);
    if (AudioRendererChangeInfoArray != null) {
      for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
        let AudioRendererChangeInfo: audio.AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
        console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
        console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
        console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
        console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`);
        for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }).catch((err: BusinessError) => {
    console.error(`getCurrentAudioRendererInfoArray :ERROR: ${err}`);
  });
}
```

### getCurrentAudioRendererInfoArraySync<sup>10+</sup>

getCurrentAudioRendererInfoArraySync(): AudioRendererChangeInfoArray

Obtains the information about the current audio renderer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                                         | Description                 |
| ------------------------------------------------------------ | --------------------------- |
| [AudioRendererChangeInfoArray](#audiorendererchangeinfoarray9) | Audio renderer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray = audioStreamManager.getCurrentAudioRendererInfoArraySync();
  console.info(`getCurrentAudioRendererInfoArraySync success.`);
  if (audioRendererChangeInfoArray != null) {
    for (let i = 0; i < audioRendererChangeInfoArray.length; i++) {
      let AudioRendererChangeInfo: audio.AudioRendererChangeInfo = audioRendererChangeInfoArray[i];
      console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
      console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
      console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
      console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`);
      for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
        console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
        console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
        console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
        console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
        console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
        console.info(`SampleRate: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
        console.info(`ChannelCount: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
        console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
      }
    }
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`getCurrentAudioRendererInfoArraySync :ERROR: ${error}`);
}
```

### getCurrentAudioCapturerInfoArray<sup>9+</sup>

getCurrentAudioCapturerInfoArray(callback: AsyncCallback&lt;AudioCapturerChangeInfoArray&gt;): void

Obtains the information about the current audio capturer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback<[AudioCapturerChangeInfoArray](#audiocapturerchangeinfoarray9)> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the information about the current audio capturer obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getCurrentAudioCapturerInfoArray(async (err: BusinessError, AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) => {
  console.info('getCurrentAudioCapturerInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getCurrentAudioCapturerInfoArray :ERROR: ${err}`);
  } else {
    if (AudioCapturerChangeInfoArray != null) {
      for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
        console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
        console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
        console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
        for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }
});
```

### getCurrentAudioCapturerInfoArray<sup>9+</sup>

getCurrentAudioCapturerInfoArray(): Promise&lt;AudioCapturerChangeInfoArray&gt;

Obtains the information about the current audio capturer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                                         | Description                                            |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| Promise<[AudioCapturerChangeInfoArray](#audiocapturerchangeinfoarray9)> | Promise used to return the audio capturer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function getCurrentAudioCapturerInfoArray(){
  await audioStreamManager.getCurrentAudioCapturerInfoArray().then((AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) => {
    console.info('getCurrentAudioCapturerInfoArray **** Get Promise Called ****');
    if (AudioCapturerChangeInfoArray != null) {
      for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
        console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
        console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
        console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
        for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }).catch((err: BusinessError) => {
    console.error(`getCurrentAudioCapturerInfoArray :ERROR: ${err}`);
  });
}
```

### getCurrentAudioCapturerInfoArraySync<sup>10+</sup>

getCurrentAudioCapturerInfoArraySync(): AudioCapturerChangeInfoArray

Obtains the information about the current audio capturer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                                         | Description                 |
| ------------------------------------------------------------ | --------------------------- |
| [AudioCapturerChangeInfoArray](#audiocapturerchangeinfoarray9) | Audio capturer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray = audioStreamManager.getCurrentAudioCapturerInfoArraySync();
  console.info('getCurrentAudioCapturerInfoArraySync success.');
  if (audioCapturerChangeInfoArray != null) {
    for (let i = 0; i < audioCapturerChangeInfoArray.length; i++) {
      console.info(`StreamId for ${i} is: ${audioCapturerChangeInfoArray[i].streamId}`);
      console.info(`Source for ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.source}`);
      console.info(`Flag  ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
      for (let j = 0; j < audioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
        console.info(`Id: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
        console.info(`Type: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
        console.info(`Role: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
        console.info(`Name: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
        console.info(`Address: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
        console.info(`SampleRate: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
        console.info(`ChannelCount: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
        console.info(`ChannelMask: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
      }
    }
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`getCurrentAudioCapturerInfoArraySync ERROR: ${error}`);
}
```

### on('audioRendererChange')<sup>9+</sup>

on(type: 'audioRendererChange', callback: Callback&lt;AudioRendererChangeInfoArray&gt;): void

Subscribes to audio renderer change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the audio playback stream status or device is changed.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'audioRendererChange'**. |
| callback | Callback<[AudioRendererChangeInfoArray](#audiorendererchangeinfoarray9)> | Yes       | Callback used to return the audio renderer information.      |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioStreamManager.on('audioRendererChange',  (AudioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray) => {
  for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
    let AudioRendererChangeInfo: audio.AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
    console.info(`## RendererChange on is called for ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
    console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
    console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
    console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`);
    for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
      console.info(`SampleRate: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCount: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
    }
  }
});
```

### off('audioRendererChange')<sup>9+</sup>

off(type: 'audioRendererChange'): void

Unsubscribes from audio renderer change events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type   | Mandatory | Description                                                  |
| ---- | ------ | --------- | ------------------------------------------------------------ |
| type | string | Yes       | Event type. The value is fixed at **'audioRendererChange'**. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioStreamManager.off('audioRendererChange');
console.info('######### RendererChange Off is called #########');
```

### on('audioCapturerChange')<sup>9+</sup>

on(type: 'audioCapturerChange', callback: Callback&lt;AudioCapturerChangeInfoArray&gt;): void

Subscribes to audio capturer change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the audio recording stream status or device is changed.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'audioCapturerChange'**. |
| callback | Callback<[AudioCapturerChangeInfoArray](#audiocapturerchangeinfoarray9)> | Yes       | Callback used to return the audio capturer information.      |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioStreamManager.on('audioCapturerChange', (AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) =>  {
  for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
    console.info(`## CapChange on is called for element ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
    console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
    console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
    for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
      console.info(`SampleRate: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCount: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
    }
  }
});

```

### off('audioCapturerChange')<sup>9+</sup>

off(type: 'audioCapturerChange'): void

Unsubscribes from audio capturer change events.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type   | Mandatory | Description                                                  |
| ---- | ------ | --------- | ------------------------------------------------------------ |
| type | string | Yes       | Event type. The value is fixed at **'audioCapturerChange'**. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioStreamManager.off('audioCapturerChange');
console.info('######### CapturerChange Off is called #########');


```

### isActive<sup>9+</sup>

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is active. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name       | Type                                | Mandatory | Description                                                  |
| ---------- | ----------------------------------- | --------- | ------------------------------------------------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes       | Audio stream types.                                          |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is active or **false** if not active; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.isActive(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
if (err) {
  console.error(`Failed to obtain the active status of the stream. ${err}`);
  return;
}
  console.info(`Callback invoked to indicate that the active status of the stream is obtained ${value}.`);
});

```

### isActive<sup>9+</sup>

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is active. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name       | Type                                | Mandatory | Description         |
| ---------- | ----------------------------------- | --------- | ------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes       | Audio stream types. |

**Return value**

| Type                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the active status of the stream. The value **true** means that the stream is active, and **false** means the opposite. |

**Example**

```ts
audioStreamManager.isActive(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the active status of the stream is obtained ${value}.`);
});

```

### isActiveSync<sup>10+</sup>

isActiveSync(volumeType: AudioVolumeType): boolean

Checks whether a stream is active. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name       | Type                                | Mandatory | Description         |
| ---------- | ----------------------------------- | --------- | ------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | Yes       | Audio stream types. |

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | **true**: The stream is active.<br> **false**: The stream is inactive. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioStreamManager.isActiveSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the active status of the stream is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the active status of the stream ${error}.`);
}

```

### getAudioEffectInfoArray<sup>10+</sup>

getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback&lt;AudioEffectInfoArray&gt;): void

Obtains information about the audio effect mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| usage    | [StreamUsage](#streamusage)                                  | Yes       | Audio stream usage.                                          |
| callback | AsyncCallback<[AudioEffectInfoArray](#audioeffectinfoarray10)> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the information about the audio effect mode obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getAudioEffectInfoArray(audio.StreamUsage.STREAM_USAGE_MUSIC, async (err: BusinessError, audioEffectInfoArray: audio.AudioEffectInfoArray) => {
  console.info('getAudioEffectInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getAudioEffectInfoArray :ERROR: ${err}`);
    return;
  } else {
    console.info(`The effect modes are: ${audioEffectInfoArray}`);
  }
});

```

### getAudioEffectInfoArray<sup>10+</sup>

getAudioEffectInfoArray(usage: StreamUsage): Promise&lt;AudioEffectInfoArray&gt;

Obtains information about the audio effect mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                        | Mandatory | Description         |
| ----- | --------------------------- | --------- | ------------------- |
| usage | [StreamUsage](#streamusage) | Yes       | Audio stream usage. |

**Return value**

| Type                                                     | Description                                                  |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[AudioEffectInfoArray](#audioeffectinfoarray10)> | Promise used to return the information about the audio effect mode obtained. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getAudioEffectInfoArray(audio.StreamUsage.STREAM_USAGE_MUSIC).then((audioEffectInfoArray: audio.AudioEffectInfoArray) => {
  console.info('getAudioEffectInfoArray ######### Get Promise is called ##########');
  console.info(`The effect modes are: ${audioEffectInfoArray}`);
}).catch((err: BusinessError) => {
  console.error(`getAudioEffectInfoArray :ERROR: ${err}`);
});

```

### getAudioEffectInfoArraySync<sup>10+</sup>

getAudioEffectInfoArraySync(usage: StreamUsage): AudioEffectInfoArray

Obtains information about the audio effect mode in use. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                        | Mandatory | Description         |
| ----- | --------------------------- | --------- | ------------------- |
| usage | [StreamUsage](#streamusage) | Yes       | Audio stream usage. |

**Return value**

| Type                                            | Description                              |
| ----------------------------------------------- | ---------------------------------------- |
| [AudioEffectInfoArray](#audioeffectinfoarray10) | Information about the audio effect mode. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioEffectInfoArray: audio.AudioEffectInfoArray = audioStreamManager.getAudioEffectInfoArraySync(audio.StreamUsage.STREAM_USAGE_MUSIC);
  console.info(`The effect modes are: ${audioEffectInfoArray}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAudioEffectInfoArraySync ERROR: ${error}`);
}

```

## AudioRoutingManager<sup>9+</sup>

Implements audio routing management. Before calling any API in **AudioRoutingManager**, you must use [getRoutingManager](#getroutingmanager9) to obtain an **AudioRoutingManager** instance.

### getDevices<sup>9+</sup>

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the audio devices with a specific flag. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name       | Type                                                         | Mandatory | Description                                                  |
| ---------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| deviceFlag | [DeviceFlag](#deviceflag)                                    | Yes       | Audio device flag.                                           |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio devices obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err: BusinessError, value: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`Failed to obtain the device list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device list is obtained.');
});

```

### getDevices<sup>9+</sup>

getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the audio devices with a specific flag. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name       | Type                      | Mandatory | Description        |
| ---------- | ------------------------- | --------- | ------------------ |
| deviceFlag | [DeviceFlag](#deviceflag) | Yes       | Audio device flag. |

**Return value**

| Type                                                         | Description                             |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise used to return the device list. |

**Example**

```ts
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data: audio.AudioDeviceDescriptors) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});

```

### getDevicesSync<sup>10+</sup>

getDevicesSync(deviceFlag: DeviceFlag): AudioDeviceDescriptors

Obtains the audio devices with a specific flag. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name       | Type                      | Mandatory | Description        |
| ---------- | ------------------------- | --------- | ------------------ |
| deviceFlag | [DeviceFlag](#deviceflag) | Yes       | Audio device flag. |

**Return value**

| Type                                              | Description  |
| ------------------------------------------------- | ------------ |
| [AudioDeviceDescriptors](#audiodevicedescriptors) | Device list. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let data: audio.AudioDeviceDescriptors = audioRoutingManager.getDevicesSync(audio.DeviceFlag.OUTPUT_DEVICES_FLAG);
  console.info(`Indicate that the device list is obtained ${data}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the device list. ${error}`);
}

```

### on('deviceChange')<sup>9+</sup>

on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback<DeviceChangeAction\>): void

Subscribes to audio device change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the connection status of an audio device is changed. 

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name       | Type                                                 | Mandatory | Description                                           |
| :--------- | :--------------------------------------------------- | :-------- | :---------------------------------------------------- |
| type       | string                                               | Yes       | Event type. The value is fixed at **'deviceChange'**. |
| deviceFlag | [DeviceFlag](#deviceflag)                            | Yes       | Audio device flag.                                    |
| callback   | Callback<[DeviceChangeAction](#devicechangeaction)\> | Yes       | Callback used to return the device change details.    |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (deviceChanged: audio.DeviceChangeAction) => {
  console.info('device change type : ' + deviceChanged.type);
  console.info('device descriptor size : ' + deviceChanged.deviceDescriptors.length);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceRole);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceType);
});

```

### off('deviceChange')<sup>9+</sup>

off(type: 'deviceChange', callback?: Callback<DeviceChangeAction\>): void

Unsubscribes from audio device change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                | Mandatory | Description                                           |
| -------- | --------------------------------------------------- | --------- | ----------------------------------------------------- |
| type     | string                                              | Yes       | Event type. The value is fixed at **'deviceChange'**. |
| callback | Callback<[DeviceChangeAction](#devicechangeaction)> | No        | Callback used to return the device change details.    |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRoutingManager.off('deviceChange');

```

### setCommunicationDevice<sup>9+</sup>

setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets a communication device to the active state. This API uses an asynchronous callback to return the result.

This API will be deprecated in a later version due to function design is changed. You are not advised to use it.

You are advised to use the [AVCastPicker component](../../media/avsession/using-switch-call-devices.md) provided by AVSession to switch between call devices.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name       | Type                                                 | Mandatory | Description                                                  |
| ---------- | ---------------------------------------------------- | --------- | ------------------------------------------------------------ |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | Yes       | Communication device type.                                   |
| active     | boolean                                              | Yes       | Active status of the device. The value **true** means to set the device to the active state, and **false** means the opposite. |
| callback   | AsyncCallback&lt;void&gt;                            | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.setCommunicationDevice(audio.CommunicationDeviceType.SPEAKER, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device is set to the active status.');
});

```

### getAvailableDevices<sup>12+</sup>

getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors

Obtains the available audio devices. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name        | Type                          | Mandatory | Description                   |
| ----------- | ----------------------------- | --------- | ----------------------------- |
| deviceUsage | [DeviceUsage](#deviceusage12) | Yes       | Usage scenario of the device. |

**Return value**

| Type                                                         | Description  |
| ------------------------------------------------------------ | ------------ |
| [AudioDeviceDescriptors](js-apis-audio.md#audiodevicedescriptors) | Device list. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let data: audio.AudioDeviceDescriptors = audioRoutingManager.getAvailableDevices(audio.DeviceUsage.MEDIA_OUTPUT_DEVICES);
  console.info(`Indicate that the device list is obtained ${data}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the device list. ${error}`);
}

```

### on('availableDeviceChange')<sup>12+</sup>

on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback<DeviceChangeAction\>): void

Subscribes to available audio device change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the connection status of available audio devices is changed. 

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name        | Type                                                         | Mandatory | Description                                                  |
| :---------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type        | string                                                       | Yes       | Event type. The value is fixed at **'availableDeviceChange'**. |
| deviceUsage | [DeviceUsage](#deviceusage12)                                | Yes       | Usage scenario of the device.                                |
| callback    | Callback<[DeviceChangeAction](js-apis-audio.md#devicechangeaction)\> | Yes       | Callback used to return the available device change details. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRoutingManager.on('availableDeviceChange', audio.DeviceUsage.MEDIA_OUTPUT_DEVICES, (deviceChanged: audio.DeviceChangeAction) => {
  console.info('device change type : ' + deviceChanged.type);
  console.info('device descriptor size : ' + deviceChanged.deviceDescriptors.length);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceRole);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceType);
});

```

### off('availableDeviceChange')<sup>12+</sup>

off(type: 'availableDeviceChange', callback?: Callback<DeviceChangeAction\>): void

Unsubscribes from available audio device change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'availableDeviceChange'**. |
| callback | Callback<[DeviceChangeAction](js-apis-audio.md#devicechangeaction)> | No        | Callback used to return the available device change details. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRoutingManager.off('availableDeviceChange');

```

### setCommunicationDevice<sup>9+</sup>

setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean): Promise&lt;void&gt;

Sets a communication device to the active state. This API uses a promise to return the result.

This API will be deprecated in a later version due to function design is changed. You are not advised to use it.

You are advised to use the [AVCastPicker component](../../media/avsession/using-switch-call-devices.md) provided by AVSession to switch between call devices.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name       | Type                                                 | Mandatory | Description                                                  |
| ---------- | ---------------------------------------------------- | --------- | ------------------------------------------------------------ |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | Yes       | Communication device type.                                   |
| active     | boolean                                              | Yes       | Active status of the device. The value **true** means to set the device to the active state, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```ts
audioRoutingManager.setCommunicationDevice(audio.CommunicationDeviceType.SPEAKER, true).then(() => {
  console.info('Promise returned to indicate that the device is set to the active status.');
});

```

### isCommunicationDeviceActive<sup>9+</sup>

isCommunicationDeviceActive(deviceType: CommunicationDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a communication device is active. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name       | Type                                                 | Mandatory | Description                                                  |
| ---------- | ---------------------------------------------------- | --------- | ------------------------------------------------------------ |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | Yes       | Communication device type.                                   |
| callback   | AsyncCallback&lt;boolean&gt;                         | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the communication device is active or **false** if not active; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.isCommunicationDeviceActive(audio.CommunicationDeviceType.SPEAKER, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the active status of the device is obtained.');
});

```

### isCommunicationDeviceActive<sup>9+</sup>

isCommunicationDeviceActive(deviceType: CommunicationDeviceType): Promise&lt;boolean&gt;

Checks whether a communication device is active. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name       | Type                                                 | Mandatory | Description                |
| ---------- | ---------------------------------------------------- | --------- | -------------------------- |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | Yes       | Communication device type. |

**Return value**

| Type                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the active status of the device. The value **true** means that the device is active, and **false** means the opposite. |

**Example**

```ts
audioRoutingManager.isCommunicationDeviceActive(audio.CommunicationDeviceType.SPEAKER).then((value: boolean) => {
  console.info(`Promise returned to indicate that the active status of the device is obtained ${value}.`);
});

```

### isCommunicationDeviceActiveSync<sup>10+</sup>

isCommunicationDeviceActiveSync(deviceType: CommunicationDeviceType): boolean

Checks whether a communication device is active. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Communication

**Parameters**

| Name       | Type                                                 | Mandatory | Description                |
| ---------- | ---------------------------------------------------- | --------- | -------------------------- |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | Yes       | Communication device type. |

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | **true**: The device is active.<br>**false**: The device is inactive. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioRoutingManager.isCommunicationDeviceActiveSync(audio.CommunicationDeviceType.SPEAKER);
  console.info(`Indicate that the active status of the device is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the active status of the device ${error}.`);
}

```

### getPreferOutputDeviceForRendererInfo<sup>10+</sup>

getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the output device with the highest priority based on the audio renderer information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                                         | Mandatory | Description                                                  |
| ------------ | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8)                     | Yes       | Audio renderer information.                                  |
| callback     | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the output device with the highest priority obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.           |
| 6800301 | System error. Return by callback.                            |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
}

async function getPreferOutputDevice() {
  audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo, (err: BusinessError, desc: audio.AudioDeviceDescriptors) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info(`device descriptor: ${desc}`);
    }
  });
}

```

### getPreferOutputDeviceForRendererInfo<sup>10+</sup>

getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the output device with the highest priority based on the audio renderer information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                     | Mandatory | Description                 |
| ------------ | ---------------------------------------- | --------- | --------------------------- |
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) | Yes       | Audio renderer information. |

**Return value**

| Type                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise used to return the information about the output device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.            |
| 6800301 | System error. Return by promise.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
}

async function getPreferOutputDevice() {
  audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo).then((desc: audio.AudioDeviceDescriptors) => {
    console.info(`device descriptor: ${desc}`);
  }).catch((err: BusinessError) => {
    console.error(`Result ERROR: ${err}`);
  })
}

```

### getPreferredOutputDeviceForRendererInfoSync<sup>10+</sup>

getPreferredOutputDeviceForRendererInfoSync(rendererInfo: AudioRendererInfo): AudioDeviceDescriptors

Obtains the output device with the highest priority based on the audio renderer information. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                     | Mandatory | Description                 |
| ------------ | ---------------------------------------- | --------- | --------------------------- |
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) | Yes       | Audio renderer information. |

**Return value**

| Type                                              | Description                                                  |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [AudioDeviceDescriptors](#audiodevicedescriptors) | Information about the output device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
}

try {
  let desc: audio.AudioDeviceDescriptors = audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(rendererInfo);
  console.info(`device descriptor: ${desc}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Result ERROR: ${error}`);
}

```

### on('preferOutputDeviceChangeForRendererInfo')<sup>10+</sup>

on(type: 'preferOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors\>): void

Subscribes to change events of the output device with the highest priority. This API uses an asynchronous callback to return the result. Such an event is triggered when the output device with the highest priority is changed.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                                         | Mandatory | Description                                                  |
| :----------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type         | string                                                       | Yes       | Event type. The value is fixed at **'preferOutputDeviceChangeForRendererInfo'**. |
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8)                     | Yes       | Audio renderer information.                                  |
| callback     | Callback<[AudioDeviceDescriptors](#audiodevicedescriptors)\> | Yes       | Callback used to return the information about the output device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
  rendererFlags : 0
}

audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', rendererInfo, (desc: audio.AudioDeviceDescriptors) => {
  console.info(`device descriptor: ${desc}`);
});

```

### off('preferOutputDeviceChangeForRendererInfo')<sup>10+</sup>

off(type: 'preferOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors\>): void

Unsubscribes from the change of the output device with the highest priority. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                        | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                                      | Yes       | Event type. The value is fixed at **'preferOutputDeviceChangeForRendererInfo'**. |
| callback | Callback<[AudioDeviceDescriptors](#audiodevicedescriptors)> | No        | Callback used to return the information about the output device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRoutingManager.off('preferOutputDeviceChangeForRendererInfo');

```

### getPreferredInputDeviceForCapturerInfo<sup>10+</sup>

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the input device with the highest priority based on the audio capturer information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                                         | Mandatory | Description                                                  |
| ------------ | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| capturerInfo | [AudioCapturerInfo](#audiocapturerinfo8)                     | Yes       | Audio capturer information.                                  |
| callback     | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the input device with the highest priority obtained; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.           |
| 6800301 | System error. Return by callback.                            |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

audioRoutingManager.getPreferredInputDeviceForCapturerInfo(capturerInfo, (err: BusinessError, desc: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`Result ERROR: ${err}`);
  } else {
    console.info(`device descriptor: ${desc}`);
  }
});

```

### getPreferredInputDeviceForCapturerInfo<sup>10+</sup>

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the input device with the highest priority based on the audio capturer information. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                     | Mandatory | Description                 |
| ------------ | ---------------------------------------- | --------- | --------------------------- |
| capturerInfo | [AudioCapturerInfo](#audiocapturerinfo8) | Yes       | Audio capturer information. |

**Return value**

| Type                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise used to return the information about the input device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.            |
| 6800301 | System error. Return by promise.                             |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

audioRoutingManager.getPreferredInputDeviceForCapturerInfo(capturerInfo).then((desc: audio.AudioDeviceDescriptors) => {
  console.info(`device descriptor: ${desc}`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});

```

### getPreferredInputDeviceForCapturerInfoSync<sup>10+</sup>

getPreferredInputDeviceForCapturerInfoSync(capturerInfo: AudioCapturerInfo): AudioDeviceDescriptors

Obtains the input device with the highest priority based on the audio capturer information. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                     | Mandatory | Description                 |
| ------------ | ---------------------------------------- | --------- | --------------------------- |
| capturerInfo | [AudioCapturerInfo](#audiocapturerinfo8) | Yes       | Audio capturer information. |

**Return value**

| Type                                              | Description                                                  |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [AudioDeviceDescriptors](#audiodevicedescriptors) | Information about the input device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

try {
  let desc: audio.AudioDeviceDescriptors = audioRoutingManager.getPreferredInputDeviceForCapturerInfoSync(capturerInfo);
  console.info(`device descriptor: ${desc}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Result ERROR: ${error}`);
}

```

### on('preferredInputDeviceChangeForCapturerInfo')<sup>10+</sup>

on(type: 'preferredInputDeviceChangeForCapturerInfo', capturerInfo: AudioCapturerInfo, callback: Callback<AudioDeviceDescriptors\>): void

Subscribes to change events of the input device with the highest priority. This API uses an asynchronous callback to return the result. Such an event is triggered when an input device with the highest priority is changed.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name         | Type                                                         | Mandatory | Description                                                  |
| :----------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type         | string                                                       | Yes       | Event type. The value is fixed at **'preferredInputDeviceChangeForCapturerInfo'**. |
| capturerInfo | [AudioCapturerInfo](#audiocapturerinfo8)                     | Yes       | Audio capturer information.                                  |
| callback     | Callback<[AudioDeviceDescriptors](#audiodevicedescriptors)\> | Yes       | Callback used to return the information about the input device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

audioRoutingManager.on('preferredInputDeviceChangeForCapturerInfo', capturerInfo, (desc: audio.AudioDeviceDescriptors) => {
  console.info(`device descriptor: ${desc}`);
});

```

### off('preferredInputDeviceChangeForCapturerInfo')<sup>10+</sup>

off(type: 'preferredInputDeviceChangeForCapturerInfo', callback?: Callback<AudioDeviceDescriptors\>): void

Unsubscribes from the change of the input device with the highest priority. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                        | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                                      | Yes       | Event type. The value is fixed at **'preferredInputDeviceChangeForCapturerInfo'**. |
| callback | Callback<[AudioDeviceDescriptors](#audiodevicedescriptors)> | No        | Callback used to return the information about the input device with the highest priority. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRoutingManager.off('preferredInputDeviceChangeForCapturerInfo');

```

## AudioSessionManager<sup>12+</sup>

Manages audio sessions. Before calling an API in **AudioSessionManager**, you must use [getSessionManager](#getsessionmanager12) to obtain an **AudioSessionManager** instance.

### activateAudioSession<sup>12+</sup>

activateAudioSession(strategy: AudioSessionStrategy): Promise\<void>

Activates an audio session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name     | Type                                            | Mandatory | Description             |
| -------- | ----------------------------------------------- | --------- | ----------------------- |
| strategy | [AudioSessionStrategy](#audiosessionstrategy12) | Yes       | Audio session strategy. |

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |
| 6800301 | System error. Returned by promise.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let strategy: audio.AudioSessionStrategy = {
  concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
}

audioSessionManager.activateAudioSession(strategy).then(() => {
  console.info('activateAudioSession SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### deactivateAudioSession<sup>12+</sup>

deactivateAudioSession(): Promise\<void>

Deactivates this audio session. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                      |
| ------- | ---------------------------------- |
| 6800301 | System error. Returned by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioSessionManager.deactivateAudioSession().then(() => {
  console.info('deactivateAudioSession SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### isAudioSessionActivated<sup>12+</sup>

isAudioSessionActivated(): boolean

Checks whether this audio session is activated.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the audio session is activated; returns **false** otherwise. |

**Example**

```ts
let isActivated = audioSessionManager.isAudioSessionActivated();

```

### on('audioSessionDeactivated')<sup>12+</sup>

on(type: 'audioSessionDeactivated', callback: Callback\<AudioSessionDeactivatedEvent>): void

Subscribes to audio session deactivation events. This API uses an asynchronous callback to return the result. Such an event is triggered when an audio session is deactivated.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'audioSessionDeactivated'**. |
| callback | Callback<[AudioSessionDeactivatedEvent](#audiosessiondeactivatedevent12)> | Yes       | Callback used to return the reason why the audio session is deactivated. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
  console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
});

```

### off('audioSessionDeactivated')<sup>12+</sup>

off(type: 'audioSessionDeactivated', callback?: Callback\<AudioSessionDeactivatedEvent>): void

Unsubscribes from audio session deactivation events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'audioSessionDeactivated'**. |
| callback | Callback<[AudioSessionDeactivatedEvent](#audiosessiondeactivatedevent12)> | No        | Callback used to return the reason why the audio session is deactivated. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters missing; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioSessionManager.off('audioSessionDeactivated');

```

## AudioRendererChangeInfoArray<sup>9+</sup>

Defines an **AudioRenderChangeInfo** array, which is read-only.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

## AudioRendererChangeInfo<sup>9+</sup>

Describes the audio renderer change event.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name              | Type                                              | Readable | Writable | Description                   |
| ----------------- | ------------------------------------------------- | -------- | -------- | ----------------------------- |
| streamId          | number                                            | Yes      | No       | Unique ID of an audio stream. |
| rendererInfo      | [AudioRendererInfo](#audiorendererinfo8)          | Yes      | No       | Audio renderer information.   |
| deviceDescriptors | [AudioDeviceDescriptors](#audiodevicedescriptors) | Yes      | No       | Audio device description.     |

**Example**

```ts
import { audio } from '@kit.AudioKit';

const audioManager = audio.getAudioManager();
let audioStreamManager = audioManager.getStreamManager();

audioStreamManager.on('audioRendererChange',  (AudioRendererChangeInfoArray) => {
  for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
    console.info(`## RendererChange on is called for ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioRendererChangeInfoArray[i].streamId}`);
    console.info(`Content for ${i} is: ${AudioRendererChangeInfoArray[i].rendererInfo.content}`);
    console.info(`Stream for ${i} is: ${AudioRendererChangeInfoArray[i].rendererInfo.usage}`);
    console.info(`Flag ${i} is: ${AudioRendererChangeInfoArray[i].rendererInfo.rendererFlags}`);
    let devDescriptor = AudioRendererChangeInfoArray[i].deviceDescriptors;
    for (let j = 0; j < AudioRendererChangeInfoArray[i].deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].name}`);
      console.info(`Addr: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].address}`);
      console.info(`SR: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
      console.info(`C ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
      console.info(`CM: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
    }
  }
});

```


## AudioCapturerChangeInfoArray<sup>9+</sup>

Defines an **AudioCapturerChangeInfo** array, which is read-only.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

## AudioCapturerChangeInfo<sup>9+</sup>

Describes the audio capturer change event.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name                | Type                                              | Readable | Writable | Description                                                  |
| ------------------- | ------------------------------------------------- | -------- | -------- | ------------------------------------------------------------ |
| streamId            | number                                            | Yes      | No       | Unique ID of an audio stream.                                |
| capturerInfo        | [AudioCapturerInfo](#audiocapturerinfo8)          | Yes      | No       | Audio capturer information.                                  |
| deviceDescriptors   | [AudioDeviceDescriptors](#audiodevicedescriptors) | Yes      | No       | Audio device description.                                    |
| muted<sup>11+</sup> | boolean                                           | Yes      | No       | Whether the audio capturer is muted. The value **true** means that the audio capturer is muted, and **false** means the opposite. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

const audioManager = audio.getAudioManager();
let audioStreamManager = audioManager.getStreamManager();

audioStreamManager.on('audioCapturerChange', (AudioCapturerChangeInfoArray) =>  {
  for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
    console.info(`## CapChange on is called for element ${i} ##`);
    console.info(`StrId for  ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
    console.info(`Src for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
    console.info(`Flag ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
    let devDescriptor = AudioCapturerChangeInfoArray[i].deviceDescriptors;
    for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
      console.info(`Addr: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
      console.info(`SR: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
      console.info(`C ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
      console.info(`CM ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
    }
  }
});

```

## AudioEffectInfoArray<sup>10+</sup>

Defines an array that contains the audio effect mode corresponding to a specific audio content type (specified by **ContentType**) and audio stream usage (specified by **StreamUsage**). The [AudioEffectMode](#audioeffectmode10) array is read-only.

## AudioDeviceDescriptors

Defines an [AudioDeviceDescriptor](#audiodevicedescriptor) array, which is read-only.

**Atomic service API**: This API can be used in atomic services since API version 12.

## AudioDeviceDescriptor

Describes an audio device.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                        | Type                                                  | Readable | Writable | Description                                                  |
| --------------------------- | ----------------------------------------------------- | -------- | -------- | ------------------------------------------------------------ |
| deviceRole                  | [DeviceRole](#devicerole)                             | Yes      | No       | Device role.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| deviceType                  | [DeviceType](#devicetype)                             | Yes      | No       | Device type.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| id<sup>9+</sup>             | number                                                | Yes      | No       | Device ID, which is unique.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| name<sup>9+</sup>           | string                                                | Yes      | No       | Device name.<br>For a Bluetooth device, you must request the **ohos.permission.USE_BLUETOOTH** permission.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| address<sup>9+</sup>        | string                                                | Yes      | No       | Device address.<br>For a Bluetooth device, you must request the **ohos.permission.USE_BLUETOOTH** permission.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| sampleRates<sup>9+</sup>    | Array&lt;number&gt;                                   | Yes      | No       | Supported sampling rates.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| channelCounts<sup>9+</sup>  | Array&lt;number&gt;                                   | Yes      | No       | Number of channels supported.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| channelMasks<sup>9+</sup>   | Array&lt;number&gt;                                   | Yes      | No       | Supported channel masks.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| displayName<sup>10+</sup>   | string                                                | Yes      | No       | Display name of the device.<br> **System capability**: SystemCapability.Multimedia.Audio.Device |
| encodingTypes<sup>11+</sup> | Array&lt;[AudioEncodingType](#audioencodingtype8)&gt; | Yes      | No       | Supported encoding types.<br> **System capability**: SystemCapability.Multimedia.Audio.Core |

**Example**

```ts
import { audio } from '@kit.AudioKit';

function displayDeviceProp(value: audio.AudioDeviceDescriptor) {
  deviceRoleValue = value.deviceRole;
  deviceTypeValue = value.deviceType;
}

let deviceRoleValue: audio.DeviceRole | undefined = undefined;;
let deviceTypeValue: audio.DeviceType | undefined = undefined;;
audio.getAudioManager().getDevices(1).then((value: audio.AudioDeviceDescriptors) => {
  console.info('AudioFrameworkTest: Promise: getDevices OUTPUT_DEVICES_FLAG');
  value.forEach(displayDeviceProp);
  if (deviceTypeValue != undefined && deviceRoleValue != undefined){
    console.info('AudioFrameworkTest: Promise: getDevices : OUTPUT_DEVICES_FLAG :  PASS');
  } else {
    console.error('AudioFrameworkTest: Promise: getDevices : OUTPUT_DEVICES_FLAG :  FAIL');
  }
});

```

## AudioDataCallbackResult<sup>12+</sup>

Enumerates the audio data callback results.

**System capability**: SystemCapability.Multimedia.Audio.Core

| Name    | Value | Description                   |
| ------- | ----- | ----------------------------- |
| INVALID | -1    | The callback data is invalid. |
| VALID   | 0     | The callback data is valid.   |

## AudioRendererWriteDataCallback<sup>12+</sup>

type AudioRendererWriteDataCallback = (data: ArrayBuffer) => AudioDataCallbackResult | void

Defines the callback function used to write data to the audio renderer.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type        | Mandatory | Description                       |
| :--- | :---------- | :-------- | :-------------------------------- |
| data | ArrayBuffer | Yes       | Data to be written to the buffer. |

**Return value**

| Type                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AudioDataCallbackResult](#audiodatacallbackresult12) \| void | If **void** or **AudioDataCallbackResult.VALID** is returned, the data is valid and will be played. If **AudioDataCallbackResult.INVALID** is returned, the data is invalid and will not be played. |

## AudioRenderer<sup>8+</sup>

Provides APIs for audio rendering. Before calling any API in **AudioRenderer**, you must use [createAudioRenderer](#audiocreateaudiorenderer8) to create an **AudioRenderer** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name               | Type                       | Readable | Writable | Description           |
| ------------------ | -------------------------- | -------- | -------- | --------------------- |
| state<sup>8+</sup> | [AudioState](#audiostate8) | Yes      | No       | Audio renderer state. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let state: audio.AudioState = audioRenderer.state;

```

### getRendererInfo<sup>8+</sup>

getRendererInfo(callback: AsyncCallback<AudioRendererInfo\>): void

Obtains the renderer information of this **AudioRenderer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                     | Mandatory | Description                                                  |
| :------- | :------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<[AudioRendererInfo](#audiorendererinfo8)\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the renderer information obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRendererInfo((err: BusinessError, rendererInfo: audio.AudioRendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`);
});

```

### getRendererInfo<sup>8+</sup>

getRendererInfo(): Promise<AudioRendererInfo\>

Obtains the renderer information of this **AudioRenderer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                               | Description                                      |
| -------------------------------------------------- | ------------------------------------------------ |
| Promise<[AudioRendererInfo](#audiorendererinfo8)\> | Promise used to return the renderer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRendererInfo().then((rendererInfo: audio.AudioRendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`)
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: RendererInfo :ERROR: ${err}`);
});

```

### getRendererInfoSync<sup>10+</sup>

getRendererInfoSync(): AudioRendererInfo

Obtains the renderer information of this **AudioRenderer** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                     | Description                 |
| ---------------------------------------- | --------------------------- |
| [AudioRendererInfo](#audiorendererinfo8) | Audio renderer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rendererInfo: audio.AudioRendererInfo = audioRenderer.getRendererInfoSync();
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`)
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRenderLog: RendererInfo :ERROR: ${error}`);
}

```

### getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

Obtains the stream information of this **AudioRenderer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                 | Mandatory | Description                                                  |
| :------- | :--------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream information obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getStreamInfo((err: BusinessError, streamInfo: audio.AudioStreamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
});

```

### getStreamInfo<sup>8+</sup>

getStreamInfo(): Promise<AudioStreamInfo\>

Obtains the stream information of this **AudioRenderer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                           | Description                                    |
| :--------------------------------------------- | :--------------------------------------------- |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | Promise used to return the stream information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getStreamInfo().then((streamInfo: audio.AudioStreamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### getStreamInfoSync<sup>10+</sup>

getStreamInfoSync(): AudioStreamInfo

Obtains the stream information of this **AudioRenderer** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                 | Description         |
| :----------------------------------- | :------------------ |
| [AudioStreamInfo](#audiostreaminfo8) | Stream information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let streamInfo: audio.AudioStreamInfo = audioRenderer.getStreamInfoSync();
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}

```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(callback: AsyncCallback<number\>): void

Obtains the stream ID of this **AudioRenderer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| :------- | :--------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<number\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream ID obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioStreamId((err: BusinessError, streamId: number) => {
  console.info(`Renderer GetStreamId: ${streamId}`);
});

```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(): Promise<number\>

Obtains the stream ID of this **AudioRenderer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type             | Description                           |
| :--------------- | :------------------------------------ |
| Promise<number\> | Promise used to return the stream ID. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioStreamId().then((streamId: number) => {
  console.info(`Renderer getAudioStreamId: ${streamId}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### getAudioStreamIdSync<sup>10+</sup>

getAudioStreamIdSync(): number

Obtains the stream ID of this **AudioRenderer** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description |
| :----- | :---------- |
| number | Stream ID.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let streamId: number = audioRenderer.getAudioStreamIdSync();
  console.info(`Renderer getAudioStreamIdSync: ${streamId}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}

```

### setAudioEffectMode<sup>10+</sup>

setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void

Sets an audio effect mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                  | Mandatory | Description                                                  |
| -------- | ------------------------------------- | --------- | ------------------------------------------------------------ |
| mode     | [AudioEffectMode](#audioeffectmode10) | Yes       | Audio effect mode to set.                                    |
| callback | AsyncCallback\<void>                  | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set params');
  } else {
    console.info('Callback invoked to indicate a successful audio effect mode setting.');
  }
});

```

### setAudioEffectMode<sup>10+</sup>

setAudioEffectMode(mode: AudioEffectMode): Promise\<void>

Sets an audio effect mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type                                  | Mandatory | Description               |
| ---- | ------------------------------------- | --------- | ------------------------- |
| mode | [AudioEffectMode](#audioeffectmode10) | Yes       | Audio effect mode to set. |

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT).then(() => {
  console.info('setAudioEffectMode SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### getAudioEffectMode<sup>10+</sup>

getAudioEffectMode(callback: AsyncCallback\<AudioEffectMode>): void

Obtains the audio effect mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                 | Mandatory | Description                                                  |
| -------- | ---------------------------------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback<[AudioEffectMode](#audioeffectmode10)> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio effect mode obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioEffectMode((err: BusinessError, effectMode: audio.AudioEffectMode) => {
  if (err) {
    console.error('Failed to get params');
  } else {
    console.info(`getAudioEffectMode: ${effectMode}`);
  }
});

```

### getAudioEffectMode<sup>10+</sup>

getAudioEffectMode(): Promise\<AudioEffectMode>

Obtains the audio effect mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                           | Description                                   |
| ---------------------------------------------- | --------------------------------------------- |
| Promise<[AudioEffectMode](#audioeffectmode10)> | Promise used to return the audio effect mode. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioEffectMode().then((effectMode: audio.AudioEffectMode) => {
  console.info(`getAudioEffectMode: ${effectMode}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

Starts the renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the operation fails, an error object with the following error code is returned:<br>Error code 6800301: indicates abnormal status, focus preemption failure, and abnormal system processing. For details, see system logs. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.start((err: BusinessError) => {
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

| Type           | Description                                                  |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the operation fails, an error object with the following error code is returned:<br>Error code 6800301: indicates abnormal status, focus preemption failure, and abnormal system processing. For details, see system logs. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.start().then(() => {
  console.info('Renderer started');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses rendering. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.pause((err: BusinessError) => {
  if (err) {
    console.error('Renderer pause failed');
  } else {
    console.info('Renderer paused.');
  }
});

```

### pause<sup>8+</sup>

pause(): Promise\<void>

Pauses rendering. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.pause().then(() => {
  console.info('Renderer paused');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### drain<sup>8+</sup>

drain(callback: AsyncCallback\<void>): void

Drains the playback buffer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.drain((err: BusinessError) => {
  if (err) {
    console.error('Renderer drain failed');
  } else {
    console.info('Renderer drained.');
  }
});

```

### drain<sup>8+</sup>

drain(): Promise\<void>

Drains the playback buffer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.drain().then(() => {
  console.info('Renderer drained successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### flush<sup>11+</sup>

flush(): Promise\<void>

Flushes the buffer. This API is available when [AudioState](#audiostate8) is **STATE_RUNNING**, **STATE_PAUSED**, or **STATE_STOPPED**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                             |
| ------- | --------------------------------------------------------- |
| 6800103 | Operation not permit at current state. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.flush().then(() => {
  console.info('Renderer flushed successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

Stops rendering. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.stop((err: BusinessError) => {
  if (err) {
    console.error('Renderer stop failed');
  } else {
    console.info('Renderer stopped.');
  }
});

```

### stop<sup>8+</sup>

stop(): Promise\<void>

Stops rendering. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.stop().then(() => {
  console.info('Renderer stopped successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

Releases the renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.release((err: BusinessError) => {
  if (err) {
    console.error('Renderer release failed');
  } else {
    console.info('Renderer released.');
  }
});

```

### release<sup>8+</sup>

release(): Promise\<void>

Releases the renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.release().then(() => {
  console.info('Renderer released successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### write<sup>8+(deprecated)</sup>

write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void

Writes the buffer. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [on('writeData')](#onwritedata11) in **AudioRenderer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| -------- | ---------------------- | --------- | ------------------------------------------------------------ |
| buffer   | ArrayBuffer            | Yes       | Data to be written to the buffer.                            |
| callback | AsyncCallback\<number> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of bytes written; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

let bufferSize: number;
class Options {
  offset?: number;
  length?: number;
}
audioRenderer.getBufferSize().then((data: number)=> {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  console.info(`Buffer size: ${bufferSize}`);
  let path = getContext().cacheDir;
  let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
  let file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);
  fileIo.stat(filePath).then(async (stat: fileIo.Stat) => {
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize == 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    for (let i = 0;i < len; i++) {
      let options: Options = {
        offset: i * bufferSize,
        length: bufferSize
      }
      let readsize: number = await fileIo.read(file.fd, buf, options)
      let writeSize: number = await new Promise((resolve,reject)=>{
        audioRenderer.write(buf,(err: BusinessError, writeSize: number)=>{
          if(err){
            reject(err)
          }else{
            resolve(writeSize)
          }
        })
      })
    }
  });
  }).catch((err: BusinessError) => {
    console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});



```

### write<sup>8+(deprecated)</sup>

write(buffer: ArrayBuffer): Promise\<number>

Writes the buffer. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [on('writeData')](#onwritedata11) in **AudioRenderer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type        | Mandatory | Description                       |
| ------ | ----------- | --------- | --------------------------------- |
| buffer | ArrayBuffer | Yes       | Data to be written to the buffer. |

**Return value**

| Type             | Description                                         |
| ---------------- | --------------------------------------------------- |
| Promise\<number> | Promise used to return the number of written bytes. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

let bufferSize: number;
class Options {
  offset?: number;
  length?: number;
}
audioRenderer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  console.info(`BufferSize: ${bufferSize}`);
  let path = getContext().cacheDir;
  let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
  let file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);
  fileIo.stat(filePath).then(async (stat: fileIo.Stat) => {
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize == 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    for (let i = 0;i < len; i++) {
      let options: Options = {
        offset: i * bufferSize,
        length: bufferSize
      }
      let readsize: number = await fileIo.read(file.fd, buf, options)
      try{
        let writeSize: number = await audioRenderer.write(buf);
      } catch(err) {
        let error = err as BusinessError;
        console.error(`audioRenderer.write err: ${error}`);
      }
    }
  });
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});

```

### getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback\<number>): void

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| -------- | ---------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of nanoseconds obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTime((err: BusinessError, timestamp: number) => {
  console.info(`Current timestamp: ${timestamp}`);
});

```

### getAudioTime<sup>8+</sup>

getAudioTime(): Promise\<number>

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type             | Description                           |
| ---------------- | ------------------------------------- |
| Promise\<number> | Promise used to return the timestamp. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTime().then((timestamp: number) => {
  console.info(`Current timestamp: ${timestamp}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### getAudioTimeSync<sup>10+</sup>

getAudioTimeSync(): number

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description |
| ------ | ----------- |
| number | Timestamp.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let timestamp: number = audioRenderer.getAudioTimeSync();
  console.info(`Current timestamp: ${timestamp}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}

```

### getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback\<number>): void

Obtains a reasonable minimum buffer size in bytes for rendering. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| -------- | ---------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum buffer size obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number;
audioRenderer.getBufferSize((err: BusinessError, data: number) => {
  if (err) {
    console.error('getBufferSize error');
  } else {
    console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
    bufferSize = data;
  }
});

```

### getBufferSize<sup>8+</sup>

getBufferSize(): Promise\<number>

Obtains a reasonable minimum buffer size in bytes for rendering. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type             | Description                             |
| ---------------- | --------------------------------------- |
| Promise\<number> | Promise used to return the buffer size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number;
audioRenderer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});

```

### getBufferSizeSync<sup>10+</sup>

getBufferSizeSync(): number

Obtains a reasonable minimum buffer size in bytes for rendering. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description  |
| ------ | ------------ |
| number | Buffer size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number = 0;
try {
  bufferSize = audioRenderer.getBufferSizeSync();
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${bufferSize}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${error}`);
}

```

### setRenderRate<sup>8+(deprecated)</sup>

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void

Sets the render rate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [setSpeed](#setspeed11) in **AudioRenderer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                     | Mandatory | Description                                                  |
| -------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| rate     | [AudioRendererRate](#audiorendererrate8) | Yes       | Audio render rate.                                           |
| callback | AsyncCallback\<void>                     | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set params');
  } else {
    console.info('Callback invoked to indicate a successful render rate setting.');
  }
});

```

### setRenderRate<sup>8+(deprecated)</sup>

setRenderRate(rate: AudioRendererRate): Promise\<void>

Sets the render rate. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [setSpeed](#setspeed11) in **AudioRenderer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type                                     | Mandatory | Description        |
| ---- | ---------------------------------------- | --------- | ------------------ |
| rate | [AudioRendererRate](#audiorendererrate8) | Yes       | Audio render rate. |

**Return value**

| Type           | Description                    |
| -------------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL).then(() => {
  console.info('setRenderRate SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### setSpeed<sup>11+</sup>

setSpeed(speed: number): void

Sets the playback speed.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type   | Mandatory | Description                                     |
| ----- | ------ | --------- | ----------------------------------------------- |
| speed | number | Yes       | Playback speed, which ranges from 0.125 to 4.0. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRenderer.setSpeed(1.5);

```

### getRenderRate<sup>8+(deprecated)</sup>

getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void

Obtains the current render rate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [getSpeed](#getspeed11) in **AudioRenderer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback<[AudioRendererRate](#audiorendererrate8)> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the render rate obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRenderRate((err: BusinessError, renderRate: audio.AudioRendererRate) => {
  console.info(`getRenderRate: ${renderRate}`);
});

```

### getRenderRate<sup>8+(deprecated)</sup>

getRenderRate(): Promise\<AudioRendererRate>

Obtains the current render rate. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [getSpeed](#getspeed11) in **AudioRenderer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                              | Description                             |
| ------------------------------------------------- | --------------------------------------- |
| Promise<[AudioRendererRate](#audiorendererrate8)> | Promise used to return the render rate. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRenderRate().then((renderRate: audio.AudioRendererRate) => {
  console.info(`getRenderRate: ${renderRate}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### getRenderRateSync<sup>10+(deprecated)</sup>

getRenderRateSync(): AudioRendererRate

Obtains the current render rate. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getSpeed](#getspeed11) in **AudioRenderer**.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                     | Description        |
| ---------------------------------------- | ------------------ |
| [AudioRendererRate](#audiorendererrate8) | Audio render rate. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let renderRate: audio.AudioRendererRate = audioRenderer.getRenderRateSync();
  console.info(`getRenderRate: ${renderRate}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}

```

### getSpeed<sup>11+</sup>

getSpeed(): number

Obtains the playback speed.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description     |
| ------ | --------------- |
| number | Playback speed. |

**Example**

```ts
let speed = audioRenderer.getSpeed();

```

### setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode): Promise&lt;void&gt;

Sets the audio interruption mode for the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name | Type                             | Mandatory | Description              |
| ---- | -------------------------------- | --------- | ------------------------ |
| mode | [InterruptMode](#interruptmode9) | Yes       | Audio interruption mode. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mode = 0;
audioRenderer.setInterruptMode(mode).then(() => {
  console.info('setInterruptMode Success!');
}).catch((err: BusinessError) => {
  console.error(`setInterruptMode Fail: ${err}`);
});

```

### setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void

Sets the audio interruption mode for the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name     | Type                             | Mandatory | Description                                                  |
| -------- | -------------------------------- | --------- | ------------------------------------------------------------ |
| mode     | [InterruptMode](#interruptmode9) | Yes       | Audio interruption mode.                                     |
| callback | AsyncCallback\<void>             | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mode = 1;
audioRenderer.setInterruptMode(mode, (err: BusinessError) => {
  if(err){
    console.error(`setInterruptMode Fail: ${err}`);
  }
  console.info('setInterruptMode Success!');
});

```

### setInterruptModeSync<sup>10+</sup>

setInterruptModeSync(mode: InterruptMode): void

Sets the audio interruption mode for the application. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name | Type                             | Mandatory | Description              |
| ---- | -------------------------------- | --------- | ------------------------ |
| mode | [InterruptMode](#interruptmode9) | Yes       | Audio interruption mode. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  audioRenderer.setInterruptModeSync(0);
  console.info('setInterruptMode Success!');
} catch (err) {
  let error = err as BusinessError;
  console.error(`setInterruptMode Fail: ${error}`);
}

```

### setVolume<sup>9+</sup>

setVolume(volume: number): Promise&lt;void&gt;

Sets the volume for the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| ------ | ------ | --------- | ------------------------------------------------------------ |
| volume | number | Yes       | Volume to set, which can be within the range from 0.0 to 1.0. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5).then(() => {
  console.info('setVolume Success!');
}).catch((err: BusinessError) => {
  console.error(`setVolume Fail: ${err}`);
});

```

### setVolume<sup>9+</sup>

setVolume(volume: number, callback: AsyncCallback\<void>): void

Sets the volume for the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| -------- | -------------------- | --------- | ------------------------------------------------------------ |
| volume   | number               | Yes       | Volume to set, which can be within the range from 0.0 to 1.0. |
| callback | AsyncCallback\<void> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5, (err: BusinessError) => {
  if(err){
    console.error(`setVolume Fail: ${err}`);
    return;
  }
  console.info('setVolume Success!');
});

```

### getVolume<sup>12+</sup>

getVolume(): number

Obtains the volume of the audio render. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description                     |
| ------ | ------------------------------- |
| number | Volume, in the range [0.0-1.0]. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getVolume();
  console.info(`Indicate that the volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume, error ${error}.`);
}

```

### getMinStreamVolume<sup>10+</sup>

getMinStreamVolume(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum volume of the application from the perspective of an audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                        | Mandatory | Description                                                  |
| -------- | --------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum volume (range: 0-1) obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMinStreamVolume((err: BusinessError, minVolume: number) => {
  if (err) {
    console.error(`getMinStreamVolume error: ${err}`);
  } else {
    console.info(`getMinStreamVolume Success! ${minVolume}`);
  }
});

```

### getMinStreamVolume<sup>10+</sup>

getMinStreamVolume(): Promise&lt;number&gt;

Obtains the minimum volume of the application from the perspective of an audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the minimum volume, ranging from 0 to 1. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMinStreamVolume().then((value: number) => {
  console.info(`Get min stream volume Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get min stream volume Fail: ${err}`);
});

```

### getMinStreamVolumeSync<sup>10+</sup>

getMinStreamVolumeSync(): number

Obtains the minimum volume of the application from the perspective of an audio stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description                          |
| ------ | ------------------------------------ |
| number | Minimum volume, ranging from 0 to 1. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getMinStreamVolumeSync();
  console.info(`Get min stream volume Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get min stream volume Fail: ${error}`);
}

```

### getMaxStreamVolume<sup>10+</sup>

getMaxStreamVolume(callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum volume of the application from the perspective of an audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                        | Mandatory | Description                                                  |
| -------- | --------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the maximum volume (range: 0-1) obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMaxStreamVolume((err: BusinessError, maxVolume: number) => {
  if (err) {
    console.error(`getMaxStreamVolume Fail: ${err}`);
  } else {
    console.info(`getMaxStreamVolume Success! ${maxVolume}`);
  }
});

```

### getMaxStreamVolume<sup>10+</sup>

getMaxStreamVolume(): Promise&lt;number&gt;

Obtains the maximum volume of the application from the perspective of an audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the maximum volume, ranging from 0 to 1. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMaxStreamVolume().then((value: number) => {
  console.info(`Get max stream volume Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get max stream volume Fail: ${err}`);
});

```

### getMaxStreamVolumeSync<sup>10+</sup>

getMaxStreamVolumeSync(): number

Obtains the maximum volume of the application from the perspective of an audio stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description                          |
| ------ | ------------------------------------ |
| number | Maximum volume, ranging from 0 to 1. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getMaxStreamVolumeSync();
  console.info(`Get max stream volume Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get max stream volume Fail: ${error}`);
}

```

### getUnderflowCount<sup>10+</sup>

getUnderflowCount(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of underflow audio frames in the audio stream that is being played. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                        | Mandatory | Description                                                  |
| -------- | --------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of underloaded audio frames obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getUnderflowCount((err: BusinessError, underflowCount: number) => {
  if (err) {
    console.error(`getUnderflowCount Fail: ${err}`);
  } else {
    console.info(`getUnderflowCount Success! ${underflowCount}`);
  }
});

```

### getUnderflowCount<sup>10+</sup>

getUnderflowCount(): Promise&lt;number&gt;

Obtains the number of underflow audio frames in the audio stream that is being played. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                  | Description                                                  |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of underflow audio frames. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getUnderflowCount().then((value: number) => {
  console.info(`Get underflow count Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get underflow count Fail: ${err}`);
});

```

### getUnderflowCountSync<sup>10+</sup>

getUnderflowCountSync(): number

Obtains the number of underflow audio frames in the audio stream that is being played. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description                       |
| ------ | --------------------------------- |
| number | Number of underflow audio frames. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getUnderflowCountSync();
  console.info(`Get underflow count Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get underflow count Fail: ${error}`);
}

```

### getCurrentOutputDevices<sup>10+</sup>

getCurrentOutputDevices(callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the output device descriptors of the audio streams. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AudioDeviceDescriptors](#audiodevicedescriptors)> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the output device descriptors obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getCurrentOutputDevices((err: BusinessError, deviceInfo: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`getCurrentOutputDevices Fail: ${err}`);
  } else {
    for (let i = 0; i < deviceInfo.length; i++) {
      console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
      console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
      console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
      console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
      console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
      console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
      console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
      console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
    }
  }
});

```

### getCurrentOutputDevices<sup>10+</sup>

getCurrentOutputDevices(): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the output device descriptors of the audio streams. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                                                         | Description                                           |
| ------------------------------------------------------------ | ----------------------------------------------------- |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise used to return the output device descriptors. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getCurrentOutputDevices().then((deviceInfo: audio.AudioDeviceDescriptors) => {
  for (let i = 0; i < deviceInfo.length; i++) {
    console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
    console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
    console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
    console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
    console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
    console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
    console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
    console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Get current output devices Fail: ${err}`);
});

```

### getCurrentOutputDevicesSync<sup>10+</sup>

getCurrentOutputDevicesSync(): AudioDeviceDescriptors

Obtains the output device descriptors of the audio streams. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                                              | Description                |
| ------------------------------------------------- | -------------------------- |
| [AudioDeviceDescriptors](#audiodevicedescriptors) | Output device descriptors. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let deviceInfo: audio.AudioDeviceDescriptors = audioRenderer.getCurrentOutputDevicesSync();
  for (let i = 0; i < deviceInfo.length; i++) {
    console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
    console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
    console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
    console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
    console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
    console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
    console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
    console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get current output devices Fail: ${error}`);
}

```

### setChannelBlendMode<sup>11+</sup>

setChannelBlendMode(mode: ChannelBlendMode): void

Sets the audio channel blending mode. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type                                    | Mandatory | Description                  |
| ---- | --------------------------------------- | --------- | ---------------------------- |
| mode | [ChannelBlendMode](#channelblendmode11) | Yes       | Audio channel blending mode. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |
| 6800103 | Operation not permit at current state.                       |

**Example**

```ts
let mode = audio.ChannelBlendMode.MODE_DEFAULT;

audioRenderer.setChannelBlendMode(mode);
console.info(`BlendMode: ${mode}`);

```

### setVolumeWithRamp<sup>11+</sup>

setVolumeWithRamp(volume: number, duration: number): void

Sets a volume ramp. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type   | Mandatory | Description                                      |
| -------- | ------ | --------- | ------------------------------------------------ |
| volume   | number | Yes       | Target volume, within the range [0.0, 1.0].      |
| duration | number | Yes       | Time range during which the ramp applies, in ms. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
let volume = 0.5;
let duration = 1000;

audioRenderer.setVolumeWithRamp(volume, duration);
console.info(`setVolumeWithRamp: ${volume}`);

```

### setSilentModeAndMixWithOthers<sup>12+</sup>

setSilentModeAndMixWithOthers(on: boolean): void

Sets the silent mode in concurrent playback for the audio stream.

If the silent mode in concurrent playback is enabled, the system mutes the audio stream and does not interrupt other audio streams. If the silent mode in concurrent playback is disabled, the audio stream can gain focus based on the system focus policy.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type    | Mandatory | Description                                                  |
| ---- | ------- | --------- | ------------------------------------------------------------ |
| on   | boolean | Yes       | Whether to enable or disable the silent mode in concurrent playback for the audio stream. The value **true** means to enable the silent mode in concurrent playback, and **false** mans the opposite. |

**Example**

```ts
audioRenderer.setSilentModeAndMixWithOthers(true);

```

### getSilentModeAndMixWithOthers<sup>12+</sup>

getSilentModeAndMixWithOthers(): boolean

Obtains the silent mode in concurrent playback for the audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | **true**: The silent mode in concurrent playback is enabled.<br>**false**: The silent mode in concurrent playback is disabled. |

**Example**

```ts
let on = audioRenderer.getSilentModeAndMixWithOthers();

```

### setDefaultOutputDevice<sup>12+</sup>

setDefaultOutputDevice(deviceType: DeviceType): Promise&lt;void&gt;

Sets the default built-in audio output device. This API uses a promise to return the result.

This API applies only to the scenario where [StreamUsage](#streamusage) is set to voice messages, VoIP voice calls, and VoIP video calls and the available device types are the receiver, speaker, and system default device.

This API can be called at any time after an **AudioRenderer** instance is created. The system records the device set by the application. When the application is started, if an external device such as a Bluetooth or wired headset is connected, the system preferentially uses the external device to play sound. Otherwise, the system uses this default device to play sound.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name       | Type                      | Mandatory | Description                                                  |
| ---------- | ------------------------- | --------- | ------------------------------------------------------------ |
| deviceType | [DeviceType](#devicetype) | Yes       | Device type.<br>The options are **EARPIECE**, **SPEAKER**, and **DEFAULT**. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |
| 6800103 | Operation not permit at current state.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// This API can be called at any time after an **AudioRenderer** instance is created.
// If the API is called when no audio is being played, the system records the default device set by the application. When the application starts playing, the sound is played from this default device.
// If the API is called when audio is being played and no external device, such as a Bluetooth or wired headset, is connected, the system immediately switches to the default device. If an external device is connected, the system records the default device and switches to it once the external device is disconnected.
audioRenderer.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
  console.info('setDefaultOutputDevice Success!');
}).catch((err: BusinessError) => {
  console.error(`setDefaultOutputDevice Fail: ${err}`);
});

```

### on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void

Subscribes to audio interruption events. This API uses an asynchronous callback to return the result. Such an event is triggered when the audio focus is changed.

The **AudioRenderer** instance proactively gains the focus when the **start** event occurs and releases the focus when the **pause** or **stop** event occurs. Therefore, you do not need to request to gain or release the focus.

After this API is called, an [InterruptEvent](#interruptevent9) is received when the **AudioRenderer** object fails to obtain the focus or an audio interruption event occurs (for example, the audio stream is interrupted by others). It is recommended that the application perform further processing based on the **InterruptEvent** information. For details, see [Processing Audio Interruption Events](../../media/audio/audio-playback-concurrency.md).

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name     | Type                                           | Mandatory | Description                                                  |
| -------- | ---------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                         | Yes       | Event type. The value is fixed at **'audioInterrupt'**.      |
| callback | Callback\<[InterruptEvent](#interruptevent9)\> | Yes       | Callback used to return the audio interruption event received by the application when playback is interrupted. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let isPlaying: boolean; // An identifier specifying whether rendering is in progress.
let isDucked: boolean; // An identifier specifying whether the audio volume is reduced.
onAudioInterrupt();

async function onAudioInterrupt(){
  audioRenderer.on('audioInterrupt', (interruptEvent: audio.InterruptEvent) => {
    // When an audio interruption event occurs, the AudioRenderer receives the interruptEvent callback and performs processing based on the content in the callback.
    // 1. (Optional) The AudioRenderer reads the value of interruptEvent.forceType to see whether the system has forcibly performed the operation.
    // Note: In the default focus policy, INTERRUPT_HINT_RESUME maps to the force type INTERRUPT_SHARE, and others map to INTERRUPT_FORCE. Therefore, the value of forceType does not need to be checked.
    // 2. (Mandatory) The AudioRenderer then reads the value of interruptEvent.hintType and performs corresponding processing.
    if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
      // The audio focus event has been forcibly executed by the system. The application needs to update its status and displayed content.
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
          // The audio stream has been paused and temporarily loses the focus. It will receive the interruptEvent corresponding to resume when it is able to regain the focus.
          console.info('Force paused. Update playing status and stop writing');
          isPlaying = false; // A simplified processing indicating several operations for switching the application to the paused state.
          break;
        case audio.InterruptHint.INTERRUPT_HINT_STOP:
          // The audio stream has been stopped and permanently loses the focus. The user must manually trigger the operation to resume rendering.
          console.info('Force stopped. Update playing status and stop writing');
          isPlaying = false; // A simplified processing indicating several operations for switching the application to the paused state.
          break;
        case audio.InterruptHint.INTERRUPT_HINT_DUCK:
          // The audio stream is rendered at a reduced volume.
          console.info('Force ducked. Update volume status');
          isDucked = true; // A simplified processing indicating several operations for updating the volume status.
          break;
        case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
          // The audio stream is rendered at the normal volume.
          console.info('Force ducked. Update volume status');
          isDucked = false; // A simplified processing indicating several operations for updating the volume status.
          break;
        default:
          console.info('Invalid interruptEvent');
          break;
      }
    } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
      // The audio focus event needs to be operated by the application, which can choose the processing mode. It is recommended that the application process the event according to the value of InterruptHint.
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_RESUME:
          // It is recommended that the application continue rendering. (The audio stream has been forcibly paused and temporarily lost the focus. It can resume rendering now.)
          // The INTERRUPT_HINT_RESUME operation must be proactively executed by the application and cannot be forcibly executed by the system. Therefore, the INTERRUPT_HINT_RESUME event must map to INTERRUPT_SHARE.
          console.info('Resume force paused renderer or ignore');
          // To continue rendering, the application must perform the required operations.
          break;
        default:
          console.info('Invalid interruptEvent');
          break;
      }
    }
  });
}

```

### on('markReach')<sup>8+</sup>

on(type: 'markReach', frame: number, callback: Callback&lt;number&gt;): void

Subscribes to mark reached events. This API uses an asynchronous callback to return the result. Such an event is triggered (only once) when the number of frames rendered reaches the value of the **frame** parameter.

For example, if **frame** is set to **100**, the callback is invoked when the number of rendered frames reaches the 100th frame.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type              | Mandatory | Description                                                  |
| :------- | :---------------- | :-------- | :----------------------------------------------------------- |
| type     | string            | Yes       | Event type. The value is fixed at **'markReach'**.           |
| frame    | number            | Yes       | Number of frames to trigger the event. The value must be greater than **0**. |
| callback | Callback\<number> | Yes       | Callback used to return the value of the **frame** parameter. |

**Example**

```ts
audioRenderer.on('markReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});

```


### off('markReach')<sup>8+</sup>

off(type: 'markReach'): void

Unsubscribes from mark reached events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type   | Mandatory | Description                                        |
| :--- | :----- | :-------- | :------------------------------------------------- |
| type | string | Yes       | Event type. The value is fixed at **'markReach'**. |

**Example**

```ts
audioRenderer.off('markReach');

```

### on('periodReach')<sup>8+</sup>

on(type: 'periodReach', frame: number, callback: Callback&lt;number&gt;): void

Subscribes to period reached events. This API uses an asynchronous callback to return the result. Such an event is triggered each time the number of frames rendered reaches the value of the **frame** parameter. In other words, the information is reported periodically.

For example, if **frame** is set to **10**, the callback is invoked each time 10 frames are rendered, for example, when the number of frames rendered reaches the 10th frame, 20th frame, and 30th frame.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type              | Mandatory | Description                                                  |
| :------- | :---------------- | :-------- | :----------------------------------------------------------- |
| type     | string            | Yes       | Event type. The value is fixed at **'periodReach'**.         |
| frame    | number            | Yes       | Number of frames to trigger the event. The value must be greater than **0**. |
| callback | Callback\<number> | Yes       | Callback used to return the value of the **frame** parameter. |

**Example**

```ts
audioRenderer.on('periodReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});

```

### off('periodReach')<sup>8+</sup>

off(type: 'periodReach'): void

Unsubscribes from period reached events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type   | Mandatory | Description                                          |
| :--- | :----- | :-------- | :--------------------------------------------------- |
| type | string | Yes       | Event type. The value is fixed at **'periodReach'**. |

**Example**

```ts
audioRenderer.off('periodReach');

```

### on('stateChange')<sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

Subscribes to audio renderer state change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the state of the audio renderer is changed.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                  | Mandatory | Description                                          |
| :------- | :------------------------------------ | :-------- | :--------------------------------------------------- |
| type     | string                                | Yes       | Event type. The value is fixed at **'stateChange'**. |
| callback | Callback\<[AudioState](#audiostate8)> | Yes       | Callback used to return the audio status.            |

**Example**

```ts
audioRenderer.on('stateChange', (state: audio.AudioState) => {
  if (state == 1) {
    console.info('audio renderer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio renderer state is: STATE_RUNNING');
  }
});

```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void

Subscribes to audio output device change events. This API uses an asynchronous callback to return the result. Such an event is triggered when an audio output device is changed.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'outputDeviceChange'**.  |
| callback | Callback\<[AudioDeviceDescriptors](#audiodevicedescriptors)> | Yes       | Callback used to return the output device descriptor of the current audio stream. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRenderer.on('outputDeviceChange', (deviceInfo: audio.AudioDeviceDescriptors) => {
  console.info(`DeviceInfo id: ${deviceInfo[0].id}`);
  console.info(`DeviceInfo name: ${deviceInfo[0].name}`);
  console.info(`DeviceInfo address: ${deviceInfo[0].address}`);
});

```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void

Unsubscribes from audio output device change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'outputDeviceChange'**.  |
| callback | Callback\<[AudioDeviceDescriptors](#audiodevicedescriptors)> | No        | Callback used to return the output device descriptor of the current audio stream. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRenderer.off('outputDeviceChange', (deviceInfo: audio.AudioDeviceDescriptors) => {
  console.info(`DeviceInfo id: ${deviceInfo[0].id}`);
  console.info(`DeviceInfo name: ${deviceInfo[0].name}`);
  console.info(`DeviceInfo address: ${deviceInfo[0].address}`);
});

```

### on('outputDeviceChangeWithInfo')<sup>11+</sup>

on(type: 'outputDeviceChangeWithInfo', callback: Callback\<AudioStreamDeviceChangeInfo>): void

Subscribes to change events of audio output devices and reasons. This API uses an asynchronous callback to return the result. Such an event is triggered when an audio output device changes, and the change reason is reported.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'outputDeviceChangeWithInfo'**. |
| callback | Callback\<[AudioStreamDeviceChangeInfo](#audiostreamdevicechangeinfo11)> | Yes       | Callback used to return the output device descriptor of the current audio stream and the change reason. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRenderer.on('outputDeviceChangeWithInfo', (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`DeviceInfo id: ${deviceChangeInfo.devices[0].id}`);
  console.info(`DeviceInfo name: ${deviceChangeInfo.devices[0].name}`);
  console.info(`DeviceInfo address: ${deviceChangeInfo.devices[0].address}`);
  console.info(`Device change reason: ${deviceChangeInfo.changeReason}`);
});

```

### off('outputDeviceChangeWithInfo')<sup>11+</sup>

off(type: 'outputDeviceChangeWithInfo', callback?: Callback\<AudioStreamDeviceChangeInfo>): void

Unsubscribes from audio output device changes and reasons. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'outputDeviceChangeWithInfo'**. |
| callback | Callback\<[AudioStreamDeviceChangeInfo](#audiostreamdevicechangeinfo11)> | No        | Callback used to return the output device descriptor of the current audio stream and the change reason. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRenderer.off('outputDeviceChangeWithInfo', (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`DeviceInfo id: ${deviceChangeInfo.devices[0].id}`);
  console.info(`DeviceInfo name: ${deviceChangeInfo.devices[0].name}`);
  console.info(`DeviceInfo address: ${deviceChangeInfo.devices[0].address}`);
  console.info(`Device change reason: ${deviceChangeInfo.changeReason}`);
});

```

### on('writeData')<sup>11+</sup>

on(type: 'writeData', callback: AudioRendererWriteDataCallback): void

Subscribes to audio data write events. This API uses an asynchronous callback to return the result. Such an event is triggered when audio data needs to be written.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'writeData'**.           |
| callback | [AudioRendererWriteDataCallback](#audiorendererwritedatacallback12) | Yes       | Callback used to write the data to the buffer.<br>API version 11 does not support the return of the callback result. API version 12 and later support the return of the callback result [AudioDataCallbackResult](#audiodatacallbackresult12). |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import {fileIo} from '@kit.CoreFileKit';

class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
let path = getContext().cacheDir;
// Ensure that the resource exists in the path.
let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
let file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);
let writeDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  };

  try {
    fileIo.readSync(file.fd, buffer, options);
    bufferSize += buffer.byteLength;
    // API version 11 does not support the return of the callback result. API version 12 and later support the return of the callback result.
    return audio.AudioDataCallbackResult.VALID;
  } catch (error) {
    console.error('Error reading file:', error);
    // API version 11 does not support the return of the callback result. API version 12 and later support the return of the callback result.
    return audio.AudioDataCallbackResult.INVALID;
  }
};

audioRenderer.on('writeData', writeDataCallback);
audioRenderer.start().then(() => {
  console.info('Renderer started');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### off('writeData')<sup>11+</sup>

off(type: 'writeData', callback?: AudioRendererWriteDataCallback): void

Unsubscribes from audio data write events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'writeData'**.           |
| callback | [AudioRendererWriteDataCallback](#audiorendererwritedatacallback12) | No        | Callback used to write the data to the buffer.<br>API version 11 does not support the return of the callback result. API version 12 and later support the return of the callback result [AudioDataCallbackResult](#audiodatacallbackresult12). |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioRenderer.off('writeData', (data: ArrayBuffer) => {
    console.info(`write data: ${data}`);
});

```

## AudioCapturer<sup>8+</sup>

Provides APIs for audio capture. Before calling any API in **AudioCapturer**, you must use [createAudioCapturer](#audiocreateaudiocapturer8) to create an **AudioCapturer** instance.

### Attributes

**System capability**: SystemCapability.Multimedia.Audio.Capturer

| Name               | Type                       | Readable | Writable | Description           |
| :----------------- | :------------------------- | :------- | :------- | :-------------------- |
| state<sup>8+</sup> | [AudioState](#audiostate8) | Yes      | No       | Audio capturer state. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let state: audio.AudioState = audioCapturer.state;

```

### getCapturerInfo<sup>8+</sup>

getCapturerInfo(callback: AsyncCallback<AudioCapturerInfo\>): void

Obtains the capturer information of this **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                                                     | Mandatory | Description                                                  |
| :------- | :------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<[AudioCapturerInfo](#audiocapturerinfo8)\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the capturer information obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getCapturerInfo((err: BusinessError, capturerInfo: audio.AudioCapturerInfo) => {
  if (err) {
    console.error('Failed to get capture info');
  } else {
    console.info('Capturer getCapturerInfo:');
    console.info(`Capturer source: ${capturerInfo.source}`);
    console.info(`Capturer flags: ${capturerInfo.capturerFlags}`);
  }
});

```


### getCapturerInfo<sup>8+</sup>

getCapturerInfo(): Promise<AudioCapturerInfo\>

Obtains the capturer information of this **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                               | Description                                  |
| :------------------------------------------------- | :------------------------------------------- |
| Promise<[AudioCapturerInfo](#audiocapturerinfo8)\> | Promise used to return capturer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getCapturerInfo().then((audioParamsGet: audio.AudioCapturerInfo) => {
  if (audioParamsGet != undefined) {
    console.info('AudioFrameworkRecLog: Capturer CapturerInfo:');
    console.info(`AudioFrameworkRecLog: Capturer SourceType: ${audioParamsGet.source}`);
    console.info(`AudioFrameworkRecLog: Capturer capturerFlags: ${audioParamsGet.capturerFlags}`);
  } else {
    console.info(`AudioFrameworkRecLog: audioParamsGet is : ${audioParamsGet}`);
    console.info('AudioFrameworkRecLog: audioParams getCapturerInfo are incorrect');
  }
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: CapturerInfo :ERROR: ${err}`);
})

```

### getCapturerInfoSync<sup>10+</sup>

getCapturerInfoSync(): AudioCapturerInfo

Obtains the capturer information of this **AudioCapturer** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                     | Description           |
| :--------------------------------------- | :-------------------- |
| [AudioCapturerInfo](#audiocapturerinfo8) | Capturer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioParamsGet: audio.AudioCapturerInfo = audioCapturer.getCapturerInfoSync();
  console.info(`AudioFrameworkRecLog: Capturer SourceType: ${audioParamsGet.source}`);
  console.info(`AudioFrameworkRecLog: Capturer capturerFlags: ${audioParamsGet.capturerFlags}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRecLog: CapturerInfo :ERROR: ${error}`);
}

```

### getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

Obtains the stream information of this **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                                                 | Mandatory | Description                                                  |
| :------- | :--------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream information obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getStreamInfo((err: BusinessError, streamInfo: audio.AudioStreamInfo) => {
  if (err) {
    console.error('Failed to get stream info');
  } else {
    console.info('Capturer GetStreamInfo:');
    console.info(`Capturer sampling rate: ${streamInfo.samplingRate}`);
    console.info(`Capturer channel: ${streamInfo.channels}`);
    console.info(`Capturer format: ${streamInfo.sampleFormat}`);
    console.info(`Capturer encoding type: ${streamInfo.encodingType}`);
  }
});

```

### getStreamInfo<sup>8+</sup>

getStreamInfo(): Promise<AudioStreamInfo\>

Obtains the stream information of this **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                           | Description                                    |
| :--------------------------------------------- | :--------------------------------------------- |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | Promise used to return the stream information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getStreamInfo().then((audioParamsGet: audio.AudioStreamInfo) => {
  console.info('getStreamInfo:');
  console.info(`sampleFormat: ${audioParamsGet.sampleFormat}`);
  console.info(`samplingRate: ${audioParamsGet.samplingRate}`);
  console.info(`channels: ${audioParamsGet.channels}`);
  console.info(`encodingType: ${audioParamsGet.encodingType}`);
}).catch((err: BusinessError) => {
  console.error(`getStreamInfo :ERROR: ${err}`);
});

```

### getStreamInfoSync<sup>10+</sup>

getStreamInfoSync(): AudioStreamInfo

Obtains the stream information of this **AudioCapturer** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                 | Description         |
| :----------------------------------- | :------------------ |
| [AudioStreamInfo](#audiostreaminfo8) | Stream information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioParamsGet: audio.AudioStreamInfo = audioCapturer.getStreamInfoSync();
  console.info(`sampleFormat: ${audioParamsGet.sampleFormat}`);
  console.info(`samplingRate: ${audioParamsGet.samplingRate}`);
  console.info(`channels: ${audioParamsGet.channels}`);
  console.info(`encodingType: ${audioParamsGet.encodingType}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getStreamInfo :ERROR: ${error}`);
}

```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(callback: AsyncCallback<number\>): void

Obtains the stream ID of this **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| :------- | :--------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<number\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream ID obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getAudioStreamId((err: BusinessError, streamId: number) => {
  console.info(`audioCapturer GetStreamId: ${streamId}`);
});

```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(): Promise<number\>

Obtains the stream ID of this **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type             | Description                           |
| :--------------- | :------------------------------------ |
| Promise<number\> | Promise used to return the stream ID. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getAudioStreamId().then((streamId: number) => {
  console.info(`audioCapturer getAudioStreamId: ${streamId}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});

```

### getAudioStreamIdSync<sup>10+</sup>

getAudioStreamIdSync(): number

Obtains the stream ID of this **AudioCapturer** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type   | Description |
| :----- | :---------- |
| number | Stream ID.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let streamId: number = audioCapturer.getAudioStreamIdSync();
  console.info(`audioCapturer getAudioStreamIdSync: ${streamId}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}

```

### start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

Starts capturing. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| :------- | :------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result. If the operation fails, an error object with the following error code is returned:<br>Error code 6800301: indicates abnormal status, focus preemption failure, and abnormal system processing. For details, see system logs. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.start((err: BusinessError) => {
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

| Type           | Description                                                  |
| :------------- | :----------------------------------------------------------- |
| Promise<void\> | Promise used to return the result. If the operation fails, an error object with the following error code is returned:<br>Error code 6800301: indicates abnormal status, focus preemption failure, and abnormal system processing. For details, see system logs. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.start().then(() => {
  console.info('AudioFrameworkRecLog: ---------START---------');
  console.info('AudioFrameworkRecLog: Capturer started: SUCCESS');
  console.info(`AudioFrameworkRecLog: AudioCapturer: STATE: ${audioCapturer.state}`);
  console.info('AudioFrameworkRecLog: Capturer started: SUCCESS');
  if ((audioCapturer.state == audio.AudioState.STATE_RUNNING)) {
    console.info('AudioFrameworkRecLog: AudioCapturer is in Running State');
  }
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: Capturer start :ERROR : ${err}`);
});

```

### stop<sup>8+</sup>

stop(callback: AsyncCallback<void\>): void

Stops capturing. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| :------- | :------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result. If the vibration stops, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.stop((err: BusinessError) => {
  if (err) {
    console.error('Capturer stop failed');
  } else {
    console.info('Capturer stopped.');
  }
});

```


### stop<sup>8+</sup>

stop(): Promise<void\>

Stops capturing. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type           | Description                    |
| :------------- | :----------------------------- |
| Promise<void\> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.stop().then(() => {
  console.info('AudioFrameworkRecLog: ---------STOP RECORD---------');
  console.info('AudioFrameworkRecLog: Capturer stopped: SUCCESS');
  if ((audioCapturer.state == audio.AudioState.STATE_STOPPED)){
    console.info('AudioFrameworkRecLog: State is Stopped:');
  }
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: Capturer stop: ERROR: ${err}`);
});

```

### release<sup>8+</sup>

release(callback: AsyncCallback<void\>): void

Releases this **AudioCapturer** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                 | Mandatory | Description                                                  |
| :------- | :------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.release((err: BusinessError) => {
  if (err) {
    console.error('capturer release failed');
  } else {
    console.info('capturer released.');
  }
});

```


### release<sup>8+</sup>

release(): Promise<void\>

Releases this **AudioCapturer** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type           | Description                    |
| :------------- | :----------------------------- |
| Promise<void\> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.release().then(() => {
  console.info('AudioFrameworkRecLog: ---------RELEASE RECORD---------');
  console.info('AudioFrameworkRecLog: Capturer release : SUCCESS');
  console.info(`AudioFrameworkRecLog: AudioCapturer : STATE : ${audioCapturer.state}`);
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: Capturer stop: ERROR: ${err}`);
});

```

### read<sup>8+(deprecated)</sup>

read(size: number, isBlockingRead: boolean, callback: AsyncCallback<ArrayBuffer\>): void

Reads the buffer. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [on('readData')](#onreaddata11) in **AudioCapturer**.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name           | Type                        | Mandatory | Description                                                  |
| :------------- | :-------------------------- | :-------- | :----------------------------------------------------------- |
| size           | number                      | Yes       | Number of bytes to read.                                     |
| isBlockingRead | boolean                     | Yes       | Whether to block the read operation. The value **true** means to block the read operation, and **false** means the opposite. |
| callback       | AsyncCallback<ArrayBuffer\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the buffer read; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number = 0;
audioCapturer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRecLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: getBufferSize: ERROR: ${err}`);
});
audioCapturer.read(bufferSize, true, (err: BusinessError, buffer: ArrayBuffer) => {
  if (!err) {
    console.info('Success in reading the buffer data');
  }
});

```

### read<sup>8+(deprecated)</sup>

read(size: number, isBlockingRead: boolean): Promise<ArrayBuffer\>

Reads the buffer. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [on('readData')](#onreaddata11) in **AudioCapturer**.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name           | Type    | Mandatory | Description                                                  |
| :------------- | :------ | :-------- | :----------------------------------------------------------- |
| size           | number  | Yes       | Number of bytes to read.                                     |
| isBlockingRead | boolean | Yes       | Whether to block the read operation. The value **true** means to block the read operation, and **false** means the opposite. |

**Return value**

| Type                  | Description                                           |
| :-------------------- | :---------------------------------------------------- |
| Promise<ArrayBuffer\> | Promise used to return the data read from the buffer. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number = 0;
audioCapturer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRecLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: getBufferSize: ERROR ${err}`);
});
console.info(`Buffer size: ${bufferSize}`);
audioCapturer.read(bufferSize, true).then((buffer: ArrayBuffer) => {
  console.info('buffer read successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR : ${err}`);
});

```

### getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback<number\>): void

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| :------- | :--------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<number\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of nanoseconds obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getAudioTime((err: BusinessError, timestamp: number) => {
  console.info(`Current timestamp: ${timestamp}`);
});

```

### getAudioTime<sup>8+</sup>

getAudioTime(): Promise<number\>

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type             | Description                                                  |
| :--------------- | :----------------------------------------------------------- |
| Promise<number\> | Promise used to return the number of nanoseconds elapsed from the Unix epoch. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getAudioTime().then((audioTime: number) => {
  console.info(`AudioFrameworkRecLog: AudioCapturer getAudioTime : Success ${audioTime}`);
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: AudioCapturer Created : ERROR : ${err}`);
});

```

### getAudioTimeSync<sup>10+</sup>

getAudioTimeSync(): number

Obtains the number of nanoseconds elapsed from the Unix epoch (January 1, 1970). This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type   | Description |
| :----- | :---------- |
| number | Timestamp.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioTime: number = audioCapturer.getAudioTimeSync();
  console.info(`AudioFrameworkRecLog: AudioCapturer getAudioTimeSync : Success ${audioTime}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRecLog: AudioCapturer getAudioTimeSync : ERROR : ${error}`);
}

```

### getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback<number\>): void

Obtains a reasonable minimum buffer size in bytes for capturing. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| :------- | :--------------------- | :-------- | :----------------------------------------------------------- |
| callback | AsyncCallback<number\> | Yes       | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum buffer size obtained; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getBufferSize((err: BusinessError, bufferSize: number) => {
  if (!err) {
    console.info(`BufferSize : ${bufferSize}`);
    audioCapturer.read(bufferSize, true).then((buffer: ArrayBuffer) => {
      console.info(`Buffer read is ${buffer.byteLength}`);
    }).catch((err: BusinessError) => {
      console.error(`AudioFrameworkRecLog: AudioCapturer Created : ERROR : ${err}`);
    });
  }
});

```

### getBufferSize<sup>8+</sup>

getBufferSize(): Promise<number\>

Obtains a reasonable minimum buffer size in bytes for capturing. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type             | Description                             |
| :--------------- | :-------------------------------------- |
| Promise<number\> | Promise used to return the buffer size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number = 0;
audioCapturer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRecLog: getBufferSize :SUCCESS ${data}`);
  bufferSize = data;
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRecLog: getBufferSize :ERROR : ${err}`);
});

```

### getBufferSizeSync<sup>10+</sup>

getBufferSizeSync(): number

Obtains a reasonable minimum buffer size in bytes for capturing. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type   | Description  |
| :----- | :----------- |
| number | Buffer size. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number = 0;
try {
  bufferSize = audioCapturer.getBufferSizeSync();
  console.info(`AudioFrameworkRecLog: getBufferSizeSync :SUCCESS ${bufferSize}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRecLog: getBufferSizeSync :ERROR : ${error}`);
}

```

### getCurrentInputDevices<sup>11+</sup>

getCurrentInputDevices(): AudioDeviceDescriptors

Obtains the descriptors of the current input devices. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                                              | Description                               |
| ------------------------------------------------- | ----------------------------------------- |
| [AudioDeviceDescriptors](#audiodevicedescriptors) | An array of the audio device descriptors. |

**Example**

```ts
let deviceDescriptors: audio.AudioDeviceDescriptors = audioCapturer.getCurrentInputDevices();
console.info(`Device id: ${deviceDescriptors[0].id}`);
console.info(`Device type: ${deviceDescriptors[0].deviceType}`);
console.info(`Device role: ${deviceDescriptors[0].deviceRole}`);
console.info(`Device name: ${deviceDescriptors[0].name}`);
console.info(`Device address: ${deviceDescriptors[0].address}`);
console.info(`Device samplerates: ${deviceDescriptors[0].sampleRates[0]}`);
console.info(`Device channelcounts: ${deviceDescriptors[0].channelCounts[0]}`);
console.info(`Device channelmask: ${deviceDescriptors[0].channelMasks[0]}`);
if (deviceDescriptors[0].encodingTypes) {
  console.info(`Device encodingTypes: ${deviceDescriptors[0].encodingTypes[0]}`);
}

```

### getCurrentAudioCapturerChangeInfo<sup>11+</sup>

getCurrentAudioCapturerChangeInfo(): AudioCapturerChangeInfo

Obtains the configuration changes of the current audio capturer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type                                                 | Description                                  |
| :--------------------------------------------------- | :------------------------------------------- |
| [AudioCapturerChangeInfo](#audiocapturerchangeinfo9) | Configuration changes of the audio capturer. |

**Example**

```ts
let info: audio.AudioCapturerChangeInfo = audioCapturer.getCurrentAudioCapturerChangeInfo();
console.info(`Info streamId: ${info.streamId}`);
console.info(`Info source: ${info.capturerInfo.source}`);
console.info(`Info capturerFlags: ${info.capturerInfo.capturerFlags}`);
console.info(`Info muted: ${info.muted}`);
console.info(`Info type: ${info.deviceDescriptors[0].deviceType}`);
console.info(`Info role: ${info.deviceDescriptors[0].deviceRole}`);
console.info(`Info name: ${info.deviceDescriptors[0].name}`);
console.info(`Info address: ${info.deviceDescriptors[0].address}`);
console.info(`Info samplerates: ${info.deviceDescriptors[0].sampleRates[0]}`);
console.info(`Info channelcounts: ${info.deviceDescriptors[0].channelCounts[0]}`);
console.info(`Info channelmask: ${info.deviceDescriptors[0].channelMasks[0]}`);
if (info.deviceDescriptors[0].encodingTypes) {
  console.info(`Device encodingTypes: ${info.deviceDescriptors[0].encodingTypes[0]}`);
}

```

### on('audioInterrupt')<sup>10+</sup>

on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void

Subscribes to audio interruption events. This API uses an asynchronous callback to return the result. Such an event is triggered when the audio focus is changed.

The **AudioCapturer** instance proactively gains the focus when the **start** event occurs and releases the focus when the **pause** or **stop** event occurs. Therefore, you do not need to request to gain or release the focus.

After this API is called, an [InterruptEvent](#interruptevent9) is received when the **AudioCapturer** object fails to obtain the focus or an audio interruption event occurs (for example, the audio stream is interrupted by others). It is recommended that the application perform further processing based on the **InterruptEvent** information. For details, see [Processing Audio Interruption Events](../../media/audio/audio-playback-concurrency.md).

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name     | Type                                           | Mandatory | Description                                                  |
| -------- | ---------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                         | Yes       | Event type. The value is fixed at **'audioInterrupt'**.      |
| callback | Callback\<[InterruptEvent](#interruptevent9)\> | Yes       | Callback used to return the audio interruption event received by the application when playback is interrupted. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let isCapturing: boolean; // An identifier specifying whether capturing is in progress.
onAudioInterrupt();

async function onAudioInterrupt(){
  audioCapturer.on('audioInterrupt', (interruptEvent: audio.InterruptEvent) => {
    // When an audio interruption event occurs, the AudioCapturer receives the interruptEvent callback and performs processing based on the content in the callback.
    // 1. (Optional) The AudioCapturer reads the value of interruptEvent.forceType to see whether the system has forcibly performed the operation.
    // Note: In the default focus policy, INTERRUPT_HINT_RESUME maps to the force type INTERRUPT_SHARE, and others map to INTERRUPT_FORCE. Therefore, the value of forceType does not need to be checked.
    // 2. (Mandatory) The AudioCapturer then reads the value of interruptEvent.hintType and performs corresponding processing.
    if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
      // The audio focus event has been forcibly executed by the system. The application needs to update its status and displayed content.
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
          // The audio stream has been paused and temporarily loses the focus. It will receive the interruptEvent corresponding to resume when it is able to regain the focus.
          console.info('Force paused. Update capturing status and stop reading');
          isCapturing = false; // A simplified processing indicating several operations for switching the application to the paused state.
          break;
        case audio.InterruptHint.INTERRUPT_HINT_STOP:
          // The audio stream has been stopped and permanently loses the focus. The user must manually trigger the operation to resume capturing.
          console.info('Force stopped. Update capturing status and stop reading');
          isCapturing = false; // A simplified processing indicating several operations for switching the application to the paused state.
          break;
        default:
          console.info('Invalid interruptEvent');
          break;
      }
    } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
      // The audio focus event needs to be operated by the application, which can choose the processing mode. It is recommended that the application process the event according to the value of InterruptHint.
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_RESUME:
          // It is recommended that the application continue capturing. (The audio stream has been forcibly paused and temporarily lost the focus. It can resume capturing now.)
          // The INTERRUPT_HINT_RESUME operation must be proactively executed by the application and cannot be forcibly executed by the system. Therefore, the INTERRUPT_HINT_RESUME event must map to INTERRUPT_SHARE.
          console.info('Resume force paused renderer or ignore');
          // To continue capturing, the application must perform the required operations.
          break;
        default:
          console.info('Invalid interruptEvent');
          break;
      }
    }
  });
}

```

### off('audioInterrupt')<sup>10+</sup>

off(type: 'audioInterrupt'): void

Unsubscribes from audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name | Type   | Mandatory | Description                                             |
| ---- | ------ | --------- | ------------------------------------------------------- |
| type | string | Yes       | Event type. The value is fixed at **'audioInterrupt'**. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioCapturer.off('audioInterrupt');

```

### on('inputDeviceChange')<sup>11+</sup>

on(type: 'inputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void

Subscribes to audio input device change events. This API uses an asynchronous callback to return the result. Such an event is triggered when an audio input device is changed.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'inputDeviceChange**.    |
| callback | Callback\<[AudioDeviceDescriptors](#audiodevicedescriptors)> | Yes       | Callback used to return the information about the new audio input device. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioCapturer.on('inputDeviceChange', (deviceChangeInfo: audio.AudioDeviceDescriptors) => {
  console.info(`inputDevice id: ${deviceChangeInfo[0].id}`);
  console.info(`inputDevice deviceRole: ${deviceChangeInfo[0].deviceRole}`);
  console.info(`inputDevice deviceType: ${deviceChangeInfo[0].deviceType}`);
});

```

### off('inputDeviceChange')<sup>11+</sup>

off(type: 'inputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void

Unsubscribes from audio input device change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'inputDeviceChange'**.   |
| callback | Callback\<[AudioDeviceDescriptors](#audiodevicedescriptors)> | No        | Callback used to return the information about the audio input device. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioCapturer.off('inputDeviceChange');

```

### on('audioCapturerChange')<sup>11+</sup>

on(type: 'audioCapturerChange', callback: Callback\<AudioCapturerChangeInfo>): void

Subscribes to audio capturer configuration change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the audio recording stream status or device is changed. The subscription is implemented asynchronously and the callback, which is triggered when the audio capturer configuration changes, may fail to reflect the actual condition.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'audioCapturerChange'**. |
| callback | Callback\<[AudioCapturerChangeInfo](#audiocapturerchangeinfo9)> | Yes       | Callback used to return the current configuration and status information of the audio capturer. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioCapturer.on('audioCapturerChange', (capturerChangeInfo: audio.AudioCapturerChangeInfo) => {
  console.info(`audioCapturerChange id: ${capturerChangeInfo[0].id}`);
  console.info(`audioCapturerChange deviceRole: ${capturerChangeInfo[0].deviceRole}`);
  console.info(`audioCapturerChange deviceType: ${capturerChangeInfo[0].deviceType}`);
});

```

### off('audioCapturerChange')<sup>11+</sup>

off(type: 'audioCapturerChange', callback?: Callback\<AudioCapturerChangeInfo>): void

Unsubscribes from audio capturer configuration change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| :------- | :----------------------------------------------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'audioCapturerChange'**. |
| callback | Callback\<[AudioCapturerChangeInfo](#audiocapturerchangeinfo9)> | No        | Callback used for unsubscription.                            |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioCapturer.off('audioCapturerChange');

```

### on('markReach')<sup>8+</sup>

on(type: 'markReach', frame: number, callback: Callback&lt;number&gt;): void

Subscribes to mark reached events. This API uses an asynchronous callback to return the result. Such an event is triggered (only once) when the number of frames captured reaches the value of the **frame** parameter. 

For example, if **frame** is set to **100**, the callback is invoked when the number of captured frames reaches the 100th frame.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type              | Mandatory | Description                                                  |
| :------- | :---------------- | :-------- | :----------------------------------------------------------- |
| type     | string            | Yes       | Event type. The value is fixed at **'markReach'**.           |
| frame    | number            | Yes       | Number of frames to trigger the event. The value must be greater than **0**. |
| callback | Callback\<number> | Yes       | Callback used to return the value of the **frame** parameter. |

**Example**

```ts
audioCapturer.on('markReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});

```

### off('markReach')<sup>8+</sup>

off(type: 'markReach'): void

Unsubscribes from mark reached events.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type   | Mandatory | Description                                        |
| :--- | :----- | :-------- | :------------------------------------------------- |
| type | string | Yes       | Event type. The value is fixed at **'markReach'**. |

**Example**

```ts
audioCapturer.off('markReach');

```

### on('periodReach')<sup>8+</sup>

on(type: 'periodReach', frame: number, callback: Callback&lt;number&gt;): void

Subscribes to period reached events. This API uses an asynchronous callback to return the result. Such an event is triggered each time the number of frames captured reaches the value of the **frame** parameter. In other words, the information is reported periodically.

For example, if **frame** is set to **10**, the callback is invoked each time 10 frames are captured, for example, when the number of frames rendered reaches the 10th frame, 20th frame, and 30th frame.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type              | Mandatory | Description                                                  |
| :------- | :---------------- | :-------- | :----------------------------------------------------------- |
| type     | string            | Yes       | Event type. The value is fixed at **'periodReach'**.         |
| frame    | number            | Yes       | Number of frames to trigger the event. The value must be greater than **0**. |
| callback | Callback\<number> | Yes       | Callback used to return the value of the **frame** parameter. |

**Example**

```ts
audioCapturer.on('periodReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});

```

### off('periodReach')<sup>8+</sup>

off(type: 'periodReach'): void

Unsubscribes from period reached events.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name | Type   | Mandatory | Description                                          |
| :--- | :----- | :-------- | :--------------------------------------------------- |
| type | string | Yes       | Event type. The value is fixed at **'periodReach'**. |

**Example**

```ts
audioCapturer.off('periodReach');

```

### on('stateChange')<sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

Subscribes to audio capturer state change events. This API uses an asynchronous callback to return the result. Such an event is triggered when the state of the audio capturer is changed.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                                  | Mandatory | Description                                          |
| :------- | :------------------------------------ | :-------- | :--------------------------------------------------- |
| type     | string                                | Yes       | Event type. The value is fixed at **'stateChange'**. |
| callback | Callback\<[AudioState](#audiostate8)> | Yes       | Callback used to return the audio status.            |

**Example**

```ts
audioCapturer.on('stateChange', (state: audio.AudioState) => {
  if (state == 1) {
    console.info('audio capturer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio capturer state is: STATE_RUNNING');
  }
});

```

### on('readData')<sup>11+</sup>

on(type: 'readData', callback: Callback\<ArrayBuffer>): void

Subscribes to audio data read events. This API uses an asynchronous callback to return the result. Such an event is triggered when audio stream data needs to be read.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| :------- | :--------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                 | Yes       | Event type. The value is fixed at **'readData'**.            |
| callback | Callback\<ArrayBuffer> | Yes       | Callback used to return the buffer from which the data is read. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
let path = getContext().cacheDir;
// Ensure that the resource exists in the sandbox path.
let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
let file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
let readDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  }
  fileIo.writeSync(file.fd, buffer, options);
  bufferSize += buffer.byteLength;
}
audioCapturer.on('readData', readDataCallback);
audioCapturer.start((err: BusinessError) => {
  if (err) {
    console.error('Capturer start failed.');
  } else {
    console.info('Capturer start success.');
  }
});

```

### off('readData')<sup>11+</sup>

off(type: 'readData', callback?: Callback\<ArrayBuffer>): void

Unsubscribes from audio data read events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name     | Type                   | Mandatory | Description                                                  |
| :------- | :--------------------- | :-------- | :----------------------------------------------------------- |
| type     | string                 | Yes       | Event type. The value is fixed at **'readData'**.            |
| callback | Callback\<ArrayBuffer> | No        | Callback used to return the buffer from which the data is read. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.                               |

**Example**

```ts
audioCapturer.off('readData', (data: ArrayBuffer) => {
    console.info(`read data: ${data}`);
});

```

### getOverflowCount<sup>12+</sup>

getOverflowCount(): Promise&lt;number&gt;

Obtains the number of overflow audio frames in the audio stream that is being captured. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                  | Description                                                 |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of overflow audio frames. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioCapturer.getOverflowCount().then((value: number) => {
  console.info(`Get overflow count Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get overflow count Fail: ${err}`);
});

```

### getOverflowCountSync<sup>12+</sup>

getOverflowCountSync(): number

Obtains the number of overflow audio frames in the audio stream that is being captured. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type   | Description                      |
| ------ | -------------------------------- |
| number | Number of overflow audio frames. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioCapturer.getOverflowCountSync();
  console.info(`Get overflow count Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get overflow count Fail: ${error}`);
}

```

## ActiveDeviceType<sup>(deprecated)</sup>

Enumerates the active device types.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [CommunicationDeviceType](#communicationdevicetype9) instead.

**System capability**: SystemCapability.Multimedia.Audio.Device

| Name          | Value | Description                                                  |
| ------------- | ----- | ------------------------------------------------------------ |
| SPEAKER       | 2     | Speaker.                                                     |
| BLUETOOTH_SCO | 7     | Bluetooth device using Synchronous Connection Oriented (SCO) links. |

## InterruptActionType<sup>(deprecated)</sup>

Enumerates the returned event types for audio interruption events.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. No substitute enum is provided. It is used together with the audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name           | Value | Description               |
| -------------- | ----- | ------------------------- |
| TYPE_ACTIVATED | 0     | Focus gain event.         |
| TYPE_INTERRUPT | 1     | Audio interruption event. |

## AudioInterrupt<sup>(deprecated)</sup>

Describes input parameters of audio interruption events.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. No substitute enum is provided. It is used together with the audio interruption events.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name            | Type                                  | Mandatory | Description                                                  |
| --------------- | ------------------------------------- | --------- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](#streamusage)           | Yes       | Audio stream usage.                                          |
| contentType     | [ContentType](#contenttypedeprecated) | Yes       | Audio content type.                                          |
| pauseWhenDucked | boolean                               | Yes       | Whether audio playback can be paused during audio interruption. The value **true** means that audio playback can be paused during audio interruption, and **false** means the opposite. |

## InterruptAction<sup>(deprecated)</sup>

Describes the callback invoked for audio interruption or focus gain events.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [InterruptEvent](#interruptevent9).

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name       | Type                                                  | Mandatory | Description                                                  |
| ---------- | ----------------------------------------------------- | --------- | ------------------------------------------------------------ |
| actionType | [InterruptActionType](#interruptactiontypedeprecated) | Yes       | Returned event type. The value **TYPE_ACTIVATED** means the focus gain event, and **TYPE_INTERRUPT** means the audio interruption event. |
| type       | [InterruptType](#interrupttype)                       | No        | Type of the audio interruption event.                        |
| hint       | [InterruptHint](#interrupthint)                       | No        | Hint provided along with the audio interruption event.       |
| activated  | boolean                                               | No        | Whether the focus is gained or released. The value **true** means that the focus is gained or released, and **false** means that the focus fails to be gained or released. |