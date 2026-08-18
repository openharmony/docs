# 图片解码内存优化(ArkTS)
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

应用在进行图片解码操作时，需要申请对应内存。内存占用的大小与内存分配类型和像素格式密切相关。当前指导将介绍不同的内存类型、像素格式，以及如何组合使用以达到最优的解码性能。

应用侧通过解码API接口获取PixelMap，并将其传递给[Image](../../reference/apis-arkui/arkui-ts/ts-basic-components-image.md)组件以进行显示。

当PixelMap较大且使用共享内存时，RS主线程将经历较长的纹理上传时间，导致卡顿现象。图形侧提供了DMA内存零拷贝功能，可在绘制图片时避免纹理上传时间消耗。此外，通过设置合适的像素格式（如YUV格式），可进一步降低内存占用。

## 内存类型介绍

当前PixelMap的内存类型包括以下两种。

- SHARE_MEMORY：共享内存。需要进行纹理上传。
- DMA_ALLOC：DMA内存。无需纹理上传。

系统提供了[createPixelMapUsingAllocator](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmapusingallocator15)接口，以便用户能够自定义内存分配类型进行解码。接口定义及使用示例详见图片解码接口说明[Interface (ImageSource)](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md)。

### SHARE_MEMORY和DMA_ALLOC的区别

| 名称               | SHARE_MEMORY                                | DMA_ALLOC              |
| ------------------ | --------------------- | ----------------------------------------- |
| 定义               | 操作系统提供的共享内存（如ashmem/匿名共享），便于在同一物理页上读写。 | 使用可被外设/GPU/显示管线直接DMA访问的缓冲区（常见形态是dmabuf/SurfaceBuffer），用于零拷贝链路。 |
| 工作原理           | 进程共享同一段内存，通过CPU进行读写。若要给GPU/显示使用，通常需进行拷贝。 | 解码器通过DMA将数据写入dmabuf；GPU/显示直接使用该dmabuf，无需拷贝。 |
| 使用场景           | 用于进程或线程间的数据共享，如后处理、算法中间结果交换等场景。 | 视频/图片硬解、预览、显示等高带宽数据传输场景。 |
| CPU占用            | CPU需参与共享内存的管理和同步（如加锁、解锁），会造成额外开销。 | 占用极低，CPU仅参与DMA控制器的配置，实际数据传输无需CPU干预。 |
| 硬件依赖           | 依赖操作系统支持的共享内存机制。 | 强依赖硬件DMA控制器。 |
| 内存分配与访问权限 | 系统为共享内存分配物理或虚拟内存区域，访问需通过用户或内核映射操作。 | DMA控制器直接操作物理内存，需预先分配DMA缓冲区（通常是连续内存）。 |
| 优势               | 灵活性强。支持多线程或多进程同时共享数据，便于图像后处理和协作。 | 高效、低延迟；适合大数据量、连续数据块的传输。 |
| 缺点               | 共享内存操作需要额外的同步机制，增加编程复杂度和CPU负担。 | 需要硬件支持，数据传输范围受DMA地址空间限制（通常需要连续物理内存）。 |

### 使用DMA_ALLOC的优势

- **减少纹理上传时间**

   当使用SHARE_MEMORY时，图片数据需通过CPU复制到GPU显存，增加了纹理上传的时间。而采用DMA_ALLOC后，数据直接保存在GPU可访问的内存中，避免了耗时的复制过程。
   - SHARE_MEMORY耗时：4K图片单帧渲染耗时约为20ms。
   - DMA_ALLOC耗时：4K图片单帧渲染时间可降至约4ms。此项优化在大尺寸图片显示和高频动态图片加载场景中效果尤为显著。

- **减轻CPU负载**

  DMA_ALLOC允许GPU直接访问解码后数据，减少了内存复制带来的负载。

> **说明：**
>
> 开发者在使用DMA_ALLOC时，必须关注stride（步幅）与图片宽度的差异，并在数据读取、解析、送显前进行对齐处理。

### 使用限制

当前图片解码功能针对内存分配模式有如下限制。

