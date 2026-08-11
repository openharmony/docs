# Troubleshooting No Audio During Recording

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=65bb9604a921f234d3e9f4b6d8fc347f11f12a39 translatedAt=2026-08-06T01:45:58.720Z pushedAt=2026-08-06T07:23:16.609Z -->

When implementing audio recording, you may encounter issues such as recording startup failure, no recording data callback, or silent recording files. This document describes common symptoms of the no-audio-during-recording issue, relevant background knowledge, and troubleshooting methods, along with reference code examples and a troubleshooting process.

## Symptom

Common symptoms of no audio during app recording are as follows:

- The recording instance fails to be created or fails to start.

- The recording instance is created and started successfully, but no recording data callback is received.

- The recording data callback is received, but the data length is always 0, or the recording file plays back as complete silence.

- After recording starts normally, it becomes silent during calls, Bluetooth switching, headset plugging/unplugging, or other specific scenarios.

## Possible Causes

**1. Prerequisites not met**

   Before starting recording, you must apply for permissions, configure parameters, and create a recording instance. If permissions are not granted, parameters do not match the service scenario, or instance creation fails, subsequent recording startup or data callback reception will be affected. For the basic recording process, see [Using AudioCapturer for Audio Recording (ArkTS)](using-audiocapturer-for-recording.md).

**2. Recording started but content is muted or affected by routing**

   No audio during recording does not necessarily mean that recording has not started. It may also be caused by muted recording, input device route changes, concurrency policy taking effect, or abnormal file writing logic in the app. Common symptoms include: "The `readData` callback is received, but the playback is completely silent," "Audio becomes silent after a call, Bluetooth switching, or headset plug/unplug," and "Recording content is incorrect after a peripheral device is connected."

**3. Recording parameters do not match the service scenario**

   `SourceType` affects the recording path, algorithm processing, concurrency interruption policy, and input device selection. An incorrect `SourceType` may cause the phenomenon of "data is received but nearly silent," or the recorded data may be completely inconsistent with service expectations. For example, regular microphone recording mistakenly uses `SOURCE_TYPE_VOICE_COMMUNICATION`, or the raw capture scenario does not select the correct source type based on the service. For related information, see [Choosing the Right Recording Stream Type](using-right-sourcetype-for-recording.md).

**4. Running state and callbacks do not change as expected**

   In a recording scenario, in addition to checking whether the `start` API succeeds, you must also pay attention to state changes, data read callbacks, input device information, and recording stream change information. Common symptoms include: "`start` returns success but no data is received at all," "the instance has been created but the state never enters `STATE_RUNNING`," and "after the object is released early by the page lifecycle, subsequent calls no longer take effect." If you are unsure what to check first, troubleshoot in the following order: permission → creation → `STATE_RUNNING` → `readData` → file writing → `SourceType` → input device/concurrency.

## Locating Process

Follow the sequence below to troubleshoot step by step. At each step, first confirm an observable result, and then proceed to the next step or jump to the corresponding document based on that result.

