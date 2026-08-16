# Image Decoding Memory Optimization (ArkTS)

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=aa31d9fcc0b122cab31aac2ab8571a969c49cd4f translatedAt=2026-08-11T01:43:21.033Z pushedAt=2026-08-11T03:04:44.293Z -->

When an app performs image decoding, it needs to allocate the corresponding memory. The memory usage depends on the memory allocation type and pixel format. This guide describes different memory types, pixel formats, and how to combine them for optimal decoding performance.

The app obtains a PixelMap through the decoding API and passes it to the [Image component](../../../application-dev/reference/apis-arkui/arkui-js/js-components-basic-image.md) for display.

When the PixelMap is large and uses shared memory, the RS main thread will experience a longer texture upload time, leading to lag. The graphics side provides a DMA memory zero-copy feature, which avoids texture upload time consumption when drawing images. In addition, setting an appropriate pixel format (such as YUV) can further reduce memory usage.

## Memory Types

The memory types for the PixelMap are as follows:

- SHARE_MEMORY: shared memory. Texture upload is required.

- DMA_ALLOC: DMA memory. Texture upload is not required.

The system provides the [createPixelMapUsingAllocator](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmapusingallocator15) API, allowing you to customize the memory allocation type for decoding. For details about the API definition and usage examples, see the image decoding API description [Interface (ImageSource)](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md).

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

When [createPixelMapUsingAllocator](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmapusingallocator15) is used for decoding, if the specified memory allocation mode does not match the image format or decoding method, an exception indicating a memory allocation failure is thrown.

If the allocation type is set to AUTO, the system determines whether to use DMA_ALLOC or SHARE_MEMORY based on the decoding and rendering time.

Different memory allocation strategies can result in differences in the stride of the image. For memory allocated by using DMA_ALLOC, the stride must be used for operations such as editing on the PixelMap. The following describes how to obtain the stride.

### Obtaining the Stride

The stride describes the storage width of each row of pixel data of an image in memory. It is an important parameter in the image drawing process and is used to correctly locate the layout of the image data in the memory.

When memory is allocated using DMA_ALLOC, the stride must meet the hardware alignment requirements.

- The stride value must be an integer multiple of the number of bytes required by the hardware platform.

- When the stride value is greater than or equal to the image width, the system automatically pads the data.

