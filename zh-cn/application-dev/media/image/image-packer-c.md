# 使用Image_NativeModule完成图片编码

图像编码类，用于创建以及释放ImagePacker实例。

## 开发步骤

### 添加链接库

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libimage_packer.so 以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libimage_packer.so libpixelmap.so)
```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image-nativemodule.md)。

在Deveco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

**编码接口使用示例**

在创建ImagePacker实例，指定编码参数后将ImageSource或Pixelmap编码至文件或者缓冲区。

> **说明：**
> 根据MIME标准，标准编码格式为image/jpeg。当使用image编码时，编码参数中的编码格式image_MimeType设置为image/jpeg，image编码后的文件扩展名可设为.jpg或.jpeg，可在支持image/jpeg解码的平台上使用。

```c++
#include <linux/kd.h>
#include <string>
#include <set>
#include <hilog/log.h>
#include <multimedia/image_framework/image/image_common.h>
#include <multimedia/image_framework/image/image_packer_native.h>
#include <multimedia/image_framework/image/pixelmap_native.h>
#include <multimedia/image_framework/image/image_source_native.h>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "MY_TAG"

static std::set<std::string> g_encodeSupportedFormats;

Image_MimeType GetMimeTypeIfEncodable(const char *format)
{
    auto it = g_encodeSupportedFormats.find(format);
    if (it == g_encodeSupportedFormats.end()) {
        return {"", 0};
    }
    return {const_cast<char *>(format), strlen(format)};
}

Image_ErrorCode packToFileFromImageSourceTest(int fd)
{
    //创建ImagePacker实例。
    OH_ImagePackerNative *testPacker = nullptr;
    Image_ErrorCode errCode = OH_ImagePackerNative_Create(&testPacker);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest CreatePacker OH_ImagePackerNative_Create failed, errCode: %{public}d.", errCode);
        return errCode;
    }
    // 获取编码能力范围。
    Image_MimeType* mimeType = nullptr;
    size_t length = 0;
    errCode = OH_ImagePackerNative_GetSupportedFormats(&mimeType, &length);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImagePackerNative_GetSupportedFormats failed, errCode: %{public}d.", errCode);
        return errCode;
    }
    for (size_t count = 0; count < length; count++) {
        OH_LOG_INFO(LOG_APP, "Encode supportedFormats:%{public}s", mimeType[count].data);
        if (mimeType[count].data != nullptr) {
            g_encodeSupportedFormats.insert(std::string(mimeType[count].data));
        }
    }
    // 创建ImageSource实例。
    OH_ImageSourceNative* imageSource = nullptr;
    errCode = OH_ImageSourceNative_CreateFromFd(fd, &imageSource);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImageSourceNative_CreateFromFd  failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 指定编码参数，将ImageSource直接编码进文件。
    OH_PackingOptions *option = nullptr;
    OH_PackingOptions_Create(&option);
    Image_MimeType image_MimeType = GetMimeTypeIfEncodable(MIME_TYPE_JPEG);
    if (image_MimeType.data == nullptr || image_MimeType.size == 0) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest GetMimeTypeIfEncodable failed, format can't support encode.");
        return IMAGE_BAD_PARAMETER;
    }
    OH_PackingOptions_SetMimeType(option, &image_MimeType);
    // 编码为hdr内容（需要资源本身为hdr，支持jpeg格式）。
    OH_PackingOptions_SetDesiredDynamicRange(option, IMAGE_PACKER_DYNAMIC_RANGE_AUTO);
    errCode = OH_ImagePackerNative_PackToFileFromImageSource(testPacker, option, imageSource, fd);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImagePackerNative_PackToFileFromImageSource failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 释放ImagePacker实例。
    errCode = OH_ImagePackerNative_Release(testPacker);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_ImagePackerNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }
    // 释放ImageSource实例。
    errCode = OH_ImageSourceNative_Release(imageSource);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_ImageSourceNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    return IMAGE_SUCCESS;
}

Image_ErrorCode packToFileFromPixelmapTest(uint8_t *buffer, size_t bufferSize, int fd)
{
    // 创建ImagePacker实例。
    OH_ImagePackerNative *testPacker = nullptr;
    Image_ErrorCode errCode = OH_ImagePackerNative_Create(&testPacker);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest CreatePacker OH_ImagePackerNative_Create failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 创建Pixelmap实例。
    OH_Pixelmap_InitializationOptions *createOpts;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, 6);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, 4);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, 3);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, 0);
    OH_PixelmapNative *pixelmap = nullptr;
    errCode = OH_PixelmapNative_CreatePixelmap(buffer, bufferSize, createOpts, &pixelmap);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_PixelmapNative_CreatePixelmap  failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 指定编码参数，将PixelMap直接编码进文件。
    OH_PackingOptions *option = nullptr;
    OH_PackingOptions_Create(&option);
    char type[] = "image/jpeg";
    Image_MimeType image_MimeType = {type, strlen(type)};
    OH_PackingOptions_SetMimeType(option, &image_MimeType);
    errCode = OH_ImagePackerNative_PackToFileFromPixelmap(testPacker, option, pixelmap, fd);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest OH_ImagePackerNative_PackToFileFromPixelmap  failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 释放ImagePacker实例。
    errCode = OH_ImagePackerNative_Release(testPacker);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_ImagePackerNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 释放Pixelmap实例。
    errCode = OH_PixelmapNative_Release(pixelmap);
    if (errCode != IMAGE_SUCCESS)
    {
        OH_LOG_ERROR(LOG_APP, "ImagePackerNativeCTest ReleasePacker OH_PixelmapNative_Release failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    return IMAGE_SUCCESS;
}
```
