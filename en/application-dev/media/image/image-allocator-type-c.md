# Allocating Memory for Image Decoding (C/C++)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

When an application performs image decoding, it needs to allocate the corresponding memory. This guide describes different types of memory and how to allocate them.

The application obtains a PixelMap through the decoding API and passes it to the **Image** component for display.

When the PixelMap is large and uses shared memory, the RenderService main thread will experience a longer texture upload time, leading to lag. The zero-copy feature of DMA memory provided by the graphics side can avoid the time cost of texture upload when the system renders images.

## Memory Types

The memory types for the PixelMap are as follows:

- SHARE_MEMORY: shared memory. Texture upload is required.
- DMA_ALLOC: DMA memory. Texture upload is not required.

You can call [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator) to customize the memory allocation type for decoding.

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
  - DMA_ALLOC time consumption: The time of single-frame rendering for a 4K image can be reduced to about 4ms. This optimization is particularly significant in scenarios involving the display of large images and frequent dynamic image loading.

- **Reduced CPU load**

  DMA_ALLOC allows the GPU to directly access decoded data, reducing the load caused by memory copying.

## Default Memory Allocation Method

When [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap) is called for decoding, different memory allocation types are used in different scenarios.

DMA_ALLOC is used in the following scenarios:

- Decoding HDR images.
- Decoding HEIF images.
- Decoding JPEG images, when the original image's width and height are both between 1024 pixels and 8192 pixels, [pixelFormat](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md) is [PIXEL_FORMAT_RGBA_8888](../../reference/apis-image-kit/capi-pixelmap-native-h.md#pixel_format) or [PIXEL_FORMAT_NV21](../../reference/apis-image-kit/capi-pixelmap-native-h.md#pixel_format), and the hardware is not busy (concurrency is 3).
- Decoding images in other formats. The value of [desiredSize](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md) must be greater than or equal to 512 * 512 pixels (consider the original image size if **desiredSize** is not set), and the width must be a multiple of 64.

In all other cases, SHARE_MEMORY is used.

## Custom Memory Allocation Method

By default, the system selects the optimal memory allocation method for performance. In specific scenarios, applications can use a specified memory allocation method.

