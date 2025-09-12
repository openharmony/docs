# Enums
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## AudioVolumeType

表示音频流类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| VOICE_CALL<sup>8+</sup>      | 0      | 语音电话。 |
| RINGTONE                     | 2      | 铃声。     |
| MEDIA                        | 3      | 媒体。     |
| ALARM<sup>10+</sup>          | 4      | 闹钟。     |
| ACCESSIBILITY<sup>10+</sup>  | 5      | 无障碍。   |
| VOICE_ASSISTANT<sup>8+</sup> | 9      | 语音助手。 |

## InterruptMode<sup>9+</sup>

表示焦点模型的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| SHARE_MODE                   | 0      | 共享焦点模式。 |
| INDEPENDENT_MODE             | 1      | 独立焦点模式。 |

## DeviceFlag

表示音频设备类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                            |  值     | 说明                        |
| ------------------------------- | ------ |---------------------------|
| OUTPUT_DEVICES_FLAG             | 1      | 输出设备。                     |
| INPUT_DEVICES_FLAG              | 2      | 输入设备。                     |
| ALL_DEVICES_FLAG                | 3      | 所有设备。                     |

## DeviceUsage<sup>12+</sup>

表示音频设备类型的枚举（根据用途分类）。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                            |  值     | 说明                        |
| ------------------------------- | ------ |---------------------------|
| MEDIA_OUTPUT_DEVICES | 1      | 媒体输出设备。|
| MEDIA_INPUT_DEVICES  | 2      | 媒体输入设备。|
| ALL_MEDIA_DEVICES    | 3      | 所有媒体设备。|
| CALL_OUTPUT_DEVICES  | 4      | 通话输出设备。|
| CALL_INPUT_DEVICES   | 8      | 通话输入设备。|
| ALL_CALL_DEVICES     | 12     | 所有通话设备。|

## DeviceRole

表示设备角色的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称          |  值    | 说明           |
| ------------- | ------ | -------------- |
| INPUT_DEVICE  | 1      | 输入设备角色。 |
| OUTPUT_DEVICE | 2      | 输出设备角色。 |

## DeviceType

表示设备类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                 | 值     | 说明                                                      |
| ---------------------| ------ | --------------------------------------------------------- |
| INVALID              | 0      | 无效设备。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| EARPIECE             | 1      | 听筒。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| SPEAKER              | 2      | 扬声器。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| WIRED_HEADSET        | 3      | 有线耳机，带麦克风。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| WIRED_HEADPHONES     | 4      | 有线耳机，不带麦克风。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| BLUETOOTH_SCO        | 7      | 蓝牙设备SCO（Synchronous Connection Oriented）连接。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| BLUETOOTH_A2DP       | 8      | 蓝牙设备A2DP（Advanced Audio Distribution Profile）连接。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| MIC                  | 15     | 麦克风。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| USB_HEADSET          | 22     | USB耳机，带麦克风。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| DISPLAY_PORT<sup>12+</sup>        | 23     | DisplayPort（显示接口，简称DP），用于外接扩展设备。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| REMOTE_CAST<sup>12+</sup>        | 24     | 音频被系统应用投送到其他的远程设备。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| USB_DEVICE<sup>18+</sup>        | 25 | USB设备（不包含USB耳机）。           |
| HDMI<sup>19+</sup>        | 27 | HDMI设备（例如HDMI、ARC、eARC等）。           |
| LINE_DIGITAL<sup>19+</sup>        | 28 | 有线数字设备（例如S/PDIF等）。           |
| REMOTE_DAUDIO<sup>18+</sup>        | 29 | 分布式设备。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| HEARING_AID<sup>20+</sup>        | 30 | 助听器设备。 |
| NEARLINK<sup>20+</sup>        | 31 | 星闪设备。 |
| DEFAULT<sup>9+</sup> | 1000   | 默认设备类型。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## CommunicationDeviceType<sup>9+</sup>

表示用于通信的可用设备类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

| 名称          | 值     | 说明          |
| ------------- | ------ | -------------|
| SPEAKER       | 2      | 扬声器。      |

## AudioRingMode

表示铃声模式的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

