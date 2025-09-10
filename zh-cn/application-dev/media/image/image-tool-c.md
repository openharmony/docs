# 使用Image_NativeModule编辑图片EXIF信息
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Image Kit提供图片EXIF信息的读取与编辑能力。

EXIF（Exchangeable image file format）是专门为数码相机的照片设定的文件格式，可以记录数码照片的属性信息和拍摄数据。当前支持JPEG、PNG、HEIF格式，且需要图片包含EXIF信息。

在图库等应用中，需要查看或修改数码照片的EXIF信息。由于摄像机的手动镜头参数无法自动写入到EXIF信息中或者因为相机断电等原因会导致拍摄时间出错，这时需要手动修改错误的EXIF数据，即可使用本功能。

OpenHarmony目前仅支持对部分EXIF信息的查看和修改，具体支持的范围请参见：[OHOS_IMAGE_PROPERTY_XXX](../../reference/apis-image-kit/capi-image-common-h.md#变量)。

## 开发步骤

### 添加链接库

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libimage_source.so 以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so)
```

### Native接口调用

EXIF信息的读取与编辑相关C API接口的详细介绍请参见[OH_ImageSource_GetImageProperty](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty) 和 [OH_ImageSource_ModifyImageProperty](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_modifyimageproperty)。

在Deveco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

**读取和编辑图片EXIF信息接口使用示例**

在创建ImageSource实例后，读取、编辑EXIF信息。

```c++
#include <string>

#include <hilog/log.h>
#include <multimedia/image_framework/image/image_source_native.h>

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

static napi_value exifTest(napi_env env, napi_callback_info info)
{
    napi_value argValue[NUM_1] = {0};
    size_t argCount = NUM_1;
    if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < NUM_1 ||
        argValue[NUM_0] == nullptr) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest napi_get_cb_info failed, argCount: %{public}lu.", argCount);
        return getJsResult(env, IMAGE_BAD_PARAMETER);
    }
    char name[1024];
    size_t nameSize = 1024;
    napi_get_value_string_utf8(env, argValue[NUM_0], name, 1024, &nameSize);

    //创建ImageSource实例。
    OH_ImageSourceNative *source = nullptr;
    Image_ErrorCode errCode = OH_ImageSourceNative_CreateFromUri(name, nameSize, &source);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest OH_ImageSourceNative_CreateFromUri failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // 读取EXIF信息，OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE为每个像素比特数。
    Image_String getKey;
    const std::string PIXEL_X_DIMENSION = OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE;
    getKey.data = (char *)PIXEL_X_DIMENSION.c_str();
    getKey.size = PIXEL_X_DIMENSION.length();
    Image_String getValue;
    errCode = OH_ImageSourceNative_GetImageProperty(source, &getKey, &getValue);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest OH_ImageSourceNative_GetImageProperty failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }

    // 编辑EXIF信息，OHOS_IMAGE_PROPERTY_ORIENTATION为图片方向。
    Image_String setKey;
    const std::string ORIENTATION = OHOS_IMAGE_PROPERTY_ORIENTATION;
    setKey.data = (char *)ORIENTATION.c_str();
    setKey.size = ORIENTATION.length();
    Image_String setValue;
    setValue.data = (char *)"4";
    setValue.size = 1;
    errCode = OH_ImageSourceNative_ModifyImageProperty(source, &setKey, &setValue);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImageSourceNativeCTest exifTest OH_ImageSourceNative_ModifyImageProperty failed, errCode: %{public}d.", errCode);
        return getJsResult(env, errCode);
    }
    
    //释放ImageSource实例。
    OH_ImageSourceNative_Release(source);
    OH_LOG_INFO(LOG_APP, "ImageSourceNativeCTest exifTest success.");
    return getJsResult(env, IMAGE_SUCCESS);
}
```
