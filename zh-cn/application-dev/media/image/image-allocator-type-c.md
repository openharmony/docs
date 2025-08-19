# 申请图片解码内存(C/C++)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

应用在进行图片解码操作时，需要申请对应内存。当前指导将介绍不同的内存类型，以及如何进行申请。

应用侧通过解码API接口获取PixelMap，并将其传递给Image组件以进行显示。

当PixelMap较大且使用普通内存时，RS主线程将经历较长的纹理上传时间，导致卡顿现象。图形侧提供的DMA内存零拷贝功能，可在绘制相同大小的图片时避免纹理上传时间消耗。

## 内存类型介绍

当前PixelMap的内存类型包括以下两种。

- DMA_ALLOC：DMA内存。IPC耗时同样较短，但无需纹理上传。
- SHARE_MEMORY：共享内存。IPC耗时较少，但需要进行纹理上传。

鉴于当前的解码接口内存分配策略无法满足某些场景的需求，系统提供了[OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator)接口，以便用户能够自定义内存分配类型进行解码。

### DMA_ALLOC和SHARE_MEMORY的区别

| 名称               | DMA_ALLOC                                                               | SHARE_MEMORY                                                                             |
| ------------------ | ----------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| 定义               | 硬件解码器直接将图片解码后的数据传输到内存或显存，无需CPU介入。         | 操作系统提供的内存共享机制，允许多个线程、进程直接访问同一块物理内存，协同处理图片数据。 |
| 工作原理           | 解码器通过DMA控制器将图片解码后的数据从设备直接传输到内存或显示缓冲区。 | GPU解码的图片数据直接映射到共享内存中，供多个线程、进程协作处理或访问。                  |
| 使用场景           | 用于高速数据传输。                                                      | 用于进程或线程间的数据共享。                                                             |
| CPU占用            | 占用极低，CPU仅参与DMA控制器的配置，实际数据传输无需CPU干预。           | CPU需参与共享内存的管理和同步（如加锁、解锁），会造成额外开销。                          |
| 硬件依赖           | 强依赖硬件DMA控制器。                                                   | 依赖操作系统支持的共享内存机制。                                                         |
| 内存分配与访问权限 | DMA控制器直接操作物理内存，需预先分配DMA缓冲区（通常是连续内存）。      | 系统为共享内存分配物理或虚拟内存区域，访问需通过用户或内核映射操作。                     |
| 优势               | 高效、低延迟；适合大数据量、连续数据块的传输。                          | 灵活性强。支持多线程或多进程同时共享数据，便于图像后处理和协作。                         |
| 缺点               | 需要硬件支持，数据传输范围受DMA地址空间限制（通常需要连续物理内存）。   | 共享内存操作需要额外的同步机制，增加编程复杂度和CPU负担。                                |
| 解码工作流中的使用 | 硬件解码器通过DMA直接输出数据到目标内存，无需CPU干预。                  | 解码完成后将数据放入共享内存，由其他进程或线程读取处理。                                 |

### 使用DMA_ALLOC内存修改的优势

- **减少纹理上传时间**

  当使用SHARE_MEMORY时，图片数据需通过CPU复制到GPU显存，增加了纹理上传的时间。而采用DMA_ALLOC后，数据直接保存在GPU可访问的内存中，避免了耗时的复制过程。

  - 传统方式上传耗时：4K图片单帧渲染耗时约为20ms。
  - DMA_ALLOC上传耗时：4K图片单帧渲染时间可降至约4ms。此项优化在大尺寸图片显示和高频动态图片加载场景中效果尤为显著。
- **减轻CPU负载**

  DMA_ALLOC允许GPU直接访问解码后数据，减少了内存复制带来的负载。

## 系统默认的内存分配方式

在使用接口[OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap)接口进行解码时，不同场景下会采取不同的内存分配类型。

以下场景将使用DMA_ALLOC。

- 解码HDR图片。
- 解码HEIF格式图片。
- 解码JPEG格式图片，当原图的宽和高均在1024至8192之间，[desiredPixelFormat](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md)为RGBA_8888或NV21，同时硬件不繁忙（并发数为3）。
- 解码其他格式图片。要求[desiredSize](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md)大于等于512 * 512（未设置desiredSize时按原图尺寸考虑），并且宽度为64的倍数。

除上述场景外，其余情况均使用SHARE_MEMORY。

## 自定义内存分配方式

