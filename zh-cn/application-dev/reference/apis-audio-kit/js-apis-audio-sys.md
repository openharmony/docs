# @ohos.multimedia.audio (音频管理)(系统接口)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

音频管理提供管理音频的一些基础能力，包括对音频音量、音频设备的管理，以及对音频数据的采集和渲染等。

该模块提供以下音频相关的常用功能：

- [AudioManager](#audiomanager)：音频管理。
- [TonePlayer](#toneplayer9)：用于管理和播放DTMF（Dual Tone Multi Frequency，双音多频）音调，如拨号音、通话回铃音等。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.audio (音频管理)](arkts-apis-audio.md)。

## 导入模块

```ts
import { audio } from '@kit.AudioKit';
```

## 常量

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                                    | 类型      | 只读 | 说明               |
| --------------------------------------- | ----------| ---- | ------------------ |
| LOCAL_NETWORK_ID<sup>9+</sup>           | string    | 是 | 本地设备网络id。 |

## audio.createTonePlayer<sup>9+</sup>

createTonePlayer(options: AudioRendererInfo, callback: AsyncCallback&lt;TonePlayer&gt;): void

创建DTMF播放器。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                                             | 必填 | 说明            |
| -------- | ----------------------------------------------- | ---- | -------------- |
| options  | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)        | 是   | 配置音频渲染器信息。|
| callback | AsyncCallback<[TonePlayer](#toneplayer9)>       | 是   | 回调函数。当获取DTMF播放器成功，err为undefined，data为获取到的DTMF播放器对象；否则为错误对象。|

**示例：**

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

创建DTMF播放器。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名  | 类型                                           | 必填 | 说明         |
| :------ | :---------------------------------------------| :--- | :----------- |
| options | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)      | 是   | 配置音频渲染器信息。 |

**返回值：**

| 类型                                      | 说明                             |
| ----------------------------------------- | -------------------------------- |
| Promise<[TonePlayer](#toneplayer9)>       | Promise对象，返回DTMF播放器对象。 |

**示例：**

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

获取自动语音识别（ASR）处理控制器。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名  | 类型                                           | 必填 | 说明       |
| :------ | :---------------------------------------------| :--- |:---------|
| audioCapturer | [AudioCapturer](arkts-apis-audio-AudioCapturer.md)      | 是   | 音频采集器对象。 |

**返回值：**

| 类型                                                    | 说明         |
|-------------------------------------------------------| ------------ |
| [AsrProcessingController](#asrprocessingcontroller12) | ASR处理控制器对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed. e.g. the source type of the input audio capturer is not [SOURCE_TYPE_VOICE_RECOGNITION](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8) or [SOURCE_TYPE_WAKEUP](#sourcetype8),<br>or this audio capturer is already released.|

**示例：**

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

枚举，音频流类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| SYSTEM<sup>20+</sup>         | 6      | 系统音。|
| ULTRASONIC<sup>10+</sup>     | 10     | 超声波。|
| NOTIFICATION<sup>20+</sup>     | 11     | 通知音。|
| NAVIGATION<sup>20+</sup>     | 12     | 导航。|
| ALL<sup>9+</sup>             | 100    | 所有公共音频流。|

## InterruptRequestResultType<sup>9+</sup>

枚举，音频中断请求结果类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| INTERRUPT_REQUEST_GRANT      | 0      | 请求音频中断成功。 |
| INTERRUPT_REQUEST_REJECT     | 1      | 请求音频中断失败，可能具有较高优先级类型。 |

## DeviceFlag

枚举，可获取的设备种类。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                            |  值     | 说明                        |
| ------------------------------- | ------ |---------------------------|
| NONE_DEVICES_FLAG<sup>9+</sup>  | 0      | 无设备。 |
| DISTRIBUTED_OUTPUT_DEVICES_FLAG<sup>9+</sup> | 4   | 分布式输出设备。 |
| DISTRIBUTED_INPUT_DEVICES_FLAG<sup>9+</sup>  | 8   | 分布式输入设备。 |
| ALL_DISTRIBUTED_DEVICES_FLAG<sup>9+</sup>    | 12  | 分布式输入和输出设备。 |

## EffectFlag<sup>18+</sup>

枚举，音效分类。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                            |  值     | 说明                        |
| ------------------------------- | ------ |------------------------------|
| RENDER_EFFECT_FLAG  | 0      | 下行音效类型。   |
| CAPTURE_EFFECT_FLAG | 1      | 上行音效类型。   |

## AudioEffectProperty<sup>18+</sup>

音效属性。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称               | 类型 | 只读 | 可选 | 说明       |
| ------------------ | ---- | ---- |---| --------- |
| name         | string | 否 | 否 | 音效名称。 |
| category     | string | 否 | 否 | 音效分类。 |
| flag        | [EffectFlag](#effectflag18) | 否 | 否 | 音效分类。 |

## AudioSeparationVolumeType

表示音频分离效果的音量类型。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称 | 值 | 说明 |
| --- | --- | --- |
| VOLUME_TYPE_VOCAL | 0 | 人声音量类型。 |

## StreamUsage

枚举，音频流使用类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                      |  值    | 说明                          |
| ------------------------------------------| ------ |-----------------------------|
| STREAM_USAGE_SYSTEM<sup>10+</sup>         | 9      | 系统音(如屏幕锁定或按键音)。 |
| STREAM_USAGE_DTMF<sup>10+</sup>           | 14     | 拨号音。 |
| STREAM_USAGE_ENFORCED_TONE<sup>10+</sup>  | 15     | 强制音(如相机快门音)。 |
| STREAM_USAGE_ULTRASONIC<sup>10+</sup>     | 16     | 超声波（目前仅提供给MSDP使用）。 |
| STREAM_USAGE_VOICE_CALL_ASSISTANT<sup>12+</sup>     | 21     | 通话辅助语音。 |
| STREAM_USAGE_ANNOUNCEMENT<sup>24+</sup>   | 22     | 通知音。<br>**模型约束：** 此接口仅可在Stage模型下使用。|
| STREAM_USAGE_EMERGENCY<sup>24+</sup>      | 23     | 告警音。<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## InterruptRequestType<sup>9+</sup>

枚举，音频中断请求类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| INTERRUPT_REQUEST_TYPE_DEFAULT     | 0      |  默认类型，可中断音频请求。  |

## VolumeFlag<sup>12+</sup>

枚举，音量相关操作。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                               | 值 | 说明       |
| ---------------------------------- |---|----------|
| FLAG_SHOW_SYSTEM_UI | 1 | 拉起系统音量条。 |

## AsrNoiseSuppressionMode<sup>12+</sup>

枚举，自动语音识别（ASR）的噪音抑制模式。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称|  值 | 说明 |
|-------|-------|-------|
| BYPASS | 0 |旁路噪音抑制。|
| STANDARD | 1 |标准噪音抑制。|
| NEAR_FIELD | 2 |近场噪音抑制。|
| FAR_FIELD | 3 |远场噪音抑制。|

## AsrAecMode<sup>12+</sup>

枚举，自动语音识别（ASR）的声学回声消除（AEC）模式。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称|  值 | 说明 |
|-------|-------|-------|
| BYPASS | 0 |不使用AEC。|
| STANDARD | 1 |使用标准AEC。|

## AsrWhisperDetectionMode<sup>12+</sup>

枚举，自动语音识别（ASR）的耳语检测模式。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称  | 值 | 说明       |
|-----|---|----------|
| BYPASS  | 0 | 不启用检测模型。 |
| STANDARD | 1 | 耳语检测模型。  |

## AsrVoiceControlMode<sup>12+</sup>

枚举，自动语音识别（ASR）的音频通路模式。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称                      | 值 | 说明                                    |
|-------------------------|---|---------------------------------------|
| AUDIO_2_VOICE_TX        | 0 | 仅媒体音频流生效。                            |
| AUDIO_MIX_2_VOICE_TX    | 1 | 媒体音频流和MIC音频流均生效。                      |
| AUDIO_2_VOICE_TX_EX     | 2 | 仅媒体音频流生效，将媒体流上报给通话录音。     |
| AUDIO_MIX_2_VOICE_TX_EX | 3 | 媒体音频流和MIC音频流均生效，将媒体流上报给通话录音。 |

## AsrVoiceMuteMode<sup>12+</sup>

枚举，自动语音识别（ASR）的静音模式。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称             | 值 | 说明                  |
|----------------|---|---------------------|
| OUTPUT_MUTE    | 0 | 本地输出静音。            |
| INPUT_MUTE     | 1 | 本地的MIC输入静音。        |
| TTS_MUTE       | 2 | 应用下发的媒体音频本地静音。     |
| CALL_MUTE      | 3 | 通话语音流静音。          |
| OUTPUT_MUTE_EX | 4 | 本地输出静音，媒体音频流送给通话录音。 |

## InterruptResult<sup>9+</sup>

音频中断结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

| 名称          | 类型                                                            | 只读 | 可选 | 说明             |
| --------------| -------------------------------------------------------------- | ---- |---| ---------------- |
| requestResult | [InterruptRequestResultType](#interruptrequestresulttype9)     | 否 | 否 | 表示音频请求中断类型。 |
| interruptNode | number                                                         | 否 | 否 | 音频请求中断的节点。 |

## VolumeEvent<sup>9+</sup>

音量改变时，应用接收的事件。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称       | 类型                                | 只读 | 可选 | 说明                                        |
| ---------- | ----------------------------------- | ---- |---|-------------------------------------------|
| volumeGroupId | number                           | 否 | 否 | 音量组id，可用于getGroupManager入参。 |
| networkId  | string                              | 否 | 否 | 网络id。 |
| percentage<sup>23+</sup> | number | 否 | 是 | 音量百分比，取值范围为[0, 100]。|

## ConnectType<sup>9+</sup>

枚举，设备连接类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                            |  值     | 说明                   |
| :------------------------------ | :----- | :--------------------- |
| CONNECT_TYPE_LOCAL              | 1      | 本地设备。         |
| CONNECT_TYPE_DISTRIBUTED        | 2      | 分布式设备。            |

## VolumeGroupInfos<sup>9+</sup>

音量组信息，数组类型，为[VolumeGroupInfo](#volumegroupinfo9)的数组，只读。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

## VolumeGroupInfo<sup>9+</sup>

音量组信息。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                        | 类型                       | 只读 | 可选 | 说明       |
| -------------------------- | -------------------------- | ---- | ---- | ---------- |
| networkId | string                     | 是   | 否   | 组网络id。  |
| groupId | number                     | 是   | 否   | 组设备组id。 |
| mappingId | number                     | 是   | 否   | 组映射id。 |
| groupName | string                     | 是   | 否   | 组名。 |
| type | [ConnectType](#connecttype9)| 是   | 否   | 连接设备类型。 |

## SourceType<sup>8+</sup>

枚举，音源类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                         |  值     | 说明                   |
| :------------------------------------------- | :----- | :--------------------- |
| SOURCE_TYPE_WAKEUP <sup>10+</sup>            | 3 | 语音唤醒音频流录制音频源。<br/>**需要权限：** ohos.permission.MANAGE_INTELLIGENT_VOICE |
| SOURCE_TYPE_VOICE_CALL<sup>11+</sup>            | 4 | 通话录音的音频源。<br/>**需要权限：** ohos.permission.RECORD_VOICE_CALL |
| SOURCE_TYPE_VOICE_TRANSCRIPTION<sup>18+</sup>   | 12     | 语音转写音频源。 |
| SOURCE_TYPE_UNPROCESSED_VOICE_ASSISTANT<sup>23+</sup>   | 19     | 未处理的语音助手音频源。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## AudioCapturerMicInConfig<sup>23+</sup>

音频采集器选项信息，可采集未经任何处理的麦克风输入（mic-in）音频数据。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称                                | 类型                                                      | 只读 | 可选 | 说明                                                         |
| ----------------------------------- | --------------------------------------------------------- | ---- |---| ------------------------------------------------------------ |
| processedStreamInfo<sup>24+</sup> | [AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8) | 否 | 是 | 处理后的音频流信息。 |
| micInStreamInfo                          | [AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8)                      | 否 | 否 | 麦克风音频流信息。   |
| capturerInfo                        | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8)                   | 否 | 否 | 音频采集器信息。         |
| ecStreamInfo | [AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8) | 否 | 是 | 回声消除音频流信息。<br>若未设置此属性，采集器将仅录制麦克风输入的音频流。    |
| preferredInputDevice | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 否 | 是 | 当前音频录音器的偏好输入设备。对于该设备有以下要求：<br/><ul><li>此设备必须为输入设备，并且<strong>capturerInfo</strong>中的源类型必须为[SOURCE_TYPE_VOICE_RECOGNITION](arkts-apis-audio-e.md#sourcetype8)或[SOURCE_TYPE_VOICE_TRANSCRIPTION](#sourcetype8)，否则此参数将被忽略。</li><li>如果用户未指定设备，系统会按当前音频路由策略自动选择可用输入设备。</li><li>当用户指定偏好设备时：<ul><li>如果偏好设备在线，当前音频录音器使用该设备录音；如果录音过程中该设备离线，系统会按当前音频路由策略自动选择其他可用输入设备。</li><li>如果偏好设备离线，系统会按当前音频路由策略自动选择其他可用输入设备；如果录音过程中该设备上线，系统会自动切换到偏好设备。</li></ul></li></ul>用户可通过[getCurrentAudioCapturerChangeInfo](arkts-apis-audio-AudioCapturer.md#getcurrentaudiocapturerchangeinfo11)查询当前实际使用的设备。<br/>**起始版本：** 26.0.0 |

## AudioCapturerMicInData<sup>24+</sup>

音频采集器数据，包含处理后的音频数据和未经任何处理的麦克风输入（mic-in）音频数据。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ----------------------------------- | --------------------------------------------------------- | ---- |---| ------------------------------------------------------------ |
| data | ArrayBuffer | 否 | 否 | 处理后的音频数据缓冲区。 |
| micInData | ArrayBuffer | 否 | 否 | 麦克风输入音频数据缓冲区。 |
| ecData | ArrayBuffer | 否 | 是 | 回声参考音频数据缓冲区。<br>如果采集器配置未设置ecStreamInfo，则该字段为空，详情请参考[AudioCapturerMicInConfig](#audiocapturermicinconfig23)。 |

## VolumeAdjustType<sup>10+</sup>

枚举，音量调节类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                   |  值     | 说明                                          |
| :--------------------- | :----- | :-------------------------------------------- |
| VOLUME_UP              | 0      | 向上调节音量。 |
| VOLUME_DOWN            | 1      | 向下调节音量。 |

## DeviceType

表示设备类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                         | 值     | 说明                              |
|----------------------------| ------ |---------------------------------|
| ACCESSORY<sup>19+</sup> | 26 | 辅助设备（例如遥控器上的麦克风等）。 |
| BLUETOOTH_SPP<sup>22+</sup> | 33 | 蓝牙设备SPP（Serial Port Profile）连接。 |
| NEARLINK_PORT<sup>22+</sup> | 34 | 星闪设备PORT连接。                     |

## AudioDevcieSelectStrategy<sup>21+</sup>

表示设备选择策略的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                         | 值     | 说明                              |
|----------------------------| ------ |---------------------------------|
| SELECT_STRATEGY_DEFAULT | 0 | 默认设备选择策略。 |
| SELECT_STRATEGY_INDEPENDENT | 1 | 独立设备选择策略。 | 

## PolicyType<sup>12+</sup>

表示静音策略类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                         | 值     | 说明                              |
|----------------------------| ------ |---------------------------------|
| EDM | 0 | 设备管理器下发的静音策略。 |
| PRIVACY | 1 | 安全隐私模块下发的静音策略。 | 

## AudioCapturerOptions<sup>8+</sup>

音频采集器选项信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称                                | 类型                                                                   | 只读 | 可选 | 说明                                                                                                                                                                                                        |
| ----------------------------------- |----------------------------------------------------------------------| ---- |---|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| preferredInputDevice<sup>22+</sup> | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 否 | 是 | 当前音频采集器的偏好输入设备。<br/>此设备必须为输入设备，并且capturerInfo的source type必须为[SOURCE_TYPE_VOICE_RECOGNITION](arkts-apis-audio-e.md#sourcetype8)或[SOURCE_TYPE_VOICE_TRANSCRIPTION](#sourcetype8)。否则，此参数将会被忽略。<br/>1. 当调用者未指定偏好设备时，系统会自动选择一个设备。<br/>2. 当调用者指定了偏好设备创建语音识别或者语音转写流时：<br/>（1）设备在线，当前audiocapturer会使用偏好设备；如果运行过程中，偏好设备下线，系统会自动选择一个录音设备。<br/>（2）设备不在线，当前audiocapturer会自动选择一个录音设备；如果运行过程中，偏好设备上线，系统会自动切换到偏好设备上。<br/>3. 调用者可以通过[getCurrentAudioCapturerChangeInfo](arkts-apis-audio-AudioCapturer.md#getcurrentaudiocapturerchangeinfo11)查询当前实际使用的录音设备。 |

                                                                                                  

## AudioManager

管理音频音量和音频设备。在调用AudioManager的接口前，需要先通过[getAudioManager](arkts-apis-audio-f.md#audiogetaudiomanager)创建实例。

### setExtraParameters<sup>11+</sup>

setExtraParameters(mainKey: string, kvpairs: Record<string, string\>): Promise&lt;void&gt;

音频扩展参数设置。使用Promise异步回调。

**需要权限：** ohos.permission.MODIFY_AUDIO_SETTINGS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| mainKey | string | 是   | 被设置的音频参数的主键。 |
| kvpairs | Record<string, string\> | 是   | 被设置的音频参数的子键值对。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息                                                                                                       |
|-----|------------------------------------------------------------------------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

获取指定音频参数值。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ |--| ---------------------- |
| mainKey | string | 是 | 待获取的音频参数的主键。 |
| subKeys | Array\<string> | 否 | 待获取的音频参数的子键。 |

**返回值：**

| 类型                  | 说明                                |
| --------------------- | ----------------------------------- |
| Promise\<Record\<string, string>> | Promise对象，返回获取的音频参数的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------ | -------------------------|
| 202 | Not system App. |
|  401  | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

设置音频场景模式。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                 |
| :------- | :----------------------------------- | :--- | :------------------- |
| scene    | [AudioScene](arkts-apis-audio-e.md#audioscene8) | 是   | 音频场景模式。       |
| callback | AsyncCallback<void\>                 | 是   | 回调函数。当设置音频场景模式成功，err为undefined，否则为错误对象。 |

**示例：**

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

设置音频场景模式。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名 | 类型                                 | 必填 | 说明           |
| :----- | :----------------------------------- | :--- | :------------- |
| scene  | [AudioScene](arkts-apis-audio-e.md#audioscene8) | 是   | 音频场景模式。 |

**返回值：**

| 类型           | 说明                 |
| :------------- | :------------------- |
| Promise<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

获取音效会话管理器。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                                           | 说明                          |
|----------------------------------------------| ----------------------------- |
| [AudioEffectManager](#audioeffectmanager18) | AudioEffectManager实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let audioEffectManager: audio.AudioEffectManager = audioManager.getEffectManager();
```

### disableSafeMediaVolume<sup>12+</sup>

disableSafeMediaVolume(): Promise&lt;void&gt;

设置安全音量为非激活状态。使用Promise异步回调。

设置为非激活状态后，当设备长时间高音量播放时，不再自动提醒用户降低到安全音量。

**需要权限：** ohos.permission.MODIFY_AUDIO_SETTINGS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                                       | 说明                          |
|------------------------------------------| ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |

**示例：**

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

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeManager中的[on('volumeChange')](arkts-apis-audio-AudioVolumeManager.md#onvolumechangedeprecated)替代。

监听系统音量变化事件（当系统音量发生变化时触发）。使用callback异步回调。

目前此订阅接口在单进程多AudioManager实例的使用场景下，仅最后一个实例的订阅生效，其他实例的订阅会被覆盖（即使最后一个实例没有进行订阅），因此推荐使用单一AudioManager实例进行开发。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'volumeChange'，当系统音量发生变化时，触发该事件。 |
| callback | Callback<[VolumeEvent](#volumeevent9)> | 是   | 回调函数，返回变化后的音量信息。 |

**示例：**

```ts
audioManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### on('ringerModeChange')<sup>(deprecated)</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

监听铃声模式变化事件（当[铃声模式](arkts-apis-audio-e.md#audioringmode)发生改变时触发）。使用callback异步回调。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[on('ringerModeChange')](arkts-apis-audio-AudioVolumeGroupManager.md#onringermodechange9)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | 是   | 事件回调类型，支持的事件为'ringerModeChange'，当铃声模式发生改变时，触发该事件。 |
| callback | Callback<[AudioRingMode](arkts-apis-audio-e.md#audioringmode)> | 是   | 回调函数，返回变化后的铃音模式。                                                   |

**示例：**

```ts
audioManager.on('ringerModeChange', (ringerMode: audio.AudioRingMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
});
```

## AudioVolumeManager<sup>9+</sup>

音量管理。在使用AudioVolumeManager的接口前，需要使用[getVolumeManager](arkts-apis-audio-AudioManager.md#getvolumemanager9)获取AudioVolumeManager实例。

### getVolumeGroupInfos<sup>9+</sup>

getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos\>\): void

获取音量组信息列表。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| networkId | string                                    | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。    |
| callback  | AsyncCallback&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | 是   | 回调函数。当获取音量组信息列表成功，err为undefined，data为获取到的音量组信息列表；否则为错误对象。 |

**示例：**
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

获取音量组信息列表。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型               | 必填 | 说明                 |
| ---------- | ------------------| ---- | -------------------- |
| networkId | string             | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。   |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | Promise对象，返回音量组信息列表。 |

**示例：**

```ts
async function getVolumeGroupInfos(){
  let volumegroupinfos: audio.VolumeGroupInfos = await audio.getAudioManager().getVolumeManager().getVolumeGroupInfos(audio.LOCAL_NETWORK_ID);
  console.info('Promise returned to indicate that the volumeGroup list is obtained.'+JSON.stringify(volumegroupinfos))
}
```

### getVolumeGroupInfosSync<sup>10+</sup>

getVolumeGroupInfosSync(networkId: string\): VolumeGroupInfos

获取音量组信息列表，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型               | 必填 | 说明                 |
| ---------- | ------------------| ---- | -------------------- |
| networkId | string             | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。   |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| [VolumeGroupInfos](#volumegroupinfos9) | 音量组信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

根据应用ID获取指定应用的音量百分比（范围为0到100）。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                               |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| uid    | number                                   | 是   | 表示应用ID。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise对象，返回应用的音量百分比，范围为[0, 100]。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed.|

**示例：**

```ts
let uid: number = 20010041; // 应用ID。

audioVolumeManager.getAppVolumePercentageForUid(20010041).then((value: number) => {
  console.info(`app volume is ${value}.`);
});
```

### setAppVolumePercentageForUid<sup>19+</sup>

setAppVolumePercentageForUid(uid: number, volume: number\): Promise<void\>

根据应用ID设置指定应用的音量百分比（范围为[0, 100]）。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明       |
| ---------- | ---------------------------------------- | ---- |----------|
| uid    | number                                   | 是   | 表示应用ID。   |
| volume    | number                                   | 是   | 要设置的音量百分比，范围为[0, 100]。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed.|
| 6800301 | Crash or blocking occurs in system process. |

**示例：**

```ts
let uid: number = 20010041; // 应用ID。
let volume: number = 20;    // 要设置的音量值。

audioVolumeManager.setAppVolumePercentageForUid(uid, volume).then(() => {
  console.info(`set app volume success.`);
});
```

### forceVolumeKeyControlType<sup>20+</sup>

forceVolumeKeyControlType(volumeType: AudioVolumeType, duration: number): void

设置音量键调节类型。

**需要权限：** ohos.permission.MODIFY_AUDIO_SETTINGS

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| volumeType     | [AudioVolumeType](#audiovolumetype)                       | 是   | 应用程序期望控制的音频音量类型。 |
| duration |number | 是   | 无音量键事件时，控制音量类型的持续时间，单位为秒（s）。<br>当计时器到期时，强制音量类型设置将被取消，最大持续时间不得超过10秒。<br>如果持续时间设置为-1，则取消该设置。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |
| 6800301  | Crash or blocking occurs in system process. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();

// 设置音量保持类型为响铃模式。
let volumeType = audio.AudioVolumeType.RINGTONE;
let duration = 10;
audioVolumeManager.forceVolumeKeyControlType(volumeType, duration);

// 取消音量保持类型，恢复默认音量控制。
let volumeTypeDefault = audio.AudioVolumeType.MEDIA;
let durationToCancel = -1;
audioVolumeManager.forceVolumeKeyControlType(volumeTypeDefault, durationToCancel);
```

### setSystemVolumePercentage<sup>23+</sup>

setSystemVolumePercentage(volumeType: AudioVolumeType, percentage: number): Promise&lt;void&gt;

设置指定流的音量百分比。使用Promise异步回调。

> **说明：**
>
> - 设置指定流的音量百分比时需要使用整数，范围从最小系统音量百分比到100。
> - 音量百分比与音量等级相对应，每个等级对应特定的百分比。
> - 当音量等级发生变化时，音量百分比会相应调整，并映射在音量等级的范围内。
> - 0等级音量映射为0%，最大音量映射为100%。中间音量等级均匀分布在1至99之间。
> - 当音量百分比变化时，音量等级会相应调整。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音量流类型。                                             |
| percentage | number | 是   | 音量百分比，可设置范围的最小值是通过[getMinSystemVolumePercentage](#getminsystemvolumepercentage23)接口获取到的音量百分比， 最大值是100。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; |Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed, including volumeType or percentage param begin out of range. |
| 6800301 | Crash or blocking occurs in system process. |

**示例：**

```ts
audioVolumeManager.setSystemVolumePercentage(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### getSystemVolumePercentage<sup>23+</sup>

getSystemVolumePercentage(volumeType: AudioVolumeType): number

获取指定流的音量百分比。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音量流类型。       |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| number | 音量百分比，取值范围为[0, 100]。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
try {
  let volume = audioVolumeManager.getSystemVolumePercentage(audio.AudioVolumeType.MEDIA);
  console.info(`MEDIA volume percentage obtained success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume percentage, error: ${error}`);
}
```

### getMinSystemVolumePercentage<sup>23+</sup>

getMinSystemVolumePercentage(volumeType: AudioVolumeType): number

获取指定流的最小音量百分比。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| number | 音量百分比，取值范围为[0, 100]。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
try {
  let volume = audioVolumeManager.getMinSystemVolumePercentage(audio.AudioVolumeType.MEDIA);
  console.info(`MEDIA volume percentage obtained success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume percentage, error: ${error}`);
}
```

### isAppVolumeMutedForUid<sup>19+</sup>

isAppVolumeMutedForUid(uid: number, owned: boolean\): Promise<boolean\>

根据应用ID查询应用音量是否已静音。使用Promise异步回调。

> **说明：**
>
> 如果有多个调用者设置了静音状态，那么只有当所有调用者都取消静音状态后，此应用才会真正取消静音。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                                        |
| ---------- | ---------------------------------------- | ---- |-------------------------------------------|
| uid    | number                                   | 是   | 表示应用ID。                                    |
| owned    | boolean                                   | 是   | 要查询的静音状态。true查询当前调用者的静音状态，false查询应用的静音状态。 |

**返回值：**

| 类型                | 说明                  |
| ------------------- |---------------------|
| Promise&lt;boolean&gt; | Promise对象。返回true表示应用为静音状态；返回false表示应用为非静音状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|

**示例：**

```ts
let uid: number = 20010041; // 应用ID。

audioVolumeManager.isAppVolumeMutedForUid(uid, true).then((value: boolean) => {
  console.info(`app muted state is ${value}.`);
});
```

### setAppVolumeMutedForUid<sup>19+</sup>

setAppVolumeMutedForUid(uid: number, muted: boolean\): Promise<void\>

根据应用ID设置应用静音状态。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                             |
| ---------- | ---------------------------------------- | ---- |--------------------------------|
| uid    | number                                   | 是   | 表示应用ID。                         |
| muted    | boolean                                   | 是   | 设置应用的静音状态。true设置为静音，false解除静音。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed.|
| 6800301 | Crash or blocking occurs in system process. |

**示例：**

```ts
let uid: number = 20010041; // 应用ID。

audioVolumeManager.setAppVolumeMutedForUid(uid, true).then(() => {
  console.info(`set app mute state success.`);
});
```

### on('appVolumeChangeForUid')<sup>19+</sup>

on(type: 'appVolumeChangeForUid', uid: number, callback: Callback\<VolumeEvent>): void

监听指定应用应用级音量变化事件（当应用级音量发生变化时触发）。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                |
| -------- | -------------------------------------- | ---- |-----------------------------------|
| type     | string                                 | 是   | 事件回调类型，支持的事件为'appVolumeChangeForUid'，当应用级音量发生变化时，触发该事件。 |
| uid | number |  是   | 表示应用ID。                          |
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 是   | 回调函数，返回变化后的音量信息。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
let uid: number = 20010041; // 应用ID。

audioVolumeManager.on('appVolumeChangeForUid', uid, (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### off('appVolumeChangeForUid')<sup>19+</sup>

off(type: 'appVolumeChangeForUid', callback?: Callback\<VolumeEvent>): void

取消监听指定应用应用级音量变化事件。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'appVolumeChangeForUid'，当取消监听指定应用应用级音量变化事件时，触发该事件。 |
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 否   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeManager.off('appVolumeChangeForUid');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
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

监听当前活跃流变化事件（当活跃流发生变化时触发）。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'activeVolumeTypeChange'，当活跃流发生变化时，触发该事件。 |
| callback | Callback\<[AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype)> | 是   | 回调函数，返回变化后的活跃音频音量类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeManager.on('activeVolumeTypeChange', (volumeType: audio.AudioVolumeType) => {
  console.info(`VolumeType of stream: ${volumeType} `);
});
```

### off('activeVolumeTypeChange')<sup>20+</sup>

off(type: 'activeVolumeTypeChange', callback?: Callback\<AudioVolumeType>): void

取消监听当前活跃流变化事件。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'activeVolumeTypeChange'，当取消监听当前活跃流变化事件时，触发该事件。 |
| callback | Callback\<[AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype)> | 否   | 回调函数，返回变化后的活跃音频音量类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeManager.off('activeVolumeTypeChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let activeVolumeTypeChangeCallback = (volumeType: audio.AudioVolumeType) => {
  console.info(`VolumeType of stream: ${volumeType} `);
};

audioVolumeManager.on('activeVolumeTypeChange', activeVolumeTypeChangeCallback);

audioVolumeManager.off('activeVolumeTypeChange', activeVolumeTypeChangeCallback);
```

### on('systemVolumeChange')<sup>20+</sup>

on(type: 'systemVolumeChange', callback: Callback\<VolumeEvent>): void

监听系统音量变化事件（当系统音量发生变化时触发）。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'systemVolumeChange'，当系统音量发生变化时，触发该事件。 |
| callback | Callback\<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 是   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeManager.on('systemVolumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`Succeeded in using on function, VolumeEvent: ${volumeEvent}.`);
});
```

### off('systemVolumeChange')<sup>20+</sup>

off(type: 'systemVolumeChange', callback?: Callback\<VolumeEvent>): void

取消监听系统音量变化事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'systemVolumeChange'，当取消监听系统音量变化事件时，触发该事件。 |
| callback | Callback\<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 否   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeManager.off('systemVolumeChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let systemVolumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`Succeeded in using on or off function, VolumeEvent: ${volumeEvent}.`);
};

audioVolumeManager.on('systemVolumeChange', systemVolumeChangeCallback);

audioVolumeManager.off('systemVolumeChange', systemVolumeChangeCallback);
```

### onVolumePercentageChange<sup>23+</sup>

onVolumePercentageChange(callback: Callback\<VolumeEvent>): void

监听系统音量百分比变化事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 是   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
onVolumePercentageChange((volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Volume percentage: ${volumeEvent.percentage} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### offVolumePercentageChange<sup>23+</sup>

offVolumePercentageChange(callback?: Callback\<VolumeEvent>): void

取消监听系统音量变化事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 否   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeManager.offVolumePercentageChange();

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let volumePercentageChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Volume percentage: ${volumeEvent.percentage} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};

audioVolumeManager.onVolumePercentageChange(volumePercentageChangeCallback);

audioVolumeManager.offVolumePercentageChange(volumePercentageChangeCallback);
```

## AudioVolumeGroupManager<sup>9+</sup>

管理音频组音量。在调用AudioVolumeGroupManager的接口前，需要先通过 [getVolumeGroupManager](arkts-apis-audio-AudioVolumeManager.md#getvolumegroupmanager9) 创建实例。

### setVolume<sup>9+</sup>

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

设置指定流的音量。使用callback异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频音量类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过[getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated)和[getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated)获取。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当设置指定流的音量成功，err为undefined，否则为错误对象。 |

**示例：**

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

设置指定流的音量。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频音量类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过[getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated)和[getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated)获取。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
audioVolumeGroupManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### setVolumeWithFlag<sup>12+</sup>

setVolumeWithFlag(volumeType: AudioVolumeType, volume: number, flags: number): Promise&lt;void&gt;

设置指定流的音量，同时指定本次修改音量是否要显示系统音量条。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                   |
| ---------- | ----------------------------------- | ---- |--------------------------------------|
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频音量类型。                               |
| volume     | number                              | 是   | 音量等级，可设置范围通过[getMinVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getminvolumedeprecated)和[getMaxVolume](arkts-apis-audio-AudioVolumeGroupManager.md#getmaxvolumedeprecated)获取。 |
| flags      | number                              | 是   | 是否需要显示系统音量条，0为不需要显示，1为需要显示。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |

**示例：**

```ts
audioVolumeGroupManager.setVolumeWithFlag(audio.AudioVolumeType.MEDIA, 10, 1).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### getActiveVolumeTypeSync<sup>13+</sup>

getActiveVolumeTypeSync(uid: number): AudioVolumeType

查询指定应用活跃的音频音量类型；如果将uid传入为0，则查询的是全局范围内活跃的音频音量类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                   |
| ---------- | ----------------------------------- | ---- |--------------------------------------|
| uid      | number                              | 是   | 应用ID。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| [AudioVolumeType](#audiovolumetype) | 音频音量类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters unspecified. 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
let uid: number = 20010041; // 应用ID。

let value = audioVolumeGroupManager.getActiveVolumeTypeSync(uid);
```

### mute<sup>9+</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定音量流静音。使用callback异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频音量类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当设置指定音量流静音成功，err为undefined，否则为错误对象。 |

**示例：**

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

设置指定音量流静音。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频音量类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
audioVolumeGroupManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
  console.info('Promise returned to indicate that the stream is muted.');
});
```

### setRingerMode<sup>9+</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

设置铃声模式。使用callback异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | 是   | 音频铃声模式。           |
| callback | AsyncCallback&lt;void&gt;       | 是   | 回调函数。当设置铃声模式成功，err为undefined，否则为错误对象。 |

**示例：**

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

设置铃声模式。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | 是   | 音频铃声模式。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
audioVolumeGroupManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
  console.info('Promise returned to indicate a successful setting of the ringer mode.');
});
```

### setMicMute<sup>11+</sup>

setMicMute(mute: boolean): Promise&lt;void&gt;

设置麦克风静音状态。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型    | 必填 | 说明                                          |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | 是   | 待设置的静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeGroupManager.setMicMute(true).then(() => {
  console.info('Promise returned to indicate that the mic is muted.');
});
```

### setMicMutePersistent<sup>12+</sup>

setMicMutePersistent(mute: boolean, type: PolicyType): Promise&lt;void&gt;

设置麦克风持久化静音状态。使用Promise异步回调。

**需要权限：** ohos.permission.MICROPHONE_CONTROL

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型    | 必填 | 说明                                          |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | 是   | 待设置的静音状态，true为静音，false为非静音。 |
| type   | [PolicyType](#policytype12) | 是   | 静音策略类型。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters missing. 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeGroupManager.setMicMutePersistent(true, audio.PolicyType.PRIVACY).then(() => {
  console.info('Succeeded in setting mic mute.');
});
```

### isPersistentMicMute<sup>12+</sup>

isPersistentMicMute(): boolean

获取麦克风持久化静音状态。同步返回结果。

**需要权限：** ohos.permission.MICROPHONE_CONTROL

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| boolean | 麦克风是否处于静音状态。true表示处于静音状态，false表示处于未静音状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |

**示例：**

```ts
let value: boolean = audioVolumeGroupManager.isPersistentMicMute();
```

### adjustVolumeByStep<sup>10+</sup>

adjustVolumeByStep(adjustType: VolumeAdjustType, callback: AsyncCallback&lt;void&gt;): void

调节当前最高优先级的流的音量，使音量值按步长加或减。使用callback异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                             |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当调节当前最高优先级的流的音量成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**示例：**

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

单步设置当前最高优先级的流的音量。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                             |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**示例：**

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

单步设置指定流的音量。使用callback异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频音量类型。                                             |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                       |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调函数。当单步设置指定流的音量成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**示例：**

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

单步设置指定流的音量。使用Promise异步回调。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频音量类型。                                             |
| adjustType | [VolumeAdjustType](#volumeadjusttype10) | 是   | 音量调节方向。                                             |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| -------- | --------------------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.adjustSystemVolumeByStep(audio.AudioVolumeType.MEDIA, audio.VolumeAdjustType.VOLUME_UP).then(() => {
  console.info('Success to adjust the system volume by step.');
}).catch((error: BusinessError) => {
  console.error('Fail to adjust the system volume by step.');
});
```
## AudioEffectManager<sup>18+</sup>

音频效果管理。在使用AudioEffectManager的接口前，需要使用[getEffectManager](#geteffectmanager18)获取AudioEffectManager实例。


### getSupportedAudioEffectProperty<sup>18+</sup>

getSupportedAudioEffectProperty(): Array\<AudioEffectProperty>

获取支持的下行音效模式，同步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                                                                      | 说明                                    |
| --------------------------------------------------------------------------| --------------------------------------- |
| Array\<[AudioEffectProperty](#audioeffectproperty18)>     | 返回当前设备支持的音效模式。              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800301 | System error. |

**示例：**

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

获取当前音效模式，同步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                                                                      | 说明                                    |
| --------------------------------------------------------------------------| --------------------------------------- |
| Array\<[AudioEffectProperty](#audioeffectproperty18)>     | 返回当前音效模式。                        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800301 | System error. |

**示例：**

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

设置当前音效模式，同步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.core

**参数：**

| 参数名        | 类型                                                  | 必填     | 说明                         |
| ------------- | ----------------------------------------------------- | -------- | ---------------------------- |
| propertyArray | Array\<[AudioEffectProperty](#audioeffectproperty18)> | 是       |  需要设置的音效模式。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800101 | Parameter verification failed. Possible causes: <br>1. More than one effect property name of the same effect property category are in the input array. <br>2. The input audioEffectProperties are not supported by the current device. <br>3. The name or category of the input audioEffectProperties is incorrect.|
| 6800301 | System error. |

**示例：**

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

### isAudioSeparationEffectSupported

isAudioSeparationEffectSupported(): boolean

查询当前设备是否支持系统的音频分离效果。

> **说明：**
>
> 应用在使用音频分离效果相关接口前，应先调用本接口确认设备是否支持。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型 | 说明 |
| --- | --- |
| boolean | 当前设备是否支持音频分离效果。true表示支持，false表示不支持。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Caller is not a system application. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let isSupported: boolean = audioEffectManager.isAudioSeparationEffectSupported();
console.info(`Audio separation effect is supported: ${isSupported}`);
```

### setAudioSeparationEffectEnabled

setAudioSeparationEffectEnabled(enabled: boolean, uid: number, streamId?: number): Promise&lt;void&gt;

为指定应用进程或音频播放流设置音频分离效果的启用状态。使用Promise异步回调。

> **说明：**
>
> - 调用此接口前，应先调用[isAudioSeparationEffectSupported](js-apis-audio-sys.md#isaudioseparationeffectsupported)确认设备是否支持音频分离效果。
> - 当streamId参数没有传入时，根据uid控制整个应用的音频分离效果开关；当streamId参数传入时，根据streamId控制指定音频播放流的音频分离效果开关。播放应用可通过[AudioRenderer.getAudioStreamIdSync](arkts-apis-audio-AudioRenderer.md#getaudiostreamidsync10)获取streamId。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | --- |
| enabled | boolean | 是 | 音频分离效果的启用状态。true表示启用，false表示禁用。 |
| uid | number | 是 | 表示目标应用进程ID。 |
| streamId | number | 否 | 目标音频播放流的ID，默认值为-1。<br>如果没有传入此参数，则根据uid控制应用级别的音频分离效果开关。<br>播放应用可通过[AudioRenderer.getAudioStreamIdSync](arkts-apis-audio-AudioRenderer.md#getaudiostreamidsync10)获取streamId。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800101 | Parameter verification failed. |
| 6800104 | Effect is not supported in this device. |
| 6800301 | Audio service error occurs like service died. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

audioEffectManager.setAudioSeparationEffectEnabled(true, 10001).then(() => {
  console.info('Succeeded in setting audio separation effect enabled.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set audio separation effect enabled. Code: ${err.code}, message: ${err.message}`);
});
```

### onAudioSeparationEffectEnabledChange

onAudioSeparationEffectEnabledChange(callback: Callback&lt;boolean&gt;): void

订阅系统音频分离效果使能状态变更事件。

系统中的音频分离效果状态可由系统播放控制应用设定，其他应用程序可以使用本接口监听状态变更事件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | --- |
| callback | Callback&lt;boolean&gt; | 是 | 回调函数。当音频分离效果启用状态变化时，返回true表示启用，false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Caller is not a system application. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioEffectManager.onAudioSeparationEffectEnabledChange((isEnabled: boolean) => {
  console.info(`Audio separation effect enabled state changed: ${isEnabled}`);
});
```

### offAudioSeparationEffectEnabledChange

offAudioSeparationEffectEnabledChange(callback?: Callback&lt;boolean&gt;): void

取消订阅系统音频分离效果使能状态变更事件。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | --- |
| callback | Callback&lt;boolean&gt; | 否 | 需要取消的回调函数，默认值为空。如果不使用此参数，则取消之前在当前进程中订阅的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Caller is not a system application. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioEffectManager.offAudioSeparationEffectEnabledChange();
```

### setAudioSeparationEffectVolume

setAudioSeparationEffectVolume(type: AudioSeparationVolumeType, volume: number): Promise&lt;void&gt;

设置指定音量类型的音频分离效果音量。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --- | --- | --- | --- |
| type | [AudioSeparationVolumeType](js-apis-audio-sys.md#audioseparationvolumetype) | 是 | 音频分离效果的音量类型。 |
| volume | number | 是 | 目标音量值，取值范围为[0, 1]。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201 | Permission denied. |
| 202 | Caller is not a system application. |
| 6800101 | Parameter verification failed. |
| 6800104 | Effect is not supported in this device. |
| 6800301 | Audio service error occurs like service died. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

audioEffectManager.setAudioSeparationEffectVolume(audio.AudioSeparationVolumeType.VOLUME_TYPE_VOCAL, 0.5).then(() => {
  console.info('Succeeded in setting audio separation effect volume.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set audio separation effect volume. Code: ${err.code}, message: ${err.message}`);
});
```

## AudioRoutingManager<sup>9+</sup>

音频路由管理。在使用AudioRoutingManager的接口前，需要使用[getRoutingManager](arkts-apis-audio-AudioManager.md#getroutingmanager9)获取AudioRoutingManager实例。

### selectInputDevice<sup>9+</sup>

selectInputDevice(inputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

选择音频输入设备，当前只能选择一个输入设备。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 输入设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当选择音频输入设备成功，err为undefined，否则为错误对象。 |

**示例：**
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

选择音频输入设备，当前只能选择一个输入设备。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 输入设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

选择音频输出设备，当前只能选择一个输出设备。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 输出设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当选择音频输出设备成功，err为undefined，否则为错误对象。 |

**示例：**
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

选择音频输出设备，当前只能选择一个输出设备。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 输出设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

根据过滤条件，选择音频输出设备，当前只能选择一个输出设备。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| filter                      | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件。               |
| outputAudioDevices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 输出设备信息。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当选择音频输出设备成功，err为undefined，否则为错误对象。 |

**示例：**
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

根据过滤条件，选择音频输出设备，当前只能选择一个输出设备。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| filter                | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件。               |
| outputAudioDevices    | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 输出设备信息。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**示例：**

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

### selectOutputDeviceByFilter<sup>21+</sup>

selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors, strategy: AudioDevcieSelectStrategy): Promise&lt;void&gt;

根据过滤条件和设备强选策略，选择音频输出设备，当前只能选择一个输出设备。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| filter                | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件。               |
| outputAudioDevices    | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 输出设备信息。               |
| strategy                | [AudioDevcieSelectStrategy](#audiodevcieselectstrategy21)                 | 是   | 设备选择策略。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
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

audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor, audio.AudioDevcieSelectStrategy.SELECT_STRATEGY_INDEPENDENT).then(() => {
  console.info('Succeeded in selecting output device by filter.');
}).catch((err: BusinessError) => {
  console.error(`Failed to select output device by filter. Code: ${err.code}, message: ${err.message}`);
});
```

### selectInputDeviceByFilter<sup>18+</sup>

selectInputDeviceByFilter(filter: AudioCapturerFilter, inputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

根据过滤条件，选择音频输入设备，当前只能选择一个输入设备。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                                | 必填 | 说明     |
| ----------------------|-------------------------------------------------------------------| ---- |--------|
| filter                      | [AudioCapturerFilter](#audiocapturerfilter18)                     | 是   | 过滤条件类。 |
| inputAudioDevices | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | 是   | 输入设备类。 |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|


**示例：**

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
    let audioManager = audio.getAudioManager();  // 需要先创建AudioManager实例。
    let audioRoutingManager = audioManager.getRoutingManager();  // 再调用AudioManager的方法创建AudioRoutingManager实例。
    audioRoutingManager.selectInputDeviceByFilter(inputAudioCapturerFilter, inputAudioDeviceDescriptor).then(() => {
        console.info('Select input devices by filter result promise: SUCCESS');
    }).catch((err: BusinessError) => {
        console.error(`Result ERROR: ${err}`);
    })
}
```

### onPreferredInputDeviceChangeByFilter

onPreferredInputDeviceChangeByFilter(filter: AudioCapturerFilter, callback: Callback\<AudioDeviceDescriptors>): void

监听指定过滤条件下最高优先级输入设备变化事件（当最高优先级输入设备发生变化时触发）。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| filter | [AudioCapturerFilter](#audiocapturerfilter18)  | 是   | 过滤条件。 |
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 是   | 回调函数，返回优先级最高的输入设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App. |
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
let inputAudioCapturerFilter: audio.AudioCapturerFilter = {
  uid : 20010041,
  capturerInfo : {
    source: audio.SourceType.SOURCE_TYPE_MIC,
    capturerFlags: 0
  }
};
audioRoutingManager.onPreferredInputDeviceChangeByFilter(inputAudioCapturerFilter, (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in using onPreferredInputDeviceChangeByFilter function, AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
});
```

### offPreferredInputDeviceChangeByFilter

offPreferredInputDeviceChangeByFilter(callback?: Callback\<AudioDeviceDescriptors>): void

取消监听指定过滤条件下最高优先级输入设备变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 否 | 回调函数，返回优先级最高的输入设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRoutingManager.offPreferredInputDeviceChangeByFilter();

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let preferredInputDeviceChangeByFilterCallback = (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in using onPreferredInputDeviceChangeByFilter or offPreferredInputDeviceChangeByFilter function, AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
};
let inputAudioCapturerFilter: audio.AudioCapturerFilter = {
  uid : 20010041,
  capturerInfo : {
    source: audio.SourceType.SOURCE_TYPE_MIC,
    capturerFlags: 0
  }
};

audioRoutingManager.onPreferredInputDeviceChangeByFilter(inputAudioCapturerFilter, preferredInputDeviceChangeByFilterCallback);

audioRoutingManager.offPreferredInputDeviceChangeByFilter(preferredInputDeviceChangeByFilterCallback);
```

### getPreferredOutputDeviceByFilter<sup>18+</sup>

getPreferredOutputDeviceByFilter(filter: AudioRendererFilter): AudioDeviceDescriptors

根据过滤条件，查询音频输出设备。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| filter                      | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)| return the device list. |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|

**示例：**
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
    let audioManager = audio.getAudioManager();  // 需要先创建AudioManager实例。
    let audioRoutingManager = audioManager.getRoutingManager();  // 再调用AudioManager的方法创建AudioRoutingManager实例。
    let desc : audio.AudioDeviceDescriptors = audioRoutingManager.getPreferredOutputDeviceByFilter(outputAudioRendererFilter);
    console.info(`device descriptor: ${desc}`);
}
```

### on('preferredOutputDeviceChangeByFilter')<sup>21+</sup>

on(type: 'preferredOutputDeviceChangeByFilter', filter: AudioRendererFilter, callback: Callback\<AudioDeviceDescriptors>): void

监听指定过滤条件下最高优先级输出设备变化事件（当最高优先级输出设备发生变化时触发）。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'preferredOutputDeviceChangeByFilter'，当最高优先级输出设备发生变化时，触发该事件。 |
| filter | [AudioRendererFilter](#audiorendererfilter9)  | 是   | 过滤条件。 |
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 是   | 回调函数，返回优先级最高的输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};
audioRoutingManager.on('preferredOutputDeviceChangeByFilter', outputAudioRendererFilter, (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in using on function, AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
});
```

### off('preferredOutputDeviceChangeByFilter')<sup>21+</sup>

off(type: 'preferredOutputDeviceChangeByFilter', callback?: Callback\<AudioDeviceDescriptors>): void

取消监听指定过滤条件下最高优先级输出设备变化事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'preferredOutputDeviceChangeByFilter'，当取消监听指定过滤条件下最高优先级输出设备变化事件时，触发该事件。 |
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 否 | 回调函数，返回优先级最高的输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRoutingManager.off('preferredOutputDeviceChangeByFilter');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let preferredOutputDeviceChangeByFilterCallback = (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in using on or off function, AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
};
let outputAudioRendererFilter: audio.AudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    usage : audio.StreamUsage.STREAM_USAGE_MUSIC,
    rendererFlags : 0
  },
  rendererId : 0
};

audioRoutingManager.on('preferredOutputDeviceChangeByFilter', outputAudioRendererFilter, preferredOutputDeviceChangeByFilterCallback);

audioRoutingManager.off('preferredOutputDeviceChangeByFilter', preferredOutputDeviceChangeByFilterCallback);
```

### getPreferredInputDeviceByFilter<sup>18+</sup>

getPreferredInputDeviceByFilter(filter: AudioCapturerFilter): AudioDeviceDescriptors

根据过滤条件，查询音频输入设备，当前只能查询一个输入设备。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                            | 必填 | 说明                      |
|---------------------|-----------------------------------------------| ---- | ------------------------- |
| filter              | [AudioCapturerFilter](#audiocapturerfilter18) | 是   | 过滤条件类。 |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | return the device list. |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system App. |
| 6800101 |  Parameter verification failed.|

**示例：**

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
    let audioManager = audio.getAudioManager();  // 需要先创建AudioManager实例。
    let audioRoutingManager = audioManager.getRoutingManager();  // 再调用AudioManager的方法创建AudioRoutingManager实例。
    let desc: audio.AudioDeviceDescriptors = audioRoutingManager.getPreferredInputDeviceByFilter(inputAudioCapturerFilter);
    console.info(`device descriptor: ${desc}`);
}
```

### excludeOutputDevices<sup>18+</sup>

excludeOutputDevices(usage: DeviceUsage, devices: AudioDeviceDescriptors): Promise&lt;void&gt;

排除输出设备。成功调用此函数后，音频将不会在指定的设备上播放。

> **说明：**
>
> 该功能仅能排除外部输出设备，不支持本地输出设备。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

从API version 23开始，使用该功能时不需要申请ohos.permission.MANAGE_AUDIO_CONFIG权限，同时不会抛出错误码201。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | 是   | 设备种类。只支持排除输出设备。               |
| devices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 排除输出设备列表。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.      |
| 202     | Not system application.                             |
| 6800101 | Parameter verification failed. |

**示例：**

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

解除排除输出设备。成功调用此函数后，音频将会重新选择输出设备。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

从API version 23开始，使用该功能时不需要申请ohos.permission.MANAGE_AUDIO_CONFIG权限，同时不会抛出错误码201。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | 是   | 设备种类。只支持排除输出设备。               |
| devices          | [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)            | 是   | 解除排除输出设备列表。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. |
| 202     | Not system application. |
| 6800101 | Parameter verification failed. |

**示例：**

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

解除属于特定用途的所有输出设备的排除。成功调用此函数后，音频将会重新选择输出设备。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

从API version 23开始，使用该功能时不需要申请ohos.permission.MANAGE_AUDIO_CONFIG权限，同时不会抛出错误码201。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | 是   | 设备种类。只支持排除输出设备。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. |
| 202     | Not system application. |
| 6800101 | Parameter verification failed. |

**示例：**

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

获取排除输出设备列表。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| usage          | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)            | 是   | 设备种类。只支持排除输出设备。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | 排除设备列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system application. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let usage: audio.DeviceUsage.MEDIA_OUTPUT_DEVICES;

async function getExcludedDevices(){
  let desc: audio.AudioDeviceDescriptors = audioRoutingManager.getExcludedDevices(usage);
  console.info(`device descriptor: ${desc}`);
}
```

### restoreOutputDeviceByFilter

restoreOutputDeviceByFilter(filter: AudioRendererFilter): Promise&lt;void&gt;

根据指定的音频渲染过滤条件恢复音频输出设备。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| filter          | [AudioRendererFilter](#audiorendererfilter9)          | 是   | 过滤条件。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Caller is not a system application. |
| 6800101 | Parameter verification failed. |

**示例：**

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

audioRoutingManager.restoreOutputDeviceByFilter(outputAudioRendererFilter).then(() => {
  console.info('Succeeded in restoring output device by filter.');
}).catch((err: BusinessError) => {
  console.error(`Failed to restore output device by filter. Code: ${err.code}, message: ${err.message}`);
});
```

### getActiveOutputDeviceDescriptors

getActiveOutputDeviceDescriptors(): Promise&lt;AudioDeviceDescriptors&gt;

获取当前音频设备场景下的活跃输出设备描述符。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**系统接口：** 此接口为系统接口。

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt; | Promise对象，返回活跃输出设备描述符列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Not system application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
audioRoutingManager.getActiveOutputDeviceDescriptors().then((audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in getting active output device descriptors, AudioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get active output device descriptors. Code: ${err.code}, message: ${err.message}`);
});
```

## AudioRendererChangeInfo<sup>9+</sup>

描述音频渲染器更改信息。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称               | 类型                                       | 只读 | 可选 | 说明                          |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| clientUid          | number                                    | 是   | 否   | 音频渲染器客户端应用程序的Uid。 |
| rendererState      | [AudioState](arkts-apis-audio-e.md#audiostate8)                 | 是   | 否   | 音频状态。|

## AudioCapturerChangeInfo<sup>9+</sup>

描述音频采集器更改信息。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称               | 类型                                       | 只读 | 可选 | 说明                          |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| clientUid          | number                                    | 是   | 否   | 音频采集器客户端应用程序的Uid。 |
| capturerState      | [AudioState](arkts-apis-audio-e.md#audiostate8)                 | 是   | 否   | 音频状态。|

## AudioDeviceDescriptor

描述音频设备。

**系统接口：** 该接口为系统接口。

| 名称                          | 类型                       | 只读 | 可选 | 说明       |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| networkId<sup>9+</sup>        | string                     | 是   | 否   | 设备组网的ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Device|
| interruptGroupId<sup>9+</sup> | number                     | 是   | 否   | 设备所处的焦点组ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Device|
| volumeGroupId<sup>9+</sup>    | number                     | 是   | 否   | 设备所处的音量组ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Device|
| dmDeviceType<sup>18+</sup>    | number                     | 是   | 是 | 设备的子类型ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Core|
| highQualityRecordingSupported<sup>21+</sup>    | boolean                     | 是   | 是 | 是否支持高品质录音。true表示支持，false表示不支持。<br> **系统能力：** SystemCapability.Multimedia.Audio.Core|
| dmDeviceInfo<sup>23+</sup>    | string                     | 是   | 是 | 分布式设备扩展信息，包括设备是否支持立体声、设备序列号等。<br> **模型约束：** 此接口仅可在Stage模型下使用。<br> **系统能力：** SystemCapability.Multimedia.Audio.Core|

## AudioRendererFilter<sup>9+</sup>

音频渲染器过滤条件。

**系统接口：** 此接口为系统接口。

| 名称          | 类型                                     | 只读 | 可选 | 说明          |
| -------------| ---------------------------------------- | ---- |---| -------------- |
| uid          | number                                   |  否  | 是 | 表示应用ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Core|
| rendererInfo | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8) |  否  | 是 | 表示渲染器信息。<br> **系统能力：** SystemCapability.Multimedia.Audio.Renderer|
| rendererId   | number                                   |  否  | 是 | 音频流唯一id。<br> **系统能力：** SystemCapability.Multimedia.Audio.Renderer|

**示例：**

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

过滤条件类。在调用selectOutputDeviceByFilter接口前，需要先创建AudioCapturerFilter实例。

**系统接口：** 该接口为系统接口。

| 名称          | 类型                                     | 只读 | 可选 | 说明          |
| -------------| ---------------------------------------- | ---- |---| -------------- |
| uid          | number                                   |  否  | 是 | 表示应用ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Core|
| capturerInfo | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8) |  否  | 是 | 表示采集器信息。<br> **系统能力：** SystemCapability.Multimedia.Audio.Capturer|

**示例：**

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

监听设备空间音频开关状态。

**系统接口**：此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

| 参数名                 | 类型                                                         | 只读 | 可选 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- |---| ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | 否 | 否 | 指定设备的描述。     |
| enabled               | boolean                                                      | 否 | 否 | 表示开启/关闭空间音频渲染或头动。true为开启，false为关闭。  |

## AudioSpatializationManager<sup>11+</sup>

空间音频管理。在使用AudioSpatializationManager的接口前，需要使用[getSpatializationManager](arkts-apis-audio-AudioManager.md#getspatializationmanager18)获取AudioSpatializationManager实例。

### isSpatializationSupported<sup>11+</sup>

isSpatializationSupported(): boolean

获取系统是否支持空间音频，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回系统是否支持空间音频，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

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

获取指定设备是否支持空间音频，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | 是   | 指定设备的描述。     |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回指定设备是否支持空间音频，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

获取系统是否支持头动跟踪，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回系统是否支持头动跟踪，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

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

获取指定设备是否支持头动跟踪，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | 是   | 指定设备的描述。     |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回指定设备是否支持头动跟踪，true为支持，false为不支持。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

根据输入指令，开启/关闭空间音频渲染效果。使用callback异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setspatializationenabled12)替代。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| enable                      | boolean                                                      | 是   | 表示开启/关闭空间音频渲染。true为开启，false为关闭。  |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当开启/关闭空间音频渲染效果成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**
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

根据输入指令，开启/关闭空间音频渲染效果。使用Promise异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[setSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setspatializationenabled12)替代。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| enable                | boolean                                                      | 是   | 表示开启/关闭空间音频渲染。true为开启，false为关闭。  |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

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

根据输入指令，开启/关闭指定设备的空间音频渲染效果。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | 是   | 指定设备的描述。     |
| enabled               | boolean                                                      | 是   | 表示开启/关闭空间音频渲染。true为开启，false为关闭。  |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |


**示例：**

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

获取空间音频渲染是否开启，同步返回结果。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[isSpatializationEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean](#isspatializationenabled12)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回空间音频渲染是否开启，true为开启，false为未开启。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

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

获取指定设备的空间音频渲染是否开启，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 是   | 指定设备的描述。     |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回指定设备的空间音频渲染是否开启，true为开启，false为未开启。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

监听空间音频渲染开关状态变化事件（当空间音频渲染开关状态发生变化时触发）。使用callback异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[on(type: 'spatializationEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void](#onspatializationenabledchangeforanydevice12)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'spatializationEnabledChange'，当空间音频渲染开关状态发生变化时，触发该事件。 |
| callback | Callback<boolean\> | 是   | 回调函数。返回true表示音频渲染已打开；返回false表示音频渲染已关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('spatializationEnabledChange', (isSpatializationEnabled: boolean) => {
  console.info(`isSpatializationEnabled: ${isSpatializationEnabled}`);
});
```

### on('spatializationEnabledChangeForAnyDevice')<sup>12+</sup>

on(type: 'spatializationEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void

监听空间音频渲染开关状态变化事件（当空间音频渲染开关状态发生变化时触发）。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'spatializationEnabledChangeForAnyDevice'，当空间音频渲染开关状态发生变化时，触发该事件。 |
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | 是   | 回调函数，返回设备信息和空间音频渲染开关状态。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('spatializationEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
});
```

### off('spatializationEnabledChange')<sup>(deprecated)</sup>

off(type: 'spatializationEnabledChange', callback?: Callback<boolean\>): void

取消监听空间音频渲染开关状态变化事件。使用callback异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[off('spatializationEnabledChangeForAnyDevice')](#offspatializationenabledchangeforanydevice12)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'spatializationEnabledChange'，当取消监听空间音频渲染开关状态变化事件时，触发该事件。 |
| callback | Callback<boolean\> | 否   | 回调函数。返回true表示音频渲染已打开；返回false表示音频渲染已关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioSpatializationManager.off('spatializationEnabledChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let spatializationEnabledChangeCallback = (isSpatializationEnabled: boolean) => {
  console.info(`isSpatializationEnabled: ${isSpatializationEnabled}`);
};

audioSpatializationManager.on('spatializationEnabledChange', spatializationEnabledChangeCallback);

audioSpatializationManager.off('spatializationEnabledChange', spatializationEnabledChangeCallback);
```

### off('spatializationEnabledChangeForAnyDevice')<sup>12+</sup>

off(type: 'spatializationEnabledChangeForAnyDevice', callback?: Callback<AudioSpatialEnabledStateForDevice\>): void

取消监听空间音频渲染开关状态变化事件。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                           |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'spatializationEnabledChangeForAnyDevice'，当取消监听空间音频渲染开关状态变化事件时，触发该事件。 |
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | 否   | 回调函数，返回设备信息和空间音频渲染开关状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

// 取消该事件的所有监听。
audioSpatializationManager.off('spatializationEnabledChangeForAnyDevice');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let spatializationEnabledChangeForAnyDeviceCallback = (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
};

audioSpatializationManager.on('spatializationEnabledChangeForAnyDevice', spatializationEnabledChangeForAnyDeviceCallback);

audioSpatializationManager.off('spatializationEnabledChangeForAnyDevice', spatializationEnabledChangeForAnyDeviceCallback);
```

### setHeadTrackingEnabled<sup>(deprecated)</sup>

setHeadTrackingEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

根据输入指令，开启/关闭头动跟踪效果。使用callback异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setheadtrackingenabled12)替代。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| enable                      | boolean                                                      | 是   | 表示开启/关闭头动跟踪。true为开启，false为关闭。  |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调函数。当开启/关闭头动跟踪效果成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by callback.      |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**
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

根据输入指令，开启/关闭头动跟踪效果。使用Promise异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise\<void>](#setheadtrackingenabled12)替代。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| enable                | boolean                                                      | 是   | 表示开启/关闭头动跟踪。true为开启，false为关闭。  |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

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

setHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise&lt;void&gt;

根据输入指令，开启/关闭指定设备的头动跟踪效果。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)         | 是   | 设备描述符。 |
| enable                | boolean                                                      | 是   | 表示开启/关闭头动跟踪。true为开启，false为关闭。  |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.       |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

获取头动跟踪是否开启，同步返回结果。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[isHeadTrackingEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean](#isheadtrackingenabled12)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回头动跟踪是否开启，true为开启，false为未开启。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

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

获取指定设备的头动跟踪是否开启，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 是   | 指定设备的描述。     |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回指定设备的头动跟踪是否开启，true为开启，false为未开启。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

监听头动跟踪开关状态变化事件（当动跟踪开关状态发生变化时触发）。使用callback异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[on(type: 'headTrackingEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void](#onheadtrackingenabledchangeforanydevice12)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string | 是   | 事件回调类型，支持的事件为'headTrackingEnabledChange'，当动跟踪开关状态发生变化时，触发该事件。 |
| callback | Callback<boolean\> | 是   | 回调函数。返回true表示头动跟踪已打开；返回false表示头动跟踪已关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('headTrackingEnabledChange', (isHeadTrackingEnabled: boolean) => {
  console.info(`isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
});
```

### on('headTrackingEnabledChangeForAnyDevice')<sup>12+</sup>

on(type: 'headTrackingEnabledChangeForAnyDevice', callback: Callback<AudioSpatialEnabledStateForDevice\>): void

监听头动跟踪开关状态变化事件（当动跟踪开关状态发生变化时触发）。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string | 是   | 事件回调类型，支持的事件为'headTrackingEnabledChangeForAnyDevice'，当动跟踪开关状态发生变化时，触发该事件。 |
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | 是   | 回调函数。返回true表示头动跟踪已打开；返回false表示头动跟踪已关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('headTrackingEnabledChangeForAnyDevice', (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
});
```

### off('headTrackingEnabledChange')<sup>(deprecated)</sup>

off(type: 'headTrackingEnabledChange', callback?: Callback<boolean\>): void

取消监听头动跟踪开关状态变化事件。使用callback异步回调。

> **说明：**
> 从 API version 11 开始支持，从 API version 12 开始废弃，建议使用[off('headTrackingEnabledChangeForAnyDevice')](#offheadtrackingenabledchangeforanydevice12)替代。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'headTrackingEnabledChange'，当取消监听头动跟踪开关状态变化事件时，触发该事件。 |
| callback | Callback<boolean\> | 否   | 回调函数。返回true表示头动跟踪已打开；返回false表示头动跟踪已关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

// 取消该事件的所有监听。
audioSpatializationManager.off('headTrackingEnabledChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let headTrackingEnabledChangeCallback = (isHeadTrackingEnabled: boolean) => {
  console.info(`isHeadTrackingEnabled: ${isHeadTrackingEnabled}`);
};

audioSpatializationManager.on('headTrackingEnabledChange', headTrackingEnabledChangeCallback);

audioSpatializationManager.off('headTrackingEnabledChange', headTrackingEnabledChangeCallback);
```

### off('headTrackingEnabledChangeForAnyDevice')<sup>12+</sup>

off(type: 'headTrackingEnabledChangeForAnyDevice', callback?: Callback<AudioSpatialEnabledStateForDevice\>): void

取消监听头动跟踪开关状态变化事件。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'headTrackingEnabledChangeForAnyDevice'，当取消监听头动跟踪开关状态变化事件时，触发该事件。 |
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | 否   | 回调函数。返回true表示头动跟踪已打开；返回false表示头动跟踪已关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

// 取消该事件的所有监听。
audioSpatializationManager.off('headTrackingEnabledChangeForAnyDevice');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let headTrackingEnabledChangeForAnyDeviceCallback = (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${audioSpatialEnabledStateForDevice.deviceDescriptor}`);
  console.info(`isSpatializationEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
};

audioSpatializationManager.on('headTrackingEnabledChangeForAnyDevice', headTrackingEnabledChangeForAnyDeviceCallback);

audioSpatializationManager.off('headTrackingEnabledChangeForAnyDevice', headTrackingEnabledChangeForAnyDeviceCallback);
```

### isAdaptiveSpatialRenderingEnabled<sup>24+</sup>

isAdaptiveSpatialRenderingEnabled(deviceDescriptor: AudioDeviceDescriptor): boolean

查询指定设备是否开启了自适应空间音频渲染。同步返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| deviceDescriptor     | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)     | 是   | 目标设备描述符，用于查询是否开启了自适应空间音频渲染。 |

**返回值：**

| 类型                                           | 说明                          |
|----------------------------------------------| ----------------------------- |
| boolean | 指定设备是否开启了自适应空间音频渲染。返回true，表示自适应空间音频渲染开启。返回false，表示自适应空间音频渲染关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 设备描述符，用于指定要查询的设备。实际使用时应通过音频框架接口获取真实设备信息，address等字段应使用真实值。
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
  // 查询指定设备的自适应空间音频渲染效果开关状态。
  let isEnabled: boolean = audioSpatializationManager.isAdaptiveSpatialRenderingEnabled(deviceDescriptor);
  console.info(`isAdaptiveSpatialRenderingEnabled: ${isEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error.code}, message: ${error.message}`);
}
```

### setAdaptiveSpatialRenderingEnabled<sup>24+</sup>

setAdaptiveSpatialRenderingEnabled(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise&lt;void&gt;

设置指定设备的自适应空间音频渲染开关。使用Promise异步回调。

当开启自适应空间音频渲染时，立体声音频将不会进行空间音频渲染。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| deviceDescriptor     | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor)     | 是   | 目标设备描述符，用于设置是否开启自适应空间音频渲染。 |
| enabled     | boolean     | 是   | 是否开启自适应空间音频渲染。true表示开启；false表示关闭。 |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied. Return by promise.     |
| 202     | Not system App.                             |
| 801     | Capability not supported on device. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 设备描述符，用于指定要设置的设备。实际使用时应通过音频框架接口获取真实设备信息，address等字段应使用真实值。
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

// 开启自适应空间音频渲染
audioSpatializationManager.setAdaptiveSpatialRenderingEnabled(deviceDescriptor, true).then(() => {
  console.info('Succeeded in setting adaptive spatial rendering enabled');
}).catch((err: BusinessError) => {
  console.error(`setAdaptiveSpatialRenderingEnabled failed: ${err.code}, message: ${err.message}`);
});
```

### onAdaptiveSpatialRenderingEnabledChangeForAnyDevice<sup>24+</sup>

onAdaptiveSpatialRenderingEnabledChangeForAnyDevice(callback: Callback<AudioSpatialEnabledStateForDevice\>): void

订阅自适应空间音频渲染开关状态变化事件，当自适应空间音频渲染开关状态发生变化时，注册的回调将被调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | 是   | 回调函数，返回设备信息和自适应空间音频渲染开关状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.onAdaptiveSpatialRenderingEnabledChangeForAnyDevice((audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${JSON.stringify(audioSpatialEnabledStateForDevice.deviceDescriptor)}`);
  console.info(`isAdaptiveSpatialRenderingEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
});
```

### offAdaptiveSpatialRenderingEnabledChangeForAnyDevice<sup>24+</sup>

offAdaptiveSpatialRenderingEnabledChangeForAnyDevice(callback?: Callback<AudioSpatialEnabledStateForDevice\>): void

取消订阅自适应空间音频渲染开关状态变化事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| callback | Callback\<[AudioSpatialEnabledStateForDevice](#audiospatialenabledstatefordevice12)> | 否   | 回调函数，返回设备信息和自适应空间音频渲染开关状态。参数为空时，表示取消所有已注册的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

// 取消该事件的所有监听。
audioSpatializationManager.offAdaptiveSpatialRenderingEnabledChangeForAnyDevice();

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let adaptiveSpatialRenderingEnabledChangeForAnyDeviceCallback = (audioSpatialEnabledStateForDevice: audio.AudioSpatialEnabledStateForDevice) => {
  console.info(`deviceDescriptor: ${JSON.stringify(audioSpatialEnabledStateForDevice.deviceDescriptor)}`);
  console.info(`isAdaptiveSpatialRenderingEnabled: ${audioSpatialEnabledStateForDevice.enabled}`);
};

audioSpatializationManager.onAdaptiveSpatialRenderingEnabledChangeForAnyDevice(adaptiveSpatialRenderingEnabledChangeForAnyDeviceCallback);

audioSpatializationManager.offAdaptiveSpatialRenderingEnabledChangeForAnyDevice(adaptiveSpatialRenderingEnabledChangeForAnyDeviceCallback);
```

### getCurrentSpatialAudioSourceType<sup>24+</sup>

getCurrentSpatialAudioSourceType(): SpatialAudioSourceType

获取当前空间音频源类型。同步返回结果。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                                           | 说明                          |
|----------------------------------------------| ----------------------------- |
| [SpatialAudioSourceType](#spatialaudiosourcetype24) | 返回当前空间音频源类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------ | -------------------------|
| 202 | Not system App. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let sourceType: audio.SpatialAudioSourceType = audioSpatializationManager.getCurrentSpatialAudioSourceType();
  console.info(`current spatial audio source type: ${sourceType}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error.code}, message: ${error.message}`);
}
```

### onSpatialAudioSourceTypeChange<sup>24+</sup>

onSpatialAudioSourceTypeChange(callback: Callback<SpatialAudioSourceType\>): void

订阅空间音频源类型变化事件。当前空间音频源类型发生变化时，注册的回调将被调用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| callback | Callback\<[SpatialAudioSourceType](#spatialaudiosourcetype24)> | 是   | 回调函数，返回变化后的空间音频源类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.onSpatialAudioSourceTypeChange((spatialAudioSourceType: audio.SpatialAudioSourceType) => {
  console.info(`spatial audio source type changed to: ${spatialAudioSourceType}`);
});
```

### offSpatialAudioSourceTypeChange<sup>24+</sup>

offSpatialAudioSourceTypeChange(callback?: Callback<SpatialAudioSourceType\>): void

取消订阅空间音频源类型变化事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| callback | Callback\<[SpatialAudioSourceType](#spatialaudiosourcetype24)> | 否   | 回调函数，返回变化后的空间音频源类型。不传入时，表示取消所有已注册的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

// 取消该事件的所有监听。
audioSpatializationManager.offSpatialAudioSourceTypeChange();

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let spatialAudioSourceTypeChangeCallback = (spatialAudioSourceType: audio.SpatialAudioSourceType) => {
  console.info(`spatial audio source type changed to: ${spatialAudioSourceType}`);
};
audioSpatializationManager.onSpatialAudioSourceTypeChange(spatialAudioSourceTypeChangeCallback);
audioSpatializationManager.offSpatialAudioSourceTypeChange(spatialAudioSourceTypeChangeCallback);
```

### updateSpatialDeviceState<sup>11+</sup>

updateSpatialDeviceState(spatialDeviceState: AudioSpatialDeviceState): void

更新空间化设备状态，同步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| spatialDeviceState     | [AudioSpatialDeviceState](#audiospatialdevicestate11)     | 是   | 需要更新的空间化设备状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

设置空间音频渲染场景类型，同步返回结果。

**需要权限：** ohos.permission.MANAGE_SYSTEM_AUDIO_EFFECTS

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| spatializationSceneType     | [AudioSpatializationSceneType](#audiospatializationscenetype12)     | 是   | 需要设置的空间音频渲染场景类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.                          |
| 202     | Not system App.                             |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

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

查询当前空间音频渲染场景类型，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| [AudioSpatializationSceneType](#audiospatializationscenetype12) | 返回当前空间音频渲染场景类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system App.                             |

**示例：**

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

空间化设备状态。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

| 名称                          | 类型                       | 只读 | 可选 | 说明       |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| address | string         | 否 | 否 | 空间化设备地址。|
| isSpatializationSupported | boolean        | 否 | 否 | 空间化设备是否支持空间音频渲染。true表示支持，false表示不支持。|
| isHeadTrackingSupported | boolean        | 否 | 否 | 空间化设备是否支持头动跟踪。true表示支持，false表示不支持。|
| spatialDeviceType | [AudioSpatialDeviceType](#audiospatialdevicetype11)   | 否 | 否 | 空间化设备类型。|

**示例：**

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

枚举，空间化设备类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| SPATIAL_DEVICE_TYPE_NONE                   | 0      |  无空间化设备类型。  |
| SPATIAL_DEVICE_TYPE_IN_EAR_HEADPHONE       | 1      |  入耳式耳机。       |
| SPATIAL_DEVICE_TYPE_HALF_IN_EAR_HEADPHONE  | 2      |  半入耳式耳机。     |
| SPATIAL_DEVICE_TYPE_OVER_EAR_HEADPHONE     | 3      |  头戴式耳机。       |
| SPATIAL_DEVICE_TYPE_GLASSES                | 4      |  眼镜式耳机。       |
| SPATIAL_DEVICE_TYPE_OTHERS                 | 5      |  其他空间化设备类型。|

## AudioSpatializationSceneType<sup>12+</sup>

枚举，空间音频渲染场景类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| DEFAULT                            | 0      |  空间音频默认渲染场景。            |
| MUSIC                              | 1      |  空间音频音乐渲染场景。            |
| MOVIE                              | 2      |  空间音频电影渲染场景。            |
| AUDIOBOOK                          | 3      |  空间音频有声读物渲染场景。          |

## SpatialAudioSourceType<sup>24+</sup>

表示空间音频源类型的枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Spatialization

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| SPATIAL_AUDIO_SOURCE_TYPE_STEREO       | 0      | 立体声源类型。            |
| SPATIAL_AUDIO_SOURCE_TYPE_AUDIO_VIVID   | 1      | Audio Vivid源类型。            |
| SPATIAL_AUDIO_SOURCE_TYPE_MULTI_CHANNEL  | 2      | 多声道源类型。          |

## AudioCollaborativeManager<sup>20+</sup>

移动全景声管理器。

在使用AudioCollaborativeManager的接口前，需要先使用[getCollaborativeManager](#getcollaborativemanager20)获取AudioCollaborativeManager实例。

### getCollaborativeManager<sup>20+</sup>

getCollaborativeManager(): AudioCollaborativeManager

获取移动全景声管理器。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                                           | 说明                          |
|----------------------------------------------| ----------------------------- |
| [AudioCollaborativeManager](#audiocollaborativemanager20) | 返回一个AudioCollaborativeManager实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system APP.                     |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let audioManager: audio.AudioManager = audio.getAudioManager();
let audioCollaborativeManager: audio.AudioCollaborativeManager = audioManager.getCollaborativeManager();
```

### isCollaborativePlaybackSupported<sup>20+</sup>

isCollaborativePlaybackSupported(): boolean

查询系统移动全景声支持能力，同步返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型    | 必填 | 说明                                                    |
| ------- |------|------------------------------------------------------- |
| boolean |  是  | 表示系统是否支持移动全景声能力，true表示支持，false表示不支持。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system application.                     |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isCollaborativeSupported: boolean = audioCollaborativeManager.isCollaborativePlaybackSupported();
  console.info(`AudioCollaborativeManager isCollaborativeSupported: ${isCollaborativeSupported}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

### setCollaborativePlaybackEnabledForDevice<sup>20+</sup>

setCollaborativePlaybackEnabledForDevice(deviceDescriptor: AudioDeviceDescriptor, enabled: boolean): Promise&lt;void&gt;

根据输入指令，开启或关闭指定设备移动全景声。使用Promise异步回调。

当前只有蓝牙A2DP（Advanced Audio Distribution Profile）设备支持移动全景声。当开启移动全景声后，指定蓝牙A2DP设备和本地扬声器将同时播放音频。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名            | 类型                                                                 | 必填 | 说明             |
| ----------       | -------------------------------------------------------------------- | ---- |------------------|
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 是   | 指定设备的描述。   |
| enabled          | boolean                                                              | 是   | 表示开启或关闭移动全景声。true表示开启，false表示关闭。|

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Not system application.                     |
| 6800101 | Parameter verification failed. Possible causes:1. The specified device is not an A2DP device.2. The specified device is not connected.|
| 801     | Capability not supported.                   |

**示例：**

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

audioCollaborativeManager.setCollaborativePlaybackEnabledForDevice(deviceDescriptor, enabled).then(() => {
  console.info(`setSpatializationEnabled success`);
}).catch((err: BusinessError) => {
  console.error(`Result ERROR: ${err}`);
});
```

### isCollaborativePlaybackEnabledForDevice<sup>20+</sup>

isCollaborativePlaybackEnabledForDevice(deviceDescriptor: AudioDeviceDescriptor): boolean

查询指定设备移动全景声状态，同步返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名            | 类型                                                                 | 必填 | 说明              |
| ----------       | -------------------------------------------------------------------- | ---- |------------------|
| deviceDescriptor | [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 是   | 指定设备的描述。   |

**返回值：**

| 类型    | 必填 | 说明                                                    |
| ------- |------|------------------------------------------------------- |
| boolean |  是  | 返回指定设备移动全景声是否开启/关闭，true表示开启，false表示关闭。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202     | Not system application.                     |
| 6800101 | Parameter verification failed.              |

**示例：**

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
}

try {
  let isCollaborativeEnabled: boolean = audioCollaborativeManager.isCollaborativePlaybackEnabledForDevice(deviceDescriptor);
  console.info(`AudioCollaborativeManager isCollaborativeEnabled: ${isCollaborativeEnabled}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## ToneType<sup>9+</sup>

枚举，播放器的音调类型。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

| 名称                                              |  值    | 说明                          |
| :------------------------------------------------ | :----- | :----------------------------|
| TONE_TYPE_DIAL_0                                  | 0      | 键0的DTMF音。                 |
| TONE_TYPE_DIAL_1                                  | 1      | 键1的DTMF音。                 |
| TONE_TYPE_DIAL_2                                  | 2      | 键2的DTMF音。                 |
| TONE_TYPE_DIAL_3                                  | 3      | 键3的DTMF音。                 |
| TONE_TYPE_DIAL_4                                  | 4      | 键4的DTMF音。                 |
| TONE_TYPE_DIAL_5                                  | 5      | 键5的DTMF音。                 |
| TONE_TYPE_DIAL_6                                  | 6      | 键6的DTMF音。                 |
| TONE_TYPE_DIAL_7                                  | 7      | 键7的DTMF音。                 |
| TONE_TYPE_DIAL_8                                  | 8      | 键8的DTMF音。                 |
| TONE_TYPE_DIAL_9                                  | 9      | 键9的DTMF音。                 |
| TONE_TYPE_DIAL_S                                  | 10     | 键*的DTMF音。                 |
| TONE_TYPE_DIAL_P                                  | 11     | 键#的DTMF音。                 |
| TONE_TYPE_DIAL_A                                  | 12     | 键A的DTMF音。                 |
| TONE_TYPE_DIAL_B                                  | 13     | 键B的DTMF音。                 |
| TONE_TYPE_DIAL_C                                  | 14     | 键C的DTMF音。                 |
| TONE_TYPE_DIAL_D                                  | 15     | 键D的DTMF音。                 |
| TONE_TYPE_COMMON_SUPERVISORY_DIAL                 | 100    | 呼叫监管音调，拨号音。          |
| TONE_TYPE_COMMON_SUPERVISORY_BUSY                 | 101    | 呼叫监管音调，忙。              |
| TONE_TYPE_COMMON_SUPERVISORY_CONGESTION           | 102    | 呼叫监管音调，拥塞。            |
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK            | 103    | 呼叫监管音调，无线电 ACK。      |
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE  | 104    | 呼叫监管音调，无线电不可用。     |
| TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING         | 106    | 呼叫监管音调，呼叫等待。        |
| TONE_TYPE_COMMON_SUPERVISORY_RINGTONE             | 107    | 呼叫监管音调，铃声。            |
| TONE_TYPE_COMMON_SUPERVISORY_CALL_HOLDING<sup>18+</sup>  | 108  | 呼叫保持音调。            |
| TONE_TYPE_COMMON_PROPRIETARY_BEEP                 | 200    | 专有声调，一般蜂鸣声。          |
| TONE_TYPE_COMMON_PROPRIETARY_ACK                  | 201    | 专有声调，ACK。                |
| TONE_TYPE_COMMON_PROPRIETARY_PROMPT               | 203    | 专有声调，PROMPT。             |
| TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP          | 204    | 专有声调，双重蜂鸣声。          |

## RenderTarget<sup>22+</sup>

枚举，音频渲染器的渲染目标。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| PLAYBACK                           | 0      | 播放模式（音频渲染器的默认模式）。<br>在此模式下，音频将通过音频渲染器正常播放。 |
| INJECT_TO_VOICE_COMMUNICATION_CAPTURE | 1 | 注入模式。<br>在此模式下，当录音流的source type为[SOURCE_TYPE_VOICE_COMMUNICATION](arkts-apis-audio-e.md#sourcetype8)，audio scene为[AUDIO_SCENE_VOICE_CHAT](arkts-apis-audio-e.md#audioscene8)时，音频渲染器的输出将被注入到VoIP录音流上。 |

## TonePlayer<sup>9+</sup>

提供播放和管理DTMF（Dual Tone Multi Frequency，双音多频）音调的方法，包括各种系统监听音调、专有音调，如拨号音、通话回铃音等。

在调用TonePlayer的接口前，需要先通过[createTonePlayer](#audiocreatetoneplayer9)创建实例。

**系统接口：** 该接口为系统接口。

### load<sup>9+</sup>

load(type: ToneType, callback: AsyncCallback&lt;void&gt;): void

加载DTMF音调配置。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名          | 类型                        | 必填  | 说明                            |
| :--------------| :-------------------------- | :-----| :------------------------------ |
| type           | [ToneType](#tonetype9)       | 是    | 配置的音调类型。                 |
| callback       | AsyncCallback<void\>        | 是    | 回调函数。当加载DTMF音调配置成功，err为undefined，否则为错误对象。 |

**示例：**

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

加载DTMF音调配置。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名         | 类型                    | 必填  |  说明             |
| :------------- | :--------------------- | :---  | ---------------- |
| type           | [ToneType](#tonetype9)   | 是    | 配置的音调类型。  |

**返回值：**

| 类型            | 说明                        |
| :--------------| :-------------------------- |
| Promise<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
tonePlayer.load(audio.ToneType.TONE_TYPE_DIAL_1).then(() => {
  console.info('promise call load ');
}).catch(() => {
  console.error('promise call load fail');
});
```

### start<sup>9+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

启动DTMF音调播放。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当启动DTMF音调播放成功，err为undefined，否则为错误对象。 |

**示例：**

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

启动DTMF音调播放。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
tonePlayer.start().then(() => {
  console.info('promise call start');
}).catch(() => {
  console.error('promise call start fail');
});
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

停止当前正在播放的音调。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当停止当前正在播放的音调成功，err为undefined，否则为错误对象。 |

**示例：**

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

停止当前正在播放的音调。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
tonePlayer.stop().then(() => {
  console.info('promise call stop finish');
}).catch(() => {
  console.error('promise call stop fail');
});
```

### release<sup>9+</sup>

release(callback: AsyncCallback&lt;void&gt;): void

释放与此TonePlayer对象关联的资源。使用callback异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| :------- | :------------------- | :--- | :---------------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当释放与此TonePlayer对象关联的资源成功，err为undefined，否则为错误对象。 |

**示例：**

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

释放与此TonePlayer对象关联的资源。使用Promise异步回调。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
tonePlayer.release().then(() => {
  console.info('promise call release');
}).catch(() => {
  console.error('promise call release fail');
});
```

## AsrProcessingController<sup>12+</sup>

自动语音识别（ASR）处理控制器。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**设备行为差异：** 当本模块接口在TV设备上使用时，将不会产生效果。

### setAsrAecMode<sup>12+</sup>

setAsrAecMode(mode: AsrAecMode): boolean

设置自动语音识别（ASR）的声学回声消除（AEC）模式，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名| 类型                         | 必填 | 说明 |
|-------|----------------------------|-------|-------|
| mode | [AsrAecMode](#asraecmode12) | 是 |AEC模式。 |

**返回值：**

| 类型 | 说明                                    |
|-------|---------------------------------------|
| boolean | 返回设置AEC模式结果，true为设置成功，false为设置失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed. |

**示例：**

```ts
let flag = asrProcessingController.setAsrAecMode(audio.AsrAecMode.BYPASS);
```

### getAsrAecMode<sup>12+</sup>

getAsrAecMode(): AsrAecMode

获取自动语音识别（ASR）的声学回声消除（AEC）模式，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型 | 说明 |
|-------|-------|
| [AsrAecMode](#asraecmode12) |AEC模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 6800104 | Operation not allowed. |


**示例：**

```ts
let mode = asrProcessingController.getAsrAecMode();
```

### setAsrNoiseSuppressionMode<sup>12+</sup>

setAsrNoiseSuppressionMode(mode: AsrNoiseSuppressionMode): boolean

设置自动语音识别（ASR）的噪音抑制模式，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名| 类型                                                    | 必填 | 说明 |
|-------|-------------------------------------------------------|-------|-------|
| mode | [AsrNoiseSuppressionMode](#asrnoisesuppressionmode12) | 是 |ASR噪音抑制模式。 |

**返回值：**

| 类型 | 说明                                     |
|-------|----------------------------------------|
| boolean | 返回设置ASR噪音抑制模式结果，true为设置成功，false为设置失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed. |

**示例：**

```ts
let flag = asrProcessingController.setAsrNoiseSuppressionMode(audio.AsrNoiseSuppressionMode.BYPASS);
```

### getAsrNoiseSuppressionMode<sup>12+</sup>

getAsrNoiseSuppressionMode(): AsrNoiseSuppressionMode

获取自动语音识别（ASR）的噪音抑制模式，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型                      |说明 |
|-------------------------|-------|
| [AsrNoiseSuppressionMode](#asrnoisesuppressionmode12) |ASR噪音抑制模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 6800104 | Operation not allowed. |

**示例：**

```ts
let mode = asrProcessingController.getAsrNoiseSuppressionMode();
```

### isWhispering<sup>12+</sup>

isWhispering(): boolean

查询耳语状态。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型 | 说明                       |
|-------|--------------------------|
| boolean | 返回耳语状态，true为开启，false为关闭。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202 | Caller is not a system application. |
| 6800104 | Operation not allowed. |

**示例：**

```ts
let flag = asrProcessingController.isWhispering();
```

### setAsrWhisperDetectionMode<sup>12+</sup>

setAsrWhisperDetectionMode(mode: AsrWhisperDetectionMode): boolean

设置自动语音识别（ASR）的耳语检测模式。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名  | 类型                  | 必填 | 说明     |
|------|---------------------|-------|--------|
| mode | [AsrWhisperDetectionMode](#asrwhisperdetectionmode12) | 是 | ASR耳语检测模式。 |

**返回值：**

| 类型 | 说明                                     |
|-------|----------------------------------------|
| boolean | 返回设置ASR耳语检测模式结果，true为设置成功，false为设置失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters unspecified; 2.Incorrect parameter types.                 |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed.                 |

**示例：**

```ts
let flag = asrProcessingController.setAsrWhisperDetectionMode(audio.AsrWhisperDetectionMode.BYPASS);
```


### getAsrWhisperDetectionMode<sup>12+</sup>

getAsrWhisperDetectionMode(): AsrWhisperDetectionMode

获取自动语音识别（ASR）的耳语检测模式，同步返回结果。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型 | 说明     |
|-------|--------|
| [AsrWhisperDetectionMode](#asrwhisperdetectionmode12) | ASR耳语检测模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 6800104 | Operation not allowed.                 |

**示例：**

```ts
let mode = asrProcessingController.getAsrWhisperDetectionMode();
```


### setAsrVoiceControlMode<sup>12+</sup>

setAsrVoiceControlMode(mode: AsrVoiceControlMode, enable: boolean): boolean

设置在系统通话中上报mode及通话录音的上行通路的自动语音识别（ASR）音频通路选择。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名  | 类型                  | 必填 | 说明     |
|------|---------------------|-------|--------|
| mode | [AsrVoiceControlMode](#asrvoicecontrolmode12) | 是 | ASR音频通路模式。 |
| enable   | boolean             | 是 | 表示系统通话中上报mode及通话录音的上行通路的ASR音频通路选择开关状态。true表示打开，false表示关闭。   |

**返回值：**

| 类型 | 说明                                                            |
|-------|---------------------------------------------------------------|
| boolean | 返回设置在系统通话中上报mode及通话录音的上行通路的ASR音频通路选择的结果。true为设置成功，false为设置失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters unspecified; 2.Incorrect parameter types.                 |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed.                 |

**示例：**

```ts
let flag = asrProcessingController.setAsrVoiceControlMode(audio.AsrVoiceControlMode.AUDIO_2_VOICE_TX, true);
```

### setAsrVoiceMuteMode<sup>12+</sup>

setAsrVoiceMuteMode(mode: AsrVoiceMuteMode, enable: boolean): boolean

在系统通话中，对自动语音识别（ASR）的音频通路进行静音控制。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名  | 类型                                    | 必填 | 说明       |
|------|---------------------------------------|-------|----------|
| mode | [AsrVoiceMuteMode](#asrvoicemutemode12) | 是 | ASR静音控制模式。 |
| enable   | boolean                               | 是 | 表示在系统通话中设置ASR音频通路静音状态。true表示静音，false表示非静音。 |

**返回值：**

| 类型 | 说明                                               |
|-------|--------------------------------------------------|
| boolean | 返回在系统通话中，对ASR音频通路进行静音控制的结果。true为设置成功，false为设置失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息                                     |
|---------|------------------------------------------|
| 202     | Caller is not a system application. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters unspecified; 2.Incorrect parameter types.                 |
| 6800101 | Parameter verification failed. |
| 6800104 | Operation not allowed.                 |

**示例：**

```ts
let flag = asrProcessingController.setAsrVoiceMuteMode(audio.AsrVoiceMuteMode.OUTPUT_MUTE, true);
```

## AudioRenderer<sup>8+</sup>

音频渲染。在使用AudioRenderer的接口之前，需先通过[audio.createAudioRenderer](arkts-apis-audio-f.md#audiocreateaudiorenderer8)获取AudioRenderer实例。

### setTarget<sup>22+</sup>

setTarget(target: RenderTarget): Promise&lt;void&gt;

设置音频渲染器的渲染目标。使用Promise异步回调。

> **说明：**
>
> - 此方法仅可在音频渲染器未处于运行或释放状态时调用，否则将返回错误。
> - 将渲染目标更改为非[PLAYBACK](#rendertarget22)的模式后：
>   - 该音频渲染器的音频路由与中断策略将无法使用[AudioSessionManager](arkts-apis-audio-AudioSessionManager.md)相关接口。
>   - 该音频渲染器的device type为[SYSTEM_PRIVATE](arkts-apis-audio-e.md#devicetype)。
>   - 调用[Start](arkts-apis-audio-AudioRenderer.md#start8)且audio scene不为[AUDIO_SCENE_VOICE_CHAT](arkts-apis-audio-e.md#audioscene8)时，将返回错误码[6800301](errorcode-audio.md#6800301-系统处理异常)。
>   - 调用[getAudioTime](arkts-apis-audio-AudioRenderer.md#getaudiotime8)或[getAudioTimeSync](arkts-apis-audio-AudioRenderer.md#getaudiotimesync10)时，将返回错误码[6800301](errorcode-audio.md#6800301-系统处理异常)。
>   - 调用[getAudioTimestampInfo](arkts-apis-audio-AudioRenderer.md#getaudiotimestampinfo19)或[getAudioTimestampInfoSync](arkts-apis-audio-AudioRenderer.md#getaudiotimestampinfosync19)时，将返回错误码[6800301](errorcode-audio.md#6800301-系统处理异常)。
>   - 调用[setDefaultOutputDevice](arkts-apis-audio-AudioRenderer.md#setdefaultoutputdevice12)时，将返回错误码[6800301](errorcode-audio.md#6800301-系统处理异常)。

**需要权限：** ohos.permission.INJECT_PLAYBACK_TO_AUDIO_CAPTURE

仅设置渲染目标为[INJECT_TO_VOICE_COMMUNICATION_CAPTURE](#rendertarget22)时需要该权限。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| target | [RenderTarget](#rendertarget22) | 是 | 设置音频渲染目标。 |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 201     | Permission denied.      |
| 202     | Caller is not a system application. |
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permit at running and release state. |
| 6800104 | Current renderer is not supported to set target. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setTarget(audio.RenderTarget.INJECT_TO_VOICE_COMMUNICATION_CAPTURE).then(() => {
  console.info('Succeeded in setting target.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set target. code: ${err.code}, message: ${err.message}`);
});
```

### getTarget<sup>22+</sup>

getTarget(): RenderTarget

获取当前音频渲染器的渲染目标。

> **说明：**
>
> - 若未更改过渲染目标，将返回默认值[PLAYBACK](#rendertarget22)。
> - 若调用此接口前，已经调用过[SetTarget](#settarget22)，请确保[SetTarget](#settarget22)的Promise对象已成功解析，否则获取到的数值可能不准确。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                          |
|----------------------------------------------| ----------------------------- |
| [RenderTarget](#rendertarget22) | 返回音频渲染器的渲染目标。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------ | -------------------------|
| 202 | Caller is not a system application. |

**示例：**

```ts
async function getTarget(){
  // 可选步骤：设置注入模式。
  await audioRenderer.setTarget(audio.RenderTarget.INJECT_TO_VOICE_COMMUNICATION_CAPTURE);
  console.info('Succeeded in setting target.');

  // 调用此接口前，若已经调用过SetTarget接口，请确保SetTarget接口已经设置成功，否则获取到的数值可能不准确。
  let renderTarget = audioRenderer.getTarget();
  console.info(`Succeeded in getting target, RenderTarget: ${renderTarget}.`);
}
```

## audio.createMicInAudioCapturer<sup>23+</sup>

function createMicInAudioCapturer(config: AudioCapturerMicInConfig): Promise\<AudioCapturer | null>

获取音频采集器。使用Promise异步回调。

> **说明：**
>
> - 此采集器可用于同时录制麦克风输入（Mic-In）音频数据和回声参考信号，供应用层进行算法处理。
> - 麦克风输入音频数据和回声参考信号会根据应用层设置的配置，被放入同一个缓冲区或多个独立缓冲区中。
> - 仅允许使用[SourceType](js-apis-audio-sys.md#sourcetype8)为SOURCE_TYPE_UNPROCESSED_VOICE_ASSISTANT类型的音源输入，其他类型的音源输入将被系统拒绝。此外，当应用处于后台运行状态时，不允许创建该采集器实例。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名  | 类型                                           | 必填 | 说明             |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| config | [AudioCapturerMicInConfig](js-apis-audio-sys.md#audiocapturermicinconfig23) | 是   | 配置音频采集器。 |

**返回值：**

| 类型                                      | 说明                   |
| ----------------------------------------- |----------------------|
| Promise<[AudioCapturer](arkts-apis-audio-AudioCapturer.md) \| null> | Promise对象，成功将返回音频采集器对象，失败时将返回包含错误信息的error对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------|
|     201 | Permission denied, including background recording.             |
|     202 | Not system App.                |
| 6800101 | Parameter verification failed. |
| 6800104 | Capturer creation is not supported, may caused by following problems: <br> 1.Source type is unsupported for this capturer, only [SOURCE_TYPE_UNPROCESSED_VOICE_ASSISTANT](js-apis-audio-sys.md#sourcetype8) is supported currently. <br> 2.Echo reference signal's config is unsupported, echo reference's sampling rate and format must be the same as MicIn audio data currently.            |
| 6800301 | Audio system internal error, such as system process crash.            |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioEcStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_UNPROCESSED_VOICE_ASSISTANT, // 音源类型：Mic音频源。SourceType需为SOURCE_TYPE_UNPROCESSED_VOICE_ASSISTANT。
  capturerFlags: 0 // 音频采集器标志。
};

let audioMicInStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};

let audioCapturerMicInConfig: audio.AudioCapturerMicInConfig = {
  ecStreamInfo: audioEcStreamInfo,
  capturerInfo: audioCapturerInfo,
  micInStreamInfo: audioMicInStreamInfo
};

let audioCapturer: audio.AudioCapturer | null = null;

audio.createMicInAudioCapturer(audioCapturerMicInConfig).then((data) => {
  audioCapturer = data;
  console.info('AudioCapturer Created : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`AudioCapturer Created : ERROR : ${err}`);
});
```

### onReadMicInData<sup>24+</sup>

onReadMicInData(callback: Callback\<AudioCapturerMicInData>): void

订阅Mic-In音频数据读取回调。使用callback异步回调。

> **说明：**
>
> - 此回调的优先级高于`onReadData`回调。如果同时订阅两者，仅会触发此回调。
> - 当有可供读取的音频缓冲区、可继续读取更多音频数据时，会触发此回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| :--- | :--- | :--- | :--- |
| callback | Callback<[AudioCapturerMicInData](#audiocapturermicindata24)> | 是 | 回调函数，返回读取到的音频数据缓冲区。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Caller is not a system application. |
| 6800103 | Operation not permitted at running state. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioEcStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
};

let audioProcessedStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
};

let audioMicInStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_UNPROCESSED_VOICE_ASSISTANT,
  capturerFlags: 0
};

let audioCapturerMicInConfig: audio.AudioCapturerMicInConfig = {
  processedStreamInfo: audioProcessedStreamInfo,
  micInStreamInfo: audioMicInStreamInfo,
  ecStreamInfo: audioEcStreamInfo,
  capturerInfo: audioCapturerInfo
};

// data表示处理后的音频数据，micInData表示原始Mic-In音频数据。
// ecData表示回声参考音频数据；如果未配置ecStreamInfo，该字段可能为空。
let readMicInDataCallback: Callback<audio.AudioCapturerMicInData> =
  (data: audio.AudioCapturerMicInData): void => {
    let ecDataLength: number = data.ecData ? data.ecData.byteLength : 0;
    console.info(`processed data length: ${data.data.byteLength}`);
    console.info(`mic-in data length: ${data.micInData.byteLength}`);
    console.info(`echo reference data length: ${ecDataLength}`);
  };

async function registerReadMicInDataCallback(): Promise<void> {
  try {
    // 先创建Mic-In采集器实例，再注册数据读取回调。
    let audioCapturer: audio.AudioCapturer | null =
      await audio.createMicInAudioCapturer(audioCapturerMicInConfig);
    if (audioCapturer === null) {
      console.error('AudioCapturer Created : ERROR : audioCapturer is null');
      return;
    }
    // 注册成功后，当有可读取的音频缓冲区时会触发readMicInDataCallback。
    audioCapturer.onReadMicInData(readMicInDataCallback);
    console.info('Succeeded in registering onReadMicInData callback.');
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to create AudioCapturer. Code: ${error.code}, message: ${error.message}`);
  }
}
```

### offReadMicInData<sup>24+</sup>

offReadMicInData(callback?: Callback\<AudioCapturerMicInData>): void

取消监听Mic-In音频数据读取回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| :--- | :--- | :--- | :--- |
| callback | Callback<[AudioCapturerMicInData](#audiocapturermicindata24)> | 否 | 需要取消监听的回调函数，默认值为空。不传入时，表示取消该事件的所有监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202 | Caller is not a system application. |
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permitted at running state. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioMicInStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_UNPROCESSED_VOICE_ASSISTANT,
  capturerFlags: 0
};

let audioCapturerMicInConfig: audio.AudioCapturerMicInConfig = {
  micInStreamInfo: audioMicInStreamInfo,
  capturerInfo: audioCapturerInfo
};

let readMicInDataCallback: Callback<audio.AudioCapturerMicInData> =
  (data: audio.AudioCapturerMicInData): void => {
    console.info(`mic-in data length: ${data.micInData.byteLength}`);
  };

async function unregisterReadMicInDataCallback(): Promise<void> {
  try {
    let audioCapturer: audio.AudioCapturer | null =
      await audio.createMicInAudioCapturer(audioCapturerMicInConfig);
    if (audioCapturer === null) {
      console.error('AudioCapturer Created : ERROR : audioCapturer is null');
      return;
    }

    audioCapturer.onReadMicInData(readMicInDataCallback);

    // 取消指定回调的监听。
    audioCapturer.offReadMicInData(readMicInDataCallback);

    // 取消该事件的所有监听。
    audioCapturer.offReadMicInData();
  } catch (err) {
    let error = err as BusinessError;
    console.error(`Failed to create AudioCapturer. Code: ${error.code}, message: ${error.message}`);
  }
}
```

## AudioRendererOptions<sup>8+</sup>

音频渲染器选项信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称         | 类型                                               | 只读 | 可选 | 说明               |
| ------------ | ------------------------------------------------- | ---- |---| ------------------ |
| originalAppIdInfo | [AppIdInfo](#appidinfo) | 否 | 是 | 表示音频流的原始应用ID信息。<br> **起始版本：** 26.0.0 |

## AppIdInfo

应用ID信息，包含应用的UID（标识应用身份）、PID（标识运行中的进程）、Token ID（用于常规身份识别与权限校验）和FullToken ID（携带应用完整身份权限信息，用于原始应用溯源与全链路权限校验）。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称         | 类型                                               | 只读 | 可选 | 说明               |
| ------------ | ------------------------------------------------- | ---- |---| ------------------ |
| appUid       | number                                            | 否   | 否 | 应用UID，用于标识应用身份。    |
| appPid       | number                                            | 否   | 否 | 应用PID，用于标识运行中的进程。    |
| appTokenId   | number                                            | 否   | 否 | 应用Token ID，用于常规身份识别与权限校验。    |
| appFullTokenId | number                                            | 否   | 否 | 应用FullToken ID，携带应用完整身份权限信息，用于原始应用溯源与全链路权限校验。    |
