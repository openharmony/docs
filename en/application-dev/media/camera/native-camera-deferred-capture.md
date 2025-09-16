# Deferred Photo Delivery (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

As an important feature of the camera, deferred photo delivery enables the system, after receiving a photo capture task from an application, to report images of different quality levels in multiple phases.

- In the first phase, the system promptly delivers an image that has undergone lightweight processing, offering a balance between reduced quality and swift image availability. The application receives a PhotoAsset object through the callback. Through this object, the application can call the media library APIs to read the image or flush the image to the disk.
- In the second phase, the camera framework enhances the image to achieve full quality, either in response to the application's request for higher quality or when the system is not busy. The enhanced image is then sent back to the media library to replace the previously provided one.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/capi-oh-camera.md) for the API reference.

1. Import the NDK, which provides camera-related properties and methods.

   ```c++
   // Include the NDK header files.
   #include <cstdint>
   #include <cstdlib>
   #include <cstring>
   #include <memory>
   #include <mutex>
   #include "hilog/log.h"
   #include "napi/native_api.h"
   #include <ohcamera/camera.h>
   #include <ohcamera/photo_output.h>
   #include <ohcamera/camera_manager.h>
   #include <multimedia/media_library/media_asset_manager_capi.h>
   #include <multimedia/media_library/media_asset_change_request_capi.h>
   #include <multimedia/media_library/media_access_helper_capi.h>
   #include <multimedia/image_framework/image/image_packer_native.h>
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

4. Register a deferred photo delivery callback, which is defined as **PhotoAssetAvailable**. Compared with one-time photo capture, only the callback registered is different.

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

   ```c++
   // Method 1: Call the media library API to save the images.
   void mediaLibSavePhoto(OH_MediaAsset* mediaAsset) {
       if (mediaAsset == nullptr) {
           OH_LOG_ERROR(LOG_APP, "mediaAsset is nullptr!");
           return;
       }
       // Create a media asset change request object.
       OH_MediaAssetChangeRequest* changeRequest = OH_MediaAssetChangeRequest_Create(mediaAsset);
       if (changeRequest == nullptr) {
           OH_LOG_ERROR(LOG_APP, "changeRequest is nullptr!");
           return;
       }
       // Request to save the image.
       MediaLibrary_ErrorCode errCode =
           OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest, MEDIA_LIBRARY_IMAGE_JPEG);
       OH_LOG_INFO(LOG_APP, "SaveCameraPhoto get errCode:%{public}d", errCode);
       // Initiate a request.
       errCode = OH_MediaAccessHelper_ApplyChanges(changeRequest);
       OH_LOG_INFO(LOG_APP, "ApplyChanges get errCode:%{public}d", errCode);
   }
   
   // Method 2: Call the media library API to request images.
   // Called when the image source is ready.
   std::mutex g_mediaAssetMutex;
   OH_MediaAsset* g_mediaAsset_;
   void OnImageDataPrepared(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId,
                            MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,
                            OH_ImageSourceNative* imageSourceNative) {
       if (imageSourceNative == nullptr) {
           OH_LOG_ERROR(LOG_APP, "OnImageDataPrepared: imageSourceNative is nullptr!");
           return;
       }
       if (mediaQuality == MediaLibrary_MediaQuality::MEDIA_LIBRARY_QUALITY_FAST) {
           OH_LOG_INFO(LOG_APP, "OnImageDataPrepared: Using fast media quality.");
       } else if (mediaQuality == MediaLibrary_MediaQuality::MEDIA_LIBRARY_QUALITY_FULL) {
           OH_LOG_INFO(LOG_APP, "OnImageDataPrepared: Using full media quality.");
       }
       // Create OH_PixelmapNative through OH_ImageSourceNative.
       OH_PixelmapNative* pixelmapNative = nullptr;
       OH_DecodingOptions* decodingOptions = nullptr;
       Image_ErrorCode imageErr = IMAGE_SUCCESS;
       imageErr = OH_ImageSourceNative_CreatePixelmap(imageSourceNative, decodingOptions, &pixelmapNative);
       if (imageErr != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OnImageDataPrepared: CreatePixelmap failed.");
           return;
       }
       // Create an image packer and set packing options.
       OH_ImagePackerNative* imagePacker;
       OH_ImagePackerNative_Create(&imagePacker);
       OH_PackingOptions* options;
       OH_PackingOptions_Create(&options);
       char format[] = "image/jpeg";
       Image_MimeType image_MimeType = {format, strlen(format)};
       OH_PackingOptions_SetMimeType(options, &image_MimeType);
       OH_PackingOptions_SetQuality (options, 100); // Highest quality: 100
       size_t bufferSize = 3072 * 4096; // If a value greater than the size after encoding is passed, a new value will be assigned after encoding.
       // Parse the image buffer.
       auto buffer = std::make_unique<uint8_t[]>(bufferSize);
       imageErr = OH_ImagePackerNative_PackToDataFromPixelmap(imagePacker, options, pixelmapNative, buffer.get(), &bufferSize);
       OH_LOG_INFO(LOG_APP, "OnImageDataPrepared: packToData ret code:%{public}u outsize:%{public}zu", imageErr, bufferSize);
       std::lock_guard<std::mutex> lock(g_mediaAssetMutex);
       if (g_mediaAsset_ == nullptr) {
         OH_LOG_ERROR(LOG_APP,  "OnImageDataPrepared: get current mediaAsset failed!");
         return;
       }
       // Call the media library API to save images in the buffer.
       OH_MediaAssetChangeRequest* changeRequest = OH_MediaAssetChangeRequest_Create(g_mediaAsset_);
       MediaLibrary_ErrorCode mediaErr = OH_MediaAssetChangeRequest_AddResourceWithBuffer(changeRequest,
           MEDIA_LIBRARY_IMAGE_RESOURCE, buffer.get(), bufferSize);
       OH_LOG_INFO(LOG_APP,  "OnImageDataPrepared: AddResourceWithBuffer get errCode:%{public}d", mediaErr);
       mediaErr = OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest, MEDIA_LIBRARY_IMAGE_JPEG);
       OH_LOG_INFO(LOG_APP,  "OnImageDataPrepared: SaveCameraPhoto get errCode:%{public}d", mediaErr);
       mediaErr = OH_MediaAccessHelper_ApplyChanges(changeRequest);
       OH_LOG_INFO(LOG_APP,  "OnImageDataPrepared: ApplyChanges get errCode:%{public}d", mediaErr);
   }
   
   void mediaLibRequestBuffer(OH_MediaAsset* mediaAsset) {
       if (mediaAsset == nullptr) {
           OH_LOG_ERROR(LOG_APP, "mediaAsset is nullptr!");
           return;
       }
       // Create a media asset manager.
       OH_MediaAssetManager* mediaAssetManager = OH_MediaAssetManager_Create();
       if (mediaAssetManager == nullptr) {
           OH_LOG_ERROR(LOG_APP, "mediaAssetManager is nullptr!");
           return;
       }
       // Set the parameters for requesting images.
       MediaLibrary_RequestOptions requestOptions;
       // Configure the policy mode based on service requirements to request image assets.
       // MEDIA_LIBRARY_FAST_MODE: callback for receiving the first-phase image.
       // MEDIA_LIBRARY_HIGH_QUALITY_MODE: callback for receiving the second-phase image.
       // MEDIA_LIBRARY_BALANCED_MODE: callback for receiving both images.
       requestOptions.deliveryMode = MEDIA_LIBRARY_FAST_MODE;
       MediaLibrary_RequestId requestId;
       // Request the image asset. Call onImageDataPrepared when it is ready.
       MediaLibrary_ErrorCode result = OH_MediaAssetManager_RequestImage(mediaAssetManager, mediaAsset, requestOptions, &requestId, OnImageDataPrepared);
       if (result != MEDIA_LIBRARY_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_MediaAssetManager_RequestImage failed.");
       }
   }
   
   // Deferred phot delivery callback.
   void OnPhotoAssetAvailable(Camera_PhotoOutput* photoOutput, OH_MediaAsset* mediaAsset) {
       OH_LOG_INFO(LOG_APP, "OnPhotoAssetAvailable start!");
       if (mediaAsset == nullptr) {
           OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable mediaAsset nullptr!");
           return;
       }
       // Processing method 1: Call the media library API to save the image in the first phase. After the image in the second phase is ready, the media library proactively replaces the image flushed.
       // mediaLibSavePhoto(mediaAsset);
       // Processing method 2: Call the media library API to request an image asset, obtain the buffer of the first-phase or second-phase image, and save the image in the buffer after service processing.
       std::lock_guard<std::mutex> lock(g_mediaAssetMutex);
       g_mediaAsset_ = mediaAsset;
       mediaLibRequestBuffer(mediaAsset);
   }
   
   // Register the PhotoAssetAvailableCallback callback.
   Camera_ErrorCode PhotoOutputRegisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput) {
       Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(photoOutput, OnPhotoAssetAvailable);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterPhotoAssetAvailableCallback failed.");
       }
       return ret;
   }
   ```
