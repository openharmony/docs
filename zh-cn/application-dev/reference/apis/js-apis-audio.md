# 音频管理

音频管理提供管理音频的一些基础能力，包括对音频音量、音频设备的管理，以及对音频数据的采集和渲染等。

该模块提供以下音频相关的常用功能：

- [AudioManager](#audiomanager)：音频管理。
- [AudioRenderer](#audiorenderer8)：音频渲染，用于播放PCM（Pulse Code Modulation）音频数据。
- [AudioCapturer](#audiocapturer8)：音频采集，用于录制PCM音频数据。

>  **说明：**
>  本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import audio from '@ohos.multimedia.audio';
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
```
var audioManager = audio.getAudioManager();
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void

获取音频渲染器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数**：

| 参数名   | 类型                                            | 必填 | 说明             |
| -------- | ----------------------------------------------- | ---- | ---------------- |
| options  | [AudioRendererOptions](#audiorendereroptions8)  | 是   | 配置渲染器。     |
| callback | AsyncCallback<[AudioRenderer](#audiorenderer8)> | 是   | 音频渲染器对象。 |

**示例：**

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

获取音频采集器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                                            | 必填 | 说明             |
| :------- | :---------------------------------------------- | :--- | :--------------- |
| options  | [AudioCapturerOptions](#audiocaptureroptions8)  | 是   | 配置音频采集器。 |
| callback | AsyncCallback<[AudioCapturer](#audiocapturer8)> | 是   | 音频采集器对象。 |

**示例：**

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

获取音频采集器。使用promise 方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名  | 类型                                           | 必填 | 说明             |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| options | [AudioCapturerOptions](#audiocaptureroptions8) | 是   | 配置音频采集器。 |

**返回值：**

| 类型                                      | 说明           |
| ----------------------------------------- | -------------- |
| Promise<[AudioCapturer](#audiocapturer8)> | 音频采集器对象 |

**示例：**

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
audio.createAudioCapturer(audioCapturerOptions).then((data) => {
    audioCapturer = data;
    console.info('AudioCapturer Created : Success : Stream Type: SUCCESS');
}).catch((err) => {
    console.info('AudioCapturer Created : ERROR : '+err.message);
});
```

## AudioVolumeType

枚举，音频流类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Volume

| 名称                         | 默认值 | 描述       |
| ---------------------------- | ------ | ---------- |
| VOICE_CALL<sup>8+</sup>      | 0      | 语音电话。 |
| RINGTONE                     | 2      | 铃声。     |
| MEDIA                        | 3      | 媒体。     |
| VOICE_ASSISTANT<sup>8+</sup> | 9      | 语音助手。 |


## InterruptMode<sup>9+</sup>

枚举，焦点模型。

**系统能力：** SystemCapability.Multimedia.Audio.InterruptMode

| 名称                         | 默认值 | 描述       |
| ---------------------------- | ------ | ---------- |
| SHARE_MODE      | 0      | 共享焦点模式。 |
| INDEPENDENT_MODE| 1      | 独立焦点模式。     |

## DeviceFlag

枚举，可获取的设备种类。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Device

| 名称                | 默认值 | 描述       |
| ------------------- | ------ | ---------- |
| OUTPUT_DEVICES_FLAG | 1      | 输出设备。 |
| INPUT_DEVICES_FLAG  | 2      | 输入设备。 |
| ALL_DEVICES_FLAG    | 3      | 所有设备。 |


## DeviceRole

枚举，设备角色。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Device

| 名称          | 默认值 | 描述           |
| ------------- | ------ | -------------- |
| INPUT_DEVICE  | 1      | 输入设备角色。 |
| OUTPUT_DEVICE | 2      | 输出设备角色。 |


## DeviceType

枚举，设备类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Device

| 名称             | 默认值 | 描述                                                      |
| ---------------- | ------ | --------------------------------------------------------- |
| INVALID          | 0      | 无效设备。                                                |
| EARPIECE         | 1      | 听筒。                                                    |
| SPEAKER          | 2      | 扬声器。                                                  |
| WIRED_HEADSET    | 3      | 有线耳机，带麦克风。                                      |
| WIRED_HEADPHONES | 4      | 有线耳机，无麦克风。                                      |
| BLUETOOTH_SCO    | 7      | 蓝牙设备SCO（Synchronous Connection Oriented）连接。      |
| BLUETOOTH_A2DP   | 8      | 蓝牙设备A2DP（Advanced Audio Distribution Profile）连接。 |
| MIC              | 15     | 麦克风。                                                  |
| USB_HEADSET      | 22     | USB耳机，带麦克风。                                       |

## ActiveDeviceType

枚举，活跃设备类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Device

| 名称          | 默认值 | 描述                                                 |
| ------------- | ------ | ---------------------------------------------------- |
| SPEAKER       | 2      | 扬声器。                                             |
| BLUETOOTH_SCO | 7      | 蓝牙设备SCO（Synchronous Connection Oriented）连接。 |

## AudioRingMode

枚举，铃声模式。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Communication

| 名称                | 默认值 | 描述       |
| ------------------- | ------ | ---------- |
| RINGER_MODE_SILENT  | 0      | 静音模式。 |
| RINGER_MODE_VIBRATE | 1      | 震动模式。 |
| RINGER_MODE_NORMAL  | 2      | 响铃模式。 |

## AudioSampleFormat<sup>8+</sup>

枚举，音频采样格式。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称                  | 默认值 | 描述                       |
| --------------------- | ------ | -------------------------- |
| SAMPLE_FORMAT_INVALID | -1     | 无效格式。                 |
| SAMPLE_FORMAT_U8      | 0      | 无符号8位整数。            |
| SAMPLE_FORMAT_S16LE   | 1      | 带符号的16位整数，小尾数。 |
| SAMPLE_FORMAT_S24LE   | 2      | 带符号的24位整数，小尾数。 |
| SAMPLE_FORMAT_S32LE   | 3      | 带符号的32位整数，小尾数。 |

## AudioChannel<sup>8+</sup>

枚举， 音频声道。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称      | 默认值   | 描述     |
| --------- | -------- | -------- |
| CHANNEL_1 | 0x1 << 0 | 单声道。 |
| CHANNEL_2 | 0x1 << 1 | 双声道。 |

## AudioSamplingRate<sup>8+</sup>

枚举，音频采样率。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称              | 默认值 | 描述            |
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

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称                  | 默认值 | 描述      |
| --------------------- | ------ | --------- |
| ENCODING_TYPE_INVALID | -1     | 无效。    |
| ENCODING_TYPE_RAW     | 0      | PCM编码。 |

## ContentType

枚举，音频内容类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称                               | 默认值 | 描述       |
| ---------------------------------- | ------ | ---------- |
| CONTENT_TYPE_UNKNOWN               | 0      | 未知类型。 |
| CONTENT_TYPE_SPEECH                | 1      | 语音。     |
| CONTENT_TYPE_MUSIC                 | 2      | 音乐。     |
| CONTENT_TYPE_MOVIE                 | 3      | 电影。     |
| CONTENT_TYPE_SONIFICATION          | 4      | 加密类型。 |
| CONTENT_TYPE_RINGTONE<sup>8+</sup> | 5      | 铃声。     |

## StreamUsage

枚举，音频流使用类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称                               | 默认值 | 描述       |
| ---------------------------------- | ------ | ---------- |
| STREAM_USAGE_UNKNOWN               | 0      | 未知类型。 |
| STREAM_USAGE_MEDIA                 | 1      | 音频。     |
| STREAM_USAGE_VOICE_COMMUNICATION   | 2      | 语音通信。 |
| STREAM_USAGE_NOTIFICATION_RINGTONE | 6      | 通知铃声。 |

## AudioState<sup>8+</sup>

枚举，音频状态。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称           | 默认值 | 描述             |
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

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称               | 默认值 | 描述       |
| ------------------ | ------ | ---------- |
| RENDER_RATE_NORMAL | 0      | 正常速度。 |
| RENDER_RATE_DOUBLE | 1      | 2倍速。    |
| RENDER_RATE_HALF   | 2      | 0.5倍数。  |

## InterruptType

枚举，中断类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称                 | 默认值 | 描述                   |
| -------------------- | ------ | ---------------------- |
| INTERRUPT_TYPE_BEGIN | 1      | 音频播放中断事件开始。 |
| INTERRUPT_TYPE_END   | 2      | 音频播放中断事件结束。 |

## InterruptForceType<sup>9+</sup>

枚举，强制打断类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称            | 默认值 | 描述                                 |
| --------------- | ------ | ------------------------------------ |
| INTERRUPT_FORCE | 0      | 由系统进行操作，强制打断音频播放。   |
| INTERRUPT_SHARE | 1      | 由应用进行操作，可以选择打断或忽略。 |

## InterruptHint

枚举，中断提示。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称                               | 默认值 | 描述                                         |
| ---------------------------------- | ------ | -------------------------------------------- |
| INTERRUPT_HINT_NONE<sup>8+</sup>   | 0      | 无提示。                                     |
| INTERRUPT_HINT_RESUME              | 1      | 提示音频恢复。                               |
| INTERRUPT_HINT_PAUSE               | 2      | 提示音频暂停。                               |
| INTERRUPT_HINT_STOP                | 3      | 提示音频停止。                               |
| INTERRUPT_HINT_DUCK                | 4      | 提示音频躲避。（躲避：音量减弱，而不会停止） |
| INTERRUPT_HINT_UNDUCK<sup>8+</sup> | 5      | 提示音量恢复。                               |

## InterruptActionType

枚举，中断事件返回类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称           | 默认值 | 描述               |
| -------------- | ------ | ------------------ |
| TYPE_ACTIVATED | 0      | 表示触发焦点事件。 |
| TYPE_INTERRUPT | 1      | 表示音频打断事件。 |

## AudioStreamInfo<sup>8+</sup>

音频流信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称         | 类型                                     | 必填 | 说明               |
| ------------ | ---------------------------------------- | ---- | ------------------ |
| samplingRate | [AudioSamplingRate](#audiosamplingrate8) | 是   | 音频文件的采样率。 |
| channels     | [AudioChannel](#audiochannel8)           | 是   | 音频文件的通道数。 |
| sampleFormat | [AudioSampleFormat](#audiosampleformat8) | 是   | 音频采样格式。     |
| encodingType | [AudioEncodingType](#audioencodingtype8) | 是   | 音频编码格式。     |

## AudioRendererInfo<sup>8+</sup>

音频渲染器信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称          | 类型                        | 必填 | 说明             |
| ------------- | --------------------------- | ---- | ---------------- |
| content       | [ContentType](#contenttype) | 是   | 媒体类型。       |
| usage         | [StreamUsage](#streamusage) | 是   | 音频流使用类型。 |
| rendererFlags | number                      | 是   | 音频渲染器标志。 |

## AudioRendererOptions<sup>8+</sup>

音频渲染器选项信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称         | 类型                                     | 必填 | 说明             |
| ------------ | ---------------------------------------- | ---- | ---------------- |
| streamInfo   | [AudioStreamInfo](#audiostreaminfo8)     | 是   | 表示音频流信息。 |
| rendererInfo | [AudioRendererInfo](#audiorendererinfo8) | 是   | 表示渲染器信息。 |

## InterruptEvent<sup>9+</sup>

播放中断时，应用接收的中断事件。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称      | 类型                                       | 必填 | 说明                                 |
| --------- | ------------------------------------------ | ---- | ------------------------------------ |
| eventType | [InterruptType](#interrupttype)            | 是   | 中断事件类型，开始或是结束。         |
| forceType | [InterruptForceType](#interruptforcetype9) | 是   | 操作是由系统执行或是由应用程序执行。 |
| hintType  | [InterruptHint](#interrupthint)            | 是   | 中断提示。                           |

## AudioInterrupt

音频监听事件传入的参数。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称            | 类型                        | 必填 | 说明                                                         |
| --------------- | --------------------------- | ---- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](#streamusage) | 是   | 音频流使用类型。                                             |
| contentType     | [ContentType](#contenttype) | 是   | 音频打断媒体类型。                                           |
| pauseWhenDucked | boolean                     | 是   | 音频打断时是否可以暂停音频播放（true表示音频播放可以在音频打断期间暂停，false表示相反）。 |

## InterruptAction

音频打断/获取焦点事件的回调方法。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Renderer

| 名称       | 类型                                        | 必填 | 说明                                                         |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| actionType | [InterruptActionType](#interruptactiontype) | 是   | 事件返回类型。TYPE_ACTIVATED为焦点触发事件，TYPE_INTERRUPT为音频打断事件。 |
| type       | [InterruptType](#interrupttype)             | 否   | 打断事件类型。                                               |
| hint       | [InterruptHint](#interrupthint)              | 否   | 打断事件提示。                                               |
| activated  | boolean                                     | 否   | 获得/释放焦点。true表示焦点获取/释放成功，false表示焦点获得/释放失败。 |

## VolumeEvent<sup>8+</sup>

音量改变时，应用接收的事件。

此接口为系统接口，三方应用不支持调用。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Volume

| 名称       | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |
| updateUi   | boolean                             | 是   | 在UI中显示音量变化。                                     |

## DeviceChangeAction

描述设备连接状态变化和设备信息。

**系统能力：**SystemCapability.Multimedia.Audio.Device

| 名称              | 类型                                              | 必填 | 说明               |
| :---------------- | :------------------------------------------------ | :--- | :----------------- |
| type              | [DeviceChangeType](#DeviceChangeType)             | 是   | 设备连接状态变化。 |
| deviceDescriptors | [AudioDeviceDescriptors](#AudioDeviceDescriptors) | 是   | 设备信息。         |

## DeviceChangeType

枚举，设备连接状态变化。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Device

| 名称       | 默认值 | 描述           |
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

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Core

| 名称                            | 默认值 | 描述                   |
| :------------------------------ | :----- | :--------------------- |
| SOURCE_TYPE_INVALID             | -1     | 无效的音频源。         |
| SOURCE_TYPE_MIC                 | 0      | Mic音频源。            |
| SOURCE_TYPE_VOICE_COMMUNICATION | 7      | 语音通话场景的音频源。 |

## AudioScene<sup>8+</sup><a name="audioscene"></a>

枚举，音频场景。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Communication

| 名称                   | 默认值 | 描述                                          |
| :--------------------- | :----- | :-------------------------------------------- |
| AUDIO_SCENE_DEFAULT    | 0      | 默认音频场景。                                |
| AUDIO_SCENE_RINGING    | 1      | 响铃模式。<br/>此接口为系统接口，三方应用不支持调用。 |
| AUDIO_SCENE_PHONE_CALL | 2      | 电话模式。<br/>此接口为系统接口，三方应用不支持调用。 |
| AUDIO_SCENE_VOICE_CHAT | 3      | 语音聊天模式。                                |

## AudioManager

管理音频音量和音频设备。在调用AudioManager的接口前，需要先通过[getAudioManager](#audiogetaudiomanager)创建实例。

### setVolume

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

设置指定流的音量，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                             |
| volume     | number                              | 是   | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调表示成功还是失败。                                   |

**示例：**

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

设置指定流的音量，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

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

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(() => {
    console.log('Promise returned to indicate a successful volume setting.');
});
```

### getVolume

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的音量，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回音量大小。 |

**示例：**

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

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promise returned to indicate that the volume is obtained.' + value);
});
```

### getMinVolume

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最小音量，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回最小音量。 |

**示例：**

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

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promised returned to indicate that the minimum volume is obtained.' + value);
});
```

### getMaxVolume

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最大音量，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                   |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。           |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调返回最大音量大小。 |

**示例：**

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

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data) => {
    console.log('Promised returned to indicate that the maximum volume is obtained.');
});
```

### mute

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定音量流静音，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                  |
| ---------- | ----------------------------------- | ---- | ------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                          |
| mute       | boolean                             | 是   | 静音状态，true为静音，false为非静音。 |
| callback   | AsyncCallback&lt;void&gt;           | 是   | 回调表示成功还是失败。                |

**示例：**

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

设置指定音量流静音，使用Promise方式异步返回结果。

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


```
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() => {
    console.log('Promise returned to indicate that the stream is muted.');
});
```


### isMute

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量流是否被静音，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                            |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                    |
| callback   | AsyncCallback&lt;boolean&gt;        | 是   | 回调返回流静音状态，true为静音，false为非静音。 |

**示例：**

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

```
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promise returned to indicate that the mute status of the stream is obtained.' + value);
});
```

### isActive

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量流是否为活跃状态，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                              |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是   | 音量流类型。                                      |
| callback   | AsyncCallback&lt;boolean&gt;        | 是   | 回调返回流的活跃状态，true为活跃，false为不活跃。 |

**示例：**

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

获取指定音量流是否为活跃状态，使用Promise方式异步返回结果。

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

```
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value) => {
    console.log('Promise returned to indicate that the active status of the stream is obtained.' + value);
});
```

### setRingerMode

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

设置铃声模式，使用callback方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                            | 必填 | 说明                     |
| -------- | ------------------------------- | ---- | ------------------------ |
| mode     | [AudioRingMode](#audioringmode) | 是   | 音频铃声模式。           |
| callback | AsyncCallback&lt;void&gt;       | 是   | 回调返回设置成功或失败。 |

**示例：**

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

设置铃声模式，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.ACCESS_NOTIFICATION_POLICY

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

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() => {
    console.log('Promise returned to indicate a successful setting of the ringer mode.');
});
```


### getRingerMode

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

获取铃声模式，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                     |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](#audioringmode)&gt; | 是   | 回调返回系统的铃声模式。 |

**示例：**

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

获取铃声模式，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**返回值：**

| 类型                                           | 说明                            |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](#audioringmode)&gt; | Promise回调返回系统的铃声模式。 |

**示例：**

```
audioManager.getRingerMode().then((value) => {
    console.log('Promise returned to indicate that the ringer mode is obtained.' + value);
});
```

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

```
audioManager.setAudioParameter('key_example', 'value_example').then(() => {
    console.log('Promise returned to indicate a successful setting of the audio parameter.');
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

```
audioManager.getAudioParameter('key_example').then((value) => {
    console.log('Promise returned to indicate that the value of the audio parameter is obtained.' + value);
});
```

### getDevices

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

获取音频设备列表，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceFlag | [DeviceFlag](#deviceflag)                                    | 是   | 设备类型的flag。     |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | 是   | 回调，返回设备列表。 |

**示例：**
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

```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    console.log('Promise returned to indicate that the device list is obtained.');
});
```

### setDeviceActive

setDeviceActive(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

设置设备激活状态，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                     |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | 是   | 活跃音频设备类型。       |
| active     | boolean                               | 是   | 设备激活状态。           |
| callback   | AsyncCallback&lt;void&gt;             | 是   | 回调返回设置成功或失败。 |

**示例：**

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

设置设备激活状态，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明               |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | 是   | 活跃音频设备类型。 |
| active     | boolean                               | 是   | 设备激活状态。     |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**


```
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true).then(() => {
    console.log('Promise returned to indicate that the device is set to the active status.');
});
```

### isDeviceActive

isDeviceActive(deviceType: ActiveDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定设备的激活状态，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                     |
| ---------- | ------------------------------------- | ---- | ------------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | 是   | 活跃音频设备类型。       |
| callback   | AsyncCallback&lt;boolean&gt;          | 是   | 回调返回设备的激活状态。 |

**示例：**

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

获取指定设备的激活状态，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                  | 必填 | 说明               |
| ---------- | ------------------------------------- | ---- | ------------------ |
| deviceType | [ActiveDeviceType](#activedevicetype) | 是   | 活跃音频设备类型。 |

**返回值：**

| Type                   | Description                     |
| ---------------------- | ------------------------------- |
| Promise&lt;boolean&gt; | Promise回调返回设备的激活状态。 |

**示例：**

```
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER).then((value) => {
    console.log('Promise returned to indicate that the active status of the device is obtained.' + value);
});
```

### setMicrophoneMute

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置麦克风静音状态，使用callback方式异步返回结果。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                          |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | 是   | 待设置的静音状态，true为静音，false为非静音。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回设置成功或失败。                      |

**示例：**

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

设置麦克风静音状态，使用Promise方式异步返回结果。

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

```
audioManager.setMicrophoneMute(true).then(() => {
    console.log('Promise returned to indicate that the microphone is muted.');
});
```

### isMicrophoneMute

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

获取麦克风静音状态，使用callback方式异步返回结果。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**

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

获取麦克风静音状态，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**


```
audioManager.isMicrophoneMute().then((value) => {
    console.log('Promise returned to indicate that the mute status of the microphone is obtained.', + value);
});
```

### on('volumeChange')<sup>8+</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

监听系统音量变化事件。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为：'volumeChange'（系统音量变化事件，检测到系统音量改变时，触发该事件）。 |
| callback | Callback<[VolumeEvent](#volumeevent8)> | 是   | 回调方法。                                                   |

**示例：**

```
audioManager.on('volumeChange', (volumeEvent) => {
    console.log('VolumeType of stream: ' + volumeEvent.volumeType);
    console.log('Volume level: ' + volumeEvent.volume);
    console.log('Whether to updateUI: ' + volumeEvent.updateUi);
});
```

### on('ringerModeChange')<sup>8+</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

监听铃声模式变化事件。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | 是   | 事件回调类型，支持的事件为：'ringerModeChange'（铃声模式变化事件，检测到铃声模式改变时，触发该事件）。 |
| callback | Callback<[AudioRingMode](#audioringmode)> | 是   | 回调方法。                                                   |

**示例：**

```
audioManager.on('ringerModeChange', (ringerMode) => {
    console.log('Updated ringermode: ' + ringerMode);
});
```

### on('deviceChange')

on(type: 'deviceChange', callback: Callback<DeviceChangeAction\>): void

设备更改。音频设备连接状态变化。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | 是   | 订阅的事件的类型。支持事件：'deviceChange' |
| callback | Callback<[DeviceChangeAction](#DeviceChangeAction)\> | 是   | 获取设备更新详情。                         |

**示例：**

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

取消订阅音频设备连接变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 订阅的事件的类型。支持事件：'deviceChange' |
| callback | Callback<[DeviceChangeAction](#DeviceChangeAction)> | 否   | 获取设备更新详情。                         |

**示例：**

```
audioManager.off('deviceChange', (deviceChanged) => {
    console.log("Should be no callback.");
});
```

### on('interrupt')

on(type: 'interrupt', interrupt: AudioInterrupt, callback: Callback\<InterruptAction>): void

请求焦点并开始监听音频打断事件（当应用程序的音频被另一个播放事件中断，回调通知此应用程序）

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名    | 类型                                          | 必填 | 说明                                                         |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type      | string                                        | 是   | 音频打断事件回调类型，支持的事件为：'interrupt'（多应用之间第二个应用会打断第一个应用，触发该事件）。 |
| interrupt | AudioInterrupt                                | 是   | 音频打断事件类型的参数。                                     |
| callback  | Callback<[InterruptAction](#interruptaction)> | 是   | 音频打断事件回调方法。                                       |

**示例：**

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

取消监听音频打断事件（删除监听事件，取消打断）

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名    | 类型                                          | 必填 | 说明                                                         |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type      | string                                        | 是   | 音频打断事件回调类型，支持的事件为：'interrupt'（多应用之间第二个应用会打断第一个应用，触发该事件）。 |
| interrupt | AudioInterrupt                                | 是   | 音频打断事件类型的参数。                                     |
| callback  | Callback<[InterruptAction](#interruptaction)> | 否   | 音频打断事件回调方法。                                       |

**示例：**

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

设置音频场景模式，使用callback方式异步返回结果。

此接口为系统接口，三方应用不支持调用。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                 |
| :------- | :----------------------------------- | :--- | :------------------- |
| scene    | <a href="#audioscene">AudioScene</a> | 是   | 音频场景模式。       |
| callback | AsyncCallback<void\>                 | 是   | 用于返回结果的回调。 |

**示例：**

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

设置音频场景模式，使用Promise方式返回异步结果。

此接口为系统接口，三方应用不支持调用。

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

```
audioManager.setAudioScene(audio.AudioScene.AUDIO_SCENE_PHONE_CALL).then(() => {
    console.log('Promise returned to indicate a successful setting of the audio scene mode.');
}).catch ((err) => {
    console.log('Failed to set the audio scene mode');
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

获取音频场景模式，使用Promise方式返回异步结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**返回值：**

| 类型                                          | 说明                         |
| :-------------------------------------------- | :--------------------------- |
| Promise<<a href="#audioscene">AudioScene</a>> | 用于返回音频场景模式的回调。 |

**示例：**

```
audioManager.getAudioScene().then((value) => {
    console.log('Promise returned to indicate that the audio scene mode is obtained.' + value);
}).catch ((err) => {
    console.log('Failed to obtain the audio scene mode');
});
```

## AudioDeviceDescriptor

描述音频设备。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Multimedia.Audio.Device

| 名称       | 类型                    | 可读 | 可写 | 说明       |
| ---------- | ------------------------- | ---- | ---- | ---------- |
| deviceRole | [DeviceRole](#devicerole) | 是   | 否   | 设备角色。 |
| deviceType | [DeviceType](#devicetype) | 是   | 否   | 设备类型。 |

## AudioDeviceDescriptors

设备属性数组类型，为[AudioDeviceDescriptor](#audiodevicedescriptor)的数组，只读。

**示例：**

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

提供音频渲染的相关接口。在调用AudioRenderer的接口前，需要先通过[createAudioRenderer](#audiocreateaudiorenderer8)创建实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称  | 类型                     | 可读 | 可写 | 说明               |
| ----- | -------------------------- | ---- | ---- | ------------------ |
| state<sup>8+</sup> | [AudioState](#audiostate8) | 是   | 否   | 音频渲染器的状态。 |

**示例：**

```
var state = audioRenderer.state;
```

### getRendererInfo<sup>8+</sup>

getRendererInfo(callback: AsyncCallback<AudioRendererInfo\>): void

获取当前被创建的音频渲染器的信息，使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                     | 必填 | 说明                   |
| :------- | :------------------------------------------------------- | :--- | :--------------------- |
| callback | AsyncCallback<[AudioRendererInfo](#audiorendererinfo8)\> | 是   | 返回音频渲染器的信息。 |

**示例：**

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

获取当前被创建的音频渲染器的信息，使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                               | 说明                            |
| -------------------------------------------------- | ------------------------------- |
| Promise<[AudioRendererInfo](#audiorendererinfo8)\> | Promise用于返回音频渲染器信息。 |

**示例：**

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

获取音频流信息，使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                 |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | 是   | 回调返回音频流信息。 |

**示例：**

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

获取音频流信息，使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                   |
| :--------------------------------------------- | :--------------------- |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | Promise返回音频流信息. |

**示例：**

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

启动音频渲染器。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。 |

**示例：**

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

启动音频渲染器。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```
audioRenderer.start().then(() => {
    console.log('Renderer started');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

暂停渲染。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

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

暂停渲染。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```
audioRenderer.pause().then(() => {
    console.log('Renderer paused');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### drain<sup>8+</sup>

drain(callback: AsyncCallback\<void>): void

检查缓冲区是否已被耗尽。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

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

检查缓冲区是否已被耗尽。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```
audioRenderer.drain().then(() => {
    console.log('Renderer drained successfully');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

停止渲染。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

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

停止渲染。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```
audioRenderer.stop().then(() => {
    console.log('Renderer stopped successfully');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

释放音频渲染器。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 返回回调的结果。 |

**示例：**

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

释放渲染器。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise方式异步返回结果。 |

**示例：**

```
audioRenderer.release().then(() => {
    console.log('Renderer released successfully');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### write<sup>8+</sup>

write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void

写入缓冲区。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| buffer   | ArrayBuffer            | 是   | 要写入缓冲区的数据。                                |
| callback | AsyncCallback\<number> | 是   | 回调如果成功，返回写入的字节数，否则返回errorcode。 |

**示例：**

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

写入缓冲区。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise返回结果，如果成功，返回写入的字节数，否则返回errorcode。 |

**示例：**

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

获取时间戳（从 1970 年 1 月 1 日开始）。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明             |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<number> | 是   | 回调返回时间戳。 |

**示例：**

```
audioRenderer.getAudioTime((err, timestamp) => {
    console.log('Current timestamp: ' + timestamp);
});
```

### getAudioTime<sup>8+</sup>

getAudioTime(): Promise\<number>

获取时间戳（从 1970 年 1 月 1 日开始）。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 描述                    |
| ---------------- | ----------------------- |
| Promise\<number> | Promise回调返回时间戳。 |

**示例：**

```
audioRenderer.getAudioTime().then((timestamp) => {
    console.log('Current timestamp: ' + timestamp);
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback\<number>): void

获取音频渲染器的最小缓冲区大小。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<number> | 是   | 回调返回缓冲区大小。 |

**示例：**

```
var bufferSize = audioRenderer.getBufferSize(async(err, bufferSize) => {
    if (err) {
        console.error('getBufferSize error');
    }
});
```

### getBufferSize<sup>8+</sup>

getBufferSize(): Promise\<number>

获取音频渲染器的最小缓冲区大小。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise\<number> | promise回调返回缓冲区大小。 |

**示例：**

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

设置音频渲染速率。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| rate     | [AudioRendererRate](#audiorendererrate8) | 是   | 渲染的速率。             |
| callback | AsyncCallback\<void>                     | 是   | 用于返回执行结果的回调。 |

**示例：**

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

设置音频渲染速率。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型                                     | 必填 | 说明         |
| ------ | ---------------------------------------- | ---- | ------------ |
| rate   | [AudioRendererRate](#audiorendererrate8) | 是   | 渲染的速率。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise用于返回执行结果。 |

**示例：**

```
audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL).then(() => {
    console.log('setRenderRate SUCCESS');
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```

### getRenderRate<sup>8+</sup>

getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void

获取当前渲染速率。使用callback方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明               |
| -------- | ------------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback<[AudioRendererRate](#audiorendererrate8)> | 是   | 回调返回渲染速率。 |

**示例：**

```
audioRenderer.getRenderRate((err, renderrate) => {
    console.log('getRenderRate: ' + renderrate);
});
```

### getRenderRate<sup>8+</sup>

getRenderRate(): Promise\<AudioRendererRate>

获取当前渲染速率。使用Promise方式异步返回结果。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                              | 说明                      |
| ------------------------------------------------- | ------------------------- |
| Promise<[AudioRendererRate](#audiorendererrate8)> | Promise回调返回渲染速率。 |

**示例：**

```
audioRenderer.getRenderRate().then((renderRate) => {
    console.log('getRenderRate: ' + renderRate);
}).catch((err) => {
    console.log('ERROR: '+err.message);
});
```
### setInterruptMode<sup>9+</sup>

setInterruptMode(interruptMode: InterruptMode): Promise&lt;void&gt;

设置应用的焦点模型。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| interruptMode | [InterruptMode](#InterruptMode) | 是   | 焦点模型。                                             |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | 以Promise对象返回结果，设置成功时返回undefined，否则返回error。 |

**示例：**

```
audioManager.setInterruptMode(audio.InterruptType.SHARE_MODE).then(() => {
    console.log('Promise returned to indicate a successful volume setting.');
});
```
### setInterruptMode<sup>9+</sup>

setInterruptMode(interruptMode: InterruptMode, callback: Callback\<void>): void

设置应用的焦点模型。使用Callback回调返回执行结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
|interruptMode | [InterruptMode](#InterruptMode) | 是   | 焦点模型。|
|callback | Callback\<void>  | 是  |回调返回执行结果。|

**示例：**

```
audioManager.setInterruptMode(audio.InterruptType.SHARE_MODE,()=>{
    console.log('Callback returned to indicate a successful volume setting.');
});
```
### on('interrupt')<sup>9+</sup>

on(type: 'interrupt', callback: Callback\<InterruptEvent>): void

监听音频中断事件。使用callback获取中断事件。

**系统能力**: SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                                         |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                       | 是   | 事件回调类型，支持的事件为：'interrupt'（中断事件被触发，音频播放被中断。） |
| callback | Callback<[InterruptEvent](#interruptevent9)> | 是   | 被监听的中断事件的回调。                                     |

**示例：**

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

订阅到达标记的事件。 当渲染的帧数达到 frame 参数的值时，回调被调用。

**系统能力:** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                      |
| :------- | :----------------------- | :--- | :---------------------------------------- |
| type     | string                   | 是   | 事件回调类型，支持的事件为：'markReach'。 |
| frame    | number                   | 是   | 触发事件的帧数。 该值必须大于 0。         |
| callback | (position: number) => {} | 是   | 触发事件时调用的回调。                    |

**示例：**

```
audioRenderer.on('markReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
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

```
audioRenderer.off('markReach');
```

### on('periodReach') <sup>8+</sup>

on(type: "periodReach", frame: number, callback: (position: number) => {}): void

订阅到达标记的事件。 当渲染的帧数达到 frame 参数的值时，回调被循环调用。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                        |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | 是   | 事件回调类型，支持的事件为：'periodReach'。 |
| frame    | number                   | 是   | 触发事件的帧数。 该值必须大于 0。           |
| callback | (position: number) => {} | 是   | 触发事件时调用的回调。                      |

**示例：**

```
audioRenderer.on('periodReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
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

```
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
| callback | [AudioState](#audiostate8) | 是   | 返回监听的状态。                            |

**示例：**

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

提供音频采集的相关接口。在调用AudioCapturer的接口前，需要先通过[createAudioCapturer](#audiocreateaudiocapturer8)创建实例。

### 属性

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

| 名称  | 类型                     | 可读 | 可写 | 说明             |
| :---- | :------------------------- | :--- | :--- | :--------------- |
| state<sup>8+</sup>  | [AudioState](#audiostate8) | 是 | 否   | 音频采集器状态。 |

**示例：**

```
var state = audioCapturer.state;
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

获取采集器信息。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型                                              | 说明                                |
| :------------------------------------------------ | :---------------------------------- |
| Promise<[AudioCapturerInfo](#audiocapturerinfo)\> | 使用Promise方式异步返回采集器信息。 |

**示例：**

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

获取采集器流信息。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                             |
| :------- | :--------------------------------------------------- | :--- | :------------------------------- |
| callback | AsyncCallback<[AudioStreamInfo](#audiostreaminfo8)\> | 是   | 使用callback方式异步返回流信息。 |

**示例：**

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

获取采集器流信息。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型                                           | 说明                            |
| :--------------------------------------------- | :------------------------------ |
| Promise<[AudioStreamInfo](#audiostreaminfo8)\> | 使用Promise方式异步返回流信息。 |

**示例：**

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

启动音频采集器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 使用callback方式异步返回结果。 |

**示例：**

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

启动音频采集器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

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

停止采集。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| :------- | :------------------- | :--- | :----------------------------- |
| callback | AsyncCallback<void\> | 是   | 使用callback方式异步返回结果。 |

**示例：**

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

停止采集。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```
audioCapturer.stop().then(() => {
    console.info('AudioFrameworkRecLog: ---------RELEASE RECORD---------');
    console.info('AudioFrameworkRecLog: Capturer stopped : SUCCESS');
    if ((audioCapturer.state == audio.AudioState.STATE_STOPPED)){
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

释放采集器。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                |
| :------- | :------------------- | :--- | :---------------------------------- |
| callback | AsyncCallback<void\> | 是   | Callback used to return the result. |

**示例：**

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

释放采集器。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型           | 说明                          |
| :------------- | :---------------------------- |
| Promise<void\> | 使用Promise方式异步返回结果。 |

**示例：**

```
audioCapturer.release().then(() => {
    console.info('AudioFrameworkRecLog: ---------RELEASE RECORD---------');
    console.info('AudioFrameworkRecLog: Capturer release : SUCCESS');
    console.info('AudioFrameworkRecLog: AudioCapturer : STATE : '+audioCapturer.state);
    stateFlag=true;
    console.info('AudioFrameworkRecLog: stateFlag : '+stateFlag);
}).catch((err) => {
    console.info('AudioFrameworkRecLog: Capturer stop:ERROR : '+err.message);
    stateFlag=false
});
```


### read<sup>8+</sup>

read(size: number, isBlockingRead: boolean, callback: AsyncCallback<ArrayBuffer\>): void

读入缓冲区。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数**

| 参数名         | 类型                        | 必填 | 说明                             |
| :------------- | :-------------------------- | :--- | :------------------------------- |
| size           | number                      | 是   | 读入的字节数。                   |
| isBlockingRead | boolean                     | 是   | 是否阻塞读操作。                 |
| callback       | AsyncCallback<ArrayBuffer\> | 是   | 使用callback方式异步返回缓冲区。 |

**示例：**

```
audioCapturer.read(bufferSize, true, async(err, buffer) => {
    if (!err) {
        console.log("Success in reading the buffer data");
    }
};
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

```
audioCapturer.read(bufferSize, true).then((buffer) => {
    console.info('buffer read successfully');
}).catch((err) => {
    console.info('ERROR : '+err.message);
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

```
audioCapturer.getAudioTime((err, timestamp) => {
    console.log('Current timestamp: ' + timestamp);
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

```
audioCapturer.getAudioTime().then((audioTime) => {
    console.info('AudioFrameworkRecLog: AudioCapturer getAudioTime : Success' + audioTime );
}).catch((err) => {
    console.info('AudioFrameworkRecLog: AudioCapturer Created : ERROR : '+err.message);
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

获取采集器合理的最小缓冲区大小。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**返回值：**

| 类型             | 说明                                |
| :--------------- | :---------------------------------- |
| Promise<number\> | 使用Promise方式异步返回缓冲区大小。 |

**示例：**

```
await audioCapturer.getBufferSize().then(async function (bufferSize) {
    console.info('AudioFrameworkRecordLog: getBufferSize :SUCCESS '+ bufferSize);
    var buffer = await audioCapturer.read(bufferSize, true);
    console.info('Buffer read is ' + buffer );
    }).catch((err) => {
    console.info('AudioFrameworkRecordLog: getBufferSize :ERROR : '+err.message);
});
```


### on('markReach')<sup>8+</sup>

on(type: 'markReach', frame: number, callback: (position: number) => {}): void

订阅标记到达的事件。 当采集的帧数达到 frame 参数的值时，回调被触发。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                       |
| :------- | :---------------------- | :--- | :----------------------------------------- |
| type     | string                  | 是   | 事件回调类型，支持的事件为：'markReach'。  |
| frame    | number                  | 是   | 触发事件的帧数。 该值必须大于0。           |
| callback | position: number) => {} | 是   | 使用callback方式异步返回被触发事件的回调。 |

**示例：**

```
audioCapturer.on('markReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
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

```
audioCapturer.off('markReach');
```

### on('periodReach')<sup>8+</sup>

on(type: "periodReach", frame: number, callback: (position: number) => {}): void

订阅到达标记的事件。 当采集的帧数达到 frame 参数的值时，回调被循环调用。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                        |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | 是   | 事件回调类型，支持的事件为：'periodReach'。 |
| frame    | number                   | 是   | 触发事件的帧数。 该值必须大于0。            |
| callback | (position: number) => {} | 是   | 使用callback方式异步返回被触发事件的回调    |

**示例：**

```
audioCapturer.on('periodReach', 1000, (position) => {
    if (position == "1000") {
        console.log('ON Triggered successfully');
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
| type   | string | Yes  | 取消事件回调类型，支持的事件为：'periodReach'。 |

**示例：**

```
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
| callback | [AudioState](#audiostate8) | 是   | 返回监听的状态。                            |

**示例：**

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