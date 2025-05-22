# @ohos.bluetooth.a2dp (Bluetooth A2DP Module)

The **a2dp** module provides APIs for using the Bluetooth Advanced Audio Distribution Profile (A2DP), which defines how to stream high quality audio from one device to another over a Bluetooth connection.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import { a2dp } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

Defines **BaseProfile** APIs.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#baseprofile) | **BaseProfile** API definition.|


## a2dp.createA2dpSrcProfile

createA2dpSrcProfile(): A2dpSourceProfile

Creates an **A2dpSrcProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [A2dpSourceProfile](#a2dpsourceprofile) | **A2dpSrcProfile** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                         |
|801 | Capability not supported.                |


**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let a2dpProfile = a2dp.createA2dpSrcProfile();
    console.info('a2dp success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## A2dpSourceProfile

Provides APIs for using the A2DP. Before using any API of **A2dpSourceProfile**, you need to create an instance of this class by using [createA2dpSrcProfile()](#a2dpcreatea2dpsrcprofile).


### getPlayingState

getPlayingState(deviceId: string): PlayingState

Obtains the playing state of a device.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [PlayingState](#playingstate) | Playing state of the remote device obtained.|

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
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let state = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## PlayingState

Enumerates the A2DP playing states.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0x0000 | Not playing. |
| STATE_PLAYING     | 0x0001 | Playing.|


## CodecInfo<sup>11+</sup>

Defines the codec information.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name       | Type                   | Readable  | Writable  | Description                                    |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType           | [CodecType](#codectype11)      | Yes   | Yes   | Codec type. The default value is **CODEC_TYPE_SBC**.|
| codecBitsPerSample  | [CodecBitsPerSample](#codecbitspersample11)  | Yes   | Yes   | Number of bits of each sample. The default value is **SCAN_MODE_LOW_POWER**.|
| codecChannelMode    | [CodecChannelMode](#codecchannelmode11) | Yes   | Yes   | Channel mode of the codec. The default value is **CODEC_CHANNEL_MODE_NONE**.|
| codecSampleRate     | [CodecSampleRate](#codecsamplerate11) | Yes   | Yes   | Sampling rate of the codec. The default value is **CODEC_BITS_PER_SAMPLE_NONE**.|


## CodecType<sup>11+</sup>

Enumerates the Bluetooth codec types.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_TYPE_INVALID | -1 | Unknown type. |
| CODEC_TYPE_SBC     | 0 | SBC.|
| CODEC_TYPE_AAC     | 1 | AAC.|
| CODEC_TYPE_L2HC    | 2 | L2HC.|
| CODEC_TYPE_L2HCST<sup>13+</sup>  | 3 | L2HCST.|
| CODEC_TYPE_LDAC<sup>13+</sup>    | 4 | LDAC.|


## CodecChannelMode<sup>11+</sup>

Enumerates the channel modes of the Bluetooth codec.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_CHANNEL_MODE_NONE   | 0 | Unknown.|
| CODEC_CHANNEL_MODE_MONO   | 1 | Mono. |
| CODEC_CHANNEL_MODE_STEREO | 2 | Stereo. |


## CodecBitsPerSample<sup>11+</sup>

Enumerates the number of bits per sample for the Bluetooth codec.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_BITS_PER_SAMPLE_NONE | 0 | Unknown.|
| CODEC_BITS_PER_SAMPLE_16   | 1 | 16 bits per sample.|
| CODEC_BITS_PER_SAMPLE_24   | 2 | 24 bits per sample.|
| CODEC_BITS_PER_SAMPLE_32   | 3 | 32 bits per sample.|


## CodecSampleRate<sup>11+</sup>

Enumerates the sampling rates of the Bluetooth codec.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| CODEC_SAMPLE_RATE_NONE    | 0 | Unknown.|
| CODEC_SAMPLE_RATE_44100   | 1 | 44.1 kHz.|
| CODEC_SAMPLE_RATE_48000   | 2 | 48 kHz.|
| CODEC_SAMPLE_RATE_88200   | 3 | 88.2 kHz.|
| CODEC_SAMPLE_RATE_96000   | 4 | 96 kHz.|
| CODEC_SAMPLE_RATE_176400  | 5 | 176.4 kHz.|
| CODEC_SAMPLE_RATE_192000  | 6 | 192 kHz.|
