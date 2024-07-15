# 音效管理

音效管理主要包括播放实例音效管理和全局音效查询两部分，播放实例音效管理主要包括查询和设置当前音频播放流的音效模式，全局音效查询支持查询[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)对应场景支持的音效模式。

## 播放实例音效管理

主要包括查询和设置当前音频播放流的音效模式，[音效模式](../../reference/apis-audio-kit/js-apis-audio.md#audioeffectmode10)包括EFFECT_NONE关闭音效模式和EFFECT_DEFAULT默认音效模式。默认音效模式会根据创建音频流的[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)自动加载对应场景的音效。

### 获取播放实例

管理播放实例音效的接口是[getAudioEffectMode()](../../reference/apis-audio-kit/js-apis-audio.md#getaudioeffectmode10)查询当前音频播放流的音效模式和[setAudioEffectMode(mode: AudioEffectMode)](../../reference/apis-audio-kit/js-apis-audio.md#setaudioeffectmode10)设置当前音频播放流的音效模式，在使用之前，需要使用[createAudioRenderer(options: AudioRendererOptions)](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiorenderer8)先创建音频播放流AudioRenderer实例。

1. 导入音频接口。

    ```ts
    import { audio } from '@kit.AudioKit';
    ```

2. 配置音频渲染参数并创建AudioRenderer实例，音频渲染参数的详细信息可以查看[AudioRendererOptions](../../reference/apis-audio-kit/js-apis-audio.md#audiorendereroptions8)，创建AudioRenderer实例时会默认挂载EFFECT_DEFAULT模式音效。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
      channels: audio.AudioChannel.CHANNEL_1,
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
    };

    let audioRendererInfo: audio.AudioRendererInfo = {
      usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
      rendererFlags: 0
    };

    let audioRendererOptions: audio.AudioRendererOptions = {
      streamInfo: audioStreamInfo,
      rendererInfo: audioRendererInfo
    };
    let audioRenderer: audio.AudioRenderer | undefined = undefined;
   
    audio.createAudioRenderer(audioRendererOptions, (err: BusinessError, data: audio.AudioRenderer) => {
      if (err) {
        console.error(`Invoke createAudioRenderer failed, code is ${err.code}, message is ${err.message}`);
        return;
      } else {
        console.info('Invoke createAudioRenderer succeeded.');
        audioRenderer = data;
      }
    });
    ```

### 查询当前播放实例的音效模式

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  audioRenderer.getAudioEffectMode((err: BusinessError, effectMode: audio.AudioEffectMode) => {
    if (err) {
      console.error(`Failed to get params, code is ${err.code}, message is ${err.message}`);
      return;    
    } else {
      console.info(`getAudioEffectMode: ${effectMode}`);
    }
  });
  ```

### 设置当前播放实例的音效模式

关闭系统音效：

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_NONE, (err: BusinessError) => {
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
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to set params, code is ${err.code}, message is ${err.message}`);
      return;
    } else {
      console.info('Callback invoked to indicate a successful audio effect mode setting.');
    }
  });
  ```

## 全局查询音效模式

主要包括全局音效查询相应[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)对应场景的音效模式。
对于播放音频类的应用，开发者需要关注该应用的音频流使用什么音效模式并做出相应的操作，比如音乐App播放时，应选择音乐场景下的模式。在使用查询接口前，开发者需要使用getStreamManager()创建一个AudioStreamManager音频流管理实例。

### 获取音频流管理接口

创建AudioStreamManager实例。在使用AudioStreamManager的API前，需要使用getStreamManager()创建一个AudioStreamManager实例。

   ```ts
   import { audio } from '@kit.AudioKit';

   let audioManager = audio.getAudioManager();
   let audioStreamManager = audioManager.getStreamManager();
   ```

### 查询对应场景的音效模式

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  audioStreamManager.getAudioEffectInfoArray(audio.StreamUsage.STREAM_USAGE_MUSIC, async (err: BusinessError, audioEffectInfoArray: audio.AudioEffectInfoArray) => {
    if (err) {
      console.error('Failed to get effect info array');
      return;    
    } else {
      console.info(`getAudioEffectInfoArray: ${audioEffectInfoArray}`);
    }
  });
  ```