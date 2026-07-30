# 使用Image_NativeModule完成位图操作
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->

创建位图，获取位图的宽、高、pixelFormat、alphaType、rowStride信息、对位图进行操作以及释放位图实例。

## 开发步骤

### 添加链接库

在进行应用开发之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libpixelmap.so以及日志依赖libhilog_ndk.z.so。

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)
```

### Native接口调用

具体接口说明请参考[Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md)。

在DevEco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。在hello.cpp中实现C API接口调用逻辑，示例代码如下：

**位图接口使用示例**

在初始化参数后创建Pixelmap实例，进行图片像素数据的读写，对图片进行缩放、位置变换、反转、旋转、裁剪等操作。

<!-- @[ndk_pixelmap_bitmap_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/NdkPixelMap/entry/src/main/cpp/libimage/pixelmap.cpp) -->

``` C++
#include <hilog/log.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "MY_TAG"

const uint8_t DATA_SIZE = 96;
const uint8_t OPTS_WIDTH = 6;
const uint8_t OPTS_HEIGHT = 4;
const float OPACITY_VALUE = 0.5;
const float SCALE_X = 2.0;
const float SCALE_Y = 1.0;
const float TRANSLATE_X = 50.0;
const float TRANSLATE_Y = 10.0;
const float ROTATE_ANGLE = 90.0;
const uint8_t REGION_X = 100;
const uint8_t REGION_Y = 100;
const uint8_t REGION_WIDTH = 6;
const uint8_t REGION_HEIGHT = 4;

