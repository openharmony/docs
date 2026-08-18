# 使用AVScreenCapture录屏写文件(C/C++)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

录屏主要为主屏幕录屏功能。

开发者可以调用[AVScreenCapture](media-kit-intro.md#avscreencapture)模块的C API接口，完成录屏，采集设备内、麦克风等的音视频源数据。可以调用录屏模块获取音视频文件，然后通过文件的形式流转到其他模块进行播放或处理，达成文件形式分享屏幕内容的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块协同完成整个视频采集的流程。

使用AVScreenCapture录屏涉及到AVScreenCapture实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。

开始录屏时正在通话中或者录屏过程中来电，录屏将自动停止。因通话中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL状态。

录屏过程中发生系统用户切换事件时，录屏将自动停止。因系统用户切换中断的录屏会上报OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES状态。

本开发指导将以完成一次屏幕数据录制的过程为例，向开发者讲解如何使用AVScreenCapture进行录屏，详细的API声明请参考[AVScreenCapture API参考](../../reference/apis-media-kit/capi-avscreencapture.md)。

如果配置了采集麦克风音频数据，需申请对应麦克风权限ohos.permission.MICROPHONE和长时任务。配置方式请参考[向用户申请权限](../../security/AccessToken/request-user-authorization.md)、[申请长时任务](../../task-management/continuous-task.md)。

从API version 22开始，在PC/2in1设备上对应用进行录屏时，可通过申请权限**ohos.permission.TIMEOUT_SCREENOFF_DISABLE_LOCK**，实现在屏幕熄灭但不锁屏的场景下，继续保持录制的效果，配置方式请参见[声明权限](../../security/AccessToken/declare-permissions.md)。

从API version 22开始，在PC/2in1设备上对应用进行录屏时，可通过申请权限**ohos.permission.CUSTOM_SCREEN_RECORDING**，实现在录屏时不再弹出隐私告警弹窗。配置方式请参见[受限开放权限](../../security/AccessToken/restricted-permissions.md)。
## 开发步骤及注意事项

使用AVScreenCapture时要明确其状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。

在确定的状态下执行不合适的方法会导致AVScreenCapture发生错误，开发者需要在调用状态转换的方法前进行状态检查，避免程序运行异常。

**在 CMake 脚本中链接动态库**

``` C
target_link_libraries(entry PUBLIC libnative_avscreen_capture.so libability_runtime.so libnative_display_manager.so)
```

1. 添加头文件。

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

2. 创建AVScreenCapture实例g_avCapture。

   <!-- @[screenCapture_create_for_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   g_avCapture = OH_AVScreenCapture_Create();
   ```

3. 配置录屏参数。

   创建AVScreenCapture实例g_avCapture后，可以设置录屏所需要的参数。

   其中，录屏存文件时默认录制内录，麦克风可以动态开关，可以同时内外录制。

   同时，录屏存文件需要设置状态回调，感知录制状态。

   <!-- @[screenCapture_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->  
   
   ``` C++
   void SetConfig02(OH_AVScreenCaptureConfig &config, OH_RecorderInfo &recorderInfo)
   {
       // 录屏时获取麦克风或者内录，内录参数必填，如果都设置了，内录和麦克风的参数设置需要一致。
       OH_AudioCaptureInfo micCapInfo = {.audioSampleRate = 48000, .audioChannels = 2, .audioSource = OH_MIC};

       OH_AudioCaptureInfo innerCapInfo = {.audioSampleRate = 48000, .audioChannels = 2, .audioSource = OH_ALL_PLAYBACK};
       // 录屏音频输出规格配置。audioBitrate保证输出文件的比特率为设置的预期比特率，和audioSampleRate无强关联。
       // 为保证音频质量，此处音频比特率取值128000。如果录屏内容以语音为主，不包含音乐、游戏音效等，可以降低为96000或48000。
       OH_AudioEncInfo audioEncInfo = {
           .audioBitrate = 128000,
           .audioCodecformat = OH_AAC_LC
       };

       // 获取屏幕信息。
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
           .dataType = OH_CAPTURE_FILE, // 录屏数据类型，文件。
           .audioInfo = audioInfo,
           .videoInfo = videoInfo,
           .recorderInfo = recorderInfo // 录制文件信息。
       };
       // 设置状态回调函数、错误回调函数和录屏屏幕ID回调函数等。
       SetCallbackFile(g_avCapture);
   }
   ```

4. 调用OH_AVScreenCapture_StartScreenRecording()方法开始进行录屏。

   <!-- @[screenCapture_startScreenRecording_for_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   result = OH_AVScreenCapture_StartScreenRecording(g_avCapture);
   ```

5. 调用OH_AVScreenCapture_StopScreenRecording()方法停止录制。

   <!-- @[screenCapture_stopScreenRecording](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   result = OH_AVScreenCapture_StopScreenRecording(g_avCapture);
   ```

6. 调用OH_AVScreenCapture_Release()方法销毁实例，释放资源。

   <!-- @[screenCapture_releaseScreenRecording_for_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   result = OH_AVScreenCapture_Release(g_avCapture);
   ```

## 完整示例

针对使用AVScreenCapture录屏存文件的完整示例代码可参考：

- [ScreenCaptureSample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample)