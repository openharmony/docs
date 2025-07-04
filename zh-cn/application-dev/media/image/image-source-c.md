# 使用Image_NativeModule完成图片解码

创建ImageSource，获取位图的宽、高信息，以及释放ImageSource实例。

## 开发步骤

### 添加链接库

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libimage_source.so、libpixelmap.so以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libpixelmap.so)
```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image-nativemodule.md)。

在Deveco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

**解码接口使用示例**

在创建ImageSource实例后，进行指定属性值的获取和修改、通过解码参数创建PixelMap对象、获取图像帧数等操作。

```c++
#include <linux/kd.h>
#include <string>
#include <hilog/log.h>
#include <multimedia/image_framework/image/image_common.h>
#include <multimedia/image_framework/image/image_source_native.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "MY_TAG"

#define NUM_0 0
#define NUM_1 1

// 处理napi返回值。
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
    // 获取解码能力范围。
    Image_MimeType* mimeType = nullptr;
    size_t length = 0;
    Image_ErrorCode errCode = OH_ImageSourceNative_GetSupportedFormats(&mimeType, &length);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetSupportedFormats failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }
    for (size_t count = 0; count < length; count++) {
        OH_LOG_INFO(LOG_APP, "Decode supportedFormats:%{public}s", mimeType[count].data);
    }
    // 创建ImageSource实例。
    OH_ImageSourceNative *source = nullptr;
    errCode = OH_ImageSourceNative_CreateFromUri(name, nameSize, &source);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_CreateFromUri failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // 创建定义图片信息的结构体对象，并获取图片信息。
    OH_ImageSource_Info *imageInfo;
    OH_ImageSourceInfo_Create(&imageInfo);
    errCode = OH_ImageSourceNative_GetImageInfo(source, 0, imageInfo);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetImageInfo failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // 获取指定属性键的值。
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

    // 修改指定属性键的值。
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

    // 通过图片解码参数创建PixelMap对象。
    OH_DecodingOptions *ops = nullptr;
    OH_DecodingOptions_Create(&ops);
    // 设置为AUTO会根据图片资源格式解码，如果图片资源为HDR资源则会解码为HDR的pixelmap。
    OH_DecodingOptions_SetDesiredDynamicRange(ops, IMAGE_DYNAMIC_RANGE_AUTO);
    OH_PixelmapNative *resPixMap = nullptr;

    // ops参数支持传入nullptr, 当不需要设置解码参数时，不用创建。
    errCode = OH_ImageSourceNative_CreatePixelmap(source, ops, &resPixMap);
    OH_DecodingOptions_Release(ops);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_CreatePixelmap failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // 判断pixelmap是否为hdr内容。
    OH_Pixelmap_ImageInfo *pixelmapImageInfo = nullptr;
    OH_PixelmapImageInfo_Create(&pixelmapImageInfo);
    OH_PixelmapNative_GetImageInfo(resPixMap, pixelmapImageInfo);
    bool pixelmapIsHdr;
    OH_PixelmapImageInfo_GetDynamicRange(pixelmapImageInfo, &pixelmapIsHdr);
    OH_PixelmapImageInfo_Release(pixelmapImageInfo);

    // 获取图像帧数。
    uint32_t frameCnt = 0;
    errCode = OH_ImageSourceNative_GetFrameCount(source, &frameCnt);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetFrameCount failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // 通过图片解码参数创建Pixelmap列表。
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

    // 获取图像延迟时间列表。
    int32_t *delayTimeList = new int32_t[frameCnt];
    size_t size = frameCnt;
    errCode = OH_ImageSourceNative_GetDelayTimeList(source, delayTimeList, size);
    delete[] delayTimeList;
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest sourceTest OH_ImageSourceNative_GetDelayTimeList failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // 释放ImageSource实例。
    OH_ImageSourceNative_Release(source);
    OH_LOG_INFO(LOG_APP, "ImageSourceNativeCTest sourceTest success.");
    return getJsResult(env, IMAGE_SUCCESS);
}
```
