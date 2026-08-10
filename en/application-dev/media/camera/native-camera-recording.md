# Video Recording (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=a6fe22b8c0b778d60770969b7ec064c000a8b479 translatedAt=2026-08-10T09:20:41.257Z pushedAt=2026-08-10T13:30:44.138Z -->

Recording is cyclic frame capture and one of the most important features of a camera app. For recording smoothness, refer to step 7 in the [development procedure of Photo Capture (C/C++)](native-camera-shooting.md#development-procedure) to set the resolution, flash, focal length, photo quality, rotation angle, and other parameters.

## How to Develop

For detailed API descriptions, refer to [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

1. Import the NDK, which provides camera-related properties and methods.

   <!-- @[import_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.h) -->

   ``` C
   #include <cstdint>
   #include <native_buffer/buffer_common.h>
   #include <unistd.h>
   #include <string>
   #include <thread>
   #include <cstdio>
   #include <fcntl.h>
   #include <map>
   #include <string>
   #include <vector>
   #include <native_buffer/native_buffer.h>
   #include "iostream"
   #include "mutex"
   
   #include "hilog/log.h"
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "napi/native_api.h"
   #include "ohcamera/camera_manager.h"
   #include <window_manager/oh_display_info.h>
   #include <window_manager/oh_display_manager.h>
   
   namespace OHOS_CAMERA_SAMPLE {
   class NDKCamera {
     public:
       struct CameraBuildingConfig {
           char *str;
           uint32_t focusMode;
           uint32_t cameraDeviceIndex;
           bool isVideo;
           bool isHdr;
           char *videoId;
       };
       ~NDKCamera();
       explicit NDKCamera(CameraBuildingConfig config);
       // ...
   };
   } // namespace OHOS_CAMERA_SAMPLE
   ```

2. Link the dynamic library in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libohcamera.so
       libhilog_ndk.z.so
   )
   ```

3. Obtain the surface ID.

The system-provided [OH_AVRecorder_Create()](../../reference/apis-media-kit/capi-avrecorder-h.md#oh_avrecorder_create) API creates an AVRecorder instance for recording, and the [OH_AVRecorder_GetInputSurface()](../../reference/apis-media-kit/capi-avrecorder-h.md#oh_avrecorder_getinputsurface) method of this instance obtains the surface ID.

4. Create a video output stream.

   Based on the surface ID passed in, call [OH_CameraManager_GetSupportedCameraOutputCapability](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameraoutputcapability) to obtain [Camera_OutputCapability](../../reference/apis-camera-kit/capi-oh-camera-camera-outputcapability.md). From there, you can access **videoProfiles** to obtain the video output streams supported by the device. Then, define video recording parameters and use **OH_CameraManager_CreateVideoOutput** to create a video output stream.

   > **NOTE**
   >
   > - The aspect ratio of the preview stream must be consistent with that of the recording output stream. For example, if the aspect ratio in the sample code is 640:480 = 4:3, the resolution in the preview stream must also have an aspect ratio of 4:3. Available resolutions include 640:480, 960:720, 1440:1080, and so on.
   >
   > - Before setting the resolution aspect ratio of the preview output stream, query the configurable width and height ranges supported for video frames through [OH_AVRecorder_Profile](../../reference/apis-media-kit/capi-avrecorder-oh-avrecorder-profile.md).

   <!-- @[create_video_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::CreateVideoOutput(char *videoId)
   {
       if (videoProfile_ == nullptr) {
           OH_LOG_ERROR(LOG_APP, "Get videoProfiles failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       ret_ = OH_CameraManager_CreateVideoOutput(cameraManager_, videoProfile_, videoId, &videoOutput_);
       OH_LOG_ERROR(LOG_APP, " create video width: %{public}d, height: %{public}d, format: %{public}d",
           videoProfile_->size.width, videoProfile_->size.height, videoProfile_->format);
       if (videoId == nullptr || videoOutput_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "CreateVideoOutput failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       VideoOutputRegisterCallback();
       return ret_;
   }
   ```

5. Start video recording.

   Call [OH_VideoOutput_Start()](../../reference/apis-camera-kit/capi-video-output-h.md#oh_videooutput_start) to start the video output stream.

   <!-- @[video_output_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::VideoOutputStart(void)
   {
       OH_LOG_INFO(LOG_APP, "VideoOutputStart begin.");
       Camera_ErrorCode ret = OH_VideoOutput_Start(videoOutput_);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_VideoOutput_Start success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed. %d ", ret);
       }
       return ret;
   }
   ```

6. Stop video recording.

   Call [OH_VideoOutput_Stop()](../../reference/apis-camera-kit/capi-video-output-h.md#oh_videooutput_stop) to stop the video output stream.

   <!-- @[video_output_stop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::VideoOutputStop(void)
   {
       OH_LOG_ERROR(LOG_APP, "enter VideoOutputStop.");
       ret_ = OH_VideoOutput_Stop(videoOutput_);
       if (ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "VideoOutputStop failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       return ret_;
   }
   ```

## Status Listening

During camera application development, you can listen for the status of the video output stream, including recording start, recording end, and video output errors.

- Register the **'frameStart'** event to listen for recording start events. This event can be registered when a VideoOutput instance is created and is triggered when the bottom layer starts exposure for recording for the first time. Video recording starts as long as the event is triggered.

  <!-- @[video_callback_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void VideoOutputOnFrameStart(Camera_VideoOutput *videoOutput)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutputOnFrameStart");
  }
  ```

- Register the **'frameEnd'** event to listen for recording end events. This event can be registered when a VideoOutput instance is created and is triggered when the last frame of recording ends. Video recording ends as long as a result is returned.

  <!-- @[video_callback_end](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void VideoOutputOnFrameEnd(Camera_VideoOutput *videoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'error'** event to listen for video output errors. The callback function returns an error code when a video output API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

  <!-- @[video_callback_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void VideoOutputOnError(Camera_VideoOutput *videoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
  }
  ```

  <!-- @[get_video_listener_and_register](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  VideoOutput_Callbacks *NDKCamera::GetVideoOutputListener(void)
  {
      static VideoOutput_Callbacks videoOutputListener = {
          .onFrameStart = VideoOutputOnFrameStart,
          .onFrameEnd = VideoOutputOnFrameEnd,
          .onError = VideoOutputOnError
      };
      return &videoOutputListener;
  }

  Camera_ErrorCode NDKCamera::VideoOutputRegisterCallback(void)
  {
      ret_ = OH_VideoOutput_RegisterCallback(videoOutput_, GetVideoOutputListener());
      if (ret_ != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
      }
      return ret_;
  }
  ```