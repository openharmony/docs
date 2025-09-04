# @ohos.bluetooth.a2dp (Bluetooth A2DP Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->

The **a2dp** module provides Bluetooth media audio capabilities based on the Advanced Audio Distribution Profile (A2DP), and supports functions such as obtaining the media playback status and connection status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import { a2dp } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

**BaseProfile** class, which provides public capabilities such as obtaining the connection status and listening for connection status changes.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md)| **BaseProfile** API definition.|


## a2dp.createA2dpSrcProfile

createA2dpSrcProfile(): A2dpSourceProfile

Creates an **A2dpSourceProfile** instance. Through this instance, you can use the local device as the audio source device and implement functions such as obtaining the Bluetooth media audio playback status of the local device.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [A2dpSourceProfile](#a2dpsourceprofile) | **A2dpSourceProfile** instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                         |
|801 | Capability not supported.                |


**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let a2dpProfile = a2dp.createA2dpSrcProfile();
    console.info('a2dp success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## A2dpSourceProfile

**A2dpSourceProfile** class, which provides the API to create an audio source device.
- This class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class.
- Before using the APIs of this class, you need to call [createA2dpSrcProfile](#a2dpcreatea2dpsrcprofile) to construct an **A2dpSourceProfile** instance.
- An instance of this class functions as the audio receiver (A2DP sink), that is, the device that receives audio data. Typical devices include earphones and speakers.

### getPlayingState

getPlayingState(deviceId: string): PlayingState

Obtains the media audio playback status between the local and peer devices.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [PlayingState](#playingstate) | Bluetooth media audio playback status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let state = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## PlayingState

Enumerates the Bluetooth media audio playback status.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0 | Media audio is not played. |
| STATE_PLAYING     | 1 | Media audio is being played.|


## CodecInfo<sup>11+</sup>

Defines the codec used by the Bluetooth media audio.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name       | Type                   | Read-Only  | Optional  | Description                                    |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType           | [CodecType](#codectype11)      | No   | No   | Codec type. The default value is **CODEC_TYPE_SBC**.|
| codecBitsPerSample  | [CodecBitsPerSample](#codecbitspersample11)  | No   | No   | Bit depth of each sampling point. The default value is **CODEC_BITS_PER_SAMPLE_NONE**.|
| codecChannelMode    | [CodecChannelMode](#codecchannelmode11) | No   | No   | Channel mode of the codec. The default value is **CODEC_CHANNEL_MODE_NONE**.|
| codecSampleRate     | [CodecSampleRate](#codecsamplerate11) | No   | No   | Sampling rate of the codec. The default value is **CODEC_SAMPLE_RATE_NONE**.|
| codecBitRate<sup>19+<sup/>     | [CodecBitRate](#codecbitrate19) | No   | Yes   | Bit rate of the codec. The default value is **CODEC_BIT_RATE_ABR**.|
| codecFrameLength<sup>19+<sup/>     | [CodecFrameLength](#codecframelength19) | No   | Yes   |Frame length of the codec. The default value is **CODEC_FRAME_LENGTH_10MS**.|

## CodecInfoList<sup>19+</sup>

Defines the capabilities supported by the Bluetooth media audio codec. The bit depth, channel mode, sampling rate, bit rate, and frame length supported by different codecs are related to the capabilities of the audio receiver device.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name       | Type                   | Read-Only  | Optional  | Description                                    |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType           | [CodecType](#codectype11)      | No   | No   | Codec type.|
| codecBitsPerSampleArray  | [CodecBitsPerSample](#codecbitspersample11)[] | No   | No   | Bit depth capability set supported by the codec.|
| codecChannelModeArray    | [CodecChannelMode](#codecchannelmode11)[] | No   | No   | Audio channel mode capabilities supported by the codec.|
| codecSampleRateArray     | [CodecSampleRate](#codecsamplerate11)[] | No   | No   | Sampling rate capabilities supported by the codec.|
| codecBitRateArray     | [CodecBitRate](#codecbitrate19)[] | No   | No   | Bit rate capabilities supported by the codec.|
| codecFrameLengthArray     | [CodecFrameLength](#codecframelength19)[] | No   | No   | Frame length capabilities supported by the codec.|

## CodecType<sup>11+</sup>

Enumerates the Bluetooth media audio codec types.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_TYPE_INVALID | -1 | Codec type unknown. |
| CODEC_TYPE_SBC     | 0 | SBC |
| CODEC_TYPE_AAC     | 1 | AAC |
| CODEC_TYPE_L2HC    | 2 | L2HC |
| CODEC_TYPE_L2HCST<sup>13+</sup>  | 3 | L2HCST |
| CODEC_TYPE_LDAC<sup>13+</sup>    | 4 | LDAC |


## CodecChannelMode<sup>11+</sup>

Enumerates the audio channel modes of Bluetooth media audio codec. A channel mode indicates the number of independent spatial signal paths during audio playback. It affects the stereo effect and spatial positioning of the audio.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_CHANNEL_MODE_NONE   | 0 | Channel unknown.|
| CODEC_CHANNEL_MODE_MONO   | 1 | Mono. |
| CODEC_CHANNEL_MODE_STEREO | 2 | Stereo. |


## CodecBitsPerSample<sup>11+</sup>

Enumerates the bit depths of the Bluetooth media codec. A bit depth indicates the number of bits used by the Bluetooth audio signal in the digital representation, in units of bit. It determines the dynamic range and precision that can be represented by each sampling point.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_BITS_PER_SAMPLE_NONE | 0 | Bit depth unknown.|
| CODEC_BITS_PER_SAMPLE_16   | 1 | 16-bit.|
| CODEC_BITS_PER_SAMPLE_24   | 2 | 24-bit.|
| CODEC_BITS_PER_SAMPLE_32   | 3 | 32-bit.|


## CodecSampleRate<sup>11+</sup>

Enumerates the sampling rates of the Bluetooth media audio codec. A sampling rate indicates the number of times that Bluetooth audio is sampled per second, in units of Hz. It affects the audio quality and transmission efficiency.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_SAMPLE_RATE_NONE    | 0 | Sampling rate unknown.|
| CODEC_SAMPLE_RATE_44100   | 1 | 44.1kHz |
| CODEC_SAMPLE_RATE_48000   | 2 | 48kHz |
| CODEC_SAMPLE_RATE_88200   | 3 | 88.2kHz |
| CODEC_SAMPLE_RATE_96000   | 4 | 96kHz |
| CODEC_SAMPLE_RATE_176400  | 5 | 176.4kHz |
| CODEC_SAMPLE_RATE_192000  | 6 | 192kHz |

## CodecBitRate<sup>19+</sup>

Enumerates the bit rates of the Bluetooth media audio codec. A bit rate indicates the amount of audio data transmitted per unit time, in units of kbit/s. It affects the audio quality and file size.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_BIT_RATE_96000    | 0 | 96kbps |
| CODEC_BIT_RATE_128000   | 1 | 128kbps |
| CODEC_BIT_RATE_192000   | 2 | 192kbps |
| CODEC_BIT_RATE_256000   | 3 | 256kbps |
| CODEC_BIT_RATE_320000   | 4 | 320kbps |
| CODEC_BIT_RATE_480000  | 5 | 480kbps |
| CODEC_BIT_RATE_640000  | 6 | 640kbps |
| CODEC_BIT_RATE_960000  | 7 | 960kbps |
| CODEC_BIT_RATE_ABR  | 8 | Adaptive bit rate (automatic adjustment of the bit rate based on network conditions).|

## CodecFrameLength<sup>19+</sup>

Enumerates frame lengths of the Bluetooth media audio codec. A frame length indicates the playback duration of an audio frame.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_FRAME_LENGTH_5MS    | 0 | 5 ms|
| CODEC_FRAME_LENGTH_10MS   | 1 | 10 ms|
