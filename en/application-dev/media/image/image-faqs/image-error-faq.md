# Image Kit Exception Handling
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Image Kit provides both ArkTS APIs and C APIs. In special circumstances (such as invalid input parameters, insufficient memory, or functions unable to process requests), the system reports errors through exceptions (for ArkTS APIs) or error codes (for C APIs). You need to properly capture and handle these errors at the application level to prevent application crashes or undefined behavior. The [Image Error Codes](../../../reference/apis-image-kit/errorcode-image.md) topic provides corresponding error messages, possible causes, and handling procedure for Image Kit error codes. However, since some scenarios have more complex causes for errors, you need to further locate issues with logs. For example, 401 parameter error may be due to invalid function parameters or lack of specific file read/write permissions, causing the failure to access or modify image files. (Image Kit does not perceive permissions, which manifests as an abnormal parameter error for the input file.)

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
          OH_PixelmapNative_GetImageInfo(pixelmap, imageInfo);
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