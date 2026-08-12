# Using AVRecorder to Record Audio (C/C++)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=538fbff37ca84fc2c14a2fdf1f0a11dec4e60e5f translatedAt=2026-08-11T01:54:36.185Z pushedAt=2026-08-12T03:13:57.227Z -->

AVRecorder supports separate audio or video recording, integrating audio capture, audio encoding, video encoding, and audio-video muxing. It is suitable for scenarios where you need to implement simple audio/video recording and directly obtain a local media file.

In this topic, you will learn how to use the AVRecorder to complete the process of starting, pausing, resuming, and stopping audio recording.

During app development, you can actively obtain the current state through the state attribute of AVRecorder, or use the OH_AVRecorder_SetStateCallback method to register a callback for monitoring state changes. The state machine requirements must be strictly followed during development. For example, OH_AVRecorder_Pause() can only be called in the started state, and OH_AVRecorder_Resume() can only be called in the paused state.

**Figure 1** Recording state transition

![Recording state change](figures/audio-recording-status-change.png)

For details about the states, see [AVRecorderState](../../reference/apis-media-kit/arkts-apis-media-t.md#avrecorderstate9).

## Requesting Permissions

Before your development, configure the following permissions for your application.

- To use the microphone, request the ohos.permission.MICROPHONE permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

- To read and save audio files, preferentially use [AudioViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker).

> **NOTE**
>
> To clone, back up, or synchronize audio files in users' public directory, request the ohos.permission.READ_AUDIO and ohos.permission.WRITE_AUDIO permissions for reading and writing audio files. For details, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.

## How to Develop

> To record only audio, you do not need to set video-related parameters such as **videoFrameWidth** and **videoFrameHeight**. Similarly, to record only videos, you do not need to set audio-related parameters such as **audioBitrate** and **audioChannels**.

By including the [avrecorder.h](../../reference/apis-media-kit/capi-avrecorder-h.md), [avrecorder_base.h](../../reference/apis-media-kit/capi-avrecorder-base-h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/capi-native-averrors-h.md) header files, you can use the APIs related to audio recording.

Read [AVRecorder](../../reference/apis-media-kit/capi-avrecorder.md) for the API reference.

Link the dynamic library in the CMake script.

```c++
target_link_libraries(entry PUBLIC libavrecorder.so)
```

When using APIs related to [native_avformat.h](../../reference/apis-avcodec-kit/capi-native-avformat-h.md), include the following header file.

```c++
#include <multimedia/player_framework/native_avformat.h>
```

Link the following dynamic library in the CMake script.

```c++
target_link_libraries(entry PUBLIC libnative_media_core.so)
```

By including the [application_context.h](../../reference/apis-ability-kit/capi-application-context-h.md) header file, you can use the APIs related to the application framework service.

```c++
#include <AbilityKit/ability_runtime/application_context.h>
```

Link the following dynamic library in the CMake script.

```c++
target_link_libraries(entry PUBLIC libability_runtime.so)
```

To use system logging, include the following header file:

```c++
#include <hilog/log.h>
```

Link the following dynamic library in the CMake script.

```c++
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```

1. Create an AVRecorder instance. The AVRecorder is in the **idle** state.

   <!-- @[include_avrecorder_h](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   #include "multimedia/player_framework/avrecorder.h"
   #include "multimedia/player_framework/avrecorder_base.h"
   ```

   <!-- @[declare_avrecorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   static OH_AVRecorder *g_recorder = nullptr;
   ```

   <!-- @[create_avrecorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   g_recorder = OH_AVRecorder_Create();
   ```

2. Set the events to listen for.

   | Event Type| Description|
   | -------- | -------- |
   | OnStateChange | Listens for AVRecorder state changes.|
   | OnError | Listens for AVRecorder errors.|

   <!-- @[set_onstatechange_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVRecorder_SetStateCallback(g_recorder, OnStateChange, nullptr);
   ```

   <!-- @[set_onerror_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVRecorder_SetErrorCallback(g_recorder, OnError, nullptr);
   ```

   <!-- @[define_onstatechange_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   static void OnStateChange(OH_AVRecorder *recorder, OH_AVRecorder_State state,
       OH_AVRecorder_StateChangeReason reason, void *userData)
   {
       // ...
   
       (void)recorder;
       (void)userData;
   
       const char *reasonStr =
           (reason == OH_AVRecorder_StateChangeReason::AVRECORDER_USER) ? "USER" :
           (reason == OH_AVRecorder_StateChangeReason::AVRECORDER_BACKGROUND) ? "BACKGROUND" : "UNKNOWN";
   
       if (state == OH_AVRecorder_State::AVRECORDER_IDLE) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange IDLE, reason: %{public}s", reasonStr);
       }
   }
   ```

   <!-- @[define_onerror_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   static void OnError(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)
   {
       // ...
       
       (void)recorder;
       (void)userData;
       OH_LOG_ERROR(LOG_APP, "==NDKDemo== Recorder OnError errorCode: %{public}d, error message: %{public}s",
                    errorCode, errorMsg);
   }
   ```

3. Set audio recording parameters and call **OH_AVRecorder_Prepare()**. The AVRecorder enters the **prepared** state.

   > **NOTE**
   >
   > Note the following about configuration parameters:
   >
   > - Before configuring parameters, ensure that the required permissions have been requested. For details, see [Requesting Permissions](#requesting-permissions).
   >
   > - Set audio-related configuration parameters in the **OH_AVRecorder_Config** input parameter of the prepare API, as shown in the sample code.
   >
   > - The output URL (that is, the url field in the config in the sample code) is in the format of **fd://xx (fd number)**. You need to call basic file operation APIs to implement app file access. For details about how to obtain the URL, see [Accessing Application Files (C/C++)](../../file-management/native-fileio-guidelines.md).

   <!-- @[prepare_audio_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   static napi_value PrepareAudioRecorder(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "PrepareAudioRecorder called");
       
       OH_AVRecorder_Config config;
       memset(&config, 0, sizeof(config));
       config.audioSourceType = AVRECORDER_MIC;
       config.profile.audioBitrate = AUDIO_BITRATE; // 112000
       config.profile.audioChannels = AUDIO_CHANNELS; // 2
       config.profile.audioCodec = AVRECORDER_AUDIO_AAC;
       config.profile.audioSampleRate = AUDIO_SAMPLE_RATE; // 48000
       config.profile.fileFormat = AVRECORDER_CFT_MPEG_4A;
       config.fileGenerationMode = AVRECORDER_APP_CREATE;

       char fileDirPath[1000] = {0};
       int32_t bufferSize = 1000;
       int32_t writeLength = 0;
       AbilityRuntime_ErrorCode errCode =
           OH_AbilityRuntime_ApplicationContextGetFilesDir(fileDirPath, bufferSize, &writeLength);
       if (errCode != AbilityRuntime_ErrorCode::ABILITY_RUNTIME_ERROR_CODE_NO_ERROR || writeLength <= 0) {
           OH_LOG_ERROR(LOG_APP, "==NDKDemo== GetFilesDir failed, errCode: %{public}d", errCode);
           napi_value res;
           napi_create_int32(env, -1, &res);
           return res;
       }
       const std::string avrecorderRoot = fileDirPath;
       g_outputFd = open((avrecorderRoot + "/audio_example.m4a").c_str(), O_RDWR | O_CREAT, FILE_PERMISSIONS);
       std::string fileUrl = "fd://" + std::to_string(g_outputFd);
       config.url = strdup(fileUrl.c_str());
       OH_LOG_INFO(LOG_APP, "config.url is: %s", config.url);

       OH_AVErrCode err = OH_AVRecorder_Prepare(g_recorder, &config);
       free(config.url);
       if (err != AV_ERR_OK) {
           OH_LOG_ERROR(LOG_APP, "Failed to prepare audio recorder, error: %{public}d", err);
       }
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }
   ```

4. Call **OH_AVRecorder_Start()** to start recording. The AVRecorder enters the **started** state.

   <!-- @[start_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Start(g_recorder);
   ```

5. Call **OH_AVRecorder_Pause()** to pause recording. The AVRecorder enters the **paused** state. In addition, pause data input.

   <!-- @[pause_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Pause(g_recorder);
   ```

6. Call **OH_AVRecorder_Resume()** to resume recording. The AVRecorder enters the **started** state again.

   <!-- @[resume_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Resume(g_recorder);
   ```

7. Call **OH_AVRecorder_Stop()** to stop recording. The AVRecorder enters the **stopped** state.

   <!-- @[stop_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Stop(g_recorder);
   ```

8. Reset the recording state. Call **OH_AVRecorder_Reset()** to re-enter the idle state, which allows you to reconfigure recording parameters.

   <!-- @[reset_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Reset(g_recorder);
   ```

9. Release recording resources. Call **OH_AVRecorder_Release()** to enter the released state and exit recording.

   <!-- @[release_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVRecorder_Release(g_recorder);
   ```

## Complete Sample Code

Refer to the following sample code, which demonstrates the complete process of creating an AVRecorder instance, preparing for recording, starting recording, pausing recording, resuming recording, stopping recording, resetting the recording state, and releasing recording resources.

   <!-- @[full_audio_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   #include <cstdio>
   #include <cstring>
   #include <string>
   #include <cinttypes>
   #include <fcntl.h>
   #include <unistd.h>
   
   #include "napi/native_api.h"
   #include "multimedia/player_framework/avrecorder.h"
   #include "multimedia/player_framework/avrecorder_base.h"
   #include "multimedia/player_framework/native_avformat.h"
   #include "multimedia/media_library/media_asset_change_request_capi.h"
   #include "multimedia/media_library/media_access_helper_capi.h"
   #include "multimedia/media_library/media_asset_capi.h"
   #include "native_window/external_window.h"
   #include "hilog/log.h"
   #include <AbilityKit/ability_runtime/application_context.h>
   
   static constexpr int32_t AUDIO_BITRATE = 112000;
   static constexpr int32_t AUDIO_CHANNELS = 2;
   static constexpr int32_t AUDIO_SAMPLE_RATE = 48000;
   // ...
   static constexpr int32_t CALLBACK_ARG_COUNT = 2;
   static constexpr int32_t FILE_PERMISSIONS = 0644;
   
   static OH_AVRecorder *g_recorder = nullptr;
   static int32_t g_outputFd = -1;
   
   // ...

   static void OnStateChange(OH_AVRecorder *recorder, OH_AVRecorder_State state,
       OH_AVRecorder_StateChangeReason reason, void *userData)
   {
       // ...

       (void)recorder;
       (void)userData;

       const char *reasonStr =
           (reason == OH_AVRecorder_StateChangeReason::AVRECORDER_USER) ? "USER" :
           (reason == OH_AVRecorder_StateChangeReason::AVRECORDER_BACKGROUND) ? "BACKGROUND" : "UNKNOWN";

       if (state == OH_AVRecorder_State::AVRECORDER_IDLE) {
           OH_LOG_INFO(LOG_APP, "==NDKDemo== Recorder OnStateChange IDLE, reason: %{public}s", reasonStr);
       }
   }

   static void OnError(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)
   {
       // ...
       
       (void)recorder;
       (void)userData;
       OH_LOG_ERROR(LOG_APP, "==NDKDemo== Recorder OnError errorCode: %{public}d, error message: %{public}s",
                    errorCode, errorMsg);
   }
   
   // ...

   static napi_value CreateRecorder(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "CreateRecorder called");
       if (g_recorder != nullptr) {
           OH_AVRecorder_Release(g_recorder);
           g_recorder = nullptr;
       }
       g_recorder = OH_AVRecorder_Create();
       if (g_recorder == nullptr) {
           OH_LOG_ERROR(LOG_APP, "Failed to create recorder");
           napi_value result;
           napi_create_int32(env, -1, &result);
           return result;
       }
       OH_LOG_INFO(LOG_APP, "CreateRecorder succeeded");
       napi_value result;
       napi_create_int32(env, 0, &result);
       return result;
   }

   static napi_value SetRecorderStateCallback(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "SetRecorderStateCallback called");
       // ...

       OH_AVRecorder_SetStateCallback(g_recorder, OnStateChange, nullptr);

       napi_value result;
       napi_create_int32(env, 0, &result);
       return result;
   }

   static napi_value SetRecorderErrorCallback(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "SetRecorderErrorCallback called");
       // ...

       OH_AVRecorder_SetErrorCallback(g_recorder, OnError, nullptr);

       napi_value result;
       napi_create_int32(env, 0, &result);
       return result;
   }

   // ...

   static napi_value PrepareAudioRecorder(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "PrepareAudioRecorder called");

       OH_AVRecorder_Config config;
       memset(&config, 0, sizeof(config));
       config.audioSourceType = AVRECORDER_MIC;
       config.profile.audioBitrate = AUDIO_BITRATE; // 112000
       config.profile.audioChannels = AUDIO_CHANNELS; // 2
       config.profile.audioCodec = AVRECORDER_AUDIO_AAC;
       config.profile.audioSampleRate = AUDIO_SAMPLE_RATE; // 48000
       config.profile.fileFormat = AVRECORDER_CFT_MPEG_4A;
       config.fileGenerationMode = AVRECORDER_APP_CREATE;

       char fileDirPath[1000] = {0};
       int32_t bufferSize = 1000;
       int32_t writeLength = 0;
       AbilityRuntime_ErrorCode errCode =
           OH_AbilityRuntime_ApplicationContextGetFilesDir(fileDirPath, bufferSize, &writeLength);
       if (errCode != AbilityRuntime_ErrorCode::ABILITY_RUNTIME_ERROR_CODE_NO_ERROR || writeLength <= 0) {
           OH_LOG_ERROR(LOG_APP, "==NDKDemo== GetFilesDir failed, errCode: %{public}d", errCode);
           napi_value res;
           napi_create_int32(env, -1, &res);
           return res;
       }
       const std::string avrecorderRoot = fileDirPath;
       g_outputFd = open((avrecorderRoot + "/audio_example.m4a").c_str(), O_RDWR | O_CREAT, FILE_PERMISSIONS);
       std::string fileUrl = "fd://" + std::to_string(g_outputFd);
       config.url = strdup(fileUrl.c_str());
       OH_LOG_INFO(LOG_APP, "config.url is: %s", config.url);

       OH_AVErrCode err = OH_AVRecorder_Prepare(g_recorder, &config);
       free(config.url);
       if (err != AV_ERR_OK) {
           OH_LOG_ERROR(LOG_APP, "Failed to prepare audio recorder, error: %{public}d", err);
       }
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }
   
   // ...

   static napi_value StartRecorder(napi_env env, napi_callback_info info)
   {
       OH_AVErrCode err = OH_AVRecorder_Start(g_recorder);
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }

   static napi_value PauseRecorder(napi_env env, napi_callback_info info)
   {
       OH_AVErrCode err = OH_AVRecorder_Pause(g_recorder);
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }

   static napi_value ResumeRecorder(napi_env env, napi_callback_info info)
   {
       OH_AVErrCode err = OH_AVRecorder_Resume(g_recorder);
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }

   static napi_value StopRecorder(napi_env env, napi_callback_info info)
   {
       OH_AVErrCode err = OH_AVRecorder_Stop(g_recorder);
       if (g_outputFd > 0) {
           close(g_outputFd);
           g_outputFd = -1;
       }
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }
   
   static napi_value ResetRecorder(napi_env env, napi_callback_info info)
   {
       OH_AVErrCode err = OH_AVRecorder_Reset(g_recorder);
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }

   static napi_value ReleaseRecorder(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "ReleaseRecorder called");
       // ...
       if (g_recorder != nullptr) {
           OH_AVRecorder_Release(g_recorder);
           g_recorder = nullptr;
       }
       if (g_outputFd > 0) {
           close(g_outputFd);
           g_outputFd = -1;
       }
       OH_LOG_INFO(LOG_APP, "ReleaseRecorder succeeded");
       napi_value result;
       napi_create_int32(env, 0, &result);
       return result;
   }
   ```