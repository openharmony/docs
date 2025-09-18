# Functions
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## audio.getAudioManager

getAudioManager(): AudioManager

Obtains an AudioManager instance.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Return value**

| Type                         | Description        |
| ----------------------------- | ------------ |
| [AudioManager](arkts-apis-audio-AudioManager.md) | AudioManager instance.|

**Example**
```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions, callback: AsyncCallback\<AudioRenderer>): void

Creates an AudioRenderer instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                           | Mandatory| Description            |
| -------- | ----------------------------------------------- | ---- | ---------------- |
| options  | [AudioRendererOptions](arkts-apis-audio-i.md#audiorendereroptions8)  | Yes  | Renderer configurations.    |
| callback | AsyncCallback<[AudioRenderer](arkts-apis-audio-AudioRenderer.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the AudioRenderer instance obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
  channels: audio.AudioChannel.CHANNEL_2, // Channel.
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
};

let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
  rendererFlags: 0 // AudioRenderer flag.
};

let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};

let audioRenderer: audio.AudioRenderer;

audio.createAudioRenderer(audioRendererOptions,(err, data) => {
  if (err) {
    console.error(`AudioRenderer Created: Error: ${err}`);
  } else {
    console.info('AudioRenderer Created: SUCCESS');
    audioRenderer = data;
  }
});
```

## audio.createAudioRenderer<sup>8+</sup>

createAudioRenderer(options: AudioRendererOptions): Promise<AudioRenderer\>

Creates an AudioRenderer instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type                                          | Mandatory| Description        |
| :------ | :--------------------------------------------- | :--- | :----------- |
| options | [AudioRendererOptions](arkts-apis-audio-i.md#audiorendereroptions8) | Yes  | Renderer configurations.|

**Return value**

| Type                                     | Description            |
| ----------------------------------------- | ---------------- |
| Promise<[AudioRenderer](arkts-apis-audio-AudioRenderer.md)> | Promise used to return the AudioRenderer instance.|

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
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
  rendererFlags: 0 // AudioRenderer flag.
};

let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};

let audioRenderer: audio.AudioRenderer;

audio.createAudioRenderer(audioRendererOptions).then((data) => {
  audioRenderer = data;
  console.info('AudioFrameworkRenderLog: AudioRenderer Created : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: AudioRenderer Created : ERROR : ${err}`);
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions, callback: AsyncCallback<AudioCapturer\>): void

Creates an AudioCapturer instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Required permissions**: ohos.permission.MICROPHONE

This permission is required when [SourceType](arkts-apis-audio-e.md#sourcetype8) is set to **SOURCE_TYPE_MIC**, **SOURCE_TYPE_VOICE_RECOGNITION**, **SOURCE_TYPE_VOICE_COMMUNICATION**, **SOURCE_TYPE_VOICE_MESSAGE**, or **SOURCE_TYPE_CAMCORDER**.

**Parameters**

| Name  | Type                                           | Mandatory| Description            |
| :------- | :---------------------------------------------- | :--- | :--------------- |
| options  | [AudioCapturerOptions](arkts-apis-audio-i.md#audiocaptureroptions8)  | Yes  | Capturer configurations.|
| callback | AsyncCallback<[AudioCapturer](arkts-apis-audio-AudioCapturer.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the AudioCapturer instance obtained; otherwise, **err** is an error object. If the operation fails, an error object with one of the following error codes is returned:<br>Error code 6800301: indicates a parameter verification exception, permission verification exception, or system processing exception. For details, see system logs.<br>Error code 6800101: indicates that a mandatory parameter is null or the parameter type is incorrect.|

**Example**

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
  capturerFlags: 0 // AudioCapturer flag.
};

let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};

let audioCapturer: audio.AudioCapturer;

audio.createAudioCapturer(audioCapturerOptions, (err, data) => {
  if (err) {
    console.error(`AudioCapturer Created : Error: ${err}`);
  } else {
    console.info('AudioCapturer Created : SUCCESS');
    audioCapturer = data;
  }
});
```

## audio.createAudioCapturer<sup>8+</sup>

createAudioCapturer(options: AudioCapturerOptions): Promise<AudioCapturer\>

Creates an AudioCapturer instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Required permissions**: ohos.permission.MICROPHONE

This permission is required when [SourceType](arkts-apis-audio-e.md#sourcetype8) is set to **SOURCE_TYPE_MIC**, **SOURCE_TYPE_VOICE_RECOGNITION**, **SOURCE_TYPE_VOICE_COMMUNICATION**, **SOURCE_TYPE_VOICE_MESSAGE**, or **SOURCE_TYPE_CAMCORDER**.

**Parameters**

| Name | Type                                          | Mandatory| Description            |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| options | [AudioCapturerOptions](arkts-apis-audio-i.md#audiocaptureroptions8) | Yes  | Capturer configurations.|

**Return value**

| Type                                     | Description                  |
| ----------------------------------------- |----------------------|
| Promise<[AudioCapturer](arkts-apis-audio-AudioCapturer.md)> | Promise used to return the result. If the operation is successful, an AudioCapturer instance is returned; otherwise, an error object with either of the following error codes is returned:<br>Error code 6800301: indicates a parameter verification exception, permission verification exception, or system processing exception. For details, see system logs.<br>Error code 6800101: indicates that a mandatory parameter is null or the parameter type is incorrect.|

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
  source: audio.SourceType.SOURCE_TYPE_MIC, // Audio source type: microphone. Set this parameter based on the service scenario.
  capturerFlags: 0 // AudioCapturer flag.
};

let audioCapturerOptions:audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};

let audioCapturer: audio.AudioCapturer;

audio.createAudioCapturer(audioCapturerOptions).then((data) => {
  audioCapturer = data;
  console.info('AudioCapturer Created : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`AudioCapturer Created : ERROR : ${err}`);
});
```

## audio.createAudioLoopback<sup>20+</sup>

createAudioLoopback(mode: AudioLoopbackMode): Promise<AudioLoopback\>

Creates an AudioLoopback instance. This API uses a promise to return the result.

Before using **createAudioLoopback**, call [isAudioLoopbackSupported](arkts-apis-audio-AudioStreamManager.md#isaudioloopbacksupported20) to check whether the system supports the audio loopback mode.


**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Required permissions**: ohos.permission.MICROPHONE

**Parameters**

| Name | Type                                          | Mandatory| Description            |
| :------ | :--------------------------------------------- | :--- | :--------------- |
| mode | [AudioLoopbackMode](arkts-apis-audio-e.md#audioloopbackmode20) | Yes  | Audio loopback mode.|

**Return value**

| Type                                     | Description                  |
| ----------------------------------------- |----------------------|
| Promise<[AudioLoopback](arkts-apis-audio-AudioLoopback.md)> | Promise used to return the result. If the operation is successful, an AudioLoopback instance is returned; otherwise, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | -------------------------------|
|     201 | Permission denied.             |
|     801 | Unsupported API.               |
| 6800101 | Parameter verification failed. |
| 6800104 | Loopback mode is unsupported.  |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioLoopback: audio.AudioLoopback;

audio.createAudioLoopback(audio.AudioLoopbackMode.HARDWARE).then((data) => {
  audioLoopback = data;
  console.info('AudioLoopback Created : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`AudioLoopback Created : ERROR : ${err}`);
});
```
