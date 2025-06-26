# OH_Pixelmap_ImageInfo

## 概述

OH_Pixelmap_ImageInfo是native层封装的图像像素信息结构体，保存图像像素的宽高、行跨距、像素格式、是否是HDR。

创建OH_Pixelmap_ImageInfo对象使用[OH_PixelmapImageInfo_Create](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_create)函数。

释放OH_Pixelmap_ImageInfo对象使用[OH_PixelmapImageInfo_Release](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_release)函数。

OH_Pixelmap_ImageInfo结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | 图片宽 | [OH_PixelmapImageInfo_GetWidth](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getwidth) | 获取图片宽。|
| uint32_t | height | 图片高 | [OH_PixelmapImageInfo_GetHeight](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getheight) | 获取图片高。|
| uint32_t | rowStride | 行跨距 | [OH_PixelmapImageInfo_GetRowStride](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride) | 获取行跨距。|
| int32_t | pixelFormat| 像素格式 | [OH_PixelmapImageInfo_GetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getpixelformat) |获取像素格式。|
| int32_t | alphaType | 透明度类型 | [OH_PixelmapImageInfo_GetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getalphatype) |获取透明度类型。|
| bool | isHdr | 是否为高动态范围的信息 | [OH_PixelmapImageInfo_GetDynamicRange](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getdynamicrange) |获取Pixelmap是否为高动态范围的信息。|

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [pixelmap_native.h](capi-pixelmap-native-h.md)