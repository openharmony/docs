# 图片解码(C/C++)

图片解码指将所支持格式的存档图片解码成统一的[PixelMap](image-overview.md)，以便在应用或系统中进行图片显示或[图片处理](image-transformation.md)。当前支持的存档图片格式包括JPEG、PNG、GIF、WebP、BMP、SVG、ICO。

## 开发步骤

图片解码相关API的详细介绍请参见：[图片解码接口说明](../reference/apis/js-apis-image.md#imagesource)。

### 添加依赖

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添libpixelmap_ndk.z.so libimage_source_ndk.z.so librawfile.z.so 以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libpixelmap_ndk.z.so libimage_source_ndk.z.so librawfile.z.so)
```

**添加接口映射**

打开src/main/cpp/hello.cpp文件，在Init函数中添加接口映射如下：

```c++
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "getSyncPixelMap", nullptr, getSyncPixelMap, nullptr, nullptr, nullptr, napi_default, nullptr },
    };

    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

**JS侧调用**

1.  打开src\main\cpp\types\libentry\index.d.ts（其中libentry根据工程名生成），导入如下引用文件:
 
    ```js
    import image from '@ohos.multimedia.image'
    import resourceManager from '@ohos.resourceManager'

    export const getSyncPixelMap: (resMgr: resourceManager.ResourceManager, src: string) => image.PixelMap;
    ```
2. 准备图片资源文件,本示例文件名为example.jpg，导入到src\main\resources\rawfile\ 路径下。

3. 打开src\main\ets\pages\index.ets，导入"libentry.so（根据工程名生成）"，调用Native接口，传入JS的资源对象。示例如下:

    ```js
    import testNapi from 'libentry.so'
    import image from '@ohos.multimedia.image'

    @Entry
    @Component
    struct Index {
      @State pixelMap : PixelMap | undefined = undefined;
      aboutToAppear() {
         this.pixelMap = testNapi.getSyncPixelMap(getContext(this).resourceManager, "example.jpg")
      }

      build() {
         Row() {
            Column() {
            Image(this.pixelMap)
               .width(100)
               .height(100)
            }
            .width('100%')
         }
         .height('100%')
      }
   }
    ```


**Native接口调用**

具体接口说明请参考[API文档](../reference/native-apis/image.md)

在hello.cpp文件中获取JS的资源对象，并转为Native的资源对象，即可调用Native接口，调用方式示例代码如下：

**添加引用文件**

   ```c++
      #include <multimedia/image_framework/image_source_mdk.h>
      #include <multimedia/image_framework/image_pixel_map_mdk.h>
      #include <rawfile/raw_file.h>
      #include <rawfile/raw_file_manager.h>
      #include <hilog/log.h>
      
      static napi_value getSyncPixelMap(napi_env env, napi_callback_info info)
      {
         size_t argc = 2;
         napi_value args[2] = {nullptr};

         napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
         
         napi_valuetype srcType;
         napi_typeof(env, args[0], &srcType);

         NativeResourceManager * mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, args[0]);
         
         size_t strSize;
         char srcBuf[2048];
         napi_get_value_string_utf8(env, args[1], srcBuf, sizeof(srcBuf), &strSize);

         RawFile * rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, srcBuf);
         if (rawFile != NULL) {
            long len = OH_ResourceManager_GetRawFileSize(rawFile);
            uint8_t * data = static_cast<uint8_t *>(malloc(len));
            int res = OH_ResourceManager_ReadRawFile(rawFile, data, len);

            OhosImageSource imageSource_c;
            imageSource_c.buffer = data;
            imageSource_c.bufferSize = len;

            OhosImageSourceOps ops{};
            napi_value imageSource;
            napi_value pixelMap;

            int32_t ret = OH_ImageSource_Create(env, &imageSource_c, &ops, &imageSource);

            ImageSourceNative * imageSourceNative_c = OH_ImageSource_InitNative(env, imageSource);
            OhosImageDecodingOps decodingOps{};
            OH_ImageSource_CreatePixelMap(imageSourceNative_c, &decodingOps, &pixelMap);

            // 下列方法,为gif等动图格式提供。
            // napi_value pixelMapList;
            // OH_ImageSource_CreatePixelMapList(imageSourceNative_c, &decodingOps, &pixelMapList);
            // OhosImageSourceDelayTimeList list{};
            // OH_ImageSource_GetDelayTime(imageSourceNative_c, &list);
            // uint32_t count;
            // OH_ImageSource_GetFrameCount(imageSourceNative_c, &count);

            OhosImageSourceInfo info{};
            OH_ImageSource_GetImageInfo(imageSourceNative_c, 0, &info);
            OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[decode]", "imageInfo width:%{public}d , height:%{public}d", info.size.width, info.size.height);
            
            OhosImageSourceProperty target;
            char exifKey_c[] = "ImageWidth";
            target.size = strlen(exifKey_c);
            target.value = exifKey_c;

            OhosImageSourceProperty dstValue;
            char dstValue_c[] = "2000";
            dstValue.size = strlen(dstValue_c);
            dstValue.value = dstValue_c;
            OH_ImageSource_ModifyImageProperty(imageSourceNative_c, &target, &dstValue);

            OhosImageSourceProperty response{};
            response.size = 20;
            response.value = static_cast<char *>(malloc(20));
            OH_ImageSource_GetImageProperty(imageSourceNative_c, &target, &response);
            OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[decode]", "ImageProperty width after modify:%{public}s", response.value);

            OH_ImageSource_Release(imageSourceNative_c);
            OH_ResourceManager_CloseRawFile(rawFile);
            return pixelMap;
         }
         OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
         return nullptr;
      }
   ```

