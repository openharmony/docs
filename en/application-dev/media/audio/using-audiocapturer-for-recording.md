# Using AudioCapturer for Audio Recording (ArkTS)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=65bb9604a921f234d3e9f4b6d8fc347f11f12a39 translatedAt=2026-08-06T01:52:28.390Z pushedAt=2026-08-06T09:03:22.441Z -->

The AudioCapturer is used to record Pulse Code Modulation (PCM) audio data. It is suitable if you have extensive audio development experience and want to implement more flexible recording features.

## Development Guidelines

Using AudioCapturer to record audio involves creating an AudioCapturer instance, configuring audio capture parameters, starting and stopping capture, and releasing resources. This development guide walks you through the process of audio recording with AudioCapturer, using a complete recording session as an example. It is recommended to read this guide together with the API reference of [AudioCapturer](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md).

The figure below shows the state changes of the AudioCapturer. After an instance is created, you can call corresponding methods to switch the AudioCapturer to a specific state and trigger the associated behavior. Note: Calling an inappropriate method in a certain state may cause the AudioCapturer to encounter an error. You are advised to check the state before calling a state transition method to avoid unexpected results.

You can use the [on('stateChange')](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#onstatechange8) method to listen for state changes of the AudioCapturer. For the value and description of each state, see [AudioState](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiostate8).

When an audio stream is in the working state (not in the released state), it occupies system audio stream resources. Because the system imposes a limit on the number of audio streams, you should call `release()` to reclaim audio resources when the audio stream is temporarily not in use, so as to ensure proper resource utilization and avoid failures when creating subsequent audio streams.

**Figure 1** AudioCapturer state transition

![AudioCapturer state change](figures/audiocapturer-status-change.png)

### How to Develop

The following examples are code snippets. You can obtain the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS) via the link at the bottom right of the sample code.

