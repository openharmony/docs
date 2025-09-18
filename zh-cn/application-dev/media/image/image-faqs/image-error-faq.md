# Image Kit异常处理
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Image Kit提供**ArkTS接口**和**C接口**。在遇到特殊情况时（例如输入参数无效、内存不足或函数无法处理请求等），系统会通过异常（ArkTS）或错误码（C接口）来反馈错误。开发者需要在应用层合理捕获和处理这些错误，以避免应用崩溃或出现未定义行为。在[Image错误码](../../../reference/apis-image-kit/errorcode-image.md)中给出了Image Kit错误码对应的错误信息、可能原因、处理步骤。但由于部分场景引发错误的原因较为复杂，还需要开发者结合日志进一步定位。例如：401参数错误，可能是函数入参存在问题，也可能是由于缺少特定的文件读写权限导致无法访问或修改图片文件（Image Kit不感知权限，表现为传入文件异常的参数错误）。

## ArkTS接口异常处理

ArkTS接口调用时，如果传入的参数不符合要求，或者底层执行过程中出现不可恢复的错误，系统会返回或抛出[BusinessError](../../../reference/apis-basic-services-kit/js-apis-base.md#businesserror)异常，又或者在异步场景中返回一个[Promise](../../../arkts-utils/async-concurrency-overview.md#promise)的rejected状态。如果开发者忽略了异常处理，可能会出现功能问题或数据丢失，甚至直接导致应用崩溃。

典型的ArkTS接口形态及API示例和处理方法如下所示。

| 接口形态          | 示例API                                                                                                       | 处理方式                                    |
| ------------- | ---------------------------------------------------------------------------------------------------------------- | ------------------------------------------ |
| **Promise异步接口** | `getImageInfo(): Promise<ImageInfo>`、`modifyImageProperty(key: PropertyKey, value: string): Promise<void>` | 使用`await`+`try/catch`，或`promise.catch`捕获`BusinessError`。|
| **AsyncCallback异步接口**       | `getImageInfo(callback: AsyncCallback<ImageInfo>): void`                                        | 使用回调函数[AsyncCallback](../../../reference/apis-basic-services-kit/js-apis-base.md#asynccallback)的参数获取`BusinessError`。             |
| **同步接口**       | `getImageInfoSync(): ImageInfo`                                                                              | 使用`try/catch`捕获同步`BusinessError`。    |

1. AsyncCallback异步接口示例。

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

2. Promise异步接口示例。

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

3. 同步型示例。

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

## C接口异常处理

C接口统一通过[Image错误码](../../../reference/apis-image-kit/errorcode-image.md)来表示函数执行结果。返回IMAGE_SUCCESS（0）表示执行成功，返回非零值表示发生错误。开发者应在调用后立即检查返回值，并进行必要的错误处理，如日志记录、资源释放等。C接口异常处理的典型示例如下所示。

1. 通过ImageInfo获取图像信息。

`Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)`

   ```cpp
   // 需要在src/main/cpp/CMakeLists.txt文件中链接so库文件：target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)。
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

       // 获取图片的宽、高、像素格式和透明度等信息。
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

2. 修改EXIF信息。

`Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)`

   ```cpp
   // 需要在src/main/cpp/CMakeLists.txt文件中链接so库文件：target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so)。
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
