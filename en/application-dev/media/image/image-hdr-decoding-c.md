# Using Image_NativeModule to Decode HDR Images

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:44:23.057Z pushedAt=2026-08-11T10:24:47.111Z -->

You can use `Image_NativeModule` to decode HDR images, obtain the dynamic range information of the decoding result, and process HDR images, SDR images, and `Picture` objects with `GainMap` auxiliary images based on service requirements.

Compared with Standard Dynamic Range (SDR) images, High Dynamic Range (HDR) images can record richer luminance levels and color information. When an app decodes an HDR image, it needs to consider whether the image source contains HDR information, whether the device supports HDR decoding, whether the decoding result remains HDR, and whether subsequent display, editing, encoding, or sharing scenarios require falling back to SDR. Currently, the system supports only HDR images in JPEG and HEIF formats, and SDR processing is used by default when the API caller does not actively configure related parameters.

HDR image decoding mainly involves the following process:

1. Create an `ImageSource` instance.

2. Select a decoding path based on service requirements:

   - PixelMap path: Create decoding parameters, set the desired dynamic range, and call the decoding API to obtain PixelMap objects.

   - Picture path: Decode the image into a `Picture` object. Obtain the SDR base image and the `GainMap` image separately, and combine them to generate an HDR image as required.

3. If the `PixelMap` path is used, obtain the PixelMap image information and determine whether the decoding result is HDR.

