# 分段式拍照(C/C++)

分段式拍照是相机的最重要功能之一，相机输出低质量图用作快速显示，提升用户感知拍照速度，同时使用高质量图保证最后的成图质量达到系统相机的水平，既满足了后处理算法的需求，又不阻塞前台的拍照速度，构筑相机性能竞争力，提升了用户的体验。

- 在第一阶段，系统快速上报轻量处理的图片，轻量处理的图片比全质量图低，出图速度快。应用通过回调会收到一个PhotoAsset对象，通过该对象可调用媒体库接口，读取图片或落盘图片。
- 在第二阶段，相机框架会根据应用的请求图片诉求或者在系统闲时，进行图像增强处理得到全质量图，将处理好的图片传回给媒体库，替换轻量处理的图片。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/capi-oh-camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。

   ```c++
   // 导入NDK接口头文件。
   #include <cstdint>
   #include <cstdlib>
   #include <cstring>
   #include <string.h>
   #include <memory>
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

2. 在CMake脚本中链接相关动态库。

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

3. 相机初始化及拍照触发参考[拍照(C/C++)](./native-camera-shooting.md)。

4. 注册分段式（PhotoAssetAvailable）拍照回调，对比单端式拍照，仅注册的拍照回调接口不同。

   > **注意：**
   >
   > 如果已经注册了PhotoAssetAvailable回调，并且在Session开始之后又注册了PhotoAvailable回调，PhotoAssetAvailable和PhotoAvailable同时注册，会导致流被重启，仅PhotoAssetAvailable生效。
   >
   > 不建议开发者同时注册PhotoAssetAvailable和PhotoAvailable。

   注册PhotoAssetAvailableCallback回调，接收分段式拍照回图示例：

   **分段式拍照开发流程（PhotoAssetAvailableCallback）**：

   - 在会话commitConfig前注册分段式拍照回调。
   - 通过分段式拍照回调，获取媒体库资源mediaAsset。
   - 通过mediaAsset直接落盘图片或者通过mediaAsset配置策略模式请求图像资源，业务处理后通过buffer保存图片，或显示图片(参考[拍照(C/C++)](./native-camera-shooting.md)步骤5)。
   - 使用完后解注册分段式拍照回调函数。

   ```c++
   // 方式一：调用媒体库落盘图片。
   void mediaLibSavePhoto(OH_MediaAsset* mediaAsset) {
       if (mediaAsset == nullptr) {
           OH_LOG_ERROR(LOG_APP, "mediaAsset is nullptr!");
           return;
       }
       // 创建媒体资产更改请求对象。
       OH_MediaAssetChangeRequest* changeRequest = OH_MediaAssetChangeRequest_Create(mediaAsset);
       if (changeRequest == nullptr) {
           OH_LOG_ERROR(LOG_APP, "changeRequest is nullptr!");
           return;
       }
       // 请求保存图片。
       MediaLibrary_ErrorCode errCode =
           OH_MediaAssetChangeRequest_SaveCameraPhoto(changeRequest, MEDIA_LIBRARY_IMAGE_JPEG);
       OH_LOG_INFO(LOG_APP, "SaveCameraPhoto get errCode:%{public}d", errCode);
       // 发起请求。
       errCode = OH_MediaAccessHelper_ApplyChanges(changeRequest);
       OH_LOG_INFO(LOG_APP, "ApplyChanges get errCode:%{public}d", errCode);
   }
   
   // 方式二：调用媒体库接口请求图像资源。
   // 图像源准备就绪时调用。
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
       // 通过OH_ImageSourceNative创建OH_PixelmapNative。
       OH_PixelmapNative* pixelmapNative = nullptr;
       OH_DecodingOptions* decodingOptions = nullptr;
       Image_ErrorCode imageErr = IMAGE_SUCCESS;
       imageErr = OH_ImageSourceNative_CreatePixelmap(imageSourceNative, decodingOptions, &pixelmapNative);
       if (imageErr != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OnImageDataPrepared: CreatePixelmap failed.");
           return;
       }
       // 创建Image Packer并设置打包选项。
       OH_ImagePackerNative* imagePacker;
       OH_ImagePackerNative_Create(&imagePacker);
       OH_PackingOptions* options;
       OH_PackingOptions_Create(&options);
       char format[] = "image/jpeg";
       Image_MimeType image_MimeType = {format, strlen(format)};
       OH_PackingOptions_SetMimeType(options, &image_MimeType);
       OH_PackingOptions_SetQuality(options, 100); // 最高质量100。
       size_t bufferSize = 3072 * 4096; // 传大于编码后的size大小，编码后会重新赋值。
       // 解析出图片buffer。
       auto buffer = std::make_unique<uint8_t[]>(bufferSize);
       imageErr = OH_ImagePackerNative_PackToDataFromPixelmap(imagePacker, options, pixelmapNative, buffer.get(), &bufferSize);
       OH_LOG_INFO(LOG_APP, "OnImageDataPrepared: packToData ret code:%{public}u outsize:%{public}zu", imageErr, bufferSize);
       if (g_mediaAsset_ == nullptr) {
           OH_LOG_ERROR(LOG_APP,  "OnImageDataPrepared: get current mediaAsset failed!");
           return;
       }
       // 调用媒体库接口通过buffer存图。
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
       // 创建媒体资产管理器。
       OH_MediaAssetManager* mediaAssetManager = OH_MediaAssetManager_Create();
       if (mediaAssetManager == nullptr) {
           OH_LOG_ERROR(LOG_APP, "mediaAssetManager is nullptr!");
           return;
       }
       // 配置请求媒体图片参数。
       MediaLibrary_RequestOptions requestOptions;
       // 按照业务需求配置策略模式请求图像资源。
       // MEDIA_LIBRARY_FAST_MODE：仅接收一阶段低质量图回调。
       // MEDIA_LIBRARY_HIGH_QUALITY_MODE：仅接收二阶段全质量图回调。
       // MEDIA_LIBRARY_BALANCED_MODE：接收一阶段及二阶段图片回调。
       requestOptions.deliveryMode = MEDIA_LIBRARY_FAST_MODE;
       MediaLibrary_RequestId requestId;
       // 请求图像资源，图像源准备就绪时调用onImageDataPrepared。
       MediaLibrary_ErrorCode result = OH_MediaAssetManager_RequestImage(mediaAssetManager, mediaAsset, requestOptions, &requestId, OnImageDataPrepared);
       if (result != MEDIA_LIBRARY_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_MediaAssetManager_RequestImage failed.");
       }
   }
   
   // 分段式拍照回调函数。
   void OnPhotoAssetAvailable(Camera_PhotoOutput* photoOutput, OH_MediaAsset* mediaAsset) {
       OH_LOG_INFO(LOG_APP, "OnPhotoAssetAvailable start!");
       if (mediaAsset == nullptr) {
           OH_LOG_ERROR(LOG_APP, "OnPhotoAssetAvailable mediaAsset nullptr!");
           return;
       }
       // 处理方式一：调用媒体库接口落盘图片，先保存一阶段图，二阶段图就绪后媒体库会主动帮应用替换落盘图片。
       // mediaLibSavePhoto(mediaAsset);
       // 处理方式二：调用媒体库接口请求图像资源，获取一阶段图或二阶段图buffer，业务处理后通过buffer存图。
       g_mediaAsset_ = mediaAsset;
       mediaLibRequestBuffer(mediaAsset);
   }
   
   // 注册分段式拍照回调。
   Camera_ErrorCode PhotoOutputRegisterPhotoAssetAvailableCallback(Camera_PhotoOutput* photoOutput) {
       Camera_ErrorCode ret = OH_PhotoOutput_RegisterPhotoAssetAvailableCallback(photoOutput, OnPhotoAssetAvailable);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterPhotoAssetAvailableCallback failed.");
       }
       return ret;
   }
   ```

