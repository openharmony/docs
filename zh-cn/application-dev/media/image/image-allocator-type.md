# 申请图片解码内存

应用侧使用解码API接口得到PixelMap，传入Image组件进行显示。如果PixelMap较大且为普通内存，RS主线程会有长时间的纹理上传耗时，导致卡顿。图形侧提供DMA内存零拷贝的能力，绘制同样大小图片不耗费纹理上传时长。

当前PixelMap的内存类型有以下两种。

- Ashmem：共享内存。IPC耗时短，需纹理上传。
- DMA：ION内存。IPC耗时短，无需纹理上传。

基于当前解码接口的内存分配策略无法满足部分场景的需要，故提供接口[createPixelMapUsingAllocator](../../reference/apis-image-kit/js-apis-image.md#createpixelmapusingallocator15)以便用户能够定制内存分配类型进行解码，接口定义及示例见[图片解码接口说明](../../reference/apis-image-kit/js-apis-image.md#imagesource)。

## 使用DMA_ALLOC内存修改的优势

### 降低纹理上传时间

使用普通内存（Ashmem）时，图片数据需要经过CPU拷贝到GPU显存，导致纹理上传时间较长。而使用DMA Buffer后，数据直接存储于GPU可访问的内存中，避免拷贝过程耗时太久。

- **传统上传耗时：4K图片单帧渲染耗时约为20ms。**
- **DMA零拷贝耗时：4K图片单帧渲染耗时可降低至约4ms。 此优化在大尺寸图片显示和高频动态图片加载场景中效果尤为显著。**

### 降低CPU负载

DMA Buffer允许GPU直接访问解码数据，省去内存拷贝的负载。

## DMA和Ashmem的区别

|       名称             | DMA                                                                       | Ashmem                                                                                   |
| ------------------ | ------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| 定义               | 硬件解码器直接将图片解码后的数据传输到内存或显存，无需CPU介入。         | 操作系统提供的内存共享机制，允许多个线程、进程直接访问同一块物理内存，协同处理图片数据。 |
| 工作原理           | 解码器通过DMA控制器将图片解码后的数据从设备直接传输到内存或显示缓冲区。 | GPU解码的图片数据直接映射到共享内存中，供多个线程、进程协作处理或访问。                 |
| 使用场景           | 用于高速数据传输。                                                    | 用于进程或线程间的数据共享。                                                             |
| CPU占用           | 占用极低，CPU仅参与DMA控制器的配置，实际数据传输无需CPU干预。        | CPU需参与共享内存的管理和同步（如加锁、解锁），会造成额外开销。                       |
| 硬件依赖           | 强依赖硬件DMA控制器。                                                   | 依赖操作系统支持的共享内存机制。                                                         |
| 内存分配与访问权限 | DMA控制器直接操作物理内存，需预先分配DMA缓冲区（通常是连续内存）。     | 系统为共享内存分配物理或虚拟内存区域，访问需通过用户或内核映射操作。                     |
| 优势               | 高效、低延迟；适合大数据量、连续数据块的传输。                        | 灵活性强；支持多线程或多进程同时共享数据，便于图像后处理和协作。                         |
| 缺点               | 需要硬件支持，数据传输范围受DMA地址空间限制（通常需要连续物理内存）。   | 共享内存操作需要额外的同步机制，增加编程复杂度和CPU负担。                            |
| 解码工作流中的使用 | 硬件解码器通过DMA直接输出数据到目标内存，无需CPU干预。                | 解码完成后将数据放入共享内存，由其他进程或线程读取处理。                                 |

## 用户使用注意事项

### 内存分配策略

创建像素图时，根据用户传入的分配器类型，来决定使用DMA分配机制或Ashmem分配机制。如传入的分配类型为AUTO，则由系统根据解码和渲染耗时综合考虑决定使用DMA分配机制或Ashmem分配机制。

不同的内存分配策略会导致图片的stride（步幅）有所不同。如果是DMA申请的内存，对PixelMap进行编辑等操作时必须使用stride。下文将介绍stride获取方法。

### stride获取方法

stride（步幅）描述了图片在内存中每一行像素数据的存储宽度。它是图片绘制过程中的重要参数，用于正确定位图片数据在内存中的布局。

使用DMA分配机制分配内存时，stride必须满足 **硬件对齐要求**。

- stride 值需为 **硬件平台要求字节数的整数倍**。
- 如果通过上面的计算公式得到的 stride 不满足对齐要求时，系统会自动补齐填充数据（padding）。

stride的值可以通过[ `PixelMap::GetImageInfo()`](../../reference/apis-image-kit/js-apis-image.md#getimageinfo) 接口获取。

1. 调用 `GetImageInfo()` 方法，获取 `ImageInfo` 对象。
2. 从 `ImageInfo` 对象中访问 stride 值：`info.stride`。

以下是获取stride的示例代码。

```ts
import image from '@ohos.multimedia.image';

async CreatePixelMapUsingAllocator() {
  const context = getContext();
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.jpg");  // 测试图片。
  let imageSource: image.ImageSource | null = await image.createImageSource(rawFile.buffer as ArrayBuffer);
  let options: image.DecodingOptions = {};
  let pixelmap = await imageSource.createPixelMapUsingAllocator(options, image.AllocatorType.AUTO);
  let info = await pixelmap.getImageInfo();
  // 用DMA_ALLOC内存申请出的pixelmap的stride与SHARE_MEMORY内存申请出的pixelmap的stride不同。
  console.log("stride = " + info.stride);
  let region: image.Region = { x: 0, y: 0, size: {height: 100, width:35} };
  if (pixelmap != undefined) {
    await pixelmap.crop(region);
    let imageInfo = await pixelmap.getImageInfo();
    if (imageInfo != undefined) {
      console.info("stride =", imageInfo.stride);
    }
  }
}
```

C-API 获取和操作stride示例代码如下。

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
    IMAGE_ALLOCATOR_TYPE allocatorType = IMAGE_ALLOCATOR_TYPE::IMAGE_ALLOCATOR_TYPE_DMA;  // 使用DMA创建pixelMap。
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

## createPixelMapUsingAllocator接口能力说明和使用限制

**createPixelMapUsingAllocator接口能力。**

- 默认场景下，由系统选择性能最优的内存分配方式。
  * HDR指定DMA的内存模式。
  * SVG图片指定SHARE_MEMORY的内存模式。
- 特定场景支持应用使用指定的内存分配方式。

**目前图片解码功能针对内存申请模式有如下限制。**

- HDR图片解码仅支持DMA的内存模式。
- 硬件解码仅支持DMA的内存模式。
- SVG图片解码仅支持SHARE_MEMORY的内存模式。

使用接口[createPixelMapUsingAllocator](../../reference/apis-image-kit/js-apis-image.md#createpixelmapusingallocator15)进行解码时，系统会根据传入的[解码参数](../../reference/apis-image-kit/js-apis-image.md#decodingoptions7)和[内存申请类型](../../reference/apis-image-kit/js-apis-image.md#allocatortype15)，自动选择硬件解码和软件解码。

**解码失败的场景如下。**

- HDR图片解码使用Ashmem分配机制。

```ts
import image from '@ohos.multimedia.image';

async CreatePixelMapUsingAllocator() {
  const context = getContext();
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("hdr.jpg"); // 输入的图片为HDR图片。
  let imageSource: image.ImageSource | null = await image.createImageSource(rawFile.buffer as ArrayBuffer);
  let options: image.DecodingOptions = {
    desiredDynamicRange: image.DecodingDynamicRange.HDR
  };
  try {
    let pixelmap = await imageSource.createPixelMapUsingAllocator(options, image.AllocatorType.SHARE_MEMORY);
  } catch(err) {
    console.error("Failed to decode HDR picture with Ashmem. error message:", err.message, "error code:", err.code);
  }
}
// 输出：Failed to decode HDR picture with Ashmem. error message: Unsupported allocator type. error code: 7700201
```

- SVG图片解码使用DMA分配机制。

```ts
import image from '@ohos.multimedia.image';

async CreatePixelMapUsingAllocator() {
  const context = getContext();
  const resourceMgr = context.resourceManager;
  const rawFile = await resourceMgr.getRawFileContent("test.svg"); // 输入的图片为svg图片。
  let imageSource: image.ImageSource | null = await image.createImageSource(rawFile.buffer as ArrayBuffer);
  let options: image.DecodingOptions = {};
  try {
    let pixelmap = await imageSource.createPixelMapUsingAllocator(options, image.AllocatorType.DMA);
  } catch(err) {
    console.error("Failed to decode SVG picture with DMA. error message:", err.message, "error code:", err.code);
  }
}
// 输出：Failed to decode SVG picture with DMA. error message: Unsupported allocator type. error code: 7700201
```