# Implementing System Audio Recording

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=e927321177bf4cc8f913140aea3aa3b5b4a59784 translatedAt=2026-08-15T01:57:16.592Z pushedAt=2026-08-15T09:37:42.987Z -->

Starting from API version 26.0.0, Audio Kit supports apps in recording system audio using AudioCapturer (ArkTS API) or OH_AudioCapturer (C API). This topic describes the specific development methods.

Phone, Tablet, and TV devices support the `SystemCapability.Multimedia.Audio.PlaybackCapture` system capability. For other devices, you can use [canIUse()](../../reference/common/js-apis-syscap.md#caniuse) to check whether this system capability is supported. When developing with the ArkTS API, only the Stage model is supported.

When creating an AudioCapturer, configure the internal recording mode through `playbackCaptureMode`. When creating an OH_AudioCapturer, configure the internal recording mode through `OH_AudioStreamBuilder_SetPlaybackCaptureMode()`.

After configuring the internal recording mode, start it through `requestPlaybackCaptureStart()` or `OH_AudioCapturer_RequestPlaybackCaptureStart()` respectively. Starting through `start()` or `OH_AudioCapturer_Start()` is not supported.

If you need to record the screen and system audio at the same time, see [Using AVScreenCapture in Basic Scenarios](../media/avscreencapture-c-basic-process.md).

## How to Develop

The basic process of capturing internal recording audio using AudioCapturer (ArkTS API) or OH_AudioCapturer (C API) is as follows:

1. Create an audio capturer, and configure the audio stream parameters and internal recording mode.

2. Register the audio data callback to prepare for receiving the captured PCM data.

3. Call the internal recording start API of the corresponding language, and confirm the start result in the asynchronous callback.

4. After the start succeeds, process the internal recording PCM data through the audio data callback.

5. Stop capture, cancel the listener, and release the audio capturer resources.

For ArkTS development, read this topic together with the API descriptions of [AudioCapturer](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md), [AudioCapturerOptions](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiocaptureroptions8), and [AudioPlaybackCaptureMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioplaybackcapturemode).

For C/C++ development, read this topic together with the API descriptions of [OH_AudioStreamBuilderStruct](../../reference/apis-audio-kit/capi-ohaudio-oh-audiostreambuilderstruct.md), [OH_AudioCapturerStruct](../../reference/apis-audio-kit/capi-ohaudio-oh-audiocapturerstruct.md), and [OH_AudioStream_PlaybackCaptureMode](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_playbackcapturemode).

### User Authorization Process

After the app calls the internal recording start API, the system automatically displays a privacy confirmation dialog box, and the app does not need to implement the dialog box. The dialog box appearance may vary by device form. Use the actual device display as the reference.

If the user selects **Allow**, the asynchronous callback returns a successful start. If the user selects **Deny**, or if the system fails to display the dialog box, the asynchronous callback returns that the user is not authorized. The app should handle the result based on the asynchronous callback: when the callback returns success, start processing the internal recording PCM data; when the callback returns unauthorized or start failure, prompt the user and release the created audio capturer.

The start API is a non-blocking API. While waiting for the user to operate the dialog box and for the system to return the asynchronous callback, the app must not block the current thread through loop waiting, synchronous lock waiting, or other means. The C API start API returning `AUDIOSTREAM_SUCCESS` only indicates that the start request has been submitted successfully, and cannot be used as the final authorization result.

**System dialog box example:**

<img src="figures/playback-capture-authorization.jpg" width="320" alt="Audio internal recording authorization dialog">

### Development Steps and Precautions for AudioCapturer (ArkTS API)

The following ArkTS example contains code snippets. Based on your actual service requirements, you can write the captured PCM data to a file, feed it to an encoder, or pass it to a custom audio processing module.

1. Import the module.

   <!-- @[PlaybackCaptureImport](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/PlaybackCapture.ets) -->

   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Configure the audio capture parameters and create an AudioCapturer instance.

   When creating the AudioCapturer, configure the internal recording mode through `playbackCaptureMode` in [AudioCapturerOptions](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiocaptureroptions8). This field supports [AudioPlaybackCaptureMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioplaybackcapturemode) enumeration values and bitwise OR combinations. If `playbackCaptureMode` is not configured, the AudioCapturer is created as a regular audio capturer.

   The currently supported internal recording modes are as follows:

   | Internal Recording Mode | Recording Range |
   | -------- | -------- |
   | `MODE_DEFAULT` | Default mode, which records most audio streams, excluding tone streams and privacy streams. |
   | `MODE_MEDIA` | Media mode, which records media, voice message, and unknown-type audio streams. |
   | `MODE_EXCLUDING_SELF` | Exclude-self mode, which records audio streams other than those played by the app itself. |
   | `MODE_MEDIA \| MODE_EXCLUDING_SELF` | Records media audio while excluding the audio played by the app itself. |

   > **NOTE**
   >
   > A user authorization check is also performed when internal recording starts. On some devices, a system authorization or privacy prompt dialog is displayed, and the authorization result is returned through the `requestPlaybackCaptureStart()` callback.

   <!-- @[SetPlaybackCaptureMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/PlaybackCapture.ets) -->

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
     capturerInfo: audioCapturerInfo,
     playbackCaptureMode: audio.AudioPlaybackCaptureMode.MODE_MEDIA |
       audio.AudioPlaybackCaptureMode.MODE_EXCLUDING_SELF
   };

   let audioCapturer: audio.AudioCapturer | undefined =
     await audio.createAudioCapturer(audioCapturerOptions);
   ```

3. Call [on('readData')](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#onreaddata11) to subscribe to the audio data read callback.

   The callback returns PCM data. Based on your business requirements, you can write the data to a file, feed it to an encoder, or pass it to a custom audio processing module. The following example counts the number of PCM data bytes received.

   <!-- @[PlaybackCaptureGlobalState](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/PlaybackCapture.ets) -->

   ``` TypeScript
   let audioCapturer: audio.AudioCapturer | undefined = undefined;
   let isPlaybackCaptureStarted: boolean = false;
   let readBytes: number = 0;
   let playbackCaptureRequestId: number = 0;
   let playbackCaptureStartState: audio.PlaybackCaptureStartState | undefined = undefined;
   ```

   <!-- @[PlaybackCaptureReadDataCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/PlaybackCapture.ets) -->

   ``` TypeScript
     private readDataCallback: Callback<ArrayBuffer> = (buffer: ArrayBuffer): void => {
       readBytes += buffer.byteLength;
       this.bytes = readBytes;
     };

   audioCapturer.on('readData', this.readDataCallback);
   ```

   > **NOTE**
   >
   > Avoid performing time-consuming tasks in the `readData` callback. If encoding, network transmission, or complex algorithm processing is required, pass the PCM data to an independent task for processing to prevent frame loss, stuttering, or noise caused by data callback blocking.

4. Call [requestPlaybackCaptureStart()](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#requestplaybackcapturestart) to request the start of internal recording.

   This API is non-blocking. The system continues to process the user authorization check and the internal recording stream startup, and returns the final result through [PlaybackCaptureStartState](../../reference/apis-audio-kit/arkts-apis-audio-e.md#playbackcapturestartstate).

   In the example, `playbackCaptureRequestId` is incremented to identify each startup request. When the callback returns, both the capturer instance and the request ID are verified to prevent a callback from an old request from modifying the current internal recording state. While waiting for authorization, the app should continue processing other tasks to avoid synchronously blocking the current thread.

   > **NOTE**
   >
   > The internal recording capturer cannot be started through the `start()` API. After calling `requestPlaybackCaptureStart()`, the app should consider internal recording as started successfully only when `STATE_SUCCESS` is received.

   <!-- @[RequestPlaybackCaptureStart](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/PlaybackCapture.ets) -->

   ``` TypeScript
   if (audioCapturer === undefined) {
     return;
   }
   // Assign a unique ID to each asynchronous startup request to prevent a callback from an old request from modifying the current state.
   const requestId: number = ++playbackCaptureRequestId;
   const capturer: audio.AudioCapturer = audioCapturer;
   capturer.requestPlaybackCaptureStart((state: audio.PlaybackCaptureStartState): void => {
     if (audioCapturer !== capturer || playbackCaptureRequestId !== requestId) {
       return;
     }
     playbackCaptureStartState = state;
     const stateText: string = playbackCaptureStateToText(state);
     if (state === audio.PlaybackCaptureStartState.STATE_SUCCESS) {
       isPlaybackCaptureStarted = true;
       this.message = `Current state: ${stateText}`;
       return;
     }
     this.message = `Current state: ${stateText}`;
     this.releasePlaybackCapture().catch((error: BusinessError): void => {
       console.error(`Release playback capture failed, code is ${error.code}, message is ${error.message}`);
     });
   });
   ```

   For the start result, see [PlaybackCaptureStartState](../../reference/apis-audio-kit/arkts-apis-audio-e.md#playbackcapturestartstate). If the start result is not `STATE_SUCCESS`, the app should prompt the user based on the service and release the created AudioCapturer instance in time. After the app actively stops the internal recording stream, it should also ignore the asynchronous callbacks returned by old requests.

5. Call [stop](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#stop8) to stop capture, and call [release](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#release8) to release the AudioCapturer resources.

   After the app finishes internal recording, stop AudioCapturer and release the resources. Before releasing, cancel the `readData` listener to avoid processing callbacks after the object is released.

   <!-- @[ReleasePlaybackCapture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/PlaybackCapture.ets) -->

   ``` TypeScript
   private async releasePlaybackCapture(): Promise<void> {
     if (audioCapturer === undefined) {
       return;
     }
     const capturer: audio.AudioCapturer = audioCapturer;
     audioCapturer = undefined;
     playbackCaptureRequestId++;
     capturer.off('readData', this.readDataCallback);
     try {
       if (isPlaybackCaptureStarted) {
         await capturer.stop();
       }
     } finally {
       isPlaybackCaptureStarted = false;
       await capturer.release();
     }
   }
   ```

### OH_AudioCapturer (C API) Development Steps and Precautions

The following C/C++ examples are code snippets that demonstrate the complete lifecycle of creating, starting, stopping, and releasing an OH_AudioCapturer. For the basic recording process of OH_AudioCapturer, see [(Recommended) Using OHAudio for Audio Recording (C/C++)](using-ohaudio-for-recording.md).

1. Include the header file and define variables for saving the internal recording capturer and the start state.

   The internal recording start API is asynchronous. After the start function returns, continue to save the `OH_AudioCapturer` instance so that failure scenarios can be handled in the start result callback, and stop and release the instance when the service ends. A mutual exclusion lock is used to protect the global capturer pointer, preventing the start result callback, repeated starts, and active stops from accessing the pointer simultaneously.

   <!-- @[header_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

   ``` C++
   #include <ohaudio/native_audiocapturer.h>
   #include <ohaudio/native_audiostreambuilder.h>
   ```

   <!-- @[PlaybackCaptureConstants](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

   ``` C++
   constexpr int32_t PLAYBACK_CAPTURE_SAMPLE_RATE = 48000;
   constexpr int32_t PLAYBACK_CAPTURE_CHANNEL_COUNT = 2;
   constexpr uint32_t PLAYBACK_CAPTURE_MODE = AUDIOSTREAM_PLAYBACKCAPTURE_MODE_MEDIA |
       AUDIOSTREAM_PLAYBACKCAPTURE_MODE_EXCLUDING_SELF;
   ```

   <!-- @[PlaybackCaptureGlobalState](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

   ``` C++
   std::mutex g_playbackCaptureMutex;
   OH_AudioCapturer* g_playbackCaptureCapturer = nullptr;
   std::atomic<int32_t> g_playbackCaptureStartState{-1};
   std::atomic<uint64_t> g_playbackCaptureReadBytes{0};
   ```

2. Define the audio data callback and the internal recording start result callback.

   The audio data callback returns the internal recording PCM data. Do not perform time-consuming tasks in the callback. If internal recording fails to start or the user has not granted authorization, release the created capturer in time.

   <!-- @[PlaybackCaptureReadDataCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

   ``` C++
   void MyOnPlaybackCaptureReadData(
       OH_AudioCapturer* capturer,
       void* userData,
       void* audioData,
       int32_t audioDataSize)
   {
       if (audioData == nullptr || audioDataSize <= 0) {
           return;
       }
       g_playbackCaptureReadBytes.fetch_add(static_cast<uint64_t>(audioDataSize));
   }
   ```

   <!-- @[PlaybackCaptureStartCallback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

   ``` C++
   void MyOnPlaybackCaptureStart(
       OH_AudioCapturer* capturer,
       void* userData,
       OH_AudioStream_PlaybackCaptureStartState state)
   {
       int32_t stateValue = static_cast<int32_t>(state);
       g_playbackCaptureStartState.store(stateValue);
       OH_LOG_Print(LOG_APP, LOG_INFO, AUDIO_CAPTURE_LOG_DOMAIN, AUDIO_CAPTURE_LOG_TAG,
           "Playback capture start callback state=%{public}d", stateValue);

       if (state == AUDIOSTREAM_PLAYBACKCAPTURE_START_STATE_SUCCESS) {
           return;
       }

       OH_AudioCapturer* capturerToRelease = nullptr;
       {
           std::lock_guard<std::mutex> lock(g_playbackCaptureMutex);
           if (g_playbackCaptureCapturer == capturer) {
               capturerToRelease = g_playbackCaptureCapturer;
               g_playbackCaptureCapturer = nullptr;
           }
       }
       if (capturerToRelease != nullptr) {
           OH_AudioCapturer_Release(capturerToRelease);
       }
   }
   ```

3. Create an audio capturer and configure the internal recording mode.

   Configure the internal recording mode through [OH_AudioStreamBuilder_SetPlaybackCaptureMode()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setplaybackcapturemode). When internal recording starts, the system checks user authorization and returns the authorization result through the start result callback.

   The supported internal recording modes are as follows:

   | Internal Recording Mode | Recording Scope |
   | -------- | -------- |
   | `AUDIOSTREAM_PLAYBACKCAPTURE_MODE_DEFAULT` | Default mode, which records most audio streams, excluding tone streams and privacy streams. |
   | `AUDIOSTREAM_PLAYBACKCAPTURE_MODE_MEDIA` | Media mode, which records media, voice messages, and unknown streams. |
   | `AUDIOSTREAM_PLAYBACKCAPTURE_MODE_EXCLUDING_SELF` | Exclude self mode, which records audio streams other than the audio played by the app itself. |
   | `AUDIOSTREAM_PLAYBACKCAPTURE_MODE_MEDIA \| AUDIOSTREAM_PLAYBACKCAPTURE_MODE_EXCLUDING_SELF` | Records media audio while excluding the audio played by the app itself. |

   When the exclude-self mode is used alone, most audio streams that are allowed to be captured are recorded, excluding the audio played by the app itself. When it is combined with the media mode, only media audio is recorded, excluding the audio played by the app itself.

   <!-- @[SetPlaybackCaptureMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

   ``` C++
   bool ConfigurePlaybackCaptureBuilder(OH_AudioStreamBuilder* builder)
   {
       OH_AudioStreamBuilder_SetSamplingRate(builder, PLAYBACK_CAPTURE_SAMPLE_RATE);
       OH_AudioStreamBuilder_SetChannelCount(builder, PLAYBACK_CAPTURE_CHANNEL_COUNT);
       OH_AudioStreamBuilder_SetSampleFormat(builder, AUDIOSTREAM_SAMPLE_S16LE);
       OH_AudioStreamBuilder_SetEncodingType(builder, AUDIOSTREAM_ENCODING_TYPE_RAW);
       OH_AudioStreamBuilder_SetCapturerReadDataCallback(builder, MyOnPlaybackCaptureReadData, nullptr);

       OH_AudioStream_Result result =
           OH_AudioStreamBuilder_SetPlaybackCaptureMode(builder, PLAYBACK_CAPTURE_MODE);
       return result == AUDIOSTREAM_SUCCESS;
   }

   OH_AudioCapturer* CreatePlaybackCapture()
   {
       OH_AudioStreamBuilder* builder = nullptr;
       OH_AudioStream_Result result =
           OH_AudioStreamBuilder_Create(&builder, AUDIOSTREAM_TYPE_CAPTURER);
       if (result != AUDIOSTREAM_SUCCESS || builder == nullptr) {
           return nullptr;
       }
       if (!ConfigurePlaybackCaptureBuilder(builder)) {
           OH_AudioStreamBuilder_Destroy(builder);
           return nullptr;
       }

       OH_AudioCapturer* audioCapturer = nullptr;
       result = OH_AudioStreamBuilder_GenerateCapturer(builder, &audioCapturer);
       OH_AudioStreamBuilder_Destroy(builder);
       if (result != AUDIOSTREAM_SUCCESS || audioCapturer == nullptr) {
           return nullptr;
       }
       return audioCapturer;
   }

   bool StorePlaybackCapture(OH_AudioCapturer* audioCapturer)
   {
       std::lock_guard<std::mutex> lock(g_playbackCaptureMutex);
       if (g_playbackCaptureCapturer != nullptr) {
           return false;
       }
       g_playbackCaptureCapturer = audioCapturer;
       g_playbackCaptureStartState.store(-1);
       g_playbackCaptureReadBytes.store(0);
       return true;
   }

   <!-- @[RequestPlaybackCaptureStart](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->
   bool RequestPlaybackCaptureStart(OH_AudioCapturer* audioCapturer)
   {
       OH_AudioStream_Result result = OH_AudioCapturer_RequestPlaybackCaptureStart(
           audioCapturer, MyOnPlaybackCaptureStart, nullptr);
       if (result == AUDIOSTREAM_SUCCESS) {
           return true;
       }

       bool shouldRelease = false;
       {
           std::lock_guard<std::mutex> lock(g_playbackCaptureMutex);
           if (g_playbackCaptureCapturer == audioCapturer) {
               g_playbackCaptureCapturer = nullptr;
               shouldRelease = true;
           }
       }
       if (shouldRelease) {
           OH_AudioCapturer_Release(audioCapturer);
       }
       return false;
   }

   void StartPlaybackCapture()
   {
       {
           std::lock_guard<std::mutex> lock(g_playbackCaptureMutex);
           if (g_playbackCaptureCapturer != nullptr) {
               return;
           }
       }

       OH_AudioCapturer* audioCapturer = CreatePlaybackCapture();
       if (audioCapturer == nullptr) {
           return;
       }
       if (!StorePlaybackCapture(audioCapturer)) {
           OH_AudioCapturer_Release(audioCapturer);
           return;
       }
       RequestPlaybackCaptureStart(audioCapturer);
   }
   ```

   After `OH_AudioCapturer` is created, the builder is no longer used. Call `OH_AudioStreamBuilder_Destroy()` immediately to release the builder resources. If setting the internal recording mode fails, destroy the builder as well.

   > **NOTE**
   >
   > - `OH_AudioCapturer_RequestPlaybackCaptureStart()` returning `AUDIOSTREAM_SUCCESS` only indicates that the start request is submitted successfully. The internal recording start is successful only when the asynchronous callback returns `AUDIOSTREAM_PLAYBACKCAPTURE_START_STATE_SUCCESS`.
   > - If the user rejects the authorization or the system fails to display the authorization dialog box, the callback returns `AUDIOSTREAM_PLAYBACKCAPTURE_START_STATE_NOT_AUTHORIZED`.

4. Stop and release the internal recording capturer.

   After the service ends, call [OH_AudioCapturer_Stop()](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_stop) to stop capture, and call [OH_AudioCapturer_Release()](../../reference/apis-audio-kit/capi-native-audiocapturer-h.md#oh_audiocapturer_release) to release resources.

   <!-- @[StopPlaybackCapture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCapturerSampleC/entry/src/main/cpp/AudioCapture.cpp) -->

   ``` C++
   napi_value StopPlaybackCapture(napi_env env, napi_callback_info info)
   {
       OH_AudioCapturer* capturerToRelease = nullptr;
       {
           std::lock_guard<std::mutex> lock(g_playbackCaptureMutex);
           capturerToRelease = g_playbackCaptureCapturer;
           g_playbackCaptureCapturer = nullptr;
       }

       std::stringstream ss;
       if (capturerToRelease == nullptr) {
           ss << "No audio internal recording stream is currently running or awaiting authorization\n";
           ss << "Last state: " << PlaybackCaptureStateToText(g_playbackCaptureStartState.load());
           return CreateStringResult(env, ss.str());
       }

       OH_AudioStream_Result stopResult = OH_AudioCapturer_Stop(capturerToRelease);
       OH_AudioStream_Result releaseResult = OH_AudioCapturer_Release(capturerToRelease);
       ss << "Audio internal recording stopped\n";
       ss << "OH_AudioCapturer_Stop return value: " << stopResult << "\n";
       ss << "OH_AudioCapturer_Release return value: " << releaseResult << "\n";
       ss << "Bytes read this time: " << g_playbackCaptureReadBytes.load();
       g_playbackCaptureStartState.store(-1);
       g_playbackCaptureReadBytes.store(0);
       return CreateStringResult(env, ss.str());
   }
   ```

### Configuring the Internal Recording Policy for the Target Playback Stream

The playback end can control whether other apps are allowed to record by configuring the privacy attribute of its own audio stream. When the system establishes an internal recording capture link, it filters out playback streams marked as privacy-protected, so call content, account information, or other private content is not captured by internal recording. This configuration is a playback-end capability and does not require additional processing by the internal recording app.

- When developing with ArkTS APIs, the playback end can use `privacyType` in [AudioRendererOptions](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiorendereroptions8) to control whether the playback stream is allowed to be recorded by other apps.

- When developing with C APIs, the playback end can use [OH_AudioStreamBuilder_SetRendererPrivacy()](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setrendererprivacy) to control whether the playback stream is allowed to be recorded by other apps.