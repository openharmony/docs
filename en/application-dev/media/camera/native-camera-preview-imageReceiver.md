# Secondary Processing of Preview Streams (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=92637e66fde45a3fccdf6e7082b1121eb02199b4 translatedAt=2026-08-10T09:19:58.359Z pushedAt=2026-08-10T13:23:36.095Z -->

You can use the APIs in **ImageReceiver** to create a PreviewOutput instance and obtain real-time data of the preview stream for secondary processing. For example, you can add a filter algorithm to the preview stream.

## How to Develop

For detailed API descriptions, refer to [OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md).

1. Import the NDK, which provides camera-related properties and methods.

   <!-- @[import_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPreviewImageSample/entry/src/main/cpp/camera_manager.h) -->    

   ``` C
   #include <cstdint>
   #include <cstdlib>
   #include "hilog/log.h"
   #include <memory>
   #include <new>
   #include <map>
   #include <multimedia/image_framework/image/image_native.h>
   #include <multimedia/image_framework/image/image_receiver_native.h>
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/camera_device.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   
   #include <multimedia/media_library/media_asset_manager_capi.h>
   #include <multimedia/media_library/media_asset_change_request_capi.h>
   #include <multimedia/media_library/media_access_helper_capi.h>
   #include <multimedia/image_framework/image/image_packer_native.h>
   ```

2. Link the dynamic library in the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohimage.so
       libimage_receiver.so
       libnative_image.so
       libohcamera.so
       libnative_buffer.so
   )
   ```

3. Initialize an [ImageReceiver](../image/image-receiver-c.md) instance and obtain a surface ID.

   Call **OH_ImageReceiverNative_Create** of the image module to create an OH_ImageReceiverNative instance, and call **OH_ImageReceiverNative_GetReceivingSurfaceId** of the instance to obtain a surface ID.

   <!-- @[init_image_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPreviewImageSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   void InitImageReceiver(uint64_t &receiverSurfaceID)
   {
       OH_ImageReceiverOptions *options = nullptr;
       // Capture exceptions and check whether the instance is null. This example shows only the API call process.
       // Set image parameters.
       Image_ErrorCode errCode = OH_ImageReceiverOptions_Create(&options);
       if (errCode != IMAGE_SUCCESS || options == nullptr) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageReceiverOptions_Create call failed");
           return;
       }
       Image_Size imgSize;
       imgSize.width = PREVIEW_WIDTH; // Width of the preview stream.
       imgSize.height = PREVIEW_HEIGHT; // Height of the preview stream.
       int32_t capacity = 8; // Maximum number of images in BufferQueue. The recommended value is 8.
       errCode = OH_ImageReceiverOptions_SetSize(options, imgSize);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageReceiverOptions_SetSize call failed");
       }
       errCode = OH_ImageReceiverOptions_SetCapacity(options, capacity);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageReceiverOptions_SetCapacity call failed");
       }
       // Create an OH_ImageReceiverNative instance.
       OH_ImageReceiverNative *receiver = nullptr;
       errCode = OH_ImageReceiverNative_Create(options, &receiver);
       if (errCode != IMAGE_SUCCESS || receiver == nullptr) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageReceiverNative_Create call failed");
           return;
       }
   
       errCode = OH_ImageReceiverNative_On(receiver, CallbackReadNextImage);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "%{public}s image receiver on failed, errCode: %{public}d.", __func__, errCode);
           OH_ImageReceiverOptions_Release(options);
           OH_ImageReceiverNative_Release(receiver);
           return;
       }
       // Obtain the Surface ID of the OH_ImageReceiverNative instance.
       errCode = OH_ImageReceiverNative_GetReceivingSurfaceId(receiver, &receiverSurfaceID);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageReceiverNative_GetReceivingSurfaceId call failed");
       } else {
           OH_LOG_INFO(LOG_APP, "receiver surfaceID:%{public}lu", receiverSurfaceID);
       }
   }
   ```

4. Create a preview stream based on the surface ID obtained. (Note that you must convert the surface ID type to char * before the creation of the preview stream.) For details, see step 4 in [Camera Preview (C/C++)](./native-camera-preview.md).

5. Create a session and enable it. For details, see [Camera Session Management (C/C++)](./native-camera-session-management.md).

