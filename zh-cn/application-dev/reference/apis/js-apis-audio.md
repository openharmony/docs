# 音频管理

音频管理提供管理音频的一些基础能力，包括对音频音量、音频设备的管理，以及对音频数据的采集和渲染等。

该模块提供以下音频相关的常用功能：

- [AudioManager](#audiomanager)：音频管理。
- [AudioRenderer](#audiorenderer8)：音频渲染，用于播放PCM（Pulse Code Modulation）音频数据。
- [AudioCapturer](#audiocapturer8)：音频采集，用于录制PCM音频数据。
- [TonePlayer](#toneplayer9)：用于管理和播放DTMF（Dual Tone Multi Frequency，双音多频）音调，如拨号音、通话回铃音等。

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import audio from '@ohos.multimedia.audio';
```

## 常量

| 名称                                    | 类型      | 可读  | 可写 | 说明               |
| --------------------------------------- | ----------| ---- | ---- | ------------------ |
| LOCAL_NETWORK_ID<sup>9+</sup>           | string    | 是   | 否   | 本地设备网络id。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.Audio.Device  |
| DEFAULT_VOLUME_GROUP_ID<sup>9+</sup>    | number    | 是   | 否   | 默认音量组id。<br> **系统能力：** SystemCapability.Multimedia.Audio.Volume       |
| DEFAULT_INTERRUPT_GROUP_ID<sup>9+</sup> | number    | 是   | 否   | 默认音频中断组id。<br> **系统能力：** SystemCapability.Multimedia.Audio.Interrupt       |

**示例：**

```js
import audio from '@ohos.multimedia.audio';

const localNetworkId = audio.LOCAL_NETWORK_ID;
const defaultVolumeGroupId = audio.DEFAULT_VOLUME_GROUP_ID;
const defaultInterruptGroupId = audio.DEFAULT_INTERRUPT_GROUP_ID;
```

## audio.getAudioManager

getAudioManager(): AudioManager

获取音频管理器。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                          | 说明         |
| ----------------------------- | ------------ |
| [AudioManager](#audiomanager) | 音频管理类。 |

**示例：**
```js
let audioManager = audio.getAudioManager();
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void

获取音频渲染器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                            | 必填 | 说明             |
| -------- | ----------------------------------------------- | ---- | ---------------- |
| options  | [AudioRendererOptions](#audiorendereroptions8)  | 是   | 配置渲染器。     |
| callback | AsyncCallback<[AudioRenderer](#audiorenderer8)> | 是   | 音频渲染器对象。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility';
import fileio from '@ohos.fileio';
import audio from '@ohos.multimedia.audio';

let audioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_1,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioRendererInfo = {
  content: audio.ContentType.CONTENT_TYPE_SPEECH,
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
  rendererFlags: 0
}

let audioRendererOptions = {
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

获取音频渲染器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名  | 类型                                           | 必填 | 说明         |
| :------ | :--------------------------------------------- | :--- | :----------- |
| options | [AudioRendererOptions](#audiorendereroptions8) | 是   | 配置渲染器。 |

**返回值：**

| 类型                                      | 说明             |
| ----------------------------------------- | ---------------- |
| Promise<[AudioRenderer](#audiorenderer8)> | 音频渲染器对象。 |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility';
import fileio from '@ohos.fileio';
import audio from '@ohos.multimedia.audio';

let audioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_1,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioRendererInfo = {
  content: audio.ContentType.CONTENT_TYPE_SPEECH,
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
  rendererFlags: 0
}

let audioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
}

let audioRenderer;
audio.createAudioRenderer(audioRendererOptions).then((data) => {
  audioRenderer = data;
  console.info('AudioFrameworkRenderLog: AudioRenderer Created : Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`AudioFrameworkRenderLog: AudioRenderer Created : ERROR : ${err}`);
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions, callback: AsyncCallback<AudioCapturer\>): void

获取音频采集器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**需要权限：** ohos.permission.MICROPHONE

**参数：**

| 参数名   | 类型                                            | 必填 | 说明             |
| :------- | :---------------------------------------------- | :--- | :--------------- |
| options  | [AudioCapturerOptions](#audiocaptureroptions8)  | 是   | 配置音频采集器。 |
| callback | AsyncCallback<[AudioCapturer](#audiocapturer8)> | 是   | 音频采集器对象。 |

**示例：**

```js
import audio from '@ohos.multimedia.audio';
let audioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

let audioCapturerOptions = {
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

获取音频采集器。使用promise 方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**需要权限：** ohos.permission.MICROPHONE

**参数：**

| 参数名  | 类型                                           | 必填 | 说明             |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| options | [AudioCapturerOptions](#audiocaptureroptions8) | 是   | 配置音频采集器。 |

**返回值：**

| 类型                                      | 说明           |
| ----------------------------------------- | -------------- |
| Promise<[AudioCapturer](#audiocapturer8)> | 音频采集器对象 |

**示例：**

```js
import audio from '@ohos.multimedia.audio';

let audioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}

let audioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
}

let audioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
}

let audioCapturer;
audio.createAudioCapturer(audioCapturerOptions).then((data) => {
  audioCapturer = data;
  console.info('AudioCapturer Created : Success : Stream Type: SUCCESS');
}).catch((err) => {
  console.error(`AudioCapturer Created : ERROR : ${err}`);
});
```

## audio.createTonePlayer<sup>9+</sup>

createTonePlayer(options: AudioRendererInfo, callback: AsyncCallback&lt;TonePlayer&gt;): void

创建DTMF播放器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                                             | 必填 | 说明            |
| -------- | ----------------------------------------------- | ---- | -------------- |
| options  | [AudioRendererInfo](#audiorendererinfo8)        | 是   | 配置音频渲染器信息。|
| callback | AsyncCallback<[TonePlayer](#toneplayer9)>       | 是   | 回调函数，回调返回音频渲染器对象。|

**示例：**

```js
import audio from '@ohos.multimedia.audio';

let audioRendererInfo = {
  content : audio.ContentType.CONTENT_TYPE_SONIFICATION,
  usage : audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags : 0
}
let tonePlayer;

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

创建DTMF播放器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**系统接口：** 该接口为系统接口

**参数：**

| 参数名  | 类型                                           | 必填 | 说明         |
| :------ | :---------------------------------------------| :--- | :----------- |
| options | [AudioRendererInfo](#audiorendererinfo8)      | 是   | 配置音频渲染器信息。 |

**返回值：**

| 类型                                      | 说明                             |
| ----------------------------------------- | -------------------------------- |
| Promise<[TonePlayer](#toneplayer9)>       | Promise对象，返回音频渲染器对象。   |

**示例：**

```js
import audio from '@ohos.multimedia.audio';
let tonePlayer;
async function createTonePlayerBefore(){
  let audioRendererInfo = {
    content : audio.ContentType.CONTENT_TYPE_SONIFICATION,
    usage : audio.StreamUsage.STREAM_USAGE_MEDIA,
    rendererFlags : 0
  }
  tonePlayer = await audio.createTonePlayer(audioRendererInfo);
}
```

## AudioVolumeType

枚举，音频流类型。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| VOICE_CALL<sup>8+</sup>      | 0      | 语音电话。 |
| RINGTONE                     | 2      | 铃声。     |
| MEDIA                        | 3      | 媒体。     |
| VOICE_ASSISTANT<sup>8+</sup> | 9      | 语音助手。 |
| ALL<sup>9+</sup>             | 100    | 所有公共音频流。<br/>此接口为系统接口。|

## InterruptRequestResultType<sup>9+</sup>

枚举，音频中断请求结果类型。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**系统接口：** 该接口为系统接口

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| INTERRUPT_REQUEST_GRANT      | 0      | 请求音频中断成功。 |
| INTERRUPT_REQUEST_REJECT     | 1      | 请求音频中断失败，可能具有较高优先级类型。 |

## InterruptMode<sup>9+</sup>

枚举，焦点模型。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

| 名称                         | 值      | 说明       |
| ---------------------------- | ------ | ---------- |
| SHARE_MODE                   | 0      | 共享焦点模式。 |
| INDEPENDENT_MODE             | 1      | 独立焦点模式。 |

## DeviceFlag

枚举，可获取的设备种类。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                            |  值     | 说明                                              |
| ------------------------------- | ------ | ------------------------------------------------- |
| NONE_DEVICES_FLAG<sup>9+</sup>  | 0      | 无 <br/>此接口为系统接口。        |
| OUTPUT_DEVICES_FLAG             | 1      | 输出设备。 |
| INPUT_DEVICES_FLAG              | 2      | 输入设备。 |
| ALL_DEVICES_FLAG                | 3      | 所有设备。 |
| DISTRIBUTED_OUTPUT_DEVICES_FLAG<sup>9+</sup> | 4   | 分布式输出设备。<br/>此接口为系统接口。  |
| DISTRIBUTED_INPUT_DEVICES_FLAG<sup>9+</sup>  | 8   | 分布式输入设备。<br/>此接口为系统接口。  |
| ALL_DISTRIBUTED_DEVICES_FLAG<sup>9+</sup>    | 12  | 分布式输入和输出设备。<br/>此接口为系统接口。  |

## DeviceRole

枚举，设备角色。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称          |  值    | 说明           |
| ------------- | ------ | -------------- |
| INPUT_DEVICE  | 1      | 输入设备角色。 |
| OUTPUT_DEVICE | 2      | 输出设备角色。 |

## DeviceType

枚举，设备类型。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                 | 值     | 说明                                                      |
| ---------------------| ------ | --------------------------------------------------------- |
| INVALID              | 0      | 无效设备。                                                |
| EARPIECE             | 1      | 听筒。                                                    |
| SPEAKER              | 2      | 扬声器。                                                  |
| WIRED_HEADSET        | 3      | 有线耳机，带麦克风。                                      |
| WIRED_HEADPHONES     | 4      | 有线耳机，无麦克风。                                      |
| BLUETOOTH_SCO        | 7      | 蓝牙设备SCO（Synchronous Connection Oriented）连接。      |
| BLUETOOTH_A2DP       | 8      | 蓝牙设备A2DP（Advanced Audio Distribution Profile）连接。 |
| MIC                  | 15     | 麦克风。                                                  |
| USB_HEADSET          | 22     | USB耳机，带麦克风。                                       |
| DEFAULT<sup>9+</sup> | 1000   | 默认设备类型。                                            |

## CommunicationDeviceType<sup>9+</sup>

枚举，用于通信的可用设备类型。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

| 名称          | 值     | 说明          |
| ------------- | ------ | -------------|
| SPEAKER       | 2      | 扬声器。      |

## AudioRingMode

枚举，铃声模式。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

| 名称                |  值    | 说明       |
| ------------------- | ------ | ---------- |
| RINGER_MODE_SILENT  | 0      | 静音模式。 |
| RINGER_MODE_VIBRATE | 1      | 震动模式。 |
| RINGER_MODE_NORMAL  | 2      | 响铃模式。 |

## AudioSampleFormat<sup>8+</sup>

枚举，音频采样格式。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                |  值    | 说明                       |
| ---------------------------------- | ------ | -------------------------- |
| SAMPLE_FORMAT_INVALID              | -1     | 无效格式。                 |
| SAMPLE_FORMAT_U8                   | 0      | 无符号8位整数。            |
| SAMPLE_FORMAT_S16LE                | 1      | 带符号的16位整数，小尾数。 |
| SAMPLE_FORMAT_S24LE                | 2      | 带符号的24位整数，小尾数。 <br>由于系统限制，该采样格式仅部分设备支持，请根据实际情况使用。|
| SAMPLE_FORMAT_S32LE                | 3      | 带符号的32位整数，小尾数。 <br>由于系统限制，该采样格式仅部分设备支持，请根据实际情况使用。|
| SAMPLE_FORMAT_F32LE<sup>9+</sup>   | 4      | 带符号的32位整数，小尾数。 <br>由于系统限制，该采样格式仅部分设备支持，请根据实际情况使用。|

## AudioErrors<sup>9+</sup>

枚举，音频错误码。

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

枚举， 音频声道。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称      |  值       | 说明     |
| --------- | -------- | -------- |
| CHANNEL_1 | 0x1 << 0 | 单声道。 |
| CHANNEL_2 | 0x1 << 1 | 双声道。 |

## AudioSamplingRate<sup>8+</sup>

枚举，音频采样率，具体设备支持的采样率规格会存在差异。

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
| SAMPLE_RATE_96000 | 96000  | 采样率为96000。 |

## AudioEncodingType<sup>8+</sup>

枚举，音频编码类型。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                  |  值    | 说明      |
| --------------------- | ------ | --------- |
| ENCODING_TYPE_INVALID | -1     | 无效。    |
| ENCODING_TYPE_RAW     | 0      | PCM编码。 |

## ContentType

枚举，音频内容类型。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                               |  值    | 说明       |
| ---------------------------------- | ------ | ---------- |
| CONTENT_TYPE_UNKNOWN               | 0      | 未知类型。 |
| CONTENT_TYPE_SPEECH                | 1      | 语音。     |
| CONTENT_TYPE_MUSIC                 | 2      | 音乐。     |
| CONTENT_TYPE_MOVIE                 | 3      | 电影。     |
| CONTENT_TYPE_SONIFICATION          | 4      | 加密类型。 |
| CONTENT_TYPE_RINGTONE<sup>8+</sup> | 5      | 铃声。     |

## StreamUsage

枚举，音频流使用类型。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                      |  值    | 说明       |
| ------------------------------------------| ------ | ---------- |
| STREAM_USAGE_UNKNOWN                      | 0      | 未知类型。 |
| STREAM_USAGE_MEDIA                        | 1      | 音频。     |
| STREAM_USAGE_VOICE_COMMUNICATION          | 2      | 语音通信。 |
| STREAM_USAGE_VOICE_ASSISTANT<sup>9+</sup> | 3      | 语音播报。 |
| STREAM_USAGE_NOTIFICATION_RINGTONE        | 6      | 通知铃声。 |

## InterruptRequestType<sup>9+</sup>

枚举，音频中断请求类型。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

| 名称                               |  值     | 说明                       |
| ---------------------------------- | ------ | ------------------------- |
| INTERRUPT_REQUEST_TYPE_DEFAULT     | 0      |  默认类型，可中断音频请求。  |

## AudioState<sup>8+</sup>

枚举，音频状态。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称           | 值     | 说明             |
| -------------- | ------ | ---------------- |
| STATE_INVALID  | -1     | 无效状态。       |
| STATE_NEW      | 0      | 创建新实例状态。 |
| STATE_PREPARED | 1      | 准备状态。       |
| STATE_RUNNING  | 2      | 可运行状态。     |
| STATE_STOPPED  | 3      | 停止状态。       |
| STATE_RELEASED | 4      | 释放状态。       |
| STATE_PAUSED   | 5      | 暂停状态。       |

## AudioRendererRate<sup>8+</sup>

枚举，音频渲染速度。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称               | 值     | 说明       |
| ------------------ | ------ | ---------- |
| RENDER_RATE_NORMAL | 0      | 正常速度。 |
| RENDER_RATE_DOUBLE | 1      | 2倍速。    |
| RENDER_RATE_HALF   | 2      | 0.5倍数。  |

## InterruptType

枚举，中断类型。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称                 |  值     | 说明                   |
| -------------------- | ------ | ---------------------- |
| INTERRUPT_TYPE_BEGIN | 1      | 音频播放中断事件开始。 |
| INTERRUPT_TYPE_END   | 2      | 音频播放中断事件结束。 |

## InterruptForceType<sup>9+</sup>

枚举，强制打断类型。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称            |  值    | 说明                                 |
| --------------- | ------ | ------------------------------------ |
| INTERRUPT_FORCE | 0      | 由系统进行操作，强制打断音频播放。   |
| INTERRUPT_SHARE | 1      | 由应用进行操作，可以选择打断或忽略。 |

## InterruptHint

枚举，中断提示。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称                               |  值     | 说明                                         |
| ---------------------------------- | ------ | -------------------------------------------- |
| INTERRUPT_HINT_NONE<sup>8+</sup>   | 0      | 无提示。                                     |
| INTERRUPT_HINT_RESUME              | 1      | 提示音频恢复。                               |
| INTERRUPT_HINT_PAUSE               | 2      | 提示音频暂停。                               |
| INTERRUPT_HINT_STOP                | 3      | 提示音频停止。                               |
| INTERRUPT_HINT_DUCK                | 4      | 提示音频躲避。（躲避：音量减弱，而不会停止） |
| INTERRUPT_HINT_UNDUCK<sup>8+</sup> | 5      | 提示音量恢复。                               |

## AudioStreamInfo<sup>8+</sup>

音频流信息。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称         | 类型                                               | 必填 | 说明               |
| ------------ | ------------------------------------------------- | ---- | ------------------ |
| samplingRate | [AudioSamplingRate](#audiosamplingrate8)          | 是   | 音频文件的采样率。 |
| channels     | [AudioChannel](#audiochannel8)                    | 是   | 音频文件的通道数。 |
| sampleFormat | [AudioSampleFormat](#audiosampleformat8)          | 是   | 音频采样格式。     |
| encodingType | [AudioEncodingType](#audioencodingtype8)          | 是   | 音频编码格式。     |

## AudioRendererInfo<sup>8+</sup>

音频渲染器信息。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称          | 类型                        | 必填  | 说明             |
| ------------- | --------------------------- | ---- | ---------------- |
| content       | [ContentType](#contenttype) | 是   | 媒体类型。       |
| usage         | [StreamUsage](#streamusage) | 是   | 音频流使用类型。 |
| rendererFlags | number                      | 是   | 音频渲染器标志。 |

## InterruptResult<sup>9+</sup>

音频中断结果。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**系统接口：** 该接口为系统接口

| 名称          | 类型                                                            | 必填 | 说明             |
| --------------| -------------------------------------------------------------- | ---- | ---------------- |
| requestResult | [InterruptRequestResultType](#interruptrequestresulttype9)     | 是   | 表示音频请求中断类型。 |
| interruptNode | number                                                         | 是   | 音频请求中断的节点。 |

## AudioRendererOptions<sup>8+</sup>

音频渲染器选项信息。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称         | 类型                                     | 必填  | 说明             |
| ------------ | ---------------------------------------- | ---- | ---------------- |
| streamInfo   | [AudioStreamInfo](#audiostreaminfo8)     | 是   | 表示音频流信息。 |
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) | 是   | 表示渲染器信息。 |

## InterruptEvent<sup>9+</sup>

播放中断时，应用接收的中断事件。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称      | 类型                                       |必填   | 说明                                 |
| --------- | ------------------------------------------ | ---- | ------------------------------------ |
| eventType | [InterruptType](#interrupttype)            | 是   | 中断事件类型，开始或是结束。         |
| forceType | [InterruptForceType](#interruptforcetype9) | 是   | 操作是由系统执行或是由应用程序执行。 |
| hintType  | [InterruptHint](#interrupthint)            | 是   | 中断提示。                           |

## VolumeEvent<sup>8+</sup>

音量改变时，应用接收的事件。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称       | 类型                                | 必填   | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |
| updateUi   | boolean                             | 是   | 在UI中显示音量变化。                                     |
| volumeGroupId<sup>9+</sup>   | number            | 是   | 音量组id。可用于getGroupManager入参                      |
| networkId<sup>9+</sup>    | string               | 是   | 网络id。                                                |

## MicStateChangeEvent<sup>9+</sup>

麦克风状态变化时，应用接收的事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称       | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- |-------------------------------------------------------- |
| mute | boolean | 是   | 回调返回系统麦克风静音状态，true为静音，false为非静音。          |

## ConnectType<sup>9+</sup>

枚举，设备连接类型。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                            |  值     | 说明                   |
| :------------------------------ | :----- | :--------------------- |
| CONNECT_TYPE_LOCAL              | 1      | 本地设备。         |
| CONNECT_TYPE_DISTRIBUTED        | 2      | 分布式设备。            |

## VolumeGroupInfos<sup>9+</sup>

音量组信息，数组类型，为[VolumeGroupInfo](#volumegroupinfo9)的数组，只读。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

## VolumeGroupInfo<sup>9+</sup>

音量组信息。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

| 名称                        | 类型                       | 可读 | 可写 | 说明       |
| -------------------------- | -------------------------- | ---- | ---- | ---------- |
| networkId<sup>9+</sup>     | string                     | 是   | 否   | 组网络id。  |
| groupId<sup>9+</sup>       | number                     | 是   | 否   | 组设备组id。 |
| mappingId<sup>9+</sup>     | number                     | 是   | 否   | 组映射id。 |
| groupName<sup>9+</sup>     | string                     | 是   | 否   | 组名。 |
| type<sup>9+</sup>          | [ConnectType](#connecttype9)| 是   | 否   | 连接设备类型。 |

## DeviceChangeAction

描述设备连接状态变化和设备信息。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称              | 类型                                              | 必填 | 说明               |
| :---------------- | :------------------------------------------------ | :--- | :----------------- |
| type              | [DeviceChangeType](#devicechangetype)             | 是   | 设备连接状态变化。 |
| deviceDescriptors | [AudioDeviceDescriptors](#audiodevicedescriptors) | 是   | 设备信息。         |

## DeviceChangeType

枚举，设备连接状态变化。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称       |  值     | 说明           |
| :--------- | :----- | :------------- |
| CONNECT    | 0      | 设备连接。     |
| DISCONNECT | 1      | 断开设备连接。 |

## AudioCapturerOptions<sup>8+</sup>

音频采集器选项信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Capturer

| 名称         | 类型                                    | 必填 | 说明             |
| ------------ | --------------------------------------- | ---- | ---------------- |
| streamInfo   | [AudioStreamInfo](#audiostreaminfo8)    | 是   | 表示音频流信息。 |
| capturerInfo | [AudioCapturerInfo](#audiocapturerinfo) | 是   | 表示采集器信息。 |

## AudioCapturerInfo<sup>8+</sup><a name="audiocapturerinfo"></a>

描述音频采集器信息。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称          | 类型                      | 必填 | 说明             |
| :------------ | :------------------------ | :--- | :--------------- |
| source        | [SourceType](#sourcetype) | 是   | 音源类型。       |
| capturerFlags | number                    | 是   | 音频采集器标志。 |

## SourceType<sup>8+</sup><a name="sourcetype"></a>

枚举，音源类型。

**系统能力：** SystemCapability.Multimedia.Audio.Core

| 名称                                         |  值     | 说明                   |
| :------------------------------------------- | :----- | :--------------------- |
| SOURCE_TYPE_INVALID                          | -1     | 无效的音频源。         |
| SOURCE_TYPE_MIC                              | 0      | Mic音频源。            |
| SOURCE_TYPE_VOICE_RECOGNITION<sup>9+</sup>   | 1      | 语音识别源。        |
| SOURCE_TYPE_VOICE_COMMUNICATION              | 7      | 语音通话场景的音频源。 |

## AudioScene<sup>8+</sup><a name="audioscene"></a>

枚举，音频场景。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

| 名称                   |  值     | 说明                                          |
| :--------------------- | :----- | :-------------------------------------------- |
| AUDIO_SCENE_DEFAULT    | 0      | 默认音频场景。                                |
| AUDIO_SCENE_RINGING    | 1      | 响铃模式。<br/>此接口为系统接口。 |
| AUDIO_SCENE_PHONE_CALL | 2      | 电话模式。<br/>此接口为系统接口。 |
| AUDIO_SCENE_VOICE_CHAT | 3      | 语音聊天模式。                                |

## AudioManager

管理音频音量和音频设备。在调用AudioManager的接口前，需要先通过[getAudioManager](#audiogetaudiomanager)创建实例。

### setAudioParameter

setAudioParameter(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

音频参数设置，使用callback方式异步返回结果。

本接口的使用场景为根据硬件设备支持能力扩展音频配置。在不同的设备平台上，所支持的音频参数会存在差异。示例代码内使用样例参数，实际支持的音频配置参数见具体设备平台的资料描述。

**需要权限：** ohos.permission.MODIFY_AUDIO_SETTINGS

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| key      | string                    | 是   | 被设置的音频参数的键。   |
| value    | string                    | 是   | 被设置的音频参数的值。   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回设置成功或失败。 |

**示例：**

```js
audioManager.setAudioParameter('key_example', 'value_example', (err) => {
  if (err) {
    console.error(`Failed to set the audio parameter. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the audio parameter.');
});
```

### setAudioParameter

setAudioParameter(key: string, value: string): Promise&lt;void&gt;

音频参数设置，使用Promise方式异步返回结果。

本接口的使用场景为根据硬件设备支持能力扩展音频配置。在不同的设备平台上，所支持的音频参数会存在差异。示例代码内使用样例参数，实际支持的音频配置参数见具体设备平台的资料描述。

**需要权限：** ohos.permission.MODIFY_AUDIO_SETTINGS

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| key    | string | 是   | 被设置的音频参数的键。 |
| value  | string | 是   | 被设置的音频参数的值。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```js
audioManager.setAudioParameter('key_example', 'value_example').then(() => {
  console.info('Promise returned to indicate a successful setting of the audio parameter.');
});
```

### getAudioParameter

getAudioParameter(key: string, callback: AsyncCallback&lt;string&gt;): void

获取指定音频参数值，使用callback方式异步返回结果。

本接口的使用场景为根据硬件设备支持能力扩展音频配置。在不同的设备平台上，所支持的音频参数会存在差异。示例代码内使用样例参数，实际支持的音频配置参数见具体设备平台的资料描述。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                         |
| -------- | --------------------------- | ---- | ---------------------------- |
| key      | string                      | 是   | 待获取的音频参数的键。       |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调返回获取的音频参数的值。 |

**示例：**

```js
audioManager.getAudioParameter('key_example', (err, value) => {
  if (err) {
    console.error(`Failed to obtain the value of the audio parameter. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the value of the audio parameter is obtained ${value}.`);
});
```

### getAudioParameter

getAudioParameter(key: string): Promise&lt;string&gt;

获取指定音频参数值，使用Promise方式异步返回结果。

本接口的使用场景为根据硬件设备支持能力扩展音频配置。在不同的设备平台上，所支持的音频参数会存在差异。示例代码内使用样例参数，实际支持的音频配置参数见具体设备平台的资料描述。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| key    | string | 是   | 待获取的音频参数的键。 |

**返回值：**

| 类型                  | 说明                                |
| --------------------- | ----------------------------------- |
| Promise&lt;string&gt; | Promise回调返回获取的音频参数的值。 |

**示例：**

```js
audioManager.getAudioParameter('key_example').then((value) => {
  console.info(`Promise returned to indicate that the value of the audio parameter is obtained ${value}.`);
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene, callback: AsyncCallback<void\>\): void

设置音频场景模式，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                 |
| :------- | :----------------------------------- | :--- | :------------------- |
| scene    | <a href="#audioscene">AudioScene</a> | 是   | 音频场景模式。       |
| callback | AsyncCallback<void\>                 | 是   | 用于返回结果的回调。 |

**示例：**

```js
audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL, (err) => {
  if (err) {
    console.error(`Failed to set the audio scene mode.​ ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the audio scene mode.');
});
```

### setAudioScene<sup>8+</sup>

setAudioScene\(scene: AudioScene\): Promise<void\>

设置音频场景模式，使用Promise方式返回异步结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名 | 类型                                 | 必填 | 说明           |
| :----- | :----------------------------------- | :--- | :------------- |
| scene  | <a href="#audioscene">AudioScene</a> | 是   | 音频场景模式。 |

**返回值：**

| 类型           | 说明                 |
| :------------- | :------------------- |
| Promise<void\> | 用于返回结果的回调。 |

**示例：**

```js
audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL).then(() => {
  console.info('Promise returned to indicate a successful setting of the audio scene mode.');
}).catch ((err) => {
  console.error(`Failed to set the audio scene mode ${err}`);
});
```

### getAudioScene<sup>8+</sup>

getAudioScene\(callback: AsyncCallback<AudioScene\>\): void

获取音频场景模式，使用callback方式返回异步结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                         |
| :------- | :-------------------------------------------------- | :--- | :--------------------------- |
| callback | AsyncCallback<<a href="#audioscene">AudioScene</a>> | 是   | 用于返回音频场景模式的回调。 |

**示例：**

```js
audioManager.getAudioScene((err, value) => {
  if (err) {
    console.error(`Failed to obtain the audio scene mode.​ ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the audio scene mode is obtained ${value}.`);
});
```

### getAudioScene<sup>8+</sup>

getAudioScene\(\): Promise<AudioScene\>

获取音频场景模式，使用Promise方式返回异步结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**返回值：**

| 类型                                          | 说明                         |
| :-------------------------------------------- | :--------------------------- |
| Promise<<a href="#audioscene">AudioScene</a>> | 用于返回音频场景模式的回调。 |

**示例：**

```js
audioManager.getAudioScene().then((value) => {
  console.info(`Promise returned to indicate that the audio scene mode is obtained ${value}.`);
}).catch ((err) => {
  console.error(`Failed to obtain the audio scene mode ${err}`);
});
```

### getVolumeManager<sup>9+</sup>

getVolumeManager(): AudioVolumeManager

获取音频音量管理器。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**示例：**

```js
let audioVolumeManager = audioManager.getVolumeManager();
```

### getStreamManager<sup>9+</sup>

getStreamManager(): AudioStreamManager

获取音频流管理器。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**示例：**

```js
let audioStreamManager = audioManager.getStreamManager();
```

### getRoutingManager<sup>9+</sup>

getRoutingManager(): AudioRoutingManager

获取音频路由设备管理器。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**示例：**

```js
let audioRoutingManager = audioManager.getRoutingManager();
```

### setVolume<sup>(deprecated)</sup>

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

设置指定流的音量，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[setVolume](#setvolume9)替代。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调表示成功还是失败。                                   |

**示例：**

```js
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err) => {
  if (err) {
    console.error(`Failed to set the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful volume setting.');
});
```

### setVolume<sup>(deprecated)</sup>

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

设置指定流的音量，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[setVolume](#setvolume9)替代。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise回调表示成功还是失败。 |

**示例：**

```js
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的音量，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getVolume](#getvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回音量大小。 |

**示例：**

```js
audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume is obtained.');
});
```

### getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的音量，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getVolume](#getvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise回调返回音量大小。 |

**示例：**

```js
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promise returned to indicate that the volume is obtained ${value} .`);
});
```

### getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最小音量，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getMinVolume](#getminvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回最小音量。 |

**示例：**

```js
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the minimum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the minimum volume is obtained. ${value}`);
});
```

### getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最小音量，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getMinVolume](#getminvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise回调返回最小音量。 |

**示例：**

```js
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promised returned to indicate that the minimum volume is obtained. ${value}`);
});
```

### getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最大音量，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getMaxVolume](#getmaxvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                   |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。           |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回最大音量大小。 |

**示例：**

```js
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the maximum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the maximum volume is obtained. ${value}`);
});
```

### getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最大音量，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getMaxVolume](#getmaxvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                  | 说明                          |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise回调返回最大音量大小。 |

**示例：**

```js
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data) => {
  console.info('Promised returned to indicate that the maximum volume is obtained.');
});
```

### mute<sup>(deprecated)</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定音量流静音，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[mute](#mute9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调表示成功还是失败。                |

**示例：**

```js
audioManager.mute(audio.AudioVolumeType.MEDIA, true, (err) => {
  if (err) {
    console.error(`Failed to mute the stream. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the stream is muted.');
});
```

### mute<sup>(deprecated)</sup>

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

设置指定音量流静音，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[mute](#mute9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise回调表示成功还是失败。 |

**示例：**


```js
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
  console.info('Promise returned to indicate that the stream is muted.');
});
```

### isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量流是否被静音，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[isMute](#ismute9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                            |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                    |
| callback   | AsyncCallback&lt;boolean&gt;        | 是   | 回调返回流静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioManager.isMute(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the mute status. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the stream is obtained. ${value}`);
});
```

### isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

获取指定音量流是否被静音，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[isMute](#ismute9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                   | 说明                                                   |
| ---------------------- | ------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise回调返回流静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promise returned to indicate that the mute status of the stream is obtained ${value}.`);
});
```

### isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量流是否为活跃状态，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioStreamManager中的[isActive](#isactive9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                              |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                      |
| callback   | AsyncCallback&lt;boolean&gt;        | 是   | 回调返回流的活跃状态，true为活跃，false为不活跃。 |

**示例：**

```js
audioManager.isActive(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the active status of the stream. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the active status of the stream is obtained ${value}.`);
});
```

### isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

获取指定音量流是否为活跃状态，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioStreamManager中的[isActive](#isactive9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                   | 说明                                                     |
| ---------------------- | -------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise回调返回流的活跃状态，true为活跃，false为不活跃。 |

**示例：**

```js
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promise returned to indicate that the active status of the stream is obtained ${value}.`);
});
```

### setRingerMode<sup>(deprecated)</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

设置铃声模式，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[setRingerMode](#setringermode9)替代。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](#audioringmode) | 是   | 音频铃声模式。           |
| callback | AsyncCallback&lt;void&gt;       | 是   | 回调返回设置成功或失败。 |

**示例：**

```js
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err) => {
  if (err) {
    console.error(`Failed to set the ringer mode.​ ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the ringer mode.');
});
```

### setRingerMode<sup>(deprecated)</sup>

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

设置铃声模式，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[setRingerMode](#setringermode9)替代。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](#audioringmode) | 是   | 音频铃声模式。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```js
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
  console.info('Promise returned to indicate a successful setting of the ringer mode.');
});
```

### getRingerMode<sup>(deprecated)</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

获取铃声模式，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getRingerMode](#getringermode9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                     |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](#audioringmode)&gt; | 是   | 回调返回系统的铃声模式。 |

**示例：**

```js
audioManager.getRingerMode((err, value) => {
  if (err) {
    console.error(`Failed to obtain the ringer mode.​ ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the ringer mode is obtained ${value}.`);
});
```

### getRingerMode<sup>(deprecated)</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

获取铃声模式，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[getRingerMode](#getringermode9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**返回值：**

| 类型                                           | 说明                            |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](#audioringmode)&gt; | Promise回调返回系统的铃声模式。 |

**示例：**

```js
audioManager.getRingerMode().then((value) => {
  console.info(`Promise returned to indicate that the ringer mode is obtained ${value}.`);
});
```

### getDevices<sup>(deprecated)</sup>

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

获取音频设备列表，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[getDevices](#getdevices9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceFlag | [DeviceFlag](#deviceflag)                                    | 是   | 设备类型的flag。     |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | 是   | 回调，返回设备列表。 |

**示例：**
```js
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the device list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device list is obtained.');
});
```

### getDevices<sup>(deprecated)</sup>

getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

获取音频设备列表，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[getDevices](#getdevices9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceFlag | [DeviceFlag](#deviceflag) | 是   | 设备类型的flag。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise回调返回设备列表。 |

**示例：**

```js
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

### setDeviceActive<sup>(deprecated)</sup>

setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

设置设备激活状态，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[setCommunicationDevice](#setcommunicationdevice9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                     |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | 是   | 活跃音频设备类型。       |
| active     | boolean                               | 是   | 设备激活状态。           |
| callback   | AsyncCallback&lt;void&gt;             | 是   | 回调返回设置成功或失败。 |

**示例：**

```js
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true, (err) => {
  if (err) {
    console.error(`Failed to set the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device is set to the active status.');
});
```

### setDeviceActive<sup>(deprecated)</sup>

setDeviceActive(deviceType: ActiveDeviceType, active: boolean): Promise&lt;void&gt;

设置设备激活状态，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[setCommunicationDevice](#setcommunicationdevice9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明               |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | 是   | 活跃音频设备类型。 |
| active     | boolean                               | 是   | 设备激活状态。     |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**


```js
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true).then(() => {
  console.info('Promise returned to indicate that the device is set to the active status.');
});
```

### isDeviceActive<sup>(deprecated)</sup>

isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定设备的激活状态，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[isCommunicationDeviceActive](#iscommunicationdeviceactive9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                     |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | 是   | 活跃音频设备类型。       |
| callback   | AsyncCallback&lt;boolean&gt;          | 是   | 回调返回设备的激活状态。 |

**示例：**

```js
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the active status of the device is obtained.');
});
```

### isDeviceActive<sup>(deprecated)</sup>

isDeviceActive(deviceType: ActiveDeviceType): Promise&lt;boolean&gt;

获取指定设备的激活状态，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[isCommunicationDeviceActive](#iscommunicationdeviceactive9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明               |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetypedeprecated) | 是   | 活跃音频设备类型。 |

**返回值：**

| Type                   | Description                     |
| ---------------------- | ------------------------------- |
| Promise&lt;boolean&gt; | Promise回调返回设备的激活状态。 |

**示例：**

```js
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER).then((value) => {
  console.info(`Promise returned to indicate that the active status of the device is obtained ${value}.`);
});
```

### setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置麦克风静音状态，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[setMicrophoneMute](#setmicrophonemute9)替代。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                          |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | 是   | 待设置的静音状态，true为静音，false为非静音。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回设置成功或失败。                      |

**示例：**

```js
audioManager.setMicrophoneMute(true, (err) => {
  if (err) {
    console.error(`Failed to mute the microphone. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the microphone is muted.');
});
```

### setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

设置麦克风静音状态，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[setMicrophoneMute](#setmicrophonemute9)替代。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名 | 类型    | 必填 | 说明                                          |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | 是   | 待设置的静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```js
audioManager.setMicrophoneMute(true).then(() => {
  console.info('Promise returned to indicate that the microphone is muted.');
});
```

### isMicrophoneMute<sup>(deprecated)</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

获取麦克风静音状态，使用callback方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[isMicrophoneMute](#ismicrophonemute9)替代。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioManager.isMicrophoneMute((err, value) => {
  if (err) {
    console.error(`Failed to obtain the mute status of the microphone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### isMicrophoneMute<sup>(deprecated)</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

获取麦克风静音状态，使用Promise方式异步返回结果。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[isMicrophoneMute](#ismicrophonemute9)替代。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioManager.isMicrophoneMute().then((value) => {
  console.info(`Promise returned to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### on('volumeChange')<sup>(deprecated)</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeManager中的[on](#on9)替代。

监听系统音量变化事件。

**系统接口：** 该接口为系统接口

目前此订阅接口在单进程多AudioManager实例的使用场景下，仅最后一个实例的订阅生效，其他实例的订阅会被覆盖（即使最后一个实例没有进行订阅），因此推荐使用单一AudioManager实例进行开发。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为：'volumeChange'（系统音量变化事件，检测到系统音量改变时，触发该事件）。 |
| callback | Callback<[VolumeEvent](#volumeevent8)> | 是   | 回调方法。                                                   |

**示例：**

```js
audioManager.on('volumeChange', (volumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

### on('ringerModeChange')<sup>(deprecated)</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

监听铃声模式变化事件。

> **说明：**
> 从 API version 8 开始支持，从 API version 9 开始废弃，建议使用AudioVolumeGroupManager中的[on('ringerModeChange')](#onringermodechange9)替代。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | 是   | 事件回调类型，支持的事件为：'ringerModeChange'（铃声模式变化事件，检测到铃声模式改变时，触发该事件）。 |
| callback | Callback<[AudioRingMode](#audioringmode)> | 是   | 回调方法。                                                   |

**示例：**

```js
audioManager.on('ringerModeChange', (ringerMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
});
```

### on('deviceChange')<sup>(deprecated)</sup>

on(type: 'deviceChange', callback: Callback<DeviceChangeAction\>): void

设备更改。音频设备连接状态变化。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[on](#on9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | 是   | 订阅的事件的类型。支持事件：'deviceChange' |
| callback | Callback<[DeviceChangeAction](#devicechangeaction)\> | 是   | 获取设备更新详情。                         |

**示例：**

```js
audioManager.on('deviceChange', (deviceChanged) => {
  console.info(`device change type : ${deviceChanged.type} `);
  console.info(`device descriptor size : ${deviceChanged.deviceDescriptors.length} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceRole} `);
  console.info(`device change descriptor : ${deviceChanged.deviceDescriptors[0].deviceType} `);
});
```

### off('deviceChange')<sup>(deprecated)</sup>

off(type: 'deviceChange', callback?: Callback<DeviceChangeAction\>): void

取消订阅音频设备连接变化事件。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用AudioRoutingManager中的[off](#off9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 订阅的事件的类型。支持事件：'deviceChange' |
| callback | Callback<[DeviceChangeAction](#devicechangeaction)> | 否   | 获取设备更新详情。                         |

**示例：**

```js
audioManager.off('deviceChange', (deviceChanged) => {
  console.info('Should be no callback.');
});
```

### on('interrupt')<sup>(deprecated)</sup>

on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void

请求焦点并开始监听音频打断事件（当应用程序的音频被另一个播放事件中断，回调通知此应用程序）。

与[on('audioInterrupt')](#onaudiointerrupt9)作用一致，均用于监听焦点变化。为无音频流的场景（未曾创建AudioRenderer对象），比如FM、语音唤醒等提供焦点变化监听功能。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名    | 类型                                          | 必填 | 说明                                                         |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type      | string                                        | 是   | 音频打断事件回调类型，支持的事件为：'interrupt'（多应用之间第二个应用会打断第一个应用，触发该事件）。 |
| interrupt | AudioInterrupt                                | 是   | 音频打断事件类型的参数。                                     |
| callback  | Callback<[InterruptAction](#interruptactiondeprecated)> | 是   | 音频打断事件回调方法。                                       |

**示例：**

```js
let interAudioInterrupt = {
  streamUsage:2,
  contentType:0,
  pauseWhenDucked:true
};
audioManager.on('interrupt', interAudioInterrupt, (InterruptAction) => {
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

取消监听音频打断事件（删除监听事件，取消打断）。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名    | 类型                                          | 必填 | 说明                                                         |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type      | string                                        | 是   | 音频打断事件回调类型，支持的事件为：'interrupt'（多应用之间第二个应用会打断第一个应用，触发该事件）。 |
| interrupt | AudioInterrupt                                | 是   | 音频打断事件类型的参数。                                     |
| callback  | Callback<[InterruptAction](#interruptactiondeprecated)> | 否   | 音频打断事件回调方法。                                       |

**示例：**

```js
let interAudioInterrupt = {
  streamUsage:2,
  contentType:0,
  pauseWhenDucked:true
};
audioManager.off('interrupt', interAudioInterrupt, (InterruptAction) => {
  if (InterruptAction.actionType === 0) {
      console.info('An event to release the audio focus starts.');
      console.info(`Focus release event: ${InterruptAction} `);
  }
});
```

## AudioVolumeManager<sup>9+</sup>

音量管理。在使用AudioVolumeManager的接口前，需要使用[getVolumeManager](#getvolumemanager9)获取AudioVolumeManager实例。

### getVolumeGroupInfos<sup>9+</sup>

getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos\>\): void

获取音量组信息列表，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| networkId | string                                    | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。    |
| callback  | AsyncCallback&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | 是   | 回调，返回音量组信息列表。 |

**示例：**
```js
audioVolumeManager.getVolumeGroupInfos(audio.LOCAL_NETWORK_ID, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the volume group infos list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
});
```

### getVolumeGroupInfos<sup>9+</sup>

getVolumeGroupInfos(networkId: string\): Promise<VolumeGroupInfos\>

获取音量组信息列表，使用promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型               | 必填 | 说明                 |
| ---------- | ------------------| ---- | -------------------- |
| networkId | string             | 是   | 设备的网络id。本地设备audio.LOCAL_NETWORK_ID。   |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;[VolumeGroupInfos](#volumegroupinfos9)&gt; | 音量组信息列表。 |

**示例：**

```js
async function getVolumeGroupInfos(){
  let volumegroupinfos = await audio.getAudioManager().getVolumeManager().getVolumeGroupInfos(audio.LOCAL_NETWORK_ID);
  console.info('Promise returned to indicate that the volumeGroup list is obtained.'+JSON.stringify(volumegroupinfos))
}
```

### getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager\>\): void

获取音频组管理器，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| groupId    | number                                    | 是   | 音量组id。     |
| callback   | AsyncCallback&lt;[AudioVolumeGroupManager](#audiovolumegroupmanager9)&gt; | 是   | 回调，返回一个音量组实例。 |

**示例：**

```js
let groupid = audio.DEFAULT_VOLUME_GROUP_ID;
audioVolumeManager.getVolumeGroupManager(groupid, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the volume group infos list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
});

```

### getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number\): Promise<AudioVolumeGroupManager\>

获取音频组管理器，使用promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明              |
| ---------- | ---------------------------------------- | ---- | ---------------- |
| groupId    | number                                   | 是   | 音量组id。     |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt; [AudioVolumeGroupManager](#audiovolumegroupmanager9) &gt; | 音量组实例。 |

**示例：**

```js
let groupid = audio.DEFAULT_VOLUME_GROUP_ID;
let audioVolumeGroupManager;
getVolumeGroupManager();
async function getVolumeGroupManager(){
  audioVolumeGroupManager = await audioVolumeManager.getVolumeGroupManager(groupid);
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
}

```

### on('volumeChange')<sup>9+</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

监听系统音量变化事件，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为：'volumeChange'。 |
| callback | Callback<[VolumeEvent](#volumeevent8)> | 是   | 回调方法。                                                   |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioVolumeManager.on('volumeChange', (volumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

## AudioVolumeGroupManager<sup>9+</sup>

管理音频组音量。在调用AudioVolumeGroupManager的接口前，需要先通过 [getVolumeGroupManager](#getvolumegroupmanager9) 创建实例。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

### setVolume<sup>9+</sup>

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

设置指定流的音量，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调表示成功还是失败。                                   |

**示例：**

```js
audioVolumeGroupManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err) => {
  if (err) {
    console.error(`Failed to set the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful volume setting.');
});
```

### setVolume<sup>9+</sup>

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

设置指定流的音量，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise回调表示成功还是失败。 |

**示例：**

```js
audioVolumeGroupManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
  console.info('Promise returned to indicate a successful volume setting.');
});
```

### getVolume<sup>9+</sup>

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的音量，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回音量大小。 |

**示例：**

```js
audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume is obtained.');
});
```

### getVolume<sup>9+</sup>

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的音量，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise回调返回音量大小。 |

**示例：**

```js
audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promise returned to indicate that the volume is obtained ${value}.`);
});
```

### getMinVolume<sup>9+</sup>

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最小音量，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回最小音量。 |

**示例：**

```js
audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the minimum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the minimum volume is obtained. ${value}`);
});
```

### getMinVolume<sup>9+</sup>

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最小音量，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise回调返回最小音量。 |

**示例：**

```js
audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promised returned to indicate that the minimum volume is obtained ${value}.`);
});
```

### getMaxVolume<sup>9+</sup>

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最大音量，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                   |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。           |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回最大音量大小。 |

**示例：**

```js
audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the maximum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the maximum volume is obtained. ${value}`);
});
```

### getMaxVolume<sup>9+</sup>

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最大音量，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                  | 说明                          |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise回调返回最大音量大小。 |

**示例：**

```js
audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data) => {
  console.info('Promised returned to indicate that the maximum volume is obtained.');
});
```

### mute<sup>9+</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定音量流静音，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调表示成功还是失败。                |

**示例：**

```js
audioVolumeGroupManager.mute(audio.AudioVolumeType.MEDIA, true, (err) => {
  if (err) {
    console.error(`Failed to mute the stream. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the stream is muted.');
});
```

### mute<sup>9+</sup>

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

设置指定音量流静音，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅设置铃声（即volumeType为AudioVolumeType.RINGTONE）在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise回调表示成功还是失败。 |

**示例：**

```js
audioVolumeGroupManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
  console.info('Promise returned to indicate that the stream is muted.');
});
```

### isMute<sup>9+</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量流是否被静音，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                            |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                    |
| callback   | AsyncCallback&lt;boolean&gt;        | 是   | 回调返回流静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the mute status. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the stream is obtained ${value}.`);
});
```

### isMute<sup>9+</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

获取指定音量流是否被静音，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。 |

**返回值：**

| 类型                   | 说明                                                   |
| ---------------------- | ------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise回调返回流静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promise returned to indicate that the mute status of the stream is obtained ${value}.`);
});
```

### setRingerMode<sup>9+</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

设置铃声模式，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](#audioringmode) | 是   | 音频铃声模式。           |
| callback | AsyncCallback&lt;void&gt;       | 是   | 回调返回设置成功或失败。 |

**示例：**

```js
audioVolumeGroupManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err) => {
  if (err) {
    console.error(`Failed to set the ringer mode.​ ${err}`);
    return;
  }
  console.info('Callback invoked to indicate a successful setting of the ringer mode.');
});
```

### setRingerMode<sup>9+</sup>

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

设置铃声模式，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

仅在静音和非静音状态切换时需要该权限。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| mode   | [AudioRingMode](#audioringmode) | 是   | 音频铃声模式。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```js
audioVolumeGroupManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
  console.info('Promise returned to indicate a successful setting of the ringer mode.');
});
```

### getRingerMode<sup>9+</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

获取铃声模式，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                     |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](#audioringmode)&gt; | 是   | 回调返回系统的铃声模式。 |

**示例：**

```js
audioVolumeGroupManager.getRingerMode((err, value) => {
  if (err) {
    console.error(`Failed to obtain the ringer mode.​ ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the ringer mode is obtained ${value}.`);
});
```

### getRingerMode<sup>9+</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

获取铃声模式，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                                           | 说明                            |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](#audioringmode)&gt; | Promise回调返回系统的铃声模式。 |

**示例：**

```js
audioVolumeGroupManager.getRingerMode().then((value) => {
  console.info(`Promise returned to indicate that the ringer mode is obtained ${value}.`);
});
```

### on('ringerModeChange')<sup>9+</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

监听铃声模式变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | 是   | 事件回调类型，支持的事件为：'ringerModeChange'（铃声模式变化事件，检测到铃声模式改变时，触发该事件）。 |
| callback | Callback<[AudioRingMode](#audioringmode)> | 是   | 回调方法。                                                   |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioVolumeGroupManager.on('ringerModeChange', (ringerMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
});
```
### setMicrophoneMute<sup>9+</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置麦克风静音状态，使用callback方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                          |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | 是   | 待设置的静音状态，true为静音，false为非静音。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回设置成功或失败。                      |

**示例：**

```js
audioVolumeGroupManager.setMicrophoneMute(true, (err) => {
  if (err) {
    console.error(`Failed to mute the microphone. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the microphone is muted.');
});
```

### setMicrophoneMute<sup>9+</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

设置麦克风静音状态，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型    | 必填 | 说明                                          |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | 是   | 待设置的静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```js
audioVolumeGroupManager.setMicrophoneMute(true).then(() => {
  console.info('Promise returned to indicate that the microphone is muted.');
});
```

### isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

获取麦克风静音状态，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioVolumeGroupManager.isMicrophoneMute((err, value) => {
  if (err) {
    console.error(`Failed to obtain the mute status of the microphone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

获取麦克风静音状态，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**

```js
audioVolumeGroupManager.isMicrophoneMute().then((value) => {
  console.info(`Promise returned to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

### on('micStateChange')<sup>9+</sup>

on(type: 'micStateChange', callback: Callback&lt;MicStateChangeEvent&gt;): void

监听系统麦克风状态更改事件。

目前此订阅接口在单进程多AudioManager实例的使用场景下，仅最后一个实例的订阅生效，其他实例的订阅会被覆盖（即使最后一个实例没有进行订阅），因此推荐使用单一AudioManager实例进行开发。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为：'micStateChange'（系统麦克风状态变化事件，检测到系统麦克风状态改变时，触发该事件）。 |
| callback | Callback<[MicStateChangeEvent](#micstatechangeevent9)> | 是   | 回调方法，返回变更后的麦克风状态。                                                   |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioVolumeGroupManager.on('micStateChange', (micStateChange) => {
  console.info(`Current microphone status is: ${micStateChange.mute} `);
});
```

## AudioStreamManager<sup>9+</sup>

管理音频流。在使用AudioStreamManager的API前，需要使用[getStreamManager](#getstreammanager9)获取AudioStreamManager实例。

### getCurrentAudioRendererInfoArray<sup>9+</sup>

getCurrentAudioRendererInfoArray(callback: AsyncCallback&lt;AudioRendererChangeInfoArray&gt;): void

获取当前音频渲染器的信息。使用callback异步回调。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型                                 | 必填     | 说明                         |
| -------- | ----------------------------------- | -------- | --------------------------- |
| callback | AsyncCallback<[AudioRendererChangeInfoArray](#audiorendererchangeinfoarray9)> | 是     |  回调函数，返回当前音频渲染器的信息。 |

**示例：**

```js
audioStreamManager.getCurrentAudioRendererInfoArray(async (err, AudioRendererChangeInfoArray) => {
  console.info('getCurrentAudioRendererInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getCurrentAudioRendererInfoArray :ERROR: ${err}`);
  } else {
    if (AudioRendererChangeInfoArray != null) {
      for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
        let AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
        console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
        console.info(`ClientUid for ${i} is: ${AudioRendererChangeInfo.clientUid}`);
        console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
        console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
        console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`); 
        console.info(`State for ${i} is: ${AudioRendererChangeInfo.rendererState}`);  
        for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
          console.info(`SampleRates: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks}`);
        }
      }
    }
  }
});
```

### getCurrentAudioRendererInfoArray<sup>9+</sup>

getCurrentAudioRendererInfoArray(): Promise&lt;AudioRendererChangeInfoArray&gt;

获取当前音频渲染器的信息。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                                                              | 说明                                    |
| ---------------------------------------------------------------------------------| --------------------------------------- |
| Promise<[AudioRendererChangeInfoArray](#audiorendererchangeinfoarray9)>          | Promise对象，返回当前音频渲染器信息。      |

**示例：**

```js
async function getCurrentAudioRendererInfoArray(){
  await audioStreamManager.getCurrentAudioRendererInfoArray().then( function (AudioRendererChangeInfoArray) {
    console.info(`getCurrentAudioRendererInfoArray ######### Get Promise is called ##########`);
    if (AudioRendererChangeInfoArray != null) {
      for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
        let AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
        console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
        console.info(`ClientUid for ${i} is: ${AudioRendererChangeInfo.clientUid}`);
        console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
        console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
        console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`); 
        console.info(`State for ${i} is: ${AudioRendererChangeInfo.rendererState}`);  
        for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
          console.info(`SampleRates: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks}`);
        }
      }
    }
  }).catch((err) => {
    console.error(`getCurrentAudioRendererInfoArray :ERROR: ${err}`);
  });
}
```

### getCurrentAudioCapturerInfoArray<sup>9+</sup>

getCurrentAudioCapturerInfoArray(callback: AsyncCallback&lt;AudioCapturerChangeInfoArray&gt;): void

获取当前音频采集器的信息。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名        | 类型                                 | 必填      | 说明                                                      |
| ---------- | ----------------------------------- | --------- | -------------------------------------------------------- |
| callback   | AsyncCallback<[AudioCapturerChangeInfoArray](#audiocapturerchangeinfoarray9)> | 是    | 回调函数，返回当前音频采集器的信息。 |

**示例：**

```js
audioStreamManager.getCurrentAudioCapturerInfoArray(async (err, AudioCapturerChangeInfoArray) => {
  console.info('getCurrentAudioCapturerInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getCurrentAudioCapturerInfoArray :ERROR: ${err}`);
  } else {
    if (AudioCapturerChangeInfoArray != null) {
      for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
        console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
        console.info(`ClientUid for ${i} is: ${AudioCapturerChangeInfoArray[i].clientUid}`);
        console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
        console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
        console.info(`State for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerState}`);  
        for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
          console.info(`SampleRates: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCounts ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
        }
      }
    }
  }
});
```

### getCurrentAudioCapturerInfoArray<sup>9+</sup>

getCurrentAudioCapturerInfoArray(): Promise&lt;AudioCapturerChangeInfoArray&gt;

获取当前音频采集器的信息。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                                                         | 说明                                 |
| -----------------------------------------------------------------------------| ----------------------------------- |
| Promise<[AudioCapturerChangeInfoArray](#audiocapturerchangeinfoarray9)>      | Promise对象，返回当前音频渲染器信息。  |

**示例：**

```js
async function getCurrentAudioCapturerInfoArray(){
  await audioStreamManager.getCurrentAudioCapturerInfoArray().then( function (AudioCapturerChangeInfoArray) {
    console.info('getCurrentAudioCapturerInfoArray **** Get Promise Called ****');
    if (AudioCapturerChangeInfoArray != null) {
      for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
        console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
        console.info(`ClientUid for ${i} is: ${AudioCapturerChangeInfoArray[i].clientUid}`);
        console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
        console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
        console.info(`State for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerState}`);  
        for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
          console.info(`SampleRates: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCounts ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
        }
      }
    }
  }).catch((err) => {
    console.error(`getCurrentAudioCapturerInfoArray :ERROR: ${err}`);
  });
}
```

### on('audioRendererChange')<sup>9+</sup>

on(type: "audioRendererChange", callback: Callback&lt;AudioRendererChangeInfoArray&gt;): void

监听音频渲染器更改事件。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名      | 类型        | 必填      | 说明                                                                     |
| -------- | ---------- | --------- | ------------------------------------------------------------------------ |
| type     | string     | 是        | 事件类型，支持的事件`'audioRendererChange'`：当音频渲染器发生更改时触发。     |
| callback | Callback<[AudioRendererChangeInfoArray](#audiorendererchangeinfoarray9)> | 是  |  回调函数。        |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioStreamManager.on('audioRendererChange',  (AudioRendererChangeInfoArray) => {
  for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
    let AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
    console.info(`## RendererChange on is called for ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
    console.info(`ClientUid for ${i} is: ${AudioRendererChangeInfo.clientUid}`);
    console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
    console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
    console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`); 
    console.info(`State for ${i} is: ${AudioRendererChangeInfo.rendererState}`);  
    for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
      console.info(`SampleRates: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCount ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks}`);
    }
  }
});
```

### off('audioRendererChange')<sup>9+</sup>

off(type: "audioRendererChange"): void

取消监听音频渲染器更改事件。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型     | 必填 | 说明              |
| -------- | ------- | ---- | ---------------- |
| type     | string  | 是   | 事件类型，支持的事件`'audioRendererChange'`：音频渲染器更改事件。 |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioStreamManager.off('audioRendererChange');
console.info('######### RendererChange Off is called #########');
```

### on('audioCapturerChange')<sup>9+</sup>

on(type: "audioCapturerChange", callback: Callback&lt;AudioCapturerChangeInfoArray&gt;): void

监听音频采集器更改事件。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名     | 类型     | 必填      | 说明                                                                                           |
| -------- | ------- | --------- | ----------------------------------------------------------------------- |
| type     | string  | 是        | 事件类型，支持的事件`'audioCapturerChange'`：当音频采集器发生更改时触发。     |
| callback | Callback<[AudioCapturerChangeInfoArray](#audiocapturerchangeinfoarray9)> | 是     | 回调函数。   |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioStreamManager.on('audioCapturerChange', (AudioCapturerChangeInfoArray) =>  {
  for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
    console.info(`## CapChange on is called for element ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
    console.info(`ClientUid for ${i} is: ${AudioCapturerChangeInfoArray[i].clientUid}`);
    console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
    console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
    console.info(`State for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerState}`);  
    let devDescriptor = AudioCapturerChangeInfoArray[i].deviceDescriptors;
    for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
      console.info(`SampleRates: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCounts ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
    }
  }
});
```

### off('audioCapturerChange')<sup>9+</sup>

off(type: "audioCapturerChange"): void;

取消监听音频采集器更改事件。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名       | 类型     | 必填 | 说明                                                          |
| -------- | -------- | --- | ------------------------------------------------------------- |
| type     | string   |是   | 事件类型，支持的事件`'audioCapturerChange'`：音频采集器更改事件。 |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioStreamManager.off('audioCapturerChange');
console.info('######### CapturerChange Off is called #########');

```

### isActive<sup>9+</sup>

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音频流是否为活跃状态，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                              |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频流类型。                                      |
| callback   | AsyncCallback&lt;boolean&gt;        | 是   | 回调返回流的活跃状态，true为活跃，false为不活跃。 |

**示例：**

```js
audioStreamManager.isActive(audio.AudioVolumeType.MEDIA, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the active status of the stream. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the active status of the stream is obtained ${value}.`);
});
```

### isActive<sup>9+</sup>

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

获取指定音频流是否为活跃状态，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音频流类型。 |

**返回值：**

| 类型                   | 说明                                                     |
| ---------------------- | -------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise回调返回流的活跃状态，true为活跃，false为不活跃。 |

**示例：**

```js
audioStreamManager.isActive(audio.AudioVolumeType.MEDIA).then((value) => {
  console.info(`Promise returned to indicate that the active status of the stream is obtained ${value}.`);
});
```

## AudioRoutingManager<sup>9+</sup>

音频路由管理。在使用AudioRoutingManager的接口前，需要使用[getRoutingManager](#getroutingmanager9)获取AudioRoutingManager实例。

### getDevices<sup>9+</sup>

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

获取音频设备列表，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceFlag | [DeviceFlag](#deviceflag)                                    | 是   | 设备类型的flag。     |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | 是   | 回调，返回设备列表。 |

**示例：**

```js
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the device list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device list is obtained.');
});
```

### getDevices<sup>9+</sup>

getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

获取音频设备列表，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceFlag | [DeviceFlag](#deviceflag) | 是   | 设备类型的flag。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise回调返回设备列表。 |

**示例：**

```js
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  console.info('Promise returned to indicate that the device list is obtained.');
});
```

### on<sup>9+</sup>

on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback<DeviceChangeAction\>): void

设备更改。音频设备连接状态变化。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | 是   | 订阅的事件的类型。支持事件：'deviceChange' |
| deviceFlag | [DeviceFlag](#deviceflag)                                    | 是   | 设备类型的flag。     |
| callback | Callback<[DeviceChangeAction](#devicechangeaction)\> | 是   | 获取设备更新详情。                         |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (deviceChanged) => {
  console.info('device change type : ' + deviceChanged.type);
  console.info('device descriptor size : ' + deviceChanged.deviceDescriptors.length);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceRole);
  console.info('device change descriptor : ' + deviceChanged.deviceDescriptors[0].deviceType);
});
```

### off<sup>9+</sup>

off(type: 'deviceChange', callback?: Callback<DeviceChangeAction\>): void

取消订阅音频设备连接变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 订阅的事件的类型。支持事件：'deviceChange' |
| callback | Callback<[DeviceChangeAction](#devicechangeaction)> | 否   | 获取设备更新详情。                         |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
audioRoutingManager.off('deviceChange', (deviceChanged) => {
  console.info('Should be no callback.');
});
```

### selectInputDevice<sup>9+</sup>

selectInputDevice(inputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

选择音频输入设备，当前只能选择一个输入设备，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](#audiodevicedescriptors)            | 是   | 输入设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调，返回选择输入设备结果。 |

**示例：**
```js
let inputAudioDeviceDescriptor = [{
    deviceRole : audio.DeviceRole.INPUT_DEVICE,
    deviceType : audio.DeviceType.EARPIECE,
    id : 1,
    name : "",
    address : "",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
}];

async function selectInputDevice(){
  audioRoutingManager.selectInputDevice(inputAudioDeviceDescriptor, (err) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select input devices result callback: SUCCESS'); }
  });
}
```

### selectInputDevice<sup>9+</sup>

selectInputDevice(inputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

**系统接口：** 该接口为系统接口

选择音频输入设备，当前只能选择一个输入设备，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| inputAudioDevices           | [AudioDeviceDescriptors](#audiodevicedescriptors)            | 是   | 输入设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise返回选择输入设备结果。 |

**示例：**

```js
let inputAudioDeviceDescriptor = [{
    deviceRole : audio.DeviceRole.INPUT_DEVICE,
    deviceType : audio.DeviceType.EARPIECE,
    id : 1,
    name : "",
    address : "",
    sampleRates : [44100],
    channelCounts : [2],
    channelMasks : [0],
    networkId : audio.LOCAL_NETWORK_ID,
    interruptGroupId : 1,
    volumeGroupId : 1,
}];

async function getRoutingManager(){
    audioRoutingManager.selectInputDevice(inputAudioDeviceDescriptor).then(() => {
      console.info('Select input devices result promise: SUCCESS');
    }).catch((err) => {
      console.error(`Result ERROR: ${err}`);
    });
}
```

### setCommunicationDevice<sup>9+</sup>

setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

设置通信设备激活状态，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                     |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | 是   | 音频设备类型。       |
| active     | boolean                               | 是   | 设备激活状态。           |
| callback   | AsyncCallback&lt;void&gt;             | 是   | 回调返回设置成功或失败。 |

**示例：**

```js
audioRoutingManager.setCommunicationDevice(audio.CommunicationDeviceType.SPEAKER, true, (err) => {
  if (err) {
    console.error(`Failed to set the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the device is set to the active status.');
});
```

### setCommunicationDevice<sup>9+</sup>

setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean): Promise&lt;void&gt;

设置通信设备激活状态，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                                   | 必填 | 说明               |
| ---------- | ----------------------------------------------------- | ---- | ------------------ |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9)  | 是   | 活跃音频设备类型。 |
| active     | boolean                                               | 是   | 设备激活状态。     |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```js
audioRoutingManager.setCommunicationDevice(audio.CommunicationDeviceType.SPEAKER, true).then(() => {
  console.info('Promise returned to indicate that the device is set to the active status.');
});
```

### isCommunicationDeviceActive<sup>9+</sup>

isCommunicationDeviceActive(deviceType: CommunicationDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定通信设备的激活状态，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                                  | 必填 | 说明                     |
| ---------- | ---------------------------------------------------- | ---- | ------------------------ |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | 是   | 活跃音频设备类型。       |
| callback   | AsyncCallback&lt;boolean&gt;                         | 是   | 回调返回设备的激活状态。 |

**示例：**

```js
audioRoutingManager.isCommunicationDeviceActive(audio.CommunicationDeviceType.SPEAKER, (err, value) => {
  if (err) {
    console.error(`Failed to obtain the active status of the device. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the active status of the device is obtained.');
});
```

### isCommunicationDeviceActive<sup>9+</sup>

isCommunicationDeviceActive(deviceType: CommunicationDeviceType): Promise&lt;boolean&gt;

获取指定通信设备的激活状态，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                                  | 必填 | 说明               |
| ---------- | ---------------------------------------------------- | ---- | ------------------ |
| deviceType | [CommunicationDeviceType](#communicationdevicetype9) | 是   | 活跃音频设备类型。 |

**返回值：**

| Type                   | Description                     |
| ---------------------- | ------------------------------- |
| Promise&lt;boolean&gt; | Promise回调返回设备的激活状态。 |

**示例：**

```js
audioRoutingManager.isCommunicationDeviceActive(audio.CommunicationDeviceType.SPEAKER).then((value) => {
  console.info(`Promise returned to indicate that the active status of the device is obtained ${value}.`);
});
```

### selectOutputDevice<sup>9+</sup>

selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

选择音频输出设备，当前只能选择一个输出设备，使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](#audiodevicedescriptors)            | 是   | 输出设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调，返回获取输出设备结果。 |

**示例：**
```js
let outputAudioDeviceDescriptor = [{
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
}];

async function selectOutputDevice(){
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor, (err) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select output devices result callback: SUCCESS'); }
  });
}
```

### selectOutputDevice<sup>9+</sup>

selectOutputDevice(outputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

**系统接口：** 该接口为系统接口

选择音频输出设备，当前只能选择一个输出设备，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| outputAudioDevices          | [AudioDeviceDescriptors](#audiodevicedescriptors)            | 是   | 输出设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise返回选择输出设备结果。 |

**示例：**

```js
let outputAudioDeviceDescriptor = [{
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
}];

async function selectOutputDevice(){
  audioRoutingManager.selectOutputDevice(outputAudioDeviceDescriptor).then(() => {
    console.info('Select output devices result promise: SUCCESS');
  }).catch((err) => {
    console.error(`Result ERROR: ${err}`);
  });
}
```

### selectOutputDeviceByFilter<sup>9+</sup>

selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors, callback: AsyncCallback&lt;void&gt;): void

**系统接口：** 该接口为系统接口

根据过滤条件，选择音频输出设备，当前只能选择一个输出设备，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| filter                      | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件类。               |
| outputAudioDevices          | [AudioDeviceDescriptors](#audiodevicedescriptors)            | 是   | 输出设备类。               |
| callback                    | AsyncCallback&lt;void&gt;                                    | 是   | 回调，返回获取输出设备结果。 |

**示例：**
```js
let outputAudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    content : audio.ContentType.CONTENT_TYPE_MUSIC,
    usage : audio.StreamUsage.STREAM_USAGE_MEDIA,
    rendererFlags : 0 },
  rendererId : 0 };
  
let outputAudioDeviceDescriptor = [{
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
}];

async function selectOutputDeviceByFilter(){
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor, (err) => {
    if (err) {
      console.error(`Result ERROR: ${err}`);
    } else {
      console.info('Select output devices by filter result callback: SUCCESS'); }
  });
}
```

### selectOutputDeviceByFilter<sup>9+</sup>

selectOutputDeviceByFilter(filter: AudioRendererFilter, outputAudioDevices: AudioDeviceDescriptors): Promise&lt;void&gt;

**系统接口：** 该接口为系统接口

根据过滤条件，选择音频输出设备，当前只能选择一个输出设备，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| filter                | [AudioRendererFilter](#audiorendererfilter9)                 | 是   | 过滤条件类。               |
| outputAudioDevices    | [AudioDeviceDescriptors](#audiodevicedescriptors)            | 是   | 输出设备类。               |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;void&gt;   | Promise返回选择输出设备结果。 |

**示例：**

```js
let outputAudioRendererFilter = {
  uid : 20010041,
  rendererInfo : {
    content : audio.ContentType.CONTENT_TYPE_MUSIC,
    usage : audio.StreamUsage.STREAM_USAGE_MEDIA,
    rendererFlags : 0 },
  rendererId : 0 };

let outputAudioDeviceDescriptor = [{
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
}];

async function selectOutputDeviceByFilter(){
  audioRoutingManager.selectOutputDeviceByFilter(outputAudioRendererFilter, outputAudioDeviceDescriptor).then(() => {
    console.info('Select output devices by filter result promise: SUCCESS');
  }).catch((err) => {
    console.error(`Result ERROR: ${err}`);
  })
}
```

## AudioRendererChangeInfoArray<sup>9+</sup>

数组类型，AudioRenderChangeInfo数组，只读。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

## AudioRendererChangeInfo<sup>9+</sup>

描述音频渲染器更改信息。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称               | 类型                                       | 可读 | 可写 | 说明                          |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| streamId           | number                                    | 是   | 否   | 音频流唯一id。                |
| clientUid          | number                                    | 是   | 否   | 音频渲染器客户端应用程序的Uid。<br/>此接口为系统接口。 |
| rendererInfo       | [AudioRendererInfo](#audiorendererinfo8)  | 是   | 否   | 音频渲染器信息。               |
| rendererState      | [AudioState](#audiostate)                 | 是   | 否   | 音频状态。<br/>此接口为系统接口。|

**示例：**

```js

import audio from '@ohos.multimedia.audio';

const audioManager = audio.getAudioManager();
let audioStreamManager = audioManager.getStreamManager();
let resultFlag = false;

audioStreamManager.on('audioRendererChange',  (AudioRendererChangeInfoArray) => {
  for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
    console.info(`## RendererChange on is called for ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioRendererChangeInfoArray[i].streamId}`);
    console.info(`ClientUid for ${i} is: ${AudioRendererChangeInfoArray[i].clientUid}`);
    console.info(`Content for ${i} is: ${AudioRendererChangeInfoArray[i].rendererInfo.content}`);
    console.info(`Stream for ${i} is: ${AudioRendererChangeInfoArray[i].rendererInfo.usage}`);
    console.info(`Flag ${i} is: ${AudioRendererChangeInfoArray[i].rendererInfo.rendererFlags}`);
    console.info(`State for ${i} is: ${AudioRendererChangeInfoArray[i].rendererState}`);
  	let devDescriptor = AudioRendererChangeInfoArray[i].deviceDescriptors;
  	for (let j = 0; j < AudioRendererChangeInfoArray[i].deviceDescriptors.length; j++) {
  	  console.info(`Id: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].id}`);
  	  console.info(`Type: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
  	  console.info(`Role: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
  	  console.info(`Name: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].name}`);
  	  console.info(`Addr: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].address}`);
  	  console.info(`SR: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
  	  console.info(`C ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
  	  console.info(`CM: ${i} : ${AudioRendererChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
  	}
    if (AudioRendererChangeInfoArray[i].rendererState == 1 && devDescriptor != null) {
      resultFlag = true;
      console.info(`ResultFlag for ${i} is: ${resultFlag}`);
    }
  }
});
```


## AudioCapturerChangeInfoArray<sup>9+</sup>

数组类型，AudioCapturerChangeInfo数组，只读。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

## AudioCapturerChangeInfo<sup>9+</sup>

描述音频采集器更改信息。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称               | 类型                                       | 可读 | 可写 | 说明                          |
| -------------------| ----------------------------------------- | ---- | ---- | ---------------------------- |
| streamId           | number                                    | 是   | 否   | 音频流唯一id。                |
| clientUid          | number                                    | 是   | 否   | 音频采集器客户端应用程序的Uid。<br/>此接口为系统接口。 |
| capturerInfo       | [AudioCapturerInfo](#audiocapturerinfo8)  | 是   | 否   | 音频采集器信息。               |
| capturerState      | [AudioState](#audiostate)                 | 是   | 否   | 音频状态。<br/>此接口为系统接口。|

**示例：**

```js
import audio from '@ohos.multimedia.audio';

const audioManager = audio.getAudioManager();
let audioStreamManager = audioManager.getStreamManager();

let resultFlag = false;
audioStreamManager.on('audioCapturerChange', (AudioCapturerChangeInfoArray) =>  {
  for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
    console.info(`## CapChange on is called for element ${i} ##`);
    console.info(`StrId for  ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
    console.info(`CUid for ${i} is: ${AudioCapturerChangeInfoArray[i].clientUid}`);
    console.info(`Src for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
    console.info(`Flag ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
    console.info(`State for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerState}`);
    let devDescriptor = AudioCapturerChangeInfoArray[i].deviceDescriptors;
    for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
      console.info(`Addr: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
      console.info(`SR: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
      console.info(`C ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
      console.info(`CM ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
    }
    if (AudioCapturerChangeInfoArray[i].capturerState == 1 && devDescriptor != null) {
      resultFlag = true;
      console.info(`ResultFlag for element ${i} is: ${resultFlag}`);
    }
  }
});
```

## AudioDeviceDescriptors

设备属性数组类型，为[AudioDeviceDescriptor](#audiodevicedescriptor)的数组，只读。

## AudioDeviceDescriptor

描述音频设备。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称                          | 类型                       | 可读 | 可写 | 说明       |
| ----------------------------- | -------------------------- | ---- | ---- | ---------- |
| deviceRole                    | [DeviceRole](#devicerole)  | 是   | 否   | 设备角色。 |
| deviceType                    | [DeviceType](#devicetype)  | 是   | 否   | 设备类型。 |
| id<sup>9+</sup>               | number                     | 是   | 否   | 设备id。  |
| name<sup>9+</sup>             | string                     | 是   | 否   | 设备名称。 |
| address<sup>9+</sup>          | string                     | 是   | 否   | 设备地址。 |
| sampleRates<sup>9+</sup>      | Array&lt;number&gt;        | 是   | 否   | 支持的采样率。 |
| channelCounts<sup>9+</sup>    | Array&lt;number&gt;        | 是   | 否   | 支持的通道数。 |
| channelMasks<sup>9+</sup>     | Array&lt;number&gt;        | 是   | 否   | 支持的通道掩码。 |
| networkId<sup>9+</sup>        | string                     | 是   | 否   | 设备组网的ID。<br/>此接口为系统接口。 |
| interruptGroupId<sup>9+</sup> | number                     | 是   | 否   | 设备所处的焦点组ID。<br/>此接口为系统接口。 |
| volumeGroupId<sup>9+</sup>    | number                     | 是   | 否   | 设备所处的音量组ID。<br/>此接口为系统接口。 |

**示例：**

```js
import audio from '@ohos.multimedia.audio';

function displayDeviceProp(value) {
  deviceRoleValue = value.deviceRole;
  deviceTypeValue = value.deviceType;
}

let deviceRoleValue = null;
let deviceTypeValue = null;
const promise = audio.getAudioManager().getDevices(1);
promise.then(function (value) {
  console.info('AudioFrameworkTest: Promise: getDevices OUTPUT_DEVICES_FLAG');
  value.forEach(displayDeviceProp);
  if (deviceTypeValue != null && deviceRoleValue != null){
    console.info('AudioFrameworkTest: Promise: getDevices : OUTPUT_DEVICES_FLAG :  PASS');
  } else {
    console.error('AudioFrameworkTest: Promise: getDevices : OUTPUT_DEVICES_FLAG :  FAIL');
  }
});
```

## AudioRendererFilter<sup>9+</sup>

过滤条件类。在调用selectOutputDeviceByFilter接口前，需要先创建AudioRendererFilter实例。

**系统接口：** 该接口为系统接口

| 名称          | 类型                                     | 必填 | 说明          |
| -------------| ---------------------------------------- | ---- | -------------- |
| uid          | number                                   |  是  | 表示应用ID。<br> **系统能力：** SystemCapability.Multimedia.Audio.Core|
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) |  否  | 表示渲染器信息。<br> **系统能力：** SystemCapability.Multimedia.Audio.Renderer|
| rendererId   | number                                   |  否  | 音频流唯一id。<br> **系统能力：** SystemCapability.Multimedia.Audio.Renderer|

**示例：**

```js
let outputAudioRendererFilter = {
  "uid":20010041,
  "rendererInfo": {
    "contentType":audio.ContentType.CONTENT_TYPE_MUSIC,
    "streamUsage":audio.StreamUsage.STREAM_USAGE_MEDIA,
    "rendererFlags":0 },
  "rendererId":0 };
```

## AudioRenderer<sup>8+</sup>

提供音频渲染的相关接口。在调用AudioRenderer的接口前，需要先通过[createAudioRenderer](#audiocreateaudiorenderer8)创建实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称  | 类型                     | 可读 | 可写 | 说明               |
| ----- | -------------------------- | ---- | ---- | ------------------ |
| state<sup>8+</sup> | [AudioState](#audiostate8) | 是   | 否   | 音频渲染器的状态。 |

**示例：**

```js
let state = audioRenderer.state;
```

### getRendererInfo<sup>8+</sup>

getRendererInfo(callback: AsyncCallback<AudioRendererInfo\>): void

获取当前被创建的音频渲染器的信息，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                     | 必填 | 说明                   |
| :------- | :------------------------------------------------------- | :--- | :--------------------- |
| callback | AsyncCallback<[AudioRendererInfo](#audiorendererinfo8)\> | 是   | 返回音频渲染器的信息。 |

**示例：**

```js
audioRenderer.getRendererInfo((err, rendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`);
});
```

### getRendererInfo<sup>8+</sup>

getRendererInfo(): Promise<AudioRendererInfo\>

获取当前被创建的音频渲染器的信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                               | 说明                            |
| -------------------------------------------------- | ------------------------------- |
| Promise<[AudioRendererInfo](#audiorendererinfo8)\> | Promise用于返回音频渲染器信息。 |

**示例：**

```js
audioRenderer.getRendererInfo().then((rendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`)
}).catch((err) => {
  console.error(`AudioFrameworkRenderLog: RendererInfo :ERROR: ${err}`);
});
```

### getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

获取音频流信息，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                 |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | 是   | 回调返回音频流信息。 |

**示例：**

```js
audioRenderer.getStreamInfo((err, streamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
});
```

### getStreamInfo<sup>8+</sup>

getStreamInfo(): Promise<AudioStreamInfo\>

获取音频流信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                   |
| :--------------------------------------------- | :--------------------- |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | Promise返回音频流信息. |

**示例：**

```js
audioRenderer.getStreamInfo().then((streamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(callback: AsyncCallback<number\>): void

获取音频流id，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                 |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<number\> | 是   | 回调返回音频流id。 |

**示例：**

```js
audioRenderer.getAudioStreamId((err, streamid) => {
  console.info(`Renderer GetStreamId: ${streamid}`);
});
```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(): Promise<number\>

获取音频流id，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                   |
| :--------------------------------------------- | :--------------------- |
| Promise<number\> | Promise返回音频流id。 |

**示例：**

```js
audioRenderer.getAudioStreamId().then((streamid) => {
  console.info(`Renderer getAudioStreamId: ${streamid}`);
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

启动音频渲染器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。 |

**示例：**

```js
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

启动音频渲染器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```js
audioRenderer.start().then(() => {
  console.info('Renderer started');
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

暂停渲染。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

```js
audioRenderer.pause((err) => {
  if (err) {
    console.error('Renderer pause failed');
  } else {
    console.info('Renderer paused.');
  }
});
```

### pause<sup>8+</sup>

pause(): Promise\<void>

暂停渲染。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```js
audioRenderer.pause().then(() => {
  console.info('Renderer paused');
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### drain<sup>8+</sup>

drain(callback: AsyncCallback\<void>): void

检查缓冲区是否已被耗尽。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

```js
audioRenderer.drain((err) => {
  if (err) {
    console.error('Renderer drain failed');
  } else {
    console.info('Renderer drained.');
  }
});
```

### drain<sup>8+</sup>

drain(): Promise\<void>

检查缓冲区是否已被耗尽。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```js
audioRenderer.drain().then(() => {
  console.info('Renderer drained successfully');
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

停止渲染。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

```js
audioRenderer.stop((err) => {
  if (err) {
    console.error('Renderer stop failed');
  } else {
    console.info('Renderer stopped.');
  }
});
```

### stop<sup>8+</sup>

stop(): Promise\<void>

停止渲染。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```js
audioRenderer.stop().then(() => {
  console.info('Renderer stopped successfully');
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

释放音频渲染器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

```js
audioRenderer.release((err) => {
  if (err) {
    console.error('Renderer release failed');
  } else {
    console.info('Renderer released.');
  }
});
```

### release<sup>8+</sup>

release(): Promise\<void>

释放渲染器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```js
audioRenderer.release().then(() => {
  console.info('Renderer released successfully');
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### write<sup>8+</sup>

write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void

写入缓冲区。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| buffer   | ArrayBuffer            | 是   | 要写入缓冲区的数据。                                |
| callback | AsyncCallback\<number> | 是   | 回调如果成功，返回写入的字节数，否则返回errorcode。 |

**示例：**

```js
let bufferSize;
audioRenderer.getBufferSize().then((data)=> {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  }).catch((err) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
  });
console.info(`Buffer size: ${bufferSize}`);
let context = featureAbility.getContext();
let path;
async function getCacheDir(){
  path = await context.getCacheDir();
}
let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
let ss = fileio.createStreamSync(filePath, 'r');
let buf = new ArrayBuffer(bufferSize);
ss.readSync(buf);
audioRenderer.write(buf, (err, writtenbytes) => {
  if (writtenbytes < 0) {
    console.error('write failed.');
  } else {
    console.info(`Actual written bytes: ${writtenbytes}`);
  }
});
```

### write<sup>8+</sup>

write(buffer: ArrayBuffer): Promise\<number>

写入缓冲区。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise返回结果，如果成功，返回写入的字节数，否则返回errorcode。 |

**示例：**

```js
let bufferSize;
audioRenderer.getBufferSize().then((data) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  }).catch((err) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
  });
console.info(`BufferSize: ${bufferSize}`);
let context = featureAbility.getContext();
let path;
async function getCacheDir(){
  path = await context.getCacheDir();
}
let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
let ss = fileio.createStreamSync(filePath, 'r');
let buf = new ArrayBuffer(bufferSize);
ss.readSync(buf);
audioRenderer.write(buf).then((writtenbytes) => {
  if (writtenbytes < 0) {
      console.error('write failed.');
  } else {
      console.info(`Actual written bytes: ${writtenbytes}`);
  }
}).catch((err) => {
    console.error(`ERROR: ${err}`);
});
```

### getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback\<number>): void

获取时间戳（从 1970 年 1 月 1 日开始）。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明             |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<number> | 是   | 回调返回时间戳。 |

**示例：**

```js
audioRenderer.getAudioTime((err, timestamp) => {
  console.info(`Current timestamp: ${timestamp}`);
});
```

### getAudioTime<sup>8+</sup>

getAudioTime(): Promise\<number>

获取时间戳（从 1970 年 1 月 1 日开始）。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 描述                    |
| ---------------- | ----------------------- |
| Promise\<number> | Promise回调返回时间戳。 |

**示例：**

```js
audioRenderer.getAudioTime().then((timestamp) => {
  console.info(`Current timestamp: ${timestamp}`);
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback\<number>): void

获取音频渲染器的最小缓冲区大小。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<number> | 是   | 回调返回缓冲区大小。 |

**示例：**

```js
let bufferSize = audioRenderer.getBufferSize(async(err, bufferSize) => {
  if (err) {
    console.error('getBufferSize error');
  }
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(): Promise\<number>

获取音频渲染器的最小缓冲区大小。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise\<number> | promise回调返回缓冲区大小。 |

**示例：**

```js
let bufferSize;
audioRenderer.getBufferSize().then((data) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
}).catch((err) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});
```

### setRenderRate<sup>8+</sup>

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void

设置音频渲染速率。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| rate     | [AudioRendererRate](#audiorendererrate8) | 是   | 渲染的速率。             |
| callback | AsyncCallback\<void>                     | 是   | 用于返回执行结果的回调。 |

**示例：**

```js
audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL, (err) => {
  if (err) {
    console.error('Failed to set params');
  } else {
    console.info('Callback invoked to indicate a successful render rate setting.');
  }
});
```

### setRenderRate<sup>8+</sup>

setRenderRate(rate: AudioRendererRate): Promise\<void>

设置音频渲染速率。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型                                     | 必填 | 说明         |
| ------ | ---------------------------------------- | ---- | ------------ |
| rate   | [AudioRendererRate](#audiorendererrate8) | 是   | 渲染的速率。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise用于返回执行结果。 |

**示例：**

```js
audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL).then(() => {
  console.info('setRenderRate SUCCESS');
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### getRenderRate<sup>8+</sup>

getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void

获取当前渲染速率。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明               |
| -------- | ------------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback<[AudioRendererRate](#audiorendererrate8)> | 是   | 回调返回渲染速率。 |

**示例：**

```js
audioRenderer.getRenderRate((err, renderrate) => {
  console.info(`getRenderRate: ${renderrate}`);
});
```

### getRenderRate<sup>8+</sup>

getRenderRate(): Promise\<AudioRendererRate>

获取当前渲染速率。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                              | 说明                      |
| ------------------------------------------------- | ------------------------- |
| Promise<[AudioRendererRate](#audiorendererrate8)> | Promise回调返回渲染速率。 |

**示例：**

```js
audioRenderer.getRenderRate().then((renderRate) => {
  console.info(`getRenderRate: ${renderRate}`);
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```
### setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode): Promise&lt;void&gt;

设置应用的焦点模型。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名     | 类型                                | 必填   | 说明        |
| ---------- | ---------------------------------- | ------ | ---------- |
| mode       | [InterruptMode](#interruptmode9)    | 是     | 焦点模型。  |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | 以Promise对象返回结果，设置成功时返回undefined，否则返回error。 |

**示例：**

```js
let mode = 0;
audioRenderer.setInterruptMode(mode).then(data=>{
  console.info('setInterruptMode Success!');
}).catch((err) => {
  console.error(`setInterruptMode Fail: ${err}`);
});
```
### setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void

设置应用的焦点模型。使用Callback回调返回执行结果。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名   | 类型                                | 必填   | 说明            |
| ------- | ----------------------------------- | ------ | -------------- |
|mode     | [InterruptMode](#interruptmode9)     | 是     | 焦点模型。|
|callback | AsyncCallback\<void>                 | 是     |回调返回执行结果。|

**示例：**

```js
let mode = 1;
audioRenderer.setInterruptMode(mode, (err, data)=>{
  if(err){
    console.error(`setInterruptMode Fail: ${err}`);
  }
  console.info('setInterruptMode Success!');
});
```

### setVolume<sup>9+</sup>

setVolume(volume: number): Promise&lt;void&gt;

设置应用的音量。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型    | 必填   | 说明                 |
| ---------- | ------- | ------ | ------------------- |
| volume     | number  | 是     | 音量值范围为0.0-1.0。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | 以Promise对象返回结果，设置成功时返回undefined，否则返回error。 |

**示例：**

```js
audioRenderer.setVolume(0.5).then(data=>{
  console.info('setVolume Success!');
}).catch((err) => {
  console.error(`setVolume Fail: ${err}`);
});
```
### setVolume<sup>9+</sup>

setVolume(volume: number, callback: AsyncCallback\<void>): void

设置应用的音量。使用Callback回调返回执行结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名  | 类型       | 必填   | 说明                 |
| ------- | -----------| ------ | ------------------- |
|volume   | number     | 是     | 音量值范围为0.0-1.0。 |
|callback | AsyncCallback\<void> | 是     |回调返回执行结果。|

**示例：**

```js
audioRenderer.setVolume(0.5, (err, data)=>{
  if(err){
    console.error(`setVolume Fail: ${err}`);
  }
  console.info('setVolume Success!');
});
```

### on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void

监听音频中断事件。使用callback获取中断事件。

与[on('interrupt')](#oninterruptdeprecated)一致，该接口在AudioRenderer对象start、pause、stop等事件发生前已经主动获取焦点，不需要开发者主动发起焦点申请。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                                         |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                       | 是   | 事件回调类型，支持的事件为：'audioInterrupt'（中断事件被触发，音频播放被中断。） |
| callback | Callback<[InterruptEvent](#interruptevent9)> | 是   | 被监听的中断事件的回调。                                     |

**错误码：**

以下错误码的详细介绍请参见[音频错误码](../errorcodes/errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | if input parameter value error              |

**示例：**

```js
let isPlay;
let started;
onAudioInterrupt();

async function onAudioInterrupt(){
  audioRenderer.on('audioInterrupt', async(interruptEvent) => {
    if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
          console.info('Force paused. Stop writing');
          isPlay = false;
          break;
        case audio.InterruptHint.INTERRUPT_HINT_STOP:
          console.info('Force stopped. Stop writing');
          isPlay = false;
          break;
      }
    } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_RESUME:
          console.info('Resume force paused renderer or ignore');
          await audioRenderer.start().then(async function () {
            console.info('AudioInterruptMusic: renderInstant started :SUCCESS ');
            started = true;
          }).catch((err) => {
            console.error(`AudioInterruptMusic: renderInstant start :ERROR : ${err}`);
            started = false;
          });
          if (started) {
            isPlay = true;
            console.info(`AudioInterruptMusic Renderer started : isPlay : ${isPlay}`);
          } else {
            console.error('AudioInterruptMusic Renderer start failed');
          }
          break;
        case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
          console.info('Choose to pause or ignore');
          if (isPlay == true) {
            isPlay == false;
            console.info('AudioInterruptMusic: Media PAUSE : TRUE');
          } else {
            isPlay = true;
            console.info('AudioInterruptMusic: Media PLAY : TRUE');
          }
          break;
      }
   }
  });
}
```

### on('markReach')<sup>8+</sup>

on(type: "markReach", frame: number, callback: Callback&lt;number&gt;): void

订阅到达标记的事件。 当渲染的帧数达到 frame 参数的值时，回调被调用。

**系统能力:** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                      |
| :------- | :----------------------- | :--- | :---------------------------------------- |
| type     | string                   | 是   | 事件回调类型，支持的事件为：'markReach'。 |
| frame    | number                   | 是   | 触发事件的帧数。 该值必须大于 0。         |
| callback | Callback\<number>         | 是   | 触发事件时调用的回调。                    |

**示例：**

```js
audioRenderer.on('markReach', 1000, (position) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```


### off('markReach') <sup>8+</sup>

off(type: 'markReach'): void

取消订阅标记事件。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| :----- | :----- | :--- | :------------------------------------------------ |
| type   | string | 是   | 要取消订阅事件的类型。支持的事件为：'markReach'。 |

**示例：**

```js
audioRenderer.off('markReach');
```

### on('periodReach') <sup>8+</sup>

on(type: "periodReach", frame: number, callback: Callback&lt;number&gt;): void

订阅到达标记的事件。 当渲染的帧数达到 frame 参数的值时，触发回调并返回设定的值。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                        |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | 是   | 事件回调类型，支持的事件为：'periodReach'。 |
| frame    | number                   | 是   | 触发事件的帧数。 该值必须大于 0。           |
| callback | Callback\<number>         | 是   | 触发事件时调用的回调。                      |

**示例：**

```js
audioRenderer.on('periodReach', 1000, (position) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```

### off('periodReach') <sup>8+</sup>

off(type: 'periodReach'): void

取消订阅标记事件。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                |
| :----- | :----- | :--- | :-------------------------------------------------- |
| type   | string | 是   | 要取消订阅事件的类型。支持的事件为：'periodReach'。 |

**示例：**

```js
audioRenderer.off('periodReach')
```

### on('stateChange') <sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

订阅监听状态变化。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'stateChange'。 |
| callback | Callback\<[AudioState](#audiostate8)> | 是   | 返回监听的状态。                            |

**示例：**

```js
audioRenderer.on('stateChange', (state) => {
  if (state == 1) {
    console.info('audio renderer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio renderer state is: STATE_RUNNING');
  }
});
```

## AudioCapturer<sup>8+</sup>

提供音频采集的相关接口。在调用AudioCapturer的接口前，需要先通过[createAudioCapturer](#audiocreateaudiocapturer8)创建实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称  | 类型                     | 可读 | 可写 | 说明             |
| :---- | :------------------------- | :--- | :--- | :--------------- |
| state<sup>8+</sup>  | [AudioState](#audiostate8) | 是 | 否   | 音频采集器状态。 |

**示例：**

```js
let state = audioCapturer.state;
```

### getCapturerInfo<sup>8+</sup>

getCapturerInfo(callback: AsyncCallback<AudioCapturerInfo\>): void

获取采集器信息。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                 |
| :------- | :-------------------------------- | :--- | :----------------------------------- |
| callback | AsyncCallback<AudioCapturerInfo\> | 是   | 使用callback方式异步返回采集器信息。 |

**示例：**

```js
audioCapturer.getCapturerInfo((err, capturerInfo) => {
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

获取采集器信息。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型                                              | 说明                                |
| :------------------------------------------------ | :---------------------------------- |
| Promise<[AudioCapturerInfo](#audiocapturerinfo)\> | 使用Promise方式异步返回采集器信息。 |

**示例：**

```js
audioCapturer.getCapturerInfo().then((audioParamsGet) => {
  if (audioParamsGet != undefined) {
    console.info('AudioFrameworkRecLog: Capturer CapturerInfo:');
    console.info(`AudioFrameworkRecLog: Capturer SourceType: ${audioParamsGet.source}`);
    console.info(`AudioFrameworkRecLog: Capturer capturerFlags: ${audioParamsGet.capturerFlags}`);
  } else {
    console.info(`AudioFrameworkRecLog: audioParamsGet is : ${audioParamsGet}`);
    console.info('AudioFrameworkRecLog: audioParams getCapturerInfo are incorrect');
  }
}).catch((err) => {
  console.error(`AudioFrameworkRecLog: CapturerInfo :ERROR: ${err}`);
});
```

### getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

获取采集器流信息。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                             |
| :------- | :--------------------------------------------------- | :--- | :------------------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | 是   | 使用callback方式异步返回流信息。 |

**示例：**

```js
audioCapturer.getStreamInfo((err, streamInfo) => {
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

获取采集器流信息。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型                                           | 说明                            |
| :--------------------------------------------- | :------------------------------ |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | 使用Promise方式异步返回流信息。 |

**示例：**

```js
audioCapturer.getStreamInfo().then((audioParamsGet) => {
  console.info('getStreamInfo:');
  console.info(`sampleFormat: ${audioParamsGet.sampleFormat}`);
  console.info(`samplingRate: ${audioParamsGet.samplingRate}`);
  console.info(`channels: ${audioParamsGet.channels}`);
  console.info(`encodingType: ${audioParamsGet.encodingType}`);
}).catch((err) => {
  console.error(`getStreamInfo :ERROR: ${err}`);
});
```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(callback: AsyncCallback<number\>): void

获取音频流id，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                 |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<number\> | 是   | 回调返回音频流id。 |

**示例：**

```js
audioCapturer.getAudioStreamId((err, streamid) => {
  console.info(`audioCapturer GetStreamId: ${streamid}`);
});
```

### getAudioStreamId<sup>9+</sup>

getAudioStreamId(): Promise<number\>

获取音频流id，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型             | 说明                   |
| :----------------| :--------------------- |
| Promise<number\> | Promise返回音频流id。 |

**示例：**

```js
audioCapturer.getAudioStreamId().then((streamid) => {
  console.info(`audioCapturer getAudioStreamId: ${streamid}`);
}).catch((err) => {
  console.error(`ERROR: ${err}`);
});
```

### start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

启动音频采集器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 使用callback方式异步返回结果。 |

**示例：**

```js
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

启动音频采集器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
audioCapturer.start().then(() => {
  console.info('AudioFrameworkRecLog: ---------START---------');
  console.info('AudioFrameworkRecLog: Capturer started: SUCCESS');
  console.info(`AudioFrameworkRecLog: AudioCapturer: STATE: ${audioCapturer.state}`);
  console.info('AudioFrameworkRecLog: Capturer started: SUCCESS');
  if ((audioCapturer.state == audio.AudioState.STATE_RUNNING)) {
    console.info('AudioFrameworkRecLog: AudioCapturer is in Running State');
  }
}).catch((err) => {
  console.info(`AudioFrameworkRecLog: Capturer start :ERROR : ${err}`);
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback<void\>): void

停止采集。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 使用callback方式异步返回结果。 |

**示例：**

```js
audioCapturer.stop((err) => {
  if (err) {
    console.error('Capturer stop failed');
  } else {
    console.info('Capturer stopped.');
  }
});
```


### stop<sup>8+</sup>

stop(): Promise<void\>

停止采集。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
audioCapturer.stop().then(() => {
  console.info('AudioFrameworkRecLog: ---------STOP RECORD---------');
  console.info('AudioFrameworkRecLog: Capturer stopped: SUCCESS');
  if ((audioCapturer.state == audio.AudioState.STATE_STOPPED)){
    console.info('AudioFrameworkRecLog: State is Stopped:');
  }
}).catch((err) => {
  console.info(`AudioFrameworkRecLog: Capturer stop: ERROR: ${err}`);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback<void\>): void

释放采集器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                |
| :------- | :------------------- | :--- | :---------------------------------- |
| callback | AsyncCallback<void\> | 是   | Callback used to return the result. |

**示例：**

```js
audioCapturer.release((err) => {
  if (err) {
    console.error('capturer release failed');
  } else {
    console.info('capturer released.');
  }
});
```


### release<sup>8+</sup>

release(): Promise<void\>

释放采集器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
let stateFlag;
audioCapturer.release().then(() => {
  console.info('AudioFrameworkRecLog: ---------RELEASE RECORD---------');
  console.info('AudioFrameworkRecLog: Capturer release : SUCCESS');
  console.info(`AudioFrameworkRecLog: AudioCapturer : STATE : ${audioCapturer.state}`);
  console.info(`AudioFrameworkRecLog: stateFlag : ${stateFlag}`);
}).catch((err) => {
  console.info(`AudioFrameworkRecLog: Capturer stop: ERROR: ${err}`);
});
```

### read<sup>8+</sup>

read(size: number, isBlockingRead: boolean, callback: AsyncCallback<ArrayBuffer\>): void

读入缓冲区。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名         | 类型                        | 必填 | 说明                             |
| :------------- | :-------------------------- | :--- | :------------------------------- |
| size           | number                      | 是   | 读入的字节数。                   |
| isBlockingRead | boolean                     | 是   | 是否阻塞读操作。                 |
| callback       | AsyncCallback<ArrayBuffer\> | 是   | 使用callback方式异步返回缓冲区。 |

**示例：**

```js
let bufferSize;
audioCapturer.getBufferSize().then((data) => {
  console.info(`AudioFrameworkRecLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  }).catch((err) => {
    console.error(`AudioFrameworkRecLog: getBufferSize: ERROR: ${err}`);
  });
audioCapturer.read(bufferSize, true, async(err, buffer) => {
  if (!err) {
    console.info('Success in reading the buffer data');
  }
});
```

### read<sup>8+</sup>

read(size: number, isBlockingRead: boolean): Promise<ArrayBuffer\>

读入缓冲区。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名         | 类型    | 必填 | 说明             |
| :------------- | :------ | :--- | :--------------- |
| size           | number  | 是   | 读入的字节数。   |
| isBlockingRead | boolean | 是   | 是否阻塞读操作。 |

**返回值：**

| 类型                  | 说明                                                   |
| :-------------------- | :----------------------------------------------------- |
| Promise<ArrayBuffer\> | 如果操作成功，返回读取的缓冲区数据；否则返回错误代码。 |

**示例：**

```js
let bufferSize;
audioCapturer.getBufferSize().then((data) => {
  console.info(`AudioFrameworkRecLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  }).catch((err) => {
  console.info(`AudioFrameworkRecLog: getBufferSize: ERROR ${err}`);
  });
console.info(`Buffer size: ${bufferSize}`);
audioCapturer.read(bufferSize, true).then((buffer) => {
  console.info('buffer read successfully');
}).catch((err) => {
  console.info(`ERROR : ${err}`);
});
```

### getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback<number\>): void

获取时间戳（从1970年1月1日开始），单位为纳秒。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                           |
| :------- | :--------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<number\> | 是   | 使用callback方式异步返回结果。 |

**示例：**

```js
audioCapturer.getAudioTime((err, timestamp) => {
  console.info(`Current timestamp: ${timestamp}`);
});
```

### getAudioTime<sup>8+</sup>

getAudioTime(): Promise<number\>

获取时间戳（从1970年1月1日开始），单位为纳秒。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型             | 说明                          |
| :--------------- | :---------------------------- |
| Promise<number\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
audioCapturer.getAudioTime().then((audioTime) => {
  console.info(`AudioFrameworkRecLog: AudioCapturer getAudioTime : Success ${audioTime}`);
}).catch((err) => {
  console.info(`AudioFrameworkRecLog: AudioCapturer Created : ERROR : ${err}`);
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback<number\>): void

获取采集器合理的最小缓冲区大小。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                 |
| :------- | :--------------------- | :--- | :----------------------------------- |
| callback | AsyncCallback<number\> | 是   | 使用callback方式异步返回缓冲区大小。 |

**示例：**

```js
audioCapturer.getBufferSize((err, bufferSize) => {
  if (!err) {
    console.info(`BufferSize : ${bufferSize}`);
    audioCapturer.read(bufferSize, true).then((buffer) => {
      console.info(`Buffer read is ${buffer}`);
    }).catch((err) => {
      console.error(`AudioFrameworkRecLog: AudioCapturer Created : ERROR : ${err}`);
    });
  }
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(): Promise<number\>

获取采集器合理的最小缓冲区大小。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型             | 说明                                |
| :--------------- | :---------------------------------- |
| Promise<number\> | 使用Promise方式异步返回缓冲区大小。 |

**示例：**

```js
let bufferSize;
audioCapturer.getBufferSize().then((data) => {
  console.info(`AudioFrameworkRecLog: getBufferSize :SUCCESS ${data}`);
  bufferSize = data;
}).catch((err) => {
  console.info(`AudioFrameworkRecLog: getBufferSize :ERROR : ${err}`);
});
```

### on('markReach')<sup>8+</sup>

on(type: "markReach", frame: number, callback: Callback&lt;number&gt;): void

订阅标记到达的事件。 当采集的帧数达到 frame 参数的值时，回调被触发。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                       |
| :------- | :----------------------  | :--- | :----------------------------------------- |
| type     | string                   | 是   | 事件回调类型，支持的事件为：'markReach'。  |
| frame    | number                   | 是   | 触发事件的帧数。 该值必须大于0。           |
| callback | Callback\<number>         | 是   | 使用callback方式异步返回被触发事件的回调。 |

**示例：**

```js
audioCapturer.on('markReach', 1000, (position) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```

### off('markReach')<sup>8+</sup>

off(type: 'markReach'): void

取消订阅标记到达的事件。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                          |
| :----- | :----- | :--- | :-------------------------------------------- |
| type   | string | 是   | 取消事件回调类型，支持的事件为：'markReach'。 |

**示例：**

```js
audioCapturer.off('markReach');
```

### on('periodReach')<sup>8+</sup>

on(type: "periodReach", frame: number, callback: Callback&lt;number&gt;): void

订阅到达标记的事件。 当采集的帧数达到 frame 参数的值时，触发回调并返回设定的值。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                        |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | 是   | 事件回调类型，支持的事件为：'periodReach'。 |
| frame    | number                   | 是   | 触发事件的帧数。 该值必须大于0。            |
| callback | Callback\<number>         | 是   | 使用callback方式异步返回被触发事件的回调    |

**示例：**

```js
audioCapturer.on('periodReach', 1000, (position) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```

### off('periodReach')<sup>8+</sup>

off(type: 'periodReach'): void

取消订阅标记到达的事件。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                            |
| :----- | :----- | :--- | :---------------------------------------------- |
| type   | string | 是  | 取消事件回调类型，支持的事件为：'periodReach'。 |

**示例：**

```js
audioCapturer.off('periodReach')
```

### on('stateChange') <sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

订阅监听状态变化。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为：'stateChange'。 |
| callback | Callback\<[AudioState](#audiostate8)> | 是   | 返回监听的状态。                            |

**示例：**

```js
audioCapturer.on('stateChange', (state) => {
  if (state == 1) {
    console.info('audio capturer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio capturer state is: STATE_RUNNING');
  }
});
```

## ToneType<sup>9+</sup>

枚举，播放器的音调类型。

**系统接口：** 该接口为系统接口

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
| TONE_TYPE_COMMON_PROPRIETARY_BEEP                 | 200    | 专有声调，一般蜂鸣声。          |
| TONE_TYPE_COMMON_PROPRIETARY_ACK                  | 201    | 专有声调，ACK。                |
| TONE_TYPE_COMMON_PROPRIETARY_PROMPT               | 203    | 专有声调，PROMPT。             |
| TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP          | 204    | 专有声调，双重蜂鸣声。          |

## TonePlayer<sup>9+</sup>

提供播放和管理DTMF（Dual Tone Multi Frequency，双音多频）音调的方法，包括各种系统监听音调、专有音调，如拨号音、通话回铃音等。

**系统接口：** 该接口为系统接口

### load<sup>9+</sup>

load(type: ToneType, callback: AsyncCallback&lt;void&gt;): void

加载DTMF音调配置。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名          | 类型                        | 必填  | 说明                            |
| :--------------| :-------------------------- | :-----| :------------------------------ |
| type           | [ToneType](#tonetype9)       | 是    | 配置的音调类型。                 |
| callback       | AsyncCallback<void\>        | 是    | 使用callback方式异步返回结果。 |

**示例：**

```js
tonePlayer.load(audio.ToneType.TONE_TYPE_DIAL_5, (err) => {
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

加载DTMF音调配置。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名         | 类型                    | 必填  |  说明             |
| :------------- | :--------------------- | :---  | ---------------- |
| type           | [ToneType](#tonetype9)   | 是    | 配置的音调类型。  |

**返回值：**

| 类型            | 说明                        |
| :--------------| :-------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
tonePlayer.load(audio.ToneType.TONE_TYPE_DIAL_1).then(() => {
  console.info('promise call load ');
}).catch(() => {
  console.error('promise call load fail');
});
```

### start<sup>9+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

启动DTMF音调播放。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 使用callback方式异步返回结果。 |

**示例：**

```js
tonePlayer.start((err) => {
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

启动DTMF音调播放。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
tonePlayer.start().then(() => {
  console.info('promise call start');
}).catch(() => {
  console.error('promise call start fail');
});
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

停止当前正在播放的音调。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 使用callback方式异步返回结果。 |

**示例：**

```js
tonePlayer.stop((err) => {
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

停止当前正在播放的音调。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
tonePlayer.stop().then(() => {
  console.info('promise call stop finish');
}).catch(() => {
  console.error('promise call stop fail');
});
```

### release<sup>9+</sup>

release(callback: AsyncCallback&lt;void&gt;): void

释放与此TonePlayer对象关联的资源。使用callback方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**参数：**

| 参数名   | 类型                 | 必填 | 说明                            |
| :------- | :------------------- | :--- | :---------------------------- |
| callback | AsyncCallback<void\> | 是   | 使用callback方式异步返回结果。  |

**示例：**

```js
tonePlayer.release((err) => {
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

释放与此TonePlayer对象关联的资源。使用Promise方式异步返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.Audio.Tone

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```js
tonePlayer.release().then(() => {
  console.info('promise call release');
}).catch(() => {
  console.error('promise call release fail');
});
```

## ActiveDeviceType<sup>(deprecated)</sup>

枚举，活跃设备类型。

> **说明：**
> 从 API version 9 开始废弃，建议使用[CommunicationDeviceType](#communicationdevicetype9)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Device

| 名称          |  值     | 说明                                                 |
| ------------- | ------ | ---------------------------------------------------- |
| SPEAKER       | 2      | 扬声器。                                             |
| BLUETOOTH_SCO | 7      | 蓝牙设备SCO（Synchronous Connection Oriented）连接。 |

## InterruptActionType<sup>(deprecated)</sup>

枚举，中断事件返回类型。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称           |  值     | 说明               |
| -------------- | ------ | ------------------ |
| TYPE_ACTIVATED | 0      | 表示触发焦点事件。 |
| TYPE_INTERRUPT | 1      | 表示音频打断事件。 |

## AudioInterrupt<sup>(deprecated)</sup>

音频监听事件传入的参数。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称            | 类型                        | 必填 | 说明                                                         |
| --------------- | --------------------------- | ----| ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](#streamusage) | 是  | 音频流使用类型。                                             |
| contentType     | [ContentType](#contenttype) | 是  | 音频打断媒体类型。                                           |
| pauseWhenDucked | boolean                     | 是  | 音频打断时是否可以暂停音频播放（true表示音频播放可以在音频打断期间暂停，false表示相反）。 |

## InterruptAction<sup>(deprecated)</sup>

音频打断/获取焦点事件的回调方法。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称       | 类型                                        | 必填 | 说明                                                         |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| actionType | [InterruptActionType](#interruptactiontypedeprecated) | 是   | 事件返回类型。TYPE_ACTIVATED为焦点触发事件，TYPE_INTERRUPT为音频打断事件。 |
| type       | [InterruptType](#interrupttype)             | 否   | 打断事件类型。                                               |
| hint       | [InterruptHint](#interrupthint)             | 否   | 打断事件提示。                                               |
| activated  | boolean                                     | 否   | 获得/释放焦点。true表示焦点获取/释放成功，false表示焦点获得/释放失败。 |