| 名称                |  值    | 说明       |
| ------------------- | ------ | ---------- |
| RINGER_MODE_SILENT  | 0      | 静音模式。 |
| RINGER_MODE_VIBRATE | 1      | 震动模式。 |
| RINGER_MODE_NORMAL  | 2      | 响铃模式。 |

## AudioSampleFormat<sup>8+</sup>

表示音频采样格式的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                |  值    | 说明                       |
| ---------------------------------- | ------ | -------------------------- |
| SAMPLE_FORMAT_INVALID              | -1     | 无效格式。                 |
| SAMPLE_FORMAT_U8                   | 0      | 无符号8位整数。            |
| SAMPLE_FORMAT_S16LE                | 1      | 带符号的16位整数，小尾数。 |
| SAMPLE_FORMAT_S24LE                | 2      | 带符号的24位整数，小尾数。 <br>由于系统限制，该采样格式仅部分设备支持，请根据实际情况使用。|
| SAMPLE_FORMAT_S32LE                | 3      | 带符号的32位整数，小尾数。 <br>由于系统限制，该采样格式仅部分设备支持，请根据实际情况使用。|
| SAMPLE_FORMAT_F32LE<sup>9+</sup>   | 4      | 带符号的32位浮点数，小尾数。 <br>由于系统限制，该采样格式仅部分设备支持，请根据实际情况使用。|

## AudioErrors<sup>9+</sup>

表示音频错误码的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                 | 值      | 说明         |
| ---------------------| --------| ----------------- |
| ERROR_INVALID_PARAM  | 6800101 | 无效入参。         |
| ERROR_NO_MEMORY      | 6800102 | 分配内存失败。     |
| ERROR_ILLEGAL_STATE  | 6800103 | 状态不支持。       |
| ERROR_UNSUPPORTED    | 6800104 | 参数选项不支持。    |
| ERROR_TIMEOUT        | 6800105 | 处理超时。         |
| ERROR_STREAM_LIMIT   | 6800201 | 音频流数量达到限制。|
| ERROR_SYSTEM         | 6800301 | 系统处理异常。     |

## AudioChannel<sup>8+</sup>

表示音频声道的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称      |  值       | 说明   |
| --------- | -------- |------|
| CHANNEL_1 | 1 | 单声道。 |
| CHANNEL_2 | 2 | 双声道。 |
| CHANNEL_3<sup>11+</sup> | 3 | 三声道。 |
| CHANNEL_4<sup>11+</sup> | 4 | 四声道。 |
| CHANNEL_5<sup>11+</sup> | 5 | 五声道。 |
| CHANNEL_6<sup>11+</sup> | 6 | 六声道。 |
| CHANNEL_7<sup>11+</sup> | 7 | 七声道。 |
| CHANNEL_8<sup>11+</sup> | 8 | 八声道。 |
| CHANNEL_9<sup>11+</sup> | 9 | 九声道。 |
| CHANNEL_10<sup>11+</sup> | 10 | 十声道。 |
| CHANNEL_12<sup>11+</sup> | 12 | 十二声道。 |
| CHANNEL_14<sup>11+</sup> | 14 | 十四声道。 |
| CHANNEL_16<sup>11+</sup> | 16 | 十六声道。 |

## AudioSamplingRate<sup>8+</sup>

表示音频采样率的枚举（具体设备支持的采样率规格会存在差异）。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称              |  值    | 说明            |
| ----------------- | ------ | --------------- |
| SAMPLE_RATE_8000  | 8000   | 采样率为8000。  |
| SAMPLE_RATE_11025 | 11025  | 采样率为11025。 |
| SAMPLE_RATE_12000 | 12000  | 采样率为12000。 |
| SAMPLE_RATE_16000 | 16000  | 采样率为16000。 |
| SAMPLE_RATE_22050 | 22050  | 采样率为22050。 |
| SAMPLE_RATE_24000 | 24000  | 采样率为24000。 |
| SAMPLE_RATE_32000 | 32000  | 采样率为32000。 |
| SAMPLE_RATE_44100 | 44100  | 采样率为44100。 |
| SAMPLE_RATE_48000 | 48000  | 采样率为48000。 |
| SAMPLE_RATE_64000 | 64000  | 采样率为64000。 |
| SAMPLE_RATE_88200<sup>12+</sup> | 88200  | 采样率为88200。 |
| SAMPLE_RATE_96000 | 96000  | 采样率为96000。 |
| SAMPLE_RATE_176400<sup>12+</sup> | 176400  | 采样率为176400。 |
| SAMPLE_RATE_192000<sup>12+</sup> | 192000  | 采样率为192000。 |

