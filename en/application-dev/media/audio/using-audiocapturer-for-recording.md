# Using AudioCapturer for Audio Recording

The AudioCapturer is used to record Pulse Code Modulation (PCM) audio data. It is suitable if you have extensive audio development experience and want to implement more flexible recording features.

## Development Guidelines

The full recording process involves creating an **AudioCapturer** instance, configuring audio recording parameters, starting and stopping recording, and releasing the instance. In this topic, you will learn how to use the AudioCapturer to recording audio data. Before the development, you are advised to read [AudioCapturer](../../reference/apis-audio-kit/js-apis-audio.md#audiocapturer8) for the API reference.

The figure below shows the state changes of the AudioCapturer. After an **AudioCapturer** instance is created, different APIs can be called to switch the AudioCapturer to different states and trigger the required behavior. If an API is called when the AudioCapturer is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AudioCapturer state before triggering state transition.

**Figure 1** AudioCapturer state transition

![AudioCapturer state change](figures/audiocapturer-status-change.png)

You can call **on('stateChange')** to listen for state changes of the AudioCapturer. For details about each state, see [AudioState](../../reference/apis-audio-kit/js-apis-audio.md#audiostate8).

### How to Develop

1. Set audio recording parameters and create an **AudioCapturer** instance. For details about the parameters, see [AudioCapturerOptions](../../reference/apis-audio-kit/js-apis-audio.md#audiocaptureroptions8).

   > **NOTE**
   >
   > When the microphone audio source is set ([SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8) is set to **SOURCE_TYPE_MIC**, **SOURCE_TYPE_VOICE_RECOGNITION**, **SOURCE_TYPE_VOICE_COMMUNICATION**, or **SOURCE_TYPE_VOICE_MESSAGE**), the permission ohos.permission.MICROPHONE is required. For details about how to apply for the permission, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

   ```ts
    import { audio } from '@kit.AudioKit';
    
    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
      channels: audio.AudioChannel.CHANNEL_2, // Channel.
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
    };
    
    let audioCapturerInfo: audio.AudioCapturerInfo = {
      source: audio.SourceType.SOURCE_TYPE_MIC, // Audio source type: microphone. Set this parameter based on the service scenario.
      capturerFlags: 0 // Flag indicating an AudioCapturer.
    };
    
    let audioCapturerOptions: audio.AudioCapturerOptions = {
      streamInfo: audioStreamInfo,
      capturerInfo: audioCapturerInfo
    };
    
    audio.createAudioCapturer(audioCapturerOptions, (err, data) => {
      if (err) {
        console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Invoke createAudioCapturer succeeded.');
        let audioCapturer = data;
      }
    });
   ```

2. Call **on('readData')** to subscribe to the audio data read callback.
    > **NOTE**
    > - **Thread management**: You are advised not to use multiple threads for data reading. If multithreading is necessary for data reading, ensure proper thread management.
    > - **Thread performance**: Do not execute time-consuming tasks in the thread where the **readData** API resides. Failing to do so may delay the data processing thread's response to callbacks, potentially causing issues like missing audio data, lag, and noise.

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo as fs } from '@kit.CoreFileKit';
    import { common } from '@kit.AbilityKit';

    class Options {
      offset?: number;
      length?: number;
    }

    let bufferSize: number = 0;
    // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    let path = context.cacheDir;
    let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
    let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    let readDataCallback = (buffer: ArrayBuffer) => {
      let options: Options = {
        offset: bufferSize,
        length: buffer.byteLength
      }
      fs.writeSync(file.fd, buffer, options);
      bufferSize += buffer.byteLength;
    };

    audioCapturer.on('readData', readDataCallback);
   ```

3. Call **start()** to switch the AudioCapturer to the **running** state and start recording.

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioCapturer.start((err: BusinessError) => {
      if (err) {
        console.error(`Capturer start failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Capturer start success.');
      }
    });
   ```

4. Call **stop()** to stop recording.

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioCapturer.stop((err: BusinessError) => {
      if (err) {
        console.error(`Capturer stop failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Capturer stopped.');
      }
    });
   ```

5. Call **release()** to release the instance.

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioCapturer.release((err: BusinessError) => {
      if (err) {
        console.error(`capturer release failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('capturer released.');
      }
    });
   ```

### Sample Code

Refer to the sample code below to record audio using AudioCapturer.

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

const TAG = 'AudioCapturerDemo';

class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
let audioCapturer: audio.AudioCapturer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
  channels: audio.AudioChannel.CHANNEL_2, // Channel.
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
};
let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // Audio source type: microphone. Set this parameter based on the service scenario.
  capturerFlags: 0 // Flag indicating an AudioCapturer.
};
let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let path = context.cacheDir;
let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
let readDataCallback = (buffer: ArrayBuffer) => {
   let options: Options = {
      offset: bufferSize,
      length: buffer.byteLength
   }
   fs.writeSync(file.fd, buffer, options);
   bufferSize += buffer.byteLength;
};

// Create an AudioCapturer instance, and set the events to listen for.
function init() {
  audio.createAudioCapturer(audioCapturerOptions, (err, capturer) => { // Create an AudioCapturer instance.
    if (err) {
      console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
       (audioCapturer as audio.AudioCapturer).on('readData', readDataCallback);
    }
  });
}

// Start audio recording.
function start() {
  if (audioCapturer !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf((audioCapturer as audio.AudioCapturer).state.valueOf()) === -1) { // Recording can be started only when the AudioCapturer is in the STATE_PREPARED, STATE_PAUSED, or STATE_STOPPED state.
      console.error(`${TAG}: start failed`);
      return;
    }

    // Start recording.
    (audioCapturer as audio.AudioCapturer).start((err: BusinessError) => {
      if (err) {
        console.error('Capturer start failed.');
      } else {
        console.info('Capturer start success.');
      }
    });
  }
}

// Stop recording.
function stop() {
  if (audioCapturer !== undefined) {
    // The AudioCapturer can be stopped only when it is in the STATE_RUNNING or STATE_PAUSED state.
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() !== audio.AudioState.STATE_RUNNING && (audioCapturer as audio.AudioCapturer).state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      return;
    }

    // Stop recording.
    (audioCapturer as audio.AudioCapturer).stop((err: BusinessError) => {
      if (err) {
        console.error('Capturer stop failed.');
      } else {
        fs.close(file);
        console.info('Capturer stop success.');
      }
    });
  }
}

// Release the instance.
function release() {
  if (audioCapturer !== undefined) {
    // The AudioCapturer can be released only when it is not in the STATE_RELEASED or STATE_NEW state.
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_RELEASED || (audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      return;
    }

    // Release the resources.
    (audioCapturer as audio.AudioCapturer).release((err: BusinessError) => {
      if (err) {
        console.error('Capturer release failed.');
      } else {
        console.info('Capturer release success.');
      }
    });
  }
}
```