1. Confirm the prerequisites for starting recording.

   At this step, first check whether the basic prerequisites are met. It is recommended to check in the following order: permission → parameter configuration → creation result.

   The check items are as follows:

   - Permission: Verify that the app has declared and requested the `ohos.permission.MICROPHONE` permission. For permission declaration, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md). For dynamic authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

   - Parameter configuration: Verify that the sample rate, number of channels, sample format, encoding format, and `SourceType` meet the service scenario requirements.

   - Creation result: Verify that `createAudioCapturer` has successfully returned a capturer instance. If creation fails, troubleshoot the permission, parameter configuration, and concurrency scenario based on the error code and logs.

   Before creating a capturer instance, for standard microphone recording, refer to the parameter configuration below. For VoIP scenarios, select the appropriate source type and data flow direction based on the voice call scenario.

   ``` TypeScript
   let audioStreamInfo: audio.AudioStreamInfo = {
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
     channels: audio.AudioChannel.CHANNEL_2,
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
   };
   let audioCapturerInfo: audio.AudioCapturerInfo = {
     source: audio.SourceType.SOURCE_TYPE_MIC,
     capturerFlags: 0
   };
   let audioCapturerOptions: audio.AudioCapturerOptions = {
     streamInfo: audioStreamInfo,
     capturerInfo: audioCapturerInfo
   };
   ```

   For the creation process, refer to `create_AudioCapturer` in the AudioCaptureSampleJS page code.

   <!-- @[create_AudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   // ...
   let audioStreamInfo: audio.AudioStreamInfo = {
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sample rate.
     channels: audio.AudioChannel.CHANNEL_2, // Channel.
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sample format.
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
   };
   let audioCapturerInfo: audio.AudioCapturerInfo = {
     source: audio.SourceType.SOURCE_TYPE_MIC, // Source type: Mic audio source. Configure based on the service scenario. See SourceType.
     capturerFlags: 0 // Audio capturer flag.
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

2. Check whether the recording instance has entered the running state.

   Check in the following order: `start` result → current state → state change → early release.

  The check items are as follows:

   - `start` result: Verify that the `start` API is called successfully.

   - Current state: Read `audioCapturer.state`, or register the `stateChange` event to confirm the state change.

   - State change: If the state does not enter `STATE_RUNNING`, print the current state and check whether the instance state before `start` is `STATE_PREPARED`, `STATE_PAUSED`, or `STATE_STOPPED`.

   - Premature release: Verify that no other service calls `stop`, `pause`, or `release` prematurely.

   - OHAudio callback: When using OHAudio to develop the recording feature, verify that the state callback is registered as required by the C/C++ API, and confirm that the state enters the running state after startup. For related APIs, see [Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md).

   For state query and state listening, refer to `view_AudioCapturerState` and `listen_AudioCapturerState` in the AudioCaptureSampleJS page code.

   <!-- @[view_AudioCapturerState](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioCapture.ets) --> 

   ``` TypeScript
   let audioCapturerState: audio.AudioState = audioCapturer.state;
   console.info(`Current state is: ${audioCapturerState }`)
   ```

3. If no recording data callback is received, check the callback registration and object lifecycle.

   Check the items in the following order: registration timing → running state → object lifecycle → callback duration.

   The check items are as follows:

   - Registration timing: Verify that `audioCapturer.on('readData', readDataCallback)` is called to register the callback after the recording instance is successfully created.

   - Running state: Verify that the recording instance has entered `STATE_RUNNING`.

   - Object lifecycle: If the callback has been registered but no data is received, verify that the recording object has not been released prematurely by the page lifecycle, route switching, or service cleanup logic.

   - Callback time consumption: Verify that no time-consuming tasks such as uploading, transcoding, or large file writing and merging are performed in the `readData` callback, to avoid blocking the data reading thread.

   - OHAudio callback: When using OHAudio to develop the recording feature, verify that the audio data reading callback has been set as required by the C/C++ API. For details, see [Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md).

   For callback registration, refer to `listen_AudioCapturer` in the AudioCaptureSampleJS page code.

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

4. If the `readData` callback is received but the recording result has no sound, check the data writing and parsing logic.

   Check in the following order: file handle → write offset → write length → PCM parsing parameters → data lifecycle.

   The check items are as follows:

   - File handle: Verify that the file handle is created successfully.

   - Write offset: Verify that the offset used during writing increments with the cumulative number of bytes written, to avoid overwriting the same data segment repeatedly.

   - Write length: Ensure that the write length matches `buffer.byteLength` in the `readData` callback to avoid writing only partial data.

   - PCM parsing parameters: Ensure that the sample rate, number of channels, and sample format used for subsequent playback or PCM parsing are consistent with the recording parameters.

   - Data lifecycle: If you need to stop recording before splicing, uploading, transcoding, or parsing PCM data, do not retain a long-term reference to the `ArrayBuffer` parameter of the `readData` callback. Instead, immediately copy an independent data copy within the callback and then pass it to subsequent business processing.

   For the file writing process, refer to `readDataCallback` in the AudioCaptureSampleJS page code.

   ``` TypeScript
   readDataCallback = (buffer: ArrayBuffer) => {
     let options: Options = {
       offset: bufferSize,
       length: buffer.byteLength
     }
     fs.writeSync(file.fd, buffer, options);
     bufferSize += buffer.byteLength;
   };
   ```

5. If the recorded content remains silent, check the source type and mute policy.

Check in the following order: `SourceType` → mute interruption policy → audio session policy → concurrency timing.

The check items are as follows:

- `SourceType`: Check whether `SourceType` matches the service scenario. Normal recording typically uses `SOURCE_TYPE_MIC`, VoIP call scenarios use `SOURCE_TYPE_VOICE_COMMUNICATION`, live streaming scenarios use `SOURCE_TYPE_LIVE`, and raw data collection scenarios use `SOURCE_TYPE_UNPROCESSED`. For more information, see [Choosing the Right Recording Stream Type](using-right-sourcetype-for-recording.md).

- Mute interruption policy: Check whether the app has called `setWillMuteWhenInterrupted`.

- Audio session policy: Check whether an audio session policy is configured and its behavior is set to `MUTE_WHEN_INTERRUPTED`.

   - Concurrency timing: Check whether the time when no sound occurs coincides with an incoming call, VoIP, voice announcement, or the start of another recording task. If you suspect that the recording stream is muted or affected by the concurrency policy, you can identify the current recording stream and input device through recording stream change information.

6. If the issue is related to peripherals or concurrency scenarios, check the input device, routing, and recording policy.

   Check in the following order: current input device → device switching → other recording streams → concurrency policy.

   The check items are as follows:

   - Current input device: Check whether the currently active input device is the expected device.

   - Device switching: Check whether input device switching (such as Bluetooth headset, wired headset, or USB sound card) occurs before or after recording starts. For querying and listening for audio input devices, see [Querying and Listening for Audio Input Devices](audio-input-device-management.md).

   - Route switching: If your app needs to specify an input device or handle device switching, see [Switching Audio Input Devices](audio-input-device-switcher.md).

   - Other recording streams: Check whether other recording tasks exist on the current device. See [Querying and Listening for the Recording Status of Other Applications](audio-recording-stream-management.md) to check whether other recording streams exist.

   - Concurrency policy: If your service runs concurrently with scenarios such as VoIP calls, system incoming calls, voice recognition, transcription, ear return, or live streaming, see [Recording Concurrency Strategy Description](audio-recording-concurrency.md) to check the system policy.

   If the absence of sound is related to calls, other recording tasks, Bluetooth headsets, wired headsets, or USB sound cards, you can check the recording stream change and input device information to confirm whether the current recording stream, `SourceType`, and input device meet expectations.

   <!-- @[audioStreamManager_on](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioStreamManager.ets) --> 

   ``` TypeScript
   audioStreamManager.on('audioCapturerChange', (audioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) =>  {
     // ...
     for (let i = 0; i < audioCapturerChangeInfoArray.length; i++) {
       console.info(`## CapChange on is called for element ${i} ##`);
       console.info(`StreamId for ${i} is: ${audioCapturerChangeInfoArray[i].streamId}`);
       console.info(`Source for ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.source}`);
       console.info(`Flag  ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
   
       // ...
   
       let devDescriptor: audio.AudioDeviceDescriptors = audioCapturerChangeInfoArray[i].deviceDescriptors;
       for (let j = 0; j < audioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
         console.info(`Id: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
         console.info(`Type: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
         console.info(`Role: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
         console.info(`Name: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
         console.info(`Address: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
         console.info(`SampleRates: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
         console.info(`ChannelCounts ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
         console.info(`ChannelMask: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
       }
     }
     // ...
   });
   ```

   When obtaining the Bluetooth device name or address through the recording stream information query API, if the app has not declared the `ohos.permission.USE_BLUETOOTH` permission, the Bluetooth device-related name and address fields may be empty.

## References

- If the issue is related to common recording, VoIP, live streaming, or raw data capture scenarios, see [Choosing the Right Recording Stream Type](using-right-sourcetype-for-recording.md) first.

- If the issue is related to concurrency with other recording tasks, calls, or audio session policies, see [Recording Concurrency Strategy Description](audio-recording-concurrency.md) and [Querying and Listening for the Recording Status of Other Applications](audio-recording-stream-management.md) first.

- If the issue is related to switching between input devices such as Bluetooth headsets, wired headsets, and USB sound cards, see [Querying and Listening for Audio Input Devices](audio-input-device-management.md) and [Switching Audio Input Devices](audio-input-device-switcher.md) first.