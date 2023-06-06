# 播放音效管理

播放音效的管理主要包括查询和设置当前音频播放流的音效模式，音效模式包括EFFECT_NONE关闭音效模式和EFFECT_DEFAULT默认音效模式。默认音效模式会根据创建音频流的ContentType和UsageType自动加载对应场景的音效。

## 获取音效管理接口

管理播放音效的接口是getAudioEffectMode()查询当前音频播放流的音效模式和setAudioEffectMode(mode: AudioEffectMode)设置当前音频播放流的音效模式，在使用之前，需要使用createAudioRenderer(options: AudioRendererOptions)先创建音频播放流AudioRenderer实例。

```ts
import audio from '@ohos.multimedia.audio';
```

1. 配置音频渲染参数并创建AudioRenderer实例，音频渲染参数的详细信息可以查看[AudioRendererOptions](../reference/apis/js-apis-audio.md#audiorendereroptions8)，创建AudioRenderer实例时会默认挂在EFFECT_DEFAULT模式音效。

```ts
let audioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_1,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
};

let audioRendererInfo = {
  content: audio.ContentType.CONTENT_TYPE_SPEECH,
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
  rendererFlags: 0
};

let audioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};

audio.createAudioRenderer(audioRendererOptions, (err, data) => {
  if (err) {
    console.error(`Invoke createAudioRenderer failed, code is ${err.code}, message is ${err.message}`);
    return;
  } else {
    console.info('Invoke createAudioRenderer succeeded.');
    let audioRenderer = data;
  }
});
```

### 查询当前播放实例的音效模式

```ts
audioRenderer.getAudioEffectMode((err, effectmode) => {
  if (err) {
    console.error(`Failed to get params, code is ${err.code}, message is ${err.message}`);
    return;    
  } else {
    console.info(`getAudioEffectMode: ${effectmode}`);
  }
});
```

### 设置当前播放实例的音效模式

关闭系统音效：

```ts
audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_NONE, (err) => {
  if (err) {
    console.error(`Failed to set params, code is ${err.code}, message is ${err.message}`);
    return;
  } else {
    console.info('Callback invoked to indicate a successful audio effect mode setting.');
  }
});
```

开启系统音效默认模式：

```ts
audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT, (err) => {
  if (err) {
    console.error(`Failed to set params, code is ${err.code}, message is ${err.message}`);
    return;
  } else {
    console.info('Callback invoked to indicate a successful audio effect mode setting.');
  }
});
```
