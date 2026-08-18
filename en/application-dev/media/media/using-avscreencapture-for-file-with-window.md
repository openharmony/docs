# Using AVScreenCapture to Capture Window-Level Screen (C/C++)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yxc2-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=ce179c7049f440ce5b4d28b675776bb4597cc1b5 translatedAt=2026-08-11T01:53:22.214Z pushedAt=2026-08-11T13:08:15.823Z -->

Starting from API version 10, you can use the C APIs provided by the `AVScreenCapture` module to implement window-level/screen capture and collect audio and video source data from microphones and devices.

This guide uses specified-window capture as an example to describe how to use the `AVScreenCapture` C APIs to implement precise window capture. This solution focuses on capturing the content of a specific window, avoiding full-screen interference, and is suitable for scenarios such as teaching demonstrations, online courses, meeting recordings, and specific content capture.

- Method 1 (recommended): Use the screen capture Picker dialog to select the window to be recorded. Use [OH_AVScreenCapture_StrategyForPickerPopUp](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_strategyforpickerpopup) to configure whether to display the screen capture Picker. Starting from API version 20, the screen capture Picker can be displayed on PCs/2-in-1 devices. Starting from API version 23, the screen capture Picker can be displayed on phones/tablets.

- Method 2: To capture a specified window, set the window ID. In this scenario, a content sharing selection dialog box is displayed after screen capture starts. For detailed API declarations, see the `OH_CAPTURE_SPECIFIED_WINDOW` mode in [OH_CaptureMode](../../reference/apis-media-kit/capi-native-avscreen-capture-base-h.md#oh_capturemode).

## Required Permissions

Before developing this feature, you must apply for the required permissions based on your actual needs:

- If microphone audio capture is configured, you need to [request user authorization](../../security/AccessToken/request-user-authorization.md) for the **ohos.permission.MICROPHONE** permission and apply for a [continuous task (ArkTS)](../../task-management/continuous-task.md).

- Starting from API version 22, when capturing the screen of an app on a PC/2-in-1 device, you can apply for the **ohos.permission.TIMEOUT_SCREENOFF_DISABLE_LOCK** permission to keep screen capture running when the screen turns off but remains unlocked. For configuration details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

- Starting from API version 22, when capturing the screen of an app on a PC/2-in-1 device, you can apply for the **ohos.permission.CUSTOM_SCREEN_RECORDING** permission to suppress the privacy warning dialog during screen capture. For configuration details, see [Restricted Permissions](../../security/AccessToken/restricted-permissions.md).

## How to Develop

**Linking Dynamic Libraries in the CMake Script**

``` C
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so libability_runtime.so libnative_display_manager.so)
```

1. Add header files.

   <!-- @[screenCapture_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/main.h) -->

   ``` C
   #include "hilog/log.h"
   #include "napi/native_api.h"
   #include <window_manager/oh_display_info.h>
   #include <window_manager/oh_display_manager.h>
   #include <AbilityKit/ability_runtime/application_context.h>
   #include <multimedia/player_framework/native_avscreen_capture.h>
   #include <multimedia/player_framework/native_avscreen_capture_base.h>
   #include <multimedia/player_framework/native_avscreen_capture_errors.h>
   #include <unistd.h>
   #include <fcntl.h>
   #include <string>
   ```

2. Call [OH_AVScreenCapture_Create](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_create) to create an `AVScreenCapture` instance `g_avCapture`.

   <!-- @[screenCapture_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   g_avCapture = OH_AVScreenCapture_Create();
   ```

3. Call [OH_AVScreenCapture_Init](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_init) to configure screen capture parameters.

After creating the `AVScreenCapture` instance `capture`, you can set the parameters required for screen capture.

   <!-- @[screenCapture_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) --> 

   ``` C++
   void SetConfig02(OH_AVScreenCaptureConfig &config, OH_RecorderInfo &recorderInfo)
   {
       // When recording, obtain microphone or internal recording. Internal recording parameters are mandatory. If both are set, the internal recording and microphone parameter settings must be consistent.
       OH_AudioCaptureInfo micCapInfo = {.audioSampleRate = 48000, .audioChannels = 2, .audioSource = OH_MIC};

       OH_AudioCaptureInfo innerCapInfo = {.audioSampleRate = 48000, .audioChannels = 2, .audioSource = OH_ALL_PLAYBACK};
       // Audio output specification configuration for screen capture. audioBitrate ensures the output file bitrate matches the expected bitrate and has no strong correlation with audioSampleRate.
       // To ensure audio quality, set the audio bitrate to 128000 here. If the recording content is primarily voice without music, game sound effects, etc., you can lower it to 96000 or 48000.
       OH_AudioEncInfo audioEncInfo = {
           .audioBitrate = 128000,
           .audioCodecformat = OH_AAC_LC
       };

       // Obtain screen information.
       uint64_t displayId = 0;
       NativeDisplayManager_ErrorCode ret = OH_NativeDisplayManager_GetDefaultDisplayId(&displayId);

       NativeDisplayManager_DisplayInfo* displayInfo = nullptr;
       ret = OH_NativeDisplayManager_CreateDisplayById(displayId, &displayInfo);
       if (ret != DISPLAY_MANAGER_OK || !displayInfo) {
           return;
       }
       int32_t screenWidth = displayInfo->width;
       int32_t screenHeight = displayInfo->height;
       OH_NativeDisplayManager_DestroyDisplay(displayInfo);
       displayInfo = nullptr;
       OH_VideoCaptureInfo videoCapInfo = {
           .videoFrameWidth = screenWidth,
           .videoFrameHeight = screenHeight,
           .videoSource = OH_VIDEO_SOURCE_SURFACE_RGBA
       };

       OH_VideoEncInfo videoEncInfo = {
           .videoCodec = OH_H264,
           .videoBitrate = 2000000,
           .videoFrameRate = 30
       };

       OH_AudioInfo audioInfo = {
           .micCapInfo = micCapInfo,
           .innerCapInfo = innerCapInfo,
           .audioEncInfo = audioEncInfo
       };

       OH_VideoInfo videoInfo = {
           .videoCapInfo = videoCapInfo,
           .videoEncInfo = videoEncInfo
       };

       config = {
           .captureMode = OH_CAPTURE_HOME_SCREEN,
           .dataType = OH_CAPTURE_FILE, // Screen recording data type: file.
           .audioInfo = audioInfo,
           .videoInfo = videoInfo,
           .recorderInfo = recorderInfo // Recording file information.
       };
       // Set the status callback, error callback, and screen recording screen ID callback.
       SetCallbackFile(g_avCapture);
   }
   ```

   Method 1 (recommended): Use the screen capture Picker dialog to select an opened app window for window-level screen recording.

   <!-- @[screenCapture_createCaptureStrategy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) --> 

   ``` C++
   // Open the screen capture picker list and select an open application window for window-level screen recording.
   OH_AVScreenCapture_CaptureStrategy *strategy = OH_AVScreenCapture_CreateCaptureStrategy();
   OH_AVScreenCapture_StrategyForPickerPopUp(strategy, true);
   OH_AVScreenCapture_SetCaptureStrategy(g_avCapture, strategy);
   OH_AVScreenCapture_ReleaseCaptureStrategy(strategy);
   ```

   Method 2: Pass the ID of the window to be captured for screen capture.

   <!-- @[screenCapture_withWindow_forID](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) --> 

   ``` C++
   // To record a single window, pass a single window ID. To record multiple windows simultaneously, pass a list of window IDs.
   g_missionIds = {g_windowId}; // Specify the window ID for recording.
   config.videoInfo.videoCapInfo.missionIDs = g_missionIds.data();
   config.videoInfo.videoCapInfo.missionIDsLen = static_cast<int32_t>(g_missionIds.size());
   config.captureMode = OH_CAPTURE_SPECIFIED_WINDOW; // Set the screen capture mode to recording a specified window.
   
   // Set to false, which means no system Picker is displayed after recording starts, and a privacy prompt dialog appears instead.
   OH_AVScreenCapture_CaptureStrategy* strategy = OH_AVScreenCapture_CreateCaptureStrategy();
   OH_AVScreenCapture_StrategyForPickerPopUp(strategy, false);
   OH_AVScreenCapture_SetCaptureStrategy(g_avCapture, strategy);
   OH_AVScreenCapture_ReleaseCaptureStrategy(strategy);
   ```

4. Call [OH_AVScreenCapture_StartScreenRecording](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_startscreenrecording) to start window-level screen capture.

   <!-- @[screenCapture_startScreenRecording](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   result = OH_AVScreenCapture_StartScreenRecording(g_avCapture);
   ```

5. Call [OH_AVScreenCapture_StopScreenRecording](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_stopscreenrecording) to stop screen capture.

   <!-- @[screenCapture_stopScreenRecording](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   result = OH_AVScreenCapture_StopScreenRecording(g_avCapture);
   ```

6. Call [OH_AVScreenCapture_Release](../../reference/apis-media-kit/capi-native-avscreen-capture-h.md#oh_avscreencapture_release) to destroy the instance and release resources.

   <!-- @[screenCapture_releaseScreenRecording](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   OH_AVScreenCapture_Release(g_avCapture);
   g_avCapture = nullptr;
   ```