# @ohos.bluetooth.a2dp (蓝牙a2dp模块)

a2dp模块提供了访问蓝牙音频接口的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import { a2dp } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

基础Profile接口定义。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#ohosbluetoothbaseprofile-蓝牙baseprofile模块) | 基础Profile接口定义。 |


## a2dp.createA2dpSrcProfile

createA2dpSrcProfile(): A2dpSourceProfile

创建a2dp profile实例。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [A2dpSourceProfile](#a2dpsourceprofile) | 返回该profile的实例。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                         |
|801 | Capability not supported.                |


**示例：**

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

使用A2dpSourceProfile方法之前需要创建该类的实例进行操作，通过[createA2dpSrcProfile()](#a2dpcreatea2dpsrcprofile)方法构造此实例。


### getPlayingState

getPlayingState(deviceId: string): PlayingState

获取设备的播放状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [PlayingState](#playingstate) | 远端设备的播放状态。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**示例：**

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

枚举，蓝牙A2DP 播放状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0x0000 | 表示未播放。  |
| STATE_PLAYING     | 0x0001 | 表示正在播放。 |


## CodecInfo<sup>11+</sup>

编码器信息。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称        | 类型                    | 只读   | 可选   | 说明                                     |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType           | [CodecType](#codectype11)      | 否    | 否    | 表示编码器类型，默认值为CODEC_TYPE_SBC。 |
| codecBitsPerSample  | [CodecBitsPerSample](#codecbitspersample11)  | 否    | 否    | 表示每个采样点的位数，默认值为CODEC_BITS_PER_SAMPLE_NONE。 |
| codecChannelMode    | [CodecChannelMode](#codecchannelmode11) | 否    | 否    | 表示编码器的声道模式，默认值为CODEC_CHANNEL_MODE_NONE。 |
| codecSampleRate     | [CodecSampleRate](#codecsamplerate11) | 否    | 否    | 表示编码器的采样率，默认值为CODEC_BITS_PER_SAMPLE_NONE。 |
| codecBitRate<sup>19+<sup/>     | [CodecBitRate](#codecbitrate19) | 否    | 是    | 表示编码器的比特率，默认值为CODEC_BIT_RATE_ABR。 |
| codecFrameLength<sup>19+<sup/>     | [CodecFrameLength](#codecframelength19) | 否    | 是    | 表示编码器的帧长，默认值为CODEC_FRAME_LENGTH_10MS。 |

## CodecInfoList<sup>19+</sup>

编码器支持的参数信息。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称        | 类型                    | 只读   | 可选   | 说明                                     |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType           | [CodecType](#codectype11)      | 否    | 否    | 表示编码器类型。 |
| codecBitsPerSampleArray  | [CodecBitsPerSample[]](#codecbitspersample11) | 否    | 否    | 表示当前编码器支持的采样点位数列表。 |
| codecChannelModeArray    | [CodecChannelMode[]](#codecchannelmode11) | 否    | 否    | 表示当前编码器支持的声道模式列表。 |
| codecSampleRateArray     | [CodecSampleRate[]](#codecsamplerate11) | 否    | 否    | 表示当前编码器支持的采样率列表。 |
| codecBitRateArray     | [CodecBitRate[]](#codecbitrate19) | 否    | 否    | 表示当前编码器支持的比特率列表。 |
| codecFrameLengthArray     | [CodecFrameLength[]](#codecframelength19) | 否    | 否    | 表示当前编码器支持的帧长列表。 |

## CodecType<sup>11+</sup>

枚举，蓝牙编码器类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_TYPE_INVALID | -1 | 未知编码类型。  |
| CODEC_TYPE_SBC     | 0 | SBC。 |
| CODEC_TYPE_AAC     | 1 | AAC。 |
| CODEC_TYPE_L2HC    | 2 | L2HC。|
| CODEC_TYPE_L2HCST<sup>13+</sup>  | 3 | L2HCST。 |
| CODEC_TYPE_LDAC<sup>13+</sup>    | 4 | LDAC。|


## CodecChannelMode<sup>11+</sup>

枚举，蓝牙编码器的声道模式。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_CHANNEL_MODE_NONE   | 0 | 未知声道。|
| CODEC_CHANNEL_MODE_MONO   | 1 | 单声道。  |
| CODEC_CHANNEL_MODE_STEREO | 2 | 双声道。  |


## CodecBitsPerSample<sup>11+</sup>

枚举，蓝牙编码器每个采样点的位数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_BITS_PER_SAMPLE_NONE | 0 | 未知采样点的位数。|
| CODEC_BITS_PER_SAMPLE_16   | 1 | 16位采样点的位数。|
| CODEC_BITS_PER_SAMPLE_24   | 2 | 24位采样点的位数。|
| CODEC_BITS_PER_SAMPLE_32   | 3 | 32位采样点的位数。|


## CodecSampleRate<sup>11+</sup>

枚举，蓝牙编码器的采样率。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_SAMPLE_RATE_NONE    | 0 | 未知采样率。|
| CODEC_SAMPLE_RATE_44100   | 1 | 44.1k采样率。|
| CODEC_SAMPLE_RATE_48000   | 2 | 48k采样率。|
| CODEC_SAMPLE_RATE_88200   | 3 | 88.2k采样率。|
| CODEC_SAMPLE_RATE_96000   | 4 | 96k位采样率。|
| CODEC_SAMPLE_RATE_176400  | 5 | 176.4k位采样率。|
| CODEC_SAMPLE_RATE_192000  | 6 | 192k位采样率。|

## CodecBitRate<sup>19+</sup>

枚举，蓝牙编码器的比特率。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_BIT_RATE_96000    | 0 | 96k比特率。|
| CODEC_BIT_RATE_128000   | 1 | 128k比特率。|
| CODEC_BIT_RATE_192000   | 2 | 192k比特率。|
| CODEC_BIT_RATE_256000   | 3 | 256k比特率。|
| CODEC_BIT_RATE_320000   | 4 | 320k比特率。|
| CODEC_BIT_RATE_480000  | 5 | 480k比特率。|
| CODEC_BIT_RATE_640000  | 6 | 640k比特率。|
| CODEC_BIT_RATE_960000  | 7 | 960k比特率。|
| CODEC_BIT_RATE_ABR  | 8 | 自适应比特率。|

## CodecFrameLength<sup>19+</sup>

枚举，蓝牙编码器的帧长。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_FRAME_LENGTH_5MS    | 0 | 5ms帧长。|
| CODEC_FRAME_LENGTH_10MS   | 1 | 10ms帧长。|