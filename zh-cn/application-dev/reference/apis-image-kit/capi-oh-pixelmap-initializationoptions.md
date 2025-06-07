# OH_Pixelmap_InitializationOptions

## 概述

OH_Pixelmap_InitializationOptions是native层封装的初始化参数结构体，用于设置Pixelmap的初始化参数。

创建OH_Pixelmap_InitializationOptions对象使用[OH_PixelmapInitializationOptions_Create](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_create)函数。

释放OH_Pixelmap_InitializationOptions对象使用[OH_PixelmapInitializationOptions_Release](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_release)函数。

OH_Pixelmap_InitializationOptions结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | 图片宽 | [OH_PixelmapInitializationOptions_GetWidth](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getwidth) |获取图片宽。|
| uint32_t | width | 图片宽 | [OH_PixelmapInitializationOptions_SetWidth](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setwidth) |设置图片宽。|
| uint32_t | height | 图片高 | [OH_PixelmapInitializationOptions_GetHeight](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getheight) |获取图片高。|
| uint32_t | height | 图片高 | [OH_PixelmapInitializationOptions_SetHeight](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setheight) |设置图片高。|
| int32_t | pixelFormat | 像素格式 | [OH_PixelmapInitializationOptions_GetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getpixelformat) |获取像素格式。|
| int32_t | pixelFormat | 像素格式 | [OH_PixelmapInitializationOptions_SetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setpixelformat) |设置像素格式。|
| int32_t | alphaType | 透明度类型 | [OH_PixelmapInitializationOptions_GetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getalphatype) |获取透明度类型。|
| int32_t | alphaType | 透明度类型 | [OH_PixelmapInitializationOptions_SetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setalphatype) |设置透明度类型。|

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**所在头文件：** [pixelmap_native.h](capi-pixelmap-native-h.md)