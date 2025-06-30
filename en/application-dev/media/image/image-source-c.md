# Using Image_NativeModule to Decode Images

This topic describes how to create an ImageSource object, obtain the width and height of the PixelMap, and release the ImageSource object.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_source.so**, **libpixelmap.so**, and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libpixelmap.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Decoding APIs**

After creating an **ImageSource** instance, obtain and modify property values, create a **PixelMap** object by using decoding parameters, and obtain the number of image frames.

   ```c++

      #include <linux/kd.h>
      #include <string>

      #include <hilog/log.h>
      #include <multimedia/image_framework/image/image_source_native.h>
      #include <multimedia/image_framework/image/pixelmap_native.h>

      #undef LOG_DOMAIN
      #undef LOG_TAG
      #define LOG_DOMAIN 0x3200
      #define LOG_TAG "MY_TAG"

      #define NUM_0 0
      #define NUM_1 1

      // Process the NAPI return value.
      napi_value getJsResult(napi_env env, int result) {
          napi_value resultNapi = nullptr;
          napi_create_int32(env, result, &resultNapi);
          return resultNapi;
      }

      static napi_value sourceTest(napi_env env, napi_callback_info info)
      {
          napi_value argValue[NUM_1] = {0};
          size_t argCount = NUM_1;
          if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < NUM_1 ||
              argValue[NUM_0] == nullptr) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest napi_get_cb_info failed, argCount: %{public}d.", argCount);
              return getJsResult(env, IMAGE_BAD_PARAMETER);
          }
          char name[1024];
          size_t nameSize = 1024;
          napi_get_value_string_utf8(env, argValue[NUM_0], name, 1024, &nameSize);

          // Create an ImageSource instance.
          OH_ImageSourceNative *source = nullptr;
          Image_ErrorCode errCode = OH_ImageSourceNative_CreateFromUri(name, nameSize, &source);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_CreateFromUri failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Create a structure object that defines the image information and obtain the image information.
          OH_ImageSource_Info *imageInfo;
          OH_ImageSourceInfo_Create(&imageInfo);
          errCode = OH_ImageSourceNative_GetImageInfo(source, 0, imageInfo);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetImageInfo failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Obtain the values of the specified properties.
          uint32_t width, height;
          OH_ImageSourceInfo_GetWidth(imageInfo, &width);
          OH_ImageSourceInfo_GetHeight(imageInfo, &height);
          OH_ImageSourceInfo_Release(imageInfo);
          OH_LOG_INFO(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetImageInfo success, width: %{public}d, height: %{public}d.", width, height);
          Image_String getKey;
          const std::string PIXEL_X_DIMENSION = "PixelXDimension";
          getKey.data = (char *)PIXEL_X_DIMENSION.c_str();
          getKey.size = PIXEL_X_DIMENSION.length();
          Image_String getValue;
          errCode = OH_ImageSourceNative_GetImageProperty(source, &getKey, &getValue);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetImageProperty failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Modify the values of the specified properties.
          Image_String setKey;
          const std::string ORIENTATION = "Orientation";
          setKey.data = (char *)ORIENTATION.c_str();
          setKey.size = ORIENTATION.length();
          Image_String setValue;
          setValue.data = (char *)"4";
          setValue.size = 1;
          errCode = OH_ImageSourceNative_ModifyImageProperty(source, &setKey, &setValue);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_ModifyImageProperty failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Create a PixelMap object based on image decoding parameters.
          OH_DecodingOptions *ops = nullptr;
          OH_DecodingOptions_Create(&ops);
          // If IMAGE_DYNAMIC_RANGE_AUTO is passed in, decoding is performed based on the image format. If the image is an HDR resource, an HDR PixelMap is obtained after decoding.
          OH_DecodingOptions_SetDesiredDynamicRange(ops, IMAGE_DYNAMIC_RANGE_AUTO);
          OH_PixelmapNative *resPixMap = nullptr;

          // A null pointer cannot be passed in to ops. If ops does not need to be set, you do not need to create a PixelMap object.
          errCode = OH_ImageSourceNative_CreatePixelmap(source, ops, &resPixMap);
          OH_DecodingOptions_Release(ops);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_CreatePixelmap failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Check whether the PixelMap is the HDR content.
          OH_Pixelmap_ImageInfo *pixelmapImageInfo = nullptr;
          OH_PixelmapImageInfo_Create(&pixelmapImageInfo);
          OH_PixelmapNative_GetImageInfo(resPixMap, pixelmapImageInfo);
          bool pixelmapIsHdr;
          OH_PixelmapImageInfo_GetDynamicRange(pixelmapImageInfo, &pixelmapIsHdr);
          OH_PixelmapImageInfo_Release(pixelmapImageInfo);

          // Obtain the number of image frames.
          uint32_t frameCnt = 0;
          errCode = OH_ImageSourceNative_GetFrameCount(source, &frameCnt);
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetFrameCount failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Create a PixelMap list based on image decoding parameters.
          OH_DecodingOptions *opts = nullptr;
          OH_DecodingOptions_Create(&opts);
          OH_PixelmapNative **resVecPixMap = new OH_PixelmapNative*[frameCnt];
          size_t outSize = frameCnt;
          errCode = OH_ImageSourceNative_CreatePixelmapList(source, opts, resVecPixMap, outSize);
          OH_DecodingOptions_Release(opts);
          delete[] resVecPixMap;
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_CreatePixelmapList failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Obtain the image delay time list.
          int32_t *delayTimeList = new int32_t[frameCnt];
          size_t size = frameCnt;
          errCode = OH_ImageSourceNative_GetDelayTimeList(source, delayTimeList, size);
          delete[] delayTimeList;
          if (errCode != IMAGE_SUCCESS) {
              OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetDelayTimeList failed, errCode: %{public}d.", errCode);
              return getJsResult(env, errCode);
          }

          // Release the ImageSource instance.
          OH_ImageSourceNative_Release(source);
          OH_LOG_INFO(LOG_APP, "ImageSourceNativeCTest sourceTest success.");
          return getJsResult(env, IMAGE_SUCCESS);
      }
   ```
