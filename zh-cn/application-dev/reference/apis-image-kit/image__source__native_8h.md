# image_source_native.h


## 概述

图片解码API。

**库：** libimage_source.so

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) | ImageSource结构体类型，用于执行ImageSource相关操作。 | 
| typedef struct [OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) [OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) | 图片源信息结构体 [OH_ImageSourceInfo_Create](_image___native_module.md#oh_imagesourceinfo_create)。 | 
| typedef struct [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) | 解码选项参数结构体，被用于[OH_ImageSourceNative_CreatePixelmap](_image___native_module.md#oh_imagesourcenative_createpixelmap)。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [IMAGE_DYNAMIC_RANGE](_image___native_module.md#image_dynamic_range) {<br/>IMAGE_DYNAMIC_RANGE_AUTO = 0,<br/>IMAGE_DYNAMIC_RANGE_SDR = 1,<br/>IMAGE_DYNAMIC_RANGE_HDR = 2<br/>} | 解码指定期望动态范围。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_Create](_image___native_module.md#oh_imagesourceinfo_create) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*\*info) | 创建OH_ImageSource_Info指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_GetWidth](_image___native_module.md#oh_imagesourceinfo_getwidth) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info, uint32_t \*width) | 获取图片的宽。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_GetHeight](_image___native_module.md#oh_imagesourceinfo_getheight) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info, uint32_t \*height) | 获取图片的高。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_GetDynamicRange](_image___native_module.md#oh_imagesourceinfo_getdynamicrange) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info, bool \*isHdr) | 获取图片是否为高动态范围的信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceInfo_Release](_image___native_module.md#oh_imagesourceinfo_release) ([OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info) | 释放OH_ImageSource_Info指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_Create](_image___native_module.md#oh_decodingoptions_create) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*\*options) | 创建OH_DecodingOptions指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetPixelFormat](_image___native_module.md#oh_decodingoptions_getpixelformat) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t \*pixelFormat) | 获取pixel格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetPixelFormat](_image___native_module.md#oh_decodingoptions_setpixelformat) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t pixelFormat) | 设置pixel格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetIndex](_image___native_module.md#oh_decodingoptions_getindex) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, uint32_t \*index) | 获取解码图片序号。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetIndex](_image___native_module.md#oh_decodingoptions_setindex) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, uint32_t index) | 设置解码图片序号。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetRotate](_image___native_module.md#oh_decodingoptions_getrotate) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, float \*rotate) | 获取旋转角度。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetRotate](_image___native_module.md#oh_decodingoptions_setrotate) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, float rotate) | 设置旋转角度。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetDesiredSize](_image___native_module.md#oh_decodingoptions_getdesiredsize) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | 获取期望输出大小。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetDesiredSize](_image___native_module.md#oh_decodingoptions_setdesiredsize) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | 设置期望输出大小。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetDesiredRegion](_image___native_module.md#oh_decodingoptions_getdesiredregion) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | 获取解码区域。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetDesiredRegion](_image___native_module.md#oh_decodingoptions_setdesiredregion) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | 设置解码区域。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_GetDesiredDynamicRange](_image___native_module.md#oh_decodingoptions_getdesireddynamicrange) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t \*desiredDynamicRange) | 获取解码时设置的期望动态范围。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_SetDesiredDynamicRange](_image___native_module.md#oh_decodingoptions_setdesireddynamicrange) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, int32_t desiredDynamicRange) | 设置解码时的期望动态范围。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptions_Release](_image___native_module.md#oh_decodingoptions_release) ([OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options) | 释放OH_DecodingOptions指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromUri](_image___native_module.md#oh_imagesourcenative_createfromuri) (char \*uri, size_t uriSize, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | 通过uri创建OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromFd](_image___native_module.md#oh_imagesourcenative_createfromfd) (int32_t fd, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | 通过fd创建OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromData](_image___native_module.md#oh_imagesourcenative_createfromdata) (uint8_t \*data, size_t dataSize, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | 通过缓冲区数据创建OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreateFromRawFile](_image___native_module.md#oh_imagesourcenative_createfromrawfile) (RawFileDescriptor \*rawFile, [OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*\*res) | 通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreatePixelmap](_image___native_module.md#oh_imagesourcenative_createpixelmap) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmap) | 通过图片解码参数创建OH_PixelmapNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreatePixelmapList](_image___native_module.md#oh_imagesourcenative_createpixelmaplist) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [OH_DecodingOptions](_image___native_module.md#oh_decodingoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*resVecPixMap[], size_t size) | 通过图片解码参数创建OH_PixelmapNative数组。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_CreatePicture](_image___native_module.md#oh_imagesourcenative_createpicture) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, OH_DecodingOptionsForPicture \*options, [OH_PictureNative](_image___native_module.md#oh_picturenative) \*\*picture) | 通过图片解码创建OH_PictureNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetDelayTimeList](_image___native_module.md#oh_imagesourcenative_getdelaytimelist) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, int32_t \*delayTimeList, size_t size) | 获取图像延迟时间数组。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetImageInfo](_image___native_module.md#oh_imagesourcenative_getimageinfo) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, int32_t index, [OH_ImageSource_Info](_image___native_module.md#oh_imagesource_info) \*info) | 获取指定序号的图片信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetImageProperty](_image___native_module.md#oh_imagesourcenative_getimageproperty) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 获取图片指定属性键的值。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_ModifyImageProperty](_image___native_module.md#oh_imagesourcenative_modifyimageproperty) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 通过指定的键修改图片属性的值。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_GetFrameCount](_image___native_module.md#oh_imagesourcenative_getframecount) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source, uint32_t \*frameCount) | 获取图像帧数。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_ImageSourceNative_Release](_image___native_module.md#oh_imagesourcenative_release) ([OH_ImageSourceNative](_image___native_module.md#oh_imagesourcenative) \*source) | 释放OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_Create](_image___native_module.md#oh_decodingoptionsforpicture_create) (OH_DecodingOptionsForPicture \*\*options) | 创建OH_DecodingOptionsForPicture指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures](_image___native_module.md#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) (OH_DecodingOptionsForPicture \*options, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*\*desiredAuxiliaryPictures, size_t \*length) | 获取解码时设置的期望辅助图（期望解码出的picture包含的辅助图）。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures](_image___native_module.md#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) (OH_DecodingOptionsForPicture \*options, [Image_AuxiliaryPictureType](_image___native_module.md#image_auxiliarypicturetype) \*desiredAuxiliaryPictures, size_t length) | 设置解码选项中的期望辅助图。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_DecodingOptionsForPicture_Release](_image___native_module.md#oh_decodingoptionsforpicture_release) (OH_DecodingOptionsForPicture \*options) | 释放OH_DecodingOptionsForPicture指针。 | 
