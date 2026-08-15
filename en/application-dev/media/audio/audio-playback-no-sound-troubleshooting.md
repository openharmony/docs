# Troubleshooting Silent Playback Issues

 <!--Kit: Audio Kit-->
 <!--Subsystem: Multimedia-->
 <!--Owner: @boxwell-->
 <!--Designer: @magekkkk-->
 <!--Tester: @Filger-->
 <!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=5e96177c24aa23aee8ea58c394f1a2c3298d3e1c translatedAt=2026-08-15T01:55:22.653Z pushedAt=2026-08-15T08:45:58.023Z -->

When implementing audio playback, developers may encounter issues such as failure to create or start a playback instance, or silent playback. This document describes common symptoms, related background knowledge, and troubleshooting methods for silent playback scenarios, and provides sample code and troubleshooting procedures for direct reference.

## Symptom

During app playback, common silent playback scenarios include:

- No sound is played after playback starts.

- Sound is played after playback starts, but suddenly becomes silent after a period of time.

- Sound is played after playback starts, but becomes silent after performing foreground/background operations, switching devices, concurrent audio playback, or other operations.

## Possible Causes

**1. Playback instance creation fails.**

   You need to configure parameters by referring to the [audio formats](audio-kit-intro.md#supported-audio-formats) supported by the current system, and properly plan the lifecycle of the playback instance. If you set invalid parameters, or if the current app or system exceeds the maximum number of creatable instances, the instance creation will fail.

**2. The playback instance is not in the running state.**

   When implementing audio playback, apps need to not only check whether the `OH_AudioRenderer_Start` API is called successfully, but also pay attention to state changes, output device information, and playback stream changes. Failure to properly handle this information may result in issues such as "no sound after being interrupted by another audio stream in multi-audio scenarios" or "no sound after device disconnection".

**3. Abnormal audio data transmission from the app.**

   The system typically uses streaming to obtain audio data from the app frame by frame through the `OH_AudioRenderer_OnWriteDataCallback` callback. If the app incorrectly passes silent data or blocks the current callback function, the entire audio pipeline will play back abnormally, resulting in no sound.

**4. The volume is set to an extremely low value or 0.**

   When the stream or system volume is set to an extremely low value or 0, the device will produce no sound. In addition, in certain special scenarios, such as Do Not Disturb mode or Silent mode, ringer and notification streams will also produce no sound.

**5. Failure to integrate long-term tasks or concurrency control restrictions.**

The system enforces various restrictions, such as long-running task permissions and concurrency control, to prevent apps from abusing system resources and to optimize the system audio experience. Failure to properly integrate long-running tasks or handle concurrent tasks may result in no sound after the app moves to the background, the screen turns off, or the audio stream is interrupted by another audio stream.

## Locating Process

Follow the sequence below to troubleshoot step by step. At each step, first confirm an observable result, and then proceed to the next step or jump to the corresponding document based on that result.

1. Confirm the playback instance creation status.

   The check items are as follows:

   - Parameter configuration: Ensure that the sample rate, channel count, sample format, encoding format, and `StreamUsage` match the service scenario. You can configure parameters by referring to the [supported audio formats](audio-kit-intro.md#supported-audio-formats) of the current system.

   - Creation result: Confirm that `OH_AudioStreamBuilder_GenerateRenderer` has successfully returned a playback instance. If creation fails, troubleshoot permissions, parameter configuration, and concurrency scenarios based on the error code and logs.

   - Excessive creation: System resources are limited. Unrestricted creation of audio streams by an app can exhaust system resources. Therefore, when the number of audio streams created by an app exceeds a certain limit, the system prevents the app from creating additional audio streams. After confirming that an audio stream is no longer in use, call `OH_AudioStreamBuilder_Destroy` promptly to release the audio resources.

Refer to the following example for audio parameter settings.

   <!-- @[Render_ConfigStream](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

   ``` C++
   // Set the audio sample rate.
   // Starting from API version 26.0.0, the audio rendering extension supports sample rate values ranging from 8000 Hz to 384000 Hz in steps of 10 Hz. The supported sample rate specifications may vary depending on the specific device.
   const int SAMPLING_RATE_48K = 48000;
   OH_AudioStreamBuilder_SetSamplingRate(builder, SAMPLING_RATE_48K);
   // Set the audio channels.
   const int channelCount = 2;
   OH_AudioStreamBuilder_SetChannelCount(builder, channelCount);
   // Set the audio sample format.
   OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
   // Set the encoding type of the audio stream.
   OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
   // Set the usage scenario of the output audio stream.
   OH_AudioStreamBuilder_SetRendererInfo(builder, AUDIOSTREAM_USAGE_MUSIC);
   ```

2. Confirm whether the playback instance is in the running state.

   The check items are as follows:

   - `start` result: Confirm that the `OH_AudioRenderer_Start` API is called successfully.

   - Current state: You can call `OH_AudioRenderer_GetCurrentState` to obtain the current audio stream state.

   - State change: If the state does not enter `STATE_RUNNING`, print the current state and check whether the state is `STATE_PREPARED`, `STATE_PAUSED`, or `STATE_STOPPED` before calling `OH_AudioRenderer_Start` to start the instance. Starting the instance in a state other than those listed above will also cause the start to fail.

   - Premature release: Verify that `OH_AudioRenderer_Pause`, `OH_AudioRenderer_Stop`, or `OH_AudioRenderer_Release` is not called after starting the instance, which would transition the instance to a non-running state.

3. If the `OH_AudioRenderer_OnWriteDataCallback` playback data callback is not received, check the callback registration and object lifecycle.

   The check items are as follows:

   - Registration timing: Verify that `OH_AudioStreamBuilder_SetRendererWriteDataCallback` is called to register the callback after the playback instance is successfully created.

   - Running state: Verify that the playback instance has entered `STATE_RUNNING`.

   - Object lifecycle: If the playback instance is in the running state but no callback is received, ensure that the playback instance has not been released prematurely by the page lifecycle, route switching, or service cleanup logic.

   - Callback duration: Ensure that no time-consuming tasks such as complex audio effect processing or large file write/merge operations are performed in the `OH_AudioRenderer_OnWriteDataCallback` callback, and that the callback does not take too long to return, to avoid blocking the next data callback.

   For callback registration, refer to `SetRendererWriteDataCallback` in the AudioRendererSampleC page code.

   <!-- @[Render_SetRendererWriteDataCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

   ``` C++
   // Custom write data function.
   static OH_AudioData_Callback_Result MyOnWriteData_New(
       OH_AudioRenderer* renderer,
       void* userData,
       void* audioData,
       int32_t audioDataSize)
   {
       // Write the data to be played into audioData based on the audioDataSize length.
       // If you do not want to play a certain audioData segment, return AUDIO_DATA_CALLBACK_RESULT_INVALID.
       size_t readCount = fread(audioData, audioDataSize, 1, g_fp);
       if (readCount == 0) {
           return AUDIO_DATA_CALLBACK_RESULT_INVALID;
       }
       if (feof(g_fp)) {
           fseek(g_fp, 0, SEEK_SET);
       }
       return AUDIO_DATA_CALLBACK_RESULT_VALID;
   }
   // ...
       // Configure the write audio data callback function.
       OH_AudioRenderer_OnWriteDataCallback writeDataCb = MyOnWriteData_New;
       OH_AudioStreamBuilder_SetRendererWriteDataCallback(builder, writeDataCb, nullptr);
   ```

4. If the `OH_AudioRenderer_OnWriteDataCallback` callback is received and data is written at a normal cycle but no sound is produced, check the data write and parsing logic.

   The check items are as follows:

   - Data generation: Ensure that the audio source data stream is generated properly and that sufficient data is available to support the write operation when the playback callback is received.

   - Data write: Ensure that audio data is written starting from the first address of `audioData` and correctly written to the returned buffer memory, avoiding repeated overwriting of the same data segment.

   - Write length: Ensure that the write length matches `audioDataSize` in the `OH_AudioRenderer_OnWriteDataCallback` callback, and avoid writing only partial data or no data.

   - Data lifecycle: Audio playback uses streaming mode. Do not perform blocking operations or overly time-consuming algorithm processing in the callback function (it is recommended that a single callback takes no more than 15 ms), as a long delay in returning from the callback may cause the system to have no data to play. In addition, after the callback returns, do not save the address of `audioData` or perform other memory operations on it, to prevent the system from reading unexpected data.

   - Return length: If you cannot fill the buffer with the required amount of data, it is recommended that you return `AUDIO_DATA_CALLBACK_RESULT_INVALID`. In this case, the system does not process this segment of audio data and requests data from the app again. If you return `AUDIO_DATA_CALLBACK_RESULT_VALID` without writing data to `audioData`, it also causes the no-sound issue.

5. If the callback writes data normally but playback remains silent, check the current system settings.

   The check items are as follows:

   - Volume settings: You can query the volume of the current audio stream by calling `OH_AudioRenderer_GetVolume`, or monitor volume changes of the current audio stream through `OH_AudioVolumeManager_OnStreamVolumeChangeCallback`, to confirm whether the volume is too low or an unexpected mute operation has occurred.

   - Do Not Disturb mode: In Do Not Disturb mode, if the audio stream type set is ringtone or notification, the system plays it silently. You can refer to [@ohos.intelligentScene (Intelligent Scene)](../../reference/apis-basic-services-kit/js-apis-intelligentScene.md) to check whether the system's Do Not Disturb feature is enabled and whether the app itself allows interruptions.

   - Foreground/background (screen-on/screen-off) playback differences: The system has an internal power consumption policy. When an app switches to the background without requesting a continuous task, it causes no sound. If playback is normal when the app is in the foreground or the screen is on, but becomes persistently silent when the app goes to the background or the screen turns off, check whether the app has integrated AVSession or requested a [continuous task (ArkTS)](../../task-management/continuous-task.md). For detailed adaptation guides, see [Accessing AVSession](../avsession/avsession-access-scene.md) and [Background Playback](../avsession/avsession-background-scene.md).

6. If the issue is related to peripheral operations or concurrency scenarios, check the output device and concurrent playback policy.

   The check items are as follows:

   - Device switching: Check whether device switching (such as Bluetooth headset or wired headset) occurs before or after playback starts, and whether the callback functions handle audio stream processing accordingly. For example, when a Bluetooth device is disconnected, a device change callback is sent and the app pauses the audio stream on its own.

   - Concurrency policy: Check whether other audio tasks exist on the current device. If no sound occurs after your service runs concurrently with scenarios such as VoIP calls, cellular calls, alarms, or voice messages, refer to [Introduction to Audio Focus](audio-playback-concurrency.md) to understand the system-side audio policy, and also refer to [Handling Audio Focus Changes](audio-playback-concurrency.md#handling-audio-focus-changes) to ensure that focus callbacks are handled correctly.

## References

- For sample code on using OHAudio for playback, see [(Recommended) Using OHAudio for Audio Playback (C/C++)](using-ohaudio-for-playback.md).

- For sample code of using AudioRenderer for playback, refer to [Using AudioRenderer for Audio Playback (ArkTS)](using-audiorenderer-for-playback.md).

- If the issue is related to concurrency with other audio tasks, refer to [Introduction to Audio Focus](audio-playback-concurrency.md) first, and also see [Handling Audio Focus Changes](audio-playback-concurrency.md#handling-audio-focus-changes).

- For the background playback adaptation guide, see [Background Playback](../avsession/avsession-background-scene.md).