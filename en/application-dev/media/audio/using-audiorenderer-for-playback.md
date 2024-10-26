# Using AudioRenderer for Audio Playback

The AudioRenderer is used to play Pulse Code Modulation (PCM) audio data. Unlike the [AVPlayer](../media/using-avplayer-for-playback.md), the AudioRenderer can perform data preprocessing before audio input. Therefore, the AudioRenderer is more suitable if you have extensive audio development experience and want to implement more flexible playback features.

## Development Guidelines

The full rendering process involves creating an **AudioRenderer** instance, configuring audio rendering parameters, starting and stopping rendering, and releasing the instance. In this topic, you will learn how to use the AudioRenderer to render audio data. Before the development, you are advised to read [AudioRenderer](../../reference/apis-audio-kit/js-apis-audio.md#audiorenderer8) for the API reference.

The figure below shows the state changes of the AudioRenderer. After an **AudioRenderer** instance is created, different APIs can be called to switch the AudioRenderer to different states and trigger the required behavior. If an API is called when the AudioRenderer is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AudioRenderer state before triggering state transition.

To prevent the UI thread from being blocked, most **AudioRenderer** calls are asynchronous. Each API provides the callback and promise functions. The following examples use the callback functions.

**Figure 1** AudioRenderer state transition

![AudioRenderer state transition](figures/audiorenderer-status-change.png)

During application development, you are advised to use [on('stateChange')](../../reference/apis-audio-kit/js-apis-audio.md#onstatechange-8) to subscribe to state changes of the AudioRenderer. This is because some operations can be performed only when the AudioRenderer is in a given state. If the application performs an operation when the AudioRenderer is not in the given state, the system may throw an exception or generate other undefined behavior.

- **prepared**: The AudioRenderer enters this state by calling [createAudioRenderer()](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiorenderer8).

- **running**: The AudioRenderer enters this state by calling [start()](../../reference/apis-audio-kit/js-apis-audio.md#start8) when it is in the **prepared**, **paused**, or **stopped** state.

- **paused**: The AudioRenderer enters this state by calling [pause()](../../reference/apis-audio-kit/js-apis-audio.md#pause8) when it is in the **running** state. When the audio playback is paused, it can call [start()](../../reference/apis-audio-kit/js-apis-audio.md#start8) to resume the playback.

- **stopped**: The AudioRenderer enters this state by calling [stop()](../../reference/apis-audio-kit/js-apis-audio.md#stop8) when it is in the **paused** or **running** state.

- **released**: The AudioRenderer enters this state by calling [release()](../../reference/apis-audio-kit/js-apis-audio.md#release8) when it is in the **prepared**, **paused**, or **stopped** state. In this state, the AudioRenderer releases all occupied hardware and software resources and will not transit to any other state.

### How to Develop

1. Set audio rendering parameters and create an **AudioRenderer** instance. For details about the parameters, see [AudioRendererOptions](../../reference/apis-audio-kit/js-apis-audio.md#audiorendereroptions8).

    ```ts
    import { audio } from '@kit.AudioKit';

    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
      channels: audio.AudioChannel.CHANNEL_2, // Channel.
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
    };

    let audioRendererInfo: audio.AudioRendererInfo = {
      usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
      rendererFlags: 0
    };

    let audioRendererOptions: audio.AudioRendererOptions = {
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

2. Call **on('writeData')** to subscribe to the audio data write callback.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo } from '@kit.CoreFileKit';

    let bufferSize: number = 0;
    class Options {
      offset?: number;
      length?: number;
    }

    let path = getContext().cacheDir;
    // Ensure that the resource exists in the path.
    let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
    let file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);

    let writeDataCallback = (buffer: ArrayBuffer) => {

      let options: Options = {
        offset: bufferSize,
        length: buffer.byteLength
      }
      fileIo.readSync(file.fd, buffer, options);
      bufferSize += buffer.byteLength;
    }

    audioRenderer.on('writeData', writeDataCallback);
    ```

3. Call **start()** to switch the AudioRenderer to the **running** state and start rendering.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioRenderer.start((err: BusinessError) => {
      if (err) {
        console.error(`Renderer start failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Renderer start success.');
      }
    });
    ```

4. Call **stop()** to stop rendering.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioRenderer.stop((err: BusinessError) => {
      if (err) {
        console.error(`Renderer stop failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Renderer stopped.');
      }
    });
    ```

5. Call **release()** to release the instance.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    
    audioRenderer.release((err: BusinessError) => {
      if (err) {
        console.error(`Renderer release failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Renderer released.');
      } 
    });
    ```

### Selecting the Correct Stream Usage

When developing a media player, it is important to correctly set the stream usage type according to the intended use case. This will ensure that the player behaves as expected in different scenarios.

The recommended use cases are described in [StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage). For example, **STREAM_USAGE_MUSIC** is recommended for music scenarios, **STREAM_USAGE_MOVIE** is recommended for movie or video scenarios, and **STREAM_USAGE_GAME** is recommended for gaming scenarios.

An incorrect configuration of **StreamUsage** may cause unexpected behavior. Example scenarios are as follows:

- When **STREAM_USAGE_MUSIC** is incorrectly used in a game scenario, the game cannot be played simultaneously with music applications. However, games usually can coexist with music playback.
- When **STREAM_USAGE_MUSIC** is incorrectly used in a navigation scenario, any playing music is interrupted when the navigation application provides audio guidance. However, it is generally expected that the music keeps playing at a lower volume while the navigation is active.

### Sample Code

Refer to the sample code below to render an audio file using AudioRenderer.

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

const TAG = 'AudioRendererDemo';

class Options {
  offset?: number;
  length?: number;
}

let context = getContext(this);
let bufferSize: number = 0;
let renderModel: audio.AudioRenderer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
  channels: audio.AudioChannel.CHANNEL_2, // Channel.
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
}
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type.
  rendererFlags: 0 // AudioRenderer flag.
}
let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
}
let path = getContext().cacheDir;
// Ensure that the resource exists in the path.
let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
let file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);

let writeDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  }
  fileIo.readSync(file.fd, buffer, options);
   bufferSize += buffer.byteLength;
}

// Create an AudioRenderer instance, and set the events to listen for.
function init() {
  audio.createAudioRenderer(audioRendererOptions, (err, renderer) => { // Create an AudioRenderer instance.
    if (!err) {
      console.info(`${TAG}: creating AudioRenderer success`);
      renderModel = renderer;
      if (renderModel !== undefined) {
        (renderModel as audio.AudioRenderer).on('writeData', writeDataCallback);
      }
    } else {
      console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
    }
  });
}

// Start audio rendering.
function start() {
  if (renderModel !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf((renderModel as audio.AudioRenderer).state.valueOf()) === -1) { // Rendering can be started only when the AudioRenderer is in the prepared, paused, or stopped state.
      console.error(TAG + 'start failed');
      return;
    }
    // Start rendering.
    (renderModel as audio.AudioRenderer).start((err: BusinessError) => {
      if (err) {
        console.error('Renderer start failed.');
      } else {
        console.info('Renderer start success.');
      }
    });
  }
}

// Pause the rendering.
function pause() {
  if (renderModel !== undefined) {
    // Rendering can be paused only when the AudioRenderer is in the running state.
    if ((renderModel as audio.AudioRenderer).state.valueOf() !== audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      return;
    }
    // Pause the rendering.
    (renderModel as audio.AudioRenderer).pause((err: BusinessError) => {
      if (err) {
        console.error('Renderer pause failed.');
      } else {
        console.info('Renderer pause success.');
      }
    });
  }
}

// Stop rendering.
async function stop() {
  if (renderModel !== undefined) {
    // Rendering can be stopped only when the AudioRenderer is in the running or paused state.
    if ((renderModel as audio.AudioRenderer).state.valueOf() !== audio.AudioState.STATE_RUNNING && (renderModel as audio.AudioRenderer).state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      return;
    }
    // Stop rendering.
    (renderModel as audio.AudioRenderer).stop((err: BusinessError) => {
      if (err) {
        console.error('Renderer stop failed.');
      } else {
        fileIo.close(file);
        console.info('Renderer stop success.');
      }
    });
  }
}

// Release the instance.
async function release() {
  if (renderModel !== undefined) {
    // The AudioRenderer can be released only when it is not in the released state.
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      return;
    }
    // Release the resources.
    (renderModel as audio.AudioRenderer).release((err: BusinessError) => {
      if (err) {
        console.error('Renderer release failed.');
      } else {
        console.info('Renderer release success.');
      }
    });
  }
}
```

When audio streams with the same or higher priority need to use the output device, the current audio playback will be interrupted. The application can respond to and handle the interruption event. For details, see [Processing Audio Interruption Events](audio-playback-concurrency.md).
