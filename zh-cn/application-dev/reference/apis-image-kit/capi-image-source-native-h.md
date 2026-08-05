# image_source_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

图片解码API。

**引用文件：** <multimedia/image_framework/image/image_source_native.h>

**库：** libimage_source.so

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

**相关开发指导：** [使用Image_NativeModule完成图片解码](../../media/image/image-source-c.md)、[图片区域解码与下采样(C/C++)](../../media/image/image-region-and-downsampling-c.md)、[使用Image_NativeModule完成动图解码](../../media/image/image-animated-decoding-c.md)、[使用Image_NativeModule完成HDR图片解码](../../media/image/image-hdr-decoding-c.md)、[使用Image_NativeModule完成多图对象解码](../../media/image/image-source-picture-c.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) | OH_ImageSourceNative | OH_ImageSourceNative是native层封装的ImageSource结构体，用于创建图片数据。 |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) | OH_ImageSource_Info | OH_ImageSource_Info是native层封装的ImageSource信息结构体，OH_ImageSource_Info结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。 |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) | OH_DecodingOptionsForPicture | Picture解码参数结构体。通过[OH_DecodingOptionsForPicture_Create](#oh_decodingoptionsforpicture_create)获取。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) | OH_DecodingOptions | OH_DecodingOptions是native层封装的解码选项参数结构体，用于设置解码选项参数，在创建Pixelmap时作为入参传入，详细信息见[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)。 |
| [OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) | OH_ImageRawData | 定义图像中的原始数据。通过[OH_ImageSourceNative_CreateImageRawData](capi-image-source-native-h.md#oh_imagesourcenative_createimagerawdata)获取。|

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [IMAGE_DYNAMIC_RANGE](#image_dynamic_range) | IMAGE_DYNAMIC_RANGE | 解码指定期望动态范围。 |
| [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) | IMAGE_ALLOCATOR_TYPE | 用于分配PixelMap内存的分配器类型。 |
| [Image_CropAndScaleStrategy](#image_cropandscalestrategy) | Image_CropAndScaleStrategy | 在同时指定desiredSize和desiredRegion时执行裁剪和缩放的策略。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Image_ErrorCode OH_ImageSourceInfo_Create(OH_ImageSource_Info **info)](#oh_imagesourceinfo_create) | 创建OH_ImageSource_Info指针。 |
| [Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)](#oh_imagesourceinfo_getwidth) | 获取图片的宽。对于没有width标签的SVG图片，返回默认值0。 |
| [Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)](#oh_imagesourceinfo_getheight) | 获取图片的高。对于没有height标签的SVG图片，返回默认值0。 |
| [Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)](#oh_imagesourceinfo_getdynamicrange) | 获取图片是否为高动态范围的信息。 |
| [Image_ErrorCode OH_ImageSourceInfo_GetMimeType(OH_ImageSource_Info *info, Image_MimeType *mimetype)](#oh_imagesourceinfo_getmimetype) | 获取图片源的MIME类型。 |
| [Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)](#oh_imagesourceinfo_release) | 释放OH_ImageSource_Info指针。调用该接口后，通过OH_ImageSourceInfo_GetMimeType()获取到的mimeType.data会失效；如需在释放后继续使用MIME类型数据，应在释放前自行深拷贝。 |
| [Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)](#oh_decodingoptions_create) | 创建OH_DecodingOptions指针。 |
| [Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options, int32_t *pixelFormat)](#oh_decodingoptions_getpixelformat) | 获取pixel格式。 |
| [Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options, int32_t pixelFormat)](#oh_decodingoptions_setpixelformat) | 设置pixel格式。 |
| [Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)](#oh_decodingoptions_getindex) | 获取解码图片序号。 |
| [Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)](#oh_decodingoptions_setindex) | 设置解码图片序号。 |
| [Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)](#oh_decodingoptions_getrotate) | 获取旋转角度。 |
| [Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)](#oh_decodingoptions_setrotate) | 设置旋转角度。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)](#oh_decodingoptions_getdesiredsize) | 获取期望输出大小。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)](#oh_decodingoptions_setdesiredsize) | 设置期望输出大小。desiredSize参数决定解码得到的PixelMap大小，且宽、高须为正整数。若与原尺寸比例不一致，则会进行拉伸/缩放到指定尺寸。默认为原始尺寸。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)](#oh_decodingoptions_getdesiredregion) | 获取解码区域。<br> 由于对应SetDesiredRegion接口无法满足区域解码诉求，从API version 19开始，推荐配套使用[OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion)接口替代。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)](#oh_decodingoptions_setdesiredregion) | 设置解码区域。<br> 实际解码结果会按照原图解码，无区域解码效果。从API version 19开始，推荐使用接口[OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion)替代。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options, int32_t *desiredDynamicRange)](#oh_decodingoptions_getdesireddynamicrange) | 获取解码时设置的期望动态范围。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options, int32_t desiredDynamicRange)](#oh_decodingoptions_setdesireddynamicrange) | 设置解码时的期望动态范围。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredColorSpace(OH_DecodingOptions *options, int32_t *colorSpace)](#oh_decodingoptions_getdesiredcolorspace) | 获取解码参数中设置的色彩空间。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredColorSpace(OH_DecodingOptions *options, int32_t colorSpace)](#oh_decodingoptions_setdesiredcolorspace) | 设置解码期望得到的色彩空间。 |
| [Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t cropAndScaleStrategy)](#oh_decodingoptions_setcropandscalestrategy) | 设置解码选项的裁剪和缩放策略。 |
| [Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t *cropAndScaleStrategy)](#oh_decodingoptions_getcropandscalestrategy) | 获取解码选项的裁剪和缩放策略。 |
| [Image_ErrorCode OH_DecodingOptions_GetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)](#oh_decodingoptions_getcropregion) | 获取解码参数中的裁剪区域。 |
| [Image_ErrorCode OH_DecodingOptions_SetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)](#oh_decodingoptions_setcropregion) | 设置解码参数中的裁剪区域。 |
| [Image_ErrorCode OH_DecodingOptions_Release(OH_DecodingOptions *options)](#oh_decodingoptions_release) | 释放OH_DecodingOptions指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromUri(char *uri, size_t uriSize, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromuri) | 通过uri创建OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromfd) | 通过fd创建OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromdata) | 通过缓冲区数据创建OH_ImageSourceNative指针。<br> data数据应该是未解码的数据，不要传入类似于RGBA，YUV的像素buffer数据，如果想通过像素buffer数据创建pixelMap，可以调用[OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap)这一类接口。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength, OH_ImageSourceNative **imageSource)](#oh_imagesourcenative_createfromdatawithuserbuffer) | 由数据缓存创建图片源。传入的数据缓存将在图片源对象中直接访问，在图片源对象的生命周期内，数据缓存需要保持可用。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromrawfile) | 通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmap) | 通过图片解码参数创建OH_PixelmapNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source, OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmapusingallocator) | 根据解码参数创建一个PixelMap，PixelMap使用的内存类型可以通过allocatorType来指定。<br> 默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理通过此接口返回的PixelMap时，请始终考虑步幅（stride）的影响。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative *resVecPixMap[], size_t size)](#oh_imagesourcenative_createpixelmaplist) | 通过图片解码参数创建OH_PixelmapNative数组。<br> 注意，此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options, OH_PictureNative **picture)](#oh_imagesourcenative_createpicture) | 通过图片解码创建OH_PictureNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index, OH_PictureNative **picture)](#oh_imagesourcenative_createpictureatindex) | 通过指定序号的图片解码创建OH_PictureNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)](#oh_imagesourcenative_getdelaytimelist) | 获取图像延迟时间数组。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index, OH_ImageSource_Info *info)](#oh_imagesourcenative_getimageinfo) | 获取指定序号的图片信息。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_getimageproperty) | 获取图片指定属性键的值。该接口获取到的value.data缺少字符串结束符'\0'，请谨慎使用。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t *value)](#oh_imagesourcenative_getimagepropertyshort) | 以短整型类型获取图像属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t *value)](#oh_imagesourcenative_getimagepropertylong) | 以长整型类型获取图像属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double *value)](#oh_imagesourcenative_getimagepropertydouble) | 以浮点型类型获取图像属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyArraySize(OH_ImageSourceNative *source, Image_String *key, size_t *size)](#oh_imagesourcenative_getimagepropertyarraysize) | 获取数组类型属性的数组长度或字符串类型属性的字符串长度。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyString(OH_ImageSourceNative *source, Image_String *key, char *value, size_t size)](#oh_imagesourcenative_getimagepropertystring) | 以字符串类型获取图像属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)](#oh_imagesourcenative_getimagepropertyintarray) | 以整型数组类型获取图像属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)](#oh_imagesourcenative_getimagepropertydoublearray) | 以浮点型数组类型获取图像属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)](#oh_imagesourcenative_getimagepropertyblob) | 以二进制对象类型获取图像属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t value)](#oh_imagesourcenative_modifyimagepropertyshort) | 修改图像属性中短整型的值。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t value)](#oh_imagesourcenative_modifyimagepropertylong) | 修改图像属性中长整型的值。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double value)](#oh_imagesourcenative_modifyimagepropertydouble) | 修改图像属性中浮点型的值。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)](#oh_imagesourcenative_modifyimagepropertyintarray) | 修改图像属性中整型数组型的值。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)](#oh_imagesourcenative_modifyimagepropertydoublearray) | 修改图像属性中浮点型数组型的值。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)](#oh_imagesourcenative_modifyimagepropertyblob) | 修改图像属性中二进制对象的值。 |
| <!--DelRow--> [Image_ErrorCode OH_ImageSourceNative_ReadImageMetadataByType(OH_ImageSourceNative *source, uint32_t index, Image_MetadataType *metadataTypes, size_t typeCount, OH_PictureMetadata **outMetadataArray, size_t *metadataCount)](#oh_imagesourcenative_readimagemetadatabytype) | 读取图像源的元数据，使用metadataType指定元数据。如果未指定metadataType，将返回所有支持的元数据。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_getimagepropertywithnull) | 获取图像属性值。输出的value.data以字符串结束符'\0'结尾。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)](#oh_imagesourcenative_modifyimageproperty) | 通过指定的键修改图片属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)](#oh_imagesourcenative_getframecount) | 获取图像帧数。 |
| [Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)](#oh_imagesourcenative_getsupportedformats) | 获取支持解码的图片格式。 |
| [Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)](#oh_imagesourcenative_release) | 释放OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)](#oh_decodingoptionsforpicture_create) | 创建OH_DecodingOptionsForPicture指针。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)](#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) | 获取解码时设置的期望辅助图（期望解码出的picture包含的辅助图）。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)](#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) | 设置解码选项中的期望辅助图。 |
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_GetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool *needsDecodeDfxData)](#oh_decodingoptionsforpicture_getneedsdecodedfxdata) | 获取解码选项中的needsDecodeDfxData参数。 |
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_SetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool needsDecodeDfxData)](#oh_decodingoptionsforpicture_setneedsdecodedfxdata) | 设置解码选项中的needsDecodeDfxData参数。 |
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size *desiredSizeForMainPixelmap)](#oh_decodingoptionsforpicture_getdesiredsizeformainpixelmap) | 获取DecodingOptionsForPicture结构体中的主图期望尺寸。 |
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size desiredSizeForMainPixelmap)](#oh_decodingoptionsforpicture_setdesiredsizeformainpixelmap) | 设置DecodingOptionsForPicture结构体中的主图期望尺寸。 |
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT *desiredPixelFormat)](#oh_decodingoptionsforpicture_getdesiredpixelformat) | 获取DecodingOptionsForPicture结构体中的像素格式。 |
| <!--DelRow--> [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT desiredPixelFormat)](#oh_decodingoptionsforpicture_setdesiredpixelformat) | 设置DecodingOptionsForPicture结构体中的像素格式。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)](#oh_decodingoptionsforpicture_release) | 释放OH_DecodingOptionsForPicture指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateImageRawData(const OH_ImageSourceNative *source, OH_ImageRawData **rawData)](#oh_imagesourcenative_createimagerawdata) | 从图像中获取rawData对象。 |
| [Image_ErrorCode OH_ImageSourceNative_GetBufferFromRawData(const OH_ImageRawData *rawData, uint8_t **data, size_t *length)](#oh_imagesourcenative_getbufferfromrawdata) | 从rawData对象获取二进制数据。 |
| [Image_ErrorCode OH_ImageSourceNative_GetBitsPerPixelFromRawData(const OH_ImageRawData *rawData, uint8_t *bitsPerPixel)](#oh_imagesourcenative_getbitsperpixelfromrawdata) | 获取缓冲区数据中每个像素实际占用的位数。 |
| [Image_ErrorCode OH_ImageSourceNative_DestroyImageRawData(OH_ImageRawData *rawData)](#oh_imagesourcenative_destroyimagerawdata) | 销毁rawData对象。 |

## 枚举类型说明

### IMAGE_DYNAMIC_RANGE

```c
enum IMAGE_DYNAMIC_RANGE
```

**描述**

解码指定期望动态范围。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IMAGE_DYNAMIC_RANGE_AUTO = 0 | 根据图片自适应处理。 |
| IMAGE_DYNAMIC_RANGE_SDR = 1 | 标准动态范围。 |
| IMAGE_DYNAMIC_RANGE_HDR = 2 | 高动态范围。 |

### IMAGE_ALLOCATOR_TYPE

```c
enum IMAGE_ALLOCATOR_TYPE
```

**描述**

用于分配PixelMap内存的分配器类型。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| IMAGE_ALLOCATOR_TYPE_AUTO = 0 | 由系统决定使用DMA内存或共享内存来创建PixelMap。 |
| IMAGE_ALLOCATOR_TYPE_DMA = 1 | 使用DMA内存来创建PixelMap。 |
| IMAGE_ALLOCATOR_TYPE_SHARE_MEMORY = 2 | 使用共享内存来创建PixelMap。 |

### Image_CropAndScaleStrategy

```c
enum Image_CropAndScaleStrategy
```

**描述**

在同时指定desiredSize和desiredRegion时执行裁剪和缩放的策略。<br> 如果在配置解码选项[OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md)时，未填入参数Image_CropAndScaleStrategy，并且同时设置了desiredRegion和desiredSize，由于系统对于不同图片格式采用的解码算法不同，最终解码效果将略有差异。<br> 例如原始图片大小200x200，传入desiredSize:{width: 150, height: 150}，desiredRegion:{x: 0, y: 0, width: 100, height: 100}，即预期解码原图左上角1/4区域，最终将pixelMap大小缩放至150x150返回。<br> 对于jpeg、webp图片（部分dng图片解码时会优先解码图片中的jpeg预览图，在此场景下也会被视为jpeg图片格式）会先进行下采样，例如按照7/8下采样，再基于175x175的图片大小进行区域裁剪，因此最终的区域内容稍大于原图的左上角1/4区域。<br> 对于svg图片，由于是矢量图，可以任意缩放不损失清晰度，在解码时会根据desiredSize与原图Size的比例选择缩放比例，再基于缩放后的图片大小进行区域裁剪，因此最终返回的解码区域会有所差异。<br> 针对该场景，建议在解码选项同时设置了desiredRegion与desiredSize时，参数Image_CropAndScaleStrategy应传入CROP_FIRST参数保证效果一致。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| IMAGE_CROP_AND_SCALE_STRATEGY_SCALE_FIRST = 1 | 先缩放，后裁剪。 |
| IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST = 2 | 先裁剪，后缩放。 |


## 函数说明

### OH_ImageSourceInfo_Create()

```c
Image_ErrorCode OH_ImageSourceInfo_Create(OH_ImageSource_Info **info)
```

**描述**

创建OH_ImageSource_Info指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) **info | 被操作的OH_ImageSource_Info指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceInfo_GetWidth()

```c
Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)
```

**描述**

获取图片的宽。对于没有width标签的SVG图片，返回默认值0。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 被操作的OH_ImageSource_Info指针。 |
| uint32_t *width | 图片的宽，单位为像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceInfo_GetHeight()

```c
Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)
```

**描述**

获取图片的高。对于没有height标签的SVG图片，返回默认值0。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 被操作的OH_ImageSource_Info指针。 |
| uint32_t *height | 图片的高，单位为像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceInfo_GetDynamicRange()

```c
Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)
```

**描述**

获取图片是否为高动态范围的信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 被操作的OH_ImageSource_Info指针。 |
| bool *isHdr | 表示是否为高动态范围（HDR）的信息。true表示是高动态范围的信息，false表示不是高动态范围的信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_ImageSourceInfo_GetMimeType()

```c
Image_ErrorCode OH_ImageSourceInfo_GetMimeType(OH_ImageSource_Info *info, Image_MimeType *mimetype)
```

**描述**

获取图片源的MIME类型。

> **说明**
>
> - [mimeType结构体的成员变量](./capi-image-nativemodule-image-string.md#成员变量)data为char *类型指针，其指向info结构体内部持有的mimeType地址，释放info会导致该地址对应的内存也被释放。
> - 开发者可以自行深拷贝一份mimeType.data，或者等mimeType使用完成后再释放info，以免出现乱码现象。
> - mimeType.data没有以'\0'结尾，需要配合mimeType.size一起使用。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | OH_ImageSource_Info指针。 |
| [Image_MimeType](capi-image-nativemodule-image-string.md) *mimeType | 图片源的MIME类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：参数错误，INFO或者MIME类型为空。 |

### OH_ImageSourceInfo_Release()

```c
Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)
```

**描述**

释放OH_ImageSource_Info指针。调用该接口后，通过OH_ImageSourceInfo_GetMimeType()获取到的mimeType.data会失效；如需在释放后继续使用MIME类型数据，应在释放前自行深拷贝。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 被操作的OH_ImageSource_Info指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_Create()

```c
Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)
```

**描述**

创建OH_DecodingOptions指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) **options | 被操作的OH_DecodingOptions指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetPixelFormat()

```c
Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options, int32_t *pixelFormat)
```

**描述**

获取pixel格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t *pixelFormat | pixel格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)，默认值为RGBA_8888。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetPixelFormat()

```c
Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options,int32_t pixelFormat)
```

**描述**

设置pixel格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t pixelFormat | pixel格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)，默认值为RGBA_8888。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetIndex()

```c
Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)
```

**描述**

获取解码图片序号。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| uint32_t *index | 解码图片序号，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetIndex()

```c
Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)
```

**描述**

设置解码图片序号。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| uint32_t index | 解码图片序号，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetRotate()

```c
Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)
```

**描述**

获取旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| float *rotate | 旋转角度，单位为角度（deg），默认值为0。取值范围为[0, 360]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetRotate()

```c
Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)
```

**描述**

设置旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| float rotate | 旋转角度，单位为角度（deg），默认值为0。取值范围为[0, 360]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetDesiredSize()

```c
Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)
```

**描述**

获取期望输出大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | 期望输出大小，默认为原始图片尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetDesiredSize()

```c
Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)
```

**描述**

设置期望输出大小。desiredSize参数决定解码得到的PixelMap大小，且宽、高须为正整数。若与原尺寸比例不一致，则会进行拉伸/缩放到指定尺寸。默认为原始尺寸。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | 期望输出大小，默认为原始图片尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetDesiredRegion()

```c
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)
```

**描述**

获取解码区域。<br> 由于对应SetDesiredRegion接口无法满足区域解码诉求，从API version 19开始，推荐配套使用[OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion)接口替代。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | 解码区域，默认为完整图片大小的区域。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetDesiredRegion()

```c
Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)
```

**描述**

设置解码区域。<br> 实际解码结果会按照原图解码，无区域解码效果。从API version 19开始，推荐使用接口[OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion)替代。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | 解码区域，默认为完整图片大小的区域。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetDesiredDynamicRange()

```c
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options, int32_t *desiredDynamicRange)
```

**描述**

获取解码时设置的期望动态范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t *desiredDynamicRange | 期望的动态范围值[IMAGE_DYNAMIC_RANGE](#image_dynamic_range)，默认值为SDR。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_DecodingOptions_SetDesiredDynamicRange()

```c
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options, int32_t desiredDynamicRange)
```

**描述**

设置解码时的期望动态范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t desiredDynamicRange | 期望的动态范围值[IMAGE_DYNAMIC_RANGE](#image_dynamic_range)，默认值为SDR。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_DecodingOptions_GetDesiredColorSpace()

```c
Image_ErrorCode OH_DecodingOptions_GetDesiredColorSpace(OH_DecodingOptions *options, int32_t *colorSpace)
```

**描述**

获取解码参数中设置的色彩空间。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| int32_t *colorSpace | 解码参数中设置的色彩空间，参考[ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：参数错误。options或colorSpace为空。 |

### OH_DecodingOptions_SetDesiredColorSpace()

```c
Image_ErrorCode OH_DecodingOptions_SetDesiredColorSpace(OH_DecodingOptions *options, int32_t colorSpace)
```

**描述**

设置解码期望得到的色彩空间。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| int32_t colorSpace | 期望的色彩空间，参考[ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：参数错误。options为空，或者传入了不支持的colorSpace。 |

### OH_DecodingOptions_SetCropAndScaleStrategy()

```c
Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t cropAndScaleStrategy)
```

**描述**

设置解码选项的裁剪和缩放策略。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t cropAndScaleStrategy | 在同时指定desiredSize和desiredRegion时执行裁剪和缩放的策略。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：options空指针或者cropAndScaleStrategy取值不在Image_CropAndScaleStrategy枚举值定义之中。 |

### OH_DecodingOptions_GetCropAndScaleStrategy()

```c
Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options, int32_t *cropAndScaleStrategy)
```

**描述**

获取解码选项的裁剪和缩放策略。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t *cropAndScaleStrategy | 指向在同时指定desiredSize和desiredRegion时执行裁剪和缩放策略的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：options或者cropAndScaleStrategy为空指针。 |

### OH_DecodingOptions_GetCropRegion()

```c
Image_ErrorCode OH_DecodingOptions_GetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)
```

**描述**

获取解码参数中的裁剪区域。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 指向解码参数指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *cropRegion | 指向要裁剪的目标区域指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：options或cropRegion为空。 |

### OH_DecodingOptions_SetCropRegion()

```c
Image_ErrorCode OH_DecodingOptions_SetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)
```

**描述**

设置解码参数中的裁剪区域。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 指向解码参数指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *cropRegion | 指向要裁剪的目标区域指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：options或cropRegion为空。 |

### OH_DecodingOptions_Release()

```c
Image_ErrorCode OH_DecodingOptions_Release(OH_DecodingOptions *options)
```

**描述**

释放OH_DecodingOptions指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreateFromUri()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromUri(char *uri, size_t uriSize, OH_ImageSourceNative **res)
```

**描述**

通过uri创建OH_ImageSourceNative指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char *uri | 指向图像源URI的指针。只接受文件URI或Base64 URI。当前文件资源只支持绝对路径。 |
| size_t uriSize | URI长度。 |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_BAD_SOURCE：解码数据源异常。 |

### OH_ImageSourceNative_CreateFromFd()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)
```

**描述**

通过fd创建OH_ImageSourceNative指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t fd | 文件描述符fd。 |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreateFromData()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)
```

**描述**

通过缓冲区数据创建OH_ImageSourceNative指针。<br> data数据应该是未解码的数据，不要传入类似于RGBA，YUV的像素buffer数据。<br> 如果想通过像素buffer数据创建pixelMap，可以调用[OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap)这一类接口。

使用场景：适用于应用已经通过网络、文件或其他模块获取到完整编码图片数据的场景，例如JPEG、PNG、WebP等格式的二进制数据。该接口创建的是图片源对象，后续可继续调用[OH_ImageSourceNative_GetImageInfo](#oh_imagesourcenative_getimageinfo)读取图片信息，或调用[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)解码为PixelMap。

资源管理：成功创建的OH_ImageSourceNative对象由调用方持有，使用完成后必须调用[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)释放。传入的data仍由调用方管理，不应传入已经解码后的像素数据。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | 图像缓冲区数据。 |
| size_t dataSize | 图像缓冲区数据长度。 |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_BAD_SOURCE：解码数据源异常。 |

### OH_ImageSourceNative_CreateFromDataWithUserBuffer()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength, OH_ImageSourceNative **imageSource)
```

**描述**

由数据缓存创建图片源。传入的数据缓存将在图片源对象中直接访问，在图片源对象的生命周期内，数据缓存需要保持可用。

使用场景：适用于希望减少图片源创建过程中的数据拷贝，并且调用方能够保证输入缓冲区生命周期的场景。

资源管理：在调用[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)释放图片源对象之前，data指向的缓冲区不能被释放、复用或修改为其他图片数据。否则后续读取图片信息、解码或读取元数据时可能访问无效数据。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | 数据缓存指针。 |
| size_t datalength | 数据缓存长度。 |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **imageSource | 图片源的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：data或imageSource是空指针，datalength为0。 |

### OH_ImageSourceNative_CreateFromRawFile()

```c
Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)
```

**描述**

通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawFileDescriptor](../apis-localization-kit/capi-rawfile-rawfiledescriptor.md) *rawFile | 指示raw文件的文件描述符。 |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreatePixelmap()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative **pixelmap)
```

**描述**

通过图片解码参数创建OH_PixelmapNative指针。

使用场景：适用于将JPEG、PNG、WebP、GIF单帧等编码图片解码为可读取、处理或再编码的PixelMap。解码前可通过OH_DecodingOptions设置帧序号、目标像素格式、目标尺寸、裁剪区域、期望动态范围等参数。

使用约束：source、options和pixelmap均不能为空指针。调用前需先创建OH_ImageSourceNative对象；如需自定义解码参数，需先创建并设置OH_DecodingOptions对象。接口执行成功后，pixelmap指向新创建的OH_PixelmapNative对象；接口执行失败时，不应使用pixelmap指向的对象。

资源管理：成功创建的OH_PixelmapNative对象由调用方持有，使用完成后应调用[OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy)释放。OH_DecodingOptions和OH_ImageSourceNative对象不会因为创建PixelMap而自动释放，需要分别调用[OH_DecodingOptions_Release](#oh_decodingoptions_release)和[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)释放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 指向c++本地层创建的OH_PixelmapNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreatePixelmapUsingAllocator()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source, OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)
```

**描述**

根据解码参数创建一个PixelMap，PixelMap使用的内存类型可以通过allocatorType来指定。<br> 默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理通过此接口返回的PixelMap时，请始终考虑步幅（stride）的影响。

使用场景：适用于调用方需要明确指定PixelMap内存类型的场景。例如，后续图像处理链路要求DMA内存时，可指定IMAGE_ALLOCATOR_TYPE_DMA。

使用约束：source、options和pixelmap均不能为空指针。allocator需为[IMAGE_ALLOCATOR_TYPE](#image_allocator_type)中定义的有效枚举值。指定的内存类型可能受图片类型、图片大小、系统版本和设备能力限制，接口可能返回IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE。当调用方进程启用沙箱隔离，且指定IMAGE_ALLOCATOR_TYPE_DMA或由IMAGE_ALLOCATOR_TYPE_AUTO选择DMA内存时，需为该沙箱进程配置访问DMA内存相关资源的SELinux权限；否则可能因SELinux策略拦截导致接口调用阻塞或失败。

资源管理：成功创建的PixelMap需要调用[OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy)释放。读取或写入像素数据时，不能假设每行字节数等于宽度乘以每像素字节数，应通过[OH_PixelmapImageInfo_GetRowStride](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getrowstride)获取行跨距。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) allocator | 指示返回的PixelMap将使用哪种内存类型。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 指向c++本地层创建的OH_PixelmapNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_BAD_SOURCE：数据源异常。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持的MIME类型。<br>         IMAGE_SOURCE_TOO_LARGE：图像过大。<br>         IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE：不支持的分配器类型。例如，使用共享内存解码HDR图像，因为只有DMA支持HDR元数据。<br>         IMAGE_SOURCE_UNSUPPORTED_OPTIONS：不支持的选项。例如，无法将图像转换为所需的像素格式。<br>         IMAGE_DECODE_FAILED：解码失败。<br>         IMAGE_SOURCE_ALLOC_FAILED：内存分配失败。 |

### OH_ImageSourceNative_CreatePixelmapList()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative *resVecPixMap[], size_t size)
```

**描述**

通过图片解码参数创建OH_PixelmapNative数组。<br> 注意，此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。

使用场景：适用于需要一次性获取动图所有帧并自行处理的场景，例如生成缩略图序列、分析每帧内容或重新编码动图。仅播放动图时，不建议优先使用该接口。

使用约束：source、options和resVecPixMap均不能为空指针。调用方需根据帧数准备足够长度的resVecPixMap数组，size应与数组可写入元素数量一致。调用前可通过[OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount)查询帧数。

资源管理：resVecPixMap数组由调用方提供，数组中的每个OH_PixelmapNative对象创建成功后都由调用方持有。使用完成后，需要逐个调用[OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy)释放。如果接口返回失败，也应检查数组中已写入的非空PixelMap指针并释放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *resVecPixMap[] | 指向c++本地层创建的OH_PixelmapNative对象的指针数组。 |
| size_t size | 数组长度。 用户可以使用[OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。 |

### OH_ImageSourceNative_CreatePicture()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options, OH_PictureNative **picture)
```

**描述**

通过图片解码创建OH_PictureNative指针。

使用约束：source、options和picture均不能为空指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 解码参数。 |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | 指向c++本地层创建的OH_PictureNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImageSourceNative_CreatePictureAtIndex()

```c
Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index, OH_PictureNative **picture)
```

**描述**

通过指定序号的图片解码创建OH_PictureNative指针。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| uint32_t index | 解码图片序号。 |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | 指向c++本地层创建的OH_PictureNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_SOURCE：数据源异常。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持的MIME类型。<br>         IMAGE_SOURCE_TOO_LARGE：图像过大。<br>         IMAGE_SOURCE_UNSUPPORTED_OPTIONS：不支持的选项。例如，无效的图片序号。<br>         IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImageSourceNative_GetDelayTimeList()

```c
Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)
```

**描述**

获取图像延迟时间数组。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| int32_t *delayTimeList | 指向获得的延迟时间列表的指针。它不能是空指针。 |
| size_t size | delayTimeList的大小。用户可以从[OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount)获得大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetImageInfo()

```c
Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index, OH_ImageSource_Info *info)
```

**描述**

获取指定序号的图片信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| int32_t index | 图片序号。对GIF图片可传入[0,N-1],N表示GIF的帧数。对只有一帧数据的图片格式，可传入0。 |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 指向获取的图像源信息的OH_ImageSource_Info指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetImageProperty()

```c
Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```

**描述**

获取图片指定属性键的值。<br> 该接口获取到的value.data缺少字符串结束符'\0'，请谨慎使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。OH_ImageSourceNative使用完成后需要主动释放，参见[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 指向属性的指针。key的取值范围请参考image_common.h的[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量。 |
| [Image_String](capi-image-nativemodule-image-string.md) *value | 指向获取的值的指针（输出参数）。调用本接口前，用户应将value->data置为空指针，并将value->size设为0。接口会为value->data自动分配所需内存，并对value->size赋值。完成对该内存的使用后，用户必须使用C标准库提供的free()函数释放value->data指向的内存，否则会出现内存泄漏。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetImagePropertyShort()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t *value)
```

**描述**

以短整型类型获取图像属性的值。

> **说明：**
>
> 读取DNG格式图片时，该接口对部分key有特殊处理。以下字段的字符串取值请参考[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量的值：
> - NewSubfileType、ImageWidth、ImageLength、DefaultCropSize、Orientation、Compression、PhotometricInterpretation、PlanarConfiguration、RowsPerStrip、StripOffsets、StripByteCounts、SamplesPerPixel、BitsPerSample、YCbCrCoefficients、YCbCrSubSampling、YCbCrPositioning、ReferenceBlackWhite、XResolution、YResolution、ResolutionUnit字段：返回主图相关的字段值。
> - ImageUniqueID字段：根据规范进行校验，不符合规范时会返回空字符串。
> - ExifVersion、FlashpixVersion、ColorSpace字段：当图片中不存在该标签时，返回错误码。
> - DNGVersion字段：当版本号小于1.0.0.0时，统一返回1.0.0.0。
> - GPSVersionID字段：当没有有效的GPS数据时，会清除GPS版本号并返回0。
> - GPSAltitudeRef字段：当未设置GPSAltitude时，会设置为0xFFFFFFFF。
> - ISOSpeedRatings字段：当该标签值为0或65535时，会优先使用推荐曝光指数，若不存在则依次使用标准输出灵敏度、ISO速度、曝光指数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| uint16_t *value | 被查询的属性的查询结果。输出参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是短整型的值。 |

### OH_ImageSourceNative_GetImagePropertyLong()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t *value)
```

**描述**

以长整型类型获取图像属性的值。

> **说明：**
>
> 读取DNG格式图片时，该接口对部分key有特殊处理。以下字段的字符串取值请参考[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量的值：
> - NewSubfileType、ImageWidth、ImageLength、DefaultCropSize、Orientation、Compression、PhotometricInterpretation、PlanarConfiguration、RowsPerStrip、StripOffsets、StripByteCounts、SamplesPerPixel、BitsPerSample、YCbCrCoefficients、YCbCrSubSampling、YCbCrPositioning、ReferenceBlackWhite、XResolution、YResolution、ResolutionUnit字段：返回主图相关的字段值。
> - ImageUniqueID字段：根据规范进行校验，不符合规范时会返回空字符串。
> - ExifVersion、FlashpixVersion、ColorSpace字段：当图片中不存在该标签时，返回错误码。
> - DNGVersion字段：当版本号小于1.0.0.0时，统一返回1.0.0.0。
> - GPSVersionID字段：当没有有效的GPS数据时，会清除GPS版本号并返回0。
> - GPSAltitudeRef字段：当未设置GPSAltitude时，会设置为0xFFFFFFFF。
> - ISOSpeedRatings字段：当该标签值为0或65535时，会优先使用推荐曝光指数，若不存在则依次使用标准输出灵敏度、ISO速度、曝光指数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| uint32_t *value | 被查询属性的查询结果。输出参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是长整型的值。 |

### OH_ImageSourceNative_GetImagePropertyDouble()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double *value)
```

**描述**

以浮点型类型获取图像属性的值。

> **说明：**
>
> 读取DNG格式图片时，该接口对部分key有特殊处理。以下字段的字符串取值请参考[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量的值：
> - NewSubfileType、ImageWidth、ImageLength、DefaultCropSize、Orientation、Compression、PhotometricInterpretation、PlanarConfiguration、RowsPerStrip、StripOffsets、StripByteCounts、SamplesPerPixel、BitsPerSample、YCbCrCoefficients、YCbCrSubSampling、YCbCrPositioning、ReferenceBlackWhite、XResolution、YResolution、ResolutionUnit字段：返回主图相关的字段值。
> - ImageUniqueID字段：根据规范进行校验，不符合规范时会返回空字符串。
> - ExifVersion、FlashpixVersion、ColorSpace字段：当图片中不存在该标签时，返回错误码。
> - DNGVersion字段：当版本号小于1.0.0.0时，统一返回1.0.0.0。
> - GPSVersionID字段：当没有有效的GPS数据时，会清除GPS版本号并返回0。
> - GPSAltitudeRef字段：当未设置GPSAltitude时，会设置为0xFFFFFFFF。
> - ISOSpeedRatings字段：当该标签值为0或65535时，会优先使用推荐曝光指数，若不存在则依次使用标准输出灵敏度、ISO速度、曝光指数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| double *value | 被查询属性的查询结果。输出参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是浮点型的值。 |

### OH_ImageSourceNative_GetImagePropertyArraySize()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyArraySize(OH_ImageSourceNative *source, Image_String *key, size_t *size)
```

**描述**

获取数组类型属性的数组长度或字符串类型属性的字符串长度。

使用场景：适用于读取字符串、数组或二进制对象类型的图像属性前，先查询需要分配的缓冲区大小。典型流程为：先调用本接口获取长度，再由调用方分配缓冲区，最后调用[OH_ImageSourceNative_GetImagePropertyString](#oh_imagesourcenative_getimagepropertystring)、[OH_ImageSourceNative_GetImagePropertyIntArray](#oh_imagesourcenative_getimagepropertyintarray)、[OH_ImageSourceNative_GetImagePropertyDoubleArray](#oh_imagesourcenative_getimagepropertydoublearray)或[OH_ImageSourceNative_GetImagePropertyBlob](#oh_imagesourcenative_getimagepropertyblob)读取实际内容。

资源管理：本接口不分配属性值缓冲区。后续读取属性值时，如果缓冲区由调用方分配，则由调用方释放；如果使用[OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty)或[OH_ImageSourceNative_GetImagePropertyWithNull](#oh_imagesourcenative_getimagepropertywithnull)由系统分配value->data，使用完成后必须调用free()释放。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| size_t *size | 数组类型属性的数组长度，字符串类型属性的字符串长度。输出参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是数组或字符串类型的值。 |

### OH_ImageSourceNative_GetImagePropertyString()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyString(OH_ImageSourceNative *source, Image_String *key, char *value, size_t size)
```

**描述**

以字符串类型获取图像属性的值。

> **说明：**
>
> 读取DNG格式图片时，该接口对部分key有特殊处理。以下字段的字符串取值请参考[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量的值：
> - NewSubfileType、ImageWidth、ImageLength、DefaultCropSize、Orientation、Compression、PhotometricInterpretation、PlanarConfiguration、RowsPerStrip、StripOffsets、StripByteCounts、SamplesPerPixel、BitsPerSample、YCbCrCoefficients、YCbCrSubSampling、YCbCrPositioning、ReferenceBlackWhite、XResolution、YResolution、ResolutionUnit字段：返回主图相关的字段值。
> - ImageUniqueID字段：根据规范进行校验，不符合规范时会返回空字符串。
> - ExifVersion、FlashpixVersion、ColorSpace字段：当图片中不存在该标签时，返回错误码。
> - DNGVersion字段：当版本号小于1.0.0.0时，统一返回1.0.0.0。
> - GPSVersionID字段：当没有有效的GPS数据时，会清除GPS版本号并返回0。
> - GPSAltitudeRef字段：当未设置GPSAltitude时，会设置为0xFFFFFFFF。
> - ISOSpeedRatings字段：当该标签值为0或65535时，会优先使用推荐曝光指数，若不存在则依次使用标准输出灵敏度、ISO速度、曝光指数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| char *value | 被查询属性的查询结果。输出参数。调用者需要管理内存并释放。 |
| size_t size | 字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是字符串类型的值。 |

### OH_ImageSourceNative_GetImagePropertyIntArray()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)
```

**描述**

以整型数组类型获取图像属性的值。

> **说明：**
>
> 读取DNG格式图片时，该接口对部分key有特殊处理。以下字段的字符串取值请参考[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量的值：
> - NewSubfileType、ImageWidth、ImageLength、DefaultCropSize、Orientation、Compression、PhotometricInterpretation、PlanarConfiguration、RowsPerStrip、StripOffsets、StripByteCounts、SamplesPerPixel、BitsPerSample、YCbCrCoefficients、YCbCrSubSampling、YCbCrPositioning、ReferenceBlackWhite、XResolution、YResolution、ResolutionUnit字段：返回主图相关的字段值。
> - ImageUniqueID字段：根据规范进行校验，不符合规范时会返回空字符串。
> - ExifVersion、FlashpixVersion、ColorSpace字段：当图片中不存在该标签时，返回错误码。
> - DNGVersion字段：当版本号小于1.0.0.0时，统一返回1.0.0.0。
> - GPSVersionID字段：当没有有效的GPS数据时，会清除GPS版本号并返回0。
> - GPSAltitudeRef字段：当未设置GPSAltitude时，会设置为0xFFFFFFFF。
> - ISOSpeedRatings字段：当该标签值为0或65535时，会优先使用推荐曝光指数，若不存在则依次使用标准输出灵敏度、ISO速度、曝光指数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| int32_t *value | 被查询属性的查询结果。输出参数。调用者需要管理内存并释放。 |
| size_t size | 字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是整型数组类型的值。 |

### OH_ImageSourceNative_GetImagePropertyDoubleArray()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)
```

**描述**

以浮点型数组类型获取图像属性的值。

> **说明：**
>
> 读取DNG格式图片时，该接口对部分key有特殊处理。以下字段的字符串取值请参考[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量的值：
> - NewSubfileType、ImageWidth、ImageLength、DefaultCropSize、Orientation、Compression、PhotometricInterpretation、PlanarConfiguration、RowsPerStrip、StripOffsets、StripByteCounts、SamplesPerPixel、BitsPerSample、YCbCrCoefficients、YCbCrSubSampling、YCbCrPositioning、ReferenceBlackWhite、XResolution、YResolution、ResolutionUnit字段：返回主图相关的字段值。
> - ImageUniqueID字段：根据规范进行校验，不符合规范时会返回空字符串。
> - ExifVersion、FlashpixVersion、ColorSpace字段：当图片中不存在该标签时，返回错误码。
> - DNGVersion字段：当版本号小于1.0.0.0时，统一返回1.0.0.0。
> - GPSVersionID字段：当没有有效的GPS数据时，会清除GPS版本号并返回0。
> - GPSAltitudeRef字段：当未设置GPSAltitude时，会设置为0xFFFFFFFF。
> - ISOSpeedRatings字段：当该标签值为0或65535时，会优先使用推荐曝光指数，若不存在则依次使用标准输出灵敏度、ISO速度、曝光指数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| double *value | 被查询属性的查询结果。输出参数。调用者需要管理内存并释放。 |
| size_t size | 数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是浮点型数组类型的值。 |

### OH_ImageSourceNative_GetImagePropertyBlob()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)
```

**描述**

以二进制对象类型获取图像属性的值。

> **说明：**
>
> 读取DNG格式图片时，该接口对部分key有特殊处理。以下字段的字符串取值请参考[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量的值：
> - NewSubfileType、ImageWidth、ImageLength、DefaultCropSize、Orientation、Compression、PhotometricInterpretation、PlanarConfiguration、RowsPerStrip、StripOffsets、StripByteCounts、SamplesPerPixel、BitsPerSample、YCbCrCoefficients、YCbCrSubSampling、YCbCrPositioning、ReferenceBlackWhite、XResolution、YResolution、ResolutionUnit字段：返回主图相关的字段值。
> - ImageUniqueID字段：根据规范进行校验，不符合规范时会返回空字符串。
> - ExifVersion、FlashpixVersion、ColorSpace字段：当图片中不存在该标签时，返回错误码。
> - DNGVersion字段：当版本号小于1.0.0.0时，统一返回1.0.0.0。
> - GPSVersionID字段：当没有有效的GPS数据时，会清除GPS版本号并返回0。
> - GPSAltitudeRef字段：当未设置GPSAltitude时，会设置为0xFFFFFFFF。
> - ISOSpeedRatings字段：当该标签值为0或65535时，会优先使用推荐曝光指数，若不存在则依次使用标准输出灵敏度、ISO速度、曝光指数。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被查询属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被查询的属性。 |
| void *value | 被查询属性的查询结果。输出参数。调用者需要管理内存并释放。 |
| size_t size | 数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是二进制对象类型的值。 |

### OH_ImageSourceNative_ModifyImagePropertyShort()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyShort(OH_ImageSourceNative *source, Image_String *key, uint16_t value)
```

**描述**

修改图像属性中短整型的值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被修改属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被修改的属性。 |
| uint16_t value | 为属性设置的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是短整型的值。 |

### OH_ImageSourceNative_ModifyImagePropertyLong()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyLong(OH_ImageSourceNative *source, Image_String *key, uint32_t value)
```

**描述**

修改图像属性中长整型的值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被修改属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被修改的属性。 |
| uint32_t value | 为属性设置的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是长整型的值。 |

### OH_ImageSourceNative_ModifyImagePropertyDouble()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDouble(OH_ImageSourceNative *source, Image_String *key, double value)
```

**描述**

修改图像属性中浮点型的值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被修改属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被修改的属性。 |
| double value | 为属性设置的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是浮点型的值。 |

### OH_ImageSourceNative_ModifyImagePropertyIntArray()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyIntArray(OH_ImageSourceNative *source, Image_String *key, int32_t *value, size_t size)
```

**描述**

修改图像属性中整型数组型的值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被修改属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被修改的属性。 |
| int32_t *value | 为属性设置的值。 |
| size_t size | 数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是整型数组类型的值。 |

### OH_ImageSourceNative_ModifyImagePropertyDoubleArray()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyDoubleArray(OH_ImageSourceNative *source, Image_String *key, double *value, size_t size)
```

**描述**

修改图像属性中浮点型数组型的值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被修改属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被修改的属性。 |
| double *value | 为属性设置的值。 |
| size_t size | 数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是浮点型数组类型的值。 |

### OH_ImageSourceNative_ModifyImagePropertyBlob()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImagePropertyBlob(OH_ImageSourceNative *source, Image_String *key, void *value, size_t size)
```

**描述**

修改图像属性中二进制对象的值。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被修改属性的ImageSource。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 被修改的属性。 |
| void *value | 为属性设置的值。 |
| size_t size | 数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为nullptr。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持查询当前mimetype的图像属性。<br>         IMAGE_SOURCE_UNSUPPORTED_METADATA：指定的元数据不存在，或者不是二进制对象类型的值。 |
<!--Del-->
### OH_ImageSourceNative_ReadImageMetadataByType()

```c
Image_ErrorCode OH_ImageSourceNative_ReadImageMetadataByType(OH_ImageSourceNative *source, uint32_t index, Image_MetadataType *metadataTypes, size_t typeCount, OH_PictureMetadata **outMetadataArray, size_t *metadataCount)
```

**描述**

读取图像源的元数据，使用metadataTypes参数指定要读取的元数据类型。如果未指定metadataTypes，将返回所有支持的元数据。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 指向图像源的指针。 |
| uint32_t index | 图片索引。 |
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) *metadataTypes | 指定的元数据类型。 |
| size_t typeCount | 指定的元数据类型的数量。 |
| [OH_PictureMetadata](capi-image-nativemodule-oh-picturemetadata.md) **outMetadataArray | 输出参数，用于接收本函数分配的元数据数组。使用完成后调用者需要释放该对象。 |
| size_t *metadataCount | 输出的元数据数组中返回的OH_PictureMetadata元素数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_SOURCE_INVALID_PARAMETER：source、outMetadataArray或metadataCount为空指针。</li><br>         <li>IMAGE_SOURCE_UNSUPPORTED_METADATA：元数据不存在，或类型不支持。</li><br>         <li>IMAGE_SOURCE_ALLOC_FAILED：内存分配失败。</li><br>         </ul> |
<!--DelEnd-->
### OH_ImageSourceNative_GetImagePropertyWithNull()

```c
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```

**描述**

获取图像属性值。输出的value.data以字符串结束符'\0'结尾。

使用场景：适用于读取字符串形式的图像属性，例如图片方向、拍摄时间、设备信息等。与[OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty)相比，本接口返回的value.data以'\0'结尾，更适合直接按C字符串处理。

使用约束：source、key和value均不能为空指针。调用前应将value.data置为NULL、value.size置为0。接口执行成功后，可通过value.data和value.size读取属性值；接口执行失败时，不应读取value.data。

资源管理：接口执行成功后，value.data由系统分配，调用方使用完成后必须调用free()释放。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source |  被操作的OH_ImageSourceNative指针。OH_ImageSourceNative使用完成后需要主动释放，参见[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 指向属性键的指针。key的取值范围请参考image_common.h的[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量。 |
| [Image_String](capi-image-nativemodule-image-string.md) *value | 指向属性值的指针（输出参数）。调用本接口前，用户应将value->data置为空指针，并将value->size设为0。接口会为value->data自动分配所需内存，并对value->size赋值。完成对该内存的使用后，用户必须使用C标准库提供的free()函数释放value->data指向的内存，否则可能导致内存泄漏。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为空。 |

### OH_ImageSourceNative_ModifyImageProperty()

```c
Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```

**描述**

通过指定的键修改图片属性的值。

使用场景：适用于修改ImageSource中的图像属性，例如方向、用户注释等字符串属性。对于短整型、长整型、浮点型、数组或二进制对象类型的属性，优先使用对应的ModifyImagePropertyShort、ModifyImagePropertyLong、ModifyImagePropertyDouble、ModifyImagePropertyIntArray、ModifyImagePropertyDoubleArray或ModifyImagePropertyBlob接口，避免类型不匹配。

资源管理：key和value指向的内存由调用方管理，接口不会接管其生命周期。修改后的属性保存在当前ImageSource对象中；如需生成包含修改后属性的图片文件或图片数据，需要结合编码接口重新输出。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。OH_ImageSourceNative使用完成后需要主动释放，参见[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 指向属性键的指针。key的取值范围请参考image_common.h的[变量](capi-image-common-h.md#变量)中定义的OHOS_IMAGE_PROPERTY_XXX系列常量。|
| [Image_String](capi-image-nativemodule-image-string.md) *value | 需要修改的属性值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetFrameCount()

```c
Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)
```

**描述**

获取图像帧数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 被操作的OH_ImageSourceNative指针。 |
| uint32_t *frameCount | 图像帧数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetSupportedFormats()

```c
Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**描述**

获取支持解码的图片格式。

使用场景：适用于在创建图片源或展示格式选择前，动态查询当前系统支持的解码格式。部分格式的解码能力可能和系统版本、设备能力有关，建议以该接口返回结果为准。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Image_MimeType](capi-image-nativemodule-image-string.md) **supportedFormats | 支持解码的图片格式。 |
| size_t *length | 数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：参数异常，supportedFormats或length为空。 |

### OH_ImageSourceNative_Release()

```c
Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)
```

**描述**

释放OH_ImageSourceNative指针。

资源管理：由OH_ImageSourceNative_CreateFromUri、OH_ImageSourceNative_CreateFromFd、OH_ImageSourceNative_CreateFromData、OH_ImageSourceNative_CreateFromDataWithUserBuffer或OH_ImageSourceNative_CreateFromRawFile成功创建的对象，都应在不再使用时调用本接口释放。释放后不得再将该source传入读取图片信息、解码、读取或修改属性等接口。释放ImageSource不会自动释放已经创建出的OH_PixelmapNative、OH_PictureNative或OH_ImageRawData对象，这些对象需要分别调用对应释放接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 要释放的OH_ImageSourceNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptionsForPicture_Create()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)
```

**描述**

创建OH_DecodingOptionsForPicture指针。

使用约束：options不能为空指针。接口返回失败时，输出参数的内容不能在后续流程中继续使用。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) **options | 被操作的OH_DecodingOptionsForPicture指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)
```

**描述**

获取解码时设置的期望辅助图（期望解码出的picture包含的辅助图）。

使用约束：options、desiredAuxiliaryPictures和length均不能为空指针。未设置期望辅助图时，接口返回IMAGE_BAD_PARAMETER。

资源管理：接口成功返回的desiredAuxiliaryPictures数组由接口分配，使用完成后调用方应使用delete[]释放。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 被操作的OH_DecodingOptionsForPicture指针。 |
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) **desiredAuxiliaryPictures | 解码选项中的期望辅助图。 |
| size_t *length | 期望辅助图长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)
```

**描述**

设置解码选项中的期望辅助图。

使用约束：options和desiredAuxiliaryPictures均不能为空指针，length必须大于0，desiredAuxiliaryPictures数组中的辅助图类型必须为当前支持的Image_AuxiliaryPictureType。

资源管理：接口会将传入数组中的辅助图类型保存到OH_DecodingOptionsForPicture对象中，不会持有传入的数组指针，接口返回后调用方可自行释放或复用该数组。多次调用该接口时，新传入的辅助图类型会追加到已有集合中；重复类型只保留一份。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 被操作的OH_DecodingOptionsForPicture指针。 |
| [Image_AuxiliaryPictureType](capi-picture-native-h.md#image_auxiliarypicturetype) *desiredAuxiliaryPictures | 将要设置的期望辅助图。 |
| size_t length | 期望辅助图长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |
<!--Del-->
### OH_DecodingOptionsForPicture_GetNeedsDecodeDfxData()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool *needsDecodeDfxData)
```

**描述**

获取解码选项中的needsDecodeDfxData参数。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 指向OH_DecodingOptionsForPicture结构体的指针。 |
| bool *needsDecodeDfxData | 图像DFX数据是否需要解码。true表示图像DFX数据需要解码，false表示图像DFX数据不需要解码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_SOURCE_INVALID_PARAMETER：options或needsDecodeDfxData为空指针。</li><br>         </ul> |

### OH_DecodingOptionsForPicture_SetNeedsDecodeDfxData()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetNeedsDecodeDfxData(OH_DecodingOptionsForPicture *options, bool needsDecodeDfxData)
```

**描述**

设置解码选项中的needsDecodeDfxData参数。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 指向OH_DecodingOptionsForPicture结构体的指针。 |
| bool needsDecodeDfxData | 图像DFX数据是否需要解码。true表示图像DFX数据需要解码，false表示图像DFX数据不需要解码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_SOURCE_INVALID_PARAMETER：options为空指针。</li><br>         </ul> |

### OH_DecodingOptionsForPicture_GetDesiredSizeForMainPixelmap()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size *desiredSizeForMainPixelmap)
```

**描述**

获取DecodingOptionsForPicture结构体中的主图期望尺寸。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 指向OH_DecodingOptionsForPicture结构体的指针。 |
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSizeForMainPixelmap | 主图的期望尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_SOURCE_INVALID_PARAMETER：options为空指针。</li><br>         </ul> |

### OH_DecodingOptionsForPicture_SetDesiredSizeForMainPixelmap()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredSizeForMainPixelmap(OH_DecodingOptionsForPicture *options, Image_Size desiredSizeForMainPixelmap)
```

**描述**

设置DecodingOptionsForPicture结构体中的主图期望尺寸。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 指向OH_DecodingOptionsForPicture结构体的指针。 |
| [Image_Size](capi-image-nativemodule-image-size.md) desiredSizeForMainPixelmap | 主图的期望尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_SOURCE_INVALID_PARAMETER：options为空指针。</li><br>         </ul> |

### OH_DecodingOptionsForPicture_GetDesiredPixelFormat()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT *desiredPixelFormat)
```

**描述**

获取DecodingOptionsForPicture结构体中的像素格式。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 指向OH_DecodingOptionsForPicture结构体的指针。 |
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) *desiredPixelFormat | 解码选项中的像素格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_SOURCE_INVALID_PARAMETER：options为空指针。</li><br>         </ul> |

### OH_DecodingOptionsForPicture_SetDesiredPixelFormat()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredPixelFormat(OH_DecodingOptionsForPicture *options, PIXEL_FORMAT desiredPixelFormat)
```

**描述**

设置DecodingOptionsForPicture结构体中的像素格式。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 指向OH_DecodingOptionsForPicture结构体的指针。 |
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) desiredPixelFormat | 解码选项中的像素格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_SOURCE_INVALID_PARAMETER：options为空指针。</li><br>         </ul> |
<!--DelEnd-->
### OH_DecodingOptionsForPicture_Release()

```c
Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)
```

**描述**

释放OH_DecodingOptionsForPicture指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 要释放的OH_DecodingOptionsForPicture指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreateImageRawData()

```c
Image_ErrorCode OH_ImageSourceNative_CreateImageRawData(const OH_ImageSourceNative *source, OH_ImageRawData **rawData)
```

**描述**

从图像中获取rawData对象。rawData对象通常占用大量内存，因为它包含来自相机的原始数据。<br>        当不再使用rawData对象时，请及时调用[OH_ImageSourceNative_DestroyImageRawData](capi-image-source-native-h.md#oh_imagesourcenative_destroyimagerawdata)方法销毁，以释放内存资源。

使用场景：适用于从包含原始图像数据的图片源中读取rawData，并交给自定义图像处理、算法分析或保存链路使用。普通图片显示或常规像素处理场景，通常应使用[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)解码为PixelMap。

资源管理：成功创建的OH_ImageRawData对象由调用方持有，使用完成后必须调用[OH_ImageSourceNative_DestroyImageRawData](#oh_imagesourcenative_destroyimagerawdata)销毁。rawData对象和OH_ImageSourceNative对象生命周期相互独立，释放ImageSource不会自动销毁rawData。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *source | 指向图像源的指针。 |
| [OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) **rawData | 解码后获得的rawData对象的双指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_SOURCE：源错误。<br>         IMAGE_SOURCE_INVALID_PARAMETER：rawData对象无效。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持的MIME类型。 |

### OH_ImageSourceNative_GetBufferFromRawData()

```c
Image_ErrorCode OH_ImageSourceNative_GetBufferFromRawData(const OH_ImageRawData *rawData, uint8_t **data, size_t *length)
```

**描述**

从rawData对象获取二进制数据。

资源管理：data返回的是rawData对象内部二进制缓冲区的地址，调用方不应对*data调用free()，也不应在[OH_ImageSourceNative_DestroyImageRawData](#oh_imagesourcenative_destroyimagerawdata)销毁rawData后继续访问该地址。如需在rawData销毁后继续使用数据，应在销毁前自行深拷贝。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) *rawData | 指向rawData对象的指针。 |
| uint8_t **data | 指向二进制缓冲区数据的指针。 |
| size_t *length | 指向所获取数据长度的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：rawData对象无效。 |

### OH_ImageSourceNative_GetBitsPerPixelFromRawData()

```c
Image_ErrorCode OH_ImageSourceNative_GetBitsPerPixelFromRawData(const OH_ImageRawData *rawData, uint8_t *bitsPerPixel)
```

**描述**

获取缓冲区数据中每个像素实际占用的位数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) *rawData | 指向rawData对象的指针。 |
| uint8_t *bitsPerPixel | 指向所获取的每像素位数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：rawData对象无效。 |

### OH_ImageSourceNative_DestroyImageRawData()

```c
Image_ErrorCode OH_ImageSourceNative_DestroyImageRawData(OH_ImageRawData *rawData)
```

**描述**

销毁rawData对象。

资源管理：该接口只销毁OH_ImageRawData对象及其内部资源，不会释放OH_ImageSourceNative对象。销毁后，之前通过[OH_ImageSourceNative_GetBufferFromRawData](#oh_imagesourcenative_getbufferfromrawdata)获取到的data地址立即失效。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageRawData](capi-image-nativemodule-oh-imagerawdata.md) *rawData | 指向rawData对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：rawData对象无效。 |
