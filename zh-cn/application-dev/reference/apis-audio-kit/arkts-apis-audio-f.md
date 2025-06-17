# Functions

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## audio.getAudioManager

getAudioManager(): AudioManager

获取音频管理器。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                          | 说明         |
| ----------------------------- | ------------ |
| [AudioManager](arkts-apis-audio-AudioManager.md) | 音频管理器对象。 |

**示例：**
```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void

获取音频渲染器。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                            | 必填 | 说明             |
| -------- | ----------------------------------------------- | ---- | ---------------- |
| options  | [AudioRendererOptions](arkts-apis-audio-i.md#audiorendereroptions8)  | 是   | 配置渲染器。     |
| callback | AsyncCallback<[AudioRenderer](arkts-apis-audio-AudioRenderer.md)> | 是   | 回调函数。当获取音频渲染器成功，err为undefined，data为获取到的音频渲染器对象；否则为错误对象。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};

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

获取音频渲染器。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名  | 类型                                           | 必填 | 说明         |
| :------ | :--------------------------------------------- | :--- | :----------- |
| options | [AudioRendererOptions](arkts-apis-audio-i.md#audiorendereroptions8) | 是   | 配置渲染器。 |

**返回值：**

| 类型                                      | 说明             |
| ----------------------------------------- | ---------------- |
| Promise<[AudioRenderer](arkts-apis-audio-AudioRenderer.md)> | Promise对象，返回音频渲染器对象。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};

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

获取音频采集器。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**需要权限：** ohos.permission.MICROPHONE

当设置Mic音频源（即[SourceType](arkts-apis-audio-e.md#sourcetype8)为SOURCE_TYPE_MIC、SOURCE_TYPE_VOICE_RECOGNITION、SOURCE_TYPE_VOICE_COMMUNICATION、SOURCE_TYPE_VOICE_MESSAGE、SOURCE_TYPE_CAMCORDER）时需要该权限。

**参数：**

| 参数名   | 类型                                            | 必填 | 说明             |
| :------- | :---------------------------------------------- | :--- | :--------------- |
| options  | [AudioCapturerOptions](arkts-apis-audio-i.md#audiocaptureroptions8)  | 是   | 配置音频采集器。 |
| callback | AsyncCallback<[AudioCapturer](arkts-apis-audio-AudioCapturer.md)> | 是   | 回调函数。当获取音频采集器成功，err为undefined，data为获取到的音频采集器对象；否则为错误对象。异常将返回error对象：<br>错误码6800301：表示参数校验异常、权限校验异常或系统处理异常（具体错误查看系统日志）。<br>错误码6800101：表示必选参数为空或参数类型错误。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
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
  }
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions): Promise<AudioCapturer\>

获取音频采集器。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**需要权限：** ohos.permission.MICROPHONE

当设置Mic音频源（即[SourceType](arkts-apis-audio-e.md#sourcetype8)为SOURCE_TYPE_MIC、SOURCE_TYPE_VOICE_RECOGNITION、SOURCE_TYPE_VOICE_COMMUNICATION、SOURCE_TYPE_VOICE_MESSAGE、SOURCE_TYPE_CAMCORDER）时需要该权限。

**参数：**

| 参数名  | 类型                                           | 必填 | 说明             |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| options | [AudioCapturerOptions](arkts-apis-audio-i.md#audiocaptureroptions8) | 是   | 配置音频采集器。 |

**返回值：**

| 类型                                      | 说明                   |
| ----------------------------------------- |----------------------|
| Promise<[AudioCapturer](arkts-apis-audio-AudioCapturer.md)> | Promise对象，成功将返回音频采集器对象，异常将返回error对象：<br>错误码6800301：表示参数校验异常、权限校验异常或系统处理异常（具体错误查看系统日志）。<br>错误码6800101：表示必选参数为空或参数类型错误。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
};

let audioCapturerOptions:audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};

let audioCapturer: audio.AudioCapturer;

audio.createAudioCapturer(audioCapturerOptions).then((data) => {
  audioCapturer = data;
  console.info('AudioCapturer Created : Success : Stream Type: SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`AudioCapturer Created : ERROR : ${err}`);
});
```
