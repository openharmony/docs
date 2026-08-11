# YUV Photo Capture (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9a88338888413bc410a855d79b95bea9e0b612b8 translatedAt=2026-08-10T09:23:11.439Z pushedAt=2026-08-10T13:51:08.206Z -->

Starting from API version 23, the camera framework provides the capability to capture photos in YUV format. Compared with regular photo capture, YUV photo capture obtains unencoded image data, which fully preserves the raw luminance and chrominance information captured by the sensor. This makes it suitable for video encoding or professional processing. However, the capture process incurs higher power consumption, and saving the data occupies more storage space.

## How to Develop

For detailed camera API descriptions, refer to the camera module description [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

1. Import the NDK interfaces, which provide camera-related attributes and methods. The import method is as follows:

   <!-- @[import_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.h) -->

   ``` C
   #include <cstdint>
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
   #include "ohcamera/camera_manager.h"
   #include "common/log_common.h"
   
   #include "multimedia/image_framework/image/image_native.h"
   #include "multimedia/image_framework/image/image_source_native.h"
   #include "multimedia/image_framework/image/image_packer_native.h"
   #include "multimedia/media_library/media_access_helper_capi.h"
   #include "multimedia/media_library/media_asset_base_capi.h"
   #include "multimedia/media_library/media_asset_capi.h"
   #include "multimedia/media_library/media_asset_change_request_capi.h"
   #include "multimedia/media_library/media_asset_manager_capi.h"
   #include "multimedia/media_library/moving_photo_capi.h"
   #include "ohcamera/photo_native.h"
   #include <window_manager/oh_display_info.h>
   #include <window_manager/oh_display_manager.h>
   ```

2. Link the relevant dynamic libraries in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libnative_buffer.so
       libohcamera.so
       libohimage.so
       libohfileuri.so
       libmedia_asset_manager.so
       libimage_source.so
       libpixelmap.so
       libimage_packer.so
       libpicture.so
   )
   ```

3. Create and open a camera device. For details, see steps 3 and 4 in [Device Input Management (C/C++)](./native-camera-device-input.md).

4. Obtain the full output capabilities of the camera device.

   Call [OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedfullcameraoutputcapabilitywithscenemode) to obtain the capabilities of all output streams supported by the current device, including preview streams, photo streams, and video streams. The output streams are in the respective profile fields of `CameraOutputCapability`, where the photo stream supports the YUV format. Depending on the specified camera device mode [Camera_SceneMode](../../reference/apis-camera-kit/capi-camera-h.md#camera_scenemode), different types of output streams need to be added.

   <!-- @[get_full_outputCapability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_OutputCapability* NDKCamera::GetSupportedFullCameraOutputCapability(Camera_Manager* cameraManager,
       Camera_Device &camera)
   {
       Camera_OutputCapability* cameraOutputCapability = nullptr;
       // Obtain the output stream capabilities supported by the camera device.
       const Camera_Profile* previewProfile = nullptr;
       const Camera_Profile* photoProfile = nullptr;
       Camera_ErrorCode ret = OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode(cameraManager, &camera,
           Camera_SceneMode::NORMAL_PHOTO, &cameraOutputCapability);
       if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
           return cameraOutputCapability;
       }
       // ...
       return cameraOutputCapability;
   }
   ```

5. Select the output stream capabilities supported by the device and create a photo output stream.

Create a photo output stream via the [OH_CameraManager_CreatePhotoOutputWithoutSurface()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createphotooutputwithoutsurface) method.

