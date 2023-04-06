# Audio Interruption Mode Development

## Introduction
The audio interruption mode is used to control the playback of multiple audio streams.

Audio applications can set the audio interruption mode to independent or shared under **AudioRenderer**.

In shared mode, multiple audio streams share one session ID. In independent mode, each audio stream has an independent session ID.

**Asynchronous operation**: To prevent the UI thread from being blocked, most **AudioRenderer** calls are asynchronous. Each API provides the callback and promise functions. The following examples use the promise functions.

## How to Develop

For details about the APIs, see [AudioRenderer in Audio Management](../reference/apis/js-apis-audio.md#audiorenderer8).

1. Use **createAudioRenderer()** to create an **AudioRenderer** instance.
   
   Set parameters of the **AudioRenderer** instance in **audioRendererOptions**.

   This instance is used to render audio, control and obtain the rendering status, and register a callback for notification.
   
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
   
2. Set the audio interruption mode.

   After the **AudioRenderer** instance is initialized, you can set the audio interruption mode.<br>

   ```js
    var mode_ = audio.InterruptMode.SHARE_MODE;
    await this.audioRenderer.setInterruptMode(mode_).then(() => {
      console.log('[JSAR] [SetInterruptMode] Setting: '+ (mode_ == 0? " share mode":"independent mode") + "success");
    });
   ```