- HDR图片解码仅支持DMA_ALLOC的内存模式。
- 硬件解码仅支持DMA_ALLOC的内存模式。
- SVG格式图片解码仅支持SHARE_MEMORY的内存模式。

使用接口[createPixelMapUsingAllocator](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmapusingallocator15)进行解码时，若设置的内存分配模式，与图片格式或解码方式不匹配，则会抛出内存分配失败的异常。

如果用户选择的分配类型为AUTO，系统将根据解码和渲染的时间综合评估，以决定使用DMA_ALLOC还是SHARE_MEMORY分配机制。

不同的内存分配策略会导致图片的stride（步幅）有所差异。对于通过DMA_ALLOC申请的内存，在对PixelMap执行编辑等操作时，必须使用stride。接下来将介绍如何获取stride。

### 获取stride

stride（步幅）描述了图片在内存中每一行像素数据的存储宽度。它是图片绘制过程中的重要参数，用于正确定位图片数据在内存中的布局。

使用DMA分配机制分配内存时，stride必须满足硬件对齐要求。

- stride值需为硬件平台要求字节数的整数倍。
- 当stride值大于等于图片宽度时，系统会自动补齐填充数据（padding）。

stride的值可以通过[getImageInfo()](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#getimageinfo-1) 接口获取。

1. 调用[getImageInfo()](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#getimageinfo-1)方法，获取ImageInfo对象。

2. 从ImageInfo对象中访问stride值：info.stride。

   <!-- @[allocator_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/AllocateMemory.ets) -->   
   
   ``` TypeScript
   // 导入相关模块。
   import { image } from '@kit.ImageKit';
   import { common } from '@kit.AbilityKit';
   ```

   <!-- @[allocator_called](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   
   
   ``` TypeScript
   async CreatePixelMapUsingAllocator(context: Context, type: image.AllocatorType): Promise<image.PixelMap | undefined> {
     const resourceMgr = context.resourceManager;
     try {
       const rawFile = await resourceMgr.getRawFileContent('99_132.jpg'); // 测试图片为99*132的jpg图。
       let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer);
       let options: image.DecodingOptions = {};
       let pixelmap = await imageSource.createPixelMapUsingAllocator(options, type);
       if (pixelmap != undefined) {
         let info = await pixelmap.getImageInfo();
         // 用DMA_ALLOC内存申请出的pixelmap的stride与SHARE_MEMORY内存申请出的pixelmap的stride不同。
         console.info('stride = ' + info.stride);
       }
       return pixelmap;
     } catch (err) {
       console.error(`Create PixelMap by setting allocator type failed: ${err}.`);
       return undefined;
     }
       
   }
   ```
   
## 像素格式介绍

图片解码后的像素格式直接影响内存占用大小。当前支持的主要像素格式如下。

### RGBA_8888和YUV格式的区别

| 名称 | RGBA_8888 | NV21/NV12（YUV 4:2:0） |
| -- | -- | -- |
| 定义 | 颜色信息由R（Red）、G（Green）、B（Blue）与透明度（Alpha）四部分组成，每个部分占8位，总共占32位。 | 颜色信息由亮度分量Y和交错排列的色度分量UV组成。Y分量占8位，UV分量因4:2:0采样平均占4位，总共平均占12位。 |
| 每像素字节数 | 4字节 | 约1.5字节 |
| 内存占用计算 | width × height × 4 | width × height × 1.5 |
| 适用场景 | 需要处理Alpha通道的场景，如透明度合成、阴影效果等。 | 图片预览、显示等场景，内存占用小，适合大尺寸图片解码。 |
| 优势 | 支持完整的Alpha通道操作，兼容性好。 | 内存占用小，JPEG硬件解码可直接输出，避免格式转换开销。 |

### 使用YUV格式的优势

- **显著降低内存占用**

  以4K图片（3840×2160）为例：
  - RGBA_8888内存占用：3840 × 2160 × 4 ≈ 33.2MB
  - NV21内存占用：3840 × 2160 × 1.5 ≈ 12.4MB
  - 内存节省约62.5%，可有效降低应用内存压力。

- **减少格式转换开销**

  JPEG等格式的图片在硬件解码时，解码器可直接输出YUV格式数据，减少格式转换开销。

> **说明：**
>
> - SVG格式和TIFF格式的图片不支持解码为YUV像素格式。
> - YUV格式不含Alpha通道，有透明度需求的图片应使用RGBA_8888格式。

### 设置YUV像素格式

使用YUV格式解码时，需在DecodingOptions中设置desiredPixelFormat参数，并推荐配合DMA内存分配使用。

<!-- @[allocator_yuv_called](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

``` TypeScript
async CreatePixelMapWithYUV(context: Context): Promise<image.PixelMap | undefined> {
  const resourceMgr = context.resourceManager;
  try {
    const rawFileDescriptor = await resourceMgr.getRawFd('test.jpeg');
    let imageSource: image.ImageSource = image.createImageSource(rawFileDescriptor);

    // 设置YUV像素格式和DMA内存分配，实现最优解码性能。
    let options: image.DecodingOptions = {
      desiredPixelFormat: image.PixelMapFormat.NV21  // 设置为YUV格式，也可选择NV12。
    };
    let pixelmap = await imageSource.createPixelMapUsingAllocator(options, image.AllocatorType.DMA);

    if (pixelmap != undefined) {
      let info = await pixelmap.getImageInfo();
      console.info('YUV PixelMap created, stride = ' + info.stride + ', pixelFormat = ' + info.pixelFormat);
    }
    return pixelmap;
  } catch (err) {
    console.error(`Create PixelMap with YUV format failed: ${err}.`);
    return undefined;
  }
}
```

## 系统默认的内存分配方式

在使用[createPixelMap](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmap7)接口进行解码时，不同场景下会采取不同的内存分配类型。

以下场景将使用DMA_ALLOC。

- 解码HDR图片。
- 解码HEIF格式图片。
- 解码JPEG格式图片，当原图的宽和高均在1024像素至8192像素之间，[desiredPixelFormat](../../reference/apis-image-kit/arkts-apis-image-i.md#decodingoptions7)为RGBA_8888或NV21，同时硬件不繁忙（并发数为3）。
- 解码其他格式图片。要求[desiredSize](../../reference/apis-image-kit/arkts-apis-image-i.md#decodingoptions7)大于等于512像素 * 512像素（未设置desiredSize时按原图尺寸考虑），并且宽度为64的倍数。

除上述场景外，其余情况均使用SHARE_MEMORY。

## 解码单张图片的内存限制

为了防止内存溢出导致系统崩溃，系统对进程内存做了限制，详细说明请参考[应用被查杀问题检测方法](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-runtime-appkilled-detection)。

图片框架对单张图片的解码设置了2GB的内存限制。进程需要主动管理自身内存，建议在不使用[PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md)时及时释放，以避免进程被系统终止。

应用可使用[onMemoryLevel](../../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onmemorylevel)监听系统内存变化情况。

PixelMap申请像素内存的计算规则如下所示。

``` TypeScript
pixels_size(像素内存大小) = stride(图片像素存储宽度) * height(图片像素高度)
```

对于原始像素内存超过2GB且支持下采样的图片，建议开发者使用[createPixelMap](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmap7)或[createPixelMapUsingAllocator](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmapusingallocator15)接口，并在[DecodingOptions](../../reference/apis-image-kit/arkts-apis-image-i.md#decodingoptions7)中设置desiredSize（期望输出大小）进行下采样解码。

从API version 21开始，对于支持下采样解码的图片，设置desiredSize（期望输出大小）后，解码器将以基准梯度为1/8的最优下采样率计算PixelMap的像素内存，即按照7/8、6/8、...、1/8的采样率，逐次递减取一个清晰度最高的采样数。

图片框架内，不同图片格式的下采样解码支持情况如下所示。
| 是否支持下采样 | 图片格式                                                  |
| ------------ | --------------------------------------------------------- |
| 支持          | .jpg .png .heic<sup>12+</sup>（具体支持情况请参考设备规格文档。） |
| 不支持        | .gif .bmp .webp .dng .svg<sup>10+</sup> .ico<sup>11+</sup> |