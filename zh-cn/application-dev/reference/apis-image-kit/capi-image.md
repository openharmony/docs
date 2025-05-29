# image

## 概述

提供image接口的访问。

**起始版本：** 10
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [image_mdk.h](capi-image-mdk-h.md) | 声明访问图像矩形、大小、格式和组件数据的函数。 |
| [image_mdk_common.h](capi-image-mdk-common-h.md) | 声明图像常用的枚举值和结构体。 |
| [image_packer_mdk.h](capi-image-packer-mdk-h.md) | 声明用于将图像编码到缓冲区或文件的api。可用于将像素数据编码到目标缓冲区或文件中。<br>编码过程如下：<br>通过OH_ImagePacker_Create方法创建编码器实例对象。<br>然后通过OH_ImagePacker_InitNative将编码器实例对象转换为编码器原生实例对象。<br>接下来用OH_ImagePacker_PackToData或者OH_ImagePacker_PackToFile将源以特定的编码选项编码进目标区域。<br>最后通过OH_ImagePacker_Release释放编码器实例对象。<br> |
| [image_pixel_map_mdk.h](capi-image-pixel-map-mdk-h.md) | 声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。Need link <b>libpixelmapndk.z.so</b> |
| [image_pixel_map_napi.h](capi-image-pixel-map-napi-h.md) | 声明可以锁定并访问pixelmap数据的方法，声明解锁的方法。 |
| [image_receiver_mdk.h](capi-image-receiver-mdk-h.md) | 声明从native层获取图片数据的方法。需要链接 <b>libimagendk.z.so</b>和<b>libimage_receiverndk.z.so</b>。 |
| [image_source_mdk.h](capi-image-source-mdk-h.md) | 声明将图片源解码成像素位图的方法。 |