You can call [OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedfullcameraoutputcapabilitywithscenemode) to obtain the complete output capability `cameraOutputCapability` supported by the camera in a specified mode, as described in step 2. From the `photoProfiles` in `cameraOutputCapability`, select a profile that supports the YUV format as the `photoProfile` parameter for creating the photo output stream.

   <!-- @[create_photo_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::CreatePhotoOutputWithoutSurfaceId()
   {
       DRAWING_LOGD("NDKCamera::CreatePhotoOutputWithoutSurfaceId into createWithoutSurfaceID branch!");
       OH_LOG_INFO(LOG_APP, "CreatePhotoOutputWithoutSurfaceId format: %{public}d!", cameraProfile_->format);
       OH_LOG_INFO(LOG_APP, "CreatePhotoOutputWithoutSurfaceId width: %{public}d!", cameraProfile_->size.width);
       OH_LOG_INFO(LOG_APP, "CreatePhotoOutputWithoutSurfaceId height: %{public}d!", cameraProfile_->size.height);
       // Create the photo stream directly without passing a surfaceId.
       ret_ = OH_CameraManager_CreatePhotoOutputWithoutSurface(cameraManager_, cameraProfile_, &photoOutput_);
       if (photoOutput_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "CreatePhotoOutputWithoutSurfaceId failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       PhotoOutputRegisterCallback();
       return ret_;
   }
   ```

6. Register a one-shot (`PhotoAvailable`) or deferred (`PhotoAssetAvailable`) photo capture callback. If your app needs to receive images quickly, the [deferred photo capture (PhotoAssetAvailable)](./native-camera-deferred-capture.md) callback is recommended.

> **NOTE**
>
> If a `PhotoAssetAvailable` callback has already been registered and a `PhotoAvailable` callback is registered again after the session starts, registering both `PhotoAssetAvailable` and `PhotoAvailable` simultaneously will cause the stream to restart, and only `PhotoAssetAvailable` will take effect.

   - **One-shot photo capture (PhotoAvailable) development process:**

     - Register the one-shot photo capture callback before the session [OH_CaptureSession_CommitConfig](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig).

     - In the one-shot photo capture callback function, obtain image information, parse the pixelMap data, and perform custom business processing.

     - Pass the processed pixelMap to the ArkTS side via a callback for image display or save the image to a file through a security component.

     - Unregister the one-shot photo capture callback function after use.

     <!-- @[set_photo_single_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

     ``` C++
     // Callback function for deferred photo capture.
     void OnPhotoAvailable(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo)
     {
         OH_LOG_INFO(LOG_APP, "OnPhotoAvailable start!");
         OH_ImageNative* imageNative;
         Camera_ErrorCode errCode = OH_PhotoNative_GetMainImage(photo, &imageNative);
         if (errCode != CAMERA_OK || imageNative == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OH_PhotoNative_GetMainImage call failed, errorCode: %{public}d", errCode);
             return;
         }
         OH_LOG_INFO(LOG_APP, "OH_PhotoNative_GetMainImage success!");
         OH_PictureNative* picture;
         errCode = OH_PhotoNative_GetUncompressedImage(photo, &picture);
         if (errCode != CAMERA_OK || picture == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OH_PhotoNative_GetUncompressedImage call failed, errorCode: %{public}d", errCode);
             return;
         }
         OH_LOG_INFO(LOG_APP, "OnPhotoAvailable errCode:%{public}d picture:%{public}p", errCode, picture);
         // Read the main image mainPixelMap from OH_PictureNative.
         OH_PixelmapNative* mainPixelmap;
         Image_ErrorCode imageErr = OH_PictureNative_GetMainPixelmap(picture, &mainPixelmap);
         if (imageErr != IMAGE_SUCCESS || mainPixelmap == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OH_ImageNative_GetImageSize call failed, errorCode: %{public}d", imageErr);
             return;
         }
         pixelMap = nullptr;
         pixelMap = mainPixelmap;
         OH_LOG_INFO(LOG_APP, "OH_PictureNative_GetMainPixelmap success");
     
         uint32_t byteCount = 0;
         // Obtain the total number of bytes occupied by all pixels in the main image Pixelmap.
         imageErr = OH_PixelmapNative_GetByteCount(mainPixelmap, &byteCount);
         OH_LOG_INFO(LOG_APP, "OH_PixelmapNative_GetByteCount count:%{public}u", byteCount);
         // Obtain the image pixel information of the main image.
         OH_Pixelmap_ImageInfo* imageInfo;
         imageErr = OH_PixelmapNative_GetImageInfo(mainPixelmap, imageInfo);
         OH_LOG_INFO(LOG_APP, "OH_PixelmapNative_GetImageInfo errorCode:%{public}d", imageErr);
     
         uint32_t width;
         uint32_t height;
         uint32_t rowStride;
         int32_t pixelFormat = PIXEL_FORMAT::PIXEL_FORMAT_UNKNOWN;
         int32_t alphaMode = PIXELMAP_ALPHA_TYPE::PIXELMAP_ALPHA_TYPE_UNKNOWN;
         int32_t alphaType = PIXELMAP_ALPHA_TYPE::PIXELMAP_ALPHA_TYPE_UNKNOWN;
         // Obtain the width from the image pixel information of the main image.
         OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
         // Obtain the height from the main image pixel information.
         OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
         // Obtain the row stride from the main image pixel information.
         OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
         // Obtain the pixel format from the main image pixel information.
         OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
         // Obtain the alpha mode from the main image pixel information.
         OH_PixelmapImageInfo_GetAlphaMode(imageInfo, &alphaMode);
         // Obtain the alpha type from the main image pixel information.
         OH_PixelmapImageInfo_GetAlphaType(imageInfo, &alphaType);
         OH_LOG_INFO(LOG_APP, "OH_PixelmapNative_GetImageInfo w: %{public}d, h: %{public}d,"
             "rowStride: %{public}d, pixelFormat: %{public}d, alphaMode: %{public}d, alphaType:"
             "%{public}d", width, height, rowStride, pixelFormat, alphaMode, alphaType);
        // Release resources.
         OH_PictureNative_Release(picture);
     }
     
     // Register the one-shot photo capture callback.
     Camera_ErrorCode NDKCamera::PhotoOutputRegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput)
     {
         OH_LOG_INFO(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback start!");
         Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAvailableCallback(photoOutput, OnPhotoAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback failed.");
         }
         OH_LOG_INFO(LOG_APP, "PhotoOutputRegisterPhotoAvailableCallback return with ret code: %{public}d!", ret);
         return ret;
     }
     
     // Unregister the one-shot photo capture callback.
     Camera_ErrorCode NDKCamera::PhotoOutputUnRegisterPhotoAvailableCallback(Camera_PhotoOutput* photoOutput)
     {
         OH_LOG_INFO(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback start!");
         Camera_ErrorCode ret = OH_PhotoOutput_UnregisterPhotoAvailableCallback(photoOutput, OnPhotoAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback failed.");
         }
         OH_LOG_INFO(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback return with ret code: %{public}d!", ret);
         return ret;
     }
     ```

   - **Deferred photo capture (PhotoAvailable) development process**:

     - Register the deferred photo capture callback before the session [OH_CaptureSession_CommitConfig](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig).

     - In the deferred photo capture callback function, obtain image information, parse the pixelMap data, and perform custom service processing.

     - Pass the processed pixelMap to the ArkTS side via a callback for image display or for saving the image to a file through a security component.

     - After calling [OH_PhotoOutput_Capture](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_capture) to take a photo, you must promptly call [OH_MediaAssetChangeRequest_SaveCameraPhoto](../../reference/apis-media-library-kit/capi-media-asset-change-request-capi-h.md#oh_mediaassetchangerequest_savecameraphoto) to save the image or [OH_MediaAssetChangeRequest_DiscardCameraPhoto](../../reference/apis-media-library-kit/capi-media-asset-change-request-capi-h.md#oh_mediaassetchangerequest_discardcameraphoto) to discard the image. Otherwise, subsequent photo capture will be affected.

     - Deregister the deferred photo capture callback function after use.

     <!-- @[set_photo_double_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

     ``` C++
     // Declare the quick return photo callback.
     void OnRequestQuickImageDataPreparedWithDetails(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId,
         MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type, OH_ImageSourceNative* imageSourceNative,
         OH_PictureNative* pictureNative)
     {
         OH_LOG_INFO(LOG_APP, "OnRequestQuickImageDataPreparedWithDetails start!");
         if (!pictureNative && !imageSourceNative) {
             OH_LOG_ERROR(LOG_APP, "pictureNative and imageSourceNative are null.");
             return;
         } else if (!pictureNative && imageSourceNative) {
             OH_LOG_ERROR(LOG_APP, "OnRequestQuickImageDataPreparedWithDetails, pictureNative is null.");
         } else if (pictureNative && !imageSourceNative) {
             OH_LOG_ERROR(LOG_APP, "OnRequestQuickImageDataPreparedWithDetails, imageSourceNative is null.");
         } else {
             OH_LOG_INFO(LOG_APP, "pictureNative and imageSourceNative are not null.");
         }
     }
     
     // Deferred photo capture callback function.
     void OnPhotoAssetAvailable(Camera_PhotoOutput* photoOutput, OH_MediaAsset* mediaAsset)
     {
         OH_LOG_INFO(LOG_APP, "OnPhotoAssetAvailable start!");
         if (mediaAsset == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable invalid error, mediaAsset is null.");
             return;
         }
         // Attempt to obtain the URI information from mediaAsset.
         NDKCamera::MediaAssetGetUri(mediaAsset);
         // Attempt to obtain the displayName information from mediaAsset.
         NDKCamera::MediaAssetGetDisplayName(mediaAsset);
         // Create a media asset manager object.
         OH_MediaAssetManager* mediaAssetManager = OH_MediaAssetManager_Create();
         if (mediaAssetManager == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to create mediaAssetManager.");
             return;
         }
     
         // Create a media asset change request.
         OH_MediaAssetChangeRequest* changeRequest = OH_MediaAssetChangeRequest_Create(mediaAsset);
         if (changeRequest == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to create changeRequest.");
         }
         // Register the media asset quick request callback.
         MediaLibrary_RequestOptions requestOptions;
         requestOptions.deliveryMode = MEDIA_LIBRARY_BALANCED_MODE;
         MediaLibrary_RequestId requestId;
         result = OH_MediaAssetManager_QuickRequestImage(mediaAssetManager, mediaAsset, requestOptions, &requestId,
             OnRequestQuickImageDataPreparedWithDetails);
         if (result != MEDIA_LIBRARY_OK) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to quick image.");
         }
         // Create the media asset save change request.
         result = OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest,
             MediaLibrary_ImageFileType::MEDIA_LIBRARY_IMAGE_JPEG);
         if (result != MEDIA_LIBRARY_OK) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to save camera photo.");
         }
         result = OH_MediaAccessHelper_ApplyChanges(changeRequest);
         if (result != MEDIA_LIBRARY_OK) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to apply changes.");
         }
     }
     
     // Register the deferred photo capture callback function.
     Camera_ErrorCode NDKCamera::RegisterPhotoAssetAvailable(Camera_PhotoOutput* photoOutput)
     {
         Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(photoOutput, OnPhotoAssetAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "RegisterPhotoAssetAvailable failed. %d ", ret);
         }
         return ret;
     }
     // Unregister the deferred photo capture callback function.
     Camera_ErrorCode NDKCamera::UnregisterPhotoAssetAvailable(Camera_PhotoOutput* photoOutput)
     {
         Camera_ErrorCode ret = OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback(photoOutput, OnPhotoAssetAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "UnregisterPhotoAssetAvailable failed. %d ", ret);
         }
         return ret;
     }
     ```

7. Create a photo session (see [Camera Session Management (C/C++)](./native-camera-session-management.md)), start the session, and prepare for photo capture.

8. Trigger photo capture.

Execute the photo capture task via the [OH_PhotoOutput_Capture()](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_capture) method.

   <!-- @[take_picture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::TakePicture(int32_t degree)
   {
       Camera_ErrorCode ret = CAMERA_OK;
       Camera_ImageRotation imageRotation;
       bool isMirSupported;
       OH_PhotoOutput_IsMirrorSupported(photoOutput_, &isMirSupported);
       OH_PhotoOutput_GetPhotoRotation(photoOutput_, degree, &imageRotation);
       imageRotation = Camera_ImageRotation::CAMERA_IMAGE_ROTATION_0;
   
       Camera_PhotoCaptureSetting curPhotoSetting = {
           quality : QUALITY_LEVEL_HIGH,
           rotation : imageRotation,
           mirror : isMirSupported
       };
       ret = OH_PhotoOutput_Capture_WithCaptureSetting(photoOutput_, curPhotoSetting);
       OH_LOG_INFO(LOG_APP, "TakePicture get quality %{public}d, rotation %{public}d, mirror %{public}d",
           curPhotoSetting.quality, curPhotoSetting.rotation, curPhotoSetting.mirror);
       OH_LOG_INFO(LOG_APP, "TakePicture ret = %{public}d.", ret);
       return ret;
   }
   ```

