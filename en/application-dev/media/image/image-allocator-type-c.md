# Image Decoding Memory Optimization (C/C++)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:42:46.183Z pushedAt=2026-08-11T03:01:43.186Z -->

When performing image decoding, an app needs to request the corresponding memory. The memory usage is closely related to the memory allocation type and pixel format. This guide introduces different memory types and pixel formats, and explains how to combine them for optimal decoding performance.

The application obtains a PixelMap through the decoding API and passes it to the **Image** component for display.

When a PixelMap is large and uses shared memory, the RS main thread experiences a long texture upload time, causing frame drops. The graphics subsystem provides the DMA memory zero-copy feature, which avoids texture upload time consumption during image drawing. In addition, setting an appropriate pixel format (such as YUV) can further reduce memory usage.

## Memory Types

The memory types for the PixelMap are as follows:

- SHARE_MEMORY: shared memory. Texture upload is required.

- DMA_ALLOC: DMA memory. Texture upload is not required.

The system provides the [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator) API, allowing you to customize the memory allocation type for decoding. For details about the API definition and usage examples, see the image decoding API description in [image_source_native.h](../../reference/apis-image-kit/capi-image-source-native-h.md).

### Differences Between SHARE_MEMORY and DMA_ALLOC

| Item              | SHARE_MEMORY                                | DMA_ALLOC              |
| ------------------ | --------------------- | ----------------------------------------- |
| Definition              | Shared memory (such as ashmem/anonymous sharing) provided by the operating system, allowing multiple processes to read/write the same physical pages.| Buffers allocated for direct DMA access by peripherals, GPU, or display pipelines. Common implementations include dmabuf and SurfaceBuffer, designed for zero-copy operations.|
| Working principle          | Processes access a shared memory region via the CPU. Transferring this data to GPU or display pipelines typically requires a copy.| Data is written directly to the buffer (for example, by a decoder via DMA), which the GPU or display pipelines can then access without any copying.|
| Use case          | Inter-process or inter-thread data sharing (for example, exchanging intermediate results in algorithms or post-processing).| High-bandwidth data transfer scenarios such as hardware decoding of images/videos, camera preview, and display rendering.|
| CPU usage           | The CPU is involved in managing and synchronizing shared memory (for example, locking and unlocking), which incurs additional overhead.| Extremely low CPU usage: The CPU is only involved in the configuration of the DMA controller, with no intervention in actual data transfer.|
| Hardware dependency          | Dependent on the shared memory mechanism of the operating system.| Strongly dependent on the hardware DMA controller.|
| Memory allocation and access permissions| The system allocates physical or virtual memory areas for shared memory, with access requiring user or kernel mapping operations.| The DMA controller directly operates the physical memory, requiring pre-allocated DMA buffers (usually contiguous memory).|
| Advantages              | High flexibility. Supports simultaneous data sharing by multiple threads or processes, facilitating image post-processing and collaboration.| High efficiency and low latency, suitable for transfer of large data volumes and continuous data blocks.|
| Disadvantages              | Shared memory operations require additional synchronization mechanisms, increasing programming complexity and CPU load.| Hardware support is required, and the data transfer range is limited by DMA address space (usually requiring contiguous physical memory).|

### Advantages of Using DMA_ALLOC Memory

- **Reduced texture upload time**

  When SHARE_MEMORY is used, image data needs to be copied to GPU memory through the CPU, increasing the texture upload time. With DMA_ALLOC, data is directly stored in memory that is accessible by the GPU, avoiding the time-consuming copy process.

  - SHARE_MEMORY time consumption: Single-frame rendering of a 4K image takes about 20 ms.

  - DMA_ALLOC time consumption: The time of single-frame rendering for a 4K image can be reduced to about 4 ms. This optimization is particularly significant in scenarios involving the display of large images and frequent dynamic image loading.

- **Reduced CPU load**

  DMA_ALLOC allows the GPU to directly access decoded data, reducing the load caused by memory copying.

> **NOTE**
>
> When using DMA_ALLOC, you must pay attention to the difference between the stride and the image width, and perform alignment before data reading, parsing, and display.

### Restrictions

The current image decoding feature has the following restrictions on memory allocation modes:

- HDR image decoding supports only DMA_ALLOC.

- Hardware decoding supports only DMA_ALLOC.

- SVG image decoding supports only SHARE_MEMORY.

When [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator) is used for decoding, if the specified memory allocation mode does not match the image format or decoding method, an exception indicating a memory allocation failure is thrown.

If the allocation type is set to AUTO, the system determines whether to use DMA_ALLOC or SHARE_MEMORY based on the decoding and rendering time.

