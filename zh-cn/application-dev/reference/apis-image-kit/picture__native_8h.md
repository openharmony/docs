# picture_native.h


## 概述

提供获取picture数据和信息的API。

**库：** libpicture.so 

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 13

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_PictureNative](_image___native_module.md#oh_picturenative) [OH_PictureNative](_image___native_module.md#oh_picturenative) | Picture结构体类型，用于执行picture相关操作。 | 
| typedef struct [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) | AuxiliaryPicture结构体类型，用于执行AuxiliaryPicture相关操作。 | 
| typedef struct [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) | AuxiliaryPictureInfo结构体类型，用于执行AuxiliaryPictureInfo相关操作。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) {<br/>AUXILIARY_PICTURE_TYPE_GAINMAP = 1,<br/>AUXILIARY_PICTURE_TYPE_DEPTH_MAP = 2,<br/>AUXILIARY_PICTURE_TYPE_UNREFOCUS_MAP = 3,<br/>AUXILIARY_PICTURE_TYPE_LINEAR_MAP = 4,<br/>AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP = 5<br/>} | 辅助图类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_CreatePicture](_image___native_module.md#oh_picturenative_createpicture) (OH_PixelmapNative \*mainPixelmap, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*\*picture) | 创建OH_PictureNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetMainPixelmap](_image___native_module.md#oh_picturenative_getmainpixelmap) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, OH_PixelmapNative \*\*mainPixelmap) | 获取主图的OH_PixelmapNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetHdrComposedPixelmap](_image___native_module.md#oh_picturenative_gethdrcomposedpixelmap) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, OH_PixelmapNative \*\*hdrPixelmap) | 获取hdr图的OH_PixelmapNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetGainmapPixelmap](_image___native_module.md#oh_picturenative_getgainmappixelmap) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, OH_PixelmapNative \*\*gainmapPixelmap) | 获取增益图的OH_PixelmapNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_SetAuxiliaryPicture](_image___native_module.md#oh_picturenative_setauxiliarypicture) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture) | 设置辅助图。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetAuxiliaryPicture](_image___native_module.md#oh_picturenative_getauxiliarypicture) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*\*auxiliaryPicture) | 根据类型获取辅助图。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_GetMetadata](_image___native_module.md#oh_picturenative_getmetadata) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*metadata) | 获取主图的元数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_SetMetadata](_image___native_module.md#oh_picturenative_setmetadata) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata) | 设置主图的元数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PictureNative_Release](_image___native_module.md#oh_picturenative_release) ([OH_PictureNative](_image___native_module.md#oh_picturenative) \*picture) | 释放OH_PictureNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_Create](_image___native_module.md#oh_auxiliarypicturenative_create) (uint8_t \*data, size_t dataLength, [Image_Size](_image___size.md) \*size, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*\*auxiliaryPicture) | 创建OH_AuxiliaryPictureNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_WritePixels](_image___native_module.md#oh_auxiliarypicturenative_writepixels) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, uint8_t \*source, size_t bufferSize) | 读取缓冲区的图像像素数据，并将结果写入为辅助图中。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_ReadPixels](_image___native_module.md#oh_auxiliarypicturenative_readpixels) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, uint8_t \*destination, size_t \*bufferSize) | 读取辅助图的像素数据，结果写入缓冲区。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_GetType](_image___native_module.md#oh_auxiliarypicturenative_gettype) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*type) | 获取辅助图类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_GetInfo](_image___native_module.md#oh_auxiliarypicturenative_getinfo) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*\*info) | 获取辅助图信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_SetInfo](_image___native_module.md#oh_auxiliarypicturenative_setinfo) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info) | 设置辅助图信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_GetMetadata](_image___native_module.md#oh_auxiliarypicturenative_getmetadata) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*\*metadata) | 获取辅助图的元数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_SetMetadata](_image___native_module.md#oh_auxiliarypicturenative_setmetadata) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_MetadataType](_image___native_module.md#image_metadatatype) metadataType, [OH_PictureMetadata](_image___native_module.md#oh_picturemetadata) \*metadata) | 设置辅助图的元数据。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureNative_Release](_image___native_module.md#oh_auxiliarypicturenative_release) ([OH_AuxiliaryPictureNative](_image___native_module.md#oh_auxiliarypicturenative) \*picture) | 释放OH_AuxiliaryPictureNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_Create](_image___native_module.md#oh_auxiliarypictureinfo_create) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*\*info) | 创建一个OH_AuxiliaryPictureInfo对象。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetType](_image___native_module.md#oh_auxiliarypictureinfo_gettype) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*type) | 获取辅助图的图片信息的辅助图类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetType](_image___native_module.md#oh_auxiliarypictureinfo_settype) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) type) | 设置辅助图的图片信息的辅助图类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetSize](_image___native_module.md#oh_auxiliarypictureinfo_getsize) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_Size](_image___size.md) \*size) | 获取辅助图的图片尺寸。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetSize](_image___native_module.md#oh_auxiliarypictureinfo_setsize) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, [Image_Size](_image___size.md) \*size) | 设置辅助图的图片尺寸。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetRowStride](_image___native_module.md#oh_auxiliarypictureinfo_getrowstride) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, uint32_t \*rowStride) | 获取辅助图的图片信息的行跨距。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetRowStride](_image___native_module.md#oh_auxiliarypictureinfo_setrowstride) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, uint32_t rowStride) | 设置辅助图的图片信息的行跨距。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_GetPixelFormat](_image___native_module.md#oh_auxiliarypictureinfo_getpixelformat) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, PIXEL_FORMAT \*pixelFormat) | 获取辅助图的图片信息的像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_SetPixelFormat](_image___native_module.md#oh_auxiliarypictureinfo_setpixelformat) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info, PIXEL_FORMAT pixelFormat) | 设置辅助图的图片信息的像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_AuxiliaryPictureInfo_Release](_image___native_module.md#oh_auxiliarypictureinfo_release) ([OH_AuxiliaryPictureInfo](_image___native_module.md#oh_auxiliarypictureinfo) \*info) | 释放OH_AuxiliaryPictureInfo指针。 | 
