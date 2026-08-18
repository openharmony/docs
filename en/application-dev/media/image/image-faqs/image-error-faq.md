# Image Kit Exception Handling

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-11T10:27:39.839Z pushedAt=2026-08-11T11:32:27.839Z -->

[Image Kit](../image-overview.md) provides **ArkTS APIs** and **C APIs**. In special cases (such as invalid input parameters, insufficient memory, or the function being unable to process the request), the system reports errors through exceptions (ArkTS) or error codes (C APIs). You need to properly catch and handle these errors at the app layer to prevent app crashes or undefined behavior. [Image Error Codes](../../../reference/apis-image-kit/errorcode-image.md) lists the error messages, possible causes, and handling steps for Image Kit error codes. However, because the causes of errors in some scenarios are complex, you may need to further locate the issue by analyzing logs. For example, error code 401 (invalid parameter) may be caused by invalid function input parameters, or by the lack of specific file read/write permissions that prevents access to or modification of image files (Image Kit is not aware of permissions, so this manifests as an invalid parameter error for the file input).

## Handling ArkTS API Exceptions

When calling an ArkTS API, if the input parameters do not meet the requirements or unrecoverable errors occur during execution, the system returns or throws a [BusinessError](../../../reference/apis-basic-services-kit/js-apis-base.md#businesserror) exception, or returns a rejected [Promise](../../../arkts-utils/async-concurrency-overview.md#promise) in asynchronous scenarios. If you ignore exception handling, it may lead to functional issues, data loss, or even direct application crashes.

The following describes typical forms of ArkTS APIs, API examples, and handling methods.

| API Form         | Example API                                                                                                      | Handling Method                                   |
| ------------- | ---------------------------------------------------------------------------------------------------------------- | ------------------------------------------ |
| **Promise asynchronous APIs**| `getImageInfo(): Promise<ImageInfo>`, `modifyImageProperty(key: PropertyKey, value: string): Promise<void>` | Use await+try/catch or promise.catch to capture BusinessError exceptions.|
| **AsyncCallback asynchronous APIs**      | `getImageInfo(callback: AsyncCallback<ImageInfo>): void`                                        | Use parameters of the [AsyncCallback](../../../reference/apis-basic-services-kit/js-apis-base.md#asynccallback) callback function to capture BusinessError exceptions.            |
| **Synchronous APIs**      | `getImageInfoSync(): ImageInfo`                                                                              | Use try/catch to capture synchronous BusinessError exceptions.   |

1. Example of an AsyncCallback asynchronous API

   ```ts
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   function getImageInfoByCallback(pixelMap: image.PixelMap): void {
     if (!pixelMap) {
       console.error("pixelMap is null or undefined");
       return;
     }
     pixelMap.getImageInfo((err: BusinessError, info: image.ImageInfo) => {
       if (err) {
         console.error(`getImageInfo callback failed, code=${err.code}, msg=${err.message}`);
         return;
       }
       console.info(`Image width=${info.size.width}, height=${info.size.height}`);
     });
   }
   ```

2. Example of a Promise asynchronous API

   ```ts
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   // getImageInfo(): Promise<ImageInfo>
   async function getImageInfoByPromise(pixelMap: image.PixelMap): Promise<void> {
     try {
       const info = await pixelMap.getImageInfo();
       console.info(`Image width=${info.size.width}, height=${info.size.height}`);
     } catch (err) {
       const e = err as BusinessError;
       console.error(`getImageInfo promise failed, code=${e.code}, msg=${e.message}`);
     }
   }

   // modifyImageProperty(key: PropertyKey, value: string): Promise<void>
   function modifyImagePropertyPromise(imageSource: image.ImageSource): void {
     imageSource.modifyImageProperty(image.PropertyKey.ORIENTATION, 'Top-left').then(() => {
       console.info('modifyImageProperty success');
     }).catch((err: BusinessError) => {
       console.error(`modifyImageProperty failed, code=${err.code}, msg=${err.message}`);
     });
   }
   ```

3. Example of a synchronous API

   ```ts
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   function getImageInfoBySync(pixelMap: image.PixelMap): void {
     try {
       const info = pixelMap.getImageInfoSync();
       console.info(`Image width=${info.size.width}, height=${info.size.height}`);
     } catch (err) {
       const e = err as BusinessError;
       console.error(`getImageInfoSync failed, code=${e.code}, msg=${e.message}`);
     }
   }
   ```

## Handling C API Exceptions

The C APIs uniformly use [Image Error Codes](../../../reference/apis-image-kit/errorcode-image.md) to represent the execution results of functions. A return value of **IMAGE_SUCCESS (0)** indicates successful execution, whereas a non-zero value indicates an error. You should immediately check the return value after calling and perform necessary error handling, such as logging and resource release. A typical example of C API exception handling is as follows:

1. Obtain image information through ImageInfo.

   `Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)`

      ```cpp
      // Link the .so library file in the src/main/cpp/CMakeLists.txt file: target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so).
      #include <hilog/log.h>
      #include <multimedia/image_framework/image/pixelmap_native.h>
   
      #undef LOG_DOMAIN
      #undef LOG_TAG
      #define LOG_DOMAIN 0x02b6
      #define LOG_TAG "ImageKitDemo"
   
      void GetImageInfoExample(OH_PixelmapNative *pixelmap) {
          if (!pixelmap) {
              OH_LOG_ERROR(LOG_APP, "GetImageInfoExample: pixelmap is nullptr");
              return;
          }
          OH_Pixelmap_ImageInfo *imageInfo;
          Image_ErrorCode errCode = OH_PixelmapImageInfo_Create(&imageInfo);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Create failed, errCode: %{public}d.", errCode);
              return;
          }
       errCode = OH_PixelmapNative_GetImageInfo(pixelmap, imageInfo);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_GetImageInfo failed, errCode: %{public}d.", errCode);
              return;
          }
   
          // Obtain the width, height, pixel format, and alpha type of the image.
          uint32_t width, height, rowStride;
          int32_t pixelFormat, alphaType;
          OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
          OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
          OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
          OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
          OH_PixelmapImageInfo_GetAlphaType(imageInfo, &alphaType);
          OH_PixelmapImageInfo_Release(imageInfo);
          OH_LOG_INFO(LOG_APP,
                      "GetImageInfo success, width: %{public}d, height: %{public}d, "
                      "rowStride: %{public}d, pixelFormat: %{public}d, alphaType: %{public}d.",
                      width, height, rowStride, pixelFormat, alphaType);
      }
      ```

2. Modify the EXIF information.

   `Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)`

      ```cpp
      // Link the .so library file in the src/main/cpp/CMakeLists.txt file: target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so).
      #include <string>
      #include <hilog/log.h>
      #include <multimedia/image_framework/image/image_source_native.h>
   
      #undef LOG_DOMAIN
      #undef LOG_TAG
      #define LOG_DOMAIN 0x02b6
      #define LOG_TAG "ImageKitDemo"
   
      void ModifyImagePropertyExample(OH_ImageSourceNative *source) {
          if (!source) {
              OH_LOG_ERROR(LOG_APP, "ModifyImagePropertyExample: source is nullptr");
              return;
          }
          const std::string keyStr = OHOS_IMAGE_PROPERTY_ORIENTATION;
          const std::string valueStr = "Top-left";
          Image_String key{const_cast<char *>(keyStr.c_str()), keyStr.length()};
          Image_String value{const_cast<char *>(valueStr.c_str()), valueStr.length()};
   
          Image_ErrorCode ret = OH_ImageSourceNative_ModifyImageProperty(source, &key, &value);
          if (ret != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ModifyImageProperty failed, code=%{public}d", ret);
              return;
          }
   
          OH_LOG_INFO(LOG_APP, "ModifyImageProperty success, key=%{public}s, value=%{public}s", keyStr.c_str(),
                      valueStr.c_str());
      }
      ```