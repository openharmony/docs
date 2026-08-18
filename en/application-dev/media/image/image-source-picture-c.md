# Using Image_NativeModule to Decode Pictures

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:47:41.897Z pushedAt=2026-08-11T09:03:25.344Z -->

You can create an **ImageSource** instance and decode a supported image file into a Picture object for HDR image display, auxiliary image processing, and other operations in an app or the system. Currently supported image file formats include JPEG and HEIF.

Picture is a multi-image object that contains a main image, auxiliary images, and metadata. The main image carries the primary image information, auxiliary images store additional information related to the main image (such as the HDR Gain Map, i.e., GAINMAP), and metadata holds other image-related information. Picture is suitable for scenarios such as HDR image processing and HEIF professional format decoding.

## Differences Between Picture and PixelMap

Picture and PixelMap are two different image decoding objects, each suitable for different scenarios.

| Object Type | Applicable Scenario | Feature |
|---|---|---|
| [PixelMap](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md) | Single-image display, basic image processing | Single pixel data, supporting image transformations (cropping, scaling, rotation, etc.) and PixelMap operations. |
| [Picture](../../reference/apis-image-kit/capi-image-nativemodule-oh-picturenative.md) | HDR images, HEIF professional format, auxiliary image processing | Contains main image + auxiliary images + metadata. You can extract the main image, gain map, or composite HDR image as a PixelMap for display or processing, and perform auxiliary image and metadata operations. |

