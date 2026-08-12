# Using AVRecorder to Record Videos (C/C++)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=538fbff37ca84fc2c14a2fdf1f0a11dec4e60e5f translatedAt=2026-08-11T01:55:14.979Z pushedAt=2026-08-12T03:22:50.706Z -->

AVRecorder supports audio and video recording, integrating audio capture, audio encoding, video encoding, and media muxing capabilities. It is suitable for scenarios where you need to implement simple video recording and directly obtain local media files.

In this topic, you will learn how to use the AVRecorder to complete the process of starting, pausing, resuming, and stopping video recording.

During app development, you can actively obtain the current status through the state property of AVRecorder, or use the OH_AVRecorder_SetStateCallback method to register a callback for monitoring status changes. The state machine requirements must be strictly followed during development. For example, OH_AVRecorder_Pause() can only be called in the started state, and OH_AVRecorder_Resume() can only be called in the paused state.

**Figure 1** Recording state transition

![Recording state change](figures/recording-status-change-ndk.png)

For detailed status descriptions, refer to [OH_AVRecorder_State](../../reference/apis-media-kit/capi-avrecorder-base-h.md#oh_avrecorder_state).

## Requesting Permissions

Before your development, configure the following permissions for your application.

- To use the microphone, request the ohos.permission.MICROPHONE permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

- To use the camera for photo capture, request the ohos.permission.CAMERA permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

- To read images or videos from Gallery, preferentially use the media library [Picker for access](../medialibrary/photoAccessHelper-photoviewpicker.md).

- To save images or videos to Gallery, preferentially use the [security component for storage](../medialibrary/photoAccessHelper-savebutton.md).

> **NOTE**
>
> Only when an app needs to clone, back up, or synchronize image and video files from the user's public directory can it request the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions to read and write image and video files. For the request method, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.

## How to Develop

> **NOTE**
>
> AVRecorder is only responsible for video data processing and must work with a video data capture module to complete video recording. The video data capture module needs to pass video data to AVRecorder through a Surface for data processing. The commonly used video data capture module is the camera module. For details, see [Camera - Video Recording](../camera/native-camera-recording.md).
>
> For file creation and storage, see [App File Access and Management](../../file-management/app-file-access.md). By default, files are stored in the app sandbox path. To store files in Gallery, use the [security component for saving media resources](../medialibrary/photoAccessHelper-savebutton.md) to save files from the sandbox.

You can use C/C++ APIs related to video recording by including the header files [avrecorder.h](../../reference/apis-media-kit/capi-avrecorder-h.md), [avrecorder_base.h](../../reference/apis-media-kit/capi-avrecorder-base-h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/capi-native-averrors-h.md).

Read [AVRecorder](../../reference/apis-media-kit/capi-avrecorder.md) for the API reference.

Link the dynamic library in the CMake script.

```C++
target_link_libraries(entry PUBLIC libavrecorder.so)
```

When using APIs related to [native_avformat.h](../../reference/apis-avcodec-kit/capi-native-avformat-h.md), include the following header file.

```C++
#include <multimedia/player_framework/native_avformat.h>
```

In addition, link the following dynamic library in the CMake script:

```C++
target_link_libraries(entry PUBLIC libnative_media_core.so)
```

Include the [application_context.h](../../reference/apis-ability-kit/capi-application-context-h.md) header file to use the application framework service APIs.

```c++
#include <AbilityKit/ability_runtime/application_context.h>
```

Link the following dynamic library in the CMake script.

```c++
target_link_libraries(entry PUBLIC libability_runtime.so)
```

To use system logging, include the following header file:

```C++
#include <hilog/log.h>
```

In addition, link the following dynamic library in the CMake script:

```C++
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
   | OnUri | Listens for media files generated by the AVRecorder.|

   <!-- @[set_onstatechange_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVRecorder_SetStateCallback(g_recorder, OnStateChange, nullptr);
   ```

   <!-- @[set_onerror_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVRecorder_SetErrorCallback(g_recorder, OnError, nullptr);
   ```

   <!-- @[set_onuri_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVRecorder_SetUriCallback(g_recorder, OnUri, nullptr);
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

   <!-- @[define_onuri_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   void OnUri(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
   {
       (void)recorder;
       (void)userData;
       OH_LOG_INFO(LOG_APP, "==NDKDemo== OnUri in!");
       if (asset != nullptr) {
           auto changeRequest = OH_MediaAssetChangeRequest_Create(asset);
           if (changeRequest == nullptr) {
               OH_LOG_ERROR(LOG_APP, "==NDKDemo== changeRequest is null!");
               OH_MediaAsset_Release(asset);
               return;
           }
           MediaLibrary_ImageFileType imageFileType = MEDIA_LIBRARY_FILE_VIDEO;
           int32_t result = OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest, imageFileType);
           OH_LOG_INFO(LOG_APP, "result of OH_MediaAssetChangeRequest_SaveCameraPhoto: %d", result);
   
           int32_t resultChange = OH_MediaAccessHelper_ApplyChanges(changeRequest);
           OH_LOG_INFO(LOG_APP, "result of OH_MediaAccessHelper_ApplyChanges: %d", resultChange);
   
           OH_MediaAsset_Release(asset);
           OH_MediaAssetChangeRequest_Release(changeRequest);
       } else {
           OH_LOG_ERROR(LOG_APP, "Received null media asset!");
       }
       OH_LOG_INFO(LOG_APP, "==NDKDemo== OnUri out!");
   }
   ```

3. Set video recording parameters and call **OH_AVRecorder_Prepare()**. The AVRecorder enters the **prepared** state.

   > **NOTE**
   >
   > Note the following points when configuring parameters:
   >
   > - Before configuring parameters, ensure that the corresponding permissions have been requested. See [Requesting Permissions](#requesting-permissions).
   >
   > - The audio and video configuration parameters set in the OH_AVRecorder_Config input parameter of the prepare API are as shown in the sample code.
   >
   > - Use the supported [recording specifications](media-kit-intro.md#supported-formats). The video bit rate, resolution, and frame rate are subject to the range supported by the actual hardware device.
   >
   > - The URL for recording output (that is, the url in config in the sample code) is in the format of fd://xx (fd number). You need to call basic file operation APIs to implement app file access. For the method of obtaining the URL, see [Accessing Application Files (C/C++)](../../file-management/native-fileio-guidelines.md).

   <!-- @[prepare_video_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   static napi_value PrepareVideoRecorder(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "PrepareVideoRecorder called");

       OH_AVRecorder_Config config;
       memset(&config, 0, sizeof(config));

       config.videoSourceType = AVRECORDER_SURFACE_YUV;
       config.profile.videoBitrate = VIDEO_BITRATE; // 3000000
       config.profile.videoCodec = AVRECORDER_VIDEO_AVC;
       config.profile.videoFrameWidth = VIDEO_FRAME_WIDTH; // 1920
       config.profile.videoFrameHeight = VIDEO_FRAME_HEIGHT; // 1080
       config.profile.videoFrameRate = VIDEO_FRAME_RATE; // 30
       config.profile.isHdr = false;
       config.profile.enableTemporalScale = false;
       config.profile.fileFormat = AVRECORDER_CFT_MPEG_4;
       config.fileGenerationMode = AVRECORDER_APP_CREATE;
       config.metadata.videoOrientation = strdup("90");

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
       g_outputFd = open((avrecorderRoot + "/video_example.mp4").c_str(), O_RDWR | O_CREAT, FILE_PERMISSIONS);
       std::string fileUrl = "fd://" + std::to_string(g_outputFd);
       config.url = strdup(fileUrl.c_str());
       OH_LOG_INFO(LOG_APP, "config.url is: %s", config.url);

       OH_AVErrCode err = OH_AVRecorder_Prepare(g_recorder, &config);
       free(config.url);
       free(config.metadata.videoOrientation);
       if (err != AV_ERR_OK) {
           OH_LOG_ERROR(LOG_APP, "Failed to prepare video recorder, error: %{public}d", err);
       }
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }
   ```

4. Obtain the surface ID required for video recording.

   Call the **OH_AVRecorder_GetInputSurface()** API to obtain **OHNativeWindow**, and then call the **OH_NativeWindow_GetSurfaceId()** API to obtain the surface ID. The surface ID is used to pass to the video data input source module. The commonly used video data input source module is the camera. The following sample code only shows the steps for obtaining the surface ID.

   The video data collection module obtains the surface based on the surface ID and transmits video data to the AVRecorder through the surface. Then the AVRecorder processes the video data.

   <!-- @[get_input_surface_id](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   static std::string GetSurfaceIdString()
   {
       OHNativeWindow *window = nullptr;
       OH_AVErrCode err = OH_AVRecorder_GetInputSurface(g_recorder, &window);
       if (err != AV_ERR_OK || window == nullptr) {
           OH_LOG_ERROR(LOG_APP, "Failed to get input surface, error: %{public}d", err);
           return "";
       }
       uint64_t surfaceId = 0;
       int32_t nErr = OH_NativeWindow_GetSurfaceId(window, &surfaceId);
       if (nErr != 0) {
           OH_LOG_ERROR(LOG_APP, "Failed to get surface ID from native window, error: %{public}d", nErr);
           return "";
       }
       std::string surfaceIdStr = std::to_string(surfaceId);
       OH_LOG_INFO(LOG_APP, "Input surface ID: %{public}s", surfaceIdStr.c_str());
       return surfaceIdStr;
   }
   ```

5. Initialize the video data input source. This step is performed in the video data collection module. For the camera module, you need to create a Camera instance, obtain the camera list, create a camera input stream, and create a video output stream. For details, see [Video Recording](../camera/native-camera-recording.md).

6. Start recording. Start the input source to input video data, for example, by calling **OH_VideoOutput_Start()** of the camera module. Then call **OH_AVRecorder_Start()** to switch the AVRecorder to the **started** state.

   <!-- @[start_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Start(g_recorder);
   ```

7. Call **OH_AVRecorder_Pause()** to pause recording. The AVRecorder enters the **paused** state. In addition, pause data input, for example, by calling **OH_VideoOutput_Stop()** of the camera module.

   <!-- @[pause_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Pause(g_recorder);
   ```

8. Call **OH_AVRecorder_Resume()** to resume recording. The AVRecorder enters the **started** state again.

   <!-- @[resume_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Resume(g_recorder);
   ```

9. Call **OH_AVRecorder_Stop()** to stop recording. The AVRecorder enters the **stopped** state. In addition, stop camera recording.

   <!-- @[stop_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

   ``` C++
   OH_AVErrCode err = OH_AVRecorder_Stop(g_recorder);
   ```

10. Call **OH_AVRecorder_Reset()** to reset the resources. The AVRecorder enters the **idle** state. In this case, you can reconfigure the recording parameters.

    <!-- @[reset_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

    ``` C++
    OH_AVErrCode err = OH_AVRecorder_Reset(g_recorder);
    ```

11. Call **OH_AVRecorder_Release()** to release the resources. The AVRecorder enters the **released** state. In addition, release the video data input source resources (camera resources in this example).

    <!-- @[release_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

    ``` C++
    OH_AVRecorder_Release(g_recorder);
    ```

## Complete Sample Code

Refer to the sample code below to complete the process of creating a recorder instance, preparing for, starting, pausing, resuming, and stopping recording, resetting the recording state, and releasing the recording resources.

   <!-- @[full_video_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/cpp/avrecorder_ndk.cpp) -->

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
   
   // ...
   static constexpr int32_t VIDEO_BITRATE = 3000000;
   static constexpr int32_t VIDEO_FRAME_WIDTH = 1920;
   static constexpr int32_t VIDEO_FRAME_HEIGHT = 1080;
   static constexpr int32_t VIDEO_FRAME_RATE = 30;
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

   void OnUri(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
   {
       (void)recorder;
       (void)userData;
       OH_LOG_INFO(LOG_APP, "==NDKDemo== OnUri in!");
       if (asset != nullptr) {
           auto changeRequest = OH_MediaAssetChangeRequest_Create(asset);
           if (changeRequest == nullptr) {
               OH_LOG_ERROR(LOG_APP, "==NDKDemo== changeRequest is null!");
               OH_MediaAsset_Release(asset);
               return;
           }
           MediaLibrary_ImageFileType imageFileType = MEDIA_LIBRARY_FILE_VIDEO;
           int32_t result = OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest, imageFileType);
           OH_LOG_INFO(LOG_APP, "result of OH_MediaAssetChangeRequest_SaveCameraPhoto: %d", result);
   
           int32_t resultChange = OH_MediaAccessHelper_ApplyChanges(changeRequest);
           OH_LOG_INFO(LOG_APP, "result of OH_MediaAccessHelper_ApplyChanges: %d", resultChange);

           OH_MediaAsset_Release(asset);
           OH_MediaAssetChangeRequest_Release(changeRequest);
       } else {
           OH_LOG_ERROR(LOG_APP, "Received null media asset!");
       }
       OH_LOG_INFO(LOG_APP, "==NDKDemo== OnUri out!");
   }

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

   static napi_value SetRecorderUriCallback(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "SetRecorderUriCallback called");
       OH_AVRecorder_SetUriCallback(g_recorder, OnUri, nullptr);
       napi_value result;
       napi_create_int32(env, 0, &result);
       return result;
   }

   // ...

   static napi_value PrepareVideoRecorder(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "PrepareVideoRecorder called");

       OH_AVRecorder_Config config;
       memset(&config, 0, sizeof(config));

       config.videoSourceType = AVRECORDER_SURFACE_YUV;
       config.profile.videoBitrate = VIDEO_BITRATE; // 3000000
       config.profile.videoCodec = AVRECORDER_VIDEO_AVC;
       config.profile.videoFrameWidth = VIDEO_FRAME_WIDTH; // 1920
       config.profile.videoFrameHeight = VIDEO_FRAME_HEIGHT; // 1080
       config.profile.videoFrameRate = VIDEO_FRAME_RATE; // 30
       config.profile.isHdr = false;
       config.profile.enableTemporalScale = false;
       config.profile.fileFormat = AVRECORDER_CFT_MPEG_4;
       config.fileGenerationMode = AVRECORDER_APP_CREATE;
       config.metadata.videoOrientation = strdup("90");

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
       g_outputFd = open((avrecorderRoot + "/video_example.mp4").c_str(), O_RDWR | O_CREAT, FILE_PERMISSIONS);
       std::string fileUrl = "fd://" + std::to_string(g_outputFd);
       config.url = strdup(fileUrl.c_str());
       OH_LOG_INFO(LOG_APP, "config.url is: %s", config.url);

       OH_AVErrCode err = OH_AVRecorder_Prepare(g_recorder, &config);
       free(config.url);
       free(config.metadata.videoOrientation);
       if (err != AV_ERR_OK) {
           OH_LOG_ERROR(LOG_APP, "Failed to prepare video recorder, error: %{public}d", err);
       }
       napi_value result;
       napi_create_int32(env, static_cast<int32_t>(err), &result);
       return result;
   }
      
   static std::string GetSurfaceIdString()
   {
       OHNativeWindow *window = nullptr;
       OH_AVErrCode err = OH_AVRecorder_GetInputSurface(g_recorder, &window);
       if (err != AV_ERR_OK || window == nullptr) {
           OH_LOG_ERROR(LOG_APP, "Failed to get input surface, error: %{public}d", err);
           return "";
       }
       uint64_t surfaceId = 0;
       int32_t nErr = OH_NativeWindow_GetSurfaceId(window, &surfaceId);
       if (nErr != 0) {
           OH_LOG_ERROR(LOG_APP, "Failed to get surface ID from native window, error: %{public}d", nErr);
           return "";
       }
       std::string surfaceIdStr = std::to_string(surfaceId);
       OH_LOG_INFO(LOG_APP, "Input surface ID: %{public}s", surfaceIdStr.c_str());
       return surfaceIdStr;
   }

   static napi_value GetInputSurfaceId(napi_env env, napi_callback_info info)
   {
       OH_LOG_INFO(LOG_APP, "GetInputSurfaceId called");
       std::string surfaceId = GetSurfaceIdString();
       napi_value result;
       napi_create_string_utf8(env, surfaceId.c_str(), NAPI_AUTO_LENGTH, &result);
       return result;
   }

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