Different memory allocation strategies can result in differences in the stride of the image. For memory allocated by using DMA_ALLOC, the stride must be used for operations such as editing on the PixelMap. The following describes how to obtain the stride.

### Obtaining the Stride

The stride describes the storage width of each row of pixel data of an image in memory. It is an important parameter in the image drawing process and is used to correctly locate the layout of the image data in the memory.

When memory is allocated using DMA_ALLOC, the stride must meet the hardware alignment requirements.

- The stride value must be an integer multiple of the number of bytes required by the hardware platform.

- When the stride value is greater than the image width, the system automatically pads the data.

  The stride value can be obtained by calling [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo).

1. Call [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo) to obtain an OH_Pixelmap_ImageInfo object.

2. Call [OH_PixelmapImageInfo_GetRowStride](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride) to obtain the stride value.

The sample code for obtaining and operating the stride by the C APIs is as follows. Before using the sample code, open the **src/main/cpp/CMakeLists.txt** file of the native project, and add **libimage_source.so** and the logging dependency **libhilog_ndk.z.so** to **target_link_libraries**.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libimage_packer.so libpixelmap.so)
```

> **NOTE**
>
> Certain APIs are supported only in API version 20 or later. You should select an appropriate API version during development.

1. Create the **GetJsResult** function to process the NAPI return value.

   <!-- @[get_returnValue](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/napi_init.cpp) -->    

   ``` C++
   // Process the NAPI return value.
   napi_value GetJsResult(napi_env env, int result)
   {
       napi_value resultNapi = nullptr;
       napi_create_int32(env, result, &resultNapi);
       return resultNapi;
   }
   ```

2. Obtain and manipulate the stride value.

   <!-- @[allocator_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAllocator.cpp) -->      

   ``` C++
   #include <cstring>
   #include <hilog/log.h>
   #include <multimedia/image_framework/image/image_common.h>
   #include <multimedia/image_framework/image/pixelmap_native.h>
   #include <multimedia/image_framework/image/image_source_native.h>
   // ...
   
   // Return the number of bytes per pixel based on the pixel format.
   int32_t GetPixelFormatBytes(int32_t pixelFormat)
   {
       switch (pixelFormat) {
           case PIXEL_FORMAT_RGB_565:
               return 2; // 2 bytes per pixel.
           case PIXEL_FORMAT_RGBA_8888:
           case PIXEL_FORMAT_BGRA_8888:
               return 4; // 4 bytes per pixel.
           case PIXEL_FORMAT_RGB_888:
               return 3; // 3 bytes per pixel.
           case PIXEL_FORMAT_ALPHA_8:
               return 1; // 1 byte per pixel.
           case PIXEL_FORMAT_RGBA_F16:
               return 8; // 8 bytes per pixel (since there are 16-bit floating-point number per channel and 4 channels in total).
           case PIXEL_FORMAT_NV21:
           case PIXEL_FORMAT_NV12:
               // NV21 and NV12 are YUV 4:2:0 semi-planar formats, and the row stride cannot be calculated using an integer number of bytes per pixel.
               return 0;
           case PIXEL_FORMAT_RGBA_1010102:
               return 4; // 4 bytes per pixel.
           case PIXEL_FORMAT_YCBCR_P010:
           case PIXEL_FORMAT_YCRCB_P010:
               return 2; // 2 bytes per pixel.
           default:
               return 0; // If the pixel format is unknown, 0 is returned.
       }
   }
   
   struct PixelmapInfo {
       uint32_t width = 0;
       uint32_t height = 0;
       uint32_t rowStride = 0;
       int32_t pixelFormat = 0;
       uint32_t byteCount = 0;
       uint32_t allocationByteCount = 0;
   };
   
   static void GetPixelmapInfo(OH_PixelmapNative *pixelmap, PixelmapInfo *info)
   {
       OH_Pixelmap_ImageInfo *srcInfo = nullptr;
       OH_PixelmapImageInfo_Create(&srcInfo);
       OH_PixelmapNative_GetImageInfo(pixelmap, srcInfo);
       OH_PixelmapImageInfo_GetWidth(srcInfo, &info->width);
       OH_PixelmapImageInfo_GetHeight(srcInfo, &info->height);
       OH_PixelmapImageInfo_GetRowStride(srcInfo, &info->rowStride);
       OH_PixelmapImageInfo_GetPixelFormat(srcInfo, &info->pixelFormat);
       OH_PixelmapImageInfo_Release(srcInfo);
       srcInfo = nullptr;
       return;
   }
   
   static void GetPixelmapAddrInfo(OH_PixelmapNative *pixelmap, PixelmapInfo *info)
   {
       OH_PixelmapNative_GetByteCount(pixelmap, &info->byteCount);
       OH_PixelmapNative_GetAllocationByteCount(pixelmap, &info->allocationByteCount);
       return;
   }
   
   static void CopyPixelRows(void *pixels, void *newPixels, const PixelmapInfo &srcInfo, uint32_t dstRowStride,
       IMAGE_ALLOCATOR_TYPE allocatorType)
   {
       uint8_t *src = reinterpret_cast<uint8_t *>(pixels);
       uint8_t *dst = reinterpret_cast<uint8_t *>(newPixels);
       uint32_t dstSize = srcInfo.byteCount;
       uint32_t rowSize = allocatorType == IMAGE_ALLOCATOR_TYPE::IMAGE_ALLOCATOR_TYPE_DMA ? srcInfo.rowStride :
           dstRowStride;
       for (uint32_t i = 0; i < srcInfo.height; ++i) {
           if (dstSize >= dstRowStride) {
               std::copy(src, src + dstRowStride, dst);
           } else {
               break;
           }
           src += rowSize;
           dst += dstRowStride;
           dstSize -= dstRowStride;
       }
   }
   
   void DataCopy(OH_PixelmapNative *pixelmap, OH_ImageSourceNative* imageSource, OH_DecodingOptions *options,
                 IMAGE_ALLOCATOR_TYPE allocatorType)
   {
       PixelmapInfo srcInfo;
       GetPixelmapInfo(pixelmap, &srcInfo);
       GetPixelmapAddrInfo(pixelmap, &srcInfo);
       void *pixels = nullptr;
       OH_PixelmapNative_AccessPixels(pixelmap, &pixels);
       OH_PixelmapNative *newPixelmap = nullptr;
       Image_ErrorCode image_ErrorCode = OH_ImageSourceNative_CreatePixelmap(imageSource, options, &newPixelmap);
       if (image_ErrorCode != IMAGE_SUCCESS || newPixelmap == nullptr) {
           OH_PixelmapNative_UnaccessPixels(pixelmap);
           OH_DecodingOptions_Release(options);
           OH_ImageSourceNative_Release(imageSource);
           OH_PixelmapNative_Release(pixelmap);
           if (newPixelmap != nullptr) {
               OH_PixelmapNative_Release(newPixelmap);
           }
           return;
       }
       int32_t pixelBytes = GetPixelFormatBytes(srcInfo.pixelFormat);
       if (pixelBytes == 0) {
           OH_PixelmapNative_UnaccessPixels(pixelmap);
           OH_DecodingOptions_Release(options);
           OH_ImageSourceNative_Release(imageSource);
           OH_PixelmapNative_Release(pixelmap);
           OH_PixelmapNative_Release(newPixelmap);
           return;
       }
       uint32_t dstRowStride = srcInfo.width * pixelBytes;
       void *newPixels = nullptr;
       OH_PixelmapNative_AccessPixels(newPixelmap, &newPixels);
       CopyPixelRows(pixels, newPixels, srcInfo, dstRowStride, allocatorType);
       OH_PixelmapNative_UnaccessPixels(newPixelmap);
       OH_PixelmapNative_UnaccessPixels(pixelmap);
       OH_DecodingOptions_Release(options);
       options = nullptr;
       OH_ImageSourceNative_Release(imageSource);
       imageSource = nullptr;
       OH_PixelmapNative_Release(pixelmap);
       pixelmap = nullptr;
       OH_PixelmapNative_Release(newPixelmap);
       newPixelmap = nullptr;
   }
   
   napi_value TestStrideWithAllocatorType(napi_env env, napi_callback_info info)
   {
       napi_value argValue[1] = {nullptr};
       size_t argCount = 1;
       if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < 1 ||
           argValue[0] == nullptr) {
           OH_LOG_ERROR(LOG_APP, "CreateImageSource napi_get_cb_info failed!");
           return GetJsResult(env, IMAGE_BAD_PARAMETER);
       }
       
       const size_t maxPathLength = 1024;
       char filePath[maxPathLength];
       size_t pathSize = maxPathLength;
       napi_get_value_string_utf8(env, argValue[0], filePath, maxPathLength, &pathSize);
   
       OH_ImageSourceNative* imageSource = nullptr;
       Image_ErrorCode image_ErrorCode = OH_ImageSourceNative_CreateFromUri(filePath, pathSize, &imageSource);
       if (image_ErrorCode != IMAGE_SUCCESS || imageSource == nullptr) {
           return GetJsResult(env, image_ErrorCode == IMAGE_SUCCESS ? IMAGE_BAD_PARAMETER : image_ErrorCode);
       }
       OH_DecodingOptions *options = nullptr;
       image_ErrorCode = OH_DecodingOptions_Create(&options);
       if (image_ErrorCode != IMAGE_SUCCESS || options == nullptr) {
           OH_ImageSourceNative_Release(imageSource);
           return GetJsResult(env, image_ErrorCode == IMAGE_SUCCESS ? IMAGE_BAD_PARAMETER : image_ErrorCode);
       }
       IMAGE_ALLOCATOR_TYPE allocatorType = IMAGE_ALLOCATOR_TYPE::IMAGE_ALLOCATOR_TYPE_DMA;  // Use DMA to create a PixelMap.
       OH_PixelmapNative *pixelmap = nullptr;
       image_ErrorCode = OH_ImageSourceNative_CreatePixelmapUsingAllocator(imageSource, options, allocatorType, &pixelmap);
       if (image_ErrorCode != IMAGE_SUCCESS || pixelmap == nullptr) {
           OH_DecodingOptions_Release(options);
           OH_ImageSourceNative_Release(imageSource);
           return GetJsResult(env, image_ErrorCode == IMAGE_SUCCESS ? IMAGE_BAD_PARAMETER : image_ErrorCode);
       }
       DataCopy(pixelmap, imageSource, options, allocatorType);
       return GetJsResult(env, image_ErrorCode);
   }
   ```

## Pixel Format

The pixel format after image decoding directly affects the memory usage. The main supported pixel formats are as follows.

### Differences Between RGBA_8888 and YUV Formats

| Name | RGBA_8888 | NV21/NV12 (YUV 4:2:0) |
| -- | -- | -- |
| Definition | Color information consists of four components: R (Red), G (Green), B (Blue), and Alpha (transparency). Each component occupies 8 bits, totaling 32 bits. | Color information consists of the luminance component Y and interleaved chrominance components UV. The Y component occupies 8 bits, and the UV components occupy an average of 4 bits due to 4:2:0 sampling, totaling an average of 12 bits. |
| Bytes per Pixel | 4 bytes | Approximately 1.5 bytes |
| Memory Usage Calculation | Width × height × 4 | Width × height × 1.5 |
| Applicable Scenarios | Scenarios that require Alpha channel processing, such as transparency compositing and shadow effects. | Scenarios such as image preview and display, with low memory usage, suitable for decoding large images. |
| Advantages | Supports complete Alpha channel operations with good compatibility. | Low memory usage. JPEG hardware decoding can directly output, avoiding format conversion overhead. |

### Advantages of Using YUV Format

- **Significantly reduces memory usage**

  Taking a 4K image (3840×2160) as an example:

  - RGBA_8888 memory usage: 3840 × 2160 × 4 ≈ 33.2 MB

  - NV21 memory usage: 3840 × 2160 × 1.5 ≈ 12.4 MB

  - Memory savings of approximately 62.5%, effectively reducing app memory pressure.

- **Reduces format conversion overhead**

  During hardware decoding of images in formats such as JPEG, the decoder can directly output YUV format data, reducing format conversion overhead.

> **NOTE**
>
> - SVG and TIFF images do not support decoding to YUV pixel format.
> - The YUV format does not include an Alpha channel. For images that require transparency, use the RGBA_8888 format.

### Setting YUV Pixel Format

When decoding with the YUV format, set the pixel format through OH_DecodingOptions_SetPixelFormat. It is recommended to use it together with DMA memory allocation.

<!-- @[allocator_yuv_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageNativeSample/entry/src/main/cpp/loadAllocator.cpp) -->

``` C++
napi_value CreatePixelmapWithYUV(napi_env env, napi_callback_info info)
{
    napi_value argValue[1] = {nullptr};
    size_t argCount = 1;
    if (napi_get_cb_info(env, info, &argCount, argValue, nullptr, nullptr) != napi_ok || argCount < 1 ||
        argValue[0] == nullptr) {
        OH_LOG_ERROR(LOG_APP, "CreatePixelmapWithYUV napi_get_cb_info failed!");
        return GetJsResult(env, IMAGE_BAD_PARAMETER);
    }
    const size_t maxPathLength = 1024;
    char filePath[maxPathLength];
    size_t pathSize = maxPathLength;
    napi_get_value_string_utf8(env, argValue[0], filePath, maxPathLength, &pathSize);

    OH_ImageSourceNative* imageSource = nullptr;
    Image_ErrorCode errorCode = OH_ImageSourceNative_CreateFromUri(filePath, pathSize, &imageSource);
    
    OH_DecodingOptions *options = nullptr;
    OH_DecodingOptions_Create(&options);
    // Set the YUV pixel format (NV21 or NV12) to optimize memory usage.
    OH_DecodingOptions_SetPixelFormat(options, PIXEL_FORMAT_NV21);
    
    // Use DMA memory allocation with the YUV format for optimal decoding performance.
    IMAGE_ALLOCATOR_TYPE allocatorType = IMAGE_ALLOCATOR_TYPE::IMAGE_ALLOCATOR_TYPE_DMA;
    OH_PixelmapNative *pixelmap = nullptr;
    errorCode = OH_ImageSourceNative_CreatePixelmapUsingAllocator(imageSource, options, allocatorType, &pixelmap);
    if (errorCode == IMAGE_SUCCESS && pixelmap != nullptr) {
        // Obtain PixelMap information and verify the pixel format.
        OH_Pixelmap_ImageInfo *imageInfo = nullptr;
        OH_PixelmapImageInfo_Create(&imageInfo);
        OH_PixelmapNative_GetImageInfo(pixelmap, imageInfo);
        
        uint32_t width;
        uint32_t height;
        uint32_t rowStride;
        int32_t pixelFormat;
        OH_PixelmapImageInfo_GetWidth(imageInfo, &width);
        OH_PixelmapImageInfo_GetHeight(imageInfo, &height);
        OH_PixelmapImageInfo_GetRowStride(imageInfo, &rowStride);
        OH_PixelmapImageInfo_GetPixelFormat(imageInfo, &pixelFormat);
        OH_LOG_INFO(LOG_APP, "YUV PixelMap created: width=%{public}u, height=%{public}u, "
                    "rowStride=%{public}u, pixelFormat=%{public}d",
                    width, height, rowStride, pixelFormat);
        OH_PixelmapImageInfo_Release(imageInfo);
    } else {
        OH_LOG_ERROR(LOG_APP, "CreatePixelmapWithYUV failed, errorCode=%{public}d", errorCode);
    }
    
    OH_DecodingOptions_Release(options);
    options = nullptr;
    OH_ImageSourceNative_Release(imageSource);
    imageSource = nullptr;
    return GetJsResult(env, errorCode);
}
```

## Default System Memory Allocation

When [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap) is called for decoding, different memory allocation types are used in different scenarios.

DMA_ALLOC is used in the following scenarios:

- Decoding HDR images

- Decoding HEIF images

- Decoding JPEG images, when the original image width and height are both between 1024 and 8192 pixels, [PIXEL_FORMAT](../../reference/apis-image-kit/capi-pixelmap-native-h.md#pixel_format) is PIXEL_FORMAT_RGBA_8888 or PIXEL_FORMAT_NV21, and the hardware is not busy (concurrency is 3).

- Decoding images in other formats, when **desiredSize** in [OH_DecodingOptions](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md) is greater than or equal to 512 × 512 pixels (the original image size is used if **desiredSize** is not set), and the width is a multiple of 64.

In all other scenarios, SHARE_MEMORY is used.

## Memory Restrictions for Decoding a Single Image

To prevent system crashes from memory overflow, the system enforces memory restrictions on processes. For details, see [Application-Killed Issues Detection](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-runtime-appkilled-detection).

The image framework imposes a 2 GB memory limit for decoding a single image. Processes should actively manage their own memory. You are advised to release [OH_PixelmapNative](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md) in a timely manner when it is no longer in use, to avoid process termination by the system.

Applications can use [onMemoryLevel](../../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onmemorylevel) to listen for system memory changes.

The calculation rule for PixelMap memory allocation is as follows:

```TypeScript
pixels_size (pixel memory size) = stride (image pixel storage width) * height (image pixel height)
```

For images with original pixel memory exceeding 2 GB and supporting downsampling, you are advised to use [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap) or [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator) and set **desiredSize** in [OH_DecodingOptions](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md) for downsampling decoding.

Starting from API version 21, for images that support downsampling decoding, when **desiredSize** (expected output size) is set, the decoder calculates PixelMap pixel memory at the optimal downsampling rate with a base gradient of 1/8. This means that it selects the highest clarity sampling rate among 7/8, 6/8, ..., 1/8.

The table below lists the downsampling decoding support for different image formats in the image framework.

| Support for Downsampling| Image Format                                                 |
| ------------ | --------------------------------------------------------- |
| Supported         | .jpg, .png, .heic (Refer to the device specification document for specific support.)|
| Not supported       | .gif, .bmp, .webp, .dng, .svg, .ico|