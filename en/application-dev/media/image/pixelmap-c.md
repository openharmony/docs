# Using Image_NativeModule for PixelMap Operations

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=ba3f6c99832577d149cf0c227912c266e5256745 translatedAt=2026-08-11T01:49:23.955Z pushedAt=2026-08-11T10:12:31.919Z -->

You can use the **Pixelmap** class to create, operate, and release a PixelMap, and obtain its width, height, pixel format, alpha type, and row stride.

## How to Develop

### Adding a Link Library

Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libpixelmap.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)
```

### Calling the Native APIs

For details about the APIs, see [Image_NativeModule](../../reference/apis-image-kit/capi-image-nativemodule.md).

When creating a Native C++ app in DevEco Studio, the generated project includes an `index.ets` file by default, and a `cpp` file (`hello.cpp` or `napi_init.cpp`; this example uses `hello.cpp` as the file name) is automatically generated in the `entry\src\main\cpp` directory. Implement the C API call logic in `hello.cpp`. The sample code is as follows:

**Example of Using the Pixelmap APIs**

Create a Pixelmap instance after parameter initialization, read and write pixel data, and perform operations such as scaling, translating, flipping, rotating, and cropping on the image.

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
    
    // Create a parameter struct instance and set parameters.
    OH_Pixelmap_InitializationOptions *createOpts;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, OPTS_WIDTH);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, OPTS_HEIGHT);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNKNOWN);

    Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, DATA_SIZE, createOpts, pixelmap);

    // Read image pixel data and write the result into the array.
    uint8_t destination[DATA_SIZE];
    size_t destinationSize = DATA_SIZE;
    errCode = OH_PixelmapNative_ReadPixels(*pixelmap, destination, &destinationSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_ReadPixels failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Read image data from the buffer and write the result into the PixelMap.
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

    // Create an image information instance and obtain image pixel information.
    OH_Pixelmap_ImageInfo *imageInfo;
    OH_PixelmapImageInfo_Create(&imageInfo);
    errCode = OH_PixelmapNative_GetImageInfo(*pixelmap, imageInfo);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_GetImageInfo failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Obtain the image width, height, pixel format, alpha type, and other information.
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
    
    // Release the InitializationOptions instance after use.
    OH_PixelmapInitializationOptions_Release(createOpts);
    return IMAGE_SUCCESS;
}

static Image_ErrorCode PixelmapTest()
{
    // Create a PixelMap instance.
    OH_PixelmapNative *pixelmap = nullptr;

    Image_ErrorCode errCode = CreatePixelMap(&pixelmap);
    if (errCode != IMAGE_SUCCESS) {
        return errCode;
    }

    // Set the opacity ratio to achieve the corresponding transparency effect on the PixelMap.
    errCode = OH_PixelmapNative_Opacity(pixelmap, OPACITY_VALUE);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Opacity failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Scale the image.
    errCode = OH_PixelmapNative_Scale(pixelmap, SCALE_X, SCALE_Y);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Scale failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Translate the image.
    errCode = OH_PixelmapNative_Translate(pixelmap, TRANSLATE_X, TRANSLATE_Y);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Translate failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Rotate the image.
    errCode = OH_PixelmapNative_Rotate(pixelmap, ROTATE_ANGLE);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Rotate failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Flip the image.
    errCode = OH_PixelmapNative_Flip(pixelmap, true, true);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_Flip failed, errCode: %{public}d.", errCode);
        return errCode;
    }

    // Crop the image.
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

    // Release the PixelMap instance after use.
    OH_PixelmapNative_Release(pixelmap);
    return IMAGE_SUCCESS;
}

// Example of PixelMap premultiplied/non-premultiplied format conversion.
static Image_ErrorCode PixelmapConvertAlphaTypeTest()
{
    uint8_t data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = i + 1;
    }

    // Create a parameter struct instance and set parameters.
    OH_Pixelmap_InitializationOptions *createOpts;
    OH_PixelmapInitializationOptions_Create(&createOpts);
    OH_PixelmapInitializationOptions_SetWidth(createOpts, OPTS_WIDTH);
    OH_PixelmapInitializationOptions_SetHeight(createOpts, OPTS_HEIGHT);
    OH_PixelmapInitializationOptions_SetSrcPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetPixelFormat(createOpts, PIXEL_FORMAT_RGBA_8888);
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED);

    // Create a pixel map instance in non-premultiplied format.
    OH_PixelmapNative *srcPixelmap = nullptr;
    Image_ErrorCode errCode = OH_PixelmapNative_CreatePixelmap(data, DATA_SIZE, createOpts, &srcPixelmap);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "Create srcPixelMap failed, errCode: %{public}d.", errCode);
    }

    // Create a pixel map instance in premultiplied format. This dstPixelmap instance will be used to store the data after converting the AlphaType of srcPixelmap.
    OH_PixelmapNative *dstPixelmap = nullptr;
    OH_PixelmapInitializationOptions_SetAlphaType(createOpts, PIXELMAP_ALPHA_TYPE_PREMULTIPLIED);
    errCode = OH_PixelmapNative_CreatePixelmap(data, DATA_SIZE, createOpts, &dstPixelmap);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "Create dstPixelMap failed, errCode: %{public}d.", errCode);
    }

    // Convert the AlphaType. The data of srcPixelmap will be converted to premultiplied format and saved to dstPixelmap.
    errCode = OH_PixelmapNative_ConvertAlphaFormat(srcPixelmap, dstPixelmap, true);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "OH_PixelmapNative_ConvertAlphaFormat failed, errCode: %{public}d.", errCode);
    }

    // Release the PixelMap and InitializationOptions instances.
    OH_PixelmapNative_Release(srcPixelmap);
    OH_PixelmapNative_Release(dstPixelmap);
    OH_PixelmapInitializationOptions_Release(createOpts);
    return errCode;
}
```

