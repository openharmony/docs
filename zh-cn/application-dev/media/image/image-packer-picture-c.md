# 使用Image_NativeModule完成多图对象编码

图像编码类，用于创建以及释放ImagePacker实例，并编码多图对象。

## 开发步骤

### 添加链接库

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libimage_packer.so 以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libimage_packer.so libpixelmap.so)
```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image-nativemodule.md)。

在DevEco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

**编码接口使用示例**

在创建ImagePacker实例，指定编码参数后将Picture多图对象编码至文件或者缓冲区。

> **说明：**
> 根据MIME标准，标准编码格式为image/jpeg。当使用image编码时，编码参数中的编码格式image_MimeType设置为image/jpeg，image编码后的文件扩展名可设为.jpg或.jpeg，可在支持image/jpeg解码的平台上使用。

```c++
#include <hilog/log.h>
#include <bits/alltypes.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sstream>
#include <multimedia/image_framework/image/image_native.h>
#include <multimedia/image_framework/image/image_packer_native.h>
#include <multimedia/image_framework/image/image_source_native.h>
#include <multimedia/image_framework/image/picture_native.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

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

// 处理napi返回值。
napi_value getJsResult(napi_env env, int result) {
    napi_value resultNapi = nullptr;
    napi_create_int32(env, result, &resultNapi);
    return resultNapi;
}

// 释放ImageSource。
Image_ErrorCode ReleaseImageSource(OH_ImageSourceNative *&source) {
    if (source != nullptr) {
        thisPicture->errorCode = OH_ImageSourceNative_Release(source);
        source = nullptr;
        return thisPicture->errorCode;
    }
OH_LOG_DEBUG(LOG_APP, "ReleaseImageSource source is null!");
    return IMAGE_SUCCESS;
}

// 设置编码参数。
void SetPackOptions(OH_PackingOptions *packerOptions, Image_MimeType format, uint32_t quality, bool needsPackProperties,
                    int32_t desiredDynamicRange) {
    OH_PackingOptions_SetMimeType(packerOptions, &format);
    OH_PackingOptions_SetQuality(packerOptions, quality);
    OH_PackingOptions_SetNeedsPackProperties(packerOptions, needsPackProperties);
    OH_PackingOptions_SetDesiredDynamicRange(packerOptions, desiredDynamicRange);
}

// 编码PackToData。
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

// 编码PackToFile。
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
