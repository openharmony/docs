# OH_DecodingOptions
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

OH_DecodingOptions是native层封装的解码选项参数结构体，用于设置解码选项参数，在创建Pixelmap时作为入参传入，详细信息见[OH_ImageSourceNative_CreatePixelmap](capi-image-source-native-h.md#oh_imagesourcenative_createpixelmap)。

OH_DecodingOptions结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

创建OH_DecodingOptions对象使用[OH_DecodingOptions_Create](capi-image-source-native-h.md#oh_decodingoptions_create)函数。

释放OH_DecodingOptions对象使用[OH_DecodingOptions_Release](capi-image-source-native-h.md#oh_decodingoptions_release)函数。

OH_DecodingOptions结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| int32_t | pixelFormat | 像素格式 | [OH_DecodingOptions_GetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_getpixelformat) |获取pixel格式。|
| int32_t | pixelFormat | 像素格式 | [OH_DecodingOptions_SetPixelFormat](capi-image-source-native-h.md#oh_decodingoptions_setpixelformat) | 设置像素格式。|
| uint32_t | index | 解码图片序号 | [OH_DecodingOptions_GetIndex](capi-image-source-native-h.md#oh_decodingoptions_getindex) | 获取解码图片序号。|
| uint32_t | index | 解码图片序号 | [OH_DecodingOptions_SetIndex](capi-image-source-native-h.md#oh_decodingoptions_setindex) | 设置解码图片序号。|
| float | rotate | 旋转角度 | [OH_DecodingOptions_GetRotate](capi-image-source-native-h.md#oh_decodingoptions_getrotate) | 获取旋转角度。|
| float | rotate | 旋转角度 | [OH_DecodingOptions_SetRotate](capi-image-source-native-h.md#oh_decodingoptions_setrotate) | 设置旋转角度。|
| Image_Size | desiredSize | 期望输出大小 | [OH_DecodingOptions_GetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_getdesiredsize) | 获取期望输出大小。|
| Image_Size | desiredSize | 期望输出大小 | [OH_DecodingOptions_SetDesiredSize](capi-image-source-native-h.md#oh_decodingoptions_setdesiredsize) | 设置期望输出大小。|
| Image_Region | desiredRegion | 解码区域 | [OH_DecodingOptions_GetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_getdesiredregion) | 获取解码区域。|
| Image_Region | desiredRegion | 解码区域 | [OH_DecodingOptions_SetDesiredRegion](capi-image-source-native-h.md#oh_decodingoptions_setdesiredregion) | 设置解码区域。|
| int32_t | desiredDynamicRange | 期望动态范围 | [OH_DecodingOptions_GetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_getdesireddynamicrange) |获取解码时设置的期望动态范围。|
| int32_t | desiredDynamicRange | 期望动态范围 | [OH_DecodingOptions_SetDesiredDynamicRange](capi-image-source-native-h.md#oh_decodingoptions_setdesireddynamicrange)|设置解码时的期望动态范围。|

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [image_source_native.h](capi-image-source-native-h.md)