**Example of Extracting the Average Color of an Image**

The dominant color of an image is obtained by scaling the image to a smaller size and then iterating through all pixels to calculate the RGB average.

```c++
#include <hilog/log.h>
#include <multimedia/image_framework/image/pixelmap_native.h>

// Color structure.
struct AverageColor {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

// Extract the average color of the image.
// Basic approach:
// 1. Scale the original PixelMap to a smaller size (e.g., 32×32 pixels) to reduce the pixel count and improve computation efficiency.
// 2. Read the scaled pixel data.
// 3. Traverse all pixels and accumulate the R, G, and B channel values.
// 4. Calculate the average value of each channel as the final color.
Image_ErrorCode ExtractAverageColor(OH_PixelmapNative* pixelmap, AverageColor& avgColor)
{
    if (pixelmap == nullptr) {
        OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: pixelmap is nullptr");
        return IMAGE_BAD_PARAMETER;
    }

    // Obtain the original image information to determine whether scaling is needed.
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

    // Define the target size after scaling down (32×32 pixels is an empirical value that balances performance and accuracy).
    const uint32_t SAMPLE_SIZE = 32;

    // If the image is large, perform scaling first.
    if (width > SAMPLE_SIZE || height > SAMPLE_SIZE) {
        // Calculate the scaling ratio.
        double scaleX = (double)SAMPLE_SIZE / width;
        double scaleY = (double)SAMPLE_SIZE / height;

        // Scale the image.
        errCode = OH_PixelmapNative_Scale(pixelmap, scaleX, scaleY);
        if (errCode != IMAGE_SUCCESS) {
            OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: Scale failed, errCode: %{public}d", errCode);
            return errCode;
        }
    }

    // Obtain the image information again after scaling.
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
        // Only the RGBA format is processed in this case.
        return IMAGE_BAD_SOURCE;
    }

    // Read the pixel data.
    size_t bufferSize = rowStride * scaledHeight;
    uint8_t* pixelData = new uint8_t[bufferSize];
    errCode = OH_PixelmapNative_ReadPixels(pixelmap, pixelData, &bufferSize);
    if (errCode != IMAGE_SUCCESS) {
        OH_LOG_ERROR(LOG_APP, "ExtractAverageColor: ReadPixels failed, errCode: %{public}d", errCode);
        delete[] pixelData;
        return errCode;
    }

    // Determine the number of bytes per pixel based on the pixel format.
    constexpr int bytesPerPixel = 4; // Default RGBA_8888

    // Accumulate the RGB values.
    uint64_t totalR = 0, totalG = 0, totalB = 0;
    uint32_t pixelCount = 0;

    for (uint32_t y = 0; y < scaledHeight; y++) {
        for (uint32_t x = 0; x < scaledWidth; x++) {
            size_t offset = y * rowStride + x * bytesPerPixel;
            // RGBA_8888 format: R-G-B-A
            totalR += pixelData[offset];
            totalG += pixelData[offset + 1];
            totalB += pixelData[offset + 2];
            pixelCount++;
        }
    }

    // Release resources.
    delete[] pixelData;
    // Calculate the average value.
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