## AudioEncodingType<sup>8+</sup>

表示音频编码类型的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                  |  值    | 说明      |
| --------------------- | ------ | --------- |
| ENCODING_TYPE_INVALID | -1     | 无效。    |
| ENCODING_TYPE_RAW     | 0      | PCM编码。 |

## AudioChannelLayout<sup>11+</sup>

表示音频文件声道布局类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                            |  值              | 说明                                          |
| ------------------------------ | ---------------- | --------------------------------------------- |
| CH_LAYOUT_UNKNOWN              | 0x0              | 未知声道布局。                                 |
| CH_LAYOUT_MONO                 | 0x4              | 声道布局为MONO。                               |
| CH_LAYOUT_STEREO               | 0x3              | 声道布局为STEREO。                             |
| CH_LAYOUT_STEREO_DOWNMIX       | 0x60000000       | 声道布局为STEREO-DOWNMIX。                     |
| CH_LAYOUT_2POINT1              | 0xB              | 声道布局为2.1。                                |
| CH_LAYOUT_3POINT0              | 0x103            | 声道布局为3.0。                                |
| CH_LAYOUT_SURROUND             | 0x7              | 声道布局为SURROUND。                           |
| CH_LAYOUT_3POINT1              | 0xF              | 声道布局为3.1。                                |
| CH_LAYOUT_4POINT0              | 0x107            | 声道布局为4.0。                                |
| CH_LAYOUT_QUAD                 | 0x33             | 声道布局为QUAD。                               |
| CH_LAYOUT_QUAD_SIDE            | 0x603            | 声道布局为QUAD-SIDE。                          |
| CH_LAYOUT_2POINT0POINT2        | 0x3000000003     | 声道布局为2.0.2。                              |
| CH_LAYOUT_AMB_ORDER1_ACN_N3D   | 0x100000000001   | 声道排序为ACN_N3D（根据ITU标准）的一阶FOA文件。  |
| CH_LAYOUT_AMB_ORDER1_ACN_SN3D  | 0x100000001001   | 声道排序为ACN_SN3D（根据ITU标准）的一阶FOA文件。 |
| CH_LAYOUT_AMB_ORDER1_FUMA      | 0x100000000101   | 声道排序为FUMA（根据ITU标准）的一阶FOA文件。     |
| CH_LAYOUT_4POINT1              | 0x10F            | 声道布局为4.1。                                  |
| CH_LAYOUT_5POINT0              | 0x607            | 声道布局为5.0。                                |
| CH_LAYOUT_5POINT0_BACK         | 0x37             | 声道布局为5.0-BACK。                           |
| CH_LAYOUT_2POINT1POINT2        | 0x300000000B     | 声道布局为2.1.2。                              |
| CH_LAYOUT_3POINT0POINT2        | 0x3000000007     | 声道布局为3.0.2。                              |
| CH_LAYOUT_5POINT1              | 0x60F            | 声道布局为5.1。                                |
| CH_LAYOUT_5POINT1_BACK         | 0x3F             | 声道布局为5.1-BACK。                           |
| CH_LAYOUT_6POINT0              | 0x707            | 声道布局为6.0。                                |
| CH_LAYOUT_HEXAGONAL            | 0x137            | 声道布局为HEXAGONAL。                          |
| CH_LAYOUT_3POINT1POINT2        | 0x500F           | 声道布局为3.1.2。                              |
| CH_LAYOUT_6POINT0_FRONT        | 0x6C3            | 声道布局为6.0-FRONT。                          |
| CH_LAYOUT_6POINT1              | 0x70F            | 声道布局为6.1。                                |
| CH_LAYOUT_6POINT1_BACK         | 0x13F            | 声道布局为6.1-BACK。                           |
| CH_LAYOUT_6POINT1_FRONT        | 0x6CB            | 声道布局为6.1-FRONT。                          |
| CH_LAYOUT_7POINT0              | 0x637            | 声道布局为7.0。                                |
| CH_LAYOUT_7POINT0_FRONT        | 0x6C7            | 声道布局为7.0-FRONT。                          |
| CH_LAYOUT_7POINT1              | 0x63F            | 声道布局为7.1。                                |
| CH_LAYOUT_OCTAGONAL            | 0x737            | 声道布局为OCTAGONAL。                          |
| CH_LAYOUT_5POINT1POINT2        | 0x300000060F     | 声道布局为5.1.2。                              |
| CH_LAYOUT_7POINT1_WIDE         | 0x6CF            | 声道布局为7.1-WIDE。                           |
| CH_LAYOUT_7POINT1_WIDE_BACK    | 0xFF             | 声道布局为7.1-WIDE-BACK。                      |
| CH_LAYOUT_AMB_ORDER2_ACN_N3D   | 0x100000000002   | 声道排序为ACN_N3D（根据ITU标准）的二阶HOA文件。  |
| CH_LAYOUT_AMB_ORDER2_ACN_SN3D  | 0x100000001002   | 声道排序为ACN_SN3D（根据ITU标准）的二阶HOA文件。 |
| CH_LAYOUT_AMB_ORDER2_FUMA      | 0x100000000102   | 声道排序为FUMA（根据ITU标准）的二阶HOA文件。     |
| CH_LAYOUT_5POINT1POINT4        | 0x2D60F          | 声道布局为5.1.4。                              |
| CH_LAYOUT_7POINT1POINT2        | 0x300000063F     | 声道布局为7.1.2。                              |
| CH_LAYOUT_7POINT1POINT4        | 0x2D63F          | 声道布局为7.1.4。                              |
| CH_LAYOUT_10POINT2             | 0x180005737      | 声道布局为10.2。                               |
| CH_LAYOUT_9POINT1POINT4        | 0x18002D63F      | 声道布局为9.1.4。                              |
| CH_LAYOUT_9POINT1POINT6        | 0x318002D63F     | 声道布局为9.1.6。                              |
| CH_LAYOUT_HEXADECAGONAL        | 0x18003F737      | 声道布局为HEXADECAGONAL。                      |
| CH_LAYOUT_AMB_ORDER3_ACN_N3D   | 0x100000000003   | 声道排序为ACN_N3D（根据ITU标准）的三阶HOA文件。  |
| CH_LAYOUT_AMB_ORDER3_ACN_SN3D  | 0x100000001003   | 声道排序为ACN_SN3D（根据ITU标准）的三阶HOA文件。 |
| CH_LAYOUT_AMB_ORDER3_FUMA      | 0x100000000103   | 声道排序为FUMA（根据ITU标准）的三阶HOA文件。     |

