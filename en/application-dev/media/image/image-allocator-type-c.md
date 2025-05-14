# Allocating Memory for Image Decoding (C/C++)

When an application performs image decoding, it needs to allocate the corresponding memory. This guide describes different types of memory and how to allocate them.

The application obtains a PixelMap through the decoding API and passes it to the **Image** component for display.

When the PixelMap is large and uses regular memory, the RenderService main thread will experience a longer texture upload time, leading to lag. The zero-copy feature of DMA memory provided by the graphics side can avoid the time cost of texture upload when the system renders images of the same size.

## Memory Types

The memory types for the PixelMap are as follows:

- DMA_ALLOC: ION memory. IPC latency is relatively low, and texture upload is not required.
- SHARE_MEMORY: shared memory. IPC latency is minimal, but texture upload is required.

Given that the current memory allocation strategy of the decoding API cannot meet the requirements in certain scenarios, the system provides [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmapusingallocator), allowing you to customize the memory allocation type for decoding.

### Differences Between DMA_ALLOC and SHARE_MEMORY

| Item              | DMA_ALLOC                                                               | SHARE_MEMORY                                                                             |
| ------------------ | ----------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| Definition              | The hardware decoder directly transfers decoded image data to memory or video memory without CPU intervention.        | The memory sharing mechanism provided by the operating system allows multiple threads and processes to directly access the same physical memory for collaborative image data processing.|
| Working principle          | The decoder uses the DMA controller to directly transfer the decoded image data from the device to memory or display buffer.| Image data decoded by the GPU is directly mapped into shared memory for collaborative processing or access by multiple threads or processes.                 |
| Use case          | Used for high-speed data transfer.                                                     | Used for data sharing between processes or threads.                                                            |
| CPU usage           | Extremely low CPU usage: The CPU is only involved in the configuration of the DMA controller, with no intervention in actual data transfer.          | The CPU is involved in managing and synchronizing shared memory (for example, locking and unlocking), which incurs additional overhead.                         |
| Hardware dependency          | Strongly dependent on the hardware DMA controller.                                                  | Dependent on the shared memory mechanism of the operating system.                                                        |
| Memory allocation and access permissions| The DMA controller directly operates the physical memory, requiring pre-allocated DMA buffers (usually contiguous memory).     | The system allocates physical or virtual memory areas for shared memory, with access requiring user or kernel mapping operations.                    |
| Advantages              | High efficiency and low latency, suitable for transfer of large data volumes and continuous data blocks.                         | High flexibility. Supports simultaneous data sharing by multiple threads or processes, facilitating image post-processing and collaboration.                        |
| Disadvantages              | Hardware support is required, and the data transfer range is limited by DMA address space (usually requiring contiguous physical memory).  | Shared memory operations require additional synchronization mechanisms, increasing programming complexity and CPU load.                               |
| Use in the decoding workflow| The hardware decoder directly outputs data to the target memory through DMA without CPU intervention.                 | After the decoding is complete, the data is stored in the shared memory for other processes or threads to read and process.                                |

### Advantages of Using DMA_ALLOC Memory

- **Reduced texture upload time**

  When SHARE_MEMORY is used, image data needs to be copied to GPU memory through the CPU, increasing the texture upload time. With DMA_ALLOC, data is directly stored in memory that is accessible by the GPU, avoiding the time-consuming copy process.

  - Traditional upload time: For a 4K image, a single frame rendering takes about 20 ms.
  - DMA_ALLOC upload time: For a 4K image, the time for a single frame rendering can be reduced to about 4 ms. This optimization is particularly significant in scenarios involving the display of large images and frequent dynamic image loading.
- **Reduced CPU load**

  DMA_ALLOC allows the GPU to directly access decoded data, reducing the load caused by memory copying.

## Default Memory Allocation Method

When [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmap) is called for decoding, different memory allocation types are used in different scenarios.

DMA_ALLOC is used in the following scenarios:

- Decoding HDR images.
- Decoding HEIF images.
- Decoding JPEG images, when the original image's width and height are both between 1024 and 8192, [desiredPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions) is RGBA_8888 or NV21, and the hardware is not busy (concurrency is 3).
- Decoding images in other formats. The value of [desiredSize](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions) must be greater than or equal to 512 * 512 (consider the original image size if **desiredSize** is not set), and the width must be a multiple of 64.

In all other cases, SHARE_MEMORY is used.

## Custom Memory Allocation Method

By default, the system selects the optimal memory allocation method for performance. In specific scenarios, applications can use a specified memory allocation method.

When you call [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmapusingallocator) for decoding, the system automatically selects hardware or software decoding based on the [decoding options](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions) and [memory application type](../../reference/apis-image-kit/_image___native_module.md#image_allocator_type).

When creating a PixelMap, the system determines whether to use DMA_ALLOC or SHARE_MEMORY based on the user-specified allocator type.

### Restrictions

The current image decoding feature has the following restrictions on memory allocation modes:

- HDR image decoding supports only DMA_ALLOC.
- Hardware decoding supports only DMA_ALLOC.
- SVG image decoding supports only SHARE_MEMORY.

When [OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmapusingallocator) is used for decoding, if the specified memory allocation mode does not match the image format or decoding method, an exception indicating a memory allocation failure is thrown.

If the allocation type is set to AUTO, the system determines whether to use DMA_ALLOC or SHARE_MEMORY based on the decoding and rendering time.

Different memory allocation strategies can result in differences in the stride of the image. For memory allocated by using DMA_ALLOC, the stride must be used for operations such as editing on the PixelMap. The following describes how to obtain the stride.

### Obtaining the Stride

The stride describes the storage width of each row of pixel data of an image in memory. It is an important parameter in the image drawing process and is used to correctly locate the layout of the image data in the memory.

When memory is allocated using DMA_ALLOC, the stride must meet the hardware alignment requirements.

- The stride value must be an integer multiple of the number of bytes required by the hardware platform.
- If the stride calculated using the above formula does not meet the alignment requirements, the system automatically pads the data.
  The stride value can be obtained by calling [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_getimageinfo).

1. Call [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_getimageinfo) to obtain an **OH_Pixelmap_ImageInfo** object.
2. Call [OH_PixelmapImageInfo_GetRowStride](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getrowstride) to obtain the stride value.

The sample code for obtaining and operating the stride by the C APIs is as follows:

```C++
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

OH_PixelmapNative* TestStrideWithAllocatorType() {
    size_t filePathSize = 1024;
    OH_ImageSourceNative* imageSource = nullptr;
    Image_ErrorCode image_ErrorCode = OH_ImageSourceNative_CreateFromUri("/data/storage/el2/base/haps/entry/files/test.jpg", filePathSize, &imageSource);
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
    uint32_t dstRowStride = srcInfo.width * GetPixelFormatBytes(srcInfo.pixelFormat);
    void *newPixels = nullptr;
    OH_PixelmapNative_AccessPixels(newPixelmap, &newPixels);
    OH_PixelmapNative_UnaccessPixels(newPixelmap);
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
    OH_PixelmapNative_UnaccessPixels(pixelmap);
    return newPixelmap;
}
```
