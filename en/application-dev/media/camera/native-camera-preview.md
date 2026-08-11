# Preview (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=92637e66fde45a3fccdf6e7082b1121eb02199b4 translatedAt=2026-08-10T09:20:06.603Z pushedAt=2026-08-10T13:25:31.969Z -->

Preview is the image you see after you start the camera application but before you take photos or record videos.

## How to Develop

For detailed API descriptions, see [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

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

The **XComponent** provides the surface ID for preview streams, and its capabilities are offered by the UI. For details, see [XComponent Reference](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

4. Call [OH_CameraManager_GetSupportedCameraOutputCapability()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameraoutputcapability) to obtain the preview capability supported by the current device based on the surface ID. Then call [OH_CameraManager_CreatePreviewOutput()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createpreviewoutput) to create a PreviewOutput instance, with the parameters set to the **cameraManager** pointer, the first item in the **previewProfiles** array, the surface ID obtained in step 3, and the returned **previewOutput** pointer, respectively.

   <!-- @[create_preview_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->    

   ``` C++
   Camera_ErrorCode NDKCamera::CreatePreviewOutput(void)
   {
       if (previewProfile_ == nullptr) {
           OH_LOG_ERROR(LOG_APP, "Get previewProfiles failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       ret_ = OH_CameraManager_CreatePreviewOutput(cameraManager_, previewProfile_, previewSurfaceId_, &previewOutput_);
       OH_LOG_ERROR(LOG_APP, "create preview width: %{public}d, height: %{public}d, format: %{public}d",
           previewProfile_->size.width, previewProfile_->size.height, previewProfile_->format);
       if (previewSurfaceId_ == nullptr || previewOutput_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "CreatePreviewOutput failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       PreviewOutputRegisterCallback();
       return ret_;
   }
   ```

5. Configure the session. Call **commitConfig()** to commit the session configuration, and then call [OH_CaptureSession_Start()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_start) to start outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

   <!-- @[session_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::SessionStart(void)
   {
       Camera_ErrorCode ret = OH_CaptureSession_Start(captureSession_);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Start success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed. %d ", ret);
       }
       return ret;
   }
   ```

6. Call [OH_CaptureSession_Stop()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_stop) to stop outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

   <!-- @[session_stop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::SessionStop(void)
   {
       Camera_ErrorCode ret = OH_CaptureSession_Stop(captureSession_);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Stop success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Stop failed. %d ", ret);
       }
       return ret;
   }
   ```

## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the **'frameStart'** event to listen for preview start events. This event can be registered when a PreviewOutput object is created and is triggered when the bottom layer starts exposure for the first time. The preview stream starts as long as a result is returned.

  <!-- @[start_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PreviewOutputOnFrameStart(Camera_PreviewOutput *previewOutput)
  {
      OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
  }
  ```

- Register the **'frameEnd'** event to listen for preview end events. This event can be registered when a PreviewOutput object is created and is triggered when the last frame of preview ends. The preview stream is considered to have ended when this event is triggered and a result is returned.

  <!-- @[end_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PreviewOutputOnFrameEnd(Camera_PreviewOutput *previewOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'error'** event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

  <!-- @[error_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PreviewOutputOnError(Camera_PreviewOutput *previewOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
  }
  ```

  <!-- @[get_listener_and_register_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  PreviewOutput_Callbacks *NDKCamera::GetPreviewOutputListener(void)
  {
      static PreviewOutput_Callbacks previewOutputListener = {
          .onFrameStart = PreviewOutputOnFrameStart,
          .onFrameEnd = PreviewOutputOnFrameEnd,
          .onError = PreviewOutputOnError
      };
      return &previewOutputListener;
  }
  
  Camera_ErrorCode NDKCamera::PreviewOutputRegisterCallback(void)
  {
      ret_ = OH_PreviewOutput_RegisterCallback(previewOutput_, GetPreviewOutputListener());
      if (ret_ != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
      }
      return ret_;
  }
  ```