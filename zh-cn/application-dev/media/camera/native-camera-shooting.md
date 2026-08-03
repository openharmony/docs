# 拍照(C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

拍照是相机的重要功能之一，拍照模块基于相机复杂的逻辑，为了保证用户拍出的照片质量，在中间步骤可以设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

目前相机开发有两种相机拍照方案，分别是相机[分段式拍照](./native-camera-deferred-capture.md)和相机单段式拍照（**本文将以单段式拍照为基础进行说明**）。 

- 分段式拍照是指相机拍照既可以输出低质量图用作缩略图，提升用户感知拍照速度，也可以使用高质量图保证最后的成图质量达到系统相机的水平。满足了图像处理算法的需求的同时，又不会阻塞前台的拍照速度，构筑相机性能竞争力，提升用户体验。 
- 单段式拍照是指在拍照过程中通过多帧融合以及多个底层算法处理之后返回一张高质量图片，所以Shot2See（用户点击拍照控件到在缩略图显示区域显示缩略图的过程）完成时延较长。此外，单段式拍照支持通过[高性能拍照](#高性能拍照)功能调整[画质优先策略](#画质优先策略)，以加快出图速度或提升图片质量。 

## 开发步骤

详细的API说明请参考[OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。

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

2. 在CMake脚本中链接相关动态库。

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

3. 创建并打开相机设备，参考[ 设备输入(C/C++)](./native-camera-device-input.md)步骤3-5。

4. 选择设备支持的输出流能力，创建拍照输出流。

   通过[OH_CameraManager_CreatePhotoOutputWithoutSurface()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createphotooutputwithoutsurface)方法创建拍照输出流。

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

5. 注册单段式(PhotoAvailable)拍照回调，若应用希望快速得到回图，推荐使用[分段式拍照回调(PhotoAssetAvailable)](./native-camera-deferred-capture.md)。

   > **注意：**
   >
   > 如果已经注册了PhotoAssetAvailable回调，并且在Session开始之后又注册了PhotoAvailable回调，PhotoAssetAvailable和PhotoAvailable同时注册，会导致流被重启，仅PhotoAssetAvailable生效。
   >
   > 不建议开发者同时注册PhotoAssetAvailable和PhotoAvailable。

   **单段式拍照开发流程（PhotoAvailable）**：

   - 在会话commitConfig前注册单段式拍照回调。
   - 在单段式拍照回调函数中获取图片信息，解析出buffer数据，做自定义业务处理。
   - 将处理完的buffer通过回调传给ArkTS侧，做图片显示或通过安全控件写文件保存图片。
   - 使用完后解注册单段式拍照回调函数。

     <!-- @[photo_available](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->
     
     ``` C++
     // 保存NAPI侧注册的buffer处理回调函数。
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
     
     // 解注册单段式拍照回调。
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

     NAPI层buffer回调处理参考示例代码：

     <!-- @[napi_buffer_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/main.cpp) -->
     
     ``` C++
     // NAPI层buffer回调方法。
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
         // 使用std::memcpy复制buffer的内容到copyBuffer。
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
                 // 调用ArkTS的buffer处理回调函数，将图片arrayBuffer传给页面做显示或保存。
                 napi_call_function(env, nullptr, callback, 1, &arrayBuffer, &retVal);
             },
             copyBuffer, &work);
         // 错误检查：创建异步工作失败时释放内存。
         if (status != napi_ok) {
             OH_LOG_ERROR(LOG_APP, "Failed to create async work");
             free(copyBuffer); // 释放分配的内存。
             return;
         }
         napi_queue_async_work_with_qos(env_, work, napi_qos_user_initiated);
     }
     ```

6. 创建拍照类型会话，参考[会话管理(C/C++)](./native-camera-session-management.md)，开启会话，准备拍照。

7. 配置拍照参数（可选）。

   配置相机的参数可以调整拍照的一些功能，包括闪光灯、变焦、焦距等。

   <!-- @[settings_configuration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->
   
   ``` C++
   Camera_ErrorCode NDKCamera::HasFlashFn(uint32_t mode)
   {
       Camera_FlashMode flashMode = static_cast<Camera_FlashMode>(mode);
       // 检查闪光灯。
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
   
       // 查询闪光灯模式是否支持。
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
   
       // 设置闪光灯模式。
       ret = OH_CaptureSession_SetFlashMode(captureSession_, flashMode);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
       }
   
       // 获取当前设备的闪光灯模式。
       ret = OH_CaptureSession_GetFlashMode(captureSession_, &flashMode);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFlashMode success. flashMode：%{public}d ", flashMode);
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFlashMode failed. %d ", ret);
       }
       return ret;
   }
   
   // 对焦模式。
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
       // 获取支持的缩放范围。
       float minZoom;
       float maxZoom;
       Camera_ErrorCode ret = OH_CaptureSession_GetZoomRatioRange(captureSession_, &minZoom, &maxZoom);
       if (captureSession_ == nullptr || ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatioRange failed.");
       } else {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatioRange success. minZoom: %{public}f, maxZoom:%{public}f",
               minZoom, maxZoom);
       }
   
       // 设置缩放比例。
       ret = OH_CaptureSession_SetZoomRatio(captureSession_, zoom);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetZoomRatio success.");
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetZoomRatio failed. %{public}d ", ret);
       }
   
       // 获取当前设备的缩放比例。
       ret = OH_CaptureSession_GetZoomRatio(captureSession_, &zoom);
       if (ret == CAMERA_OK) {
           OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatio success. zoom：%{public}f ", zoom);
       } else {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatio failed. %{public}d ", ret);
       }
       return ret;
   }
   ```

8. 触发拍照。

   通过[OH_PhotoOutput_Capture_WithCaptureSetting()](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_capture_withcapturesetting)方法，执行拍照任务。

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

## 高性能拍照

从API version 21开始支持高性能拍照功能，即在进行单段式拍照时设置明确的[画质优先策略](#画质优先策略)。

单段式拍照的体验主要由出图速度和最终图片质量衡量。因此，为满足开发者在不同场景下的差异化需求，对这两项指标的侧重也不同。例如，街头抓拍要求快速捕捉瞬间，而风景或人像拍摄则更追求极致的画质。

> **注意：**
>
> 仅单段式拍照支持设置画质优先策略。若在分段式拍照中设置画质优先策略，该设置将无效。


### 画质优先策略

在使用单段式拍照时，支持设置速度优先和画质优先两种画质优先策略类型，并且分别对应着不同的[Camera_PhotoQualityPrioritization](../../reference/apis-camera-kit/capi-camera-h.md#camera_photoqualityprioritization)枚举类型。 

- [CAMERA_PHOTO_QUALITY_PRIORITIZATION_SPEED](../../reference/apis-camera-kit/capi-camera-h.md#camera_photoqualityprioritization)对应着速度优先，表示降低画质来提升拍照的速度。如果开发者在进行单段式拍照时没有设置明确的画质优先策略，**单段式拍照就默认为速度优先状态**。 
- [CAMERA_PHOTO_QUALITY_PRIORITIZATION_HIGH_QUALITY](../../reference/apis-camera-kit/capi-camera-h.md#camera_photoqualityprioritization)对应着画质优先，表示通过较长的耗时来得到画质更高的图片。 

### 如何正确设置画质优先策略

为了正确地在单段式拍照中设置画质优先策略，高性能拍照功能提供了如下两个接口：

- [OH_PhotoOutput_IsPhotoQualityPrioritizationSupported](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_isphotoqualityprioritizationsupported)：查询当前设备是否支持指定的画质优先策略。返回true表示支持，返回false表示不支持。在进行设置画质优先策略之前，必须先查询将要设置的画质优先策略在当前设备上是否可用。 
- [OH_PhotoOutput_SetPhotoQualityPrioritization](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_setphotoqualityprioritization)：画质优先策略设置接口，通过该接口设置对应的画质优先策略，实现高性能拍照。 

### 开发步骤

高性能拍照相关接口需要在[会话管理(C/C++)](native-camera-session-management.md)流程的使能步骤中进行调用。  

具体调用时机如下： 

- 在[会话管理(C/C++)](native-camera-session-management.md)流程中的使能步骤中的[OH_CaptureSession_CommitConfig()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig)结束之后进行调用。 

  ```c++
  Camera_ErrorCode StartSession(Camera_CaptureSession* captureSession, Camera_Input* cameraInput,
    Camera_PreviewOutput* previewOutput, Camera_PhotoOutput* photoOutput)
  {
    // 向会话中添加相机输入流。
    Camera_ErrorCode ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
      return ret;
    }

    // 向会话中添加预览输出流。
    ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
      return ret;
    }

    // 向会话中添加拍照输出流。
    ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
      return ret;
    }

    // 提交会话配置。
    ret = OH_CaptureSession_CommitConfig(captureSession);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
      return ret;
    }

    // 启动会话。
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

- 在[会话管理(C/C++)](native-camera-session-management.md)流程中的使能步骤中的[OH_CaptureSession_CommitConfig()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig)之前调用。 

  ```c++
  Camera_ErrorCode StartSession(Camera_CaptureSession* captureSession, Camera_Input* cameraInput,
    Camera_PreviewOutput* previewOutput, Camera_PhotoOutput* photoOutput)
  {
    // 向会话中添加相机输入流。
    Camera_ErrorCode ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
      return ret;
    }

    // 向会话中添加预览输出流。
    ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
      return ret;
    }

    // 向会话中添加拍照输出流。
    ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
      return ret;
    }

    SetHighQualityPhotoQualityPrioritization(photoOutput);
    
    // 提交会话配置。
    ret = OH_CaptureSession_CommitConfig(captureSession);
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
      return ret;
    }

    // 启动会话。
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

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的onFrameStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，拍照第一次曝光时触发。

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

- 通过注册固定的onFrameEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听。

  <!-- @[photo_output_end_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKPhotoVideoSample/entry/src/main/cpp/camera_manager.cpp) -->
  
  ``` C++
  void PhotoOutputOnFrameEnd(Camera_PhotoOutput *photoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
  }
  ```

- 通过注册固定的onError回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode)。

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