## StreamUsage

表示音频流使用类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                      |  值    | 说明                                                                             |
| ------------------------------------------| ------ |--------------------------------------------------------------------------------|
| STREAM_USAGE_UNKNOWN                      | 0      | 未知类型。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_MEDIA<sup>(deprecated)</sup> | 1      | 媒体。<br/> 从API version 7开始支持，从API version 10开始废弃，建议使用该枚举中的STREAM_USAGE_MUSIC、STREAM_USAGE_MOVIE、STREAM_USAGE_GAME或STREAM_USAGE_AUDIOBOOK替代。 |
| STREAM_USAGE_MUSIC<sup>10+</sup>          | 1      | 音乐。   <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_VOICE_COMMUNICATION          | 2      | VoIP语音通话（该流类型起播时，会触发开启3A算法）。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| STREAM_USAGE_VOICE_ASSISTANT<sup>9+</sup> | 3      | 语音播报。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_ALARM<sup>10+</sup>          | 4      | 闹钟。   <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_VOICE_MESSAGE<sup>10+</sup>  | 5      | 语音消息。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_NOTIFICATION_RINGTONE<sup>(deprecated)</sup> | 6      | 通知铃声。<br/> 从API version 7开始支持，从API version 10开始废弃，建议使用该枚举中的STREAM_USAGE_RINGTONE替代。 |
| STREAM_USAGE_RINGTONE<sup>10+</sup>       | 6      | 铃声。    <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_NOTIFICATION<sup>10+</sup>   | 7      | 通知音。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_ACCESSIBILITY<sup>10+</sup>  | 8      | 无障碍。    <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_MOVIE<sup>10+</sup>          | 10     | 电影或视频。   <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_GAME<sup>10+</sup>           | 11     | 游戏。  <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_AUDIOBOOK<sup>10+</sup>      | 12     | 有声读物（包括听书、相声、评书）、听新闻、播客等。   <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_NAVIGATION<sup>10+</sup>     | 13     | 导航。   <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| STREAM_USAGE_VIDEO_COMMUNICATION<sup>12+</sup>     | 17     | VoIP视频通话（该流类型起播时，会触发开启3A算法）。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## AudioState<sup>8+</sup>

