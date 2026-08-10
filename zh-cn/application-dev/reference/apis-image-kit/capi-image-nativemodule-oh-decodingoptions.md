# OH_DecodingOptions
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_DecodingOptions OH_DecodingOptions
```

## 概述

OH_DecodingOptions是native层封装的解码选项参数结构体，用于设置解码选项参数，在创建Pixelmap时作为入参传入，详细信息见[OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap)。

OH_DecodingOptions结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

使用[OH_DecodingOptions_Create](capi-image-source-native-h.md#oh_decodingoptions_create)函数创建OH_DecodingOptions对象。

使用[OH_DecodingOptions_Release](capi-image-source-native-h.md#oh_decodingoptions_release)函数释放OH_DecodingOptions对象。

使用约束：OH_DecodingOptions用于配置PixelMap解码参数，通常作为[OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap)、[OH_ImageSourceNative_CreatePixelmapUsingAllocator](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmapusingallocator)或[OH_ImageSourceNative_CreatePixelmapList](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmaplist)的入参。使用前需通过[OH_DecodingOptions_Create](capi-image-source-native-h.md#oh_decodingoptions_create)创建对象；使用完成后，应调用[OH_DecodingOptions_Release](capi-image-source-native-h.md#oh_decodingoptions_release)释放对象。

资源管理：释放OH_ImageSourceNative或解码生成的OH_PixelmapNative对象，不会自动释放OH_DecodingOptions对象。OH_DecodingOptions释放后，不应继续传入解码接口或调用其字段获取和设置接口。

OH_DecodingOptions结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 | 字段默认值 | 字段获取函数 | 字段设置函数 |
| -------- | -------- | -------- | -------- | -------- | -------- |
| int32_t | pixelFormat | 像素格式。 | RGBA_8888 | [OH_DecodingOptions_GetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_getpixelformat) | [OH_DecodingOptions_SetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_setpixelformat) |
| uint32_t | index | 解码图片序号。 | 0 | [OH_DecodingOptions_GetIndex](capi-image-source-native-h.md#oh_decodingoptions_getindex) | [OH_DecodingOptions_SetIndex](capi-image-source-native-h.md#oh_decodingoptions_setindex) |
| float | rotate | 旋转角度。 | 单位为角度（deg），默认值为0 | [OH_DecodingOptions_GetRotate](capi-image-source-native-h.md#oh_decodingoptions_getrotate) | [OH_DecodingOptions_SetRotate](capi-image-source-native-h.md#oh_decodingoptions_setrotate) |
| Image_Size | desiredSize | 期望输出大小。 | 默认为原始图片尺寸。 | [OH_DecodingOptions_GetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_getdesiredsize) | [OH_DecodingOptions_SetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_setdesiredsize) |
| Image_Region | desiredRegion | 解码区域。 | 默认为完整图片大小的区域。 | [OH_DecodingOptions_GetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_getdesiredregion) | [OH_DecodingOptions_SetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_setdesiredregion) |
| int32_t | desiredDynamicRange | 期望动态范围。 | SDR |[OH_DecodingOptions_GetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_getdesireddynamicrange) | [OH_DecodingOptions_SetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_setdesireddynamicrange) |
| int32_t | desiredColorSpace | 期望色彩空间。 | 默认色彩空间。 | [OH_DecodingOptions_GetDesiredColorSpace](capi-image-source-native-h.md#oh_decodingoptions_getdesiredcolorspace) | [OH_DecodingOptions_SetDesiredColorSpace](capi-image-source-native-h.md#oh_decodingoptions_setdesiredcolorspace) |
| Image_Region | cropRegion | 裁剪区域。 | 默认为完整图片大小的区域。 | [OH_DecodingOptions_GetCropRegion](capi-image-source-native-h.md#oh_decodingoptions_getcropregion) | [OH_DecodingOptions_SetCropRegion](capi-image-source-native-h.md#oh_decodingoptions_setcropregion) |
| int32_t | cropAndScaleStrategy | 裁剪和缩放策略。 | 0 | [OH_DecodingOptions_GetCropAndScaleStrategy](capi-image-source-native-h.md#oh_decodingoptions_getcropandscalestrategy) | [OH_DecodingOptions_SetCropAndScaleStrategy](capi-image-source-native-h.md#oh_decodingoptions_setcropandscalestrategy) |

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [image_source_native.h](capi-image-source-native-h.md)

**相关开发指导：** [使用Image_NativeModule完成图片解码](../../media/image/image-source-c.md)、[图片区域解码与下采样(C/C++)](../../media/image/image-region-and-downsampling-c.md)、[使用Image_NativeModule完成HDR图片解码](../../media/image/image-hdr-decoding-c.md)
