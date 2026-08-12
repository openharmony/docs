# Using Image_NativeModule to Decode Images

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:47:35.545Z pushedAt=2026-08-11T08:46:55.196Z -->

This topic describes how to create an ImageSource object, obtain the width and height of the PixelMap, and release the ImageSource object.

Starting from API version 22, thumbnail decoding is provided for images in various professional camera formats. The formats supported are CR2, CR3, ARW, NEF, RAF, NRW, ORF, RW2, PEF, and SRW.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_source.so**, **libpixelmap.so**, and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libpixelmap.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Decoding APIs**

> **NOTE**
>
> Some APIs (such as [OH_ImageSourceNative_GetSupportedFormats](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_getsupportedformats)) are supported only from API version 20. You need to select an appropriate API version during development.

1. Import the required header files.

   <!-- @[decodingPixel_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->     

   ``` C++
   #include <string>
   #include <hilog/log.h>
   #include <multimedia/image_framework/image/image_source_native.h>
   #include "napi/native_api.h"
   #include <multimedia/image_framework/image/image_common.h>
   #include <multimedia/image_framework/image/pixelmap_native.h>
   ```

2. Modify the log macro definition as required.

   <!-- @[define_logInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->     

   ``` C++
   #undef LOG_DOMAIN
   #undef LOG_TAG
   #define LOG_DOMAIN 0x3200
   #define LOG_TAG "IMAGE_SAMPLE"
   ```

3. Define the ImageSourceNative class.

   <!-- @[define_sourceClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/imageKits.h) -->     

   ``` C
   class ImageSourceNative {
   public:
       OH_ImageSource_Info *imageInfo;
       OH_ImageSourceNative *source = nullptr;
       OH_PixelmapNative *resPixMap = nullptr;
       OH_Pixelmap_ImageInfo *pixelmapImageInfo = nullptr;
       uint32_t frameCnt = 0;
       ImageSourceNative() {}
       ~ImageSourceNative() {}
   };
   ```

4. Create an instance of ImageSourceNative.

   <!-- @[create_sourceClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->        

   ``` C++
   static ImageSourceNative *g_thisImageSource = new ImageSourceNative();
   ```

5. Create the **GetJsResult** function to process the NAPI return value.

   <!-- @[get_returnValue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/napi_init.cpp) -->       

   ``` C++
   // Process the NAPI return value.
   napi_value GetJsResult(napi_env env, int result)
   {
       napi_value resultNapi = nullptr;
       napi_create_int32(env, result, &resultNapi);
       return resultNapi;
   }
   ```

6. Define constants.

   <!-- @[define_maxStringLength](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->     

   ``` C++
   const int MAX_STRING_LENGTH = 1024;
   ```

7. Create an ImageSource instance.

   <!-- @[decodingPixel_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->     

   ``` C++
   // Return the error code.
   napi_value ReturnErrorCode(napi_env env, Image_ErrorCode errCode, std::string funcName)
   {
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "%{public}s failed, errCode: %{public}d.", funcName.c_str(), errCode);
           return GetJsResult(env, errCode);
       }
       return GetJsResult(env, errCode);
   }
   
   // Obtain the decoding capability range.
   napi_value GetSupportedFormats(napi_env env, napi_callback_info info)
   {
       Image_MimeType* mimeType = nullptr;
       size_t length = 0;
       Image_ErrorCode errCode = OH_ImageSourceNative_GetSupportedFormats(&mimeType, &length);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_GetSupportedFormats failed, "
                        "errCode: %{public}d.", errCode);
           return GetJsResult(env, errCode);
       }
       for (size_t count = 0; count < length; count++) {
           OH_LOG_INFO(LOG_APP, "Decode supportedFormats: %{public}s", mimeType[count].data);
       }
       return GetJsResult(env, errCode);
   }
   
   // Create an ImageSource instance.
   napi_value CreateImageSource(napi_env env, napi_callback_info info)
   {
       napi_value argValue[1] = {nullptr};
       size_t argCount = 1;
       if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < 1 ||
           argValue[0] == nullptr) {
           OH_LOG_ERROR(LOG_APP, "CreateImageSource napi_get_cb_info failed!");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       char name[MAX_STRING_LENGTH];
       size_t nameSize = MAX_STRING_LENGTH;
       napi_get_value_string_utf8(env, argValue[0], name, MAX_STRING_LENGTH, &nameSize);
   
       Image_ErrorCode errCode = OH_ImageSourceNative_CreateFromUri(name, nameSize, &g_thisImageSource->source);
       return ReturnErrorCode(env, errCode, "OH_ImageSourceNative_CreateFromUri");
   }
   ```

8. After creating an ImageSource instance, obtain and modify property values, create a PixelMap object by using decoding parameters, and obtain the number of image frames.

   - Create a PixelMap object.

     <!-- @[create_pixelMap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->    

     ``` C++
     // Create a PixelMap object based on image decoding parameters.
     napi_value CreatePixelMap(napi_env env, napi_callback_info info)
     {
         // nullptr cannot be passed in to ops. If ops does not need to be set, you do not need to create a PixelMap object.
         OH_DecodingOptions *ops = nullptr;
         OH_DecodingOptions_Create(&ops);
         // If **IMAGE_DYNAMIC_RANGE_AUTO** is passed in, the system decodes the image based on the image format and the device capabilities. If the image is HDR and the device supports HDR decoding, the image is decoded into an HDR PixelMap.
         OH_DecodingOptions_SetDesiredDynamicRange(ops, IMAGE_DYNAMIC_RANGE_AUTO);
         
         OH_PixelmapNative_Release(g_thisImageSource->resPixMap);
         g_thisImageSource->resPixMap = nullptr;
         
         Image_ErrorCode errCode = OH_ImageSourceNative_CreatePixelmap(g_thisImageSource->source,
                                                                       ops, &g_thisImageSource->resPixMap);
         OH_DecodingOptions_Release(ops);
         ops = nullptr;
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_CreatePixelmap failed, errCode: %{public}d.", errCode);
             return GetJsResult(env, errCode);
         }
     
         // Check whether the PixelMap is the HDR content.
         OH_PixelmapImageInfo_Create(&g_thisImageSource->pixelmapImageInfo);
         OH_PixelmapNative_GetImageInfo(g_thisImageSource->resPixMap, g_thisImageSource->pixelmapImageInfo);
         bool pixelmapIsHdr;
         OH_PixelmapImageInfo_GetDynamicRange(g_thisImageSource->pixelmapImageInfo, &pixelmapIsHdr);
         if (pixelmapIsHdr) {
             OH_LOG_INFO(LOG_APP, "The pixelMap's dynamicRange is HDR.");
         }
         OH_PixelmapImageInfo_Release(g_thisImageSource->pixelmapImageInfo);
         g_thisImageSource->pixelmapImageInfo = nullptr;
         return GetJsResult(env, errCode);
     }
     ```

   - Create a structure object that defines the image information and obtain the image information.

     <!-- @[get_imageInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->      

     ``` C++
     // Create a structure object that defines the image information and obtain the image information.
     napi_value GetImageInfo(napi_env env, napi_callback_info info)
     {
         OH_ImageSourceInfo_Create(&g_thisImageSource->imageInfo);
         Image_ErrorCode errCode = OH_ImageSourceNative_GetImageInfo(g_thisImageSource->source,
                                                                     0, g_thisImageSource->imageInfo);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "OH_ImageSourceInfo_Create failed, errCode: %{public}d.", errCode);
             return GetJsResult(env, errCode);
         }
         
         uint32_t width;
         uint32_t height;
         errCode = OH_ImageSourceInfo_GetWidth(g_thisImageSource->imageInfo, &width);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "OH_ImageSourceInfo_GetWidth failed, errCode: %{public}d.", errCode);
             OH_ImageSourceInfo_Release(g_thisImageSource->imageInfo);
             g_thisImageSource->imageInfo = nullptr;
             return GetJsResult(env, errCode);
         }
         errCode = OH_ImageSourceInfo_GetHeight(g_thisImageSource->imageInfo, &height);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "OH_ImageSourceInfo_GetHeight failed, errCode: %{public}d.", errCode);
             OH_ImageSourceInfo_Release(g_thisImageSource->imageInfo);
             g_thisImageSource->imageInfo = nullptr;
             return GetJsResult(env, errCode);
         }
         OH_LOG_INFO(LOG_APP, "OH_ImageSourceNative_GetImageInfo success,"
                    "width: %{public}d, height: %{public}d.", width, height);
         OH_ImageSourceInfo_Release(g_thisImageSource->imageInfo);
         g_thisImageSource->imageInfo = nullptr;
         return GetJsResult(env, width); // Return the width of the obtained info.
     }
     ```

   - Read and edit Exif data.

     <!-- @[editExif_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->      

     ``` C++
     // Obtain the value of a specified property.
     napi_value GetImageProperty(napi_env env, napi_callback_info info)
     {
         napi_value argValue[1] = {nullptr};
         size_t argCount = 1;
         if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < 1 ||
             argValue[0] == nullptr) {
             OH_LOG_ERROR(LOG_APP, "GetImageProperty napi_get_cb_info failed!");
             return GetJsResult(env, IMAGE_BAD_PARAMETER);
         }
         // Modify the values of the specified properties.
         char key[MAX_STRING_LENGTH] = {0};
         size_t keySize = 0;
         if (napi_get_value_string_utf8(env, argValue[0], key, sizeof(key), &keySize) != napi_ok) {
             OH_LOG_ERROR(LOG_APP, "GetImageProperty napi_get_value_string_utf8 failed!");
             return GetJsResult(env, IMAGE_BAD_PARAMETER);
         }
         key[MAX_STRING_LENGTH - 1] = '\0';
         Image_String getKey;
         getKey.data = key;
         getKey.size = keySize;
         Image_String getValue = {nullptr, 0};
         OH_LOG_INFO(LOG_APP, "OH_ImageSourceNative_GetImageProperty key: %{public}s.", getKey.data);
         Image_ErrorCode errCode = OH_ImageSourceNative_GetImagePropertyWithNull(g_thisImageSource->source,
                                                                                 &getKey, &getValue);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_GetImageProperty failed, errCode: %{public}d.", errCode);
             if (getValue.data != nullptr) {
                 free(getValue.data);
                 getValue.data = nullptr;
             }
             return GetJsResult(env, errCode);
         }
         napi_value resultNapi = nullptr;
         napi_create_string_utf8(env, getValue.data, getValue.size, &resultNapi);
         free(getValue.data);
         getValue.data = nullptr;
         return resultNapi;
     }
     
     // Modify the value of a specified property.
     napi_value ModifyImageProperty(napi_env env, napi_callback_info info)
     {
         napi_value argValue[2] = {nullptr};
         size_t argCount = 2;
         const size_t minCount = 2;
         if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < minCount ||
             argValue[0] == nullptr || argValue[1] == nullptr) {
             OH_LOG_ERROR(LOG_APP, "ModifyImageProperty napi_get_cb_info failed!");
             return GetJsResult(env, IMAGE_BAD_PARAMETER);
         }
     
         // Obtain the key to be modified.
         char key[MAX_STRING_LENGTH] = {0};
         size_t keySize = 0;
         if (napi_get_value_string_utf8(env, argValue[0], key, sizeof(key), &keySize) != napi_ok) {
             OH_LOG_ERROR(LOG_APP, "ModifyImageProperty key napi_get_value_string_utf8 failed!");
             return GetJsResult(env, IMAGE_BAD_PARAMETER);
         }
         key[MAX_STRING_LENGTH - 1] = '\0';
         Image_String setKey;
         setKey.data = key;
         setKey.size = keySize;
         OH_LOG_INFO(LOG_APP, "ModifyImageProperty key: %{public}s.", setKey.data);
         
         // Obtain the value to be modified.
         char value[MAX_STRING_LENGTH] = {0};
         size_t valueSize = 0;
         if (napi_get_value_string_utf8(env, argValue[1], value, sizeof(value), &valueSize) != napi_ok) {
             OH_LOG_ERROR(LOG_APP, "ModifyImageProperty value napi_get_value_string_utf8 failed!");
             return GetJsResult(env, IMAGE_BAD_PARAMETER);
         }
         value[MAX_STRING_LENGTH - 1] = '\0';
         Image_String setValue;
         setValue.data = value;
         setValue.size = valueSize;
         OH_LOG_INFO(LOG_APP, "ModifyImageProperty value: %{public}s.", setValue.data);
     
         Image_ErrorCode errCode = OH_ImageSourceNative_ModifyImageProperty(g_thisImageSource->source, &setKey, &setValue);
         return GetJsResult(env, errCode);
     }
     ```

   - Obtain the number of frames.

     <!-- @[get_frameCount](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->     

     ``` C++
     // Obtain the number of image frames.
     napi_value GetFrameCount(napi_env env, napi_callback_info info)
     {
         Image_ErrorCode errCode = OH_ImageSourceNative_GetFrameCount(g_thisImageSource->source,
                                                                      &g_thisImageSource->frameCnt);
         if (errCode != IMAGE_SUCCESS) {
             OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_GetFrameCount failed, errCode: %{public}d.", errCode);
             return GetJsResult(env, errCode);
         }
         return GetJsResult(env, g_thisImageSource->frameCnt); // Return the number of obtained image frames.
     }
     ```

   - Create a PixelMap list based on image decoding parameters.

     <!-- @[create_pixelmapList](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->             

     ``` C++
     // Create a PixelMap list based on image decoding parameters.
     napi_value CreatePixelmapList(napi_env env, napi_callback_info info)
     {
         OH_DecodingOptions *opts = nullptr;
         OH_DecodingOptions_Create(&opts);
         OH_PixelmapNative** resVecPixMap = new OH_PixelmapNative* [g_thisImageSource->frameCnt]();
         size_t outSize = g_thisImageSource->frameCnt;
         Image_ErrorCode errCode = OH_ImageSourceNative_CreatePixelmapList(g_thisImageSource->source,
                                                                           opts, resVecPixMap, outSize);
         OH_DecodingOptions_Release(opts);
         opts = nullptr;
         for (size_t index = 0; index < outSize; index++) {
             if (resVecPixMap[index] != nullptr) {
                 OH_PixelmapNative_Release(resVecPixMap[index]);
                 resVecPixMap[index] = nullptr;
             }
         }
         delete[] resVecPixMap;
         return ReturnErrorCode(env, errCode, "OH_ImageSourceNative_CreatePixelmapList");
     }
     ```

   - Obtain the image delay time list.

     <!-- @[get_delayTimeList](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->        

     ``` C++
     // Obtain the image delay time list.
     napi_value GetDelayTimeList(napi_env env, napi_callback_info info)
     {
         int32_t *delayTimeList = new int32_t[g_thisImageSource->frameCnt];
         size_t size = g_thisImageSource->frameCnt;
         OH_LOG_INFO(LOG_APP, "GetDelayTimeList size: %{public}zu.", size);
         Image_ErrorCode errCode = OH_ImageSourceNative_GetDelayTimeList(g_thisImageSource->source, delayTimeList, size);
         if (errCode == IMAGE_SUCCESS) {
             for (size_t index = 0; index < size; index++) {
                 OH_LOG_INFO(LOG_APP, "Frame %{public}zu delay time: %{public}d ms.", index, delayTimeList[index]);
             }
         }
         delete[] delayTimeList;
         delayTimeList = nullptr;
         return ReturnErrorCode(env, errCode, "OH_ImageSourceNative_GetDelayTimeList");
     }
     ```

9. Release the ImageSource instance.

   <!-- @[release_imageSource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->       

   ``` C++
   // Release the instance.
   napi_value ReleaseImageSource(napi_env env, napi_callback_info info)
   {
       Image_ErrorCode errCode = OH_ImageSourceNative_Release(g_thisImageSource->source);
       g_thisImageSource->source = nullptr;
       OH_PixelmapNative_Release(g_thisImageSource->resPixMap);
       g_thisImageSource->resPixMap = nullptr;
       return ReturnErrorCode(env, errCode, "OH_ImageSourceNative_Release");
   }
   ```

## Advanced Topics

- **Memory-optimized decoding**: Use DMA memory and YUV pixel format to reduce memory usage and improve decoding performance. For details, see [Image Decoding Memory Optimization (C/C++)](image-allocator-type-c.md).

- **Region decoding**: Decode a specified region of an image, suitable for partial viewing and crop preview of large images. For details, see [Image Region Decoding and Downsampling (C/C++)](image-region-and-downsampling-c.md).

- **Downsampling decoding**: Scale the image to the target size directly during decoding, avoiding the performance overhead of post-decode scaling. Suitable for thumbnail generation. For details, see [Image Region Decoding and Downsampling (C/C++)](image-region-and-downsampling-c.md).

- **Multi-image object decoding**: Decode a Picture object that contains a primary image and auxiliary images, suitable for HDR images and HEIF professional format processing. For details, see [Using Image_NativeModule to Decode Pictures](image-source-picture-c.md).