表示音频状态的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称           | 值     | 说明             |
| -------------- | ------ | ---------------- |
| STATE_INVALID  | -1     | 无效状态。       |
| STATE_NEW      | 0      | 创建新实例状态。 |
| STATE_PREPARED | 1      | 准备状态。       |
| STATE_RUNNING  | 2      | 运行状态。 |
| STATE_STOPPED  | 3      | 停止状态。       |
| STATE_RELEASED | 4      | 释放状态。       |
| STATE_PAUSED   | 5      | 暂停状态。       |

## AudioEffectMode<sup>10+</sup>

表示音效模式的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称               | 值     | 说明       |
| ------------------ | ------ | ---------- |
| EFFECT_NONE        | 0      | 关闭音效。 |
| EFFECT_DEFAULT     | 1      | 默认音效。 |

## AudioRendererRate<sup>8+</sup>

表示音频渲染速度的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称               | 值     | 说明       |
| ------------------ | ------ | ---------- |
| RENDER_RATE_NORMAL | 0      | 正常速度。 |
| RENDER_RATE_DOUBLE | 1      | 2倍速。    |
| RENDER_RATE_HALF   | 2      | 0.5倍速。  |

## InterruptType

表示中断类型的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称                 |  值     | 说明                   |
| -------------------- | ------ | ---------------------- |
| INTERRUPT_TYPE_BEGIN | 1      | 音频播放中断事件开始。 |
| INTERRUPT_TYPE_END   | 2      | 音频播放中断事件结束。 |

## InterruptForceType<sup>9+</sup>

表示音频打断类型的枚举。

