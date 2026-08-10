# Camera Metadata (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=7af318f702cc007dfff9ab3817e651170c470e50 translatedAt=2026-08-10T09:19:26.344Z pushedAt=2026-08-10T13:23:13.900Z -->

Metadata is the description and context of image information returned by the camera application. It provides detailed data for the image information, such as the coordinates of a viewfinder frame for identifying a portrait in a photo or video.

Metadata primarily uses a TAG (Key) to locate the corresponding data (Value), enabling parameter and configuration information transfer while reducing memory copy operations.

## How to Develop

For detailed API descriptions, see [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

1. Import the NDK.

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

3. Call **OH_CameraManager_GetSupportedCameraOutputCapability()** to obtain the metadata types supported by the current device, and then call **OH_CameraManager_CreateMetadataOutput()** to create a metadata output stream.

   <!-- @[create_metadata_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::CreateMetadataOutput(void)
   {
       metaDataObjectType_ = cameraOutputCapability_->supportedMetadataObjectTypes[0];
       if (metaDataObjectType_ == nullptr) {
           OH_LOG_ERROR(LOG_APP, "Get metaDataObjectType failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       ret_ = OH_CameraManager_CreateMetadataOutput(cameraManager_, metaDataObjectType_, &metadataOutput_);
       if (metadataOutput_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "CreateMetadataOutput failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       MetadataOutputRegisterCallback();
       return ret_;
   }
   ```

4. Call [OH_CameraManager_CreateCaptureSession()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createcapturesession) to create a session.

   <!-- @[create_capture_session](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   ret = OH_CameraManager_CreateCaptureSession(cameraManager_, &captureSession_);
   if (captureSession_ == nullptr || ret != CAMERA_OK) {
       OH_LOG_ERROR(LOG_APP, "Create captureSession failed.");
   }
   ```

5. Configure the session. After the configuration, call [OH_CaptureSession_Start()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_start) to output metadata. If the call fails, an error code is returned. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

   <!-- @[add_metadata_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   // Start configuring the session.
   Camera_ErrorCode ret = OH_CaptureSession_BeginConfig(captureSession_);

   // Add the camera input stream to the session.
   ret = OH_CaptureSession_AddInput(captureSession_, cameraInput_);

   // Add the camera preview stream to the session.
   ret = OH_CaptureSession_AddPreviewOutput(captureSession_, previewOutput_);

   if (isVideo_) {
       // Add the camera video stream to the session.
       AddVideoOutput();
       if (isHdrVideo) {
           // HDR Vivid video requires setting the color space to OH_COLORSPACE_BT2020_HLG_LIMIT.
           OH_NativeBuffer_ColorSpace colorSpace = OH_NativeBuffer_ColorSpace::OH_COLORSPACE_BT2020_HLG_LIMIT;
           SetColorSpace(colorSpace);
       }
   } else {
       // Add the camera photo stream to the session.
       AddPhotoOutput();
       ret = CreateMetadataOutput();
       ret = OH_CaptureSession_AddMetadataOutput(captureSession_, metadataOutput_);
       OH_NativeBuffer_ColorSpace colorSpace = OH_NativeBuffer_ColorSpace::OH_COLORSPACE_P3_FULL;
       SetColorSpace(colorSpace);
   }

   // Commit the session configuration.
   ret = OH_CaptureSession_CommitConfig(captureSession_);
   // ...

   InitPreviewRotation();
   // Start the session.
   OH_LOG_INFO(LOG_APP, "session start");
   ret = OH_CaptureSession_Start(captureSession_);
   ```

6. Call [OH_MetadataOutput_Stop()](../../reference/apis-camera-kit/capi-metadata-output-h.md#oh_metadataoutput_stop) to stop outputting metadata. If the API call fails, a corresponding error code is returned.

   ```c++
   Camera_ErrorCode StopMetadataOutput(Camera_MetadataOutput* metadataOutput)
   {
       Camera_ErrorCode ret = OH_MetadataOutput_Stop(metadataOutput);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_Stop failed.");
       }
       return ret;
   }
   ```

## Status Listening

During camera application development, you can listen for the status of metadata objects and output stream.

- Register the **'metadataObjectsAvailable'** event to listen for metadata objects that are available. When a valid metadata object is detected, the callback function returns the metadata. This event can be registered when a MetadataOutput object is created.

  <!-- @[metadata_callback_available](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void OnMetadataObjectAvailable(Camera_MetadataOutput *metadataOutput, Camera_MetadataObject *metadataObject,
      uint32_t size)
  {
      OH_LOG_INFO(LOG_APP, "size = %{public}d", size);
  }
  ```

  > **NOTE**
  >
  > Currently, only **FACE_DETECTION** is available for the metadata type. The metadata object is the rectangle of the recognized face, including the x-axis coordinate and y-axis coordinate of the top-left corner of the rectangle as well as the width and height of the rectangle.

- Register the **'error'** event to listen for metadata stream errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

  <!-- @[metadata_callback_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void OnMetadataOutputError(Camera_MetadataOutput *metadataOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "OnMetadataOutput errorCode = %{public}d", errorCode);
  }
  ```

  <!-- @[get_metadata_listener_and_register](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  MetadataOutput_Callbacks *NDKCamera::GetMetadataOutputListener(void)
  {
      static MetadataOutput_Callbacks metadataOutputListener = {
          .onMetadataObjectAvailable = OnMetadataObjectAvailable,
          .onError = OnMetadataOutputError
      };
      return &metadataOutputListener;
  }
  
  Camera_ErrorCode NDKCamera::MetadataOutputRegisterCallback(void)
  {
      ret_ = OH_MetadataOutput_RegisterCallback(metadataOutput_, GetMetadataOutputListener());
      if (ret_ != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_MetadataOutput_RegisterCallback failed.");
      }
      return ret_;
  }
  ```