# Using Image_NativeModule to Read and Edit Image Exif Data

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:48:19.733Z pushedAt=2026-08-11T09:47:41.998Z -->

Image Kit provides the capabilities of reading and editing Exchangeable Image File Format (Exif) data.

Exchangeable image file format (Exif) is a file format dedicated for photos taken by digital cameras and is used to record attributes and shooting data of the photos. The image must contain Exif data.

In Gallery, camera, image editing, and other apps, you can read Exif data such as shooting time, orientation, focal length, and geographic location, and modify part of the Exif data when needed. For example, when the manual lens parameters of the camera are not automatically written as part of the Exif data, or when the shooting time is incorrect due to a camera power failure, you can manually correct the corresponding Exif data.

Currently, the system allows you to read and modify only part of Exif data. For details about the supported scope, see the `OHOS_IMAGE_PROPERTY_XXX` types in [Variables](../../reference/apis-image-kit/capi-image-common-h.md#variables). The following table lists the read and write support for Exif data by image format.

| Image Format | Read Exif Information | Modify Exif Information |
| -------- | -------- | -------- |
| JPG/JPEG | Supported | Supported |
| PNG | Supported | Supported |
| HEIF | Supported | Supported |
| WebP<sup>23+</sup> | Supported | Supported |
| DNG<sup>23+</sup> | Supported | Not supported |

## Available APIs

The following table lists the C APIs for reading and editing Exif data. For details, see [image_source_native.h](../../reference/apis-image-kit/capi-image-source-native-h.md).

| API | Description |
| -------- | -------- |
| [OH_ImageSourceNative_GetImageProperty()](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty) | Obtains the Exif data of a specified property key. |
| [OH_ImageSourceNative_ModifyImageProperty()](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_modifyimageproperty) | Modifies the Exif data of a specified property key. |

## Precautions

- You must create an `OH_ImageSourceNative` object before reading or editing Exif data.

- Before reading the Exif data of an image, ensure that the app has the read permission on the target image. Before modifying the Exif data of an image, ensure that the app has the write permission on the target image.

- In certain image source or access scenarios, the system may remove privacy information such as GPS data even if the app has the image read permission. In this case, the corresponding Exif data cannot be obtained.

- The image file must contain Exif data. For images that do not contain Exif data or do not contain the target attribute key, the read result may be empty or an error code may be returned.

- Before modifying Exif data, confirm that the image format and the target attribute key support writing.

- Image metadata may contain privacy information such as shooting location. Before displaying, uploading, or sharing images, ensure that user authorization and privacy protection are properly handled based on the service scenario.

## How to Develop

### Adding a Link Library

Before developing an app, open the `src/main/cpp/CMakeLists.txt` file of the native project, and add `libimage_source.so` and `libhilog_ndk.z.so` (required for logging) to the `target_link_libraries` dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so)
```

### Calling the Native APIs

When creating a Native C++ app in DevEco Studio, the generated project includes an `index.ets` file by default, and a `cpp` file (`hello.cpp` or `napi_init.cpp`; this example uses `hello.cpp` as the file name) is automatically generated in the `entry/src/main/cpp` directory. Implement the C API call logic in `hello.cpp`. The sample code is as follows:

**Example for Reading and Editing Exif Data**

> **NOTE**
>
> Certain APIs are supported only in API version 20 or later. You should select an appropriate API version during development.

1. Import the required header files.

   <!-- @[editExif_operations_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->      

   ``` C++
   #include <string>
   #include <hilog/log.h>
   #include <multimedia/image_framework/image/image_source_native.h>
   #include "napi/native_api.h"
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

5. Create the GetJsResult function to process the NAPI return value.

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

6. After an ImageSource object is created, read and edit its Exif data.

   > **NOTE**
   >
   > For details about how to create an ImageSource object, see [Image Decoding](../image/image-source-c.md).

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
       // Modify the value of a specified property key.
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