static Image_ErrorCode CreatePixelMap(OH_PixelmapNative **pixelmap)
{
    uint8_t data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = i + 1;
    }
    
    // 创建参数结构体实例，并设置参数。
    OH_Pixelmap_InitializationOptions *createOpts;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, OPTS_WIDTH);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, OPTS_HEIGHT);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);

    Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, DATA_SIZE, createOpts, pixelmap);

    // 读取图像像素数据，结果写入数组里。
    uint8_t destination[DATA_SIZE];
    size_t destinationSize = DATA_SIZE;
    errCode = OH_PixelmapNative_ReadPixels(*pixelmap, destination, &destinationSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_ReadPixels failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 读取缓冲区中的图片数据，结果写入Pixelmap中。
    uint8_t source[DATA_SIZE];
    size_t sourceSize = DATA_SIZE;
    for (int i = 0; i < sourceSize; i++) {
        source[i] = i + 1;
    }
    errCode = OH_PixelmapNative_WritePixels(*pixelmap, source, sourceSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_WritePixels failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 创建图片信息实例，并获取图像像素信息。
    OH_Pixelmap_ImageInfo *imageInfo;
    OH_PixelmapImageInfo_Create(&imageInfo);
    errCode = OH_PixelmapNative_GetImageInfo(*pixelmap, imageInfo);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_GetImageInfo failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 获取图片的宽、高、像素格式、透明度类型等信息。
    uint32_t width, height, rowStride;
    int32_t pixelFormat, alphaType;
    OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
    OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
    OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
    OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
    OH_PixelmapImageInfo_GetAlphaType(imageInfo, &alphaType);
    OH_PixelmapImageInfo_Release(imageInfo);
    OH_LOG_INFO(LOG_APP, "Get image info success, width: %{public}d, height: %{public}d, rowStride: %{public}d, "
        "pixelFormat: %{public}d, alphaType: %{public}d.", width, height, rowStride, pixelFormat, alphaType);
    
    // 使用完毕后释放InitializationOptions实例。
    OH_PixelmapInitializationOptions_Release(createOpts);
    return IMAGE_SUCCESS;
}

static Image_ErrorCode PixelmapTest()
{
    // 创建Pixelmap实例。
    OH_PixelmapNative *pixelmap = nullptr;

    Image_ErrorCode errCode = CreatePixelMap(&pixelmap);
    if (errCode != IMAGE_SUCCESS) {
        return errCode;
    }

    // 设置透明比率来让Pixelmap达到对应的透明效果。
    errCode = OH_PixelmapNative_Opacity(pixelmap, OPACITY_VALUE);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Opacity failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行缩放。
    errCode = OH_PixelmapNative_Scale(pixelmap, SCALE_X, SCALE_Y);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Scale failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行位置变换。
    errCode = OH_PixelmapNative_Translate(pixelmap, TRANSLATE_X, TRANSLATE_Y);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Translate failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行旋转。
    errCode = OH_PixelmapNative_Rotate(pixelmap, ROTATE_ANGLE);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Rotate failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行翻转。
    errCode = OH_PixelmapNative_Flip(pixelmap, true, true);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Flip failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 对图片进行裁剪。
    Image_Region region;
    region.x = REGION_X;
    region.y = REGION_Y;
    region.width = REGION_WIDTH;
    region.height = REGION_HEIGHT;
    errCode = OH_PixelmapNative_Crop(pixelmap, &region);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Crop failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // 使用完毕后释放Pixelmap实例。
    OH_PixelmapNative_Release(pixelmap);
    return IMAGE_SUCCESS;
}

// PixelMap预乘/非预乘格式转换示例。
static Image_ErrorCode PixelmapConvertAlphaTypeTest()
{
    uint8_t data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = i + 1;
    }

    // 创建参数结构体实例，并设置参数。
    OH_Pixelmap_InitializationOptions *createOpts;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, OPTS_WIDTH);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, OPTS_HEIGHT);
    OH_PixelmapInitializationOptions_SetSrcPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED);

    // 创建非预乘格式的位图实例。
    OH_PixelmapNative *srcPixelmap = nullptr;
    Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, DATA_SIZE, createOpts, &srcPixelmap);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "Create srcPixelMap failed, errCode: %{public}d.", errCode);
    }

    // 创建预乘格式的位图实例，该dstPixelmap实例将用于保存srcPixelmap转换AlphaType后的数据。
    OH_PixelmapNative *dstPixelmap = nullptr;
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_PREMULTIPLIED);
    errCode = OH_PixelmapNative_CreatePixelmap(data, DATA_SIZE, createOpts, &dstPixelmap);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "Create dstPixelMap failed, errCode: %{public}d.", errCode);
    }

    // 转换AlphaType，srcPixelmap的数据将被转换为预乘格式，并保存到dstPixelmap中。
    errCode = OH_PixelmapNative_ConvertAlphaFormat(srcPixelmap, dstPixelmap, true);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_ConvertAlphaFormat failed, errCode: %{public}d.", errCode);
    }

    // 释放Pixelmap、InitializationOptions实例。
    OH_PixelmapNative_Release(srcPixelmap);
    OH_PixelmapNative_Release(dstPixelmap);
    OH_PixelmapInitializationOptions_Release(createOpts);
    return errCode;
}
```

**提取图片平均颜色示例**

通过将图片缩放到较小尺寸，遍历所有像素计算RGB平均值来获取图片的主色调。

```c++
#include <hilog/log.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

// 颜色结构体。
struct AverageColor {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

// 提取图片平均颜色。
// 基本思路：
// 1. 将原始PixelMap缩放到较小尺寸（如32像素×32像素），减少像素数量以提高计算效率。
// 2. 读取缩放后的像素数据。
// 3. 遍历所有像素，累加R、G、B通道的值。
// 4. 计算各通道的平均值作为最终颜色。
Image_ErrorCode ExtractAverageColor(OH_PixelmapNative* pixelmap, AverageColor& avgColor)
{
    if (pixelmap == nullptr) {
        OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: pixelmap is nullptr");
        return IMAGE_BAD_PARAMETER;
    }

    // 获取原始图片信息，判断是否需要缩放。
    OH_Pixelmap_ImageInfo* imageInfo;
    OH_PixelmapImageInfo_Create(&imageInfo);
    Image_ErrorCode errCode = OH_PixelmapNative_GetImageInfo(pixelmap, imageInfo);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: GetImageInfo failed, errCode: %{public}d", errCode);
        OH_PixelmapImageInfo_Release(imageInfo);
        return errCode;
    }

