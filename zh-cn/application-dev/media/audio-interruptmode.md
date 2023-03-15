# 音频焦点模式开发指导

## 简介
音频焦点模式指的是应用内，允许对多个声音的播放进行控制。<br>
音频应用可以在AudioRenderer下设置独立焦点模式、共享焦点模式。<br>
当设置在共享的模式下，多个音频共用一个会话ID；独立焦点模式下，每一个音频拥有单独会话ID。

- **异步操作**：为保证UI线程不被阻塞，大部分AudioRenderer调用都是异步的。对于每个API均提供了callback函数和Promise函数，以下示例均采用Promise函数。

## 开发指导

详细API含义可参考：[音频管理API文档AudioRenderer](../reference/apis/js-apis-audio.md#audiorenderer8)

1. 使用createAudioRenderer()创建一个AudioRenderer实例。<br>
   在audioRendererOptions中设置相关参数。<br>
   该实例可用于音频渲染、控制和获取采集状态，以及注册通知回调。<br>

   ```js
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

   let audioRenderer = await audio.createAudioRenderer(audioRendererOptions);
   ```

2. 设置焦点模式。
   
   在AudioRenderer初始化完毕后，可以进行焦点模式的设置。<br>

   ```js
    var mode_ = audio.InterruptMode.SHARE_MODE;
    await this.audioRenderer.setInterruptMode(mode_).then(() => {
      console.log('[JSAR] [SetInterruptMode] 设置: ' + (mode_ == 0 ? "共享模式":"独立焦点模式") + "成功" );
    });
   ```