4. If the `Picture` path is used, the following processing can be performed based on the service scenario:

   - Call [`OH_PictureNative_GetMainPixelmap()`](../../reference/apis-image-kit/capi-picture-native-h.md#oh_picturenative_getmainpixelmap) to obtain the SDR primary image.

   - Call [`OH_PictureNative_GetGainmapPixelmap`](../../reference/apis-image-kit/capi-picture-native-h.md#oh_picturenative_getgainmappixelmap) to obtain the `GainMap`.

   - Call [`OH_PictureNative_GetHdrComposedPixelmap`](../../reference/apis-image-kit/capi-picture-native-h.md#oh_picturenative_gethdrcomposedpixelmap) to compose the HDR image.

5. After use, release resources such as `ImageSource`, `PixelMap`, `Picture`, and decoding parameters.

## Basic Concepts

Before developing HDR images, you are advised to understand the following concepts.

| Concept | Description |
| --- | --- |
| SDR | Standard Dynamic Range image, suitable for normal display, editing, and sharing scenarios. |
| HDR | High Dynamic Range image, capable of expressing a wider brightness range and richer light and dark gradations. The display effect depends on the image data, device capability, and display pipeline. |
| Dynamic Range | Indicates the expression range of image brightness information. During decoding, you can specify the desired output as HDR or SDR through the dynamic range parameter. |
| GainMap | An HDR compatibility scheme in which the image contains an SDR primary image and an auxiliary image representing luminance gain information. Devices that support HDR can combine the primary image and GainMap to produce an HDR effect; devices that do not support HDR can use the SDR primary image for compatible display. |
| Picture | A multi-image object that can carry a primary image and auxiliary images. For images with a GainMap, you can use Picture-related APIs to obtain the auxiliary image or compose an HDR PixelMap. |

> **NOTE**
>
> The HDR decoding result is affected by factors such as image format, image metadata, device capability, decoding parameters, and memory type. When the source image is an HDR image, the decoding result may not always be HDR; when the device or parameters do not meet the conditions, the result may fall back to SDR.

## How to Develop

### Adding Libraries

Before starting app development, open the `src/main/cpp/CMakeLists.txt` file in the native project and add `libimage_source.so`, `libpixelmap.so`, `libpicture.so`, `libimage_packer.so`, and `libhilog_ndk.z.so` (required for logging) to the `target_link_libraries` dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libpixelmap.so libpicture.so libimage_packer.so)
```

### Calling Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

When creating a Native C++ app in DevEco Studio, the generated project includes an `index.ets` file by default, and a `cpp` file (`hello.cpp` or `napi_init.cpp`; this example uses `hello.cpp` as the file name) is automatically generated in the `entry\src\main\cpp` directory. Implement the C API call logic in `hello.cpp`. The sample code is as follows:

1. Include the relevant header files.

   <!-- @[hdrColorSpace_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

   ``` C++
   #include <cstring>
   #include <string>
   #include <hilog/log.h>
   #include <multimedia/image_framework/image/image_common.h>
   #include <multimedia/image_framework/image/image_source_native.h>
   #include <multimedia/image_framework/image/pixelmap_native.h>
   #include <multimedia/image_framework/image/picture_native.h>
   #include <multimedia/image_framework/image/image_packer_native.h>
   #include "napi/native_api.h"
   #include <imageKits.h>
   ```

2. For the log macro definition, refer to the following code and modify it as needed.

   <!-- @[define_logInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadImageSource.cpp) -->

   ``` C++
   #undef LOG_DOMAIN
   #undef LOG_TAG
   #define LOG_DOMAIN 0x3200
   #define LOG_TAG "IMAGE_SAMPLE"
   ```

3. Define a class related to HDR image decoding to store the `ImageSource`, `PixelMap`, `Picture`, and decoding result information.

   <!-- @[define_hdrColorSpaceClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/imageKits.h) -->

   ``` C
   class ImageHdrColorSpaceNative {
   public:
       OH_ImageSourceNative *source = nullptr;
       OH_PixelmapNative *pixelMap = nullptr;
       OH_PixelmapNative *mainPixelMap = nullptr;
       OH_PixelmapNative *gainmapPixelMap = nullptr;
       OH_PixelmapNative *hdrPixelMap = nullptr;
       OH_Pixelmap_ImageInfo *pixelMapImageInfo = nullptr;
       OH_PictureNative *picture = nullptr;
       bool isHdr = false;
       ImageHdrColorSpaceNative() {}
       ~ImageHdrColorSpaceNative() {}
   };
   ```

4. Create an `ImageHdrColorSpaceNative` instance.

   <!-- @[create_hdrColorSpaceClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

   ``` C++
   static ImageHdrColorSpaceNative *g_hdrColorSpace = new ImageHdrColorSpaceNative();
   ```

5. Create the `GetJsResult` function to process the NAPI return value.

   <!-- @[get_returnValue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Process the napi return value.
   napi_value GetJsResult(napi_env env, int result)
   {
       napi_value resultNapi = nullptr;
       napi_create_int32(env, result, &resultNapi);
       return resultNapi;
   }
   ```

6. Define constants.

   <!-- @[define_maxStringLength](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

   ``` C++
   const int MAX_STRING_LENGTH = 1024;
   ```

7. Create an `ImageSource` instance.

   `ImageSource` is used to manage image source data. Subsequent HDR decoding, `Picture` decoding, and image information retrieval are all performed based on `ImageSource`.

   <!-- @[hdrColorSpace_createImageSource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

   ``` C++
   napi_value CreateHdrImageSource(napi_env env, napi_callback_info info)
   {
       napi_value argValue[1] = {nullptr};
       size_t argCount = 1;
       if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok ||
           argCount < 1 || argValue[0] == nullptr) {
           OH_LOG_ERROR(LOG_APP, "CreateHdrImageSource napi_get_cb_info failed!");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       if (g_hdrColorSpace->source != nullptr) {
           ReleaseHdrColorSpaceSource(env, info);
       }
   
       char filePath[MAX_STRING_LENGTH];
       size_t pathSize = MAX_STRING_LENGTH;
       napi_get_value_string_utf8(env, argValue[0], filePath, MAX_STRING_LENGTH, &pathSize);
   
       Image_ErrorCode errCode = OH_ImageSourceNative_CreateFromUri(filePath, pathSize, &g_hdrColorSpace->source);
       return ReturnHdrErrorCode(env, errCode, "OH_ImageSourceNative_CreateFromUri");
   }
   ```

8. Set the dynamic range and decode the image to a `PixelMap`.

   Use `OH_DecodingOptions_SetDesiredDynamicRange` to set the desired decoding dynamic range. The following table lists common dynamic range strategies.

   | Dynamic Range Strategy | Description |
   | -------------------------- | -------------------------------------------------- |
   | `IMAGE_DYNAMIC_RANGE_AUTO` | Adaptive decoding based on the image source and device capability. When the source image is HDR and the device supports it, the decoding result may be HDR; otherwise, it may output SDR. |
   | `IMAGE_DYNAMIC_RANGE_HDR` | Desired output is HDR. The actual result is still affected by the image source, device capability, and decoding conditions. |
   | `IMAGE_DYNAMIC_RANGE_SDR` | Desired output is SDR, suitable for scenarios such as normal display, editing, sharing, or when compatibility is prioritized. |

   <!-- @[hdrColorSpace_decodePixelMap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

   ``` C++
   napi_value DecodeHdrPixelMap(napi_env env, napi_callback_info info)
   {
       if (g_hdrColorSpace->source == nullptr) {
           OH_LOG_ERROR(LOG_APP, "ImageSource is nullptr.");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       OH_DecodingOptions *opts = nullptr;
       Image_ErrorCode errCode = OH_DecodingOptions_Create(&opts);
       if (errCode != IMAGE_SUCCESS || opts == nullptr) {
           return ReturnHdrErrorCode(env, errCode, "OH_DecodingOptions_Create");
       }
   
       OH_DecodingOptions_SetDesiredDynamicRange(opts, IMAGE_DYNAMIC_RANGE_AUTO);
       ReleasePixelMap(&g_hdrColorSpace->pixelMap);
       errCode = OH_ImageSourceNative_CreatePixelmap(g_hdrColorSpace->source, opts, &g_hdrColorSpace->pixelMap);
   
       OH_DecodingOptions_Release(opts);
       opts = nullptr;
       return ReturnHdrErrorCode(env, errCode, "OH_ImageSourceNative_CreatePixelmap");
   }
   ```

9. Determine whether the `PixelMap` decoding result is HDR.

   After decoding is complete, you can obtain the `PixelMap` image information through `OH_PixelmapNative_GetImageInfo`, and then determine whether the decoding result is HDR through `OH_PixelmapImageInfo_GetDynamicRange`. This result indicates the dynamic range of the current `PixelMap`, and does not necessarily mean that the source image file is HDR or SDR.

   <!-- @[hdrColorSpace_checkDynamicRange](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

   ``` C++
   napi_value CheckHdrDynamicRange(napi_env env, napi_callback_info info)
   {
       if (g_hdrColorSpace->pixelMap == nullptr) {
           OH_LOG_ERROR(LOG_APP, "PixelMap is nullptr.");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       Image_ErrorCode errCode = OH_PixelmapImageInfo_Create(&g_hdrColorSpace->pixelMapImageInfo);
       if (errCode != IMAGE_SUCCESS || g_hdrColorSpace->pixelMapImageInfo == nullptr) {
           return ReturnHdrErrorCode(env, errCode, "OH_PixelmapImageInfo_Create");
       }
   
       errCode = OH_PixelmapNative_GetImageInfo(g_hdrColorSpace->pixelMap, g_hdrColorSpace->pixelMapImageInfo);
       if (errCode != IMAGE_SUCCESS) {
           OH_PixelmapImageInfo_Release(g_hdrColorSpace->pixelMapImageInfo);
           g_hdrColorSpace->pixelMapImageInfo = nullptr;
           return ReturnHdrErrorCode(env, errCode, "OH_PixelmapNative_GetImageInfo");
       }
   
       bool isHdr = false;
       errCode = OH_PixelmapImageInfo_GetDynamicRange(g_hdrColorSpace->pixelMapImageInfo, &isHdr);
       if (errCode == IMAGE_SUCCESS) {
           g_hdrColorSpace->isHdr = isHdr;
           OH_LOG_INFO(LOG_APP, "PixelMap dynamic range is %{public}s.", isHdr ? "HDR" : "SDR");
       }
   
       OH_PixelmapImageInfo_Release(g_hdrColorSpace->pixelMapImageInfo);
       g_hdrColorSpace->pixelMapImageInfo = nullptr;
       return ReturnHdrErrorCode(env, errCode, "OH_PixelmapImageInfo_GetDynamicRange");
   }
   ```

10. Decode an image in SDR mode.

    When the app needs to support scenarios such as standard display, editing, sharing, or environments that do not support HDR, the desired dynamic range can be set to `IMAGE_DYNAMIC_RANGE_SDR`. This mode can serve as a fallback when HDR decoding fails or the device does not support HDR.

    <!-- @[hdrColorSpace_decodeSdrPixelMap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

    ``` C++
    napi_value DecodeSdrPixelMap(napi_env env, napi_callback_info info)
    {
        if (g_hdrColorSpace->source == nullptr) {
            OH_LOG_ERROR(LOG_APP, "ImageSource is nullptr.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        OH_DecodingOptions *opts = nullptr;
        Image_ErrorCode errCode = OH_DecodingOptions_Create(&opts);
        if (errCode != IMAGE_SUCCESS || opts == nullptr) {
            return ReturnHdrErrorCode(env, errCode, "OH_DecodingOptions_Create");
        }
    
        OH_DecodingOptions_SetDesiredDynamicRange(opts, IMAGE_DYNAMIC_RANGE_SDR);
        ReleasePixelMap(&g_hdrColorSpace->pixelMap);
        errCode = OH_ImageSourceNative_CreatePixelmap(g_hdrColorSpace->source, opts, &g_hdrColorSpace->pixelMap);
    
        OH_DecodingOptions_Release(opts);
        opts = nullptr;
        return ReturnHdrErrorCode(env, errCode, "OH_ImageSourceNative_CreatePixelmap");
    }
    ```

11. Decode the image to a `Picture`.

    `Picture` is an image structure in Image Kit used to carry primary and auxiliary images. For HDR images with a `GainMap`, `Picture` can simultaneously provide the SDR primary image, the `GainMap`, and the synthesized HDR image, allowing the app to choose different processing paths based on device capabilities and business scenarios:

    - When compatibility with normal display or sharing is required, the SDR primary image can be used.

    - When HDR display or processing is required, an HDR `PixelMap` can be synthesized.

    <!-- @[hdrColorSpace_decodePicture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

    ``` C++
    napi_value DecodeHdrPicture(napi_env env, napi_callback_info info)
    {
        if (g_hdrColorSpace->source == nullptr) {
            OH_LOG_ERROR(LOG_APP, "ImageSource is nullptr.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        OH_DecodingOptionsForPicture *options = nullptr;
        Image_ErrorCode errCode = OH_DecodingOptionsForPicture_Create(&options);
        if (errCode != IMAGE_SUCCESS || options == nullptr) {
            return ReturnHdrErrorCode(env, errCode, "OH_DecodingOptionsForPicture_Create");
        }
    
        Image_AuxiliaryPictureType desiredAuxiliaryPictures[] = { AUXILIARY_PICTURE_TYPE_GAINMAP };
        errCode = OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(options, desiredAuxiliaryPictures, 1);
        if (errCode != IMAGE_SUCCESS) {
            OH_DecodingOptionsForPicture_Release(options);
            options = nullptr;
            return ReturnHdrErrorCode(env, errCode, "OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures");
        }
    
        if (g_hdrColorSpace->picture != nullptr) {
            OH_PictureNative_Release(g_hdrColorSpace->picture);
            g_hdrColorSpace->picture = nullptr;
        }
    
        errCode = OH_ImageSourceNative_CreatePicture(g_hdrColorSpace->source, options, &g_hdrColorSpace->picture);
    
        OH_DecodingOptionsForPicture_Release(options);
        options = nullptr;
        return ReturnHdrErrorCode(env, errCode, "OH_ImageSourceNative_CreatePicture");
    }
    ```

12. Obtain the SDR primary image from `Picture`.

    The SDR primary image can be used for normal display, editing, sharing, or as a fallback when HDR processing fails. For HDR images with a `GainMap`, the primary image is typically the image data compatible with the SDR display link.

    <!-- @[hdrColorSpace_getMainPixelmap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

    ``` C++
    napi_value GetMainPixelmapFromPicture(napi_env env, napi_callback_info info)
    {
        if (g_hdrColorSpace->picture == nullptr) {
            OH_LOG_ERROR(LOG_APP, "Picture is nullptr.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        ReleasePixelMap(&g_hdrColorSpace->mainPixelMap);
        Image_ErrorCode errCode = OH_PictureNative_GetMainPixelmap(g_hdrColorSpace->picture,
            &g_hdrColorSpace->mainPixelMap);
        return ReturnHdrErrorCode(env, errCode, "OH_PictureNative_GetMainPixelmap");
    }
    ```

13. Obtain the `GainMap` from the `Picture`.

    The `GainMap` records the gain information used to restore or enhance HDR effects from the SDR primary image. If the app needs custom HDR processing, it can obtain the `GainMap PixelMap` for further processing.

    <!-- @[hdrColorSpace_getGainmapPixelmap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

    ``` C++
    napi_value GetGainmapPixelmapFromPicture(napi_env env, napi_callback_info info)
    {
        if (g_hdrColorSpace->picture == nullptr) {
            OH_LOG_ERROR(LOG_APP, "Picture is nullptr.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        ReleasePixelMap(&g_hdrColorSpace->gainmapPixelMap);
        Image_ErrorCode errCode = OH_PictureNative_GetGainmapPixelmap(g_hdrColorSpace->picture,
            &g_hdrColorSpace->gainmapPixelMap);
        return ReturnHdrErrorCode(env, errCode, "OH_PictureNative_GetGainmapPixelmap");
    }
    ```

14. Obtain the composited HDR image from the `Picture`.

    When the `Picture` contains a valid `GainMap`, the composited HDR `PixelMap` can be obtained directly. If the `Picture` does not contain a `GainMap`, the API may return `IMAGE_UNSUPPORTED_OPERATION`, and the app can fall back to the SDR primary image.

    <!-- @[hdrColorSpace_getHdrComposedPixelmap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

    ``` C++
    napi_value GetHdrComposedPixelmapFromPicture(napi_env env, napi_callback_info info)
    {
        if (g_hdrColorSpace->picture == nullptr) {
            OH_LOG_ERROR(LOG_APP, "Picture is nullptr.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        ReleasePixelMap(&g_hdrColorSpace->hdrPixelMap);
        Image_ErrorCode errCode = OH_PictureNative_GetHdrComposedPixelmap(g_hdrColorSpace->picture,
            &g_hdrColorSpace->hdrPixelMap);
        return ReturnHdrErrorCode(env, errCode, "OH_PictureNative_GetHdrComposedPixelmap");
    }
    ```

15. Encode the HDR `PixelMap`.

    If the app needs to save the processed HDR `PixelMap` as a file, encoding parameters can be set through `ImagePacker`. Whether the encoding result is HDR depends on the dynamic range of the source `PixelMap`, the encoding format, the device capability, and the encoding parameters. If the service only requires compatibility for sharing or standard display, encoding to an SDR result is preferred.

    <!-- @[hdrColorSpace_packHdrPixelMap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

    ``` C++
    napi_value PackHdrPixelMap(napi_env env, napi_callback_info info)
    {
        if (g_hdrColorSpace->pixelMap == nullptr) {
            OH_LOG_ERROR(LOG_APP, "PixelMap is nullptr.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        napi_value argValue[1] = {nullptr};
        size_t argCount = 1;
        if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok ||
            argCount < 1 || argValue[0] == nullptr) {
            OH_LOG_ERROR(LOG_APP, "PackHdrPixelMap napi_get_cb_info failed!");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        int32_t fd = -1;
        napi_get_value_int32(env, argValue[0], &fd);
    
        OH_ImagePackerNative *packer = nullptr;
        Image_ErrorCode errCode = OH_ImagePackerNative_Create(&packer);
        if (errCode != IMAGE_SUCCESS || packer == nullptr) {
            return ReturnHdrErrorCode(env, errCode, "OH_ImagePackerNative_Create");
        }
    
        OH_PackingOptions *packingOptions = nullptr;
        errCode = OH_PackingOptions_Create(&packingOptions);
        if (errCode != IMAGE_SUCCESS || packingOptions == nullptr) {
            OH_ImagePackerNative_Release(packer);
            packer = nullptr;
            return ReturnHdrErrorCode(env, errCode, "OH_PackingOptions_Create");
        }
    
        char type[] = "image/jpeg";
        Image_MimeType mimeType = {type, strlen(type)};
        OH_PackingOptions_SetMimeType(packingOptions, &mimeType);
        //         // Set the encoding quality. The default value of quality is 0, and a value of no less than 80 is recommended.
        // In this example, it is uniformly set to 90 to balance image quality and file size.
        uint32_t quality = 90;
        OH_PackingOptions_SetQuality(packingOptions, quality);
        OH_PackingOptions_SetDesiredDynamicRange(packingOptions, IMAGE_PACKER_DYNAMIC_RANGE_AUTO);
    
        errCode = OH_ImagePackerNative_PackToFileFromPixelmap(packer, packingOptions, g_hdrColorSpace->pixelMap, fd);
    
        OH_PackingOptions_Release(packingOptions);
        packingOptions = nullptr;
        OH_ImagePackerNative_Release(packer);
        packer = nullptr;
        return ReturnHdrErrorCode(env, errCode, "OH_ImagePackerNative_PackToFileFromPixelmap");
    }
    ```

16. Release resources.

    After use, resources such as `ImageSource`, `PixelMap`, and `Picture` must be released to avoid memory leaks.

    <!-- @[hdrColorSpace_release](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadHdrColorSpace.cpp) -->

    ``` C++
    napi_value ReleaseHdrColorSpaceSource(napi_env env, napi_callback_info info)
    {
        Image_ErrorCode errCode = IMAGE_SUCCESS;
    
        ReleasePixelMap(&g_hdrColorSpace->hdrPixelMap);
        ReleasePixelMap(&g_hdrColorSpace->gainmapPixelMap);
        ReleasePixelMap(&g_hdrColorSpace->mainPixelMap);
    
        if (g_hdrColorSpace->picture != nullptr) {
            errCode = OH_PictureNative_Release(g_hdrColorSpace->picture);
            g_hdrColorSpace->picture = nullptr;
        }
    
        ReleasePixelMap(&g_hdrColorSpace->pixelMap);
    
        if (g_hdrColorSpace->source != nullptr) {
            errCode = OH_ImageSourceNative_Release(g_hdrColorSpace->source);
            g_hdrColorSpace->source = nullptr;
        }
    
        g_hdrColorSpace->isHdr = false;
        return ReturnHdrErrorCode(env, errCode, "ReleaseHdrColorSpaceSource");
    }
    ```

## Constraints

- The HDR decoding result depends on factors such as the image source, device capabilities, decoding parameters, memory type, and system capabilities. Even if the source image is HDR, the decoded result may not be HDR.

- When `IMAGE_DYNAMIC_RANGE_AUTO` is used, the system selects an appropriate decoding result based on the image source and device capabilities. Applications can call `OH_PixelmapImageInfo_GetDynamicRange` to check the actual result.

- `IMAGE_DYNAMIC_RANGE_SDR` can be used for scenarios where compatibility is prioritized.

- When encoding HDR images, applications need to consider the encoding format, the dynamic range of the source `PixelMap`, and device capabilities. If encoding fails, an error code is returned. Applications must handle the error by providing SDR encoding as a fallback or displaying an error message.