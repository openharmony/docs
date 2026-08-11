# Deferred Photo Delivery (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=92637e66fde45a3fccdf6e7082b1121eb02199b4 translatedAt=2026-08-10T09:18:40.990Z pushedAt=2026-08-10T13:16:40.561Z -->

Deferred photo capture is one of the most important camera features. The camera outputs a low-quality image for quick display, enhancing the user's perceived capture speed, while using a high-quality image to ensure the final image quality meets the level of the system camera. This not only meets the needs of post-processing algorithms but also avoids blocking the foreground capture speed, building camera performance competitiveness and improving user experience.

- In the first phase, the system promptly delivers an image that has undergone lightweight processing, offering a balance between reduced quality and swift image availability. The application receives a PhotoAsset object through the callback. Through this object, the application can call the media library APIs to read the image or flush the image to the disk.

- In the second phase, the camera framework enhances the image to achieve full quality, either in response to the application's request for higher quality or when the system is not busy. The enhanced image is then sent back to the media library to replace the previously provided one.

## How to Develop

For details about the APIs, see [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

1. Import the NDK, which provides camera-related properties and methods.

   <!-- @[import_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKDeferredCaptureSample/entry/src/main/cpp/camera_manager.h) -->

   ``` C
   #include <cstdint>
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

2. Link the dynamic libraries in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohcamera.so
       libimage_source.so
       libmedia_asset_manager.so
       libimage_packer.so
   )
   ```

3. Initialize the camera and trigger photo capture. For details, see [Photo Capture (C/C++)](./native-camera-shooting.md).

4. Register a deferred photo capture (**PhotoAssetAvailable**) callback. Compared with one-shot photo capture, only the callback registered is different.

   > **NOTE**
   >
   > If the **PhotoAssetAvailable** callback has been registered and the **PhotoAvailable** callback is registered after the session starts, the stream will be restarted. In this case, only the **PhotoAssetAvailable** callback takes effect.
   >
   > Therefore, you are not advised to register both **PhotoAssetAvailable** and **PhotoAvailable**.

   Register **PhotoAssetAvailableCallback** to receive images delivered in both phases.

   The development process is as follows:

   - Register the callback before the session commits the configuration.

   - Obtain a media asset through the callback.

   - Through the media asset, either save the images or request images and after service processing, save them through a buffer or display them. For details, see step 5 in [Photo Capture (C/C++)](./native-camera-shooting.md).

   - Unregister the callback when it is no longer required.

   <!-- @[deferred_photo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKDeferredCaptureSample/entry/src/main/cpp/camera_manager.cpp) -->    

   ``` C++
   // Deferred photo capture callback.
   void onPhotoAssetAvailable(Camera_PhotoOutput *photoOutput, OH_MediaAsset *mediaAsset)
   {
       if (mediaAsset == nullptr) {
           DRAWING_LOGI("onPhotoAssetAvailable mediaAsset is nullptr !");
           return;
       }
       DRAWING_LOGD("onPhotoAssetAvailable start!");
       NDKCamera::MediaAssetRelease();
       g_mediaAsset = mediaAsset;
       NDKCamera::MediaAssetGetUri(mediaAsset);
       NDKCamera::MediaAssetGetDisplayName(mediaAsset);
       NDKCamera::MediaAssetGetSize(mediaAsset);
       NDKCamera::MediaAssetGetDateModifiedMs(mediaAsset);
       NDKCamera::MediaAssetGetWidth(mediaAsset);
       NDKCamera::MediaAssetGetHeight(mediaAsset);
       NDKCamera::MediaAssetGetOrientation(mediaAsset);
       NDKCamera::MediaAssetManagerCreate();
       NDKCamera::MediaAssetChangeRequest(mediaAsset);
       DRAWING_LOGD("onPhotoAssetAvailable finish!");
       return;
   }
   
   // Register the deferred photo capture callback.
   Camera_ErrorCode NDKCamera::PhotoOutputRegisterPhotoAssetAvailableCallback(void)
   {
       DRAWING_LOGD("NDKCamera::PhotoOutputRegisterPhotoAssetAvailableCallback start!");
       MediaAssetManagerCreate();
       ret_ = OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(photoOutput_, onPhotoAssetAvailable);
       if (ret_ != CAMERA_OK) {
           DRAWING_LOGD("NDKCamera::PhotoOutputRegisterPhotoAssetAvailableCallback failed.");
       }
       DRAWING_LOGD(
           "NDKCamera::PhotoOutputRegisterPhotoAssetAvailableCallback return with ret code: %{public}d!",
           ret_);
       return ret_;
   }
   
   MediaLibrary_ErrorCode NDKCamera::MediaAssetChangeRequest(OH_MediaAsset *mediaAsset)
   {
       DRAWING_LOGD("NDKCamera::MediaAssetChangeRequest start!");
       MediaAssetChangeRequestCreate(mediaAsset);
       MediaAssetManagerRequestImage(mediaAsset);
       DRAWING_LOGD("NDKCamera::MediaAssetChangeRequest finish!");
       return MEDIA_LIBRARY_OK;
   }
   
   MediaLibrary_ErrorCode NDKCamera::MediaAssetChangeRequestCreate(OH_MediaAsset *mediaAsset)
   {
       DRAWING_LOGD("NDKCamera::MediaAssetChangeRequestCreate start!");
       g_changeRequest = OH_MediaAssetChangeRequest_Create(mediaAsset);
       if (g_changeRequest == nullptr) {
           DRAWING_LOGD("NDKCamera::MediaAssetChangeRequestCreate failed.");
       }
       return MEDIA_LIBRARY_OK;
   }
   
   MediaLibrary_ErrorCode NDKCamera::MediaAssetManagerCreate(void)
   {
       DRAWING_LOGD("NDKCamera::MediaAssetManagerCreate start!");
       mediaAssetManager = OH_MediaAssetManager_Create();
       if (mediaAssetManager == nullptr) {
           DRAWING_LOGD("NDKCamera::MediaAssetManagerCreate failed.");
       }
       return MEDIA_LIBRARY_OK;
   }
   
   void OnRequestImageDataPreparedWithDetails(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId,
       MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type, OH_ImageSourceNative *imageSourceNative)
   {
       auto cb = (void (*)(char *))(g_requestImageCallback);
       auto qCb = (void (*)(char *))(g_requestImageQualityCallback);
       DRAWING_LOGD("OnRequestImageDataPreparedWithDetails start!");
       if (mediaQuality == MediaLibrary_MediaQuality::MEDIA_LIBRARY_QUALITY_FAST) {
           DRAWING_LOGD("OnRequestImageDataPreparedWithDetails into fast quality mode!");
           g_mediaQualityCb = "fast";
           qCb(g_mediaQualityCb);
       } else {
           DRAWING_LOGD("OnRequestImageDataPreparedWithDetails into high quality mode!");
           g_mediaQualityCb = "high";
           qCb(g_mediaQualityCb);
       }
       DRAWING_LOGD("OnRequestImageDataPreparedWithDetails GetUri uri_ = %{public}s", URI);
       cb(const_cast<char *>(URI));
       NDKCamera::ChangeRequestAddResourceWithBuffer(imageSourceNative);
       return;
   }
   
   // Request image data: deliveryMode, quality, and other parameters are controlled via requestOptions. The callback OnRequestImageDataPreparedWithDetails is invoked upon completion.
   MediaLibrary_ErrorCode NDKCamera::MediaAssetManagerRequestImage(OH_MediaAsset *mediaAsset)
   {
       DRAWING_LOGD("NDKCamera::MediaAssetManagerRequestImage start! g_deliveryMode = %{public}d",
           g_deliveryMode);
       requestOptions.deliveryMode = g_deliveryMode;
       result = OH_MediaAssetManager_RequestImage(mediaAssetManager, mediaAsset, requestOptions, &g_requestId,
           OnRequestImageDataPreparedWithDetails);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD("NDKCamera::MediaAssetManagerRequestImage failed.");
       }
       DRAWING_LOGD("NDKCamera::MediaAssetManagerRequestImage return with ret code: %{public}d!", result);
       return result;
   }
   
   MediaLibrary_ErrorCode NDKCamera::ChangeRequestAddResourceWithBuffer(OH_ImageSourceNative *imageSourceNative)
   {
       DRAWING_LOGD("NDKCamera::ChangeRequestAddResourceWithBuffer start!");
       size_t bufferSize = BUFFER_SIZE;
       char buffer[BUFFER_SIZE];
       int fd = open("/data/storage/el2/base/haps/test.jpg", O_RDONLY);
       int fr = read(fd, buffer, bufferSize);
       if (fr == -1) {
           DRAWING_LOGD("NDKCamera::ChangeRequestAddResourceWithBuffer read failed.");
           return MEDIA_LIBRARY_OK;
       }
       if (fr == BUFFER_SIZE) {
           DRAWING_LOGD("NDKCamera::ChangeRequestAddResourceWithBuffer read not complete.");
           return MEDIA_LIBRARY_OK;
       }
       result = OH_MediaAssetChangeRequest_AddResourceWithBuffer(g_changeRequest,
           MediaLibrary_ResourceType::MEDIA_LIBRARY_IMAGE_RESOURCE, (uint8_t *)buffer, (uint32_t)bufferSize);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD("NDKCamera::ChangeRequestAddResourceWithBuffer failed.");
           DRAWING_LOGD("NDKCamera::ChangeRequestAddResourceWithBuffer failed %{public}d.", result);
           return MEDIA_LIBRARY_OK;
       }
       result = OH_MediaAccessHelper_ApplyChanges(g_changeRequest);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD(
               "NDKCamera::ChangeRequestAddResourceWithBuffer OH_MediaAccessHelper_ApplyChanges failed.");
           return MEDIA_LIBRARY_OK;
       }
       DRAWING_LOGD("NDKCamera::ChangeRequestAddResourceWithBuffer OH_MediaAccessHelper_ApplyChanges return "
                    "with ret code: %{public}d!",
           result);
       return result;
   }
   
   MediaLibrary_ErrorCode NDKCamera::ChangeRequestSaveCameraPhoto(void)
   {
       DRAWING_LOGD("NDKCamera::ChangeRequestSaveCameraPhoto start!");
       result = OH_MediaAssetChangeRequest_SaveCameraPhoto(g_changeRequest,
           MediaLibrary_ImageFileType::MEDIA_LIBRARY_IMAGE_JPEG);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD(
               "NDKCamera::ChangeRequestSaveCameraPhoto OH_MediaAssetChangeRequest_SaveCameraPhoto failed.");
       }
       DRAWING_LOGD("NDKCamera::ChangeRequestSaveCameraPhoto OH_MediaAssetChangeRequest_SaveCameraPhoto "
                    "return with ret code: %{public}d!",
           result);
       result = OH_MediaAccessHelper_ApplyChanges(g_changeRequest);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD("NDKCamera::ChangeRequestSaveCameraPhoto OH_MediaAccessHelper_ApplyChanges failed.");
       }
       DRAWING_LOGD("NDKCamera::ChangeRequestSaveCameraPhoto OH_MediaAccessHelper_ApplyChanges return with "
                    "ret code: %{public}d!",
           result);
       return result;
   }
   
   MediaLibrary_ErrorCode NDKCamera::ChangeRequestDiscardCameraPhoto(void)
   {
       DRAWING_LOGD("NDKCamera::ChangeRequestDiscardCameraPhoto start!");
       result = OH_MediaAssetChangeRequest_DiscardCameraPhoto(g_changeRequest);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD("NDKCamera::ChangeRequestDiscardCameraPhoto "
                        "OH_MediaAssetChangeRequest_DiscardCameraPhoto failed.");
       }
       DRAWING_LOGD("NDKCamera::ChangeRequestDiscardCameraPhoto OH_MediaAssetChangeRequest_DiscardCameraPhoto "
                    "return with ret code: %{public}d!",
           result);
       result = OH_MediaAccessHelper_ApplyChanges(g_changeRequest);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD(
               "NDKCamera::ChangeRequestDiscardCameraPhoto OH_MediaAccessHelper_ApplyChanges failed.");
       }
       DRAWING_LOGD("NDKCamera::ChangeRequestDiscardCameraPhoto OH_MediaAccessHelper_ApplyChanges return with "
                    "ret code: %{public}d!",
           result);
       return result;
   }
   
   MediaLibrary_ErrorCode NDKCamera::ChangeRequestRelease(void)
   {
       DRAWING_LOGD("NDKCamera::ChangeRequestRelease start!");
       result = OH_MediaAssetChangeRequest_Release(g_changeRequest);
       if (result != MEDIA_LIBRARY_OK) {
           DRAWING_LOGD("NDKCamera::ChangeRequestRelease failed.");
       }
       g_changeRequest = nullptr;
       DRAWING_LOGD("NDKCamera::ChangeRequestRelease return with ret code: %{public}d!", result);
       return result;
   }
   ```