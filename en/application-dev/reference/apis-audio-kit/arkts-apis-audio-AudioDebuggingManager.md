# Interface (AudioDebuggingManager)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

The audio debug manager is used for audio runtime debugging, including features such as retrieving snapshot information, to locate abnormal issues in scenarios such as audio playback, recording, loopback, and sessions.

**Since:** 26.0.0

> **NOTE**
>
> The content and format of the snapshot information are subject to optimization and adjustment based on developer usage and feedback, and may change across versions. Therefore, it is intended for manual debugging reference only. You are advised not to build functional logic that depends on the snapshot information.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## printAppInfo

printAppInfo(fd: number): void

Prints a complete audio runtime snapshot of the current application process. The snapshot contains information about all playback streams, recording streams, and audio sessions.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters:**

| Name| Type| Mandatory| Description|
| -------- | -------- | ---- | ---- |
| fd | number | Yes| File descriptor, which specifies the write location for the snapshot information. If `fd` is less than 0 or not writable, the snapshot information is output to the runtime log. Otherwise, it is written to the file pointed to by `fd`.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let debugManager = audioManager.getDebuggingManager();

// Output to the log.
debugManager.printAppInfo(-1);
```

## printRendererInfo

printRendererInfo(renderer: AudioRenderer, fd: number): void

Prints a complete audio runtime snapshot of the specified audio player instance. The snapshot contains stream information, path information, volume, and device information.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters:**

| Name| Type| Mandatory| Description|
| -------- | -------- | ---- | ---- |
| renderer | [AudioRenderer](arkts-apis-audio-AudioRenderer.md) | Yes| Target audio playback instance.|
| fd | number | Yes| File descriptor, which specifies the write location for the snapshot information. If `fd` is less than 0 or not writable, the snapshot information is output to the runtime log. Otherwise, it is written to the file pointed to by `fd`.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
  channels: audio.AudioChannel.CHANNEL_2, // Channel.
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
};

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario. For details, see StreamUsage.
  rendererFlags: 0 // Audio renderer flag.
};

let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};

let audioManager = audio.getAudioManager();
let debugManager = audioManager.getDebuggingManager();

audio.createAudioRenderer(audioRendererOptions).then((data) => {
  console.info('AudioFrameworkRenderLog: AudioRenderer Created : SUCCESS');
  let audioRenderer = data;
  // Output to the log.
  debugManager.printRendererInfo(audioRenderer, -1);
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: AudioRenderer Created : ERROR : ${err}`);
});
```

## printCapturerInfo

printCapturerInfo(capturer: AudioCapturer, fd: number): void

Prints a complete audio runtime snapshot of the specified audio recording instance. The snapshot contains stream information, path information, volume, and device information.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters:**

| Name| Type| Mandatory| Description|
| -------- | -------- | ---- | ---- |
| capturer | [AudioCapturer](arkts-apis-audio-AudioCapturer.md) | Yes| Target recording instance.|
| fd | number | Yes| File descriptor, which specifies the write location for the snapshot information. If `fd` is less than 0 or not writable, the snapshot information is output to the runtime log. Otherwise, it is written to the file pointed to by `fd`.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
  channels: audio.AudioChannel.CHANNEL_2, // Channel.
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // Audio source type: microphone. Set this parameter based on the service scenario. For details, see SourceType.
  capturerFlags: 0 // AudioCapturer flag.
};

let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};

let audioManager = audio.getAudioManager();
let debugManager = audioManager.getDebuggingManager();

audio.createAudioCapturer(audioCapturerOptions).then((data) => {
  console.info('AudioCapturer Created : SUCCESS');
  let audioCapturer = data;
  // Output to the log.
  debugManager.printCapturerInfo(audioCapturer, -1);
}).catch((err: BusinessError) => {
  console.error(`AudioCapturer Created : ERROR : ${err}`);
});
```

## printLoopbackInfo

printLoopbackInfo(loopback: AudioLoopback, fd: number): void

Prints a complete audio runtime snapshot of the specified loopback instance. The snapshot contains loopback status, device, and audio effect information.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters:**

| Name| Type| Mandatory| Description|
| -------- | -------- | ---- | ---- |
| loopback | [AudioLoopback](arkts-apis-audio-AudioLoopback.md) | Yes| Target loopback instance.|
| fd | number | Yes| File descriptor, which specifies the write location for the snapshot information. If `fd` is less than 0 or not writable, the snapshot information is output to the runtime log. Otherwise, it is written to the file pointed to by `fd`.|

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let debugManager = audioManager.getDebuggingManager();

audio.createAudioLoopback(audio.AudioLoopbackMode.HARDWARE).then((data) => {
  console.info('AudioLoopback Created : SUCCESS');
  let audioLoopback = data;
  // Output to the log.
  debugManager.printLoopbackInfo(audioLoopback, -1);
}).catch((err: BusinessError) => {
  console.error(`AudioLoopback Created : ERROR : ${err}`);
});
```

## printSessionInfo

printSessionInfo(session: AudioSessionManager, fd: number): void

Prints a complete audio runtime snapshot of the specified session manager instance. The snapshot contains session status, scene, policy, and device information.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Parameters:**

| Name| Type| Mandatory| Description|
| -------- | -------- | ---- | ---- |
| session | [AudioSessionManager](arkts-apis-audio-AudioSessionManager.md) | Yes| Target session manager instance.|
| fd | number | Yes| File descriptor, which specifies the write location for the snapshot information. If `fd` is less than 0 or not writable, the snapshot information is output to the runtime log. Otherwise, it is written to the file pointed to by `fd`.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
let debugManager = audioManager.getDebuggingManager();

// Output to the log.
debugManager.printSessionInfo(audioSessionManager, -1);
```