图片框架支持增量式解码，使用方法如下：
   ```c++
      #include <multimedia/image_framework/image_source_mdk.h>
      #include <multimedia/image_framework/image_pixel_map_mdk.h>
      #include <rawfile/raw_file.h>
      #include <rawfile/raw_file_manager.h>
      #include <hilog/log.h>
      
      static napi_value getSyncPixelMap(napi_env env, napi_callback_info info)
      {
         size_t argc = 2;
         napi_value args[2] = {nullptr};

         napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
         
         napi_valuetype srcType;
         napi_typeof(env, args[0], &srcType);

         NativeResourceManager * mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, args[0]);
         
         size_t strSize;
         char srcBuf[2048];
         napi_get_value_string_utf8(env, args[1], srcBuf, sizeof(srcBuf), &strSize);

         RawFile * rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, srcBuf);
         if (rawFile != NULL) {
            long len = OH_ResourceManager_GetRawFileSize(rawFile);
            if (len > 2048) {
               uint8_t * data = static_cast<uint8_t *>(malloc(len));
               int res = OH_ResourceManager_ReadRawFile(rawFile, data, len);
               
               uint8_t * holderdata = static_cast<uint8_t *>(malloc(len));

               OhosImageSource imageSource_c;
               imageSource_c.buffer = holderdata;
               imageSource_c.bufferSize = len;
               OhosImageSourceOps ops{};
               napi_value imageSource;
               OH_ImageSource_CreateIncremental(env, &imageSource_c, &ops, &imageSource);

               ImageSourceNative * imageSourceNative_c = OH_ImageSource_InitNative(env, imageSource);

               // 以下模拟分片加载场景。
               OhosImageSourceUpdateData firstData{};
               firstData.buffer = data;
               firstData.bufferSize = len;
               firstData.isCompleted = false;
               firstData.offset = 0;
               firstData.updateLength = 2048;
               OH_ImageSource_UpdateData(imageSourceNative_c, &firstData);

               OhosImageSourceUpdateData secondData{};
               secondData.buffer = data;
               secondData.bufferSize = len;
               secondData.isCompleted = true;
               secondData.offset = 2048;
               secondData.updateLength = len - 2048;
               OH_ImageSource_UpdateData(imageSourceNative_c, &secondData);

               napi_value pixelMap;
               OhosImageDecodingOps decodingOps{};
               decodingOps.index = 0;
               OH_ImageSource_CreatePixelMap(imageSourceNative_c, &decodingOps, &pixelMap);

               OH_ImageSource_Release(imageSourceNative_c);
               OH_ResourceManager_CloseRawFile(rawFile);
               return pixelMap;
            } 
            uint8_t * data = static_cast<uint8_t *>(malloc(len));
            int res = OH_ResourceManager_ReadRawFile(rawFile, data, len);

            OhosImageSource imageSource_c;
            imageSource_c.buffer = data;
            imageSource_c.bufferSize = len;

            OhosImageSourceOps ops{};
            napi_value imageSource;
            napi_value pixelMap;

            int32_t ret = OH_ImageSource_Create(env, &imageSource_c, &ops, &imageSource);

            ImageSourceNative * imageSourceNative_c = OH_ImageSource_InitNative(env, imageSource);
            OhosImageDecodingOps decodingOps{};
            OH_ImageSource_CreatePixelMap(imageSourceNative_c, &decodingOps, &pixelMap);

            OH_ImageSource_Release(imageSourceNative_c);
            OH_ResourceManager_CloseRawFile(rawFile);
            return pixelMap;
         }
         OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
         return nullptr;
      }
    ```