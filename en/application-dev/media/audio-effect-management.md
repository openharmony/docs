# Audio Effect Management

You can manage the audio effect of a specific playback instance, for example, obtaining or setting the audio effect mode of the current audio playback stream. You can also obtain the global audio effect, that is, the audio effect mode corresponding to a specific audio content type (specified by **ContentType**) and audio stream usage (specified by **StreamUsage**).

## Managing the Audio Effect of a Playback Instance

You can obtain and set the audio effect mode, which can be disabled (**EFFECT_NONE**) or default (**EFFECT_DEFAULT**), of the current audio playback stream. In default audio effect mode, the audio effect of the corresponding scenario is automatically loaded based on **ContentType** and **StreamUsage** of the audio stream.

### Creating a Playback Instance

Before obtaining or setting the audio effect mode, you must call **createAudioRenderer(options: AudioRendererOptions)** to create an **AudioRenderer** instance.

1. Import the audio module.

  ```js
  import audio from '@ohos.multimedia.audio';
  ```

2. Configure audio rendering parameters and create an **AudioRenderer** instance. For details about the audio rendering parameters, see [AudioRendererOptions](../reference/apis/js-apis-audio.md#audiorendereroptions8). For the **AudioRenderer** instance, the audio effect mode **EFFECT_DEFAULT** is used by default.

  ```js
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

### Obtaining the Audio Effect Mode of the Playback Instance

  ```js
  audioRenderer.getAudioEffectMode((err, effectmode) => {
    if (err) {
      console.error(`Failed to get params, code is ${err.code}, message is ${err.message}`);
      return;    
    } else {
      console.info(`getAudioEffectMode: ${effectmode}`);
    }
  });
  ```

### Setting an Audio Effect Mode for the Playback Instance

Disable the system audio effect.

  ```js
  audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_NONE, (err) => {
    if (err) {
      console.error(`Failed to set params, code is ${err.code}, message is ${err.message}`);
      return;
    } else {
      console.info('Callback invoked to indicate a successful audio effect mode setting.');
    }
  });
  ```

Enable the default system audio effect.

  ```js
  audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT, (err) => {
    if (err) {
      console.error(`Failed to set params, code is ${err.code}, message is ${err.message}`);
      return;
    } else {
      console.info('Callback invoked to indicate a successful audio effect mode setting.');
    }
  });
  ```

## Obtaining the Global Audio Effect Mode

You can obtain the global audio effect mode corresponding to a specific audio content type (specified by **ContentType**) and audio stream usage (specified by **StreamUsage**).
For an audio playback application, pay attention to the audio effect mode used by the audio stream of the application and perform corresponding operations. For example, for a music application, select the audio effect mode for the music scenario. Before obtaining the global audio effect mode, call **getStreamManager()** to create an **AudioStreamManager** instance.

### Creating an AudioStreamManager Instance

Create an **AudioStreamManager** instance. Before using **AudioStreamManager** APIs, you must use **getStreamManager()** to create an **AudioStreamManager** instance.

   ```js
   import audio from '@ohos.multimedia.audio';
   let audioManager = audio.getAudioManager();
   let audioStreamManager = audioManager.getStreamManager();
   ```

### Querying the Audio Effect Mode of the Corresponding Scenario

  ```js
  audioStreamManager.getAudioEffectInfoArray(audio.ContentType.CONTENT_TYPE_MUSIC, audio.StreamUsage.STREAM_USAGE_MEDIA, async (err, audioEffectInfoArray) => {
    if (err) {
      console.error(`Failed to get effect info array`);
      return;    
    } else {
      console.info(`getAudioEffectInfoArray: ${audioEffectInfoArray}`);
    }
  });
  ```