> **Suggestion:**
> - Use PixelMap when you need to directly display a single image or perform image processing such as cropping, scaling, and rotation.
> - Use Picture when you need to process HDR images, obtain auxiliary images (such as GAINMAP), or manipulate image metadata. If you need to crop or scale the content of a Picture, you can extract a PixelMap first through APIs such as [OH_PictureNative_GetMainPixelmap()](../../reference/apis-image-kit/capi-picture-native-h.md#oh_picturenative_getmainpixelmap) and then process it.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_source.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Decoding APIs**

> **NOTE**
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

3. Define the ImagePictureNative class.

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

4. Create an ImagePictureNative instance.

   <!-- @[create_pictureClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadPicture.cpp) -->    

   ``` C++
   static ImagePictureNative *g_thisPicture = new ImagePictureNative();
   ```

5. Define the ImageAuxiliaryPictureNative class.

   <!-- @[define_auxPictureClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/imageKits.h) -->    

   ``` C
   class ImageAuxiliaryPictureNative {
   public:
       Image_ErrorCode errorCode = IMAGE_SUCCESS;
       Image_AuxiliaryPictureType type = AUXILIARY_PICTURE_TYPE_GAINMAP;
       OH_AuxiliaryPictureNative *auxiliaryPicture = nullptr;
       size_t buffSize = 640 * 480 * 4; // Size of the auxiliary picture (width * height * number of bytes per pixel).
       ImageAuxiliaryPictureNative() {}
       ~ImageAuxiliaryPictureNative() {}
   };
   ```

6. Create an ImageAuxiliaryPictureNative instance.

   <!-- @[create_auxPictureClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadPicture.cpp) -->    

   ``` C++
   static ImageAuxiliaryPictureNative *g_thisAuxiliaryPicture  = new ImageAuxiliaryPictureNative();
   ```

7. Create the **GetJsResult** function to process the NAPI return value.

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

8. Create and configure decoding options, and call the decoding API to decode the image and obtain an auxiliary image.

   During decoding, you can specify the types of auxiliary images to decode. Auxiliary images are not directly displayed as standalone images; instead, they participate in image processing as auxiliary data (such as HDR compositing and depth information extraction). Common auxiliary image types include:

   | Auxiliary Image Type | Description |
   |---|---|
   | GAINMAP | Gain map, used for high dynamic range rendering of HDR images. |
   | DEPTH_MAP | Depth map, storing pixel distance information for scenarios such as 3D reconstruction and background separation. |
   | UNREFOCUS_MAP | Unrefocused original image, used for portrait bokeh post-processing. |
   | LINEAR_MAP | Linear map, used for visual effect enhancement and color post-processing. |
   | FRAGMENT_MAP | Watermark crop map, used for scenarios such as watermark removal and original image restoration. |

   > **NOTE**
   >
   > Not all images contain auxiliary images. Before obtaining an auxiliary image, call the `OH_PictureNative_GetAuxiliaryPicture` API to attempt retrieval. For other auxiliary image types, see [Image_AuxiliaryPictureType](../../reference/apis-image-kit/capi-picture-native-h.md#image_auxiliarypicturetype).

   <!-- @[picture_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadPicture.cpp) -->      

   ``` C++
   // Release the image source.
   napi_value ReleasePictureSource(napi_env env, napi_callback_info info)
   {
       if (g_thisPicture->source != nullptr) {
           g_thisPicture->errorCode = OH_ImageSourceNative_Release(g_thisPicture->source);
           g_thisPicture->source = nullptr;
           return GetJsResult(env, g_thisPicture->errorCode);
       }
       
       if (g_thisPicture->picture != nullptr) {
           g_thisPicture->errorCode = OH_PictureNative_Release(g_thisPicture->picture);
           g_thisPicture->picture = nullptr;
           return GetJsResult(env, g_thisPicture->errorCode);
       }
       
       OH_LOG_DEBUG(LOG_APP, "ReleasePictureSource source is null !");
       return GetJsResult(env, g_thisPicture->errorCode);
   }
   
   // Create decoding parameters.
   napi_value CreateDecodingOptions(napi_env env, napi_callback_info info)
   {
       g_thisPicture->errorCode = OH_DecodingOptionsForPicture_Create(&g_thisPicture->options);
   
       if (g_thisPicture->errorCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_DecodingOptionsForPicture_Create failed, errCode: %{public}d.",
                        g_thisPicture->errorCode);
           return GetJsResult(env, g_thisPicture->errorCode);
       } else {
           OH_LOG_DEBUG(LOG_APP, "OH_DecodingOptionsForPicture_Create success !");
       }
   
       return GetJsResult(env, g_thisPicture->errorCode);
   }
   
   // Configure decoding parameters, which are passed from the application layer.
   napi_value SetDesiredAuxiliaryPictures(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
       if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok || argc < 1 || args[0] == nullptr) {
           OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed !");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       uint32_t length = 0;
       napi_get_array_length(env, args[0], &length);
       if (length <= 0) {
           OH_LOG_INFO(LOG_APP, "Desired auxiliary picture type list is empty.");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
       Image_AuxiliaryPictureType typeList[length];
       for (int index = 0; index < length; index++) {
           napi_value element;
           uint32_t ulType = 0;
           napi_get_element(env, args[0], index, &element);
           napi_get_value_uint32(env, element, &ulType);
           typeList[index] = static_cast<Image_AuxiliaryPictureType>(ulType);
           OH_LOG_DEBUG(LOG_APP, "ulType is :%{public}d", ulType);
       }
       
       // Call OH_DecodingOptionsForPicture_Create to create DecodingOptions.
       CreateDecodingOptions(env, info);
       g_thisPicture->errorCode =
           OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(g_thisPicture->options, typeList, length);
       if (g_thisPicture->errorCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures failed,errCode: %{public}d.",
                        g_thisPicture->errorCode);
           return GetJsResult(env, g_thisPicture->errorCode);
       } else {
           OH_LOG_DEBUG(LOG_APP, "OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures success !");
       }
   
       return GetJsResult(env, g_thisPicture->errorCode);
   }
   
   // Decode data.
   napi_value CreatePictureByImageSource(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value args[1] = {nullptr};
   
       if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok || argc < 1 || args[0] == nullptr) {
           OH_LOG_ERROR(LOG_APP, "CreatePicture_ napi_get_cb_info failed !");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
       
       char filePath[MAX_SIZE] = {0};
       size_t pathSize = 0;
       if (napi_get_value_string_utf8(env, args[0], filePath, sizeof(filePath), &pathSize) != napi_ok) {
           OH_LOG_ERROR(LOG_APP, "CreatePictureByImageSource napi_get_value_string_utf8 failed !");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
       filePath[MAX_SIZE - 1] = '\0';
   
       g_thisPicture->errorCode = OH_ImageSourceNative_CreateFromUri(filePath, pathSize, &g_thisPicture->source);
       if (g_thisPicture->errorCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "OH_ImageSourceNative_CreateFromUri failed, errCode: %{public}d.",
                        g_thisPicture->errorCode);
           return GetJsResult(env, g_thisPicture->errorCode);
       } else {
           OH_LOG_DEBUG(LOG_APP, "OH_ImageSourceNative_CreateFromUri success !");
       }
       
       // Create decoding options and then decode the video. The API for creating the decoding options is implemented in SetDesiredAuxiliaryPictures.
       g_thisPicture->errorCode =
           OH_ImageSourceNative_CreatePicture(g_thisPicture->source, g_thisPicture->options, &g_thisPicture->picture);
       
       // Release the decoding options.
       OH_DecodingOptionsForPicture_Release(g_thisPicture->options);
       g_thisPicture->options = nullptr;
       
       g_thisAuxiliaryPicture ->errorCode = OH_PictureNative_GetAuxiliaryPicture(g_thisPicture->picture,
           g_thisAuxiliaryPicture ->type, &g_thisAuxiliaryPicture ->auxiliaryPicture);
       if (g_thisAuxiliaryPicture ->errorCode == IMAGE_SUCCESS) {
           uint8_t* buff = new uint8_t[g_thisAuxiliaryPicture ->buffSize];
           Image_ErrorCode readCode = OH_AuxiliaryPictureNative_ReadPixels(g_thisAuxiliaryPicture ->auxiliaryPicture, buff,
               &g_thisAuxiliaryPicture ->buffSize);
           if (readCode != IMAGE_SUCCESS) {
               OH_LOG_ERROR(LOG_APP, "OH_AuxiliaryPictureNative_ReadPixels failed, errCode: %{public}d.", readCode);
           }
           OH_AuxiliaryPictureNative_Release(g_thisAuxiliaryPicture ->auxiliaryPicture);
           g_thisAuxiliaryPicture ->auxiliaryPicture = nullptr;
           delete []buff;
       }
       
       if (g_thisPicture->errorCode != IMAGE_SUCCESS) {
           OH_LOG_ERROR(LOG_APP, "ImageSourceNative_CreatePicture failed, errCode: %{public}d.",
                        g_thisPicture->errorCode);
           return GetJsResult(env, g_thisPicture->errorCode);
       } else {
           OH_LOG_DEBUG(LOG_APP, "ImageSourceNative_CreatePicture success !");
       }
       
       return GetJsResult(env, g_thisPicture->errorCode);
   }
   ```