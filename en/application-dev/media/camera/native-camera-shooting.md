# Photo Capture (C/C++)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-10T09:23:00.294Z pushedAt=2026-08-10T14:20:40.538Z -->

## Overview

Photo capture is one of the key functions of a camera. Based on the complex logic of the camera module, you can set information such as resolution, flash, focal length, photo quality, and rotation angle in intermediate steps to ensure the quality of captured photos.

Currently, there are two photo capture solutions: [deferred photo capture](./native-camera-deferred-capture.md) and one-shot photo capture (**this document uses one-shot photo capture as the basis for explanation**).

- Deferred photo capture allows the camera to output a low-quality image as a thumbnail to improve the perceived capture speed, while also using a high-quality image to ensure that the final image quality reaches the level of the system camera. This meets the requirements of image processing algorithms without blocking the foreground capture speed, building camera performance competitiveness and improving user experience.

- One-shot photo capture returns a high-quality image after multi-frame fusion and multiple underlying algorithm processing during the capture process, so the Shot2See latency (the process from when the user taps the capture control to when the thumbnail appears in the thumbnail display area) is relatively long. In addition, one-shot photo capture supports adjusting the [photo quality prioritization strategy](#photo-quality-prioritization-strategy) through the [high-performance photo capture](#high-performance-photo-capture) feature to speed up image output or improve image quality.

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
       libhilog_ndk.z.so
       libnative_buffer.so
       libohcamera.so
       libohimage.so
       libohfileuri.so
   )
   ```

3. Create and open a camera device. For details, see steps 3 to 5 in [Device Input Management (C/C++)](./native-camera-device-input.md).

4. Select the output stream capability supported by the camera device and create a photo output stream.

   Call [OH_CameraManager_CreatePhotoOutputWithoutSurface()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createphotooutputwithoutsurface) to create a photo output stream.

   <!-- @[create_photo_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::CreatePhotoOutputWithoutSurfaceId()
   {
       OH_LOG_ERROR(LOG_APP, "CreatePhotoOutputWithoutSurfaceId enter.");
       profile_ = cameraOutputCapability_->photoProfiles[0];
       Camera_Profile* profile = cameraOutputCapability_->photoProfiles[0];
       profile->size.width = NUM_1920;
       profile->size.height = NUM_1080;
       profile_ = profile;
       if (profile_ == nullptr) {
           OH_LOG_ERROR(LOG_APP, "Get photoProfiles failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       ret_ = OH_CameraManager_CreatePhotoOutputWithoutSurface(cameraManager_, profile_, &photoOutput_);
       if (photoOutput_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "CreatePhotoOutputWithoutSurfaceId failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
   // ...
       return ret_;
   }
   ```

5. Register a one-time photo capture callback, which is defined as **PhotoAvailable**. If your application requires rapid image display, use the deferred photo delivery callback, which is defined as [PhotoAssetAvailable](./native-camera-deferred-capture.md).

   > **NOTE**
   >
   > If the **PhotoAssetAvailable** callback has been registered and the **PhotoAvailable** callback is registered after the session starts, the stream will be restarted. In this case, only the **PhotoAssetAvailable** callback takes effect.
   >
   > Therefore, you are not advised to register both **PhotoAssetAvailable** and **PhotoAvailable**.

