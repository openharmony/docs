# image_native.h


## 概述

声明图像的剪辑矩形、大小和组件数据的接口函数。

**库：** libohimage.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImageNative](_image___native_module.md#oh_imagenative) [OH_ImageNative](_image___native_module.md#oh_imagenative) | 为图像接口定义native层图像对象的别名。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetImageSize](_image___native_module.md#oh_imagenative_getimagesize) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, [Image_Size](_image___size.md) \*size) | 获取native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象的 [Image_Size](_image___size.md) 信息。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetComponentTypes](_image___native_module.md#oh_imagenative_getcomponenttypes) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t \*\*types, size_t \*typeSize) | 获取native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象的组件列表信息。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetByteBuffer](_image___native_module.md#oh_imagenative_getbytebuffer) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, OH_NativeBuffer \*\*nativeBuffer) | 获取native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象中某个组件类型所对应的缓冲区。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetBufferSize](_image___native_module.md#oh_imagenative_getbuffersize) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, size_t \*size) | 获取native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象中某个组件类型所对应的缓冲区的大小。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetRowStride](_image___native_module.md#oh_imagenative_getrowstride) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, int32_t \*rowStride) | 获取native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象中某个组件类型所对应的像素行宽。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetPixelStride](_image___native_module.md#oh_imagenative_getpixelstride) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, uint32_t componentType, int32_t \*pixelStride) | 获取native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象中某个组件类型所对应的像素大小。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_GetTimestamp](_image___native_module.md#oh_imagenative_gettimestamp) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image, int64_t \*timestamp) | 获取Native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象中的时间戳信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageNative_Release](_image___native_module.md#oh_imagenative_release) ([OH_ImageNative](_image___native_module.md#oh_imagenative) \*image) | 释放native [OH_ImageNative](_image___native_module.md#oh_imagenative) 对象。  | 
