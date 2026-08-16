# Using Image_NativeModule to Decode Animated Images

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=d44ee7b2ca28d36220fe90dd5fc8000fc5484075 translatedAt=2026-08-11T01:42:11.466Z pushedAt=2026-08-11T03:10:43.471Z -->

You can use `Image_NativeModule` to decode animated image resources such as GIF and WebP, obtain the frame count and frame delay time, and choose full decoding or frame-by-frame decoding to obtain PixelMap objects based on your service requirements.

Animated image decoding involves the following steps:

1. Create an `ImageSource` instance.

2. Call the API to obtain the frame count and determine whether the image is an animated image.

3. Obtain the delay time of each frame.

4. Based on the service scenario, choose either full decoding of all frames or decoding a specific frame by index.

5. Release resources such as the `ImageSource`, PixelMap, and decoding parameters after use.

## How to Develop

### Adding Libraries

Before developing an app, open the `src/main/cpp/CMakeLists.txt` file of the native project, and add `libimage_source.so`, `libpixelmap.so`, and `libhilog_ndk.z.so` (required for logging) to the `target_link_libraries` dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libpixelmap.so)
```

### Calling Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

When creating a Native C++ app in DevEco Studio, the generated project includes an `index.ets` file by default, and a `cpp` file (`hello.cpp` or `napi_init.cpp`; this example uses `hello.cpp` as the file name) is automatically generated in the `entry\src\main\cpp` directory. Implement the C API call logic in `hello.cpp`. The sample code is as follows:

**Using Animated Image Decoding APIs**

1. Include the relevant header files.

   <!-- @[animatedDecoding_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

   ``` C++
   #include <string>
   #include <hilog/log.h>
   #include <multimedia/image_framework/image/image_source_native.h>
   #include <multimedia/image_framework/image/image_common.h>
   #include <multimedia/image_framework/image/pixelmap_native.h>
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

3. Define a class for animated image decoding to store the `ImageSource` instance, frame count, and decoded PixelMap objects.

   <!-- @[define_animatedSourceClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/imageKits.h) -->

   ``` C
   class ImageAnimatedNative {
   public:
       OH_ImageSourceNative *source = nullptr;
       OH_PixelmapNative **pixelMapList = nullptr;
       OH_PixelmapNative *pixelMap = nullptr;
       uint32_t frameCnt = 0;
       size_t pixelMapListSize = 0;
       ImageAnimatedNative() {}
       ~ImageAnimatedNative() {}
   };
   ```

