# Using Image_NativeModule to Encode Images

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:44:50.261Z pushedAt=2026-08-11T07:22:02.477Z -->

You can use the **ImagePacker** class to create and release ImagePacker instances.

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
> - According to the MIME standard, the standard encoding format is `image/jpeg`. When using image encoding, set the encoding format `image_MimeType` in the encoding parameters to `image/jpeg`. The file extension of the encoded image can be `.jpg` or `.jpeg`, and the file can be used on platforms that support `image/jpeg` decoding.
>
> - Some APIs (for example, [OH_ImagePackerNative_GetSupportedFormats](../../reference/apis-image-kit/capi-image-packer-native-h.md#oh_imagepackernative_getsupportedformats)) are supported only from API version 20 onward. You need to select an appropriate API version during development.

1. Import the required header files.

   <!-- @[packSource_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->     

   ``` C++
   #include <string>
   #include <hilog/log.h>
   #include <multimedia/image_framework/image/image_source_native.h>
   #include "napi/native_api.h"
   #include <multimedia/image_framework/image/image_common.h>
   #include <multimedia/image_framework/image/pixelmap_native.h>
   #include <set>
   #include <multimedia/image_framework/image/image_packer_native.h>
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

5. Define a global variable to record the encoding formats supported.

   <!-- @[packSource_supportedFormats](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->   

   ``` C++
   static std::set<std::string> g_encodeSupportedFormats;
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

7. After an ImagePacker instance is created and encoding parameters are specified, the ImageSource or PixelMap object is encoded to a file or buffer.

   <!-- @[pack_source](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->     

   ``` C++
   // Obtain the encoding capability range.
   Image_ErrorCode GetEncodeSupportedFormats()
   {
       Image_MimeType* mimeType = nullptr;
       size_t length = 0;
       Image_ErrorCode errCode = OH_ImagePackerNative_GetSupportedFormats(&mimeType, &length);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImagePackerNative_GetSupportedFormats failed,"
                                 "errCode: %{public}d.", errCode);
           return errCode;
       }
       for (size_t count = 0; count < length; count++) {
           if (mimeType[count].data != nullptr) {
               g_encodeSupportedFormats.insert(std::string(mimeType[count].data));
               OH_LOG_INFO(LOG_APP, "Encode supportedFormats: %{public}s", mimeType[count].data);
           }
       }
       return IMAGE_SUCCESS;
   }
   
   Image_MimeType GetMimeTypeIfEncodable(const char *format)
   {
       auto it = g_encodeSupportedFormats.find(format);
       if (it == g_encodeSupportedFormats.end()) {
           return {const_cast<char *>(""), 0};
       }
       return {const_cast<char *>(format), strlen(format)};
   }
   
   static Image_ErrorCode ReleaseImageSourcePackingResources(OH_ImagePackerNative *testPacker,
       OH_PackingOptions *option)
   {
       Image_ErrorCode errCode = OH_ImagePackerNative_Release(testPacker);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromImageSourceTest OH_ImagePackerNative_Release failed,"
                        "errCode: %{public}d.", errCode);
           OH_PackingOptions_Release(option);
           return errCode;
       }
       errCode = OH_PackingOptions_Release(option);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromImageSourceTest OH_PackingOptions_Release failed,"
                        "errCode: %{public}d.", errCode);
       }
       return errCode;
   }
   
   Image_ErrorCode packToFileFromImageSourceTest(int fd, OH_ImageSourceNative* imageSource)
   {
       // Create an ImagePacker instance.
       OH_ImagePackerNative *testPacker = nullptr;
       Image_ErrorCode errCode = OH_ImagePackerNative_Create(&testPacker);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromImageSourceTest OH_ImagePackerNative_Create failed,"
                                 "errCode: %{public}d.", errCode);
           return errCode;
       }
       // Obtain the encoding capability range.
       errCode = GetEncodeSupportedFormats();
       if (errCode != IMAGE_SUCCESS) {
           OH_ImagePackerNative_Release(testPacker);
           return errCode;
       }
       // Specify encoding parameters and encode the ImageSource into a file.
       OH_PackingOptions *option = nullptr;
       errCode = OH_PackingOptions_Create(&option);
       if (errCode != IMAGE_SUCCESS || option == nullptr) {
           OH_ImagePackerNative_Release(testPacker);
           return errCode == IMAGE_SUCCESS ? IMAGE_BAD_PARAMETER : errCode;
       }
       Image_MimeType image_MimeType = GetMimeTypeIfEncodable(MIME_TYPE_JPEG);
       if (image_MimeType.data == nullptr || image_MimeType.size == 0) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromImageSourceTest GetMimeTypeIfEncodable failed,"
                        "format can't support encode.");
           OH_PackingOptions_Release(option);
           OH_ImagePackerNative_Release(testPacker);
           return IMAGE_BAD_PARAMETER;
       }
       OH_PackingOptions_SetMimeType(option, &image_MimeType);
       // HDR encoding is possible only when the device supports HDR encoding, the image resource is an HDR image, and the format of the image resource is JPEG.
       OH_PackingOptions_SetDesiredDynamicRange(option, IMAGE_PACKER_DYNAMIC_RANGE_AUTO);
       // Set the encoding quality. The default value of quality is 0, and a value no lower than 80 is recommended. In this example, quality is set to 90 to balance image quality and file size.
       uint32_t quality = 90;
       OH_PackingOptions_SetQuality(option, quality);
       errCode = OH_ImagePackerNative_PackToFileFromImageSource(testPacker, option, imageSource, fd);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromImageSourceTest OH_ImagePackerNative_PackToFileFromImageSource failed,"
                                 "errCode: %{public}d.", errCode);
           OH_PackingOptions_Release(option);
           OH_ImagePackerNative_Release(testPacker);
           return errCode;
       }
       return ReleaseImageSourcePackingResources(testPacker, option);
   }
   
   Image_ErrorCode packToFileFromPixelmapTest(int fd, OH_PixelmapNative *pixelmap)
   {
       // Create an ImagePacker instance.
       OH_ImagePackerNative *testPacker = nullptr;
       Image_ErrorCode errCode = OH_ImagePackerNative_Create(&testPacker);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromPixelmapTest CreatePacker OH_ImagePackerNative_Create failed,"
                        "errCode: %{public}d.", errCode);
           return errCode;
       }
   
       // Specify encoding parameters and encode the PixelMap into a file.
       OH_PackingOptions *option = nullptr;
       errCode = OH_PackingOptions_Create(&option);
       if (errCode != IMAGE_SUCCESS || option == nullptr) {
           OH_ImagePackerNative_Release(testPacker);
           return errCode == IMAGE_SUCCESS ? IMAGE_BAD_PARAMETER : errCode;
       }
       char type[] = "image/jpeg";
       Image_MimeType image_MimeType = {type, strlen(type)};
       errCode = OH_PackingOptions_SetMimeType(option, &image_MimeType);
       if (errCode != IMAGE_SUCCESS) {
           OH_PackingOptions_Release(option);
           OH_ImagePackerNative_Release(testPacker);
           return errCode;
       }
       // Set the encoding quality. The default value of quality is 0, and a value no lower than 80 is recommended. In this example, quality is set to 90 to balance image quality and file size.
       uint32_t quality = 90;
       OH_PackingOptions_SetQuality(option, quality);
       errCode = OH_ImagePackerNative_PackToFileFromPixelmap(testPacker, option, pixelmap, fd);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromPixelmapTest OH_ImagePackerNative_PackToFileFromPixelmap failed,"
                                 "errCode: %{public}d.", errCode);
           OH_PackingOptions_Release(option);
           OH_ImagePackerNative_Release(testPacker);
           return errCode;
       }
   
       // Release the ImagePacker instance.
       errCode = OH_ImagePackerNative_Release(testPacker);
       testPacker = nullptr;
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromPixelmapTest ReleasePacker OH_ImagePackerNative_Release failed,"
                                 "errCode: %{public}d.", errCode);
           OH_PackingOptions_Release(option);
           return errCode;
       }
       
       // Release the PackingOptions instance.
       errCode = OH_PackingOptions_Release(option);
       option = nullptr;
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromPixelmapTest OH_PackingOptions_Release failed,"
                                 "errCode: %{public}d.", errCode);
           return errCode;
       }
       
       return IMAGE_SUCCESS;
   }
   
   napi_value PackToFileFromImageSourceTestJs(napi_env env, napi_callback_info info)
   {
       napi_value argv[1] = {0};
       size_t argc = 1;
       if (napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr) != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "PackToFileFromImageSourceTestJs napi_get_cb_info failed.");
           return nullptr;
       }
       
       int fd;
       napi_get_value_int32(env, argv[0], &fd);
       
       Image_ErrorCode errCode = packToFileFromImageSourceTest(fd, g_thisImageSource->source);
       if (errCode == IMAGE_SUCCESS) {
           OH_LOG_INFO(LOG_APP, "ImagePackerNativeCTest PackToFileFromImageSourceTestJs successfully.");
       }
       return GetJsResult(env, errCode);
   }
   
   napi_value PackToFileFromPixelmapTestJs(napi_env env, napi_callback_info info)
   {
       napi_value argv[1] = {0};
       size_t argc = 1;
       if (napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr) != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "PackToFileFromImageSourceTestJs napi_get_cb_info failed.");
           return nullptr;
       }
       
       int fd;
       napi_get_value_int32(env, argv[0], &fd);
       
       Image_ErrorCode errCode = packToFileFromPixelmapTest(fd, g_thisImageSource->resPixMap);
       if (errCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "packToFileFromPixelmapTest failed,"
                        "errCode: %{public}d.", errCode);
           return GetJsResult(env, errCode);
       } else {
           OH_LOG_INFO(LOG_APP, "PackToFileFromPixelmapTestJs successfully.");
       }
       return GetJsResult(env, errCode);
   }
   ```