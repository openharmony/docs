# Using Image_NativeModule to Encode Pictures

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:44:59.546Z pushedAt=2026-08-11T07:23:11.034Z -->

With Image_NativeModule, you can create and release ImagePacker instances and encode picture objects.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_packer.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libimage_packer.so libpixelmap.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Encoding APIs**

> **NOTE**
>
> According to the MIME protocol, the standard encoding format is image/jpeg. When the APIs provided by the image module are used for encoding, **image_MimeType** of the encoding parameters must be set to **image/jpeg**. The file name extension of the encoded image file can be .jpg or .jpeg, and the file can be used on platforms that support image/jpeg decoding.
>
> Certain APIs are supported only in API version 20 or later. You should select an appropriate API version during development.

1. Import the required header files.

   <!-- @[decodingPicture_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadPicture.cpp) -->     

   ``` C++
   #include <hilog/log.h>
   #include <multimedia/image_framework/image/image_native.h>
   #include <multimedia/image_framework/image/image_packer_native.h>
   #include <multimedia/image_framework/image/image_source_native.h>
   #include <multimedia/image_framework/image/picture_native.h>
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

3. Define constants used for image processing.

   <!-- @[define_const](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadPicture.cpp) -->      

   ``` C++
   #define AUTO 0
   #define SDR 1
   const int MAX_SIZE = 1024;
   const int MAX_FORMAT_LENGTH = 20;
   ```

4. Define the ImagePictureNative class.

   <!-- @[define_pictureClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/imageKits.h) -->   

   ``` C
   class ImagePictureNative {
   public:
       Image_ErrorCode errorCode = IMAGE_SUCCESS;
       OH_DecodingOptionsForPicture *options = nullptr;
       OH_ImagePackerNative *imagePacker = nullptr;
       OH_PackingOptions *packerOptions = nullptr;
       OH_PictureNative *picture = nullptr;
       OH_ImageSourceNative *source = nullptr;
       ImagePictureNative() {}
       ~ImagePictureNative() {}
   };
   ```

5. Create an instance of ImagePictureNative.

   <!-- @[create_pictureClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadPicture.cpp) -->   

   ``` C++
   static ImagePictureNative *g_thisPicture = new ImagePictureNative();
   ```

6. Create the **GetJsResult** function to process the NAPI return value.

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

7. After an ImagePacker instance is created and encoding parameters are specified, the Picture object is encoded to a file or buffer.

   <!-- @[pack_picture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadPicture.cpp) -->    

   ``` C++
   // Set packing parameters.
   void SetPackOptions(OH_PackingOptions *packerOptions,
                       Image_MimeType format,
                       uint32_t quality,
                       bool needsPackProperties,
                       int32_t desiredDynamicRange)
   {
       OH_PackingOptions_SetMimeType(packerOptions, &format);
       OH_PackingOptions_SetQuality(packerOptions, quality);
       OH_PackingOptions_SetNeedsPackProperties(packerOptions, needsPackProperties);
       OH_PackingOptions_SetDesiredDynamicRange(packerOptions, desiredDynamicRange);
   }
   
   // PackToData.
   napi_value PackToDataFromPicture(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
       if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed!");
           return GetJsResult(env, g_thisPicture->errorCode);
       }
       
       size_t outDataSize = 10000 * 10000;
       uint8_t *outData = new uint8_t[outDataSize];
   
       if (g_thisPicture->packerOptions == nullptr) {
           g_thisPicture->errorCode = OH_PackingOptions_Create(&g_thisPicture->packerOptions);
       }
       if (g_thisPicture->imagePacker == nullptr) {
           g_thisPicture->errorCode = OH_ImagePackerNative_Create(&g_thisPicture->imagePacker);
       }
       
       char strFormat[MAX_FORMAT_LENGTH] = {0};
       size_t strFormatSize = 0;
       if (napi_get_value_string_utf8(env, args[0], strFormat, sizeof(strFormat), &strFormatSize) != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "PackToDataFromPicture napi_get_value_string_utf8 failed!");
           delete[] outData;
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
       strFormat[MAX_FORMAT_LENGTH - 1] = '\0';
       OH_LOG_DEBUG(LOG_APP, "PackToDataFromPicture format: %{public}s", strFormat);
   
       Image_MimeType format;
       format.size = strFormatSize;
       format.data = const_cast<char *>(strFormat);
       // Set the encoding quality. The default value of quality is 0, and a value no lower than 80 is recommended. In this example, it is set to 90 to balance image quality and file size.
       uint32_t quality = 90;
       bool needsPackProperties = true;
       int32_t desiredDynamicRange = AUTO;
       SetPackOptions(g_thisPicture->packerOptions, format, quality, needsPackProperties, desiredDynamicRange);
       // Ensure that the Picture object has been created.
       g_thisPicture->errorCode = OH_ImagePackerNative_PackToDataFromPicture(
           g_thisPicture->imagePacker, g_thisPicture->packerOptions, g_thisPicture->picture, outData, &outDataSize);
       
       // Release imagePacker and packerOptions.
       OH_PackingOptions_Release(g_thisPicture->packerOptions);
       g_thisPicture->packerOptions = nullptr;
       OH_ImagePackerNative_Release(g_thisPicture->imagePacker);
       g_thisPicture->imagePacker = nullptr;
       
       if (g_thisPicture->errorCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImagePackerNative_PackToDataFromPicture failed, errCode: %{public}d.",
                        g_thisPicture->errorCode);
           delete[] outData;
           return GetJsResult(env, g_thisPicture->errorCode);
       } else {
           OH_LOG_DEBUG(LOG_APP, "OH_ImagePackerNative_PackToDataFromPicture success !");
       }
       delete[] outData;
       return GetJsResult(env, g_thisPicture->errorCode);
   }
   
   // PackToFile.
   napi_value PackToFileFromPicture(napi_env env, napi_callback_info info)
   {
       size_t argc = 2;
       napi_value args[2] = {nullptr};
       if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok) {
       OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed!");
           return GetJsResult(env, g_thisPicture->errorCode);
       }
       uint32_t fd = 0;
       napi_get_value_uint32(env, args[0], &fd);
   
       if (g_thisPicture->packerOptions == nullptr) {
           g_thisPicture->errorCode = OH_PackingOptions_Create(&g_thisPicture->packerOptions);
       }
       if (g_thisPicture->imagePacker == nullptr) {
           g_thisPicture->errorCode = OH_ImagePackerNative_Create(&g_thisPicture->imagePacker);
       }
       
       char strFormat[MAX_FORMAT_LENGTH] = {0};
       size_t strFormatSize = 0;
       if (napi_get_value_string_utf8(env, args[1], strFormat, sizeof(strFormat), &strFormatSize) != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "PackToFileFromPicture napi_get_value_string_utf8 failed!");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
       strFormat[MAX_FORMAT_LENGTH - 1] = '\0';
       OH_LOG_INFO(LOG_APP, "PackToFileFromPicture format: %{public}s", strFormat);
   
       Image_MimeType format;
       format.size = strFormatSize;
       format.data = const_cast<char *>(strFormat);
       // Set the encoding quality. The default value of quality is 0, and a value no lower than 80 is recommended. In this example, it is set to 90 to balance image quality and file size.
       uint32_t quality = 90;
       bool needsPackProperties = false;
       int32_t desiredDynamicRange = SDR;
       SetPackOptions(g_thisPicture->packerOptions, format, quality, needsPackProperties, desiredDynamicRange);
       // Ensure that the Picture object has been created.
       g_thisPicture->errorCode = OH_ImagePackerNative_PackToFileFromPicture(
           g_thisPicture->imagePacker, g_thisPicture->packerOptions, g_thisPicture->picture, fd);
       
       // Release imagePacker and packerOptions.
       OH_PackingOptions_Release(g_thisPicture->packerOptions);
       g_thisPicture->packerOptions = nullptr;
       OH_ImagePackerNative_Release(g_thisPicture->imagePacker);
       g_thisPicture->imagePacker = nullptr;
       
       if (g_thisPicture->errorCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImagePackerNative_PackToFileFromPicture failed,"
                        "errCode: %{public}d.", g_thisPicture->errorCode);
           return GetJsResult(env, g_thisPicture->errorCode);
       } else {
           OH_LOG_DEBUG(LOG_APP, "OH_ImagePackerNative_PackToFileFromPicture success !");
       }
   
       return GetJsResult(env, g_thisPicture->errorCode);
   }
   ```