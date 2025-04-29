# Image Decoding

Image decoding refers to the process of decoding an image in a supported format into a [PixelMap](image-overview.md) for image display or [processing](image-transformation.md). Currently, the following image formats are supported: JPEG, PNG, GIF, WebP, BMP, SVG, ICO, DNG, and HEIF (depending on the hardware).

## How to Develop

Read [Image](../../reference/apis-image-kit/js-apis-image.md) for APIs related to image decoding.

### Adding Dependencies

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libace_napi.z.so**, **libpixelmap_ndk.z.so**, **libimage_source_ndk.z.so**, **librawfile.z.so**, and **libhilog_ndk.z.so** (on which the native log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libpixelmap_ndk.z.so libimage_source_ndk.z.so librawfile.z.so)
```

### Adding API Mappings

Open the **src/main/cpp/hello.cpp** file, and add the mapping of the **getSyncPixelMap** function to the **Init** function. The **getSyncPixelMap** function is used to generate a PixelMap in synchronous mode. The code is as follows:

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

### Calling APIs on the JS Side

1. Open **src\main\cpp\types\*libentry*\index.d.ts** (where **libentry** varies according to the project name), and import the following files:

    ```js
    import { image } from '@kit.ImageKit';
    import { resourceManager } from '@kit.LocalizationKit';

    // Synchronous call. The input parameters are the resource manager and image resource name, and a PixelMap is returned.
    export const getSyncPixelMap: (resMgr: resourceManager.ResourceManager, src: string) => image.PixelMap;
    ```

2. Prepare an image resource file, named **example.jpg** in this example, and import it to **src\main\resources\rawfile\**.

3. Open **src\main\ets\pages\index.ets**, import ***libentry*.so** (where **libentry** varies according to the project name), call the native APIs, and pass in the JS resource object. The following is an example:

    ```js
    import testNapi from 'libentry.so'
    import { image } from '@kit.ImageKit';

    @Entry
    @Component
    struct Index {
      @State pixelMap : PixelMap | undefined = undefined;
      aboutToAppear() {
         // Call the custom getSyncPixelMap function to obtain a PixelMap.
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

### Calling the Native APIs

For details about the APIs, see [Image](../../reference/apis-image-kit/image.md).

Obtain the JS resource object from the **hello.cpp** file and convert it to a native resource object. Then you can call native APIs.

**Adding Reference Files**

   ```c++
      // Include the image framework, raw file, raw file management, and log print header files.
      #include <cstdlib>
      #include <cstring>
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

         // The input parameter args[0] indicates the resource manager, which is used to initialize the resource manager at the native layer.
         NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, args[0]);
         
         size_t strSize;
         char srcBuf[2048];
         // The input parameter args[1] indicates the file name.
         napi_get_value_string_utf8(env, args[1], srcBuf, sizeof(srcBuf), &strSize);

         // Use the resource manager to open the raw file.
         RawFile * rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, srcBuf);
         if (rawFile != NULL) {
            // Obtain the file size and read data.
            long len = OH_ResourceManager_GetRawFileSize(rawFile);
            uint8_t * data = static_cast<uint8_t *>(malloc(len));
            int res = OH_ResourceManager_ReadRawFile(rawFile, data, len);

            OhosImageSource imageSource_c;
            imageSource_c.buffer = data;
            imageSource_c.bufferSize = len;

            OhosImageSourceOps ops{};
            napi_value imageSource;
            napi_value pixelMap;

            // Create an ImageSource object using the read raw data.
            int32_t ret = OH_ImageSource_Create(env, &imageSource_c, &ops, &imageSource);

            // Initialize the ImageSource object at the native layer.
            ImageSourceNative * imageSourceNative_c = OH_ImageSource_InitNative(env, imageSource);
            OhosImageDecodingOps decodingOps{};
            // Create a PixelMap.
            OH_ImageSource_CreatePixelMap(imageSourceNative_c, &decodingOps, &pixelMap);

            // The following APIs are used for the GIF format.
            // napi_value pixelMapList;
            // OH_ImageSource_CreatePixelMapList(imageSourceNative_c, &decodingOps, &pixelMapList);
            // OhosImageSourceDelayTimeList list{};
            // OH_ImageSource_GetDelayTime(imageSourceNative_c, &list);
            // uint32_t count;
            // OH_ImageSource_GetFrameCount(imageSourceNative_c, &count);

            OhosImageSourceInfo info{};
            // Read the image width and height.
            OH_ImageSource_GetImageInfo(imageSourceNative_c, 0, &info);
            OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[decode]", "imageInfo width:%{public}d , height:%{public}d", info.size.width, info.size.height);
            
            // Read the ImageWidth configuration of the image source and print logs.
            OhosImageSourceProperty target;
            char exifKey_c[] = "ImageWidth";
            target.size = strlen(exifKey_c);
            target.value = exifKey_c;

            OhosImageSourceProperty response{};
            response.size = 20;
            response.value = static_cast<char *>(malloc(20));
            OH_ImageSource_GetImageProperty(imageSourceNative_c, &target, &response);
            OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, "[decode]", "ImageProperty width after modify:%{public}s", response.value);

            // After the processing is complete, release resources at the native layer.
            OH_ImageSource_Release(imageSourceNative_c);
            OH_ResourceManager_CloseRawFile(rawFile);
            return pixelMap;
         }
         OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
         return nullptr;
      }
   ```

The image framework supports incremental decoding. The method is as follows:

   ```c++
      // Include the image framework, raw file, raw file management, and log print header files.
      #include <cstdlib>
      #include <cstring>
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

         // The input parameter args[0] indicates the resource manager, which is used to initialize the resource manager at the native layer.
         NativeResourceManager * mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, args[0]);
         
         size_t strSize;
         char srcBuf[2048];
         // The input parameter args[1] indicates the file name.
         napi_get_value_string_utf8(env, args[1], srcBuf, sizeof(srcBuf), &strSize);

         // Use the resource manager to open the raw file.
         RawFile * rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, srcBuf);
         if (rawFile != NULL) {
            // Obtain the file size. If the file size is greater than 2048 bytes, incremental decoding is performed. Otherwise, full decoding is performed.
            long len = OH_ResourceManager_GetRawFileSize(rawFile);
            if (len > 2048) {
               uint8_t * data = static_cast<uint8_t *>(malloc(len));
               // Read all data in the file.
               int res = OH_ResourceManager_ReadRawFile(rawFile, data, len);
               
               uint8_t * holderdata = static_cast<uint8_t *>(malloc(len));

               OhosImageSource imageSource_c;
               // A buffer of imageSource_c is allocated, but no data is filled in.
               imageSource_c.buffer = holderdata;
               imageSource_c.bufferSize = len;
               OhosImageSourceOps ops{};
               napi_value imageSource;
               // Initialize the incremental ImageSource object.
               OH_ImageSource_CreateIncremental(env, &imageSource_c, &ops, &imageSource);

               // Initialize the ImageSource object at the native layer.
               ImageSourceNative * imageSourceNative_c = OH_ImageSource_InitNative(env, imageSource);

               // The following simulates segment loading. Segments are loaded twice. 2048 bytes of data are loaded for the first time, and the remaining data is loaded for the second time.
               OhosImageSourceUpdateData firstData{};
               firstData.buffer = data; // Image data.
               firstData.bufferSize = len; // Total size of the image data.
               firstData.isCompleted = false;
               firstData.offset = 0; // The first loading starts from the very beginning.
               firstData.updateLength = 2048; // 2048 bytes are loaded for the first time.
               OH_ImageSource_UpdateData(imageSourceNative_c, &firstData);

               OhosImageSourceUpdateData secondData{};
               secondData.buffer = data;
               secondData.bufferSize = len;
               secondData.isCompleted = true; // Last loading, to indicating that loading is complete.
               secondData.offset = 2048; // 2048 bytes of data have been loaded. Offset the data to load for the second time.
               secondData.updateLength = len - 2048; // Load the remaining data for the second time.
               OH_ImageSource_UpdateData(imageSourceNative_c, &secondData);

               napi_value pixelMap;
               OhosImageDecodingOps decodingOps{};
               decodingOps.index = 0;
               // Create a PixelMap.
               OH_ImageSource_CreatePixelMap(imageSourceNative_c, &decodingOps, &pixelMap);

               // After the processing is complete, release resources at the native layer.
               OH_ImageSource_Release(imageSourceNative_c);
               OH_ResourceManager_CloseRawFile(rawFile);
               return pixelMap;
            } 
            // Read all data in the raw file.
            uint8_t * data = static_cast<uint8_t *>(malloc(len));
            int res = OH_ResourceManager_ReadRawFile(rawFile, data, len);

            OhosImageSource imageSource_c;
            imageSource_c.buffer = data;
            imageSource_c.bufferSize = len;

            OhosImageSourceOps ops{};
            napi_value imageSource;
            napi_value pixelMap;

            // Create an ImageSource object using the read raw data.
            int32_t ret = OH_ImageSource_Create(env, &imageSource_c, &ops, &imageSource);

            // Initialize the ImageSource object at the native layer.
            ImageSourceNative * imageSourceNative_c = OH_ImageSource_InitNative(env, imageSource);
            OhosImageDecodingOps decodingOps{};

            // Create a PixelMap.
            OH_ImageSource_CreatePixelMap(imageSourceNative_c, &decodingOps, &pixelMap);

            // After the processing is complete, release resources at the native layer.
            OH_ImageSource_Release(imageSourceNative_c);
            OH_ResourceManager_CloseRawFile(rawFile);
            return pixelMap;
         }
         OH_ResourceManager_ReleaseNativeResourceManager(mNativeResMgr);
         return nullptr;
      }
   ```
