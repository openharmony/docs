# CodecImageType.idl


## 概述

定义图像编解码器模块API中使用的自定义数据类型，包括编解码器图像参数、类型和缓冲区。

模块包路径：ohos.hdi.codec.image.v1_0

**起始版本：** 4.0

**相关模块：**[Codec](_codec_v20.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[CodecImageRegion](_codec_image_region_v20.md) | 定义图像区域信息。 | 
| struct&nbsp;&nbsp;[CodecImageBuffer](_codec_image_buffer_v20.md) | 定义编解码图像缓冲区信息。 | 
| struct&nbsp;&nbsp;[CodecImageCapability](_codec_image_capability_v20.md) | 定义图像编解码器功能。 | 
| struct&nbsp;&nbsp;[CodecJpegQuantTable](_codec_jpeg_quant_table_v20.md) | 定义jpeg图像量化表信息。 | 
| struct&nbsp;&nbsp;[CodecJpegHuffTable](_codec_jpeg_huff_table_v20.md) | 定义jpeg图像Huffman表信息。 | 
| struct&nbsp;&nbsp;[CodecJpegCompInfo](_codec_jpeg_comp_info_v20.md) | 定义jpeg图像的颜色分量信息。 | 
| struct&nbsp;&nbsp;[CodecJpegDecInfo](_codec_jpeg_dec_info_v20.md) | 定义jpeg图像解码信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CodecImageRole](_codec_v20.md#codecimagerole) { CODEC_IMAGE_JPEG = 0 , CODEC_IMAGE_HEIF , CODEC_IMAGE_INVALID } | 编解码的图像格式枚举。 | 
| [CodecImageType](_codec_v20.md#codecimagetype) { CODEC_IMAGE_TYPE_DECODER = 0 , CODEC_IMAGE_TYPE_ENCODER , CODEC_IMAGE_TYPE_INVALID } | 定义图像编解码器类型。 | 