## Status Listening

During camera app development, you can listen for photo output stream status at any time, including the start of the photo stream, the start and end of photo frames, whether the next photo is ready to be captured, and errors in the photo output stream.

- Listen for the photo start result by registering the fixed **onFrameStart** callback function. You can listen for this event once the photo output is created successfully. This event is triggered upon the first exposure of a photo.

  <!-- @[photo_output_start_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PhotoOutputOnFrameStart(Camera_PhotoOutput *photoOutput)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameStart");
  }
  
  void PhotoOutputOnFrameShutter(Camera_PhotoOutput *photoOutput, Camera_FrameShutterInfo *info)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameShutter");
  }
  ```

- Listen for the photo end result by registering the fixed **onFrameEnd** callback function. You can listen for this event once the photo output is created successfully.

  <!-- @[photo_output_end_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PhotoOutputOnFrameEnd(Camera_PhotoOutput *photoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
  }
  ```

- Listen for the result of whether the next photo can be captured by registering the fixed **captureReady** callback function. You can listen for this event once the photo output is created successfully. This event is triggered when the next photo is ready to be captured, and the returned result contains information about the readiness for the next photo.

  <!-- @[capture_ready_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void CaptureReadyCb(Camera_PhotoOutput* photoOutput)
  {
      g_captureReadyFlag = true;
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnCaptureReady captureReadyFlag = %{public}d", g_captureReadyFlag);
  }
  
  void NDKCamera::RegisterCaptureReadyCallback(Camera_PhotoOutput* photoOutput)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnCaptureReady");
      Camera_ErrorCode ret = OH_PhotoOutput_RegisterCaptureReadyCallback(photoOutput, CaptureReadyCb);
  }
  ```

- Listen for error results of the photo output stream by registering the fixed `onError` callback function. The callback returns the corresponding error code when an error occurs in using the photo output interface. For details about the error codes, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

  <!-- @[photo_output_error_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PhotoOutputOnError(Camera_PhotoOutput *photoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
  }
  ```