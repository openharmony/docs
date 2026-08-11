# OH_Pixelmap_ImageInfo
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

```c
struct OH_Pixelmap_ImageInfo
```

## 概述

OH_Pixelmap_ImageInfo是Native层封装的图像像素信息结构体，保存图像像素的宽高、行跨距、像素格式、透明度类型、是否为HDR等信息，适用于在Native层查询Pixelmap属性的场景。

创建OH_Pixelmap_ImageInfo对象使用[OH_PixelmapImageInfo_Create](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_create)函数，使用完成后需调用[OH_PixelmapImageInfo_Release](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_release)函数释放资源，两者需配对使用，否则会导致内存泄漏。

OH_Pixelmap_ImageInfo结构体内容和操作方式如下：

| 字段类型 | 字段名称 | 字段描述 | 操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | 图片宽，单位：像素（px）。 | [OH_PixelmapImageInfo_GetWidth](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getwidth) | 获取图片宽。 |
| uint32_t | height | 图片高，单位：像素（px）。 | [OH_PixelmapImageInfo_GetHeight](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getheight) | 获取图片高。 |
| uint32_t | rowStride | 行跨距，表示内存中每行像素所占的空间。单位：字节（Byte）。受内存对齐影响，该值可能大于图片宽度对应的实际像素数据字节数。 | [OH_PixelmapImageInfo_GetRowStride](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride) | 获取行跨距。 |
| int32_t | pixelFormat | 像素格式，表示像素数据的颜色通道排列和位深信息，取值参考[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 | [OH_PixelmapImageInfo_GetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getpixelformat) | 获取像素格式。 |
| int32_t | alphaType | 透明度类型，取值参考[PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type)。 | [OH_PixelmapImageInfo_GetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getalphatype) | 获取透明度类型。 |
| bool | isHdr | 是否为高动态范围（HDR）的信息。true表示是HDR，false表示非HDR。 | [OH_PixelmapImageInfo_GetDynamicRange](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getdynamicrange) | 获取Pixelmap是否为高动态范围的信息。返回true表示是HDR，返回false表示非HDR。 |

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [pixelmap_native.h](capi-pixelmap-native-h.md)