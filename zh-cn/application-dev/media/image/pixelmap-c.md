# 使用Image_NativeModule完成位图操作

创建位图，获取位图的宽、高、pixelFormat、alphaType、rowStride信息、对位图进行操作以及释放位图实例。

## 开发步骤

### 添加链接库

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libpixelmap.so以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)
```

### Native接口调用

具体接口说明请参考[API文档](../../reference/apis-image-kit/capi-image-nativemodule.md)。

在Deveco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

**位图接口使用示例**

在初始化参数后创建Pixelmap实例，进行图片像素数据的读写，对图片进行缩放、位置变换、反转、旋转、裁剪等操作。

```c++

#include <linux/kd.h>
#include <string>

#include <hilog/log.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "MY_TAG"

Image_ErrorCode PixelmapTest()
{
    uint8_t data[96];
    size_t dataSize = 96;
    for (int i = 0; i < dataSize; i++) {
        data[i] = i + 1;
    }

    // 创建参数结构体实例，并设置参数。
    OH_Pixelmap_InitializationOptions *createOpts;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, 6);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, 4);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);

    // 创建Pixelmap实例。
    OH_PixelmapNative *pixelmap = nullptr;
    Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, dataSize, createOpts, &pixelmap);

    // 读取图像像素数据，结果写入数组里。
    uint8_t destination[96];
    size_t destinationSize = 96;
    errCode = OH_PixelmapNative_ReadPixels(pixelmap, destination, &destinationSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_ReadPixels failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 读取缓冲区中的图片数据，结果写入Pixelmap中。
    uint8_t source[96];
    size_t sourceSize = 96;
    for (int i = 0; i < sourceSize; i++) {
        source[i] = i + 1;
    }
    errCode = OH_PixelmapNative_WritePixels(pixelmap, source, sourceSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_WritePixels failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 创建图片信息实例，并获取图像像素信息。
    OH_Pixelmap_ImageInfo *imageInfo;
    OH_PixelmapImageInfo_Create(&imageInfo);
    errCode = OH_PixelmapNative_GetImageInfo(pixelmap, imageInfo);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_GetImageInfo failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 获取图片的宽，高，pixel格式，透明度等信息。
    uint32_t width, height, rowStride;
    int32_t pixelFormat, alphaType;
    OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
    OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
    OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
    OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
    OH_PixelmapImageInfo_GetAlphaType(imageInfo, &alphaType);
    OH_PixelmapImageInfo_Release(imageInfo);
    OH_LOG_INFO(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest GetImageInfo success, width: %{public}d, height: %{public}d, rowStride: %{public}d, pixelFormat: %{public}d, alphaType: %{public}d.", width, height, rowStride, pixelFormat, alphaType);

    // 设置透明比率来让Pixelmap达到对应的透明效果。
    errCode = OH_PixelmapNative_Opacity(pixelmap, 0.5);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Opacity failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行缩放。
    errCode = OH_PixelmapNative_Scale(pixelmap, 2.0, 1.0);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Scale failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行位置变换。
    errCode = OH_PixelmapNative_Translate(pixelmap, 50.0, 10.0);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Translate failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行旋转。
    errCode = OH_PixelmapNative_Rotate(pixelmap, 90.0);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Rotate failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行翻转。
    errCode = OH_PixelmapNative_Flip(pixelmap, true, true);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Flip failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行裁剪。
    Image_Region region;
    region.x = 100;
    region.y = 100;
    region.width = 6;
    region.height = 4;
    errCode = OH_PixelmapNative_Crop(pixelmap, &region);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ImagePixelmapNativeCTest pixelmapTest OH_PixelmapNative_Crop failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 释放Pixelmap, InitializationOptions实例。
    OH_PixelmapNative_Release(pixelmap);
    OH_PixelmapInitializationOptions_Release(createOpts);
    return IMAGE_SUCCESS;
}
```