默认场景下，由系统选择性能最优的内存分配方式。特定场景支持应用使用指定的内存分配方式。

开发者使用接口[OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator)进行解码时，系统会根据传入的[解码参数](../../reference/apis-image-kit/capi-image-nativemodule-oh-decodingoptions.md)和[内存申请类型](../../reference/apis-image-kit/capi-image-source-native-h.md#image_allocator_type)，自动选择硬件解码和软件解码。

在创建像素图时，将根据用户指定的分配器类型来决定采用DMA_ALLOC分配机制还是SHARE_MEMORY分配机制。

### 使用限制

当前图片解码功能针对内存分配模式有如下限制。

- HDR图片解码仅支持DMA_ALLOC的内存模式。
- 硬件解码仅支持DMA_ALLOC的内存模式。
- SVG格式图片解码仅支持SHARE_MEMORY的内存模式。

使用接口[OH_ImageSourceNative_CreatePixelmapUsingAllocator](../../reference/apis-image-kit/capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator)进行解码时，若设置的内存分配模式，与图片格式或解码方式不匹配，则会抛出内存分配失败的异常。

如果用户选择的分配类型为AUTO，系统将根据解码和渲染的时间综合评估，以决定使用DMA_ALLOC还是SHARE_MEMORY分配机制。

不同的内存分配策略会导致图片的stride（步幅）有所差异。对于通过DMA_ALLOC申请的内存，在对PixelMap执行编辑等操作时，必须使用stride。接下来将介绍如何获取stride。

### 获取stride

stride（步幅）描述了图片在内存中每一行像素数据的存储宽度。它是图片绘制过程中的重要参数，用于正确定位图片数据在内存中的布局。

使用DMA分配机制分配内存时，stride必须满足硬件对齐要求。

- stride值需为硬件平台要求字节数的整数倍。
- 如果通过上面的计算公式得到的stride不满足对齐要求时，系统会自动补齐填充数据（padding）。
  stride的值可以通过[OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo) 接口获取。

1. 调用[OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_getimageinfo)方法，获取 `OH_Pixelmap_ImageInfo` 对象。
2. 调用[OH_PixelmapImageInfo_GetRowStride](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride)方法，获取stride的值。

C-API 获取和操作stride示例代码如下。在使用下面的示例代码之前，开发者需要打开native工程的src/main/cpp/CMakeLists.txt，在target_link_libraries依赖中添加libimage_packer.so 以及日志依赖libhilog_ndk.z.so。

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
            return 8; // 每通道16位浮点数，共4通道：4 * 2 bytes = 8 bytes
        case 8: // PIXEL_FORMAT_NV21
        case 9: // PIXEL_FORMAT_NV12'
            // NV21 和 NV12 是 YUV 4:2:0 半平面格式：
            // - Y 分量占用 width × height 字节（每像素1字节）
            // - UV 分量以交错方式排列（UV 或 VU），占用 width × height / 2 字节
            // - 总字节数 = width × height × 1.5
            // 因为函数返回类型为 int32_t，无法返回小数，因此保守起见向上取整返回 2
            // 虽然实际平均每像素占用 1.5 字节，但返回 2 可以保证内存分配安全，避免越界。代价是需要注意stride的处理。
            return 2; // Semi-planar YUV, use 2 as approximate per-byte-per-pixel
        case 10: // PIXEL_FORMAT_RGBA_1010102
            return 4;
        case 11: // PIXEL_FORMAT_YCBCR_P010
        case 12: // PIXEL_FORMAT_YCRCB_P010
            return 2; // 10-bit YUV 格式，通常对齐为 16 bit（2 字节）
        default: // PIXEL_FORMAT_UNKNOWN or unsupported
            return 0;
    }
}

OH_PixelmapNative* TestStrideWithAllocatorType() {
    size_t filePathSize = 1024;
    OH_ImageSourceNative* imageSource = nullptr;
    Image_ErrorCode image_ErrorCode = OH_ImageSourceNative_CreateFromUri("/data/storage/el2/base/haps/entry/files/test.jpg", filePathSize, &imageSource);
    OH_DecodingOptions *options = nullptr;
    OH_DecodingOptions_Create(&options);
    IMAGE_ALLOCATOR_TYPE allocatorType = IMAGE_ALLOCATOR_TYPE::IMAGE_ALLOCATOR_TYPE_DMA;  // 使用DMA创建pixelMap。
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
