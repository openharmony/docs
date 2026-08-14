# Using AVScreenCapture to Capture Screens and Write Them to Files (C/C++)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--Designer: @stupig001-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=ce179c7049f440ce5b4d28b675776bb4597cc1b5 translatedAt=2026-08-11T01:53:45.436Z pushedAt=2026-08-12T01:27:33.465Z -->

Screen capture is mainly used to record the main screen.

You can call the C APIs of the [AVScreenCapture](media-kit-intro.md#avscreencapture) module to record the screen and collect audio and video source data from the device and microphone. You can call the screen capture module to obtain audio and video files, and then transfer them to other modules for playback or processing, enabling screen content sharing in the form of files.

The AVScreenCapture, Window, and Graphics modules together implement the entire video capture process.

Using AVScreenCapture for screen capture involves creating an AVScreenCapture instance, configuring audio and video capture parameters, starting and stopping capture, and releasing resources.

If you are in a call when screen capture starts or a call is coming during screen capture, screen capture automatically stops. Screen capture interrupted by a call reports the **OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL** status.

If a system user switching event occurs during screen capture, screen capture automatically stops. Screen capture interrupted by system user switching reports the **OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES** status.

This topic describes how to use AVScreenCapture for screen capture by walking through the process of recording screen data once. For details about the API reference, see [AVScreenCapture](../../reference/apis-media-kit/capi-avscreencapture.md).

If microphone audio data collection is configured, you must request the microphone permission **ohos.permission.MICROPHONE** and a continuous task. For the configuration method, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md) and [Continuous Task (ArkTS)](../../task-management/continuous-task.md).

Starting from API version 22, when you perform screen capture for an application on a PC/2-in-1 device, you can request the ohos.permission.TIMEOUT_SCREENOFF_DISABLE_LOCK permission to maintain capture even when the screen is off but not locked. For details about the configuration, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

Starting from API version 22, when capturing the screen of an app on a PC/2-in-1 device, you can request the **ohos.permission.CUSTOM_SCREEN_RECORDING** permission to suppress the privacy warning dialog during screen capture. For the configuration method, see [Restricted Permissions](../../security/AccessToken/restricted-permissions.md).

## How to Develop

After an AVScreenCapture instance is created, different APIs can be called to switch the AVScreenCapture to different states and trigger the required behavior.

If an API is called when the AVScreenCapture is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AVScreenCapture state before triggering state transition.

**Linking the Dynamic Libraries in the CMake Script**

``` C
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so libability_runtime.so libnative_display_manager.so)
```

1. Add the header files.

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

2. Create an AVScreenCapture instance, named **g_avCapture** in this example.

   <!-- @[screenCapture_create_for_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   g_avCapture = OH_AVScreenCapture_Create();
   ```

3. Set screen capture parameters.

   After creating the AVScreenCapture instance **g_avCapture**, you can set the parameters required for screen capture.

   By default, internal capture is used when captured files need to be stored. The microphone, which can be dynamically turned on or off, can be used for both internal and external capture simultaneously.

   A callback function must be set to listen for the capture status when captured files need to be stored.

   <!-- @[screenCapture_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->  

   ``` C++
   void SetConfig02(OH_AVScreenCaptureConfig &config, OH_RecorderInfo &recorderInfo)
   {
       // When recording the screen, obtain audio from the microphone or internal recording. Internal recording parameters are required. If both are set, the parameter settings for internal recording and microphone must be consistent.
       OH_AudioCaptureInfo micCapInfo = {.audioSampleRate = 48000, .audioChannels = 2, .audioSource = OH_MIC};

       OH_AudioCaptureInfo innerCapInfo = {.audioSampleRate = 48000, .audioChannels = 2, .audioSource = OH_ALL_PLAYBACK};
       // Screen recording audio output specification configuration. audioBitrate ensures that the output file bitrate matches the expected bitrate and is not strongly correlated with audioSampleRate.
       // To ensure audio quality, set the audio bitrate to 128000. If the screen recording content is primarily voice without music or game sound effects, you can lower it to 96000 or 48000.
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

4. Call **OH_AVScreenCapture_StartScreenRecording()** to start screen capture.

   <!-- @[screenCapture_startScreenRecording_for_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   result = OH_AVScreenCapture_StartScreenRecording(g_avCapture);
   ```

5. Call **OH_AVScreenCapture_StopScreenRecording()** to stop recording.

   <!-- @[screenCapture_stopScreenRecording](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   result = OH_AVScreenCapture_StopScreenRecording(g_avCapture);
   ```

6. Call **OH_AVScreenCapture_Release()** to destroy the instance and release resources.

   <!-- @[screenCapture_releaseScreenRecording_for_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   result = OH_AVScreenCapture_Release(g_avCapture);
   ```

## Complete Sample Code

Refer to the following sample code for the complete implementation of captured file storage using AVScreenCapture:

- [ScreenCaptureSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample)