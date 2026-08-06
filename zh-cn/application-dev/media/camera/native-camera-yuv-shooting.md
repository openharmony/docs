# YUV拍照(C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

从API version 23开始，相机框架提供YUV格式图片拍照能力。与普通拍照相比，YUV拍照获取到的是未经过编码的图像数据，完整保留了传感器捕获的原始亮度和色度信息，适用于视频编码或专业处理。同时，拍摄过程会产生更高的能耗开销，保存会占用更多的存储空间。

## 开发步骤

详细的相机功能API说明请参考Camera模块描述[OH_Camera](../../reference/apis-camera-kit/capi-oh-camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。

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

2. 在CMake脚本中链接相关动态库。

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

3. 创建并打开相机设备，参考[设备输入(C/C++)](./native-camera-device-input.md)中的步骤3-4。

4. 获取相机设备完整输出能力。

   通过[OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedfullcameraoutputcapabilitywithscenemode)方法，获取当前设备支持的所有输出流的能力，包含预览流、拍照流、录像流等。输出流在CameraOutputCapability中的各个profile字段中，其中拍照流支持YUV格式。根据相机设备指定模式[Camera_SceneMode](../../reference/apis-camera-kit/capi-camera-h.md#camera_scenemode)的不同，需要添加不同类型的输出流。

   <!-- @[get_full_outputCapability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->
   
   ``` C++
   Camera_OutputCapability* NDKCamera::GetSupportedFullCameraOutputCapability(Camera_Manager* cameraManager,
       Camera_Device &camera)
   {
       Camera_OutputCapability* cameraOutputCapability = nullptr;
       // 获取相机设备支持的输出流能力。
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

5. 选择设备支持的输出流能力，创建拍照输出流。

   通过[OH_CameraManager_CreatePhotoOutputWithoutSurface()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createphotooutputwithoutsurface)方法创建拍照输出流。

   可以通过[OH_CameraManager_GetSupportedFullCameraOutputCapabilityWithSceneMode()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedfullcameraoutputcapabilitywithscenemode)获取相机在指定模式下支持的完整输出能力cameraOutputCapability，参考步骤2。在cameraOutputCapability的photoProfiles中选择支持YUV格式的profile，作为创建拍照输出流的参数photoProfile。

   <!-- @[create_photo_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->
   
   ``` C++
   Camera_ErrorCode NDKCamera::CreatePhotoOutputWithoutSurfaceId()
   {
       DRAWING_LOGD("NDKCamera::CreatePhotoOutputWithoutSurfaceId into createWithoutSurfaceID branch!");
       OH_LOG_INFO(LOG_APP, "CreatePhotoOutputWithoutSurfaceId format: %{public}d!", cameraProfile_->format);
       OH_LOG_INFO(LOG_APP, "CreatePhotoOutputWithoutSurfaceId width: %{public}d!", cameraProfile_->size.width);
       OH_LOG_INFO(LOG_APP, "CreatePhotoOutputWithoutSurfaceId height: %{public}d!", cameraProfile_->size.height);
       // 无需传入surfaceId，直接创建拍照流。
       ret_ = OH_CameraManager_CreatePhotoOutputWithoutSurface(cameraManager_, cameraProfile_, &photoOutput_);
       if (photoOutput_ == nullptr || ret_ != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "CreatePhotoOutputWithoutSurfaceId failed.");
           return CAMERA_INVALID_ARGUMENT;
       }
       PhotoOutputRegisterCallback();
       return ret_;
   }
   ```

6. 注册单段式(PhotoAvailable)或分段式(PhotoAssetAvailable)拍照回调，若应用希望快速得到回图，推荐使用[分段式拍照(PhotoAssetAvailable)](./native-camera-deferred-capture.md)回调。

   > **注意：**
   >
   > 如果已经注册了PhotoAssetAvailable回调，并且在Session开始之后又注册了PhotoAvailable回调，PhotoAssetAvailable和PhotoAvailable同时注册会导致流被重启，仅PhotoAssetAvailable生效。

   - **单段式拍照（PhotoAvailable）开发流程**：

     - 在会话[OH_CaptureSession_CommitConfig](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig)前注册单段式拍照回调。
     - 在单段式拍照回调函数中获取图片信息，解析出pixelMap数据，做自定义业务处理。
     - 将处理完的pixelMap通过回调传给ArkTS侧，做图片显示或通过安全控件写文件保存图片。
     - 使用完后解注册单段式拍照回调函数。

     <!-- @[set_photo_single_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->
     
     ``` C++
     // 单段式拍照回调函数。
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
         // 读取OH_PictureNative中的主图mainPixelMap。
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
         // 获取主图Pixelmap中所有像素所占用的总字节数。
         imageErr = OH_PixelmapNative_GetByteCount(mainPixelmap, &byteCount);
         OH_LOG_INFO(LOG_APP, "OH_PixelmapNative_GetByteCount count:%{public}u", byteCount);
         // 获取主图的图像像素信息。
         OH_Pixelmap_ImageInfo* imageInfo;
         imageErr = OH_PixelmapNative_GetImageInfo(mainPixelmap, imageInfo);
         OH_LOG_INFO(LOG_APP, "OH_PixelmapNative_GetImageInfo errorCode:%{public}d", imageErr);
     
         uint32_t width;
         uint32_t height;
         uint32_t rowStride;
         int32_t pixelFormat = PIXEL_FORMAT::PIXEL_FORMAT_UNKNOWN;
         int32_t alphaMode = PIXELMAP_ALPHA_TYPE::PIXELMAP_ALPHA_TYPE_UNKNOWN;
         int32_t alphaType = PIXELMAP_ALPHA_TYPE::PIXELMAP_ALPHA_TYPE_UNKNOWN;
         // 获取主图图像像素信息中的宽度。
         OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
         // 获取主图图像像素信息中的高度。
         OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
         // 获取主图图像像素信息中的行跨距。
         OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
         // 获取主图图像像素信息中的像素格式。
         OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
         // 获取主图图像像素信息中的透明通道类型。
         OH_PixelmapImageInfo_GetAlphaMode(imageInfo, &alphaMode);
         // 获取主图图像像素信息中的默认的透明通道类型。
         OH_PixelmapImageInfo_GetAlphaType(imageInfo, &alphaType);
         OH_LOG_INFO(LOG_APP, "OH_PixelmapNative_GetImageInfo w: %{public}d, h: %{public}d,"
             "rowStride: %{public}d, pixelFormat: %{public}d, alphaMode: %{public}d, alphaType:"
             "%{public}d", width, height, rowStride, pixelFormat, alphaMode, alphaType);
        // 释放资源。
         OH_PictureNative_Release(picture);
     }
     
     // 注册单段式拍照回调。
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
     
     // 解注册单段式拍照回调。
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

   - **分段式拍照（PhotoAvailable）开发流程**：

     - 在会话[OH_CaptureSession_CommitConfig](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_commitconfig)前注册分段式拍照回调。
     - 在分段式拍照回调函数中获取图片信息，解析出pixelMap数据，做自定义业务处理。
     - 将处理完的pixelMap通过回调传给ArkTS侧，做图片显示或通过安全控件写文件保存图片。
     - 调用[OH_PhotoOutput_Capture](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_capture)拍照后，需要及时调用[OH_MediaAssetChangeRequest_SaveCameraPhoto](../../reference/apis-media-library-kit/capi-media-asset-change-request-capi-h.md#oh_mediaassetchangerequest_savecameraphoto)保存图片或[OH_MediaAssetChangeRequest_DiscardCameraPhoto](../../reference/apis-media-library-kit/capi-media-asset-change-request-capi-h.md#oh_mediaassetchangerequest_discardcameraphoto)取消保存图片，否则会影响后续图片的拍摄。
     - 使用完后解注册分段式拍照回调函数。

     <!-- @[set_photo_double_cb](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->
     
     ``` C++
     // 声明快速返图回调。
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
     
     // 分段式拍照回调函数。
     void OnPhotoAssetAvailable(Camera_PhotoOutput* photoOutput, OH_MediaAsset* mediaAsset)
     {
         OH_LOG_INFO(LOG_APP, "OnPhotoAssetAvailable start!");
         if (mediaAsset == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable invalid error, mediaAsset is null.");
             return;
         }
         // 尝试获取mediaAsset中的uri信息。
         NDKCamera::MediaAssetGetUri(mediaAsset);
         // 尝试获取mediaAsset中的displayName信息。
         NDKCamera::MediaAssetGetDisplayName(mediaAsset);
         // 创建媒体资产管理对象。
         OH_MediaAssetManager* mediaAssetManager = OH_MediaAssetManager_Create();
         if (mediaAssetManager == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to create mediaAssetManager.");
             return;
         }
     
         // 创建媒体资产变更请求。
         OH_MediaAssetChangeRequest* changeRequest = OH_MediaAssetChangeRequest_Create(mediaAsset);
         if (changeRequest == nullptr) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to create changeRequest.");
         }
         // 注册媒体资产快速请求回调。
         MediaLibrary_RequestOptions requestOptions;
         requestOptions.deliveryMode = MEDIA_LIBRARY_BALANCED_MODE;
         MediaLibrary_RequestId requestId;
         result = OH_MediaAssetManager_QuickRequestImage(mediaAssetManager, mediaAsset, requestOptions, &requestId,
             OnRequestQuickImageDataPreparedWithDetails);
         if (result != MEDIA_LIBRARY_OK) {
             OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable failed to quick image.");
         }
         // 创建媒体资产保存变更请求。
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
     
     // 注册分段式拍照回调函数。
     Camera_ErrorCode NDKCamera::RegisterPhotoAssetAvailable(Camera_PhotoOutput* photoOutput)
     {
         Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(photoOutput, OnPhotoAssetAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "RegisterPhotoAssetAvailable failed. %d ", ret);
         }
         return ret;
     }
     // 解注册分段式拍照回调函数。
     Camera_ErrorCode NDKCamera::UnregisterPhotoAssetAvailable(Camera_PhotoOutput* photoOutput)
     {
         Camera_ErrorCode ret = OH_PhotoOutput_UnregisterPhotoAssetAvailableCallback(photoOutput, OnPhotoAssetAvailable);
         if (ret != CAMERA_OK) {
             OH_LOG_ERROR(LOG_APP, "UnregisterPhotoAssetAvailable failed. %d ", ret);
         }
         return ret;
     }
     ```

7. 创建拍照类型会话（参考[会话管理(C/C++)](./native-camera-session-management.md)），开启会话，准备拍照。

8. 触发拍照。

   通过[OH_PhotoOutput_Capture()](../../reference/apis-camera-kit/capi-photo-output-h.md#oh_photooutput_capture)方法，执行拍照任务。

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

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍摄下一张图片是否就绪、拍照输出流的错误。

- 通过注册固定的onFrameStart回调函数获取监听拍照开始结果，当photoOutput创建成功时，即可监听。拍照第一次曝光时触发。

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

- 通过注册固定的onFrameEnd回调函数监听拍照结束结果，当photoOutput创建成功时，即可监听。
  
  <!-- @[photo_output_end_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->
  
  ``` C++
  void PhotoOutputOnFrameEnd(Camera_PhotoOutput *photoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
  }
  ```

- 通过注册固定的captureReady回调函数监听能否继续拍摄下一张的结果，当photoOutput创建成功时，即可监听。当下一张可拍时触发，该事件返回结果为下一张可拍的相关信息。

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

- 通过注册固定的onError回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode)。

  <!-- @[photo_output_error_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/NDKYUVPhotoSample/entry/src/main/cpp/camera_manager.cpp) -->
  
  ``` C++
  void PhotoOutputOnError(Camera_PhotoOutput *photoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
  }
  ```
