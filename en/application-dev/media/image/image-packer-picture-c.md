# Using Image_NativeModule to Encode Pictures

With Image_NativeModule, you can create and release **ImagePacker** instances and encode picture objects.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_packer.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_packer.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md).

Create a native C++ application in DevEco Studio. The project created by default contains the **index.ets** file, and a **hello.cpp** or **napi_init.cpp** file is generated in the **entry\src\main\cpp** directory. In this example, the generated file is **hello.cpp**. Implement the C APIs in **hello.cpp**. Refer to the sample code below.

**Example of Using the Encoding APIs**

After an **ImagePacker** instance is created and encoding parameters are specified, the Picture object is encoded to a file or buffer.

> **NOTE**
>
> According to the MIME protocol, the standard encoding format is image/jpeg. When the APIs provided by the image module are used for encoding, **image_MimeType** of the encoding parameters must be set to **image/jpeg**. The file name extension of the encoded image file can be .jpg or .jpeg, and the file can be used on platforms that support image/jpeg decoding.

   ```c++

    #include "imagepicture_native.h"
    #include "common/log_common.h"
    #include <bits/alltypes.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sstream>

    #define AUTO 0
    #define SDR 1

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

    static ImagePictureNative *thisPicture = new ImagePictureNative();

    // Process the NAPI return value.
    napi_value getJsResult(napi_env env, int result) {
        napi_value resultNapi = nullptr;
        napi_create_int32(env, result, &resultNapi);
        return resultNapi;
    }

    // Release the image source.
    Image_ErrorCode ReleaseImageSource(OH_ImageSourceNative *&source) {
        if (source != nullptr) {
            thisPicture->errorCode = OH_ImageSourceNative_Release(source);
            source = nullptr;
            return thisPicture->errorCode;
        }
    OH_LOG_DEBUG(LOG_APP, "ReleaseImageSource source is null!");
        return IMAGE_SUCCESS;
    }

    // Set packing parameters.
    void SetPackOptions(OH_PackingOptions *packerOptions, Image_MimeType format, uint32_t quality, bool needsPackProperties,
                        int32_t desiredDynamicRange) {
        OH_PackingOptions_SetMimeType(packerOptions, &format);
        OH_PackingOptions_SetQuality(packerOptions, quality);
        OH_PackingOptions_SetNeedsPackProperties(packerOptions, needsPackProperties);
        OH_PackingOptions_SetDesiredDynamicRange(packerOptions, desiredDynamicRange);
    }

    // Call PackToData.
    static napi_value PackToDataFromPicture(napi_env env, napi_callback_info info) {
        size_t argc = 2;
        napi_value args[2] = {nullptr};
        if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok) {
            OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed!");
            return getJsResult(env, thisPicture->errorCode);
        }
        uint32_t fd = 0;
        napi_get_value_uint32(env, args[0], &fd);
        size_t outDataSize = 10000 * 10000;
        uint8_t *outData = new uint8_t[10000 * 10000];

        if (thisPicture->packerOptions == nullptr) {
            thisPicture->errorCode = OH_PackingOptions_Create(&thisPicture->packerOptions);
        }
        if (thisPicture->imagePacker == nullptr) {
            thisPicture->errorCode = OH_ImagePackerNative_Create(&thisPicture->imagePacker);
        }

        char strFormat[20];
        size_t strFormatSize;
        napi_get_value_string_utf8(env, args[1], strFormat, 20, &strFormatSize);
        OH_LOG_DEBUG(LOG_APP, "PackToDataFromPicture format: %{public}s", strFormat);

        Image_MimeType format;
        format.size = strFormatSize;
        format.data = const_cast<char *>(strFormat);
        uint32_t quality = 98;
        bool needsPackProperties = true;
        int32_t desiredDynamicRange = AUTO;
        SetPackOptions(thisPicture->packerOptions, format, quality, needsPackProperties, desiredDynamicRange);

        thisPicture->errorCode = OH_ImagePackerNative_PackToDataFromPicture(
            thisPicture->imagePacker, thisPicture->packerOptions, thisPicture->picture, outData, &outDataSize);
        if (thisPicture->errorCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_ImagePackerNative_PackToDataFromPicture failed, errCode: %{public}d.",
                thisPicture->errorCode);
            delete[] outData;
            return getJsResult(env, thisPicture->errorCode);
        } else {
            ReleaseImageSource(thisPicture->source);
            OH_ImageSourceNative_CreateFromData(outData, outDataSize, &thisPicture->source);
            OH_ImagePackerNative_PackToFileFromImageSource(thisPicture->imagePacker, thisPicture->packerOptions,
                                                        thisPicture->source, fd);
            ReleaseImageSource(thisPicture->source);
        OH_LOG_DEBUG(LOG_APP, "OH_ImagePackerNative_PackToDataFromPicture success !");
        }

        return getJsResult(env, thisPicture->errorCode);
    }

    // Call PackToFile.
    static napi_value PackToFileFromPicture(napi_env env, napi_callback_info info) {
        size_t argc = 2;
        napi_value args[2] = {nullptr};
        if (napi_get_cb_info(env, info, &argc, args, nullptr, nullptr) != napi_ok) {
        OH_LOG_ERROR(LOG_APP, "napi_get_cb_info failed!");
            return getJsResult(env, thisPicture->errorCode);
        }
        uint32_t fd = 0;
        napi_get_value_uint32(env, args[0], &fd);

        if (thisPicture->packerOptions == nullptr) {
            thisPicture->errorCode = OH_PackingOptions_Create(&thisPicture->packerOptions);
        }
        if (thisPicture->imagePacker == nullptr) {
            thisPicture->errorCode = OH_ImagePackerNative_Create(&thisPicture->imagePacker);
        }

        char strFormat[20];
        size_t strFormatSize;
        napi_get_value_string_utf8(env, args[1], strFormat, 20, &strFormatSize);
    OH_LOG_ERROR(LOG_APP, "PackToFileFromPicture format: %{public}s", strFormat);

        Image_MimeType format;
        format.size = strFormatSize;
        format.data = const_cast<char *>(strFormat);
        uint32_t quality = 98;
        bool needsPackProperties = false;
        int32_t desiredDynamicRange = SDR;
        SetPackOptions(thisPicture->packerOptions, format, quality, needsPackProperties, desiredDynamicRange);

        thisPicture->errorCode = OH_ImagePackerNative_PackToFileFromPicture(
            thisPicture->imagePacker, thisPicture->packerOptions, thisPicture->picture, fd);

        if (thisPicture->errorCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_ImagePackerNative_PackToFileFromPicture failed, errCode: %{public}d.", 
            thisPicture->errorCode);

            return getJsResult(env, thisPicture->errorCode);
        } else {
        OH_LOG_DEBUG(LOG_APP, "OH_ImagePackerNative_PackToFileFromPicture success !");
        }

        return getJsResult(env, thisPicture->errorCode);
    }
   ```