4. Create an `ImageAnimatedNative` instance.

   <!-- @[create_animatedSourceClass](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

   ``` C++
   static ImageAnimatedNative *g_thisAnimated = new ImageAnimatedNative();
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

   <!-- @[animatedDecoding_maxStringLength](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->   

   ``` C++
   const int ANIMATED_MAX_STRING_LENGTH = 1024;
   ```

7. Create an `ImageSource` instance.

   <!-- @[animatedDecoding_createImageSource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

   ``` C++
   // Create an ImageSource instance.
   napi_value CreateAnimatedImageSource(napi_env env, napi_callback_info info)
   {
       napi_value argValue[1] = {nullptr};
       size_t argCount = 1;
       if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok ||
           argCount < 1 || argValue[0] == nullptr) {
           OH_LOG_ERROR(LOG_APP, "CreateAnimatedImageSource napi_get_cb_info failed!");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       char filePath[ANIMATED_MAX_STRING_LENGTH];
       size_t pathSize = ANIMATED_MAX_STRING_LENGTH;
       napi_get_value_string_utf8(env, argValue[0], filePath, ANIMATED_MAX_STRING_LENGTH, &pathSize);
   
       if (g_thisAnimated->source != nullptr) {
           ReleaseAnimatedImageSource(env, info);
       }
   
       Image_ErrorCode errCode = OH_ImageSourceNative_CreateFromUri(filePath, pathSize, &g_thisAnimated->source);
       return ReturnAnimatedErrorCode(env, errCode, "OH_ImageSourceNative_CreateFromUri");
   }
   ```

8. Obtain the image frame count. If the frame count is greater than 1, the image can be processed as an animated image.

   <!-- @[animatedDecoding_getFrameCount](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

   ``` C++
   // Obtain the image frame count. If the frame count is greater than 1, the image can be processed as an animated image.
   napi_value GetAnimatedFrameCount(napi_env env, napi_callback_info info)
   {
       if (g_thisAnimated->source == nullptr) {
           OH_LOG_ERROR(LOG_APP, "ImageSource is nullptr.");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       Image_ErrorCode errCode = OH_ImageSourceNative_GetFrameCount(g_thisAnimated->source, &g_thisAnimated->frameCnt);
       if (errCode != IMAGE_SUCCESS) {
           return ReturnAnimatedErrorCode(env, errCode, "OH_ImageSourceNative_GetFrameCount");
       }
   
       OH_LOG_INFO(LOG_APP, "Frame count: %{public}u.", g_thisAnimated->frameCnt);
       return GetJsResult(env, g_thisAnimated->frameCnt);
   }
   ```

9. Obtain the frame delay time list of the animated image. The delay time list is used to control the display duration of each frame.

   <!-- @[animatedDecoding_getDelayTimeList](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

   ``` C++
   // Obtain the image delay time list.
   napi_value GetAnimatedDelayTimeList(napi_env env, napi_callback_info info)
   {
       if (g_thisAnimated->source == nullptr || g_thisAnimated->frameCnt == 0) {
           OH_LOG_ERROR(LOG_APP, "Invalid ImageSource or frame count.");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
   
       int32_t *delayTimeList = new int32_t[g_thisAnimated->frameCnt];
       size_t size = g_thisAnimated->frameCnt;
       Image_ErrorCode errCode = OH_ImageSourceNative_GetDelayTimeList(g_thisAnimated->source, delayTimeList, size);
       if (errCode == IMAGE_SUCCESS) {
           for (size_t index = 0; index < size; index++) {
               OH_LOG_INFO(LOG_APP, "Frame %{public}zu delay time: %{public}d ms.", index, delayTimeList[index]);
           }
       }
       delete[] delayTimeList;
       delayTimeList = nullptr;
       return ReturnAnimatedErrorCode(env, errCode, "OH_ImageSourceNative_GetDelayTimeList");
   }
   ```

10. Decode animated image frames.

    For animated image frame decoding, you can choose full decoding or frame-by-frame decoding based on the service scenario.

    - Full decoding: decodes all frames at once. This is suitable for scenarios with a small frame count where all frames need to be played continuously. Full decoding holds multiple PixelMap instances simultaneously, and the memory usage is related to the frame count and the size of each frame.

    - Frame-by-frame decoding: decodes a specified frame by index. This is suitable for scenarios where peak memory usage needs to be reduced. During frame-by-frame decoding, the `ImageSource` instance must be kept valid.

    The following shows an example of full decoding of animated image frames.

    <!-- @[animatedDecoding_createPixelmapList](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

    ``` C++
    // Create a PixelMap list using image decoding parameters.
    napi_value CreateAnimatedPixelmapList(napi_env env, napi_callback_info info)
    {
        if (g_thisAnimated->source == nullptr || g_thisAnimated->frameCnt == 0) {
            OH_LOG_ERROR(LOG_APP, "Invalid ImageSource or frame count.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        ReleaseAnimatedPixelmapList();
    
        OH_DecodingOptions *opts = nullptr;
        Image_ErrorCode errCode = OH_DecodingOptions_Create(&opts);
        if (errCode != IMAGE_SUCCESS || opts == nullptr) {
            return ReturnAnimatedErrorCode(env, errCode, "OH_DecodingOptions_Create");
        }
    
        g_thisAnimated->pixelMapList = new OH_PixelmapNative *[g_thisAnimated->frameCnt]();
        g_thisAnimated->pixelMapListSize = g_thisAnimated->frameCnt;
        errCode = OH_ImageSourceNative_CreatePixelmapList(g_thisAnimated->source, opts,
            g_thisAnimated->pixelMapList, g_thisAnimated->pixelMapListSize);
    
        OH_DecodingOptions_Release(opts);
        opts = nullptr;
    
        if (errCode != IMAGE_SUCCESS) {
            ReleaseAnimatedPixelmapList();
            return ReturnAnimatedErrorCode(env, errCode, "OH_ImageSourceNative_CreatePixelmapList");
        }
    
        OH_LOG_INFO(LOG_APP, "Create %{public}zu pixelmaps.", g_thisAnimated->pixelMapListSize);
        return GetJsResult(env, errCode);
    }
    ```

    The following shows an example of decoding a specified frame by index.

    <!-- @[animatedDecoding_createPixelmapByIndex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

    ``` C++
    // Create a PixelMap for the specified frame by frame index.
    napi_value CreateAnimatedPixelmapByIndex(napi_env env, napi_callback_info info)
    {
        if (g_thisAnimated->source == nullptr || g_thisAnimated->frameCnt == 0) {
            OH_LOG_ERROR(LOG_APP, "Invalid ImageSource or frame count.");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        napi_value argValue[1] = {nullptr};
        size_t argCount = 1;
        if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok ||
            argCount < 1 || argValue[0] == nullptr) {
            OH_LOG_ERROR(LOG_APP, "CreateAnimatedPixelmapByIndex napi_get_cb_info failed!");
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        uint32_t index = 0;
        napi_get_value_uint32(env, argValue[0], &index);
        if (index >= g_thisAnimated->frameCnt) {
            OH_LOG_ERROR(LOG_APP, "Invalid frame index: %{public}u.", index);
            return GetJsResult(env, IMAGE_BAD_PARAMETER);
        }
    
        OH_DecodingOptions *opts = nullptr;
        Image_ErrorCode errCode = OH_DecodingOptions_Create(&opts);
        if (errCode != IMAGE_SUCCESS || opts == nullptr) {
            return ReturnAnimatedErrorCode(env, errCode, "OH_DecodingOptions_Create");
        }
        OH_DecodingOptions_SetIndex(opts, index);
    
        if (g_thisAnimated->pixelMap != nullptr) {
            OH_PixelmapNative_Release(g_thisAnimated->pixelMap);
            g_thisAnimated->pixelMap = nullptr;
        }
    
        errCode = OH_ImageSourceNative_CreatePixelmap(g_thisAnimated->source, opts, &g_thisAnimated->pixelMap);
        OH_DecodingOptions_Release(opts);
        opts = nullptr;
    
        return ReturnAnimatedErrorCode(env, errCode, "OH_ImageSourceNative_CreatePixelmap");
    }
    ```

11. Release resources.

    After use, release resources such as the `ImageSource` instance, the PixelMap list, and the single-frame PixelMap.

    <!-- @[animatedDecoding_release](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAnimatedImageSource.cpp) -->

    ``` C++
    // Release resources related to animated image decoding.
    napi_value ReleaseAnimatedImageSource(napi_env env, napi_callback_info info)
    {
        ReleaseAnimatedPixelmapList();
    
        if (g_thisAnimated->pixelMap != nullptr) {
            OH_PixelmapNative_Release(g_thisAnimated->pixelMap);
            g_thisAnimated->pixelMap = nullptr;
        }
    
        Image_ErrorCode errCode = IMAGE_SUCCESS;
        if (g_thisAnimated->source != nullptr) {
            errCode = OH_ImageSourceNative_Release(g_thisAnimated->source);
            g_thisAnimated->source = nullptr;
        }
    
        g_thisAnimated->frameCnt = 0;
        return ReturnAnimatedErrorCode(env, errCode, "OH_ImageSourceNative_Release");
    }
    ```