6. Register an ImageReceiver callback to listen for the image content reported by each frame.

   <!-- @[image_receiver_callback_show](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPreviewImageSample/entry/src/main/cpp/napi_init.cpp) -->    

   ``` C++
   void copyBuffer(OH_NativeBuffer *srcBuffer, size_t srcSize, OHNativeWindowBuffer *dstBuffer)
   {
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest %{public}s IN", __func__);
       void *srcVir = nullptr;
       OH_NativeBuffer_Map(srcBuffer, &srcVir);
       BufferHandle *bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(dstBuffer);
       OH_LOG_INFO(LOG_APP,
           "ImageReceiverNativeCTest %{public}s bufferHandle info fd= %{public}d , width= %{public}d, "
           "height=%{public}d, stride= %{public}d, size= %{public}d, format= %{public}d, usage= %{public}lu",
           __func__, bufferHandle->fd, bufferHandle->width, bufferHandle->height, bufferHandle->stride, bufferHandle->size,
           bufferHandle->format, bufferHandle->usage);
   
       void *mappedAddr =
           mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0);
       std::memcpy(static_cast<unsigned char *>(mappedAddr), static_cast<unsigned char *>(srcVir), srcSize);
       munmap(mappedAddr, bufferHandle->size);
   
       OH_NativeBuffer_Unmap(srcBuffer);
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest %{public}s SUCCESS", __func__);
   }

   void ShowImage(OH_ImageNative *image)
   {
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest %{public}s IN", __func__);
       uint64_t xComponentSurfaceId = std::stoull(g_xComponentSurfaceIdSlave);
       OH_LOG_ERROR(LOG_APP, "ImageReceiverNativeCTest %{public}s XComponentId is : %{public}lu.", __func__,
           xComponentSurfaceId);
       OHNativeWindow *nativeWindow = nullptr;
       int32_t res = OH_NativeWindow_CreateNativeWindowFromSurfaceId(xComponentSurfaceId, &nativeWindow);
       if (res != 0) {
           OH_LOG_ERROR(LOG_APP,
               "ShowImage CreateNativeWindowFromSurfaceId failed, errCode: %{public}d.", res);
           return;
       }
   
       // Important: Adjust the nativeWindow size and format to match the size and format of the image.
       res = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, SET_BUFFER_GEOMETRY, g_imageWidth, g_imageHeight);
       res = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, SET_FORMAT, NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP); // NV21
       
       int32_t displayRotation = g_ndkCamera->GetDefaultDisplayRotation();
       int32_t previewRotation = static_cast<int32_t>(g_ndkCamera->GetPreviewRotation(displayRotation));
       if (g_isFront && (displayRotation == ROTATION_90 || displayRotation == ROTATION_270)) {
           previewRotation = (previewRotation + ROTATION_180) % ROTATION_360;
       }
       OH_NativeBuffer_TransformType transformType = g_ndkCamera->GetNativeBufferTransformType(previewRotation, g_isFront);
       res = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, SET_TRANSFORM, transformType);
   
       OH_NativeBuffer *imageBuffer = nullptr;
       Image_ErrorCode errCode = OH_ImageNative_GetByteBuffer(image, g_jpegComponent, &imageBuffer);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "ShowImage GetByteBuffer failed, errCode: %{public}d.", errCode);
           return;
       }
       Image_Size imgSize = {};
       OH_ImageNative_GetImageSize(image, &imgSize);
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest %{public}s imgSize is : %{public}u, %{public}u.", __func__,
           imgSize.width, imgSize.height);
       size_t bufSize = 0;
       OH_ImageNative_GetBufferSize(image, g_jpegComponent, &bufSize);

       OHNativeWindowBuffer *nativeWindowBuffer = nullptr;
       int fenceFd = -1;
       res = OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &nativeWindowBuffer, &fenceFd);
       if (res != 0) {
           OH_LOG_ERROR(LOG_APP, "ShowImage RequestBuffer failed, errCode: %{public}d.", res);
           return;
       }
   
       // Copy the image data to the nativeWindowBuffer.
       copyBuffer(imageBuffer, bufSize, nativeWindowBuffer);
   
       Region region1{};
       res = OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, nativeWindowBuffer, fenceFd, region1);
       if (res != 0) {
           OH_LOG_ERROR(LOG_APP, "ShowImage FlushBuffer failed, errCode: %{public}d.", res);
           return;
       }
       OH_LOG_INFO(LOG_APP, "ImageReceiverNativeCTest %{public}s SUCCESS", __func__);
   }
   
   static void CallbackReadNextImage(OH_ImageReceiverNative *receiver)
   {
       OH_LOG_INFO(LOG_APP, "CallbackReadNextImage %{public}s IN", __func__);
       // Read the next image object from OH_ImageReceiverNative.
       OH_ImageNative *image = nullptr;
       Image_ErrorCode errCode = OH_ImageReceiverNative_ReadNextImage(receiver, &image);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP,
               "CallbackReadNextImage %{public}s get image receiver next image failed, errCode: %{public}d.", __func__,
               errCode);
           return;
       }
   
       ShowImage(image);
   
       // Release the OH_ImageNative instance.
       errCode = OH_ImageNative_Release(image);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "CallbackReadNextImage %{public}s release image native failed, errCode: %{public}d.",
               __func__, errCode);
       }
       OH_LOG_INFO(LOG_APP, "CallbackReadNextImage %{public}s SUCCESS", __func__);
   }
   ```