The stride value can be obtained by calling [getImageInfo()](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#getimageinfo-1).

1. Call [getImageInfo()](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#getimageinfo-1) to obtain an ImageInfo object.

2. Access the stride value (**info.stride**) from the ImageInfo object.

   <!-- @[allocator_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/AllocateMemory.ets) -->   

   ``` TypeScript
   // Import the related modules.
   import { image } from '@kit.ImageKit';
   import { common } from '@kit.AbilityKit';
   ```

   <!-- @[allocator_called](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

   ``` TypeScript
   async CreatePixelMapUsingAllocator(context: Context, type: image.AllocatorType): Promise<image.PixelMap | undefined> {
     const resourceMgr = context.resourceManager;
     try {
       const rawFile = await resourceMgr.getRawFileContent('99_132.jpg'); // The test image is a 99*132 JPG image.
       let imageSource: image.ImageSource = image.createImageSource(rawFile.buffer as ArrayBuffer);
       let options: image.DecodingOptions = {};
       let pixelmap = await imageSource.createPixelMapUsingAllocator(options, type);
       if (pixelmap != undefined) {
         let info = await pixelmap.getImageInfo();
         // The stride of the pixelmap allocated with DMA_ALLOC memory differs from that of the pixelmap allocated with SHARE_MEMORY memory.
         console.info('stride = ' + info.stride);
       }
       return pixelmap;
     } catch (err) {
       console.error(`Create PixelMap by setting allocator type failed: ${err}.`);
       return undefined;
     }
       
   }
   ```

## Pixel Format

The pixel format after image decoding directly affects memory usage. The main supported pixel formats are as follows.

### Differences Between RGBA_8888 and YUV Formats

| Name | RGBA_8888 | NV21/NV12 (YUV 4:2:0) |
| -- | -- | -- |
| Definition | Color information consists of four components: R (Red), G (Green), B (Blue), and Alpha (transparency). Each component occupies 8 bits, totaling 32 bits. | Color information consists of a luma component Y and interleaved chroma components UV. The Y component occupies 8 bits, and the UV components average 4 bits due to 4:2:0 sampling, totaling an average of 12 bits. |
| Bytes per Pixel | 4 bytes | Approximately 1.5 bytes |
| Memory Usage Calculation | Width × height × 4 | Width × height × 1.5 |
| Applicable Scenarios | Scenarios requiring Alpha channel processing, such as transparency compositing and shadow effects. | Image preview, display, and similar scenarios. Low memory usage, suitable for large-size image decoding. |
| Advantages | Supports full Alpha channel operations with good compatibility. | Low memory usage. JPEG hardware decoding can directly output this format, avoiding format conversion overhead. |

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
> - SVG and TIFF format images do not support decoding to YUV pixel format.
> - The YUV format does not include an Alpha channel. For images requiring transparency, use the RGBA_8888 format.

### Setting the YUV Pixel Format

When decoding in YUV format, set the desiredPixelFormat parameter in DecodingOptions. It is recommended to use DMA memory allocation together with this setting.

<!-- @[allocator_yuv_called](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

``` TypeScript
async CreatePixelMapWithYUV(context: Context): Promise<image.PixelMap | undefined> {
  const resourceMgr = context.resourceManager;
  try {
    const rawFileDescriptor = await resourceMgr.getRawFd('test.jpeg');
    let imageSource: image.ImageSource = image.createImageSource(rawFileDescriptor);

    // Set the YUV pixel format and DMA memory allocation for optimal decoding performance.
    let options: image.DecodingOptions = {
      desiredPixelFormat: image.PixelMapFormat.NV21  // Set to YUV format. NV12 is also available.
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

## System Default Memory Allocation

When [createPixelMap](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmap7) is called for decoding, different memory allocation types are used in different scenarios.

DMA_ALLOC is used in the following scenarios:

- Decoding HDR images

- Decoding HEIF format images

- Decoding JPEG format images, when the original image width and height are both between 1024 and 8192 pixels, [desiredPixelFormat](../../reference/apis-image-kit/arkts-apis-image-i.md#decodingoptions7) is RGBA_8888 or NV21, and the hardware is not busy (concurrency of 3).

- Decoding images in other formats, when [desiredSize](../../reference/apis-image-kit/arkts-apis-image-i.md#decodingoptions7) is greater than or equal to 512 × 512 pixels (the original image size is used if desiredSize is not set), and the width is a multiple of 64.

In all other scenarios, SHARE_MEMORY is used.

## Memory Restrictions for Decoding a Single Image

To prevent system crashes from memory overflow, the system enforces memory restrictions on processes. For details, see [Application-Killed Issues Detection](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-runtime-appkilled-detection).

The image framework imposes a 2 GB memory limit for decoding a single image. Processes should actively manage their memory usage. You are advised to release [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) objects promptly when they are no longer needed, to avoid process termination by the system.

Applications can use [onMemoryLevel](../../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#onmemorylevel) to listen for system memory changes.

The calculation rule for PixelMap memory allocation is as follows:

``` TypeScript
pixels_size (pixel memory size) = stride (image pixel storage width) * height (image pixel height)
```

For images with original pixel memory exceeding 2 GB that support downsampling, you are advised to use the [createPixelMap](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmap7) or [createPixelMapUsingAllocator](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmapusingallocator15) API, and set desiredSize (expected output size) in [DecodingOptions](../../reference/apis-image-kit/arkts-apis-image-i.md#decodingoptions7) for downsampling decoding.

Starting from API version 21, for images that support downsampling decoding, when **desiredSize** (expected output size) is set, the decoder calculates PixelMap pixel memory at the optimal downsampling rate with a base gradient of 1/8. This means that it selects the highest clarity sampling rate among 7/8, 6/8, ..., 1/8.

The table below lists the downsampling decoding support for different image formats in the image framework.

| Support for Downsampling| Image Format                                                 |
| ------------ | --------------------------------------------------------- |
| Supported         | .jpg, .png, .heic<sup>12+</sup> (Refer to the device specification document for specific support.)|
| Not supported | .gif .bmp .webp .dng .svg<sup>10+</sup> .ico<sup>11+</sup> |