    uint32_t width, height;
    OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
    OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
    OH_PixelmapImageInfo_Release(imageInfo);

    // 定义缩小后的目标尺寸（32像素×32像素是经验值，平衡性能和准确度）。
    const uint32_t SAMPLE_SIZE = 32;

    // 如果图片较大，先进行缩放处理。
    if (width > SAMPLE_SIZE || height > SAMPLE_SIZE) {
        // 计算缩放比例。
        double scaleX = (double)SAMPLE_SIZE / width;
        double scaleY = (double)SAMPLE_SIZE / height;

        // 对图片进行缩放。
        errCode = OH_PixelmapNative_Scale(pixelmap, scaleX, scaleY);
        if (errCode != IMAGE_SUCCESS) {
            OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: Scale failed, errCode: %{public}d", errCode);
            return errCode;
        }
    }

    // 重新获取缩放后的图片信息。
    OH_PixelmapImageInfo_Create(&imageInfo);
    errCode = OH_PixelmapNative_GetImageInfo(pixelmap, imageInfo);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: GetImageInfo after scale failed, errCode: %{public}d", errCode);
        OH_PixelmapImageInfo_Release(imageInfo);
        return errCode;
    }

    uint32_t scaledWidth, scaledHeight, rowStride;
    int32_t pixelFormat, alphaType;
    OH_PixelmapImageInfo_GetWidth(imageInfo, &scaledWidth);
    OH_PixelmapImageInfo_GetHeight(imageInfo, &scaledHeight);
    OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
    OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
    OH_PixelmapImageInfo_GetAlphaType(imageInfo, &alphaType);
    OH_PixelmapImageInfo_Release(imageInfo);
    if (pixelFormat != PIXEL_FORMAT_RGBA_8888) {
        // 此案例中只处理RGBA格式。
        return IMAGE_BAD_SOURCE;
    }

    // 读取像素数据。
    size_t bufferSize = rowStride * scaledHeight;
    uint8_t* pixelData = new uint8_t[bufferSize];
    errCode = OH_PixelmapNative_ReadPixels(pixelmap, pixelData, &bufferSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: ReadPixels failed, errCode: %{public}d", errCode);
        delete[] pixelData;
        return errCode;
    }

    // 根据像素格式确定每像素字节数。
    constexpr int bytesPerPixel = 4; // 默认RGBA_8888

    // 累加RGB值。
    uint64_t totalR = 0, totalG = 0, totalB = 0;
    uint32_t pixelCount = 0;

    for (uint32_t y = 0; y < scaledHeight; y++) {
        for (uint32_t x = 0; x < scaledWidth; x++) {
            size_t offset = y * rowStride + x * bytesPerPixel;
            // RGBA_8888格式：R-G-B-A
            totalR += pixelData[offset];
            totalG += pixelData[offset + 1];
            totalB += pixelData[offset + 2];
            pixelCount++;
        }
    }

    // 释放资源。
    delete[] pixelData;
    // 计算平均值。
    if (pixelCount > 0) {
        avgColor.r = (uint8_t)(totalR / pixelCount);
        avgColor.g = (uint8_t)(totalG / pixelCount);
        avgColor.b = (uint8_t)(totalB / pixelCount);
    } else {
        avgColor.r = 0;
        avgColor.g = 0;
        avgColor.b = 0;
    }

    OH_LOG_INFO(LOG_APP,
        "ExtractAverageColor success, avgColor: R=%{public}d, G=%{public}d, B=%{public}d, pixelCount=%{public}d",
        avgColor.r, avgColor.g, avgColor.b, pixelCount);

    return IMAGE_SUCCESS;
}
```