当用户监听到音频中断（即收到[InterruptEvent](arkts-apis-audio-i.md#interruptevent9)事件）时，获取此信息。

此类型表示音频打断是否已由系统强制执行，具体操作信息（如音频暂停、停止等）可通过[InterruptHint](#interrupthint)获取。关于音频打断策略的详细说明可参考文档[音频焦点和音频会话介绍](../../media/audio/audio-playback-concurrency.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称            |  值    | 说明                                 |
| --------------- | ------ | ------------------------------------ |
| INTERRUPT_FORCE | 0      | 强制打断类型，即具体操作已由系统强制执行。   |
| INTERRUPT_SHARE | 1      | 共享打断类型，即系统不执行具体操作，通过[InterruptHint](#interrupthint)建议并提示应用操作，应用可自行决策下一步处理方式。 |

## InterruptHint

表示中断提示的枚举。

当用户监听到音频中断事件（即收到[InterruptEvent](arkts-apis-audio-i.md#interruptevent9)事件）时，获取此信息。

此类型表示根据焦点策略，对音频流执行的具体操作（如暂停、调整音量等）。

可以结合InterruptEvent中的[InterruptForceType](#interruptforcetype9)信息，判断该操作是否已由系统强制执行。详情请参阅文档[音频焦点和音频会话介绍](../../media/audio/audio-playback-concurrency.md)。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称                               |  值     | 说明                                         |
| ---------------------------------- | ------ | -------------------------------------------- |
| INTERRUPT_HINT_NONE<sup>8+</sup>   | 0      | 无提示。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| INTERRUPT_HINT_RESUME              | 1      | 提示音频恢复，应用可主动触发开始渲染或开始采集的相关操作。<br>此操作无法由系统强制执行，其对应的[InterruptForceType](#interruptforcetype9)一定为INTERRUPT_SHARE类型。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| INTERRUPT_HINT_PAUSE               | 2      | 提示音频暂停，暂时失去音频焦点。<br>待焦点可用时，会收到INTERRUPT_HINT_RESUME事件。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| INTERRUPT_HINT_STOP                | 3      | 提示音频停止，彻底失去音频焦点。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| INTERRUPT_HINT_DUCK                | 4      | 提示音频躲避开始，降低音量播放。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| INTERRUPT_HINT_UNDUCK<sup>8+</sup> | 5      | 提示音频躲避结束，恢复音量播放。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| INTERRUPT_HINT_MUTE<sup>20+</sup> | 6      | 提示音频静音。 |
| INTERRUPT_HINT_UNMUTE<sup>20+</sup> | 7      | 提示音频解除静音。            |

## AudioVolumeMode<sup>19+</sup>

表示音量模式的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称           | 值     | 说明           |
| -------------- | ------ |--------------|
| SYSTEM_GLOBAL  | 0 | 系统级音量（默认模式）。 |
| APP_INDIVIDUAL | 1 | 应用级音量。       |

## AudioPrivacyType<sup>10+</sup>

表示对应播放音频流是否支持被其他应用录制的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.PlaybackCapture

| 名称                 | 值   | 说明                             |
| -------------------- | ---- | -------------------------------- |
| PRIVACY_TYPE_PUBLIC  | 0    | 表示音频流可以被其他应用录制。   |
| PRIVACY_TYPE_PRIVATE | 1    | 表示音频流不可以被其他应用录制。 |

## ChannelBlendMode<sup>11+</sup>

表示声道混合模式类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                         |  值     | 说明                   |
| :------------------------------------------- | :----- | :--------------------- |
| MODE_DEFAULT | 0     | 无声道混合。  |
| MODE_BLEND_LR | 1      | 混合左右声道。 |
| MODE_ALL_LEFT | 2      | 从左声道覆盖到右声道混合。  |
| MODE_ALL_RIGHT | 3 | 从右声道覆盖到左声道混合。 |

## AudioStreamDeviceChangeReason<sup>11+</sup>

表示流设备变更原因的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                                        |  值     | 说明              |
|:------------------------------------------| :----- |:----------------|
| REASON_UNKNOWN | 0 | 未知原因。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| REASON_NEW_DEVICE_AVAILABLE | 1 | 新设备可用。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| REASON_OLD_DEVICE_UNAVAILABLE | 2 | 旧设备不可用。报告此原因时，应考虑暂停音频播放。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| REASON_OVERRODE | 3 | 强选。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| REASON_SESSION_ACTIVATED<sup>20+</sup> | 4 | 音频会话已激活。 |
| REASON_STREAM_PRIORITY_CHANGED<sup>20+</sup> | 5 | 更高优先级的音频流出现导致的系统设备切换。 |

## OutputDeviceChangeRecommendedAction<sup>20+</sup>

表示输出设备变更后推荐操作的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                        |  值     | 说明              |
|:------------------------------------------| :----- |:----------------|
| DEVICE_CHANGE_RECOMMEND_TO_CONTINUE | 0 | 推荐继续播放。           |
| DEVICE_CHANGE_RECOMMEND_TO_STOP | 1 | 推荐停止播放。         |

## DeviceChangeType

表示设备连接状态变化的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称       | 值   | 说明           |
| :--------- | :--- | :------------- |
| CONNECT    | 0    | 设备连接。     |
| DISCONNECT | 1    | 断开设备连接。 |

## DeviceBlockStatus<sup>13+</sup>

表示音频设备是否被堵塞的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称       | 值   | 说明           |
| :--------- | :--- | :------------- |
| UNBLOCKED  | 0    | 音频设备正常。    |
| BLOCKED    | 1    | 音频设备被堵塞。 |

## SourceType<sup>8+</sup>

表示音源类型的枚举。

| 名称                                         |  值     | 说明                   |
| :------------------------------------------- | :----- | :--------------------- |
| SOURCE_TYPE_INVALID                          | -1     | 无效的音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core  |
| SOURCE_TYPE_MIC                              | 0      | Mic音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_VOICE_RECOGNITION<sup>9+</sup>   | 1      | 语音识别源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core  |
| SOURCE_TYPE_PLAYBACK_CAPTURE<sup>(deprecated)</sup>   | 2 | 播放音频流（内录）录制音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.PlaybackCapture <br/> 从API version 10开始支持，从API version 12开始废弃，建议使用[录屏接口AVScreenCapture](../apis-media-kit/capi-avscreencapture.md)替代。  |
| SOURCE_TYPE_VOICE_COMMUNICATION              | 7      | 语音通话场景的音频源（单独启动录制不会开启3A算法，需同时使用[STREAM_USAGE_VOICE_COMMUNICATION](#streamusage)或[STREAM_USAGE_VIDEO_COMMUNICATION](#streamusage)类型的AudioRender起播才会触发开启3A算法）。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_VOICE_MESSAGE<sup>12+</sup>      | 10     | 短语音消息的音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_CAMCORDER<sup>13+</sup>          | 13     | 录像的音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core |
| SOURCE_TYPE_UNPROCESSED<sup>14+</sup>     | 14 |  麦克风纯净录音的音频源（系统不做任何算法处理）。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core |
|  SOURCE_TYPE_LIVE<sup>20+</sup>     | 17 |  直播场景的音频源。<br/>**系统能力：** SystemCapability.Multimedia.Audio.Core |

## AudioScene<sup>8+</sup>

表示音频场景的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

| 名称                   |  值     | 说明                                          |
| :--------------------- | :----- | :-------------------------------------------- |
| AUDIO_SCENE_DEFAULT                  | 0      | 默认音频场景。                                |
| AUDIO_SCENE_RINGING<sup>12+</sup>    | 1      | 响铃模式。 |
| AUDIO_SCENE_PHONE_CALL<sup>12+</sup> | 2      | 电话模式。 |
| AUDIO_SCENE_VOICE_CHAT               | 3      | 语音聊天模式。                                |

## AudioConcurrencyMode<sup>12+</sup>

表示音频并发模式的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                   | 值 | 说明      |
| :--------------------- |:--|:--------|
| CONCURRENCY_DEFAULT | 0 | 默认使用系统策略。     |
| CONCURRENCY_MIX_WITH_OTHERS | 1 | 和其他音频并发。     |
| CONCURRENCY_DUCK_OTHERS | 2 | 压低其他音频的音量。 |
| CONCURRENCY_PAUSE_OTHERS | 3 | 暂停其他音频。 |

## AudioSessionDeactivatedReason<sup>12+</sup>

表示音频会话停用原因的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                   | 值 | 说明     |
| :--------------------- |:--|:-------|
| DEACTIVATED_LOWER_PRIORITY | 0 | 应用焦点被抢占。 |
| DEACTIVATED_TIMEOUT | 1 | 音频会话等待超时。    |

## AudioSessionScene<sup>20+</sup>

枚举音频会话场景。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                   | 值 | 说明      |
| :--------------------- |:--|:--------|
| AUDIO_SESSION_SCENE_MEDIA | 0 | 媒体音频会话场景。     |
| AUDIO_SESSION_SCENE_GAME | 1 | 游戏音频会话场景。     |
| AUDIO_SESSION_SCENE_VOICE_COMMUNICATION  | 2 | VoIP语音通话音频会话场景。 |

## AudioSessionStateChangeHint<sup>20+</sup>

枚举用于音频会话状态变更提示。

当用户监听到音频会话状态变化事件（即收到[AudioSessionStateChangedEvent](arkts-apis-audio-i.md#audiosessionstatechangedevent20)事件）时，获取相关信息。

此类型表示根据焦点策略对音频会话执行的操作，包括暂停、调整音量等。

详情请参阅文档[音频焦点和音频会话介绍](../../media/audio/audio-playback-concurrency.md)。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                               |  值     | 说明                                         |
| ---------------------------------- | ------ | -------------------------------------------- |
| AUDIO_SESSION_STATE_CHANGE_HINT_RESUME              | 0      | 提示音频会话恢复，应用可主动触发开始渲染等操作。 |
| AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE               | 1      | 提示音频会话暂停，暂时失去音频焦点。当焦点再次可用时，会收到 AUDIO_SESSION_STATE_CHANGE_HINT_RESUME 事件。 |
| AUDIO_SESSION_STATE_CHANGE_HINT_STOP                | 2      | 提示音频会话因焦点被抢占而停止，彻底失去音频焦点。 |
| AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP                | 3      | 提示音频会话因长时间无业务而被系统停止，导致失去音频焦点。 |
| AUDIO_SESSION_STATE_CHANGE_HINT_DUCK                | 4      | 提示音频会话躲避开始，降低音量播放。 |
| AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK | 5      | 提示音频会话躲避结束，恢复音量播放。 |

## AudioDataCallbackResult<sup>12+</sup>

表示音频数据回调结果的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                 | 值      | 说明         |
| ---------------------| --------| ----------------- |
| INVALID  | -1 | 表示该回调数据无效。      |
| VALID      | 0 | 表示该回调数据有效。     |

## ContentType<sup>(deprecated)</sup>

表示音频内容类型的枚举。

> **说明：**
> 从API version 7开始支持，从API version 10开始废弃，建议使用[StreamUsage](#streamusage)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                               |  值    | 说明       |
| ---------------------------------- | ------ | ---------- |
| CONTENT_TYPE_UNKNOWN               | 0      | 未知类型。 |
| CONTENT_TYPE_SPEECH                | 1      | 语音。     |
| CONTENT_TYPE_MUSIC                 | 2      | 音乐。     |
| CONTENT_TYPE_MOVIE                 | 3      | 电影。     |
| CONTENT_TYPE_SONIFICATION          | 4      | 通知音。   |
| CONTENT_TYPE_RINGTONE<sup>8+</sup> | 5      | 铃声。     |

## ActiveDeviceType<sup>(deprecated)</sup>

表示活跃设备类型的枚举。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[CommunicationDeviceType](#communicationdevicetype9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称          |  值     | 说明                                                 |
| ------------- | ------ | ---------------------------------------------------- |
| SPEAKER       | 2      | 扬声器。                                             |
| BLUETOOTH_SCO | 7      | 蓝牙设备SCO（Synchronous Connection Oriented）连接。 |

## InterruptActionType<sup>(deprecated)</sup>

表示中断事件返回类型的枚举。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，无替代接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称           |  值     | 说明               |
| -------------- | ------ | ------------------ |
| TYPE_ACTIVATED | 0      | 表示触发焦点事件。 |
| TYPE_INTERRUPT | 1      | 表示音频打断事件。 |

## AudioLoopbackMode<sup>20+</sup>

表示返听模式的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称           | 值     | 说明              |
| -------------- | ------ | ----------------- |
| HARDWARE       | 0      | 表示硬件返听模式。 |

## AudioLoopbackStatus<sup>20+</sup>

表示返听状态的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称               | 值     | 说明             |
| ------------------ | ------ | ---------------- |
| UNAVAILABLE_DEVICE | -2     | 表示返听由于输入\输出设备而不可用（如出声设备变更）。    |
| UNAVAILABLE_SCENE  | -1     | 表示返听由于音频场景而不可用（如音频焦点、低时延管控）。 |
| AVAILABLE_IDLE     |  0     | 表示返听可用。     |
| AVAILABLE_RUNNING  |  1     | 表示返听运行中。   |

## AudioLoopbackReverbPreset<sup>21+</sup>

表示返听混响模式的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称      | 值     | 说明             |
| --------- | ------ | ---------------- |
| ORIGINAL  | 1     | 保持原始混响，不进行任何增强。   |
| KTV       | 2     | 提供类似KTV的混响效果。 |
| THEATER   | 3     | 提供类似剧场的混响效果（默认的混响模式）。 |
| CONCERT   | 4     | 提供类似演唱会的混响效果。   |

## AudioLoopbackEqualizerPreset<sup>21+</sup>

表示返听均衡器类型的枚举。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称      | 值     | 说明             |
| --------- | ------ | ---------------- |
| FLAT   | 1     | 保持原始声音，不进行均衡调节。|
| FULL   | 2     | 使人声更饱满（默认的均衡器类型）。|
| BRIGHT | 3     | 使人声更明亮。|