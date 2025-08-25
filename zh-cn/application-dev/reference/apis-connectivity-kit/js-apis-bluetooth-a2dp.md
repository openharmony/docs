# @ohos.bluetooth.a2dp (蓝牙a2dp模块)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

本模块提供基于增强音频分发协议（Advanced Audio Distribution Profile，A2DP）的蓝牙媒体音频能力，支持获取媒体播放状态和连接状态等方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import { a2dp } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

基础Profile接口定义，提供监听和获取连接状态等公共能力。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#ohosbluetoothbaseprofile-蓝牙baseprofile模块) | 基础Profile接口定义。 |


## a2dp.createA2dpSrcProfile

createA2dpSrcProfile(): A2dpSourceProfile

创建蓝牙媒体音频源实例。通过该实例可使用本端作为音频源设备的方法，如：获取和其他设备间的蓝牙媒体音频播放状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [A2dpSourceProfile](#a2dpsourceprofile) | 返回蓝牙媒体音频源实例。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                         |
|801 | Capability not supported.                |


**示例：**

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

该实例表示音频源设备端，负责发送音频数据。
- 该类继承于[BaseProfile](#baseprofile)，因此可以使用其父类中的方法。
- 使用该类的方法前，需通过[createA2dpSrcProfile](#a2dpcreatea2dpsrcprofile)方法构造该类的实例。
- 和该实例角色相对应的是音频接收器（A2DP Sink），即接收音频数据的设备端，典型设备如：耳机或者音箱。

### getPlayingState

getPlayingState(deviceId: string): PlayingState

获取本端和对端设备间的媒体音频播放状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [PlayingState](#playingstate) | 蓝牙媒体音频播放状态。 |

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
import { BusinessError } from '@kit.BasicServicesKit';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let state = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## PlayingState

枚举，蓝牙媒体音频播放状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0 | 未播放媒体音频。  |
| STATE_PLAYING     | 1 | 正在播放媒体音频。 |


## CodecInfo<sup>11+</sup>

蓝牙媒体音频使用的编解码器。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称        | 类型                    | 只读   | 可选   | 说明                                     |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType           | [CodecType](#codectype11)      | 否    | 否    | 编解码器类型，默认值为CODEC_TYPE_SBC。 |
| codecBitsPerSample  | [CodecBitsPerSample](#codecbitspersample11)  | 否    | 否    | 每个采样点的位深，默认值为CODEC_BITS_PER_SAMPLE_NONE。 |
| codecChannelMode    | [CodecChannelMode](#codecchannelmode11) | 否    | 否    | 编解码器的声道模式，默认值为CODEC_CHANNEL_MODE_NONE。 |
| codecSampleRate     | [CodecSampleRate](#codecsamplerate11) | 否    | 否    | 编解码器的采样率，默认值为CODEC_SAMPLE_RATE_NONE。 |
| codecBitRate<sup>19+<sup/>     | [CodecBitRate](#codecbitrate19) | 否    | 是    | 编解码器的码率，默认值为CODEC_BIT_RATE_ABR。 |
| codecFrameLength<sup>19+<sup/>     | [CodecFrameLength](#codecframelength19) | 否    | 是    |编解码器的帧长，默认值为CODEC_FRAME_LENGTH_10MS。 |

## CodecInfoList<sup>19+</sup>

蓝牙媒体音频编解码器支持的能力集合。不同编解码器支持的位深、声道模式、采样率、码率和帧长类型与音频接收器设备端能力有关。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称        | 类型                    | 只读   | 可选   | 说明                                     |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType           | [CodecType](#codectype11)      | 否    | 否    | 编解码器类型。 |
| codecBitsPerSampleArray  | [CodecBitsPerSample](#codecbitspersample11)[] | 否    | 否    | 编解码器支持的位深能力集合。 |
| codecChannelModeArray    | [CodecChannelMode](#codecchannelmode11)[] | 否    | 否    | 编解码器支持的声道模式能力集合。 |
| codecSampleRateArray     | [CodecSampleRate](#codecsamplerate11)[] | 否    | 否    | 编解码器支持的采样率能力集合。 |
| codecBitRateArray     | [CodecBitRate](#codecbitrate19)[] | 否    | 否    | 编解码器支持的码率能力集合。 |
| codecFrameLengthArray     | [CodecFrameLength](#codecframelength19)[] | 否    | 否    | 编解码器支持的帧长能力集合。 |

## CodecType<sup>11+</sup>

枚举，蓝牙媒体音频编解码器类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_TYPE_INVALID | -1 | 编解码器类型未知。  |
| CODEC_TYPE_SBC     | 0 | SBC |
| CODEC_TYPE_AAC     | 1 | AAC |
| CODEC_TYPE_L2HC    | 2 | L2HC |
| CODEC_TYPE_L2HCST<sup>13+</sup>  | 3 | L2HCST |
| CODEC_TYPE_LDAC<sup>13+</sup>    | 4 | LDAC |


## CodecChannelMode<sup>11+</sup>

枚举，蓝牙媒体音频编解码器的声道模式，表示音频播放时独立的空间信号路径数量。声道模式影响声音的立体感和空间定位‌。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_CHANNEL_MODE_NONE   | 0 | 声道未知。 |
| CODEC_CHANNEL_MODE_MONO   | 1 | 单声道。  |
| CODEC_CHANNEL_MODE_STEREO | 2 | 双声道。  |


## CodecBitsPerSample<sup>11+</sup>

枚举，蓝牙媒体音频编解码器的位深，表示蓝牙音频信号在数字表示中使用的位数，单位为bit。位深决定每个采样点可以表示的动态范围和精度。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_BITS_PER_SAMPLE_NONE | 0 | 位深未知。 |
| CODEC_BITS_PER_SAMPLE_16   | 1 | 16bit |
| CODEC_BITS_PER_SAMPLE_24   | 2 | 24bit |
| CODEC_BITS_PER_SAMPLE_32   | 3 | 32bit |


## CodecSampleRate<sup>11+</sup>

枚举，蓝牙媒体音频编解码器的采样率，表示每秒对蓝牙音频采样的次数，单位为Hz。采样率的选择会影响音质和传输效率。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_SAMPLE_RATE_NONE    | 0 | 采样率未知。 |
| CODEC_SAMPLE_RATE_44100   | 1 | 44.1kHz |
| CODEC_SAMPLE_RATE_48000   | 2 | 48kHz |
| CODEC_SAMPLE_RATE_88200   | 3 | 88.2kHz |
| CODEC_SAMPLE_RATE_96000   | 4 | 96kHz |
| CODEC_SAMPLE_RATE_176400  | 5 | 176.4kHz |
| CODEC_SAMPLE_RATE_192000  | 6 | 192kHz |

## CodecBitRate<sup>19+</sup>

枚举，蓝牙媒体音频编解码器的码率，表示单位时间内音频数据的传输量，单位为kbps。码率影响音频音质和文件大小。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_BIT_RATE_96000    | 0 | 96kbps |
| CODEC_BIT_RATE_128000   | 1 | 128kbps |
| CODEC_BIT_RATE_192000   | 2 | 192kbps |
| CODEC_BIT_RATE_256000   | 3 | 256kbps |
| CODEC_BIT_RATE_320000   | 4 | 320kbps |
| CODEC_BIT_RATE_480000  | 5 | 480kbps |
| CODEC_BIT_RATE_640000  | 6 | 640kbps |
| CODEC_BIT_RATE_960000  | 7 | 960kbps |
| CODEC_BIT_RATE_ABR  | 8 | 自适应码率（根据网络条件自动调整）。|

## CodecFrameLength<sup>19+</sup>

枚举，蓝牙媒体音频编解码器的帧长，表示一帧音频数据播放的时长。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_FRAME_LENGTH_5MS    | 0 | 5ms帧长。 |
| CODEC_FRAME_LENGTH_10MS   | 1 | 10ms帧长。 |