1. Set audio recording parameters and create an AudioCapturer instance. For details about the parameters, see [AudioCapturerOptions](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiocaptureroptions8).

   > **NOTE**
   >
   > When the microphone audio source is set ([SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8) is set to **SOURCE_TYPE_MIC**, **SOURCE_TYPE_VOICE_RECOGNITION**, **SOURCE_TYPE_VOICE_COMMUNICATION**, **SOURCE_TYPE_VOICE_MESSAGE**, or **SOURCE_TYPE_LIVE**), the permission ohos.permission.MICROPHONE is required. Note that **SOURCE_TYPE_LIVE** is supported since API version 20. For details about how to apply for the permission, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

   <!-- @[create_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) -->

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   // ...
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
   // ...
     audio.createAudioCapturer(audioCapturerOptions, (err, capturer) => { // Create an AudioCapturer instance.
       if (err) {
         console.error(`${TAG}: Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
         // ...
         return;
       }
       console.info(`${TAG}: create AudioCapturer success`);
       // ...
       audioCapturer = capturer;
       if (audioCapturer !== undefined) {
         audioCapturer.on('readData', onReadData);
         // ...
       }
     });
   ```

2. Call [on('readData')](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#onreaddata11) to subscribe to the audio data read callback.

   > **NOTE**
   > 
   > - **Thread management**: You are advised not to use multiple threads for data reading. If multithreading is necessary for data reading, ensure proper thread management.
   > - **Thread performance**: Do not execute time-consuming tasks in the thread where the **readData** API resides. Failing to do so may delay the data processing thread's response to callbacks, potentially causing issues like missing audio data, lag, and noise.
   > - **Callback registration**: You should avoid registering callbacks on the main thread, as this may cause delayed callback responses and freezes due to blocking by other service processes. You are advised to use an independent asynchronous thread pool to handle callbacks.

   <!-- @[listen_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   import { common, abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';
   
   // ...
   class Options {
     public offset?: number;
     public length?: number;
   }
   
   // ...
      let writtenBytes: number = 0;
      pendingRecordingWrite = Promise.resolve();
      let path = context.cacheDir;
      let filePath = path + '/S16LE_2_48000.pcm';
      recordingFile = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      onReadData = (buffer: ArrayBuffer) => {
        // ...
        let recordingBuffer = buffer.slice(0);
        let writeOffset = writtenBytes;
        writtenBytes += recordingBuffer.byteLength;
        let options: Options = {
          offset: writeOffset,
          length: recordingBuffer.byteLength
        }
        pendingRecordingWrite = pendingRecordingWrite.then(async () => {
          await fs.write(recordingFile.fd, recordingBuffer, options);
        }).catch((error: BusinessError) => {
          console.error(`${TAG}: Write recording data failed, code: ${error.code}, message: ${error.message}`);
        });
      };
     // ...
         audioCapturer.on('readData', onReadData);
   ```

3. Call [start](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#start8) to switch the AudioCapturer to the running state and start recording.

   <!-- @[start_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) -->

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
       try {
         await audioCapturer.start();
         // ...
         console.info(`${TAG}: Capturer start success.`);
       } catch (err) {
         let error = err as BusinessError;
         // ...
         console.error(`${TAG}: Capturer start failed, code: ${error.code}, message: ${error.message}`);
       }
   ```

4. Call [stop](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#stop8) to stop recording.

   <!-- @[stop_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) -->

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
       try {
         await audioCapturer.stop();
         // ...
         console.info(`${TAG}: Capturer stop success.`);
       } catch (err) {
         let error = err as BusinessError;
         // ...
         console.error(`${TAG}: Capturer stop failed, code: ${error.code}, message: ${error.message}`);
      }
   ```

5. Call [release](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#release8) to destroy the instance and release resources.

   <!-- @[release_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
       try {
        await audioCapturer.release();
        capturerMuteHintEnabledByApp = false;
        console.info(`${TAG}: Capturer release success.`);
        // ...
       } catch (err) {
        let error = err as BusinessError;
        // ...
        console.error(`${TAG}: Capturer release failed, code: ${error.code}, message: ${error.message}`);
      } finally {
        await pendingRecordingWrite;
        fs.closeSync(recordingFile.fd);
      }
   ```

### Complete Sample Code

Refer to the sample code below to record audio using AudioCapturer.

<!-- @[all_audioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common, abilityAccessCtrl, PermissionRequestResult } from '@kit.AbilityKit';

const TAG = 'AudioCapturerDemo';

class Options {
  public offset?: number;
  public length?: number;
}

let audioRenderer: audio.AudioRenderer | undefined = undefined;
let audioCapturer: audio.AudioCapturer | undefined = undefined;
let capturerMuteHintEnabledByApp: boolean = false;
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
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Configure based on the service scenario. For details, see StreamUsage.
  rendererFlags: 0 // Audio renderer flags.
};
let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};

let file: fs.File;
let recordingFile: fs.File;
let onReadData: Callback<ArrayBuffer>;
let writeDataCallback: audio.AudioRendererWriteDataCallback;
let pendingRecordingWrite: Promise<void> = Promise.resolve();

// ...

async function initRecordingResources(context: common.UIAbilityContext): Promise<void> {
  let writtenBytes: number = 0;
  pendingRecordingWrite = Promise.resolve();
  let path = context.cacheDir;
  let filePath = path + '/S16LE_2_48000.pcm';
  recordingFile = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  onReadData = (buffer: ArrayBuffer) => {
    let recordingBuffer = buffer.slice(0);
    let writeOffset = writtenBytes;
    writtenBytes += recordingBuffer.byteLength;
    let options: Options = {
      offset: writeOffset,
      length: recordingBuffer.byteLength
    }
    pendingRecordingWrite = pendingRecordingWrite.then(async () => {
      await fs.write(recordingFile.fd, recordingBuffer, options);
    }).catch((error: BusinessError) => {
      console.error(`${TAG}: Write recording data failed, code: ${error.code}, message: ${error.message}`);
    });
  };
}

async function initRender(context: common.UIAbilityContext) {
  let bufferSize: number = 0;
  let path = context.cacheDir;
  // This is only an example. In actual use, replace the file with the PCM file to be played by the app.
  let filePath = path + '/S16LE_2_48000.pcm';
  file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  writeDataCallback = (buffer: ArrayBuffer) => {
    let options: Options = {
      offset: bufferSize,
      length: buffer.byteLength
    };

    try {
      let bufferLength = fs.readSync(file.fd, buffer, options);
      bufferSize += buffer.byteLength;
      // If the data passed in the current callback is less than one frame, fill the blank area with silence data. Otherwise, noise may occur during playback.
      if (bufferLength < buffer.byteLength) {
        let view = new DataView(buffer);
        for (let i = bufferLength; i < buffer.byteLength; i++) {
          // Fill the blank area with silence data. When the audio sampling format is SAMPLE_FORMAT_U8, 0x7F is the silence data. When other sampling formats are used, 0 is the silence data.
          view.setUint8(i, 0);
        }
      }
      // API version 11 does not support returning callback results. Starting from API version 12, returning callback results is supported.
      // If you do not want to play a certain buffer, return audio.AudioDataCallbackResult.INVALID.
      return audio.AudioDataCallbackResult.VALID;
    } catch (error) {
      console.error('Error reading file:', error);
      // API version 11 does not support returning callback results. Starting from API version 12, returning callback results is supported.
      return audio.AudioDataCallbackResult.INVALID;
    }
  };
  audio.createAudioRenderer(audioRendererOptions, (err, renderer) => { // Create an AudioRenderer instance.
    if (!err) {
      console.info(`${TAG}: creating AudioRenderer success`);
      audioRenderer = renderer;
      if (audioRenderer !== undefined) {
        audioRenderer.on('writeData', writeDataCallback);
      }
    } else {
      console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
    }
  });
}

// Start audio rendering.
async function startRender(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioRenderer !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(audioRenderer.state.valueOf()) === -1) { // Rendering can be started only when the state is one of prepared, paused, or stopped.
      console.error(TAG + 'start failed');
      return;
    }
    // Start rendering.
    audioRenderer.start((err: BusinessError) => {
      if (err) {
        console.error('Renderer start failed.');
      } else {
        console.info('Renderer start success.');
      }
    });
  }
}

// Stop rendering.
async function stopRender(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioRenderer !== undefined) {
    // Rendering can be stopped only when the renderer state is running or paused.
    if (audioRenderer.state.valueOf() !== audio.AudioState.STATE_RUNNING &&
      audioRenderer.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      return;
    }
    // Stop rendering.
    audioRenderer.stop((err: BusinessError) => {
      if (err) {
        console.error('Renderer stop failed.');
      } else {
        console.info('Renderer stop success.');
      }
    });
  }
}

// Destroy the instance and release resources.
async function releaseRender(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioRenderer !== undefined) {
    // Release can be performed only when the renderer state is not released.
    if (audioRenderer.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      return;
    }
    // Release resources.
    audioRenderer.release((err: BusinessError) => {
      if (err) {
        console.error('Renderer release failed.');
      } else {
        await pendingRecordingWrite;
        fs.closeSync(recordingFile.fd);
        console.info('Renderer release success.');
      }
    });
  }
}

// Create an AudioCapturer instance, and set the events to listen for.
async function init(updateCallback?: (msg: string, isError: boolean) => void, stateCallback?:
  (msg: string) => void): Promise<void> {
  audio.createAudioCapturer(audioCapturerOptions, (err, capturer) => { // Create an AudioCapturer instance.
    if (err) {
      console.error(`${TAG}: Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      // ...
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    // ...
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
      audioCapturer.on('readData', onReadData);
      // ...
    }
  });
}

// Start audio recording.
async function start(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioCapturer !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED
      , audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    // Recording can be started only when the AudioCapturer is in the STATE_PREPARED, STATE_PAUSED, or STATE_STOPPED state.
    if (stateGroup.indexOf(audioCapturer.state.valueOf()) === -1) {
      console.error(`${TAG}: start failed`);
      // ...
      return;
    }

    // Start recording.
    try {
      await audioCapturer.start();
      // ...
      console.info(`${TAG}: Capturer start success.`);
    } catch (err) {
      let error = err as BusinessError;
      // ...
      console.error(`${TAG}: Capturer start failed, code: ${error.code}, message: ${error.message}`);
    }
  }
}

// Set or cancel the mute prompt for the recording stream.
async function setAudioCapturerMuteHint(muteHint: boolean, updateCallback?: (msg: string, isError: boolean) => void):
  Promise<boolean> {
  if (audioCapturer === undefined) {
    const errorMsg = 'AudioCapturer has not been created.';
    console.error(errorMsg);
    if (updateCallback) {
      updateCallback(errorMsg, true);
    }
    return false;
  }

  if (audioCapturer.state.valueOf() !== audio.AudioState.STATE_RUNNING) {
    const errorMsg = 'AudioCapturer is not running.';
    console.error(errorMsg);
    if (updateCallback) {
      updateCallback(errorMsg, true);
    }
    return false;
  }

  try {
    await audioCapturer.setMuteHint(muteHint);
    capturerMuteHintEnabledByApp = muteHint;
    console.info(`setMuteHint ${muteHint} success.`);
    if (updateCallback) {
      updateCallback(`setMuteHint ${muteHint} success.`, false);
    }
    return true;
  } catch (err) {
    let error = err as BusinessError;
    console.error(`setMuteHint ${muteHint} failed. Code: ${error.code}, message: ${error.message}`);
    if (updateCallback) {
      updateCallback(`setMuteHint ${muteHint} failed. Code: ${error.code}, message: ${error.message}`, true);
    }
    return false;
  }
}

// Stop recording.
async function stop(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioCapturer !== undefined) {
    // The AudioCapturer can be stopped only when it is in the STATE_RUNNING or STATE_PAUSED state.
    if (audioCapturer.state.valueOf() !== audio.AudioState.STATE_RUNNING &&
      audioCapturer.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info(`${TAG}: Capturer is not running or paused`);
      // ...
      return;
    }

    // Stop recording.
    try {
      await audioCapturer.stop();
      // ...
      console.info(`${TAG}: Capturer stop success.`);
    } catch (err) {
      let error = err as BusinessError;
      // ...
      console.error(`${TAG}: Capturer stop failed, code: ${error.code}, message: ${error.message}`);
    }
  }
}

// Release the instance.
async function release(updateCallback?: (msg: string, isError: boolean) => void): Promise<void> {
  if (audioCapturer !== undefined) {
    // The AudioCapturer can be released only when it is not in the STATE_RELEASED or STATE_NEW state.
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED ||
      audioCapturer.state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info(`${TAG}: Capturer already released`);
      // ...
      return;
    }

    // Release the resources.
    try {
      await audioCapturer.release();
      capturerMuteHintEnabledByApp = false;
      console.info(`${TAG}: Capturer release success.`);
      // ...
    } catch (err) {
      let error = err as BusinessError;
      // ...
      console.error(`${TAG}: Capturer release failed, code: ${error.code}, message: ${error.message}`);
      } finally {
        await pendingRecordingWrite;
        fs.closeSync(recordingFile.fd);
      }
  }
}

// ...

// ...
```

### Setting the Mute Interruption Mode

To ensure that the recording is not interrupted by the system's focus concurrency rules, a feature is introduced to change the interruption strategy from stopping the recording to simply muting it. You can control this behavior by calling [setWillMuteWhenInterrupted](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setwillmutewheninterrupted20) when creating an AudioCapturer instance. By default, this mode is disabled, and the audio focus strategy manages the order of concurrent audio streams. When enabled, if the recording is interrupted by another application, it will go into a muted state instead of stopping or pausing. In this state, the audio captured is silent.

### Setting Mute Hint for Recording Stream

Starting from API version 24, when an app has muted a recording stream on the service side, you can call [setMuteHint](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setmutehint24) to report this state to the system audio module. The system audio module then adjusts its policies based on the reported state to reduce power consumption. Note: This feature currently takes effect only on certain PCs/2-in-1 devices. This API does not actually trigger muting, nor does it mute the recording data. It simply informs the system audio module that the app has muted the current recording stream. The app still needs to process the recording data on its own, for example, by not sending captured data or by sending silent data.

This API can only be called when the AudioCapturer is in the running state; otherwise, error code `6800103` is returned. If both a stream-level mute hint and a session-level mute hint [setCapturerMuteHint](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setcapturermutehint24) are set for the same recording stream, the stream-level mute hint takes precedence, and the stream-level setting is used. No system query API is currently provided. If you need to display the mute hint state on the UI, the app must maintain the most recently set state on its own. In the following example, `muteHint` set to `true` indicates reporting a mute hint, and `false` indicates canceling the mute hint. `capturerMuteHintEnabledByApp` is a state maintained locally by the app, recording the current value of muteHint.

<!-- @[set_mute_hint](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 

``` TypeScript
try {
  await audioCapturer.setMuteHint(muteHint);
  capturerMuteHintEnabledByApp = muteHint;
  console.info(`setMuteHint ${muteHint} success.`);
  // ...
} catch (err) {
  let error = err as BusinessError;
  console.error(`setMuteHint ${muteHint} failed. Code: ${error.code}, message: ${error.message}`);
  // ...
}
```

### Echo Cancellation

Echo cancellation effectively eliminates echo interference during recording on supported devices, thereby improving audio capture quality. You can enable this feature by specifying particular microphone audio [source types](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8) (**SOURCE_TYPE_VOICE_COMMUNICATION** or **SOURCE_TYPE_LIVE**). Once enabled, the system automatically processes the captured audio signal to cancel echoes.

Before enabling this feature, you are advised to call [isAcousticEchoCancelerSupported](../../reference//apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isacousticechocancelersupported20) to check whether the device supports echo cancellation for the audio input [source type](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8). (This API is available since API version 20.) If supported, you can activate the echo cancellation processing by setting the corresponding microphone audio source when creating the audio capturer.