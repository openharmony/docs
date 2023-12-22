# Developing Audio Call (ArkTS)

During an audio call, audio output (playing the peer voice) and audio input (recording the local voice) are carried out simultaneously. You can use the AudioRenderer to implement audio output and the AudioCapturer to implement audio input.

Before starting or stopping using the audio call service, the application needs to check the [audio scene](audio-call-overview.md#audio-scene) and [ringer mode](audio-call-overview.md#ringer-mode) to adopt proper audio management and prompt policies.

The sample code below demonstrates the basic process of using the AudioRenderer and AudioCapturer to implement the audio call service, without the process of call data transmission. In actual development, the peer call data transmitted over the network needs to be decoded and played, and the sample code uses the process of reading an audio file instead; the local call data needs to be encoded and packed and then sent to the peer over the network, and the sample code uses the process of writing an audio file instead.

## Using AudioRenderer to Play the Peer Voice

This process is similar to the process of [using AudioRenderer to develop audio playback](using-audiorenderer-for-playback.md). The key differences lie in the **audioRendererInfo** parameter and audio data source. In the **audioRendererInfo** parameter used for audio calling, **content** must be set to **CONTENT_TYPE_SPEECH**, and **usage** must be set to **STREAM_USAGE_VOICE_COMMUNICATION**.

```ts
import audio from '@ohos.multimedia.audio';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

const TAG = 'VoiceCallDemoForAudioRenderer';
// The process is similar to the process of using AudioRenderer to develop audio playback. The key differences lie in the audioRendererInfo parameter and audio data source.
let context = getContext(this);
let renderModel: audio.AudioRenderer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
  channels: audio.AudioChannel.CHANNEL_2, // Channel.
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
}
let audioRendererInfo: audio.AudioRendererInfo = {
  // Parameters corresponding to the call scenario need to be used.
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // Audio stream usage type: voice communication.
  rendererFlags: 0 // AudioRenderer flag. The default value is 0.
}
let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
}

// Create an AudioRenderer instance, and set the events to listen for.
audio.createAudioRenderer(audioRendererOptions, (err: BusinessError, renderer: audio.AudioRenderer) => { // Create an AudioRenderer instance.
  if (!err) {
    console.info(`${TAG}: creating AudioRenderer success`);
    renderModel = renderer;
    if (renderModel !== undefined) {
      renderModel.on('stateChange', (state: audio.AudioState) => { // Set the events to listen for. A callback is invoked when the AudioRenderer is switched to the specified state.
        if (state == 1) {
          console.info('audio renderer state is: STATE_PREPARED');
        }
        if (state == 2) {
          console.info('audio renderer state is: STATE_RUNNING');
        }
      });
      renderModel.on('markReach', 1000, (position: number) => { // Subscribe to the markReach event. A callback is triggered when the number of rendered frames reaches 1000.
        if (position == 1000) {
          console.info('ON Triggered successfully');
        }
      });
    }
  } else {
    console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
  }
});

// Start audio rendering.
async function start() {
  if (renderModel !== undefined) {
    let stateGroup: number[] = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(renderModel.state.valueOf()) === -1) { // Rendering can be started only when the AudioRenderer is in the STATE_PREPARED, STATE_PAUSED, or STATE_STOPPED state.
      console.error(TAG + 'start failed');
      return;
    }
    await renderModel.start(); // Start rendering.
    const bufferSize: number = await renderModel.getBufferSize();
    // The process of reading audio file data is used as an example. In actual audio call development, audio data transmitted from the peer needs to be read.

    let path = context.filesDir;

    const filePath = path + '/voice_call_data.wav'; // Sandbox path. The actual path is /data/storage/el2/base/haps/entry/files/voice_call_data.wav.
    let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
    let stat = await fs.stat(filePath);
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize === 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    class Option {
      offset: number = 0
      length: number = 0
    }
    for (let i = 0; i < len; i++) {
      let options: Option = {
        offset: i * bufferSize,
        length: bufferSize
      };
      let readsize = await fs.read(file.fd, buf, options);
      // buf indicates the audio data to be written to the buffer. Before calling AudioRenderer.write(), you can preprocess the audio data for personalized playback. The AudioRenderer reads the audio data written to the buffer for rendering.
      let writeSize: number = await renderModel.write(buf);
      if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) { // The rendering stops if the AudioRenderer is in the STATE_RELEASED state.
        fs.close(file);
        await renderModel.stop();
      }
      if (renderModel.state.valueOf() === audio.AudioState.STATE_RUNNING) {
        if (i === len - 1) { // The rendering stops if the file finishes reading.
          fs.close(file);
          await renderModel.stop();
        }
      }
    }
  }
}

// Pause the rendering.
async function pause() {
  if (renderModel !== undefined) {
    // Rendering can be paused only when the AudioRenderer is in the STATE_RUNNING state.
    if (renderModel.state.valueOf() !== audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      return;
    }
    await renderModel.pause(); // Pause rendering.
    if (renderModel.state.valueOf() === audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is paused.');
    } else {
      console.error('Pausing renderer failed.');
    }
  }
}

// Stop rendering.
async function stop() {
  if (renderModel !== undefined) {
    // Rendering can be stopped only when the AudioRenderer is in the STATE_RUNNING or STATE_PAUSED state.
    if (renderModel.state.valueOf() !== audio.AudioState.STATE_RUNNING && renderModel.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      return;
    }
    await renderModel.stop(); // Stop rendering.
    if (renderModel.state.valueOf() === audio.AudioState.STATE_STOPPED) {
      console.info('Renderer stopped.');
    } else {
      console.error('Stopping renderer failed.');
    }
  }
}

// Release the instance.
async function release() {
  if (renderModel !== undefined) {
    // The AudioRenderer can be released only when it is not in the STATE_RELEASED state.
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      return;
    }
    await renderModel.release(); // Release the instance.
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer released');
    } else {
      console.error('Renderer release failed.');
    }
  }
}
```

## Using AudioCapturer to Record the Local Voice

This process is similar to the process of [using AudioCapturer to develop audio recording](using-audiocapturer-for-recording.md). The key differences lie in the **audioCapturerInfo** parameter and audio data stream direction. In the **audioCapturerInfo** parameter used for audio calling, **source** must be set to **SOURCE_TYPE_VOICE_COMMUNICATION**.

```ts
import audio from '@ohos.multimedia.audio';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let context = getContext(this);
const TAG = 'VoiceCallDemoForAudioCapturer';
// The process is similar to the process of using AudioCapturer to develop audio recording. The key differences lie in the audioCapturerInfo parameter and audio data stream direction.
let audioCapturer: audio.AudioCapturer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100, // Sampling rate.
  channels: audio.AudioChannel.CHANNEL_1, // Channel.
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
}
let audioCapturerInfo: audio.AudioCapturerInfo = {
  // Parameters corresponding to the call scenario need to be used.
  source: audio.SourceType.SOURCE_TYPE_VOICE_COMMUNICATION, // Audio source type: voice communication.
  capturerFlags: 0 // AudioCapturer flag. The default value is 0.
}
let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
}

// Create an AudioRenderer instance, and set the events to listen for.
async function init() {
  audio.createAudioCapturer(audioCapturerOptions, (err: BusinessError, capturer: audio.AudioCapturer) => { // Create an AudioCapturer instance.
    if (err) {
      console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
      audioCapturer.on('markReach', 1000, (position: number) => { // Subscribe to the markReach event. A callback is triggered when the number of captured frames reaches 1000.
        if (position === 1000) {
          console.info('ON Triggered successfully');
        }
      });
      audioCapturer.on('periodReach', 2000, (position: number) => { // Subscribe to the periodReach event. A callback is triggered when the number of captured frames reaches 2000.
        if (position === 2000) {
          console.info('ON Triggered successfully');
        }
      });
    }
  });
}

// Start audio recording.
async function start() {
  if (audioCapturer !== undefined) {
    let stateGroup: number[] = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(audioCapturer.state.valueOf()) === -1) { // Recording can be started only when the AudioCapturer is in the STATE_PREPARED, STATE_PAUSED, or STATE_STOPPED state.
      console.error(`${TAG}: start failed`);
      return;
    }
    await audioCapturer.start(); // Start recording.
    // The following describes how to write audio data to a file. In actual audio call development, the local audio data needs to be encoded and packed, and then sent to the peer through the network.
    const path = context.filesDir + '/voice_call_data.wav'; // Path for storing the recorded audio file.
    let file = fs.openSync(path, 0o2 | 0o100); // Create the file if it does not exist.
    let fd = file.fd;
    let numBuffersToCapture = 150; // Write data for 150 times.
    let count = 0;
    class Options {
      offset: number = 0
      length: number = 0
    }
    while (numBuffersToCapture) {
      let bufferSize: number = await audioCapturer.getBufferSize();
      let buffer: ArrayBuffer = await audioCapturer.read(bufferSize, true);
      let options: Options = {
        offset: count * bufferSize,
        length: bufferSize
      };
      if (buffer === undefined) {
        console.error(`${TAG}: read buffer failed`);
      } else {
        let number = fs.writeSync(fd, buffer, options);
        console.info(`${TAG}: write date: ${number}`);
      }
      numBuffersToCapture--;
      count++;
    }
  }
}

// Stop recording.
async function stop() {
  if (audioCapturer !== undefined) {
    // The AudioCapturer can be stopped only when it is in STATE_RUNNING or STATE_PAUSED state.
    if (audioCapturer.state.valueOf() !== audio.AudioState.STATE_RUNNING && audioCapturer.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      return;
    }
    await audioCapturer.stop(); // Stop recording.
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_STOPPED) {
      console.info('Capturer stopped');
    } else {
      console.error('Capturer stop failed');
    }
  }
}

// Release the instance.
async function release() {
  if (audioCapturer !== undefined) {
    // The AudioCapturer can be released only when it is not in the STATE_RELEASED or STATE_NEW state.
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED || audioCapturer.state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      return;
    }
    await audioCapturer.release(); // Release the instance.
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Capturer released');
    } else {
      console.error('Capturer release failed');
    }
  }
}
```