When you call [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator) for decoding, the system automatically selects hardware or software decoding based on the [decoding options](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md) and [memory application type](../../reference/apis-image-kit/capi-image-source-native-h.md#image_allocator_type).

When creating a PixelMap, the system determines whether to use DMA_ALLOC or SHARE_MEMORY based on the user-specified allocator type.

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
- If the stride does not meet the alignment requirements, the system automatically pads the data.
  The stride value can be obtained by calling [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo).

1. Call [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo) to obtain an OH_Pixelmap_ImageInfo object.
2. Call [OH_PixelmapImageInfo_GetRowStride](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride) to obtain the stride value.

The sample code for obtaining and operating the stride by the C APIs is as follows: Open the **src/main/cpp/CMakeLists.txt** file of the native project, add **libimage_packer.so** and **libhilog_ndk.z.so** (on which the log APIs depend) to the **target_link_libraries** dependency.

```txt
target_link_libraries(entry PUBLIC libhilog_ndk.z.so libimage_source.so libimage_packer.so libpixelmap.so)
```

```C++
#include <cstring>
#include <multimedia/image_framework/image/image_common.h>
#include <multimedia/image_framework/image/pixelmap_native.h>
#include <multimedia/image_framework/image/image_source_native.h>

struct PixelmapInfo {
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t rowStride = 0;
    int32_t pixelFormat = 0;
    uint32_t byteCount = 0;
    uint32_t allocationByteCount = 0;
};

static void GetPixelmapInfo(OH_PixelmapNative *pixelmap, PixelmapInfo *info) {
    OH_Pixelmap_ImageInfo *srcInfo = nullptr;
    OH_PixelmapImageInfo_Create(&srcInfo);
    OH_PixelmapNative_GetImageInfo(pixelmap, srcInfo);
    OH_PixelmapImageInfo_GetWidth(srcInfo, &info->width);
    OH_PixelmapImageInfo_GetHeight(srcInfo, &info->height);
    OH_PixelmapImageInfo_GetRowStride(srcInfo, &info->rowStride);
    OH_PixelmapImageInfo_GetPixelFormat(srcInfo, &info->pixelFormat);
    OH_PixelmapImageInfo_Release(srcInfo);
    return;
}

static void GetPixelmapAddrInfo(OH_PixelmapNative *pixelmap, PixelmapInfo *info) {
    OH_PixelmapNative_GetByteCount(pixelmap, &info->byteCount);
    OH_PixelmapNative_GetAllocationByteCount(pixelmap, &info->allocationByteCount);
    return;
}

int32_t GetPixelFormatBytes(int32_t pixelFormat) {
    switch (pixelFormat) {
        case 2: // PIXEL_FORMAT_RGB_565
            return 2;
        case 3: // PIXEL_FORMAT_RGBA_8888
        case 4: // PIXEL_FORMAT_BGRA_8888
            return 4;
        case 5: // PIXEL_FORMAT_RGB_888
            return 3;
        case 6: // PIXEL_FORMAT_ALPHA_8
            return 1;
        case 7: // PIXEL_FORMAT_RGBA_F16
            return 8; // 16-bit floating-point number per channel, four channels: 4 * 2 bytes = 8 bytes
        case 8: // PIXEL_FORMAT_NV21
        case 9: // PIXEL_FORMAT_NV12'
            // NV21 and NV12 are YUV 4:2:0 semi-planar formats:
            // - The Y component occupies width × height bytes (1 byte per pixel).
            // - The UV components are interleaved (UV or VU) and occupy width × height / 2 bytes.
            // - Total bytes = width × height × 1.5
            // The return type of the function is int32_t, and the function cannot return a decimal number. Therefore, 2 is returned after rounding up.
            // Although the actual average number of bytes per pixel is 1.5, returning 2 ensures secure memory allocation and avoids overflows. The trade-off is that you need to handle the stride carefully.
            return 2; // Semi-planar YUV, use 2 as approximate per-byte-per-pixel
        case 10: // PIXEL_FORMAT_RGBA_1010102
            return 4;
        case 11: // PIXEL_FORMAT_YCBCR_P010
        case 12: // PIXEL_FORMAT_YCRCB_P010
            return 2; // 10-bit YUV format, usually aligned to 16 bits (2 bytes)
        default: // PIXEL_FORMAT_UNKNOWN or unsupported
            return 0;
    }
}

OH_PixelmapNative* TestStrideWithAllocatorType() {
    char* filePath = const_cast<char *>("/data/storage/el2/base/haps/entry/files/test.jpg");
    size_t filePathSize = 1024;
    OH_ImageSourceNative* imageSource = nullptr;
    Image_ErrorCode image_ErrorCode = OH_ImageSourceNative_CreateFromUri(filePath, filePathSize, &imageSource);
    OH_DecodingOptions *options = nullptr;
    OH_DecodingOptions_Create(&options);
    IMAGE_ALLOCATOR_TYPE allocatorType = IMAGE_ALLOCATOR_TYPE::IMAGE_ALLOCATOR_TYPE_DMA;  // Use DMA to create a PixelMap.
    OH_PixelmapNative *pixelmap = nullptr;
    image_ErrorCode = OH_ImageSourceNative_CreatePixelmapUsingAllocator(imageSource, options, allocatorType, &pixelmap);
    PixelmapInfo srcInfo;
    GetPixelmapInfo(pixelmap, &srcInfo);
    GetPixelmapAddrInfo(pixelmap, &srcInfo);

    void *pixels = nullptr;
    OH_PixelmapNative_AccessPixels(pixelmap, &pixels);
    OH_PixelmapNative *newPixelmap = nullptr;
    OH_ImageSourceNative_CreatePixelmap(imageSource, options, &newPixelmap);
    uint32_t dstRowStride = srcInfo.width * GetPixelFormatBytes(srcInfo.pixelFormat);
    void *newPixels = nullptr;
    OH_PixelmapNative_AccessPixels(newPixelmap, &newPixels);
    uint8_t *src = reinterpret_cast<uint8_t *>(pixels);
    uint8_t *dst = reinterpret_cast<uint8_t *>(newPixels);
    uint32_t dstSize = srcInfo.byteCount;
    uint32_t rowSize;
    if (allocatorType == IMAGE_ALLOCATOR_TYPE::IMAGE_ALLOCATOR_TYPE_DMA) { 
        rowSize = srcInfo.rowStride; 
    } else {
        rowSize = dstRowStride;
    }
    for (uint32_t i = 0; i < srcInfo.height; ++i) {
        memcpy(dst, src, dstRowStride);
        src += rowSize;
        dst += dstRowStride;
        dstSize -= dstRowStride;
    }
    OH_PixelmapNative_UnaccessPixels(newPixelmap);
    OH_PixelmapNative_UnaccessPixels(pixelmap);
    OH_DecodingOptions_Release(options);
    OH_ImageSourceNative_Release(imageSource);
    return newPixelmap;
}
```