**One-shot photo capture development process (PhotoAvailable)**:

   - Register the callback before the session commits the configuration.

   - Obtain the image information from the callback, parse the buffer data, and perform custom service processing.

   - Pass the processed buffer to the ArkTS side through the callback for image display or storage (using a security component).

   - Unregister the callback when it is no longer required.

     <!-- @[photo_available](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

     ``` C++
     // Save the buffer processing callback registered on the NAPI side.
     Camera_ErrorCode NDKCamera::RegisterBufferCb(void *cb)
     {
         OH_LOG_INFO(LOG_APP, " RegisterBufferCb start");
         if (cb == nullptr) {
             OH_LOG_INFO(LOG_APP, " RegisterBufferCb invalid error");
             return CAMERA_INVALID_ARGUMENT;
         }
         g_bufferCb = cb;
         return CAMERA_OK;
     }

     static bool ProcessImageNative(OH_ImageNative* imageNative, uint32_t** components,
                                    OH_NativeBuffer** nativeBuffer, size_t* nativeBufferSize)
     {
         if (imageNative == nullptr || components == nullptr || nativeBuffer == nullptr || nativeBufferSize == nullptr) {
             return false;
         }
     
         Image_Size size;
         Image_ErrorCode imageErr = OH_ImageNative_GetImageSize(imageNative, &size);
         if (imageErr != IMAGE_SUCCESS) {
             return false;
         }
     
         size_t componentTypeSize = 0;
         imageErr = OH_ImageNative_GetComponentTypes(imageNative, nullptr, &componentTypeSize);
         if (imageErr != IMAGE_SUCCESS || componentTypeSize == 0) {
             OH_LOG_ERROR(LOG_APP, "GetComponentTypes failed: %{public}d, size: %{public}zu",
                 imageErr, componentTypeSize);
             return false;
         }
     
         if (componentTypeSize > (SIZE_MAX / sizeof(uint32_t))) {
             OH_LOG_ERROR(LOG_APP, "componentTypeSize too large: %{public}zu", componentTypeSize);
             return false;
         }
     
         uint32_t* compArray = new (std::nothrow) uint32_t[componentTypeSize];
         if (!compArray) {
             return false;
         }
     
         size_t tempSize = componentTypeSize;
         imageErr = OH_ImageNative_GetComponentTypes(imageNative, &compArray, &tempSize);
         if (imageErr != IMAGE_SUCCESS) {
             delete[] compArray;
             return false;
         }
         *components = compArray;
     
         imageErr = OH_ImageNative_GetByteBuffer(imageNative, compArray[0], nativeBuffer);
         if (imageErr != IMAGE_SUCCESS) {
             delete[] compArray;
             return false;
         }
     
         imageErr = OH_ImageNative_GetBufferSize(imageNative, compArray[0], nativeBufferSize);
         if (imageErr != IMAGE_SUCCESS) {
             delete[] compArray;
             return false;
         }
     
         int32_t rowStride = 0;
         int32_t pixelStride = 0;
         OH_ImageNative_GetRowStride(imageNative, compArray[0], &rowStride);
         OH_ImageNative_GetPixelStride(imageNative, compArray[0], &pixelStride);
         OH_LOG_INFO(LOG_APP, "Buffer size: %{public}zu, strides: %{public}d/%{public}d",
             *nativeBufferSize, rowStride, pixelStride);
     
         return true;
     }
     
     
     static void CleanupResources(OH_ImageNative* imageNative, uint32_t* components,
                                  OH_NativeBuffer* nativeBuffer, void* virAddr)
     {
         if (components) {
             delete[] components;
         }
     
         if (imageNative) {
             int32_t ret = OH_ImageNative_Release(imageNative);
             if (ret != 0) {
                 OH_LOG_ERROR(LOG_APP, "Release image failed: %{public}d", ret);
             }
         }
     
         if (nativeBuffer && virAddr) {
             int32_t ret = OH_NativeBuffer_Unmap(nativeBuffer);
             if (ret != 0) {
                 OH_LOG_ERROR(LOG_APP, "Unmap buffer failed: %{public}d", ret);
             }
         }
     }
     
     void OnPhotoAvailable(Camera_PhotoOutput *photoOutput, OH_PhotoNative *photo)
     {
         OH_LOG_INFO(LOG_APP, "OnPhotoAvailable start!");
     
         OH_ImageNative *imageNative = nullptr;
         Camera_ErrorCode errCode = OH_PhotoNative_GetMainImage(photo, &imageNative);
         if (errCode != CAMERA_OK || !imageNative) {
             OH_LOG_ERROR(LOG_APP, "GetMainImage failed: %{public}d", errCode);
             return;
         }
     
         uint32_t* components = nullptr;
         OH_NativeBuffer* nativeBuffer = nullptr;
         size_t nativeBufferSize = 0;
     
         if (!ProcessImageNative(imageNative, &components, &nativeBuffer, &nativeBufferSize)) {
             CleanupResources(imageNative, components, nullptr, nullptr);
             return;
         }
     
         void* virAddr = nullptr;
         int32_t ret = OH_NativeBuffer_Map(nativeBuffer, &virAddr);
         if (ret != 0 || !virAddr) {
             OH_LOG_ERROR(LOG_APP, "Map buffer failed: %{public}d", ret);
             CleanupResources(imageNative, components, nativeBuffer, nullptr);
             return;
         }
     
         auto cb = (void (*)(void *, size_t))(g_bufferCb);
         if (cb && virAddr && nativeBufferSize > 0) {
             cb(virAddr, nativeBufferSize);
             OH_LOG_INFO(LOG_APP, "Buffer callback called");
         } else {
             OH_LOG_ERROR(LOG_APP, "Invalid callback parameters");
         }
     
         CleanupResources(imageNative, components, nativeBuffer, virAddr);
     
         OH_LOG_INFO(LOG_APP, "OnPhotoAvailable end");
     }

     Camera_ErrorCode NDKCamera::PhotoOutputRegisterPhotoAvailableCallback(void)
     {
         OH_LOG_INFO(LOG_APP, "NDKCamera::PhotoOutputRegisterPhotoAvailableCallback start!");
         Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAvailableCallback(photoOutput_, OnPhotoAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_INFO(LOG_APP, "NDKCamera::PhotoOutputRegisterPhotoAvailableCallback failed.");
         }
         OH_LOG_INFO(LOG_APP, "NDKCamera::PhotoOutputRegisterPhotoAvailableCallback return with ret code: %{public}d!",
             ret_);
         return ret;
     }

     // Unregister the PhotoAvailableCallback callback.
     Camera_ErrorCode NDKCamera::PhotoOutputUnRegisterPhotoAvailableCallback()
     {
         OH_LOG_INFO(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback start!");
         Camera_ErrorCode ret = OH_PhotoOutput_UnregisterPhotoAvailableCallback(photoOutput_, OnPhotoAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback failed.");
         }
         OH_LOG_INFO(LOG_APP, "PhotoOutputUnRegisterPhotoAvailableCallback return with ret code: %{public}d!", ret);
         return ret;
     }
     ```

    Reference sample code for buffer callback processing at the NAPI layer:

     <!-- @[napi_buffer_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/main.cpp) -->

     ``` C++
     // Buffer callback at the NAPI layer.
     static void BufferCb(void* buffer, size_t size)
     {
         OH_LOG_INFO(LOG_APP, "BufferCb size:%{public}zu", size);
         g_size = size;
         napi_value asyncResource = nullptr;
         napi_value asyncResourceName = nullptr;
         napi_async_work work;

         if (size == 0 || size > SIZE_MAX) {
             OH_LOG_ERROR(LOG_APP, "BufferCb size is invalid");
             return;
         }
         void* copyBuffer = malloc(size);
         if (copyBuffer == nullptr) {
             return;
         }
         OH_LOG_INFO(LOG_APP, "BufferCb copyBuffer:%{public}p", copyBuffer);
         // Use std::memcpy to copy the content in the buffer to the copyBuffer.
         std::memcpy(copyBuffer, buffer, size);
         napi_create_string_utf8(env_, "BufferCb", NAPI_AUTO_LENGTH, &asyncResourceName);
         napi_status status = napi_create_async_work(
             env_, asyncResource, asyncResourceName, [](napi_env env, void* copyBuffer) {},
             [](napi_env env, napi_status status, void* copyBuffer) {
                 napi_value retVal;
                 napi_value callback = nullptr;
                 void* data = nullptr;
                 napi_value arrayBuffer = nullptr;
                 size_t bufferSize = g_size;
                 napi_create_arraybuffer(env, bufferSize, &data, &arrayBuffer);
                 std::memcpy(data, copyBuffer, bufferSize);
                 OH_LOG_INFO(LOG_APP, "BufferCb g_size: %{public}zu", g_size);
                 napi_get_reference_value(env, bufferCbRef_, &callback);
                 if (callback) {
                     OH_LOG_INFO(LOG_APP, "BufferCb callback is full");
                 } else {
                     OH_LOG_ERROR(LOG_APP, "BufferCb callback is null");
                 }
                 // Call the buffer processing callback function at the ArkTS side to pass the image arrayBuffer for display or storage.
                 napi_call_function(env, nullptr, callback, 1, &arrayBuffer, &retVal);
             },
             copyBuffer, &work);
         // Error check: The memory is released when the asynchronous work fails to be created.
         if (status != napi_ok) {
             OH_LOG_ERROR(LOG_APP, "Failed to create async work");
             free(copyBuffer); // Release the allocated memory.
             return;
         }
         napi_queue_async_work_with_qos(env_, work, napi_qos_user_initiated);
     }
     ```

6. Create a photo session. For details, see [Camera Session Management (C/C++)](./native-camera-session-management.md).

7. (Optional) Set photo capture parameters.

   You can set camera parameters to adjust photo capture functions, including the flash, zoom ratio, and focal length.

   <!-- @[settings_configuration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::HasFlashFn(uint32_t mode)
   {
       Camera_FlashMode flashMode = static_cast<Camera_FlashMode>(mode);
       // Check the flash.
       bool hasFlash = false;
       Camera_ErrorCode ret = OH_CaptureSession_HasFlash(captureSession_, &hasFlash);
       if (captureSession_ == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_HasFlash failed.");
       }
       if (hasFlash) {
           OH_LOG_INFO(LOG_APP, "hasFlash success-----");
       } else {
           OH_LOG_ERROR(LOG_APP, "hasFlash fail-----");
       }

       // Query whether the flash mode is supported.
       bool isSupported = false;
       ret = OH_CaptureSession_IsFlashModeSupported(captureSession_, flashMode, &isSupported);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFlashModeSupported failed.");
       }
       if (isSupported) {
           OH_LOG_INFO(LOG_APP, "isFlashModeSupported success-----");
       } else {
           OH_LOG_ERROR(LOG_APP, "isFlashModeSupported fail-----");
       }
   
       // Set the flash mode.
       ret = OH_CaptureSession_SetFlashMode(captureSession_, flashMode);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
       }
   
       // Obtain the flash mode of the current device.
       ret = OH_CaptureSession_GetFlashMode(captureSession_, &flashMode);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFlashMode success. flashMode: %{public}d ", flashMode);
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFlashMode failed. %d ", ret);
       }
       return ret;
   }

   // Focus mode.
   Camera_ErrorCode NDKCamera::IsFocusModeSupported(uint32_t mode)
   {
       Camera_FocusMode focusMode = static_cast<Camera_FocusMode>(mode);
       ret_ = OH_CaptureSession_IsFocusModeSupported(captureSession_, focusMode, &isFocusModeSupported_);
       if (&isFocusModeSupported_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "IsFocusModeSupported failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       return ret_;
   }
   
   Camera_ErrorCode NDKCamera::IsFocusMode(uint32_t mode)
   {
       OH_LOG_INFO(LOG_APP, "IsFocusMode start.");
       Camera_FocusMode focusMode = static_cast<Camera_FocusMode>(mode);
       ret_ = OH_CaptureSession_IsFocusModeSupported(captureSession_, focusMode, &isFocusModeSupported_);
       if (&isFocusModeSupported_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "IsFocusModeSupported failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       ret_ = OH_CaptureSession_SetFocusMode(captureSession_, focusMode);
       if (ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "SetFocusMode failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       ret_ = OH_CaptureSession_GetFocusMode(captureSession_, &focusMode);
       if (&focusMode == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "GetFocusMode failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       OH_LOG_INFO(LOG_APP, "IsFocusMode end.");
       return ret_;
   }

   Camera_ErrorCode NDKCamera::setZoomRatioFn(uint32_t zoomRatio)
   {
       float zoom = float(zoomRatio);
       // Obtain the supported zoom range.
       float minZoom;
       float maxZoom;
       Camera_ErrorCode ret = OH_CaptureSession_GetZoomRatioRange(captureSession_, &minZoom, &maxZoom);
       if (captureSession_ == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatioRange failed.");
       } else {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatioRange success. minZoom: %{public}f, maxZoom:%{public}f",
               minZoom, maxZoom);
       }
   
       // Set the zoom ratio.
       ret = OH_CaptureSession_SetZoomRatio(captureSession_, zoom);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetZoomRatio success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetZoomRatio failed. %{public}d ", ret);
       }
   
       // Obtain the zoom ratio of the current device.
       ret = OH_CaptureSession_GetZoomRatio(captureSession_, &zoom);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatio success. zoom: %{public}f ", zoom);
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatio failed. %{public}d ", ret);
       }
       return ret;
   }
   ```

8. Trigger photo capture.

   Call [OH_PhotoOutput_Capture_WithCaptureSetting()](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_capture_withcapturesetting) to execute the photo capture task.

   <!-- @[capture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

   ``` C++
   Camera_ErrorCode NDKCamera::TakePicture(int32_t degree)
   {
       Camera_ErrorCode ret = CAMERA_OK;
       Camera_ImageRotation imageRotation;
       bool isMirSupported;
       OH_PhotoOutput_IsMirrorSupported(photoOutput_, &isMirSupported);
       OH_PhotoOutput_GetPhotoRotation(photoOutput_, degree, &imageRotation);
   
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

## High-Performance Photo Capture

Starting from API version 21, the high-performance photo capture feature is supported, which allows you to set an explicit [photo quality prioritization strategy](#photo-quality-prioritization-strategy) during one-shot photo capture.

The experience of one-shot photo capture is primarily measured by image output speed and final image quality. Therefore, to meet the differentiated requirements of developers in different scenarios, the emphasis on these two metrics varies. For example, street snapshots require quickly capturing the moment, while landscape or portrait photography pursues ultimate image quality.

> **NOTE**
>
> Only one-shot photo capture supports setting the photo quality prioritization strategy. If the strategy is set in deferred photo capture, the setting will not take effect.

### Photo Quality Prioritization Strategy

When using one-shot photo capture, you can set two types of photo quality prioritization strategies: speed priority and high quality priority, which correspond to different [Camera_PhotoQualityPrioritization](../../reference/apis-camera-kit/capi-camera-h.md#camera_photoqualityprioritization) enumeration values.

- [CAMERA_PHOTO_QUALITY_PRIORITIZATION_SPEED](../../reference/apis-camera-kit/capi-camera-h.md#camera_photoqualityprioritization) corresponds to speed priority, which reduces image quality to improve capture speed. If you do not set an explicit photo quality prioritization strategy during one-shot photo capture, **one-shot photo capture defaults to the speed priority state**.

- [CAMERA_PHOTO_QUALITY_PRIORITIZATION_HIGH_QUALITY](../../reference/apis-camera-kit/capi-camera-h.md#camera_photoqualityprioritization) corresponds to high quality priority, which takes a longer time to obtain a higher-quality image.

### How to Correctly Set the Photo Quality Prioritization Strategy

To correctly set the photo quality prioritization strategy in one-shot photo capture, the high-performance photo capture feature provides the following two APIs:

- [OH_PhotoOutput_IsPhotoQualityPrioritizationSupported](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_isphotoqualityprioritizationsupported): Queries whether the current device supports the specified photo quality prioritization strategy. The value **true** indicates supported, and **false** indicates not supported. Before setting the photo quality prioritization strategy, you must first query whether the strategy to be set is available on the current device.

- [OH_PhotoOutput_SetPhotoQualityPrioritization](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_setphotoqualityprioritization): Sets the photo quality prioritization strategy. Call this API to set the corresponding strategy for high-performance photo capture.

### How to Develop

The high-performance photo capture APIs must be called during the enabling step of the [Camera Session Management (C/C++)](native-camera-session-management.md) process.

The specific calling timing is as follows:

- Call after [OH_CaptureSession_CommitConfig()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig) in the enabling step of the [Camera Session Management (C/C++)](native-camera-session-management.md) process.

  ```c++
  Camera_ErrorCode StartSession(Camera_CaptureSession* captureSession, Camera_Input* cameraInput,
    Camera_PreviewOutput* previewOutput, Camera_PhotoOutput* photoOutput)
  {
    // Add the camera input stream to the session.
    Camera_ErrorCode ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
      return ret;
    }

    // Add the preview output stream to the session.
    ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
      return ret;
    }

    // Add the photo output stream to the session.
    ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
      return ret;
    }

    // Commit the session configuration.
    ret = OH_CaptureSession_CommitConfig(captureSession);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
      return ret;
    }

    // Start the session.
    ret = OH_CaptureSession_Start(captureSession);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
    }

    SetHighQualityPhotoQualityPrioritization(photoOutput);
    return ret;
  }

  void SetHighQualityPhotoQualityPrioritization(Camera_PhotoOutput* photoOutput)
  {
    Camera_PhotoQualityPrioritization quality = Camera_PhotoQualityPrioritization::CAMERA_PHOTO_QUALITY_PRIORITIZATION_HIGH_QUALITY;
    bool isSupported = false;
    Camera_ErrorCode ret = OH_PhotoOutput_IsPhotoQualityPrioritizationSupported(photoOutput, quality, &isSupported);
    if (isSupported) {
      ret = OH_PhotoOutput_SetPhotoQualityPrioritization(photoOutput, quality);
      if (ret != 0) {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_SetPhotoQualityPrioritization failed.");
      }
    } else {
      OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_IsPhotoQualityPrioritizationSupported not supported.");
    }
  }
  ```

- Call before [OH_CaptureSession_CommitConfig()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig) in the enabling step of the [Camera Session Management (C/C++)](native-camera-session-management.md) process.

  ```c++
  Camera_ErrorCode StartSession(Camera_CaptureSession* captureSession, Camera_Input* cameraInput,
    Camera_PreviewOutput* previewOutput, Camera_PhotoOutput* photoOutput)
  {
    // Add the camera input stream to the session.
    Camera_ErrorCode ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
      return ret;
    }

    // Add the preview output stream to the session.
    ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
      return ret;
    }

    // Add the photo output stream to the session.
    ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
      return ret;
    }

    SetHighQualityPhotoQualityPrioritization(photoOutput);
    
    // Commit the session configuration.
    ret = OH_CaptureSession_CommitConfig(captureSession);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
      return ret;
    }

    // Start the session.
    ret = OH_CaptureSession_Start(captureSession);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
    }

    return ret;
  }

  void SetHighQualityPhotoQualityPrioritization(Camera_PhotoOutput* photoOutput)
  {
    Camera_PhotoQualityPrioritization quality = Camera_PhotoQualityPrioritization::CAMERA_PHOTO_QUALITY_PRIORITIZATION_HIGH_QUALITY;
    bool isSupported = false;
    Camera_ErrorCode ret = OH_PhotoOutput_IsPhotoQualityPrioritizationSupported(photoOutput, quality, &isSupported);
    if (isSupported) {
      ret = OH_PhotoOutput_SetPhotoQualityPrioritization(photoOutput, quality);
      if (ret != 0) {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_SetPhotoQualityPrioritization failed.");
      }
    } else {
      OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_IsPhotoQualityPrioritizationSupported not supported.");
    }
  }
  ```

## Status Listening

During camera application development, you can listen for the status of the photo output stream, including the start of the photo stream, the start and end of the photo frame, and the errors of the photo output stream.

- Register the **'onFrameStart'** event to listen for photo capture start events. This event can be registered when a PhotoOutput instance is created and is triggered when the bottom layer starts exposure for photo capture for the first time. The capture ID is returned.

  <!-- @[photo_output_start_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  // PhotoOutput Callback
  void PhotoOutputOnFrameStart(Camera_PhotoOutput *photoOutput)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameStart");
  }
  
  void PhotoOutputOnFrameShutter(Camera_PhotoOutput *photoOutput, Camera_FrameShutterInfo *info)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameShutter");
  }
  ```

- Register the **'onFrameEnd'** event to listen for photo capture end events. This event can be registered when a PhotoOutput instance is created.

  <!-- @[photo_output_end_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PhotoOutputOnFrameEnd(Camera_PhotoOutput *photoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
  }
  ```

- Register the **'onError'** event to listen for photo output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode).

  <!-- @[photo_output_error_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  void PhotoOutputOnError(Camera_PhotoOutput *photoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
  }
  ```

  <!-- @[get_photo_output_listener_and_register_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->

  ``` C++
  PhotoOutput_Callbacks *NDKCamera::GetPhotoOutputListener(void)
  {
      static PhotoOutput_Callbacks photoOutputListener = {
          .onFrameStart = PhotoOutputOnFrameStart,
          .onFrameShutter = PhotoOutputOnFrameShutter,
          .onFrameEnd = PhotoOutputOnFrameEnd,
          .onError = PhotoOutputOnError
      };
      return &photoOutputListener;
  }
  
  Camera_ErrorCode NDKCamera::PhotoOutputRegisterCallback(void)
  {
      ret_ = OH_PhotoOutput_RegisterCallback(photoOutput_, GetPhotoOutputListener());
      if (ret_ != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterCallback failed.");
      }
      return ret_;
  }
  ```