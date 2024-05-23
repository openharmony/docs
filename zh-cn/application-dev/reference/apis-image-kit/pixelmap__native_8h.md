# pixelmap_native.h


## 概述

访问Pixelmap的API。

**库：** libpixelmap.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) | Pixelmap结构体类型，用于执行Pixelmap相关操作。 | 
| typedef struct [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) | 初始化参数结构体。 | 
| typedef struct [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) | 图像像素信息结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PIXELMAP_ALPHA_TYPE](_image___native_module.md#pixelmap_alpha_type) {<br/>PIXELMAP_ALPHA_TYPE_UNKNOWN = 0,<br/>PIXELMAP_ALPHA_TYPE_OPAQUE = 1,<br/>PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2 } | Pixelmap透明度类型。 | 
| [PIXEL_FORMAT](_image___native_module.md#pixel_format) {<br/>PIXEL_FORMAT_UNKNOWN = 0, PIXEL_FORMAT_RGB_565 = 2,<br/>PIXEL_FORMAT_RGBA_8888 = 3, PIXEL_FORMAT_BGRA_8888 = 4,<br/>PIXEL_FORMAT_RGB_888 = 5, PIXEL_FORMAT_ALPHA_8 = 6,<br/>PIXEL_FORMAT_RGBA_F16 = 7, PIXEL_FORMAT_NV21 = 8,<br/>PIXEL_FORMAT_NV12 = 9<br/>} | 图片像素格式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_Create](_image___native_module.md#oh_pixelmapinitializationoptions_create) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*\*options) | 创建OH_Pixelmap_InitializationOptions指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetWidth](_image___native_module.md#oh_pixelmapinitializationoptions_getwidth) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t \*width) | 获取图片宽。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetWidth](_image___native_module.md#oh_pixelmapinitializationoptions_setwidth) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t width) | 设置图片宽。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetHeight](_image___native_module.md#oh_pixelmapinitializationoptions_getheight) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t \*height) | 获取图片高。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetHeight](_image___native_module.md#oh_pixelmapinitializationoptions_setheight) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t height) | 设置图片高。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_getpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t \*pixelFormat) | 获取像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_setpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t pixelFormat) | 设置像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetAlphaType](_image___native_module.md#oh_pixelmapinitializationoptions_getalphatype) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t \*alphaType) | 获取透明度类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetAlphaType](_image___native_module.md#oh_pixelmapinitializationoptions_setalphatype) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t alphaType) | 设置透明度类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_Release](_image___native_module.md#oh_pixelmapinitializationoptions_release) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options) | 释放OH_Pixelmap_InitializationOptions指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_Create](_image___native_module.md#oh_pixelmapimageinfo_create) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*\*info) | 创建OH_Pixelmap_ImageInfo指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetWidth](_image___native_module.md#oh_pixelmapimageinfo_getwidth) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*width) | 获取图片宽。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetHeight](_image___native_module.md#oh_pixelmapimageinfo_getheight) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*height) | 获取图片高。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetRowStride](_image___native_module.md#oh_pixelmapimageinfo_getrowstride) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*rowStride) | 获取行跨距。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetPixelFormat](_image___native_module.md#oh_pixelmapimageinfo_getpixelformat) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, int32_t \*pixelFormat) | 获取像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetAlphaType](_image___native_module.md#oh_pixelmapimageinfo_getalphatype) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, int32_t \*alphaType) | 获取透明度类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetDynamicRange](_image___native_module.md#oh_pixelmapimageinfo_getdynamicrange) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, bool \*isHdr) | 获取Pixelmap是否为高动态范围的信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_Release](_image___native_module.md#oh_pixelmapimageinfo_release) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info) | 释放OH_Pixelmap_ImageInfo指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_CreatePixelmap](_image___native_module.md#oh_pixelmapnative_createpixelmap) (uint8_t \*data, size_t dataLength, [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmap) | 通过属性创建PixelMap，默认采用BGRA_8888格式处理数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_ReadPixels](_image___native_module.md#oh_pixelmapnative_readpixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | 读取图像像素数据，结果写入ArrayBuffer里。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_WritePixels](_image___native_module.md#oh_pixelmapnative_writepixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*source, size_t bufferSize) | 读取缓冲区中的图片数据，结果写入PixelMap中 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetImageInfo](_image___native_module.md#oh_pixelmapnative_getimageinfo) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*imageInfo) | 获取图像像素信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Opacity](_image___native_module.md#oh_pixelmapnative_opacity) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float rate) | 通过设置透明比率来让PixelMap达到对应的透明效果 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Scale](_image___native_module.md#oh_pixelmapnative_scale) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY) | 根据输入的宽高对图片进行缩放。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Translate](_image___native_module.md#oh_pixelmapnative_translate) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float x, float y) | 根据输入的坐标对图片进行位置变换。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Rotate](_image___native_module.md#oh_pixelmapnative_rotate) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float angle) | 根据输入的角度对图片进行旋转。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Flip](_image___native_module.md#oh_pixelmapnative_flip) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically) | 根据输入的条件对图片进行翻转。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Crop](_image___native_module.md#oh_pixelmapnative_crop) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [Image_Region](_image___region.md) \*region) | 根据输入的尺寸对图片进行裁剪 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Release](_image___native_module.md#oh_pixelmapnative_release) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap) | 释放OH_PixelmapNative指针。 | 
